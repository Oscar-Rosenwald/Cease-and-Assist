use super::*;

/// A list of 0 or more elements.
type Any<T> = Option<Vec<T>>;

/// A list of 1 or more elements.
type Some<T> = Vec<T>;

/// A user error wrapper.
pub(super) type Parsed<T> = Result<T, CeaseError>;

/// Describes the set of tokens of a Cease file ordered and structured according
/// to the Cease grammar.
pub enum Cease {
    Program(expression::Program),
    Package {
        declaration: package::Package,
        exports: Vec<package::ExportedSymbol>,
    },
}

/// Objects describing general type syntax such as type hints.
pub(super) mod types {
    use super::*;

    /// Type annotations such as `mut` or `may`.
    #[derive(Debug, PartialEq, Eq)]
    pub enum Annotation {
        Into,
        Function,
        Maybe,
        Iterated,
        Error,
        Ark,
        Pointer,
        Mutable,
        Reference,
        List,
    }

    /// Type hints such as `_` or `#`.
    #[derive(Debug, PartialEq, Eq)]
    pub enum Hint {
        Interface,
        Generic,
        Enum,
        PureType,
    }

    /// A type constraint: `<#A>` or `<B, may str>`
    pub type Constraint = BareType;

    /// A generic declaration: `[A: _io:>IoReader]`
    #[derive(Debug, PartialEq, Eq)]
    pub struct Generic {
        name: Token,
        type_: BareType,
        constraints: Any<Constraint>,
    }

    /// Access to a package symbol: `core:>io:>File` or just `str`.
    #[derive(Debug, PartialEq, Eq)]
    pub struct PackageLiteral {
        packages: Any<Token>,
        package_symbol: Token,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct BareType {
        annotations: Any<Annotation>,
        hint: Option<Hint>,
        name: PackageLiteral,
    }
}

/// Objects describing built-in or basic syntax such as strings.
pub(super) mod lang {
    use super::*;

    #[derive(Debug, PartialEq, Eq)]
    pub struct Base {
        position: Position,
        kind: BaseKind,
    }

    #[derive(Debug, PartialEq, Eq)]
    enum BaseKind {
        Literal(Token),
        Builtin(Builtin),
        Grouping(Box<expression::Expression>),
        EmbeddedLiteral, // The word Embedded, not the {...} block (that's a Builtin).
        ProgramLiteral,  // The word Program, not the {...} block (that's a Builtin).
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct Range {
        start: Option<(RangeBoundary, Position)>,
        kind: RangeKind,
        end: RangeBoundary,
    }

    #[derive(Debug, PartialEq, Eq)]
    enum RangeBoundary {
        Number(u64),
        Value(types::PackageLiteral),
    }

    #[derive(Debug, PartialEq, Eq)]
    enum RangeKind {
        Inclusive,
        Exclusive,
    }

    pub type Array = Any<precedence::Equality>;

    #[derive(Debug, PartialEq, Eq)]
    pub enum Builtin {
        Number(u64),
        String(String),
        Char(char),
        Embedded(Embedded),
        Program(Program),
        Void,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct Embedded {
        operations: Any<statement::Operation>,
        terminator: statement::ProcedureEnd,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct Program {
        operations: Any<statement::Operation>,
    }
}

/// Objects which encode the precedence of operations. Generic stuff like
/// products or data access etc.
pub(super) mod precedence {
    use super::*;

    #[derive(Debug, PartialEq, Eq)]
    pub struct Equality {
        position: Position,
        base: Comparison,
        rest: Option<(EqualityKind, Comparison)>,
    }

    #[derive(Debug, PartialEq, Eq)]
    enum EqualityKind {
        Equals,
        NotEquals,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct Comparison {
        position: Position,
        base: Logic,
        rest: Option<(ComparisonKind, Logic)>,
    }

    #[derive(Debug, PartialEq, Eq)]
    enum ComparisonKind {
        Lesser,
        Greater,
        LesserOrEqual,
        GreaterOrEqual,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct Logic {
        position: Position,
        base: Sum,
        rest: Any<(LogicKind, Sum)>,
    }

    #[derive(Debug, PartialEq, Eq)]
    enum LogicKind {
        And,
        Nand,
        Or,
        Xor,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct Sum {
        position: Position,
        base: Product,
        rest: Any<(SumKind, Product)>,
    }

    #[derive(Debug, PartialEq, Eq)]
    enum SumKind {
        Plus,
        Minus,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct Product {
        position: Position,
        base: Value,
        rest: Any<(ProductKind, Value)>,
    }

