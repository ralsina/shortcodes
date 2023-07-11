#include <stdio.h>
#include <string.h>
#include "bglibs/str.h"
#include "bglibs/gstack.h"

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
    % {str_cats(&output, "N ");
       str_catb(&output, mark, p-mark);
       str_cats(&output, "\n");
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
  @ {
      str_cats(&output, "+++ opening\n");
      str_copy(&open_name, &new_name);
      data_mark = p;
    };

  closing_shortcode = (start spc '/' name spc end)
  > {
    // Starting a shortcode, close data
    str_copyb(&data, data_mark+1, p-data_mark-2);
  };

  matched_shortcode = (shortcode any* closing_shortcode)
  @ {
    str_cats(&output, "--- closing\n");
    printf("closing from %s to %s\n", open_name.s, new_name.s);
    printf("data: %s\n", data.s);
    if (str_cmp(&open_name, 0, &new_name, 0) != 0) {
      // Closing the wrong code
      // TODO error reporting
      return output;
    }
    str_truncate(&open_name,0);
  };

  main := (any* (shortcode | matched_shortcode))*;
}%%

str parse(char *input) {
    %%write data;
    char *eof, *ts, *te = 0;
    int cs, act = 0;

    char *p = input;
    char *pe = p + strlen(input);
    str open_name, new_name, output, data;
    str_init(&open_name);
    str_init(&new_name);
    str_init(&output);
    str_init(&data);

    char *mark = p;
    char *data_mark = p;

    %% write init;
    %% write exec;
    return output;
}

struct shortcode {
  str name;
  str args;
  str content;
};

int main(int argc, char **argv) {
    str output = parse("
      sarasa
      {{< o1  arg1  >}}
      stuff
      {{< c1  arg2  >}}foobar{{% /c1%}}
      {{< o2  arg1  >}}      
      {{< o3  arg1  >}}
      more stuff
      ");
    // if (output == 0) {
    //   printf("parse error\n");
    //   return 1;
    // }
    printf("\n%s\n", output.s);
    return 0;
}
