#ifndef SHORTCODES_H
#define SHORTCODES_H

// A chunk is a reference to a piece of string
// from "start" relative to its start
// and goes on for len characters.
struct chunk
{
    int start, len;
};
typedef struct chunk chunk;

// Describes a parsed shortcode
struct shortcode
{
    chunk whole;
    chunk name;
    chunk data;
    char matching;
    chunk argnames[100];
    chunk argvals[100];
    int argcount;
};
typedef struct shortcode shortcode;

shortcode *parse(char *);
#endif
