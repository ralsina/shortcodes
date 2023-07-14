@[Link(ldflags: "#{__DIR__}/../shortcodes.o")]
lib Shortcodes

  struct Chunk
    start : UInt32
    len : UInt32
  end

  struct ScError
    position: UInt32
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

  fun parse(input : Pointer(LibC::Char)) : ScResult;
end