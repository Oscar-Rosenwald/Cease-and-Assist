use super::*;

/// A list of 0 or more elements.
type Any<T> = Option<Vec<T>>;

/// A list of 1 or more elements.
type Some<T> = Vec<T>;

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
mod types {
    use super::*;

    /// Type annotations such as `mut` or `may`.
    pub(super) enum Annotation {
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
    pub(super) enum Hint {
        Interface,
        Generic,
        Enum,
        PureType,
    }

    /// A type constraint: `<#A>` or `<B, may str>`
    pub(super) type Constraint = BareType;

    /// A generic declaration: `[A: _io:>IoReader]`
    pub(super) struct Generic {
        name: Token,
        type_: BareType,
        constraints: Any<Constraint>,
    }

    /// Access to a package symbol: `core:>io:>File` or just `str`.
    pub(super) struct PackageLiteral {
        packages: Any<Token>,
        package_symbol: Token,
    }

    pub(super) struct BareType {
        annotations: Any<Annotation>,
        hint: Option<Hint>,
        name: PackageLiteral,
    }
}

/// Objects describing built-in or basic syntax such as strings.
mod lang {
    use super::*;

    pub(super) struct Base {
        position: Position,
        kind: BaseKind,
    }

    enum BaseKind {
        Literal(Token),
        Builtin(Builtin),
        Grouping(Box<expression::Expression>),
        EmbeddedLiteral, // The word Embedded, not the {...} block (that's a Builtin).
        ProgramLiteral,  // The word Program, not the {...} block (that's a Builtin).
    }

    pub(super) struct Range {
        start: Option<(RangeBoundary, Position)>,
        kind: RangeKind,
        end: RangeBoundary,
    }

    enum RangeBoundary {
        Number(u64),
        Value(types::PackageLiteral),
    }

    enum RangeKind {
        Inclusive,
        Exclusive,
    }

    pub(super) type Array = Any<precedence::Equality>;

    pub(super) enum Builtin {
        Number(u64),
        String(String),
        Char(char),
        Embedded(Embedded),
        Program(Program),
        Void,
    }

    pub(super) struct Embedded {
        operations: Any<statement::Operation>,
        terminator: statement::ProcedureEnd,
    }

    pub(super) struct Program {
        operations: Any<statement::Operation>,
    }
}

/// Objects which encode the precedence of operations. Generic stuff like
/// products or data access etc.
mod precedence {
    use super::*;

    pub(super) struct Equality {
        position: Position,
        base: Comparison,
        rest: Option<(EqualityKind, Comparison)>,
    }

    enum EqualityKind {
        Equals,
        NotEquals,
    }

    pub(super) struct Comparison {
        position: Position,
        base: Logic,
        rest: Option<(ComparisonKind, Logic)>,
    }

    enum ComparisonKind {
        Lesser,
        Greater,
        LesserOrEqual,
        GreaterOrEqual,
    }

    pub(super) struct Logic {
        position: Position,
        base: Sum,
        rest: Any<(LogicKind, Sum)>,
    }

    enum LogicKind {
        And,
        Nand,
        Or,
        Xor,
    }

    pub(super) struct Sum {
        position: Position,
        base: Product,
        rest: Any<(SumKind, Product)>,
    }

    enum SumKind {
        Plus,
        Minus,
    }

    pub(super) struct Product {
        position: Position,
        base: Value,
        rest: Any<(ProductKind, Value)>,
    }

    enum ProductKind {
        Multiply,
        Divide,
    }

    pub(super) enum Value {
        Unary(Unary),
        Variant(Variant),
    }

    pub(super) struct Unary {
        position: Position,
        kind: Option<UnaryKind>,
        base: Access,
    }

    enum UnaryKind {
        Negative,
        Negate,
        Reference,
        Dereference,
    }

