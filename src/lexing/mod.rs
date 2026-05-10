//! A lexer parses files into a series of known tokens. No assumptions are made
//! about the semantics of the tokens, or the correctness.

pub mod lexer;
mod state_machine;
pub mod token;
