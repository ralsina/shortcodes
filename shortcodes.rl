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
    % {bcatcstr(output, "N"); 
       bcatblk(output, mark, p-mark);
       bcatcstr(output, "\n");
      };
  argname = alpha+ 
    > mark
    % {bcatcstr(output, "A"); 
       bcatblk(output, mark, p-mark);
       bcatcstr(output, "\n");
      };
  qvalue = ('"' [^"]* '"')
    > mark
    % {bcatcstr(output, "V"); 
       bcatblk(output, mark+1, p-mark-2);
       bcatcstr(output, "\n");
      };

  value = alnum+
    > mark
    % {bcatcstr(output, "V"); 
       bcatblk(output, mark, p-mark);
       bcatcstr(output, "\n");
      };

  arg = ((argname '=')? (value|qvalue));

  start_p = '{{%';
  end_p = '%}}';

  start_b = '{{<';
  end_b = '>}}';

  start = start_p | start_b ;
  end = end_p | end_b ;

  shortcode = (start spc name (sep arg)* spc end)
  > {bcatcstr(output, "---\n");}
  % {bcatcstr(output, "\n");};

  

  main := (any* shortcode)*;
}%%

bstring parse(char *input) {
    %%write data;
    char *eof, *ts, *te = 0;
    int cs, act = 0;

    char *p = input;
    char *pe = p + strlen(input);

    char *mark = 0;
    bstring output = bfromcstr("");
    %% write init;
    %% write exec;
    return output;
}

int main(int argc, char **argv) {
    bstring output = parse("{{< thename  \"onearg\">}} {{% sc/42 another argname=\"val3\" %}}");
    printf("\n%s\n", output->data);
    return 0;
}
