
#line 1 "shortcodes.rl"
#include <string.h>
#include "shortcodes.h"


#line 124 "shortcodes.rl"



sc_result parse(char *input, unsigned int len) {

  
#line 15 "shortcodes.c"
static const int shortcode_start = 141;
static const int shortcode_first_final = 141;
static const int shortcode_error = -1;

static const int shortcode_en_main = 141;


#line 130 "shortcodes.rl"
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

  
#line 41 "shortcodes.c"
	{
	cs = shortcode_start;
	}

#line 147 "shortcodes.rl"
  
#line 48 "shortcodes.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr176:
#line 71 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st141;
st141:
	if ( ++p == pe )
		goto _test_eof141;
case 141:
#line 69 "shortcodes.c"
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
#line 81 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st1;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
#line 90 "shortcodes.c"
	if ( (*p) == 123 )
		goto tr2;
	goto st0;
tr2:
#line 81 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 104 "shortcodes.c"
	switch( (*p) ) {
		case 37: goto st3;
		case 60: goto st139;
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
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 138 "shortcodes.c"
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
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st5;
tr19:
#line 35 "shortcodes.rl"
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
tr267:
#line 47 "shortcodes.rl"
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
#line 198 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st5;
		case 34: goto tr11;
		case 37: goto st8;
		case 62: goto st88;
		case 123: goto tr1;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st5;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr15;
		} else if ( (*p) >= 65 )
			goto tr15;
	} else
		goto tr13;
	goto st0;
tr11:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
#line 228 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr18;
	}
	goto st6;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	switch( (*p) ) {
		case 32: goto tr19;
		case 37: goto tr20;
		case 62: goto tr21;
		case 123: goto tr1;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr19;
	goto st0;
tr7:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st8;
tr20:
#line 35 "shortcodes.rl"
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
tr224:
#line 47 "shortcodes.rl"
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
#line 288 "shortcodes.c"
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
		case 125: goto tr23;
	}
	goto st0;
tr23:
#line 84 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st142;
tr38:
#line 103 "shortcodes.rl"
	{
    if (
        sc_list[c_sc-1].name.len != sc_list[c_sc].name.len ||
        strncmp(
          start + sc_list[c_sc-1].name.start,
          start + sc_list[c_sc].name.start,
          sc_list[c_sc-1].name.len) !=0) 
    {
      result.errors[result.errcount].position = 
          sc_list[c_sc].whole.start;
      result.errors[result.errcount].code = ERR_MISMATCHED_CLOSING_TAG;
      result.errcount++;
    } else {
      // The previous shortcode is matching (mark it)
      sc_list[c_sc-1].matching = 1;
      sc_list[c_sc-1].whole.len = p-start-sc_list[c_sc-1].whole.start + 1;
    }
    // Do NOT increase c_sc
}
	goto st142;
tr57:
#line 71 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st142;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
#line 348 "shortcodes.c"
	if ( (*p) == 123 )
		goto tr25;
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
	if ( (*p) == 123 )
		goto tr25;
	goto st10;
tr25:
#line 81 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 91 "shortcodes.rl"
	{
    // Starting a "closing" shortcode ( {{ /foo }}), 
    // close data (if previous shortcode is opening)
    // If previous shortcode was closing, then previous 
    // text can't be data.
    if (sc_list[c_sc-1].matching == 0) {
      sc_list[c_sc-1].data.start = data_mark-start;
      sc_list[c_sc-1].data.len = p-data_mark-1;
    }
  }
	goto st11;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
#line 380 "shortcodes.c"
	if ( (*p) == 123 )
		goto tr26;
	goto st10;
tr26:
#line 81 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 91 "shortcodes.rl"
	{
    // Starting a "closing" shortcode ( {{ /foo }}), 
    // close data (if previous shortcode is opening)
    // If previous shortcode was closing, then previous 
    // text can't be data.
    if (sc_list[c_sc-1].matching == 0) {
      sc_list[c_sc-1].data.start = data_mark-start;
      sc_list[c_sc-1].data.len = p-data_mark-1;
    }
  }
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
#line 405 "shortcodes.c"
	switch( (*p) ) {
		case 37: goto st13;
		case 60: goto st86;
		case 123: goto tr26;
	}
	goto st10;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	switch( (*p) ) {
		case 32: goto st13;
		case 47: goto st14;
		case 123: goto tr25;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st13;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr30;
	} else
		goto tr30;
	goto st10;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	if ( (*p) == 123 )
		goto tr25;
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr31;
	} else if ( (*p) >= 65 )
		goto tr31;
	goto st10;
tr31:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
#line 452 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr32;
		case 37: goto tr33;
		case 62: goto tr33;
		case 123: goto tr25;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr32;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st15;
		} else if ( (*p) >= 65 )
			goto st15;
	} else
		goto st15;
	goto st10;
