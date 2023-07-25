
#line 1 "shortcodes.rl"
#include <string.h>
#include <stdio.h>
#include "shortcodes.h"


#line 133 "shortcodes.rl"



sc_result parse(char *input, unsigned int len) {

  
#line 16 "shortcodes.c"
static const int shortcode_start = 171;
static const int shortcode_first_final = 171;
static const int shortcode_error = -1;

static const int shortcode_en_main = 171;


#line 139 "shortcodes.rl"
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

#line 157 "shortcodes.rl"
  
#line 50 "shortcodes.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr224:
#line 66 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 74 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st171;
tr278:
#line 62 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 74 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st171;
st171:
	if ( ++p == pe )
		goto _test_eof171;
case 171:
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
#line 84 "shortcodes.rl"
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
#line 84 "shortcodes.rl"
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
		case 60: goto st169;
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
#line 18 "shortcodes.rl"
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
#line 36 "shortcodes.rl"
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
tr344:
#line 48 "shortcodes.rl"
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
#line 215 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st5;
		case 34: goto tr11;
		case 37: goto st8;
		case 62: goto st106;
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
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
#line 245 "shortcodes.c"
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
#line 18 "shortcodes.rl"
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
#line 36 "shortcodes.rl"
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
tr345:
#line 48 "shortcodes.rl"
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
#line 305 "shortcodes.c"
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
#line 62 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 87 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st172;
tr40:
#line 62 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 97 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
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
	goto st172;
tr42:
#line 66 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 97 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
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
	goto st172;
tr61:
#line 66 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 74 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st172;
tr129:
#line 62 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 74 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st172;
tr135:
#line 66 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 87 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st172;
st172:
	if ( ++p == pe )
		goto _test_eof172;
case 172:
#line 448 "shortcodes.c"
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
#line 84 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 94 "shortcodes.rl"
	{sc_mark = p;}
	goto st11;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
#line 471 "shortcodes.c"
	if ( (*p) == 123 )
		goto tr26;
	goto st10;
tr26:
#line 84 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 94 "shortcodes.rl"
	{sc_mark = p;}
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
#line 487 "shortcodes.c"
	switch( (*p) ) {
		case 37: goto st13;
		case 60: goto st104;
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
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
#line 534 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr32;
		case 37: goto tr33;
		case 62: goto tr35;
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
#line 18 "shortcodes.rl"
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
#line 570 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st16;
		case 37: goto st17;
		case 62: goto st19;
		case 123: goto tr25;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st16;
	goto st10;
tr33:
#line 18 "shortcodes.rl"
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
#line 597 "shortcodes.c"
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
		case 125: goto tr40;
	}
	goto st10;
tr35:
#line 18 "shortcodes.rl"
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
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 629 "shortcodes.c"
	switch( (*p) ) {
		case 123: goto tr25;
		case 125: goto st20;
	}
	goto st10;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	switch( (*p) ) {
		case 123: goto tr25;
		case 125: goto tr42;
	}
	goto st10;
tr30:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 654 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr43;
		case 37: goto tr44;
		case 62: goto tr46;
		case 123: goto tr25;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr43;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st21;
		} else if ( (*p) >= 65 )
			goto st21;
	} else
		goto st21;
	goto st10;
tr43:
#line 18 "shortcodes.rl"
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
	goto st22;
tr56:
#line 36 "shortcodes.rl"
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
tr212:
#line 48 "shortcodes.rl"
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
#line 714 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st22;
		case 34: goto tr48;
		case 37: goto st25;
		case 62: goto st27;
		case 123: goto tr25;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st22;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr52;
		} else if ( (*p) >= 65 )
			goto tr52;
	} else
		goto tr50;
	goto st10;
tr48:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
#line 744 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr55;
	}
	goto st23;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
	switch( (*p) ) {
		case 32: goto tr56;
		case 37: goto tr57;
		case 62: goto tr58;
		case 123: goto tr25;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr56;
	goto st10;
tr44:
#line 18 "shortcodes.rl"
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
tr57:
#line 36 "shortcodes.rl"
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
tr213:
#line 48 "shortcodes.rl"
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
#line 804 "shortcodes.c"
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
		case 125: goto tr23;
	}
	goto st10;
tr46:
#line 18 "shortcodes.rl"
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
	goto st27;
tr58:
#line 36 "shortcodes.rl"
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
tr215:
#line 48 "shortcodes.rl"
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
#line 860 "shortcodes.c"
	switch( (*p) ) {
		case 123: goto tr25;
		case 125: goto st28;
	}
	goto st10;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
	switch( (*p) ) {
		case 123: goto tr25;
		case 125: goto tr61;
	}
	goto st10;
tr55:
#line 84 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 94 "shortcodes.rl"
	{sc_mark = p;}
	goto st29;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
#line 887 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr62;
	}
	goto st23;
tr62:
#line 84 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 94 "shortcodes.rl"
	{sc_mark = p;}
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 905 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st24;
		case 37: goto st31;
		case 60: goto st49;
		case 123: goto tr62;
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
		case 123: goto tr55;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st31;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr66;
	} else
		goto tr66;
	goto st23;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr55;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr67;
	} else if ( (*p) >= 65 )
		goto tr67;
	goto st23;
tr67:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
#line 956 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr68;
		case 34: goto st24;
		case 37: goto tr69;
		case 62: goto tr71;
		case 123: goto tr55;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr68;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st33;
		} else if ( (*p) >= 65 )
			goto st33;
	} else
		goto st33;
	goto st23;
tr68:
#line 18 "shortcodes.rl"
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
	goto st34;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
#line 993 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st34;
		case 34: goto st24;
		case 37: goto st35;
		case 62: goto st37;
		case 123: goto tr55;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st34;
	goto st23;
tr69:
#line 18 "shortcodes.rl"
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
	goto st35;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
#line 1021 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr55;
		case 125: goto st36;
	}
	goto st23;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr55;
		case 125: goto tr76;
	}
	goto st23;
