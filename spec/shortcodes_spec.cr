require "./spec_helper"

def sanity_check(input : String, result : Shortcodes::Result)
  result.shortcodes.each do |scode|
    input[scode.position, scode.whole.size].should eq scode.whole
  end
end

describe "Shortcodes" do
  it "should parse empty string" do
    result = Shortcodes.parse("")
    result.shortcodes.size.should eq 0
    result.errors.size.should eq 0
  end

  it "should parse simple shortcode" do
    input = "foobar {{% shortcode %}}blah"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    sc = result.shortcodes[0]
    sc.name.should eq "shortcode"
    sc.matching?.should be_false
    sc.is_inline?.should be_false
    sc.args.size.should eq 0
    sc.whole.should eq "{{% shortcode %}}"
  end

  it "should parse simple shortcode with . and / in the name" do
    input = "foobar {{% shortcode.foo/bar %}}blah"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "shortcode.foo/bar"
    result.shortcodes[0].matching?.should be_false
    result.shortcodes[0].is_inline?.should be_false
    result.shortcodes[0].args.size.should eq 0
    result.shortcodes[0].whole.should eq "{{% shortcode.foo/bar %}}"
  end

  it "should report mismatched tags" do
    input = "foobar {{% shortcode %}}blah{{% /foo %}}"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 1
    result.errors[0].code.should eq Shortcodes::ERR_MISMATCHED_CLOSING_TAG
    input[result.errors[0].position, 8].should eq "{{% /foo"
  end

  it "should report mismatched brackets" do
    input = "foobar {{% shortcode >}}blah"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.shortcodes.size.should eq 0
    result.errors.size.should eq 1
    result.errors[0].code.should eq Shortcodes::ERR_MISMATCHED_BRACKET
    Shortcodes.nice_error(result.errors[0], input).should eq <<-ERROR
      Error in line 1, column 22
        Mismatched closing bracket style
        foobar {{% shortcode >}}blah
        #{" " * 21}⬆️ HERE
      ERROR
    input[result.errors[0].position, 3].should eq ">}}"
  end

  it "should accept mismatched brackets inside data are ok" do
    input = "foobar {{% sc %}} >}}blah {{% /sc %}} "
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].whole.should eq "{{% sc %}} >}}blah {{% /sc %}}"
    result.shortcodes[0].data.should eq " >}}blah "
    result.shortcodes[0].args.size.should eq 0
  end

  it "should accept mismatched brackets in qvals" do
    input = "foobar {{% sc  \">}}blah\" %}} {{% /sc %}}"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].whole.should eq "{{% sc  \">}}blah\" %}} {{% /sc %}}"
    result.shortcodes[0].args.size.should eq 1
    result.shortcodes[0].args[0].@value.should eq ">}}blah"
  end

  it "should consider spaces in shortcodes optional" do
    input = "foobar {{%    shortcode%}}blah"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
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
    sanity_check(input, result)
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
    sanity_check(input, result)
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
    sanity_check(input, result)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "shortcode"
    result.shortcodes[0].matching?.should be_true
    result.shortcodes[0].is_inline?.should be_false
    result.shortcodes[0].args.size.should eq 0
    result.shortcodes[0].whole.should eq "{{% shortcode %}}blah {{% /shortcode %}}"
    result.shortcodes[0].data.should eq "blah "
  end

  it "should parse matching shortcodes with names containing . and /" do
    input = "foobar {{% shortcode.foo/bar %}}blah {{% /shortcode.foo/bar %}} blah"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "shortcode.foo/bar"
    result.shortcodes[0].matching?.should be_true
    result.shortcodes[0].args.size.should eq 0
    result.shortcodes[0].data.should eq "blah "
  end

  it "should parse quoted arg" do
    input = "foobar {{% shortcode \"bar\" %}}blah"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "shortcode"
    result.shortcodes[0].matching?.should be_false
    result.shortcodes[0].args.size.should eq 1
    result.shortcodes[0].args[0].name.should eq ""
    result.shortcodes[0].args[0].value.should eq "bar"
  end

  it "should parse quoted arg with escaped quote" do
    input = "foobar {{% shortcode 'ba\\'r' %}}blah"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "shortcode"
    result.shortcodes[0].matching?.should be_false
    result.shortcodes[0].args.size.should eq 1
    result.shortcodes[0].args[0].name.should eq ""
    result.shortcodes[0].args[0].value.should eq "ba'r"
  end

  it "should parse single-quoted arg" do
    input = "foobar {{% shortcode 'bar' %}}blah"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
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
    sanity_check(input, result)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "shortcode"
    result.shortcodes[0].matching?.should be_false
    result.shortcodes[0].args.size.should eq 1
    result.shortcodes[0].args[0].name.should eq ""
    result.shortcodes[0].args[0].value.should eq "bar"
  end

  # Every punctuation character allowed in unquoted values, in every
  # position it can legally appear (leading, middle, trailing)
  unquoted_values = [
    "-42",
    "_x",
    ".hidden",
    "~x",
    "+1",
    "#tag",
    ":def",
    "@user",
    "42",
    "x",
    "x_",
    "end.",
    "x~",
    "x#",
    "x:",
    "a-b",
    "a//b",
    "a-b_c.d:e@f+g~h#i/j",
    "https://example.com/page#anchor",
  ]

  unquoted_values.each do |value|
    it "should parse unquoted positional value #{value.inspect}" do
      input = "foobar {{% shortcode #{value} %}}blah"
      result = Shortcodes.parse(input)
      sanity_check(input, result)
      result.shortcodes.size.should eq 1
      result.errors.size.should eq 0
      result.shortcodes[0].name.should eq "shortcode"
      result.shortcodes[0].matching?.should be_false
      result.shortcodes[0].args.size.should eq 1
      result.shortcodes[0].args[0].name.should eq ""
      result.shortcodes[0].args[0].value.should eq value
    end

    it "should parse unquoted named arg v=#{value.inspect}" do
      input = "foobar {{% shortcode v=#{value} %}}blah"
      result = Shortcodes.parse(input)
      sanity_check(input, result)
      result.shortcodes.size.should eq 1
      result.errors.size.should eq 0
      result.shortcodes[0].name.should eq "shortcode"
      result.shortcodes[0].matching?.should be_false
      result.shortcodes[0].args.size.should eq 1
      result.shortcodes[0].args[0].name.should eq "v"
      result.shortcodes[0].args[0].value.should eq value
    end
  end

  it "should parse multiple unquoted args mixed with named ones" do
    input = "foobar {{% shortcode one two=2 three/four -5 %}}blah"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].args.size.should eq 4
    result.shortcodes[0].args[0].name.should eq ""
    result.shortcodes[0].args[0].value.should eq "one"
    result.shortcodes[0].args[1].name.should eq "two"
    result.shortcodes[0].args[1].value.should eq "2"
    result.shortcodes[0].args[2].name.should eq ""
    result.shortcodes[0].args[2].value.should eq "three/four"
    result.shortcodes[0].args[3].name.should eq ""
    result.shortcodes[0].args[3].value.should eq "-5"
  end

  # Ambiguous unquoted values are rejected instead of misparsed
  it "should reject an unquoted value with a trailing slash" do
    input = "foobar {{% shortcode path=dir/ %}}blah"
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 0
    result.errors.size.should eq 0
  end

  it "should reject an unquoted value containing =" do
    input = "foobar {{% shortcode a=b=c %}}blah"
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 0
  end

  it "should reject an unquoted value containing >" do
    input = "foobar {{% shortcode a>b %}}blah"
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 0
  end

  it "should reject an unquoted value with non-ascii characters" do
    input = "foobar {{% shortcode café %}}blah"
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 0
  end

  it "should reject an unquoted value containing a backslash" do
    input = "foobar {{% shortcode a\\b %}}blah"
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 0
  end

  it "should parse quoted arg with trailing slash" do
    input = "foobar {{% shortcode path=\"dir/\" %}}blah"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].args.size.should eq 1
    result.shortcodes[0].args[0].name.should eq "path"
    result.shortcodes[0].args[0].value.should eq "dir/"
  end

  it "should not absorb a trailing slash into an unquoted value" do
    input = "foobar {{% shortcode foo/%}}blah"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].args.size.should eq 1
    result.shortcodes[0].args[0].name.should eq ""
    result.shortcodes[0].args[0].value.should eq "foo"
    result.shortcodes[0].self_closing?.should be_true
  end

  it "should parse named arg" do
    input = "foobar {{% shortcode foo=bar %}}blah"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
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
    sanity_check(input, result)
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
    sanity_check(input, result)
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
    input = %({{% raw %}}{{< foobarbat >}}{{% /raw %}})
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "raw"
    result.shortcodes[0].matching?.should be_true
    result.shortcodes[0].data.should eq "{{< foobarbat >}}"
  end

  it "should ignore nested shortcodes with inner inline" do
    input = "\n      {{< raw >}}{{% foo.inline %}}{{% /foo.inline %}}{{< /raw >}}\n    "
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "raw"
    result.shortcodes[0].matching?.should be_true
    result.shortcodes[0].data.should eq "{{% foo.inline %}}{{% /foo.inline %}}"
  end

  it "should ignore nested matching shortcodes" do
    input = %({{< raw >}}{{%heading%}}inner{{%/heading%}}{{< /raw >}})
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].name.should eq "raw"
    result.shortcodes[0].matching?.should be_true
    result.shortcodes[0].data.should eq "{{%heading%}}inner{{%/heading%}}"
  end

  it "should handle unicode" do
    input = "áé😃"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.shortcodes.size.should eq 0
    result.errors.size.should eq 0
  end

  it "should handle unicode outside the shortcode" do
    input = "áé😃{{% foo %}}áé😃"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].whole.should eq "{{% foo %}}"
  end

  it "should handle unicode data" do
    input = "{{% foo %}}áé😃{{%/foo%}}"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    result.shortcodes[0].data.should eq "áé😃"
  end

  it "should handle unicode qvals" do
    input = "{{% foo arg=\"áé😃\" \"😅😅😅\" %}}áé😃{{%/foo%}}"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.shortcodes.size.should eq 1
    result.errors.size.should eq 0
    sc = result.shortcodes[0]
    sc.args.size.should eq 2
    sc.args[0].value.should eq "áé😃"
    sc.args[1].value.should eq "😅😅😅"
    input[sc.position...sc.position + sc.whole.size].should eq sc.whole
  end

  it "should only mark as markdown if it ends with %}}" do
    input = "{{% foo %}} {{< bar >}}"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.shortcodes.size.should eq 2
    result.errors.size.should eq 0
    result.shortcodes[0].markdown?.should be_true
    result.shortcodes[1].markdown?.should be_false
  end

  it "should not mush similar shortcodes" do
    input = "{{%h%}}1{{%/h%}} {{%h%}}2{{%/h%}}"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.errors.size.should eq 0
    result.shortcodes[0].data.should eq "1"
    result.shortcodes[1].data.should eq "2"
    result.shortcodes.size.should eq 2
  end

  it "should handle nested similar shortcodes" do
    input = "{{% raw %}}{{% raw %}}inner{{% /raw %}}{{% /raw %}}"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.errors.size.should eq 0
    result.shortcodes.size.should eq 1
    result.shortcodes[0].matching?.should be_true
    result.shortcodes[0].data.should eq "{{% raw %}}inner{{% /raw %}}"
  end

  it "should mark shortcodes as inline" do
    input = "{{< time.inline >}}{{ now }}{{< /time.inline >}}"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.errors.size.should eq 0
    result.shortcodes.size.should eq 1
    result.shortcodes[0].is_inline?.should be_true
    result.shortcodes[0].data.should eq "{{ now }}"
  end

  it "should mark shortcodes as self-closing" do
    input = "{{< innershortcode />}}"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.errors.size.should eq 0
    result.shortcodes.size.should eq 1
    result.shortcodes[0].self_closing?.should be_true
  end

  it "should mark shortcodes as escaped" do
    input = "{{</* foobar */>}}"
    result = Shortcodes.parse(input)
    sanity_check(input, result)
    result.errors.size.should eq 0
    result.shortcodes.size.should eq 1
    result.shortcodes[0].escaped?.should be_true
  end

  it "should report an error instead of overflowing past 100 shortcodes" do
    input = "{{% foo %}}" * 101
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 100
    result.errors.size.should eq 1
    result.errors[0].code.should eq Shortcodes::ERR_TOO_MANY_SHORTCODES
  end

  it "should report an error instead of overflowing past 100 args" do
    input = "foobar {{% shortcode #{"a=1 " * 100}a=1 %}}blah"
    result = Shortcodes.parse(input)
    result.shortcodes.size.should eq 1
    result.shortcodes[0].args.size.should eq 100
    # The 100th arg keeps its recorded value, later args don't mutate it
    result.shortcodes[0].args[99].name.should eq "a"
    result.shortcodes[0].args[99].value.should eq "1"
    result.errors.size.should eq 1
    result.errors[0].code.should eq Shortcodes::ERR_TOO_MANY_ARGS
  end

  it "should handle unknown error codes in nice_error" do
    error = Shortcodes::Error.new(0, 99)
    Shortcodes.nice_error(error, "irrelevant").should contain "Unknown error code 99"
  end

  it "should report codepoint columns in nice_error" do
    # á(2 bytes) é(2 bytes) 😃(4 bytes) so the error's byte position is
    # 8 bytes higher than its codepoint column
    input = "áé😃 {{% sc >}}"
    result = Shortcodes.parse(input)
    result.errors.size.should eq 1
    Shortcodes.nice_error(result.errors[0], input).should eq <<-ERROR
      Error in line 1, column 12
        Mismatched closing bracket style
        áé😃 {{% sc >}}
        #{" " * 11}⬆️ HERE
      ERROR
  end

  it "should report codepoint columns on later lines too" do
    input = "áé😃\n{{% sc >}}"
    result = Shortcodes.parse(input)
    result.errors.size.should eq 1
    Shortcodes.nice_error(result.errors[0], input).should contain "Error in line 2, column 8"
  end
end
