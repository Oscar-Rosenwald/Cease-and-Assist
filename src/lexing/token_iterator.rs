use super::*;
use crate::common::errors;

use std::convert::TryFrom;

pub type Block = Vec<Token>;

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
    pub fn read_block(&mut self) -> errors::Result<Option<Block>> {
        let first_token = match self.skip_whitespace() {
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

    fn skip_whitespace(&mut self) -> Option<Token> {
        self.skip_while(|t| match t.type_ {
            TokenType::Newline | TokenType::EndOfFile => true,
            _ => false,
        })
        .next()
    }

    fn gather_block(&mut self, first_token: Token, block_end: BlockEnd) -> Block {
        let mut block_end_stack = vec![block_end];
        let mut ret_tokens = Vec::new();
        ret_tokens.push(first_token);

        for token in self {
            let current_block_end = match block_end_stack.last() {
                None => break,
                Some(block_end) => block_end,
            };

            match current_block_end.test_token(&token) {
                TokenAction::Accept => ret_tokens.push(token),
                TokenAction::Recursive(new_block_end) => {
                    block_end_stack.push(new_block_end);
                }
                TokenAction::Terminate => {
                    ret_tokens.push(token);
                    let _ = block_end_stack.pop();
                }
            }
        }

        return ret_tokens;
    }

    fn read_documented_block(&mut self, doc_token: Token) -> errors::Result<Option<Block>> {
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

enum TokenAction {
    Accept,
    Terminate,
    Recursive(BlockEnd),
}

enum BlockEnd {
    Newline,
    Brace,
    Semicolon,
}

impl BlockEnd {
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
