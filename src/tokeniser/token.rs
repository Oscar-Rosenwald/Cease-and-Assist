use super::*;
use std::str::FromStr;

#[derive(Debug)]
pub struct Token {
    pub position: Position,
    pub kind: TokenKind,
    pub syntax_errors: Option<Vec<CeaseError>>,
}

#[derive(Debug)]
pub enum TokenKind {
    Error(String),
    Literal(String),
    Documentation(String),
    String(String),
    Char(char),
    Keyword(Keyword),
    Symbol(Symbol),
    Int(u64),
}

#[derive(Debug)]
pub enum Keyword {
    New,            // "new"
    Old,            // "old"
    Heap,           // "heap"
    Return,         // "return"
    Yield,          // "yield"
    Cascade,        // "cascade"
    Loop,           // "loop"
    Breaks,         // "break"
    Void,           // "void"
    Const,          // "const"
    Into,           // "into"
    Fun,            // "fun"
    Maybe,          // "may"
    Iterated,       // "itr"
    Failing,        // "err"
    Ark,            // "ark"
    Alias,          // "alias"
    Type,           // "type"
    Struct,         // "struct"
    Enum,           // "enum"
    Data,           // "data"
    Base,           // "base"
    Property,       // "prop"
    Properties,     // "properties"
    Interface,      // "interface"
    Implementation, // "impl"
    If,             // "if"
    Else,           // "else"
    While,          // "while"
    For,            // "for"
    In,             // "in"
    Switch,         // "switch"
    Case,           // "case"
    Fail,           // "fail"
    Package,        // "package"
    Pkg,            // "pkg"
    Fn,             // "fn"
    Use,            // "use"
    Sec,            // "sec"
    True,           // "true"
    False,          // "false"
}

#[derive(Debug)]
pub enum Symbol {
    Dot,                // "."
    Comma,              // ","
    Semicolon,          // ";"
    Equals,             // "="
    SetPoint,           // "<-"
    DotDot,             // ".."
    DotDotLess,         // "..<"
    Plus,               // "+"
    Minus,              // "-"
    Star,               // "*"
    Slash,              // "/"
    Carrot,             // "^"
    AndPerSeAnd,        // "&"
    Dollar,             // "$"
    Bar,                // "|"
    GrabbyPipe,         // "|>"
    Colon,              // ":"
    ColonColon,         // "::"
    ColonColonColon,    // ":::"
    Arrow,              // "->"
    DoubleArrow,        // "=>"
    Tilda,              // "~"
    Hash,               // "#"
    Percent,            // "%"
    Backslash,          // "\"
    At,                 // "@"
    Underscore,         // "_"
    DotDotDot,          // "..."
    MinuxMinux,         // "--"
    DoubleSlash,        // "//"
    SlashStar,          // "/*"
    StarSlash,          // "*/"
    EqualsEquals,       // "=="
    ThreeEquals,        // "==="
    TwoUnderscore,      // "__"
    ThreeUnderscore,    // "___"
    QuestionQuestion,   // "??"
    LeftParen,          // "("
    RightParen,         // ")"
    LeftBrace,          // "{"
    RightBrace,         // "}"
    LeftBracket,        // "["
    RightBracket,       // "]"
    LeftChevron,        // "<"
    RightChevron,       // ">"
    LeftDoubleChevron,  // "<<"
    RightDoubleChevron, // ">>"
}

impl std::fmt::Display for Keyword {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let word = match self {
            Self::New => "new",
            Self::Old => "old",
            Self::Heap => "heap",
            Self::Return => "return",
            Self::Yield => "yield",
            Self::Cascade => "cascade",
            Self::Loop => "loop",
            Self::Breaks => "break",
            Self::Void => "void",
            Self::Const => "const",
            Self::Into => "into",
            Self::Fun => "fun",
            Self::Maybe => "may",
            Self::Iterated => "itr",
            Self::Failing => "err",
            Self::Ark => "ark",
            Self::Alias => "alias",
            Self::Type => "type",
            Self::Struct => "struct",
            Self::Enum => "enum",
            Self::Data => "data",
            Self::Base => "base",
            Self::Property => "prop",
            Self::Properties => "properties",
            Self::Interface => "interface",
            Self::Implementation => "impl",
            Self::If => "if",
            Self::Else => "else",
            Self::While => "while",
            Self::For => "for",
            Self::In => "in",
            Self::Switch => "switch",
            Self::Case => "case",
            Self::Fail => "fail",
            Self::Package => "package",
            Self::Pkg => "pkg",
            Self::Fn => "fn",
            Self::Use => "use",
            Self::Sec => "sec",
            Self::True => "true",
            Self::False => "false",
        };

        write!(f, "{word}")
    }
}

