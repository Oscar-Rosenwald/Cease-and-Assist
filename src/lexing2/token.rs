use std::convert::TryFrom;
use std::string::ToString;

pub const DOCUMENTATION_TAG: &'static str = "====";
pub const STRING_BOUNDTRY: char = '"';
pub const CHAR_BOUNDRY: char = '\'';

#[derive(PartialEq, Eq)]
pub enum Token {
    Newline,                      // \n
    WordSeparator(WordSeparator), // A character which breaks up a word, like ':' or '-' or '('. Not a space.
    String(String),               // Anything surrounded by ""
    Char(String), // Anything surrounded by ''. Is a string because error checking of this sort happens later.
    Documentation(String), // Block of text surrounded by lines with '===='
    Literal(String), // Anything else
}

#[derive(PartialEq, Eq)]
pub enum WordSeparator {
    Dot,          // .
    Comma,        // ,
    Colon,        // :
    Semicolon,    // ;
    Exclamation,  // !
    Question,     // ?
    LeftParen,    // (
    RightParen,   // )
    LeftChevron,  // <
    RightChevron, // >
    LeftBracket,  // [
    RightBracket, // ]
    LeftBrace,    // {
    RightBrace,   // }
    Plus,         // +
    Minus,        // -
    Star,         // *
    Equal,        // =
    Bar,          // |
    Slash,        // /
    Backslash,    // \
    AndPerSeAnd,  // &
    Dollar,       // $
    Hash,         // #
    At,           // @
    Percent,      // %
    Carrot,       // ^
    Tilda,        // ~
}

impl TryFrom<char> for WordSeparator {
    type Error = ();

    fn try_from(value: char) -> Result<Self, Self::Error> {
        Ok(match value {
            '.' => Self::Dot,
            ',' => Self::Comma,
            ':' => Self::Colon,
            ';' => Self::Semicolon,
            '!' => Self::Exclamation,
            '?' => Self::Question,
            '(' => Self::LeftParen,
            ')' => Self::RightParen,
            '<' => Self::LeftChevron,
            '>' => Self::RightChevron,
            '[' => Self::LeftBracket,
            ']' => Self::RightBracket,
            '{' => Self::LeftBrace,
            '}' => Self::RightBrace,
            '+' => Self::Plus,
            '-' => Self::Minus,
            '*' => Self::Star,
            '=' => Self::Equal,
            '|' => Self::Bar,
            '/' => Self::Slash,
            '\\' => Self::Backslash,
            '&' => Self::AndPerSeAnd,
            '$' => Self::Dollar,
            '#' => Self::Hash,
            '@' => Self::At,
            '%' => Self::Percent,
            '^' => Self::Carrot,
            '~' => Self::Tilda,
            _ => return Err(()),
        })
    }
}

impl ToString for WordSeparator {
    fn to_string(&self) -> String {
        match self {
            Self::Dot => ".",
            Self::Comma => ",",
            Self::Colon => ":",
            Self::Semicolon => ";",
            Self::Exclamation => "!",
            Self::Question => "?",
            Self::LeftParen => "(",
            Self::RightParen => ")",
            Self::LeftChevron => "<",
            Self::RightChevron => ">",
            Self::LeftBracket => "[",
            Self::RightBracket => "]",
            Self::LeftBrace => "{",
            Self::RightBrace => "}",
            Self::Plus => "+",
            Self::Minus => "-",
            Self::Star => "*",
            Self::Equal => "=",
            Self::Bar => "|",
            Self::Slash => "/",
            Self::Backslash => "\\",
            Self::AndPerSeAnd => "&",
            Self::Dollar => "$",
            Self::Hash => "#",
            Self::At => "@",
            Self::Percent => "%",
            Self::Carrot => "^",
            Self::Tilda => "~",
        }
        .to_string()
    }
}

pub(super) enum Quote {
    SingleQuote, // '
    DoubleQuote, // "
    Grave,       // `
}

// TODO used?
impl TryFrom<char> for Quote {
    type Error = ();

    fn try_from(value: char) -> Result<Self, Self::Error> {
        Ok(match value {
            '\'' => Self::SingleQuote,
            '"' => Self::DoubleQuote,
            '`' => Self::Grave,
            _ => return Err(()),
        })
    }
}

impl ToString for Quote {
    fn to_string(&self) -> String {
        match self {
            Self::SingleQuote => "'",
            Self::DoubleQuote => r#"""#,
            Self::Grave => "`",
        }
        .to_string()
    }
}

pub enum Keyword {
    Function,  // fn
    Pipe,      // pipe
    Const,     // const
    New,       // new
    Into,      // into
    Reference, // ref
    Mutable,   // mut
    Locked,    // locked
    Readable,  // readable
    Writable,  // writable
    Rlock,     // rlock
    Wlock,     // wlock
    Unlock,    // unlock
    Maybe,     // maybe
    Failing,   // failing
    Noerror,   // noerror
    Public,    // pub
    Private,   // private
    Nothing,   // nothing
    Interface, // interface
    Impl,      // impl
    Use,       // use
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
            _ => return Err(()),
        })
    }
}
