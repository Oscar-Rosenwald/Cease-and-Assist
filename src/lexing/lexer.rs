use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;
use std::{cell::RefCell, rc::Rc};

use super::token::*;
use crate::common::errors::{self, LexingError, ToLexingError};
use crate::common::file::*;

pub fn parse_file(file_path: &Path) -> errors::Result<Vec<Token>> {
    let file_name = file_path
        .file_name()
        .ok_or(LexingError::bare("No such file"))?
        .to_str()
        .ok_or(LexingError::bare("File is broken"))?;

    let file = File::open(file_path)
        .map_err(|e| e.wrap_location("Cannot open file", Location::file(file_name)))?;

    let lines = io::BufReader::new(file).lines();

    let mut lexer = Lexer {
        state: Rc::new(RefCell::new(LexerState::Normal(String::new()))),
        tokens: Vec::new(),
        maybe_doc_boundry: false,
    };

    for (line_index, line) in lines.enumerate() {
        let location = Location::line(file_name, line_index + 1);

        let line = line.map_err(|e| {
            e.wrap_location("Failed to read line", location.add_column(line_index + 1))
        })?;

        let mut line_length = 0;
        for (char_index, char) in line.chars().enumerate() {
            let location = location.add_column(char_index + 1);
            line_length += 1;
            lexer.push_char(char, location);
        }

        let location = location.add_column(line_length + 1);
        lexer.push_newline(location);
    }

    let location = Location::file(file_name);
    let mut tokens = lexer.tokens;
    let last_state = Rc::try_unwrap(lexer.state)
        .expect("Who's using my state?")
        .into_inner();

    match last_state {
        LexerState::Normal(_) => Ok(()),
        LexerState::String(_) => Err(LexingError::new("Unterminated string", location)),
        LexerState::Char(_) => Err(LexingError::new("Unterminated character", location)),
        LexerState::Documentation(_) => Err(LexingError::new(
            "Unterminated documentation block",
            location,
        )),
        LexerState::Comment {
            terminator,
            last_char: _,
        } => match terminator {
            CommentTerminator::Newline => Ok(()),
            CommentTerminator::StarSlash => {
                Err(LexingError::new("Unterminated multiline comment", location))
            }
        },
        LexerState::TokenCandidate {
            candidate,
            start_location,
        } => {
            unreachable!("Improperly handled token candidate {candidate} at {start_location}")
        }
    }?;

    tokens.pop_if(|t| match t.type_ {
        TokenType::Newline => true,
        _ => false,
    });

    return Ok(tokens);
}

pub struct Lexer {
    state: Rc<RefCell<LexerState>>,
    maybe_doc_boundry: bool,
    tokens: Vec<Token>,
}

impl Lexer {
    fn push_token(&mut self, token_type: TokenType, location: Location) {
        self.tokens.push(Token::new(token_type, location));
    }

    fn push_newline_token(&mut self, location: Location) {
        let is_newline = |t: &Token| match t.type_ {
            TokenType::Newline => true,
            _ => false,
        };

        let last_is_newline = self.tokens.last().map(is_newline).unwrap_or(false);

        if last_is_newline {
            return;
        }

        self.push_token(TokenType::Newline, location);
    }

    fn push_and_reset(&mut self, token_type: TokenType, location: Location) {
        self.push_token(token_type, location);
        self.state = Rc::new(RefCell::new(LexerState::Normal(String::new())));
    }

    fn push_char(&mut self, c: char, location: Location) {
        let state = self.state.clone();
        let mut state = state.borrow_mut();

        if c != '=' {
            self.maybe_doc_boundry = false;
        }

        match &mut *state {
            LexerState::Normal(word) => self.normal_push_char(c, word, location),
            LexerState::TokenCandidate {
                candidate,
                start_location,
            } => self.token_candidate_push_char(c, candidate, start_location.clone(), location),
            LexerState::String(sentense) => self.string_push_char(c, sentense, location),
            LexerState::Char(character) => self.char_push_char(c, character, location),
            LexerState::Documentation(doc) => self.documentation_push_char(c, doc),
            LexerState::Comment {
                terminator,
                last_char,
            } => self.comment_push_char(c, last_char, terminator),
        }
    }

    fn normal_handle_word(&mut self, word: &str, location: Location) {
        if word.is_empty() {
            return;
        }

        let token_type = if let Ok(keyword) = Keyword::try_from(word) {
            TokenType::Keyword(keyword)
        } else if let Ok(number) = word.parse::<u32>() {
            TokenType::Number(number)
        } else {
            TokenType::Literal(word.to_string())
        };

        self.push_and_reset(token_type, location);
    }

