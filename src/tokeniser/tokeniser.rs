use super::*;
use std::fs::File;
use std::io;
use std::io::BufRead;
use std::path::Path;

/// Turns the given file into a series of tokens.
pub fn parse_file(file_path: &Path) -> Result<VecDeque<Token>, CeaseError> {
    let file_name = file_path.to_str().expect("File has no name?");

    let file = File::open(file_path).map_err(|e| {
        let message = format!("Failed to open file {file_name}: {e}");
        CeaseError::lexer(message, ErrorLocation::File(file_path.to_path_buf()))
    })?;

    let file_lines = io::BufReader::new(file).lines();

    return parse_input(file_lines, file_name, file_path);
}

/// Parses any generic input over lines (strings) into a list of tokens.
///
/// Separated so that `parse_file` can be used in `main` and `parse_input` more
/// generally in tests.
fn parse_input<Lines>(
    input: Lines,
    file_name: &str,
    file_path: &Path,
) -> Result<VecDeque<Token>, CeaseError>
where
    Lines: std::iter::IntoIterator<Item = Result<String, io::Error>>,
{
    let mut lexer = Lexer::new(file_path.to_path_buf());

    for (line_index, line) in input.into_iter().enumerate() {
        let line = line.map_err(|e| {
            let message = format!("Failed to read line from file {file_name}: {e}");
            CeaseError::lexer(message, ErrorLocation::File(file_path.to_path_buf()))
        })?;

        let mut line_length = 0;

        for (char_index, char) in line.chars().enumerate() {
            let location = FileLocation::new(line_index + 1, char_index + 1);
            lexer.push_char(char, location);
            line_length += 1;
        }

        let location = FileLocation::new(line_index + 1, line_length + 1);
        lexer.push_char('\n', location);
    }

    let tokens = lexer.end_of_input();
    return Ok(tokens);
}
