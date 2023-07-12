#include <cgreen/cgreen.h>
#include <bglibs/str.h>
#include "shortcodes.h"

Describe(parse);
BeforeEach(parse) {}
AfterEach(parse) {}

shortcode *result;
str s;

chunk_s(char *buffer, chunk c){
    str_copyb(&s, buffer + c.start, c.len);
}

Ensure(parse, empty_string)
{
    char *input = "";
    result = parse(input);
    // This means no shortcodes in it
    assert_that(result[0].name.len, is_equal_to(0));
}

Ensure(parse, simple_shortcode)
{
    char *input = "foobar {{% shortcode %}}blah";
    result = parse(input);
    // Only 1 shortcode
    assert_that(result[1].name.len, is_equal_to(0));

    // It's a simple one called shortcode, no args
    chunk_s(input, result[0].name);
    assert_that(s.s, is_equal_to_string("shortcode"));
    assert_that(result[0].matching, is_equal_to(0));
    assert_that(result[0].argcount, is_equal_to(0));
    chunk_s(input, result[0].whole);
    assert_that(s.s, is_equal_to_string("{{% shortcode %}}"));
}

Ensure(parse, matching_shortcode)
{
    char *input = "{{% shortcode %}}foo bar{{% /shortcode %}}";
    result = parse(input);
    chunk_s(input, result[0].name);

    // Only 1 shortcode
    assert_that(result[1].name.len, is_equal_to(0));

    // It's a matching one called shortcode, no args
    assert_that(s.s, is_equal_to_string("shortcode"));
    assert_that(result[0].matching, is_equal_to(1));
    assert_that(result[0].argcount, is_equal_to(0));
}

int main(int argc, char **argv)
{
    str_init(&s);
    TestSuite *suite = create_test_suite();
    add_test_with_context(suite, parse, empty_string);
    add_test_with_context(suite, parse, simple_shortcode);
    add_test_with_context(suite, parse, matching_shortcode);
    return run_test_suite(suite, create_text_reporter());
}