tr32:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
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
#line 488 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st16;
		case 37: goto st17;
		case 62: goto st17;
		case 123: goto tr25;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st16;
	goto st10;
tr33:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
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
#line 515 "shortcodes.c"
	switch( (*p) ) {
		case 123: goto tr25;
		case 125: goto st18;
	}
	goto st10;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	switch( (*p) ) {
		case 123: goto tr25;
		case 125: goto tr38;
	}
	goto st10;
tr30:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 540 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr39;
		case 37: goto tr40;
		case 62: goto tr42;
		case 123: goto tr25;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr39;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st19;
		} else if ( (*p) >= 65 )
			goto st19;
	} else
		goto st19;
	goto st10;
tr39:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st20;
tr52:
#line 35 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st20;
tr168:
#line 47 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
#line 600 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st20;
		case 34: goto tr44;
		case 37: goto st23;
		case 62: goto st25;
		case 123: goto tr25;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st20;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr48;
		} else if ( (*p) >= 65 )
			goto tr48;
	} else
		goto tr46;
	goto st10;
tr44:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 630 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st22;
		case 123: goto tr51;
	}
	goto st21;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
	switch( (*p) ) {
		case 32: goto tr52;
		case 37: goto tr53;
		case 62: goto tr54;
		case 123: goto tr25;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr52;
	goto st10;
tr40:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st23;
tr53:
#line 35 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st23;
tr115:
#line 47 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
#line 690 "shortcodes.c"
	switch( (*p) ) {
		case 123: goto tr25;
		case 125: goto st24;
	}
	goto st10;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	switch( (*p) ) {
		case 123: goto tr25;
		case 125: goto tr23;
	}
	goto st10;
tr42:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st25;
tr54:
#line 35 "shortcodes.rl"
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
tr113:
#line 47 "shortcodes.rl"
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
#line 746 "shortcodes.c"
	switch( (*p) ) {
		case 123: goto tr25;
		case 125: goto st26;
	}
	goto st10;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	switch( (*p) ) {
		case 123: goto tr25;
		case 125: goto tr57;
	}
	goto st10;
tr51:
#line 81 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 91 "shortcodes.rl"
	{
    // Starting a "closing" shortcode ( {{ /foo }}), 
    // close data (if previous shortcode is opening)
    // If previous shortcode was closing, then previous 
    // text can't be data.
    if (sc_list[c_sc-1].matching == 0) {
      sc_list[c_sc-1].data.start = data_mark-start;
      sc_list[c_sc-1].data.len = p-data_mark-1;
    }
  }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 782 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st22;
		case 123: goto tr58;
	}
	goto st21;
tr58:
#line 81 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 91 "shortcodes.rl"
	{
    // Starting a "closing" shortcode ( {{ /foo }}), 
    // close data (if previous shortcode is opening)
    // If previous shortcode was closing, then previous 
    // text can't be data.
    if (sc_list[c_sc-1].matching == 0) {
      sc_list[c_sc-1].data.start = data_mark-start;
      sc_list[c_sc-1].data.len = p-data_mark-1;
    }
  }
	goto st28;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
#line 809 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st22;
		case 37: goto st29;
		case 60: goto st45;
		case 123: goto tr58;
	}
	goto st21;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
	switch( (*p) ) {
		case 32: goto st29;
		case 34: goto st22;
		case 47: goto st30;
		case 123: goto tr51;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st29;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr62;
	} else
		goto tr62;
	goto st21;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
	switch( (*p) ) {
		case 34: goto st22;
		case 123: goto tr51;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr63;
	} else if ( (*p) >= 65 )
		goto tr63;
	goto st21;
tr63:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
#line 860 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr64;
		case 34: goto st22;
		case 37: goto tr65;
		case 62: goto tr65;
		case 123: goto tr51;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr64;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st31;
		} else if ( (*p) >= 65 )
			goto st31;
	} else
		goto st31;
	goto st21;
tr64:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st32;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
#line 897 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st32;
		case 34: goto st22;
		case 37: goto st33;
		case 62: goto st33;
		case 123: goto tr51;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st32;
	goto st21;
tr65:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
#line 925 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st22;
		case 123: goto tr51;
		case 125: goto st34;
	}
	goto st21;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
	switch( (*p) ) {
		case 34: goto st22;
		case 123: goto tr51;
		case 125: goto tr70;
	}
	goto st21;
tr85:
#line 84 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st143;
tr70:
#line 103 "shortcodes.rl"
	{
    if (
        sc_list[c_sc-1].name.len != sc_list[c_sc].name.len ||
        strncmp(
          start + sc_list[c_sc-1].name.start,
          start + sc_list[c_sc].name.start,
          sc_list[c_sc-1].name.len) !=0) 
    {
      result.errors[result.errcount].position = 
          sc_list[c_sc].whole.start;
      result.errors[result.errcount].code = ERR_MISMATCHED_CLOSING_TAG;
      result.errcount++;
    } else {
      // The previous shortcode is matching (mark it)
      sc_list[c_sc-1].matching = 1;
      sc_list[c_sc-1].whole.len = p-start-sc_list[c_sc-1].whole.start + 1;
    }
    // Do NOT increase c_sc
}
	goto st143;
