/// Type represents the type of an expression, that is the type of the thing
/// (being very technical here) to which the expression evaluates.
///
/// # Node
///
/// Type should hold information about the type as well as the type itself. For
/// structs, there would be a list of interfaces that it implements.
pub struct Type {
    pub kind: TypeKind,
}

impl Type {
    pub(super) fn new(kind: TypeKind) -> Self {
        Self { kind }
    }
}

/// The [`Type`] struct represents all sorts of information about a type defined
/// or used within the Cease language. The `TypeKind` just tells you what type
/// an expression evaluates to.
///
/// `TypeKind` also holds the value.
pub enum TypeKind {
    String(String),
    Char(char),
    Decimal(i64),
    Float(f64),
    Bool(bool),
    /// On the left-hand side of an assignment, the Name is used as an
    /// unevaluatable entity which will be assigned the value on the right-hand
    /// side.
    Name(String),
    // TODO struct, data, a reflection type, closure, pipe,...
}

impl std::fmt::Display for TypeKind {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let str = match self {
            Self::String(_) => "string".to_string(),
            Self::Char(_) => "char".to_string(),
            Self::Decimal(_) => "int".to_string(),
            Self::Float(_) => "float".to_string(),
            Self::Bool(_) => "bool".to_string(),
            Self::Name(name) => format!("'{name}'"),
        };

        write!(f, "{str}")
    }
}

impl Default for TypeKind {
    fn default() -> Self {
        Self::Bool(false)
    }
}
