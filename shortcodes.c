
#line 1 "shortcodes.rl"
#include <stdio.h>
#include "bstrlib/bstrlib.h"


#line 14 "shortcodes.rl"


bstring parse(char *_input) {
    
#line 13 "shortcodes.c"
static const int shortcode_start = 1;
static const int shortcode_first_final = 6;
static const int shortcode_error = 0;

static const int shortcode_en_main = 1;


#line 18 "shortcodes.rl"
    char *eof, *ts, *te = 0;
    int cs, act = 0;

    bstring output = bfromcstr("out");

    bstring input = bfromcstr(_input);
    char *p = input->data;
    char *pe = p + blength(input);

    char *label_start = 0;
    char *label_end = 0;
    
 
    
#line 36 "shortcodes.c"
	{
	cs = shortcode_start;
	}

#line 32 "shortcodes.rl"
    
#line 43 "shortcodes.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
case 1:
	if ( (*p) == 123 )
		goto st2;
	goto st0;
st0:
cs = 0;
	goto _out;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 123 )
		goto st3;
	goto st0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	if ( (*p) == 125 )
		goto tr4;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr3;
	} else if ( (*p) >= 65 )
		goto tr3;
	goto st0;
tr3:
#line 9 "shortcodes.rl"
	{printf("start");}
#line 7 "shortcodes.rl"
	{label_start = p; printf("%s", label_start);}
#line 7 "shortcodes.rl"
	{printf("=>%s", label_start);}
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 87 "shortcodes.c"
	if ( (*p) == 125 )
		goto tr6;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st4;
	} else if ( (*p) >= 65 )
		goto st4;
	goto st0;
tr4:
#line 9 "shortcodes.rl"
	{printf("start");}
#line 10 "shortcodes.rl"
	{printf("end");}
	goto st5;
tr6:
#line 10 "shortcodes.rl"
	{printf("end");}
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
#line 110 "shortcodes.c"
	if ( (*p) == 125 )
		goto st6;
	goto st0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	goto st0;
	}
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 

	_test_eof: {}
	_out: {}
	}

#line 33 "shortcodes.rl"

    return output;
}

int main(int argc, char **argv) {
    bstring output = parse("{{foo}}");
    printf("\n%s\n", output->data);
    return 0;
}