impl FromStr for Keyword {
    type Err = ();

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        let keyword = match s {
            "new" => Self::New,
            "old" => Self::Old,
            "heap" => Self::Heap,
            "return" => Self::Return,
            "yield" => Self::Yield,
            "cascade" => Self::Cascade,
            "loop" => Self::Loop,
            "break" => Self::Breaks,
            "void" => Self::Void,
            "const" => Self::Const,
            "into" => Self::Into,
            "fun" => Self::Fun,
            "may" => Self::Maybe,
            "itr" => Self::Iterated,
            "err" => Self::Failing,
            "ark" => Self::Ark,
            "alias" => Self::Alias,
            "type" => Self::Type,
            "struct" => Self::Struct,
            "enum" => Self::Enum,
            "data" => Self::Data,
            "base" => Self::Base,
            "prop" => Self::Property,
            "properties" => Self::Properties,
            "interface" => Self::Interface,
            "impl" => Self::Implementation,
            "if" => Self::If,
            "else" => Self::Else,
            "while" => Self::While,
            "for" => Self::For,
            "in" => Self::In,
            "switch" => Self::Switch,
            "case" => Self::Case,
            "fail" => Self::Fail,
            "package" => Self::Package,
            "pkg" => Self::Pkg,
            "fn" => Self::Fn,
            "use" => Self::Use,
            "sec" => Self::Sec,
            "true" => Self::True,
            "false" => Self::False,
            _ => return Err(()),
        };
        return Ok(keyword);
    }
}

impl std::fmt::Display for Symbol {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let symbol = match self {
            Self::Dot => ".",
            Self::Comma => ",",
            Self::Semicolon => ";",
            Self::Equals => "=",
            Self::SetPoint => "<-",
            Self::DotDot => "..",
            Self::DotDotLess => "..<",
            Self::Plus => "+",
            Self::Minus => "-",
            Self::Star => "*",
            Self::Slash => "/",
            Self::Carrot => "^",
            Self::AndPerSeAnd => "&",
            Self::Dollar => "$",
            Self::Bar => "|",
            Self::GrabbyPipe => "|>",
            Self::Colon => ":",
            Self::ColonColon => "::",
            Self::ColonColonColon => ":::",
            Self::Arrow => "->",
            Self::DoubleArrow => "=>",
            Self::Tilda => "~",
            Self::Hash => "#",
            Self::Percent => "%",
            Self::Backslash => "\\",
            Self::At => "@",
            Self::Underscore => "_",
            Self::DotDotDot => "...",
            Self::MinuxMinux => "--",
            Self::DoubleSlash => "//",
            Self::SlashStar => "/*",
            Self::StarSlash => "*/",
            Self::EqualsEquals => "==",
            Self::ThreeEquals => "===",
            Self::TwoUnderscore => "__",
            Self::ThreeUnderscore => "___",
            Self::QuestionQuestion => "??",
            Self::LeftParen => "(",
            Self::RightParen => ")",
            Self::LeftBrace => "{",
            Self::RightBrace => "}",
            Self::LeftBracket => "[",
            Self::RightBracket => "]",
            Self::LeftChevron => "<",
            Self::RightChevron => ">",
            Self::LeftDoubleChevron => "<<",
            Self::RightDoubleChevron => ">>",
        };

        write!(f, "{symbol}")
    }
}

impl std::str::FromStr for Symbol {
    type Err = ();

    fn from_str(s: &str) -> Result<Self, Self::Err> {
        let symbol = match s {
            "." => Self::Dot,
            "," => Self::Comma,
            ";" => Self::Semicolon,
            "=" => Self::Equals,
            "<-" => Self::SetPoint,
            ".." => Self::DotDot,
            "..<" => Self::DotDotLess,
            "+" => Self::Plus,
            "-" => Self::Minus,
            "*" => Self::Star,
            "/" => Self::Slash,
            "^" => Self::Carrot,
            "&" => Self::AndPerSeAnd,
            "$" => Self::Dollar,
            "|" => Self::Bar,
            "|>" => Self::GrabbyPipe,
            ":" => Self::Colon,
            "::" => Self::ColonColon,
            ":::" => Self::ColonColonColon,
            "->" => Self::Arrow,
            "=>" => Self::DoubleArrow,
            "~" => Self::Tilda,
            "#" => Self::Hash,
            "%" => Self::Percent,
            "\\" => Self::Backslash,
            "@" => Self::At,
            "_" => Self::Underscore,
            "..." => Self::DotDotDot,
            "--" => Self::MinuxMinux,
            "//" => Self::DoubleSlash,
            "/*" => Self::SlashStar,
            "*/" => Self::StarSlash,
            "==" => Self::EqualsEquals,
            "===" => Self::ThreeEquals,
            "__" => Self::TwoUnderscore,
            "___" => Self::ThreeUnderscore,
            "??" => Self::QuestionQuestion,
            "(" => Self::LeftParen,
            ")" => Self::RightParen,
            "{" => Self::LeftBrace,
            "}" => Self::RightBrace,
            "[" => Self::LeftBracket,
            "]" => Self::RightBracket,
            "<" => Self::LeftChevron,
            ">" => Self::RightChevron,
            "<<" => Self::LeftDoubleChevron,
            ">>" => Self::RightDoubleChevron,
            _ => return Err(()),
        };

        return Ok(symbol);
    }
}

