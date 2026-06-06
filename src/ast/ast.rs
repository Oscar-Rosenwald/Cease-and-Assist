use super::expression::*;
use super::statement::*;
use crate::common::errors::*;
use crate::common::file::*;

use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;

pub struct Tree {
    root: Rc<RefCell<Node>>,
}

impl Tree {
    pub fn from_tokens(tokens: VecDeque<Token>) -> LexResult<Tree> {
        let root = Rc::new(RefCell::new(Node::new_root()));
        let children = Node::parse_subtree(root.clone(), tokens)?;
        let mut root_mut = root.borrow_mut();
        root_mut.children = children;

        return Ok(Self { root: root.clone() });
    }
}

pub struct Node {
    kind: NodeKind,
    location: FileLocation,
    parent: Option<Rc<RefCell<Node>>>,
    children: Vec<Rc<RefCell<Node>>>,
}

impl Node {
    fn new_root() -> Self {
        Node {
            children: Vec::new(),
            kind: NodeKind::Root,
            parent: None,
            location: FileLocation::none(),
        }
    }

    fn parse_subtree(
        parent: Rc<RefCell<Node>>,
        mut tokens: VecDeque<Token>,
    ) -> LexResult<Vec<Rc<RefCell<Node>>>> {
        let mut nodes_ret = Vec::new();

        loop {
            let (node_kind, other_tokens) = match Expression::parse_tokens(tokens) {
                Err(ast_error) => (NodeKind::Error(ast_error.error), ast_error.tokens),
                Ok(expression) => (NodeKind::Expression(expression.0), expression.1),
            };

            let node = Node {
                location: node_kind.location(),
                kind: node_kind,
                parent: Some(parent.clone()),
                children: Vec::new(),
            };

            nodes_ret.push(Rc::new(RefCell::new(node)));

            if other_tokens.is_empty() {
                return Ok(nodes_ret);
            }

            tokens = other_tokens;
        }
    }
}

pub enum NodeKind {
    /// The top node of a tree, with no parents.
    Root,
    Expression(Expression),
    Statement(Statement),
    Error(AstError),
}

#[cfg(test)]
mod test {
    use crate::ast::*;
    use crate::common::file::*;
    use std::cell::RefCell;
    use std::collections::VecDeque;
    use std::rc::Rc;

    fn file_name() -> String {
        String::from("file.stop")
    }

    #[test]
    fn maths1() {
        let line = vec![TokenType::Keyword(Keyword::True)];
        let line: VecDeque<Token> = line
            .into_iter()
            .map(|t| {
                Token::new(
                    t,
                    Location::line(file_name(), 1),
                    Location::line(file_name(), 2),
                )
            })
            .collect();

        let root = Rc::new(RefCell::new(Node::new_root()));
        let actual = Node::parse_subtree(root, line).unwrap();
    }

    #[test]
    fn maths() {
        // (1 + 2 < 3 * 4 / -5 ^ 6 == 7 - -(8 * 9)) and true
        //     let line = vec![
        //     // st
        //             ];

        //     let mut root = Node::new_root();
    }
}
