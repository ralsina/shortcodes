@[Link(ldflags: "#{__DIR__}/shortcodes.o")]
lib LibShortcodes
  struct Chunk
    start : UInt32
    len : UInt32
  end

  struct ScError
    position : UInt32
    code : UInt32
  end

  struct Shortcode
    closed : LibC::Char
    escaped : LibC::Char
    is_inline : LibC::Char
    markdown : LibC::Char
    matching : LibC::Char
    self_closing : LibC::Char
    whole : Chunk
    name : Chunk
    data : Chunk
    argnames : Chunk[100]
    argvals : Chunk[100]
    argcount : UInt32
  end

  struct ScResult
    shortcodes : Shortcode[100]
    sccount : UInt32
    errors : ScError[10]
    errcount : UInt32
  end

  fun parse(input : Pointer(LibC::Char), len : UInt32) : ScResult
end

module Shortcodes
  struct Arg
    property name : String = ""
    property value : String = ""

    def initialize(@name, @value)
    end
  end

  struct Error
    property position : UInt32
    property code : UInt32

    def initialize(@position, @code)
    end
  end

  struct Shortcode
    property name : String = ""
    property data : String = ""
    property? matching : Bool = false
    property? markdown : Bool = false
    property? is_inline : Bool = false
    property? self_closing : Bool = false
    property? escaped : Bool = false
    property args : Array(Arg) = [] of Arg
    property whole : String = ""
    property position : Int32 = 0
    property len : UInt32 = 0

    def initialize(
      @name,
      @data,
      @matching,
      @markdown,
      @is_inline,
      @self_closing,
      @escaped,
      @args,
      @whole,
      @position,
      @len
    )
    end
  end

  struct Result
    property shortcodes : Array(Shortcode) = [] of Shortcode
    property errors : Array(Error) = [] of Error
  end

  def self.extract(c : LibShortcodes::Chunk, s : String)
    # This is to account for UTF-8 character width
    # because start and end are in bytes, not chars.
    String.new(s.to_slice[c.start, c.len])
  end

  def self.nice_error(e : Error, s : String)
    return "" if e.position.nil?
    line = s[0, e.position].count('\n')
    column = e.position - (s[0, e.position].rindex('\n') || 0)
    error_line = s.split('\n')[line]
    msg = {
      ERR_MISMATCHED_BRACKET     => "Mismatched closing bracket style",
      ERR_MISMATCHED_CLOSING_TAG => "Closing shortcode that was never opened",
    }
    %(Error in line #{line + 1}, column #{column + 1}
  #{msg[e.code]}
  #{error_line}
  #{" "*column + "⬆️ HERE"})
  end

  def self.parse(input : String)
    r = LibShortcodes.parse(input.to_unsafe, input.bytesize)
    result = Result.new

    (0...r.sccount).each do |i|
      sc = r.shortcodes[i]
      args = [] of Arg
      (0...sc.argcount).each do |j|
        args << Arg.new(
          extract(sc.argnames[j], input),
          extract(sc.argvals[j], input).gsub(/\\([^\\])/, "\\1"))
      end

      result.shortcodes << Shortcode.new(
        extract(sc.name, input),
        sc.matching == 1 ? extract(sc.data, input) : "",
        sc.matching == 1,
        sc.markdown == 1,
        sc.is_inline == 1,
        sc.self_closing == 1,
        sc.escaped == 1,
        args,
        extract(sc.whole, input),
        # start is in BYTES, not chars
        String.new(input.to_slice[0, sc.whole.start]).size,
        sc.whole.len,
      )
    end
    (0...r.errcount).each do |k|
      result.errors << Error.new(
        r.errors[k].position,
        r.errors[k].code,
      )
    end
    result
  end

  # ### Error codes
  #
  # You are closing the wrong shortcode.
  # Example:
  # {{% foo %}}  {{% /bar %}}
  ERR_MISMATCHED_CLOSING_TAG = 1

  # You are using mismatched brackets.
  # Example:
  # {{% foo >}}
  ERR_MISMATCHED_BRACKET = 2
end
