#[derive(Debug, PartialEq, Eq)]
pub enum Unary {
    Not,
    Negative,
    Dereference,
}

#[derive(Debug, PartialEq, Eq)]
pub enum Product {
    Multiply,
    Divide,
}

#[derive(Debug, PartialEq, Eq)]
pub enum Sum {
    Plus,
    Minus,
}

#[derive(Debug, PartialEq, Eq)]
pub enum Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
}

#[derive(Debug, PartialEq, Eq)]
pub enum Equality {
    Equal,
    NotEqual,
}

#[derive(Debug, PartialEq, Eq)]
pub enum Logic {
    And,
    Or,
    Xor,
    Nand,
}

#[derive(Debug, PartialEq, Eq)]
pub enum BinaryArithmetic {
    And,
    Or,
}