tr93:
#line 62 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 87 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st173;
tr76:
#line 62 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 97 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
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
	goto st173;
tr78:
#line 66 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 97 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
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
	goto st173;
tr95:
#line 66 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 74 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st173;
tr169:
#line 62 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 74 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st173;
tr171:
#line 66 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 87 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st173;
st173:
	if ( ++p == pe )
		goto _test_eof173;
case 173:
#line 1166 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr55;
	}
	goto st23;
tr71:
#line 18 "shortcodes.rl"
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
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
#line 1189 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr55;
		case 125: goto st38;
	}
	goto st23;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr55;
		case 125: goto tr78;
	}
	goto st23;
tr66:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
#line 1216 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr79;
		case 34: goto st24;
		case 37: goto tr80;
		case 62: goto tr82;
		case 123: goto tr55;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr79;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st39;
		} else if ( (*p) >= 65 )
			goto st39;
	} else
		goto st39;
	goto st23;
tr79:
#line 18 "shortcodes.rl"
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
tr89:
#line 36 "shortcodes.rl"
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
tr96:
#line 48 "shortcodes.rl"
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
#line 1277 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st40;
		case 34: goto tr84;
		case 37: goto st42;
		case 62: goto st44;
		case 123: goto tr55;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st40;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr88;
		} else if ( (*p) >= 65 )
			goto tr88;
	} else
		goto tr86;
	goto st23;
tr84:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
#line 1307 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr89;
		case 34: goto st24;
		case 37: goto tr90;
		case 62: goto tr91;
		case 123: goto tr55;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr89;
	goto st23;
tr80:
#line 18 "shortcodes.rl"
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
	goto st42;
tr90:
#line 36 "shortcodes.rl"
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
tr97:
#line 48 "shortcodes.rl"
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
#line 1359 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr55;
		case 125: goto st43;
	}
	goto st23;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr55;
		case 125: goto tr93;
	}
	goto st23;
tr82:
#line 18 "shortcodes.rl"
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
	goto st44;
tr91:
#line 36 "shortcodes.rl"
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
tr99:
#line 48 "shortcodes.rl"
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
#line 1417 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr55;
		case 125: goto st45;
	}
	goto st23;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr55;
		case 125: goto tr95;
	}
	goto st23;
tr86:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st46;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
#line 1444 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr96;
		case 34: goto st24;
		case 37: goto tr97;
		case 62: goto tr99;
		case 123: goto tr55;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr96;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st46;
		} else if ( (*p) >= 65 )
			goto st46;
	} else
		goto st46;
	goto st23;
tr88:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
#line 1474 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr96;
		case 34: goto st24;
		case 37: goto tr97;
		case 61: goto tr100;
		case 62: goto tr99;
		case 123: goto tr55;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr96;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st47;
		} else if ( (*p) >= 65 )
			goto st47;
	} else
		goto st46;
	goto st23;
tr100:
#line 30 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
#line 1506 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr84;
		case 123: goto tr55;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr86;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr86;
	} else
		goto tr86;
	goto st23;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
	switch( (*p) ) {
		case 32: goto st49;
		case 34: goto st24;
		case 47: goto st32;
		case 123: goto tr55;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st49;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr102;
	} else
		goto tr102;
	goto st23;
tr102:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st50;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
#line 1549 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr103;
		case 34: goto st24;
		case 37: goto tr104;
		case 62: goto tr106;
		case 123: goto tr55;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr103;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st50;
		} else if ( (*p) >= 65 )
			goto st50;
	} else
		goto st50;
	goto st23;
tr103:
#line 18 "shortcodes.rl"
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
tr165:
#line 36 "shortcodes.rl"
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
tr206:
#line 48 "shortcodes.rl"
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
#line 1610 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st51;
		case 34: goto tr108;
		case 37: goto st76;
		case 62: goto st78;
		case 123: goto tr55;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st51;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr112;
		} else if ( (*p) >= 65 )
			goto tr112;
	} else
		goto tr110;
	goto st23;
tr108:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
#line 1640 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr114;
		case 34: goto st54;
		case 37: goto tr116;
		case 62: goto tr117;
		case 123: goto tr118;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr114;
	goto st53;
tr123:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st53;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
#line 1661 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st54;
		case 123: goto tr118;
	}
	goto st53;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
	switch( (*p) ) {
		case 32: goto tr119;
		case 37: goto tr120;
		case 62: goto tr121;
		case 123: goto tr25;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr119;
	goto st10;
tr219:
#line 18 "shortcodes.rl"
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
	goto st55;
tr119:
#line 36 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st55;
tr130:
#line 48 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
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
#line 1721 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st55;
		case 34: goto tr123;
		case 37: goto st56;
		case 62: goto st59;
		case 123: goto tr25;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st55;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr127;
		} else if ( (*p) >= 65 )
			goto tr127;
	} else
		goto tr125;
	goto st10;
tr220:
#line 18 "shortcodes.rl"
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
	goto st56;
tr120:
#line 36 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st56;
tr131:
#line 48 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st56;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
#line 1782 "shortcodes.c"
	switch( (*p) ) {
		case 123: goto tr25;
		case 125: goto st57;
	}
	goto st10;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
	switch( (*p) ) {
		case 123: goto tr25;
		case 125: goto tr129;
	}
	goto st10;
tr125:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st58;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
#line 1807 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr130;
		case 37: goto tr131;
		case 62: goto tr133;
		case 123: goto tr25;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr130;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st58;
		} else if ( (*p) >= 65 )
			goto st58;
	} else
		goto st58;
	goto st10;
tr222:
#line 18 "shortcodes.rl"
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
	goto st59;
tr121:
#line 36 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st59;
tr133:
#line 48 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st59;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
#line 1867 "shortcodes.c"
	switch( (*p) ) {
		case 123: goto tr25;
		case 125: goto st60;
	}
	goto st10;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
	switch( (*p) ) {
		case 123: goto tr25;
		case 125: goto tr135;
	}
	goto st10;
