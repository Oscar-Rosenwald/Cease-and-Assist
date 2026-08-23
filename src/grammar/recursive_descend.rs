use super::*;
use std::collections::VecDeque;

use macros::{
    Line, extract_first_token, extract_token, first_is_token, from_first_token, from_token,
    is_token, read_til_semicolon,
};

const MAX_PACKAGE_NAME_SEGMENTS: usize = 7;

/// Turns a vector of [`Token`]s into a syntax tree. Pass only tokens of a
/// single file.
pub fn parse_tokens(mut tokens: VecDeque<Token>) -> Cease {
    println!("___ parsing tokens {:?}", tokens);
    let documentation = from_first_token!(tokens, Documentation).map(|doc| doc.0);

    if first_is_token!(tokens, Keyword, Package) {
        let (declaration, exports) = parse_package_file(tokens, documentation);
        Cease::Package {
            exports,
            declaration,
        }
    } else {
        Cease::Program(parse_code_file(tokens))
    }
}

/// Parses tokens of a `package.stop` file into a syntax tree.
fn parse_package_file(
    mut tokens: VecDeque<Token>,
    documentation: Option<String>,
) -> (package::Package, Vec<package::ExportedSymbol>) {
    let (_, package_position) = extract_first_token!(tokens, Keyword);
    let package = parse_package_declaration(&mut tokens, package_position, documentation);
    let exported_symbols = parse_exported_symbols(&mut tokens);
    return (package, exported_symbols);
}

/// Parses `tokens` as if they are a package declaration. The `package` keyword
/// has already been parsed, and starts at `start_position`. `documentation` of
/// the package is also provided.
fn parse_package_declaration(
    tokens: &mut VecDeque<Token>,
    start_position: Position,
    documentation: Option<String>,
) -> package::Package {
    match read_til_semicolon(tokens) {
        Line::Empty => {
            return package::Package::new_error(
                documentation,
                start_position,
                SyntaxTreeError::MissingSemicolon,
            );
        }
        Line::NoSemicolon { tokens, position } => match Token::find_errors(&tokens) {
            Some(errors) => {
                return package::Package::new_error(
                    documentation,
                    position,
                    SyntaxTreeError::PackageNameBadToken(errors),
                );
            }
            None => {
                return package::Package::new_error(
                    documentation,
                    start_position.merge(position),
                    SyntaxTreeError::MissingSemicolon,
                );
            }
        },
        Line::Semicolon {
            mut tokens,
            position,
        } => {
            let Some((literal, _)) = from_first_token!(tokens, Literal) else {
                return terminate_wrong_package_name(tokens, documentation, position);
            };

            if let Some(errors) = Token::find_errors(&tokens) {
                return package::Package::new_error(
                    documentation,
                    position,
                    SyntaxTreeError::PackageNameBadToken(errors),
                );
            }

            return parse_package_name(
                literal,
                tokens,
                documentation,
                position.merge(start_position),
            );
        }
    };
}

/// Treats `remaining_tokens` as a list of Tokens following `first_name` in the
/// package name declaration. The remaining tokens are none
/// [`TokenKind::Error`]. They should take the form `/literal` zero or more
/// times.
///
/// This function should be called to finalise the package declaration parsing.
fn parse_package_name(
    first_name: String,
    mut remaining_tokens: VecDeque<Token>,
    documentation: Option<String>,
    position: Position,
) -> package::Package {
    let mut package_names = vec![first_name];

    while !remaining_tokens.is_empty() {
        let token = remaining_tokens.pop_front().unwrap();

        if !is_token!(token, Symbol, Slash) {
            let token_str = token.to_string();
            return package::Package::new_error(
                documentation,
                token.position,
                SyntaxTreeError::PackageNameLiteralFollowup(token_str),
            );
        }

        match from_first_token!(remaining_tokens, Literal) {
            Some((literal, _)) => package_names.push(literal),
            None => match remaining_tokens.pop_front() {
                None => {
                    return package::Package::new_error(
                        documentation,
                        position,
                        SyntaxTreeError::MissingSemicolon,
                    );
                }
                Some(token) => {
                    let token_str = token.to_string();
                    return package::Package::new_error(
                        documentation,
                        token.position,
                        SyntaxTreeError::PackageNameSlashFollowup(token_str),
                    );
                }
            },
        }
    }

    if package_names.len() <= MAX_PACKAGE_NAME_SEGMENTS {
        return package::Package::new(documentation, position, package_names);
    }

    return package::Package::new_error(
        documentation,
        position,
        SyntaxTreeError::PackageNameTooLong(package_names.len()),
    );
}

