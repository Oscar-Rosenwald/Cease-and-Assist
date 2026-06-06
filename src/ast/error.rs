use crate::lexing::*;

use std::collections::VecDeque;
use std::fmt::Display;

/// An error caused by parsing an invalid series of [`Token`]s into an
/// expression. By "invalid" we mean the tokens do not conform to the syntax of
/// the Cease language.
///
/// The error includes a message which describes the syntactic problem, a list
/// of tokens which exhibit this problem, if one such can be constructed, and a
/// list of tokens which are yet to be processed.
///
/// Unlike most errors, AstError is meant to be included in the output of the
/// abstract syntax tree parser. The parser produces a tree where some nodes are
/// of kind `AstError`. The other nodes can still be evaluated and some limited
/// analysis can be run on them, and as long as that is the case, we don't need
/// to block the whole operation just because one line is wrong.
#[derive(Debug, PartialEq, Eq)]
pub struct AstError {
    pub message: String,
    pub failing_tokens: Vec<Token>,
    pub remaining_tokens: VecDeque<Token>,
}

impl AstError {
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

impl Display for AstError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "Did a little syntactic oopsie, didn't we? {}",
            self.message
        ) // TODO Eventually we'd like to print the tokens as well.
    }
}

/// A `Result` wrapper for the [`AstError`] type.
pub type AstResult<T> = Result<T, AstError>;