tr127:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st61;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
#line 1892 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr130;
		case 37: goto tr131;
		case 61: goto tr136;
		case 62: goto tr133;
		case 123: goto tr25;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr130;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st61;
		} else if ( (*p) >= 65 )
			goto st61;
	} else
		goto st58;
	goto st10;
tr136:
#line 30 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st62;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
#line 1923 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr123;
		case 123: goto tr25;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr125;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr125;
	} else
		goto tr125;
	goto st10;
tr118:
#line 84 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 94 "shortcodes.rl"
	{sc_mark = p;}
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
#line 1949 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st54;
		case 123: goto tr138;
	}
	goto st53;
tr138:
#line 84 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
#line 94 "shortcodes.rl"
	{sc_mark = p;}
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
#line 1967 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st54;
		case 37: goto st65;
		case 60: goto st87;
		case 123: goto tr138;
	}
	goto st53;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
	switch( (*p) ) {
		case 32: goto st65;
		case 34: goto st54;
		case 47: goto st66;
		case 123: goto tr118;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st65;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr142;
	} else
		goto tr142;
	goto st53;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
	switch( (*p) ) {
		case 34: goto st54;
		case 123: goto tr118;
	}
	if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr143;
	} else if ( (*p) >= 65 )
		goto tr143;
	goto st53;
tr143:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
#line 2018 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr144;
		case 34: goto st54;
		case 37: goto tr145;
		case 62: goto tr147;
		case 123: goto tr118;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr144;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st67;
		} else if ( (*p) >= 65 )
			goto st67;
	} else
		goto st67;
	goto st53;
tr144:
#line 18 "shortcodes.rl"
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
	goto st68;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
#line 2055 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st68;
		case 34: goto st54;
		case 37: goto st69;
		case 62: goto st71;
		case 123: goto tr118;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto st68;
	goto st53;
tr145:
#line 18 "shortcodes.rl"
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
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
#line 2083 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st54;
		case 123: goto tr118;
		case 125: goto st70;
	}
	goto st53;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
	switch( (*p) ) {
		case 34: goto st54;
		case 123: goto tr118;
		case 125: goto tr152;
	}
	goto st53;
tr173:
#line 62 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 87 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st174;
tr152:
#line 62 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 97 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
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
	goto st174;
tr154:
#line 66 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 97 "shortcodes.rl"
	{
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    for (int i=c_sc-1; i>=0; i--) {
      if (sc_list[i].name.len == sc_list[c_sc].name.len &&
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc-1].name.len) ==0) {
        // This is the one!
        // So, it's a matching shortcode
        sc_list[i].matching = 1;
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
	goto st174;
tr179:
#line 66 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 74 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st174;
tr197:
#line 62 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 74 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st174;
tr199:
#line 66 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 87 "shortcodes.rl"
	{
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    }
	goto st174;
st174:
	if ( ++p == pe )
		goto _test_eof174;
case 174:
#line 2228 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st54;
		case 123: goto tr118;
	}
	goto st53;
tr147:
#line 18 "shortcodes.rl"
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
	goto st71;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
#line 2251 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st54;
		case 123: goto tr118;
		case 125: goto st72;
	}
	goto st53;
st72:
	if ( ++p == pe )
		goto _test_eof72;
case 72:
	switch( (*p) ) {
		case 34: goto st54;
		case 123: goto tr118;
		case 125: goto tr154;
	}
	goto st53;
tr142:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st73;
st73:
	if ( ++p == pe )
		goto _test_eof73;
case 73:
#line 2278 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr155;
		case 34: goto st54;
		case 37: goto tr156;
		case 62: goto tr158;
		case 123: goto tr118;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr155;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st73;
		} else if ( (*p) >= 65 )
			goto st73;
	} else
		goto st73;
	goto st53;
tr155:
#line 18 "shortcodes.rl"
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
	goto st74;
tr114:
#line 36 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st74;
tr174:
#line 48 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st74;
st74:
	if ( ++p == pe )
		goto _test_eof74;
case 74:
#line 2339 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st74;
		case 34: goto tr160;
		case 37: goto st80;
		case 62: goto st83;
		case 123: goto tr118;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st74;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr164;
		} else if ( (*p) >= 65 )
			goto tr164;
	} else
		goto tr162;
	goto st53;
tr160:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st75;
st75:
	if ( ++p == pe )
		goto _test_eof75;
case 75:
#line 2369 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr165;
		case 34: goto st24;
		case 37: goto tr166;
		case 62: goto tr167;
		case 123: goto tr55;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr165;
	goto st23;
tr104:
#line 18 "shortcodes.rl"
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
	goto st76;
tr166:
#line 36 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st76;
tr207:
#line 48 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st76;
st76:
	if ( ++p == pe )
		goto _test_eof76;
case 76:
#line 2421 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr55;
		case 125: goto st77;
	}
	goto st23;
st77:
	if ( ++p == pe )
		goto _test_eof77;
case 77:
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr55;
		case 125: goto tr169;
	}
	goto st23;
tr106:
#line 18 "shortcodes.rl"
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
	goto st78;
tr167:
#line 36 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st78;
tr209:
#line 48 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st78;
st78:
	if ( ++p == pe )
		goto _test_eof78;
case 78:
#line 2479 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr55;
		case 125: goto st79;
	}
	goto st23;
st79:
	if ( ++p == pe )
		goto _test_eof79;
case 79:
	switch( (*p) ) {
		case 34: goto st24;
		case 123: goto tr55;
		case 125: goto tr171;
	}
	goto st23;
tr156:
#line 18 "shortcodes.rl"
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
	goto st80;
tr116:
#line 36 "shortcodes.rl"
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
tr175:
#line 48 "shortcodes.rl"
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
#line 2537 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st54;
		case 123: goto tr118;
		case 125: goto st81;
	}
	goto st53;
