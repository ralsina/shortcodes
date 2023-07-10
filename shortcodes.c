
#line 1 "shortcodes.rl"
#include <stdio.h>
#include "bstrlib/bstrlib.h"

bstring grab_chunk(char *start, char *end) {
  blk2bstr(start, end-start);
}


#line 63 "shortcodes.rl"


bstring parse(char *input) {
    
#line 17 "shortcodes.c"
static const int shortcode_start = 24;
static const int shortcode_first_final = 24;
static const int shortcode_error = -1;

static const int shortcode_en_main = 24;


#line 67 "shortcodes.rl"
    char *eof, *ts, *te = 0;
    int cs, act = 0;

    char *p = input;
    char *pe = p + strlen(input);

    char *mark = 0;
    bstring output = bfromcstr("");
    
#line 35 "shortcodes.c"
	{
	cs = shortcode_start;
	}

#line 76 "shortcodes.rl"
    
#line 42 "shortcodes.c"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
case 24:
	if ( (*p) == 123 )
		goto tr1;
	goto st0;
tr45:
#line 58 "shortcodes.rl"
	{bcatcstr(output, "\n");}
	goto st0;
st0:
	if ( ++p == pe )
		goto _test_eof0;
case 0:
#line 60 "shortcodes.c"
	if ( (*p) == 123 )
		goto tr1;
	goto st0;
tr1:
#line 57 "shortcodes.rl"
	{bcatcstr(output, "---\n");}
	goto st1;
tr46:
#line 57 "shortcodes.rl"
	{bcatcstr(output, "---\n");}
#line 58 "shortcodes.rl"
	{bcatcstr(output, "\n");}
	goto st1;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
#line 78 "shortcodes.c"
	if ( (*p) == 123 )
		goto tr2;
	goto st0;
tr2:
#line 57 "shortcodes.rl"
	{bcatcstr(output, "---\n");}
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 90 "shortcodes.c"
	switch( (*p) ) {
		case 37: goto st3;
		case 60: goto st3;
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
			goto tr4;
	} else
		goto tr4;
	goto st0;
tr4:
#line 11 "shortcodes.rl"
	{
    mark = p;
  }
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 124 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr5;
		case 37: goto tr6;
		case 62: goto tr6;
		case 123: goto tr1;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr5;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st4;
		} else if ( (*p) >= 65 )
			goto st4;
	} else
		goto st4;
	goto st0;
tr5:
#line 21 "shortcodes.rl"
	{bcatcstr(output, "N"); 
       bcatblk(output, mark, p-mark);
       bcatcstr(output, "\n");
      }
	goto st5;
tr16:
#line 33 "shortcodes.rl"
	{bcatcstr(output, "V"); 
       bcatblk(output, mark+1, p-mark-2);
       bcatcstr(output, "\n");
      }
	goto st5;
tr40:
#line 40 "shortcodes.rl"
	{bcatcstr(output, "V"); 
       bcatblk(output, mark, p-mark);
       bcatcstr(output, "\n");
      }
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
#line 168 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st5;
		case 34: goto tr9;
		case 37: goto st8;
		case 62: goto st8;
		case 123: goto tr1;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st5;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr12;
		} else if ( (*p) >= 65 )
			goto tr12;
	} else
		goto tr11;
	goto st0;
tr9:
#line 11 "shortcodes.rl"
	{
    mark = p;
  }
	goto st6;
tr47:
#line 58 "shortcodes.rl"
	{bcatcstr(output, "\n");}
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
#line 202 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr15;
	}
	goto st6;
tr48:
#line 58 "shortcodes.rl"
	{bcatcstr(output, "\n");}
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
#line 216 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr16;
		case 37: goto tr17;
		case 62: goto tr17;
		case 123: goto tr1;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr16;
	goto st0;
tr6:
#line 21 "shortcodes.rl"
	{bcatcstr(output, "N"); 
       bcatblk(output, mark, p-mark);
       bcatcstr(output, "\n");
      }
	goto st8;
tr17:
#line 33 "shortcodes.rl"
	{bcatcstr(output, "V"); 
       bcatblk(output, mark+1, p-mark-2);
       bcatcstr(output, "\n");
      }
	goto st8;
tr41:
#line 40 "shortcodes.rl"
	{bcatcstr(output, "V"); 
       bcatblk(output, mark, p-mark);
       bcatcstr(output, "\n");
      }
	goto st8;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
#line 251 "shortcodes.c"
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
		case 125: goto st25;
	}
	goto st0;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
	if ( (*p) == 123 )
		goto tr46;
	goto tr45;
tr15:
#line 57 "shortcodes.rl"
	{bcatcstr(output, "---\n");}
	goto st10;
tr49:
#line 57 "shortcodes.rl"
	{bcatcstr(output, "---\n");}
#line 58 "shortcodes.rl"
	{bcatcstr(output, "\n");}
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
#line 287 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr20;
	}
	goto st6;
tr20:
#line 57 "shortcodes.rl"
	{bcatcstr(output, "---\n");}
	goto st11;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
#line 301 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 37: goto st12;
		case 60: goto st12;
		case 123: goto tr20;
	}
	goto st6;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
	switch( (*p) ) {
		case 32: goto st12;
		case 34: goto st7;
		case 123: goto tr15;
	}
	if ( (*p) < 65 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st12;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr22;
	} else
		goto tr22;
	goto st6;
