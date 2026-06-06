use super::*;

use std::collections::VecDeque;

pub enum Literal {
    Bool(bool),
    String(String),
    Char(char),
    WholeNumber(u32),
    FloatingNumber { base: u32, rest: u32 },
    Name(String), // variable name etc.
}

pub enum Expression {
    Calculation(Equality),
}

pub struct Equality {
    pub base: Logic,
    pub rest: Option<(operation::Equality, Logic)>,
}

pub struct Logic {
    pub base: Comparison,
    pub rest: Vec<(operation::Logic, Comparison)>,
}

pub struct Comparison {
    pub base: Sum,
    pub rest: Option<(operation::Comparison, Sum)>,
}

pub struct Sum {
    pub base: Product,
    pub rest: Vec<(operation::Sum, Product)>,
}

pub struct Product {
    pub base: BinaryArithmetic,
    pub rest: Vec<(operation::Product, BinaryArithmetic)>,
}

pub struct BinaryArithmetic {
    pub base: Unary,
    pub rest: Option<(operation::BinaryArithmetic, Unary)>,
}

pub struct Unary {
    pub operation: Option<operation::Unary>,
    pub base: Base,
    start_location: Location,
}

pub struct Base {
    kind: BaseKind,
    location: FileLocation,
}

pub enum BaseKind {
    Literal(Literal),
    Group(Box<Expression>),
}

impl Expression {
    pub(super) fn parse_tokens(tokens: VecDeque<Token>) -> AstResult<(Self, VecDeque<Token>)> {
        let (calculation, tokens) = Equality::parse_tokens(tokens)?;
        return Ok((Self::Calculation(calculation), tokens));
    }

    pub(super) fn location(&self) -> FileLocation {
        match self {
            Self::Calculation(calculation) => FileLocation {
                start_location: calculation.start(),
                end_location: calculation.end(),
            },
        }
    }
}

impl Equality {
    fn start(&self) -> Location {
        self.base.start()
    }

    fn end(&self) -> Option<Location> {
        match self.rest.iter().last() {
            None => None,
            Some(last) => last.1.end(),
        }
    }

    fn parse_tokens(tokens: VecDeque<Token>) -> AstResult<(Self, VecDeque<Token>)> {
        let (logic, mut tokens) = Logic::parse_tokens(tokens)?;
        let mut equality_ret = Self {
            base: logic,
            rest: None,
        };

        let operation: Option<operation::Equality> = match tokens.get(0) {
            None => None,
            Some(token) => match token.type_ {
                TokenType::Symbol(ref symbol) => match symbol {
                    Symbol::EqualEqual => Some(operation::Equality::Equal),
                    Symbol::NotEqual => Some(operation::Equality::NotEqual),
                    _ => None,
                },
                _ => None,
            },
        };

        let operation = match operation {
            None => return Ok((equality_ret, tokens)),
            Some(op) => {
                tokens.pop_front();
                op
            }
        };

        let (logic, tokens) = Logic::parse_tokens(tokens)?;
        equality_ret.rest = Some((operation, logic));

        return Ok((equality_ret, tokens));
    }
}

impl Logic {
    fn start(&self) -> Location {
        self.base.start()
    }

    fn end(&self) -> Option<Location> {
        match self.rest.iter().last() {
            None => None,
            Some(last) => last.1.end(),
        }
    }

    fn parse_tokens(tokens: VecDeque<Token>) -> AstResult<(Self, VecDeque<Token>)> {
        let (comparison, mut tokens) = Comparison::parse_tokens(tokens)?;
        let mut logic_ret = Self {
            base: comparison,
            rest: Vec::new(),
        };

        loop {
            let operation: Option<operation::Logic> = match tokens.get(0) {
                None => None,
                Some(token) => match token.type_ {
                    TokenType::Symbol(ref symbol) => match symbol {
                        Symbol::And => Some(operation::Logic::And),
                        Symbol::Or => Some(operation::Logic::Or),
                        _ => None,
                    },
                    TokenType::Keyword(ref keyword) => match keyword {
                        Keyword::And => Some(operation::Logic::And),
                        Keyword::Or => Some(operation::Logic::Or),
                        Keyword::Nand => Some(operation::Logic::Nand),
                        Keyword::Xor => Some(operation::Logic::Xor),
                        _ => None,
                    },
                    _ => None,
                },
            };

            let operation = match operation {
                None => return Ok((logic_ret, tokens)),
                Some(op) => {
                    tokens.pop_front();
                    op
                }
            };

            let (comparison, other_tokens) = Comparison::parse_tokens(tokens)?;
            logic_ret.rest.push((operation, comparison));
            tokens = other_tokens;
        }
    }
}

impl Comparison {
    fn start(&self) -> Location {
        self.base.start()
    }

    fn end(&self) -> Option<Location> {
        match self.rest.iter().last() {
            None => None,
            Some(last) => last.1.end(),
        }
    }

