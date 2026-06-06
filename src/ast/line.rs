use super::*;

/// An abstract line is a group of tokens read together which compose a node of
/// the abstract syntax tree. A simple expression like `1 + 2` is an abstract
/// line, but a whole function definition, signature and body together, are also
/// one line.
///
/// The abstract line is nesting, so a line may contain smaller lines. The
/// elements of a line are [`LineSegment`]s, which are anything from a single
/// token to another abstract line. An abstract line is then a vector of line
/// segments.
pub(super) struct AbstractLine {
    pub segments: Vec<LineSegment>,
}

/// Elements of an [`AbstractLine`].
pub(super) enum LineSegment {
    /// Some abstract lines have a heading which is represented as a series of
    /// tokens. E.g. an `if` statement has a heading `if <condition>`.
    ///
    /// `else if <condition>` is also a heading.
    Heading(Vec<Token>),
    /// A singular token of an abstract line. E.g. `new x = 4` is a simple line
    /// consisting only of tokens `new`, `x`, `=`, and `4`.
    Token(Token),
    /// A line inside of another line. E.g. `if (condition)` is the heading,
    /// which is followed by a Nested line, which is the body of the expression.
    ///
    /// A nested line may be surrounded in the code by `{ }`. These are not
    /// included in the Nested variant.
    Nested(Vec<AbstractLine>),
}
