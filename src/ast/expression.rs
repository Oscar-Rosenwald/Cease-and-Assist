pub mod expression {
    use super::maths;

    pub enum Literal {
        Bool(bool),
        String(String),
        Char(char),
        Number(Number),
        Name(String), // variable name etc.
    }

    pub enum Number {
        Decimal(u32),
        Floating { base: u32, rest: u32 },
    }

    pub enum Expression {
        Literal(Literal), // variable name etc,
        Maths(maths::Expression),
        // Application
        // Block
        // Exit
        // Builin
    }
}

pub mod maths {
    use super::super::operation;
    use super::expression;

    pub type Expression = Equality;

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
        Expression(Box<expression::Expression>),
        Group(Box<expression::Expression>),
    }
}
