#pragma once

// A chunk is a reference to a piece of string
// from "start" relative to its start
// and goes on for len characters.
struct chunk
{
    unsigned int start;
    unsigned int len;
};
typedef struct chunk chunk;

// An error
struct sc_error
{
    unsigned int position;
    unsigned int code;
};
typedef struct sc_error sc_error;

// Describes a parsed shortcode
struct shortcode
{
    chunk whole;
    chunk name;
    chunk data;
    char matching;
    chunk argnames[100];
    chunk argvals[100];
    unsigned int argcount;
};
typedef struct shortcode shortcode;

struct sc_result
{
    shortcode sc[100];
    unsigned int sccount;
    sc_error errors[10];
    unsigned int errcount;
};
typedef struct sc_result sc_result;

// Error codes

/* You are closing the wrong shortcode.
Example:

{{% foo %}}  {{% /bar %}}
*/
#define ERR_MISMATCHED_CLOSING_TAG 1

/* You are using mismatched brackets.
Example:

{{% foo >}}
*/
#define ERR_MISMATCHED_BRACKET 2


sc_result parse(char *, unsigned int);
