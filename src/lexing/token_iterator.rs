use super::*;
use crate::common::errors;

use std::convert::TryFrom;

/// Block is a basic group of commands in the Cease language. Everything is
/// inside a block. Blocks are either statements (augmenting the behaviour of
/// the code but having no value, e.g. code which manages packages), or
/// expressions (commands which can be evaluated into some result, and which
/// thus hava a type).
///
/// A block is a list of block segments. A block segment is either a line of
/// [`Token`]s or a nested block. Eventually, everything is a list of Tokens,
/// but for ease of processing later in the compiler we'll denote the inner
/// blocks (like `if` statements) here as they are harder to parse.
pub type Block = Vec<BlockSegment>;

/// A block segment is a part of a [`Block`], which is a generic name for either
/// expressions or statements. A segment of the block is either a list of tokens
/// which denote a base expression (usually temrinated by a newline), or a
/// nested block.
///
/// For example, `new x = 7` is a token block. A function is a block which
/// contains the signature (tokens), and the body (a list of blocks). The body
/// may be formed of simple expressions (so tokens, again), or inner blocks
/// (like an if statement and a closure definition etc.).
pub enum BlockSegment {
    Tokens(Vec<Token>),
    Nested(Block),
}

pub struct TokenIter {
    tokens: std::collections::VecDeque<Token>,
}

impl Iterator for TokenIter {
    type Item = Token;

    fn next(&mut self) -> Option<Self::Item> {
        self.tokens.pop_front()
    }
}

impl TokenIter {
    /// Reads the next section of tokens which compose a block, which is an
    /// expression or a statement. E.e. a function is one block, which can be
    /// further esplit into the signature and the body, which itself contains
    /// expressions, that is blocks. This function returns only the top-most
    /// block, so in this example the function.
    pub fn read_block(&mut self) -> errors::LexResult<Option<Block>> {
        let first_token = match self.next_skip_whitespace() {
            None => return Ok(None),
            Some(token) => token,
        };

        let block_end = match &first_token.type_ {
            TokenType::Newline => {
                unreachable!("I thought we stripped empty newlines")
            }
            TokenType::WordSeparator(_) => {
                unreachable!("I thought we stripped word separators at starts of lines")
            }
            TokenType::Symbol(_) => {
                unreachable!("I thought we stripped symbols at starts of lines")
            }
            TokenType::Keyword(keyword) => {
                BlockEnd::try_from(keyword).unwrap_or_else(|_| BlockEnd::Newline)
            }
            TokenType::EndOfFile => return Ok(None),
            TokenType::Documentation(_) => return self.read_documented_block(first_token),
            TokenType::String(_)
            | TokenType::Char(_)
            | TokenType::Number(_)
            | TokenType::DecimalNumber(_, _)
            | TokenType::Literal(_) => BlockEnd::Newline,
        };

        return Ok(Some(self.gather_block(first_token, block_end)));
    }

    fn next_skip_whitespace(&mut self) -> Option<Token> {
        self.skip_while(|t| match t.type_ {
            TokenType::Newline | TokenType::EndOfFile => true,
            _ => false,
        })
        .next()
    }

    /// Read tokens until `block_end` is encountered.
    fn gather_block(&mut self, first_token: Token, block_end: BlockEnd) -> Block {
        let mut block_end_stack = vec![block_end];
        let mut current_tokens = Vec::new();
        current_tokens.push(first_token);

        for token in self {
            let current_block_end = match block_end_stack.last() {
                None => break,
                Some(block_end) => block_end,
            };

            match current_block_end.test_token(&token) {
                TokenAction::Accept => current_tokens.push(token),
                TokenAction::Recursive(new_block_end) => {
                    block_end_stack.push(new_block_end);
                }
                TokenAction::Terminate => {
                    current_tokens.push(token);
                    let _ = block_end_stack.pop();
                }
            }
        }

        return current_tokens;
    }

    /// Read a block which follows after a documentation token.
    fn read_documented_block(&mut self, doc_token: Token) -> errors::LexResult<Option<Block>> {
        let mut documented_object = self
            .read_block()
            .map_err(|e| {
                errors::LexingError::wrap(
                    "Error while reading documented block",
                    e,
                    doc_token.end_location.clone(),
                )
            })?
            .ok_or_else(|| {
                errors::LexingError::new(
                    "What are you documenting?",
                    doc_token.end_location.clone(),
                )
            })?;

        documented_object.insert(0, doc_token);

        return Ok(Some(documented_object));
    }
}

/// What should be done with the next read token?
enum TokenAction {
    /// The token belongs in the same block.
    Accept,
    /// The token terminates the block.
    Terminate,
    /// The token is a start of a nested block.
    Recursive(BlockEnd),
}

/// Determines how the block which is currently being read will end.
enum BlockEnd {
    Newline,
    Brace,
    Semicolon,
}

impl BlockEnd {
    /// Given `self` as a block terminator, how should a `token` be treated?
    fn test_token(&self, token: &Token) -> TokenAction {
        match self {
            Self::Newline => match token.type_ {
                TokenType::Newline => TokenAction::Terminate,
                TokenType::EndOfFile => TokenAction::Terminate,
                TokenType::Keyword(ref keyword) => match BlockEnd::try_from(keyword) {
                    Err(_) => TokenAction::Accept,
                    Ok(inner_block_end) => TokenAction::Recursive(inner_block_end),
                },
                _ => TokenAction::Accept,
            },
            Self::Brace => match token.type_ {
                TokenType::WordSeparator(ref separator) => match separator {
                    WordSeparator::RightBrace => TokenAction::Terminate,
                    _ => TokenAction::Accept,
                },
                TokenType::Keyword(ref keyword) => match BlockEnd::try_from(keyword) {
                    Err(_) => TokenAction::Accept,
                    Ok(inner_block_end) => TokenAction::Recursive(inner_block_end),
                },
                _ => TokenAction::Accept,
            },
            Self::Semicolon => match token.type_ {
                TokenType::WordSeparator(ref separator) => match separator {
                    WordSeparator::Semicolon => TokenAction::Terminate,
                    _ => TokenAction::Accept,
                },
                TokenType::Keyword(ref keyword) => match BlockEnd::try_from(keyword) {
                    Err(_) => TokenAction::Accept,
                    Ok(inner_block_end) => TokenAction::Recursive(inner_block_end),
                },
                _ => TokenAction::Accept,
            },
        }
    }
}

impl TryFrom<&Keyword> for BlockEnd {
    type Error = ();

    fn try_from(value: &Keyword) -> Result<Self, Self::Error> {
        match value {
            Keyword::New | Keyword::Remote | Keyword::Const | Keyword::Public | Keyword::Secret => {
                Ok(BlockEnd::Newline)
            }
            Keyword::Impl | Keyword::Interface | Keyword::Function | Keyword::Pipe => {
                Ok(BlockEnd::Brace)
            }
            _ => Err(()),
        }
    }
}
