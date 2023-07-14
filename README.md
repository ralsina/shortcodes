# Shortcodes

## What it is

This is a parser for the shortcode spec as explained in the Hugo docs
and used in Hugo and Nikola. Approximately.

I am implementing this for Nicolino.

It probably won't be 100% identical, but I'll try to make it
as close as practical.

* Implemented in Ragel + C for performance
* Allocates no memory, because all strings are references to
  pieces of input.

## What works

* Detect shortcodes with names
* Standalone and matched shortcodes
* Capture data between tags in matched shortcodes
* Capture arguments with and without names
* Capture values with and without quotes (with details, see [TODO](TODO.md))

## Building

You need [Ragel](http://www.colm.net/open-source/ragel/) and a C compiler.

Ragel is used to generate `shortcodes.c` out of `shortcodes.rl`.
As a convenience there is a generated `shortcodes.c` in the repo,

Then:

```shell
  cd src && make
```

To run tests:

```shell
  crystal spec
```

## Installation

1. Add the dependency to your `shard.yml`:

   ```yaml
   dependencies:
     cr-discount:
       github: ralsina/shortcodes
   ```

2. Run `shards install`

## Usage

```crystal
require "shortcodes"
```
