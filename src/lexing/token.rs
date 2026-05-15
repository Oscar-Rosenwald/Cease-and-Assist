use std::convert::TryFrom;
use std::string::ToString;

use crate::common::file;

pub const STRING_BOUNDRY: char = '"';
pub const CHAR_BOUNDRY: char = '\'';

pub struct Token {
    pub type_: TokenType,
    pub location: file::Location,
}

#[derive(PartialEq, Eq)]
pub enum TokenType {
    Newline,                      // \n
    WordSeparator(WordSeparator), // A character which breaks up a word, like ':' or '-' or '('. Not a space.
    String(String),               // Anything surrounded by ""
    Char(String), // Anything surrounded by ''. Is a string because error checking of this sort happens later.
    Number(u32),
    Documentation(String), // Block of text surrounded by lines with '===='
    Keyword(Keyword),      // fn and the like
    Literal(String),       // Anything else
}

impl Token {
    pub(super) fn new(type_: TokenType, location: file::Location) -> Self {
        Self { type_, location }
    }

    pub fn to_debug_string(&self) -> String {
        match &self.type_ {
            TokenType::Newline => format!("newline: {}", self.location),
            TokenType::WordSeparator(separator) => {
                format!("separator: {} {}", self.location, separator.to_string())
            }
            TokenType::String(sentense) => {
                format!(r#"string: {} "{}""#, self.location, sentense.to_string())
            }
            TokenType::Char(character) => {
                format!("char: {} '{}'", self.location, character.to_string())
            }
            TokenType::Number(number) => format!("num: {} {number}", self.location),
            TokenType::Documentation(doc) => format!("docs: {} {}", self.location, doc.to_string()),
            TokenType::Keyword(keyword) => {
                format!("keyword: {} {}", self.location, keyword.to_string())
            }
            TokenType::Literal(literal) => {
                format!("literal: {} {}", self.location, literal.to_string())
            }
        }
    }
}

impl ToString for Token {
    fn to_string(&self) -> String {
        match &self.type_ {
            TokenType::Newline => "\n".to_string(),
            TokenType::WordSeparator(separator) => separator.to_string(),
            TokenType::String(sentense) => sentense.to_string(),
            TokenType::Char(character) => character.to_string(),
            TokenType::Number(number) => format!("{number}"),
            TokenType::Documentation(doc) => doc.to_string(),
            TokenType::Keyword(keyword) => keyword.to_string(),
            TokenType::Literal(literal) => literal.to_string(),
        }
    }
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

#[derive(PartialEq, Eq)]
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
    Public,    // pub
    Private,   // private
    Void,      // void
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
            "pub" => Keyword::Public,
            "private" => Keyword::Private,
            "void" => Keyword::Void,
            "interface" => Keyword::Interface,
            "impl" => Keyword::Impl,
            "use" => Keyword::Use,
            _ => return Err(()),
        })
    }
}

impl ToString for Keyword {
    fn to_string(&self) -> String {
        match self {
            Keyword::Function => "fn",
            Keyword::Pipe => "pipe",
            Keyword::Const => "const",
            Keyword::New => "new",
            Keyword::Into => "into",
            Keyword::Reference => "ref",
            Keyword::Mutable => "mut",
            Keyword::Locked => "locked",
            Keyword::Readable => "readable",
            Keyword::Writable => "writable",
            Keyword::Rlock => "rlock",
            Keyword::Wlock => "wlock",
            Keyword::Unlock => "unlock",
            Keyword::Maybe => "maybe",
            Keyword::Failing => "failing",
            Keyword::Public => "pub",
            Keyword::Private => "private",
            Keyword::Void => "void",
            Keyword::Interface => "interface",
            Keyword::Impl => "impl",
            Keyword::Use => "use",
        }
        .to_string()
    }
}