    fn normal_push_char(&mut self, c: char, word: &mut String, location: Location) {
        if c.is_whitespace() {
            if !word.is_empty() {
                self.normal_handle_word(&word, location);
            }
            return;
        }

        let last_token = self
            .tokens
            .last()
            .map(|t| t.to_string())
            .unwrap_or(String::new());

        if c == '/' && last_token == "/" {
            self.normal_handle_comment(word, location);
            return;
        }

        if c == '*' && last_token == "/" {
            self.normal_handle_multiline_comment(word, location);
            return;
        }

        if c == STRING_BOUNDRY {
            self.normal_handle_word(word, location);
            self.state = Rc::new(RefCell::new(LexerState::String(String::new())));
            return;
        }

        if c == CHAR_BOUNDRY {
            self.normal_handle_word(word, location);
            self.state = Rc::new(RefCell::new(LexerState::Char(String::new())));
            return;
        }

        let separator = match WordSeparator::try_from(c) {
            Ok(separator) => separator,
            Err(_) => {
                word.push(c);
                return;
            }
        };

        self.normal_handle_word(&word, location.clone());

        if GroupedChar::is_candidate(c.to_string().as_str()) {
            self.normal_handle_grouped_char_candidate(c, location);
        } else {
            self.push_and_reset(TokenType::WordSeparator(separator), location);
        }
    }

    fn normal_handle_grouped_char_candidate(&mut self, c: char, location: Location) {
        self.state = Rc::new(RefCell::new(LexerState::TokenCandidate {
            candidate: c.to_string(),
            start_location: location,
        }));
    }

    fn normal_handle_comment(&mut self, word: &String, location: Location) {
        self.tokens.pop();
        self.normal_handle_word(word, location);
        self.state = Rc::new(RefCell::new(LexerState::Comment {
            terminator: CommentTerminator::Newline,
            last_char: ' ',
        }));
    }

    fn normal_handle_multiline_comment(&mut self, word: &String, location: Location) {
        self.tokens.pop();
        self.normal_handle_word(word, location);
        self.state = Rc::new(RefCell::new(LexerState::Comment {
            terminator: CommentTerminator::StarSlash,
            last_char: ' ',
        }));
    }

    fn token_candidate_push_char(
        &mut self,
        c: char,
        candidate: &mut String,
        start_location: Location,
        location: Location,
    ) {
        let new_candidate = format!("{candidate}{c}");

        match GroupedChar::try_from(new_candidate.as_str()) {
            // It may seem strange to push rather than store the token, but we
            // need to handle a (hypothentical) case where --> is also a token.
            // I we pushed the token as soon as it's recognised, then when we
            // get to --, we'd greedily delcare that to be the MinusMinus token,
            // but that's ignoring the --> possibility. We need to match on the
            // whole candidate the moment that we NO LONGER match any known
            // tokens with the new char, then push the new character separately.
            Ok(_) => {
                candidate.push(c);
                return;
            }
            Err(_) => {}
        }

        match GroupedChar::try_from(candidate.as_str()) {
            // Now we know it's safe to push.
            Ok(grouped_char) => {
                let maybe_doc_boundry = if let GroupedChar::EqualEqual = grouped_char {
                    true
                } else {
                    false
                };

                self.push_and_reset(TokenType::Group(grouped_char), start_location);
                self.push_char(c, location);
                self.maybe_doc_boundry = maybe_doc_boundry;
                return;
            }
            Err(_) => {}
        }

        if GroupedChar::is_candidate(new_candidate.as_str()) {
            candidate.push(c);
            return;
        }

        self.token_candidate_abort(candidate, start_location);
        self.state = Rc::new(RefCell::new(LexerState::Normal(String::new())));
        self.push_char(c, location);
    }

    fn string_push_char(&mut self, c: char, sentense: &mut String, location: Location) {
        if c != STRING_BOUNDRY {
            sentense.push(c);
            return;
        }

        let escaped_chars_count = sentense.chars().rev().take_while(|c| *c == '\\').count();
        let is_escaped = escaped_chars_count % 2 == 1;

        if is_escaped {
            sentense.push(c);
        } else {
            self.push_and_reset(TokenType::String(sentense.to_string()), location);
        }
    }

