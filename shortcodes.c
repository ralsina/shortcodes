
#line 1 "shortcodes.rl"
#include <stdio.h>
#include "bstrlib/bstrlib.h"


#line 14 "shortcodes.rl"


bstring parse(char *_input) {
    
#line 13 "shortcodes.c"
static const int shortcode_start = 1;
static const int shortcode_first_final = 1;
static const int shortcode_error = 0;

static const int shortcode_en_main = 1;


#line 18 "shortcodes.rl"
    char *eof, *ts, *te = 0;
    int cs, act = 0;

    bstring output = bfromcstr("out");

    bstring input = bfromcstr(_input);
    char *p = input->data;
    char *pe = p + blength(input);
    
 
    
#line 33 "shortcodes.c"
	{
	cs = shortcode_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 29 "shortcodes.rl"
    
#line 43 "shortcodes.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr0:
#line 11 "shortcodes.rl"
	{te = p+1;{printf("start");}}
	goto st1;
tr2:
#line 12 "shortcodes.rl"
	{te = p+1;{printf("end");}}
	goto st1;
st1:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof1;
case 1:
#line 1 "NONE"
	{ts = p;}
#line 65 "shortcodes.c"
	switch( (*p) ) {
		case 65: goto tr0;
		case 66: goto tr2;
	}
	goto st0;
st0:
cs = 0;
	goto _out;
	}
	_test_eof1: cs = 1; goto _test_eof; 

	_test_eof: {}
	_out: {}
	}

#line 30 "shortcodes.rl"

    return output;
}

int main(int argc, char **argv) {
    bstring output = parse("ABAAB");
    printf("%s\n", output->data);
    return 0;
}