tr87:
#line 71 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st143;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
#line 987 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st22;
		case 123: goto tr51;
	}
	goto st21;
tr62:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st35;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
#line 1003 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr71;
		case 34: goto st22;
		case 37: goto tr72;
		case 62: goto tr74;
		case 123: goto tr51;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr71;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st35;
		} else if ( (*p) >= 65 )
			goto st35;
	} else
		goto st35;
	goto st21;
tr71:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st36;
tr81:
#line 35 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st36;
tr88:
#line 47 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
#line 1064 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st36;
		case 34: goto tr76;
		case 37: goto st38;
		case 62: goto st40;
		case 123: goto tr51;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st36;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr80;
		} else if ( (*p) >= 65 )
			goto tr80;
	} else
		goto tr78;
	goto st21;
tr76:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
#line 1094 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr81;
		case 34: goto st22;
		case 37: goto tr82;
		case 62: goto tr83;
		case 123: goto tr51;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr81;
	goto st21;
tr72:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st38;
tr82:
#line 35 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st38;
tr89:
#line 47 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
#line 1146 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st22;
		case 123: goto tr51;
		case 125: goto st39;
	}
	goto st21;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
	switch( (*p) ) {
		case 34: goto st22;
		case 123: goto tr51;
		case 125: goto tr85;
	}
	goto st21;
tr74:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st40;
tr83:
#line 35 "shortcodes.rl"
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
tr91:
#line 47 "shortcodes.rl"
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
#line 1204 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st22;
		case 123: goto tr51;
		case 125: goto st41;
	}
	goto st21;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
	switch( (*p) ) {
		case 34: goto st22;
		case 123: goto tr51;
		case 125: goto tr87;
	}
	goto st21;
tr78:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 1231 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr88;
		case 34: goto st22;
		case 37: goto tr89;
		case 62: goto tr91;
		case 123: goto tr51;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr88;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st42;
		} else if ( (*p) >= 65 )
			goto st42;
	} else
		goto st42;
	goto st21;
tr80:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st43;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
#line 1261 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr88;
		case 34: goto st22;
		case 37: goto tr89;
		case 61: goto tr92;
		case 62: goto tr91;
		case 123: goto tr51;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr88;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st43;
		} else if ( (*p) >= 65 )
			goto st43;
	} else
		goto st42;
	goto st21;
tr92:
#line 29 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
#line 1293 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr76;
		case 123: goto tr51;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr78;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr78;
	} else
		goto tr78;
	goto st21;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	switch( (*p) ) {
		case 32: goto st45;
		case 34: goto st22;
		case 47: goto st30;
		case 123: goto tr51;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st45;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr94;
	} else
		goto tr94;
	goto st21;
tr94:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st46;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
#line 1336 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr95;
		case 34: goto st22;
		case 37: goto tr74;
		case 62: goto tr72;
		case 123: goto tr51;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr95;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st46;
		} else if ( (*p) >= 65 )
			goto st46;
	} else
		goto st46;
	goto st21;
tr95:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st47;
tr141:
#line 35 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st47;
tr164:
#line 47 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
#line 1397 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st47;
		case 34: goto tr98;
		case 37: goto st40;
		case 62: goto st38;
		case 123: goto tr51;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st47;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr100;
		} else if ( (*p) >= 65 )
			goto tr100;
	} else
		goto tr99;
	goto st21;
tr98:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
#line 1427 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr102;
		case 34: goto st50;
		case 37: goto tr104;
		case 62: goto tr105;
		case 123: goto tr106;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr102;
	goto st49;
tr109:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st49;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
#line 1448 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st50;
		case 123: goto tr106;
	}
	goto st49;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
	switch( (*p) ) {
		case 32: goto tr107;
		case 37: goto tr54;
		case 62: goto tr53;
		case 123: goto tr25;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr107;
	goto st10;
tr173:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st51;
tr107:
#line 35 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st51;
tr112:
#line 47 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
#line 1508 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st51;
		case 34: goto tr109;
		case 37: goto st25;
		case 62: goto st23;
		case 123: goto tr25;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st51;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr111;
		} else if ( (*p) >= 65 )
			goto tr111;
	} else
		goto tr110;
	goto st10;
tr110:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
#line 1538 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr112;
		case 37: goto tr113;
		case 62: goto tr115;
		case 123: goto tr25;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr112;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st52;
		} else if ( (*p) >= 65 )
			goto st52;
	} else
		goto st52;
	goto st10;