    fn char_push_char(&mut self, c: char, character: &mut String, location: Location) {
        if c != CHAR_BOUNDRY {
            character.push(c);
            return;
        }

        let is_escaped = character
            .chars()
            .last()
            .map(|last| last == '\\')
            .unwrap_or(false);

        if is_escaped {
            character.push(c);
        } else {
            self.push_and_reset(TokenType::Char(character.to_string()), location);
        }
    }

    fn documentation_push_char(&mut self, c: char, doc: &mut String) {
        doc.push(c);
    }

    fn comment_push_char(
        &mut self,
        new_char: char,
        last_char: &mut char,
        terminator: &CommentTerminator,
    ) {
        match terminator {
            CommentTerminator::Newline => *last_char = new_char,
            CommentTerminator::StarSlash => {
                if new_char == '/' && *last_char == '*' {
                    self.state = Rc::new(RefCell::new(LexerState::Normal(String::new())));
                } else {
                    *last_char = new_char;
                }
            }
        }
    }

    fn push_newline(&mut self, location: Location) {
        let state = self.state.clone();
        let maybe_doc_boundry = self.maybe_doc_boundry;
        let mut state = state.borrow_mut();

        match &mut *state {
            LexerState::String(sentense) => sentense.push('\n'),
            LexerState::Char(character) => character.push('\n'),
            LexerState::Comment {
                terminator,
                last_char: _,
            } => self.comment_handle_newline(terminator, location),
            LexerState::Normal(word) => {
                self.normal_handle_newline(word, maybe_doc_boundry, location)
            }
            LexerState::Documentation(doc) => self.documentation_handle_newline(doc, location),
            LexerState::TokenCandidate {
                candidate,
                start_location,
            } => self.token_candidate_handle_newline(candidate, start_location, location),
        }
    }

    fn token_candidate_abort(&mut self, candidate: &String, start_location: Location) {
        for (char_index, char) in candidate.chars().enumerate() {
            // All characters of the GroupedChar candidates are word separators,
            // so they can be pushed directly, accounting for the columns.

            let separator = WordSeparator::try_from(char)
                .expect("non-word-separator character treated as a word separator");

            self.push_token(
                TokenType::WordSeparator(separator),
                start_location.add_column(char_index),
            );
        }
    }

    fn comment_handle_newline(&mut self, terminator: &CommentTerminator, location: Location) {
        if let CommentTerminator::Newline = terminator {
            self.state = Rc::new(RefCell::new(LexerState::Normal(String::new())));
        }
        self.push_newline_token(location);
    }

    fn normal_handle_newline(
        &mut self,
        word: &mut String,
        maybe_doc_boundry: bool,
        location: Location,
    ) {
        if !maybe_doc_boundry {
            self.normal_handle_word(word, location.clone());
            self.push_newline_token(location);
            return;
        }

        let mut reversed_tokens: Vec<String> = word.chars().rev().map(|c| c.to_string()).collect();
        let mut last_tokens: Vec<String> =
            self.tokens.iter().rev().map(|t| t.to_string()).collect();
        reversed_tokens.append(&mut last_tokens);

        if !is_documentation_boundry(reversed_tokens.iter()) {
            self.normal_handle_word(word, location.clone());
            self.push_newline_token(location);
            return;
        }

        // Remove the last two '=='s.
        for _ in 0..2 {
            self.tokens.pop();
        }

        self.state = Rc::new(RefCell::new(LexerState::Documentation(String::new())));
        return;
    }

    fn documentation_handle_newline(&mut self, doc: &mut String, location: Location) {
        if !is_documentation_boundry(doc.chars().rev()) {
            doc.push('\n');
            return;
        }

        // Remove the last two '=='s and the extra newline.
        for _ in 0.. {
            let c = doc.pop();
            if c.is_none() {
                break;
            }
            if c.unwrap() == '\n' {
                break;
            }
        }

        self.push_and_reset(TokenType::Documentation(doc.to_string()), location);
    }

    fn token_candidate_handle_newline(
        &mut self,
        candidate: &String,
        start_location: &Location,
        current_location: Location,
    ) {
        if !self.maybe_doc_boundry {
            self.token_candidate_process_eol(candidate, start_location, current_location);
            return;
        }

        let mut reversed_tokens = vec![candidate.to_string()];
        let mut last_tokens: Vec<String> = self
            .tokens
            .iter()
            .rev()
            .take(2)
            .map(|t| t.to_string())
            .collect();
        reversed_tokens.append(&mut last_tokens);

        if !is_documentation_boundry(reversed_tokens.iter()) {
            self.normal_handle_word(candidate, start_location.clone());
            self.push_newline_token(current_location);
            return;
        }

        for _ in 0..2 {
            self.tokens.pop();
        }

        self.state = Rc::new(RefCell::new(LexerState::Documentation(String::new())));
    }