/// Returns an erronous [`package::Package`] according to `tokens` which
/// encapsulate the whole `package` line (except the `package` keyword` and the
/// terminating semicolon).
///
/// The error is either
///
/// - [`SyntaxTreeError::PackageNameBadToken`] if `tokens` contain an error token;
///
/// - [`SyntaxTreeError::WrongPackageName`] if `tokens` isn't empty (containing
///   etc. a Keyword instead of literals and slashes).
///
/// - [`SyntaxTreeError::PackageNameMissing`] if `tokens` is empty.
///
/// This function should be called **before** we attempt to parse the package
/// names.
fn terminate_wrong_package_name(
    tokens: VecDeque<Token>,
    documentation: Option<String>,
    position: Position,
) -> package::Package {
    if let Some(errors) = Token::find_errors(&tokens) {
        return package::Package::new_error(
            documentation,
            position,
            SyntaxTreeError::PackageNameBadToken(errors),
        );
    } else if tokens.len() > 0 {
        let token_strs = tokens
            .into_iter()
            .map(|t| t.to_string())
            .collect::<Vec<_>>()
            .join(" ");

        return package::Package::new_error(
            documentation,
            position,
            SyntaxTreeError::WrongPackageName(token_strs),
        );
    }

    return package::Package::new_error(
        documentation,
        position,
        SyntaxTreeError::PackageNameMissing,
    );
}

fn parse_exported_symbols(tokens: &mut VecDeque<Token>) -> Vec<package::ExportedSymbol> {
    let mut ret_exports = Vec::new();

    loop {
        match read_til_semicolon(tokens) {
            Line::Empty => return ret_exports,
            Line::NoSemicolon {
                tokens: _,
                position,
            } => {
                let error_export =
                    package::ExportedSymbol::new_error(position, SyntaxTreeError::MissingSemicolon);
                ret_exports.push(error_export);
            }
            Line::Semicolon {
                mut tokens,
                position,
            } => {
                let documentation = from_first_token!(tokens, Documentation).map(|d| d.0);
                let mut statement = documentation
                    .clone()
                    .map(|d| format!("{d}\n"))
                    .unwrap_or(String::new());

                let package_local = first_is_token!(tokens, Keyword, Pkg);
                if package_local {
                    statement = format!("{}{}", statement, Keyword::Pkg);
                    tokens.pop_front();
                }

                let Some(keyword) = from_first_token!(tokens, Keyword) else {
                    todo!()
                };

                let Some(symbol_name) = from_first_token!(tokens, Literal) else {
                    todo!()
                    //
                };

                let Ok(export_kind) =
                    package::ExportedSymbolKind::from_keyword(keyword.0, symbol_name.0)
                else {
                    todo!()
                    //
                };

                let export = package::ExportedSymbol::new(
                    documentation,
                    position,
                    package_local,
                    export_kind,
                );

                ret_exports.push(export);

                if tokens.len() > 0 {
                    todo!()
                }
            }
        }
    }

    return ret_exports;
}

/// Parses tokens of a `file.stop` file into a syntax tree.
fn parse_code_file(mut tokens: VecDeque<Token>) -> expression::Program {
    todo!()
}

/// Defines some common macros and functions for manipulating with and checking
/// tokens and token groups.
mod macros {
    use crate::tokeniser::*;
    use crate::util::*;
    use std::collections::VecDeque;

    macro_rules! is_token {
        ( $token:expr, $token_kind:ident ) => {
            match &$token.kind {
                TokenKind::$token_kind(_) => true,
                _ => false,
            }
        };

        ( $token:expr, $token_kind:ident, $which_kind:ident ) => {
            match $token.kind {
                TokenKind::$token_kind(ref value) => match value {
                    $token_kind::$which_kind => true,
                    _ => false,
                },
                _ => false,
            }
        };
    }

