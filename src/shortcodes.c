
#line 1 "shortcodes.rl"
#include <string.h>
#include <stdio.h>
#include "shortcodes.h"


#line 155 "shortcodes.rl"



sc_result parse(char *input, unsigned int len) {

  
#line 16 "shortcodes.c"
static const int shortcode_start = 513;
static const int shortcode_first_final = 513;
static const int shortcode_error = -1;

static const int shortcode_en_main = 513;


#line 161 "shortcodes.rl"
  char *eof = input + len;
  char *ts, *te = 0;
  int cs, act = 0;

  char *start = input;
  char *p = input;
  char *pe = p + len;

  sc_result result;
  result.errcount = 0;
  shortcode *sc_list = result.sc;
  int c_sc = 0;

  char *mark = p;
  char *data_mark = p;
  char *sc_mark = p;

  
#line 43 "shortcodes.c"
	{
	cs = shortcode_start;
	}

#line 179 "shortcodes.rl"
  
#line 50 "shortcodes.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr635:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st513;
tr728:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st513;
st513:
	if ( ++p == pe )
		goto _test_eof513;
case 513:
#line 86 "shortcodes.c"
	if ( (*p) == 123 )
		goto tr1;
	goto st0;
st0:
	if ( ++p == pe )
		goto _test_eof0;
case 0:
	if ( (*p) == 123 )
		goto tr1;
	goto st0;
tr1:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st1;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
#line 107 "shortcodes.c"
	if ( (*p) == 123 )
		goto tr2;
	goto st0;
tr2:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 121 "shortcodes.c"
	switch( (*p) ) {
		case 37: goto st3;
		case 60: goto st511;
		case 123: goto tr2;
	}
	goto st0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	switch( (*p) ) {
		case 32: goto st3;
		case 123: goto tr1;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st3;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr5;
	} else
		goto tr5;
	goto st0;
tr5:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 155 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr6;
		case 37: goto tr7;
		case 62: goto tr9;
		case 123: goto tr1;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr6;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st4;
		} else if ( (*p) >= 65 )
			goto st4;
	} else
		goto st4;
	goto st0;
tr6:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st5;
tr20:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st5;
tr1074:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
#line 216 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st5;
		case 34: goto tr11;
		case 37: goto st8;
		case 39: goto tr13;
		case 62: goto st298;
		case 123: goto tr1;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st5;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr16;
		} else if ( (*p) >= 65 )
			goto tr16;
	} else
		goto tr14;
	goto st0;
tr11:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
#line 247 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr19;
	}
	goto st6;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	switch( (*p) ) {
		case 32: goto tr20;
		case 37: goto tr21;
		case 62: goto tr22;
		case 123: goto tr1;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr20;
	goto st0;
tr7:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st8;
tr21:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st8;
tr1075:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st8;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
#line 308 "shortcodes.c"
	switch( (*p) ) {
		case 123: goto tr1;
		case 125: goto st9;
	}
	goto st0;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
	switch( (*p) ) {
		case 123: goto tr1;
		case 125: goto tr24;
	}
	goto st0;
tr24:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 106 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st514;
tr41:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 118 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (!sc_list[i].closed && sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
        sc_list[i].closed = 1;
        // We tamper with its data
        sc_list[i].data.start = sc_list[i].whole.start+sc_list[i].whole.len;
        sc_list[i].data.len = sc_mark - start - sc_list[i].data.start - 1;
        // It goes all the way to the end of this tag
        sc_list[i].whole.len = p-start-sc_list[i].whole.start + 1;

        // We ignore every other shortcode because it's nested
        c_sc = i+1;
        found = 1;
        break;
      } 
    }
    if (!found) {
      // We are not closing any shortcode, error
      result.errors[result.errcount].position = 
          sc_list[c_sc].whole.start;
      result.errors[result.errcount].code = ERR_MISMATCHED_CLOSING_TAG;
      result.errcount++;
      // Do NOT increase c_sc
    } 
}
	goto st514;
tr43:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 118 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (!sc_list[i].closed && sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
        sc_list[i].closed = 1;
        // We tamper with its data
        sc_list[i].data.start = sc_list[i].whole.start+sc_list[i].whole.len;
        sc_list[i].data.len = sc_mark - start - sc_list[i].data.start - 1;
        // It goes all the way to the end of this tag
        sc_list[i].whole.len = p-start-sc_list[i].whole.start + 1;

        // We ignore every other shortcode because it's nested
        c_sc = i+1;
        found = 1;
        break;
      } 
    }
    if (!found) {
      // We are not closing any shortcode, error
      result.errors[result.errcount].position = 
          sc_list[c_sc].whole.start;
      result.errors[result.errcount].code = ERR_MISMATCHED_CLOSING_TAG;
      result.errcount++;
      // Do NOT increase c_sc
    } 
}
	goto st514;
tr63:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st514;
tr185:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st514;
tr603:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 106 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st514;
st514:
	if ( ++p == pe )
		goto _test_eof514;
case 514:
#line 453 "shortcodes.c"
	if ( (*p) == 123 )
		goto tr26;
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
	if ( (*p) == 123 )
		goto tr26;
	goto st10;
tr26:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 114 "shortcodes.rl"
	{sc_mark = p;}
	goto st11;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
#line 476 "shortcodes.c"
	if ( (*p) == 123 )
		goto tr27;
	goto st10;
tr27:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 114 "shortcodes.rl"
	{sc_mark = p;}
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
#line 492 "shortcodes.c"
	switch( (*p) ) {
		case 37: goto st13;
		case 60: goto st296;
		case 123: goto tr27;
	}
	goto st10;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	switch( (*p) ) {
		case 32: goto st13;
		case 47: goto st14;
		case 123: goto tr26;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st13;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr31;
	} else
		goto tr31;
	goto st10;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	if ( (*p) == 123 )
		goto tr26;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr32;
	} else if ( (*p) >= 65 )
		goto tr32;
	goto st10;
tr32:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
#line 539 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr33;
		case 37: goto tr34;
		case 62: goto tr36;
		case 123: goto tr26;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr33;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st15;
		} else if ( (*p) >= 65 )
			goto st15;
	} else
		goto st15;
	goto st10;
tr33:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
#line 576 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st16;
		case 37: goto st17;
		case 62: goto st19;
		case 123: goto tr26;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st16;
	goto st10;
tr34:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
#line 604 "shortcodes.c"
	switch( (*p) ) {
		case 123: goto tr26;
		case 125: goto st18;
	}
	goto st10;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	switch( (*p) ) {
		case 123: goto tr26;
		case 125: goto tr41;
	}
	goto st10;
tr36:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 637 "shortcodes.c"
	switch( (*p) ) {
		case 123: goto tr26;
		case 125: goto st20;
	}
	goto st10;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	switch( (*p) ) {
		case 123: goto tr26;
		case 125: goto tr43;
	}
	goto st10;
tr31:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 662 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr44;
		case 37: goto tr45;
		case 62: goto tr47;
		case 123: goto tr26;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr44;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st21;
		} else if ( (*p) >= 65 )
			goto st21;
	} else
		goto st21;
	goto st10;
tr44:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st22;
tr58:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st22;
tr623:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
#line 723 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st22;
		case 34: goto tr49;
		case 37: goto st25;
		case 39: goto tr51;
		case 62: goto st27;
		case 123: goto tr26;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st22;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr54;
		} else if ( (*p) >= 65 )
			goto tr54;
	} else
		goto tr52;
	goto st10;
tr49:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
#line 754 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr57;
	}
	goto st23;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	switch( (*p) ) {
		case 32: goto tr58;
		case 37: goto tr59;
		case 62: goto tr60;
		case 123: goto tr26;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr58;
	goto st10;
tr45:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st25;
tr59:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st25;
tr624:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
#line 815 "shortcodes.c"
	switch( (*p) ) {
		case 123: goto tr26;
		case 125: goto st26;
	}
	goto st10;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	switch( (*p) ) {
		case 123: goto tr26;
		case 125: goto tr24;
	}
	goto st10;
tr47:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st27;
tr60:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st27;
tr626:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 872 "shortcodes.c"
	switch( (*p) ) {
		case 123: goto tr26;
		case 125: goto st28;
	}
	goto st10;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	switch( (*p) ) {
		case 123: goto tr26;
		case 125: goto tr63;
	}
	goto st10;
tr57:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 114 "shortcodes.rl"
	{sc_mark = p;}
	goto st29;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
#line 899 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr64;
	}
	goto st23;
tr64:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 114 "shortcodes.rl"
	{sc_mark = p;}
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 917 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st24;
		case 37: goto st31;
		case 60: goto st291;
		case 123: goto tr64;
	}
	goto st23;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
	switch( (*p) ) {
		case 32: goto st31;
		case 34: goto st24;
		case 47: goto st32;
		case 123: goto tr57;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st31;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr68;
	} else
		goto tr68;
	goto st23;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr57;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr69;
	} else if ( (*p) >= 65 )
		goto tr69;
	goto st23;
tr69:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
#line 968 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr70;
		case 34: goto st24;
		case 37: goto tr71;
		case 62: goto tr73;
		case 123: goto tr57;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr70;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st33;
		} else if ( (*p) >= 65 )
			goto st33;
	} else
		goto st33;
	goto st23;
tr70:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st34;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
#line 1006 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st34;
		case 34: goto st24;
		case 37: goto st35;
		case 62: goto st37;
		case 123: goto tr57;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st34;
	goto st23;
tr71:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st35;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
#line 1035 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr57;
		case 125: goto st36;
	}
	goto st23;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr57;
		case 125: goto tr78;
	}
	goto st23;
tr96:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 106 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st515;
tr78:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 118 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (!sc_list[i].closed && sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
        sc_list[i].closed = 1;
        // We tamper with its data
        sc_list[i].data.start = sc_list[i].whole.start+sc_list[i].whole.len;
        sc_list[i].data.len = sc_mark - start - sc_list[i].data.start - 1;
        // It goes all the way to the end of this tag
        sc_list[i].whole.len = p-start-sc_list[i].whole.start + 1;

        // We ignore every other shortcode because it's nested
        c_sc = i+1;
        found = 1;
        break;
      } 
    }
    if (!found) {
      // We are not closing any shortcode, error
      result.errors[result.errcount].position = 
          sc_list[c_sc].whole.start;
      result.errors[result.errcount].code = ERR_MISMATCHED_CLOSING_TAG;
      result.errcount++;
      // Do NOT increase c_sc
    } 
}
	goto st515;
tr80:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 118 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (!sc_list[i].closed && sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
        sc_list[i].closed = 1;
        // We tamper with its data
        sc_list[i].data.start = sc_list[i].whole.start+sc_list[i].whole.len;
        sc_list[i].data.len = sc_mark - start - sc_list[i].data.start - 1;
        // It goes all the way to the end of this tag
        sc_list[i].whole.len = p-start-sc_list[i].whole.start + 1;

        // We ignore every other shortcode because it's nested
        c_sc = i+1;
        found = 1;
        break;
      } 
    }
    if (!found) {
      // We are not closing any shortcode, error
      result.errors[result.errcount].position = 
          sc_list[c_sc].whole.start;
      result.errors[result.errcount].code = ERR_MISMATCHED_CLOSING_TAG;
      result.errcount++;
      // Do NOT increase c_sc
    } 
}
	goto st515;
tr98:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st515;
tr237:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st515;
tr243:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 106 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st515;
st515:
	if ( ++p == pe )
		goto _test_eof515;
case 515:
#line 1182 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr57;
	}
	goto st23;
tr73:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
#line 1206 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr57;
		case 125: goto st38;
	}
	goto st23;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr57;
		case 125: goto tr80;
	}
	goto st23;
tr68:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
#line 1233 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr81;
		case 34: goto st24;
		case 37: goto tr82;
		case 62: goto tr84;
		case 123: goto tr57;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr81;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st39;
		} else if ( (*p) >= 65 )
			goto st39;
	} else
		goto st39;
	goto st23;
tr81:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st40;
tr92:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st40;
tr612:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
#line 1295 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st40;
		case 34: goto tr86;
		case 37: goto st42;
		case 39: goto tr88;
		case 62: goto st44;
		case 123: goto tr57;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st40;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr91;
		} else if ( (*p) >= 65 )
			goto tr91;
	} else
		goto tr89;
	goto st23;
tr86:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
#line 1326 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr92;
		case 34: goto st24;
		case 37: goto tr93;
		case 62: goto tr94;
		case 123: goto tr57;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr92;
	goto st23;
tr82:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st42;
tr93:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st42;
tr613:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 1379 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr57;
		case 125: goto st43;
	}
	goto st23;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr57;
		case 125: goto tr96;
	}
	goto st23;
tr84:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st44;
tr94:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st44;
tr615:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
#line 1438 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr57;
		case 125: goto st45;
	}
	goto st23;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr57;
		case 125: goto tr98;
	}
	goto st23;
tr88:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st46;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
#line 1465 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st47;
		case 39: goto st41;
		case 123: goto tr102;
	}
	goto st46;
tr131:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
#line 1482 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr104;
		case 37: goto tr105;
		case 39: goto st24;
		case 62: goto tr106;
		case 123: goto tr107;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr104;
	goto st48;
tr51:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
#line 1503 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st24;
		case 123: goto tr107;
	}
	goto st48;
tr107:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 114 "shortcodes.rl"
	{sc_mark = p;}
	goto st49;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
#line 1521 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st24;
		case 123: goto tr108;
	}
	goto st48;
tr108:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 114 "shortcodes.rl"
	{sc_mark = p;}
	goto st50;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
#line 1539 "shortcodes.c"
	switch( (*p) ) {
		case 37: goto st51;
		case 39: goto st24;
		case 60: goto st68;
		case 123: goto tr108;
	}
	goto st48;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
	switch( (*p) ) {
		case 32: goto st51;
		case 39: goto st24;
		case 47: goto st52;
		case 123: goto tr107;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st51;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr112;
	} else
		goto tr112;
	goto st48;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
	switch( (*p) ) {
		case 39: goto st24;
		case 123: goto tr107;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr113;
	} else if ( (*p) >= 65 )
		goto tr113;
	goto st48;
tr113:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st53;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
#line 1590 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr114;
		case 37: goto tr115;
		case 39: goto st24;
		case 62: goto tr117;
		case 123: goto tr107;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr114;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st53;
		} else if ( (*p) >= 65 )
			goto st53;
	} else
		goto st53;
	goto st48;
tr114:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
#line 1628 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st54;
		case 37: goto st55;
		case 39: goto st24;
		case 62: goto st57;
		case 123: goto tr107;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st54;
	goto st48;
tr115:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
#line 1657 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st24;
		case 123: goto tr107;
		case 125: goto st56;
	}
	goto st48;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
	switch( (*p) ) {
		case 39: goto st24;
		case 123: goto tr107;
		case 125: goto tr122;
	}
	goto st48;
tr136:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 106 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st516;
tr122:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 118 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (!sc_list[i].closed && sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
        sc_list[i].closed = 1;
        // We tamper with its data
        sc_list[i].data.start = sc_list[i].whole.start+sc_list[i].whole.len;
        sc_list[i].data.len = sc_mark - start - sc_list[i].data.start - 1;
        // It goes all the way to the end of this tag
        sc_list[i].whole.len = p-start-sc_list[i].whole.start + 1;

        // We ignore every other shortcode because it's nested
        c_sc = i+1;
        found = 1;
        break;
      } 
    }
    if (!found) {
      // We are not closing any shortcode, error
      result.errors[result.errcount].position = 
          sc_list[c_sc].whole.start;
      result.errors[result.errcount].code = ERR_MISMATCHED_CLOSING_TAG;
      result.errcount++;
      // Do NOT increase c_sc
    } 
}
	goto st516;
tr124:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 118 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (!sc_list[i].closed && sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
        sc_list[i].closed = 1;
        // We tamper with its data
        sc_list[i].data.start = sc_list[i].whole.start+sc_list[i].whole.len;
        sc_list[i].data.len = sc_mark - start - sc_list[i].data.start - 1;
        // It goes all the way to the end of this tag
        sc_list[i].whole.len = p-start-sc_list[i].whole.start + 1;

        // We ignore every other shortcode because it's nested
        c_sc = i+1;
        found = 1;
        break;
      } 
    }
    if (!found) {
      // We are not closing any shortcode, error
      result.errors[result.errcount].position = 
          sc_list[c_sc].whole.start;
      result.errors[result.errcount].code = ERR_MISMATCHED_CLOSING_TAG;
      result.errcount++;
      // Do NOT increase c_sc
    } 
}
	goto st516;
tr142:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st516;
tr165:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st516;
tr167:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 106 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st516;
st516:
	if ( ++p == pe )
		goto _test_eof516;
case 516:
#line 1804 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st24;
		case 123: goto tr107;
	}
	goto st48;
tr117:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st57;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
#line 1828 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st24;
		case 123: goto tr107;
		case 125: goto st58;
	}
	goto st48;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	switch( (*p) ) {
		case 39: goto st24;
		case 123: goto tr107;
		case 125: goto tr124;
	}
	goto st48;
tr112:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st59;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
#line 1855 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr125;
		case 37: goto tr126;
		case 39: goto st24;
		case 62: goto tr128;
		case 123: goto tr107;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr125;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st59;
		} else if ( (*p) >= 65 )
			goto st59;
	} else
		goto st59;
	goto st48;
tr125:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st60;
tr104:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st60;
tr137:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st60;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
#line 1917 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st60;
		case 34: goto tr88;
		case 37: goto st61;
		case 39: goto tr131;
		case 62: goto st64;
		case 123: goto tr107;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st60;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr134;
		} else if ( (*p) >= 65 )
			goto tr134;
	} else
		goto tr132;
	goto st48;
tr126:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st61;
tr105:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st61;
tr138:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st61;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
#line 1980 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st24;
		case 123: goto tr107;
		case 125: goto st62;
	}
	goto st48;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	switch( (*p) ) {
		case 39: goto st24;
		case 123: goto tr107;
		case 125: goto tr136;
	}
	goto st48;
tr132:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
#line 2007 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr137;
		case 37: goto tr138;
		case 39: goto st24;
		case 62: goto tr140;
		case 123: goto tr107;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr137;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st63;
		} else if ( (*p) >= 65 )
			goto st63;
	} else
		goto st63;
	goto st48;
tr128:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st64;
tr106:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st64;
tr140:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
#line 2069 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st24;
		case 123: goto tr107;
		case 125: goto st65;
	}
	goto st48;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	switch( (*p) ) {
		case 39: goto st24;
		case 123: goto tr107;
		case 125: goto tr142;
	}
	goto st48;
tr134:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st66;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
#line 2096 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr137;
		case 37: goto tr138;
		case 39: goto st24;
		case 61: goto tr143;
		case 62: goto tr140;
		case 123: goto tr107;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr137;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st66;
		} else if ( (*p) >= 65 )
			goto st66;
	} else
		goto st63;
	goto st48;
tr143:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
#line 2128 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr88;
		case 39: goto tr131;
		case 123: goto tr107;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr132;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr132;
	} else
		goto tr132;
	goto st48;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
	switch( (*p) ) {
		case 32: goto st68;
		case 39: goto st24;
		case 47: goto st52;
		case 123: goto tr107;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st68;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr145;
	} else
		goto tr145;
	goto st48;
tr145:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st69;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
#line 2172 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr146;
		case 37: goto tr147;
		case 39: goto st24;
		case 62: goto tr149;
		case 123: goto tr107;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr146;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st69;
		} else if ( (*p) >= 65 )
			goto st69;
	} else
		goto st69;
	goto st48;
tr146:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st70;
tr161:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st70;
tr606:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st70;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
#line 2234 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st70;
		case 34: goto tr151;
		case 37: goto st73;
		case 39: goto tr153;
		case 62: goto st75;
		case 123: goto tr107;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st70;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr156;
		} else if ( (*p) >= 65 )
			goto tr156;
	} else
		goto tr154;
	goto st48;
tr151:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st71;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
#line 2265 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st72;
		case 39: goto st77;
		case 123: goto tr160;
	}
	goto st71;
tr212:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st72;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
#line 2282 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr161;
		case 37: goto tr162;
		case 39: goto st24;
		case 62: goto tr163;
		case 123: goto tr107;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr161;
	goto st48;
tr147:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st73;
tr162:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st73;
tr607:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st73;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
#line 2335 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st24;
		case 123: goto tr107;
		case 125: goto st74;
	}
	goto st48;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
	switch( (*p) ) {
		case 39: goto st24;
		case 123: goto tr107;
		case 125: goto tr165;
	}
	goto st48;
tr149:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st75;
tr163:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st75;
tr609:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st75;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
#line 2394 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st24;
		case 123: goto tr107;
		case 125: goto st76;
	}
	goto st48;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
	switch( (*p) ) {
		case 39: goto st24;
		case 123: goto tr107;
		case 125: goto tr167;
	}
	goto st48;
tr231:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st77;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
#line 2421 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr169;
		case 34: goto st79;
		case 37: goto tr171;
		case 62: goto tr172;
		case 123: goto tr173;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr169;
	goto st78;
tr178:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st78;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
#line 2442 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st79;
		case 123: goto tr173;
	}
	goto st78;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	switch( (*p) ) {
		case 32: goto tr174;
		case 37: goto tr175;
		case 62: goto tr176;
		case 123: goto tr26;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr174;
	goto st10;
tr630:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st80;
tr174:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st80;
tr598:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st80;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
#line 2503 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st80;
		case 34: goto tr178;
		case 37: goto st81;
		case 39: goto tr180;
		case 62: goto st281;
		case 123: goto tr26;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st80;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr183;
		} else if ( (*p) >= 65 )
			goto tr183;
	} else
		goto tr181;
	goto st10;
tr631:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st81;
tr175:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st81;
tr599:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st81;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
#line 2566 "shortcodes.c"
	switch( (*p) ) {
		case 123: goto tr26;
		case 125: goto st82;
	}
	goto st10;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
	switch( (*p) ) {
		case 123: goto tr26;
		case 125: goto tr185;
	}
	goto st10;
tr180:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st83;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
#line 2591 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st79;
		case 123: goto tr187;
	}
	goto st83;
tr187:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 114 "shortcodes.rl"
	{sc_mark = p;}
	goto st84;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
#line 2609 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st79;
		case 123: goto tr188;
	}
	goto st83;
tr188:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 114 "shortcodes.rl"
	{sc_mark = p;}
	goto st85;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
#line 2627 "shortcodes.c"
	switch( (*p) ) {
		case 37: goto st86;
		case 39: goto st79;
		case 60: goto st278;
		case 123: goto tr188;
	}
	goto st83;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	switch( (*p) ) {
		case 32: goto st86;
		case 39: goto st79;
		case 47: goto st87;
		case 123: goto tr187;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st86;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr192;
	} else
		goto tr192;
	goto st83;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	switch( (*p) ) {
		case 39: goto st79;
		case 123: goto tr187;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr193;
	} else if ( (*p) >= 65 )
		goto tr193;
	goto st83;
