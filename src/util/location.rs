type FileName = std::path::PathBuf;

/// The location of a character in a file.
///
/// The location of any character can be represented as either an offset from
/// the start of the file, or as a line-number pair. The former is useful for
/// the program, the latter for people. The location module is used for error
/// reporting, which is a human-thing, so we only keep the file-line.
///
/// For a file that looks like this:
///
/// ```
/// 1234567890⮒
/// ```
///
/// `1` has the line-number `1:1`, and `9` has line-number `1:9`. The newline at
/// the end of the line has line-number `1:11`.
#[derive(Debug, Clone)]
pub struct FileLocation {
    /// Indexed from 1.
    line: usize,
    /// Indexed from 1.
    column: usize,
}

/// A set of coordinates of a file. This can define any amount of text, one
/// character long or larger. This can be used to report e.g. errors in a series
/// of tokens.
#[derive(Debug, Clone)]
pub struct Position {
    file: FileName,
    start_position: FileLocation,
    end_position: Option<FileLocation>,
}

impl Default for FileLocation {
    fn default() -> Self {
        Self { line: 1, column: 1 }
    }
}

impl FileLocation {
    pub fn new(line: usize, column: usize) -> Self {
        Self::validate(line, column);
        Self { line, column }
    }

    fn validate(line: usize, column: usize) {
        if line < 1 {
            panic!("Cannot have line have a value < 1, have {line}");
        }
        if column < 1 {
            panic!("Cannot have column have a value < 1, have {column}");
        }
    }
}

impl std::fmt::Display for Position {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self.end_position {
            None => write!(
                f,
                "{}:{}:{}",
                self.file.to_string_lossy(),
                self.start_position.line,
                self.start_position.column
            ),
            Some(ref end) => write!(
                f,
                "{}: {}:{} - {}:{}",
                self.file.to_string_lossy(),
                self.start_position.line,
                self.start_position.column,
                end.line,
                end.column,
            ),
        }
    }
}

impl Position {
    /// Construct a Position which spans more than one character.
    pub fn new_span(
        file_name: FileName,
        start_line: usize,
        start_column: usize,
        end_line: usize,
        end_column: usize,
    ) -> Self {
        Self {
            file: file_name,
            start_position: FileLocation {
                line: start_line,
                column: start_column,
            },
            end_position: Some(FileLocation {
                line: end_line,
                column: end_column,
            }),
        }
    }

    pub fn new_location(file: FileName, location: FileLocation) -> Self {
        Self {
            file,
            start_position: location,
            end_position: None,
        }
    }

    /// Constructs a Position with no end file and line.
    pub fn new_point(file_name: FileName, line: usize, column: usize) -> Self {
        Self {
            file: file_name,
            end_position: None,
            start_position: FileLocation { line, column },
        }
    }

    /// Constructs a Position from the start and end.
    pub fn new_start_end(file_name: FileName, start: FileLocation, end: FileLocation) -> Self {
        Self {
            file: file_name,
            start_position: start,
            end_position: Some(end),
        }
    }

    pub fn merge(self, other: Self) -> Self {
        if self.start_position.line < other.start_position.line {
            return Self {
                file: self.file.clone(),
                start_position: self.start_position,
                end_position: other.end_position,
            };
        }
        if self.start_position.line > other.start_position.line {
            return Self {
                file: self.file.clone(),
                start_position: other.start_position,
                end_position: self.end_position,
            };
        }
        if self.start_position.column < other.start_position.column {
            return Self {
                file: self.file.clone(),
                start_position: self.start_position,
                end_position: other.end_position,
            };
        }
        return Self {
            file: self.file.clone(),
            start_position: other.start_position,
            end_position: self.end_position,
        };
    }

    /// Panics if any of the arguments are below 1. This is because
    /// [`Position`]'s fields are indexed from 1.
    fn validate(start_line: usize, start_column: usize, end_line: usize, end_column: usize) {
        if start_line < 1 {
            panic!("Cannot have start line have a value < 1, have {start_line}");
        }
        if start_column < 1 {
            panic!("Cannot have start column have a value < 1, have {start_column}");
        }
        if end_line < 1 {
            panic!("Cannot have end line have a value < 1, have {end_line}");
        }
        if end_column < 1 {
            panic!("Cannot have end column have a value < 1, have {end_column}");
        }
    }
}

/// Creates a new `Position` object.
///
/// Can either be a point (argument `file_name`, `start_line`, `start_column`)
/// or a span (the same plus `end_line`, `end_column`).
///
/// `file_name` is a `path::PathBuf`. The rest are `usize` indexed from 1. The
/// macro will panic if either of those is <1.
macro_rules! position {
    ($file_name:expr, $start_line:expr, $start_column:expr, $end_line:expr, $end_column:expr) => {
        util::location::Position::validate($start_line, $start_column, $end_line, $end_column);
        util::location::Position::new_span(
            $file_name,
            $start_line,
            $start_column,
            $end_line,
            $end_column,
        );
    };

    ($file_name:expr, $start_line:expr, $start_column:expr) => {
        util::location::Position::validate($start_line, $start_column);
        util::location::Position::new_point($file_name, $start_line, $start_column);
    };
}
