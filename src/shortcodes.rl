#include <string.h>
#include <stdio.h>
#include "shortcodes.h"

%%{
  machine shortcode;

  action mark {
    mark = p;
  }

  spc = space*;
  sep = space+;
  path = (alnum | '/' )+;

  name = (alpha+ path?)
    > mark
    %{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      };
  argname = alpha+
    > mark
    % {
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    };
  qvalue = ('"' [^"]* '"')
    > mark
    % {
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start+1;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark-2;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    };

  value = alnum+
    > mark
    % {
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
    };

  arg = ((argname '=')? (value|qvalue));

  start_p = ('{{%');
  end_p = '%}}'
  @{sc_list[c_sc].markdown = 1;};

  start_b = ('{{<');
  end_b = '>}}' 
  @{sc_list[c_sc].markdown = 0;};

  content = spc name (sep arg)* spc;

  start = start_p | start_b ;
  end = end_p | end_b ;

  mismatched = ((start_p content end_b) | (start_b content end_p)) 
  @{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  };

  shortcode = ((start_p content end_p) | (start_b content end_b))
  > {
      sc_list[c_sc].whole.start = p-start-1;
    }
  @ {
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    };

  closing_shortcode = (start spc '/' name spc end)
  > {sc_mark = p;};

  matched_shortcode = (shortcode any* closing_shortcode)
  @ {
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
};

  main := (any* (shortcode | matched_shortcode | mismatched))*;
}%%


sc_result parse(char *input, unsigned int len) {

  %%write data;
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

  %% write init;
  %% write exec;

  result.sccount = c_sc;
  return result;
}