tr193:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st88;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
#line 2678 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr194;
		case 37: goto tr195;
		case 39: goto st79;
		case 62: goto tr197;
		case 123: goto tr187;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr194;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st88;
		} else if ( (*p) >= 65 )
			goto st88;
	} else
		goto st88;
	goto st83;
tr194:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st89;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
#line 2716 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st89;
		case 37: goto st90;
		case 39: goto st79;
		case 62: goto st92;
		case 123: goto tr187;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st89;
	goto st83;
tr195:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st90;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
#line 2745 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st79;
		case 123: goto tr187;
		case 125: goto st91;
	}
	goto st83;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
	switch( (*p) ) {
		case 39: goto st79;
		case 123: goto tr187;
		case 125: goto tr202;
	}
	goto st83;
tr224:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 106 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st517;
tr202:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 118 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (!sc_list[i].closed && sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
        sc_list[i].closed = 1;
        // We tamper with its data
        sc_list[i].data.start = sc_list[i].whole.start+sc_list[i].whole.len;
        sc_list[i].data.len = sc_mark - start - sc_list[i].data.start - 1;
        // It goes all the way to the end of this tag
        sc_list[i].whole.len = p-start-sc_list[i].whole.start + 1;

        // We ignore every other shortcode because it's nested
        c_sc = i+1;
        found = 1;
        break;
      } 
    }
    if (!found) {
      // We are not closing any shortcode, error
      result.errors[result.errcount].position = 
          sc_list[c_sc].whole.start;
      result.errors[result.errcount].code = ERR_MISMATCHED_CLOSING_TAG;
      result.errcount++;
      // Do NOT increase c_sc
    } 
}
	goto st517;
tr204:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 118 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (!sc_list[i].closed && sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
        sc_list[i].closed = 1;
        // We tamper with its data
        sc_list[i].data.start = sc_list[i].whole.start+sc_list[i].whole.len;
        sc_list[i].data.len = sc_mark - start - sc_list[i].data.start - 1;
        // It goes all the way to the end of this tag
        sc_list[i].whole.len = p-start-sc_list[i].whole.start + 1;

        // We ignore every other shortcode because it's nested
        c_sc = i+1;
        found = 1;
        break;
      } 
    }
    if (!found) {
      // We are not closing any shortcode, error
      result.errors[result.errcount].position = 
          sc_list[c_sc].whole.start;
      result.errors[result.errcount].code = ERR_MISMATCHED_CLOSING_TAG;
      result.errcount++;
      // Do NOT increase c_sc
    } 
}
	goto st517;
tr226:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st517;
tr359:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st517;
tr365:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 106 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st517;
st517:
	if ( ++p == pe )
		goto _test_eof517;
case 517:
#line 2892 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st79;
		case 123: goto tr187;
	}
	goto st83;
tr197:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st92;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
#line 2916 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st79;
		case 123: goto tr187;
		case 125: goto st93;
	}
	goto st83;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
	switch( (*p) ) {
		case 39: goto st79;
		case 123: goto tr187;
		case 125: goto tr204;
	}
	goto st83;
tr192:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st94;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
#line 2943 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr205;
		case 37: goto tr206;
		case 39: goto st79;
		case 62: goto tr208;
		case 123: goto tr187;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr205;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st94;
		} else if ( (*p) >= 65 )
			goto st94;
	} else
		goto st94;
	goto st83;
tr205:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st95;
tr220:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st95;
tr587:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st95;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
#line 3005 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st95;
		case 34: goto tr210;
		case 37: goto st98;
		case 39: goto tr212;
		case 62: goto st100;
		case 123: goto tr187;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st95;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr215;
		} else if ( (*p) >= 65 )
			goto tr215;
	} else
		goto tr213;
	goto st83;
tr210:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st96;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
#line 3036 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st97;
		case 39: goto st102;
		case 123: goto tr219;
	}
	goto st96;
tr153:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st97;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
#line 3053 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr220;
		case 37: goto tr221;
		case 39: goto st79;
		case 62: goto tr222;
		case 123: goto tr187;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr220;
	goto st83;
tr206:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st98;
tr221:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st98;
tr588:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st98;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
#line 3106 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st79;
		case 123: goto tr187;
		case 125: goto st99;
	}
	goto st83;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	switch( (*p) ) {
		case 39: goto st79;
		case 123: goto tr187;
		case 125: goto tr224;
	}
	goto st83;
tr208:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st100;
tr222:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st100;
tr590:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st100;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
#line 3165 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st79;
		case 123: goto tr187;
		case 125: goto st101;
	}
	goto st83;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
	switch( (*p) ) {
		case 39: goto st79;
		case 123: goto tr187;
		case 125: goto tr226;
	}
	goto st83;
tr400:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st102;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
#line 3192 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr227;
		case 34: goto st24;
		case 37: goto tr228;
		case 62: goto tr229;
		case 123: goto tr57;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr227;
	goto st23;
tr619:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st103;
tr227:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st103;
tr238:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st103;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
#line 3245 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st103;
		case 34: goto tr231;
		case 37: goto st104;
		case 39: goto tr210;
		case 62: goto st107;
		case 123: goto tr57;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st103;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr235;
		} else if ( (*p) >= 65 )
			goto tr235;
	} else
		goto tr233;
	goto st23;
tr620:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st104;
tr228:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st104;
tr239:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st104;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
#line 3308 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr57;
		case 125: goto st105;
	}
	goto st23;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr57;
		case 125: goto tr237;
	}
	goto st23;
tr233:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st106;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
#line 3335 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr238;
		case 34: goto st24;
		case 37: goto tr239;
		case 62: goto tr241;
		case 123: goto tr57;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr238;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st106;
		} else if ( (*p) >= 65 )
			goto st106;
	} else
		goto st106;
	goto st23;
tr622:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st107;
tr229:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st107;
tr241:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st107;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
#line 3397 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr57;
		case 125: goto st108;
	}
	goto st23;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr57;
		case 125: goto tr243;
	}
	goto st23;
tr235:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st109;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
#line 3424 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr238;
		case 34: goto st24;
		case 37: goto tr239;
		case 61: goto tr244;
		case 62: goto tr241;
		case 123: goto tr57;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr238;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st109;
		} else if ( (*p) >= 65 )
			goto st109;
	} else
		goto st106;
	goto st23;
tr244:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st110;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
#line 3456 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr231;
		case 39: goto tr210;
		case 123: goto tr57;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr233;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr233;
	} else
		goto tr233;
	goto st23;
tr219:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 114 "shortcodes.rl"
	{sc_mark = p;}
	goto st111;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
#line 3483 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st97;
		case 39: goto st102;
		case 123: goto tr246;
	}
	goto st96;
tr246:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 114 "shortcodes.rl"
	{sc_mark = p;}
	goto st112;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
#line 3502 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st97;
		case 37: goto st113;
		case 39: goto st102;
		case 60: goto st273;
		case 123: goto tr246;
	}
	goto st96;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
	switch( (*p) ) {
		case 32: goto st113;
		case 34: goto st97;
		case 39: goto st102;
		case 47: goto st114;
		case 123: goto tr219;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st113;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr250;
	} else
		goto tr250;
	goto st96;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
	switch( (*p) ) {
		case 34: goto st97;
		case 39: goto st102;
		case 123: goto tr219;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr251;
	} else if ( (*p) >= 65 )
		goto tr251;
	goto st96;
tr251:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st115;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
#line 3556 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr252;
		case 34: goto st97;
		case 37: goto tr253;
		case 39: goto st102;
		case 62: goto tr255;
		case 123: goto tr219;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr252;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st115;
		} else if ( (*p) >= 65 )
			goto st115;
	} else
		goto st115;
	goto st96;
tr252:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st116;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
#line 3595 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st116;
		case 34: goto st97;
		case 37: goto st117;
		case 39: goto st102;
		case 62: goto st119;
		case 123: goto tr219;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st116;
	goto st96;
tr253:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st117;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
#line 3625 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st97;
		case 39: goto st102;
		case 123: goto tr219;
		case 125: goto st118;
	}
	goto st96;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
	switch( (*p) ) {
		case 34: goto st97;
		case 39: goto st102;
		case 123: goto tr219;
		case 125: goto tr260;
	}
	goto st96;
tr278:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 106 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st518;
tr260:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 118 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (!sc_list[i].closed && sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
        sc_list[i].closed = 1;
        // We tamper with its data
        sc_list[i].data.start = sc_list[i].whole.start+sc_list[i].whole.len;
        sc_list[i].data.len = sc_mark - start - sc_list[i].data.start - 1;
        // It goes all the way to the end of this tag
        sc_list[i].whole.len = p-start-sc_list[i].whole.start + 1;

        // We ignore every other shortcode because it's nested
        c_sc = i+1;
        found = 1;
        break;
      } 
    }
    if (!found) {
      // We are not closing any shortcode, error
      result.errors[result.errcount].position = 
          sc_list[c_sc].whole.start;
      result.errors[result.errcount].code = ERR_MISMATCHED_CLOSING_TAG;
      result.errcount++;
      // Do NOT increase c_sc
    } 
}
	goto st518;
tr262:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 118 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (!sc_list[i].closed && sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
        sc_list[i].closed = 1;
        // We tamper with its data
        sc_list[i].data.start = sc_list[i].whole.start+sc_list[i].whole.len;
        sc_list[i].data.len = sc_mark - start - sc_list[i].data.start - 1;
        // It goes all the way to the end of this tag
        sc_list[i].whole.len = p-start-sc_list[i].whole.start + 1;

        // We ignore every other shortcode because it's nested
        c_sc = i+1;
        found = 1;
        break;
      } 
    }
    if (!found) {
      // We are not closing any shortcode, error
      result.errors[result.errcount].position = 
          sc_list[c_sc].whole.start;
      result.errors[result.errcount].code = ERR_MISMATCHED_CLOSING_TAG;
      result.errcount++;
      // Do NOT increase c_sc
    } 
}
	goto st518;
tr280:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st518;
tr465:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st518;
tr471:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 106 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st518;
st518:
	if ( ++p == pe )
		goto _test_eof518;
case 518:
#line 3774 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st97;
		case 39: goto st102;
		case 123: goto tr219;
	}
	goto st96;
tr255:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st119;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
#line 3799 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st97;
		case 39: goto st102;
		case 123: goto tr219;
		case 125: goto st120;
	}
	goto st96;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	switch( (*p) ) {
		case 34: goto st97;
		case 39: goto st102;
		case 123: goto tr219;
		case 125: goto tr262;
	}
	goto st96;
tr250:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st121;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
#line 3828 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr263;
		case 34: goto st97;
		case 37: goto tr264;
		case 39: goto st102;
		case 62: goto tr266;
		case 123: goto tr219;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr263;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st121;
		} else if ( (*p) >= 65 )
			goto st121;
	} else
		goto st121;
	goto st96;
tr263:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st122;
tr274:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st122;
tr576:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st122;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
#line 3891 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st122;
		case 34: goto tr268;
		case 37: goto st124;
		case 39: goto tr270;
		case 62: goto st126;
		case 123: goto tr219;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st122;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr273;
		} else if ( (*p) >= 65 )
			goto tr273;
	} else
		goto tr271;
	goto st96;
tr268:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st123;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
#line 3922 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr274;
		case 34: goto st97;
		case 37: goto tr275;
		case 39: goto st102;
		case 62: goto tr276;
		case 123: goto tr219;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr274;
	goto st96;
tr264:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st124;
tr275:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st124;
tr577:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st124;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
#line 3976 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st97;
		case 39: goto st102;
		case 123: goto tr219;
		case 125: goto st125;
	}
	goto st96;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
	switch( (*p) ) {
		case 34: goto st97;
		case 39: goto st102;
		case 123: goto tr219;
		case 125: goto tr278;
	}
	goto st96;
tr266:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st126;
tr276:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st126;
tr579:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st126;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
#line 4037 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st97;
		case 39: goto st102;
		case 123: goto tr219;
		case 125: goto st127;
	}
	goto st96;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
	switch( (*p) ) {
		case 34: goto st97;
		case 39: goto st102;
		case 123: goto tr219;
		case 125: goto tr280;
	}
	goto st96;
tr270:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st128;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
#line 4066 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr281;
		case 34: goto st47;
		case 37: goto tr282;
		case 39: goto st41;
		case 62: goto tr283;
		case 123: goto tr102;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr281;
	goto st46;
tr563:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st129;
tr281:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st129;
tr570:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st129;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
#line 4120 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st129;
		case 34: goto tr285;
		case 37: goto st241;
		case 39: goto tr268;
		case 62: goto st264;
		case 123: goto tr102;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st129;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr289;
		} else if ( (*p) >= 65 )
			goto tr289;
	} else
		goto tr287;
	goto st46;
tr285:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st130;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
#line 4151 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr290;
		case 34: goto st72;
		case 37: goto tr291;
		case 39: goto st77;
		case 62: goto tr292;
		case 123: goto tr160;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr290;
	goto st71;
tr316:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st131;
tr290:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st131;
tr515:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st131;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
#line 4205 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st131;
		case 34: goto tr270;
		case 37: goto st132;
		case 39: goto tr285;
		case 62: goto st144;
		case 123: goto tr160;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st131;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr297;
		} else if ( (*p) >= 65 )
			goto tr297;
	} else
		goto tr295;
	goto st71;
tr317:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st132;
tr291:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st132;
tr516:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st132;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
#line 4268 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st72;
		case 39: goto st77;
		case 123: goto tr160;
		case 125: goto st237;
	}
	goto st71;
tr160:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 114 "shortcodes.rl"
	{sc_mark = p;}
	goto st133;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
#line 4288 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st72;
		case 39: goto st77;
		case 123: goto tr299;
	}
	goto st71;
tr299:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 114 "shortcodes.rl"
	{sc_mark = p;}
	goto st134;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
#line 4307 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st72;
		case 37: goto st135;
		case 39: goto st77;
		case 60: goto st146;
		case 123: goto tr299;
	}
	goto st71;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
	switch( (*p) ) {
		case 32: goto st135;
		case 34: goto st72;
		case 39: goto st77;
		case 47: goto st136;
		case 123: goto tr160;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st135;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr303;
	} else
		goto tr303;
	goto st71;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
	switch( (*p) ) {
		case 34: goto st72;
		case 39: goto st77;
		case 123: goto tr160;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr304;
	} else if ( (*p) >= 65 )
		goto tr304;
	goto st71;
tr304:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st137;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
#line 4361 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr305;
		case 34: goto st72;
		case 37: goto tr306;
		case 39: goto st77;
		case 62: goto tr308;
		case 123: goto tr160;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr305;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st137;
		} else if ( (*p) >= 65 )
			goto st137;
	} else
		goto st137;
	goto st71;
tr305:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st138;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
#line 4400 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st138;
		case 34: goto st72;
		case 37: goto st139;
		case 39: goto st77;
		case 62: goto st141;
		case 123: goto tr160;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st138;
	goto st71;
tr306:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st139;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
#line 4430 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st72;
		case 39: goto st77;
		case 123: goto tr160;
		case 125: goto st140;
	}
	goto st71;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
	switch( (*p) ) {
		case 34: goto st72;
		case 39: goto st77;
		case 123: goto tr160;
		case 125: goto tr313;
	}
	goto st71;
tr514:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 106 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st519;
tr313:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 118 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (!sc_list[i].closed && sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
        sc_list[i].closed = 1;
        // We tamper with its data
        sc_list[i].data.start = sc_list[i].whole.start+sc_list[i].whole.len;
        sc_list[i].data.len = sc_mark - start - sc_list[i].data.start - 1;
        // It goes all the way to the end of this tag
        sc_list[i].whole.len = p-start-sc_list[i].whole.start + 1;

        // We ignore every other shortcode because it's nested
        c_sc = i+1;
        found = 1;
        break;
      } 
    }
    if (!found) {
      // We are not closing any shortcode, error
      result.errors[result.errcount].position = 
          sc_list[c_sc].whole.start;
      result.errors[result.errcount].code = ERR_MISMATCHED_CLOSING_TAG;
      result.errcount++;
      // Do NOT increase c_sc
    } 
}
	goto st519;
tr315:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 118 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (!sc_list[i].closed && sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
        sc_list[i].closed = 1;
        // We tamper with its data
        sc_list[i].data.start = sc_list[i].whole.start+sc_list[i].whole.len;
        sc_list[i].data.len = sc_mark - start - sc_list[i].data.start - 1;
        // It goes all the way to the end of this tag
        sc_list[i].whole.len = p-start-sc_list[i].whole.start + 1;

        // We ignore every other shortcode because it's nested
        c_sc = i+1;
        found = 1;
        break;
      } 
    }
    if (!found) {
      // We are not closing any shortcode, error
      result.errors[result.errcount].position = 
          sc_list[c_sc].whole.start;
      result.errors[result.errcount].code = ERR_MISMATCHED_CLOSING_TAG;
      result.errcount++;
      // Do NOT increase c_sc
    } 
}
	goto st519;
tr321:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st519;
tr338:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st519;
tr340:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 106 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st519;
st519:
	if ( ++p == pe )
		goto _test_eof519;
case 519:
#line 4579 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st72;
		case 39: goto st77;
		case 123: goto tr160;
	}
	goto st71;
tr308:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st141;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
#line 4604 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st72;
		case 39: goto st77;
		case 123: goto tr160;
		case 125: goto st142;
	}
	goto st71;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	switch( (*p) ) {
		case 34: goto st72;
		case 39: goto st77;
		case 123: goto tr160;
		case 125: goto tr315;
	}
	goto st71;
tr303:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st143;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
#line 4633 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr316;
		case 34: goto st72;
		case 37: goto tr317;
		case 39: goto st77;
		case 62: goto tr319;
		case 123: goto tr160;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr316;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st143;
		} else if ( (*p) >= 65 )
			goto st143;
	} else
		goto st143;
	goto st71;
tr319:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st144;
tr292:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st144;
tr518:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st144;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
#line 4696 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st72;
		case 39: goto st77;
		case 123: goto tr160;
		case 125: goto st145;
	}
	goto st71;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
	switch( (*p) ) {
		case 34: goto st72;
		case 39: goto st77;
		case 123: goto tr160;
		case 125: goto tr321;
	}
	goto st71;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	switch( (*p) ) {
		case 32: goto st146;
		case 34: goto st72;
		case 39: goto st77;
		case 47: goto st136;
		case 123: goto tr160;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st146;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr322;
	} else
		goto tr322;
	goto st71;
tr322:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st147;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
#line 4745 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr323;
		case 34: goto st72;
		case 37: goto tr324;
		case 39: goto st77;
		case 62: goto tr326;
		case 123: goto tr160;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr323;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st147;
		} else if ( (*p) >= 65 )
			goto st147;
	} else
		goto st147;
	goto st71;
tr323:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st148;
tr334:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st148;
tr508:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st148;
st148:
	if ( ++p == pe )
		goto _test_eof148;
case 148:
#line 4808 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st148;
		case 34: goto tr328;
		case 37: goto st150;
		case 39: goto tr330;
		case 62: goto st152;
		case 123: goto tr160;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st148;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr333;
		} else if ( (*p) >= 65 )
			goto tr333;
	} else
		goto tr331;
	goto st71;
tr328:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st149;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
#line 4839 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr334;
		case 34: goto st72;
		case 37: goto tr335;
		case 39: goto st77;
		case 62: goto tr336;
		case 123: goto tr160;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr334;
	goto st71;
tr324:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st150;
tr335:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st150;
tr509:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st150;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
#line 4893 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st72;
		case 39: goto st77;
		case 123: goto tr160;
		case 125: goto st151;
	}
	goto st71;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
	switch( (*p) ) {
		case 34: goto st72;
		case 39: goto st77;
		case 123: goto tr160;
		case 125: goto tr338;
	}
	goto st71;
tr326:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st152;
tr336:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st152;
tr511:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st152;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
#line 4954 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st72;
		case 39: goto st77;
		case 123: goto tr160;
		case 125: goto st153;
	}
	goto st71;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
	switch( (*p) ) {
		case 34: goto st72;
		case 39: goto st77;
		case 123: goto tr160;
		case 125: goto tr340;
	}
	goto st71;
tr330:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st154;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
#line 4983 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr342;
		case 34: goto st156;
		case 37: goto tr344;
		case 39: goto st165;
		case 62: goto tr346;
		case 123: goto tr347;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr342;
	goto st155;
tr352:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st155;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
#line 5005 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st156;
		case 39: goto st165;
		case 123: goto tr347;
	}
	goto st155;
tr354:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st156;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
#line 5022 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr348;
		case 37: goto tr349;
		case 39: goto st79;
		case 62: goto tr350;
		case 123: goto tr187;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr348;
	goto st83;
tr594:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st157;
tr348:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st157;
tr360:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st157;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
#line 5075 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st157;
		case 34: goto tr352;
		case 37: goto st158;
		case 39: goto tr354;
		case 62: goto st161;
		case 123: goto tr187;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st157;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr357;
		} else if ( (*p) >= 65 )
			goto tr357;
	} else
		goto tr355;
	goto st83;
tr595:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st158;
tr349:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st158;
tr361:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st158;
st158:
	if ( ++p == pe )
		goto _test_eof158;
case 158:
#line 5138 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st79;
		case 123: goto tr187;
		case 125: goto st159;
	}
	goto st83;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
	switch( (*p) ) {
		case 39: goto st79;
		case 123: goto tr187;
		case 125: goto tr359;
	}
	goto st83;
tr355:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st160;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
#line 5165 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr360;
		case 37: goto tr361;
		case 39: goto st79;
		case 62: goto tr363;
		case 123: goto tr187;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr360;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st160;
		} else if ( (*p) >= 65 )
			goto st160;
	} else
		goto st160;
	goto st83;
tr597:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st161;
tr350:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st161;
tr363:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st161;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
#line 5227 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st79;
		case 123: goto tr187;
		case 125: goto st162;
	}
	goto st83;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
	switch( (*p) ) {
		case 39: goto st79;
		case 123: goto tr187;
		case 125: goto tr365;
	}
	goto st83;
tr357:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st163;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
#line 5254 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr360;
		case 37: goto tr361;
		case 39: goto st79;
		case 61: goto tr366;
		case 62: goto tr363;
		case 123: goto tr187;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr360;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st163;
		} else if ( (*p) >= 65 )
			goto st163;
	} else
		goto st160;
	goto st83;
tr366:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st164;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
#line 5286 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr352;
		case 39: goto tr354;
		case 123: goto tr187;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr355;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr355;
	} else
		goto tr355;
	goto st83;
tr372:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st165;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
#line 5311 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr368;
		case 34: goto st79;
		case 37: goto tr369;
		case 62: goto tr370;
		case 123: goto tr173;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr368;
	goto st78;
tr416:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st166;
tr368:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st166;
tr423:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st166;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
#line 5364 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st166;
		case 34: goto tr372;
		case 37: goto st167;
		case 39: goto tr352;
		case 62: goto st189;
		case 123: goto tr173;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st166;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr376;
		} else if ( (*p) >= 65 )
			goto tr376;
	} else
		goto tr374;
	goto st78;
tr417:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st167;
tr369:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st167;
tr424:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st167;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
#line 5427 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st79;
		case 123: goto tr173;
		case 125: goto st191;
	}
	goto st78;