tr111:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st53;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
#line 1567 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr112;
		case 37: goto tr113;
		case 61: goto tr116;
		case 62: goto tr115;
		case 123: goto tr25;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr112;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st53;
		} else if ( (*p) >= 65 )
			goto st53;
	} else
		goto st52;
	goto st10;
tr116:
#line 29 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
#line 1598 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr109;
		case 123: goto tr25;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr110;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr110;
	} else
		goto tr110;
	goto st10;
tr106:
#line 81 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 91 "shortcodes.rl"
	{
    // Starting a "closing" shortcode ( {{ /foo }}), 
    // close data (if previous shortcode is opening)
    // If previous shortcode was closing, then previous 
    // text can't be data.
    if (sc_list[c_sc-1].matching == 0) {
      sc_list[c_sc-1].data.start = data_mark-start;
      sc_list[c_sc-1].data.len = p-data_mark-1;
    }
  }
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
#line 1633 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st50;
		case 123: goto tr118;
	}
	goto st49;
tr118:
#line 81 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 91 "shortcodes.rl"
	{
    // Starting a "closing" shortcode ( {{ /foo }}), 
    // close data (if previous shortcode is opening)
    // If previous shortcode was closing, then previous 
    // text can't be data.
    if (sc_list[c_sc-1].matching == 0) {
      sc_list[c_sc-1].data.start = data_mark-start;
      sc_list[c_sc-1].data.len = p-data_mark-1;
    }
  }
	goto st56;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
#line 1660 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st50;
		case 37: goto st57;
		case 60: goto st73;
		case 123: goto tr118;
	}
	goto st49;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	switch( (*p) ) {
		case 32: goto st57;
		case 34: goto st50;
		case 47: goto st58;
		case 123: goto tr106;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st57;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr122;
	} else
		goto tr122;
	goto st49;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
	switch( (*p) ) {
		case 34: goto st50;
		case 123: goto tr106;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr123;
	} else if ( (*p) >= 65 )
		goto tr123;
	goto st49;
tr123:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st59;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
#line 1711 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr124;
		case 34: goto st50;
		case 37: goto tr125;
		case 62: goto tr125;
		case 123: goto tr106;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr124;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st59;
		} else if ( (*p) >= 65 )
			goto st59;
	} else
		goto st59;
	goto st49;
tr124:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
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
#line 1748 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st60;
		case 34: goto st50;
		case 37: goto st61;
		case 62: goto st61;
		case 123: goto tr106;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st60;
	goto st49;
tr125:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
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
#line 1776 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st50;
		case 123: goto tr106;
		case 125: goto st62;
	}
	goto st49;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
	switch( (*p) ) {
		case 34: goto st50;
		case 123: goto tr106;
		case 125: goto tr130;
	}
	goto st49;
tr143:
#line 84 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st144;
tr130:
#line 103 "shortcodes.rl"
	{
    if (
        sc_list[c_sc-1].name.len != sc_list[c_sc].name.len ||
        strncmp(
          start + sc_list[c_sc-1].name.start,
          start + sc_list[c_sc].name.start,
          sc_list[c_sc-1].name.len) !=0) 
    {
      result.errors[result.errcount].position = 
          sc_list[c_sc].whole.start;
      result.errors[result.errcount].code = ERR_MISMATCHED_CLOSING_TAG;
      result.errcount++;
    } else {
      // The previous shortcode is matching (mark it)
      sc_list[c_sc-1].matching = 1;
      sc_list[c_sc-1].whole.len = p-start-sc_list[c_sc-1].whole.start + 1;
    }
    // Do NOT increase c_sc
}
	goto st144;
tr149:
#line 71 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st144;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
#line 1838 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st50;
		case 123: goto tr106;
	}
	goto st49;
tr122:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
#line 1854 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr131;
		case 34: goto st50;
		case 37: goto tr132;
		case 62: goto tr134;
		case 123: goto tr106;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr131;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st63;
		} else if ( (*p) >= 65 )
			goto st63;
	} else
		goto st63;
	goto st49;
tr131:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st64;
tr102:
#line 35 "shortcodes.rl"
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
tr144:
#line 47 "shortcodes.rl"
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
#line 1915 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st64;
		case 34: goto tr136;
		case 37: goto st66;
		case 62: goto st69;
		case 123: goto tr106;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st64;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr140;
		} else if ( (*p) >= 65 )
			goto tr140;
	} else
		goto tr138;
	goto st49;
tr136:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st65;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
#line 1945 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr141;
		case 34: goto st22;
		case 37: goto tr83;
		case 62: goto tr82;
		case 123: goto tr51;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr141;
	goto st21;
tr132:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st66;
tr104:
#line 35 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st66;
tr145:
#line 47 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st66;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
#line 1997 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st50;
		case 123: goto tr106;
		case 125: goto st67;
	}
	goto st49;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
	switch( (*p) ) {
		case 34: goto st50;
		case 123: goto tr106;
		case 125: goto tr143;
	}
	goto st49;
