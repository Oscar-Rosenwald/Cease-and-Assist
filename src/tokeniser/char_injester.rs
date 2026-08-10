use super::*;
use std::path::PathBuf;
use std::str::FromStr;

/// Receives characters from a file and turns them into tokens. Characters are
/// to be pushed one at a time via [`Self::push_char`]. When the file is
/// finished, calld [`Self::end_of_file`].
///
/// When a newline is encountered, send that via `push_char` as well.
pub(super) struct Lexer {
    /// This is where the currently read lexime is stored.
    staging_area: Stage,
    /// Tokens which have already been read from the file.
    seen_tokens: VecDeque<Token>,
}

/// Stage represents the current lexime which has not yet been turned into a
/// [`Token`]. Characters are pushed to it via [`Self::push_char`] or
/// [`Self::push_whitespace`] and the file is terminated via
/// [`Self::end_of_file`]. Those methods may return the tokens which are
/// represented by the lexime.
struct Stage {
    /// Stores the lexime and the type of lexime it is.
    kind: StageKind,
    /// Where does the current lexime start?
    start_location: FileLocation,
    /// Last location seen which belongs to the lexime. This will eventually
    /// represent the lexime's end location.
    last_seen_location: FileLocation,
    /// Path to the file we're reading from.
    file_path: PathBuf,
}

/// Represents which kind of lexime we're reading, and stores information about
/// it. The default value is [`StageKind::Whitespace`].
enum StageKind {
    /// This is a one-character lexime which is never turned into any tokens.
    Whitespace,
    /// A word of some kind. May be a variable name, a keyword, a function name,
    /// etc.
    Normal(String),
    /// Comment blocks. No token is formed from them.
    Comment(CommentKind),
    /// A lexime which can be turned into a symbol, but which, if more
    /// appropriate characters follow, can become a different symbol.
    ///
    /// E.g.: `..` is a symbol, but `...` is to, so `..` is an extendable
    /// symbol.
    ExtendableSymbol(Symbol),
    /// A lexime which could be turned into a symbol if appropriate characters
    /// follow. If they don't, it's not a symbol.
    ///
    /// E.g.: `__` is not a valid symbol, but `___` is valid, so `__` is a
    /// symbol candidate.
    ///
    /// A symbol candiddate may follow a [`StageKind::Normal`] lexime with no
    /// space. E.g. in variable names with an underscore: `variable_name`. In
    /// such a case, the symbol candidate is `_` and `variable` is kept. If we
    /// then follow with `__`, we'll turn those two into: `variable` and `___`.
    /// If a letter follows (`n` in this case), we'll treat the symbol candidate
    /// as a [`StageKind::Normal`] lexime.
    SymbolCandidate {
        /// When valid, this is the part of the current lexime which is a normal
        /// name, e.g. of a variable. When invalid, there is no such name.
        non_symbol_snippet: Option<String>,
        /// The candidate for a symbol - not a valid symbol by itself.
        candidate: Symbol,
    },
    /// A string lexime, composed potentially of many words and lines.
    String {
        /// Is the next character escaped? I.e., is the last character '\'?
        escaped: bool,
        /// The string lexime thus far.
        snippet: String,
    },
    /// A char lexime. It is represented as a string the user may have made a
    /// mistake. We want to keep `'abc'` as one token with a syntax error rather
    /// than panicking when `abc` cannot fit in a single `char`.
    Char {
        /// Is the next character escaped? I.e., is the last character '\'?
        escaped: bool,
        /// The char lexime thus far.
        snippet: String,
    },
    /// A documentation block. Starts and ends with `===`. May contain multiple
    /// words and lines.
    Documentation {
        seen_terminator_count: usize,
        snippet: String,
    },
}

impl Default for StageKind {
    fn default() -> Self {
        Self::Whitespace
    }
}

/// Comments are euther singleline (starting with `//` and ending with a
/// newline) or multiline (`/*` ... `*/`).
pub(super) enum CommentKind {
    SingleLine,
    MultiLine { seen_star: bool },
}

impl Lexer {
    pub(super) fn new(file_path: PathBuf) -> Self {
        Self {
            staging_area: Stage {
                file_path: file_path.clone(),
                kind: StageKind::default(),
                start_location: FileLocation::default(),
                last_seen_location: FileLocation::default(),
            },
            seen_tokens: VecDeque::new(),
        }
    }

