#include "bstrlib/bstrlib.h"

bstring parse(char *_input) {
    bstring output = bfromcstr(_input);
    bconchar(output, '!');
    return output;
}
