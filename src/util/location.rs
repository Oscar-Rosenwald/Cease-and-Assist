type FilePath = std::path::PathBuf;

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
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct FileLocation {
    /// Indexed from 1.
    line: usize,
    /// Indexed from 1.
    column: usize,
}

/// A set of coordinates of a file. This can define any amount of text, one
/// character long or larger. This can be used to report e.g. errors in a series
/// of tokens.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Position {
    file: FilePath,
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
    #[cfg(test)]
    pub fn new_span(
        file_path: FilePath,
        start_line: usize,
        start_column: usize,
        end_line: usize,
        end_column: usize,
    ) -> Position {
        let ret = Self {
            start_position: FileLocation::new(start_line, start_column),
            end_position: Some(FileLocation::new(end_line, end_column)),
            file: file_path,
        };
        ret.validate();
        return ret;
    }

    /// Constructs a Position from the start and end.
    pub fn new(file_path: FilePath, start: FileLocation, end: FileLocation) -> Self {
        Self {
            file: file_path,
            start_position: start,
            end_position: Some(end),
        }
    }

    /// Panics if any of the arguments are below 1. This is because
    /// [`Position`]'s fields are indexed from 1.
    #[cfg(test)]
    pub fn validate(&self) {
        let (start_line, start_column) = (self.start_position.line, self.start_position.column);

        if start_line < 1 {
            panic!("Cannot have start line have a value < 1, have {start_line}");
        }
        if start_column < 1 {
            panic!("Cannot have start column have a value < 1, have {start_column}");
        }

        let Some(ref end_position) = self.end_position else {
            return;
        };

        let (end_line, end_column) = (end_position.line, end_position.column);

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
/// Can either be a point (argument `file_path`, `start_line`, `start_column`)
/// or a span (the same plus `end_line`, `end_column`).
///
/// `file_name` is a `path::PathBuf`. The rest are `usize` indexed from 1. The
/// macro will panic if either of those is <1.
#[cfg(test)]
#[macro_export]
macro_rules! position {
    ($file_path:expr, $start_line:expr, $start_column:expr, $end_line:expr, $end_column:expr) => {
        crate::util::location::Position::new_span(
            $file_path,
            $start_line,
            $start_column,
            $end_line,
            $end_column,
        )
    };
}
