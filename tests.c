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
    // The whole shortcode is the whole thing
    chunk_s(input, result[0].whole);
    assert_that(s.s, is_equal_to_string("{{% shortcode %}}"));
}

Ensure(parse, inner_spaces_optional)
{
    char *input = "foobar {{%    shortcode%}}blah";
    result = parse(input);
    // Only 1 shortcode
    assert_that(result[1].name.len, is_equal_to(0));

    // It's a simple one called shortcode, no args
    chunk_s(input, result[0].name);
    assert_that(s.s, is_equal_to_string("shortcode"));
    assert_that(result[0].matching, is_equal_to(0));
    assert_that(result[0].argcount, is_equal_to(0));
    // The whole shortcode is the whole thing
    chunk_s(input, result[0].whole);
    assert_that(s.s, is_equal_to_string("{{%    shortcode%}}"));
}

Ensure(parse, multiple_shortcodes)
{
    char *input = "foobar {{% shortcode %}}blah {{<sc2 >}}blahblah";
    result = parse(input);
    // 2 shortcodes
    assert_that(result[2].name.len, is_equal_to(0));

    // It's a simple one called shortcode, no args
    chunk_s(input, result[0].name);
    assert_that(s.s, is_equal_to_string("shortcode"));
    assert_that(result[0].matching, is_equal_to(0));
    assert_that(result[0].argcount, is_equal_to(0));
    // The whole shortcode is the whole thing
    chunk_s(input, result[0].whole);
    assert_that(s.s, is_equal_to_string("{{% shortcode %}}"));
    // It's a simple one called sc2, no args
    chunk_s(input, result[1].name);
    assert_that(s.s, is_equal_to_string("sc2"));
    assert_that(result[1].matching, is_equal_to(0));
    assert_that(result[1].argcount, is_equal_to(0));
    // The whole shortcode is the whole thing
    chunk_s(input, result[1].whole);
    assert_that(s.s, is_equal_to_string("{{<sc2 >}}"));
}

Ensure(parse, matching_shortcode)
{
    char *input = "blah {{% shortcode %}}foo bar{{% /shortcode %}} blah";
    result = parse(input);

    // Only 1 shortcode
    assert_that(result[1].name.len, is_equal_to(0));

    // It's a matching one called shortcode, no args
    chunk_s(input, result[0].name);
    assert_that(s.s, is_equal_to_string("shortcode"));
    assert_that(result[0].matching, is_equal_to(1));
    assert_that(result[0].argcount, is_equal_to(0));
    // data is the stuff between the shortcode tags
    chunk_s(input, result[0].data);
    assert_that(s.s, is_equal_to_string("foo bar"));
    // The whole shortcode is the whole thing
    chunk_s(input, result[0].whole);
    assert_that(s.s, is_equal_to_string("{{% shortcode %}}foo bar{{% /shortcode %}}"));
}

int main(int argc, char **argv)
{
    str_init(&s);
    TestSuite *suite = create_test_suite();
    add_test_with_context(suite, parse, empty_string);
    add_test_with_context(suite, parse, simple_shortcode);
    add_test_with_context(suite, parse, inner_spaces_optional);
    add_test_with_context(suite, parse, multiple_shortcodes);
    add_test_with_context(suite, parse, matching_shortcode);
    return run_test_suite(suite, create_text_reporter());
}
