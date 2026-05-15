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

impl TryFrom<&WordSeparator> for Unary {
    type Error = ();

    fn try_from(separator: &WordSeparator) -> Result<Self, Self::Error> {
        Ok(match separator {
            WordSeparator::Minus => Self::Negate,
            WordSeparator::Exclamation => Self::Not,
            WordSeparator::Star => Self::Dereference,
            _ => return Err(()),
        })
    }
}

impl TryFrom<&Keyword> for Unary {
    type Error = ();

    fn try_from(keyword: &Keyword) -> Result<Self, Self::Error> {
        Ok(match keyword {
            Keyword::Not => Self::Not,
            _ => return Err(()),
        })
    }
}