impl std::fmt::Display for TokenKind {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Self::Error(error) => write!(f, "{error}"),
            Self::Literal(literal) => write!(f, "{literal}"),
            Self::Documentation(documentation) => write!(f, "{documentation}"),
            Self::String(sentense) => write!(f, "{sentense}"),
            Self::Char(character) => write!(f, "{character}"),
            Self::Keyword(keyword) => write!(f, "{keyword}"),
            Self::Symbol(symbol) => write!(f, "{symbol}"),
            Self::Int(value) => write!(f, "{value}"),
        }
    }
}

impl std::fmt::Display for Token {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}: {}", self.position, self.kind)
    }
}

impl Token {
    pub(super) fn new(kind: TokenKind, position: Position) -> Self {
        Self {
            kind,
            position,
            syntax_errors: None,
        }
    }

    pub(super) fn failing(
        error_snippet: String,
        position: Position,
        error: CeaseError,
        mut errors: Vec<CeaseError>,
    ) -> Self {
        errors.push(error);

        Self {
            kind: TokenKind::Error(error_snippet),
            position,
            syntax_errors: Some(errors),
        }
    }
}

/// The result of [`Symbol::parse_char`]. We pass a `char` we've just read from
/// the input. We return whether the `char` is a symbol, a part of a potential
/// symbol, or not a symbol at all. Parts of symbols become candidates which are
/// passed the next time we call the function.
pub(super) enum SymbolParseResult {
    /// The candidate-char pair are not a symbol.
    NoSymbol,
    /// The candidate-char pair is a candidate for a symbol, but not a symbol by
    /// itself. When `terminal` is true, regardless of whether the candidate
    /// resolves into a full Symbol or not, the old token/lexime is already
    /// concluded. In other words, if `terminal` is true and `symbol` doesn't
    /// turn out to be Symbol afterall, it's a syntax error.
    ///
    /// E.g. `something_` is a candidate with `terminal = false` because
    /// `something_` is a valid variable name.
    ///
    /// But `something__` is a candidate with `terminal = true` because `__` is
    /// not a valid part of a variable name, and it's not a symbol, either. It's
    /// a candidate for `___`.
    Candidate { symbol: Symbol, terminal: bool },
    /// The candidate-char pair is a candidate for a symbol, but also a symbol
    /// by itself should the next `char` not finish the possible (longer)
    /// symbol.
    ///
    /// # Example
    ///
    /// We're building the ... symbol.
    /// ```rust
    /// let candidate = ".";
    /// let new_char = '.';
    /// let parse_result = Symbol::parse_char(&candidate, new_char);
    /// ```
    ///
    /// This returns an `ExtendableCandidate` because '..' is itself a symbol,
    /// but another '.' would turn it into the '...' symbol.
    ExtendableCandidate(Symbol),
    /// The canddiate-char pair is a full symbol.
    Symbol(Symbol),
}

impl Symbol {
    /// Reports whether the character `c` and an optional `candidate` prependix
    /// are together a symbol, or a part of a symbol. See [`SymbolParseResult`]
    /// for more docs.
    pub(super) fn parse_char(candidate: Option<&str>, c: char) -> SymbolParseResult {
        let candidate = match candidate {
            None => c.to_string(),
            Some(candidate) => format!("{candidate}{c}"),
        };

        let Ok(symbol) = Self::from_str(&candidate) else {
            return SymbolParseResult::NoSymbol;
        };

        match symbol {
            // One-character symbols
            Self::Comma
            | Self::Semicolon
            | Self::Plus
            | Self::Carrot
            | Self::AndPerSeAnd
            | Self::Dollar
            | Self::Hash
            | Self::Percent
            | Self::Backslash
            | Self::At
            | Self::QuestionQuestion
            | Self::LeftParen
            | Self::RightParen
            | Self::LeftBrace
            | Self::RightBrace
            | Self::LeftBracket
            | Self::RightBracket => SymbolParseResult::Symbol(symbol),

            // Symbol candidates
            Self::TwoUnderscore => SymbolParseResult::Candidate {
                symbol,
                terminal: false,
            },

            // Extendable symbols (symbols by themselves and symbol candidates
            // at the same time)
            Self::Dot
            | Self::Colon
            | Self::Minus
            | Self::Slash
            | Self::Star
            | Self::Bar
            | Self::Equals
            | Self::Tilda
            | Self::Underscore
            | Self::EqualsEquals
            | Self::LeftChevron
            | Self::RightChevron
            | Self::DotDot
            | Self::ColonColon => SymbolParseResult::ExtendableCandidate(symbol),

            // Multi-character symbols
            Self::DotDotLess
            | Self::SetPoint
            | Self::GrabbyPipe
            | Self::ColonColonColon
            | Self::DoubleSlash
            | Self::SlashStar
            | Self::StarSlash
            | Self::Arrow
            | Self::DoubleArrow
            | Self::DotDotDot
            | Self::MinuxMinux
            | Self::ThreeUnderscore
            | Self::ThreeEquals
            | Self::LeftDoubleChevron
            | Self::RightDoubleChevron => SymbolParseResult::Symbol(symbol),
        }
    }
}
