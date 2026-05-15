#[derive(Debug, PartialEq, Eq)]
pub struct Statement {
    pub kind: StatementKind,
    // TODO Others
}

// Something like module creation, {} blocks, `database db = psql` etc.
#[derive(Debug, PartialEq, Eq)]
pub enum StatementKind {}
