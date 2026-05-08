use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;
use std::{cell::RefCell, rc::Rc};

use super::token::*;
use crate::common::errors::{self, LexingError, ToLexingError};
use crate::common::file::*;

pub fn parse_file(file_path: &Path) -> errors::Result<Vec<Token>> {
    let file_name = file_path
        .file_name()
        .ok_or(LexingError::bare("No such file"))?
        .to_str()
        .ok_or(LexingError::bare("File is broken"))?;

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

        let mut line_length = 0;
        for (char_index, char) in line.chars().enumerate() {
            let location = location.add_column(char_index + 1);
            line_length += 1;
            lexer.push_char(char, location);
        }

        let location = location.add_column(line_length + 1);
        lexer.push_newline(location);
    }

    let location = Location::file(file_name);
    let tokens = lexer.tokens;
    let last_state = Rc::try_unwrap(lexer.state)
        .expect("Who's using my state?")
        .into_inner();

    match last_state {
        LexerState::Normal(_) => Ok(()),
        LexerState::String(_) => Err(LexingError::new("Unterminated string", location)),
        LexerState::Char(_) => Err(LexingError::new("Unterminated character", location)),
        LexerState::Documentation(_) => Err(LexingError::new(
            "Unterminated documentation block",
            location,
        )),
        LexerState::Comment {
            terminator,
            last_char: _,
        } => match terminator {
            CommentTerminator::Newline => Ok(()),
            CommentTerminator::StarSlash => {
                Err(LexingError::new("Unterminated multiline comment", location))
            }
        },
    }?;

    return Ok(tokens);
}

pub struct Lexer {
    state: Rc<RefCell<LexerState>>,
    tokens: Vec<Token>,
}

impl Lexer {
    fn push_char(&mut self, c: char, location: Location) {
        let state = self.state.clone();
        let mut state = state.borrow_mut();

        match &mut *state {
            LexerState::Normal(word) => self.normal_push_char(c, word, location),
            LexerState::String(sentense) => self.string_push_char(c, sentense, location),
            LexerState::Char(character) => self.char_push_char(c, character, location),
            LexerState::Documentation(doc) => self.documentation_push_char(c, doc),
            LexerState::Comment {
                terminator,
                last_char,
            } => self.comment_push_char(c, last_char, terminator),
        }
    }

    fn normal_handle_word(&mut self, word: &str, location: Location) {
        if word.is_empty() {
            return;
        }

        let token = match Keyword::try_from(word) {
            Ok(keyword) => Token::new(TokenType::Keyword(keyword), location),
            Err(_) => Token::new(TokenType::Literal(word.to_string()), location),
        };

        self.tokens.push(token);
        self.state = Rc::new(RefCell::new(LexerState::Normal(String::new())));
    }

    fn normal_push_char(&mut self, c: char, word: &mut String, location: Location) {
        if c.is_whitespace() {
            if !word.is_empty() {
                self.normal_handle_word(&word, location);
            }
            return;
        }

        let last_token = self
            .tokens
            .last()
            .map(|t| t.to_string())
            .unwrap_or(String::new());

        if c == '/' && last_token == "/" {
            self.tokens.pop();
            self.normal_handle_word(word, location);
            self.state = Rc::new(RefCell::new(LexerState::Comment {
                terminator: CommentTerminator::Newline,
                last_char: ' ',
            }));
            return;
        }

        if c == '*' && last_token == "/" {
            self.tokens.pop();
            self.normal_handle_word(word, location);
            self.state = Rc::new(RefCell::new(LexerState::Comment {
                terminator: CommentTerminator::StarSlash,
                last_char: ' ',
            }));
            return;
        }

        if c == STRING_BOUNDRY {
            self.normal_handle_word(word, location);
            self.state = Rc::new(RefCell::new(LexerState::String(String::new())));
            return;
        }

        if c == CHAR_BOUNDRY {
            self.normal_handle_word(word, location);
            self.state = Rc::new(RefCell::new(LexerState::Char(String::new())));
            return;
        }

        match WordSeparator::try_from(c) {
            Ok(separator) => {
                self.normal_handle_word(&word, location.clone());
                self.tokens
                    .push(Token::new(TokenType::WordSeparator(separator), location));
                self.state = Rc::new(RefCell::new(LexerState::Normal(String::new())));
            }
            Err(_) => {
                word.push(c);
                return;
            }
        }
    }

    fn string_push_char(&mut self, c: char, sentense: &mut String, location: Location) {
        if c != STRING_BOUNDRY {
            sentense.push(c);
            return;
        }

        let escaped_chars_count = sentense.chars().rev().take_while(|c| *c == '\\').count();
        let is_escaped = escaped_chars_count % 2 == 1;

        if is_escaped {
            sentense.push(c);
        } else {
            self.tokens.push(Token::new(
                TokenType::String(sentense.to_string()),
                location,
            ));
            self.state = Rc::new(RefCell::new(LexerState::Normal(String::new())));
        }
    }

    fn char_push_char(&mut self, c: char, character: &mut String, location: Location) {
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
            self.tokens
                .push(Token::new(TokenType::Char(character.to_string()), location));
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

    fn push_newline(&mut self, location: Location) {
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
            LexerState::Normal(word) => {
                let last_tokens: Vec<String> = self
                    .tokens
                    .iter()
                    .rev()
                    .take(5)
                    .map(|token| token.to_string())
                    .collect();

                if is_documentation_boundry(last_tokens) {
                    // Remove the last four '='s.
                    (0..4).for_each(|_| {
                        self.tokens.pop();
                    });
                    self.state = Rc::new(RefCell::new(LexerState::Documentation(String::new())));
                } else {
                    self.normal_handle_word(word, location.clone());
                    self.tokens.push(Token::new(TokenType::Newline, location));
                }
            }
            LexerState::Documentation(doc) => {
                let last_chars: Vec<String> =
                    doc.chars().rev().take(5).map(|c| c.to_string()).collect();

                if is_documentation_boundry(last_chars) {
                    // Remove the last four '='s and the extra newline.
                    (0..5).for_each(|_| {
                        doc.pop();
                    });
                    self.tokens.push(Token::new(
                        TokenType::Documentation(doc.to_string()),
                        location,
                    ));
                    self.state = Rc::new(RefCell::new(LexerState::Normal(String::new())));
                } else {
                    doc.push('\n');
                }
            }
        }
    }
}

#[derive(Debug)]
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

#[derive(Debug)]
enum CommentTerminator {
    Newline,
    StarSlash,
}

fn is_documentation_boundry(last_tokens: Vec<String>) -> bool {
    if last_tokens.len() < 4 {
        return false;
    }

    let has_four_equals = last_tokens[..4]
        .iter()
        .fold(true, |all_equals, x| all_equals && *x == "=");

    if !has_four_equals {
        return false;
    }

    if last_tokens.len() == 4 {
        return true;
    }

    return last_tokens[4] == "\n";
}