    /// Reports whether the first token in a vector of tokens matches a given
    /// [`TokenKind`]. The vector is never mutated.
    ///
    /// # Examples
    ///
    /// ```rust
    /// let tokens = vec![token1, token2];
    /// is_token!(tokens, String); // Matches TokenKind::String
    /// is_token!(tokens, Symbol); // Matches any TokenKind::Symbol
    /// is_token!(tokens, Symbol, Equals); // Matches TokenKind::Symbol(Symbol::Equals)
    /// ```
    ///
    /// Empty vectors return `false`.
    macro_rules! first_is_token {
        ( $tokens:expr, $token_kind:ident ) => {
            match $tokens.get(0) {
                None => false,
                Some(token) => is_token!(token, $token_kind),
            }
        };

        ( $tokens:expr, $token_kind:ident, $which_kind:ident ) => {
            match $tokens.get(0) {
                None => false,
                Some(token) => is_token!(token, $token_kind, $which_kind),
            }
        };
    }

    /// Extracts the inner value and position of the first token in a token
    /// `VecDequeue` if it matches the given [`TokenKind`]. In such a case, the
    /// first token of the vector is removed from the vector. If the first token
    /// doesn't match the token kind, the vector isn't mutated.
    ///
    /// # Examples
    ///
    /// ```rust
    /// let tokens = vec![token1, token2];
    /// let extracted: Some((char, Position)) = from_first_token(tokens, Char);
    /// // extracted is now either None (if the first token isn't a Char)
    /// // or (inner_value, token_position).
    /// ```
    macro_rules! from_first_token {
        ( $tokens:expr, $token_kind:ident ) => {
            if first_is_token!($tokens, $token_kind) {
                let token = $tokens.pop_front().unwrap();
                if let TokenKind::$token_kind(value) = token.kind {
                    Some((value, token.position))
                } else {
                    unreachable!("This makes no sense. Sorry for the bug.");
                }
            } else {
                None
            }
        };
    }

    /// Like [`from_token`], but unwraps the result.
    macro_rules! extract_first_token {
        ( $tokens:expr, $token_kind:ident ) => {
            from_first_token!($tokens, $token_kind).expect("Token of an unexpected kind")
        };
    }

    /// Extracts the inner value of the token.
    ///
    /// # Examples
    ///
    /// ```rust
    /// let extracted: Some((char, Position)) = from_token(token, Char);
    /// ```
    macro_rules! from_token {
        ( $token:expr, $token_kind:ident) => {
            if is_token!($token, $token_kind) {
                if let TokenKind::$token_kind(value) = $token.kind {
                    Some((value, $token.position))
                } else {
                    unreachable!("This makes no sense. Sorry for the bug.")
                }
            } else {
                None
            }
        };
    }

    macro_rules! extract_token {
        ( $token:expr, $token_kind:ident) => {
            from_token!($token, $token_kind).expect("Token of an unexpected kind")
        };
    }

    pub(super) use extract_first_token;
    pub(super) use extract_token;
    pub(super) use first_is_token;
    pub(super) use from_first_token;
    pub(super) use from_token;
    pub(super) use is_token;

    /// Represents a line as read by [`read_til_semicolon`].
    pub(super) enum Line {
        Empty,
        NoSemicolon {
            tokens: VecDeque<Token>,
            position: Position,
        },
        Semicolon {
            tokens: VecDeque<Token>,
            position: Position,
        },
    }

    /// Reads from `tokens` until either a semicolon is found of the tokens run
    /// out. Returns the tokens as a [`Line`]. The semicolon is *not* a part of
    /// the returned list of tokens.
    ///
    /// If no tokens are given, [`Line::Empty`] is returned. If there is no
    /// semicolon in the file, returns [`Line::NoSemicolon`]. Otherwise, returns
    /// [`Line::Semicolon`] which contains the tokens of the line and their
    /// overall position.
    pub(super) fn read_til_semicolon(tokens: &mut VecDeque<Token>) -> Line {
        let mut ret_tokens = VecDeque::new();

        let first_token = match tokens.pop_front() {
            None => return Line::Empty,
            Some(token) => token,
        };

        let start_position = first_token.position.clone();

        if is_token!(first_token, Symbol, Semicolon) {
            return Line::Semicolon {
                tokens: ret_tokens,
                position: start_position,
            };
        }

        ret_tokens.push_back(first_token);
        let mut end_position = start_position.clone();

        loop {
            let token = match tokens.pop_front() {
                Some(token) => token,
                None => {
                    return Line::NoSemicolon {
                        tokens: ret_tokens,
                        position: start_position.merge(end_position),
                    };
                }
            };

            end_position = token.position.clone();

            if !is_token!(token, Symbol, Semicolon) {
                ret_tokens.push_back(token);
                continue;
            }

            return Line::Semicolon {
                tokens: ret_tokens,
                position: start_position.merge(end_position),
            };
        }
    }
}

