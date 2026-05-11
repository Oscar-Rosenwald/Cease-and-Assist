use super::comment::{CommentMachine, MultilineCommentMachine};
use super::documentation::DocumentationMachine;
use super::types::*;
use crate::lexing::lexer::Character;
use crate::lexing::token::*;

use crate::common::errors;

/// This trait defines a series of states which the lexer goes through on the
/// same level. For example, when reading a constant, the `StateMachine`
/// implementaion will read the contant's name, the `=` sign, and the expression
/// which evaluates to the constant value. It is common for states of the
/// machine to create their own state machines and delegate the next part of the
/// process to them, but from the perspective of the lexer that doesn't matter.
pub trait StateMachine {
    /// The enum of states available to this machine's patent state machine.
    type ParentState;

    /// Give the next character to the StateMachine. Returns the machine state
    /// which may dictate a new transition.
    fn push_char(&mut self, new_char: Character)
    -> errors::Result<MachineState<Self::ParentState>>;

    /// Send a signal to the machine which says we've run out of characters in
    /// the file. The machine must be able to handle this or else it returns an
    /// error. A vector of tokens is returned if this is a valid place to end
    /// the parsing.
    fn end_of_file(self, file_name: String) -> errors::Result<Vec<Token>>;
}

/// For very simple state machines.
pub struct NoState;

/// Generic state of a state machine. Computed and returned after each character
/// is processed.
pub enum MachineState<ParentStateEnum> {
    /// The state machine has completed and is returning with these tokens.
    Completed(Vec<Token>),
    /// The state machine wants more characters.
    Continuing,
    Transition(ParentStateEnum),
}

pub enum FileState {
    /// Reads characters until it's clear which other top-level state we're
    /// going into. This is doable because all other such states start with a
    /// keyword.
    Neutral(String),
    /// Input is ignored until the terminator is reached.
    Comment(CommentMachine),
    /// Input is ignored until the terminator is reached.
    MultilineComment(MultilineCommentMachine),
    /// Markdown block of text surrounded by '====' (must cover the whole line).
    Documentation(DocumentationMachine),
    Struct,
    Enum,
    /// Defines a constant with a static lifetime.
    Constant,
    Function,
    Pipe,
    /// Interface definition.
    Interface,
    Implementation,
    // TODO: 'use' which imports shit
    // TODO: 'database' which defines the database driver, e.g. `database db = db:psql` and thereafter `db:query | delete Device`
}

pub enum CommentState {
    // Bit sparse. That's okey.
    Reading,
}

pub enum MultilineCommentState {
    Reading,
    Star, // Termination candidate
}

/*
====
<any markdown text including strings of = unless there are exactly 4 in a row alone on a line>
====
*/
pub enum DocumentationState {
    Reading,
    TerminationCandidate,
    Equal,
    TwoEqual,
    ThreeEqual,
    FourEqual,
}

pub enum FunctionState {
    Generics,
    Name,
    Arguments,
    Returns,
    Body,
}

// "[" <name> [: <<type>>] [, ...] "]"
enum GenericDeclarationState {
    Name,
    Parameters, // = a type (interface)
}

// "(" <name>: <<type>> [, ...] ")"
enum ArgState {
    Name,
    Type,
}

// [<annotation>] <name> ["<" <<parameter>> [, ...] ">"]
pub enum TypeState {
    NameOrAnnotation(String),
    Name(String), // If annotation found, next must be a name
    Parameters(Box<ParameterMachine>),
}

// "<"  <<type>> [, ...] ">"
pub enum ParameterState {
    Type(Box<TypeMachine>), // Very useful enum, this.
}

/// Parses the return types in pipe/function signatures.
pub enum ReturnState {
    Arrow,
    Name,
    Type,
}

/*
struct <name>["<" <<parameter>> [, ...] ">" ] {
    <<struct-field>> ...
}
*/
pub enum StructState {
    Name,
    Parameters,
    Body,
}

// <name>: <<type>>,
pub enum StructFieldState {
    Name,
    Type,
}

/*
enum <name> {
    <<enum-field>> ...
}
*/
pub enum EnumState {
    Name,
    Field,
}

// <name> [( <<type>> )]
pub enum EnumFieldState {
    Name,
    Type,
}

/// Pipe or function body states.
enum ExecBody {
    Neutral,
    NewVar,
    If,
    Switch,
    For,
    Forever,
    WindowPipe,
    GrabbyPipe,
    Dot,
    Return,
}
