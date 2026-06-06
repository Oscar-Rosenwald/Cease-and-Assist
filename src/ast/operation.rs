use crate::lexing::*;

use std::convert::TryFrom;

pub enum Unary {
    Not,
    Negate,
    Dereference,
}

pub enum Product {
    Multiply,
    Divide,
}

pub enum Sum {
    Plus,
    Minus,
}

pub enum Comparison {
    Less,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
}

pub enum Equality {
    Equal,
    NotEqual,
}

pub enum Logic {
    And,
    Or,
    Xor,
    Nand,
}

pub enum BinaryArithmetic {
    And,
    Or,
}
