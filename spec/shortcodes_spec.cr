require "./spec_helper"
include Shortcodes

describe "Shortcodes" do
  it "should parse empty string" do
    result = parse("")
    result.shortcodes.size.should eq 0
    result.errors.size.should eq 0
  end

  it "should parse simeple shortcode" do
    result = parse("foobar {{% shortcode %}}blah")
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "shortcode"
    result.shortcodes[0].matching.should eq 0
    result.shortcodes[0].args.size.should eq 0
    result.shortcodes[0].whole.should eq "{{% shortcode %}}"
  end

  it "should report mismatched tags" do
    input = "foobar {{% shortcode %}}blah{{% /foo %}}"
    result = parse(input)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 1
    result.errors[0].code.should eq ERR_MISMATCHED_CLOSING_TAG
    input[result.errors[0].position, 8].should eq "{{% /foo"
  end

  it "should report mismatched brackets" do
    input = "foobar {{% shortcode >}}blah"
    result = parse(input)
    result.shortcodes.size.should eq 0
    result.errors.size.should eq 1
    result.errors[0].code.should eq ERR_MISMATCHED_BRACKET
    input[result.errors[0].position, 3].should eq ">}}"
  end

  it "should accept mismatched brackets inside data are ok" do
    input = "foobar {{% sc %}} >}}blah {{% /sc %}} "
    result = parse(input)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].whole.should eq "{{% sc %}} >}}blah {{% /sc %}}"
    result.shortcodes[0].data.should eq " >}}blah "
  end

  it "should accept mismatched brackets in qvals" do
    input = "foobar {{% sc  \">}}blah\" %}} {{% /sc %}}"
    result = parse(input)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].whole.should eq "{{% sc  \">}}blah\" %}} {{% /sc %}}"
    result.shortcodes[0].args.size.should eq 1
    result.shortcodes[0].args[0].@value.should eq ">}}blah"
  end

  it "should consider spaces in shortcodes optional" do
    input = "foobar {{%    shortcode%}}blah"
    result = parse(input)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "shortcode"
    result.shortcodes[0].matching.should eq 0
    result.shortcodes[0].args.size.should eq 0
    result.shortcodes[0].whole.should eq "{{%    shortcode%}}"
  end

  it "should allow path-like names" do
    input = "foobar {{% shortcode/foo/bar %}}blah"
    result = parse(input)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "shortcode/foo/bar"
    result.shortcodes[0].matching.should eq 0
    result.shortcodes[0].args.size.should eq 0
    result.shortcodes[0].whole.should eq "{{% shortcode/foo/bar %}}"
  end

  it "should parse multiple shortcodes" do
    input = "foobar {{% shortcode %}}blah {{<sc2 >}}blahblah"
    result = parse(input)
    result.shortcodes.size.should eq 2
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "shortcode"
    result.shortcodes[0].matching.should eq 0
    result.shortcodes[0].args.size.should eq 0
    result.shortcodes[0].whole.should eq "{{% shortcode %}}"
    result.shortcodes[1].name.should eq "sc2"
    result.shortcodes[1].matching.should eq 0
    result.shortcodes[1].args.size.should eq 0
    result.shortcodes[1].whole.should eq "{{<sc2 >}}"
  end
  
  it "should parse matching shortcodes" do
    input = "foobar {{% shortcode %}}blah {{% /shortcode %}} blah"
    result = parse(input)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "shortcode"
    result.shortcodes[0].matching.should eq 1
    result.shortcodes[0].args.size.should eq 0
    result.shortcodes[0].whole.should eq "{{% shortcode %}}blah {{% /shortcode %}}"
    result.shortcodes[0].data.should eq "blah "
  end

  it "should parse shortcode args" do
    input = "foobar {{% shortcode foo \"bar\" 42 bat=v1 baz=\"v2\" %}}blah"
    result = parse(input)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "shortcode"
    result.shortcodes[0].matching.should eq 0
    result.shortcodes[0].args.size.should eq 5
    result.shortcodes[0].args[0].name.should eq ""
    result.shortcodes[0].args[0].value.should eq "foo"
    result.shortcodes[0].args[1].name.should eq ""
    result.shortcodes[0].args[1].value.should eq "bar"
    result.shortcodes[0].args[2].name.should eq ""
    result.shortcodes[0].args[2].value.should eq "42"
    result.shortcodes[0].args[3].name.should eq "bat"
    result.shortcodes[0].args[3].value.should eq "v1"
    result.shortcodes[0].args[4].name.should eq "baz"
    result.shortcodes[0].args[4].value.should eq "v2"
    result.shortcodes[0].whole.should eq "{{% shortcode foo \"bar\" 42 bat=v1 baz=\"v2\" %}}"
  end


  # // BUG?
  # // Ensure(parse, escaped_shortcode)
  # // {
  # //     char *input = "foobar \\{{% shortcode %}}";
  # //     result = parse(input);
  # //     // No shortcodes
  # //     assert_that(result.sc[0].name.len, is_equal_to(0));
  # // }
end
