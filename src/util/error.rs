use super::*;
use std::string::ToString;

#[derive(Debug, PartialEq, Eq, Clone)]
pub struct Error {
    kind: ErrorKind,
    location: ErrorLocation,
}

/// Denotes the place where an error was encountered.
#[derive(Debug, PartialEq, Eq, Clone)]
pub enum ErrorLocation {
    /// Error not connected with any particular position in a file.
    Generic,
    /// Error processing a file as a whole.
    File(std::path::PathBuf),
    /// Error at a particular position in a file.
    Position(Position),
}

/// Denotes which step of compilation the error occured in.
#[derive(Debug, PartialEq, Eq, Clone)]
pub enum ErrorKind {
    /// An error on the part of yours truly. Submit a bug, I guess.
    Author(String),
    /// The programmer is using Ceaes wrong.
    Syntax(SyntaxError),
    /// Error during reading of the input. File errors etc.
    Lexer(LexerError),
    /// Error sorting tokens into expressions and statements.
    SyntaxTree(SyntaxTreeError),
}

#[derive(Debug, PartialEq, Eq, Clone)]
pub enum SyntaxError {
    InvalidNameOrSymbol,
    InvalidSymbol,
    UnterminatedString,
    UnterminatedChar,
    UnterminatedDocumentation,
    CharTooLong,
}

#[derive(Debug, Eq, Clone)]
pub enum LexerError {
    CannotOpenFile { file_name: String, error: String },
    CannotReadLine { file_name: String, error: String },
}

#[derive(Debug, PartialEq, Eq, Clone)]
pub enum SyntaxTreeError {
    // Package name errors
    /// `package;`
    PackageNameMissing,
    /// `package best-module;`
    PackageNameLiteralFollowup(String),
    /// `package best/??;`
    PackageNameSlashFollowup(String),
    /// `package "best/module";
    WrongPackageName(String),
    /// The package name is too long (too many components).
    PackageNameTooLong(usize),
    PackageNameBadToken(Vec<(String, CeaseError)>),

    // Package export errors
    /// E.g. `pkg fn;`.
    ExportIncompleteStatement(String),
    /// E.g. `8` instead of `fn` in package.stop file.
    ExportExpectedKeyword(String),
    /// E.g. `8` instead of `append` in a `fn append;` kind of line.
    ExportExpectedLiteral(String),
    /// E.g. `struct` instead of `type` in a `type Type` kind of line.
    ExportExpectedDifferentKeyword(String),
    /// `8 - 'c'` in `prop Property 8 - c;` kind of line.
    ExportTrailingTokens(Vec<String>),

    /// `package best/module` or `package`
    MissingSemicolon,
    /// File ends with a documentation block.
    EofDocumentation,
}

impl std::fmt::Display for SyntaxError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let message = match self {
            Self::InvalidNameOrSymbol => "Invalid name or unfinished symbol",
            Self::InvalidSymbol => "Invalid symbol.",
            Self::UnterminatedString => "Unterminated string. Try a quote, dumbarse.",
            Self::UnterminatedChar => "Unterminated char. Try a quote, dumbarse.",
            Self::UnterminatedDocumentation => {
                "Unterminated documentation block. Try ending it? With a === maybe? Jesus Christ."
            }
            Self::CharTooLong => {
                "Too many characters in this character. Try one? Or two with a backslash."
            }
        };

        write!(f, "{message}")
    }
}

impl PartialEq for LexerError {
    fn eq(&self, other: &Self) -> bool {
        match self {
            Self::CannotOpenFile {
                file_name,
                error: _,
            } => match other {
                Self::CannotReadLine {
                    file_name: _,
                    error: _,
                } => false,
                Self::CannotOpenFile {
                    file_name: other_name,
                    error: _,
                } => file_name == other_name,
            },
            Self::CannotReadLine {
                file_name,
                error: _,
            } => match other {
                Self::CannotOpenFile {
                    file_name: _,
                    error: _,
                } => false,
                Self::CannotReadLine {
                    file_name: other_name,
                    error: _,
                } => file_name == other_name,
            },
        }
    }
}

impl std::fmt::Display for LexerError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let message = match self {
            Self::CannotOpenFile { file_name, error } => {
                format!("Cannot open file '{file_name}': {error}")
            }
            Self::CannotReadLine { file_name, error } => {
                format!("Cannot read line '{file_name}': {error}")
            }
        };

        write!(f, "{message}")
    }
}