tr138:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st68;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
#line 2024 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr144;
		case 34: goto st50;
		case 37: goto tr145;
		case 62: goto tr147;
		case 123: goto tr106;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr144;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st68;
		} else if ( (*p) >= 65 )
			goto st68;
	} else
		goto st68;
	goto st49;
tr134:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st69;
tr105:
#line 35 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st69;
tr147:
#line 47 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st69;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
#line 2085 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st50;
		case 123: goto tr106;
		case 125: goto st70;
	}
	goto st49;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	switch( (*p) ) {
		case 34: goto st50;
		case 123: goto tr106;
		case 125: goto tr149;
	}
	goto st49;
tr140:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st71;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
#line 2112 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr144;
		case 34: goto st50;
		case 37: goto tr145;
		case 61: goto tr150;
		case 62: goto tr147;
		case 123: goto tr106;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr144;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st71;
		} else if ( (*p) >= 65 )
			goto st71;
	} else
		goto st68;
	goto st49;
tr150:
#line 29 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st72;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
#line 2144 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr136;
		case 123: goto tr106;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr138;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr138;
	} else
		goto tr138;
	goto st49;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
	switch( (*p) ) {
		case 32: goto st73;
		case 34: goto st50;
		case 47: goto st58;
		case 123: goto tr106;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st73;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr152;
	} else
		goto tr152;
	goto st49;
tr152:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st74;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
#line 2187 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr153;
		case 34: goto st50;
		case 37: goto tr134;
		case 62: goto tr132;
		case 123: goto tr106;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr153;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st74;
		} else if ( (*p) >= 65 )
			goto st74;
	} else
		goto st74;
	goto st49;
tr153:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st75;
tr159:
#line 35 "shortcodes.rl"
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
tr160:
#line 47 "shortcodes.rl"
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
#line 2248 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st75;
		case 34: goto tr156;
		case 37: goto st69;
		case 62: goto st66;
		case 123: goto tr106;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st75;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr158;
		} else if ( (*p) >= 65 )
			goto tr158;
	} else
		goto tr157;
	goto st49;
tr156:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st76;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
#line 2278 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr159;
		case 34: goto st50;
		case 37: goto tr105;
		case 62: goto tr104;
		case 123: goto tr106;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr159;
	goto st49;
tr157:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st77;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
#line 2299 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr160;
		case 34: goto st50;
		case 37: goto tr147;
		case 62: goto tr145;
		case 123: goto tr106;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr160;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st77;
		} else if ( (*p) >= 65 )
			goto st77;
	} else
		goto st77;
	goto st49;
tr158:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st78;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
#line 2329 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr160;
		case 34: goto st50;
		case 37: goto tr147;
		case 61: goto tr162;
		case 62: goto tr145;
		case 123: goto tr106;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr160;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st78;
		} else if ( (*p) >= 65 )
			goto st78;
	} else
		goto st77;
	goto st49;
tr162:
#line 29 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st79;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
#line 2361 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr156;
		case 123: goto tr106;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr157;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr157;
	} else
		goto tr157;
	goto st49;
tr99:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st80;
st80:
	if ( ++p == pe )
		goto _test_eof80;
case 80:
#line 2385 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr164;
		case 34: goto st22;
		case 37: goto tr91;
		case 62: goto tr89;
		case 123: goto tr51;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr164;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st80;
		} else if ( (*p) >= 65 )
			goto st80;
	} else
		goto st80;
	goto st21;
tr100:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st81;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
#line 2415 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr164;
		case 34: goto st22;
		case 37: goto tr91;
		case 61: goto tr166;
		case 62: goto tr89;
		case 123: goto tr51;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr164;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st81;
		} else if ( (*p) >= 65 )
			goto st81;
	} else
		goto st80;
	goto st21;
tr166:
#line 29 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st82;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
#line 2447 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr98;
		case 123: goto tr51;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr99;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr99;
	} else
		goto tr99;
	goto st21;
tr46:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st83;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
#line 2471 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr168;
		case 37: goto tr115;
		case 62: goto tr113;
		case 123: goto tr25;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr168;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st83;
		} else if ( (*p) >= 65 )
			goto st83;
	} else
		goto st83;
	goto st10;
tr48:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st84;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
#line 2500 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr168;
		case 37: goto tr115;
		case 61: goto tr170;
		case 62: goto tr113;
		case 123: goto tr25;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr168;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st84;
		} else if ( (*p) >= 65 )
			goto st84;
	} else
		goto st83;
	goto st10;
tr170:
#line 29 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st85;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
#line 2531 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr44;
		case 123: goto tr25;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr46;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr46;
	} else
		goto tr46;
	goto st10;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
	switch( (*p) ) {
		case 32: goto st86;
		case 47: goto st14;
		case 123: goto tr25;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st86;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr172;
	} else
		goto tr172;
	goto st10;
