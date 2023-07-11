#include <stdio.h>
#include "bstrlib/bstrlib.h"

bstring grab_chunk(char *start, char *end) {
  blk2bstr(start, end-start);
}

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
    % {bcatStatic(output, "N ");
       bcatblk(output, mark, p-mark);
       bcatStatic(output, "\n");
       bassignblk (new_name, mark, p-mark);
      };
  argname = alpha+
    > mark
    % {bcatStatic(output, "A ");
       bcatblk(output, mark, p-mark);
       bcatStatic(output, "\n");
      };
  qvalue = ('"' [^"]* '"')
    > mark
    % {bcatStatic(output, "V ");
       bcatblk(output, mark+1, p-mark-2);
       bcatStatic(output, "\n");
      };

  value = alnum+
    > mark
    % {bcatStatic(output, "V ");
       bcatblk(output, mark, p-mark);
       bcatStatic(output, "\n");
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
      bcatStatic(output, "+++ opening\n");
      bassign(open_name, new_name);
    };

  closing_shortcode = (start spc '/' name spc end)
  @ {
    bcatStatic(output, "--- closing\n");
    // TODO: fail on error. 
    // TODO: Use a stack of open shortcodes rather than 1
    printf("closing from %s to %s", open_name->data, new_name->data);
  };


  main := (any* (shortcode | closing_shortcode))*;
}%%

bstring parse(char *input) {
    %%write data;
    char *eof, *ts, *te = 0;
    int cs, act = 0;

    char *p = input;
    char *pe = p + strlen(input);
    bstring open_name = bfromcstr("");
    bstring new_name = bfromcstr("");

    char *mark = 0;
    bstring output = bfromcstr("");
    %% write init;
    %% write exec;
    return output;
}

int main(int argc, char **argv) {
    bstring output = parse("
      {{< o1  arg1  >}}
      {{% /c1%}}");
    printf("\n%s\n", output->data);
    return 0;
}
