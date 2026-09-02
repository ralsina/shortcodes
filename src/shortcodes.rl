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
      if (c_sc < SC_MAX) {
        sc_list[c_sc].name.start = mark-start;
        sc_list[c_sc].name.len = p-mark;
        sc_list[c_sc].matching = 0;
        sc_list[c_sc].closed = 0;
        sc_list[c_sc].argcount = 0;
        in_arg = 0;
        if (p-mark > 7 && !strncmp(p-7, ".inline", 7)) {
          sc_list[c_sc].is_inline = 1;
        } else {
          sc_list[c_sc].is_inline = 0;
        }
        sc_list[c_sc].argnames[sc_list[c_sc].argcount].start=0;
        sc_list[c_sc].argnames[sc_list[c_sc].argcount].len=0;
        sc_list[c_sc].argvals[sc_list[c_sc].argcount].start=0;
        sc_list[c_sc].argvals[sc_list[c_sc].argcount].len=0;
      }
      arg_overflow = 0;
    };
  # name for the arg, just a word
  argname = alpha+
    > mark
    % {
      if (c_sc < SC_MAX) {
        if (!in_arg) {
          if (sc_list[c_sc].argcount >= ARG_MAX) {
            add_error(result, ERR_TOO_MANY_ARGS, mark-start);
            arg_overflow = 1;
          } else {
            cur_arg = sc_list[c_sc].argcount;
            sc_list[c_sc].argcount++;
          }
          in_arg = 1;
        }
        if (!arg_overflow) {
          sc_list[c_sc].argnames[cur_arg].start = mark-start;
          sc_list[c_sc].argnames[cur_arg].len = p-mark;
        }
      }
    };

  # quoted string, between double quotes
  qvalue = (('"' ([^"\\] | /\\./)* '"') | ("'" ([^'\\] | /\\./)* "'"))
    > mark
    % {
      if (c_sc < SC_MAX) {
        if (!in_arg) {
          if (sc_list[c_sc].argcount >= ARG_MAX) {
            add_error(result, ERR_TOO_MANY_ARGS, mark-start);
            arg_overflow = 1;
          } else {
            cur_arg = sc_list[c_sc].argcount;
            sc_list[c_sc].argcount++;
            /* positional arg: nobody else will write the name slot */
            sc_list[c_sc].argnames[cur_arg].start = 0;
            sc_list[c_sc].argnames[cur_arg].len = 0;
          }
          in_arg = 1;
        }
        if (!arg_overflow) {
          sc_list[c_sc].argvals[cur_arg].start = mark-start+1;
          sc_list[c_sc].argvals[cur_arg].len = p-mark-2;
        }
      }
    };

  # A value, unquoted: letters, numbers and unambiguous punctuation.
  # The value must start and end with a non-slash character so a
  # trailing '/' can't bleed into the self-closing delimiters
  # '/%}}' or '/>}}'
  unq = (alnum | '-' | '_' | '.' | ':' | '@' | '+' | '~' | '#');
  value = (unq ((unq | '/')* unq)?)
    > mark
    % {
      /* The machine passes through intermediate final states
         ("docs" vs "docs/v2_1") and this action fires on each:
         count the arg only the first time, then keep extending
         the recorded span. */
      if (c_sc < SC_MAX) {
        if (last_val_mark != mark) {
          if (!in_arg) {
            if (sc_list[c_sc].argcount >= ARG_MAX) {
              add_error(result, ERR_TOO_MANY_ARGS, mark-start);
              arg_overflow = 1;
            } else {
              cur_arg = sc_list[c_sc].argcount;
              sc_list[c_sc].argcount++;
              /* positional arg: nobody else will write the name slot */
              sc_list[c_sc].argnames[cur_arg].start = 0;
              sc_list[c_sc].argnames[cur_arg].len = 0;
            }
            in_arg = 1;
            last_val_mark = mark;
          } else {
            last_val_mark = mark;
          }
        }
        if (!arg_overflow) {
          sc_list[c_sc].argvals[cur_arg].start = mark-start;
          sc_list[c_sc].argvals[cur_arg].len = p-mark;
        }
      }
    };

  # An argument is a name, an = and a value or quoted value
  # Or, just a value or qvalue (positional argument)
  # argcount is maintained by the actions above, not here.
  arg = ((argname '=')? (value|qvalue));

  # Between args: the current arg is done
  argsep = sep
    @{ in_arg = 0; };

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
  content = spc name (argsep arg)* spc;

  # Both possible starts or ends
  start = start_p | start_b ;
  end = end_p | end_b | end_p_sc | end_b_sc;

  # Mismatched start and end, remove it
  mismatched = ((start_p content end_b) | (start_b content end_p))
  @{
    // Since it's mismatched, remove the name
    if (c_sc < SC_MAX) {
      sc_list[c_sc].name.start = 0;
      sc_list[c_sc].name.len=0;
    }
    add_error(result, ERR_MISMATCHED_BRACKET, p-start-2);
  };

  # A full shortcode
  shortcode = ((start_p content (end_p | end_p_sc)) | (start_b content (end_b | end_b_sc)) | (start_e content end_e))
  > {
      if (c_sc < SC_MAX) {
        sc_list[c_sc].whole.start = p-start-1;
      }
    }
  @ {
      if (c_sc < SC_MAX) {
        sc_list[c_sc].whole.len = p-start-sc_list[c_sc].whole.start+1;
        data_mark = p+1;
        c_sc++;
      } else {
        add_error(result, ERR_TOO_MANY_SHORTCODES, p-start);
      }
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
    for (int i=(c_sc < SC_MAX ? c_sc : 0)-1; i>=0; i--) {

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
      add_error(result, ERR_MISMATCHED_CLOSING_TAG,
          (c_sc < SC_MAX) ? sc_list[c_sc].whole.start : 0);
      // Do NOT increase c_sc
    }
};

  main := (any* (shortcode | matched_shortcode | mismatched))*;
}%%

/* Limits must match the array sizes in sc_result (shortcodes.h) */
#define SC_MAX 100
#define ARG_MAX 100
#define ERR_MAX 10

static void add_error(sc_result *result, unsigned int code, unsigned int position) {
  if (result->errcount < ERR_MAX) {
    result->errors[result->errcount].position = position;
    result->errors[result->errcount].code = code;
    result->errcount++;
  }
}

/* The result is written into a caller-provided sc_result instead of
being returned by value: the struct is ~160KB, and by-value returns
make optimizing compilers explode the copies into hundreds of
thousands of instructions. */
void parse(char *input, unsigned int len, sc_result *result) {

  %%write data;
  char *eof = input + len;
  char *ts, *te = 0;
  int cs, act = 0;

  char *start = input;
  char *p = input;
  char *pe = p + len;

  /* Zero the whole result: some fields (escaped, self_closing, ...)
  are only assigned when their actions fire, and callers rely on
  them being 0 otherwise. */
  memset(result, 0, sizeof(*result));
  shortcode *sc_list = result->sc;
  int c_sc = 0;

  char *mark = p;
  char *data_mark = p;
  char *sc_mark = p;
  char *last_val_mark = 0;
  int in_arg = 0;
  int cur_arg = 0;
  int arg_overflow = 0;

  %% write init;
  %% write exec;

  result->sccount = c_sc;
}
