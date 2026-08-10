use super::*;
use std::string::ToString;

#[derive(Debug, PartialEq, Eq)]
pub struct Error {
    message: String,
    kind: ErrorKind,
    location: ErrorLocation,
}

/// Denotes the place where an error was encountered.
#[derive(Debug, PartialEq, Eq)]
pub enum ErrorLocation {
    /// Error not connected with any particular position in a file.
    Generic,
    /// Error processing a file as a whole.
    File(std::path::PathBuf),
    /// Error at a particular position in a file.
    Position(Position),
}

/// Denotes which step of compilation the error occured in.
#[derive(Debug, PartialEq, Eq)]
pub enum ErrorKind {
    /// An error on the part of the author of the Cease language. Submit a bug,
    /// I guess.
    Author,
    /// The programmer is using Ceaes wrong.
    Syntax,
    /// Error during reading of the input. File errors etc.
    Lexer,
    /// Error sorting tokens into expressions and statements.
    #[allow(dead_code)] // TODO: Remove when you get there
    SyntaxTree,
}

impl Error {
    /// Returns a (`error location`, `error summaries`) pair.
    pub fn vec_to_debug(errors: &Vec<Self>) -> (String, Vec<String>) {
        if errors.is_empty() {
            return (String::new(), Vec::new());
        }

        let ret_location = match &errors.first().unwrap().location {
            ErrorLocation::Generic => String::from("Compiler"),
            ErrorLocation::File(file_path) => file_path.to_string_lossy().to_string(),
            ErrorLocation::Position(position) => position.to_string(),
        };

        let mut ret_str = Vec::new();

        for error in errors {
            let error = format!("({:?}) {}", error.kind, error.message);
            ret_str.push(error);
        }

        return (ret_location, ret_str);
    }

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

    /// Construct a new Error of [`ErrorKind::Lexer`].
    pub fn lexer<S: ToString>(message: S, location: ErrorLocation) -> Self {
        Self {
            message: message.to_string(),
            kind: ErrorKind::Lexer,
            location,
        }
    }

    /// Construct a new Error of [`ErrorKind::SyntaxTree`].
    #[allow(dead_code)] // TODO: Remove when you get there
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