tr173:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 114 "shortcodes.rl"
	{sc_mark = p;}
	goto st168;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
#line 5446 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st79;
		case 123: goto tr378;
	}
	goto st78;
tr378:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 114 "shortcodes.rl"
	{sc_mark = p;}
	goto st169;
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
#line 5464 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st79;
		case 37: goto st170;
		case 60: goto st187;
		case 123: goto tr378;
	}
	goto st78;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
	switch( (*p) ) {
		case 32: goto st170;
		case 34: goto st79;
		case 47: goto st171;
		case 123: goto tr173;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st170;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr382;
	} else
		goto tr382;
	goto st78;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
	switch( (*p) ) {
		case 34: goto st79;
		case 123: goto tr173;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr383;
	} else if ( (*p) >= 65 )
		goto tr383;
	goto st78;
tr383:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st172;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
#line 5515 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr384;
		case 34: goto st79;
		case 37: goto tr385;
		case 62: goto tr387;
		case 123: goto tr173;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr384;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st172;
		} else if ( (*p) >= 65 )
			goto st172;
	} else
		goto st172;
	goto st78;
tr384:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st173;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
#line 5553 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st173;
		case 34: goto st79;
		case 37: goto st174;
		case 62: goto st176;
		case 123: goto tr173;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st173;
	goto st78;
tr385:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st174;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
#line 5582 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st79;
		case 123: goto tr173;
		case 125: goto st175;
	}
	goto st78;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
	switch( (*p) ) {
		case 34: goto st79;
		case 123: goto tr173;
		case 125: goto tr392;
	}
	goto st78;
tr406:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 106 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st520;
tr392:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 118 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (!sc_list[i].closed && sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
        sc_list[i].closed = 1;
        // We tamper with its data
        sc_list[i].data.start = sc_list[i].whole.start+sc_list[i].whole.len;
        sc_list[i].data.len = sc_mark - start - sc_list[i].data.start - 1;
        // It goes all the way to the end of this tag
        sc_list[i].whole.len = p-start-sc_list[i].whole.start + 1;

        // We ignore every other shortcode because it's nested
        c_sc = i+1;
        found = 1;
        break;
      } 
    }
    if (!found) {
      // We are not closing any shortcode, error
      result.errors[result.errcount].position = 
          sc_list[c_sc].whole.start;
      result.errors[result.errcount].code = ERR_MISMATCHED_CLOSING_TAG;
      result.errcount++;
      // Do NOT increase c_sc
    } 
}
	goto st520;
tr394:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 118 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (!sc_list[i].closed && sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
        sc_list[i].closed = 1;
        // We tamper with its data
        sc_list[i].data.start = sc_list[i].whole.start+sc_list[i].whole.len;
        sc_list[i].data.len = sc_mark - start - sc_list[i].data.start - 1;
        // It goes all the way to the end of this tag
        sc_list[i].whole.len = p-start-sc_list[i].whole.start + 1;

        // We ignore every other shortcode because it's nested
        c_sc = i+1;
        found = 1;
        break;
      } 
    }
    if (!found) {
      // We are not closing any shortcode, error
      result.errors[result.errcount].position = 
          sc_list[c_sc].whole.start;
      result.errors[result.errcount].code = ERR_MISMATCHED_CLOSING_TAG;
      result.errcount++;
      // Do NOT increase c_sc
    } 
}
	goto st520;
tr412:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st520;
tr422:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st520;
tr421:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 106 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st520;
st520:
	if ( ++p == pe )
		goto _test_eof520;
case 520:
#line 5729 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st79;
		case 123: goto tr173;
	}
	goto st78;
tr387:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st176;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
#line 5753 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st79;
		case 123: goto tr173;
		case 125: goto st177;
	}
	goto st78;
st177:
	if ( ++p == pe )
		goto _test_eof177;
case 177:
	switch( (*p) ) {
		case 34: goto st79;
		case 123: goto tr173;
		case 125: goto tr394;
	}
	goto st78;
tr382:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st178;
st178:
	if ( ++p == pe )
		goto _test_eof178;
case 178:
#line 5780 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr395;
		case 34: goto st79;
		case 37: goto tr396;
		case 62: goto tr398;
		case 123: goto tr173;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr395;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st178;
		} else if ( (*p) >= 65 )
			goto st178;
	} else
		goto st178;
	goto st78;
tr395:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st179;
tr169:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st179;
tr407:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st179;
st179:
	if ( ++p == pe )
		goto _test_eof179;
case 179:
#line 5842 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st179;
		case 34: goto tr400;
		case 37: goto st180;
		case 39: goto tr151;
		case 62: goto st183;
		case 123: goto tr173;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st179;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr404;
		} else if ( (*p) >= 65 )
			goto tr404;
	} else
		goto tr402;
	goto st78;
tr396:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st180;
tr171:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st180;
tr408:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st180;
st180:
	if ( ++p == pe )
		goto _test_eof180;
case 180:
#line 5905 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st79;
		case 123: goto tr173;
		case 125: goto st181;
	}
	goto st78;
st181:
	if ( ++p == pe )
		goto _test_eof181;
case 181:
	switch( (*p) ) {
		case 34: goto st79;
		case 123: goto tr173;
		case 125: goto tr406;
	}
	goto st78;
tr402:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st182;
st182:
	if ( ++p == pe )
		goto _test_eof182;
case 182:
#line 5932 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr407;
		case 34: goto st79;
		case 37: goto tr408;
		case 62: goto tr410;
		case 123: goto tr173;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr407;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st182;
		} else if ( (*p) >= 65 )
			goto st182;
	} else
		goto st182;
	goto st78;
tr398:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st183;
tr172:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st183;
tr410:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st183;
st183:
	if ( ++p == pe )
		goto _test_eof183;
case 183:
#line 5994 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st79;
		case 123: goto tr173;
		case 125: goto st184;
	}
	goto st78;
st184:
	if ( ++p == pe )
		goto _test_eof184;
case 184:
	switch( (*p) ) {
		case 34: goto st79;
		case 123: goto tr173;
		case 125: goto tr412;
	}
	goto st78;
tr404:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st185;
st185:
	if ( ++p == pe )
		goto _test_eof185;
case 185:
#line 6021 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr407;
		case 34: goto st79;
		case 37: goto tr408;
		case 61: goto tr413;
		case 62: goto tr410;
		case 123: goto tr173;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr407;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st185;
		} else if ( (*p) >= 65 )
			goto st185;
	} else
		goto st182;
	goto st78;
tr413:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st186;
st186:
	if ( ++p == pe )
		goto _test_eof186;
case 186:
#line 6053 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr400;
		case 39: goto tr151;
		case 123: goto tr173;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr402;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr402;
	} else
		goto tr402;
	goto st78;
st187:
	if ( ++p == pe )
		goto _test_eof187;
case 187:
	switch( (*p) ) {
		case 32: goto st187;
		case 34: goto st79;
		case 47: goto st171;
		case 123: goto tr173;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st187;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr415;
	} else
		goto tr415;
	goto st78;
tr415:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st188;
st188:
	if ( ++p == pe )
		goto _test_eof188;
case 188:
#line 6097 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr416;
		case 34: goto st79;
		case 37: goto tr417;
		case 62: goto tr419;
		case 123: goto tr173;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr416;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st188;
		} else if ( (*p) >= 65 )
			goto st188;
	} else
		goto st188;
	goto st78;
tr419:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st189;
tr370:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st189;
tr426:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st189;
st189:
	if ( ++p == pe )
		goto _test_eof189;
case 189:
#line 6159 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st79;
		case 123: goto tr173;
		case 125: goto st190;
	}
	goto st78;
st190:
	if ( ++p == pe )
		goto _test_eof190;
case 190:
	switch( (*p) ) {
		case 34: goto st79;
		case 123: goto tr173;
		case 125: goto tr421;
	}
	goto st78;
st191:
	if ( ++p == pe )
		goto _test_eof191;
case 191:
	switch( (*p) ) {
		case 34: goto st79;
		case 123: goto tr173;
		case 125: goto tr422;
	}
	goto st78;
tr374:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st192;
st192:
	if ( ++p == pe )
		goto _test_eof192;
case 192:
#line 6196 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr423;
		case 34: goto st79;
		case 37: goto tr424;
		case 62: goto tr426;
		case 123: goto tr173;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr423;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st192;
		} else if ( (*p) >= 65 )
			goto st192;
	} else
		goto st192;
	goto st78;
tr376:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st193;
st193:
	if ( ++p == pe )
		goto _test_eof193;
case 193:
#line 6226 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr423;
		case 34: goto st79;
		case 37: goto tr424;
		case 61: goto tr427;
		case 62: goto tr426;
		case 123: goto tr173;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr423;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st193;
		} else if ( (*p) >= 65 )
			goto st193;
	} else
		goto st192;
	goto st78;
tr427:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st194;
st194:
	if ( ++p == pe )
		goto _test_eof194;
case 194:
#line 6258 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr372;
		case 39: goto tr352;
		case 123: goto tr173;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr374;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr374;
	} else
		goto tr374;
	goto st78;
tr347:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 114 "shortcodes.rl"
	{sc_mark = p;}
	goto st195;
st195:
	if ( ++p == pe )
		goto _test_eof195;
case 195:
#line 6285 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st156;
		case 39: goto st165;
		case 123: goto tr429;
	}
	goto st155;
tr429:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 114 "shortcodes.rl"
	{sc_mark = p;}
	goto st196;
st196:
	if ( ++p == pe )
		goto _test_eof196;
case 196:
#line 6304 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st156;
		case 37: goto st197;
		case 39: goto st165;
		case 60: goto st223;
		case 123: goto tr429;
	}
	goto st155;
st197:
	if ( ++p == pe )
		goto _test_eof197;
case 197:
	switch( (*p) ) {
		case 32: goto st197;
		case 34: goto st156;
		case 39: goto st165;
		case 47: goto st198;
		case 123: goto tr347;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st197;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr433;
	} else
		goto tr433;
	goto st155;
st198:
	if ( ++p == pe )
		goto _test_eof198;
case 198:
	switch( (*p) ) {
		case 34: goto st156;
		case 39: goto st165;
		case 123: goto tr347;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr434;
	} else if ( (*p) >= 65 )
		goto tr434;
	goto st155;
tr434:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st199;
st199:
	if ( ++p == pe )
		goto _test_eof199;
case 199:
#line 6358 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr435;
		case 34: goto st156;
		case 37: goto tr436;
		case 39: goto st165;
		case 62: goto tr438;
		case 123: goto tr347;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr435;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st199;
		} else if ( (*p) >= 65 )
			goto st199;
	} else
		goto st199;
	goto st155;
tr435:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st200;
st200:
	if ( ++p == pe )
		goto _test_eof200;
case 200:
#line 6397 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st200;
		case 34: goto st156;
		case 37: goto st201;
		case 39: goto st165;
		case 62: goto st203;
		case 123: goto tr347;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st200;
	goto st155;
tr436:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st201;
st201:
	if ( ++p == pe )
		goto _test_eof201;
case 201:
#line 6427 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st156;
		case 39: goto st165;
		case 123: goto tr347;
		case 125: goto st202;
	}
	goto st155;
st202:
	if ( ++p == pe )
		goto _test_eof202;
case 202:
	switch( (*p) ) {
		case 34: goto st156;
		case 39: goto st165;
		case 123: goto tr347;
		case 125: goto tr443;
	}
	goto st155;
tr475:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 106 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st521;
tr443:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 118 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (!sc_list[i].closed && sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
        sc_list[i].closed = 1;
        // We tamper with its data
        sc_list[i].data.start = sc_list[i].whole.start+sc_list[i].whole.len;
        sc_list[i].data.len = sc_mark - start - sc_list[i].data.start - 1;
        // It goes all the way to the end of this tag
        sc_list[i].whole.len = p-start-sc_list[i].whole.start + 1;

        // We ignore every other shortcode because it's nested
        c_sc = i+1;
        found = 1;
        break;
      } 
    }
    if (!found) {
      // We are not closing any shortcode, error
      result.errors[result.errcount].position = 
          sc_list[c_sc].whole.start;
      result.errors[result.errcount].code = ERR_MISMATCHED_CLOSING_TAG;
      result.errcount++;
      // Do NOT increase c_sc
    } 
}
	goto st521;
tr445:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 118 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (!sc_list[i].closed && sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
        sc_list[i].closed = 1;
        // We tamper with its data
        sc_list[i].data.start = sc_list[i].whole.start+sc_list[i].whole.len;
        sc_list[i].data.len = sc_mark - start - sc_list[i].data.start - 1;
        // It goes all the way to the end of this tag
        sc_list[i].whole.len = p-start-sc_list[i].whole.start + 1;

        // We ignore every other shortcode because it's nested
        c_sc = i+1;
        found = 1;
        break;
      } 
    }
    if (!found) {
      // We are not closing any shortcode, error
      result.errors[result.errcount].position = 
          sc_list[c_sc].whole.start;
      result.errors[result.errcount].code = ERR_MISMATCHED_CLOSING_TAG;
      result.errcount++;
      // Do NOT increase c_sc
    } 
}
	goto st521;
tr481:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st521;
tr499:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st521;
tr501:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 106 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st521;
st521:
	if ( ++p == pe )
		goto _test_eof521;
case 521:
#line 6576 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st156;
		case 39: goto st165;
		case 123: goto tr347;
	}
	goto st155;
tr438:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st203;
st203:
	if ( ++p == pe )
		goto _test_eof203;
case 203:
#line 6601 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st156;
		case 39: goto st165;
		case 123: goto tr347;
		case 125: goto st204;
	}
	goto st155;
st204:
	if ( ++p == pe )
		goto _test_eof204;
case 204:
	switch( (*p) ) {
		case 34: goto st156;
		case 39: goto st165;
		case 123: goto tr347;
		case 125: goto tr445;
	}
	goto st155;
tr433:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st205;
st205:
	if ( ++p == pe )
		goto _test_eof205;
case 205:
#line 6630 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr446;
		case 34: goto st156;
		case 37: goto tr447;
		case 39: goto st165;
		case 62: goto tr449;
		case 123: goto tr347;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr446;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st205;
		} else if ( (*p) >= 65 )
			goto st205;
	} else
		goto st205;
	goto st155;
tr446:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st206;
tr342:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st206;
tr476:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st206;
st206:
	if ( ++p == pe )
		goto _test_eof206;
case 206:
#line 6693 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st206;
		case 34: goto tr451;
		case 37: goto st216;
		case 39: goto tr328;
		case 62: goto st219;
		case 123: goto tr347;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st206;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr455;
		} else if ( (*p) >= 65 )
			goto tr455;
	} else
		goto tr453;
	goto st155;
tr451:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st207;
st207:
	if ( ++p == pe )
		goto _test_eof207;
case 207:
#line 6724 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr456;
		case 34: goto st97;
		case 37: goto tr457;
		case 39: goto st102;
		case 62: goto tr458;
		case 123: goto tr219;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr456;
	goto st96;
tr583:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st208;
tr456:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st208;
tr466:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st208;
st208:
	if ( ++p == pe )
		goto _test_eof208;
case 208:
#line 6778 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st208;
		case 34: goto tr330;
		case 37: goto st209;
		case 39: goto tr451;
		case 62: goto st212;
		case 123: goto tr219;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st208;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr463;
		} else if ( (*p) >= 65 )
			goto tr463;
	} else
		goto tr461;
	goto st96;
tr584:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st209;
tr457:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st209;
tr467:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st209;
st209:
	if ( ++p == pe )
		goto _test_eof209;
case 209:
#line 6841 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st97;
		case 39: goto st102;
		case 123: goto tr219;
		case 125: goto st210;
	}
	goto st96;
st210:
	if ( ++p == pe )
		goto _test_eof210;
case 210:
	switch( (*p) ) {
		case 34: goto st97;
		case 39: goto st102;
		case 123: goto tr219;
		case 125: goto tr465;
	}
	goto st96;
tr461:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st211;
st211:
	if ( ++p == pe )
		goto _test_eof211;
case 211:
#line 6870 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr466;
		case 34: goto st97;
		case 37: goto tr467;
		case 39: goto st102;
		case 62: goto tr469;
		case 123: goto tr219;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr466;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st211;
		} else if ( (*p) >= 65 )
			goto st211;
	} else
		goto st211;
	goto st96;
tr586:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st212;
tr458:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st212;
tr469:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st212;
st212:
	if ( ++p == pe )
		goto _test_eof212;
case 212:
#line 6933 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st97;
		case 39: goto st102;
		case 123: goto tr219;
		case 125: goto st213;
	}
	goto st96;
st213:
	if ( ++p == pe )
		goto _test_eof213;
case 213:
	switch( (*p) ) {
		case 34: goto st97;
		case 39: goto st102;
		case 123: goto tr219;
		case 125: goto tr471;
	}
	goto st96;
tr463:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st214;
st214:
	if ( ++p == pe )
		goto _test_eof214;
case 214:
#line 6962 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr466;
		case 34: goto st97;
		case 37: goto tr467;
		case 39: goto st102;
		case 61: goto tr472;
		case 62: goto tr469;
		case 123: goto tr219;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr466;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st214;
		} else if ( (*p) >= 65 )
			goto st214;
	} else
		goto st211;
	goto st96;
tr472:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st215;
st215:
	if ( ++p == pe )
		goto _test_eof215;
case 215:
#line 6995 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr330;
		case 39: goto tr451;
		case 123: goto tr219;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr461;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr461;
	} else
		goto tr461;
	goto st96;
tr447:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st216;
tr344:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st216;
tr477:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st216;
st216:
	if ( ++p == pe )
		goto _test_eof216;
case 216:
#line 7052 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st156;
		case 39: goto st165;
		case 123: goto tr347;
		case 125: goto st217;
	}
	goto st155;
st217:
	if ( ++p == pe )
		goto _test_eof217;
case 217:
	switch( (*p) ) {
		case 34: goto st156;
		case 39: goto st165;
		case 123: goto tr347;
		case 125: goto tr475;
	}
	goto st155;
tr453:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st218;
st218:
	if ( ++p == pe )
		goto _test_eof218;
case 218:
#line 7081 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr476;
		case 34: goto st156;
		case 37: goto tr477;
		case 39: goto st165;
		case 62: goto tr479;
		case 123: goto tr347;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr476;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st218;
		} else if ( (*p) >= 65 )
			goto st218;
	} else
		goto st218;
	goto st155;
tr449:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st219;
tr346:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st219;
tr479:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st219;
st219:
	if ( ++p == pe )
		goto _test_eof219;
case 219:
#line 7144 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st156;
		case 39: goto st165;
		case 123: goto tr347;
		case 125: goto st220;
	}
	goto st155;
st220:
	if ( ++p == pe )
		goto _test_eof220;
case 220:
	switch( (*p) ) {
		case 34: goto st156;
		case 39: goto st165;
		case 123: goto tr347;
		case 125: goto tr481;
	}
	goto st155;
tr455:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st221;
st221:
	if ( ++p == pe )
		goto _test_eof221;
case 221:
#line 7173 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr476;
		case 34: goto st156;
		case 37: goto tr477;
		case 39: goto st165;
		case 61: goto tr482;
		case 62: goto tr479;
		case 123: goto tr347;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr476;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st221;
		} else if ( (*p) >= 65 )
			goto st221;
	} else
		goto st218;
	goto st155;
tr482:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st222;
st222:
	if ( ++p == pe )
		goto _test_eof222;
case 222:
#line 7206 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr451;
		case 39: goto tr328;
		case 123: goto tr347;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr453;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr453;
	} else
		goto tr453;
	goto st155;
st223:
	if ( ++p == pe )
		goto _test_eof223;
case 223:
	switch( (*p) ) {
		case 32: goto st223;
		case 34: goto st156;
		case 39: goto st165;
		case 47: goto st198;
		case 123: goto tr347;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st223;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr484;
	} else
		goto tr484;
	goto st155;
tr484:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st224;
st224:
	if ( ++p == pe )
		goto _test_eof224;
case 224:
#line 7251 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr485;
		case 34: goto st156;
		case 37: goto tr486;
		case 39: goto st165;
		case 62: goto tr488;
		case 123: goto tr347;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr485;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st224;
		} else if ( (*p) >= 65 )
			goto st224;
	} else
		goto st224;
	goto st155;
tr485:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st225;
tr495:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st225;
tr502:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st225;
st225:
	if ( ++p == pe )
		goto _test_eof225;
case 225:
#line 7314 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st225;
		case 34: goto tr490;
		case 37: goto st227;
		case 39: goto tr490;
		case 62: goto st229;
		case 123: goto tr347;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st225;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr494;
		} else if ( (*p) >= 65 )
			goto tr494;
	} else
		goto tr492;
	goto st155;
tr490:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st226;
st226:
	if ( ++p == pe )
		goto _test_eof226;
case 226:
#line 7345 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr495;
		case 34: goto st156;
		case 37: goto tr496;
		case 39: goto st165;
		case 62: goto tr497;
		case 123: goto tr347;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr495;
	goto st155;
tr486:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st227;
tr496:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st227;
tr503:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st227;
st227:
	if ( ++p == pe )
		goto _test_eof227;
case 227:
#line 7399 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st156;
		case 39: goto st165;
		case 123: goto tr347;
		case 125: goto st228;
	}
	goto st155;
st228:
	if ( ++p == pe )
		goto _test_eof228;
case 228:
	switch( (*p) ) {
		case 34: goto st156;
		case 39: goto st165;
		case 123: goto tr347;
		case 125: goto tr499;
	}
	goto st155;
tr488:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st229;
tr497:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st229;
tr505:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st229;
st229:
	if ( ++p == pe )
		goto _test_eof229;
case 229:
#line 7460 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st156;
		case 39: goto st165;
		case 123: goto tr347;
		case 125: goto st230;
	}
	goto st155;
st230:
	if ( ++p == pe )
		goto _test_eof230;
case 230:
	switch( (*p) ) {
		case 34: goto st156;
		case 39: goto st165;
		case 123: goto tr347;
		case 125: goto tr501;
	}
	goto st155;
tr492:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st231;
st231:
	if ( ++p == pe )
		goto _test_eof231;
case 231:
#line 7489 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr502;
		case 34: goto st156;
		case 37: goto tr503;
		case 39: goto st165;
		case 62: goto tr505;
		case 123: goto tr347;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr502;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st231;
		} else if ( (*p) >= 65 )
			goto st231;
	} else
		goto st231;
	goto st155;
tr494:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st232;
st232:
	if ( ++p == pe )
		goto _test_eof232;
case 232:
#line 7520 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr502;
		case 34: goto st156;
		case 37: goto tr503;
		case 39: goto st165;
		case 61: goto tr506;
		case 62: goto tr505;
		case 123: goto tr347;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr502;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st232;
		} else if ( (*p) >= 65 )
			goto st232;
	} else
		goto st231;
	goto st155;
tr506:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st233;
st233:
	if ( ++p == pe )
		goto _test_eof233;
