use super::token::*;
use crate::common::errors;
use crate::common::file::*;
use crate::common::slice::filter_window;

use std::collections::VecDeque;
use std::default::Default;
use std::string::ToString;

const DOCUMENTATION_TAG: &'static str = "====";
const MULTILINE_COMMENT_END: char = '*';
const COMMENT_START: char = '/';
const STRING_ESCAPE: char = '\\';
const STRING_BOUNDRY: char = '"';
const CHAR_BOUNDRY: char = '\'';
const EQUAL_SIGN: char = '=';
const NEWLINE: char = '\n';
const SPACE: char = ' ';
const DOT: char = '.';

/// Convenience vector wrapper.
pub(super) type Tokens = Vec<Token>;

/// The object which is passed characters one by one and turns them into tokens
/// when appropriate. It keeps an internal state which dictates how new
/// characters are interpreted. In turn, the characters dictate which state
/// Lexer is in.
pub(super) struct Lexer {
    state: State,
}

// public methods
impl Lexer {
    pub(super) fn new() -> Self {
        Self {
            // Start in the newline state so that potential newlines at the
            // start of the file are ignored.
            state: State::Newline,
        }
    }

    /// Pushes any non-newline character into the lexer.
    pub(super) fn push_char(&mut self, c: char, location: Location) -> errors::Result<Tokens> {
        if c.is_whitespace() {
            return self.push_whitespace(c, location);
        }

        let state = std::mem::take(&mut self.state);
        let (tokens, new_state) = state.push_char(c, location)?;
        self.set_state(new_state);
        return Ok(tokens);
    }

    /// Pushes a newline signal to the lexer. This must be handled explicitly
    /// because reading files often results in iterating over lines and that
    /// strips the newline character at the end.
    ///
    /// It should also be called at the end of a file.
    pub(super) fn push_newline(&mut self, location: Location) -> errors::Result<Tokens> {
        let state = std::mem::take(&mut self.state);

        let (tokens, new_state) = match state {
            State::Newline => (vec![], State::Newline),
            State::MultilineComment => (vec![], State::MultilineComment),
            State::OnelineComment => (vec![], State::Newline),
            State::MultilineCommentEnd => (vec![], State::MultilineComment),
            State::StringWhitespace(chars) => (vec![], State::StringWhitespace(chars)),
            State::String(chars) => (vec![], State::StringWhitespace(chars.add_char(SPACE))),
            State::Symbols(chars) => {
                let (mut tokens, new_state) = chars.process_symbols(location.clone())?;
                if new_state.is_none() {
                    tokens.push(Token::new(TokenType::Newline, location.clone(), location));
                }
                (tokens, new_state.unwrap_or(State::Newline))
            }
            State::SymbolCommentCandidate(candidate) => {
                let chars = candidate.chars_thus_far.add_char(COMMENT_START);
                let (tokens, new_state) = chars.process_symbols(location)?;
                (tokens, new_state.unwrap_or(State::Newline))
            }
            State::Whitespace => (
                vec![Token::new(TokenType::Newline, location.clone(), location)],
                State::Newline,
            ),
            State::Word(chars) => {
                let token = chars.process_word(location.clone());
                let new_token = Token::new(TokenType::Newline, location.clone(), location);
                (vec![token, new_token], State::Newline)
            }
            State::Number(chars) => {
                let token = chars.process_number(location.clone())?;
                let newline = Token::new(TokenType::Newline, location.clone(), location);
                (vec![token, newline], State::Newline)
            }
            State::DecimalNumber { base, decimal } => {
                let token = base.process_decimal_number(decimal, location.clone())?;
                let newline = Token::new(TokenType::Newline, location.clone(), location);
                (vec![token, newline], State::Newline)
            }
            State::Char(_) => {
                return Err(errors::LexingError::new(
                    "Unterminated character sequence",
                    location,
                ));
            }
            State::Documentation(doc) => {
                (vec![], State::DocumentationNewline(doc.add_char(NEWLINE)))
            }
            State::DocumentationNewline(doc) => {
                (vec![], State::DocumentationNewline(doc.add_char(NEWLINE)))
            }
            State::DocumentationEnd { docs, end } => {
                if end.len() == DOCUMENTATION_TAG.len() {
                    let token = Token::new(
                        TokenType::Documentation(docs.to_string()),
                        docs.start_location,
                        location,
                    );
                    (vec![token], State::Newline)
                } else {
                    let new_state = State::Documentation(docs.add_more(end).add_char(NEWLINE));
                    (vec![], new_state)
                }
            }
            State::EolComment => {
                let newline = Token::new(TokenType::Newline, location.clone(), location);
                (vec![newline], State::Newline)
            }
        };

        self.set_state(new_state);

        return Ok(tokens);
    }