    pub(super) struct Variant {
        position: Position,
        enum_name: Option<types::PackageLiteral>,
        variant_name: Token,
        variant_inner_values: Any<VariantInnerValue>,
    }

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
    pub(super) struct Access {
        base: lang::Base,
        rest: Any<(AccessKind, lang::Base)>,
    }

    enum AccessKind {
        Package,
        Data,
        Field,
    }
}

/// Objects which have to do with generic statements.
mod statement {
    use super::*;

    pub(super) enum Operation {
        Expression(expression::Expression),
        Assignment(Assignment),
    }

    pub(super) struct Assignment {
        position: Position,
        target: AssignmentTarget,
        new_values: Some<expression::Expression>,
    }

    enum AssignmentTarget {
        Values(Some<AssignmentTargetValue>), // new a, old b c.d =
        Pointer(precedence::Access),         // old a:>b.c <-
    }

    struct AssignmentTargetValue {
        designation: TargetValueDesignation,
        targets: Some<precedence::Access>,
    }

    enum TargetValueDesignation {
        New,
        Old,
        Heap,
        Constant,
    }

    pub(super) struct ProcedureEnd {
        position: Position,
        values: Any<expression::Expression>,
    }
}

/// Expressions which contain other expressions.
mod block {
    use super::*;

    pub(super) struct Block {
        position: Position,
        kind: BlockKind,
        terminator: BlockTerminator,
    }

    enum BlockKind {
        If(If),
        While(While),
        For(For),
        Switch(Switch),
        Case(Case),
    }

    pub(super) struct BlockTerminator {
        position: Position,
        kind: TerminatorKind,
        values: Any<expression::Expression>,
    }

    enum TerminatorKind {
        Yield,
        Cascade,
        Loop,
        Break,
        Return,
    }

    pub(super) struct If {
        condition: precedence::Equality,
        operations: Any<statement::Operation>,
        else_ifs: Any<If>,
        else_: Option<(Any<statement::Operation>, BlockTerminator)>,
    }

    pub(super) struct While {
        condition: precedence::Equality,
        operations: Any<statement::Operation>,
    }

    pub(super) struct For {
        range_over: precedence::Equality,
        range_values: Any<Token>,
        operations: Any<statement::Operation>,
    }

    pub(super) struct Switch {
        root: precedence::Equality,
        cases: Some<SwitchCase>,
    }

    struct SwitchCase {
        variant: precedence::Value,
        operations: Any<statement::Operation>,
    }

    struct Variant {
        enum_name: Option<types::PackageLiteral>,
        name: Token,
        expansions: Any<VariantExpansion>,
    }

    enum VariantExpansion {
        SingleValue(call::Call),
        Named(Some<(Token, Option<call::Call>)>),
    }

    pub(super) struct Case {
        target_variant: Variant,
        root: precedence::Value,
        operations: Any<statement::Operation>,
    }
}

/// Expressions consisting of procedure calls.
mod call {
    use super::*;

    pub(super) struct Call {
        position: Position,
        debug_print: bool,
        abort_error: ErrorAbort,
        kind: CallKind,
    }

    enum CallKind {
        Pipe(PipeCall),
        Func(FunctionCall),
    }

    enum CallArguments {
        Bare(Some<precedence::Equality>),
        Named(Some<(Token, Call)>),
    }

    struct ErrorAbort {
        position: Position,
        error_message: String,
    }

    pub(super) struct PipeCall {
        payload: precedence::Equality,
    }

    struct Pipe {
        position: Position,
        kind: procedure::PipeKind,
        name: Token,
        arguments: Option<CallArguments>,
    }

    pub(super) struct FunctionCall {
        position: Position,
        name: Token,
        arguments: Option<CallArguments>,
    }
}

/// Procedure definitions inlcuding the body.
mod procedure {
    use super::*;

    pub(super) struct Argument {
        names: Some<Token>,
        type_: types::BareType,
    }

    pub(super) struct Result {
        names: Any<Token>,
        type_: types::BareType,
    }

