require "./spec_helper"

describe "Shortcodes" do
  # TODO: Write tests

  it "works" do
    result = Shortcodes.parse("foo{{% bar %}}baz{{% /bar %}}qux");
    p! result.sccount;
    p! result.shortcodes[0].matching;
  end
end
