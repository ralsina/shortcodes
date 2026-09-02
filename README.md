# Shortcodes

## What it is

This is a parser for the shortcode spec as explained in the Hugo docs
and used in Hugo and Nikola. Approximately.

I am implementing this for [Nicolino.](https://nicolino.ralsina.me)

It probably won't be 100% identical, but I'll try to make it
as close as practical.

* Implemented in Ragel + C for performance
* The C parser allocates no memory: all positions and lengths are
  references to pieces of the input, and nothing is copied or
  heap-allocated during parsing.
* The Crystal binding allocates only the result objects: one copy of
  each reported string, and nothing else.

## What works

* Detect shortcodes with names
* Standalone and matched shortcodes
* Capture data between tags in matched shortcodes
* Self-closing shortcodes
* Inline shortcodes
* Markdown and Verbatim shortcodes
* Capture arguments with and without names
* Capture values with and without single/double quotes, including escaped quotes
* Unquoted values support letters, numbers and unambiguous punctuation:
  `-` `_` `.` `/` `:` `@` `+` `~` `#` (e.g. `src=images/photo-1.png`).
  Anything else, or values with spaces, can be quoted. A trailing `/` in an
  unquoted value is ambiguous with the self-closing delimiters, so quote it
  (`path="dir/"`).
* UTF-8 strings AFAICT (arg and shortcode names only support ascii tho)

## Things you should know

* Names and unquoted values are ASCII-only. UTF-8 works fine in the
  text around shortcodes, in matched content and in quoted values.
* Text that looks like a shortcode but isn't one (e.g. `{{% foo >}}`)
  passes through untouched rather than producing an error, because it
  may be content, not a broken shortcode. Only unambiguous errors
  (closing a shortcode that was never opened, mismatched bracket
  *styles* in a complete shortcode) are reported.
* Only the first 10 errors are reported. Fix them in order, the rest
  will surface on the next pass.
* More than 100 shortcodes per document or 100 arguments per shortcode
  is an error; anything past the limit is dropped.
* In a `Shortcode`, `position` counts codepoints, while `len` and the
  sizes of `whole` and `data` are in bytes.

Nested shortcodes should be handled in a higher layer by recursive calls to
the parser where it makes sense.

## Building

You need [Ragel](http://www.colm.net/open-source/ragel/) 7 and a C compiler.
The generated `shortcodes.c` in the repo is built with ragel 7; older
versions generate different (buggy) code, so don't regenerate with 6.x.

Ragel is used to generate `shortcodes.c` out of `shortcodes.rl`.
As a convenience there is a generated `shortcodes.c` in the repo,

Then:

```shell
  make
```

To run tests:

```shell
  crystal spec
```

## Installation

1. Add the dependency to your `shard.yml`:

   ```yaml
   dependencies:
     shortcodes:
       github: ralsina/shortcodes
   ```

2. Run `shards install`

## Usage in Crystal

```crystal
require "shortcodes"
```

## Usage in C

Just copy `shortcodes.c` and `shortcodes.h` into your project and have fun.

```c
sc_result result;
parse(input, len, &result);
```

The caller provides the `sc_result`: it is ~160KB, and returning it by
value used to make optimizing compilers explode compile times
dramatically. See
[docs/compile-time-pitfall.md](docs/compile-time-pitfall.md) for the
full story.
