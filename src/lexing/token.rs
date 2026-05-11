use std::convert::Into;
use std::convert::TryFrom;
use std::fmt::Display;
use std::string::ToString;

pub enum Token {
    Documentation(String),
    Constant { name: String, value: Expression },
}

impl Display for Token {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "unimplemented")
    }
}

pub struct Expression {
    //
}

pub enum Keyword {
    Function,              // fn
    Pipe,                  // pipe
    Const,                 // const
    New,                   // new
    Into,                  // into
    Reference,             // ref
    Mutable,               // mut
    Locked,                // locked
    Readable,              // readable
    Writable,              // writable
    Rlock,                 // rlock
    Wlock,                 // wlock
    Unlock,                // unlock
    Maybe,                 // maybe
    Failing,               // failing
    Noerror,               // noerror
    Public,                // pub
    Private,               // private
    Nothing,               // nothing
    Interface,             // interface
    Impl,                  // impl
    Use,                   // use
    Comment,               // // or //// or more (3 reserved for coumentation)
    Documentation,         // ==== (bounded on both sides)
    MultilineCommentStart, // /*
    MultilineCommentEnd,   // */
}

impl TryFrom<&str> for Keyword {
    // The error is always "this string is not a keword" so it can be empty.
    type Error = ();

    fn try_from(value: &str) -> Result<Self, Self::Error> {
        Ok(match value {
            "fn" => Keyword::Function,
            "pipe" => Keyword::Pipe,
            "const" => Keyword::Const,
            "new" => Keyword::New,
            "into" => Keyword::Into,
            "ref" => Keyword::Reference,
            "mut" => Keyword::Mutable,
            "locked" => Keyword::Locked,
            "readable" => Keyword::Readable,
            "writable" => Keyword::Writable,
            "rlock" => Keyword::Rlock,
            "wlock" => Keyword::Wlock,
            "unlock" => Keyword::Unlock,
            "maybe" => Keyword::Maybe,
            "failing" => Keyword::Failing,
            "noerror" => Keyword::Noerror,
            "pub" => Keyword::Public,
            "private" => Keyword::Private,
            "nothing" => Keyword::Nothing,
            "interface" => Keyword::Interface,
            "impl" => Keyword::Impl,
            "use" => Keyword::Use,
            "====" => Keyword::Documentation,
            "/*" => Keyword::MultilineCommentStart,
            "*/" => Keyword::MultilineCommentEnd,
            cmt if cmt.chars().all(|c| c == '/') && (cmt.len() == 2 || cmt.len() > 3) => {
                Keyword::Comment
            }
            _ => return Err(()),
        })
    }
}

pub enum Brackets {
    LeftParen,    // (
    RightParen,   // )
    LeftBracket,  // [
    RightBracket, // ]
    LeftBrace,    // {
    RightBrace,   // }
    LeftChevron,  // <
    RightChevron, // >
}

pub enum Symbol {
    Dot,       // .
    Comma,     // ,
    Colon,     // :
    Semicolon, // ;
    Newlinee,  // \n
}

pub enum Strings {
    SingleQuote, // '
    DoubleQuote, // "
    Grave,       // `
}

pub enum Maths {
    Equals,       // =
    EqualsEquals, // ==
    Plus,         // +
    Minus,        // -
    Times,        // *
    Divide,       // /
    Mod,          // %
}

pub enum BoolOperand {
    True,    // true
    False,   // false
    NotWord, // not
    NotMark, // !
    AndWord, // and
    AndMark, // &&
}

pub enum Access {
    FieldValue,  // .
    FieldObject, // =>
    Package,     // :
    ChillPipe,   // |
    GrabbyPIpe,  // |>
}

pub enum TypeAnnotation {
    Mut,
    Ref,
    Locked,
    Writable,
    Readable,
    Into,
    Iterated,
    Maybe,
    Failing,
    Expanding,
}

impl TryFrom<&str> for TypeAnnotation {
    type Error = ();

    fn try_from(value: &str) -> Result<Self, Self::Error> {
        use TypeAnnotation::*;
        Ok(match value {
            "mut" | "*" => Mut,
            "ref" | "&" => Ref,
            "locked" | "#" => Locked,
            "writable" | "." => Writable,
            "readable" | "~" => Readable,
            "into" | "=" => Into,
            "iterated" | ">" => Iterated,
            "maybe" | "?" => Maybe,
            "failing" | "!" => Failing,
            "expand" | "+" => Expanding,

            _ => return Err(()),
        })
    }
}
