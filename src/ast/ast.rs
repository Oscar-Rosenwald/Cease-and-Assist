use super::*;

use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;

pub struct Tree {
    root: Rc<RefCell<Node>>,
}

impl Tree {
    pub fn parse_tokens(tokens: VecDeque<Token>) -> AstResult<Self> {
        let root = Rc::new(RefCell::new(Node::new_root()));
        let tree = Node::parse_subtree(root.clone(), tokens);

        {
            let mut root_mut = root.borrow_mut();
            root_mut.kind = NodeKind::Root { children: tree };
        }

        return Ok(Self { root });
    }
}

#[derive(Debug, PartialEq, Eq)]
pub struct Node {
    kind: NodeKind,
    location: FileLocation,
}

impl Node {
    fn new_root() -> Self {
        Node {
            location: FileLocation::none(),
            kind: NodeKind::Root {
                children: Vec::new(),
            },
        }
    }

    fn parse_subtree(
        parent: Rc<RefCell<Node>>,
        mut tokens: VecDeque<Token>,
    ) -> Vec<Rc<RefCell<Node>>> {
        let mut nodes_ret = Vec::new();

        loop {
            tokens.pop_front_if(|front| {
                if let TokenType::Newline = &front.type_ {
                    true
                } else {
                    false
                }
            });

            if tokens.is_empty() {
                return nodes_ret;
            }

            let (node_kind, other_tokens) = match Expression::parse_tokens(tokens) {
                Err(ast_error) => (
                    NodeKind::Error {
                        error_message: ast_error.message,
                        failing_tokens: ast_error.failing_tokens,
                    },
                    ast_error.remaining_tokens,
                ),
                Ok(expression) => (
                    NodeKind::Expression {
                        expression: expression.0,
                        parent: parent.clone(),
                    },
                    expression.1,
                ),
            };

            let node = Node {
                location: node_kind.location(),
                kind: node_kind,
            };

            nodes_ret.push(Rc::new(RefCell::new(node)));

            if other_tokens.is_empty() {
                return nodes_ret;
            }

            tokens = other_tokens;
        }
    }
}

#[derive(Debug, PartialEq, Eq)]
pub enum NodeKind {
    /// The top node of a tree, with no parents.
    Root { children: Vec<Rc<RefCell<Node>>> },
    Expression {
        expression: Expression,
        parent: Rc<RefCell<Node>>,
    },
    Statement {
        statement: Statement,
        children: Vec<Rc<RefCell<Node>>>,
        parent: Rc<RefCell<Node>>,
    },
    Error {
        error_message: String,
        failing_tokens: Vec<Token>,
    },
}

impl NodeKind {
    fn location(&self) -> FileLocation {
        match self {
            Self::Root { children } => FileLocation {
                start_location: children.first().map_or_else(
                    || Location::None,
                    |child| child.borrow().kind.location().start_location.clone(),
                ),
                end_location: children
                    .last()
                    .map(|child| child.borrow().kind.location().end_location.unwrap().clone()),
            },
            Self::Expression {
                expression,
                parent: _,
            } => expression.location(),
            Self::Statement {
                statement: _,
                children: _,
                parent: _,
            } => unimplemented!("Statements to be done"),
            Self::Error {
                error_message: _,
                failing_tokens,
            } => FileLocation {
                end_location: failing_tokens.last().map(|x| x.end_location.clone()),
                start_location: failing_tokens
                    .first()
                    .map(|x| x.start_location.clone())
                    .unwrap_or_else(|| Location::None),
            },
        }
    }
}

#[cfg(test)]
mod test {
    use crate::ast::*;
    use crate::common::file::*;
    use pretty_assertions::assert_eq;
    use std::cell::RefCell;
    use std::collections::VecDeque;
    use std::rc::Rc;

    fn file_name() -> String {
        String::from("file.stop")
    }

    /// Produces a [`Location`] from the given file and line.
    /// [`file_name`] is used as the file name.
    macro_rules! loc {
        ($line:expr, $column:expr) => {
            Location::column(file_name(), $line, $column)
        };
    }