st81:
	if ( ++p == pe )
		goto _test_eof81;
case 81:
	switch( (*p) ) {
		case 34: goto st54;
		case 123: goto tr118;
		case 125: goto tr173;
	}
	goto st53;
tr162:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st82;
st82:
	if ( ++p == pe )
		goto _test_eof82;
case 82:
#line 2564 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr174;
		case 34: goto st54;
		case 37: goto tr175;
		case 62: goto tr177;
		case 123: goto tr118;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr174;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st82;
		} else if ( (*p) >= 65 )
			goto st82;
	} else
		goto st82;
	goto st53;
tr158:
#line 18 "shortcodes.rl"
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
	goto st83;
tr117:
#line 36 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st83;
tr177:
#line 48 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st83;
st83:
	if ( ++p == pe )
		goto _test_eof83;
case 83:
#line 2625 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st54;
		case 123: goto tr118;
		case 125: goto st84;
	}
	goto st53;
st84:
	if ( ++p == pe )
		goto _test_eof84;
case 84:
	switch( (*p) ) {
		case 34: goto st54;
		case 123: goto tr118;
		case 125: goto tr179;
	}
	goto st53;
tr164:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st85;
st85:
	if ( ++p == pe )
		goto _test_eof85;
case 85:
#line 2652 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr174;
		case 34: goto st54;
		case 37: goto tr175;
		case 61: goto tr180;
		case 62: goto tr177;
		case 123: goto tr118;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr174;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st85;
		} else if ( (*p) >= 65 )
			goto st85;
	} else
		goto st82;
	goto st53;
tr180:
#line 30 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st86;
st86:
	if ( ++p == pe )
		goto _test_eof86;
case 86:
#line 2684 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr160;
		case 123: goto tr118;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr162;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr162;
	} else
		goto tr162;
	goto st53;
st87:
	if ( ++p == pe )
		goto _test_eof87;
case 87:
	switch( (*p) ) {
		case 32: goto st87;
		case 34: goto st54;
		case 47: goto st66;
		case 123: goto tr118;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st87;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr182;
	} else
		goto tr182;
	goto st53;
tr182:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st88;
st88:
	if ( ++p == pe )
		goto _test_eof88;
case 88:
#line 2727 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr183;
		case 34: goto st54;
		case 37: goto tr184;
		case 62: goto tr186;
		case 123: goto tr118;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr183;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st88;
		} else if ( (*p) >= 65 )
			goto st88;
	} else
		goto st88;
	goto st53;
tr183:
#line 18 "shortcodes.rl"
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
	goto st89;
tr193:
#line 36 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st89;
tr200:
#line 48 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
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
#line 2788 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st89;
		case 34: goto tr188;
		case 37: goto st91;
		case 62: goto st93;
		case 123: goto tr118;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st89;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr192;
		} else if ( (*p) >= 65 )
			goto tr192;
	} else
		goto tr190;
	goto st53;
tr188:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st90;
st90:
	if ( ++p == pe )
		goto _test_eof90;
case 90:
#line 2818 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr193;
		case 34: goto st54;
		case 37: goto tr194;
		case 62: goto tr195;
		case 123: goto tr118;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr193;
	goto st53;
tr184:
#line 18 "shortcodes.rl"
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
	goto st91;
tr194:
#line 36 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st91;
tr201:
#line 48 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st91;
st91:
	if ( ++p == pe )
		goto _test_eof91;
case 91:
#line 2870 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st54;
		case 123: goto tr118;
		case 125: goto st92;
	}
	goto st53;
st92:
	if ( ++p == pe )
		goto _test_eof92;
case 92:
	switch( (*p) ) {
		case 34: goto st54;
		case 123: goto tr118;
		case 125: goto tr197;
	}
	goto st53;
tr186:
#line 18 "shortcodes.rl"
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
	goto st93;
tr195:
#line 36 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st93;
tr203:
#line 48 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st93;
st93:
	if ( ++p == pe )
		goto _test_eof93;
case 93:
#line 2928 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st54;
		case 123: goto tr118;
		case 125: goto st94;
	}
	goto st53;
st94:
	if ( ++p == pe )
		goto _test_eof94;
case 94:
	switch( (*p) ) {
		case 34: goto st54;
		case 123: goto tr118;
		case 125: goto tr199;
	}
	goto st53;
tr190:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st95;
st95:
	if ( ++p == pe )
		goto _test_eof95;
case 95:
#line 2955 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr200;
		case 34: goto st54;
		case 37: goto tr201;
		case 62: goto tr203;
		case 123: goto tr118;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr200;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st95;
		} else if ( (*p) >= 65 )
			goto st95;
	} else
		goto st95;
	goto st53;
tr192:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st96;
st96:
	if ( ++p == pe )
		goto _test_eof96;
case 96:
#line 2985 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr200;
		case 34: goto st54;
		case 37: goto tr201;
		case 61: goto tr204;
		case 62: goto tr203;
		case 123: goto tr118;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr200;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st96;
		} else if ( (*p) >= 65 )
			goto st96;
	} else
		goto st95;
	goto st53;
tr204:
#line 30 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st97;
st97:
	if ( ++p == pe )
		goto _test_eof97;
case 97:
#line 3017 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr188;
		case 123: goto tr118;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr190;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr190;
	} else
		goto tr190;
	goto st53;
tr110:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st98;
st98:
	if ( ++p == pe )
		goto _test_eof98;
case 98:
#line 3041 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr206;
		case 34: goto st24;
		case 37: goto tr207;
		case 62: goto tr209;
		case 123: goto tr55;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr206;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st98;
		} else if ( (*p) >= 65 )
			goto st98;
	} else
		goto st98;
	goto st23;
tr112:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st99;
st99:
	if ( ++p == pe )
		goto _test_eof99;