    pub(super) fn push_char(&mut self, new_char: char, location: FileLocation) {
        let tokens = if new_char.is_whitespace() {
            self.staging_area.push_whitespace(new_char, location)
        } else {
            self.staging_area.push_char(new_char, location)
        };

        for token in tokens {
            self.seen_tokens.push_back(token);
        }
    }

    pub(super) fn end_of_input(mut self) -> VecDeque<Token> {
        for token in self.staging_area.end_of_input() {
            self.seen_tokens.push_back(token);
        }
        return self.seen_tokens;
    }
}

// Business logic
impl Stage {
    fn push_char(&mut self, new_char: char, location: FileLocation) -> Vec<Token> {
        let (new_stage_kind, processed_tokens) = match std::mem::take(&mut self.kind) {
            StageKind::Whitespace => {
                self.last_seen_location = location.clone();
                self.push_char_to_whitespace(new_char, location)
            }
            StageKind::Comment(comment_kind) => {
                (push_char_to_comment(new_char, comment_kind), vec![])
            }
            StageKind::Normal(snippet) => {
                let (new_stage_kind, processed_tokens) =
                    self.push_char_to_normal(new_char, snippet, location);
                (new_stage_kind, processed_tokens)
            }
            StageKind::ExtendableSymbol(candidate) => {
                self.push_char_to_extendable_symbol(new_char, candidate, location)
            }
            StageKind::SymbolCandidate {
                non_symbol_snippet,
                candidate,
            } => self.push_char_to_symbol_candidate(new_char, non_symbol_snippet, candidate),
            StageKind::String { escaped, snippet } => {
                self.last_seen_location = location;
                let (new_str, processed_tokens) =
                    self.push_char_to_string(new_char, escaped, snippet);

                let new_stage_kind = match new_str {
                    None => StageKind::Whitespace,
                    Some((snippet, escaped)) => StageKind::String { escaped, snippet },
                };

                (new_stage_kind, processed_tokens)
            }
            StageKind::Char { escaped, snippet } => {
                self.last_seen_location = location;
                let (new_str, processed_tokens) =
                    self.push_char_to_char(new_char, escaped, snippet);

                let new_stage_kind = match new_str {
                    None => StageKind::Whitespace,
                    Some((snippet, escaped)) => StageKind::Char { escaped, snippet },
                };
                (new_stage_kind, processed_tokens)
            }
            StageKind::Documentation {
                seen_terminator_count,
                snippet,
            } => {
                self.last_seen_location = location;
                (
                    push_char_to_documentation(new_char, snippet, seen_terminator_count),
                    vec![],
                )
            }
        };

        self.kind = new_stage_kind;
        return processed_tokens;
    }

    fn push_whitespace(&mut self, new_char: char, location: FileLocation) -> Vec<Token> {
        let (new_stage_kind, processed_tokens) = match std::mem::take(&mut self.kind) {
            StageKind::Whitespace => (StageKind::Whitespace, vec![]),
            StageKind::Normal(snippet) => (StageKind::Whitespace, vec![self.end_normal(snippet)]),
            StageKind::Comment(comment_kind) => {
                let new_stage_kind = match comment_kind {
                    CommentKind::SingleLine => match new_char {
                        '\n' => StageKind::Whitespace,
                        _ => StageKind::Comment(CommentKind::SingleLine),
                    },
                    CommentKind::MultiLine { seen_star: _ } => {
                        StageKind::Comment(CommentKind::MultiLine { seen_star: false })
                    }
                };
                (new_stage_kind, vec![])
            }
            StageKind::ExtendableSymbol(symbol) => {
                let token_kind = TokenKind::Symbol(symbol);
                let token = Token::new(token_kind, self.position());
                (StageKind::Whitespace, vec![token])
            }
            StageKind::SymbolCandidate {
                non_symbol_snippet,
                candidate,
            } => {
                let token = match non_symbol_snippet {
                    None => {
                        let error = CeaseError::syntax(
                            "Invalid name or unfinished symbol",
                            ErrorLocation::Position(self.position()),
                        );
                        Token::failing(
                            format!("{candidate}"),
                            IntendedTokenKind::Other,
                            self.position(),
                            error,
                        )
                    }
                    Some(ref snippet) => {
                        let token_kind = TokenKind::Literal(format!("{snippet}{candidate}"));
                        Token::new(token_kind, self.position())
                    }
                };

                (StageKind::Whitespace, vec![token])
            }
            StageKind::String {
                escaped: _,
                mut snippet,
            } => {
                self.last_seen_location = location;
                snippet.push(new_char);
                let new_stage_kind = StageKind::String {
                    escaped: false,
                    snippet,
                };
                (new_stage_kind, vec![])
            }
            StageKind::Char {
                escaped: _,
                mut snippet,
            } => {
                self.last_seen_location = location;
                snippet.push(new_char);
                let new_stage_kind = StageKind::Char {
                    escaped: false,
                    snippet,
                };
                (new_stage_kind, vec![])
            }
            StageKind::Documentation {
                seen_terminator_count,
                snippet,
            } => {
                if seen_terminator_count >= 3 {
                    let token_kind = TokenKind::Documentation(snippet.trim().to_string());
                    let token = Token::new(token_kind, self.position());
                    self.last_seen_location = location;

                    (StageKind::Whitespace, vec![token])
                } else {
                    let new_stage_kind =
                        push_char_to_documentation(new_char, snippet, seen_terminator_count);
                    self.last_seen_location = location;
                    (new_stage_kind, vec![])
                }
            }
        };

        self.kind = new_stage_kind;
        return processed_tokens;
    }