case 233:
#line 7553 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr490;
		case 39: goto tr490;
		case 123: goto tr347;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr492;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr492;
	} else
		goto tr492;
	goto st155;
tr331:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st234;
st234:
	if ( ++p == pe )
		goto _test_eof234;
case 234:
#line 7578 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr508;
		case 34: goto st72;
		case 37: goto tr509;
		case 39: goto st77;
		case 62: goto tr511;
		case 123: goto tr160;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr508;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st234;
		} else if ( (*p) >= 65 )
			goto st234;
	} else
		goto st234;
	goto st71;
tr333:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st235;
st235:
	if ( ++p == pe )
		goto _test_eof235;
case 235:
#line 7609 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr508;
		case 34: goto st72;
		case 37: goto tr509;
		case 39: goto st77;
		case 61: goto tr512;
		case 62: goto tr511;
		case 123: goto tr160;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr508;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st235;
		} else if ( (*p) >= 65 )
			goto st235;
	} else
		goto st234;
	goto st71;
tr512:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st236;
st236:
	if ( ++p == pe )
		goto _test_eof236;
case 236:
#line 7642 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr328;
		case 39: goto tr330;
		case 123: goto tr160;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr331;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr331;
	} else
		goto tr331;
	goto st71;
st237:
	if ( ++p == pe )
		goto _test_eof237;
case 237:
	switch( (*p) ) {
		case 34: goto st72;
		case 39: goto st77;
		case 123: goto tr160;
		case 125: goto tr514;
	}
	goto st71;
tr295:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st238;
st238:
	if ( ++p == pe )
		goto _test_eof238;
case 238:
#line 7678 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr515;
		case 34: goto st72;
		case 37: goto tr516;
		case 39: goto st77;
		case 62: goto tr518;
		case 123: goto tr160;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr515;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st238;
		} else if ( (*p) >= 65 )
			goto st238;
	} else
		goto st238;
	goto st71;
tr297:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st239;
st239:
	if ( ++p == pe )
		goto _test_eof239;
case 239:
#line 7709 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr515;
		case 34: goto st72;
		case 37: goto tr516;
		case 39: goto st77;
		case 61: goto tr519;
		case 62: goto tr518;
		case 123: goto tr160;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr515;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st239;
		} else if ( (*p) >= 65 )
			goto st239;
	} else
		goto st238;
	goto st71;
tr519:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st240;
st240:
	if ( ++p == pe )
		goto _test_eof240;
case 240:
#line 7742 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr270;
		case 39: goto tr285;
		case 123: goto tr160;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr295;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr295;
	} else
		goto tr295;
	goto st71;
tr564:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st241;
tr282:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st241;
tr571:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st241;
st241:
	if ( ++p == pe )
		goto _test_eof241;
case 241:
#line 7799 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st47;
		case 39: goto st41;
		case 123: goto tr102;
		case 125: goto st266;
	}
	goto st46;
tr102:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 114 "shortcodes.rl"
	{sc_mark = p;}
	goto st242;
st242:
	if ( ++p == pe )
		goto _test_eof242;
case 242:
#line 7819 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st47;
		case 39: goto st41;
		case 123: goto tr522;
	}
	goto st46;
tr522:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 114 "shortcodes.rl"
	{sc_mark = p;}
	goto st243;
st243:
	if ( ++p == pe )
		goto _test_eof243;
case 243:
#line 7838 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st47;
		case 37: goto st244;
		case 39: goto st41;
		case 60: goto st262;
		case 123: goto tr522;
	}
	goto st46;
st244:
	if ( ++p == pe )
		goto _test_eof244;
case 244:
	switch( (*p) ) {
		case 32: goto st244;
		case 34: goto st47;
		case 39: goto st41;
		case 47: goto st245;
		case 123: goto tr102;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st244;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr526;
	} else
		goto tr526;
	goto st46;
st245:
	if ( ++p == pe )
		goto _test_eof245;
case 245:
	switch( (*p) ) {
		case 34: goto st47;
		case 39: goto st41;
		case 123: goto tr102;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr527;
	} else if ( (*p) >= 65 )
		goto tr527;
	goto st46;
tr527:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st246;
st246:
	if ( ++p == pe )
		goto _test_eof246;
case 246:
#line 7892 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr528;
		case 34: goto st47;
		case 37: goto tr529;
		case 39: goto st41;
		case 62: goto tr531;
		case 123: goto tr102;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr528;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st246;
		} else if ( (*p) >= 65 )
			goto st246;
	} else
		goto st246;
	goto st46;
tr528:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st247;
st247:
	if ( ++p == pe )
		goto _test_eof247;
case 247:
#line 7931 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st247;
		case 34: goto st47;
		case 37: goto st248;
		case 39: goto st41;
		case 62: goto st250;
		case 123: goto tr102;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st247;
	goto st46;
tr529:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st248;
st248:
	if ( ++p == pe )
		goto _test_eof248;
case 248:
#line 7961 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st47;
		case 39: goto st41;
		case 123: goto tr102;
		case 125: goto st249;
	}
	goto st46;
st249:
	if ( ++p == pe )
		goto _test_eof249;
case 249:
	switch( (*p) ) {
		case 34: goto st47;
		case 39: goto st41;
		case 123: goto tr102;
		case 125: goto tr536;
	}
	goto st46;
tr553:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 106 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st522;
tr536:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 118 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (!sc_list[i].closed && sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
        sc_list[i].closed = 1;
        // We tamper with its data
        sc_list[i].data.start = sc_list[i].whole.start+sc_list[i].whole.len;
        sc_list[i].data.len = sc_mark - start - sc_list[i].data.start - 1;
        // It goes all the way to the end of this tag
        sc_list[i].whole.len = p-start-sc_list[i].whole.start + 1;

        // We ignore every other shortcode because it's nested
        c_sc = i+1;
        found = 1;
        break;
      } 
    }
    if (!found) {
      // We are not closing any shortcode, error
      result.errors[result.errcount].position = 
          sc_list[c_sc].whole.start;
      result.errors[result.errcount].code = ERR_MISMATCHED_CLOSING_TAG;
      result.errcount++;
      // Do NOT increase c_sc
    } 
}
	goto st522;
tr538:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 118 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (!sc_list[i].closed && sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
        sc_list[i].closed = 1;
        // We tamper with its data
        sc_list[i].data.start = sc_list[i].whole.start+sc_list[i].whole.len;
        sc_list[i].data.len = sc_mark - start - sc_list[i].data.start - 1;
        // It goes all the way to the end of this tag
        sc_list[i].whole.len = p-start-sc_list[i].whole.start + 1;

        // We ignore every other shortcode because it's nested
        c_sc = i+1;
        found = 1;
        break;
      } 
    }
    if (!found) {
      // We are not closing any shortcode, error
      result.errors[result.errcount].position = 
          sc_list[c_sc].whole.start;
      result.errors[result.errcount].code = ERR_MISMATCHED_CLOSING_TAG;
      result.errcount++;
      // Do NOT increase c_sc
    } 
}
	goto st522;
tr555:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st522;
tr569:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st522;
tr568:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 106 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st522;
st522:
	if ( ++p == pe )
		goto _test_eof522;
case 522:
#line 8110 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st47;
		case 39: goto st41;
		case 123: goto tr102;
	}
	goto st46;
tr531:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st250;
st250:
	if ( ++p == pe )
		goto _test_eof250;
case 250:
#line 8135 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st47;
		case 39: goto st41;
		case 123: goto tr102;
		case 125: goto st251;
	}
	goto st46;
st251:
	if ( ++p == pe )
		goto _test_eof251;
case 251:
	switch( (*p) ) {
		case 34: goto st47;
		case 39: goto st41;
		case 123: goto tr102;
		case 125: goto tr538;
	}
	goto st46;
tr526:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st252;
st252:
	if ( ++p == pe )
		goto _test_eof252;
case 252:
#line 8164 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr539;
		case 34: goto st47;
		case 37: goto tr540;
		case 39: goto st41;
		case 62: goto tr542;
		case 123: goto tr102;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr539;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st252;
		} else if ( (*p) >= 65 )
			goto st252;
	} else
		goto st252;
	goto st46;
tr539:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st253;
tr549:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st253;
tr556:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st253;
st253:
	if ( ++p == pe )
		goto _test_eof253;
case 253:
#line 8227 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st253;
		case 34: goto tr544;
		case 37: goto st255;
		case 39: goto tr544;
		case 62: goto st257;
		case 123: goto tr102;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st253;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr548;
		} else if ( (*p) >= 65 )
			goto tr548;
	} else
		goto tr546;
	goto st46;
tr544:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st254;
st254:
	if ( ++p == pe )
		goto _test_eof254;
case 254:
#line 8258 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr549;
		case 34: goto st47;
		case 37: goto tr550;
		case 39: goto st41;
		case 62: goto tr551;
		case 123: goto tr102;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr549;
	goto st46;
tr540:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st255;
tr550:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st255;
tr557:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st255;
st255:
	if ( ++p == pe )
		goto _test_eof255;
case 255:
#line 8312 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st47;
		case 39: goto st41;
		case 123: goto tr102;
		case 125: goto st256;
	}
	goto st46;
st256:
	if ( ++p == pe )
		goto _test_eof256;
case 256:
	switch( (*p) ) {
		case 34: goto st47;
		case 39: goto st41;
		case 123: goto tr102;
		case 125: goto tr553;
	}
	goto st46;
tr542:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st257;
tr551:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st257;
tr559:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st257;
st257:
	if ( ++p == pe )
		goto _test_eof257;
case 257:
#line 8373 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st47;
		case 39: goto st41;
		case 123: goto tr102;
		case 125: goto st258;
	}
	goto st46;
st258:
	if ( ++p == pe )
		goto _test_eof258;
case 258:
	switch( (*p) ) {
		case 34: goto st47;
		case 39: goto st41;
		case 123: goto tr102;
		case 125: goto tr555;
	}
	goto st46;
tr546:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st259;
st259:
	if ( ++p == pe )
		goto _test_eof259;
case 259:
#line 8402 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr556;
		case 34: goto st47;
		case 37: goto tr557;
		case 39: goto st41;
		case 62: goto tr559;
		case 123: goto tr102;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr556;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st259;
		} else if ( (*p) >= 65 )
			goto st259;
	} else
		goto st259;
	goto st46;
tr548:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st260;
st260:
	if ( ++p == pe )
		goto _test_eof260;
case 260:
#line 8433 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr556;
		case 34: goto st47;
		case 37: goto tr557;
		case 39: goto st41;
		case 61: goto tr560;
		case 62: goto tr559;
		case 123: goto tr102;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr556;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st260;
		} else if ( (*p) >= 65 )
			goto st260;
	} else
		goto st259;
	goto st46;
tr560:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st261;
st261:
	if ( ++p == pe )
		goto _test_eof261;
case 261:
#line 8466 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr544;
		case 39: goto tr544;
		case 123: goto tr102;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr546;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr546;
	} else
		goto tr546;
	goto st46;
st262:
	if ( ++p == pe )
		goto _test_eof262;
case 262:
	switch( (*p) ) {
		case 32: goto st262;
		case 34: goto st47;
		case 39: goto st41;
		case 47: goto st245;
		case 123: goto tr102;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st262;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr562;
	} else
		goto tr562;
	goto st46;
tr562:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st263;
st263:
	if ( ++p == pe )
		goto _test_eof263;
case 263:
#line 8511 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr563;
		case 34: goto st47;
		case 37: goto tr564;
		case 39: goto st41;
		case 62: goto tr566;
		case 123: goto tr102;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr563;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st263;
		} else if ( (*p) >= 65 )
			goto st263;
	} else
		goto st263;
	goto st46;
tr566:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st264;
tr283:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st264;
tr573:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st264;
st264:
	if ( ++p == pe )
		goto _test_eof264;
case 264:
#line 8574 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st47;
		case 39: goto st41;
		case 123: goto tr102;
		case 125: goto st265;
	}
	goto st46;
st265:
	if ( ++p == pe )
		goto _test_eof265;
case 265:
	switch( (*p) ) {
		case 34: goto st47;
		case 39: goto st41;
		case 123: goto tr102;
		case 125: goto tr568;
	}
	goto st46;
st266:
	if ( ++p == pe )
		goto _test_eof266;
case 266:
	switch( (*p) ) {
		case 34: goto st47;
		case 39: goto st41;
		case 123: goto tr102;
		case 125: goto tr569;
	}
	goto st46;
tr287:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st267;
st267:
	if ( ++p == pe )
		goto _test_eof267;
case 267:
#line 8614 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr570;
		case 34: goto st47;
		case 37: goto tr571;
		case 39: goto st41;
		case 62: goto tr573;
		case 123: goto tr102;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr570;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st267;
		} else if ( (*p) >= 65 )
			goto st267;
	} else
		goto st267;
	goto st46;
tr289:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st268;
st268:
	if ( ++p == pe )
		goto _test_eof268;
case 268:
#line 8645 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr570;
		case 34: goto st47;
		case 37: goto tr571;
		case 39: goto st41;
		case 61: goto tr574;
		case 62: goto tr573;
		case 123: goto tr102;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr570;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st268;
		} else if ( (*p) >= 65 )
			goto st268;
	} else
		goto st267;
	goto st46;
tr574:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st269;
st269:
	if ( ++p == pe )
		goto _test_eof269;
case 269:
#line 8678 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr285;
		case 39: goto tr268;
		case 123: goto tr102;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr287;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr287;
	} else
		goto tr287;
	goto st46;
tr271:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st270;
st270:
	if ( ++p == pe )
		goto _test_eof270;
case 270:
#line 8703 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr576;
		case 34: goto st97;
		case 37: goto tr577;
		case 39: goto st102;
		case 62: goto tr579;
		case 123: goto tr219;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr576;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st270;
		} else if ( (*p) >= 65 )
			goto st270;
	} else
		goto st270;
	goto st96;
tr273:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st271;
st271:
	if ( ++p == pe )
		goto _test_eof271;
case 271:
#line 8734 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr576;
		case 34: goto st97;
		case 37: goto tr577;
		case 39: goto st102;
		case 61: goto tr580;
		case 62: goto tr579;
		case 123: goto tr219;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr576;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st271;
		} else if ( (*p) >= 65 )
			goto st271;
	} else
		goto st270;
	goto st96;
tr580:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st272;
st272:
	if ( ++p == pe )
		goto _test_eof272;
case 272:
#line 8767 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr268;
		case 39: goto tr270;
		case 123: goto tr219;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr271;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr271;
	} else
		goto tr271;
	goto st96;
st273:
	if ( ++p == pe )
		goto _test_eof273;
case 273:
	switch( (*p) ) {
		case 32: goto st273;
		case 34: goto st97;
		case 39: goto st102;
		case 47: goto st114;
		case 123: goto tr219;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st273;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr582;
	} else
		goto tr582;
	goto st96;
tr582:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st274;
st274:
	if ( ++p == pe )
		goto _test_eof274;
case 274:
#line 8812 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr583;
		case 34: goto st97;
		case 37: goto tr584;
		case 39: goto st102;
		case 62: goto tr586;
		case 123: goto tr219;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr583;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st274;
		} else if ( (*p) >= 65 )
			goto st274;
	} else
		goto st274;
	goto st96;
tr213:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st275;
st275:
	if ( ++p == pe )
		goto _test_eof275;
case 275:
#line 8843 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr587;
		case 37: goto tr588;
		case 39: goto st79;
		case 62: goto tr590;
		case 123: goto tr187;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr587;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st275;
		} else if ( (*p) >= 65 )
			goto st275;
	} else
		goto st275;
	goto st83;
tr215:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st276;
st276:
	if ( ++p == pe )
		goto _test_eof276;
case 276:
#line 8873 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr587;
		case 37: goto tr588;
		case 39: goto st79;
		case 61: goto tr591;
		case 62: goto tr590;
		case 123: goto tr187;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr587;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st276;
		} else if ( (*p) >= 65 )
			goto st276;
	} else
		goto st275;
	goto st83;
tr591:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st277;
st277:
	if ( ++p == pe )
		goto _test_eof277;
case 277:
#line 8905 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr210;
		case 39: goto tr212;
		case 123: goto tr187;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr213;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr213;
	} else
		goto tr213;
	goto st83;
st278:
	if ( ++p == pe )
		goto _test_eof278;
case 278:
	switch( (*p) ) {
		case 32: goto st278;
		case 39: goto st79;
		case 47: goto st87;
		case 123: goto tr187;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st278;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr593;
	} else
		goto tr593;
	goto st83;
tr593:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st279;
st279:
	if ( ++p == pe )
		goto _test_eof279;
case 279:
#line 8949 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr594;
		case 37: goto tr595;
		case 39: goto st79;
		case 62: goto tr597;
		case 123: goto tr187;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr594;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st279;
		} else if ( (*p) >= 65 )
			goto st279;
	} else
		goto st279;
	goto st83;
tr181:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st280;
st280:
	if ( ++p == pe )
		goto _test_eof280;
case 280:
#line 8979 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr598;
		case 37: goto tr599;
		case 62: goto tr601;
		case 123: goto tr26;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr598;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st280;
		} else if ( (*p) >= 65 )
			goto st280;
	} else
		goto st280;
	goto st10;
tr633:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st281;
tr176:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st281;
tr601:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st281;
st281:
	if ( ++p == pe )
		goto _test_eof281;
case 281:
#line 9040 "shortcodes.c"
	switch( (*p) ) {
		case 123: goto tr26;
		case 125: goto st282;
	}
	goto st10;
st282:
	if ( ++p == pe )
		goto _test_eof282;
case 282:
	switch( (*p) ) {
		case 123: goto tr26;
		case 125: goto tr603;
	}
	goto st10;
tr183:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st283;
st283:
	if ( ++p == pe )
		goto _test_eof283;
case 283:
#line 9065 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr598;
		case 37: goto tr599;
		case 61: goto tr604;
		case 62: goto tr601;
		case 123: goto tr26;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr598;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st283;
		} else if ( (*p) >= 65 )
			goto st283;
	} else
		goto st280;
	goto st10;
tr604:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st284;
st284:
	if ( ++p == pe )
		goto _test_eof284;
case 284:
#line 9096 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr178;
		case 39: goto tr180;
		case 123: goto tr26;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr181;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr181;
	} else
		goto tr181;
	goto st10;
tr154:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st285;
st285:
	if ( ++p == pe )
		goto _test_eof285;
case 285:
#line 9121 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr606;
		case 37: goto tr607;
		case 39: goto st24;
		case 62: goto tr609;
		case 123: goto tr107;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr606;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st285;
		} else if ( (*p) >= 65 )
			goto st285;
	} else
		goto st285;
	goto st48;
tr156:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st286;
st286:
	if ( ++p == pe )
		goto _test_eof286;
case 286:
#line 9151 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr606;
		case 37: goto tr607;
		case 39: goto st24;
		case 61: goto tr610;
		case 62: goto tr609;
		case 123: goto tr107;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr606;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st286;
		} else if ( (*p) >= 65 )
			goto st286;
	} else
		goto st285;
	goto st48;
tr610:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st287;
st287:
	if ( ++p == pe )
		goto _test_eof287;
case 287:
#line 9183 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr151;
		case 39: goto tr153;
		case 123: goto tr107;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr154;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr154;
	} else
		goto tr154;
	goto st48;
tr89:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st288;
st288:
	if ( ++p == pe )
		goto _test_eof288;
case 288:
#line 9208 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr612;
		case 34: goto st24;
		case 37: goto tr613;
		case 62: goto tr615;
		case 123: goto tr57;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr612;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st288;
		} else if ( (*p) >= 65 )
			goto st288;
	} else
		goto st288;
	goto st23;
tr91:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st289;
st289:
	if ( ++p == pe )
		goto _test_eof289;
case 289:
#line 9238 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr612;
		case 34: goto st24;
		case 37: goto tr613;
		case 61: goto tr616;
		case 62: goto tr615;
		case 123: goto tr57;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr612;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st289;
		} else if ( (*p) >= 65 )
			goto st289;
	} else
		goto st288;
	goto st23;
tr616:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st290;
st290:
	if ( ++p == pe )
		goto _test_eof290;
case 290:
#line 9270 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr86;
		case 39: goto tr88;
		case 123: goto tr57;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr89;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr89;
	} else
		goto tr89;
	goto st23;
st291:
	if ( ++p == pe )
		goto _test_eof291;
case 291:
	switch( (*p) ) {
		case 32: goto st291;
		case 34: goto st24;
		case 47: goto st32;
		case 123: goto tr57;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st291;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr618;
	} else
		goto tr618;
	goto st23;
tr618:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st292;
st292:
	if ( ++p == pe )
		goto _test_eof292;
case 292:
#line 9314 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr619;
		case 34: goto st24;
		case 37: goto tr620;
		case 62: goto tr622;
		case 123: goto tr57;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr619;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st292;
		} else if ( (*p) >= 65 )
			goto st292;
	} else
		goto st292;
	goto st23;
tr52:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st293;
st293:
	if ( ++p == pe )
		goto _test_eof293;
case 293:
#line 9344 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr623;
		case 37: goto tr624;
		case 62: goto tr626;
		case 123: goto tr26;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr623;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st293;
		} else if ( (*p) >= 65 )
			goto st293;
	} else
		goto st293;
	goto st10;
tr54:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st294;
st294:
	if ( ++p == pe )
		goto _test_eof294;
case 294:
#line 9373 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr623;
		case 37: goto tr624;
		case 61: goto tr627;
		case 62: goto tr626;
		case 123: goto tr26;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr623;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st294;
		} else if ( (*p) >= 65 )
			goto st294;
	} else
		goto st293;
	goto st10;
tr627:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st295;
st295:
	if ( ++p == pe )
		goto _test_eof295;
case 295:
#line 9404 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr49;
		case 39: goto tr51;
		case 123: goto tr26;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr52;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr52;
	} else
		goto tr52;
	goto st10;
st296:
	if ( ++p == pe )
		goto _test_eof296;
case 296:
	switch( (*p) ) {
		case 32: goto st296;
		case 47: goto st14;
		case 123: goto tr26;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st296;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr629;
	} else
		goto tr629;
	goto st10;
tr629:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st297;
st297:
	if ( ++p == pe )
		goto _test_eof297;
case 297:
#line 9447 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr630;
		case 37: goto tr631;
		case 62: goto tr633;
		case 123: goto tr26;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr630;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st297;
		} else if ( (*p) >= 65 )
			goto st297;
	} else
		goto st297;
	goto st10;
tr9:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st298;
tr22:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st298;
tr1077:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st298;
st298:
	if ( ++p == pe )
		goto _test_eof298;
case 298:
#line 9508 "shortcodes.c"
	switch( (*p) ) {
		case 123: goto tr1;
		case 125: goto st299;
	}
	goto st0;
st299:
	if ( ++p == pe )
		goto _test_eof299;
case 299:
	switch( (*p) ) {
		case 123: goto tr1;
		case 125: goto tr635;
	}
	goto st0;
tr19:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st300;
st300:
	if ( ++p == pe )
		goto _test_eof300;
case 300:
#line 9533 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr636;
	}
	goto st6;
