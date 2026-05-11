use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

use super::token::*;
use crate::common::errors::{self, ToLexingError};
use crate::common::file::*;

pub fn parse_file(file_path: &Path) -> errors::Result<Vec<Token>> {
    let file_name = file_path
        .file_name()
        .ok_or(errors::LexingError::bare("No such file"))?
        .to_str()
        .ok_or(errors::LexingError::bare("File is broken"))?;

    let file = File::open(file_path)
        .map_err(|e| e.wrap_location("Cannot open file", Location::file(file_name)))?;

    let lines = io::BufReader::new(file).lines();

    let mut lexer = Lexer {
        state: LexerState::Other,
        tokens: Vec::new(),
        current_token: String::new(),
    };

    for (line_index, line) in lines.enumerate() {
        let location = Location::line(file_name, line_index + 1);

        let line = line.map_err(|e| {
            e.wrap_location("Failed to read line", location.add_column(line_index + 1))
        })?;

        for word in line.split_whitespace() {
            for char in word.chars() {
                lexer.push_char(char);
            }

            lexer.push_end_of_word();
        }

        lexer.push_newline();
    }

    return Ok(lexer.tokens);
}

pub struct Lexer {
    state: LexerState,
    tokens: Vec<Token>,
    current_token: String,
}

impl Lexer {
    fn push_newline(&mut self) {
        let last = self.tokens.last();
        if last.eq(&Some(&Token::Newline)) {
            return;
        }

        let is_doc = self.current_token == DOCUMENTATION_TAG;

        match &self.state {
            LexerState::Other => self.tokens.push(Token::Newline),
            LexerState::String => self.tokens.push(Token::Newline),
            LexerState::Char => self.tokens.push(Token::Newline), // not valid, but we'll sort that out later
            LexerState::Comment(terminator) => match terminator {
                CommentTerminator::Newline => self.state = LexerState::Other,
                CommentTerminator::StarSlash => {}
            },
            LexerState::Documentation if is_doc => self.state = LexerState::String,
            LexerState::Documentation => self.tokens.push(Token::Newline),
        }
    }

    fn push_end_of_word(&mut self) {
        match &self.state {
            LexerState::String => {}
            LexerState::Char => {} // not valid, but we'll sort that out later
            LexerState::Documentation => {}
            LexerState::Comment(_) => {}
            LexerState::Other => {
                let literal = std::mem::take(&mut self.current_token);
                self.tokens.push(Token::Literal(literal));
            }
        }
    }

    fn push_char(&mut self, c: char) {
        let current_state = &self.state;

        match current_state {
            LexerState::Documentation => self.current_token.push(c),
            LexerState::String => {
                if c == STRING_BOUNDTRY {
                    // TODO: Add escaped quotes.
                    let literal = std::mem::take(&mut self.current_token);
                    self.tokens.push(Token::String(literal));
                    self.state = LexerState::Other;
                } else {
                    self.current_token.push(c);
                }
            }
            LexerState::Char => {
                if c == CHAR_BOUNDRY {
                    // TODO: escaped quote
                    let literal = std::mem::take(&mut self.current_token);
                    self.tokens.push(Token::Char(literal));
                    self.state = LexerState::Other;
                } else {
                    // This may not be valid, but we'll sort that out later
                    self.current_token.push(c);
                }
            }
            LexerState::Comment(terminator) => {
                if let CommentTerminator::Newline = terminator {
                    self.current_token.push(c);
                    return;
                }

                if c.to_string() != WordSeparator::Slash.to_string() {
                    self.current_token.push(c);
                    return;
                }

                let last_char = self.current_token.chars().last().unwrap_or(' ');
                if last_char.to_string() != WordSeparator::Star.to_string() {
                    self.current_token.push(c);
                    return;
                }

                self.state = LexerState::Other;
            }
            LexerState::Other => {
                if self.current_token.ends_with("/") {
                    if c == '/' {
                        self.current_token.pop();
                        self.state = LexerState::Comment(CommentTerminator::Newline);
                        return;
                    }
                    if c == '*' {
                        self.current_token.pop();
                        self.state = LexerState::Comment(CommentTerminator::StarSlash);
                        return;
                    }
                }
            }
        }
    }
}

enum LexerState {
    String,
    Char,
    Documentation,
    Comment(CommentTerminator),
    Other, // We'll spend most of the time here
}

enum CommentTerminator {
    Newline,
    StarSlash,
}
