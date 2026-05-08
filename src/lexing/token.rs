use crate::common::file::*;
use anyhow::{Result, anyhow};
use std::fmt::Display;

const COMMENT_TOKEN: &'static str = "//";
const DOCUMENTATION_TOKEN: &'static str = "///";

#[derive(Debug)]
pub(super) enum TokenType {
    LeftParen,    // (
    RightParen,   // )
    LeftBrace,    // {
    RightBrace,   // }
    LeftSquare,   // [
    RightSquare,  // ]
    LeftChevron,  // <
    RightChevron, // >

    LessEqual,    // <=
    GreaterEqual, // >=

    WindowPipe, // |
    GrabbyPipe, // |>

    ReturnValue,        // ->
    FieldNameAccess,    // =>
    TypePropertyAccess, // :: for enums and associated functions etc.
    PackageAccess,      // :
    FieldAccess,        // .

    Comma,        // ,
    Semicolon,    // ;
    Slash,        // /
    Star,         // *
    Exclamation,  // !
    Hash,         // #
    Percent,      // %
    Tilda,        // ~
    Hat,          // ^
    Dollar,       // $
    Ampersand,    // &
    At,           // @
    Questionmark, // ?
    Underscore,   // _
    Plus,         // +
    Equals,       // =
    Minus,        // -

    AndWord,     // and
    AndSymbol,   // &&
    OrWord,      // or
    OrSymbol,    // ||
    IsEqual,     // ==
    IsDifferent, // !=

    OpenRange,   // ..
    ClosedRange, // ..=

    Number(i64), // Literal numbers, range bounds, parts of float numbers (before and after dot)
    String(String), // String
    LiteralString(String), // `...`
    Literal(String), // Named things (variables, packages, functions, built-in pipes, ...)

    Interface,            // interface
    Struct,               // struct
    Enum,                 // enum
    Data,                 // data
    Function,             // fn
    Pipe,                 // pipe
    Use,                  // use
    ReadableReference,    // ref
    WritableReference,    // mut
    Into,                 // into
    LockedMux,            // locked
    ReadableMuxReference, // readable
    WritableMuxReference, // writable
    ReadUnlock,           // runlock
    WriteUnlock,          // wunlock
    Lock,                 // lock
    Nothing,              // nothing
    SelfType,             // self
    Shoutor,              // shoutor
    Shoutee,              // shoutee

    IteratedAnnotation, // >>
}

pub(super) struct Token {
    pub type_: TokenType,
    pub location: FileLine,
}

impl Token {
    fn new(token_type: TokenType, location: FileLine) -> Self {
        Self {
            type_: token_type,
            location,
        }
    }

    pub fn parse(word: &str, location: &FileLine) -> Result<Vec<Self>> {
        // TODO handle comments and documentation, including that which follows
        // without spaces a valid lexeme

        let token = to_basic_token(word);
        if let Some(token) = token {
            let me = Self::new(token, location.clone());
            return Ok(vec![me]);
        }

        let mut ret = Vec::new();
        let mut current_word = String::new();

        for char in word.chars() {
            todo!();
        }

        return Ok(ret);
    }
}

impl Display for Token {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}: {:?}", self.location, self.type_)
    }
}

fn to_basic_token(word: &str) -> Option<TokenType> {
    let token_type = match word {
        "(" => TokenType::LeftParen,
        ")" => TokenType::RightParen,
        "{" => TokenType::LeftBrace,
        "}" => TokenType::RightBrace,
        "[" => TokenType::LeftSquare,
        "]" => TokenType::RightSquare,
        "<" => TokenType::LeftChevron,
        ">" => TokenType::RightChevron,
        "<=" => TokenType::LessEqual,
        ">=" => TokenType::GreaterEqual,
        "|" => TokenType::WindowPipe,
        "|>" => TokenType::GrabbyPipe,
        "->" => TokenType::ReturnValue,
        "=>" => TokenType::FieldNameAccess,
        ":: " => TokenType::TypePropertyAccess,
        ":" => TokenType::PackageAccess,
        "." => TokenType::FieldAccess,
        "," => TokenType::Comma,
        ";" => TokenType::Semicolon,
        "/" => TokenType::Slash,
        "*" => TokenType::Star,
        "!" => TokenType::Exclamation,
        "#" => TokenType::Hash,
        "%" => TokenType::Percent,
        "~" => TokenType::Tilda,
        "^" => TokenType::Hat,
        "$" => TokenType::Dollar,
        "&" => TokenType::Ampersand,
        "@" => TokenType::At,
        "?" => TokenType::Questionmark,
        "_" => TokenType::Underscore,
        "+" => TokenType::Plus,
        "=" => TokenType::Equals,
        "-" => TokenType::Minus,
        "and" => TokenType::AndWord,
        "&&" => TokenType::AndSymbol,
        "or" => TokenType::OrWord,
        "||" => TokenType::OrSymbol,
        "==" => TokenType::IsEqual,
        "!=" => TokenType::IsDifferent,
        ".." => TokenType::OpenRange,
        "..=" => TokenType::ClosedRange,
        "interface" => TokenType::Interface,
        "struct" => TokenType::Struct,
        "enum" => TokenType::Enum,
        "data" => TokenType::Data,
        "fn" => TokenType::Function,
        "pipe" => TokenType::Pipe,
        "use" => TokenType::Use,
        "ref" => TokenType::ReadableReference,
        "mut" => TokenType::WritableReference,
        "into" => TokenType::Into,
        "locked" => TokenType::LockedMux,
        "readable" => TokenType::ReadableMuxReference,
        "writable" => TokenType::WritableMuxReference,
        "runlock" => TokenType::ReadUnlock,
        "wunlock" => TokenType::WriteUnlock,
        "lock" => TokenType::Lock,
        "nothing" => TokenType::Nothing,
        "self" => TokenType::SelfType,
        "shoutor" => TokenType::Shoutor,
        "shoutee" => TokenType::Shoutee,
        ">>" => TokenType::IteratedAnnotation,

        _ => return None,
    };

    return Some(token_type);
}
