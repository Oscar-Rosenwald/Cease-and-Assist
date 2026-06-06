use std::convert::TryFrom;
use std::string::ToString;

use crate::common::file;

/// A token is a lexicographical unit of the parsed text. Any meaningful symbol
/// or group of symbols are represented via a token. A source file is read into
/// a series of tokens. No type checking or validity is performed except to
/// ensure that multi-word tokens (such as strings) are terminated.
#[derive(Clone)]
pub struct Token {
    /// What kind of token is this, plus the value of it.
    pub type_: TokenType,
    /// Where does the token begin in the file?
    pub start_location: file::Location,
    /// Where does the token end in the file?
    pub end_location: file::Location,
}

/*
TODO: remove when no longer using.

    match  {
        TokenType::Newline => todo!(),
        TokenType::EndOfFile => todo!(),
        TokenType::WordSeparator(separator) => todo!(),
        TokenType::Symbol(symbol) => todo!(),
        TokenType::String(sentense) => todo!(),
        TokenType::Char(char) => todo!(),
        TokenType::Number(number) => todo!(),
        TokenType::DecimalNumber(base, rest) => todo!(),
        TokenType::Documentation(doc) => todo!(),
        TokenType::Keyword(keyword) => todo!(),
        TokenType::Literal(literal) => todo!(),
    }
 */

#[derive(Clone, Debug, PartialEq, Eq)]
pub enum TokenType {
    /// We'll only ever have one newline in a row.
    Newline,
    /// Duh.
    EndOfFile,
    /// A character which breaks up a word, like ':' or '-' or '('. Not a space.
    /// Some character groups such as -> are treated as a single token, and
    /// aren't WordSeparators.
    WordSeparator(WordSeparator),
    /// A hard-coded series of [`WordSeparator`]s which, in a given order and no
    /// whitespace, have semantic meaning. E.g. -> or ==.
    Symbol(Symbol),
    /// Anything surrounded by ""
    String(String),
    /// Anything surrounded by ''.
    Char(char),
    /// A numeric entity with no decimals.
    Number(u32),
    /// A number and the decimals.
    DecimalNumber(u32, u32),
    /// Block of text surrounded by lines with '====' on a line
    Documentation(String),
    Keyword(Keyword),
    /// Names of things: variables, functions, etc.
    Literal(String),
}

impl Default for TokenType {
    fn default() -> Self {
        Self::Newline
    }
}

impl Token {
    pub fn new(
        type_: TokenType,
        start_location: file::Location,
        end_location: file::Location,
    ) -> Self {
        Self {
            type_,
            start_location,
            end_location,
        }
    }

    /// Turns the token into a string which is fit for debugging purposes.
    pub fn to_debug_string(&self) -> String {
        match &self.type_ {
            TokenType::Newline => format!("newline: {}", self.start_location),
            TokenType::EndOfFile => format!("EOF"),
            TokenType::WordSeparator(separator) => {
                format!(
                    "separator: {} {}",
                    self.start_location,
                    separator.to_string()
                )
            }
            TokenType::String(sentense) => {
                format!(
                    r#"string: {} "{}""#,
                    self.start_location,
                    sentense.to_string()
                )
            }
            TokenType::Char(character) => {
                format!("char: {} '{}'", self.start_location, character.to_string())
            }
            TokenType::Number(number) => format!("num: {} {number}", self.start_location),
            TokenType::DecimalNumber(base, decimal) => {
                format!("num: {} {base}.{decimal}", self.start_location)
            }
            TokenType::Documentation(doc) => {
                format!("docs: {} {}", self.start_location, doc.to_string())
            }
            TokenType::Keyword(keyword) => {
                format!("keyword: {} {}", self.start_location, keyword.to_string())
            }
            TokenType::Literal(literal) => {
                format!("literal: {} {}", self.start_location, literal.to_string())
            }
            TokenType::Symbol(symbol) => {
                format!("symbol: {} {}", self.start_location, symbol.to_string())
            }
        }
    }
}

impl TokenType {
    pub fn is_whitespace(&self) -> bool {
        match self {
            TokenType::Newline => true,
            TokenType::EndOfFile => true,
            _ => false,
        }
    }
}

impl ToString for Token {
    fn to_string(&self) -> String {
        match &self.type_ {
            TokenType::Newline => "\\n".to_string(),
            TokenType::EndOfFile => String::from("EOF"),
            TokenType::WordSeparator(separator) => separator.to_string(),
            TokenType::String(sentense) => sentense.to_string(),
            TokenType::Char(character) => character.to_string(),
            TokenType::Number(number) => format!("{number}"),
            TokenType::DecimalNumber(base, decimal) => format!("{base}.{decimal}"),
            TokenType::Documentation(doc) => doc.to_string(),
            TokenType::Keyword(keyword) => keyword.to_string(),
            TokenType::Literal(literal) => literal.to_string(),
            TokenType::Symbol(symbol) => symbol.to_string(),
        }
    }
}

