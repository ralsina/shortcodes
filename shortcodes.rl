#include <stdio.h>
#include "bstrlib/bstrlib.h"

%%{
  machine shortcode;

  label = alpha+ > {label_start = p; printf("%s", label_start);} > {printf("=>%s", label_start);};

  start = '{{' % {printf("start");};
  end = '}}' > {printf("end");};

  main := (start label? end);

}%%

bstring parse(char *_input) {
    %%write data;
    char *eof, *ts, *te = 0;
    int cs, act = 0;

    bstring output = bfromcstr("out");

    bstring input = bfromcstr(_input);
    char *p = input->data;
    char *pe = p + blength(input);

    char *label_start = 0;
    char *label_end = 0;
    
 
    %% write init;
    %% write exec;

    return output;
}

int main(int argc, char **argv) {
    bstring output = parse("{{foo}}");
    printf("\n%s\n", output->data);
    return 0;
}