    /// Performs simple processing on `tokens` (only allowing one newline in a
    /// row), then insures that all multi-word tokens (such as strings) have
    /// been terminated.
    pub(super) fn process_eof(
        self,
        mut tokens: Vec<Token>,
        location: Location,
    ) -> errors::Result<VecDeque<Token>> {
        tokens.push(Token::new(
            TokenType::EndOfFile,
            location.clone(),
            location.clone(),
        ));
        let tokens = filter_window(tokens, include_middle);

        let error_msg = match self.state {
            State::Whitespace => return Ok(tokens),
            State::Newline => return Ok(tokens),
            State::Word(_) => "Badly processed word",
            State::Number(_) => "Badly processed number",
            State::DecimalNumber {
                base: _,
                decimal: _,
            } => "Badly processed decimal number",
            State::String(_) => "Unterminated string sequence",
            State::StringWhitespace(_) => "Unterminated string sequence",
            State::Char(_) => "Unterminated character sequence",
            State::Symbols(_) => "Badly processed symbol sequence",
            State::SymbolCommentCandidate(_) => "Badly processed comment candidate sequence",
            State::Documentation(_) => "Unterminated documentation block",
            State::DocumentationNewline(_) => "Unterminated documentation block",
            State::DocumentationEnd { docs: _, end: _ } => "Unterminated documentation block",
            State::OnelineComment => "Unterminated comment",
            State::EolComment => "Unterminated comment",
            State::MultilineComment => "Unterminated comment",
            State::MultilineCommentEnd => "Unterminated comment",
        };

        return Err(errors::LexingError::new(error_msg, location));
    }
}

// private methods
impl Lexer {
    fn set_state(&mut self, state: State) {
        self.state = state;
    }

    /// Pushes a whitespace character to Lexer. This usually forces accumulated
    /// tokens to be processed. E.e. when parsing this line:
    ///
    /// ```
    /// new x = 5
    /// ```
    ///
    /// We'll first accumulate "new" in the Lexer, then get a whitespace
    /// character, which reads "new" and realises it's a keyword.
    ///
    /// Whitespace must **NEVER** be a newline. There's a [`Self::push_newline`]
    /// for that.
    fn push_whitespace(&mut self, new_c: char, location: Location) -> errors::Result<Tokens> {
        let state = std::mem::take(&mut self.state);

        let (tokens, new_state) = match state {
            State::MultilineCommentEnd => (vec![], State::MultilineCommentEnd),
            State::MultilineComment => (vec![], State::MultilineComment),
            State::OnelineComment => (vec![], State::OnelineComment),
            State::EolComment => (vec![], State::EolComment),
            State::Whitespace => (vec![], State::Whitespace),
            State::Newline => (vec![], State::Newline),
            State::Word(word) => {
                let token = word.process_word(location);
                (vec![token], State::Whitespace)
            }
            State::Number(number) => (vec![], State::Number(number)),
            State::DecimalNumber { base, decimal } => {
                (vec![], State::DecimalNumber { base, decimal })
            }
            State::String(sentense) => (vec![], State::String(sentense.add_char(new_c))),
            State::StringWhitespace(sentense) => (vec![], State::StringWhitespace(sentense)),
            State::Char(chars) => chars.char_push_char(new_c, location)?,
            State::Symbols(symbols) => {
                let (tokens, state) = symbols.process_symbols(location)?;
                (tokens, state.unwrap_or(State::Whitespace))
            }
            State::SymbolCommentCandidate(candidate) => {
                let symbols = candidate.chars_thus_far.add_char(COMMENT_START);
                let (tokens, state) = symbols.process_symbols(location)?;
                (tokens, state.unwrap_or(State::Whitespace))
            }
            State::Documentation(docs) => (vec![], State::Documentation(docs.add_char(new_c))),
            State::DocumentationEnd { docs, end } => documentation_end_push_char(docs, end, new_c),
            State::DocumentationNewline(docs) => {
                (vec![], State::Documentation(docs.add_char(new_c)))
            }
        };

        self.state = new_state;
        return Ok(tokens);
    }
}

