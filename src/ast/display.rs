use super::expression::expression;
use super::expression::maths;
use super::operation;
use std::fmt::Display;

impl Display for expression::Literal {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            expression::Literal::Bool(val) => write!(f, "{val}"),
            expression::Literal::String(val) => write!(f, "{val}"),
            expression::Literal::Char(val) => write!(f, "{val}"),
            expression::Literal::Number(val) => write!(f, "{val}"),
            expression::Literal::Name(val) => write!(f, "{val}"),
        }
    }
}

impl Display for expression::Number {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            expression::Number::Decimal(n) => write!(f, "{n}"),
            expression::Number::Floating { base, rest } => write!(f, "{base}.{rest}"),
        }
    }
}

impl Display for expression::Expression {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match &self {
            expression::Expression::Literal(lit) => write!(f, "{lit}"),
            expression::Expression::Maths(maths) => write!(f, "{maths}"),
        }
    }
}

impl Display for maths::Equality {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match &self.rest {
            None => write!(f, "{}", self.base),
            Some(sum) => write!(f, "{} {} {}", self.base, sum.0, sum.1),
        }
    }
}

impl Display for maths::Logic {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let mut base = format!("{}", self.base);
        if self.rest.is_none() {
            return write!(f, "{base}");
        }

        for other in self.rest.as_ref().unwrap() {
            base = format!("{base} {} {}", other.0, other.1);
        }

        write!(f, "{base}")
    }
}

impl Display for maths::Comparison {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match &self.rest {
            None => write!(f, "{}", self.base),
            Some(sum) => write!(f, "{} {} {}", self.base, sum.0, sum.1),
        }
    }
}

impl Display for maths::Sum {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let mut base = format!("{}", self.base);
        if self.rest.is_none() {
            return write!(f, "{base}");
        }

        for other in self.rest.as_ref().unwrap() {
            base = format!("{base} {} {}", other.0, other.1);
        }

        write!(f, "{base}")
    }
}

impl Display for maths::Product {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let mut base = format!("{}", self.base);
        if self.rest.is_none() {
            return write!(f, "{base}");
        }

        for other in self.rest.as_ref().unwrap() {
            base = format!("{base} {} {}", other.0, other.1);
        }

        write!(f, "{base}")
    }
}

impl Display for maths::BinaryArithmetic {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let mut base = format!("{}", self.base);
        if self.rest.is_none() {
            return write!(f, "{base}");
        }

        for other in self.rest.as_ref().unwrap() {
            base = format!("{base}{}{}", other.0, other.1);
        }

        write!(f, "{base}")
    }
}

impl Display for maths::Unary {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match &self.operation {
            None => write!(f, "{}", self.base),
            Some(op) => write!(f, "{op}{}", self.base),
        }
    }
}

impl Display for maths::Base {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Self::Expression(expr) => write!(f, "{expr}"),
            Self::Group(expr) => write!(f, "({expr})"),
        }
    }
}

impl Display for operation::Unary {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            operation::Unary::Not => write!(f, "not"),
            operation::Unary::Negate => write!(f, "-"),
        }
    }
}

impl Display for operation::Product {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            operation::Product::Multiply => write!(f, "*"),
            operation::Product::Divide => write!(f, "/"),
        }
    }
}

impl Display for operation::Sum {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            operation::Sum::Plus => write!(f, "+"),
            operation::Sum::Minus => write!(f, "-"),
        }
    }
}

impl Display for operation::Comparison {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            operation::Comparison::Less => write!(f, "<"),
            operation::Comparison::LessOrEqual => write!(f, "<="),
            operation::Comparison::Greater => write!(f, ">"),
            operation::Comparison::GreaterOrEqual => write!(f, ">="),
        }
    }
}

impl Display for operation::Equality {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            operation::Equality::Equal => write!(f, "=="),
            operation::Equality::NotEqual => write!(f, "!="),
        }
    }
}

impl Display for operation::Logic {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            operation::Logic::And => write!(f, "and"),
            operation::Logic::Or => write!(f, "or"),
            operation::Logic::Xor => write!(f, "xor"),
            operation::Logic::Nand => write!(f, "nand"),
        }
    }
}

impl Display for operation::BinaryArithmetic {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Self::And => write!(f, "&"),
            Self::Or => write!(f, "|"),
        }
    }
}