impl std::fmt::Display for SyntaxTreeError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let message = match self {
            Self::PackageNameLiteralFollowup(str) => format!(
                "Package name must be followed by a slash or a semicolon. You followed it up with {str}. Idiot."
            ),
            Self::PackageNameSlashFollowup(str) => format!(
                "Slash in package name must be followed by a literal, like 'awesome/package'. You followed it up with {str}. Moron."
            ),
            Self::PackageNameTooLong(name_count) => format!(
                "I won't tell you how to name your packages. You want {} namese in the import path? Be my guest. But I WILL actually tell you how to name your packages, and this is fucking ridiculous. Make it shorter. Who's supposed to type all that?",
                name_count,
            ),
            Self::PackageNameMissing => {
                "Missing package name. Call it something like awesomePackage or best/package/ever."
                    .to_string()
            }
            Self::WrongPackageName(name) => format!(
                "Expected package name (with format 'literal [ /literal ...]'), got {}",
                name
            ),
            Self::PackageNameBadToken(errors) => {
                let something = errors
                    .into_iter()
                    .map(|(snippet, error)| format!("{}: {}", snippet, error.to_string()))
                    .collect::<Vec<_>>();

                format!(
                    "WTF do you want me to do with a package name like this?:\n\n{}",
                    something.join("\n")
                )
            }
            Self::ExportExpectedKeyword(actual) => format!("Expected keyword, got {actual}"),
            Self::ExportExpectedLiteral(actual) => {
                format!("Expected name of an exported symbol, got {actual}")
            }
            Self::ExportExpectedDifferentKeyword(actual) => {
                format!("Expected 'fn,' 'type,' 'prop,' or 'interface,' got {actual}")
            }
            Self::ExportTrailingTokens(others) => format!(
                "Unexpected tokens after a full export statement: {}",
                others.join(", ")
            ),
            Self::MissingSemicolon => "Missing semicolon".to_string(),
            Self::EofDocumentation => "Dude. What are you documenting?".to_string(),
        };

        write!(f, "{message}")
    }
}

impl std::fmt::Display for ErrorKind {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let message = match self {
            Self::Author(message) => message.to_string(),
            Self::Syntax(message) => message.to_string(),
            Self::Lexer(message) => message.to_string(),
            Self::SyntaxTree(message) => message.to_string(),
        };
        write!(f, "{message}",)
    }
}

impl std::fmt::Display for Error {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let location_str = match &self.location {
            ErrorLocation::Generic => String::new(),
            ErrorLocation::File(file_path) => {
                format!("{}: ", file_path.file_name().unwrap().to_string_lossy())
            }
            ErrorLocation::Position(position) => format!("{position}: "),
        };

        write!(f, "{location_str}{}", self.kind)
    }
}

impl Error {
    /// Returns a (`error location`, `error summaries`) pair.
    pub fn debug(error: &Self) -> (String, String) {
        let ret_location = match &error.location {
            ErrorLocation::Generic => String::from("Compiler"),
            ErrorLocation::File(file_path) => file_path.to_string_lossy().to_string(),
            ErrorLocation::Position(position) => position.to_string(),
        };

        return (ret_location, format!("({:?}) {}", error.kind, error));
    }

    /// Constructs a new Error of [`ErrorKind::Author`] which denotes an error
    /// in the compiler.
    pub fn author<S: ToString>(message: S, location: ErrorLocation) -> Self {
        Self {
            kind: ErrorKind::Author(message.to_string()),
            location,
        }
    }

    /// Constructs a new Error of [`ErrorKind::Syntax`].
    pub fn syntax(kind: SyntaxError, location: ErrorLocation) -> Self {
        Self {
            kind: ErrorKind::Syntax(kind),
            location,
        }
    }

    /// Construct a new Error of [`ErrorKind::Lexer`].
    pub fn lexer(kind: LexerError, location: ErrorLocation) -> Self {
        Self {
            kind: ErrorKind::Lexer(kind),
            location,
        }
    }

    /// Construct a new Error of [`ErrorKind::SyntaxTree`].
    pub fn syntax_tree(kind: SyntaxTreeError, location: ErrorLocation) -> Self {
        Self {
            kind: ErrorKind::SyntaxTree(kind),
            location,
        }
    }

    #[cfg(test)]
    pub fn kind(self) -> ErrorKind {
        self.kind
    }
}