    fn parse_tokens(tokens: VecDeque<Token>) -> AstResult<(Self, VecDeque<Token>)> {
        let (sum, mut tokens) = Sum::parse_tokens(tokens)?;
        let mut comparison_ret = Self {
            base: sum,
            rest: None,
        };

        let operation: Option<operation::Comparison> = match tokens.get(0) {
            None => None,
            Some(token) => match token.type_ {
                TokenType::WordSeparator(ref separator) => match separator {
                    WordSeparator::LeftChevron => Some(operation::Comparison::Less),
                    WordSeparator::RightChevron => Some(operation::Comparison::Greater),
                    _ => None,
                },
                TokenType::Symbol(ref symbol) => match symbol {
                    Symbol::LessOrEqual => Some(operation::Comparison::LessOrEqual),
                    Symbol::GreaterOrEqual => Some(operation::Comparison::GreaterOrEqual),
                    _ => None,
                },
                _ => None,
            },
        };

        let operation = match operation {
            None => return Ok((comparison_ret, tokens)),
            Some(op) => {
                tokens.pop_front();
                op
            }
        };

        let (sum, tokens) = Sum::parse_tokens(tokens)?;
        comparison_ret.rest = Some((operation, sum));

        return Ok((comparison_ret, tokens));
    }
}

impl Sum {
    fn start(&self) -> Location {
        self.base.start()
    }

    fn end(&self) -> Option<Location> {
        match self.rest.iter().last() {
            None => None,
            Some(last) => last.1.end(),
        }
    }

    fn parse_tokens(tokens: VecDeque<Token>) -> AstResult<(Self, VecDeque<Token>)> {
        let (product, mut tokens) = Product::parse_tokens(tokens)?;
        let mut sum_ret = Self {
            base: product,
            rest: Vec::new(),
        };

        loop {
            let operation: Option<operation::Sum> = match tokens.get(0) {
                None => None,
                Some(token) => match token.type_ {
                    TokenType::WordSeparator(ref separator) => match separator {
                        WordSeparator::Plus => Some(operation::Sum::Plus),
                        WordSeparator::Slash => Some(operation::Sum::Minus),
                        _ => None,
                    },
                    _ => None,
                },
            };

            let operation = match operation {
                None => return Ok((sum_ret, tokens)),
                Some(op) => {
                    tokens.pop_front();
                    op
                }
            };

            let (product, other_tokens) = Product::parse_tokens(tokens)?;
            sum_ret.rest.push((operation, product));
            tokens = other_tokens;
        }
    }
}

impl Product {
    fn start(&self) -> Location {
        self.base.start()
    }

    fn end(&self) -> Option<Location> {
        match self.rest.iter().last() {
            None => None,
            Some(last) => last.1.end(),
        }
    }

    fn parse_tokens(tokens: VecDeque<Token>) -> AstResult<(Self, VecDeque<Token>)> {
        let (binary_arithmetic, mut tokens) = BinaryArithmetic::parse_tokens(tokens)?;
        let mut product_ret = Product {
            base: binary_arithmetic,
            rest: Vec::new(),
        };

        loop {
            let operation: Option<operation::Product> = match tokens.get(0) {
                None => None,
                Some(token) => match token.type_ {
                    TokenType::WordSeparator(ref separator) => match separator {
                        WordSeparator::Star => Some(operation::Product::Multiply),
                        WordSeparator::Slash => Some(operation::Product::Divide),
                        _ => None,
                    },
                    _ => None,
                },
            };

            let operation = match operation {
                None => return Ok((product_ret, tokens)),
                Some(op) => {
                    tokens.pop_front();
                    op
                }
            };

            let (binary, other_tokens) = BinaryArithmetic::parse_tokens(tokens)?;
            product_ret.rest.push((operation, binary));
            tokens = other_tokens;
        }
    }
}

impl BinaryArithmetic {
    fn start(&self) -> Location {
        self.base.start()
    }

    fn end(&self) -> Option<Location> {
        match self.rest.iter().last() {
            None => None,
            Some(last) => last.1.end(),
        }
    }

    fn parse_tokens(tokens: VecDeque<Token>) -> AstResult<(Self, VecDeque<Token>)> {
        let (unary, mut tokens) = Unary::parse_tokens(tokens)?;
        let mut binary_ret = Self {
            base: unary,
            rest: None,
        };

        let operation: Option<operation::BinaryArithmetic> = match tokens.get(0) {
            None => None,
            Some(token) => match token.type_ {
                TokenType::Symbol(ref symbol) => match symbol {
                    Symbol::BitAnd => Some(operation::BinaryArithmetic::And),
                    Symbol::BitOr => Some(operation::BinaryArithmetic::Or),
                    _ => None,
                },
                _ => None,
            },
        };

        let operation = match operation {
            None => return Ok((binary_ret, tokens)),
            Some(op) => {
                tokens.pop_front();
                op
            }
        };

        let (unary, tokens) = Unary::parse_tokens(tokens)?;
        binary_ret.rest = Some((operation, unary));

        return Ok((binary_ret, tokens));
    }
}

impl Unary {
    fn start(&self) -> Location {
        self.start_location.clone()
    }

