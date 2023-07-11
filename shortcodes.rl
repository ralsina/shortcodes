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
       str_copyb(&new_name, mark, p-mark);
      };
  argname = alpha+
    > mark
    % {str_cats(&output, "A ");
       str_catb(&output, mark, p-mark);
       str_cats(&output, "\n");
      };
  qvalue = ('"' [^"]* '"')
    > mark
    % {str_cats(&output, "V ");
       str_catb(&output, mark+1, p-mark-2);
       str_cats(&output, "\n");
      };

  value = alnum+
    > mark
    % {str_cats(&output, "V ");
       str_catb(&output, mark, p-mark);
       str_cats(&output, "\n");
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
      str_copy(&open_name, &new_name);
      shortcodes[c_sc].len = p-start-shortcodes[c_sc].start+1;
      data_mark = p+1;
      c_sc++;
    };

  closing_shortcode = (start spc '/' name spc end)
  > {
    // Starting a shortcode, close data
    shortcodes[c_sc-1].data.start = data_mark-start;
    shortcodes[c_sc-1].data.len = p-data_mark-1;
    str_copyb(&sc, start+shortcodes[c_sc-1].data.start, shortcodes[c_sc-1].data.len);
  };

  matched_shortcode = (shortcode any* closing_shortcode)
  @ {
    shortcodes[c_sc-1].matching = 1;
    shortcodes[c_sc-1].len = p-start-shortcodes[c_sc-1].start + 1;
    shortcodes[c_sc].name.start = 0;
    if (str_cmp(&open_name, 0, &new_name, 0) != 0) {
      // Closing the wrong code
      // TODO error reporting
      return;
    }
    str_truncate(&open_name,0);
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
};
typedef struct shortcode shortcode;

void parse(char *input) {
    %%write data;
    char *eof, *ts, *te = 0;
    int cs, act = 0;

    char *start = input;
    char *p = input;
    char *pe = p + strlen(input);
    str open_name, new_name, output, data;
    str_init(&open_name);
    str_init(&new_name);
    str_init(&output);
    str_init(&data);

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
    }
}

int main(int argc, char **argv) {
    parse("{{< c1  arg2  >}}foobar{{% /c1%}}{{% sarasa %}}");
    // if (output == 0) {
    //   printf("parse error\n");
    //   return 1;
    // }
    return 0;
}
