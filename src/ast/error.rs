use crate::lexing::*;

use std::collections::VecDeque;

/// An error caused by parsing an invalid series of [`Token`]s into an
/// expression. By "invalid" we mean the tokens do not conform to the syntax of
/// the Cease language.
pub struct AstError {
    pub message: String,
    pub tokens: Vec<Token>,
}

impl AstError {
    pub fn empty<S: ToString>(msg: S) -> Self {
        Self {
            message: msg.to_string(),
            tokens: Vec::new(),
        }
    }

    pub fn tokens<S: ToString>(msg: S, tokens: Vec<Token>) -> Self {
        Self {
            message: msg.to_string(),
            tokens,
        }
    }
}

pub struct ParseError {
    pub error: AstError,
    pub tokens: VecDeque<Token>,
}

impl ParseError {
    pub fn empty<S: ToString>(msg: S, tokens: VecDeque<Token>) -> Self {
        let ast_error = AstError {
            message: msg.to_string(),
            tokens: Vec::new(),
        };

        Self {
            error: ast_error,
            tokens,
        }
    }

    pub fn tokens<S: ToString>(msg: S, error_tokens: Vec<Token>, tokens: VecDeque<Token>) -> Self {
        let ast_error = AstError {
            message: msg.to_string(),
            tokens: error_tokens,
        };

        Self {
            error: ast_error,
            tokens,
        }
    }
}

/// A `Result` wrapper for the [`AstError`] type.
pub type AstResult<T> = Result<T, ParseError>;