tr172:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st87;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
#line 2573 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr173;
		case 37: goto tr42;
		case 62: goto tr40;
		case 123: goto tr25;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr173;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st87;
		} else if ( (*p) >= 65 )
			goto st87;
	} else
		goto st87;
	goto st10;
tr9:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st88;
tr21:
#line 35 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st88;
tr222:
#line 47 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st88;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
#line 2633 "shortcodes.c"
	switch( (*p) ) {
		case 123: goto tr1;
		case 125: goto st89;
	}
	goto st0;
st89:
	if ( ++p == pe )
		goto _test_eof89;
case 89:
	switch( (*p) ) {
		case 123: goto tr1;
		case 125: goto tr176;
	}
	goto st0;
tr18:
#line 81 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st90;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
#line 2658 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr177;
	}
	goto st6;
tr177:
#line 81 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st91;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
#line 2674 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 37: goto st92;
		case 60: goto st103;
		case 123: goto tr177;
	}
	goto st6;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	switch( (*p) ) {
		case 32: goto st92;
		case 34: goto st7;
		case 123: goto tr18;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st92;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr180;
	} else
		goto tr180;
	goto st6;
tr180:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st93;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
#line 2710 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr181;
		case 34: goto st7;
		case 37: goto tr182;
		case 62: goto tr184;
		case 123: goto tr18;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr181;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st93;
		} else if ( (*p) >= 65 )
			goto st93;
	} else
		goto st93;
	goto st6;
tr181:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st94;
tr191:
#line 35 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st94;
tr197:
#line 47 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st94;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
#line 2771 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st94;
		case 34: goto tr186;
		case 37: goto st96;
		case 62: goto st98;
		case 123: goto tr18;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st94;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr190;
		} else if ( (*p) >= 65 )
			goto tr190;
	} else
		goto tr188;
	goto st6;
tr186:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st95;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
#line 2801 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr191;
		case 34: goto st7;
		case 37: goto tr192;
		case 62: goto tr193;
		case 123: goto tr18;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr191;
	goto st6;
tr182:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st96;
tr192:
#line 35 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st96;
tr198:
#line 47 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st96;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
#line 2853 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr18;
		case 125: goto st97;
	}
	goto st6;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr18;
		case 125: goto tr85;
	}
	goto st6;
tr184:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st98;
tr193:
#line 35 "shortcodes.rl"
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
tr200:
#line 47 "shortcodes.rl"
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
#line 2911 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr18;
		case 125: goto st99;
	}
	goto st6;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr18;
		case 125: goto tr196;
	}
	goto st6;
tr196:
#line 71 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st145;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
#line 2943 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr18;
	}
	goto st6;
tr188:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st100;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
#line 2959 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr197;
		case 34: goto st7;
		case 37: goto tr198;
		case 62: goto tr200;
		case 123: goto tr18;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr197;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st100;
		} else if ( (*p) >= 65 )
			goto st100;
	} else
		goto st100;
	goto st6;
tr190:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st101;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
#line 2989 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr197;
		case 34: goto st7;
		case 37: goto tr198;
		case 61: goto tr201;
		case 62: goto tr200;
		case 123: goto tr18;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr197;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st101;
		} else if ( (*p) >= 65 )
			goto st101;
	} else
		goto st100;
	goto st6;
tr201:
#line 29 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st102;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
#line 3021 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr186;
		case 123: goto tr18;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr188;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr188;
	} else
		goto tr188;
	goto st6;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
	switch( (*p) ) {
		case 32: goto st103;
		case 34: goto st7;
		case 123: goto tr18;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st103;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr203;
	} else
		goto tr203;
	goto st6;
tr203:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st104;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
#line 3063 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr204;
		case 34: goto st7;
		case 37: goto tr184;
		case 62: goto tr182;
		case 123: goto tr18;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr204;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st104;
		} else if ( (*p) >= 65 )
			goto st104;
	} else
		goto st104;
	goto st6;
tr204:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st105;
tr241:
#line 35 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st105;
tr263:
#line 47 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st105;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
#line 3124 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st105;
		case 34: goto tr207;
		case 37: goto st98;
		case 62: goto st96;
		case 123: goto tr18;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st105;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr209;
		} else if ( (*p) >= 65 )
			goto tr209;
	} else
		goto tr208;
	goto st6;
tr207:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st106;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
#line 3154 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr211;
		case 34: goto st108;
		case 37: goto tr213;
		case 62: goto tr214;
		case 123: goto tr215;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr211;
	goto st107;