/// An object which keeps track of the characters read thus far in one Lexer
/// state and the file location where they started.
struct Chars {
    chars: Vec<char>,
    start_location: Location,
}

impl Chars {
    fn new(start_location: Location) -> Self {
        Self {
            chars: Vec::new(),
            start_location,
        }
    }

    fn add_char(mut self, c: char) -> Self {
        self.chars.push(c);
        self
    }

    fn add_more(mut self, cs: Vec<char>) -> Self {
        for c in cs {
            self.chars.push(c);
        }
        self
    }

    /// Pushes a character, assuming `self` is [`State::Documentation`] or its
    /// variant.
    fn doc_push_char(self, new_c: char) -> State {
        if new_c != EQUAL_SIGN {
            return State::Documentation(self.add_char(new_c));
        }

        let state = State::DocumentationEnd {
            docs: self,
            end: vec!['='],
        };

        return state;
    }

    /// Pushes a character, assuming `self` is [`State::Symbols`] or its
    /// variant.
    fn symbol_push_char(self, new_c: char, location: Location) -> errors::Result<(Tokens, State)> {
        if new_c == COMMENT_START {
            let candidate = SymbolComment {
                chars_thus_far: Chars::new(location),
                comment_candidacy: CommentCandidacy::Eol,
            };
            return Ok((vec![], State::SymbolCommentCandidate(candidate)));
        }

        if let Ok(_) = WordSeparator::try_from(new_c)
            && new_c != STRING_BOUNDRY
            && new_c != CHAR_BOUNDRY
        {
            return Ok((vec![], State::Symbols(self.add_char(new_c))));
        }

        let (mut tokens, new_state) = self.process_symbols(location.clone())?;

        if let Some(new_state) = new_state {
            let (mut new_tokens, newer_state) = new_state.push_char(new_c, location)?;
            tokens.append(&mut new_tokens);
            return Ok((tokens, newer_state));
        }

        let new_state = process_first_char(new_c, CommentCandidacy::Eol, location);
        return Ok((tokens, new_state));
    }

    /// Pushes a character, assuming `self` is [`State::Word`].
    fn word_push_char(mut self, new_c: char, location: Location) -> (Tokens, State) {
        let is_string_start = new_c == STRING_BOUNDRY;

        if let Err(_) = WordSeparator::try_from(new_c)
            && !is_string_start
        {
            return (vec![], State::Word(self.add_char(new_c)));
        }

        let start_location = std::mem::take(&mut self.start_location);

        let word = self.to_string();
        let token = match Keyword::try_from(word.as_str()) {
            Ok(kw) => Token::new(TokenType::Keyword(kw), start_location, location.clone()),
            Err(_) => Token::new(
                TokenType::Literal(self.to_string()),
                start_location,
                location.clone(),
            ),
        };

        let new_state = if is_string_start {
            let string = StringState {
                chars: Chars::new(location),
                escaped: false,
            };
            State::String(string)
        } else {
            State::Symbols(Chars::new(location).add_char(new_c))
        };

        return (vec![token], new_state);
    }

