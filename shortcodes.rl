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

  name = alpha+ 
    > mark
    % {printf("name: '%s'\n", grab_chunk(mark, p)->data);};
  argname = alpha+ 
    > mark
    % {printf("argname: '%s'\n", grab_chunk(mark, p)->data);};
  value = (('"' [^"]* '"') | alnum+) 
    > mark 
    % {printf("value: '%s'\n", grab_chunk(mark, p)->data);};
  arg = (argname '=' value) 
    > mark
    % {printf("arg: '%s'\n", grab_chunk(mark, p)->data);};

  start = '{{';
  end = '}}';

  main := (start spc name (sep (arg | value))* spc end);
}%%

bstring parse(char *_input) {
    %%write data;
    char *eof, *ts, *te = 0;
    int cs, act = 0;

    bstring output = bfromcstr("out");

    bstring input = bfromcstr(_input);
    char *p = input->data;
    char *pe = p + blength(input);

    char *mark = 0;
    bstring label;
    
 
    %% write init;
    %% write exec;

    printf("\nLabel is: '%s'\n", label->data);
    return output;
}

int main(int argc, char **argv) {
    bstring output = parse("{{ thename  \"onearg\" another arg=\"val3\" }}");
    printf("\n%s\n", output->data);
    return 0;
}