case 99:
#line 3071 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr206;
		case 34: goto st24;
		case 37: goto tr207;
		case 61: goto tr210;
		case 62: goto tr209;
		case 123: goto tr55;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr206;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st99;
		} else if ( (*p) >= 65 )
			goto st99;
	} else
		goto st98;
	goto st23;
tr210:
#line 30 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st100;
st100:
	if ( ++p == pe )
		goto _test_eof100;
case 100:
#line 3103 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr108;
		case 123: goto tr55;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr110;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr110;
	} else
		goto tr110;
	goto st23;
tr50:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st101;
st101:
	if ( ++p == pe )
		goto _test_eof101;
case 101:
#line 3127 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr212;
		case 37: goto tr213;
		case 62: goto tr215;
		case 123: goto tr25;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr212;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st101;
		} else if ( (*p) >= 65 )
			goto st101;
	} else
		goto st101;
	goto st10;
tr52:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st102;
st102:
	if ( ++p == pe )
		goto _test_eof102;
case 102:
#line 3156 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr212;
		case 37: goto tr213;
		case 61: goto tr216;
		case 62: goto tr215;
		case 123: goto tr25;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr212;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st102;
		} else if ( (*p) >= 65 )
			goto st102;
	} else
		goto st101;
	goto st10;
tr216:
#line 30 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st103;
st103:
	if ( ++p == pe )
		goto _test_eof103;
case 103:
#line 3187 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr48;
		case 123: goto tr25;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr50;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr50;
	} else
		goto tr50;
	goto st10;
st104:
	if ( ++p == pe )
		goto _test_eof104;
case 104:
	switch( (*p) ) {
		case 32: goto st104;
		case 47: goto st14;
		case 123: goto tr25;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st104;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr218;
	} else
		goto tr218;
	goto st10;
tr218:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st105;
st105:
	if ( ++p == pe )
		goto _test_eof105;
case 105:
#line 3229 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr219;
		case 37: goto tr220;
		case 62: goto tr222;
		case 123: goto tr25;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr219;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st105;
		} else if ( (*p) >= 65 )
			goto st105;
	} else
		goto st105;
	goto st10;
tr9:
#line 18 "shortcodes.rl"
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
	goto st106;
tr21:
#line 36 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st106;
tr347:
#line 48 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st106;
st106:
	if ( ++p == pe )
		goto _test_eof106;
case 106:
#line 3289 "shortcodes.c"
	switch( (*p) ) {
		case 123: goto tr1;
		case 125: goto st107;
	}
	goto st0;
st107:
	if ( ++p == pe )
		goto _test_eof107;
case 107:
	switch( (*p) ) {
		case 123: goto tr1;
		case 125: goto tr224;
	}
	goto st0;
tr18:
#line 84 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st108;
st108:
	if ( ++p == pe )
		goto _test_eof108;
case 108:
#line 3314 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr225;
	}
	goto st6;
tr225:
#line 84 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st109;
st109:
	if ( ++p == pe )
		goto _test_eof109;
case 109:
#line 3330 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 37: goto st110;
		case 60: goto st121;
		case 123: goto tr225;
	}
	goto st6;
st110:
	if ( ++p == pe )
		goto _test_eof110;
case 110:
	switch( (*p) ) {
		case 32: goto st110;
		case 34: goto st7;
		case 123: goto tr18;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st110;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr228;
	} else
		goto tr228;
	goto st6;
tr228:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st111;
st111:
	if ( ++p == pe )
		goto _test_eof111;
case 111:
#line 3366 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr229;
		case 34: goto st7;
		case 37: goto tr230;
		case 62: goto tr232;
		case 123: goto tr18;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr229;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st111;
		} else if ( (*p) >= 65 )
			goto st111;
	} else
		goto st111;
	goto st6;
tr229:
#line 18 "shortcodes.rl"
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
	goto st112;
tr239:
#line 36 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st112;
tr245:
#line 48 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st112;
st112:
	if ( ++p == pe )
		goto _test_eof112;
case 112:
#line 3427 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st112;
		case 34: goto tr234;
		case 37: goto st114;
		case 62: goto st116;
		case 123: goto tr18;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st112;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr238;
		} else if ( (*p) >= 65 )
			goto tr238;
	} else
		goto tr236;
	goto st6;
tr234:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st113;
st113:
	if ( ++p == pe )
		goto _test_eof113;
case 113:
#line 3457 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr239;
		case 34: goto st7;
		case 37: goto tr240;
		case 62: goto tr241;
		case 123: goto tr18;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr239;
	goto st6;
tr230:
#line 18 "shortcodes.rl"
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
	goto st114;
tr240:
#line 36 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st114;
tr246:
#line 48 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st114;
st114:
	if ( ++p == pe )
		goto _test_eof114;
case 114:
#line 3509 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr18;
		case 125: goto st115;
	}
	goto st6;
st115:
	if ( ++p == pe )
		goto _test_eof115;
case 115:
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr18;
		case 125: goto tr93;
	}
	goto st6;
tr232:
#line 18 "shortcodes.rl"
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
	goto st116;
tr241:
#line 36 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st116;
tr248:
#line 48 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
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
#line 3567 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr18;
		case 125: goto st117;
	}
	goto st6;
st117:
	if ( ++p == pe )
		goto _test_eof117;
case 117:
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr18;
		case 125: goto tr244;
	}
	goto st6;
tr244:
#line 66 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 74 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st175;
tr304:
#line 62 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 74 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st175;
st175:
	if ( ++p == pe )
		goto _test_eof175;
case 175:
#line 3614 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr18;
	}
	goto st6;
tr236:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st118;
st118:
	if ( ++p == pe )
		goto _test_eof118;
case 118:
#line 3630 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr245;
		case 34: goto st7;
		case 37: goto tr246;
		case 62: goto tr248;
		case 123: goto tr18;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr245;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st118;
		} else if ( (*p) >= 65 )
			goto st118;
	} else
		goto st118;
	goto st6;
