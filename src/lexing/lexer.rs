use super::state_machine::{
    file::FileMachine,
    machine_definition::{MachineState, StateMachine},
};
use super::token::Token;
use crate::common::file::{FileLine, FileLocation};

use anyhow::{Result, anyhow};
use std::fs::File;
use std::io::{self, BufRead};
use std::iter::Iterator;
use std::path::PathBuf;

/// Lexer turns a file into a list of tokens.
pub struct Lexer {
    src_file: SourceFile,
}

impl Lexer {
    pub fn new(src_file: PathBuf) -> Result<Self> {
        Ok(Self {
            src_file: SourceFile::new(src_file)
                .map_err(|e| anyhow!("Failed to initialise source file: {e}"))?,
        })
    }

    pub fn parse(self) -> Result<Vec<Token>> {
        let mut state_machine = FileMachine::new();
        let mut tokens = Vec::new();
        let file_name = self.src_file.file_name.clone();

        for char in self.src_file {
            let char = char.map_err(|e| anyhow!("Failed to read next character: {e}"))?;
            let machine_state = state_machine.push_char(char).map_err(|e| anyhow!("{e}"))?;

            match machine_state {
                MachineState::Continuing => {}
                MachineState::Completed(mut new_tokens) => tokens.append(&mut new_tokens),
                MachineState::Transition(_) => {
                    unreachable!("The top-level machine cannot transition anywhere. Are you dumb?")
                }
            }
        }

        let mut final_tokens = state_machine
            .end_of_file(file_name)
            .map_err(|e| anyhow!("{e}"))?;

        tokens.append(&mut final_tokens);

        return Ok(tokens);
    }
}

/// Merges the character and its location within a file.
pub(super) struct Character {
    pub char: char,
    pub location: FileLocation,
}

pub(super) struct SourceFile {
    file_name: String,

    /// Iterates over the lines of a file. Each line is then converted into
    /// `self.current_line_chars`. A new line is read when the chars run out.
    lines: io::Lines<io::BufReader<File>>,

    /// Character representation of the current line. Accessed via
    /// `self.current_char_offset`. When no more characters are available, a new
    /// line is read from `self.lines`.
    current_line_chars: Vec<char>,

    /// Points to the character in `self.current_line_chars` that is to be
    /// parsed next.
    current_char_offset: usize,

    /// The [`FileLine`] (without column) of the current line.
    current_location: FileLine,

    /// True when we've reached the end of the current line
    /// (`self.current_line_chars`) and we also sent the Newline character.
    /// Newlines aren't a part of the chars, so we need to simulate them
    /// manually.
    end_of_line_sent: bool,
}

impl<'a> SourceFile {
    fn new(path: PathBuf) -> io::Result<Self> {
        let file_name = path
            .file_name()
            .ok_or(io::Error::new(
                io::ErrorKind::InvalidData,
                "no filename of source file",
            ))?
            .to_str()
            .ok_or(io::Error::new(
                io::ErrorKind::InvalidData,
                "filename cannot be stringified (what?)",
            ))?
            .to_string();

        let file = File::open(&path)?;
        let mut lines = io::BufReader::new(file).lines();

        let current_line = match lines.next() {
            None => String::new(),
            Some(line) => line?,
        };

        let me = Self {
            file_name: file_name.clone(),
            lines,
            current_line_chars: current_line.chars().collect(),
            current_char_offset: 0,
            current_location: FileLine::new(file_name, 1),
            end_of_line_sent: false,
        };

        return Ok(me);
    }

    /// After reaching the end of a line, call this to load the next line of the
    /// source file into memory and update all internal fields to reflect this
    /// fact. Makes no checks as to whether that line is empty. Returns `None`
    /// when EOF.
    fn load_new_line(&mut self) -> Option<io::Result<()>> {
        let next_line = match self.lines.next()? {
            Ok(line) => line,
            Err(e) => {
                let msg = format!("Failed to read next line: {e}");
                return Some(Err(io::Error::new(e.kind(), msg)));
            }
        };

        self.current_line_chars = next_line.chars().collect();
        self.current_char_offset = 0;

        self.current_location = FileLine::new(
            self.current_location.file_name(),
            self.current_location.line_number() + 1,
        );

        return Some(Ok(()));
    }

    /// Loads lines of the source file until it finds a non-empty one. Then
    /// returns the first character of that line. Returning `None` means EOF.
    fn next_char_after_newline(&mut self) -> Option<io::Result<char>> {
        loop {
            if let Err(e) = self.load_new_line()? {
                let msg = format!("Failed to load next line: {e}");
                return Some(Err(io::Error::new(e.kind(), msg)));
            };

            match self.current_line_chars.get(self.current_char_offset) {
                None => continue,
                Some(c) => return Some(Ok(*c)),
            }
        }
    }
}

impl<'a> Iterator for SourceFile {
    type Item = io::Result<Character>;

    fn next(&mut self) -> Option<Self::Item> {
        let next_inline_char = self.current_line_chars.get(self.current_char_offset);

        let next_char = if let Some(c) = next_inline_char {
            *c
        } else if !self.end_of_line_sent {
            self.end_of_line_sent = true;
            let location = self
                .current_location
                .add_column(self.current_char_offset + 1);
            return Some(Ok(Character {
                char: '\n',
                location,
            }));
        } else {
            self.end_of_line_sent = false;
            match self.next_char_after_newline()? {
                Ok(c) => c,
                Err(e) => {
                    return Some(Err(io::Error::new(
                        e.kind(),
                        format!("Failed to jump to next line: {e}"),
                    )));
                }
            }
        };

        let location = self
            .current_location
            .add_column(self.current_char_offset + 1);

        let ret = Character {
            char: next_char,
            location: location,
        };

        self.current_char_offset += 1;

        return Some(Ok(ret));
    }
}