    #[derive(Debug, PartialEq, Eq)]
    enum ProductKind {
        Multiply,
        Divide,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub enum Value {
        Unary(Unary),
        Variant(Variant),
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct Unary {
        position: Position,
        kind: Option<UnaryKind>,
        base: Access,
    }

    #[derive(Debug, PartialEq, Eq)]
    enum UnaryKind {
        Negative,
        Negate,
        Reference,
        Dereference,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct Variant {
        position: Position,
        enum_name: Option<types::PackageLiteral>,
        variant_name: Token,
        variant_inner_values: Any<VariantInnerValue>,
    }

    #[derive(Debug, PartialEq, Eq)]
    struct VariantInnerValue {
        field_name: Token,
        name_bound_to: Option<Token>,
    }

    // Because handling the proper access rules is quite hard (the grammar rule
    // is surprisingly hard), it's simpler to treat all AccessKinds equally and
    // cause a parser error if the user didn't type in something reasonable. At
    // that point it'll be much easier to check that we aren't doing something
    // dumbg like
    //
    //   Type=>field:>symbol
    #[derive(Debug, PartialEq, Eq)]
    pub struct Access {
        base: lang::Base,
        rest: Any<(AccessKind, lang::Base)>,
    }

    #[derive(Debug, PartialEq, Eq)]
    enum AccessKind {
        Package,
        Data,
        Field,
    }
}

/// Objects which have to do with generic statements.
pub(super) mod statement {
    use super::*;

    #[derive(Debug, PartialEq, Eq)]
    pub enum Operation {
        Expression(expression::Expression),
        Assignment(Assignment),
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct Assignment {
        position: Position,
        target: AssignmentTarget,
        new_values: Some<expression::Expression>,
    }

    #[derive(Debug, PartialEq, Eq)]
    enum AssignmentTarget {
        Values(Some<AssignmentTargetValue>), // new a, old b c.d =
        Pointer(precedence::Access),         // old a:>b.c <-
    }

    #[derive(Debug, PartialEq, Eq)]
    struct AssignmentTargetValue {
        designation: TargetValueDesignation,
        targets: Some<precedence::Access>,
    }

    #[derive(Debug, PartialEq, Eq)]
    enum TargetValueDesignation {
        New,
        Old,
        Heap,
        Constant,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct ProcedureEnd {
        position: Position,
        values: Any<expression::Expression>,
    }
}

/// Expressions which contain other expressions.
pub(super) mod block {
    use super::*;

    #[derive(Debug, PartialEq, Eq)]
    pub struct Block {
        position: Position,
        kind: BlockKind,
        terminator: BlockTerminator,
    }

    #[derive(Debug, PartialEq, Eq)]
    enum BlockKind {
        If(If),
        While(While),
        For(For),
        Switch(Switch),
        Case(Case),
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct BlockTerminator {
        position: Position,
        kind: TerminatorKind,
        values: Any<expression::Expression>,
    }

    #[derive(Debug, PartialEq, Eq)]
    enum TerminatorKind {
        Yield,
        Cascade,
        Loop,
        Break,
        Return,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct If {
        condition: precedence::Equality,
        operations: Any<statement::Operation>,
        else_ifs: Any<If>,
        else_: Option<(Any<statement::Operation>, BlockTerminator)>,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct While {
        condition: precedence::Equality,
        operations: Any<statement::Operation>,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct For {
        range_over: precedence::Equality,
        range_values: Any<Token>,
        operations: Any<statement::Operation>,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct Switch {
        root: precedence::Equality,
        cases: Some<SwitchCase>,
    }

    #[derive(Debug, PartialEq, Eq)]
    struct SwitchCase {
        variant: precedence::Value,
        operations: Any<statement::Operation>,
    }

    #[derive(Debug, PartialEq, Eq)]
    struct Variant {
        enum_name: Option<types::PackageLiteral>,
        name: Token,
        expansions: Any<VariantExpansion>,
    }

    #[derive(Debug, PartialEq, Eq)]
    enum VariantExpansion {
        SingleValue(call::Call),
        Named(Some<(Token, Option<call::Call>)>),
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct Case {
        target_variant: Variant,
        root: precedence::Value,
        operations: Any<statement::Operation>,
    }
}

/// Expressions consisting of procedure calls.
pub(super) mod call {
    use super::*;

    #[derive(Debug, PartialEq, Eq)]
    pub struct Call {
        position: Position,
        debug_print: bool,
        abort_error: ErrorAbort,
        kind: CallKind,
    }

    #[derive(Debug, PartialEq, Eq)]
    enum CallKind {
        Pipe(PipeCall),
        Func(FunctionCall),
    }

    #[derive(Debug, PartialEq, Eq)]
    enum CallArguments {
        Bare(Some<precedence::Equality>),
        Named(Some<(Token, Call)>),
    }

    #[derive(Debug, PartialEq, Eq)]
    struct ErrorAbort {
        position: Position,
        error_message: String,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct PipeCall {
        payload: precedence::Equality,
    }

    #[derive(Debug, PartialEq, Eq)]
    struct Pipe {
        position: Position,
        kind: procedure::PipeKind,
        name: Token,
        arguments: Option<CallArguments>,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct FunctionCall {
        position: Position,
        name: Token,
        arguments: Option<CallArguments>,
    }
}

/// Procedure definitions inlcuding the body.
pub(super) mod procedure {
    use super::*;

    #[derive(Debug, PartialEq, Eq)]
    pub struct Argument {
        names: Some<Token>,
        type_: types::BareType,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct Result {
        names: Any<Token>,
        type_: types::BareType,
    }

    #[derive(Debug, PartialEq, Eq)]
    struct Signature {
        arguments: Any<Argument>,
        results: Any<Result>,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct Closure {
        arguments: Any<Argument>,
        results: Any<Result>,
        operations: lang::Embedded,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct Implementation {
        position: Position,
        preamble: Option<ImplementationPreamble>,
        pipe: Pipe,
    }

    #[derive(Debug, PartialEq, Eq)]
    struct ImplementationPreamble {
        default: bool,
        interface: types::PackageLiteral,
        constraints: Any<types::Constraint>,
    }

    #[derive(Debug, PartialEq, Eq)]
    struct Pipe {
        generics: Any<types::Generic>,
        payload: Option<Payload>,
        function: Function,
    }

    #[derive(Debug, PartialEq, Eq)]
    struct Payload {
        payload: types::BareType,
        constraints: Any<types::Constraint>,
        pipe_kind: PipeKind,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub enum PipeKind {
        Chill,
        Grabby,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct Function {
        name: Token,
        signature: Option<Signature>,
        operations: Any<statement::Operation>,
        terminator: statement::ProcedureEnd,
    }
}

/// Definitions of types.
pub(super) mod type_def {
    use super::*;

    #[derive(Debug, PartialEq, Eq)]
    pub struct Enum {
        position: Position,
        generics: Any<types::Generic>,
        name: Token,
        constraints: Any<types::Constraint>,
        fields: Some<EnumField>,
    }

    #[derive(Debug, PartialEq, Eq)]
    struct EnumField {
        position: Position,
        name: Token,
        kind: EnumFieldKind,
    }

    #[derive(Debug, PartialEq, Eq)]
    enum EnumFieldKind {
        Bare,
        Anonymous {
            type_: types::BareType,
            constraint: Any<types::Constraint>,
        },
        Named {
            name: Token,
            type_: types::BareType,
            constraints: Any<types::Constraint>,
        },
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct Struct {
        position: Position,
        generics: Any<types::Generic>,
        name: Token,
        constraints: Any<types::Constraint>,
        fields: Some<StructField>,
    }

    #[derive(Debug, PartialEq, Eq)]
    struct StructField {
        position: Position,
        package_local: bool,
        name: Token,
        type_: types::BareType,
        constraints: Any<types::Constraint>,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct TypeDef {
        position: Position,
        kind: TypeKind,
        name: Token,
        new_constraints: Any<types::Constraint>,
        old_type: types::BareType,
        old_constraints: Any<types::Constraint>,
    }

    #[derive(Debug, PartialEq, Eq)]
    enum TypeKind {
        Property,
        Type,
        Alias,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct Interface {
        position: Position,
        generics: Any<types::Generic>,
        name: Token,
        constraints: Any<types::Constraint>,
        pipes: Some<InterfacePipe>,
    }

    #[derive(Debug, PartialEq, Eq)]
    struct InterfacePipe {
        position: Position,
        default: bool,
        annotations: Any<types::Annotation>,
        kind: procedure::PipeKind,
        name: Token,
        arguments: Any<procedure::Argument>,
        results: Any<procedure::Result>,
    }
}

/// Import blocks
pub(super) mod import {
    use super::*;

    #[derive(Debug, PartialEq, Eq)]
    pub struct Use {
        position: Position,
        kind: Parsed<UseKind>,
    }

    #[derive(Debug, PartialEq, Eq)]
    enum UseKind {
        Direct(DirectUse),
        Package(NamedPackage),
        Symbol(NamedSymbol),
    }

    #[derive(Debug, PartialEq, Eq)]
    enum SymbolKind {
        All,
        Literal(Token),
        NamedLiterals(Some<NamedSymbol>),
    }

    #[derive(Debug, PartialEq, Eq)]
    struct DirectUse {
        package: Some<Token>,
        symbols: Option<SymbolKind>,
    }

    #[derive(Debug, PartialEq, Eq)]
    struct NamedPackage {
        package_name: Token,
        package: Some<Token>,
    }

    #[derive(Debug, PartialEq, Eq)]
    struct NamedSymbol {
        position: Position,
        name: Token,
        symbol: Token,
    }
}

/// Generic expressions - objects which evaluate to something.
pub(super) mod expression {
    use super::*;

    #[derive(Debug, PartialEq, Eq)]
    pub struct Expression {
        position: Position,
        kind: ExpressionKind,
    }

    #[derive(Debug, PartialEq, Eq)]
    enum ExpressionKind {
        Call(call::Call),
        Block(block::Block),
        ClosureDef(procedure::Closure),
        ProcedureEnd(statement::ProcedureEnd),
    }

    #[derive(Debug)]
    pub struct Program {
        imports: Any<import::Use>,
        content: Any<ProgramElement>,
    }

    #[derive(Debug, PartialEq, Eq)]
    struct ProgramElement {
        position: Position,
        documentation: Option<String>,
        kind: ProgramKind,
    }

    #[derive(Debug, PartialEq, Eq)]
    enum ProgramKind {
        Type(type_def::TypeDef),
        Struct(type_def::Struct),
        Enum(type_def::Enum),
        Interface(type_def::Interface),
        Assignment(statement::Assignment),
        Implementation(procedure::Implementation),
        UserError(CeaseError),
    }

    impl PartialEq for Program {
        fn eq(&self, other: &Self) -> bool {
            if !self.imports.eq(&other.imports) {
                return false;
            }
            return self.content.eq(&other.content);
        }
    }

    impl Program {
        pub fn empty() -> Self {
            Self {
                content: None,
                imports: None,
            }
        }
    }
}

/// Content of the package file
pub(super) mod package {
    use super::*;

    #[derive(Debug, PartialEq, Eq)]
    pub struct Package {
        position: Position,
        documentation: Option<String>,
        package_name: Parsed<Some<String>>,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub struct ExportedSymbol {
        documentation: Option<String>,
        position: Position,
        package_local: bool,
        kind: Parsed<ExportedSymbolKind>,
    }

    #[derive(Debug, PartialEq, Eq)]
    pub enum ExportedSymbolKind {
        Type(String),
        Interface(String),
        Function(String),
        Property(String),
    }

    impl Package {
        pub fn new(documentation: Option<String>, position: Position, names: Some<String>) -> Self {
            Self {
                documentation,
                package_name: Ok(names),
                position,
            }
        }

        pub fn new_error(
            documentation: Option<String>,
            position: Position,
            error: SyntaxTreeError,
        ) -> Self {
            Self {
                documentation,
                package_name: Err(CeaseError::syntax_tree(
                    error,
                    ErrorLocation::Position(position.clone()),
                )),
                position,
            }
        }

        #[cfg(test)]
        pub fn name_error(self) -> CeaseError {
            match self.package_name {
                Ok(names) => panic!("Unexpected package name: {}", names.join("/")),
                Err(e) => e,
            }
        }

        #[cfg(test)]
        pub fn name_parts(&self) -> Vec<String> {
            match &self.package_name {
                Err(e) => panic!("Unexpected package name error: {e}"),
                Ok(names) => names
                    .iter()
                    .map(|name_part| format!("{name_part}"))
                    .collect(),
            }
        }

        #[cfg(test)]
        pub fn documentation(&self) -> Option<String> {
            self.documentation.clone()
        }
    }

    impl ExportedSymbol {
        pub fn new(
            documentation: Option<String>,
            position: Position,
            package_local: bool,
            kind: ExportedSymbolKind,
        ) -> Self {
            Self {
                documentation,
                position,
                package_local,
                kind: Ok(kind),
            }
        }

        pub fn new_error(position: Position, error: SyntaxTreeError) -> Self {
            let error = Err(CeaseError::syntax_tree(
                error,
                ErrorLocation::Position(position.clone()),
            ));

            Self {
                documentation: None,
                position,
                package_local: false,
                kind: error,
            }
        }

        #[cfg(test)]
        pub fn documentation(&self) -> Option<String> {
            self.documentation.clone()
        }

        #[cfg(test)]
        pub fn kind(&self) -> &Parsed<ExportedSymbolKind> {
            &self.kind
        }
    }

    impl ExportedSymbolKind {
        pub fn from_keyword(keyword: Keyword, symbol_name: String) -> Result<Self, ()> {
            Ok(match keyword {
                Keyword::Type => Self::Type(symbol_name),
                Keyword::Interface => Self::Interface(symbol_name),
                Keyword::Fn => Self::Function(symbol_name),
                Keyword::Property => Self::Property(symbol_name),
                _ => return Err(()),
            })
        }
    }
}
