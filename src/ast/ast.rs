use super::expression::*;
use super::statement::*;
use crate::common::errors::*;
use crate::common::file::*;
use crate::lexing::*;

use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;

pub struct Tree {
    root: Node,
}

pub struct Node {
    kind: NodeKind,
    location: FileLocation,
    parent: Option<Rc<RefCell<Node>>>,
    children: Vec<Node>,
}

pub enum NodeKind {
    /// The top node of a tree, with no parents.
    Root,
    Expression(Expression),
    Statement(Statement),
}

impl Tree {
    pub fn parse_tokens(mut tokens: VecDeque<Token>) -> LexResult<Tree> {
        let tree = parse_subtree(tokens)?;
        return Self {
            root: Node {
                kind: NodeKind::Root,
            },
        };
    }
}

fn parse_subtree(mut _tokens: VecDeque<Token>) -> LexResult<Vec<Node>> {
    todo!()
}
