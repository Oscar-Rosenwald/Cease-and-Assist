use std::error::Error as CoreError;
use std::fmt::Display;
use std::string::ToString;

use super::file::*;

pub type Result<T> = core::result::Result<T, LexingError>;

#[derive(Debug)]
pub struct LexingError {
    msg: String,
    location: Option<Location>,
    error: Option<Box<dyn CoreError>>,
}

impl LexingError {
    pub fn bare<S: ToString>(msg: S) -> Self {
        Self {
            msg: msg.to_string(),
            error: None,
            location: None,
        }
    }

    pub fn new<S: ToString>(msg: S, location: Location) -> Self {
        Self {
            msg: msg.to_string(),
            location: Some(location),
            error: None,
        }
    }

    pub fn wrap<S: ToString, E: CoreError + 'static>(msg: S, e: E, location: Location) -> Self {
        Self {
            msg: msg.to_string(),
            location: Some(location),
            error: Some(Box::new(e)),
        }
    }
}

impl CoreError for LexingError {
    fn source(&self) -> Option<&(dyn std::error::Error + 'static)> {
        match self.error {
            None => None,
            Some(ref e) => Some(e.as_ref()),
        }
    }
}

impl Display for LexingError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match (&self.location, &self.error) {
            (None, None) => write!(f, "{}", self.msg),
            (None, Some(e)) => write!(f, "{}: {e}", self.msg),
            (Some(l), None) => write!(f, "{l}: {}", self.msg),
            (Some(l), Some(e)) => write!(f, "{l}: {}: {e}", self.msg),
        }
    }
}

pub trait ToLexingError {
    fn wrap_location<S: ToString>(self, msg: S, location: Location) -> LexingError;
}

impl ToLexingError for std::io::Error {
    fn wrap_location<S: ToString>(self, msg: S, location: Location) -> LexingError {
        LexingError::wrap(msg, self, location)
    }
}
