use super::state_machine::*;
use super::token::*;
use crate::common::errors::{self, LexingError, ToLexingError};
use crate::common::file::*;

use std::collections::VecDeque;
use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

/// Reads code from the given file path and converts it into a series of tokens.
/// The only processing on the tokens afterwards is that there are neveer two
/// newlines in a row.
pub fn parse_file(file_path: &Path) -> errors::Result<VecDeque<Token>> {
    let file_name = file_path
        .file_name()
        .ok_or(LexingError::bare("No such file"))?
        .to_str()
        .ok_or(LexingError::bare("File is broken"))?;

    let file = File::open(file_path)
        .map_err(|e| e.wrap_location("Cannot open file", Location::file(file_name)))?;

    let lines = io::BufReader::new(file).lines();

    let mut lexer = Lexer::new();
    let mut ret_tokens = Vec::new();

    for (line_index, line) in lines.enumerate() {
        parse_line(&mut lexer, &mut ret_tokens, file_name, line_index + 1, line)?;
    }

    let location = Location::file(file_name);
    return Ok(lexer.process_eof(ret_tokens, location)?);
}

/// Turns one line into a series of tokens and writes them into `tokens`.
fn parse_line(
    lexer: &mut Lexer,
    tokens: &mut Vec<Token>,
    file_name: &str,
    line_number: usize,
    line: Result<String, io::Error>,
) -> errors::Result<()> {
    let location = Location::line(file_name, line_number);

    let line =
        line.map_err(|e| e.wrap_location("Failed to read line", location.add_column(line_number)))?;

    let mut line_length = 0;
    for (char_index, char) in line.chars().enumerate() {
        let location = location.add_column(char_index + 1);
        line_length += 1;
        let mut new_tokens = lexer.push_char(char, location)?;
        tokens.append(&mut new_tokens);
    }

    let location = location.add_column(line_length + 1);
    let mut new_tokens = lexer.push_newline(location)?;
    tokens.append(&mut new_tokens);

    Ok(())
}

#[cfg(test)]
mod tests {
    use crate::lexing::*;

    const TEST_DIR: &'static str = "src/lexing/tests";

    fn run_test(file_base_name: &str, expected_tokens: Vec<TokenType>) {
        let file_path = std::path::PathBuf::from(format!("{TEST_DIR}/{file_base_name}.stop",));

        let tokens: Vec<TokenType> = super::parse_file(&file_path)
            .expect(&format!("Failed to parse file {file_base_name}"))
            .iter()
            .map(|token| token.type_.clone())
            .collect();

        assert_eq!(tokens, expected_tokens);
    }

    #[test]
    fn empty_file() {
        let file = "empty";
        run_test(file, vec![TokenType::EndOfFile]);
    }

    #[test]
    fn comments_and_documentation() {
        let file = "comments-and-docs";
        let expected =vec![
            TokenType::Newline,
            TokenType::Documentation(
                "This is documentation.\n\n==== Still documentation ====\n=====\nAnd still\n=\nStill\n==\nStill\n===\nStill\n".to_string(),
            ),
            TokenType::EndOfFile,
        ];

        run_test(file, expected);
    }

    #[test]
    fn only_expressions() {
        let file = "expressions";
        let expected = vec![
            TokenType::Number(1),
            TokenType::WordSeparator(WordSeparator::Plus),
            TokenType::Number(2),
            TokenType::WordSeparator(WordSeparator::Star),
            TokenType::Number(3),
            TokenType::Symbol(Symbol::PlusPlus),
            TokenType::Symbol(Symbol::And),
            TokenType::Number(4),
            TokenType::WordSeparator(WordSeparator::Slash),
            TokenType::Number(5),
            TokenType::Symbol(Symbol::EqualEqual),
            TokenType::Number(6),
            TokenType::WordSeparator(WordSeparator::LeftChevron),
            TokenType::WordSeparator(WordSeparator::LeftParen),
            TokenType::Number(7),
            TokenType::WordSeparator(WordSeparator::Slash),
            TokenType::Number(8),
            TokenType::WordSeparator(WordSeparator::Minus),
            TokenType::WordSeparator(WordSeparator::Minus),
            TokenType::Number(9),
            TokenType::WordSeparator(WordSeparator::RightParen),
            TokenType::WordSeparator(WordSeparator::Star),
            TokenType::WordSeparator(WordSeparator::Minus),
            TokenType::WordSeparator(WordSeparator::LeftParen),
            TokenType::Number(10),
            TokenType::WordSeparator(WordSeparator::RightParen),
            TokenType::EndOfFile,
        ];

        run_test(file, expected);
    }