    /// Produces the vector to pass to [`test_expression`].
    ///
    /// `token_type` is just the name of the [`TokenType`] variant, e.g.
    /// `Keyword`.
    ///
    /// `token`, if given, is the inner value of the [`TokenType`] variable,
    /// e.g. `Keyword::False`. For some token types you don't supply this
    /// because it would be dumb, like `Newline`. What what you put in?
    ///
    /// `start` and `end` are [`Location`]s (usually produced with the [`loc`]
    /// macro.
    ///
    /// # Examples:
    ///
    /// ```rust
    ///     let tokens = token!(
    ///         Keyword (Keyword::True), loc!(1,0), loc!(1,1);
    ///         Newline, loc!(1,2), loc!(1,2);
    ///     );
    ///     let expected = // Create expression
    ///     test_expression(tokens, expected);
    /// ```
    macro_rules! tokens {
        ( $( [ $token_type:ident $( ($token:expr) )?, [ $start_line:expr, $start_column:expr ], [ $end_line:expr, $end_column:expr ] ] ),+ $(,)? ) => {
            vec![ $( (TokenType::$token_type $( ($token) )?, loc!($start_line, $start_column), loc!($end_line, $end_column)) ),+ ]
        };
    }

    /// Performs a test where a given expected [`ExpressionTrait`]
    /// implementation is compared against the a list of tokens. The tokens are
    /// converted into an expression, then the comparison happens.
    ///
    /// # Usage
    ///
    /// ```
    /// test_expr!( <known-expected-value>, <type-of-the-expected-value>, <tokens-to-convert-to-expected-type>)
    /// ```
    macro_rules! test_expr {
        ( $expected:expr, $expr_type:ty, $actual_tokens:expr ) => {
            let line: VecDeque<Token> = $actual_tokens
                .into_iter()
                .map(|(t, start, end)| Token::new(t, start, end))
                .collect();

            let (actual, rest) = <$expr_type>::parse_tokens(line).unwrap();

            assert_eq!($expected, actual);
            assert_eq!(VecDeque::new(), rest);
        };
    }

    fn location(start: Location, end: Location) -> FileLocation {
        FileLocation {
            start_location: start,
            end_location: Some(end),
        }
    }

    fn test_expression<E: ExpressionTrait>(
        actual_tokens: Vec<(TokenType, Location, Location)>,
        expected: E,
    ) {
        let start = actual_tokens.first().unwrap().1.clone();
        let end = actual_tokens.last().unwrap().2.clone();
        test_expression_with_locaiton(actual_tokens, expected, start, end);
    }

    fn test_expression_with_locaiton<E: ExpressionTrait>(
        actual_tokens: Vec<(TokenType, Location, Location)>,
        expected: E,
        expression_start: Location,
        expression_end: Location,
    ) {
        let line: VecDeque<Token> = actual_tokens
            .into_iter()
            .map(|(t, start, end)| Token::new(t, start, end))
            .collect();

        let root = Rc::new(RefCell::new(Node::new_root()));
        let actual = Node::parse_subtree(root.clone(), line);

        let expected = Node {
            kind: NodeKind::Expression {
                expression: expected.to_expression(),
                parent: root,
            },
            location: location(expression_start, expression_end),
        };
        let expected = vec![Rc::new(RefCell::new(expected))];

        assert_eq!(expected, actual);
    }

    #[test] // true
    fn maths_true() {
        let actual = tokens!(
            [Newline, [1, 0], [1, 0]],
            [Keyword(Keyword::True), [2, 0], [2, 1]],
            [Newline, [2, 2], [2, 2]],
        );

        let expected = Base::new(
            BaseKind::Literal(Literal::Bool(true)),
            location(loc!(2, 0), loc!(2, 1)),
        );

        test_expression_with_locaiton(actual, expected, loc!(2, 0), loc!(2, 1));
    }

    #[test] // -7
    fn maths_unary() {
        let actual = tokens!(
            [WordSeparator(WordSeparator::Minus), [1, 0], [1, 1]],
            [Number(7), [1, 3], [1, 4]]
        );

        let base = Base::new(
            BaseKind::Literal(Literal::WholeNumber(7)),
            location(loc!(1, 3), loc!(1, 4)),
        );

        let unary = expression::Unary {
            operation: Some(operation::Unary::Negate),
            base,
            start_location: loc!(1, 0),
        };

        test_expression(actual, unary);
    }

