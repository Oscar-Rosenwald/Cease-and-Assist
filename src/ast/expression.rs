use super::operation;

pub enum Literal {
    Bool(bool),
    String(String),
    Char(char),
    WholeNumber(u32),
    FloatingNumber { base: u32, rest: u32 },
    Name(String), // variable name etc.
}

pub enum Expression {
    Calculation(Calculation),
}

pub struct Calculation {
    pub equality: Equality,
}

pub struct Equality {
    pub base: Logic,
    pub rest: Option<(operation::Equality, Logic)>,
}

pub struct Logic {
    pub base: Comparison,
    pub rest: Option<Vec<(operation::Logic, Comparison)>>,
}

pub struct Comparison {
    pub base: Sum,
    pub rest: Option<(operation::Comparison, Sum)>,
}

pub struct Sum {
    pub base: Product,
    pub rest: Option<Vec<(operation::Sum, Product)>>,
}

pub struct Product {
    pub base: BinaryArithmetic,
    pub rest: Option<Vec<(operation::Product, BinaryArithmetic)>>,
}

pub struct BinaryArithmetic {
    pub base: Unary,
    pub rest: Option<Vec<(operation::BinaryArithmetic, Unary)>>,
}

pub struct Unary {
    pub operation: Option<operation::Unary>,
    pub base: Base,
}

pub enum Base {
    Literal(Literal),
    Group(Box<Expression>),
}
