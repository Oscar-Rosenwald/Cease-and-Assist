use std::fmt::Display;

#[derive(Clone)]
pub struct FileLine {
    pub name: String,
    pub line: usize,
}

impl Display for FileLine {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}: {}", self.name, self.line)
    }
}
