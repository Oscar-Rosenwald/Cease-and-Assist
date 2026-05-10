use super::comment::*;
use super::documentation::*;
use super::machine_definition::*;
use crate::common::errors;
use crate::lexing::lexer::Character;
use crate::lexing::token::*;

pub struct FileMachine {
    state: FileState,
    known_tokens: Vec<Token>,
}

impl FileMachine {
    pub fn new() -> Self {
        Self {
            state: FileState::Neutral(String::new()),
            known_tokens: Vec::new(),
        }
    }
}

impl StateMachine for FileMachine {
    type ParentState = NoState;

    fn push_char(&mut self, new_char: Character) -> errors::Result<MachineState<NoState>> {
        let machine_state = match &mut self.state {
            FileState::Neutral(word) => Ok(Self::push_char_to_neutral(word, new_char)),
            FileState::Comment(sm) => sm.push_char(new_char),
            FileState::MultilineComment(sm) => sm.push_char(new_char),
            FileState::Documentation(sm) => sm.push_char(new_char),
            FileState::Constant => todo!(),
            FileState::Interface => todo!(),
            FileState::Struct => todo!(),
            FileState::Enum => todo!(),
            FileState::Function => todo!(),
            FileState::Pipe => todo!(),
            FileState::Implementation => todo!(),
        };

        match machine_state? {
            MachineState::Continuing => Ok(MachineState::Continuing),
            MachineState::Completed(mut tokens) => {
                self.state = FileState::Neutral(String::new());
                self.known_tokens.append(&mut tokens);
                Ok(MachineState::Continuing)
            }
            MachineState::Transition(next_state) => {
                self.state = next_state;
                Ok(MachineState::Continuing)
            }
        }
    }

    fn end_of_file(self, file_name: String) -> errors::Result<Vec<Token>> {
        match self.state {
            FileState::Neutral(ref word) => {
                Self::process_neutral_eof(word, file_name, self.known_tokens)
            }
            FileState::Comment(sm) => sm.end_of_file(file_name),
            FileState::MultilineComment(sm) => sm.end_of_file(file_name),
            FileState::Documentation(sm) => sm.end_of_file(file_name),
            FileState::Constant => todo!(),
            FileState::Interface => todo!(),
            FileState::Struct => todo!(),
            FileState::Enum => todo!(),
            FileState::Function => todo!(),
            FileState::Pipe => todo!(),
            FileState::Implementation => todo!(),
        }
    }
}

impl FileMachine {
    fn push_char_to_neutral(word: &mut String, new_char: Character) -> MachineState<FileState> {
        if new_char.char != '/' && *word == "//" {
            return MachineState::Transition(FileState::Comment(CommentMachine::new()));
        }

        if new_char.char == '*' && *word == "/" {
            return MachineState::Transition(FileState::MultilineComment(
                MultilineCommentMachine::new(),
            ));
        }

        if new_char.char == '\n' && *word == "====" {
            return MachineState::Transition(FileState::Documentation(DocumentationMachine::new()));
        }

        // TODO

        word.push(new_char.char);

        return MachineState::Continuing;
    }

    fn process_neutral_eof(
        word: &String,
        file_name: String,
        tokens: Vec<Token>,
    ) -> errors::Result<Vec<Token>> {
        if word.is_empty() {
            return Ok(tokens);
        }

        return Err(errors::LexingError::no_line(
            format!("Trailing garbage. Shite, even."),
            file_name,
        ));
    }
}
