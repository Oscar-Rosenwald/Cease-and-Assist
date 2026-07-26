use super::*;
use std::string::ToString;

#[derive(Debug)]
pub struct Error {
    message: String,
    kind: ErrorKind,
    location: ErrorLocation,
}

/// Denotes the place where an error was encountered.
#[derive(Debug)]
pub enum ErrorLocation {
    /// Error not connected with any particular position in a file.
    Generic,
    /// Error processing a file as a whole.
    File(std::path::PathBuf),
    /// Error at a particular position in a file.
    Position(Position),
}

/// Denotes which step of compilation the error occured in.
#[derive(Debug)]
pub enum ErrorKind {
    /// An error on the part of the author of the Cease language. Submit a bug,
    /// I guess.
    Author,
    /// The programmer is using Ceaes wrong.
    Syntax,
    /// Error during reading of the input. File errors etc.
    Lexer,
    /// Error splitting the program into tokens.
    Tokeniser,
    /// Error sorting tokens into expressions and statements.
    SyntaxTree,
}

impl Error {
    /// Constructs a new Error of [`ErrorKind::Author`] which denotes an error
    /// in the compiler.
    pub fn author<S: ToString>(message: S, location: ErrorLocation) -> Self {
        Self {
            message: message.to_string(),
            kind: ErrorKind::Author,
            location,
        }
    }

    /// Constructs a new Error of [`ErrorKind::Syntax`].
    pub fn syntax<S: ToString>(message: S, location: ErrorLocation) -> Self {
        Self {
            message: message.to_string(),
            kind: ErrorKind::Syntax,
            location,
        }
    }

    /// Constructs a new Error of [`ErrorKind::Tokeniser`].
    pub fn tokeniser<S: ToString>(message: S, location: ErrorLocation) -> Self {
        Self {
            message: message.to_string(),
            kind: ErrorKind::Tokeniser,
            location,
        }
    }

    /// Construct a new Error of [`ErrorKind::Lexer`].
    pub fn lexer<S: ToString>(message: S, location: ErrorLocation) -> Self {
        Self {
            message: message.to_string(),
            kind: ErrorKind::Lexer,
            location,
        }
    }

    /// Construct a new Error of [`ErrorKind::SyntaxTree`].
    pub fn syntax_tree<S: ToString>(message: S, location: ErrorLocation) -> Self {
        Self {
            message: message.to_string(),
            kind: ErrorKind::SyntaxTree,
            location,
        }
    }
}

impl std::fmt::Display for Error {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let error_kind = match self.kind {
            ErrorKind::Author => "Compiler bug",
            ErrorKind::Syntax => "Syntax error",
            ErrorKind::Tokeniser => "Tokenisation error",
            ErrorKind::Lexer => "Lexing error",
            ErrorKind::SyntaxTree => "Error parsing syntax tree",
        };

        match &self.location {
            ErrorLocation::Generic => write!(f, "{error_kind}: {}", self.message),
            ErrorLocation::Position(position) => {
                write!(f, "{error_kind} in {position}: {}", self.message)
            }
            ErrorLocation::File(file_path) => write!(
                f,
                "{error_kind} in {}: {}",
                file_path.to_string_lossy(),
                self.message
            ),
        }
    }
}
