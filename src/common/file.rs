use std::fmt::Display;
use std::string::ToString;

#[derive(Clone)]
struct LineLocation {
    word_number: usize,
    char_number_in_word: usize,
}

impl Display for LineLocation {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "word {}, character in word: {}",
            self.word_number, self.char_number_in_word
        )
    }
}

#[derive(Clone)]
pub struct FileLocation {
    /// Name of the file
    name: String,
    /// Line number, starts from 1 because it's meant for human consumption.
    line: usize,
    /// Character number in `line`, starts from 1 because I'm not insane.
    column: usize,
}

impl Display for FileLocation {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}:{}:{}", self.name, self.line, self.column)
    }
}

#[derive(Clone)]
pub struct FileLine {
    name: String,
    line: usize,
}

impl FileLine {
    /// Create an instance of self on the given line (starts from 1).
    pub fn new<S: ToString>(file_name: S, line: usize) -> Self {
        Self {
            name: file_name.to_string(),
            line,
        }
    }

    /// Register the column number (starts from 1).
    pub fn add_column(&mut self, column: usize) -> FileLocation {
        FileLocation {
            line: self.line,
            name: self.name.clone(),
            column: column,
        }
    }

    pub fn file_name(&self) -> String {
        self.name.clone()
    }

    pub fn line_number(&self) -> usize {
        self.line
    }
}

impl Display for FileLine {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(f, "{}:{}", self.name, self.line)
    }
}
