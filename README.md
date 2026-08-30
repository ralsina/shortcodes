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

Nested shortcodes should be handled in a higher layer by recursive calls to
the parser where it makes sense.

## Building

You need [Ragel](http://www.colm.net/open-source/ragel/) and a C compiler.

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