    /// Pushes a character, assuming `self` is [`State::Number`].
    fn number_push_char(self, new_c: char, location: Location) -> errors::Result<(Tokens, State)> {
        if new_c.is_numeric() {
            return Ok((vec![], State::Number(self.add_char(new_c))));
        }

        if new_c == DOT {
            let new_state = State::DecimalNumber {
                base: self,
                decimal: Vec::new(),
            };
            return Ok((vec![], new_state));
        }

        if let Err(_) = WordSeparator::try_from(new_c)
            && new_c != STRING_BOUNDRY
            && new_c != CHAR_BOUNDRY
        {
            return Err(errors::LexingError::new("Invalid number format", location));
        }

        let number = self
            .to_string()
            .parse::<u32>()
            .expect("Rust has a numeric bug???");

        let token = Token::new(
            TokenType::Number(number),
            self.start_location,
            location.clone(),
        );

        let state = process_first_char(new_c, CommentCandidacy::Eol, location);
        return Ok((vec![token], state));
    }

    /// Treats self as a collection of symbols which are returned as tokens.
    /// Returns a valid state to transition into if one can be ascertained, or
    /// None if it's up to the caller.
    fn process_symbols(self, end_location: Location) -> errors::Result<(Tokens, Option<State>)> {
        let symbol_str = self.to_string();

        if symbol_str == DOCUMENTATION_TAG {
            return Ok((vec![], Some(State::Documentation(Chars::new(end_location)))));
        }

        match Symbol::try_from(symbol_str.as_str()) {
            Ok(symbol) => {
                let token =
                    Token::new(TokenType::Symbol(symbol), self.start_location, end_location);

                return Ok((vec![token], None));
            }
            Err(_) => {}
        }

        let mut tokens = Vec::new();

        for (char_index, c) in self.chars.iter().enumerate() {
            let separator = WordSeparator::try_from(*c).map_err(|_| {
                errors::LexingError::new(
                    format!("{c} is not a word separator"),
                    end_location.clone(),
                )
            })?;

            let start_location = self.start_location.add_column(char_index);

            let token = Token::new(
                TokenType::WordSeparator(separator),
                start_location,
                end_location.clone(),
            );

            tokens.push(token);
        }

        Ok((tokens, None))
    }

    /// Turns self into a token, assuming self is the data of [`State::Word`].
    fn process_word(self, location: Location) -> Token {
        let word = self.to_string();

        let type_ = match Keyword::try_from(word.as_str()) {
            Ok(kw) => TokenType::Keyword(kw),
            Err(_) => TokenType::Literal(word),
        };

        return Token::new(type_, self.start_location, location);
    }

    /// Turns self into a token, assuming self is the data of [`State::Number`].
    fn process_number(self, location: Location) -> errors::Result<Token> {
        let word = self.to_string();

        word.parse::<u32>()
            .map_err(|e| {
                errors::LexingError::wrap(format!("Invalid number {word}"), e, location.clone())
            })
            .map(|n| Token::new(TokenType::Number(n), self.start_location, location))
    }

    /// Turns self into a token, assuming self is the data of
    /// [`State::DecimalNumber`].
    fn process_decimal_number(
        self,
        decimal: Vec<char>,
        location: Location,
    ) -> errors::Result<Token> {
        let word = self.to_string();
        let base = word.parse::<u32>().map_err(|e| {
            errors::LexingError::wrap(format!("Invalid number {word}"), e, location.clone())
        })?;

        let word: String = decimal.iter().collect();
        let decimal = word.parse::<u32>().map_err(|e| {
            errors::LexingError::wrap(format!("Invalid number {word}"), e, location.clone())
        })?;

        return Ok(Token::new(
            TokenType::DecimalNumber(base, decimal),
            self.start_location,
            location,
        ));
    }
}

impl ToString for Chars {
    fn to_string(&self) -> String {
        self.chars.iter().collect()
    }
}