tr218:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st107;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
#line 3175 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st108;
		case 123: goto tr215;
	}
	goto st107;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
	switch( (*p) ) {
		case 32: goto tr216;
		case 37: goto tr21;
		case 62: goto tr20;
		case 123: goto tr1;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr216;
	goto st0;
tr272:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st109;
tr216:
#line 35 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st109;
tr221:
#line 47 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st109;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
#line 3235 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st109;
		case 34: goto tr218;
		case 37: goto st88;
		case 62: goto st8;
		case 123: goto tr1;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st109;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr220;
		} else if ( (*p) >= 65 )
			goto tr220;
	} else
		goto tr219;
	goto st0;
tr219:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st110;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
#line 3265 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr221;
		case 37: goto tr222;
		case 62: goto tr224;
		case 123: goto tr1;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr221;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st110;
		} else if ( (*p) >= 65 )
			goto st110;
	} else
		goto st110;
	goto st0;
tr220:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st111;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
#line 3294 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr221;
		case 37: goto tr222;
		case 61: goto tr225;
		case 62: goto tr224;
		case 123: goto tr1;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr221;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st111;
		} else if ( (*p) >= 65 )
			goto st111;
	} else
		goto st110;
	goto st0;
tr225:
#line 29 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st112;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
#line 3325 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr218;
		case 123: goto tr1;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr219;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr219;
	} else
		goto tr219;
	goto st0;
tr215:
#line 81 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st113;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
#line 3349 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st108;
		case 123: goto tr227;
	}
	goto st107;
tr227:
#line 81 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st114;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
#line 3365 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st108;
		case 37: goto st115;
		case 60: goto st126;
		case 123: goto tr227;
	}
	goto st107;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	switch( (*p) ) {
		case 32: goto st115;
		case 34: goto st108;
		case 123: goto tr215;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st115;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr230;
	} else
		goto tr230;
	goto st107;
tr230:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st116;
st116:
	if ( ++p == pe )
		goto _test_eof116;
case 116:
#line 3401 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr231;
		case 34: goto st108;
		case 37: goto tr232;
		case 62: goto tr234;
		case 123: goto tr215;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr231;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st116;
		} else if ( (*p) >= 65 )
			goto st116;
	} else
		goto st116;
	goto st107;
tr231:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st117;
tr211:
#line 35 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st117;
tr243:
#line 47 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
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
#line 3462 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st117;
		case 34: goto tr236;
		case 37: goto st119;
		case 62: goto st122;
		case 123: goto tr215;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st117;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr240;
		} else if ( (*p) >= 65 )
			goto tr240;
	} else
		goto tr238;
	goto st107;
tr236:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st118;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
#line 3492 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr241;
		case 34: goto st7;
		case 37: goto tr193;
		case 62: goto tr192;
		case 123: goto tr18;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr241;
	goto st6;
tr232:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st119;
tr213:
#line 35 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st119;
tr244:
#line 47 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
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
#line 3544 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st108;
		case 123: goto tr215;
		case 125: goto st120;
	}
	goto st107;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
	switch( (*p) ) {
		case 34: goto st108;
		case 123: goto tr215;
		case 125: goto tr143;
	}
	goto st107;
tr238:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st121;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
#line 3571 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr243;
		case 34: goto st108;
		case 37: goto tr244;
		case 62: goto tr246;
		case 123: goto tr215;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr243;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st121;
		} else if ( (*p) >= 65 )
			goto st121;
	} else
		goto st121;
	goto st107;
tr234:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st122;
tr214:
#line 35 "shortcodes.rl"
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
tr246:
#line 47 "shortcodes.rl"
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
#line 3632 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st108;
		case 123: goto tr215;
		case 125: goto st123;
	}
	goto st107;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
	switch( (*p) ) {
		case 34: goto st108;
		case 123: goto tr215;
		case 125: goto tr248;
	}
	goto st107;
tr248:
#line 71 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st146;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
#line 3664 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st108;
		case 123: goto tr215;
	}
	goto st107;
tr240:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st124;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
#line 3680 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr243;
		case 34: goto st108;
		case 37: goto tr244;
		case 61: goto tr249;
		case 62: goto tr246;
		case 123: goto tr215;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr243;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st124;
		} else if ( (*p) >= 65 )
			goto st124;
	} else
		goto st121;
	goto st107;
tr249:
#line 29 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st125;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
#line 3712 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr236;
		case 123: goto tr215;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr238;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr238;
	} else
		goto tr238;
	goto st107;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	switch( (*p) ) {
		case 32: goto st126;
		case 34: goto st108;
		case 123: goto tr215;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st126;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr251;
	} else
		goto tr251;
	goto st107;
tr251:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st127;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
#line 3754 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr252;
		case 34: goto st108;
		case 37: goto tr234;
		case 62: goto tr232;
		case 123: goto tr215;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr252;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st127;
		} else if ( (*p) >= 65 )
			goto st127;
	} else
		goto st127;
	goto st107;