tr238:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st119;
st119:
	if ( ++p == pe )
		goto _test_eof119;
case 119:
#line 3660 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr245;
		case 34: goto st7;
		case 37: goto tr246;
		case 61: goto tr249;
		case 62: goto tr248;
		case 123: goto tr18;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr245;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st119;
		} else if ( (*p) >= 65 )
			goto st119;
	} else
		goto st118;
	goto st6;
tr249:
#line 30 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st120;
st120:
	if ( ++p == pe )
		goto _test_eof120;
case 120:
#line 3692 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr234;
		case 123: goto tr18;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr236;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr236;
	} else
		goto tr236;
	goto st6;
st121:
	if ( ++p == pe )
		goto _test_eof121;
case 121:
	switch( (*p) ) {
		case 32: goto st121;
		case 34: goto st7;
		case 123: goto tr18;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st121;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr251;
	} else
		goto tr251;
	goto st6;
tr251:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st122;
st122:
	if ( ++p == pe )
		goto _test_eof122;
case 122:
#line 3734 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr252;
		case 34: goto st7;
		case 37: goto tr253;
		case 62: goto tr255;
		case 123: goto tr18;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr252;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st122;
		} else if ( (*p) >= 65 )
			goto st122;
	} else
		goto st122;
	goto st6;
tr252:
#line 18 "shortcodes.rl"
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
	goto st123;
tr300:
#line 36 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st123;
tr338:
#line 48 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st123;
st123:
	if ( ++p == pe )
		goto _test_eof123;
case 123:
#line 3795 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st123;
		case 34: goto tr257;
		case 37: goto st141;
		case 62: goto st143;
		case 123: goto tr18;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st123;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr261;
		} else if ( (*p) >= 65 )
			goto tr261;
	} else
		goto tr259;
	goto st6;
tr257:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st124;
st124:
	if ( ++p == pe )
		goto _test_eof124;
case 124:
#line 3825 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr263;
		case 34: goto st126;
		case 37: goto tr265;
		case 62: goto tr266;
		case 123: goto tr267;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr263;
	goto st125;
tr272:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st125;
st125:
	if ( ++p == pe )
		goto _test_eof125;
case 125:
#line 3846 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st126;
		case 123: goto tr267;
	}
	goto st125;
st126:
	if ( ++p == pe )
		goto _test_eof126;
case 126:
	switch( (*p) ) {
		case 32: goto tr268;
		case 37: goto tr269;
		case 62: goto tr270;
		case 123: goto tr1;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr268;
	goto st0;
tr351:
#line 18 "shortcodes.rl"
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
	goto st127;
tr268:
#line 36 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st127;
tr279:
#line 48 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st127;
st127:
	if ( ++p == pe )
		goto _test_eof127;
case 127:
#line 3906 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st127;
		case 34: goto tr272;
		case 37: goto st128;
		case 62: goto st131;
		case 123: goto tr1;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st127;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr276;
		} else if ( (*p) >= 65 )
			goto tr276;
	} else
		goto tr274;
	goto st0;
tr352:
#line 18 "shortcodes.rl"
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
tr269:
#line 36 "shortcodes.rl"
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
tr280:
#line 48 "shortcodes.rl"
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
#line 3967 "shortcodes.c"
	switch( (*p) ) {
		case 123: goto tr1;
		case 125: goto st129;
	}
	goto st0;
st129:
	if ( ++p == pe )
		goto _test_eof129;
case 129:
	switch( (*p) ) {
		case 123: goto tr1;
		case 125: goto tr278;
	}
	goto st0;
tr274:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st130;
st130:
	if ( ++p == pe )
		goto _test_eof130;
case 130:
#line 3992 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr279;
		case 37: goto tr280;
		case 62: goto tr282;
		case 123: goto tr1;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr279;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st130;
		} else if ( (*p) >= 65 )
			goto st130;
	} else
		goto st130;
	goto st0;
tr354:
#line 18 "shortcodes.rl"
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
	goto st131;
tr270:
#line 36 "shortcodes.rl"
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
tr282:
#line 48 "shortcodes.rl"
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
#line 4052 "shortcodes.c"
	switch( (*p) ) {
		case 123: goto tr1;
		case 125: goto st132;
	}
	goto st0;
st132:
	if ( ++p == pe )
		goto _test_eof132;
case 132:
	switch( (*p) ) {
		case 123: goto tr1;
		case 125: goto tr135;
	}
	goto st0;
tr276:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st133;
st133:
	if ( ++p == pe )
		goto _test_eof133;
case 133:
#line 4077 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr279;
		case 37: goto tr280;
		case 61: goto tr284;
		case 62: goto tr282;
		case 123: goto tr1;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr279;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st133;
		} else if ( (*p) >= 65 )
			goto st133;
	} else
		goto st130;
	goto st0;
tr284:
#line 30 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st134;
st134:
	if ( ++p == pe )
		goto _test_eof134;
case 134:
#line 4108 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr272;
		case 123: goto tr1;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr274;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr274;
	} else
		goto tr274;
	goto st0;
tr267:
#line 84 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st135;
st135:
	if ( ++p == pe )
		goto _test_eof135;
case 135:
#line 4132 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st126;
		case 123: goto tr286;
	}
	goto st125;
tr286:
#line 84 "shortcodes.rl"
	{
      sc_list[c_sc].whole.start = p-start-1;
    }
	goto st136;
st136:
	if ( ++p == pe )
		goto _test_eof136;
case 136:
#line 4148 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st126;
		case 37: goto st137;
		case 60: goto st152;
		case 123: goto tr286;
	}
	goto st125;
st137:
	if ( ++p == pe )
		goto _test_eof137;
case 137:
	switch( (*p) ) {
		case 32: goto st137;
		case 34: goto st126;
		case 123: goto tr267;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st137;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr289;
	} else
		goto tr289;
	goto st125;