    struct Signature {
        arguments: Any<Argument>,
        results: Any<Result>,
    }

    pub(super) struct Closure {
        arguments: Any<Argument>,
        results: Any<Result>,
        operations: lang::Embedded,
    }

    pub(super) struct Implementation {
        position: Position,
        preamble: Option<ImplementationPreamble>,
        pipe: Pipe,
    }

    struct ImplementationPreamble {
        default: bool,
        interface: types::PackageLiteral,
        constraints: Any<types::Constraint>,
    }

    struct Pipe {
        generics: Any<types::Generic>,
        payload: Option<Payload>,
        function: Function,
    }

    struct Payload {
        payload: types::BareType,
        constraints: Any<types::Constraint>,
        pipe_kind: PipeKind,
    }

    pub(super) enum PipeKind {
        Chill,
        Grabby,
    }

    pub(super) struct Function {
        name: Token,
        signature: Option<Signature>,
        operations: Any<statement::Operation>,
        terminator: statement::ProcedureEnd,
    }
}

/// Definitions of types.
mod type_def {
    use super::*;

    pub(super) struct Enum {
        position: Position,
        generics: Any<types::Generic>,
        name: Token,
        constraints: Any<types::Constraint>,
        fields: Some<EnumField>,
    }

    struct EnumField {
        position: Position,
        name: Token,
        kind: EnumFieldKind,
    }

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

    pub(super) struct Struct {
        position: Position,
        generics: Any<types::Generic>,
        name: Token,
        constraints: Any<types::Constraint>,
        fields: Some<StructField>,
    }

    struct StructField {
        position: Position,
        package_local: bool,
        name: Token,
        type_: types::BareType,
        constraints: Any<types::Constraint>,
    }

    pub(super) struct TypeDef {
        position: Position,
        kind: TypeKind,
        name: Token,
        new_constraints: Any<types::Constraint>,
        old_type: types::BareType,
        old_constraints: Any<types::Constraint>,
    }

    enum TypeKind {
        Property,
        Type,
        Alias,
    }

    pub(super) struct Interface {
        position: Position,
        generics: Any<types::Generic>,
        name: Token,
        constraints: Any<types::Constraint>,
        pipes: Some<InterfacePipe>,
    }

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
mod import {
    use super::*;

    pub(super) struct Use {
        position: Position,
        kind: UseKind,
    }

    enum UseKind {
        Direct(DirectUse),
        Package(NamedPackage),
        Symbol(NamedSymbol),
    }

    enum SymbolKind {
        All,
        Literal(Token),
        NamedLiterals(Some<NamedSymbol>),
    }

    struct DirectUse {
        package: Some<Token>,
        symbols: Option<SymbolKind>,
    }

    struct NamedPackage {
        package_name: Token,
        package: Some<Token>,
    }

    struct NamedSymbol {
        position: Position,
        name: Token,
        symbol: Token,
    }
}

/// Generic expressions - objects which evaluate to something.
mod expression {
    use super::*;

    pub(super) struct Expression {
        position: Position,
        kind: ExpressionKind,
    }

    enum ExpressionKind {
        Call(call::Call),
        Block(block::Block),
        ClosureDef(procedure::Closure),
        ProcedureEnd(statement::ProcedureEnd),
    }

    pub struct Program {
        imports: Any<import::Use>,
        kind: Any<ProgramKind>,
    }

    enum ProgramKind {
        Type(type_def::TypeDef),
        Struct(type_def::Struct),
        Enum(type_def::Enum),
        Interface(type_def::Interface),
        Assignment(statement::Assignment),
        Implementation(procedure::Implementation),
    }
}

/// Content of the package file
mod package {
    use super::*;

    pub struct Package {
        position: Position,
        package_name: Some<Token>,
    }

    pub struct ExportedSymbol {
        position: Position,
        kind: ExportedSymbolKind,
    }

    enum ExportedSymbolKind {
        Type,
        Interface,
        Function,
        Property,
    }
}