tr636:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st301;
st301:
	if ( ++p == pe )
		goto _test_eof301;
case 301:
#line 9549 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 37: goto st302;
		case 60: goto st506;
		case 123: goto tr636;
	}
	goto st6;
st302:
	if ( ++p == pe )
		goto _test_eof302;
case 302:
	switch( (*p) ) {
		case 32: goto st302;
		case 34: goto st7;
		case 123: goto tr19;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st302;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr639;
	} else
		goto tr639;
	goto st6;
tr639:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st303;
st303:
	if ( ++p == pe )
		goto _test_eof303;
case 303:
#line 9585 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr640;
		case 34: goto st7;
		case 37: goto tr641;
		case 62: goto tr643;
		case 123: goto tr19;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr640;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st303;
		} else if ( (*p) >= 65 )
			goto st303;
	} else
		goto st303;
	goto st6;
tr640:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st304;
tr651:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st304;
tr1063:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st304;
st304:
	if ( ++p == pe )
		goto _test_eof304;
case 304:
#line 9647 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st304;
		case 34: goto tr645;
		case 37: goto st306;
		case 39: goto tr647;
		case 62: goto st308;
		case 123: goto tr19;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st304;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr650;
		} else if ( (*p) >= 65 )
			goto tr650;
	} else
		goto tr648;
	goto st6;
tr645:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st305;
st305:
	if ( ++p == pe )
		goto _test_eof305;
case 305:
#line 9678 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr651;
		case 34: goto st7;
		case 37: goto tr652;
		case 62: goto tr653;
		case 123: goto tr19;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr651;
	goto st6;
tr641:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st306;
tr652:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st306;
tr1064:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st306;
st306:
	if ( ++p == pe )
		goto _test_eof306;
case 306:
#line 9731 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr19;
		case 125: goto st307;
	}
	goto st6;
st307:
	if ( ++p == pe )
		goto _test_eof307;
case 307:
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr19;
		case 125: goto tr96;
	}
	goto st6;
tr643:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st308;
tr653:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st308;
tr1066:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st308;
st308:
	if ( ++p == pe )
		goto _test_eof308;
case 308:
#line 9790 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr19;
		case 125: goto st309;
	}
	goto st6;
st309:
	if ( ++p == pe )
		goto _test_eof309;
case 309:
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr19;
		case 125: goto tr656;
	}
	goto st6;
tr656:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st523;
tr766:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st523;
st523:
	if ( ++p == pe )
		goto _test_eof523;
case 523:
#line 9837 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr19;
	}
	goto st6;
tr647:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st310;
st310:
	if ( ++p == pe )
		goto _test_eof310;
case 310:
#line 9853 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st311;
		case 39: goto st305;
		case 123: goto tr660;
	}
	goto st310;
tr676:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st311;
st311:
	if ( ++p == pe )
		goto _test_eof311;
case 311:
#line 9870 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr662;
		case 37: goto tr663;
		case 39: goto st7;
		case 62: goto tr664;
		case 123: goto tr665;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr662;
	goto st312;
tr13:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st312;
st312:
	if ( ++p == pe )
		goto _test_eof312;
case 312:
#line 9891 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st7;
		case 123: goto tr665;
	}
	goto st312;
tr665:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st313;
st313:
	if ( ++p == pe )
		goto _test_eof313;
case 313:
#line 9907 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st7;
		case 123: goto tr666;
	}
	goto st312;
tr666:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st314;
st314:
	if ( ++p == pe )
		goto _test_eof314;
case 314:
#line 9923 "shortcodes.c"
	switch( (*p) ) {
		case 37: goto st315;
		case 39: goto st7;
		case 60: goto st325;
		case 123: goto tr666;
	}
	goto st312;
st315:
	if ( ++p == pe )
		goto _test_eof315;
case 315:
	switch( (*p) ) {
		case 32: goto st315;
		case 39: goto st7;
		case 123: goto tr665;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st315;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr669;
	} else
		goto tr669;
	goto st312;
tr669:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st316;
st316:
	if ( ++p == pe )
		goto _test_eof316;
case 316:
#line 9959 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr670;
		case 37: goto tr671;
		case 39: goto st7;
		case 62: goto tr673;
		case 123: goto tr665;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr670;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st316;
		} else if ( (*p) >= 65 )
			goto st316;
	} else
		goto st316;
	goto st312;
tr670:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st317;
tr662:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st317;
tr681:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st317;
st317:
	if ( ++p == pe )
		goto _test_eof317;
case 317:
#line 10021 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st317;
		case 34: goto tr647;
		case 37: goto st318;
		case 39: goto tr676;
		case 62: goto st321;
		case 123: goto tr665;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st317;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr679;
		} else if ( (*p) >= 65 )
			goto tr679;
	} else
		goto tr677;
	goto st312;
tr671:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st318;
tr663:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st318;
tr682:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st318;
st318:
	if ( ++p == pe )
		goto _test_eof318;
case 318:
#line 10084 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st7;
		case 123: goto tr665;
		case 125: goto st319;
	}
	goto st312;
st319:
	if ( ++p == pe )
		goto _test_eof319;
case 319:
	switch( (*p) ) {
		case 39: goto st7;
		case 123: goto tr665;
		case 125: goto tr136;
	}
	goto st312;
tr677:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st320;
st320:
	if ( ++p == pe )
		goto _test_eof320;
case 320:
#line 10111 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr681;
		case 37: goto tr682;
		case 39: goto st7;
		case 62: goto tr684;
		case 123: goto tr665;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr681;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st320;
		} else if ( (*p) >= 65 )
			goto st320;
	} else
		goto st320;
	goto st312;
tr673:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st321;
tr664:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st321;
tr684:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st321;
st321:
	if ( ++p == pe )
		goto _test_eof321;
case 321:
#line 10173 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st7;
		case 123: goto tr665;
		case 125: goto st322;
	}
	goto st312;
st322:
	if ( ++p == pe )
		goto _test_eof322;
case 322:
	switch( (*p) ) {
		case 39: goto st7;
		case 123: goto tr665;
		case 125: goto tr686;
	}
	goto st312;
tr686:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st524;
tr709:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st524;
st524:
	if ( ++p == pe )
		goto _test_eof524;
case 524:
#line 10220 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st7;
		case 123: goto tr665;
	}
	goto st312;
tr679:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st323;
st323:
	if ( ++p == pe )
		goto _test_eof323;
case 323:
#line 10236 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr681;
		case 37: goto tr682;
		case 39: goto st7;
		case 61: goto tr687;
		case 62: goto tr684;
		case 123: goto tr665;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr681;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st323;
		} else if ( (*p) >= 65 )
			goto st323;
	} else
		goto st320;
	goto st312;
tr687:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st324;
st324:
	if ( ++p == pe )
		goto _test_eof324;
case 324:
#line 10268 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr647;
		case 39: goto tr676;
		case 123: goto tr665;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr677;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr677;
	} else
		goto tr677;
	goto st312;
st325:
	if ( ++p == pe )
		goto _test_eof325;
case 325:
	switch( (*p) ) {
		case 32: goto st325;
		case 39: goto st7;
		case 123: goto tr665;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st325;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr689;
	} else
		goto tr689;
	goto st312;
tr689:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st326;
st326:
	if ( ++p == pe )
		goto _test_eof326;
case 326:
#line 10311 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr690;
		case 37: goto tr691;
		case 39: goto st7;
		case 62: goto tr693;
		case 123: goto tr665;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr690;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st326;
		} else if ( (*p) >= 65 )
			goto st326;
	} else
		goto st326;
	goto st312;
tr690:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st327;
tr705:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st327;
tr1057:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st327;
st327:
	if ( ++p == pe )
		goto _test_eof327;
case 327:
#line 10373 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st327;
		case 34: goto tr695;
		case 37: goto st330;
		case 39: goto tr697;
		case 62: goto st332;
		case 123: goto tr665;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st327;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr700;
		} else if ( (*p) >= 65 )
			goto tr700;
	} else
		goto tr698;
	goto st312;
tr695:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st328;
st328:
	if ( ++p == pe )
		goto _test_eof328;
case 328:
#line 10404 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st329;
		case 39: goto st334;
		case 123: goto tr704;
	}
	goto st328;
tr742:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st329;
st329:
	if ( ++p == pe )
		goto _test_eof329;
case 329:
#line 10421 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr705;
		case 37: goto tr706;
		case 39: goto st7;
		case 62: goto tr707;
		case 123: goto tr665;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr705;
	goto st312;
tr691:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st330;
tr706:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st330;
tr1058:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st330;
st330:
	if ( ++p == pe )
		goto _test_eof330;
case 330:
#line 10474 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st7;
		case 123: goto tr665;
		case 125: goto st331;
	}
	goto st312;
st331:
	if ( ++p == pe )
		goto _test_eof331;
case 331:
	switch( (*p) ) {
		case 39: goto st7;
		case 123: goto tr665;
		case 125: goto tr709;
	}
	goto st312;
tr693:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st332;
tr707:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st332;
tr1060:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st332;
st332:
	if ( ++p == pe )
		goto _test_eof332;
case 332:
#line 10533 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st7;
		case 123: goto tr665;
		case 125: goto st333;
	}
	goto st312;
st333:
	if ( ++p == pe )
		goto _test_eof333;
case 333:
	switch( (*p) ) {
		case 39: goto st7;
		case 123: goto tr665;
		case 125: goto tr167;
	}
	goto st312;
tr760:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st334;
st334:
	if ( ++p == pe )
		goto _test_eof334;
case 334:
#line 10560 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr712;
		case 34: goto st336;
		case 37: goto tr714;
		case 62: goto tr715;
		case 123: goto tr716;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr712;
	goto st335;
tr721:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st335;
st335:
	if ( ++p == pe )
		goto _test_eof335;
case 335:
#line 10581 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st336;
		case 123: goto tr716;
	}
	goto st335;
st336:
	if ( ++p == pe )
		goto _test_eof336;
case 336:
	switch( (*p) ) {
		case 32: goto tr717;
		case 37: goto tr718;
		case 62: goto tr719;
		case 123: goto tr1;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr717;
	goto st0;
tr1081:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st337;
tr717:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st337;
tr1050:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st337;
st337:
	if ( ++p == pe )
		goto _test_eof337;
case 337:
#line 10642 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st337;
		case 34: goto tr721;
		case 37: goto st338;
		case 39: goto tr723;
		case 62: goto st496;
		case 123: goto tr1;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st337;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr726;
		} else if ( (*p) >= 65 )
			goto tr726;
	} else
		goto tr724;
	goto st0;
tr1082:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st338;
tr718:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st338;
tr1051:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st338;
st338:
	if ( ++p == pe )
		goto _test_eof338;
case 338:
#line 10705 "shortcodes.c"
	switch( (*p) ) {
		case 123: goto tr1;
		case 125: goto st339;
	}
	goto st0;
st339:
	if ( ++p == pe )
		goto _test_eof339;
case 339:
	switch( (*p) ) {
		case 123: goto tr1;
		case 125: goto tr728;
	}
	goto st0;
tr723:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st340;
st340:
	if ( ++p == pe )
		goto _test_eof340;
case 340:
#line 10730 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st336;
		case 123: goto tr730;
	}
	goto st340;
tr730:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st341;
st341:
	if ( ++p == pe )
		goto _test_eof341;
case 341:
#line 10746 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st336;
		case 123: goto tr731;
	}
	goto st340;
tr731:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st342;
st342:
	if ( ++p == pe )
		goto _test_eof342;
case 342:
#line 10762 "shortcodes.c"
	switch( (*p) ) {
		case 37: goto st343;
		case 39: goto st336;
		case 60: goto st493;
		case 123: goto tr731;
	}
	goto st340;
st343:
	if ( ++p == pe )
		goto _test_eof343;
case 343:
	switch( (*p) ) {
		case 32: goto st343;
		case 39: goto st336;
		case 123: goto tr730;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st343;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr734;
	} else
		goto tr734;
	goto st340;
tr734:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st344;
st344:
	if ( ++p == pe )
		goto _test_eof344;
case 344:
#line 10798 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr735;
		case 37: goto tr736;
		case 39: goto st336;
		case 62: goto tr738;
		case 123: goto tr730;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr735;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st344;
		} else if ( (*p) >= 65 )
			goto st344;
	} else
		goto st344;
	goto st340;
tr735:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st345;
tr750:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st345;
tr1039:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st345;
st345:
	if ( ++p == pe )
		goto _test_eof345;
case 345:
#line 10860 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st345;
		case 34: goto tr740;
		case 37: goto st348;
		case 39: goto tr742;
		case 62: goto st350;
		case 123: goto tr730;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st345;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr745;
		} else if ( (*p) >= 65 )
			goto tr745;
	} else
		goto tr743;
	goto st340;
tr740:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st346;
st346:
	if ( ++p == pe )
		goto _test_eof346;
case 346:
#line 10891 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st347;
		case 39: goto st352;
		case 123: goto tr749;
	}
	goto st346;
tr697:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st347;
st347:
	if ( ++p == pe )
		goto _test_eof347;
case 347:
#line 10908 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr750;
		case 37: goto tr751;
		case 39: goto st336;
		case 62: goto tr752;
		case 123: goto tr730;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr750;
	goto st340;
tr736:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st348;
tr751:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st348;
tr1040:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st348;
st348:
	if ( ++p == pe )
		goto _test_eof348;
case 348:
#line 10961 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st336;
		case 123: goto tr730;
		case 125: goto st349;
	}
	goto st340;
st349:
	if ( ++p == pe )
		goto _test_eof349;
case 349:
	switch( (*p) ) {
		case 39: goto st336;
		case 123: goto tr730;
		case 125: goto tr224;
	}
	goto st340;
tr738:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st350;
tr752:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st350;
tr1042:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st350;
st350:
	if ( ++p == pe )
		goto _test_eof350;
case 350:
#line 11020 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st336;
		case 123: goto tr730;
		case 125: goto st351;
	}
	goto st340;
st351:
	if ( ++p == pe )
		goto _test_eof351;
case 351:
	switch( (*p) ) {
		case 39: goto st336;
		case 123: goto tr730;
		case 125: goto tr755;
	}
	goto st340;
tr755:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st525;
tr859:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st525;
st525:
	if ( ++p == pe )
		goto _test_eof525;
case 525:
#line 11067 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st336;
		case 123: goto tr730;
	}
	goto st340;
tr886:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st352;
st352:
	if ( ++p == pe )
		goto _test_eof352;
case 352:
#line 11083 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr756;
		case 34: goto st7;
		case 37: goto tr757;
		case 62: goto tr758;
		case 123: goto tr19;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr756;
	goto st6;
tr1070:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st353;
tr756:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st353;
tr767:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st353;
st353:
	if ( ++p == pe )
		goto _test_eof353;
case 353:
#line 11136 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st353;
		case 34: goto tr760;
		case 37: goto st354;
		case 39: goto tr740;
		case 62: goto st357;
		case 123: goto tr19;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st353;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr764;
		} else if ( (*p) >= 65 )
			goto tr764;
	} else
		goto tr762;
	goto st6;
tr1071:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st354;
tr757:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st354;
tr768:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st354;
st354:
	if ( ++p == pe )
		goto _test_eof354;
case 354:
#line 11199 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr19;
		case 125: goto st355;
	}
	goto st6;
st355:
	if ( ++p == pe )
		goto _test_eof355;
case 355:
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr19;
		case 125: goto tr766;
	}
	goto st6;
tr762:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st356;
st356:
	if ( ++p == pe )
		goto _test_eof356;
case 356:
#line 11226 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr767;
		case 34: goto st7;
		case 37: goto tr768;
		case 62: goto tr770;
		case 123: goto tr19;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr767;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st356;
		} else if ( (*p) >= 65 )
			goto st356;
	} else
		goto st356;
	goto st6;
tr1073:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st357;
tr758:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st357;
tr770:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st357;
st357:
	if ( ++p == pe )
		goto _test_eof357;
case 357:
#line 11288 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr19;
		case 125: goto st358;
	}
	goto st6;
st358:
	if ( ++p == pe )
		goto _test_eof358;
case 358:
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr19;
		case 125: goto tr243;
	}
	goto st6;
tr764:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st359;
st359:
	if ( ++p == pe )
		goto _test_eof359;
case 359:
#line 11315 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr767;
		case 34: goto st7;
		case 37: goto tr768;
		case 61: goto tr772;
		case 62: goto tr770;
		case 123: goto tr19;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr767;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st359;
		} else if ( (*p) >= 65 )
			goto st359;
	} else
		goto st356;
	goto st6;
tr772:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st360;
st360:
	if ( ++p == pe )
		goto _test_eof360;
case 360:
#line 11347 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr760;
		case 39: goto tr740;
		case 123: goto tr19;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr762;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr762;
	} else
		goto tr762;
	goto st6;
tr749:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st361;
st361:
	if ( ++p == pe )
		goto _test_eof361;
case 361:
#line 11372 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st347;
		case 39: goto st352;
		case 123: goto tr774;
	}
	goto st346;
tr774:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st362;
st362:
	if ( ++p == pe )
		goto _test_eof362;
case 362:
#line 11389 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st347;
		case 37: goto st363;
		case 39: goto st352;
		case 60: goto st488;
		case 123: goto tr774;
	}
	goto st346;
st363:
	if ( ++p == pe )
		goto _test_eof363;
case 363:
	switch( (*p) ) {
		case 32: goto st363;
		case 34: goto st347;
		case 39: goto st352;
		case 123: goto tr749;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st363;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr777;
	} else
		goto tr777;
	goto st346;
tr777:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st364;
st364:
	if ( ++p == pe )
		goto _test_eof364;
case 364:
#line 11427 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr778;
		case 34: goto st347;
		case 37: goto tr779;
		case 39: goto st352;
		case 62: goto tr781;
		case 123: goto tr749;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr778;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st364;
		} else if ( (*p) >= 65 )
			goto st364;
	} else
		goto st364;
	goto st346;
tr778:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st365;
tr789:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st365;
tr1028:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st365;
st365:
	if ( ++p == pe )
		goto _test_eof365;
case 365:
#line 11490 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st365;
		case 34: goto tr783;
		case 37: goto st367;
		case 39: goto tr785;
		case 62: goto st369;
		case 123: goto tr749;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st365;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr788;
		} else if ( (*p) >= 65 )
			goto tr788;
	} else
		goto tr786;
	goto st346;
tr783:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st366;
st366:
	if ( ++p == pe )
		goto _test_eof366;
case 366:
#line 11521 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr789;
		case 34: goto st347;
		case 37: goto tr790;
		case 39: goto st352;
		case 62: goto tr791;
		case 123: goto tr749;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr789;
	goto st346;
tr779:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st367;
tr790:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st367;
tr1029:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st367;
st367:
	if ( ++p == pe )
		goto _test_eof367;
case 367:
#line 11575 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st347;
		case 39: goto st352;
		case 123: goto tr749;
		case 125: goto st368;
	}
	goto st346;
st368:
	if ( ++p == pe )
		goto _test_eof368;
case 368:
	switch( (*p) ) {
		case 34: goto st347;
		case 39: goto st352;
		case 123: goto tr749;
		case 125: goto tr278;
	}
	goto st346;
tr781:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st369;
tr791:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st369;
tr1031:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st369;
st369:
	if ( ++p == pe )
		goto _test_eof369;
case 369:
#line 11636 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st347;
		case 39: goto st352;
		case 123: goto tr749;
		case 125: goto st370;
	}
	goto st346;
st370:
	if ( ++p == pe )
		goto _test_eof370;
case 370:
	switch( (*p) ) {
		case 34: goto st347;
		case 39: goto st352;
		case 123: goto tr749;
		case 125: goto tr794;
	}
	goto st346;
tr794:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st526;
tr936:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st526;
st526:
	if ( ++p == pe )
		goto _test_eof526;
case 526:
#line 11685 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st347;
		case 39: goto st352;
		case 123: goto tr749;
	}
	goto st346;
tr785:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st371;
st371:
	if ( ++p == pe )
		goto _test_eof371;
case 371:
#line 11702 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr795;
		case 34: goto st311;
		case 37: goto tr796;
		case 39: goto st305;
		case 62: goto tr797;
		case 123: goto tr660;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr795;
	goto st310;
tr1016:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st372;
tr795:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st372;
tr1022:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st372;
st372:
	if ( ++p == pe )
		goto _test_eof372;
case 372:
#line 11756 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st372;
		case 34: goto tr799;
		case 37: goto st463;
		case 39: goto tr783;
		case 62: goto st479;
		case 123: goto tr660;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st372;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr803;
		} else if ( (*p) >= 65 )
			goto tr803;
	} else
		goto tr801;
	goto st310;
tr799:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st373;
st373:
	if ( ++p == pe )
		goto _test_eof373;
case 373:
#line 11787 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr804;
		case 34: goto st329;
		case 37: goto tr805;
		case 39: goto st334;
		case 62: goto tr806;
		case 123: goto tr704;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr804;
	goto st328;
tr817:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st374;
tr804:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st374;
tr982:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st374;
st374:
	if ( ++p == pe )
		goto _test_eof374;
case 374:
#line 11841 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st374;
		case 34: goto tr785;
		case 37: goto st375;
		case 39: goto tr799;
		case 62: goto st380;
		case 123: goto tr704;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st374;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr811;
		} else if ( (*p) >= 65 )
			goto tr811;
	} else
		goto tr809;
	goto st328;
tr818:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st375;
tr805:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st375;
tr983:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st375;
st375:
	if ( ++p == pe )
		goto _test_eof375;
case 375:
#line 11904 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st329;
		case 39: goto st334;
		case 123: goto tr704;
		case 125: goto st459;
	}
	goto st328;
tr704:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st376;
st376:
	if ( ++p == pe )
		goto _test_eof376;
case 376:
#line 11922 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st329;
		case 39: goto st334;
		case 123: goto tr813;
	}
	goto st328;
tr813:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st377;
st377:
	if ( ++p == pe )
		goto _test_eof377;
case 377:
#line 11939 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st329;
		case 37: goto st378;
		case 39: goto st334;
		case 60: goto st382;
		case 123: goto tr813;
	}
	goto st328;
st378:
	if ( ++p == pe )
		goto _test_eof378;
case 378:
	switch( (*p) ) {
		case 32: goto st378;
		case 34: goto st329;
		case 39: goto st334;
		case 123: goto tr704;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st378;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr816;
	} else
		goto tr816;
	goto st328;
tr816:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st379;
st379:
	if ( ++p == pe )
		goto _test_eof379;
case 379:
#line 11977 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr817;
		case 34: goto st329;
		case 37: goto tr818;
		case 39: goto st334;
		case 62: goto tr820;
		case 123: goto tr704;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr817;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st379;
		} else if ( (*p) >= 65 )
			goto st379;
	} else
		goto st379;
	goto st328;
tr820:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st380;
tr806:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st380;
tr985:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st380;
st380:
	if ( ++p == pe )
		goto _test_eof380;
case 380:
#line 12040 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st329;
		case 39: goto st334;
		case 123: goto tr704;
		case 125: goto st381;
	}
	goto st328;