struct StringState {
    chars: Chars,
    /// Is the next character escaped? If so, it'll be treated differently.
    escaped: bool,
}

impl StringState {
    fn add_char(mut self, new_c: char) -> Self {
        self.chars = self.chars.add_char(new_c);
        self.escaped = false;
        self
    }

    /// Pushes character into `self` assuming `self` is the data of
    /// [`State::Char`].
    fn char_push_char(
        mut self,
        new_c: char,
        location: Location,
    ) -> errors::Result<(Tokens, State)> {
        if self.escaped {
            // TODO Support for escaped characters
        }

        if new_c == STRING_ESCAPE {
            self.escaped = true;
            return Ok((vec![], State::Char(self)));
        }

        if new_c == CHAR_BOUNDRY && self.chars.chars.len() != 1 {
            return Err(errors::LexingError::new(
                "Invalid character sequence",
                self.chars.start_location,
            ));
        }

        if new_c == CHAR_BOUNDRY {
            let start_location = std::mem::take(&mut self.chars.start_location);
            let token = Token::new(
                TokenType::Char(self.chars.chars[0]),
                start_location,
                location,
            );
            return Ok((vec![token], State::Whitespace));
        }

        self.chars = self.chars.add_char(new_c);
        return Ok((vec![], State::Char(self)));
    }

    /// Pushes character into `self` assuming `self` is the data of
    /// [`State::String`].
    fn string_push_char(mut self, new_c: char, location: Location) -> (Tokens, State) {
        if self.escaped {
            // TODO Support for escaped characters
        }

        if new_c == STRING_ESCAPE {
            self.escaped = true;
            return (vec![], State::String(self));
        }

        if new_c == STRING_BOUNDRY {
            let start_location = std::mem::take(&mut self.chars.start_location);
            let token = Token::new(
                TokenType::String(self.chars.to_string()),
                start_location,
                location,
            );
            return (vec![token], State::Whitespace);
        }

        self.chars = self.chars.add_char(new_c);
        return (vec![], State::String(self));
    }
}

/// When reading symbols, we may at any point transition into a comment.
/// Comments come in three varieties. One is handled implicitly - '/*...*/' is
/// always recognisable, but '//...' can either follow non-comment text or a
/// newline and some whitespace. To differentiate between those, we'll give the
/// first character '/' a candidacy.
enum CommentCandidacy {
    /// For comments like:
    ///
    /// ```
    /// new x = 5 // this is an eol comment
    /// ```
    Eol,
    /// For comments like:
    ///
    /// ```
    /// new x = 5
    /// // this is a line comment
    /// ```
    Line,
}

/// Data which holds [`State::Symbols`]'s data read thus far but which may
/// transition into a comment. In practrice it's when `Symbols` encounters `/`.
/// Here, `/` may be a '/' or the beginning of '//', which is a comment.
struct SymbolComment {
    /// Describes what kind of comment this would be.
    comment_candidacy: CommentCandidacy,
    /// Which symbols preceded the `/`.
    chars_thus_far: Chars, // without the last '/'
}

impl SymbolComment {
    /// Pushes a character to `self`, handling the cases when `self` turned out
    /// to be a comment start tag, and the cases when `self` is just an
    /// over-eager `/`.
    fn push_char(self, new_c: char, location: Location) -> errors::Result<(Tokens, State)> {
        if new_c == COMMENT_START {
            let (tokens, _) = self.chars_thus_far.symbol_push_char(new_c, location)?;
            let new_state = match self.comment_candidacy {
                CommentCandidacy::Eol => State::EolComment,
                CommentCandidacy::Line => State::OnelineComment,
            };
            return Ok((tokens, new_state));
        }

        if new_c == MULTILINE_COMMENT_END {
            let (tokens, _) = self.chars_thus_far.symbol_push_char(new_c, location)?;
            return Ok((tokens, State::MultilineComment));
        }

        return self
            .chars_thus_far
            .add_char(COMMENT_START)
            .symbol_push_char(new_c, location);
    }
}