    fn end_of_input(mut self) -> Vec<Token> {
        match std::mem::take(&mut self.kind) {
            StageKind::Whitespace => vec![],
            StageKind::Normal(snippet) => vec![self.end_normal(snippet)],
            StageKind::Comment(_) => vec![],
            StageKind::ExtendableSymbol(symbol) => {
                let token_kind = TokenKind::Symbol(symbol);
                let token = Token::new(token_kind, self.position());
                vec![token]
            }
            StageKind::SymbolCandidate {
                non_symbol_snippet,
                candidate,
            } => {
                let error_message = match non_symbol_snippet {
                    None => candidate.to_string(),
                    Some(snippet) => format!("{snippet}{}", candidate.to_string()),
                };

                let error_location = ErrorLocation::Position(self.position());
                let error = CeaseError::syntax("Invalid symbol.", error_location);
                let token = Token::failing(
                    error_message,
                    IntendedTokenKind::Other,
                    self.position(),
                    error,
                );
                vec![token]
            }
            StageKind::String {
                escaped: _,
                snippet,
            } => {
                let error_location = ErrorLocation::Position(self.position());
                let error = CeaseError::syntax(
                    "Unterminated string. Try a quote, dumbarse.",
                    error_location,
                );
                let token =
                    Token::failing(snippet, IntendedTokenKind::String, self.position(), error);
                vec![token]
            }
            StageKind::Char {
                escaped: _,
                snippet,
            } => {
                let error_location = ErrorLocation::Position(self.position());
                let error =
                    CeaseError::syntax("Unterminated char. Try a quote, dumbarse.", error_location);
                let token =
                    Token::failing(snippet, IntendedTokenKind::Char, self.position(), error);
                vec![token]
            }
            StageKind::Documentation {
                seen_terminator_count: _,
                snippet,
            } => {
                let error_location = ErrorLocation::Position(self.position());
                let error = CeaseError::syntax(
                    "Unterminated documentation block. Try ending it? With a === maybe? Jesus Christ.",
                    error_location,
                );
                let token = Token::failing(
                    snippet,
                    IntendedTokenKind::Documentation,
                    self.position(),
                    error,
                );
                vec![token]
            }
        }
    }
}

// Helper methods
impl Stage {
    fn push_char_to_whitespace(
        &mut self,
        new_char: char,
        location: FileLocation,
    ) -> (StageKind, Vec<Token>) {
        self.start_location = location;

        match new_char {
            '"' => (
                StageKind::String {
                    escaped: false,
                    snippet: String::new(),
                },
                vec![],
            ),
            '\'' => (
                StageKind::Char {
                    escaped: false,
                    snippet: String::new(),
                },
                vec![],
            ),
            c => self.push_generic_char_to_whitespace(c),
        }
    }