st381:
	if ( ++p == pe )
		goto _test_eof381;
case 381:
	switch( (*p) ) {
		case 34: goto st329;
		case 39: goto st334;
		case 123: goto tr704;
		case 125: goto tr822;
	}
	goto st328;
tr822:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st527;
tr839:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st527;
st527:
	if ( ++p == pe )
		goto _test_eof527;
case 527:
#line 12089 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st329;
		case 39: goto st334;
		case 123: goto tr704;
	}
	goto st328;
st382:
	if ( ++p == pe )
		goto _test_eof382;
case 382:
	switch( (*p) ) {
		case 32: goto st382;
		case 34: goto st329;
		case 39: goto st334;
		case 123: goto tr704;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st382;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr823;
	} else
		goto tr823;
	goto st328;
tr823:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st383;
st383:
	if ( ++p == pe )
		goto _test_eof383;
case 383:
#line 12125 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr824;
		case 34: goto st329;
		case 37: goto tr825;
		case 39: goto st334;
		case 62: goto tr827;
		case 123: goto tr704;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr824;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st383;
		} else if ( (*p) >= 65 )
			goto st383;
	} else
		goto st383;
	goto st328;
tr824:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st384;
tr835:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st384;
tr976:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st384;
st384:
	if ( ++p == pe )
		goto _test_eof384;
case 384:
#line 12188 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st384;
		case 34: goto tr829;
		case 37: goto st386;
		case 39: goto tr831;
		case 62: goto st388;
		case 123: goto tr704;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st384;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr834;
		} else if ( (*p) >= 65 )
			goto tr834;
	} else
		goto tr832;
	goto st328;
tr829:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st385;
st385:
	if ( ++p == pe )
		goto _test_eof385;
case 385:
#line 12219 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr835;
		case 34: goto st329;
		case 37: goto tr836;
		case 39: goto st334;
		case 62: goto tr837;
		case 123: goto tr704;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr835;
	goto st328;
tr825:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st386;
tr836:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st386;
tr977:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st386;
st386:
	if ( ++p == pe )
		goto _test_eof386;
case 386:
#line 12273 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st329;
		case 39: goto st334;
		case 123: goto tr704;
		case 125: goto st387;
	}
	goto st328;
st387:
	if ( ++p == pe )
		goto _test_eof387;
case 387:
	switch( (*p) ) {
		case 34: goto st329;
		case 39: goto st334;
		case 123: goto tr704;
		case 125: goto tr839;
	}
	goto st328;
tr827:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st388;
tr837:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st388;
tr979:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st388;
st388:
	if ( ++p == pe )
		goto _test_eof388;
case 388:
#line 12334 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st329;
		case 39: goto st334;
		case 123: goto tr704;
		case 125: goto st389;
	}
	goto st328;
st389:
	if ( ++p == pe )
		goto _test_eof389;
case 389:
	switch( (*p) ) {
		case 34: goto st329;
		case 39: goto st334;
		case 123: goto tr704;
		case 125: goto tr340;
	}
	goto st328;
tr831:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st390;
st390:
	if ( ++p == pe )
		goto _test_eof390;
case 390:
#line 12363 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr842;
		case 34: goto st392;
		case 37: goto tr844;
		case 39: goto st401;
		case 62: goto tr846;
		case 123: goto tr847;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr842;
	goto st391;
tr852:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st391;
st391:
	if ( ++p == pe )
		goto _test_eof391;
case 391:
#line 12385 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st392;
		case 39: goto st401;
		case 123: goto tr847;
	}
	goto st391;
tr854:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st392;
st392:
	if ( ++p == pe )
		goto _test_eof392;
case 392:
#line 12402 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr848;
		case 37: goto tr849;
		case 39: goto st336;
		case 62: goto tr850;
		case 123: goto tr730;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr848;
	goto st340;
tr1046:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st393;
tr848:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st393;
tr860:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st393;
st393:
	if ( ++p == pe )
		goto _test_eof393;
case 393:
#line 12455 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st393;
		case 34: goto tr852;
		case 37: goto st394;
		case 39: goto tr854;
		case 62: goto st397;
		case 123: goto tr730;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st393;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr857;
		} else if ( (*p) >= 65 )
			goto tr857;
	} else
		goto tr855;
	goto st340;
tr1047:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st394;
tr849:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st394;
tr861:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st394;
st394:
	if ( ++p == pe )
		goto _test_eof394;
case 394:
#line 12518 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st336;
		case 123: goto tr730;
		case 125: goto st395;
	}
	goto st340;
st395:
	if ( ++p == pe )
		goto _test_eof395;
case 395:
	switch( (*p) ) {
		case 39: goto st336;
		case 123: goto tr730;
		case 125: goto tr859;
	}
	goto st340;
tr855:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st396;
st396:
	if ( ++p == pe )
		goto _test_eof396;
case 396:
#line 12545 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr860;
		case 37: goto tr861;
		case 39: goto st336;
		case 62: goto tr863;
		case 123: goto tr730;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr860;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st396;
		} else if ( (*p) >= 65 )
			goto st396;
	} else
		goto st396;
	goto st340;
tr1049:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st397;
tr850:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st397;
tr863:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st397;
st397:
	if ( ++p == pe )
		goto _test_eof397;
case 397:
#line 12607 "shortcodes.c"
	switch( (*p) ) {
		case 39: goto st336;
		case 123: goto tr730;
		case 125: goto st398;
	}
	goto st340;
st398:
	if ( ++p == pe )
		goto _test_eof398;
case 398:
	switch( (*p) ) {
		case 39: goto st336;
		case 123: goto tr730;
		case 125: goto tr365;
	}
	goto st340;
tr857:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st399;
st399:
	if ( ++p == pe )
		goto _test_eof399;
case 399:
#line 12634 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr860;
		case 37: goto tr861;
		case 39: goto st336;
		case 61: goto tr865;
		case 62: goto tr863;
		case 123: goto tr730;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr860;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st399;
		} else if ( (*p) >= 65 )
			goto st399;
	} else
		goto st396;
	goto st340;
tr865:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st400;
st400:
	if ( ++p == pe )
		goto _test_eof400;
case 400:
#line 12666 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr852;
		case 39: goto tr854;
		case 123: goto tr730;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr855;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr855;
	} else
		goto tr855;
	goto st340;
tr871:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st401;
st401:
	if ( ++p == pe )
		goto _test_eof401;
case 401:
#line 12691 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr867;
		case 34: goto st336;
		case 37: goto tr868;
		case 62: goto tr869;
		case 123: goto tr716;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr867;
	goto st335;
tr901:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st402;
tr867:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st402;
tr907:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st402;
st402:
	if ( ++p == pe )
		goto _test_eof402;
case 402:
#line 12744 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st402;
		case 34: goto tr871;
		case 37: goto st403;
		case 39: goto tr852;
		case 62: goto st418;
		case 123: goto tr716;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st402;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr875;
		} else if ( (*p) >= 65 )
			goto tr875;
	} else
		goto tr873;
	goto st335;
tr902:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st403;
tr868:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st403;
tr908:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st403;
st403:
	if ( ++p == pe )
		goto _test_eof403;
case 403:
#line 12807 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st336;
		case 123: goto tr716;
		case 125: goto st420;
	}
	goto st335;
tr716:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st404;
st404:
	if ( ++p == pe )
		goto _test_eof404;
case 404:
#line 12824 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st336;
		case 123: goto tr877;
	}
	goto st335;
tr877:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st405;
st405:
	if ( ++p == pe )
		goto _test_eof405;
case 405:
#line 12840 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st336;
		case 37: goto st406;
		case 60: goto st416;
		case 123: goto tr877;
	}
	goto st335;
st406:
	if ( ++p == pe )
		goto _test_eof406;
case 406:
	switch( (*p) ) {
		case 32: goto st406;
		case 34: goto st336;
		case 123: goto tr716;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st406;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr880;
	} else
		goto tr880;
	goto st335;
tr880:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st407;
st407:
	if ( ++p == pe )
		goto _test_eof407;
case 407:
#line 12876 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr881;
		case 34: goto st336;
		case 37: goto tr882;
		case 62: goto tr884;
		case 123: goto tr716;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr881;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st407;
		} else if ( (*p) >= 65 )
			goto st407;
	} else
		goto st407;
	goto st335;
tr881:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st408;
tr712:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st408;
tr892:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st408;
st408:
	if ( ++p == pe )
		goto _test_eof408;
case 408:
#line 12938 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st408;
		case 34: goto tr886;
		case 37: goto st409;
		case 39: goto tr695;
		case 62: goto st412;
		case 123: goto tr716;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st408;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr890;
		} else if ( (*p) >= 65 )
			goto tr890;
	} else
		goto tr888;
	goto st335;
tr882:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st409;
tr714:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st409;
tr893:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st409;
st409:
	if ( ++p == pe )
		goto _test_eof409;
case 409:
#line 13001 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st336;
		case 123: goto tr716;
		case 125: goto st410;
	}
	goto st335;
st410:
	if ( ++p == pe )
		goto _test_eof410;
case 410:
	switch( (*p) ) {
		case 34: goto st336;
		case 123: goto tr716;
		case 125: goto tr406;
	}
	goto st335;
tr888:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st411;
st411:
	if ( ++p == pe )
		goto _test_eof411;
case 411:
#line 13028 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr892;
		case 34: goto st336;
		case 37: goto tr893;
		case 62: goto tr895;
		case 123: goto tr716;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr892;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st411;
		} else if ( (*p) >= 65 )
			goto st411;
	} else
		goto st411;
	goto st335;
tr884:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st412;
tr715:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st412;
tr895:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st412;
st412:
	if ( ++p == pe )
		goto _test_eof412;
case 412:
#line 13090 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st336;
		case 123: goto tr716;
		case 125: goto st413;
	}
	goto st335;
st413:
	if ( ++p == pe )
		goto _test_eof413;
case 413:
	switch( (*p) ) {
		case 34: goto st336;
		case 123: goto tr716;
		case 125: goto tr897;
	}
	goto st335;
tr897:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st528;
tr906:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st528;
st528:
	if ( ++p == pe )
		goto _test_eof528;
case 528:
#line 13137 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st336;
		case 123: goto tr716;
	}
	goto st335;
tr890:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st414;
st414:
	if ( ++p == pe )
		goto _test_eof414;
case 414:
#line 13153 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr892;
		case 34: goto st336;
		case 37: goto tr893;
		case 61: goto tr898;
		case 62: goto tr895;
		case 123: goto tr716;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr892;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st414;
		} else if ( (*p) >= 65 )
			goto st414;
	} else
		goto st411;
	goto st335;
tr898:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st415;
st415:
	if ( ++p == pe )
		goto _test_eof415;
case 415:
#line 13185 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr886;
		case 39: goto tr695;
		case 123: goto tr716;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr888;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr888;
	} else
		goto tr888;
	goto st335;
st416:
	if ( ++p == pe )
		goto _test_eof416;
case 416:
	switch( (*p) ) {
		case 32: goto st416;
		case 34: goto st336;
		case 123: goto tr716;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st416;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr900;
	} else
		goto tr900;
	goto st335;
tr900:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st417;
st417:
	if ( ++p == pe )
		goto _test_eof417;
case 417:
#line 13228 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr901;
		case 34: goto st336;
		case 37: goto tr902;
		case 62: goto tr904;
		case 123: goto tr716;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr901;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st417;
		} else if ( (*p) >= 65 )
			goto st417;
	} else
		goto st417;
	goto st335;
tr904:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st418;
tr869:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st418;
tr910:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st418;
st418:
	if ( ++p == pe )
		goto _test_eof418;
case 418:
#line 13290 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st336;
		case 123: goto tr716;
		case 125: goto st419;
	}
	goto st335;
st419:
	if ( ++p == pe )
		goto _test_eof419;
case 419:
	switch( (*p) ) {
		case 34: goto st336;
		case 123: goto tr716;
		case 125: goto tr421;
	}
	goto st335;
st420:
	if ( ++p == pe )
		goto _test_eof420;
case 420:
	switch( (*p) ) {
		case 34: goto st336;
		case 123: goto tr716;
		case 125: goto tr906;
	}
	goto st335;
tr873:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st421;
st421:
	if ( ++p == pe )
		goto _test_eof421;
case 421:
#line 13327 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr907;
		case 34: goto st336;
		case 37: goto tr908;
		case 62: goto tr910;
		case 123: goto tr716;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr907;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st421;
		} else if ( (*p) >= 65 )
			goto st421;
	} else
		goto st421;
	goto st335;
tr875:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st422;
st422:
	if ( ++p == pe )
		goto _test_eof422;
case 422:
#line 13357 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr907;
		case 34: goto st336;
		case 37: goto tr908;
		case 61: goto tr911;
		case 62: goto tr910;
		case 123: goto tr716;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr907;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st422;
		} else if ( (*p) >= 65 )
			goto st422;
	} else
		goto st421;
	goto st335;
tr911:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st423;
st423:
	if ( ++p == pe )
		goto _test_eof423;
case 423:
#line 13389 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr871;
		case 39: goto tr852;
		case 123: goto tr716;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr873;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr873;
	} else
		goto tr873;
	goto st335;
tr847:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st424;
st424:
	if ( ++p == pe )
		goto _test_eof424;
case 424:
#line 13414 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st392;
		case 39: goto st401;
		case 123: goto tr913;
	}
	goto st391;
tr913:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st425;
st425:
	if ( ++p == pe )
		goto _test_eof425;
case 425:
#line 13431 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st392;
		case 37: goto st426;
		case 39: goto st401;
		case 60: goto st445;
		case 123: goto tr913;
	}
	goto st391;
st426:
	if ( ++p == pe )
		goto _test_eof426;
case 426:
	switch( (*p) ) {
		case 32: goto st426;
		case 34: goto st392;
		case 39: goto st401;
		case 123: goto tr847;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st426;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr916;
	} else
		goto tr916;
	goto st391;
tr916:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st427;
st427:
	if ( ++p == pe )
		goto _test_eof427;
case 427:
#line 13469 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr917;
		case 34: goto st392;
		case 37: goto tr918;
		case 39: goto st401;
		case 62: goto tr920;
		case 123: goto tr847;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr917;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st427;
		} else if ( (*p) >= 65 )
			goto st427;
	} else
		goto st427;
	goto st391;
tr917:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st428;
tr842:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st428;
tr945:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st428;
st428:
	if ( ++p == pe )
		goto _test_eof428;
case 428:
#line 13532 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st428;
		case 34: goto tr922;
		case 37: goto st438;
		case 39: goto tr829;
		case 62: goto st441;
		case 123: goto tr847;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st428;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr926;
		} else if ( (*p) >= 65 )
			goto tr926;
	} else
		goto tr924;
	goto st391;
tr922:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st429;
st429:
	if ( ++p == pe )
		goto _test_eof429;
case 429:
#line 13563 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr927;
		case 34: goto st347;
		case 37: goto tr928;
		case 39: goto st352;
		case 62: goto tr929;
		case 123: goto tr749;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr927;
	goto st346;
tr1035:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st430;
tr927:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st430;
tr937:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st430;
st430:
	if ( ++p == pe )
		goto _test_eof430;
case 430:
#line 13617 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st430;
		case 34: goto tr831;
		case 37: goto st431;
		case 39: goto tr922;
		case 62: goto st434;
		case 123: goto tr749;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st430;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr934;
		} else if ( (*p) >= 65 )
			goto tr934;
	} else
		goto tr932;
	goto st346;
tr1036:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st431;
tr928:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st431;
tr938:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st431;
st431:
	if ( ++p == pe )
		goto _test_eof431;
case 431:
#line 13680 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st347;
		case 39: goto st352;
		case 123: goto tr749;
		case 125: goto st432;
	}
	goto st346;
st432:
	if ( ++p == pe )
		goto _test_eof432;
case 432:
	switch( (*p) ) {
		case 34: goto st347;
		case 39: goto st352;
		case 123: goto tr749;
		case 125: goto tr936;
	}
	goto st346;
tr932:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st433;
st433:
	if ( ++p == pe )
		goto _test_eof433;
case 433:
#line 13709 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr937;
		case 34: goto st347;
		case 37: goto tr938;
		case 39: goto st352;
		case 62: goto tr940;
		case 123: goto tr749;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr937;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st433;
		} else if ( (*p) >= 65 )
			goto st433;
	} else
		goto st433;
	goto st346;
tr1038:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st434;
tr929:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st434;
tr940:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st434;
st434:
	if ( ++p == pe )
		goto _test_eof434;
case 434:
#line 13772 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st347;
		case 39: goto st352;
		case 123: goto tr749;
		case 125: goto st435;
	}
	goto st346;
st435:
	if ( ++p == pe )
		goto _test_eof435;
case 435:
	switch( (*p) ) {
		case 34: goto st347;
		case 39: goto st352;
		case 123: goto tr749;
		case 125: goto tr471;
	}
	goto st346;
tr934:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st436;
st436:
	if ( ++p == pe )
		goto _test_eof436;
case 436:
#line 13801 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr937;
		case 34: goto st347;
		case 37: goto tr938;
		case 39: goto st352;
		case 61: goto tr942;
		case 62: goto tr940;
		case 123: goto tr749;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr937;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st436;
		} else if ( (*p) >= 65 )
			goto st436;
	} else
		goto st433;
	goto st346;
tr942:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st437;
st437:
	if ( ++p == pe )
		goto _test_eof437;
case 437:
#line 13834 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr831;
		case 39: goto tr922;
		case 123: goto tr749;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr932;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr932;
	} else
		goto tr932;
	goto st346;
tr918:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st438;
tr844:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st438;
tr946:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st438;
st438:
	if ( ++p == pe )
		goto _test_eof438;
case 438:
#line 13891 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st392;
		case 39: goto st401;
		case 123: goto tr847;
		case 125: goto st439;
	}
	goto st391;
st439:
	if ( ++p == pe )
		goto _test_eof439;
case 439:
	switch( (*p) ) {
		case 34: goto st392;
		case 39: goto st401;
		case 123: goto tr847;
		case 125: goto tr475;
	}
	goto st391;
tr924:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st440;
st440:
	if ( ++p == pe )
		goto _test_eof440;
case 440:
#line 13920 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr945;
		case 34: goto st392;
		case 37: goto tr946;
		case 39: goto st401;
		case 62: goto tr948;
		case 123: goto tr847;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr945;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st440;
		} else if ( (*p) >= 65 )
			goto st440;
	} else
		goto st440;
	goto st391;
tr920:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st441;
tr846:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st441;
tr948:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st441;
st441:
	if ( ++p == pe )
		goto _test_eof441;
case 441:
#line 13983 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st392;
		case 39: goto st401;
		case 123: goto tr847;
		case 125: goto st442;
	}
	goto st391;
st442:
	if ( ++p == pe )
		goto _test_eof442;
case 442:
	switch( (*p) ) {
		case 34: goto st392;
		case 39: goto st401;
		case 123: goto tr847;
		case 125: goto tr950;
	}
	goto st391;
tr950:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st529;
tr968:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st529;
st529:
	if ( ++p == pe )
		goto _test_eof529;
case 529:
#line 14032 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st392;
		case 39: goto st401;
		case 123: goto tr847;
	}
	goto st391;
tr926:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st443;
st443:
	if ( ++p == pe )
		goto _test_eof443;
case 443:
#line 14049 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr945;
		case 34: goto st392;
		case 37: goto tr946;
		case 39: goto st401;
		case 61: goto tr951;
		case 62: goto tr948;
		case 123: goto tr847;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr945;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st443;
		} else if ( (*p) >= 65 )
			goto st443;
	} else
		goto st440;
	goto st391;
tr951:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st444;
st444:
	if ( ++p == pe )
		goto _test_eof444;
case 444:
#line 14082 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr922;
		case 39: goto tr829;
		case 123: goto tr847;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr924;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr924;
	} else
		goto tr924;
	goto st391;
st445:
	if ( ++p == pe )
		goto _test_eof445;
case 445:
	switch( (*p) ) {
		case 32: goto st445;
		case 34: goto st392;
		case 39: goto st401;
		case 123: goto tr847;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st445;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr953;
	} else
		goto tr953;
	goto st391;
tr953:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st446;
st446:
	if ( ++p == pe )
		goto _test_eof446;
case 446:
#line 14126 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr954;
		case 34: goto st392;
		case 37: goto tr955;
		case 39: goto st401;
		case 62: goto tr957;
		case 123: goto tr847;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr954;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st446;
		} else if ( (*p) >= 65 )
			goto st446;
	} else
		goto st446;
	goto st391;
tr954:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st447;
tr964:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st447;
tr970:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st447;
st447:
	if ( ++p == pe )
		goto _test_eof447;
case 447:
#line 14189 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st447;
		case 34: goto tr959;
		case 37: goto st449;
		case 39: goto tr959;
		case 62: goto st451;
		case 123: goto tr847;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st447;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr963;
		} else if ( (*p) >= 65 )
			goto tr963;
	} else
		goto tr961;
	goto st391;
tr959:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st448;
st448:
	if ( ++p == pe )
		goto _test_eof448;
case 448:
#line 14220 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr964;
		case 34: goto st392;
		case 37: goto tr965;
		case 39: goto st401;
		case 62: goto tr966;
		case 123: goto tr847;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr964;
	goto st391;
tr955:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st449;
tr965:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st449;
tr971:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st449;
st449:
	if ( ++p == pe )
		goto _test_eof449;
case 449:
#line 14274 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st392;
		case 39: goto st401;
		case 123: goto tr847;
		case 125: goto st450;
	}
	goto st391;
st450:
	if ( ++p == pe )
		goto _test_eof450;
case 450:
	switch( (*p) ) {
		case 34: goto st392;
		case 39: goto st401;
		case 123: goto tr847;
		case 125: goto tr968;
	}
	goto st391;
tr957:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st451;
tr966:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st451;
tr973:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st451;
st451:
	if ( ++p == pe )
		goto _test_eof451;
case 451:
#line 14335 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st392;
		case 39: goto st401;
		case 123: goto tr847;
		case 125: goto st452;
	}
	goto st391;
st452:
	if ( ++p == pe )
		goto _test_eof452;
case 452:
	switch( (*p) ) {
		case 34: goto st392;
		case 39: goto st401;
		case 123: goto tr847;
		case 125: goto tr501;
	}
	goto st391;
tr961:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st453;
st453:
	if ( ++p == pe )
		goto _test_eof453;
case 453:
#line 14364 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr970;
		case 34: goto st392;
		case 37: goto tr971;
		case 39: goto st401;
		case 62: goto tr973;
		case 123: goto tr847;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr970;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st453;
		} else if ( (*p) >= 65 )
			goto st453;
	} else
		goto st453;
	goto st391;
tr963:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st454;
st454:
	if ( ++p == pe )
		goto _test_eof454;
case 454:
#line 14395 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr970;
		case 34: goto st392;
		case 37: goto tr971;
		case 39: goto st401;
		case 61: goto tr974;
		case 62: goto tr973;
		case 123: goto tr847;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr970;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st454;
		} else if ( (*p) >= 65 )
			goto st454;
	} else
		goto st453;
	goto st391;
