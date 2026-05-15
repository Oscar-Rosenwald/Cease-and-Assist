use super::{expression::expression::*, statement::*};
use crate::common::file::*;
use crate::lexing::token::*;

pub struct Tree {
    root: Vec<Node>,
}

pub struct Node {
    pub kind: NodeKind,
    pub children: Vec<Node>,
    pub start_location: Location,
    pub end_location: Location,
}

pub enum NodeKind {
    Expression(Expression),
    Statement(Statement),
}

fn split_by_expression(tokens: Vec<Token>) -> Vec<Vec<Token>> {
    todo!()
}