    #[test] // true ^& !false
    fn maths_binary_arithmetic() {
        use WordSeparator::Exclamation;
        let actual = tokens!(
            [Keyword(Keyword::True), [1, 0], [1, 3]],
            [Symbol(Symbol::BitAnd), [1, 5], [1, 7]],
            [WordSeparator(Exclamation), [1, 9], [1, 10]],
            [Keyword(Keyword::False), [1, 12], [1, 16]],
        );

        let base1 = Base::new(
            BaseKind::Literal(Literal::Bool(true)),
            location(loc!(1, 0), loc!(1, 3)),
        );
        let unary1 = expression::Unary {
            base: base1,
            operation: None,
            start_location: loc!(1, 0),
        };

        let base2 = Base::new(
            BaseKind::Literal(Literal::Bool(false)),
            location(loc!(1, 12), loc!(1, 16)),
        );
        let unary2 = expression::Unary {
            base: base2,
            operation: Some(operation::Unary::Not),
            start_location: loc!(1, 9),
        };

        let binary = expression::BinaryArithmetic {
            base: unary1,
            rest: Some((operation::BinaryArithmetic::And, unary2)),
        };

        test_expr!(binary, expression::BinaryArithmetic, actual);
    }

    #[test]
    fn maths_bitwise_and() {
        let tokens = tokens!(
            [WordSeparator(WordSeparator::Minus), [1, 9], [1, 9]],
            [Number(5), [1, 10], [1, 10]],
            [Symbol(Symbol::BitAnd), [1, 11], [1, 11]],
            [Number(6), [1, 12], [1, 12]],
        );

        test_expr!(bit_and(), expression::BinaryArithmetic, tokens);
    }

    #[test]
    fn maths_add() {
        let tokens = tokens!(
            [Number(1), [1, 1], [1, 1]],
            [WordSeparator(WordSeparator::Plus), [1, 2], [1, 2]],
            [Number(2), [1, 3], [1, 3]],
        );

        test_expr!(one_plus_two(), expression::Sum, tokens);
    }

    #[test]
    fn negated_product() {
        let tokens = tokens!(
            [WordSeparator(WordSeparator::Minus), [1, 16], [1, 16]],
            [WordSeparator(WordSeparator::LeftParen), [1, 17], [1, 21]],
            [Number(8), [1, 18], [1, 18]],
            [WordSeparator(WordSeparator::Star), [1, 19], [1, 19]],
            [Number(9), [1, 20], [1, 20]],
            [WordSeparator(WordSeparator::RightParen), [1, 21], [1, 21]],
        );

        test_expr!(minus_eight_times_nine(), expression::Unary, tokens);
    }

    #[test]
    fn maths_negated_sum() {
        let tokens = tokens!(
            [Number(7), [1, 14], [1, 14]],
            [WordSeparator(WordSeparator::Minus), [1, 15], [1, 15]],
            [WordSeparator(WordSeparator::Minus), [1, 16], [1, 16]],
            [WordSeparator(WordSeparator::LeftParen), [1, 17], [1, 21]],
            [Number(8), [1, 18], [1, 18]],
            [WordSeparator(WordSeparator::Star), [1, 19], [1, 19]],
            [Number(9), [1, 20], [1, 20]],
            [WordSeparator(WordSeparator::RightParen), [1, 21], [1, 21]],
        );

        test_expr!(seven_minus_group(), expression::Sum, tokens);
    }

    #[test]
    fn maths_product_division() {
        let tokens = tokens!(
            [Number(3), [1, 5], [1, 5]],
            [WordSeparator(WordSeparator::Star), [1, 6], [1, 6]],
            [Number(4), [1, 7], [1, 7]],
            [WordSeparator(WordSeparator::Slash), [1, 8], [1, 8]],
            [WordSeparator(WordSeparator::Minus), [1, 9], [1, 9]],
            [Number(5), [1, 10], [1, 10]],
            [Symbol(Symbol::BitAnd), [1, 11], [1, 12]],
            [Number(6), [1, 12], [1, 12]],
        );

        test_expr!(three_times_four_div_bitand(), expression::Product, tokens);
    }

    #[test]
    fn maths_comparison() {
        let tokens = tokens!(
            [Number(1), [1, 1], [1, 1]],
            [WordSeparator(WordSeparator::Plus), [1, 2], [1, 2]],
            [Number(2), [1, 3], [1, 3]],
            [WordSeparator(WordSeparator::LeftChevron), [1, 4], [1, 4]],
            [Number(3), [1, 5], [1, 5]],
            [WordSeparator(WordSeparator::Star), [1, 6], [1, 6]],
            [Number(4), [1, 7], [1, 7]],
            [WordSeparator(WordSeparator::Slash), [1, 8], [1, 8]],
            [WordSeparator(WordSeparator::Minus), [1, 9], [1, 9]],
            [Number(5), [1, 10], [1, 10]],
            [Symbol(Symbol::BitAnd), [1, 11], [1, 11]],
            [Number(6), [1, 12], [1, 12]],
        );

        test_expr!(less_than(), expression::Comparison, tokens);
    }