tr974:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st455;
st455:
	if ( ++p == pe )
		goto _test_eof455;
case 455:
#line 14428 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr959;
		case 39: goto tr959;
		case 123: goto tr847;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr961;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr961;
	} else
		goto tr961;
	goto st391;
tr832:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st456;
st456:
	if ( ++p == pe )
		goto _test_eof456;
case 456:
#line 14453 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr976;
		case 34: goto st329;
		case 37: goto tr977;
		case 39: goto st334;
		case 62: goto tr979;
		case 123: goto tr704;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr976;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st456;
		} else if ( (*p) >= 65 )
			goto st456;
	} else
		goto st456;
	goto st328;
tr834:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st457;
st457:
	if ( ++p == pe )
		goto _test_eof457;
case 457:
#line 14484 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr976;
		case 34: goto st329;
		case 37: goto tr977;
		case 39: goto st334;
		case 61: goto tr980;
		case 62: goto tr979;
		case 123: goto tr704;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr976;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st457;
		} else if ( (*p) >= 65 )
			goto st457;
	} else
		goto st456;
	goto st328;
tr980:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st458;
st458:
	if ( ++p == pe )
		goto _test_eof458;
case 458:
#line 14517 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr829;
		case 39: goto tr831;
		case 123: goto tr704;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr832;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr832;
	} else
		goto tr832;
	goto st328;
st459:
	if ( ++p == pe )
		goto _test_eof459;
case 459:
	switch( (*p) ) {
		case 34: goto st329;
		case 39: goto st334;
		case 123: goto tr704;
		case 125: goto tr514;
	}
	goto st328;
tr809:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st460;
st460:
	if ( ++p == pe )
		goto _test_eof460;
case 460:
#line 14553 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr982;
		case 34: goto st329;
		case 37: goto tr983;
		case 39: goto st334;
		case 62: goto tr985;
		case 123: goto tr704;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr982;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st460;
		} else if ( (*p) >= 65 )
			goto st460;
	} else
		goto st460;
	goto st328;
tr811:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st461;
st461:
	if ( ++p == pe )
		goto _test_eof461;
case 461:
#line 14584 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr982;
		case 34: goto st329;
		case 37: goto tr983;
		case 39: goto st334;
		case 61: goto tr986;
		case 62: goto tr985;
		case 123: goto tr704;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr982;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st461;
		} else if ( (*p) >= 65 )
			goto st461;
	} else
		goto st460;
	goto st328;
tr986:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st462;
st462:
	if ( ++p == pe )
		goto _test_eof462;
case 462:
#line 14617 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr785;
		case 39: goto tr799;
		case 123: goto tr704;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr809;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr809;
	} else
		goto tr809;
	goto st328;
tr1017:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st463;
tr796:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st463;
tr1023:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st463;
st463:
	if ( ++p == pe )
		goto _test_eof463;
case 463:
#line 14674 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st311;
		case 39: goto st305;
		case 123: goto tr660;
		case 125: goto st481;
	}
	goto st310;
tr660:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st464;
st464:
	if ( ++p == pe )
		goto _test_eof464;
case 464:
#line 14692 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st311;
		case 39: goto st305;
		case 123: goto tr989;
	}
	goto st310;
tr989:
#line 103 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st465;
st465:
	if ( ++p == pe )
		goto _test_eof465;
case 465:
#line 14709 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st311;
		case 37: goto st466;
		case 39: goto st305;
		case 60: goto st477;
		case 123: goto tr989;
	}
	goto st310;
st466:
	if ( ++p == pe )
		goto _test_eof466;
case 466:
	switch( (*p) ) {
		case 32: goto st466;
		case 34: goto st311;
		case 39: goto st305;
		case 123: goto tr660;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st466;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr992;
	} else
		goto tr992;
	goto st310;
tr992:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st467;
st467:
	if ( ++p == pe )
		goto _test_eof467;
case 467:
#line 14747 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr993;
		case 34: goto st311;
		case 37: goto tr994;
		case 39: goto st305;
		case 62: goto tr996;
		case 123: goto tr660;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr993;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st467;
		} else if ( (*p) >= 65 )
			goto st467;
	} else
		goto st467;
	goto st310;
tr993:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st468;
tr1003:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st468;
tr1009:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st468;
st468:
	if ( ++p == pe )
		goto _test_eof468;
case 468:
#line 14810 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st468;
		case 34: goto tr998;
		case 37: goto st470;
		case 39: goto tr998;
		case 62: goto st472;
		case 123: goto tr660;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st468;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr1002;
		} else if ( (*p) >= 65 )
			goto tr1002;
	} else
		goto tr1000;
	goto st310;
tr998:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st469;
st469:
	if ( ++p == pe )
		goto _test_eof469;
case 469:
#line 14841 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr1003;
		case 34: goto st311;
		case 37: goto tr1004;
		case 39: goto st305;
		case 62: goto tr1005;
		case 123: goto tr660;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr1003;
	goto st310;
tr994:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st470;
tr1004:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st470;
tr1010:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st470;
st470:
	if ( ++p == pe )
		goto _test_eof470;
case 470:
#line 14895 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st311;
		case 39: goto st305;
		case 123: goto tr660;
		case 125: goto st471;
	}
	goto st310;
st471:
	if ( ++p == pe )
		goto _test_eof471;
case 471:
	switch( (*p) ) {
		case 34: goto st311;
		case 39: goto st305;
		case 123: goto tr660;
		case 125: goto tr553;
	}
	goto st310;
tr996:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st472;
tr1005:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st472;
tr1012:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st472;
st472:
	if ( ++p == pe )
		goto _test_eof472;
case 472:
#line 14956 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st311;
		case 39: goto st305;
		case 123: goto tr660;
		case 125: goto st473;
	}
	goto st310;
st473:
	if ( ++p == pe )
		goto _test_eof473;
case 473:
	switch( (*p) ) {
		case 34: goto st311;
		case 39: goto st305;
		case 123: goto tr660;
		case 125: goto tr1008;
	}
	goto st310;
tr1008:
#line 81 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st530;
tr1021:
#line 75 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 92 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st530;
st530:
	if ( ++p == pe )
		goto _test_eof530;
case 530:
#line 15005 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st311;
		case 39: goto st305;
		case 123: goto tr660;
	}
	goto st310;
tr1000:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st474;
st474:
	if ( ++p == pe )
		goto _test_eof474;
case 474:
#line 15022 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr1009;
		case 34: goto st311;
		case 37: goto tr1010;
		case 39: goto st305;
		case 62: goto tr1012;
		case 123: goto tr660;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr1009;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st474;
		} else if ( (*p) >= 65 )
			goto st474;
	} else
		goto st474;
	goto st310;
tr1002:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st475;
st475:
	if ( ++p == pe )
		goto _test_eof475;
case 475:
#line 15053 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr1009;
		case 34: goto st311;
		case 37: goto tr1010;
		case 39: goto st305;
		case 61: goto tr1013;
		case 62: goto tr1012;
		case 123: goto tr660;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr1009;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st475;
		} else if ( (*p) >= 65 )
			goto st475;
	} else
		goto st474;
	goto st310;
tr1013:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st476;
st476:
	if ( ++p == pe )
		goto _test_eof476;
case 476:
#line 15086 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr998;
		case 39: goto tr998;
		case 123: goto tr660;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr1000;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1000;
	} else
		goto tr1000;
	goto st310;
st477:
	if ( ++p == pe )
		goto _test_eof477;
case 477:
	switch( (*p) ) {
		case 32: goto st477;
		case 34: goto st311;
		case 39: goto st305;
		case 123: goto tr660;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st477;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1015;
	} else
		goto tr1015;
	goto st310;
tr1015:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st478;
st478:
	if ( ++p == pe )
		goto _test_eof478;
case 478:
#line 15130 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr1016;
		case 34: goto st311;
		case 37: goto tr1017;
		case 39: goto st305;
		case 62: goto tr1019;
		case 123: goto tr660;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr1016;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st478;
		} else if ( (*p) >= 65 )
			goto st478;
	} else
		goto st478;
	goto st310;
tr1019:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st479;
tr797:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st479;
tr1025:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st479;
st479:
	if ( ++p == pe )
		goto _test_eof479;
case 479:
#line 15193 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st311;
		case 39: goto st305;
		case 123: goto tr660;
		case 125: goto st480;
	}
	goto st310;
st480:
	if ( ++p == pe )
		goto _test_eof480;
case 480:
	switch( (*p) ) {
		case 34: goto st311;
		case 39: goto st305;
		case 123: goto tr660;
		case 125: goto tr568;
	}
	goto st310;
st481:
	if ( ++p == pe )
		goto _test_eof481;
case 481:
	switch( (*p) ) {
		case 34: goto st311;
		case 39: goto st305;
		case 123: goto tr660;
		case 125: goto tr1021;
	}
	goto st310;
tr801:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st482;
st482:
	if ( ++p == pe )
		goto _test_eof482;
case 482:
#line 15233 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr1022;
		case 34: goto st311;
		case 37: goto tr1023;
		case 39: goto st305;
		case 62: goto tr1025;
		case 123: goto tr660;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr1022;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st482;
		} else if ( (*p) >= 65 )
			goto st482;
	} else
		goto st482;
	goto st310;
tr803:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st483;
st483:
	if ( ++p == pe )
		goto _test_eof483;
case 483:
#line 15264 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr1022;
		case 34: goto st311;
		case 37: goto tr1023;
		case 39: goto st305;
		case 61: goto tr1026;
		case 62: goto tr1025;
		case 123: goto tr660;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr1022;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st483;
		} else if ( (*p) >= 65 )
			goto st483;
	} else
		goto st482;
	goto st310;
tr1026:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st484;
st484:
	if ( ++p == pe )
		goto _test_eof484;
case 484:
#line 15297 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr799;
		case 39: goto tr783;
		case 123: goto tr660;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr801;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr801;
	} else
		goto tr801;
	goto st310;
tr786:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st485;
st485:
	if ( ++p == pe )
		goto _test_eof485;
case 485:
#line 15322 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr1028;
		case 34: goto st347;
		case 37: goto tr1029;
		case 39: goto st352;
		case 62: goto tr1031;
		case 123: goto tr749;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr1028;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st485;
		} else if ( (*p) >= 65 )
			goto st485;
	} else
		goto st485;
	goto st346;
tr788:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st486;
st486:
	if ( ++p == pe )
		goto _test_eof486;
case 486:
#line 15353 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr1028;
		case 34: goto st347;
		case 37: goto tr1029;
		case 39: goto st352;
		case 61: goto tr1032;
		case 62: goto tr1031;
		case 123: goto tr749;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr1028;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st486;
		} else if ( (*p) >= 65 )
			goto st486;
	} else
		goto st485;
	goto st346;
tr1032:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st487;
st487:
	if ( ++p == pe )
		goto _test_eof487;
case 487:
#line 15386 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr783;
		case 39: goto tr785;
		case 123: goto tr749;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr786;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr786;
	} else
		goto tr786;
	goto st346;
st488:
	if ( ++p == pe )
		goto _test_eof488;
case 488:
	switch( (*p) ) {
		case 32: goto st488;
		case 34: goto st347;
		case 39: goto st352;
		case 123: goto tr749;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st488;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1034;
	} else
		goto tr1034;
	goto st346;
tr1034:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st489;
st489:
	if ( ++p == pe )
		goto _test_eof489;
case 489:
#line 15430 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr1035;
		case 34: goto st347;
		case 37: goto tr1036;
		case 39: goto st352;
		case 62: goto tr1038;
		case 123: goto tr749;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr1035;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st489;
		} else if ( (*p) >= 65 )
			goto st489;
	} else
		goto st489;
	goto st346;
tr743:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st490;
st490:
	if ( ++p == pe )
		goto _test_eof490;
case 490:
#line 15461 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr1039;
		case 37: goto tr1040;
		case 39: goto st336;
		case 62: goto tr1042;
		case 123: goto tr730;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr1039;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st490;
		} else if ( (*p) >= 65 )
			goto st490;
	} else
		goto st490;
	goto st340;
tr745:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st491;
st491:
	if ( ++p == pe )
		goto _test_eof491;
case 491:
#line 15491 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr1039;
		case 37: goto tr1040;
		case 39: goto st336;
		case 61: goto tr1043;
		case 62: goto tr1042;
		case 123: goto tr730;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr1039;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st491;
		} else if ( (*p) >= 65 )
			goto st491;
	} else
		goto st490;
	goto st340;
tr1043:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st492;
st492:
	if ( ++p == pe )
		goto _test_eof492;
case 492:
#line 15523 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr740;
		case 39: goto tr742;
		case 123: goto tr730;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr743;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr743;
	} else
		goto tr743;
	goto st340;
st493:
	if ( ++p == pe )
		goto _test_eof493;
case 493:
	switch( (*p) ) {
		case 32: goto st493;
		case 39: goto st336;
		case 123: goto tr730;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st493;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1045;
	} else
		goto tr1045;
	goto st340;
tr1045:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st494;
st494:
	if ( ++p == pe )
		goto _test_eof494;
case 494:
#line 15566 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr1046;
		case 37: goto tr1047;
		case 39: goto st336;
		case 62: goto tr1049;
		case 123: goto tr730;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr1046;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st494;
		} else if ( (*p) >= 65 )
			goto st494;
	} else
		goto st494;
	goto st340;
tr724:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st495;
st495:
	if ( ++p == pe )
		goto _test_eof495;
case 495:
#line 15596 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr1050;
		case 37: goto tr1051;
		case 62: goto tr1053;
		case 123: goto tr1;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr1050;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st495;
		} else if ( (*p) >= 65 )
			goto st495;
	} else
		goto st495;
	goto st0;
tr1084:
#line 23 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st496;
tr719:
#line 45 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st496;
tr1053:
#line 58 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st496;
st496:
	if ( ++p == pe )
		goto _test_eof496;
case 496:
#line 15657 "shortcodes.c"
	switch( (*p) ) {
		case 123: goto tr1;
		case 125: goto st497;
	}
	goto st0;
st497:
	if ( ++p == pe )
		goto _test_eof497;
case 497:
	switch( (*p) ) {
		case 123: goto tr1;
		case 125: goto tr603;
	}
	goto st0;
tr726:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st498;
st498:
	if ( ++p == pe )
		goto _test_eof498;
case 498:
#line 15682 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr1050;
		case 37: goto tr1051;
		case 61: goto tr1055;
		case 62: goto tr1053;
		case 123: goto tr1;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr1050;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st498;
		} else if ( (*p) >= 65 )
			goto st498;
	} else
		goto st495;
	goto st0;
tr1055:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st499;
st499:
	if ( ++p == pe )
		goto _test_eof499;
case 499:
#line 15713 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr721;
		case 39: goto tr723;
		case 123: goto tr1;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr724;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr724;
	} else
		goto tr724;
	goto st0;
tr698:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st500;
st500:
	if ( ++p == pe )
		goto _test_eof500;
case 500:
#line 15738 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr1057;
		case 37: goto tr1058;
		case 39: goto st7;
		case 62: goto tr1060;
		case 123: goto tr665;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr1057;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st500;
		} else if ( (*p) >= 65 )
			goto st500;
	} else
		goto st500;
	goto st312;
tr700:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st501;
st501:
	if ( ++p == pe )
		goto _test_eof501;
case 501:
#line 15768 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr1057;
		case 37: goto tr1058;
		case 39: goto st7;
		case 61: goto tr1061;
		case 62: goto tr1060;
		case 123: goto tr665;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr1057;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st501;
		} else if ( (*p) >= 65 )
			goto st501;
	} else
		goto st500;
	goto st312;
tr1061:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st502;
st502:
	if ( ++p == pe )
		goto _test_eof502;
case 502:
#line 15800 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr695;
		case 39: goto tr697;
		case 123: goto tr665;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr698;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr698;
	} else
		goto tr698;
	goto st312;
tr648:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st503;
st503:
	if ( ++p == pe )
		goto _test_eof503;
case 503:
#line 15825 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr1063;
		case 34: goto st7;
		case 37: goto tr1064;
		case 62: goto tr1066;
		case 123: goto tr19;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr1063;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st503;
		} else if ( (*p) >= 65 )
			goto st503;
	} else
		goto st503;
	goto st6;
tr650:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st504;
st504:
	if ( ++p == pe )
		goto _test_eof504;
case 504:
#line 15855 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr1063;
		case 34: goto st7;
		case 37: goto tr1064;
		case 61: goto tr1067;
		case 62: goto tr1066;
		case 123: goto tr19;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr1063;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st504;
		} else if ( (*p) >= 65 )
			goto st504;
	} else
		goto st503;
	goto st6;
tr1067:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st505;
st505:
	if ( ++p == pe )
		goto _test_eof505;
case 505:
#line 15887 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr645;
		case 39: goto tr647;
		case 123: goto tr19;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr648;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr648;
	} else
		goto tr648;
	goto st6;
st506:
	if ( ++p == pe )
		goto _test_eof506;
case 506:
	switch( (*p) ) {
		case 32: goto st506;
		case 34: goto st7;
		case 123: goto tr19;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st506;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1069;
	} else
		goto tr1069;
	goto st6;
tr1069:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st507;
st507:
	if ( ++p == pe )
		goto _test_eof507;
case 507:
#line 15930 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr1070;
		case 34: goto st7;
		case 37: goto tr1071;
		case 62: goto tr1073;
		case 123: goto tr19;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr1070;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st507;
		} else if ( (*p) >= 65 )
			goto st507;
	} else
		goto st507;
	goto st6;
tr14:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st508;
st508:
	if ( ++p == pe )
		goto _test_eof508;
case 508:
#line 15960 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr1074;
		case 37: goto tr1075;
		case 62: goto tr1077;
		case 123: goto tr1;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr1074;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st508;
		} else if ( (*p) >= 65 )
			goto st508;
	} else
		goto st508;
	goto st0;
tr16:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st509;
st509:
	if ( ++p == pe )
		goto _test_eof509;
case 509:
#line 15989 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr1074;
		case 37: goto tr1075;
		case 61: goto tr1078;
		case 62: goto tr1077;
		case 123: goto tr1;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr1074;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st509;
		} else if ( (*p) >= 65 )
			goto st509;
	} else
		goto st508;
	goto st0;
tr1078:
#line 37 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st510;
st510:
	if ( ++p == pe )
		goto _test_eof510;
case 510:
#line 16020 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr11;
		case 39: goto tr13;
		case 123: goto tr1;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr14;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr14;
	} else
		goto tr14;
	goto st0;
st511:
	if ( ++p == pe )
		goto _test_eof511;
case 511:
	switch( (*p) ) {
		case 32: goto st511;
		case 123: goto tr1;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st511;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr1080;
	} else
		goto tr1080;
	goto st0;
tr1080:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st512;
st512:
	if ( ++p == pe )
		goto _test_eof512;