    fn end(&self) -> Option<Location> {
        self.base.end()
    }

    fn parse_tokens(mut tokens: VecDeque<Token>) -> AstResult<(Unary, VecDeque<Token>)> {
        let (unary_operation, start_location): (Option<operation::Unary>, Option<Location>) =
            match tokens.get(0) {
                None => return Err(ParseError::empty("Unexpected end of file", tokens)),
                Some(token) => match token.type_ {
                    TokenType::WordSeparator(ref separator) => match separator {
                        WordSeparator::Exclamation => (
                            Some(operation::Unary::Not),
                            Some(token.start_location.clone()),
                        ),
                        WordSeparator::Minus => (
                            Some(operation::Unary::Negate),
                            Some(token.start_location.clone()),
                        ),
                        WordSeparator::Star => (
                            Some(operation::Unary::Dereference),
                            Some(token.start_location.clone()),
                        ),
                        _ => (None, None),
                    },
                    _ => (None, None),
                },
            };

        // If we found a unary operation at the front of the token stream, we
        // must drop that first token (e.g. the '-' symbol) before passing the
        // other tokens to the Base parser function. Otherwise Base would
        // attempt to pass the '-' as well.
        if unary_operation.is_some() {
            tokens.pop_front();
        }

        let (base, tokens) = Base::parse_tokens(tokens)?;

        let unary = Unary {
            start_location: start_location.unwrap_or_else(|| base.start()),
            operation: unary_operation,
            base,
        };

        return Ok((unary, tokens));
    }
}

impl Base {
    fn start(&self) -> Location {
        self.location.start_location.clone()
    }

    fn end(&self) -> Option<Location> {
        self.location.end_location.clone()
    }

    fn parse_tokens(mut tokens: VecDeque<Token>) -> AstResult<(Self, VecDeque<Token>)> {
        let mut first_token = match tokens.pop_front() {
            None => return Err(ParseError::empty("Unexpected end of file", tokens)),
            Some(token) => token,
        };

        let mut start_location = first_token.start_location.clone();
        let mut end_location = first_token.end_location.clone();
        let token_type = std::mem::take(&mut first_token.type_);

        let base_kind = match token_type {
            TokenType::Newline => return Err(ParseError::empty("Unexpected end of line", tokens)),
            TokenType::EndOfFile => {
                return Err(ParseError::empty("Unexpected end of file", tokens));
            }
            TokenType::Documentation(_) => {
                first_token.type_ = token_type;
                return Err(ParseError::tokens(
                    "Unexpected documentation block",
                    vec![first_token],
                    tokens,
                ));
            }
            TokenType::Symbol(_) => {
                first_token.type_ = token_type;
                let mut offending_tokens = vec![first_token];
                let (mut line, other_tokens) = read_line(tokens);
                offending_tokens.append(&mut line);

                return Err(ParseError::tokens(
                    "Unexpected symbol",
                    offending_tokens,
                    other_tokens,
                ));
            }
            TokenType::WordSeparator(separator) => match separator {
                WordSeparator::LeftParen => todo!(), // TODO must call the expression, then parse the closing parenthetical
                _ => {
                    let mut offending_tokens = vec![Token::new(
                        TokenType::WordSeparator(separator),
                        first_token.start_location,
                        first_token.end_location,
                    )];

                    let (mut line, other_tokens) = read_line(tokens);
                    offending_tokens.append(&mut line);

                    return Err(ParseError::tokens(
                        "Unexpected word separator",
                        offending_tokens,
                        other_tokens,
                    ));
                }
            },
            TokenType::Keyword(keyword) => match keyword {
                Keyword::True => BaseKind::Literal(Literal::Bool(true)),
                Keyword::False => BaseKind::Literal(Literal::Bool(false)),
                _ => unimplemented!("Named expressions not yet implemented"),
            },
            TokenType::String(sentense) => BaseKind::Literal(Literal::String(sentense)),
            TokenType::Char(char) => BaseKind::Literal(Literal::Char(char)),
            TokenType::Literal(literal) => BaseKind::Literal(Literal::Name(literal)),
            TokenType::Number(number) => BaseKind::Literal(Literal::WholeNumber(number)),
            TokenType::DecimalNumber(base, rest) => {
                BaseKind::Literal(Literal::FloatingNumber { base, rest })
            }
        };

        let base = Base {
            kind: base_kind,
            location: FileLocation {
                start_location,
                end_location: Some(end_location),
            },
        };

        return Ok((base, tokens));
    }
}

/// Returns tokens up until the next newline token, and the tokens which follow
/// that newline token. In other words, reads the next line of the token stream
/// and returns that line, plus the rest of the stream, leaving the newline
/// character out.
fn read_line(tokens: VecDeque<Token>) -> (Vec<Token>, VecDeque<Token>) {
    let mut token_iter = tokens.into_iter();

    let line: Vec<Token> = token_iter
        .by_ref()
        .take_while(|token| !token.type_.is_whitespace())
        .collect();

    let rest: VecDeque<Token> = token_iter.collect();

    return (line, rest);
}