    fn token_candidate_process_eol(
        &mut self,
        candidate: &String,
        start_location: &Location,
        current_location: Location,
    ) {
        match GroupedChar::try_from(candidate.as_str()) {
            Ok(grouped_char) => {
                self.push_and_reset(TokenType::Group(grouped_char), start_location.clone());
            }
            Err(_) => {
                self.token_candidate_abort(candidate, start_location.clone());
                self.state = Rc::new(RefCell::new(LexerState::Normal(String::new())));
            }
        }

        self.push_newline_token(current_location);
    }
}

#[derive(Debug)]
enum LexerState {
    Normal(String), // We'll spend most of the time here
    TokenCandidate {
        candidate: String,
        start_location: Location,
    },
    String(String),
    Char(String),
    Documentation(String),
    Comment {
        terminator: CommentTerminator,
        last_char: char,
    },
}

#[derive(Debug)]
enum CommentTerminator {
    Newline,
    StarSlash,
}

fn is_documentation_boundry<S: ToString, I: Iterator<Item = S>>(reversed_tokens: I) -> bool {
    let mut needed_equals = 4;

    for token in reversed_tokens {
        let expect_newline = needed_equals == 0;
        let token = token.to_string();

        if token == "\n" {
            return expect_newline;
        }

        if token == "==" {
            needed_equals -= 2;
            continue;
        }

        if token == "=" {
            needed_equals -= 1;
            continue;
        }

        let is_whitespace = token
            .chars()
            .fold(true, |prev, c| prev && c.is_whitespace());

        if !is_whitespace {
            return false;
        }
    }

    return needed_equals == 0;
}

