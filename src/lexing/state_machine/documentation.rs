use super::machine_definition::*;
use crate::common::errors;
use crate::lexing::lexer::Character;
use crate::lexing::token::*;

pub struct DocumentationMachine {
    state: DocumentationState,
    documentation: String,
}

impl DocumentationMachine {
    pub fn new() -> Self {
        Self {
            state: DocumentationState::Reading,
            documentation: String::new(),
        }
    }
}

impl StateMachine for DocumentationMachine {
    type ParentState = FileState;

    fn push_char(
        &mut self,
        new_char: Character,
    ) -> errors::Result<MachineState<Self::ParentState>> {
        use DocumentationState::*;

        let new_state = match &self.state {
            Reading => {
                if new_char.char == '\n' {
                    TerminationCandidate
                } else {
                    self.documentation.push(new_char.char);
                    Reading
                }
            }
            TerminationCandidate => {
                if new_char.char == '\n' {
                    self.documentation.push(new_char.char);
                    TerminationCandidate
                } else if new_char.char == '=' {
                    Equal
                } else {
                    self.documentation = format!("{}\n{}", self.documentation, new_char.char);
                    Reading
                }
            }
            Equal => {
                if new_char.char == '\n' {
                    self.documentation = format!("{}\n={}", self.documentation, new_char.char);
                    Reading
                } else if new_char.char == '=' {
                    TwoEqual
                } else {
                    self.documentation.push(new_char.char);
                    Reading
                }
            }
            TwoEqual => {
                if new_char.char == '\n' {
                    self.documentation = format!("{}\n=={}", self.documentation, new_char.char);
                    Reading
                } else if new_char.char == '=' {
                    ThreeEqual
                } else {
                    self.documentation.push(new_char.char);
                    Reading
                }
            }
            ThreeEqual => {
                if new_char.char == '\n' {
                    self.documentation = format!("{}\n==={}", self.documentation, new_char.char);
                    Reading
                } else if new_char.char == '=' {
                    FourEqual
                } else {
                    self.documentation.push(new_char.char);
                    Reading
                }
            }
            FourEqual => {
                if new_char.char == '\n' {
                    let tokens = vec![Token::Documentation(self.documentation.clone())];
                    return Ok(MachineState::Completed(tokens));
                } else {
                    self.documentation = format!("{}\n===={}", self.documentation, new_char.char);
                    Reading
                }
            }
        };

        self.state = new_state;
        return Ok(MachineState::Continuing);
    }

    fn end_of_file(self, file_name: String) -> errors::Result<Vec<Token>> {
        Err(errors::LexingError::no_line(
            "Documentation block not terminated",
            file_name,
        ))
    }
}