#[cfg(test)]
mod test_utils {
    use std::io;
    use std::iter;

    /// Returns the file name (corresponding with [`file_path`]) used for
    /// testing.
    pub(super) const FILE_NAME: &'static str = "file.stop";

    /// Returns the file path used for testing. In tests we don't actually care
    /// much about the path.
    pub(super) fn file_path() -> &'static std::path::Path {
        std::path::Path::new(FILE_NAME)
    }

    /// Converts the string `input` into an iterator over the `input`'s lines.
    /// The output is fit to be passed to [`parse_input`].
    pub(super) fn input(input: &str) -> impl iter::Iterator<Item = Result<String, io::Error>> {
        input.split('\n').map(|line| Ok(line.to_string()))
    }

    /// Converts a string into a list of tokens which describe its syntax tree.
    macro_rules! to_tokens {
        ($content:expr) => {
            match crate::tokeniser::tokeniser::parse_input(
                test_utils::input($content),
                test_utils::FILE_NAME,
                test_utils::file_path(),
            ) {
                Err(e) => panic!("{e}"),
                Ok(tokens) => tokens,
            }
        };
    }

    pub(crate) use to_tokens;
}

#[cfg(test)]
mod package_tests {
    use super::{test_utils::to_tokens, *};
    use crate::grammar::program::*;
    use crate::tokeniser::token::*;
    use crate::util::error::*;
    use pretty_assertions::assert_eq;

    /// Extracts a [`package::Package`] from the syntax tree of the string
    /// argument.
    ///
    /// # Examples
    ///
    /// ```rust
    /// let program = assert_program!("package test/pk;");
    /// ```
    macro_rules! assert_package {
        ($content:expr) => {
            match parse_tokens(to_tokens!($content)) {
                Cease::Package {
                    declaration,
                    exports,
                } => (declaration, exports),
                Cease::Program(_) => panic!("Unexpected 'program' syntax tree"),
            }
        };
    }

    /// Confirms a package declaration in a package file has the expected name.
    ///
    /// # Example
    ///
    /// ```rust
    /// let (declaration, _) = assert_package!("package test/pk;");
    /// check_package_declaration!(declaration, "test", "pk");
    /// ```
    macro_rules! check_package_declaration {
        ($declaration:expr, $( $names:expr ),+ ) => {{
            assert_eq!(None, $declaration.documentation());
            let package_name = $declaration.name_parts();
            let expected_names = vec![ $( $names ),* ];
            assert_eq!(expected_names.len(), package_name.len());
            for (index, name) in expected_names.iter().enumerate() {
                assert_eq!(*name, package_name[index]);
            }
        }};
    }

    /// Confirms a package declaration in a package file has the expected name
    /// and documentation.
    ///
    /// # Example
    ///
    /// ```rust
    /// let (declaration, _) = assert_package!("=== docs === package test/pk;");
    /// check_package_declaration!(declaration, "docs", "test", "pk");
    /// ```
    macro_rules! check_package_with_docs {
        ($declaration:expr, $documentation:expr, $( $names:expr ),+ ) => {{
            assert_eq!(Some($documentation.to_string()), $declaration.documentation());
            let package_name = $declaration.name_parts();
            let expected_names = vec![ $( $names ),* ];
            assert_eq!(expected_names.len(), package_name.len());
            for (index, name) in expected_names.iter().enumerate() {
                assert_eq!(*name, package_name[index]);
            }
        }};
    }

    /// Confirms a package delcaration in a package file has failed with an
    /// expected error. The error matches [`SyntaxTreeError`].
    ///
    /// # Example
    /// ```rust
    /// let (declaration, _) = assert_package!("package 'a';");
    /// check_package_error!(declaration, WrongPackageName);
    /// ```
    ///
    /// You can also check the value of the error (works for single-valued
    /// errors only):
    ///
    /// ```rust
    /// let (declaration, _) = assert_package!("package a/b/c/d/e/f/g;");
    /// check_declaration_error!(declaration, PackageNameTooLong, 8);
    /// ```
    macro_rules! check_declaration_error {
        ( $declaration:expr, $error_kind:ident ) => {
            assert_eq!(None, $declaration.documentation());
            match $declaration.name_error().kind() {
                ErrorKind::SyntaxTree(e) => match e {
                    SyntaxTreeError::$error_kind => {}
                    e => panic!("Unexpected syntax tree error {:?}", e),
                },
                e => panic!("Unexpected error kind: {:?}", e),
            }
        };

        ( $declaration:expr, $error_kind:ident, $error_value:expr ) => {
            assert_eq!(None, $declaration.documentation());
            match $declaration.name_error().kind() {
                ErrorKind::SyntaxTree(e) => match e {
                    SyntaxTreeError::$error_kind(value) => assert_eq!($error_value, value),
                    e => panic!("Unexpected syntax tree error {:?}", e),
                },
                e => panic!("Unexpected error kind: {:?}", e),
            }
        };
    }