tr252:
#line 17 "shortcodes.rl"
	{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
	goto st128;
tr258:
#line 35 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st128;
tr259:
#line 47 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st128;
st128:
	if ( ++p == pe )
		goto _test_eof128;
case 128:
#line 3815 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st128;
		case 34: goto tr255;
		case 37: goto st122;
		case 62: goto st119;
		case 123: goto tr215;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st128;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr257;
		} else if ( (*p) >= 65 )
			goto tr257;
	} else
		goto tr256;
	goto st107;
tr255:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st129;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
#line 3845 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr258;
		case 34: goto st108;
		case 37: goto tr214;
		case 62: goto tr213;
		case 123: goto tr215;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr258;
	goto st107;
tr256:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st130;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
#line 3866 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr259;
		case 34: goto st108;
		case 37: goto tr246;
		case 62: goto tr244;
		case 123: goto tr215;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr259;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st130;
		} else if ( (*p) >= 65 )
			goto st130;
	} else
		goto st130;
	goto st107;
tr257:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st131;
st131:
	if ( ++p == pe )
		goto _test_eof131;
case 131:
#line 3896 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr259;
		case 34: goto st108;
		case 37: goto tr246;
		case 61: goto tr261;
		case 62: goto tr244;
		case 123: goto tr215;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr259;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st131;
		} else if ( (*p) >= 65 )
			goto st131;
	} else
		goto st130;
	goto st107;
tr261:
#line 29 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st132;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
#line 3928 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr255;
		case 123: goto tr215;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr256;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr256;
	} else
		goto tr256;
	goto st107;
tr208:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st133;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
#line 3952 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr263;
		case 34: goto st7;
		case 37: goto tr200;
		case 62: goto tr198;
		case 123: goto tr18;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr263;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st133;
		} else if ( (*p) >= 65 )
			goto st133;
	} else
		goto st133;
	goto st6;
tr209:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st134;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
#line 3982 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr263;
		case 34: goto st7;
		case 37: goto tr200;
		case 61: goto tr265;
		case 62: goto tr198;
		case 123: goto tr18;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr263;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st134;
		} else if ( (*p) >= 65 )
			goto st134;
	} else
		goto st133;
	goto st6;
tr265:
#line 29 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st135;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
#line 4014 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr207;
		case 123: goto tr18;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr208;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr208;
	} else
		goto tr208;
	goto st6;
tr13:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st136;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
#line 4038 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr267;
		case 37: goto tr224;
		case 62: goto tr222;
		case 123: goto tr1;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr267;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st136;
		} else if ( (*p) >= 65 )
			goto st136;
	} else
		goto st136;
	goto st0;
tr15:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st137;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
#line 4067 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr267;
		case 37: goto tr224;
		case 61: goto tr269;
		case 62: goto tr222;
		case 123: goto tr1;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr267;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st137;
		} else if ( (*p) >= 65 )
			goto st137;
	} else
		goto st136;
	goto st0;
tr269:
#line 29 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st138;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
#line 4098 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr11;
		case 123: goto tr1;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr13;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr13;
	} else
		goto tr13;
	goto st0;
st139:
	if ( ++p == pe )
		goto _test_eof139;
case 139:
	switch( (*p) ) {
		case 32: goto st139;
		case 123: goto tr1;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st139;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr271;
	} else
		goto tr271;
	goto st0;
tr271:
#line 7 "shortcodes.rl"
	{
    mark = p;
  }
	goto st140;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
#line 4139 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr272;
		case 37: goto tr9;
		case 62: goto tr7;
		case 123: goto tr1;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr272;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st140;
		} else if ( (*p) >= 65 )
			goto st140;
	} else
		goto st140;
	goto st0;
	}
	_test_eof141: cs = 141; goto _test_eof; 
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
	_test_eof142: cs = 142; goto _test_eof; 
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
	_test_eof143: cs = 143; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
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
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof60: cs = 60; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof62: cs = 62; goto _test_eof; 
	_test_eof144: cs = 144; goto _test_eof; 
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
	_test_eof92: cs = 92; goto _test_eof; 
	_test_eof93: cs = 93; goto _test_eof; 
	_test_eof94: cs = 94; goto _test_eof; 
	_test_eof95: cs = 95; goto _test_eof; 
	_test_eof96: cs = 96; goto _test_eof; 
	_test_eof97: cs = 97; goto _test_eof; 
	_test_eof98: cs = 98; goto _test_eof; 
	_test_eof99: cs = 99; goto _test_eof; 
	_test_eof145: cs = 145; goto _test_eof; 
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
	_test_eof119: cs = 119; goto _test_eof; 
	_test_eof120: cs = 120; goto _test_eof; 
	_test_eof121: cs = 121; goto _test_eof; 
	_test_eof122: cs = 122; goto _test_eof; 
	_test_eof123: cs = 123; goto _test_eof; 
	_test_eof146: cs = 146; goto _test_eof; 
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

	_test_eof: {}
	}

#line 148 "shortcodes.rl"

  result.sccount = c_sc;
  return result;
}
