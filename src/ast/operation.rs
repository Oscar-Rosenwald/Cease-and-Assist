#[derive(Debug, PartialEq, Eq)]
pub enum Unary {
    Not,
    Negative,
    Dereference,
    Address,
    Wlock,
    Rlock,
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

#[derive(Debug, PartialEq, Eq)]
pub enum PipeKind {
    Grabby, // |>
    Chill,  // |
}

#[derive(Debug, PartialEq, Eq)]
pub enum AccessKind {
    Module, // :: for accessing elements of an imported module
    Field,  // => for accessing the metadata of a type field
    Value,  // .  for accessing the value of a type field
}