    /// Confirms the exported symbol in a package file has the expected format.
    /// You must supply the exported `symbol`, its kind's name from
    /// [`package::ExportedSymbolKind`], and the name of the symbol. You may
    /// also specify the symbol's documentation.
    ///
    /// # Examples
    ///
    /// ## No documentation of the exported symbol
    ///
    /// ```rust
    /// let (_, exports) = assert_package!("package test; fn Func;");
    /// check_export(exports[0], Function, "Func");
    /// // Matches ExportedSymbolKind::Function whose token is of TokenKind::Literal and contains "Func"
    /// ```
    ///
    /// ## With documentation
    ///
    /// ```rust
    /// let (_, exports) = assert_package!("package test; === doc === fn Func;");
    /// check_epxort(exports[0], "doc", Function, "Func");
    /// ```
    macro_rules! check_export {
        ($symbol:expr, $symbol_kind:ident, $symbol_name:expr) => {
            match $symbol.kind() {
                Err(e) => panic!("Unexpected user error: {e}"),
                Ok(kind) => match kind {
                    package::ExportedSymbolKind::$symbol_kind(content) => {
                        assert_eq!($symbol_name, content)
                    }
                    k => panic!("Unexpected symbol kind {:?}", k),
                },
            }
        };

        ($symbol:expr, $symbol_documentation:expr, $symbol_kind:ident, $symbol_name:expr) => {{
            assert_eq!(
                Some($symbol_documentation.to_string()),
                $symbol.documentation()
            );

            let kind = match $symbol.kind() {
                Err(e) => panic!("Unexpected user error: {e}"),
                Ok(kind) => kind,
            };

            match kind {
                package::ExportedSymbolKind::$symbol_kind(content) => {
                    assert_eq!($symbol_name, content);
                }
                k => panic!("Unexpected symbol kind {:?}", k),
            }
        }};
    }

    #[test]
    fn package_name_success() {
        let (declaration, exports) = assert_package!("package test/pk;");
        assert_eq!(0, exports.len());
        check_package_declaration!(declaration, "test", "pk");
    }

    #[test]
    fn export_type() {
        let content = r"package test;
        type Struct;
        ";
        let (declaration, exports) = assert_package!(content);
        check_package_declaration!(declaration, "test");
        assert_eq!(1, exports.len());
        check_export!(exports[0], Type, "Struct");
    }

    #[test]
    fn export_interface() {
        let content = r"package test;

        interface Inter;";
        let (declaration, exports) = assert_package!(content);
        check_package_declaration!(declaration, "test");
        assert_eq!(1, exports.len());
        check_export!(exports[0], Interface, "Inter");
    }

    #[test]
    fn export_function() {
        let (declaration, exports) = assert_package!("package test; fn Func;");
        check_package_declaration!(declaration, "test");
        assert_eq!(1, exports.len());
        check_export!(exports[0], Function, "Func");
    }

    #[test]
    fn export_property() {
        let (declaration, exports) = assert_package!("package test; prop Property;");
        check_package_declaration!(declaration, "test");
        assert_eq!(1, exports.len());
        check_export!(exports[0], Property, "Property");
    }

    #[test]
    fn export_with_docs() {
        let content = r"===
        This is package documentation.
        ===
        package test;

        === This is symbol documentation. ===
        interface Inter;";

        let (declaration, exports) = assert_package!(content);
        check_package_with_docs!(declaration, "This is package documentation.", "test");
        assert_eq!(1, exports.len());
        check_export!(
            exports[0],
            "This is symbol documentation.",
            Interface,
            "Inter"
        );
    }

