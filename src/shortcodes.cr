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
    whole : Chunk
    name : Chunk
    data : Chunk
    matching : LibC::Char
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

  struct Shortcode
    property name : String = ""
    property data : String = ""
    property matching : Int32 = 0
    property args : Array(Arg) = [] of Arg

    def initialize(@name, @data, @matching, @args)
    end
  end

  struct Result
    property shortcodes : Array(Shortcode) = [] of Shortcode
  end

  def extract(c : LibShortcodes::Chunk, s : String)
    s[c.start, c.len]
  end

  def parse(input : String)
    r = LibShortcodes.parse(input.to_unsafe, input.bytesize)
    result = Result.new
    p! r.sccount

    (0...r.sccount).each do |i|
      sc = r.shortcodes[i]
      args = [] of Arg
      (0...sc.argcount).each do |j|
        args << Arg.new(
          extract(sc.argnames[j], input),
          extract(sc.argvals[j], input),
        )
      end
      result.shortcodes << Shortcode.new(
        extract(sc.name, input),
        extract(sc.data, input),
        sc.matching,
        args,
      )
    end
    result
  end
end