case 512:
#line 16062 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr1081;
		case 37: goto tr1082;
		case 62: goto tr1084;
		case 123: goto tr1;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr1081;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st512;
		} else if ( (*p) >= 65 )
			goto st512;
	} else
		goto st512;
	goto st0;
	}
	_test_eof513: cs = 513; goto _test_eof; 
	_test_eof0: cs = 0; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof514: cs = 514; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof515: cs = 515; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
	_test_eof55: cs = 55; goto _test_eof; 
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof516: cs = 516; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof60: cs = 60; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof62: cs = 62; goto _test_eof; 
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof72: cs = 72; goto _test_eof; 
	_test_eof73: cs = 73; goto _test_eof; 
	_test_eof74: cs = 74; goto _test_eof; 
	_test_eof75: cs = 75; goto _test_eof; 
	_test_eof76: cs = 76; goto _test_eof; 
	_test_eof77: cs = 77; goto _test_eof; 
	_test_eof78: cs = 78; goto _test_eof; 
	_test_eof79: cs = 79; goto _test_eof; 
	_test_eof80: cs = 80; goto _test_eof; 
	_test_eof81: cs = 81; goto _test_eof; 
	_test_eof82: cs = 82; goto _test_eof; 
	_test_eof83: cs = 83; goto _test_eof; 
	_test_eof84: cs = 84; goto _test_eof; 
	_test_eof85: cs = 85; goto _test_eof; 
	_test_eof86: cs = 86; goto _test_eof; 
	_test_eof87: cs = 87; goto _test_eof; 
	_test_eof88: cs = 88; goto _test_eof; 
	_test_eof89: cs = 89; goto _test_eof; 
	_test_eof90: cs = 90; goto _test_eof; 
	_test_eof91: cs = 91; goto _test_eof; 
	_test_eof517: cs = 517; goto _test_eof; 
	_test_eof92: cs = 92; goto _test_eof; 
	_test_eof93: cs = 93; goto _test_eof; 
	_test_eof94: cs = 94; goto _test_eof; 
	_test_eof95: cs = 95; goto _test_eof; 
	_test_eof96: cs = 96; goto _test_eof; 
	_test_eof97: cs = 97; goto _test_eof; 
	_test_eof98: cs = 98; goto _test_eof; 
	_test_eof99: cs = 99; goto _test_eof; 
	_test_eof100: cs = 100; goto _test_eof; 
	_test_eof101: cs = 101; goto _test_eof; 
	_test_eof102: cs = 102; goto _test_eof; 
	_test_eof103: cs = 103; goto _test_eof; 
	_test_eof104: cs = 104; goto _test_eof; 
	_test_eof105: cs = 105; goto _test_eof; 
	_test_eof106: cs = 106; goto _test_eof; 
	_test_eof107: cs = 107; goto _test_eof; 
	_test_eof108: cs = 108; goto _test_eof; 
	_test_eof109: cs = 109; goto _test_eof; 
	_test_eof110: cs = 110; goto _test_eof; 
	_test_eof111: cs = 111; goto _test_eof; 
	_test_eof112: cs = 112; goto _test_eof; 
	_test_eof113: cs = 113; goto _test_eof; 
	_test_eof114: cs = 114; goto _test_eof; 
	_test_eof115: cs = 115; goto _test_eof; 
	_test_eof116: cs = 116; goto _test_eof; 
	_test_eof117: cs = 117; goto _test_eof; 
	_test_eof118: cs = 118; goto _test_eof; 
	_test_eof518: cs = 518; goto _test_eof; 
	_test_eof119: cs = 119; goto _test_eof; 
	_test_eof120: cs = 120; goto _test_eof; 
	_test_eof121: cs = 121; goto _test_eof; 
	_test_eof122: cs = 122; goto _test_eof; 
	_test_eof123: cs = 123; goto _test_eof; 
	_test_eof124: cs = 124; goto _test_eof; 
	_test_eof125: cs = 125; goto _test_eof; 
	_test_eof126: cs = 126; goto _test_eof; 
	_test_eof127: cs = 127; goto _test_eof; 
	_test_eof128: cs = 128; goto _test_eof; 
	_test_eof129: cs = 129; goto _test_eof; 
	_test_eof130: cs = 130; goto _test_eof; 
	_test_eof131: cs = 131; goto _test_eof; 
	_test_eof132: cs = 132; goto _test_eof; 
	_test_eof133: cs = 133; goto _test_eof; 
	_test_eof134: cs = 134; goto _test_eof; 
	_test_eof135: cs = 135; goto _test_eof; 
	_test_eof136: cs = 136; goto _test_eof; 
	_test_eof137: cs = 137; goto _test_eof; 
	_test_eof138: cs = 138; goto _test_eof; 
	_test_eof139: cs = 139; goto _test_eof; 
	_test_eof140: cs = 140; goto _test_eof; 
	_test_eof519: cs = 519; goto _test_eof; 
	_test_eof141: cs = 141; goto _test_eof; 
	_test_eof142: cs = 142; goto _test_eof; 
	_test_eof143: cs = 143; goto _test_eof; 
	_test_eof144: cs = 144; goto _test_eof; 
	_test_eof145: cs = 145; goto _test_eof; 
	_test_eof146: cs = 146; goto _test_eof; 
	_test_eof147: cs = 147; goto _test_eof; 
	_test_eof148: cs = 148; goto _test_eof; 
	_test_eof149: cs = 149; goto _test_eof; 
	_test_eof150: cs = 150; goto _test_eof; 
	_test_eof151: cs = 151; goto _test_eof; 
	_test_eof152: cs = 152; goto _test_eof; 
	_test_eof153: cs = 153; goto _test_eof; 
	_test_eof154: cs = 154; goto _test_eof; 
	_test_eof155: cs = 155; goto _test_eof; 
	_test_eof156: cs = 156; goto _test_eof; 
	_test_eof157: cs = 157; goto _test_eof; 
	_test_eof158: cs = 158; goto _test_eof; 
	_test_eof159: cs = 159; goto _test_eof; 
	_test_eof160: cs = 160; goto _test_eof; 
	_test_eof161: cs = 161; goto _test_eof; 
	_test_eof162: cs = 162; goto _test_eof; 
	_test_eof163: cs = 163; goto _test_eof; 
	_test_eof164: cs = 164; goto _test_eof; 
	_test_eof165: cs = 165; goto _test_eof; 
	_test_eof166: cs = 166; goto _test_eof; 
	_test_eof167: cs = 167; goto _test_eof; 
	_test_eof168: cs = 168; goto _test_eof; 
	_test_eof169: cs = 169; goto _test_eof; 
	_test_eof170: cs = 170; goto _test_eof; 
	_test_eof171: cs = 171; goto _test_eof; 
	_test_eof172: cs = 172; goto _test_eof; 
	_test_eof173: cs = 173; goto _test_eof; 
	_test_eof174: cs = 174; goto _test_eof; 
	_test_eof175: cs = 175; goto _test_eof; 
	_test_eof520: cs = 520; goto _test_eof; 
	_test_eof176: cs = 176; goto _test_eof; 
	_test_eof177: cs = 177; goto _test_eof; 
	_test_eof178: cs = 178; goto _test_eof; 
	_test_eof179: cs = 179; goto _test_eof; 
	_test_eof180: cs = 180; goto _test_eof; 
	_test_eof181: cs = 181; goto _test_eof; 
	_test_eof182: cs = 182; goto _test_eof; 
	_test_eof183: cs = 183; goto _test_eof; 
	_test_eof184: cs = 184; goto _test_eof; 
	_test_eof185: cs = 185; goto _test_eof; 
	_test_eof186: cs = 186; goto _test_eof; 
	_test_eof187: cs = 187; goto _test_eof; 
	_test_eof188: cs = 188; goto _test_eof; 
	_test_eof189: cs = 189; goto _test_eof; 
	_test_eof190: cs = 190; goto _test_eof; 
	_test_eof191: cs = 191; goto _test_eof; 
	_test_eof192: cs = 192; goto _test_eof; 
	_test_eof193: cs = 193; goto _test_eof; 
	_test_eof194: cs = 194; goto _test_eof; 
	_test_eof195: cs = 195; goto _test_eof; 
	_test_eof196: cs = 196; goto _test_eof; 
	_test_eof197: cs = 197; goto _test_eof; 
	_test_eof198: cs = 198; goto _test_eof; 
	_test_eof199: cs = 199; goto _test_eof; 
	_test_eof200: cs = 200; goto _test_eof; 
	_test_eof201: cs = 201; goto _test_eof; 
	_test_eof202: cs = 202; goto _test_eof; 
	_test_eof521: cs = 521; goto _test_eof; 
	_test_eof203: cs = 203; goto _test_eof; 
	_test_eof204: cs = 204; goto _test_eof; 
	_test_eof205: cs = 205; goto _test_eof; 
	_test_eof206: cs = 206; goto _test_eof; 
	_test_eof207: cs = 207; goto _test_eof; 
	_test_eof208: cs = 208; goto _test_eof; 
	_test_eof209: cs = 209; goto _test_eof; 
	_test_eof210: cs = 210; goto _test_eof; 
	_test_eof211: cs = 211; goto _test_eof; 
	_test_eof212: cs = 212; goto _test_eof; 
	_test_eof213: cs = 213; goto _test_eof; 
	_test_eof214: cs = 214; goto _test_eof; 
	_test_eof215: cs = 215; goto _test_eof; 
	_test_eof216: cs = 216; goto _test_eof; 
	_test_eof217: cs = 217; goto _test_eof; 
	_test_eof218: cs = 218; goto _test_eof; 
	_test_eof219: cs = 219; goto _test_eof; 
	_test_eof220: cs = 220; goto _test_eof; 
	_test_eof221: cs = 221; goto _test_eof; 
	_test_eof222: cs = 222; goto _test_eof; 
	_test_eof223: cs = 223; goto _test_eof; 
	_test_eof224: cs = 224; goto _test_eof; 
	_test_eof225: cs = 225; goto _test_eof; 
	_test_eof226: cs = 226; goto _test_eof; 
	_test_eof227: cs = 227; goto _test_eof; 
	_test_eof228: cs = 228; goto _test_eof; 
	_test_eof229: cs = 229; goto _test_eof; 
	_test_eof230: cs = 230; goto _test_eof; 
	_test_eof231: cs = 231; goto _test_eof; 
	_test_eof232: cs = 232; goto _test_eof; 
	_test_eof233: cs = 233; goto _test_eof; 
	_test_eof234: cs = 234; goto _test_eof; 
	_test_eof235: cs = 235; goto _test_eof; 
	_test_eof236: cs = 236; goto _test_eof; 
	_test_eof237: cs = 237; goto _test_eof; 
	_test_eof238: cs = 238; goto _test_eof; 
	_test_eof239: cs = 239; goto _test_eof; 
	_test_eof240: cs = 240; goto _test_eof; 
	_test_eof241: cs = 241; goto _test_eof; 
	_test_eof242: cs = 242; goto _test_eof; 
	_test_eof243: cs = 243; goto _test_eof; 
	_test_eof244: cs = 244; goto _test_eof; 
	_test_eof245: cs = 245; goto _test_eof; 
	_test_eof246: cs = 246; goto _test_eof; 
	_test_eof247: cs = 247; goto _test_eof; 
	_test_eof248: cs = 248; goto _test_eof; 
	_test_eof249: cs = 249; goto _test_eof; 
	_test_eof522: cs = 522; goto _test_eof; 
	_test_eof250: cs = 250; goto _test_eof; 
	_test_eof251: cs = 251; goto _test_eof; 
	_test_eof252: cs = 252; goto _test_eof; 
	_test_eof253: cs = 253; goto _test_eof; 
	_test_eof254: cs = 254; goto _test_eof; 
	_test_eof255: cs = 255; goto _test_eof; 
	_test_eof256: cs = 256; goto _test_eof; 
	_test_eof257: cs = 257; goto _test_eof; 
	_test_eof258: cs = 258; goto _test_eof; 
	_test_eof259: cs = 259; goto _test_eof; 
	_test_eof260: cs = 260; goto _test_eof; 
	_test_eof261: cs = 261; goto _test_eof; 
	_test_eof262: cs = 262; goto _test_eof; 
	_test_eof263: cs = 263; goto _test_eof; 
	_test_eof264: cs = 264; goto _test_eof; 
	_test_eof265: cs = 265; goto _test_eof; 
	_test_eof266: cs = 266; goto _test_eof; 
	_test_eof267: cs = 267; goto _test_eof; 
	_test_eof268: cs = 268; goto _test_eof; 
	_test_eof269: cs = 269; goto _test_eof; 
	_test_eof270: cs = 270; goto _test_eof; 
	_test_eof271: cs = 271; goto _test_eof; 
	_test_eof272: cs = 272; goto _test_eof; 
	_test_eof273: cs = 273; goto _test_eof; 
	_test_eof274: cs = 274; goto _test_eof; 
	_test_eof275: cs = 275; goto _test_eof; 
	_test_eof276: cs = 276; goto _test_eof; 
	_test_eof277: cs = 277; goto _test_eof; 
	_test_eof278: cs = 278; goto _test_eof; 
	_test_eof279: cs = 279; goto _test_eof; 
	_test_eof280: cs = 280; goto _test_eof; 
	_test_eof281: cs = 281; goto _test_eof; 
	_test_eof282: cs = 282; goto _test_eof; 
	_test_eof283: cs = 283; goto _test_eof; 
	_test_eof284: cs = 284; goto _test_eof; 
	_test_eof285: cs = 285; goto _test_eof; 
	_test_eof286: cs = 286; goto _test_eof; 
	_test_eof287: cs = 287; goto _test_eof; 
	_test_eof288: cs = 288; goto _test_eof; 
	_test_eof289: cs = 289; goto _test_eof; 
	_test_eof290: cs = 290; goto _test_eof; 
	_test_eof291: cs = 291; goto _test_eof; 
	_test_eof292: cs = 292; goto _test_eof; 
	_test_eof293: cs = 293; goto _test_eof; 
	_test_eof294: cs = 294; goto _test_eof; 
	_test_eof295: cs = 295; goto _test_eof; 
	_test_eof296: cs = 296; goto _test_eof; 
	_test_eof297: cs = 297; goto _test_eof; 
	_test_eof298: cs = 298; goto _test_eof; 
	_test_eof299: cs = 299; goto _test_eof; 
	_test_eof300: cs = 300; goto _test_eof; 
	_test_eof301: cs = 301; goto _test_eof; 
	_test_eof302: cs = 302; goto _test_eof; 
	_test_eof303: cs = 303; goto _test_eof; 
	_test_eof304: cs = 304; goto _test_eof; 
	_test_eof305: cs = 305; goto _test_eof; 
	_test_eof306: cs = 306; goto _test_eof; 
	_test_eof307: cs = 307; goto _test_eof; 
	_test_eof308: cs = 308; goto _test_eof; 
	_test_eof309: cs = 309; goto _test_eof; 
	_test_eof523: cs = 523; goto _test_eof; 
	_test_eof310: cs = 310; goto _test_eof; 
	_test_eof311: cs = 311; goto _test_eof; 
	_test_eof312: cs = 312; goto _test_eof; 
	_test_eof313: cs = 313; goto _test_eof; 
	_test_eof314: cs = 314; goto _test_eof; 
	_test_eof315: cs = 315; goto _test_eof; 
	_test_eof316: cs = 316; goto _test_eof; 
	_test_eof317: cs = 317; goto _test_eof; 
	_test_eof318: cs = 318; goto _test_eof; 
	_test_eof319: cs = 319; goto _test_eof; 
	_test_eof320: cs = 320; goto _test_eof; 
	_test_eof321: cs = 321; goto _test_eof; 
	_test_eof322: cs = 322; goto _test_eof; 
	_test_eof524: cs = 524; goto _test_eof; 
	_test_eof323: cs = 323; goto _test_eof; 
	_test_eof324: cs = 324; goto _test_eof; 
	_test_eof325: cs = 325; goto _test_eof; 
	_test_eof326: cs = 326; goto _test_eof; 
	_test_eof327: cs = 327; goto _test_eof; 
	_test_eof328: cs = 328; goto _test_eof; 
	_test_eof329: cs = 329; goto _test_eof; 
	_test_eof330: cs = 330; goto _test_eof; 
	_test_eof331: cs = 331; goto _test_eof; 
	_test_eof332: cs = 332; goto _test_eof; 
	_test_eof333: cs = 333; goto _test_eof; 
	_test_eof334: cs = 334; goto _test_eof; 
	_test_eof335: cs = 335; goto _test_eof; 
	_test_eof336: cs = 336; goto _test_eof; 
	_test_eof337: cs = 337; goto _test_eof; 
	_test_eof338: cs = 338; goto _test_eof; 
	_test_eof339: cs = 339; goto _test_eof; 
	_test_eof340: cs = 340; goto _test_eof; 
	_test_eof341: cs = 341; goto _test_eof; 
	_test_eof342: cs = 342; goto _test_eof; 
	_test_eof343: cs = 343; goto _test_eof; 
	_test_eof344: cs = 344; goto _test_eof; 
	_test_eof345: cs = 345; goto _test_eof; 
	_test_eof346: cs = 346; goto _test_eof; 
	_test_eof347: cs = 347; goto _test_eof; 
	_test_eof348: cs = 348; goto _test_eof; 
	_test_eof349: cs = 349; goto _test_eof; 
	_test_eof350: cs = 350; goto _test_eof; 
	_test_eof351: cs = 351; goto _test_eof; 
	_test_eof525: cs = 525; goto _test_eof; 
	_test_eof352: cs = 352; goto _test_eof; 
	_test_eof353: cs = 353; goto _test_eof; 
	_test_eof354: cs = 354; goto _test_eof; 
	_test_eof355: cs = 355; goto _test_eof; 
	_test_eof356: cs = 356; goto _test_eof; 
	_test_eof357: cs = 357; goto _test_eof; 
	_test_eof358: cs = 358; goto _test_eof; 
	_test_eof359: cs = 359; goto _test_eof; 
	_test_eof360: cs = 360; goto _test_eof; 
	_test_eof361: cs = 361; goto _test_eof; 
	_test_eof362: cs = 362; goto _test_eof; 
	_test_eof363: cs = 363; goto _test_eof; 
	_test_eof364: cs = 364; goto _test_eof; 
	_test_eof365: cs = 365; goto _test_eof; 
	_test_eof366: cs = 366; goto _test_eof; 
	_test_eof367: cs = 367; goto _test_eof; 
	_test_eof368: cs = 368; goto _test_eof; 
	_test_eof369: cs = 369; goto _test_eof; 
	_test_eof370: cs = 370; goto _test_eof; 
	_test_eof526: cs = 526; goto _test_eof; 
	_test_eof371: cs = 371; goto _test_eof; 
	_test_eof372: cs = 372; goto _test_eof; 
	_test_eof373: cs = 373; goto _test_eof; 
	_test_eof374: cs = 374; goto _test_eof; 
	_test_eof375: cs = 375; goto _test_eof; 
	_test_eof376: cs = 376; goto _test_eof; 
	_test_eof377: cs = 377; goto _test_eof; 
	_test_eof378: cs = 378; goto _test_eof; 
	_test_eof379: cs = 379; goto _test_eof; 
	_test_eof380: cs = 380; goto _test_eof; 
	_test_eof381: cs = 381; goto _test_eof; 
	_test_eof527: cs = 527; goto _test_eof; 
	_test_eof382: cs = 382; goto _test_eof; 
	_test_eof383: cs = 383; goto _test_eof; 
	_test_eof384: cs = 384; goto _test_eof; 
	_test_eof385: cs = 385; goto _test_eof; 
	_test_eof386: cs = 386; goto _test_eof; 
	_test_eof387: cs = 387; goto _test_eof; 
	_test_eof388: cs = 388; goto _test_eof; 
	_test_eof389: cs = 389; goto _test_eof; 
	_test_eof390: cs = 390; goto _test_eof; 
	_test_eof391: cs = 391; goto _test_eof; 
	_test_eof392: cs = 392; goto _test_eof; 
	_test_eof393: cs = 393; goto _test_eof; 
	_test_eof394: cs = 394; goto _test_eof; 
	_test_eof395: cs = 395; goto _test_eof; 
	_test_eof396: cs = 396; goto _test_eof; 
	_test_eof397: cs = 397; goto _test_eof; 
	_test_eof398: cs = 398; goto _test_eof; 
	_test_eof399: cs = 399; goto _test_eof; 
	_test_eof400: cs = 400; goto _test_eof; 
	_test_eof401: cs = 401; goto _test_eof; 
	_test_eof402: cs = 402; goto _test_eof; 
	_test_eof403: cs = 403; goto _test_eof; 
	_test_eof404: cs = 404; goto _test_eof; 
	_test_eof405: cs = 405; goto _test_eof; 
	_test_eof406: cs = 406; goto _test_eof; 
	_test_eof407: cs = 407; goto _test_eof; 
	_test_eof408: cs = 408; goto _test_eof; 
	_test_eof409: cs = 409; goto _test_eof; 
	_test_eof410: cs = 410; goto _test_eof; 
	_test_eof411: cs = 411; goto _test_eof; 
	_test_eof412: cs = 412; goto _test_eof; 
	_test_eof413: cs = 413; goto _test_eof; 
	_test_eof528: cs = 528; goto _test_eof; 
	_test_eof414: cs = 414; goto _test_eof; 
	_test_eof415: cs = 415; goto _test_eof; 
	_test_eof416: cs = 416; goto _test_eof; 
	_test_eof417: cs = 417; goto _test_eof; 
	_test_eof418: cs = 418; goto _test_eof; 
	_test_eof419: cs = 419; goto _test_eof; 
	_test_eof420: cs = 420; goto _test_eof; 
	_test_eof421: cs = 421; goto _test_eof; 
	_test_eof422: cs = 422; goto _test_eof; 
	_test_eof423: cs = 423; goto _test_eof; 
	_test_eof424: cs = 424; goto _test_eof; 
	_test_eof425: cs = 425; goto _test_eof; 
	_test_eof426: cs = 426; goto _test_eof; 
	_test_eof427: cs = 427; goto _test_eof; 
	_test_eof428: cs = 428; goto _test_eof; 
	_test_eof429: cs = 429; goto _test_eof; 
	_test_eof430: cs = 430; goto _test_eof; 
	_test_eof431: cs = 431; goto _test_eof; 
	_test_eof432: cs = 432; goto _test_eof; 
	_test_eof433: cs = 433; goto _test_eof; 
	_test_eof434: cs = 434; goto _test_eof; 
	_test_eof435: cs = 435; goto _test_eof; 
	_test_eof436: cs = 436; goto _test_eof; 
	_test_eof437: cs = 437; goto _test_eof; 
	_test_eof438: cs = 438; goto _test_eof; 
	_test_eof439: cs = 439; goto _test_eof; 
	_test_eof440: cs = 440; goto _test_eof; 
	_test_eof441: cs = 441; goto _test_eof; 
	_test_eof442: cs = 442; goto _test_eof; 
	_test_eof529: cs = 529; goto _test_eof; 
	_test_eof443: cs = 443; goto _test_eof; 
	_test_eof444: cs = 444; goto _test_eof; 
	_test_eof445: cs = 445; goto _test_eof; 
	_test_eof446: cs = 446; goto _test_eof; 
	_test_eof447: cs = 447; goto _test_eof; 
	_test_eof448: cs = 448; goto _test_eof; 
	_test_eof449: cs = 449; goto _test_eof; 
	_test_eof450: cs = 450; goto _test_eof; 
	_test_eof451: cs = 451; goto _test_eof; 
	_test_eof452: cs = 452; goto _test_eof; 
	_test_eof453: cs = 453; goto _test_eof; 
	_test_eof454: cs = 454; goto _test_eof; 
	_test_eof455: cs = 455; goto _test_eof; 
	_test_eof456: cs = 456; goto _test_eof; 
	_test_eof457: cs = 457; goto _test_eof; 
	_test_eof458: cs = 458; goto _test_eof; 
	_test_eof459: cs = 459; goto _test_eof; 
	_test_eof460: cs = 460; goto _test_eof; 
	_test_eof461: cs = 461; goto _test_eof; 
	_test_eof462: cs = 462; goto _test_eof; 
	_test_eof463: cs = 463; goto _test_eof; 
	_test_eof464: cs = 464; goto _test_eof; 
	_test_eof465: cs = 465; goto _test_eof; 
	_test_eof466: cs = 466; goto _test_eof; 
	_test_eof467: cs = 467; goto _test_eof; 
	_test_eof468: cs = 468; goto _test_eof; 
	_test_eof469: cs = 469; goto _test_eof; 
	_test_eof470: cs = 470; goto _test_eof; 
	_test_eof471: cs = 471; goto _test_eof; 
	_test_eof472: cs = 472; goto _test_eof; 
	_test_eof473: cs = 473; goto _test_eof; 
	_test_eof530: cs = 530; goto _test_eof; 
	_test_eof474: cs = 474; goto _test_eof; 
	_test_eof475: cs = 475; goto _test_eof; 
	_test_eof476: cs = 476; goto _test_eof; 
	_test_eof477: cs = 477; goto _test_eof; 
	_test_eof478: cs = 478; goto _test_eof; 
	_test_eof479: cs = 479; goto _test_eof; 
	_test_eof480: cs = 480; goto _test_eof; 
	_test_eof481: cs = 481; goto _test_eof; 
	_test_eof482: cs = 482; goto _test_eof; 
	_test_eof483: cs = 483; goto _test_eof; 
	_test_eof484: cs = 484; goto _test_eof; 
	_test_eof485: cs = 485; goto _test_eof; 
	_test_eof486: cs = 486; goto _test_eof; 
	_test_eof487: cs = 487; goto _test_eof; 
	_test_eof488: cs = 488; goto _test_eof; 
	_test_eof489: cs = 489; goto _test_eof; 
	_test_eof490: cs = 490; goto _test_eof; 
	_test_eof491: cs = 491; goto _test_eof; 
	_test_eof492: cs = 492; goto _test_eof; 
	_test_eof493: cs = 493; goto _test_eof; 
	_test_eof494: cs = 494; goto _test_eof; 
	_test_eof495: cs = 495; goto _test_eof; 
	_test_eof496: cs = 496; goto _test_eof; 
	_test_eof497: cs = 497; goto _test_eof; 
	_test_eof498: cs = 498; goto _test_eof; 
	_test_eof499: cs = 499; goto _test_eof; 
	_test_eof500: cs = 500; goto _test_eof; 
	_test_eof501: cs = 501; goto _test_eof; 
	_test_eof502: cs = 502; goto _test_eof; 
	_test_eof503: cs = 503; goto _test_eof; 
	_test_eof504: cs = 504; goto _test_eof; 
	_test_eof505: cs = 505; goto _test_eof; 
	_test_eof506: cs = 506; goto _test_eof; 
	_test_eof507: cs = 507; goto _test_eof; 
	_test_eof508: cs = 508; goto _test_eof; 
	_test_eof509: cs = 509; goto _test_eof; 
	_test_eof510: cs = 510; goto _test_eof; 
	_test_eof511: cs = 511; goto _test_eof; 
	_test_eof512: cs = 512; goto _test_eof; 

	_test_eof: {}
	}

#line 180 "shortcodes.rl"

  result.sccount = c_sc;
  return result;
}