    #[test]
    fn multiple_exports() {
        let content = r"=== Package docs. ===
        package test/pk;
        fn Func1;
        === Symbol docs. ===
        type Typ;
        ";

        let (declaration, exports) = assert_package!(content);
        check_package_with_docs!(declaration, "Package docs.", "test", "pk");
        assert_eq!(2, exports.len());
        check_export!(exports[0], Function, "Func1");
        check_export!(exports[1], "Symbol docs.", Type, "Typ");
    }

    #[test]
    fn no_name_at_all() {
        let (declaration, exports) = assert_package!("package;");
        assert_eq!(0, exports.len());
        check_declaration_error!(declaration, PackageNameMissing);

        let (declaration, exports) = assert_package!("package");
        assert_eq!(0, exports.len());
        check_declaration_error!(declaration, MissingSemicolon);
    }

    #[test]
    fn no_slash_after_name() {
        let (declaration, exports) = assert_package!("package best?package;");
        assert_eq!(0, exports.len());
        check_declaration_error!(
            declaration,
            PackageNameLiteralFollowup,
            format!("{}", TokenKind::Symbol(Symbol::Questionmark))
        );
    }

    #[test]
    fn no_name_after_slash() {
        let (declaration, exports) = assert_package!(r#"package best/"module";"#);
        assert_eq!(0, exports.len());
        check_declaration_error!(
            declaration,
            PackageNameSlashFollowup,
            format!("{}", TokenKind::String("module".to_string()))
        );

        let (declaration, exports) = assert_package!(r#"package best/'c';"#);
        assert_eq!(0, exports.len());
        check_declaration_error!(
            declaration,
            PackageNameSlashFollowup,
            format!("{}", TokenKind::Char('c'))
        );

        let (declaration, exports) = assert_package!(r#"package best/8/module;"#);
        assert_eq!(0, exports.len());
        check_declaration_error!(
            declaration,
            PackageNameSlashFollowup,
            format!("{}", TokenKind::Int(8))
        );
    }

    #[test]
    fn wrong_package_name() {
        let (declaration, exports) = assert_package!(r#"package "best/package";"#);
        assert_eq!(0, exports.len());
        check_declaration_error!(
            declaration,
            WrongPackageName,
            format!("{}", TokenKind::String("best/package".to_string()))
        );
    }

    #[test]
    fn package_name_too_long() {
        let (declaration, exports) = assert_package!(r#"package a/b/c/d/e/f/g/h;"#);
        assert_eq!(0, exports.len());
        check_declaration_error!(declaration, PackageNameTooLong, 8);
    }

    #[test]
    fn no_semicolon() {
        let (declaration, exports) = assert_package!("package best/module");
        assert_eq!(0, exports.len());
        check_declaration_error!(declaration, MissingSemicolon);
    }

    #[test]
    fn package_name_bad_token() {
        let (declaration, exports) = assert_package!(r#"package __;"#);
        assert_eq!(0, exports.len());
        assert_eq!(None, declaration.documentation());
        let error = match declaration.name_error().kind() {
            ErrorKind::SyntaxTree(e) => e,
            other => panic!("Unexpected error type (wanted SyntaxTree): {other}"),
        };
        let SyntaxTreeError::PackageNameBadToken(errors) = error else {
            panic!("Unexpected syntax tree error (wanted BadToken): {error}");
        };
        assert_eq!(1, errors.len());
        let (ref snippet, ref error) = errors[0];
        assert_eq!(r#"__"#, snippet);
        let error = match error.clone().kind() {
            ErrorKind::Syntax(e) => e,
            other => panic!("Unexpected error type (wanted Syntax): {other}"),
        };
        assert_eq!(SyntaxError::InvalidSymbol, error);
    }
}

#[cfg(test)]
mod program_test {
    use super::{test_utils::to_tokens, *};
    use crate::grammar::program::*;

    /// Extracts an [`expression::Program`] from the syntax tree of the string
    /// argument.
    ///
    /// # Examples
    ///
    /// ```rust
    /// let program = assert_program!("type Line string;");
    /// ```
    macro_rules! assert_program {
        ($content:expr) => {
            match parse_tokens(to_tokens!($content)) {
                Cease::Package {
                    declaration: _,
                    exports: _,
                } => panic!("Unexpected 'package' syntax tree"),
                Cease::Program(program) => program,
            }
        };
    }

    #[test]
    fn empty() {
        let program = assert_program!("");
        assert_eq!(expression::Program::empty(), program);
    }
}
