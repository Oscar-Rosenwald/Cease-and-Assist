use super::*;

use std::cell::RefCell;
use std::collections::VecDeque;
use std::fmt::Display;
use std::rc::Rc;

/// A `Result` wrapper for the [`SyntaxError`] type.
pub type SyntaxResult<T> = Result<T, SyntaxError>;

/// An error caused by parsing an invalid series of [`Token`]s into an
/// expression or statement. By "invalid" we mean the tokens do not conform to
/// the syntax of the Cease language.
///
/// The error includes a message which describes the syntactic problem, a list
/// of tokens which exhibit this problem, if one such can be constructed, and a
/// list of tokens which are yet to be processed.
///
/// Unlike most errors, SyntaxError is meant to be included in the output of the
/// abstract syntax tree parser. The parser produces a tree where some nodes are
/// of kind [`NodeKind::Error`]. The other nodes can still be evaluated and some
/// limited analysis can be run on them, and as long as that is the case, we
/// don't need to block the whole operation just because one line is wrong.
#[derive(Debug, PartialEq, Eq)]
pub struct SyntaxError {
    pub(super) message: String,
    pub failing_tokens: Vec<Token>,
    pub(super) remaining_tokens: VecDeque<Token>,
}

impl SyntaxError {
    pub fn empty<S: ToString>(msg: S, remaining_tokens: VecDeque<Token>) -> Self {
        Self {
            message: msg.to_string(),
            failing_tokens: vec![],
            remaining_tokens,
        }
    }

    pub fn tokens<S: ToString>(
        msg: S,
        failing_tokens: Vec<Token>,
        remaining_tokens: VecDeque<Token>,
    ) -> Self {
        Self {
            message: msg.to_string(),
            failing_tokens,
            remaining_tokens,
        }
    }
}

impl Display for SyntaxError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "Did a little syntactic oopsie, didn't we? {}",
            self.message
        ) // TODO Eventually we'd like to print the tokens as well.
    }
}

/// A `Result` wrapper for the [`TypeError`] type.
pub type TypeResult<T> = Result<T, TypeError>;

/// A `TypeError` is an error produced when the abstract syntax tree is
/// evaluated. It describes a... let's see... an error with the expression
/// types. Hmmmm. Who'd have guessed?
#[derive(Debug, PartialEq, Eq)]
pub struct TypeError {
    message: String,
    location: FileLocation,
}

impl TypeError {
    pub fn new<S: ToString>(msg: S, location: FileLocation) -> Self {
        Self {
            message: msg.to_string(),
            location,
        }
    }
}
