use super::operation;

pub enum Number {
    Decimal(u32),
    Floating { base: u32, rest: u32 },
}

pub enum NumberPrimary {
    Number(Number),
    Group(Box<MathsExpression>),
    Bool(bool),
}

pub struct Unary {
    pub operation: Option<operation::Unary>,
    pub base: NumberPrimary,
}

pub struct BinaryArithmetic {
    pub base: Unary,
    pub rest: Option<Vec<(operation::BinaryArithmetic, Unary)>>,
}

pub struct Product {
    pub base: BinaryArithmetic,
    pub rest: Option<Vec<(operation::Product, BinaryArithmetic)>>,
}

pub struct Sum {
    pub base: Product,
    pub rest: Option<Vec<(operation::Sum, Product)>>,
}

pub struct Comparison {
    pub base: Sum,
    pub rest: Option<(operation::Comparison, Sum)>,
}

pub struct Logic {
    pub base: Comparison,
    pub rest: Option<Vec<(operation::Logic, Comparison)>>,
}

pub struct Equality {
    pub base: Logic,
    pub rest: Option<(operation::Equality, Logic)>,
}

pub type MathsExpression = Equality;
