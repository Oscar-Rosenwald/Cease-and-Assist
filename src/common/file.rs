use std::fmt::Display;
use std::string::ToString;

#[derive(Debug, PartialEq, Eq, Clone)]
pub enum Location {
    File(String),
    Line {
        file_name: String,
        line_number: usize,
    },
    Position {
        file_name: String,
        line_number: usize,
        column_number: usize,
    },
}

impl Location {
    pub fn file<S: ToString>(file_name: S) -> Self {
        Self::File(file_name.to_string())
    }

    pub fn line<S: ToString>(file_name: S, line_number: usize) -> Self {
        Self::Line {
            file_name: file_name.to_string(),
            line_number,
        }
    }

    pub fn column<S: ToString>(file_name: S, line_number: usize, column_number: usize) -> Self {
        Self::Position {
            file_name: file_name.to_string(),
            line_number,
            column_number,
        }
    }

    pub fn add_column(&self, column_number: usize) -> Self {
        match self {
            Self::Line {
                file_name,
                line_number,
            } => Self::Position {
                file_name: file_name.clone(),
                line_number: line_number.clone(),
                column_number,
            },
            other => other.clone(),
        }
    }
}

impl Display for Location {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Self::File(location) => write!(f, "{location}"),
            Self::Line {
                file_name,
                line_number,
            } => write!(f, "{file_name}:{line_number}"),
            Self::Position {
                file_name,
                line_number,
                column_number,
            } => write!(f, "{file_name}:{line_number}:{column_number}"),
        }
    }
}
