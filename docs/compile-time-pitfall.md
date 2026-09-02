# The ~160KB struct that cost 18 minutes of compile time

A case study of a C-interop pitfall: **returning a large struct by value
across a C ABI can turn an optimizing compiler into a brick**. This shard
used to do exactly that, and the largest project using it
([nicolino](https://nicolino.ralsina.me)) paid ~17 extra minutes on every
`--release` build. This document explains the symptom, the mechanism, the
fix, and the measurements taken before and after.

*Environment where this was observed and measured:* Crystal 1.21.0 /
LLVM 22.1.8, Linux x86-64, 12 cores.

## TL;DR

* `parse()` used to return `sc_result` **by value**. That struct is
  **163,688 bytes** (`Shortcode[100]`, each holding two `Chunk[100]`
  arrays).
* When the Crystal wrapper got inlined into its callers, LLVM expanded
  the constant-size struct copies into scalar instructions: the function
  grew from **588 to 166,188 IR instructions** (99.6% of them raw
  load/store/addressing).
* Optimizing that one function consumed **86.6% of the entire
  optimization phase** of the consumer project (measured with
  `opt -O2 -time-passes`: `InstCombinePass` 816s of 942s), plus minutes
  more in the backend instruction scheduler, which is superlinear in the
  number of memory operations per basic block.
* The fix is the classic one: **pass an output pointer instead of
  returning the struct**. Compile time for a minimal consumer went from
  ">9 minutes, aborted" to **6.7 seconds**.
* Bonus pitfall: zero-initializing that same struct on the Crystal side
  (`ScResult.new`) is *also* pathological for LLVM (168s debug builds!).
  Use `uninitialized` + a C-side `memset`.
* And importantly: **this is not a C-interop problem**. A pure-Crystal
  def returning a large struct reproduces it with no C, no lib, no
  macros involved — see the next section.

## It's not about C: a pure-Crystal reproduction

We found this in a C-binding shard, but the C part is incidental. The
optimizer doesn't care where a big by-value struct comes from. This
dependency-free program — no `lib`, no C, no macros — reproduces the
pathology on its own:

```crystal
# big.cr — a def that returns a ~163KB struct by value
struct Big
  getter a : StaticArray(UInt64, 20410) # 20410 * 8 = ~163KB

  def initialize
    @a = StaticArray(UInt64, 20410).new(0_u64)
  end
end

def make : Big
  big = Big.new
  big.a[0] = 1_u64
  big # returned by value
end

x = make
y = make
puts x.a[0] + y.a[0]
```

Sweeping the size of the returned struct (fresh compiler cache, builds
run one at a time) shows exactly where the cliff starts. Times in
parentheses mean the build was killed before finishing:

| returned struct size | debug build | release build |
|---------------------:|------------:|--------------:|
| 1 KB                 | 1.2s        | 6.3s          |
| 4 KB                 | 1.0s        | 6.3s          |
| 16 KB                | 2.0s        | 7.5s          |
| 64 KB                | 16.6s       | 28.9s         |
| 256 KB               | >2 min      | >5 min        |
| 1 MB                 | 1.7s        | >5 min        |

Up to ~16KB nobody notices anything. At 64KB builds are already 4-5x a
normal one. From ~256KB the build effectively never finishes — with
*either* optimization level. The exact numbers wobble at the big end
(note 1MB debug being fast again): the compiler switches between
strategies for initializing, copying and scalarizing huge aggregates,
and which one blows up first depends on the size. The shape of the
curve is the message: **large value types are compile-time poison, and
the cliff sits in the tens-of-KB range.**

That also matches the shortcodes story: `sc_result` at 163,688 bytes
sat deep inside the cliff, and no C was needed to demonstrate it.

## Symptoms

nicolino, a static site generator using this shard:

| build                    | time       |
|--------------------------|------------|
| `shards build` (debug)   | 29s        |
| `shards build --release` | 18m 26s    |

A 38x ratio. Slow `--release` builds are normal in Crystal; 3x-5x debug
time is typical. 38x means something specific went wrong, and it went
wrong in the optimizer: profiling showed the time was spent in LLVM
itself, not in Crystal's front-end (semantic analysis and unoptimized
codegen together took ~30s).

Strangest of all: **nothing looked guilty**. Building tiny programs
against each dependency of nicolino in release mode took minutes
*total*; the explosion only appeared in the full build.

## Finding the culprit

Three tools pinned it down:

1. **perf on the live release build**: ~70% of samples in LLVM's
   SelectionDAG instruction scheduler (`BuildSchedGraph`,
   `ClusterNeighboringLoads`) and use-list maintenance, with the rest in
   InstCombine-region code. These passes are all superlinear (roughly
   quadratic) in the number of instructions/memory-ops of a *single
   function*. Conclusion: something in the module produces enormous
   functions.

2. **`opt -O2 -time-passes`** on the module's LLVM IR: of 942s of
   optimization, `InstCombinePass` alone took **816s (86.6%)**.
   Everything else was noise.

3. **Comparing IR before/after optimization** (`crystal build --emit
   llvm-ir`, then optimize with `opt`): one function stood out by two
   orders of magnitude. For scale: the biggest *normal* function in the
   module (a stdlib table initializer) is ~18k lines:

   | function                            | before opt | after opt   |
   |-------------------------------------|-----------:|------------:|
   | `*Shortcodes::parse<String>`        | 588 lines  | **166,188** |
   | biggest function after this one     | ~18,000    | 18,835      |

   The opcode census of the optimized monster:

   | opcode        | count   |
   |---------------|--------:|
   | `getelementptr` | 82,886 |
   | `store`         | 41,449 |
   | `load`          | 41,444 |
   | everything else |    409 |

   99.6% of the function is raw memory traffic: it *is* the struct
   copies.

## The mechanism

The old C interface was:

```c
struct sc_result {
    shortcode sc[100];        /* each shortcode: 2 x Chunk[100] arrays */
    unsigned int sccount;
    sc_error errors[10];
    unsigned int errcount;
};                            /* 163,688 bytes */

sc_result parse(char *input, unsigned int len);
```

and the Crystal wrapper called it in a loop per document:

```crystal
def self.parse(input : String)
  r = LibShortcodes.parse(input.to_unsafe, input.bytesize)
  ...
end
```

What happens next is a cooperation between two completely ordinary
compiler behaviors:

1. Crystal's optimizer inlines `Shortcodes.parse` into its callers. The
   by-value C return becomes a large temporary plus **constant-size
   struct copies** (~164KB each).
2. InstCombine expands constant-size `memcpy`s into individual
   load/store pairs so they can be optimized further. A 163,688-byte
   copy becomes ~41k load/store pairs (plus addressing), *per copy*.
3. The resulting single gigantic (mostly straight-line) function then
   gets visited by *every* pass in the pipeline. Several of them
   (InstCombine worklists, MemorySSA, and especially the SelectionDAG
   instruction scheduler) scale badly — in practice quadratically — with
   the instruction count of a basic block.

Nothing here is a compiler bug. Every step is reasonable in isolation;
the pathology is the *combination*: by-value semantics for a huge
aggregate + inlining + memcpy expansion + superlinear passes.

### Why it hid until the full build

Crystal only generates code for methods that are *reachable* from the
entry point. Any program that merely did `require "shortcodes"` never
compiled `Shortcodes.parse`'s body at all, so every per-dependency
bisect build looked innocent. Only the real program — which calls
`Shortcodes.parse` from its markdown pipeline — materialized the
monster. This is why the slow build looked like "the whole project is
somehow slow" instead of "this one call site is slow".

## The fix

Classic C-interop hygiene: **don't return big aggregates by value; let
the caller provide the storage.**

Before:

```c
sc_result parse(char *input, unsigned int len);
```

After:

```c
/* The result is written into a caller-provided sc_result instead of
being returned by value: the struct is ~160KB, and by-value returns
make optimizing compilers explode the copies into hundreds of
thousands of instructions. */
void parse(char *input, unsigned int len, sc_result *result);
```

On the C side the function now writes into `result` (and zeroes it with
`memset` first — see "the second pitfall" below). On the Crystal side:

Before:

```crystal
fun parse(input : Pointer(LibC::Char), len : UInt32) : ScResult
```

After:

```crystal
fun parse(input : Pointer(LibC::Char), len : UInt32, result : ScResult*) : Nil
```

```crystal
def self.parse(input : String)
  # It is zeroed on the C side, so `uninitialized` is safe here (and
  # `.new` would be slow: zero-initializing this struct is pathological
  # for LLVM, too).
  r = uninitialized LibShortcodes::ScResult
  LibShortcodes.parse(input.to_unsafe, input.bytesize, pointerof(r))
  ...
end
```

The public Crystal API (`Shortcodes.parse(input : String)`) is
unchanged; only the C ABI changed, which is why the version went from
0.4.x to 0.5.0. C consumers who copied `shortcodes.c`/`shortcodes.h`
need to adapt their call sites.

## The second pitfall: zero-initializing the result Crystal-side

The first attempt at the fix zero-initialized the struct on the Crystal
side with `r = LibShortcodes::ScResult.new`. That restored a *different*
compile-time explosion — this time in **debug** builds:

| minimal consumer, fresh build | debug | release |
|-------------------------------|------:|--------:|
| with `ScResult.new`           | 168s  | 188s    |
| with `uninitialized` + C-side `memset` | 1.4s | 6.7s |

Zero-initializing a large nested-array struct is itself pathological for
LLVM. Zeroing in C (`memset(result, 0, sizeof *result)`, one call,
~160KB, once per document) is free by comparison and has the same
semantics.

Note that the memset is not merely defensive: the parser only assigns
`escaped` and `self_closing` inside the actions that parse those
particular forms, so for ordinary shortcodes those bytes were never
written at all. The old by-value code "worked" because the uninitialized
stack bytes it read happened to be zero. The memset makes the contract
explicit: every field of the result is deterministic.

## Timings, before and after

Minimal consumer program (require + parse a few shortcodes, release
build, fresh compiler cache):

| version                                   | debug  | release |
|-------------------------------------------|-------:|--------:|
| 0.4.1 (by-value return)                   | 2.6s   | >9 min, aborted |
| 0.5.0-dev, `ScResult.new` zero-init       | 168s   | 188s    |
| 0.5.0 (output pointer + C-side memset)    | **1.4s** | **6.7s** |

Consumer project (nicolino, ~11k lines plus dependencies):

| build                    | shortcodes 0.4.1 | shortcodes 0.5.0 |
|--------------------------|-----------------:|-----------------:|
| `shards build`           | 29s              | (unchanged)      |
| `shards build --release` | 18m 26s          | ~1-2 min (est.)  |

The nicolino estimate comes from the per-dependency bisect: with
shortcodes fixed, every remaining component of the build was measured at
seconds-to-minutes, and nothing else in the module produces functions
beyond normal size. The 0.4.1 debug builds were always fine because the
by-value copies are only expanded by the *optimizing* pipeline; 0.5.0
with `ScResult.new` was the odd case where even debug builds exploded.

## Guidance for shard authors

* Never return large structs by value over a C ABI — as a rule of thumb,
  once a struct contains fixed-size arrays sized in the hundreds, or
  exceeds a few kilobytes, take an output pointer (or return a heap
  pointer) instead. The compile-time cost lands on every downstream
  project's `--release` build, where nobody will connect it to your
  shard.
* If the struct must be big, zero it on the C side and declare it
  `uninitialized` in Crystal. Do not use `.new` on huge lib structs.
* If a `--release` build is absurdly slower than the debug build,
  profile the *compiler* (`perf record -p <crystal pid>`) and try
  `crystal build --emit llvm-ir` plus `opt -O2 -time-passes` on the
  result. A single function with six-figure instruction counts is the
  smoking gun, and `-time-passes` will name the suffering pass.
* The same explosion is reproducible with pure Crystal (see the size
  sweep above), so this is an LLVM interaction any backend language can
  hit — Crystal just makes it easy to have a 160KB struct cross an ABI
  without noticing.

## Reproducing the measurements

```shell
# The consumer repro: 10 lines calling Shortcodes.parse
crystal build -o repro repro.cr            # debug
time crystal build --release -o repro repro.cr

# Where the compiler spends its time during a pathological build:
perf record -F 99 -g -p <pid of crystal build>; perf report

# Per-pass attribution on the emitted IR:
crystal build --emit llvm-ir repro.cr
opt -O2 -time-passes repro.ll -o /dev/null

# Function sizes before/after optimization:
crystal build --emit llvm-ir repro.cr && grep -c '' repro.ll
opt -O2 -S repro.ll -o repro.opt.ll && grep -c '' repro.opt.ll
```