tr289:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st138;
st138:
	if ( ++p == pe )
		goto _test_eof138;
case 138:
#line 4184 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr290;
		case 34: goto st126;
		case 37: goto tr291;
		case 62: goto tr293;
		case 123: goto tr267;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr290;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st138;
		} else if ( (*p) >= 65 )
			goto st138;
	} else
		goto st138;
	goto st125;
tr290:
#line 18 "shortcodes.rl"
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
	goto st139;
tr263:
#line 36 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st139;
tr307:
#line 48 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
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
#line 4245 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st139;
		case 34: goto tr295;
		case 37: goto st145;
		case 62: goto st148;
		case 123: goto tr267;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st139;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr299;
		} else if ( (*p) >= 65 )
			goto tr299;
	} else
		goto tr297;
	goto st125;
tr295:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st140;
st140:
	if ( ++p == pe )
		goto _test_eof140;
case 140:
#line 4275 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr300;
		case 34: goto st7;
		case 37: goto tr301;
		case 62: goto tr302;
		case 123: goto tr18;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr300;
	goto st6;
tr253:
#line 18 "shortcodes.rl"
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
	goto st141;
tr301:
#line 36 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st141;
tr339:
#line 48 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
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
#line 4327 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr18;
		case 125: goto st142;
	}
	goto st6;
st142:
	if ( ++p == pe )
		goto _test_eof142;
case 142:
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr18;
		case 125: goto tr304;
	}
	goto st6;
tr255:
#line 18 "shortcodes.rl"
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
	goto st143;
tr302:
#line 36 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st143;
tr341:
#line 48 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st143;
st143:
	if ( ++p == pe )
		goto _test_eof143;
case 143:
#line 4385 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr18;
		case 125: goto st144;
	}
	goto st6;
st144:
	if ( ++p == pe )
		goto _test_eof144;
case 144:
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr18;
		case 125: goto tr171;
	}
	goto st6;
tr291:
#line 18 "shortcodes.rl"
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
	goto st145;
tr265:
#line 36 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st145;
tr308:
#line 48 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st145;
st145:
	if ( ++p == pe )
		goto _test_eof145;
case 145:
#line 4443 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st126;
		case 123: goto tr267;
		case 125: goto st146;
	}
	goto st125;
st146:
	if ( ++p == pe )
		goto _test_eof146;
case 146:
	switch( (*p) ) {
		case 34: goto st126;
		case 123: goto tr267;
		case 125: goto tr173;
	}
	goto st125;
tr297:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st147;
st147:
	if ( ++p == pe )
		goto _test_eof147;
case 147:
#line 4470 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr307;
		case 34: goto st126;
		case 37: goto tr308;
		case 62: goto tr310;
		case 123: goto tr267;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr307;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st147;
		} else if ( (*p) >= 65 )
			goto st147;
	} else
		goto st147;
	goto st125;
tr293:
#line 18 "shortcodes.rl"
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
	goto st148;
tr266:
#line 36 "shortcodes.rl"
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
tr310:
#line 48 "shortcodes.rl"
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
#line 4531 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st126;
		case 123: goto tr267;
		case 125: goto st149;
	}
	goto st125;
st149:
	if ( ++p == pe )
		goto _test_eof149;
case 149:
	switch( (*p) ) {
		case 34: goto st126;
		case 123: goto tr267;
		case 125: goto tr312;
	}
	goto st125;
tr312:
#line 66 "shortcodes.rl"
	{sc_list[c_sc].markdown = 0;}
#line 74 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st176;
tr330:
#line 62 "shortcodes.rl"
	{sc_list[c_sc].markdown = 1;}
#line 74 "shortcodes.rl"
	{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  }
	goto st176;
st176:
	if ( ++p == pe )
		goto _test_eof176;
case 176:
#line 4578 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st126;
		case 123: goto tr267;
	}
	goto st125;
tr299:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st150;
st150:
	if ( ++p == pe )
		goto _test_eof150;
case 150:
#line 4594 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr307;
		case 34: goto st126;
		case 37: goto tr308;
		case 61: goto tr313;
		case 62: goto tr310;
		case 123: goto tr267;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr307;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st150;
		} else if ( (*p) >= 65 )
			goto st150;
	} else
		goto st147;
	goto st125;
tr313:
#line 30 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st151;
st151:
	if ( ++p == pe )
		goto _test_eof151;
case 151:
#line 4626 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr295;
		case 123: goto tr267;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr297;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr297;
	} else
		goto tr297;
	goto st125;
st152:
	if ( ++p == pe )
		goto _test_eof152;
case 152:
	switch( (*p) ) {
		case 32: goto st152;
		case 34: goto st126;
		case 123: goto tr267;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st152;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr315;
	} else
		goto tr315;
	goto st125;
tr315:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st153;
st153:
	if ( ++p == pe )
		goto _test_eof153;
case 153:
#line 4668 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr316;
		case 34: goto st126;
		case 37: goto tr317;
		case 62: goto tr319;
		case 123: goto tr267;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr316;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st153;
		} else if ( (*p) >= 65 )
			goto st153;
	} else
		goto st153;
	goto st125;
tr316:
#line 18 "shortcodes.rl"
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
	goto st154;
tr326:
#line 36 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st154;
tr332:
#line 48 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st154;
st154:
	if ( ++p == pe )
		goto _test_eof154;
case 154:
#line 4729 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st154;
		case 34: goto tr321;
		case 37: goto st156;
		case 62: goto st158;
		case 123: goto tr267;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st154;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr325;
		} else if ( (*p) >= 65 )
			goto tr325;
	} else
		goto tr323;
	goto st125;
tr321:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st155;
st155:
	if ( ++p == pe )
		goto _test_eof155;
case 155:
#line 4759 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr326;
		case 34: goto st126;
		case 37: goto tr327;
		case 62: goto tr328;
		case 123: goto tr267;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr326;
	goto st125;