    #[test]
    fn main_function() {
        let file = "main-func";
        let expected = vec![
            TokenType::Documentation(String::from("This is\nmain documentation\n")),
            TokenType::Keyword(Keyword::Function),
            TokenType::Literal(String::from("main")),
            TokenType::WordSeparator(WordSeparator::LeftParen),
            TokenType::WordSeparator(WordSeparator::RightParen),
            TokenType::WordSeparator(WordSeparator::LeftBrace),
            TokenType::Char('c'),
            TokenType::Newline,
            TokenType::Literal(String::from("say")),
            TokenType::String(String::from("Stop that")),
            TokenType::Newline,
            TokenType::WordSeparator(WordSeparator::RightBrace),
            TokenType::EndOfFile,
        ];
        run_test(file, expected);
    }

    #[test]
    fn function_calls() {
        let file = "function-calls";
        let expected = vec![
            TokenType::Keyword(Keyword::Function),
            TokenType::Literal(String::from("function1")),
            TokenType::WordSeparator(WordSeparator::LeftParen),
            TokenType::WordSeparator(WordSeparator::RightParen),
            TokenType::Symbol(Symbol::Arrow),
            TokenType::Literal(String::from("int")),
            TokenType::WordSeparator(WordSeparator::LeftBrace),
            TokenType::Number(1),
            TokenType::Newline,
            TokenType::WordSeparator(WordSeparator::RightBrace),
            TokenType::Newline,
            TokenType::Keyword(Keyword::Function),
            TokenType::Literal(String::from("function2")),
            TokenType::WordSeparator(WordSeparator::LeftParen),
            TokenType::WordSeparator(WordSeparator::RightParen),
            TokenType::Symbol(Symbol::Arrow),
            TokenType::Literal(String::from("int")),
            TokenType::WordSeparator(WordSeparator::LeftBrace),
            TokenType::Number(2),
            TokenType::WordSeparator(WordSeparator::RightBrace),
            TokenType::Newline,
            TokenType::Keyword(Keyword::Function),
            TokenType::Literal(String::from("functionX")),
            TokenType::WordSeparator(WordSeparator::LeftParen),
            TokenType::Literal(String::from("x")),
            TokenType::WordSeparator(WordSeparator::Colon),
            TokenType::Literal(String::from("int")),
            TokenType::WordSeparator(WordSeparator::RightParen),
            TokenType::Symbol(Symbol::Arrow),
            TokenType::Literal(String::from("int")),
            TokenType::WordSeparator(WordSeparator::LeftBrace),
            TokenType::Keyword(Keyword::Return),
            TokenType::Literal(String::from("x")),
            TokenType::Newline,
            TokenType::WordSeparator(WordSeparator::RightBrace),
            TokenType::Newline,
            TokenType::Documentation(String::from("Some docs to the mix.\n")),
            TokenType::Keyword(Keyword::Function),
            TokenType::Literal(String::from("main")),
            TokenType::WordSeparator(WordSeparator::LeftParen),
            TokenType::WordSeparator(WordSeparator::RightParen),
            TokenType::WordSeparator(WordSeparator::LeftBrace),
            TokenType::Literal(String::from("say")),
            TokenType::Literal(String::from("functionX")),
            TokenType::WordSeparator(WordSeparator::LeftParen),
            TokenType::Literal(String::from("function1")),
            TokenType::WordSeparator(WordSeparator::LeftParen),
            TokenType::WordSeparator(WordSeparator::RightParen),
            TokenType::WordSeparator(WordSeparator::Plus),
            TokenType::Literal(String::from("function2")),
            TokenType::WordSeparator(WordSeparator::LeftParen),
            TokenType::WordSeparator(WordSeparator::RightParen),
            TokenType::WordSeparator(WordSeparator::RightParen),
            TokenType::Newline,
            TokenType::WordSeparator(WordSeparator::RightBrace),
            TokenType::EndOfFile,
        ];

        run_test(file, expected);
    }

