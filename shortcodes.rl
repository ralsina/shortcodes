#include <stdio.h>
#include <string.h>
#include "bglibs/str.h"

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
    %{ shortcodes[c_sc].name.start = mark-start;
       shortcodes[c_sc].name.len = p-mark;
       shortcodes[c_sc].matching = 0;
      };
  argname = alpha+
    > mark
    % {
      shortcodes[c_sc].argnames[shortcodes[c_sc].argcount].start = mark-start;
      shortcodes[c_sc].argnames[shortcodes[c_sc].argcount].len = p-mark;
    };
  qvalue = ('"' [^"]* '"')
    > mark
    % {
      shortcodes[c_sc].argvals[shortcodes[c_sc].argcount].start = mark-start;
      shortcodes[c_sc].argvals[shortcodes[c_sc].argcount].len = p-mark;
      shortcodes[c_sc].argcount++;
    };

  value = alnum+
    > mark
    % {
      shortcodes[c_sc].argvals[shortcodes[c_sc].argcount].start = mark-start;
      shortcodes[c_sc].argvals[shortcodes[c_sc].argcount].len = p-mark;
      shortcodes[c_sc].argcount++;
    };

  arg = ((argname '=')? (value|qvalue));

  start_p = '{{%';
  end_p = '%}}';

  start_b = '{{<';
  end_b = '>}}';

  start = start_p | start_b ;
  end = end_p | end_b ;

  shortcode = (start spc name (sep arg)* spc end)
  > {
      shortcodes[c_sc].start = p-start-1;
    }
  @ {
      shortcodes[c_sc].len = p-start-shortcodes[c_sc].start+1;
      data_mark = p+1;
      c_sc++;
    };

  closing_shortcode = (start spc '/' name spc end)
  > {
    // Starting a shortcode, close data (if previous shortcode is opening)
    // If it's closing, then previous text can't be data.
    if (shortcodes[c_sc-1].matching == 0) {
      shortcodes[c_sc-1].data.start = data_mark-start;
      shortcodes[c_sc-1].data.len = p-data_mark-1;
    }
  };

  matched_shortcode = (shortcode any* closing_shortcode)
  @ {
    shortcodes[c_sc-1].matching = 1;
    shortcodes[c_sc-1].len = p-start-shortcodes[c_sc-1].start + 1;
    if (
        shortcodes[c_sc-1].name.len != shortcodes[c_sc].name.len ||
        strncmp(
          start + shortcodes[c_sc-1].name.start,
          start + shortcodes[c_sc].name.start,
          shortcodes[c_sc-1].name.len) !=0) 
     {
      printf("Mismatched tags!\n");
      str_copyb(&sc,start + shortcodes[c_sc-1].name.start, shortcodes[c_sc-1].name.len);
      printf("opened: %s\n", sc.s);
      str_copyb(&sc,start + shortcodes[c_sc].name.start, shortcodes[c_sc].name.len);
      printf("closed: %s\n", sc.s);
      return 1;
    }
    // Reuse this shortcode entry for next one
    shortcodes[c_sc].name.start = 0;
  };

  main := (any* (shortcode | matched_shortcode))*;
}%%


struct chunk {
  int start, len;
};

typedef struct chunk chunk;

struct shortcode {
  int start;
  int len;
  chunk name;
  chunk data;
  char matching;
  chunk argnames[100];
  chunk argvals[100];
  int argcount;
};
typedef struct shortcode shortcode;

int parse(char *input) {
  %%write data;
  char *eof, *ts, *te = 0;
  int cs, act = 0;

  char *start = input;
  char *p = input;
  char *pe = p + strlen(input);

  shortcode shortcodes[1000]; 
  int c_sc = 0;

  int sc_start = 0;
  int sc_end = 0;

  char *mark = p;
  char *data_mark = p;
  str sc;
  str_init(&sc);

  %% write init;
  %% write exec;

  for (int i=0; shortcodes[i].name.start!=0; i++) {
    str_copyb(&sc, start + shortcodes[i].name.start, shortcodes[i].name.len);
    printf("sc_name: %s (%d)\n", sc.s, shortcodes[i].matching );
    str_copyb(&sc, start + shortcodes[i].start, shortcodes[i].len);
    printf("full_sc: %s\n", sc.s);
    if (shortcodes[i].matching) {
      str_copyb(&sc, start + shortcodes[i].data.start, shortcodes[i].data.len);
      printf("sc_data: %s\n", sc.s);
    }

    for (int j=0; j< shortcodes[i].argcount; j++) {
      str_copyb(&sc, start + shortcodes[i].argnames[j].start, shortcodes[i].argnames[j].len);
      printf("argname %d: %s\n", j, sc.s);
      str_copyb(&sc, start + shortcodes[i].argvals[j].start, shortcodes[i].argvals[j].len);
      printf("argval %d: %s\n", j, sc.s);
    }
  }
  return 0;
}

int main(int argc, char **argv) {
    parse(
"bbb{{% sarasa sar1 sar2 \"sar3\" %}}ccc
{{< c1  arg2  >}}foobar{{% /c1%}}aaa{{% sarasa name=pepe %}}");
    // if (output == 0) {
    //   printf("parse error\n");
    //   return 1;
    // }
    return 0;
}
