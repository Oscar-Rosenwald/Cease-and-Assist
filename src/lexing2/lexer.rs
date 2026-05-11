use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

use super::token::*;
use crate::common::errors::{self, LexingError};
use crate::common::file::*;

pub fn parse_file(file_path: &Path) -> errors::Result<Vec<Token>> {
    let file_name = file_path
        .file_name()
        .ok_or(errors::LexingError::no_file("No such file"))?
        .to_str()
        .ok_or(errors::LexingError::no_file("File is broken"))?;

    let file = File::open(file_path).map_err(|e| {
        let msg = format!("Cannot open file: {e}");
        errors::LexingError::no_line(msg, file_name)
    })?;

    let lines = io::BufReader::new(file).lines();

    let mut lexer = Lexer {
        state: LexerState::Other,
        tokens: Vec::new(),
        current_word: String::new(),
    };

    for (line_index, line) in lines.enumerate() {
        let location = FileLine::new(file_name, line_index + 1); // Lines start from 1

        let line = line.map_err(|e| {
            let msg = format!("Failed to read line: {e}");
            errors::LexingError::new(msg, location.add_column(0))
        })?;

        for word in line.split_whitespace() {
            todo!()
        }

        lexer.push_newline();
    }

    todo!()
}

pub struct Lexer {
    state: LexerState,
    tokens: Vec<Token>,
    current_word: String,
}

impl Lexer {
    fn push_newline(&mut self) {
        let last = self.tokens.last();
        if last.eq(&Some(&Token::Newline)) {
            return;
        }

        match &self.state {
            LexerState::String => self.tokens.push(Token::Newline),
            LexerState::Documentation => self.tokens.push(Token::Newline),
            LexerState::Other => self.tokens.push(Token::Newline),
            LexerState::Comment(terminator) => match terminator {
                CommentTerminator::Newline => self.state = LexerState::Other,
                CommentTerminator::StarSlash => {}
            },
        }
    }
}

enum LexerState {
    String,
    Documentation,
    Comment(CommentTerminator),
    Other, // We'll spend most of the time here
}

enum CommentTerminator {
    Newline,
    StarSlash,
}
