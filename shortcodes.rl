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

  start_p = '{{%';
  end_p = '%}}';

  start_b = '{{<';
  end_b = '>}}';

  start = start_p | start_b ;
  end = end_p | end_b ;

  shortcode = (start spc name (sep arg)* spc end)
  > {
      sc_list[c_sc].start = p-start-1;
    }
  @ {
      sc_list[c_sc].len = p-start-sc_list[c_sc].start+1;
      data_mark = p+1;
      c_sc++;
    };

  closing_shortcode = (start spc '/' name spc end)
  > {
    // Starting a shortcode, close data (if previous shortcode is opening)
    // If it's closing, then previous text can't be data.
    if (sc_list[c_sc-1].matching == 0) {
      sc_list[c_sc-1].data.start = data_mark-start;
      sc_list[c_sc-1].data.len = p-data_mark-1;
    }
  };

  matched_shortcode = (shortcode any* closing_shortcode)
  @ {
    sc_list[c_sc-1].matching = 1;
    sc_list[c_sc-1].len = p-start-sc_list[c_sc-1].start + 1;
    if (
        sc_list[c_sc-1].name.len != sc_list[c_sc].name.len ||
        strncmp(
          start + sc_list[c_sc-1].name.start,
          start + sc_list[c_sc].name.start,
          sc_list[c_sc-1].name.len) !=0) 
     {
      printf("Mismatched tags!\n");
      str_copyb(&sc,start + sc_list[c_sc-1].name.start, sc_list[c_sc-1].name.len);
      printf("opened: %s\n", sc.s);
      str_copyb(&sc,start + sc_list[c_sc].name.start, sc_list[c_sc].name.len);
      printf("closed: %s\n", sc.s);
      return 1;
    }
    // Reuse this shortcode entry for next one
    sc_list[c_sc].name.start = 0;
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

  shortcode sc_list[1000]; 
  int c_sc = 0;

  int sc_start = 0;
  int sc_end = 0;

  char *mark = p;
  char *data_mark = p;
  str sc;
  str_init(&sc);

  %% write init;
  %% write exec;

  for (int i=0; sc_list[i].name.start!=0; i++) {
    str_copyb(&sc, start + sc_list[i].name.start, sc_list[i].name.len);
    printf("sc_name: %s (%d)\n", sc.s, sc_list[i].matching );
    str_copyb(&sc, start + sc_list[i].start, sc_list[i].len);
    printf("full_sc: %s\n", sc.s);
    if (sc_list[i].matching) {
      str_copyb(&sc, start + sc_list[i].data.start, sc_list[i].data.len);
      printf("sc_data: %s\n", sc.s);
    }

    for (int j=0; j< sc_list[i].argcount; j++) {
      str_copyb(&sc, start + sc_list[i].argnames[j].start, sc_list[i].argnames[j].len);
      printf("argname %d: %s\n", j, sc.s);
      str_copyb(&sc, start + sc_list[i].argvals[j].start, sc_list[i].argvals[j].len);
      printf("argval %d: %s\n", j, sc.s);
    }
  }
  return 0;
}

// int main(int argc, char **argv) {
//     parse(
// "bbb{{% sarasa sar1 sar2 \"sar3\" %}}ccc"
// "{{< c1  arg2  >}}foobar{{% /c1%}}aaa{{% sarasa name=\"pepe\" %}}");
//     return 0;
// };
