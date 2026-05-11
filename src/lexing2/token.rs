use std::convert::TryFrom;
use std::string::ToString;

#[derive(PartialEq, Eq)]
pub enum Token {
    Newline,
    WordSeparator,
    String(String),
    Documentation(String),
    Literal(String),
}

pub(super) enum WordSeparator {
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
    Underscore,   // _
    SingleQuote,  // '
    DoubleQuote,  // "
    Grave,        // `
}

impl TryFrom<&str> for WordSeparator {
    type Error = ();

    fn try_from(value: &str) -> Result<Self, Self::Error> {
        Ok(match value {
            "." => Self::Dot,
            "," => Self::Comma,
            ":" => Self::Colon,
            ";" => Self::Semicolon,
            "!" => Self::Exclamation,
            "?" => Self::Question,
            "(" => Self::LeftParen,
            ")" => Self::RightParen,
            "<" => Self::LeftChevron,
            ">" => Self::RightChevron,
            "[" => Self::LeftBracket,
            "]" => Self::RightBracket,
            "{" => Self::LeftBrace,
            "}" => Self::RightBrace,
            "+" => Self::Plus,
            "-" => Self::Minus,
            "*" => Self::Star,
            "=" => Self::Equal,
            "|" => Self::Bar,
            "/" => Self::Slash,
            "\\" => Self::Backslash,
            "&" => Self::AndPerSeAnd,
            "$" => Self::Dollar,
            "#" => Self::Hash,
            "@" => Self::At,
            "%" => Self::Percent,
            "^" => Self::Carrot,
            "~" => Self::Tilda,
            "_" => Self::Underscore,
            "'" => Self::SingleQuote,
            r#"""# => Self::DoubleQuote,
            "`" => Self::Grave,
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
            Self::Underscore => "_",
            Self::SingleQuote => "'",
            Self::DoubleQuote => r#"""#,
            Self::Grave => "`",
        }
        .to_string()
    }
}
