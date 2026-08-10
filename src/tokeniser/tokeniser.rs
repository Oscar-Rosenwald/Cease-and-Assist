use super::*;
use std::fs::File;
use std::io;
use std::io::BufRead;
use std::path::Path;

/// Turns the given file into a series of tokens.
///
/// Due to reasons beyond your ken, files which do not end with a newline will
/// be treated as though they do.
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

#[cfg(test)]
mod tests {
    use super::*;
    use crate::position;
    use pretty_assertions::assert_eq;
    use std::iter;

    /// Returns the file name (corresponding with [`file_path`]) used for
    /// testing.
    const FILE_NAME: &'static str = "name.stop";

    /// Returns the file path used for testing. In tests we don't actually care
    /// much about the path.
    fn file_path() -> &'static std::path::Path {
        std::path::Path::new(FILE_NAME)
    }

    /// Like [`file_path`] but with `PathBuf`.
    fn path() -> std::path::PathBuf {
        file_path().to_path_buf()
    }

    /// Converts the string `input` into an iterator over the `input`'s lines.
    /// The output is fit to be passed to [`parse_input`].
    fn input(input: &str) -> impl iter::Iterator<Item = Result<String, io::Error>> {
        input.split('\n').map(|line| Ok(line.to_string()))
    }

    fn parse(input_str: &str) -> VecDeque<Token> {
        match parse_input(input(input_str), FILE_NAME, file_path()) {
            Err(e) => panic!("{e}"),
            Ok(tokens) => tokens,
        }
    }

    /// Panics if the number of `tokens` is not equal to the `expected` number.
    /// Prints the tokens if the number doesn't match.
    macro_rules! check_length {
        ($expected:expr, $tokens:expr) => {
            if $tokens.len() != $expected {
                eprintln!("{:#?}", $tokens);
                panic!(
                    "Unexpected number of tokens. Wanted {}, got {}.",
                    $expected,
                    $tokens.len()
                );
            }
        };
    }

    /// Confirms that the `token: &Token` matches the given `position: Position`
    /// and `kind: TokenKind`.
    ///
    /// Recommend creating the `position` argument using the `position!()`
    /// macro.
    macro_rules! check_token {
        ($position:expr, $kind:expr, $token:expr) => {
            $token.position.validate();
            assert_eq!($kind, $token.kind);
            assert_eq!($position, $token.position);
        };
    }

    #[test]
    fn nothing() {
        let tokens = parse("");
        check_length!(0, tokens);
    }

    #[test]
    fn literal() {
        let literal = "literal";
        let tokens = parse(literal);

        check_length!(1, tokens);
        check_token!(
            position!(path(), 1, 1, 1, 7),
            TokenKind::Literal(String::from(literal)),
            tokens[0]
        );
    }

    #[test]
    fn string() {
        let string = "string";
        let tokens = parse(&format!(r#""{string}""#));

        check_length!(1, tokens);
        check_token!(
            position!(path(), 1, 1, 1, 8),
            TokenKind::String(String::from(string)),
            tokens[0]
        );
    }

    #[test]
    fn escaped_string() {
        let tokens = parse(r#""\"string\"""#);

        check_length!(1, tokens);
        check_token!(
            position!(path(), 1, 1, 1, 12),
            TokenKind::String(String::from(r#""string""#)),
            tokens[0]
        );
    }

    #[test]
    fn char() {
        let tokens = parse(&format!("'c'"));

        check_length!(1, tokens);
        check_token!(
            position!(path(), 1, 1, 1, 3),
            TokenKind::Char('c'),
            tokens[0]
        );
    }

    #[test]
    fn escaped_char() {
        let tokens = parse(r"'\\'");

        check_length!(1, tokens);
        check_token!(
            position!(path(), 1, 1, 1, 4),
            TokenKind::Char('\\'),
            tokens[0]
        );
    }

    #[test]
    fn keyword() {
        let keyword = "yield";
        let tokens = parse(keyword);

        check_length!(1, tokens);
        check_token!(
            position!(path(), 1, 1, 1, 5),
            TokenKind::Keyword(Keyword::Yield),
            tokens[0]
        );
    }

    #[test]
    fn symbol() {
        let symbol = "?";
        let tokens = parse(symbol);

        check_length!(1, tokens);
        check_token!(
            position!(path(), 1, 1, 1, 1),
            TokenKind::Symbol(Symbol::Questionmark),
            tokens[0]
        );
    }

    #[test]
    fn int() {
        let tokens = parse("884");

        check_length!(1, tokens);
        check_token!(
            position!(path(), 1, 1, 1, 3),
            TokenKind::Int(884),
            tokens[0]
        );
    }

    #[test]
    fn literal_with_number() {
        let literal = "literal8";
        let tokens = parse(literal);

        check_length!(1, tokens);
        check_token!(
            position!(path(), 1, 1, 1, 8),
            TokenKind::Literal(String::from(literal)),
            tokens[0]
        );
    }
    #[test]
    fn literal_with_underscore_start() {
        let literal = "_literal";
        let tokens = parse(literal);

        check_length!(1, tokens);
        check_token!(
            position!(path(), 1, 1, 1, 8),
            TokenKind::Literal(String::from(literal)),
            tokens[0]
        );
    }

    #[test]
    fn literal_with_underscore_end() {
        let literal = "literal_";
        let tokens = parse(literal);

        check_length!(1, tokens);
        check_token!(
            position!(path(), 1, 1, 1, 8),
            TokenKind::Literal(String::from(literal)),
            tokens[0]
        );
    }

    #[test]
    fn literal_with_underscore_middle() {
        let literal = "literal_literal";
        let tokens = parse(literal);

        check_length!(1, tokens);
        check_token!(
            position!(path(), 1, 1, 1, 15),
            TokenKind::Literal(String::from(literal)),
            tokens[0]
        );
    }

    #[test]
    fn documentation_oneline() {
        let doc = "one line documenation";
        let tokens = parse(&format!("=== {doc} ==="));

        check_length!(1, tokens);
        check_token!(
            position!(path(), 1, 1, 1, 29),
            TokenKind::Documentation(doc.to_string()),
            tokens[0]
        );
    }

    #[test]
    fn documentation_multiline() {
        let doc = r#"one line documenation
two line documentation"#;

        let tokens = parse(&format!(
            r#"===
{doc}
==="#
        ));

        check_length!(1, tokens);
        check_token!(
            position!(path(), 1, 1, 4, 3),
            TokenKind::Documentation(doc.to_string()),
            tokens[0]
        );
    }

    #[test]
    fn field_access() {
        let access = "Type=>field";
        let tokens = parse(access);

        check_length!(3, tokens);

        check_token!(
            position!(path(), 1, 1, 1, 4),
            TokenKind::Literal(String::from("Type")),
            tokens[0]
        );
        check_token!(
            position!(path(), 1, 5, 1, 6),
            TokenKind::Symbol(Symbol::DoubleArrow),
            tokens[1]
        );
        check_token!(
            position!(path(), 1, 7, 1, 11),
            TokenKind::Literal(String::from("field")),
            tokens[2]
        );
    }

    #[test]
    fn maths() {
        let maths = r#"1 + func(2) = "four""#;
        let tokens = parse(maths);

        check_length!(8, tokens);
        check_token!(position!(path(), 1, 1, 1, 1), TokenKind::Int(1), &tokens[0]);
        check_token!(
            position!(path(), 1, 3, 1, 3),
            TokenKind::Symbol(Symbol::Plus),
            tokens[1]
        );
        check_token!(
            position!(path(), 1, 5, 1, 8),
            TokenKind::Literal(String::from("func")),
            tokens[2]
        );
        check_token!(
            position!(path(), 1, 9, 1, 9),
            TokenKind::Symbol(Symbol::LeftParen),
            tokens[3]
        );
        check_token!(
            position!(path(), 1, 10, 1, 10),
            TokenKind::Int(2),
            tokens[4]
        );
        check_token!(
            position!(path(), 1, 11, 1, 11),
            TokenKind::Symbol(Symbol::RightParen),
            tokens[5]
        );
        check_token!(
            position!(path(), 1, 13, 1, 13),
            TokenKind::Symbol(Symbol::Equals),
            tokens[6]
        );
        check_token!(
            position!(path(), 1, 15, 1, 20),
            TokenKind::String(String::from("four")),
            tokens[7]
        );
    }

    #[test]
    fn two_lines() {
        let lines = r"struct
20";
        let tokens = parse(lines);

        check_length!(2, tokens);
        check_token!(
            position!(path(), 1, 1, 1, 6),
            TokenKind::Keyword(Keyword::Struct),
            tokens[0]
        );
        check_token!(position!(path(), 2, 1, 2, 2), TokenKind::Int(20), tokens[1]);
    }

    #[test]
    fn singleline_comment() {
        let comment = "// this is a comment";
        check_length!(0, parse(comment));
    }

    #[test]
    fn multiline_comment() {
        let comment = r"/* this is
        a multiline
        comment*/";
        check_length!(0, parse(comment));
    }
}