    #[test]
    fn func_and_pipe_calls() {
        let file = "func-and-pipe-calls";
        let expected = vec![
            TokenType::Keyword(Keyword::Function),
            TokenType::Literal(String::from("function1")),
            TokenType::WordSeparator(WordSeparator::LeftParen),
            TokenType::WordSeparator(WordSeparator::RightParen),
            TokenType::Symbol(Symbol::Arrow),
            TokenType::Literal(String::from("int")),
            TokenType::WordSeparator(WordSeparator::LeftBrace),
            TokenType::Number(1),
            TokenType::WordSeparator(WordSeparator::RightBrace),
            TokenType::Newline,
            TokenType::Keyword(Keyword::Pipe),
            TokenType::WordSeparator(WordSeparator::LeftParen),
            TokenType::Literal(String::from("me")),
            TokenType::WordSeparator(WordSeparator::Colon),
            TokenType::Literal(String::from("int")),
            TokenType::WordSeparator(WordSeparator::RightParen),
            TokenType::WordSeparator(WordSeparator::Bar),
            TokenType::Literal(String::from("add")),
            TokenType::WordSeparator(WordSeparator::LeftParen),
            TokenType::Literal(String::from("x")),
            TokenType::WordSeparator(WordSeparator::Colon),
            TokenType::Literal(String::from("int")),
            TokenType::WordSeparator(WordSeparator::RightParen),
            TokenType::Symbol(Symbol::Arrow),
            TokenType::Literal(String::from("int")),
            TokenType::WordSeparator(WordSeparator::LeftBrace),
            TokenType::Keyword(Keyword::Return),
            TokenType::Literal(String::from("me")),
            TokenType::WordSeparator(WordSeparator::Plus),
            TokenType::Literal(String::from("x")),
            TokenType::Newline,
            TokenType::WordSeparator(WordSeparator::RightBrace),
            TokenType::Newline,
            TokenType::Keyword(Keyword::Pipe),
            TokenType::WordSeparator(WordSeparator::LeftParen),
            TokenType::Literal(String::from("me")),
            TokenType::WordSeparator(WordSeparator::Colon),
            TokenType::Literal(String::from("int")),
            TokenType::WordSeparator(WordSeparator::RightParen),
            TokenType::Symbol(Symbol::GrabbyPipe),
            TokenType::Literal(String::from("double")),
            TokenType::WordSeparator(WordSeparator::LeftParen),
            TokenType::WordSeparator(WordSeparator::RightParen),
            TokenType::Symbol(Symbol::Arrow),
            TokenType::Literal(String::from("int")),
            TokenType::WordSeparator(WordSeparator::LeftBrace),
            TokenType::Literal(String::from("me")),
            TokenType::WordSeparator(WordSeparator::Star),
            TokenType::Number(2),
            TokenType::WordSeparator(WordSeparator::RightBrace),
            TokenType::Newline,
            TokenType::Keyword(Keyword::Function),
            TokenType::Literal(String::from("main")),
            TokenType::WordSeparator(WordSeparator::LeftParen),
            TokenType::WordSeparator(WordSeparator::RightParen),
            TokenType::WordSeparator(WordSeparator::LeftBrace),
            TokenType::Keyword(Keyword::New),
            TokenType::Literal(String::from("x")),
            TokenType::WordSeparator(WordSeparator::Equal),
            TokenType::Literal(String::from("function1")),
            TokenType::WordSeparator(WordSeparator::LeftParen),
            TokenType::WordSeparator(WordSeparator::RightParen),
            TokenType::WordSeparator(WordSeparator::Bar),
            TokenType::Literal(String::from("add")),
            TokenType::Number(8),
            TokenType::Symbol(Symbol::GrabbyPipe),
            TokenType::Literal(String::from("double")),
            TokenType::Newline,
            TokenType::Literal(String::from("say")),
            TokenType::Literal(String::from("x")),
            TokenType::Newline,
            TokenType::WordSeparator(WordSeparator::RightBrace),
            TokenType::EndOfFile,
        ];

        run_test(file, expected);
    }

    #[test]
    fn wrong_formatting() {
        let file = "wrong-formatting";
        let expected = vec![
            TokenType::Keyword(Keyword::Function),
            TokenType::WordSeparator(WordSeparator::LeftParen),
            TokenType::Literal(String::from("x")),
            TokenType::WordSeparator(WordSeparator::Colon),
            TokenType::Literal(String::from("int")),
            TokenType::WordSeparator(WordSeparator::RightParen),
            TokenType::Symbol(Symbol::Arrow),
            TokenType::Literal(String::from("int")),
            TokenType::WordSeparator(WordSeparator::LeftBrace),
            TokenType::Keyword(Keyword::Return),
            TokenType::Newline,
            TokenType::Literal(String::from("x")),
            TokenType::WordSeparator(WordSeparator::RightBrace),
            TokenType::Newline,
            TokenType::Keyword(Keyword::Function),
            TokenType::Literal(String::from("main")),
            TokenType::WordSeparator(WordSeparator::LeftParen),
            TokenType::WordSeparator(WordSeparator::RightParen),
            TokenType::WordSeparator(WordSeparator::LeftBrace),
            TokenType::Literal(String::from("say")),
            TokenType::Literal(String::from("x")),
            TokenType::WordSeparator(WordSeparator::RightBrace),
            TokenType::EndOfFile,
        ];

        run_test(file, expected);
    }
}
