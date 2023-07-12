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

Ensure(parse, mismatched_brackets)
{
    char *input = "foobar {{% shortcode >}}blah";
    result = parse(input);
    // No shortcodes
    assert_that(result[0].name.len, is_equal_to(0));
}

Ensure(parse, mismatched_brackets_inside_data_are_ok)
{
    char *input = "foobar {{% sc %}} >}}blah {{% /sc %}} ";
    result = parse(input);
    // 1 shortcode
    assert_that(result[1].name.len, is_equal_to(0));
    chunk_s(input, result[0].whole);
    assert_that(s.s, is_equal_to_string("{{% sc %}} >}}blah {{% /sc %}}"));
    chunk_s(input, result[0].data);
    assert_that(s.s, is_equal_to_string(" >}}blah "));
}

Ensure(parse, mismatched_brackets_in_qval_are_ok)
{
    char *input = "foobar {{% sc  \">}}blah\" %}} {{% /sc %}}";
    result = parse(input);
    // 1 shortcode
    assert_that(result[1].name.len, is_equal_to(0));
    chunk_s(input, result[0].whole);
    assert_that(s.s, is_equal_to_string("{{% sc  \">}}blah\" %}} {{% /sc %}}"));
    chunk_s(input, result[0].argvals[0]);
    assert_that(s.s, is_equal_to_string(">}}blah"));
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

Ensure(parse, name_can_be_path)
{
    char *input = "foobar {{% shortcode/foo/bar %}}blah";
    result = parse(input);
    // Only 1 shortcode
    assert_that(result[1].name.len, is_equal_to(0));

    // It's a simple one called shortcode, no args
    chunk_s(input, result[0].name);
    assert_that(s.s, is_equal_to_string("shortcode/foo/bar"));
    assert_that(result[0].matching, is_equal_to(0));
    assert_that(result[0].argcount, is_equal_to(0));
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

Ensure(parse, shortcode_args)
{
    char *input = "foobar {{% shortcode foo \"bar\" 42 bat=v1 baz=\"v2\" %}}blah";
    result = parse(input);
    // Only 1 shortcode
    assert_that(result[1].name.len, is_equal_to(0));

    // The whole shortcode is the whole thing
    chunk_s(input, result[0].whole);
    assert_that(s.s, is_equal_to_string("{{% shortcode foo \"bar\" 42 bat=v1 baz=\"v2\" %}}"));

    // Name is shortcode
    chunk_s(input, result[0].name);
    assert_that(s.s, is_equal_to_string("shortcode"));
    assert_that(result[0].matching, is_equal_to(0));

    // Has 5 args
    assert_that(result[0].argcount, is_equal_to(5));

    // Arg1 is foo, no name
    assert_that(result[0].argnames[0].len, is_equal_to(0));
    chunk_s(input, result[0].argvals[0]);
    assert_that(s.s, is_equal_to_string("foo"));
    // Arg2 is bar, no name
    assert_that(result[0].argnames[1].len, is_equal_to(0));
    chunk_s(input, result[0].argvals[1]);
    assert_that(s.s, is_equal_to_string("bar"));
    // Arg3 is 42, no name
    assert_that(result[0].argnames[2].len, is_equal_to(0));
    chunk_s(input, result[0].argvals[2]);
    assert_that(s.s, is_equal_to_string("42"));
    // Arg4 is bat=v1
    chunk_s(input, result[0].argnames[3]);
    assert_that(s.s, is_equal_to_string("bat"));
    chunk_s(input, result[0].argvals[3]);
    assert_that(s.s, is_equal_to_string("v1"));
    // Arg5 is baz=v2
    chunk_s(input, result[0].argnames[4]);
    assert_that(s.s, is_equal_to_string("baz"));
    chunk_s(input, result[0].argvals[4]);
    assert_that(s.s, is_equal_to_string("v2"));
}

Ensure(parse, escaped_shortcode)
{
    char *input = "foobar \\{{% shortcode %}}";
    result = parse(input);
    // No shortcodes
    assert_that(result[0].name.len, is_equal_to(0));
}


int main(int argc, char **argv)
{
    str_init(&s);
    TestSuite *suite = create_test_suite();
    add_test_with_context(suite, parse, empty_string);
    add_test_with_context(suite, parse, simple_shortcode);
    add_test_with_context(suite, parse, mismatched_brackets);
    add_test_with_context(suite, parse, mismatched_brackets_inside_data_are_ok);
    add_test_with_context(suite, parse, mismatched_brackets_in_qval_are_ok);
    add_test_with_context(suite, parse, name_can_be_path);
    add_test_with_context(suite, parse, inner_spaces_optional);
    add_test_with_context(suite, parse, multiple_shortcodes);
    add_test_with_context(suite, parse, matching_shortcode);
    add_test_with_context(suite, parse, shortcode_args);

    // Bugs
    // add_test_with_context(suite, parse, escaped_shortcode);
    return run_test_suite(suite, create_text_reporter());
}