    #[test]
    fn maths_equality() {
        let tokens = tokens!(
            [Number(1), [1, 1], [1, 1]],
            [WordSeparator(WordSeparator::Plus), [1, 2], [1, 2]],
            [Number(2), [1, 3], [1, 3]],
            [WordSeparator(WordSeparator::LeftChevron), [1, 4], [1, 4]],
            [Number(3), [1, 5], [1, 5]],
            [WordSeparator(WordSeparator::Star), [1, 6], [1, 6]],
            [Number(4), [1, 7], [1, 7]],
            [WordSeparator(WordSeparator::Slash), [1, 8], [1, 8]],
            [WordSeparator(WordSeparator::Minus), [1, 9], [1, 9]],
            [Number(5), [1, 10], [1, 10]],
            [Symbol(Symbol::BitAnd), [1, 11], [1, 11]],
            [Number(6), [1, 12], [1, 12]],
            [Symbol(Symbol::EqualEqual), [1, 13], [1, 13]],
            [Number(7), [1, 14], [1, 14]],
            [WordSeparator(WordSeparator::Minus), [1, 15], [1, 15]],
            [WordSeparator(WordSeparator::Minus), [1, 16], [1, 16]],
            [WordSeparator(WordSeparator::LeftParen), [1, 17], [1, 21]],
            [Number(8), [1, 18], [1, 18]],
            [WordSeparator(WordSeparator::Star), [1, 19], [1, 19]],
            [Number(9), [1, 20], [1, 20]],
            [WordSeparator(WordSeparator::RightParen), [1, 21], [1, 21]],
        );

        test_expr!(equality(), expression::Equality, tokens);
    }

    #[test]
    fn maths() {
        let tokens = tokens!(
            [WordSeparator(WordSeparator::LeftParen), [1, 0], [1, 0]],
            [Number(1), [1, 1], [1, 1]],
            [WordSeparator(WordSeparator::Plus), [1, 2], [1, 2]],
            [Number(2), [1, 3], [1, 3]],
            [WordSeparator(WordSeparator::LeftChevron), [1, 4], [1, 4]],
            [Number(3), [1, 5], [1, 5]],
            [WordSeparator(WordSeparator::Star), [1, 6], [1, 6]],
            [Number(4), [1, 7], [1, 7]],
            [WordSeparator(WordSeparator::Slash), [1, 8], [1, 8]],
            [WordSeparator(WordSeparator::Minus), [1, 9], [1, 9]],
            [Number(5), [1, 10], [1, 10]],
            [Symbol(Symbol::BitAnd), [1, 11], [1, 11]],
            [Number(6), [1, 12], [1, 12]],
            [Symbol(Symbol::EqualEqual), [1, 13], [1, 13]],
            [Number(7), [1, 14], [1, 14]],
            [WordSeparator(WordSeparator::Minus), [1, 15], [1, 15]],
            [WordSeparator(WordSeparator::Minus), [1, 16], [1, 16]],
            [WordSeparator(WordSeparator::LeftParen), [1, 17], [1, 21]],
            [Number(8), [1, 18], [1, 18]],
            [WordSeparator(WordSeparator::Star), [1, 19], [1, 19]],
            [Number(9), [1, 20], [1, 20]],
            [WordSeparator(WordSeparator::RightParen), [1, 21], [1, 21]],
            [WordSeparator(WordSeparator::RightParen), [1, 22], [1, 22]],
            [Keyword(Keyword::And), [1, 23], [1, 23]],
            [Keyword(Keyword::True), [1, 24], [1, 24]],
        );

        test_expr!(full_expression(), expression::Logic, tokens);
    }

    // -5
    fn minus_five() -> expression::Unary {
        expression::Unary {
            operation: Some(operation::Unary::Negate),
            start_location: loc!(1, 9),
            base: number(5, location(loc!(1, 10), loc!(1, 10))),
        }
    }

    // -5 ^& 6
    fn bit_and() -> expression::BinaryArithmetic {
        expression::BinaryArithmetic {
            base: minus_five(),
            rest: Some((operation::BinaryArithmetic::And, unary(6, loc!(1, 12)))),
        }
    }

    // 3 * 4 / -5 ^& 6
    fn three_times_four_div_bitand() -> expression::Product {
        let base = binary_arithmetic(3, loc!(1, 5));
        let rest1 = binary_arithmetic(4, loc!(1, 7));
        let rest2 = bit_and();

        expression::Product {
            base: base,
            rest: vec![
                (operation::Product::Multiply, rest1),
                (operation::Product::Divide, rest2),
            ],
        }
    }

