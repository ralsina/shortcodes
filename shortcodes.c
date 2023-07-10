
#line 1 "shortcodes.rl"
#include <stdio.h>
#include "bstrlib/bstrlib.h"

bstring grab_chunk(char *start, char *end) {
  blk2bstr(start, end-start);
}


#line 36 "shortcodes.rl"


bstring parse(char *_input) {
    
#line 17 "shortcodes.c"
static const int shortcode_start = 1;
static const int shortcode_first_final = 15;
static const int shortcode_error = 0;

static const int shortcode_en_main = 1;


#line 40 "shortcodes.rl"
    char *eof, *ts, *te = 0;
    int cs, act = 0;

    bstring output = bfromcstr("out");

    bstring input = bfromcstr(_input);
    char *p = input->data;
    char *pe = p + blength(input);

    char *mark = 0;
    bstring label;
    
 
    
#line 40 "shortcodes.c"
	{
	cs = shortcode_start;
	}

#line 54 "shortcodes.rl"
    
#line 47 "shortcodes.c"
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
	if ( (*p) == 32 )
		goto st3;
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st3;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr3;
	} else
		goto tr3;
	goto st0;
tr3:
#line 11 "shortcodes.rl"
	{
    mark = p;
  }
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 92 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr4;
		case 125: goto tr6;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr4;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st4;
	} else
		goto st4;
	goto st0;
tr4:
#line 20 "shortcodes.rl"
	{printf("name: '%s'\n", grab_chunk(mark, p)->data);}
	goto st5;
tr14:
#line 26 "shortcodes.rl"
	{printf("value: '%s'\n", grab_chunk(mark, p)->data);}
	goto st5;
tr24:
#line 26 "shortcodes.rl"
	{printf("value: '%s'\n", grab_chunk(mark, p)->data);}
#line 29 "shortcodes.rl"
	{printf("arg: '%s'\n", grab_chunk(mark, p)->data);}
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
#line 124 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st5;
		case 34: goto tr8;
		case 125: goto st8;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st5;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr10;
		} else if ( (*p) >= 65 )
			goto tr10;
	} else
		goto tr9;
	goto st0;
tr8:
#line 11 "shortcodes.rl"
	{
    mark = p;
  }
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
#line 152 "shortcodes.c"
	if ( (*p) == 34 )
		goto st7;
	goto st6;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	switch( (*p) ) {
		case 32: goto tr14;
		case 125: goto tr15;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr14;
	goto st0;
tr6:
#line 20 "shortcodes.rl"
	{printf("name: '%s'\n", grab_chunk(mark, p)->data);}
	goto st8;
tr15:
#line 26 "shortcodes.rl"
	{printf("value: '%s'\n", grab_chunk(mark, p)->data);}
	goto st8;
tr25:
#line 26 "shortcodes.rl"
	{printf("value: '%s'\n", grab_chunk(mark, p)->data);}
#line 29 "shortcodes.rl"
	{printf("arg: '%s'\n", grab_chunk(mark, p)->data);}
	goto st8;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
#line 185 "shortcodes.c"
	if ( (*p) == 125 )
		goto st15;
	goto st0;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	goto st0;
tr9:
#line 11 "shortcodes.rl"
	{
    mark = p;
  }
	goto st9;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
#line 204 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr14;
		case 125: goto tr15;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr14;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st9;
		} else if ( (*p) >= 65 )
			goto st9;
	} else
		goto st9;
	goto st0;
tr10:
#line 11 "shortcodes.rl"
	{
    mark = p;
  }
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
#line 231 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr14;
		case 61: goto tr18;
		case 125: goto tr15;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr14;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st10;
		} else if ( (*p) >= 65 )
			goto st10;
	} else
		goto st9;
	goto st0;
tr18:
#line 23 "shortcodes.rl"
	{printf("argname: '%s'\n", grab_chunk(mark, p)->data);}
	goto st11;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
#line 257 "shortcodes.c"
	if ( (*p) == 34 )
		goto tr20;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr21;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr21;
	} else
		goto tr21;
	goto st0;
tr20:
#line 11 "shortcodes.rl"
	{
    mark = p;
  }
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
#line 279 "shortcodes.c"
	if ( (*p) == 34 )
		goto st13;
	goto st12;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	switch( (*p) ) {
		case 32: goto tr24;
		case 125: goto tr25;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr24;
	goto st0;
tr21:
#line 11 "shortcodes.rl"
	{
    mark = p;
  }
	goto st14;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
#line 304 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr24;
		case 125: goto tr25;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr24;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st14;
		} else if ( (*p) >= 65 )
			goto st14;
	} else
		goto st14;
	goto st0;
	}
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 

	_test_eof: {}
	_out: {}
	}

#line 55 "shortcodes.rl"

    printf("\nLabel is: '%s'\n", label->data);
    return output;
}

int main(int argc, char **argv) {
    bstring output = parse("{{ thename  \"onearg\" another arg=\"val3\" }}");
    printf("\n%s\n", output->data);
    return 0;
}
