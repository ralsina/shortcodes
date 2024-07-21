#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "shortcodes.h"

%%{
  machine shortcode;

  action mark {
    mark = p;
  }

  spc = space*;
  sep = space+;
  path = (alnum | '/' | '.' )+;

  # sc_list is a list of shortcodes
  # c_sc is the current shortcode we are parsing
  # argnames is the list of arguments for the shortcode

  # name is the first word in the sc can be a path
  name = (alpha+ path?) 
    > mark
    %{ 
      sc_list[c_sc].name.start = mark-start;
      sc_list[c_sc].name.len = p-mark;
      sc_list[c_sc].matching = 0;
      sc_list[c_sc].closed = 0;
      sc_list[c_sc].argcount = 0;
      if (p-mark > 7) {
        sc_list[c_sc].is_inline = abs(strncmp(p-7, ".inline", 7));  
      }
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      };
  # name for the arg, just a word
  argname = alpha+  
    > mark
    % {
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argnames[sc_list[c_sc].argcount].len = p-mark;
    };

  # quoted string, between double quotes
  qvalue = (('"' [^"]* '"') | ("'" [^']* "'"))
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

  # A value, letters or numbers
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

  # An argument is a name, an = and a value or quoted value
  # Or, just a value or qvalue (positional argument)
  arg = ((argname '=')? (value|qvalue));

  # A shortcode with markdown content
  start_p = ('{{%');
  end_p = '%}}'
  @{sc_list[c_sc].markdown = 1;};
  end_p_sc = '/%}}'
  @{sc_list[c_sc].markdown = 1;
    sc_list[c_sc].self_closing = 1;
  };


  # A shortcode with verbatim content
  start_b = ('{{<');
  end_b = '>}}' 
  @{sc_list[c_sc].markdown = 0;};
  end_b_sc = '/>}}'
  @{sc_list[c_sc].markdown = 1;
    sc_list[c_sc].self_closing = 1;
  };

  # An escaped shortcode
  start_e = ('{{</*' | '{{%/*');
  end_e = ('*/>}}' | '*/%}}')
  @{sc_list[c_sc].escaped = 1;};

  # Inside a shortcode is content: name, zero or more arguments
  content = spc name (sep arg)* spc;

  # Both possible starts or ends
  start = start_p | start_b ;
  end = end_p | end_b | end_p_sc | end_b_sc;

  # Mismatched start and end, remove it
  mismatched = ((start_p content end_b) | (start_b content end_p)) 
  @{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
    result.errors[result.errcount].position = p-start-2;
    result.errors[result.errcount].code = ERR_MISMATCHED_BRACKET;
    result.errcount++;
  };

  # A full shortcode
  shortcode = ((start_p content (end_p | end_p_sc)) | (start_b content (end_b | end_b_sc)) | (start_e content end_e))
  > {
      sc_list[c_sc].whole.start = p-start-1;
    }
  @ {
      sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
      data_mark = p+1;
      c_sc++;
    };

  # A closing shortcode for matched "tags"
  closing_shortcode = (start spc '/' name spc end)
  > {sc_mark = p;};

  # Only close matched shortcodes
  matched_shortcode = (shortcode any* closing_shortcode)
  @ {
    // First find what opening shortcode we are closing
    // IF ANY!
    int found = 0;
    // Go back in the list of shortcodes from the previous one 
    for (int i=c_sc-1; i>=0; i--) {

      if (!sc_list[i].closed  // If it's a not-closed 
        && sc_list[i].name.len == sc_list[c_sc].name.len // Same length
        && // Same name
          strncmp(
            start + sc_list[i].name.start,
            start + sc_list[c_sc].name.start,
            sc_list[c_sc].name.len) ==0) {
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
