#ifndef SHORTCODES_H
#define SHORTCODES_H
struct chunk
{
    int start, len;
};

typedef struct chunk chunk;

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
