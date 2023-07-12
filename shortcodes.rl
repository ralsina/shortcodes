#include <string.h>
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
    %{ sc_list[c_sc].name.start = mark-start;
       sc_list[c_sc].name.len = p-mark;
       sc_list[c_sc].matching = 0;
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
    };

  value = alnum+
    > mark
    % {
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].start = mark-start;
      sc_list[c_sc].argvals[sc_list[c_sc].argcount].len = p-mark;
      sc_list[c_sc].argcount++;
    };

  arg = ((argname '=')? (value|qvalue));

  start_p = ('{{%');
  end_p = '%}}';

  start_b = ('{{<');
  end_b = '>}}';

  content = spc name (sep arg)* spc;

  start = start_p | start_b ;
  end = end_p | end_b ;

  mismatched = ((start_p content end_b) | (start_b content end_p)) 
  @{
    // Since it's mismatched, remove the name
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
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
  > {
    // Starting a "closing" shortcode ( {{ /foo }}), 
    // close data (if previous shortcode is opening)
    // If previous shortcode was closing, then previous 
    // text can't be data.
    if (sc_list[c_sc-1].matching == 0) {
      sc_list[c_sc-1].data.start = data_mark-start;
      sc_list[c_sc-1].data.len = p-data_mark-1;
    }
  };

  matched_shortcode = (shortcode any* closing_shortcode)
  @ {
    sc_list[c_sc-1].matching = 1;
    sc_list[c_sc-1].whole.len = p-start-sc_list[c_sc-1].whole.start + 1;
    if (
        sc_list[c_sc-1].name.len != sc_list[c_sc].name.len ||
        strncmp(
          start + sc_list[c_sc-1].name.start,
          start + sc_list[c_sc].name.start,
          sc_list[c_sc-1].name.len) !=0) 
     {
      return NULL;
    }
    // Reuse this shortcode entry for next one
    sc_list[c_sc].name.start = 0;
    sc_list[c_sc].name.len=0;
};

  main := (any* (shortcode | matched_shortcode | mismatched))*;
}%%


shortcode *parse(char *input) {

  %%write data;
  char *eof, *ts, *te = 0;
  int cs, act = 0;

  char *start = input;
  char *p = input;
  char *pe = p + strlen(input);

  shortcode sc_list[1000]; 
  int c_sc = 0;

  int sc_start = 0;
  int sc_end = 0;

  char *mark = p;
  char *data_mark = p;

  %% write init;
  %% write exec;

  return sc_list;
}

// int main(int argc, char **argv) {
//     parse(
// "bbb{{% sarasa sar1 sar2 \"sar3\" %}}ccc"
// "{{< c1  arg2  >}}foobar{{% /c1%}}aaa{{% sarasa name=\"pepe\" %}}");
//     return 0;
// };
