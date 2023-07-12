#include <cgreen/cgreen.h>
#include "shortcodes.h"

Describe(parse);
BeforeEach(parse) {}
AfterEach(parse) {}

Ensure(parse, empty_string) {
    char *input = "";
    int output = parse(input);
    assert_that(output, is_equal_to(0));
}


int main(int argc, char **argv) {
    TestSuite *suite = create_test_suite();
    add_test_with_context(suite, parse, empty_string);
    return run_test_suite(suite, create_text_reporter());
}