/// A state of the Lexer state machine.
enum State {
    // We've read a non-newline whitespace char. Further whitespace is ignored.
    Whitespace,
    // We've read a newline char, followed by any whitespaces. Further
    // whitespace or newline is ignored.
    Newline,
    // Any unrecognised word.
    Word(Chars),
    // Numbers without decimals.
    Number(Chars),
    // Numbers where we encounterd a decimal.
    DecimalNumber { base: Chars, decimal: Vec<char> },
    // No bounding quotes.
    String(StringState),
    // Skipping whitespace until more of the string appears. Follows a newline
    // inside a string.
    StringWhitespace(StringState),
    // Must have length 1 (no bounding quotes).
    Char(StringState),
    // Groups of WordSeparators which will be turned into symbold tokens or word
    // separator tokens eventually.
    Symbols(Chars),
    // Symbols followed by one '/'. A second one transitions us to
    SymbolCommentCandidate(SymbolComment),
    Documentation(Chars),
    // Follows a newline inside a documentation block. Serves to differentiate
    // when the `====` tag follows a newline vs. anything else, since only
    // `\n====\n` should end (or start, but that's not handled here) a
    // documentation block.
    DocumentationNewline(Chars),
    // When we've read on or more '='s in a row after a newline, we might be
    // ending the documentation block. We remain here until we confirm one way
    // or another.
    DocumentationEnd { docs: Chars, end: Vec<char> },
    // Whole line is a comment.
    OnelineComment,
    // Comment appended to the end of a line.
    EolComment,
    MultilineComment,
    // When inside MultilineComment and we enconter '*'. This may be a random
    // star, or the beginning of '*/'.
    MultilineCommentEnd,
}

impl State {
    /// Returns the tokens which result from pushing character `c` into self,
    /// and the new state that the machine should go into. May return `None`
    /// when there is no change.
    fn push_char(self, new_c: char, location: Location) -> errors::Result<(Tokens, State)> {
        Ok(match self {
            State::Whitespace => (
                vec![],
                process_first_char(new_c, CommentCandidacy::Eol, location),
            ),
            State::Newline => (
                vec![],
                process_first_char(new_c, CommentCandidacy::Line, location),
            ),
            State::OnelineComment => (vec![], State::OnelineComment),
            State::EolComment => (vec![], State::EolComment),
            State::Documentation(doc) => (vec![], State::Documentation(doc.add_char(new_c))),
            State::DocumentationNewline(doc) => (vec![], doc.doc_push_char(new_c)),
            State::Word(word) => word.word_push_char(new_c, location),
            State::Number(number) => number.number_push_char(new_c, location)?,
            State::String(sentense) => sentense.string_push_char(new_c, location),
            State::StringWhitespace(sentense) => sentense.string_push_char(new_c, location),
            State::Char(char) => char.char_push_char(new_c, location)?,
            State::Symbols(symbol) => symbol.symbol_push_char(new_c, location)?,
            State::SymbolCommentCandidate(candidate) => candidate.push_char(new_c, location)?,
            State::DecimalNumber { base, decimal } => {
                decimal_push_char(base, decimal, new_c, location)?
            }
            State::DocumentationEnd { docs, end } => documentation_end_push_char(docs, end, new_c),
            State::MultilineComment => {
                if new_c != MULTILINE_COMMENT_END {
                    (vec![], State::MultilineComment)
                } else {
                    (vec![], State::MultilineCommentEnd)
                }
            }
            State::MultilineCommentEnd => {
                if new_c == COMMENT_START {
                    (vec![], State::Whitespace)
                } else {
                    (vec![], State::MultilineComment)
                }
            }
        })
    }
}

impl Default for State {
    fn default() -> Self {
        State::Whitespace
    }
}

