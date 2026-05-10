use super::machine_definition::*;
use crate::common::errors;
use crate::lexing::lexer::Character;
use crate::lexing::token::*;

pub struct CommentMachine {
    state: CommentState,
}

impl CommentMachine {
    pub fn new() -> Self {
        Self {
            state: CommentState::Reading,
        }
    }
}

impl StateMachine for CommentMachine {
    type ParentState = FileState;

    fn push_char(&mut self, new_char: Character) -> errors::Result<MachineState<FileState>> {
        if new_char.char == '\n' {
            return Ok(MachineState::Completed(vec![]));
        }
        return Ok(MachineState::Continuing);
    }

    fn end_of_file(self, _file_name: String) -> errors::Result<Vec<Token>> {
        Ok(vec![])
    }
}

pub struct MultilineCommentMachine {
    state: MultilineCommentState,
}

impl MultilineCommentMachine {
    pub fn new() -> Self {
        Self {
            state: MultilineCommentState::Reading,
        }
    }
}

impl StateMachine for MultilineCommentMachine {
    type ParentState = FileState;

    fn push_char(
        &mut self,
        new_char: Character,
    ) -> errors::Result<MachineState<Self::ParentState>> {
        use MultilineCommentState::*;
        let new_state = match &self.state {
            Reading => {
                if new_char.char == '*' {
                    Star
                } else {
                    Reading
                }
            }
            Star => {
                if new_char.char == '/' {
                    return Ok(MachineState::Completed(vec![]));
                } else {
                    Reading
                }
            }
        };

        self.state = new_state;
        return Ok(MachineState::Continuing);
    }

    fn end_of_file(self, file_name: String) -> errors::Result<Vec<Token>> {
        Err(errors::LexingError::no_line(
            "Unterminated multiline comment",
            file_name,
        ))
    }
}