    fn push_generic_char_to_whitespace(&self, new_char: char) -> (StageKind, Vec<Token>) {
        let symbol_result = Symbol::parse_char(None, new_char);
        match symbol_result {
            SymbolParseResult::NoSymbol => {
                return (StageKind::Normal(String::from(new_char)), vec![]);
            }
            SymbolParseResult::ExtendableCandidate(candidate) => {
                return (StageKind::ExtendableSymbol(candidate), vec![]);
            }
            SymbolParseResult::Candidate {
                symbol,
                terminal: _,
            } => {
                let new_stage_kind = StageKind::SymbolCandidate {
                    non_symbol_snippet: None,
                    candidate: symbol,
                };
                return (new_stage_kind, vec![]);
            }
            SymbolParseResult::Symbol(symbol) => {
                let token = Token::new(TokenKind::Symbol(symbol), self.position());
                return (StageKind::Whitespace, vec![token]);
            }
        }
    }

    fn push_char_to_normal(
        &mut self,
        new_char: char,
        mut snippet: String,
        end_location: FileLocation,
    ) -> (StageKind, Vec<Token>) {
        match Symbol::parse_char(None, new_char) {
            SymbolParseResult::NoSymbol => {
                self.last_seen_location = end_location;
                snippet.push(new_char);
                return (StageKind::Normal(snippet), vec![]);
            }
            SymbolParseResult::Symbol(symbol) => {
                let normal_token = self.end_normal(snippet);

                self.start_location = end_location.clone();
                self.last_seen_location = end_location;
                let token_kind = TokenKind::Symbol(symbol);
                let symbol_token = Token::new(token_kind, self.position());

                return (StageKind::Whitespace, vec![normal_token, symbol_token]);
            }
            SymbolParseResult::ExtendableCandidate(candidate) => {
                return self.normal_and_symbol_snippet_to_token(snippet, candidate, end_location);
            }
            SymbolParseResult::Candidate {
                symbol: candidate,
                terminal,
            } => {
                if terminal {
                    return self.normal_and_symbol_snippet_to_token(
                        snippet,
                        candidate,
                        end_location,
                    );
                }

                self.last_seen_location = end_location;
                let new_stage_kind = StageKind::SymbolCandidate {
                    candidate,
                    non_symbol_snippet: Some(snippet),
                };
                return (new_stage_kind, vec![]);
            }
        }
    }

    fn push_char_to_extendable_symbol(
        &mut self,
        new_char: char,
        symbol_candidate: Symbol,
        end_location: FileLocation,
    ) -> (StageKind, Vec<Token>) {
        match Symbol::parse_char(Some(symbol_candidate.to_string().as_str()), new_char) {
            SymbolParseResult::NoSymbol => {
                let token_kind = TokenKind::Symbol(symbol_candidate);
                let token = Token::new(token_kind, self.position());
                let mut tokens = vec![token];
                tokens.append(&mut self.push_char(new_char, end_location));

                return (std::mem::take(&mut self.kind), tokens);
            }
            SymbolParseResult::Symbol(symbol) => match symbol {
                Symbol::DoubleSlash => {
                    return (StageKind::Comment(CommentKind::SingleLine), vec![]);
                }
                Symbol::SlashStar => {
                    return (
                        StageKind::Comment(CommentKind::MultiLine { seen_star: false }),
                        vec![],
                    );
                }
                Symbol::ThreeEquals => {
                    return (
                        StageKind::Documentation {
                            seen_terminator_count: 0,
                            snippet: String::new(),
                        },
                        vec![],
                    );
                }
                symbol => {
                    self.last_seen_location = end_location.clone();
                    let token = Token::new(TokenKind::Symbol(symbol), self.position());
                    return (StageKind::Whitespace, vec![token]);
                }
            },
            SymbolParseResult::Candidate {
                symbol,
                terminal: _,
            } => {
                let new_stage_kind = StageKind::SymbolCandidate {
                    non_symbol_snippet: None,
                    candidate: symbol,
                };
                return (new_stage_kind, vec![]);
            }
            SymbolParseResult::ExtendableCandidate(candidate) => {
                return (StageKind::ExtendableSymbol(candidate), vec![]);
            }
        }
    }