tr22:
#line 11 "shortcodes.rl"
	{
    mark = p;
  }
	goto st13;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
#line 337 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr23;
		case 34: goto st7;
		case 37: goto tr24;
		case 62: goto tr24;
		case 123: goto tr15;
	}
	if ( (*p) < 47 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr23;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st13;
		} else if ( (*p) >= 65 )
			goto st13;
	} else
		goto st13;
	goto st6;
tr23:
#line 21 "shortcodes.rl"
	{bcatcstr(output, "N"); 
       bcatblk(output, mark, p-mark);
       bcatcstr(output, "\n");
      }
	goto st14;
tr31:
#line 33 "shortcodes.rl"
	{bcatcstr(output, "V"); 
       bcatblk(output, mark+1, p-mark-2);
       bcatcstr(output, "\n");
      }
	goto st14;
tr35:
#line 40 "shortcodes.rl"
	{bcatcstr(output, "V"); 
       bcatblk(output, mark, p-mark);
       bcatcstr(output, "\n");
      }
	goto st14;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
#line 382 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto st14;
		case 34: goto tr27;
		case 37: goto st16;
		case 62: goto st16;
		case 123: goto tr15;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto st14;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto tr30;
		} else if ( (*p) >= 65 )
			goto tr30;
	} else
		goto tr29;
	goto st6;
tr27:
#line 11 "shortcodes.rl"
	{
    mark = p;
  }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
#line 412 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr31;
		case 34: goto st7;
		case 37: goto tr32;
		case 62: goto tr32;
		case 123: goto tr15;
	}
	if ( 9 <= (*p) && (*p) <= 13 )
		goto tr31;
	goto st6;
tr24:
#line 21 "shortcodes.rl"
	{bcatcstr(output, "N"); 
       bcatblk(output, mark, p-mark);
       bcatcstr(output, "\n");
      }
	goto st16;
tr32:
#line 33 "shortcodes.rl"
	{bcatcstr(output, "V"); 
       bcatblk(output, mark+1, p-mark-2);
       bcatcstr(output, "\n");
      }
	goto st16;
tr36:
#line 40 "shortcodes.rl"
	{bcatcstr(output, "V"); 
       bcatblk(output, mark, p-mark);
       bcatcstr(output, "\n");
      }
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
#line 448 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr15;
		case 125: goto st17;
	}
	goto st6;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	switch( (*p) ) {
		case 34: goto st7;
		case 123: goto tr15;
		case 125: goto st26;
	}
	goto st6;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
	switch( (*p) ) {
		case 34: goto tr48;
		case 123: goto tr49;
	}
	goto tr47;
tr29:
#line 11 "shortcodes.rl"
	{
    mark = p;
  }
	goto st18;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
#line 484 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr35;
		case 34: goto st7;
		case 37: goto tr36;
		case 62: goto tr36;
		case 123: goto tr15;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr35;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st18;
		} else if ( (*p) >= 65 )
			goto st18;
	} else
		goto st18;
	goto st6;
tr30:
#line 11 "shortcodes.rl"
	{
    mark = p;
  }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 514 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr35;
		case 34: goto st7;
		case 37: goto tr36;
		case 61: goto tr38;
		case 62: goto tr36;
		case 123: goto tr15;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr35;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st19;
		} else if ( (*p) >= 65 )
			goto st19;
	} else
		goto st18;
	goto st6;
tr38:
#line 27 "shortcodes.rl"
	{bcatcstr(output, "A"); 
       bcatblk(output, mark, p-mark);
       bcatcstr(output, "\n");
      }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
#line 546 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr27;
		case 123: goto tr15;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr29;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr29;
	} else
		goto tr29;
	goto st6;
tr11:
#line 11 "shortcodes.rl"
	{
    mark = p;
  }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 570 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr40;
		case 37: goto tr41;
		case 62: goto tr41;
		case 123: goto tr1;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr40;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st21;
		} else if ( (*p) >= 65 )
			goto st21;
	} else
		goto st21;
	goto st0;
tr12:
#line 11 "shortcodes.rl"
	{
    mark = p;
  }
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
#line 599 "shortcodes.c"
	switch( (*p) ) {
		case 32: goto tr40;
		case 37: goto tr41;
		case 61: goto tr43;
		case 62: goto tr41;
		case 123: goto tr1;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr40;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st22;
		} else if ( (*p) >= 65 )
			goto st22;
	} else
		goto st21;
	goto st0;
tr43:
#line 27 "shortcodes.rl"
	{bcatcstr(output, "A"); 
       bcatblk(output, mark, p-mark);
       bcatcstr(output, "\n");
      }
	goto st23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
#line 630 "shortcodes.c"
	switch( (*p) ) {
		case 34: goto tr9;
		case 123: goto tr1;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr11;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto tr11;
	} else
		goto tr11;
	goto st0;
	}
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
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 25: 
	case 26: 
#line 58 "shortcodes.rl"
	{bcatcstr(output, "\n");}
	break;
#line 681 "shortcodes.c"
	}
	}

	}

#line 77 "shortcodes.rl"
    return output;
}

int main(int argc, char **argv) {
    bstring output = parse("{{< thename  \"onearg\">}} {{% sc/42 another argname=\"val3\" %}}");
    printf("\n%s\n", output->data);
    return 0;
}
