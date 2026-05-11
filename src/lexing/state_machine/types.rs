use super::machine_definition::*;
use crate::common::errors;
use crate::lexing::lexer::Character;
use crate::lexing::token::*;

pub struct TypeMachine<T> {
    state: TypeState,
    annotation: Option<TypeAnnotation>,
    name: String,
    parameter: Vec<Token>,
}

impl<T> TypeMachine<T> {
    pub fn new() -> Self {
        Self {
            state: TypeState::NameOrAnnotation(String::new()),
            annotation: None,
            name: String::new(),
            parameter: Vec::new(),
        }
    }
}

impl<T> StateMachine for TypeMachine<T> {
    type ParentState = T;

    fn push_char(
        &mut self,
        new_char: Character,
    ) -> errors::Result<MachineState<Self::ParentState>> {
        let new_state = match &mut self.state {
            TypeState::NameOrAnnotation(word) => {
                let is_whitespace = new_char.char.is_whitespace();
                if is_whitespace && word.is_empty() {
                    None
                } else if is_whitespace {
                    if let Ok(annotation) = TypeAnnotation::try_from(word.as_str()) {
                        self.annotation = Some(annotation);
                        Some(TypeState::Name(String::new()))
                    } else {
                        Some(TypeState::Name(word.clone()))
                    }
                    // TODO: what if it's a parameter start?
                } else {
                    word.push(new_char.char);
                    if word.len() == 1 {
                        if let Ok(annotation) = TypeAnnotation::try_from(word.as_str()) {
                            self.annotation = Some(annotation);
                            Some(TypeState::Name(String::new()))
                        } else {
                            None
                        }
                    } else {
                        None
                    }
                }
            }
            TypeState::Name(word) => todo!(),
            TypeState::Parameters(sm) => sm.push_char(new_char),
        };

        if let Some(state) = new_state {
            self.state = state;
        }

        return Ok(MachineState::Continuing);
    }

    fn end_of_file(self, file_name: String) -> errors::Result<Vec<Token>> {
        Err(errors::LexingError::no_line(
            "Type definition terminated unexpectedly",
            file_name,
        ))
    }
}

pub struct ParameterMachine<T> {
    state: ParameterState,
}

impl<T> ParameterMachine<T> {
    fn new() -> Self {
        Self {
            state: ParameterState::Type(Box::new(TypeMachine::new())),
        }
    }
}

impl<T> StateMachine for ParameterMachine<T> {
    type ParentState = T;

    fn push_char(
        &mut self,
        new_char: Character,
    ) -> errors::Result<MachineState<Self::ParentState>> {
        todo!()
    }

    fn end_of_file(self, file_name: String) -> errors::Result<Vec<Token>> {
        todo!()
    }
}
