use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;
use std::{cell::RefCell, rc::Rc};

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
        state: Rc::new(RefCell::new(LexerState::Normal(String::new()))),
        tokens: Vec::new(),
    };

    for (line_index, line) in lines.enumerate() {
        let location = Location::line(file_name, line_index + 1);

        let line = line.map_err(|e| {
            e.wrap_location("Failed to read line", location.add_column(line_index + 1))
        })?;

        for char in line.chars() {
            lexer.push_char(char);
        }

        lexer.push_newline();
    }

    return Ok(lexer.tokens);
}

pub struct Lexer {
    state: Rc<RefCell<LexerState>>,
    tokens: Vec<Token>,
}

impl Lexer {
    fn push_char(&mut self, c: char) {
        let state = self.state.clone();
        let mut state = state.borrow_mut();

        match &mut *state {
            LexerState::Normal(word) => self.normal_push_char(c, word),
            LexerState::String(sentense) => self.string_push_char(c, sentense),
            LexerState::Char(character) => self.char_push_char(c, character),
            LexerState::Documentation(doc) => self.documentation_push_char(c, doc),
            LexerState::Comment {
                terminator,
                last_char,
            } => self.comment_push_char(c, last_char, terminator),
        }
    }

    fn normal_handle_word(&mut self, word: &str) {
        let token = match Keyword::try_from(word) {
            Ok(keyword) => Token::Keyword(keyword),
            Err(_) => Token::Literal(word.to_string()),
        };

        self.tokens.push(token);
        self.state = Rc::new(RefCell::new(LexerState::Normal(String::new())));
    }

    fn normal_push_char(&mut self, c: char, word: &mut String) {
        if c.is_whitespace() {
            if !word.is_empty() {
                self.normal_handle_word(&word);
            }
            return;
        }

        let last_char = word.chars().last().unwrap_or(' ');

        if c == '/' && last_char == '/' {
            word.pop();
            self.normal_handle_word(word);
            self.state = Rc::new(RefCell::new(LexerState::Comment {
                terminator: CommentTerminator::Newline,
                last_char: ' ',
            }));
            return;
        }

        if c == '*' && last_char == '/' {
            word.pop();
            self.normal_handle_word(word);
            self.state = Rc::new(RefCell::new(LexerState::Comment {
                terminator: CommentTerminator::StarSlash,
                last_char: ' ',
            }));
            return;
        }

        if c == STRING_BOUNDRY {
            self.normal_handle_word(word);
            self.state = Rc::new(RefCell::new(LexerState::String(String::new())));
            return;
        }

        if c == CHAR_BOUNDRY {
            self.normal_handle_word(word);
            self.state = Rc::new(RefCell::new(LexerState::Char(String::new())));
            return;
        }

        match WordSeparator::try_from(c) {
            Ok(separator) => {
                self.normal_handle_word(&word);
                self.tokens.push(Token::WordSeparator(separator));
                self.state = Rc::new(RefCell::new(LexerState::Normal(String::new())));
            }
            Err(_) => {
                word.push(c);
                return;
            }
        }
    }

    fn string_push_char(&mut self, c: char, sentense: &mut String) {
        if c != STRING_BOUNDRY {
            sentense.push(c);
            return;
        }

        let escaped_chars_count = sentense.chars().rev().take_while(|c| *c == '\\').count();
        let is_escaped = escaped_chars_count % 2 == 1;

        if is_escaped {
            sentense.push(c);
        } else {
            self.tokens.push(Token::String(sentense.to_string()));
            self.state = Rc::new(RefCell::new(LexerState::Normal(String::new())));
        }
    }

    fn char_push_char(&mut self, c: char, character: &mut String) {
        if c != CHAR_BOUNDRY {
            character.push(c);
            return;
        }

        let is_escaped = character
            .chars()
            .last()
            .map(|last| last == '\\')
            .unwrap_or(false);

        if is_escaped {
            character.push(c);
        } else {
            self.tokens.push(Token::Char(character.to_string()));
            self.state = Rc::new(RefCell::new(LexerState::Normal(String::new())));
        }
    }

    fn documentation_push_char(&mut self, c: char, doc: &mut String) {
        doc.push(c);
    }

    fn comment_push_char(
        &mut self,
        new_char: char,
        last_char: &mut char,
        terminator: &CommentTerminator,
    ) {
        match terminator {
            CommentTerminator::Newline => *last_char = new_char,
            CommentTerminator::StarSlash => {
                if new_char == '/' && *last_char == '*' {
                    self.state = Rc::new(RefCell::new(LexerState::Normal(String::new())));
                } else {
                    *last_char = new_char;
                }
            }
        }
    }

    fn push_newline(&mut self) {
        let state = self.state.clone();
        let mut state = state.borrow_mut();

        match &mut *state {
            LexerState::String(sentense) => sentense.push('\n'),
            LexerState::Char(character) => character.push('\n'),
            LexerState::Comment {
                terminator,
                last_char: _,
            } => {
                if let CommentTerminator::Newline = terminator {
                    self.state = Rc::new(RefCell::new(LexerState::Normal(String::new())));
                }
            }
            LexerState::Normal(_) => {
                let last_tokens: Vec<char> = self
                    .tokens
                    .iter()
                    .rev()
                    .take(5)
                    .map(|token| todo!("Convert token to a char (or string)"))
                    .collect();

                if self.is_documentation_boundry(last_tokens) {
                    (0..4).map(|_| self.tokens.pop()); // Remove the last four '='s.
                    self.state = Rc::new(RefCell::new(LexerState::Documentation(String::new())));
                }
            }
            LexerState::Documentation(doc) => {
                // NEXT: Copy is_documentation_boundry but with the string
                // (because Doc pushes even word separators into the string)
            }
        }
    }

    fn is_documentation_boundry(&self, last_tokens: Vec<char>) -> bool {
        if last_tokens.len() != 5 {
            return false;
        }

        let has_four_equals = last_tokens[..4]
            .iter()
            .fold(true, |all_equals, x| all_equals && *x == '\n');

        if !has_four_equals {
            return false;
        }

        return last_tokens[4] == '\n';
    }
}

enum LexerState {
    Normal(String), // We'll spend most of the time here
    String(String),
    Char(String),
    Documentation(String),
    Comment {
        terminator: CommentTerminator,
        last_char: char,
    },
}

enum CommentTerminator {
    Newline,
    StarSlash,
}
