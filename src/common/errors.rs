use std::fmt::Display;
use std::string::ToString;

use super::file::*;

pub struct LexingError {
    msg: String,
    location: Location,
}

impl LexingError {
    pub fn new<S: ToString>(msg: S, location: FileLocation) -> Self {
        Self {
            msg: msg.to_string(),
            location: Location::Position(location),
        }
    }

    pub fn no_line<S1: ToString, S2: ToString>(msg: S1, file_name: S2) -> Self {
        Self {
            msg: msg.to_string(),
            location: Location::File(file_name.to_string()),
        }
    }

    pub fn no_file<S: ToString>(msg: S) -> Self {
        Self {
            msg: msg.to_string(),
            location: Location::Line(FileLine::new("pre_processing", 0)),
        }
    }
}

impl Display for LexingError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{} - {}", self.location, self.msg)
    }
}

pub type Result<T> = core::result::Result<T, LexingError>;

enum Location {
    File(String),
    Line(FileLine),
    Position(FileLocation),
}

impl Display for Location {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Self::File(location) => write!(f, "{location}"),
            Self::Line(location) => write!(f, "{location}"),
            Self::Position(location) => write!(f, "{location}"),
        }
    }
}