#[cfg(test)]
mod tests {
    use super::super::token::*;

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
        run_test(file, vec![]);
    }

    #[test]
    fn comments_and_documentation() {
        let file = "comments-and-docs";
        let expected =vec![
            TokenType::Documentation(
                "This is documentation.\n\n==== Still documentation ====\n=====\nAnd still\n=\nStill\n==\nStill\n===\nStill".to_string(),
            ),
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
            TokenType::Group(GroupedChar::PlusPlus),
            TokenType::Group(GroupedChar::And),
            TokenType::Number(4),
            TokenType::WordSeparator(WordSeparator::Slash),
            TokenType::Number(5),
            TokenType::Group(GroupedChar::EqualEqual),
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
        ];

        run_test(file, expected);
    }

    #[test]
    fn main_function() {
        let file = "main-func";
        let expected = vec![
            TokenType::Documentation(String::from("This is\nmain documentation")),
            TokenType::Keyword(Keyword::Function),
            TokenType::Literal(String::from("main")),
            TokenType::Group(GroupedChar::Tuple),
            TokenType::WordSeparator(WordSeparator::LeftBrace),
            TokenType::Newline,
            TokenType::Literal(String::from("say")),
            TokenType::String(String::from("Stop that")),
            TokenType::Newline,
            TokenType::WordSeparator(WordSeparator::RightBrace),
        ];
        run_test(file, expected);
    }

    #[test]
    fn function_calls() {
        let file = "function-calls";
        let expected = vec![
            TokenType::Keyword(Keyword::Function),
            TokenType::Literal(String::from("function1")),
            TokenType::Group(GroupedChar::Tuple),
            TokenType::Group(GroupedChar::Arrow),
            TokenType::Literal(String::from("int")),
            TokenType::WordSeparator(WordSeparator::LeftBrace),
            TokenType::Newline,
            TokenType::Number(1),
            TokenType::Newline,
            TokenType::WordSeparator(WordSeparator::RightBrace),
            TokenType::Newline,
            TokenType::Keyword(Keyword::Function),
            TokenType::Literal(String::from("function2")),
            TokenType::Group(GroupedChar::Tuple),
            TokenType::Group(GroupedChar::Arrow),
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
            TokenType::Group(GroupedChar::Arrow),
            TokenType::Literal(String::from("int")),
            TokenType::WordSeparator(WordSeparator::LeftBrace),
            TokenType::Newline,
            TokenType::Literal(String::from("return")),
            TokenType::Literal(String::from("x")),
            TokenType::Newline,
            TokenType::WordSeparator(WordSeparator::RightBrace),
            TokenType::Documentation(String::from("Some docs to the mix.")),
            TokenType::Keyword(Keyword::Function),
            TokenType::Literal(String::from("main")),
            TokenType::Group(GroupedChar::Tuple),
            TokenType::WordSeparator(WordSeparator::LeftBrace),
            TokenType::Newline,
            TokenType::Literal(String::from("say")),
            TokenType::Literal(String::from("functionX")),
            TokenType::WordSeparator(WordSeparator::LeftParen),
            TokenType::Literal(String::from("function1")),
            TokenType::Group(GroupedChar::Tuple),
            TokenType::WordSeparator(WordSeparator::Plus),
            TokenType::Literal(String::from("function2")),
            TokenType::Group(GroupedChar::Tuple),
            TokenType::WordSeparator(WordSeparator::RightParen),
            TokenType::Newline,
            TokenType::WordSeparator(WordSeparator::RightBrace),
        ];

        run_test(file, expected);
    }

    #[test]
    fn func_and_pipe_calls() {
        let file = "func-and-pipe-calls";
        let expected = vec![
            TokenType::Keyword(Keyword::Function),
            TokenType::Literal(String::from("function1")),
            TokenType::Group(GroupedChar::Tuple),
            TokenType::Group(GroupedChar::Arrow),
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
            TokenType::Group(GroupedChar::Arrow),
            TokenType::Literal(String::from("int")),
            TokenType::WordSeparator(WordSeparator::LeftBrace),
            TokenType::Newline,
            TokenType::Literal(String::from("return")),
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
            TokenType::Group(GroupedChar::GrabbyPipe),
            TokenType::Literal(String::from("double")),
            TokenType::Group(GroupedChar::Tuple),
            TokenType::Group(GroupedChar::Arrow),
            TokenType::Literal(String::from("int")),
            TokenType::WordSeparator(WordSeparator::LeftBrace),
            TokenType::Literal(String::from("me")),
            TokenType::WordSeparator(WordSeparator::Star),
            TokenType::Number(2),
            TokenType::WordSeparator(WordSeparator::RightBrace),
            TokenType::Newline,
            TokenType::Keyword(Keyword::Function),
            TokenType::Literal(String::from("main")),
            TokenType::Group(GroupedChar::Tuple),
            TokenType::WordSeparator(WordSeparator::LeftBrace),
            TokenType::Newline,
            TokenType::Keyword(Keyword::New),
            TokenType::Literal(String::from("x")),
            TokenType::WordSeparator(WordSeparator::Equal),
            TokenType::Literal(String::from("function1")),
            TokenType::Group(GroupedChar::Tuple),
            TokenType::Newline,
            TokenType::WordSeparator(WordSeparator::Bar),
            TokenType::Literal(String::from("add")),
            TokenType::Number(8),
            TokenType::Newline,
            TokenType::Group(GroupedChar::GrabbyPipe),
            TokenType::Literal(String::from("double")),
            TokenType::Newline,
            TokenType::Literal(String::from("say")),
            TokenType::Literal(String::from("x")),
            TokenType::Newline,
            TokenType::WordSeparator(WordSeparator::RightBrace),
        ];

        run_test(file, expected);
    }

    #[test]
    fn wrong_formatting() {
        let file = "wrong-formatting";
        let expected = vec![
            TokenType::Keyword(Keyword::Function),
            TokenType::WordSeparator(WordSeparator::LeftParen),
            TokenType::Newline,
            TokenType::Literal(String::from("x")),
            TokenType::Newline,
            TokenType::WordSeparator(WordSeparator::Colon),
            TokenType::Newline,
            TokenType::Literal(String::from("int")),
            TokenType::WordSeparator(WordSeparator::RightParen),
            TokenType::Group(GroupedChar::Arrow),
            TokenType::Newline,
            TokenType::Literal(String::from("int")),
            TokenType::Newline,
            TokenType::WordSeparator(WordSeparator::LeftBrace),
            TokenType::Newline,
            TokenType::Literal(String::from("return")),
            TokenType::Newline,
            TokenType::Literal(String::from("x")),
            TokenType::WordSeparator(WordSeparator::RightBrace),
            TokenType::Newline,
            TokenType::Keyword(Keyword::Function),
            TokenType::Literal(String::from("main")),
            TokenType::Group(GroupedChar::Tuple),
            TokenType::WordSeparator(WordSeparator::LeftBrace),
            TokenType::Newline,
            TokenType::Literal(String::from("say")),
            TokenType::Literal(String::from("x")),
            TokenType::WordSeparator(WordSeparator::RightBrace),
        ];

        run_test(file, expected);
    }
}
