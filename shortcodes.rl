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

  label = alpha+ 
    > mark
    % {printf("label: '%s'\n", grab_chunk(mark, p)->data);};
  value = (('"' [^"]* '"') | alnum+) 
    > mark 
    % {printf("value: '%s'\n", grab_chunk(mark, p)->data);};
  arg = (label '=' value) 
    > mark
    % {printf("arg: '%s'\n", grab_chunk(mark, p)->data);};

  start = '{{';
  end = '}}';

  main := (start spc label (sep (value | arg))* spc end);

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
    bstring output = parse("{{   foo  \"sarasa\" foobar foo=\"bar\" }}");
    printf("\n%s\n", output->data);
    return 0;
}
