#!/usr/bin/tcc -run -lcgreen shortcodes.c bstrlib/bstrlib.c
#include <cgreen/cgreen.h>
#include "shortcodes.h"
#include "bstrlib/bstrlib.h"

Describe(parse);
BeforeEach(parse) {}
AfterEach(parse) {}

Ensure(parse, is_identity) {
    char *input = "hello";
    bstring output = parse(input);
    printf("%s / %s", output->data, input);
    assert_that(output->data, is_equal_to_string("hello!"));
}


int main(int argc, char **argv) {
    TestSuite *suite = create_test_suite();
    add_test_with_context(suite, parse, is_identity);
    return run_test_suite(suite, create_text_reporter());
}
