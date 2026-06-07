use super::*;

use std::collections::VecDeque;

pub trait ExpressionTrait
where
    Self: Sized + ToString,
{
    fn parse_tokens(tokens: VecDeque<Token>) -> SyntaxResult<(Self, VecDeque<Token>)>;

    #[cfg(test)]
    fn to_expression(self) -> Expression;

    fn start(&self) -> Location;

    fn end(&self) -> Option<Location>;
}

#[derive(Debug, PartialEq, Eq)]
pub enum Literal {
    Bool(bool),
    String(String),
    Char(char),
    WholeNumber(u32),
    FloatingNumber { base: u32, rest: u32 },
    Name(String), // variable name etc.
}

#[derive(Debug, PartialEq, Eq)]
pub enum Expression {
    Calculation(Equality),
}

#[derive(Debug, PartialEq, Eq)]
pub struct Equality {
    pub base: Logic,
    pub rest: Option<(operation::Equality, Logic)>,
}

#[derive(Debug, PartialEq, Eq)]
pub struct Logic {
    pub base: Comparison,
    pub rest: Vec<(operation::Logic, Comparison)>,
}

#[derive(Debug, PartialEq, Eq)]
pub struct Comparison {
    pub base: Sum,
    pub rest: Option<(operation::Comparison, Sum)>,
}

#[derive(Debug, PartialEq, Eq)]
pub struct Sum {
    pub base: Product,
    pub rest: Vec<(operation::Sum, Product)>,
}

#[derive(Debug, PartialEq, Eq)]
pub struct Product {
    pub base: BinaryArithmetic,
    pub rest: Vec<(operation::Product, BinaryArithmetic)>,
}

#[derive(Debug, PartialEq, Eq)]
pub struct BinaryArithmetic {
    pub base: Unary,
    pub rest: Option<(operation::BinaryArithmetic, Unary)>,
}

#[derive(Debug, PartialEq, Eq)]
pub struct Unary {
    pub operation: Option<operation::Unary>,
    pub base: Base,
    pub(super) start_location: Location,
}

#[derive(Debug, PartialEq, Eq)]
pub struct Base {
    kind: BaseKind,
    location: FileLocation,
}

#[derive(Debug, PartialEq, Eq)]
pub enum BaseKind {
    Literal(Literal),
    Group(Box<Expression>),
}

