# Shortcodes

This is a parser for the shortcode spec as explained in the Hugo docs
and used in Hugo and Nikola. Approximately.

I am implementing this for Nicolino.

It probably won't be 100% identical, but I'll try to make it
as close as practical.

* Implemented in Ragel + C for performance
* Allocates no memory, because all strings are references to 
  pieces of input.

What works:

* Detect shortcodes with names
* Standalone and matched shortcodes
* Capture data between tags in matched shortcodes
* Capture arguments with and without names
* Capture values with and without quotes (with details, see TODO above)