tr317:
#line 18 "shortcodes.rl"
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
	goto st156;
tr327:
#line 36 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st156;
tr333:
#line 48 "shortcodes.rl"
	{
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    }
	goto st156;
st156:
	if ( ++p == pe )
		goto _test_eof156;
case 156:
#line 4811 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st126;
		case 123: goto tr267;
		case 125: goto st157;
	}
	goto st125;
st157:
	if ( ++p == pe )
		goto _test_eof157;
case 157:
	switch( (*p) ) {
		case 34: goto st126;
		case 123: goto tr267;
		case 125: goto tr330;
	}
	goto st125;
tr319:
#line 18 "shortcodes.rl"
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
	goto st158;
tr328:
#line 36 "shortcodes.rl"
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
tr335:
#line 48 "shortcodes.rl"
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
#line 4869 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st126;
		case 123: goto tr267;
		case 125: goto st159;
	}
	goto st125;
st159:
	if ( ++p == pe )
		goto _test_eof159;
case 159:
	switch( (*p) ) {
		case 34: goto st126;
		case 123: goto tr267;
		case 125: goto tr199;
	}
	goto st125;
tr323:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st160;
st160:
	if ( ++p == pe )
		goto _test_eof160;
case 160:
#line 4896 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr332;
		case 34: goto st126;
		case 37: goto tr333;
		case 62: goto tr335;
		case 123: goto tr267;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr332;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st160;
		} else if ( (*p) >= 65 )
			goto st160;
	} else
		goto st160;
	goto st125;
tr325:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st161;
st161:
	if ( ++p == pe )
		goto _test_eof161;
case 161:
#line 4926 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr332;
		case 34: goto st126;
		case 37: goto tr333;
		case 61: goto tr336;
		case 62: goto tr335;
		case 123: goto tr267;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr332;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st161;
		} else if ( (*p) >= 65 )
			goto st161;
	} else
		goto st160;
	goto st125;
tr336:
#line 30 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st162;
st162:
	if ( ++p == pe )
		goto _test_eof162;
case 162:
#line 4958 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr321;
		case 123: goto tr267;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr323;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr323;
	} else
		goto tr323;
	goto st125;
tr259:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st163;
st163:
	if ( ++p == pe )
		goto _test_eof163;
case 163:
#line 4982 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr338;
		case 34: goto st7;
		case 37: goto tr339;
		case 62: goto tr341;
		case 123: goto tr18;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr338;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st163;
		} else if ( (*p) >= 65 )
			goto st163;
	} else
		goto st163;
	goto st6;
tr261:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st164;
st164:
	if ( ++p == pe )
		goto _test_eof164;
case 164:
#line 5012 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr338;
		case 34: goto st7;
		case 37: goto tr339;
		case 61: goto tr342;
		case 62: goto tr341;
		case 123: goto tr18;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr338;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st164;
		} else if ( (*p) >= 65 )
			goto st164;
	} else
		goto st163;
	goto st6;
tr342:
#line 30 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st165;
st165:
	if ( ++p == pe )
		goto _test_eof165;
case 165:
#line 5044 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr257;
		case 123: goto tr18;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr259;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr259;
	} else
		goto tr259;
	goto st6;
tr13:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st166;
st166:
	if ( ++p == pe )
		goto _test_eof166;
case 166:
#line 5068 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr344;
		case 37: goto tr345;
		case 62: goto tr347;
		case 123: goto tr1;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr344;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st166;
		} else if ( (*p) >= 65 )
			goto st166;
	} else
		goto st166;
	goto st0;
tr15:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st167;
st167:
	if ( ++p == pe )
		goto _test_eof167;
case 167:
#line 5097 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr344;
		case 37: goto tr345;
		case 61: goto tr348;
		case 62: goto tr347;
		case 123: goto tr1;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr344;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st167;
		} else if ( (*p) >= 65 )
			goto st167;
	} else
		goto st166;
	goto st0;
tr348:
#line 30 "shortcodes.rl"
	{
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    }
	goto st168;
st168:
	if ( ++p == pe )
		goto _test_eof168;
case 168:
#line 5128 "shortcodes.c"
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
st169:
	if ( ++p == pe )
		goto _test_eof169;
case 169:
	switch( (*p) ) {
		case 32: goto st169;
		case 123: goto tr1;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st169;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr350;
	} else
		goto tr350;
	goto st0;
tr350:
#line 8 "shortcodes.rl"
	{
    mark = p;
  }
	goto st170;
st170:
	if ( ++p == pe )
		goto _test_eof170;
case 170:
#line 5169 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr351;
		case 37: goto tr352;
		case 62: goto tr354;
		case 123: goto tr1;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr351;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st170;
		} else if ( (*p) >= 65 )
			goto st170;
	} else
		goto st170;
	goto st0;
	}
	_test_eof171: cs = 171; goto _test_eof; 
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
	_test_eof172: cs = 172; goto _test_eof; 
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
	_test_eof173: cs = 173; goto _test_eof; 
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
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 
	_test_eof174: cs = 174; goto _test_eof; 
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
	_test_eof175: cs = 175; goto _test_eof; 
	_test_eof118: cs = 118; goto _test_eof; 
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
	_test_eof141: cs = 141; goto _test_eof; 
	_test_eof142: cs = 142; goto _test_eof; 
	_test_eof143: cs = 143; goto _test_eof; 
	_test_eof144: cs = 144; goto _test_eof; 
	_test_eof145: cs = 145; goto _test_eof; 
	_test_eof146: cs = 146; goto _test_eof; 
	_test_eof147: cs = 147; goto _test_eof; 
	_test_eof148: cs = 148; goto _test_eof; 
	_test_eof149: cs = 149; goto _test_eof; 
	_test_eof176: cs = 176; goto _test_eof; 
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

	_test_eof: {}
	}

#line 158 "shortcodes.rl"

  result.sccount = c_sc;
  return result;
}