    // 1 + 2
    fn one_plus_two() -> expression::Sum {
        expression::Sum {
            base: product(1, loc!(1, 1)),
            rest: vec![(operation::Sum::Plus, product(2, loc!(1, 3)))],
        }
    }

    // 1 + 2 < 3 * 4 / -5 ^& 6
    fn less_than() -> expression::Comparison {
        expression::Comparison {
            base: one_plus_two(),
            rest: Some((
                operation::Comparison::Less,
                expression::Sum {
                    base: three_times_four_div_bitand(),
                    rest: vec![],
                },
            )),
        }
    }

    // 8 * 9
    fn eight_times_nine() -> expression::Product {
        expression::Product {
            base: binary_arithmetic(8, loc!(1, 18)),
            rest: vec![(
                operation::Product::Multiply,
                binary_arithmetic(9, loc!(1, 20)),
            )],
        }
    }

    // -(8 * 9)
    fn minus_eight_times_nine() -> expression::Unary {
        let grouped = Base::new(
            BaseKind::Group(Box::new(eight_times_nine().to_expression())),
            FileLocation {
                start_location: loc!(1, 17),
                end_location: Some(loc!(1, 21)),
            },
        );

        expression::Unary {
            base: grouped,
            operation: Some(operation::Unary::Negate),
            start_location: loc!(1, 16),
        }
    }

    // 7 - -(8 * 9)
    fn seven_minus_group() -> expression::Sum {
        let inner_product = expression::Product {
            base: expression::BinaryArithmetic {
                base: minus_eight_times_nine(),
                rest: None,
            },
            rest: vec![],
        };

        expression::Sum {
            base: product(7, loc!(1, 14)),
            rest: vec![(operation::Sum::Minus, inner_product)],
        }
    }

    // 1 + 2 < 3 * 4 / -5 ^& 6 == 7 - -(8 * 9)
    fn equality() -> expression::Equality {
        expression::Equality {
            base: expression::Logic {
                base: less_than(),
                rest: vec![],
            },
            rest: Some((
                operation::Equality::Equal,
                expression::Logic {
                    rest: vec![],
                    base: expression::Comparison {
                        base: seven_minus_group(),
                        rest: None,
                    },
                },
            )),
        }
    }

    // (1 + 2 < 3 * 4 / -5 ^& 6 == 7 - -(8 * 9)) and true
    fn full_expression() -> expression::Logic {
        let true_ = expression::Comparison {
            rest: None,
            base: expression::Sum {
                rest: vec![],
                base: expression::Product {
                    rest: vec![],
                    base: expression::BinaryArithmetic {
                        rest: None,
                        base: expression::Unary {
                            operation: None,
                            start_location: loc!(1, 24),
                            base: Base::new(
                                BaseKind::Literal(Literal::Bool(true)),
                                location(loc!(1, 24), loc!(1, 24)),
                            ),
                        },
                    },
                },
            },
        };

        expression::Logic {
            rest: vec![(operation::Logic::And, true_)],
            base: expression::Comparison {
                rest: None,
                base: expression::Sum {
                    rest: vec![],
                    base: expression::Product {
                        rest: vec![],
                        base: expression::BinaryArithmetic {
                            rest: None,
                            base: expression::Unary {
                                operation: None,
                                start_location: loc!(1, 0),
                                base: Base::new(
                                    BaseKind::Group(Box::new(equality().to_expression())),
                                    location(loc!(1, 0), loc!(1, 22)),
                                ),
                            },
                        },
                    },
                },
            },
        }
    }

    fn number(n: u32, location: FileLocation) -> Base {
        Base::new(BaseKind::Literal(Literal::WholeNumber(n)), location)
    }

    fn unary(n: u32, location: Location) -> expression::Unary {
        expression::Unary {
            start_location: location.clone(),
            base: number(
                n,
                FileLocation {
                    start_location: location.clone(),
                    end_location: Some(location),
                },
            ),
            operation: None,
        }
    }

    fn binary_arithmetic(n: u32, location: Location) -> expression::BinaryArithmetic {
        expression::BinaryArithmetic {
            base: unary(n, location),
            rest: None,
        }
    }

    fn product(n: u32, location: Location) -> expression::Product {
        expression::Product {
            base: binary_arithmetic(n, location),
            rest: vec![],
        }
    }
}
