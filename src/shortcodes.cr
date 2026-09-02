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

  fun parse(input : Pointer(LibC::Char), len : UInt32, result : ScResult*) : Nil
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
      @len,
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

  MESSAGES = {
    ERR_MISMATCHED_BRACKET     => "Mismatched closing bracket style",
    ERR_MISMATCHED_CLOSING_TAG => "Closing shortcode that was never opened",
    ERR_TOO_MANY_SHORTCODES    => "Too many shortcodes in one document (limit 100)",
    ERR_TOO_MANY_ARGS          => "Too many arguments in one shortcode (limit 100)",
  }

  # Counts UTF-8 codepoints in a byte slice without allocating.
  # A codepoint start byte is anything that is not a continuation byte.
  def self.codepoint_count(bytes : Slice(UInt8)) : Int32
    bytes.count { |byte| (byte & 0xC0) != 0x80 }
  end

  def self.nice_error(e : Error, s : String)
    before = s.to_slice[0, e.position]
    line = before.count(0x0A.to_u8)
    # Columns count codepoints, not bytes: the offset from the last
    # newline (or the start of the input) to the error position.
    line_start = (before.rindex(0x0A.to_u8) || -1) + 1
    column = codepoint_count(before[line_start..])
    error_line = s.split('\n')[line]
    msg = MESSAGES[e.code]? || "Unknown error code #{e.code}"
    <<-ERROR
      Error in line #{line + 1}, column #{column + 1}
        #{msg}
        #{error_line}
        #{" " * column}⬆️ HERE
      ERROR
  end

  def self.parse(input : String)
    # The parsed result is written into a pre-allocated struct instead of
    # being returned by value (~160KB), which optimizing compilers handle
    # pathologically (see parse in shortcodes.rl). It is zeroed on the C
    # side, so `uninitialized` is safe here (and `.new` would be slow:
    # zero-initializing this struct is pathological for LLVM, too).
    r = uninitialized LibShortcodes::ScResult
    LibShortcodes.parse(input.to_unsafe, input.bytesize, pointerof(r))
    result = Result.new

    (0...r.sccount).each do |i|
      sc = r.shortcodes[i]
      args = [] of Arg
      (0...sc.argcount).each do |j|
        raw_value = extract(sc.argvals[j], input)
        # Only allocate a new string if there is something to unescape
        value = raw_value.includes?('\\') ? raw_value.gsub(/\\([^\\])/, "\\1") : raw_value
        args << Arg.new(
          extract(sc.argnames[j], input),
          value)
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
        codepoint_count(input.to_slice[0, sc.whole.start]),
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

  # There are more than 100 shortcodes in the document.
  # Shortcodes past the limit are dropped.
  ERR_TOO_MANY_SHORTCODES = 3

  # A shortcode has more than 100 arguments.
  # Arguments past the limit are dropped.
  ERR_TOO_MANY_ARGS = 4
end