impl ToString for &Token {
    fn to_string(&self) -> String {
        (*self).to_string()
    }
}

/// A word separator is a symbol which, even if it appears in the middle of
/// another token, splits that token. Some groups of word separators become
/// [`Symbol`]s instead.
#[derive(Clone, Debug, PartialEq, Eq)]
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

#[derive(Clone, Debug, PartialEq, Eq)]
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
    Secret,    // sec
    Void,      // void
    Interface, // interface
    Impl,      // impl
    Remote,    // use
    And,       // and
    Or,        // or
    Nand,      // nand
    Xor,       // xor
    Not,       // not
    Return,    // return
    Continue,  // continue
    Break,     // break
    True,      // true
    False,     // false
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
            "sec" => Keyword::Secret,
            "void" => Keyword::Void,
            "interface" => Keyword::Interface,
            "impl" => Keyword::Impl,
            "remote" => Keyword::Remote,
            "and" => Keyword::And,
            "or" => Keyword::Or,
            "nand" => Keyword::Nand,
            "xor" => Keyword::Xor,
            "not" => Keyword::Not,
            "return" => Keyword::Return,
            "continue" => Keyword::Continue,
            "break" => Keyword::Break,
            "true" => Keyword::True,
            "false" => Keyword::False,
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
            Keyword::Secret => "sec",
            Keyword::Void => "void",
            Keyword::Interface => "interface",
            Keyword::Impl => "impl",
            Keyword::Remote => "remote",
            Keyword::Not => "not",
            Keyword::And => "and",
            Keyword::Or => "or",
            Keyword::Nand => "nand",
            Keyword::Xor => "xor",
            Keyword::Return => "return",
            Keyword::Continue => "continue",
            Keyword::Break => "break",
            Keyword::True => "true",
            Keyword::False => "false",
        }
        .to_string()
    }
}

/// For special symbols which, when present without whitespace between them,
/// should be treated as a single token despite being also [`WordSeparator`]s.
/// E.g. == or -> or ++.
#[derive(Clone, Debug, PartialEq, Eq)]
pub enum Symbol {
    PlusPlus,       // ++
    MinusMinus,     // --
    EqualEqual,     // ==
    NotEqual,       // !=
    LessOrEqual,    // <=
    GreaterOrEqual, // >=
    Arrow,          // ->
    DoubleArrow,    // =>
    LessLess,       // <<
    ColonColon,     // ::
    Empty,          // {}
    StarStar,       // **
    GrabbyPipe,     // |>
    And,            // &&
    Or,             // ||
    BitAnd,         // ^&
    BitOr,          // ^|
    DebugPrint,     // ___
}

impl TryFrom<&str> for Symbol {
    type Error = ();

    fn try_from(value: &str) -> Result<Self, ()> {
        Ok(match value {
            "++" => Symbol::PlusPlus,
            "--" => Symbol::MinusMinus,
            "==" => Symbol::EqualEqual,
            "!=" => Symbol::NotEqual,
            "<=" => Symbol::LessOrEqual,
            ">=" => Symbol::GreaterOrEqual,
            "->" => Symbol::Arrow,
            "=>" => Symbol::DoubleArrow,
            "<<" => Symbol::LessLess,
            "::" => Symbol::ColonColon,
            "{}" => Symbol::Empty,
            "**" => Symbol::StarStar,
            "|>" => Symbol::GrabbyPipe,
            "&&" => Symbol::And,
            "||" => Symbol::Or,
            "^&" => Symbol::BitAnd,
            "^|" => Symbol::BitOr,
            "___" => Symbol::DebugPrint,
            _ => return Err(()),
        })
    }
}

impl ToString for Symbol {
    fn to_string(&self) -> String {
        match self {
            Symbol::PlusPlus => "++",
            Symbol::MinusMinus => "--",
            Symbol::EqualEqual => "==",
            Symbol::NotEqual => "!=",
            Symbol::LessOrEqual => "<=",
            Symbol::GreaterOrEqual => ">=",
            Symbol::Arrow => "->",
            Symbol::DoubleArrow => "=>",
            Symbol::LessLess => "<<",
            Symbol::ColonColon => "::",
            Symbol::Empty => "{}",
            Symbol::StarStar => "**",
            Symbol::GrabbyPipe => "|>",
            Symbol::And => "&&",
            Symbol::Or => "||",
            Symbol::BitAnd => "^&",
            Symbol::BitOr => "^|",
            Symbol::DebugPrint => "___",
        }
        .to_string()
    }
}
