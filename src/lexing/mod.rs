//! Lexer takes in a files and turns it into a string of tokens. Tokens have a
//! file:line:column location and a basic type. No validity is checked except
//! whether multi-word tokens (strings, documentation, multi-line comments) are
//! terminated.

pub mod lexer;
pub mod state_machine;
pub mod token;
pub mod token_iterator;

pub use token::*;
pub use token_iterator::*;