impl ToString for Literal {
    fn to_string(&self) -> String {
        match self {
            Literal::Bool(bool) => format!("{bool}"),
            Literal::String(sentense) => format!(r#""{sentense}""#),
            Literal::Char(char) => format!("{char}"),
            Literal::Name(name) => format!("'{name}'"),
            Literal::WholeNumber(number) => format!("{number}"),
            Literal::FloatingNumber { base, rest } => format!("{base}.{rest}"),
        }
    }
}

impl ToString for Expression {
    fn to_string(&self) -> String {
        match self {
            Expression::Calculation(calculation) => calculation.to_string(),
        }
    }
}

impl Expression {
    pub(super) fn parse_tokens(tokens: VecDeque<Token>) -> SyntaxResult<(Self, VecDeque<Token>)> {
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

impl ToString for Equality {
    fn to_string(&self) -> String {
        let base = self.base.to_string();

        let Some((operation, logic)) = &self.rest else {
            return base;
        };

        match operation {
            operation::Equality::Equal => format!("{base} == {}", logic.to_string()),
            operation::Equality::NotEqual => format!("{base} != {}", logic.to_string()),
        }
    }
}

impl ExpressionTrait for Equality {
    #[cfg(test)]
    fn to_expression(self) -> Expression {
        Expression::Calculation(self)
    }

    fn start(&self) -> Location {
        self.base.start()
    }

    fn end(&self) -> Option<Location> {
        match self.rest.iter().last() {
            None => self.base.end(),
            Some(last) => last.1.end(),
        }
    }

    fn parse_tokens(tokens: VecDeque<Token>) -> SyntaxResult<(Self, VecDeque<Token>)> {
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

impl ToString for Logic {
    fn to_string(&self) -> String {
        let mut base = self.base.to_string();

        for (operation, comparison) in &self.rest {
            base = match operation {
                operation::Logic::And => format!("{base} and {}", comparison.to_string()),
                operation::Logic::Or => format!("{base} or {}", comparison.to_string()),
                operation::Logic::Nand => format!("{base} nand {}", comparison.to_string()),
                operation::Logic::Xor => format!("{base} xor {}", comparison.to_string()),
            };
        }

        return base;
    }
}

impl ExpressionTrait for Logic {
    #[cfg(test)]
    fn to_expression(self) -> Expression {
        Equality {
            base: self,
            rest: None,
        }
        .to_expression()
    }

    fn start(&self) -> Location {
        self.base.start()
    }

    fn end(&self) -> Option<Location> {
        match self.rest.iter().last() {
            None => self.base.end(),
            Some(last) => last.1.end(),
        }
    }

    fn parse_tokens(tokens: VecDeque<Token>) -> SyntaxResult<(Self, VecDeque<Token>)> {
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

impl ToString for Comparison {
    fn to_string(&self) -> String {
        let base = self.base.to_string();

        let Some((operation, sum)) = &self.rest else {
            return base;
        };

        match operation {
            operation::Comparison::Less => format!("{base} < {}", sum.to_string()),
            operation::Comparison::LessOrEqual => format!("{base} <= {}", sum.to_string()),
            operation::Comparison::Greater => format!("{base} > {}", sum.to_string()),
            operation::Comparison::GreaterOrEqual => format!("{base} >= {}", sum.to_string()),
        }
    }
}

impl ExpressionTrait for Comparison {
    #[cfg(test)]
    fn to_expression(self) -> Expression {
        Logic {
            base: self,
            rest: vec![],
        }
        .to_expression()
    }

    fn start(&self) -> Location {
        self.base.start()
    }

    fn end(&self) -> Option<Location> {
        match self.rest.iter().last() {
            None => self.base.end(),
            Some(last) => last.1.end(),
        }
    }

    fn parse_tokens(tokens: VecDeque<Token>) -> SyntaxResult<(Self, VecDeque<Token>)> {
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

impl ToString for Sum {
    fn to_string(&self) -> String {
        let mut base = self.base.to_string();

        for (operation, product) in &self.rest {
            base = match operation {
                operation::Sum::Plus => format!("{base} + {}", product.to_string()),
                operation::Sum::Minus => format!("{base} - {}", product.to_string()),
            };
        }

        return base;
    }
}

impl ExpressionTrait for Sum {
    #[cfg(test)]
    fn to_expression(self) -> Expression {
        Comparison {
            base: self,
            rest: None,
        }
        .to_expression()
    }

    fn start(&self) -> Location {
        self.base.start()
    }

    fn end(&self) -> Option<Location> {
        match self.rest.iter().last() {
            None => self.base.end(),
            Some(last) => last.1.end(),
        }
    }

    fn parse_tokens(tokens: VecDeque<Token>) -> SyntaxResult<(Self, VecDeque<Token>)> {
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
                        WordSeparator::Minus => Some(operation::Sum::Minus),
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

impl ToString for Product {
    fn to_string(&self) -> String {
        let mut base = self.base.to_string();

        for (operation, bin_arithmetic) in &self.rest {
            base = match operation {
                operation::Product::Multiply => format!("{base} * {}", bin_arithmetic.to_string()),
                operation::Product::Divide => format!("{base} / {}", bin_arithmetic.to_string()),
            };
        }

        return base;
    }
}

impl ExpressionTrait for Product {
    #[cfg(test)]
    fn to_expression(self) -> Expression {
        Sum {
            base: self,
            rest: vec![],
        }
        .to_expression()
    }

    fn start(&self) -> Location {
        self.base.start()
    }

    fn end(&self) -> Option<Location> {
        match self.rest.iter().last() {
            None => self.base.end(),
            Some(last) => last.1.end(),
        }
    }

    fn parse_tokens(tokens: VecDeque<Token>) -> SyntaxResult<(Self, VecDeque<Token>)> {
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

impl ToString for BinaryArithmetic {
    fn to_string(&self) -> String {
        let base = self.base.to_string();
        match &self.rest {
            None => base,
            Some((operation, unary)) => match operation {
                operation::BinaryArithmetic::And => format!("{base} ^& {}", unary.to_string()),
                operation::BinaryArithmetic::Or => format!("{base} ^| {}", unary.to_string()),
            },
        }
    }
}

impl ExpressionTrait for BinaryArithmetic {
    #[cfg(test)]
    fn to_expression(self) -> Expression {
        Product {
            base: self,
            rest: vec![],
        }
        .to_expression()
    }

    fn start(&self) -> Location {
        self.base.start()
    }

    fn end(&self) -> Option<Location> {
        match self.rest.iter().last() {
            None => self.base.end(),
            Some(last) => last.1.end(),
        }
    }

    fn parse_tokens(tokens: VecDeque<Token>) -> SyntaxResult<(Self, VecDeque<Token>)> {
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

impl ToString for Unary {
    fn to_string(&self) -> String {
        match self.operation {
            None => self.base.to_string(),
            Some(ref operation) => match operation {
                operation::Unary::Not => format!("!{}", self.base.to_string()),
                operation::Unary::Negative => format!("-{}", self.base.to_string()),
                operation::Unary::Dereference => format!("*{}", self.base.to_string()),
            },
        }
    }
}

impl ExpressionTrait for Unary {
    #[cfg(test)]
    fn to_expression(self) -> Expression {
        BinaryArithmetic {
            base: self,
            rest: None,
        }
        .to_expression()
    }

    fn start(&self) -> Location {
        self.start_location.clone()
    }

    fn end(&self) -> Option<Location> {
        self.base.end()
    }

    fn parse_tokens(mut tokens: VecDeque<Token>) -> SyntaxResult<(Unary, VecDeque<Token>)> {
        let (unary_operation, start_location): (Option<operation::Unary>, Option<Location>) =
            match tokens.get(0) {
                None => return Err(SyntaxError::empty("Unexpected end of file", tokens)),
                Some(token) => match token.type_ {
                    TokenType::WordSeparator(ref separator) => match separator {
                        WordSeparator::Exclamation => (
                            Some(operation::Unary::Not),
                            Some(token.start_location.clone()),
                        ),
                        WordSeparator::Minus => (
                            Some(operation::Unary::Negative),
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
    #[cfg(test)]
    pub(super) fn new(kind: BaseKind, location: FileLocation) -> Self {
        Self { kind, location }
    }

    /// Parses `tokens` as an inner (grouped) expression surrounded by
    /// parentheses. The first parenthesis (`(`) has already been processed. The
    /// closing one (`)`) will be handled here. If we don't find it, we return
    /// an error.
    fn parse_grouped_expresssion(
        tokens: VecDeque<Token>,
    ) -> SyntaxResult<(Expression, VecDeque<Token>, Location)> {
        let (inner_expression, mut remaining_tokens) = Expression::parse_tokens(tokens)?;

        let mut first_token = match remaining_tokens.pop_front() {
            Some(token) => token,
            None => {
                return Err(SyntaxError::empty(
                    "Unclosed parathentical",
                    remaining_tokens,
                ));
            }
        };

        let token_type = std::mem::take(&mut first_token.type_);
        let TokenType::WordSeparator(ref separator) = token_type else {
            first_token.type_ = token_type;
            return Err(SyntaxError::tokens(
                "Expected closing parenthetical",
                vec![first_token],
                remaining_tokens,
            ));
        };

        let WordSeparator::RightParen = separator else {
            first_token.type_ = token_type;
            return Err(SyntaxError::tokens(
                "Expected closing parenthetical",
                vec![first_token],
                remaining_tokens,
            ));
        };

        return Ok((inner_expression, remaining_tokens, first_token.end_location));
    }

    /// Parses `tokens` after a [`WordSeparator`] has been seen. This is either
    /// a normal word separator (e.g. `+` which in this case is an error that is
    /// returned from here), or it's an opening parenthesis, which indicates a
    /// [`BaseKind::Group`] subexpression (e.g. `(1 + 2)`).
    ///
    /// If an inner (grouped) expression is found, it is parsed and returned in
    /// the appropriate `BaseKind`. We also return the remaining tokens, and the
    /// end location of this grouped expression.
    fn parse_word_separator(
        current_token: Token,
        separator: WordSeparator,
        tokens: VecDeque<Token>,
    ) -> SyntaxResult<(BaseKind, VecDeque<Token>, Location)> {
        let WordSeparator::LeftParen = separator else {
            let mut offending_tokens = vec![Token::new(
                TokenType::WordSeparator(separator),
                current_token.start_location,
                current_token.end_location,
            )];

            let (mut line, other_tokens) = read_line(tokens);
            offending_tokens.append(&mut line);

            return Err(SyntaxError::tokens(
                "Unexpected word separator",
                offending_tokens,
                other_tokens,
            ));
        };

        let (inner_expression, remaining_tokens, end_location) =
            Self::parse_grouped_expresssion(tokens)?;

        return Ok((
            BaseKind::Group(Box::new(inner_expression)),
            remaining_tokens,
            end_location,
        ));
    }
}

impl ToString for Base {
    fn to_string(&self) -> String {
        match &self.kind {
            BaseKind::Literal(literal) => literal.to_string(),
            BaseKind::Group(group) => format!("({})", group.to_string()),
        }
    }
}

impl ExpressionTrait for Base {
    #[cfg(test)]
    fn to_expression(self) -> Expression {
        Unary {
            start_location: self.location.start_location.clone(),
            base: self,
            operation: None,
        }
        .to_expression()
    }

    fn start(&self) -> Location {
        self.location.start_location.clone()
    }

    fn end(&self) -> Option<Location> {
        self.location.end_location.clone()
    }

    fn parse_tokens(mut tokens: VecDeque<Token>) -> SyntaxResult<(Self, VecDeque<Token>)> {
        let mut first_token = match tokens.pop_front() {
            None => return Err(SyntaxError::empty("Unexpected end of file", tokens)),
            Some(token) => token,
        };

        let start_location = first_token.start_location.clone();
        let mut end_location = first_token.end_location.clone();
        let token_type = std::mem::take(&mut first_token.type_);

        let base_kind = match token_type {
            TokenType::Newline => {
                return Err(SyntaxError::tokens(
                    "Unexpected end of line",
                    vec![first_token],
                    tokens,
                ));
            }
            TokenType::EndOfFile => {
                return Err(SyntaxError::empty("Unexpected end of file", tokens));
            }
            TokenType::Documentation(_) => {
                first_token.type_ = token_type;
                return Err(SyntaxError::tokens(
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

                return Err(SyntaxError::tokens(
                    "Unexpected symbol",
                    offending_tokens,
                    other_tokens,
                ));
            }
            TokenType::WordSeparator(separator) => {
                let (base_kind, remaining_tokens, inner_end) =
                    Self::parse_word_separator(first_token, separator, tokens)?;
                tokens = remaining_tokens;
                end_location = inner_end;
                base_kind
            }
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