/// Treats `new_c` as the first character in a new, unknown state.
fn process_first_char(
    new_c: char,
    comment_candidacy: CommentCandidacy,
    location: Location,
) -> State {
    let chars = Chars::new(location);

    if new_c.is_numeric() {
        return State::Number(chars.add_char(new_c));
    }

    if new_c == COMMENT_START {
        let candidate = SymbolComment {
            comment_candidacy,
            chars_thus_far: chars,
        };
        return State::SymbolCommentCandidate(candidate);
    }

    if new_c == CHAR_BOUNDRY {
        return State::Char(StringState {
            chars: chars,
            escaped: false,
        });
    }

    if new_c == STRING_BOUNDRY {
        let string = StringState {
            escaped: false,
            chars,
        };
        return State::String(string);
    }

    match WordSeparator::try_from(new_c) {
        Err(_) => State::Word(chars.add_char(new_c)),
        Ok(_) => State::Symbols(chars.add_char(new_c)),
    }
}

/// Treats `new_c` as a potential digit in the decimal expansion of a number. If
/// this is wrong, will return the appropriate state.
fn decimal_push_char(
    base: Chars,
    mut decimals: Vec<char>,
    new_c: char,
    location: Location,
) -> errors::Result<(Tokens, State)> {
    if new_c.is_numeric() {
        decimals.push(new_c);
        let state = State::DecimalNumber {
            base,
            decimal: decimals,
        };
        return Ok((vec![], state));
    }

    if let Err(_) = WordSeparator::try_from(new_c)
        && new_c != STRING_BOUNDRY
        && new_c != CHAR_BOUNDRY
    {
        return Err(errors::LexingError::new("Invalid number format", location));
    }

    if decimals.len() == 0 {
        return Err(errors::LexingError::new(
            "Invalid number format - missing decimal digits",
            location,
        ));
    }

    let number = base
        .to_string()
        .parse::<u32>()
        .expect("Rust has a numeric bug???");

    let decimal = decimals
        .iter()
        .collect::<String>()
        .parse::<u32>()
        .expect("Rust has a numeric bug???");

    let token = Token::new(
        TokenType::DecimalNumber(number, decimal),
        base.start_location,
        location.clone(),
    );

    let state = process_first_char(new_c, CommentCandidacy::Eol, location);

    return Ok((vec![token], state));
}

/// Handles new characters arriving to the [`State::DocumentationEnd`] state.
/// This will never transition out of a documentation block, but may reset the
/// End bit.
fn documentation_end_push_char(base: Chars, mut end: Vec<char>, new_c: char) -> (Tokens, State) {
    if new_c != EQUAL_SIGN {
        let new_state = State::Documentation(base.add_more(end).add_char(new_c));
        return (vec![], new_state);
    }

    end.push(new_c);
    let new_state = State::DocumentationEnd { docs: base, end };
    return (vec![], new_state);
}

/// Reports whether the `second` token should be included in the tokens that are
/// to be parsed by the rest of the compiler. This serves to remove duplicated
/// newlines, or newlines where they don't belong, or generally the newlines
/// that the user put in place and that we don't like.
fn include_middle(first: &Token, second: &Token, third: &Token) -> bool {
    use TokenType::*;
    match (&first.type_, &second.type_, &third.type_) {
        (Newline, Newline, _) => false,
        (_, Newline, EndOfFile) => false,
        (_, Newline, WordSeparator(separator)) => match separator {
            super::token::WordSeparator::RightBrace => true,
            _ => false,
        },
        (WordSeparator(separator), Newline, _) => match separator {
            super::token::WordSeparator::RightBrace => true,
            super::token::WordSeparator::RightParen => true,
            super::token::WordSeparator::RightBracket => true,
            _ => false,
        },
        (_, Newline, Symbol(_)) => false,
        (Symbol(symbol), Newline, _) => match symbol {
            super::token::Symbol::DebugPrint => true,
            _ => false,
        },
        (Keyword(keyword), Newline, _) => match keyword {
            super::token::Keyword::Void
            | super::token::Keyword::Return
            | super::token::Keyword::Continue
            | super::token::Keyword::Break => true,
            _ => false,
        },
        _ => true,
    }
}
