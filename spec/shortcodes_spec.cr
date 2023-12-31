require "./spec_helper"

describe "Shortcodes" do
  it "should parse empty string" do
    result = Shortcodes.parse("")
    result.shortcodes.size.should eq 0
    result.errors.size.should eq 0
  end

  it "should parse simeple shortcode" do
    result = Shortcodes.parse("foobar {{% shortcode %}}blah")
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "shortcode"
    result.shortcodes[0].matching?.should be_false
    result.shortcodes[0].args.size.should eq 0
    result.shortcodes[0].whole.should eq "{{% shortcode %}}"
  end

  it "should report mismatched tags" do
    input = "foobar {{% shortcode %}}blah{{% /foo %}}"
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 1
    result.errors[0].code.should eq Shortcodes::ERR_MISMATCHED_CLOSING_TAG
    input[result.errors[0].position, 8].should eq "{{% /foo"
  end

  it "should report mismatched brackets" do
    input = "foobar {{% shortcode >}}blah"
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 0
    result.errors.size.should eq 1
    result.errors[0].code.should eq Shortcodes::ERR_MISMATCHED_BRACKET
    Shortcodes.nice_error(result.errors[0], input).should eq \
      "Error in line 1, column 22\n" +
      "  Mismatched closing bracket style\n" +
      "  foobar {{% shortcode >}}blah\n" +
      "                       ⬆️ HERE"
    input[result.errors[0].position, 3].should eq ">}}"
  end

  it "should accept mismatched brackets inside data are ok" do
    input = "foobar {{% sc %}} >}}blah {{% /sc %}} "
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].whole.should eq "{{% sc %}} >}}blah {{% /sc %}}"
    result.shortcodes[0].data.should eq " >}}blah "
    result.shortcodes[0].args.size.should eq 0
  end

  it "should accept mismatched brackets in qvals" do
    input = "foobar {{% sc  \">}}blah\" %}} {{% /sc %}}"
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].whole.should eq "{{% sc  \">}}blah\" %}} {{% /sc %}}"
    result.shortcodes[0].args.size.should eq 1
    result.shortcodes[0].args[0].@value.should eq ">}}blah"
  end

  it "should consider spaces in shortcodes optional" do
    input = "foobar {{%    shortcode%}}blah"
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "shortcode"
    result.shortcodes[0].matching?.should be_false
    result.shortcodes[0].args.size.should eq 0
    result.shortcodes[0].whole.should eq "{{%    shortcode%}}"
  end

  it "should allow path-like names" do
    input = "foobar {{% shortcode/foo/bar %}}blah"
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "shortcode/foo/bar"
    result.shortcodes[0].matching?.should be_false
    result.shortcodes[0].args.size.should eq 0
    result.shortcodes[0].whole.should eq "{{% shortcode/foo/bar %}}"
  end

  it "should parse multiple shortcodes" do
    input = "foobar {{% shortcode %}}blah {{<sc2 >}}blahblah"
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 2
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "shortcode"
    result.shortcodes[0].matching?.should be_false
    result.shortcodes[0].args.size.should eq 0
    result.shortcodes[0].whole.should eq "{{% shortcode %}}"
    result.shortcodes[1].name.should eq "sc2"
    result.shortcodes[1].matching?.should be_false
    result.shortcodes[1].args.size.should eq 0
    result.shortcodes[1].whole.should eq "{{<sc2 >}}"
  end

  it "should parse matching shortcodes" do
    input = "foobar {{% shortcode %}}blah {{% /shortcode %}} blah"
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "shortcode"
    result.shortcodes[0].matching?.should be_true
    result.shortcodes[0].args.size.should eq 0
    result.shortcodes[0].whole.should eq "{{% shortcode %}}blah {{% /shortcode %}}"
    result.shortcodes[0].data.should eq "blah "
  end

  it "should parse quoted arg" do
    input = "foobar {{% shortcode \"bar\" %}}blah"
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "shortcode"
    result.shortcodes[0].matching?.should be_false
    result.shortcodes[0].args.size.should eq 1
    result.shortcodes[0].args[0].name.should eq ""
    result.shortcodes[0].args[0].value.should eq "bar"
  end

  it "should parse unquoted arg" do
    input = "foobar {{% shortcode bar %}}blah"
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "shortcode"
    result.shortcodes[0].matching?.should be_false
    result.shortcodes[0].args.size.should eq 1
    result.shortcodes[0].args[0].name.should eq ""
    result.shortcodes[0].args[0].value.should eq "bar"
  end

  it "should parse named arg" do
    input = "foobar {{% shortcode foo=bar %}}blah"
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "shortcode"
    result.shortcodes[0].matching?.should be_false
    result.shortcodes[0].args.size.should eq 1
    result.shortcodes[0].args[0].name.should eq "foo"
    result.shortcodes[0].args[0].value.should eq "bar"
  end

  it "should parse named, quoted arg" do
    input = "foobar {{% shortcode foo=\"bar\" %}}blah"
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "shortcode"
    result.shortcodes[0].matching?.should be_false
    result.shortcodes[0].args.size.should eq 1
    result.shortcodes[0].args[0].name.should eq "foo"
    result.shortcodes[0].args[0].value.should eq "bar"
  end

  it "should parse multiple shortcode args" do
    input = "foobar {{% shortcode foo \"bar\" 42 bat=v1 baz=\"v2\" %}}blah"
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "shortcode"
    result.shortcodes[0].matching?.should be_false
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

  it "should ignore nested shortcodes" do
    input = %({{% raw %}}{{% figure %}}{{% /raw %}})
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "raw"
    result.shortcodes[0].matching?.should be_true
    result.shortcodes[0].data.should eq "{{% figure %}}"
  end

  it "should ignore nested matching shortcodes" do
    input = %({{< raw >}}{{%heading%}}inner{{%/heading%}}{{< /raw >}})
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "raw"
    result.shortcodes[0].matching?.should be_true
    result.shortcodes[0].data.should eq "{{%heading%}}inner{{%/heading%}}"
  end

  it "should handle unicode" do
    input = "áé😃"
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 0
    result.errors.size.should eq 0
  end

  it "should handle unicode outside the shortcode" do
    input = "áé😃{{% foo %}}áé😃"
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].whole.should eq "{{% foo %}}"
  end

  it "should handle unicode data" do
    input = "{{% foo %}}áé😃{{%/foo%}}"
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].data.should eq "áé😃"
  end

  it "should handle unicode qvals" do
    input = "{{% foo arg=\"áé😃\" \"😅😅😅\" %}}"
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].args.size.should eq 2
    result.shortcodes[0].args[0].value.should eq "áé😃"
    result.shortcodes[0].args[1].value.should eq "😅😅😅"
  end

  it "should only mark as markdown if it ends with %}}" do
    input = "{{% foo %}} {{< bar >}}"
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 2
    result.errors.size.should eq 0
    result.shortcodes[0].markdown?.should be_true
    result.shortcodes[1].markdown?.should be_false
  end

  it "should not mush similar shortcodes" do
    input = "{{%h%}}1{{%/h%}} {{%h%}}2{{%/h%}}"
    result = Shortcodes.parse(input)
    result.errors.size.should eq 0
    result.shortcodes[0].data.should eq "1"
    result.shortcodes[1].data.should eq "2"
    result.shortcodes.size.should eq 2
  end

  it "should handle nested similar shortcodes" do
    input = "{{% raw %}}{{% raw %}}inner{{% /raw %}}{{% /raw %}}"
    result = Shortcodes.parse(input)
    result.errors.size.should eq 0
    result.shortcodes.size.should eq 1
    result.shortcodes[0].matching?.should be_true
    result.shortcodes[0].data.should eq "{{% raw %}}inner{{% /raw %}}"
  end

  # BUG?
  # it "should ignore escaped shortcodes" do
  #   input = "foobar \\{{% shortcode %}}blah"
  #   result = Shortcodes.parse(input)
  #   result.shortcodes.size.should eq 0
  #   result.errors.size.should eq 0
  # end
end