    fn push_char_to_symbol_candidate(
        &self,
        new_char: char,
        snippet: Option<String>,
        symbol_candidate: Symbol,
    ) -> (StageKind, Vec<Token>) {
        let candidate_str = symbol_candidate.to_string();
        let mut snippet = match snippet {
            None => candidate_str,
            Some(mut s) => {
                s.push_str(&candidate_str);
                s
            }
        };

        match Symbol::parse_char(Some(&snippet), new_char) {
            SymbolParseResult::NoSymbol => {
                snippet.push(new_char);
                return (StageKind::Normal(snippet), vec![]);
            }
            SymbolParseResult::ExtendableCandidate(symbol) => {
                return (StageKind::ExtendableSymbol(symbol), vec![]);
            }
            SymbolParseResult::Candidate {
                symbol,
                terminal: _,
            } => {
                let new_stage_kind = StageKind::SymbolCandidate {
                    non_symbol_snippet: None,
                    candidate: symbol,
                };
                return (new_stage_kind, vec![]);
            }
            SymbolParseResult::Symbol(symbol) => {
                let token = Token::new(TokenKind::Symbol(symbol), self.position());
                return (StageKind::Whitespace, vec![token]);
            }
        }
    }

    fn push_char_to_char(
        &self,
        new_char: char,
        escaped: bool,
        mut snippet: String,
    ) -> (Option<(String, bool)>, Vec<Token>) {
        match new_char {
            '\'' if escaped => snippet.push(new_char),
            '\'' => match char::from_str(&snippet) {
                Ok(c) => {
                    let token = Token::new(TokenKind::Char(c), self.position());
                    return (None, vec![token]);
                }
                Err(_) => {
                    let error_location = ErrorLocation::Position(self.position());
                    let error = CeaseError::syntax(
                        "Too many characters in this character. Try one.",
                        error_location,
                    );
                    let token =
                        Token::failing(snippet, IntendedTokenKind::Char, self.position(), error);
                    return (None, vec![token]);
                }
            },
            '\\' if escaped => snippet.push(new_char),
            '\\' => return (Some((snippet, true)), vec![]),
            c => snippet.push(c),
        }

        return (Some((snippet, false)), vec![]);
    }

    fn push_char_to_string(
        &self,
        new_char: char,
        escaped: bool,
        mut snippet: String,
    ) -> (Option<(String, bool)>, Vec<Token>) {
        match new_char {
            '"' if escaped => snippet.push(new_char),
            '"' => {
                let token = Token::new(TokenKind::String(snippet), self.position());
                return (None, vec![token]);
            }
            '\\' if escaped => snippet.push(new_char),
            '\\' => return (Some((snippet, true)), vec![]),
            c => snippet.push(c),
        }

        return (Some((snippet, false)), vec![]);
    }

    fn normal_and_symbol_snippet_to_token(
        &mut self,
        snippet: String,
        symbol_candidate: Symbol,
        end_location: FileLocation,
    ) -> (StageKind, Vec<Token>) {
        let token_kind = match Keyword::from_str(&snippet) {
            Ok(keyword) => TokenKind::Keyword(keyword),
            Err(_) => TokenKind::Literal(snippet),
        };

        let token = Token::new(token_kind, self.position());

        self.start_location = end_location.clone();
        self.last_seen_location = end_location;

        let new_stage_kind = StageKind::ExtendableSymbol(symbol_candidate);

        return (new_stage_kind, vec![token]);
    }

    fn end_normal(&self, snippet: String) -> Token {
        let token_kind = if let Ok(keyword) = Keyword::from_str(&snippet) {
            TokenKind::Keyword(keyword)
        } else if let Ok(number) = u64::from_str(&snippet) {
            TokenKind::Int(number)
        } else {
            TokenKind::Literal(snippet)
        };

        Token::new(token_kind, self.position())
    }

    fn position(&self) -> Position {
        Position::new(
            self.file_path.clone(),
            self.start_location.clone(),
            self.last_seen_location.clone(),
        )
    }
}

fn push_char_to_comment(new_char: char, comment_kind: CommentKind) -> StageKind {
    match comment_kind {
        CommentKind::SingleLine => StageKind::Comment(comment_kind),
        CommentKind::MultiLine { seen_star } => {
            if seen_star && new_char == '/' {
                StageKind::Whitespace
            } else {
                StageKind::Comment(CommentKind::MultiLine {
                    seen_star: new_char == '*',
                })
            }
        }
    }
}

fn push_char_to_documentation(
    new_char: char,
    snippet: String,
    seen_terminator_count: usize,
) -> StageKind {
    if new_char == '=' {
        return StageKind::Documentation {
            seen_terminator_count: seen_terminator_count + 1,
            snippet,
        };
    }

    let terminators: String = std::iter::repeat_n('=', seen_terminator_count).collect();

    return StageKind::Documentation {
        seen_terminator_count: 0,
        snippet: format!("{snippet}{terminators}{new_char}"),
    };
}
