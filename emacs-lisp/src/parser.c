#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 36
#define LARGE_STATE_COUNT 28
#define SYMBOL_COUNT 128
#define ALIAS_COUNT 0
#define TOKEN_COUNT 110
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 3
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 7

enum {
  sym_identifier = 1,
  aux_sym_comment_token1 = 2,
  aux_sym__doc_content_token1 = 3,
  anon_sym_EQ = 4,
  anon_sym_EQ_EQ = 5,
  anon_sym_EQ_EQ_EQ = 6,
  anon_sym_DOT = 7,
  anon_sym_EQ_GT = 8,
  anon_sym_PIPE = 9,
  anon_sym_PIPE_GT = 10,
  anon_sym_COLON_COLON = 11,
  anon_sym_COLON_COLON_COLON = 12,
  anon_sym_fn = 13,
  anon_sym_DOLLAR = 14,
  anon_sym_LT_LT = 15,
  sym_type_identifier = 16,
  anon_sym__ = 17,
  anon_sym_PERCENT = 18,
  anon_sym_POUND = 19,
  anon_sym_new = 20,
  anon_sym_old = 21,
  anon_sym_heap = 22,
  anon_sym_const = 23,
  anon_sym_if = 24,
  anon_sym_else = 25,
  anon_sym_while = 26,
  anon_sym_for = 27,
  anon_sym_in = 28,
  anon_sym_switch = 29,
  anon_sym_case = 30,
  anon_sym_fail = 31,
  anon_sym_sec = 32,
  anon_sym_pkg = 33,
  anon_sym_use = 34,
  anon_sym_package = 35,
  anon_sym_default = 36,
  anon_sym_struct = 37,
  anon_sym_type = 38,
  anon_sym_interface = 39,
  anon_sym_alias = 40,
  anon_sym_enum = 41,
  anon_sym_prop = 42,
  anon_sym_impl = 43,
  anon_sym_return = 44,
  anon_sym_yield = 45,
  anon_sym_cascade = 46,
  anon_sym_break = 47,
  anon_sym_loop = 48,
  anon_sym_void = 49,
  anon_sym_int = 50,
  anon_sym_char = 51,
  anon_sym_bool = 52,
  anon_sym_float = 53,
  anon_sym_range = 54,
  anon_sym_list = 55,
  anon_sym_string = 56,
  anon_sym_line = 57,
  anon_sym_word = 58,
  anon_sym_Program = 59,
  anon_sym_Embedded = 60,
  anon_sym_Self = 61,
  anon_sym_Type = 62,
  anon_sym_Field = 63,
  anon_sym_Variable = 64,
  anon_sym_into = 65,
  anon_sym_fun = 66,
  anon_sym_may = 67,
  anon_sym_itr = 68,
  anon_sym_err = 69,
  anon_sym_ark = 70,
  anon_sym_ptr = 71,
  anon_sym_mut = 72,
  anon_sym_ref = 73,
  anon_sym_true = 74,
  anon_sym_false = 75,
  anon_sym_LT_DASH = 76,
  anon_sym_DASH_GT = 77,
  anon_sym_QMARK_QMARK = 78,
  anon_sym____ = 79,
  anon_sym_BANG_EQ = 80,
  anon_sym_LT = 81,
  anon_sym_GT = 82,
  anon_sym_LT_EQ = 83,
  anon_sym_GT_EQ = 84,
  anon_sym_PLUS = 85,
  anon_sym_DASH = 86,
  anon_sym_STAR = 87,
  anon_sym_SLASH = 88,
  anon_sym_CARET = 89,
  anon_sym_BANG = 90,
  anon_sym_TILDE = 91,
  anon_sym_AMP = 92,
  anon_sym_BSLASH = 93,
  anon_sym_QMARK = 94,
  anon_sym_AT = 95,
  anon_sym_DASH_DASH = 96,
  anon_sym_GT_GT = 97,
  anon_sym_COLON = 98,
  anon_sym_SEMI = 99,
  anon_sym_COMMA = 100,
  anon_sym_LBRACE = 101,
  anon_sym_RBRACE = 102,
  anon_sym_LBRACK = 103,
  anon_sym_RBRACK = 104,
  anon_sym_LPAREN = 105,
  anon_sym_RPAREN = 106,
  sym_string = 107,
  sym_char = 108,
  sym_number = 109,
  sym_source_file = 110,
  sym_comment = 111,
  sym__item = 112,
  aux_sym__doc_content = 113,
  sym_documentation = 114,
  sym_field = 115,
  sym_procedure_definition = 116,
  sym_func_usage = 117,
  sym_pipe_usage = 118,
  sym_type_usage = 119,
  sym_keyword = 120,
  sym_terminator = 121,
  sym_type_keyword = 122,
  sym_modifier = 123,
  sym_boolean = 124,
  sym_operator = 125,
  sym_punctuation = 126,
  aux_sym_source_file_repeat1 = 127,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [sym_identifier] = "identifier",
  [aux_sym_comment_token1] = "comment_token1",
  [aux_sym__doc_content_token1] = "_doc_content_token1",
  [anon_sym_EQ] = "=",
  [anon_sym_EQ_EQ] = "==",
  [anon_sym_EQ_EQ_EQ] = "===",
  [anon_sym_DOT] = ".",
  [anon_sym_EQ_GT] = "=>",
  [anon_sym_PIPE] = "|",
  [anon_sym_PIPE_GT] = "|>",
  [anon_sym_COLON_COLON] = "::",
  [anon_sym_COLON_COLON_COLON] = ":::",
  [anon_sym_fn] = "fn",
  [anon_sym_DOLLAR] = "$",
  [anon_sym_LT_LT] = "<<",
  [sym_type_identifier] = "type_identifier",
  [anon_sym__] = "operator",
  [anon_sym_PERCENT] = "%",
  [anon_sym_POUND] = "#",
  [anon_sym_new] = "new",
  [anon_sym_old] = "old",
  [anon_sym_heap] = "heap",
  [anon_sym_const] = "const",
  [anon_sym_if] = "if",
  [anon_sym_else] = "else",
  [anon_sym_while] = "while",
  [anon_sym_for] = "for",
  [anon_sym_in] = "in",
  [anon_sym_switch] = "switch",
  [anon_sym_case] = "case",
  [anon_sym_fail] = "fail",
  [anon_sym_sec] = "sec",
  [anon_sym_pkg] = "pkg",
  [anon_sym_use] = "use",
  [anon_sym_package] = "package",
  [anon_sym_default] = "default",
  [anon_sym_struct] = "struct",
  [anon_sym_type] = "type",
  [anon_sym_interface] = "interface",
  [anon_sym_alias] = "alias",
  [anon_sym_enum] = "enum",
  [anon_sym_prop] = "prop",
  [anon_sym_impl] = "impl",
  [anon_sym_return] = "return",
  [anon_sym_yield] = "yield",
  [anon_sym_cascade] = "cascade",
  [anon_sym_break] = "break",
  [anon_sym_loop] = "loop",
  [anon_sym_void] = "void",
  [anon_sym_int] = "int",
  [anon_sym_char] = "char",
  [anon_sym_bool] = "bool",
  [anon_sym_float] = "float",
  [anon_sym_range] = "range",
  [anon_sym_list] = "list",
  [anon_sym_string] = "string",
  [anon_sym_line] = "line",
  [anon_sym_word] = "word",
  [anon_sym_Program] = "Program",
  [anon_sym_Embedded] = "Embedded",
  [anon_sym_Self] = "Self",
  [anon_sym_Type] = "Type",
  [anon_sym_Field] = "Field",
  [anon_sym_Variable] = "Variable",
  [anon_sym_into] = "into",
  [anon_sym_fun] = "fun",
  [anon_sym_may] = "may",
  [anon_sym_itr] = "itr",
  [anon_sym_err] = "err",
  [anon_sym_ark] = "ark",
  [anon_sym_ptr] = "ptr",
  [anon_sym_mut] = "mut",
  [anon_sym_ref] = "ref",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [anon_sym_LT_DASH] = "<-",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_QMARK_QMARK] = "\?\?",
  [anon_sym____] = "___",
  [anon_sym_BANG_EQ] = "!=",
  [anon_sym_LT] = "<",
  [anon_sym_GT] = ">",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_STAR] = "*",
  [anon_sym_SLASH] = "/",
  [anon_sym_CARET] = "^",
  [anon_sym_BANG] = "!",
  [anon_sym_TILDE] = "~",
  [anon_sym_AMP] = "&",
  [anon_sym_BSLASH] = "\\",
  [anon_sym_QMARK] = "\?",
  [anon_sym_AT] = "@",
  [anon_sym_DASH_DASH] = "--",
  [anon_sym_GT_GT] = ">>",
  [anon_sym_COLON] = ":",
  [anon_sym_SEMI] = ";",
  [anon_sym_COMMA] = ",",
  [anon_sym_LBRACE] = "{",
  [anon_sym_RBRACE] = "}",
  [anon_sym_LBRACK] = "[",
  [anon_sym_RBRACK] = "]",
  [anon_sym_LPAREN] = "(",
  [anon_sym_RPAREN] = ")",
  [sym_string] = "string",
  [sym_char] = "char",
  [sym_number] = "number",
  [sym_source_file] = "source_file",
  [sym_comment] = "comment",
  [sym__item] = "_item",
  [aux_sym__doc_content] = "_doc_content",
  [sym_documentation] = "documentation",
  [sym_field] = "field",
  [sym_procedure_definition] = "procedure_definition",
  [sym_func_usage] = "func_usage",
  [sym_pipe_usage] = "pipe_usage",
  [sym_type_usage] = "type_usage",
  [sym_keyword] = "keyword",
  [sym_terminator] = "terminator",
  [sym_type_keyword] = "type_keyword",
  [sym_modifier] = "modifier",
  [sym_boolean] = "boolean",
  [sym_operator] = "operator",
  [sym_punctuation] = "punctuation",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [sym_identifier] = sym_identifier,
  [aux_sym_comment_token1] = aux_sym_comment_token1,
  [aux_sym__doc_content_token1] = aux_sym__doc_content_token1,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
  [anon_sym_EQ_EQ_EQ] = anon_sym_EQ_EQ_EQ,
  [anon_sym_DOT] = anon_sym_DOT,
  [anon_sym_EQ_GT] = anon_sym_EQ_GT,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_PIPE_GT] = anon_sym_PIPE_GT,
  [anon_sym_COLON_COLON] = anon_sym_COLON_COLON,
  [anon_sym_COLON_COLON_COLON] = anon_sym_COLON_COLON_COLON,
  [anon_sym_fn] = anon_sym_fn,
  [anon_sym_DOLLAR] = anon_sym_DOLLAR,
  [anon_sym_LT_LT] = anon_sym_LT_LT,
  [sym_type_identifier] = sym_type_identifier,
  [anon_sym__] = sym_operator,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_POUND] = anon_sym_POUND,
  [anon_sym_new] = anon_sym_new,
  [anon_sym_old] = anon_sym_old,
  [anon_sym_heap] = anon_sym_heap,
  [anon_sym_const] = anon_sym_const,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_else] = anon_sym_else,
  [anon_sym_while] = anon_sym_while,
  [anon_sym_for] = anon_sym_for,
  [anon_sym_in] = anon_sym_in,
  [anon_sym_switch] = anon_sym_switch,
  [anon_sym_case] = anon_sym_case,
  [anon_sym_fail] = anon_sym_fail,
  [anon_sym_sec] = anon_sym_sec,
  [anon_sym_pkg] = anon_sym_pkg,
  [anon_sym_use] = anon_sym_use,
  [anon_sym_package] = anon_sym_package,
  [anon_sym_default] = anon_sym_default,
  [anon_sym_struct] = anon_sym_struct,
  [anon_sym_type] = anon_sym_type,
  [anon_sym_interface] = anon_sym_interface,
  [anon_sym_alias] = anon_sym_alias,
  [anon_sym_enum] = anon_sym_enum,
  [anon_sym_prop] = anon_sym_prop,
  [anon_sym_impl] = anon_sym_impl,
  [anon_sym_return] = anon_sym_return,
  [anon_sym_yield] = anon_sym_yield,
  [anon_sym_cascade] = anon_sym_cascade,
  [anon_sym_break] = anon_sym_break,
  [anon_sym_loop] = anon_sym_loop,
  [anon_sym_void] = anon_sym_void,
  [anon_sym_int] = anon_sym_int,
  [anon_sym_char] = anon_sym_char,
  [anon_sym_bool] = anon_sym_bool,
  [anon_sym_float] = anon_sym_float,
  [anon_sym_range] = anon_sym_range,
  [anon_sym_list] = anon_sym_list,
  [anon_sym_string] = anon_sym_string,
  [anon_sym_line] = anon_sym_line,
  [anon_sym_word] = anon_sym_word,
  [anon_sym_Program] = anon_sym_Program,
  [anon_sym_Embedded] = anon_sym_Embedded,
  [anon_sym_Self] = anon_sym_Self,
  [anon_sym_Type] = anon_sym_Type,
  [anon_sym_Field] = anon_sym_Field,
  [anon_sym_Variable] = anon_sym_Variable,
  [anon_sym_into] = anon_sym_into,
  [anon_sym_fun] = anon_sym_fun,
  [anon_sym_may] = anon_sym_may,
  [anon_sym_itr] = anon_sym_itr,
  [anon_sym_err] = anon_sym_err,
  [anon_sym_ark] = anon_sym_ark,
  [anon_sym_ptr] = anon_sym_ptr,
  [anon_sym_mut] = anon_sym_mut,
  [anon_sym_ref] = anon_sym_ref,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_LT_DASH] = anon_sym_LT_DASH,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_QMARK_QMARK] = anon_sym_QMARK_QMARK,
  [anon_sym____] = anon_sym____,
  [anon_sym_BANG_EQ] = anon_sym_BANG_EQ,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_CARET] = anon_sym_CARET,
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_TILDE] = anon_sym_TILDE,
  [anon_sym_AMP] = anon_sym_AMP,
  [anon_sym_BSLASH] = anon_sym_BSLASH,
  [anon_sym_QMARK] = anon_sym_QMARK,
  [anon_sym_AT] = anon_sym_AT,
  [anon_sym_DASH_DASH] = anon_sym_DASH_DASH,
  [anon_sym_GT_GT] = anon_sym_GT_GT,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_SEMI] = anon_sym_SEMI,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_LBRACE] = anon_sym_LBRACE,
  [anon_sym_RBRACE] = anon_sym_RBRACE,
  [anon_sym_LBRACK] = anon_sym_LBRACK,
  [anon_sym_RBRACK] = anon_sym_RBRACK,
  [anon_sym_LPAREN] = anon_sym_LPAREN,
  [anon_sym_RPAREN] = anon_sym_RPAREN,
  [sym_string] = sym_string,
  [sym_char] = sym_char,
  [sym_number] = sym_number,
  [sym_source_file] = sym_source_file,
  [sym_comment] = sym_comment,
  [sym__item] = sym__item,
  [aux_sym__doc_content] = aux_sym__doc_content,
  [sym_documentation] = sym_documentation,
  [sym_field] = sym_field,
  [sym_procedure_definition] = sym_procedure_definition,
  [sym_func_usage] = sym_func_usage,
  [sym_pipe_usage] = sym_pipe_usage,
  [sym_type_usage] = sym_type_usage,
  [sym_keyword] = sym_keyword,
  [sym_terminator] = sym_terminator,
  [sym_type_keyword] = sym_type_keyword,
  [sym_modifier] = sym_modifier,
  [sym_boolean] = sym_boolean,
  [sym_operator] = sym_operator,
  [sym_punctuation] = sym_punctuation,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_comment_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__doc_content_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_EQ_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PIPE_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_COLON_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fn] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DOLLAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_LT] = {
    .visible = true,
    .named = false,
  },
  [sym_type_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym__] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_POUND] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_new] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_old] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_heap] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_const] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_else] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_while] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_for] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_in] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_switch] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_case] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fail] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_sec] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pkg] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_use] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_package] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_default] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_struct] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_type] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_interface] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_alias] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_enum] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_prop] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_impl] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_return] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_yield] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_cascade] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_break] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_loop] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_void] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_int] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_char] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_bool] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_float] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_range] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_list] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_string] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_line] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_word] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Program] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Embedded] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Self] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Type] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Field] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_Variable] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_into] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_fun] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_may] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_itr] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_err] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ark] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ptr] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_mut] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_ref] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_true] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_false] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_QMARK_QMARK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym____] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CARET] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_TILDE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_BSLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_QMARK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SEMI] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RBRACK] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LPAREN] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_RPAREN] = {
    .visible = true,
    .named = false,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [sym_char] = {
    .visible = true,
    .named = true,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym_comment] = {
    .visible = true,
    .named = true,
  },
  [sym__item] = {
    .visible = false,
    .named = true,
  },
  [aux_sym__doc_content] = {
    .visible = false,
    .named = false,
  },
  [sym_documentation] = {
    .visible = true,
    .named = true,
  },
  [sym_field] = {
    .visible = true,
    .named = true,
  },
  [sym_procedure_definition] = {
    .visible = true,
    .named = true,
  },
  [sym_func_usage] = {
    .visible = true,
    .named = true,
  },
  [sym_pipe_usage] = {
    .visible = true,
    .named = true,
  },
  [sym_type_usage] = {
    .visible = true,
    .named = true,
  },
  [sym_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_terminator] = {
    .visible = true,
    .named = true,
  },
  [sym_type_keyword] = {
    .visible = true,
    .named = true,
  },
  [sym_modifier] = {
    .visible = true,
    .named = true,
  },
  [sym_boolean] = {
    .visible = true,
    .named = true,
  },
  [sym_operator] = {
    .visible = true,
    .named = true,
  },
  [sym_punctuation] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
};

enum {
  field_name = 1,
  field_operator = 2,
  field_prefix = 3,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_name] = "name",
  [field_operator] = "operator",
  [field_prefix] = "prefix",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 1},
  [3] = {.index = 2, .length = 1},
  [4] = {.index = 3, .length = 2},
  [5] = {.index = 5, .length = 1},
  [6] = {.index = 2, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 1},
    {field_operator, 0},
  [2] =
    {field_name, 1},
  [3] =
    {field_name, 1},
    {field_prefix, 0},
  [5] =
    {field_name, 0},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [3] = {
    [0] = sym_keyword,
  },
  [4] = {
    [0] = sym_operator,
  },
  [5] = {
    [1] = sym_operator,
  },
  [6] = {
    [0] = sym_operator,
    [2] = sym_operator,
  },
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 7,
  [8] = 8,
  [9] = 9,
  [10] = 10,
  [11] = 11,
  [12] = 12,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 16,
  [17] = 17,
  [18] = 18,
  [19] = 19,
  [20] = 20,
  [21] = 21,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 33,
  [34] = 34,
  [35] = 35,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(10);
      if (lookahead == '!') ADVANCE(44);
      if (lookahead == '"') ADVANCE(1);
      if (lookahead == '#') ADVANCE(30);
      if (lookahead == '$') ADVANCE(26);
      if (lookahead == '%') ADVANCE(29);
      if (lookahead == '&') ADVANCE(46);
      if (lookahead == '\'') ADVANCE(6);
      if (lookahead == '(') ADVANCE(59);
      if (lookahead == ')') ADVANCE(60);
      if (lookahead == '*') ADVANCE(41);
      if (lookahead == '+') ADVANCE(39);
      if (lookahead == ',') ADVANCE(54);
      if (lookahead == '-') ADVANCE(40);
      if (lookahead == '.') ADVANCE(20);
      if (lookahead == '/') ADVANCE(42);
      if (lookahead == ':') ADVANCE(52);
      if (lookahead == ';') ADVANCE(53);
      if (lookahead == '<') ADVANCE(35);
      if (lookahead == '=') ADVANCE(17);
      if (lookahead == '>') ADVANCE(36);
      if (lookahead == '?') ADVANCE(48);
      if (lookahead == '@') ADVANCE(49);
      if (lookahead == '[') ADVANCE(57);
      if (lookahead == '\\') ADVANCE(47);
      if (lookahead == ']') ADVANCE(58);
      if (lookahead == '^') ADVANCE(43);
      if (lookahead == '_') ADVANCE(65);
      if (lookahead == '`') ADVANCE(7);
      if (lookahead == '{') ADVANCE(55);
      if (lookahead == '|') ADVANCE(22);
      if (lookahead == '}') ADVANCE(56);
      if (lookahead == '~') ADVANCE(45);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(63);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(28);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(61);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '\'') ADVANCE(62);
      END_STATE();
    case 3:
      if (lookahead == '/') ADVANCE(12);
      END_STATE();
    case 4:
      if (lookahead == '/') ADVANCE(14);
      if (lookahead == '=') ADVANCE(16);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(13);
      if (lookahead != 0) ADVANCE(15);
      END_STATE();
    case 5:
      if (lookahead == '/') ADVANCE(3);
      if (lookahead == '_') ADVANCE(65);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(5)
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 6:
      if (lookahead == '\\') ADVANCE(9);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 7:
      if (lookahead == '`') ADVANCE(61);
      if (lookahead != 0) ADVANCE(7);
      END_STATE();
    case 8:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(64);
      END_STATE();
    case 9:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(2);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead == '\n') ADVANCE(15);
      if (lookahead == '=') ADVANCE(12);
      if (lookahead != 0) ADVANCE(11);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(aux_sym_comment_token1);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(12);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(aux_sym__doc_content_token1);
      if (lookahead == '/') ADVANCE(14);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(13);
      if (lookahead != 0 &&
          lookahead != '=') ADVANCE(15);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(aux_sym__doc_content_token1);
      if (lookahead == '/') ADVANCE(11);
      if (lookahead != 0 &&
          lookahead != '=') ADVANCE(15);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(aux_sym__doc_content_token1);
      if (lookahead != 0 &&
          lookahead != '=') ADVANCE(15);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(18);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(18);
      if (lookahead == '>') ADVANCE(21);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      if (lookahead == '=') ADVANCE(19);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_EQ_EQ_EQ);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_EQ_GT);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '>') ADVANCE(23);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_PIPE_GT);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_COLON_COLON);
      if (lookahead == ':') ADVANCE(25);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_COLON_COLON_COLON);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_LT_LT);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(sym_type_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(28);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_LT_DASH);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_QMARK_QMARK);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '-') ADVANCE(31);
      if (lookahead == '<') ADVANCE(27);
      if (lookahead == '=') ADVANCE(37);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(38);
      if (lookahead == '>') ADVANCE(51);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-') ADVANCE(50);
      if (lookahead == '>') ADVANCE(32);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '/') ADVANCE(12);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_CARET);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_BANG);
      if (lookahead == '=') ADVANCE(34);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_AMP);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_QMARK);
      if (lookahead == '?') ADVANCE(33);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_GT_GT);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == ':') ADVANCE(24);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_char);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(8);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(63);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(64);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(65);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(66);
      END_STATE();
    default:
      return false;
  }
}

static bool ts_lex_keywords(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (lookahead == 'E') ADVANCE(1);
      if (lookahead == 'F') ADVANCE(2);
      if (lookahead == 'P') ADVANCE(3);
      if (lookahead == 'S') ADVANCE(4);
      if (lookahead == 'T') ADVANCE(5);
      if (lookahead == 'V') ADVANCE(6);
      if (lookahead == '_') ADVANCE(7);
      if (lookahead == 'a') ADVANCE(8);
      if (lookahead == 'b') ADVANCE(9);
      if (lookahead == 'c') ADVANCE(10);
      if (lookahead == 'd') ADVANCE(11);
      if (lookahead == 'e') ADVANCE(12);
      if (lookahead == 'f') ADVANCE(13);
      if (lookahead == 'h') ADVANCE(14);
      if (lookahead == 'i') ADVANCE(15);
      if (lookahead == 'l') ADVANCE(16);
      if (lookahead == 'm') ADVANCE(17);
      if (lookahead == 'n') ADVANCE(18);
      if (lookahead == 'o') ADVANCE(19);
      if (lookahead == 'p') ADVANCE(20);
      if (lookahead == 'r') ADVANCE(21);
      if (lookahead == 's') ADVANCE(22);
      if (lookahead == 't') ADVANCE(23);
      if (lookahead == 'u') ADVANCE(24);
      if (lookahead == 'v') ADVANCE(25);
      if (lookahead == 'w') ADVANCE(26);
      if (lookahead == 'y') ADVANCE(27);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      END_STATE();
    case 1:
      if (lookahead == 'm') ADVANCE(28);
      END_STATE();
    case 2:
      if (lookahead == 'i') ADVANCE(29);
      END_STATE();
    case 3:
      if (lookahead == 'r') ADVANCE(30);
      END_STATE();
    case 4:
      if (lookahead == 'e') ADVANCE(31);
      END_STATE();
    case 5:
      if (lookahead == 'y') ADVANCE(32);
      END_STATE();
    case 6:
      if (lookahead == 'a') ADVANCE(33);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym__);
      if (lookahead == '_') ADVANCE(34);
      END_STATE();
    case 8:
      if (lookahead == 'l') ADVANCE(35);
      if (lookahead == 'r') ADVANCE(36);
      END_STATE();
    case 9:
      if (lookahead == 'o') ADVANCE(37);
      if (lookahead == 'r') ADVANCE(38);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(39);
      if (lookahead == 'h') ADVANCE(40);
      if (lookahead == 'o') ADVANCE(41);
      END_STATE();
    case 11:
      if (lookahead == 'e') ADVANCE(42);
      END_STATE();
    case 12:
      if (lookahead == 'l') ADVANCE(43);
      if (lookahead == 'n') ADVANCE(44);
      if (lookahead == 'r') ADVANCE(45);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(46);
      if (lookahead == 'l') ADVANCE(47);
      if (lookahead == 'n') ADVANCE(48);
      if (lookahead == 'o') ADVANCE(49);
      if (lookahead == 'u') ADVANCE(50);
      END_STATE();
    case 14:
      if (lookahead == 'e') ADVANCE(51);
      END_STATE();
    case 15:
      if (lookahead == 'f') ADVANCE(52);
      if (lookahead == 'm') ADVANCE(53);
      if (lookahead == 'n') ADVANCE(54);
      if (lookahead == 't') ADVANCE(55);
      END_STATE();
    case 16:
      if (lookahead == 'i') ADVANCE(56);
      if (lookahead == 'o') ADVANCE(57);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(58);
      if (lookahead == 'u') ADVANCE(59);
      END_STATE();
    case 18:
      if (lookahead == 'e') ADVANCE(60);
      END_STATE();
    case 19:
      if (lookahead == 'l') ADVANCE(61);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(62);
      if (lookahead == 'k') ADVANCE(63);
      if (lookahead == 'r') ADVANCE(64);
      if (lookahead == 't') ADVANCE(65);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(66);
      if (lookahead == 'e') ADVANCE(67);
      END_STATE();
    case 22:
      if (lookahead == 'e') ADVANCE(68);
      if (lookahead == 't') ADVANCE(69);
      if (lookahead == 'w') ADVANCE(70);
      END_STATE();
    case 23:
      if (lookahead == 'r') ADVANCE(71);
      if (lookahead == 'y') ADVANCE(72);
      END_STATE();
    case 24:
      if (lookahead == 's') ADVANCE(73);
      END_STATE();
    case 25:
      if (lookahead == 'o') ADVANCE(74);
      END_STATE();
    case 26:
      if (lookahead == 'h') ADVANCE(75);
      if (lookahead == 'o') ADVANCE(76);
      END_STATE();
    case 27:
      if (lookahead == 'i') ADVANCE(77);
      END_STATE();
    case 28:
      if (lookahead == 'b') ADVANCE(78);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(79);
      END_STATE();
    case 30:
      if (lookahead == 'o') ADVANCE(80);
      END_STATE();
    case 31:
      if (lookahead == 'l') ADVANCE(81);
      END_STATE();
    case 32:
      if (lookahead == 'p') ADVANCE(82);
      END_STATE();
    case 33:
      if (lookahead == 'r') ADVANCE(83);
      END_STATE();
    case 34:
      if (lookahead == '_') ADVANCE(84);
      END_STATE();
    case 35:
      if (lookahead == 'i') ADVANCE(85);
      END_STATE();
    case 36:
      if (lookahead == 'k') ADVANCE(86);
      END_STATE();
    case 37:
      if (lookahead == 'o') ADVANCE(87);
      END_STATE();
    case 38:
      if (lookahead == 'e') ADVANCE(88);
      END_STATE();
    case 39:
      if (lookahead == 's') ADVANCE(89);
      END_STATE();
    case 40:
      if (lookahead == 'a') ADVANCE(90);
      END_STATE();
    case 41:
      if (lookahead == 'n') ADVANCE(91);
      END_STATE();
    case 42:
      if (lookahead == 'f') ADVANCE(92);
      END_STATE();
    case 43:
      if (lookahead == 's') ADVANCE(93);
      END_STATE();
    case 44:
      if (lookahead == 'u') ADVANCE(94);
      END_STATE();
    case 45:
      if (lookahead == 'r') ADVANCE(95);
      END_STATE();
    case 46:
      if (lookahead == 'i') ADVANCE(96);
      if (lookahead == 'l') ADVANCE(97);
      END_STATE();
    case 47:
      if (lookahead == 'o') ADVANCE(98);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_fn);
      END_STATE();
    case 49:
      if (lookahead == 'r') ADVANCE(99);
      END_STATE();
    case 50:
      if (lookahead == 'n') ADVANCE(100);
      END_STATE();
    case 51:
      if (lookahead == 'a') ADVANCE(101);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 53:
      if (lookahead == 'p') ADVANCE(102);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_in);
      if (lookahead == 't') ADVANCE(103);
      END_STATE();
    case 55:
      if (lookahead == 'r') ADVANCE(104);
      END_STATE();
    case 56:
      if (lookahead == 'n') ADVANCE(105);
      if (lookahead == 's') ADVANCE(106);
      END_STATE();
    case 57:
      if (lookahead == 'o') ADVANCE(107);
      END_STATE();
    case 58:
      if (lookahead == 'y') ADVANCE(108);
      END_STATE();
    case 59:
      if (lookahead == 't') ADVANCE(109);
      END_STATE();
    case 60:
      if (lookahead == 'w') ADVANCE(110);
      END_STATE();
    case 61:
      if (lookahead == 'd') ADVANCE(111);
      END_STATE();
    case 62:
      if (lookahead == 'c') ADVANCE(112);
      END_STATE();
    case 63:
      if (lookahead == 'g') ADVANCE(113);
      END_STATE();
    case 64:
      if (lookahead == 'o') ADVANCE(114);
      END_STATE();
    case 65:
      if (lookahead == 'r') ADVANCE(115);
      END_STATE();
    case 66:
      if (lookahead == 'n') ADVANCE(116);
      END_STATE();
    case 67:
      if (lookahead == 'f') ADVANCE(117);
      if (lookahead == 't') ADVANCE(118);
      END_STATE();
    case 68:
      if (lookahead == 'c') ADVANCE(119);
      END_STATE();
    case 69:
      if (lookahead == 'r') ADVANCE(120);
      END_STATE();
    case 70:
      if (lookahead == 'i') ADVANCE(121);
      END_STATE();
    case 71:
      if (lookahead == 'u') ADVANCE(122);
      END_STATE();
    case 72:
      if (lookahead == 'p') ADVANCE(123);
      END_STATE();
    case 73:
      if (lookahead == 'e') ADVANCE(124);
      END_STATE();
    case 74:
      if (lookahead == 'i') ADVANCE(125);
      END_STATE();
    case 75:
      if (lookahead == 'i') ADVANCE(126);
      END_STATE();
    case 76:
      if (lookahead == 'r') ADVANCE(127);
      END_STATE();
    case 77:
      if (lookahead == 'e') ADVANCE(128);
      END_STATE();
    case 78:
      if (lookahead == 'e') ADVANCE(129);
      END_STATE();
    case 79:
      if (lookahead == 'l') ADVANCE(130);
      END_STATE();
    case 80:
      if (lookahead == 'g') ADVANCE(131);
      END_STATE();
    case 81:
      if (lookahead == 'f') ADVANCE(132);
      END_STATE();
    case 82:
      if (lookahead == 'e') ADVANCE(133);
      END_STATE();
    case 83:
      if (lookahead == 'i') ADVANCE(134);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym____);
      END_STATE();
    case 85:
      if (lookahead == 'a') ADVANCE(135);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_ark);
      END_STATE();
    case 87:
      if (lookahead == 'l') ADVANCE(136);
      END_STATE();
    case 88:
      if (lookahead == 'a') ADVANCE(137);
      END_STATE();
    case 89:
      if (lookahead == 'c') ADVANCE(138);
      if (lookahead == 'e') ADVANCE(139);
      END_STATE();
    case 90:
      if (lookahead == 'r') ADVANCE(140);
      END_STATE();
    case 91:
      if (lookahead == 's') ADVANCE(141);
      END_STATE();
    case 92:
      if (lookahead == 'a') ADVANCE(142);
      END_STATE();
    case 93:
      if (lookahead == 'e') ADVANCE(143);
      END_STATE();
    case 94:
      if (lookahead == 'm') ADVANCE(144);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_err);
      END_STATE();
    case 96:
      if (lookahead == 'l') ADVANCE(145);
      END_STATE();
    case 97:
      if (lookahead == 's') ADVANCE(146);
      END_STATE();
    case 98:
      if (lookahead == 'a') ADVANCE(147);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_for);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_fun);
      END_STATE();
    case 101:
      if (lookahead == 'p') ADVANCE(148);
      END_STATE();
    case 102:
      if (lookahead == 'l') ADVANCE(149);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_int);
      if (lookahead == 'e') ADVANCE(150);
      if (lookahead == 'o') ADVANCE(151);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_itr);
      END_STATE();
    case 105:
      if (lookahead == 'e') ADVANCE(152);
      END_STATE();
    case 106:
      if (lookahead == 't') ADVANCE(153);
      END_STATE();
    case 107:
      if (lookahead == 'p') ADVANCE(154);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_may);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_mut);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_new);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_old);
      END_STATE();
    case 112:
      if (lookahead == 'k') ADVANCE(155);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_pkg);
      END_STATE();
    case 114:
      if (lookahead == 'p') ADVANCE(156);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_ptr);
      END_STATE();
    case 116:
      if (lookahead == 'g') ADVANCE(157);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_ref);
      END_STATE();
    case 118:
      if (lookahead == 'u') ADVANCE(158);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_sec);
      END_STATE();
    case 120:
      if (lookahead == 'i') ADVANCE(159);
      if (lookahead == 'u') ADVANCE(160);
      END_STATE();
    case 121:
      if (lookahead == 't') ADVANCE(161);
      END_STATE();
    case 122:
      if (lookahead == 'e') ADVANCE(162);
      END_STATE();
    case 123:
      if (lookahead == 'e') ADVANCE(163);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(anon_sym_use);
      END_STATE();
    case 125:
      if (lookahead == 'd') ADVANCE(164);
      END_STATE();
    case 126:
      if (lookahead == 'l') ADVANCE(165);
      END_STATE();
    case 127:
      if (lookahead == 'd') ADVANCE(166);
      END_STATE();
    case 128:
      if (lookahead == 'l') ADVANCE(167);
      END_STATE();
    case 129:
      if (lookahead == 'd') ADVANCE(168);
      END_STATE();
    case 130:
      if (lookahead == 'd') ADVANCE(169);
      END_STATE();
    case 131:
      if (lookahead == 'r') ADVANCE(170);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(anon_sym_Self);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(anon_sym_Type);
      END_STATE();
    case 134:
      if (lookahead == 'a') ADVANCE(171);
      END_STATE();
    case 135:
      if (lookahead == 's') ADVANCE(172);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_bool);
      END_STATE();
    case 137:
      if (lookahead == 'k') ADVANCE(173);
      END_STATE();
    case 138:
      if (lookahead == 'a') ADVANCE(174);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(anon_sym_case);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_char);
      END_STATE();
    case 141:
      if (lookahead == 't') ADVANCE(175);
      END_STATE();
    case 142:
      if (lookahead == 'u') ADVANCE(176);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_enum);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(anon_sym_fail);
      END_STATE();
    case 146:
      if (lookahead == 'e') ADVANCE(177);
      END_STATE();
    case 147:
      if (lookahead == 't') ADVANCE(178);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_heap);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_impl);
      END_STATE();
    case 150:
      if (lookahead == 'r') ADVANCE(179);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(anon_sym_into);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(anon_sym_line);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_list);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_loop);
      END_STATE();
    case 155:
      if (lookahead == 'a') ADVANCE(180);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_prop);
      END_STATE();
    case 157:
      if (lookahead == 'e') ADVANCE(181);
      END_STATE();
    case 158:
      if (lookahead == 'r') ADVANCE(182);
      END_STATE();
    case 159:
      if (lookahead == 'n') ADVANCE(183);
      END_STATE();
    case 160:
      if (lookahead == 'c') ADVANCE(184);
      END_STATE();
    case 161:
      if (lookahead == 'c') ADVANCE(185);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(anon_sym_type);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(anon_sym_void);
      END_STATE();
    case 165:
      if (lookahead == 'e') ADVANCE(186);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(anon_sym_word);
      END_STATE();
    case 167:
      if (lookahead == 'd') ADVANCE(187);
      END_STATE();
    case 168:
      if (lookahead == 'd') ADVANCE(188);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(anon_sym_Field);
      END_STATE();
    case 170:
      if (lookahead == 'a') ADVANCE(189);
      END_STATE();
    case 171:
      if (lookahead == 'b') ADVANCE(190);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(anon_sym_alias);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(anon_sym_break);
      END_STATE();
    case 174:
      if (lookahead == 'd') ADVANCE(191);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(anon_sym_const);
      END_STATE();
    case 176:
      if (lookahead == 'l') ADVANCE(192);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(anon_sym_float);
      END_STATE();
    case 179:
      if (lookahead == 'f') ADVANCE(193);
      END_STATE();
    case 180:
      if (lookahead == 'g') ADVANCE(194);
      END_STATE();
    case 181:
      ACCEPT_TOKEN(anon_sym_range);
      END_STATE();
    case 182:
      if (lookahead == 'n') ADVANCE(195);
      END_STATE();
    case 183:
      if (lookahead == 'g') ADVANCE(196);
      END_STATE();
    case 184:
      if (lookahead == 't') ADVANCE(197);
      END_STATE();
    case 185:
      if (lookahead == 'h') ADVANCE(198);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(anon_sym_while);
      END_STATE();
    case 187:
      ACCEPT_TOKEN(anon_sym_yield);
      END_STATE();
    case 188:
      if (lookahead == 'e') ADVANCE(199);
      END_STATE();
    case 189:
      if (lookahead == 'm') ADVANCE(200);
      END_STATE();
    case 190:
      if (lookahead == 'l') ADVANCE(201);
      END_STATE();
    case 191:
      if (lookahead == 'e') ADVANCE(202);
      END_STATE();
    case 192:
      if (lookahead == 't') ADVANCE(203);
      END_STATE();
    case 193:
      if (lookahead == 'a') ADVANCE(204);
      END_STATE();
    case 194:
      if (lookahead == 'e') ADVANCE(205);
      END_STATE();
    case 195:
      ACCEPT_TOKEN(anon_sym_return);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(anon_sym_string);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(anon_sym_struct);
      END_STATE();
    case 198:
      ACCEPT_TOKEN(anon_sym_switch);
      END_STATE();
    case 199:
      if (lookahead == 'd') ADVANCE(206);
      END_STATE();
    case 200:
      ACCEPT_TOKEN(anon_sym_Program);
      END_STATE();
    case 201:
      if (lookahead == 'e') ADVANCE(207);
      END_STATE();
    case 202:
      ACCEPT_TOKEN(anon_sym_cascade);
      END_STATE();
    case 203:
      ACCEPT_TOKEN(anon_sym_default);
      END_STATE();
    case 204:
      if (lookahead == 'c') ADVANCE(208);
      END_STATE();
    case 205:
      ACCEPT_TOKEN(anon_sym_package);
      END_STATE();
    case 206:
      ACCEPT_TOKEN(anon_sym_Embedded);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(anon_sym_Variable);
      END_STATE();
    case 208:
      if (lookahead == 'e') ADVANCE(209);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(anon_sym_interface);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 4},
  [29] = {.lex_state = 4},
  [30] = {.lex_state = 4},
  [31] = {.lex_state = 4},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 5},
  [34] = {.lex_state = 0},
  [35] = {(TSStateId)(-1)},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [sym_comment] = STATE(0),
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_EQ_EQ] = ACTIONS(1),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(1),
    [anon_sym_DOT] = ACTIONS(1),
    [anon_sym_EQ_GT] = ACTIONS(1),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_PIPE_GT] = ACTIONS(1),
    [anon_sym_COLON_COLON] = ACTIONS(1),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(1),
    [anon_sym_fn] = ACTIONS(1),
    [anon_sym_DOLLAR] = ACTIONS(1),
    [anon_sym_LT_LT] = ACTIONS(1),
    [sym_type_identifier] = ACTIONS(1),
    [anon_sym__] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_POUND] = ACTIONS(1),
    [anon_sym_new] = ACTIONS(1),
    [anon_sym_old] = ACTIONS(1),
    [anon_sym_heap] = ACTIONS(1),
    [anon_sym_const] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_else] = ACTIONS(1),
    [anon_sym_while] = ACTIONS(1),
    [anon_sym_for] = ACTIONS(1),
    [anon_sym_in] = ACTIONS(1),
    [anon_sym_switch] = ACTIONS(1),
    [anon_sym_case] = ACTIONS(1),
    [anon_sym_fail] = ACTIONS(1),
    [anon_sym_sec] = ACTIONS(1),
    [anon_sym_pkg] = ACTIONS(1),
    [anon_sym_use] = ACTIONS(1),
    [anon_sym_package] = ACTIONS(1),
    [anon_sym_default] = ACTIONS(1),
    [anon_sym_struct] = ACTIONS(1),
    [anon_sym_type] = ACTIONS(1),
    [anon_sym_interface] = ACTIONS(1),
    [anon_sym_alias] = ACTIONS(1),
    [anon_sym_enum] = ACTIONS(1),
    [anon_sym_prop] = ACTIONS(1),
    [anon_sym_impl] = ACTIONS(1),
    [anon_sym_return] = ACTIONS(1),
    [anon_sym_yield] = ACTIONS(1),
    [anon_sym_cascade] = ACTIONS(1),
    [anon_sym_break] = ACTIONS(1),
    [anon_sym_loop] = ACTIONS(1),
    [anon_sym_void] = ACTIONS(1),
    [anon_sym_int] = ACTIONS(1),
    [anon_sym_char] = ACTIONS(1),
    [anon_sym_bool] = ACTIONS(1),
    [anon_sym_float] = ACTIONS(1),
    [anon_sym_range] = ACTIONS(1),
    [anon_sym_list] = ACTIONS(1),
    [anon_sym_string] = ACTIONS(1),
    [anon_sym_line] = ACTIONS(1),
    [anon_sym_word] = ACTIONS(1),
    [anon_sym_Program] = ACTIONS(1),
    [anon_sym_Embedded] = ACTIONS(1),
    [anon_sym_Self] = ACTIONS(1),
    [anon_sym_Type] = ACTIONS(1),
    [anon_sym_Field] = ACTIONS(1),
    [anon_sym_Variable] = ACTIONS(1),
    [anon_sym_into] = ACTIONS(1),
    [anon_sym_fun] = ACTIONS(1),
    [anon_sym_may] = ACTIONS(1),
    [anon_sym_itr] = ACTIONS(1),
    [anon_sym_err] = ACTIONS(1),
    [anon_sym_ark] = ACTIONS(1),
    [anon_sym_ptr] = ACTIONS(1),
    [anon_sym_mut] = ACTIONS(1),
    [anon_sym_ref] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [anon_sym_LT_DASH] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_QMARK_QMARK] = ACTIONS(1),
    [anon_sym____] = ACTIONS(1),
    [anon_sym_BANG_EQ] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_CARET] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_TILDE] = ACTIONS(1),
    [anon_sym_AMP] = ACTIONS(1),
    [anon_sym_BSLASH] = ACTIONS(1),
    [anon_sym_QMARK] = ACTIONS(1),
    [anon_sym_AT] = ACTIONS(1),
    [anon_sym_DASH_DASH] = ACTIONS(1),
    [anon_sym_GT_GT] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_SEMI] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_LBRACE] = ACTIONS(1),
    [anon_sym_RBRACE] = ACTIONS(1),
    [anon_sym_LBRACK] = ACTIONS(1),
    [anon_sym_RBRACK] = ACTIONS(1),
    [anon_sym_LPAREN] = ACTIONS(1),
    [anon_sym_RPAREN] = ACTIONS(1),
    [sym_string] = ACTIONS(1),
    [sym_char] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(32),
    [sym_comment] = STATE(1),
    [sym__item] = STATE(21),
    [sym_documentation] = STATE(18),
    [sym_field] = STATE(18),
    [sym_procedure_definition] = STATE(18),
    [sym_func_usage] = STATE(18),
    [sym_pipe_usage] = STATE(18),
    [sym_type_usage] = STATE(18),
    [sym_keyword] = STATE(18),
    [sym_terminator] = STATE(18),
    [sym_type_keyword] = STATE(18),
    [sym_modifier] = STATE(18),
    [sym_boolean] = STATE(18),
    [sym_operator] = STATE(18),
    [sym_punctuation] = STATE(18),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_identifier] = ACTIONS(7),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(9),
    [anon_sym_EQ_EQ] = ACTIONS(9),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(11),
    [anon_sym_DOT] = ACTIONS(13),
    [anon_sym_EQ_GT] = ACTIONS(13),
    [anon_sym_PIPE] = ACTIONS(15),
    [anon_sym_PIPE_GT] = ACTIONS(17),
    [anon_sym_COLON_COLON] = ACTIONS(9),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(19),
    [anon_sym_fn] = ACTIONS(21),
    [anon_sym_DOLLAR] = ACTIONS(19),
    [anon_sym_LT_LT] = ACTIONS(19),
    [sym_type_identifier] = ACTIONS(23),
    [anon_sym__] = ACTIONS(25),
    [anon_sym_PERCENT] = ACTIONS(27),
    [anon_sym_POUND] = ACTIONS(27),
    [anon_sym_new] = ACTIONS(29),
    [anon_sym_old] = ACTIONS(29),
    [anon_sym_heap] = ACTIONS(29),
    [anon_sym_const] = ACTIONS(29),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_else] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(29),
    [anon_sym_for] = ACTIONS(29),
    [anon_sym_in] = ACTIONS(29),
    [anon_sym_switch] = ACTIONS(29),
    [anon_sym_case] = ACTIONS(29),
    [anon_sym_fail] = ACTIONS(29),
    [anon_sym_sec] = ACTIONS(29),
    [anon_sym_pkg] = ACTIONS(29),
    [anon_sym_use] = ACTIONS(29),
    [anon_sym_package] = ACTIONS(29),
    [anon_sym_default] = ACTIONS(29),
    [anon_sym_struct] = ACTIONS(29),
    [anon_sym_type] = ACTIONS(29),
    [anon_sym_interface] = ACTIONS(29),
    [anon_sym_alias] = ACTIONS(29),
    [anon_sym_enum] = ACTIONS(29),
    [anon_sym_prop] = ACTIONS(29),
    [anon_sym_impl] = ACTIONS(29),
    [anon_sym_return] = ACTIONS(31),
    [anon_sym_yield] = ACTIONS(31),
    [anon_sym_cascade] = ACTIONS(31),
    [anon_sym_break] = ACTIONS(31),
    [anon_sym_loop] = ACTIONS(31),
    [anon_sym_void] = ACTIONS(33),
    [anon_sym_int] = ACTIONS(33),
    [anon_sym_char] = ACTIONS(33),
    [anon_sym_bool] = ACTIONS(33),
    [anon_sym_float] = ACTIONS(33),
    [anon_sym_range] = ACTIONS(33),
    [anon_sym_list] = ACTIONS(33),
    [anon_sym_string] = ACTIONS(33),
    [anon_sym_line] = ACTIONS(33),
    [anon_sym_word] = ACTIONS(33),
    [anon_sym_Program] = ACTIONS(33),
    [anon_sym_Embedded] = ACTIONS(33),
    [anon_sym_Self] = ACTIONS(33),
    [anon_sym_Type] = ACTIONS(33),
    [anon_sym_Field] = ACTIONS(33),
    [anon_sym_Variable] = ACTIONS(33),
    [anon_sym_into] = ACTIONS(35),
    [anon_sym_fun] = ACTIONS(35),
    [anon_sym_may] = ACTIONS(35),
    [anon_sym_itr] = ACTIONS(35),
    [anon_sym_err] = ACTIONS(35),
    [anon_sym_ark] = ACTIONS(35),
    [anon_sym_ptr] = ACTIONS(35),
    [anon_sym_mut] = ACTIONS(35),
    [anon_sym_ref] = ACTIONS(35),
    [anon_sym_true] = ACTIONS(37),
    [anon_sym_false] = ACTIONS(37),
    [anon_sym_LT_DASH] = ACTIONS(19),
    [anon_sym_DASH_GT] = ACTIONS(19),
    [anon_sym_QMARK_QMARK] = ACTIONS(19),
    [anon_sym____] = ACTIONS(9),
    [anon_sym_BANG_EQ] = ACTIONS(19),
    [anon_sym_LT] = ACTIONS(9),
    [anon_sym_GT] = ACTIONS(9),
    [anon_sym_LT_EQ] = ACTIONS(19),
    [anon_sym_GT_EQ] = ACTIONS(19),
    [anon_sym_PLUS] = ACTIONS(19),
    [anon_sym_DASH] = ACTIONS(9),
    [anon_sym_STAR] = ACTIONS(19),
    [anon_sym_SLASH] = ACTIONS(9),
    [anon_sym_CARET] = ACTIONS(19),
    [anon_sym_BANG] = ACTIONS(9),
    [anon_sym_TILDE] = ACTIONS(19),
    [anon_sym_AMP] = ACTIONS(19),
    [anon_sym_BSLASH] = ACTIONS(19),
    [anon_sym_QMARK] = ACTIONS(9),
    [anon_sym_AT] = ACTIONS(19),
    [anon_sym_DASH_DASH] = ACTIONS(19),
    [anon_sym_GT_GT] = ACTIONS(19),
    [anon_sym_COLON] = ACTIONS(39),
    [anon_sym_SEMI] = ACTIONS(41),
    [anon_sym_COMMA] = ACTIONS(41),
    [anon_sym_LBRACE] = ACTIONS(41),
    [anon_sym_RBRACE] = ACTIONS(41),
    [anon_sym_LBRACK] = ACTIONS(41),
    [anon_sym_RBRACK] = ACTIONS(41),
    [anon_sym_LPAREN] = ACTIONS(41),
    [anon_sym_RPAREN] = ACTIONS(41),
    [sym_string] = ACTIONS(43),
    [sym_char] = ACTIONS(43),
    [sym_number] = ACTIONS(45),
  },
  [2] = {
    [sym_comment] = STATE(2),
    [sym__item] = STATE(21),
    [sym_documentation] = STATE(18),
    [sym_field] = STATE(18),
    [sym_procedure_definition] = STATE(18),
    [sym_func_usage] = STATE(18),
    [sym_pipe_usage] = STATE(18),
    [sym_type_usage] = STATE(18),
    [sym_keyword] = STATE(18),
    [sym_terminator] = STATE(18),
    [sym_type_keyword] = STATE(18),
    [sym_modifier] = STATE(18),
    [sym_boolean] = STATE(18),
    [sym_operator] = STATE(18),
    [sym_punctuation] = STATE(18),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(47),
    [sym_identifier] = ACTIONS(7),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(9),
    [anon_sym_EQ_EQ] = ACTIONS(9),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(11),
    [anon_sym_DOT] = ACTIONS(13),
    [anon_sym_EQ_GT] = ACTIONS(13),
    [anon_sym_PIPE] = ACTIONS(15),
    [anon_sym_PIPE_GT] = ACTIONS(17),
    [anon_sym_COLON_COLON] = ACTIONS(9),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(19),
    [anon_sym_fn] = ACTIONS(21),
    [anon_sym_DOLLAR] = ACTIONS(19),
    [anon_sym_LT_LT] = ACTIONS(19),
    [sym_type_identifier] = ACTIONS(23),
    [anon_sym__] = ACTIONS(25),
    [anon_sym_PERCENT] = ACTIONS(27),
    [anon_sym_POUND] = ACTIONS(27),
    [anon_sym_new] = ACTIONS(29),
    [anon_sym_old] = ACTIONS(29),
    [anon_sym_heap] = ACTIONS(29),
    [anon_sym_const] = ACTIONS(29),
    [anon_sym_if] = ACTIONS(29),
    [anon_sym_else] = ACTIONS(29),
    [anon_sym_while] = ACTIONS(29),
    [anon_sym_for] = ACTIONS(29),
    [anon_sym_in] = ACTIONS(29),
    [anon_sym_switch] = ACTIONS(29),
    [anon_sym_case] = ACTIONS(29),
    [anon_sym_fail] = ACTIONS(29),
    [anon_sym_sec] = ACTIONS(29),
    [anon_sym_pkg] = ACTIONS(29),
    [anon_sym_use] = ACTIONS(29),
    [anon_sym_package] = ACTIONS(29),
    [anon_sym_default] = ACTIONS(29),
    [anon_sym_struct] = ACTIONS(29),
    [anon_sym_type] = ACTIONS(29),
    [anon_sym_interface] = ACTIONS(29),
    [anon_sym_alias] = ACTIONS(29),
    [anon_sym_enum] = ACTIONS(29),
    [anon_sym_prop] = ACTIONS(29),
    [anon_sym_impl] = ACTIONS(29),
    [anon_sym_return] = ACTIONS(31),
    [anon_sym_yield] = ACTIONS(31),
    [anon_sym_cascade] = ACTIONS(31),
    [anon_sym_break] = ACTIONS(31),
    [anon_sym_loop] = ACTIONS(31),
    [anon_sym_void] = ACTIONS(33),
    [anon_sym_int] = ACTIONS(33),
    [anon_sym_char] = ACTIONS(33),
    [anon_sym_bool] = ACTIONS(33),
    [anon_sym_float] = ACTIONS(33),
    [anon_sym_range] = ACTIONS(33),
    [anon_sym_list] = ACTIONS(33),
    [anon_sym_string] = ACTIONS(33),
    [anon_sym_line] = ACTIONS(33),
    [anon_sym_word] = ACTIONS(33),
    [anon_sym_Program] = ACTIONS(33),
    [anon_sym_Embedded] = ACTIONS(33),
    [anon_sym_Self] = ACTIONS(33),
    [anon_sym_Type] = ACTIONS(33),
    [anon_sym_Field] = ACTIONS(33),
    [anon_sym_Variable] = ACTIONS(33),
    [anon_sym_into] = ACTIONS(35),
    [anon_sym_fun] = ACTIONS(35),
    [anon_sym_may] = ACTIONS(35),
    [anon_sym_itr] = ACTIONS(35),
    [anon_sym_err] = ACTIONS(35),
    [anon_sym_ark] = ACTIONS(35),
    [anon_sym_ptr] = ACTIONS(35),
    [anon_sym_mut] = ACTIONS(35),
    [anon_sym_ref] = ACTIONS(35),
    [anon_sym_true] = ACTIONS(37),
    [anon_sym_false] = ACTIONS(37),
    [anon_sym_LT_DASH] = ACTIONS(19),
    [anon_sym_DASH_GT] = ACTIONS(19),
    [anon_sym_QMARK_QMARK] = ACTIONS(19),
    [anon_sym____] = ACTIONS(9),
    [anon_sym_BANG_EQ] = ACTIONS(19),
    [anon_sym_LT] = ACTIONS(9),
    [anon_sym_GT] = ACTIONS(9),
    [anon_sym_LT_EQ] = ACTIONS(19),
    [anon_sym_GT_EQ] = ACTIONS(19),
    [anon_sym_PLUS] = ACTIONS(19),
    [anon_sym_DASH] = ACTIONS(9),
    [anon_sym_STAR] = ACTIONS(19),
    [anon_sym_SLASH] = ACTIONS(9),
    [anon_sym_CARET] = ACTIONS(19),
    [anon_sym_BANG] = ACTIONS(9),
    [anon_sym_TILDE] = ACTIONS(19),
    [anon_sym_AMP] = ACTIONS(19),
    [anon_sym_BSLASH] = ACTIONS(19),
    [anon_sym_QMARK] = ACTIONS(9),
    [anon_sym_AT] = ACTIONS(19),
    [anon_sym_DASH_DASH] = ACTIONS(19),
    [anon_sym_GT_GT] = ACTIONS(19),
    [anon_sym_COLON] = ACTIONS(39),
    [anon_sym_SEMI] = ACTIONS(41),
    [anon_sym_COMMA] = ACTIONS(41),
    [anon_sym_LBRACE] = ACTIONS(41),
    [anon_sym_RBRACE] = ACTIONS(41),
    [anon_sym_LBRACK] = ACTIONS(41),
    [anon_sym_RBRACK] = ACTIONS(41),
    [anon_sym_LPAREN] = ACTIONS(41),
    [anon_sym_RPAREN] = ACTIONS(41),
    [sym_string] = ACTIONS(43),
    [sym_char] = ACTIONS(43),
    [sym_number] = ACTIONS(45),
  },
  [3] = {
    [sym_comment] = STATE(3),
    [sym__item] = STATE(21),
    [sym_documentation] = STATE(18),
    [sym_field] = STATE(18),
    [sym_procedure_definition] = STATE(18),
    [sym_func_usage] = STATE(18),
    [sym_pipe_usage] = STATE(18),
    [sym_type_usage] = STATE(18),
    [sym_keyword] = STATE(18),
    [sym_terminator] = STATE(18),
    [sym_type_keyword] = STATE(18),
    [sym_modifier] = STATE(18),
    [sym_boolean] = STATE(18),
    [sym_operator] = STATE(18),
    [sym_punctuation] = STATE(18),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(49),
    [sym_identifier] = ACTIONS(51),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(54),
    [anon_sym_EQ_EQ] = ACTIONS(54),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(57),
    [anon_sym_DOT] = ACTIONS(60),
    [anon_sym_EQ_GT] = ACTIONS(60),
    [anon_sym_PIPE] = ACTIONS(63),
    [anon_sym_PIPE_GT] = ACTIONS(66),
    [anon_sym_COLON_COLON] = ACTIONS(54),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(69),
    [anon_sym_fn] = ACTIONS(72),
    [anon_sym_DOLLAR] = ACTIONS(69),
    [anon_sym_LT_LT] = ACTIONS(69),
    [sym_type_identifier] = ACTIONS(75),
    [anon_sym__] = ACTIONS(78),
    [anon_sym_PERCENT] = ACTIONS(81),
    [anon_sym_POUND] = ACTIONS(81),
    [anon_sym_new] = ACTIONS(84),
    [anon_sym_old] = ACTIONS(84),
    [anon_sym_heap] = ACTIONS(84),
    [anon_sym_const] = ACTIONS(84),
    [anon_sym_if] = ACTIONS(84),
    [anon_sym_else] = ACTIONS(84),
    [anon_sym_while] = ACTIONS(84),
    [anon_sym_for] = ACTIONS(84),
    [anon_sym_in] = ACTIONS(84),
    [anon_sym_switch] = ACTIONS(84),
    [anon_sym_case] = ACTIONS(84),
    [anon_sym_fail] = ACTIONS(84),
    [anon_sym_sec] = ACTIONS(84),
    [anon_sym_pkg] = ACTIONS(84),
    [anon_sym_use] = ACTIONS(84),
    [anon_sym_package] = ACTIONS(84),
    [anon_sym_default] = ACTIONS(84),
    [anon_sym_struct] = ACTIONS(84),
    [anon_sym_type] = ACTIONS(84),
    [anon_sym_interface] = ACTIONS(84),
    [anon_sym_alias] = ACTIONS(84),
    [anon_sym_enum] = ACTIONS(84),
    [anon_sym_prop] = ACTIONS(84),
    [anon_sym_impl] = ACTIONS(84),
    [anon_sym_return] = ACTIONS(87),
    [anon_sym_yield] = ACTIONS(87),
    [anon_sym_cascade] = ACTIONS(87),
    [anon_sym_break] = ACTIONS(87),
    [anon_sym_loop] = ACTIONS(87),
    [anon_sym_void] = ACTIONS(90),
    [anon_sym_int] = ACTIONS(90),
    [anon_sym_char] = ACTIONS(90),
    [anon_sym_bool] = ACTIONS(90),
    [anon_sym_float] = ACTIONS(90),
    [anon_sym_range] = ACTIONS(90),
    [anon_sym_list] = ACTIONS(90),
    [anon_sym_string] = ACTIONS(90),
    [anon_sym_line] = ACTIONS(90),
    [anon_sym_word] = ACTIONS(90),
    [anon_sym_Program] = ACTIONS(90),
    [anon_sym_Embedded] = ACTIONS(90),
    [anon_sym_Self] = ACTIONS(90),
    [anon_sym_Type] = ACTIONS(90),
    [anon_sym_Field] = ACTIONS(90),
    [anon_sym_Variable] = ACTIONS(90),
    [anon_sym_into] = ACTIONS(93),
    [anon_sym_fun] = ACTIONS(93),
    [anon_sym_may] = ACTIONS(93),
    [anon_sym_itr] = ACTIONS(93),
    [anon_sym_err] = ACTIONS(93),
    [anon_sym_ark] = ACTIONS(93),
    [anon_sym_ptr] = ACTIONS(93),
    [anon_sym_mut] = ACTIONS(93),
    [anon_sym_ref] = ACTIONS(93),
    [anon_sym_true] = ACTIONS(96),
    [anon_sym_false] = ACTIONS(96),
    [anon_sym_LT_DASH] = ACTIONS(69),
    [anon_sym_DASH_GT] = ACTIONS(69),
    [anon_sym_QMARK_QMARK] = ACTIONS(69),
    [anon_sym____] = ACTIONS(54),
    [anon_sym_BANG_EQ] = ACTIONS(69),
    [anon_sym_LT] = ACTIONS(54),
    [anon_sym_GT] = ACTIONS(54),
    [anon_sym_LT_EQ] = ACTIONS(69),
    [anon_sym_GT_EQ] = ACTIONS(69),
    [anon_sym_PLUS] = ACTIONS(69),
    [anon_sym_DASH] = ACTIONS(54),
    [anon_sym_STAR] = ACTIONS(69),
    [anon_sym_SLASH] = ACTIONS(54),
    [anon_sym_CARET] = ACTIONS(69),
    [anon_sym_BANG] = ACTIONS(54),
    [anon_sym_TILDE] = ACTIONS(69),
    [anon_sym_AMP] = ACTIONS(69),
    [anon_sym_BSLASH] = ACTIONS(69),
    [anon_sym_QMARK] = ACTIONS(54),
    [anon_sym_AT] = ACTIONS(69),
    [anon_sym_DASH_DASH] = ACTIONS(69),
    [anon_sym_GT_GT] = ACTIONS(69),
    [anon_sym_COLON] = ACTIONS(99),
    [anon_sym_SEMI] = ACTIONS(102),
    [anon_sym_COMMA] = ACTIONS(102),
    [anon_sym_LBRACE] = ACTIONS(102),
    [anon_sym_RBRACE] = ACTIONS(102),
    [anon_sym_LBRACK] = ACTIONS(102),
    [anon_sym_RBRACK] = ACTIONS(102),
    [anon_sym_LPAREN] = ACTIONS(102),
    [anon_sym_RPAREN] = ACTIONS(102),
    [sym_string] = ACTIONS(105),
    [sym_char] = ACTIONS(105),
    [sym_number] = ACTIONS(108),
  },
  [4] = {
    [sym_comment] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(111),
    [sym_identifier] = ACTIONS(113),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(113),
    [anon_sym_EQ_EQ] = ACTIONS(113),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(111),
    [anon_sym_DOT] = ACTIONS(111),
    [anon_sym_EQ_GT] = ACTIONS(111),
    [anon_sym_PIPE] = ACTIONS(113),
    [anon_sym_PIPE_GT] = ACTIONS(111),
    [anon_sym_COLON_COLON] = ACTIONS(115),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(117),
    [anon_sym_fn] = ACTIONS(113),
    [anon_sym_DOLLAR] = ACTIONS(111),
    [anon_sym_LT_LT] = ACTIONS(111),
    [sym_type_identifier] = ACTIONS(113),
    [anon_sym__] = ACTIONS(113),
    [anon_sym_PERCENT] = ACTIONS(111),
    [anon_sym_POUND] = ACTIONS(111),
    [anon_sym_new] = ACTIONS(113),
    [anon_sym_old] = ACTIONS(113),
    [anon_sym_heap] = ACTIONS(113),
    [anon_sym_const] = ACTIONS(113),
    [anon_sym_if] = ACTIONS(113),
    [anon_sym_else] = ACTIONS(113),
    [anon_sym_while] = ACTIONS(113),
    [anon_sym_for] = ACTIONS(113),
    [anon_sym_in] = ACTIONS(113),
    [anon_sym_switch] = ACTIONS(113),
    [anon_sym_case] = ACTIONS(113),
    [anon_sym_fail] = ACTIONS(113),
    [anon_sym_sec] = ACTIONS(113),
    [anon_sym_pkg] = ACTIONS(113),
    [anon_sym_use] = ACTIONS(113),
    [anon_sym_package] = ACTIONS(113),
    [anon_sym_default] = ACTIONS(113),
    [anon_sym_struct] = ACTIONS(113),
    [anon_sym_type] = ACTIONS(113),
    [anon_sym_interface] = ACTIONS(113),
    [anon_sym_alias] = ACTIONS(113),
    [anon_sym_enum] = ACTIONS(113),
    [anon_sym_prop] = ACTIONS(113),
    [anon_sym_impl] = ACTIONS(113),
    [anon_sym_return] = ACTIONS(113),
    [anon_sym_yield] = ACTIONS(113),
    [anon_sym_cascade] = ACTIONS(113),
    [anon_sym_break] = ACTIONS(113),
    [anon_sym_loop] = ACTIONS(113),
    [anon_sym_void] = ACTIONS(113),
    [anon_sym_int] = ACTIONS(113),
    [anon_sym_char] = ACTIONS(113),
    [anon_sym_bool] = ACTIONS(113),
    [anon_sym_float] = ACTIONS(113),
    [anon_sym_range] = ACTIONS(113),
    [anon_sym_list] = ACTIONS(113),
    [anon_sym_string] = ACTIONS(113),
    [anon_sym_line] = ACTIONS(113),
    [anon_sym_word] = ACTIONS(113),
    [anon_sym_Program] = ACTIONS(113),
    [anon_sym_Embedded] = ACTIONS(113),
    [anon_sym_Self] = ACTIONS(113),
    [anon_sym_Type] = ACTIONS(113),
    [anon_sym_Field] = ACTIONS(113),
    [anon_sym_Variable] = ACTIONS(113),
    [anon_sym_into] = ACTIONS(113),
    [anon_sym_fun] = ACTIONS(113),
    [anon_sym_may] = ACTIONS(113),
    [anon_sym_itr] = ACTIONS(113),
    [anon_sym_err] = ACTIONS(113),
    [anon_sym_ark] = ACTIONS(113),
    [anon_sym_ptr] = ACTIONS(113),
    [anon_sym_mut] = ACTIONS(113),
    [anon_sym_ref] = ACTIONS(113),
    [anon_sym_true] = ACTIONS(113),
    [anon_sym_false] = ACTIONS(113),
    [anon_sym_LT_DASH] = ACTIONS(111),
    [anon_sym_DASH_GT] = ACTIONS(111),
    [anon_sym_QMARK_QMARK] = ACTIONS(111),
    [anon_sym____] = ACTIONS(113),
    [anon_sym_BANG_EQ] = ACTIONS(111),
    [anon_sym_LT] = ACTIONS(113),
    [anon_sym_GT] = ACTIONS(113),
    [anon_sym_LT_EQ] = ACTIONS(111),
    [anon_sym_GT_EQ] = ACTIONS(111),
    [anon_sym_PLUS] = ACTIONS(111),
    [anon_sym_DASH] = ACTIONS(113),
    [anon_sym_STAR] = ACTIONS(111),
    [anon_sym_SLASH] = ACTIONS(113),
    [anon_sym_CARET] = ACTIONS(111),
    [anon_sym_BANG] = ACTIONS(113),
    [anon_sym_TILDE] = ACTIONS(111),
    [anon_sym_AMP] = ACTIONS(111),
    [anon_sym_BSLASH] = ACTIONS(111),
    [anon_sym_QMARK] = ACTIONS(113),
    [anon_sym_AT] = ACTIONS(111),
    [anon_sym_DASH_DASH] = ACTIONS(111),
    [anon_sym_GT_GT] = ACTIONS(111),
    [anon_sym_COLON] = ACTIONS(113),
    [anon_sym_SEMI] = ACTIONS(111),
    [anon_sym_COMMA] = ACTIONS(111),
    [anon_sym_LBRACE] = ACTIONS(111),
    [anon_sym_RBRACE] = ACTIONS(111),
    [anon_sym_LBRACK] = ACTIONS(111),
    [anon_sym_RBRACK] = ACTIONS(111),
    [anon_sym_LPAREN] = ACTIONS(111),
    [anon_sym_RPAREN] = ACTIONS(111),
    [sym_string] = ACTIONS(111),
    [sym_char] = ACTIONS(111),
    [sym_number] = ACTIONS(113),
  },
  [5] = {
    [sym_comment] = STATE(5),
    [ts_builtin_sym_end] = ACTIONS(119),
    [sym_identifier] = ACTIONS(121),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(121),
    [anon_sym_EQ_EQ] = ACTIONS(121),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(119),
    [anon_sym_DOT] = ACTIONS(119),
    [anon_sym_EQ_GT] = ACTIONS(119),
    [anon_sym_PIPE] = ACTIONS(121),
    [anon_sym_PIPE_GT] = ACTIONS(119),
    [anon_sym_COLON_COLON] = ACTIONS(123),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(125),
    [anon_sym_fn] = ACTIONS(121),
    [anon_sym_DOLLAR] = ACTIONS(127),
    [anon_sym_LT_LT] = ACTIONS(127),
    [sym_type_identifier] = ACTIONS(121),
    [anon_sym__] = ACTIONS(121),
    [anon_sym_PERCENT] = ACTIONS(119),
    [anon_sym_POUND] = ACTIONS(119),
    [anon_sym_new] = ACTIONS(121),
    [anon_sym_old] = ACTIONS(121),
    [anon_sym_heap] = ACTIONS(121),
    [anon_sym_const] = ACTIONS(121),
    [anon_sym_if] = ACTIONS(121),
    [anon_sym_else] = ACTIONS(121),
    [anon_sym_while] = ACTIONS(121),
    [anon_sym_for] = ACTIONS(121),
    [anon_sym_in] = ACTIONS(121),
    [anon_sym_switch] = ACTIONS(121),
    [anon_sym_case] = ACTIONS(121),
    [anon_sym_fail] = ACTIONS(121),
    [anon_sym_sec] = ACTIONS(121),
    [anon_sym_pkg] = ACTIONS(121),
    [anon_sym_use] = ACTIONS(121),
    [anon_sym_package] = ACTIONS(121),
    [anon_sym_default] = ACTIONS(121),
    [anon_sym_struct] = ACTIONS(121),
    [anon_sym_type] = ACTIONS(121),
    [anon_sym_interface] = ACTIONS(121),
    [anon_sym_alias] = ACTIONS(121),
    [anon_sym_enum] = ACTIONS(121),
    [anon_sym_prop] = ACTIONS(121),
    [anon_sym_impl] = ACTIONS(121),
    [anon_sym_return] = ACTIONS(121),
    [anon_sym_yield] = ACTIONS(121),
    [anon_sym_cascade] = ACTIONS(121),
    [anon_sym_break] = ACTIONS(121),
    [anon_sym_loop] = ACTIONS(121),
    [anon_sym_void] = ACTIONS(121),
    [anon_sym_int] = ACTIONS(121),
    [anon_sym_char] = ACTIONS(121),
    [anon_sym_bool] = ACTIONS(121),
    [anon_sym_float] = ACTIONS(121),
    [anon_sym_range] = ACTIONS(121),
    [anon_sym_list] = ACTIONS(121),
    [anon_sym_string] = ACTIONS(121),
    [anon_sym_line] = ACTIONS(121),
    [anon_sym_word] = ACTIONS(121),
    [anon_sym_Program] = ACTIONS(121),
    [anon_sym_Embedded] = ACTIONS(121),
    [anon_sym_Self] = ACTIONS(121),
    [anon_sym_Type] = ACTIONS(121),
    [anon_sym_Field] = ACTIONS(121),
    [anon_sym_Variable] = ACTIONS(121),
    [anon_sym_into] = ACTIONS(121),
    [anon_sym_fun] = ACTIONS(121),
    [anon_sym_may] = ACTIONS(121),
    [anon_sym_itr] = ACTIONS(121),
    [anon_sym_err] = ACTIONS(121),
    [anon_sym_ark] = ACTIONS(121),
    [anon_sym_ptr] = ACTIONS(121),
    [anon_sym_mut] = ACTIONS(121),
    [anon_sym_ref] = ACTIONS(121),
    [anon_sym_true] = ACTIONS(121),
    [anon_sym_false] = ACTIONS(121),
    [anon_sym_LT_DASH] = ACTIONS(119),
    [anon_sym_DASH_GT] = ACTIONS(119),
    [anon_sym_QMARK_QMARK] = ACTIONS(119),
    [anon_sym____] = ACTIONS(121),
    [anon_sym_BANG_EQ] = ACTIONS(119),
    [anon_sym_LT] = ACTIONS(121),
    [anon_sym_GT] = ACTIONS(121),
    [anon_sym_LT_EQ] = ACTIONS(119),
    [anon_sym_GT_EQ] = ACTIONS(119),
    [anon_sym_PLUS] = ACTIONS(119),
    [anon_sym_DASH] = ACTIONS(121),
    [anon_sym_STAR] = ACTIONS(119),
    [anon_sym_SLASH] = ACTIONS(121),
    [anon_sym_CARET] = ACTIONS(119),
    [anon_sym_BANG] = ACTIONS(121),
    [anon_sym_TILDE] = ACTIONS(119),
    [anon_sym_AMP] = ACTIONS(119),
    [anon_sym_BSLASH] = ACTIONS(119),
    [anon_sym_QMARK] = ACTIONS(121),
    [anon_sym_AT] = ACTIONS(119),
    [anon_sym_DASH_DASH] = ACTIONS(119),
    [anon_sym_GT_GT] = ACTIONS(119),
    [anon_sym_COLON] = ACTIONS(121),
    [anon_sym_SEMI] = ACTIONS(119),
    [anon_sym_COMMA] = ACTIONS(119),
    [anon_sym_LBRACE] = ACTIONS(119),
    [anon_sym_RBRACE] = ACTIONS(119),
    [anon_sym_LBRACK] = ACTIONS(119),
    [anon_sym_RBRACK] = ACTIONS(119),
    [anon_sym_LPAREN] = ACTIONS(119),
    [anon_sym_RPAREN] = ACTIONS(119),
    [sym_string] = ACTIONS(119),
    [sym_char] = ACTIONS(119),
    [sym_number] = ACTIONS(121),
  },
  [6] = {
    [sym_comment] = STATE(6),
    [ts_builtin_sym_end] = ACTIONS(129),
    [sym_identifier] = ACTIONS(131),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(133),
    [anon_sym_EQ_EQ] = ACTIONS(133),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(129),
    [anon_sym_DOT] = ACTIONS(129),
    [anon_sym_EQ_GT] = ACTIONS(129),
    [anon_sym_PIPE] = ACTIONS(133),
    [anon_sym_PIPE_GT] = ACTIONS(129),
    [anon_sym_COLON_COLON] = ACTIONS(133),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(129),
    [anon_sym_fn] = ACTIONS(133),
    [anon_sym_DOLLAR] = ACTIONS(129),
    [anon_sym_LT_LT] = ACTIONS(129),
    [sym_type_identifier] = ACTIONS(133),
    [anon_sym__] = ACTIONS(133),
    [anon_sym_PERCENT] = ACTIONS(129),
    [anon_sym_POUND] = ACTIONS(129),
    [anon_sym_new] = ACTIONS(133),
    [anon_sym_old] = ACTIONS(133),
    [anon_sym_heap] = ACTIONS(133),
    [anon_sym_const] = ACTIONS(133),
    [anon_sym_if] = ACTIONS(133),
    [anon_sym_else] = ACTIONS(133),
    [anon_sym_while] = ACTIONS(133),
    [anon_sym_for] = ACTIONS(133),
    [anon_sym_in] = ACTIONS(133),
    [anon_sym_switch] = ACTIONS(133),
    [anon_sym_case] = ACTIONS(133),
    [anon_sym_fail] = ACTIONS(133),
    [anon_sym_sec] = ACTIONS(133),
    [anon_sym_pkg] = ACTIONS(133),
    [anon_sym_use] = ACTIONS(133),
    [anon_sym_package] = ACTIONS(133),
    [anon_sym_default] = ACTIONS(133),
    [anon_sym_struct] = ACTIONS(133),
    [anon_sym_type] = ACTIONS(133),
    [anon_sym_interface] = ACTIONS(133),
    [anon_sym_alias] = ACTIONS(133),
    [anon_sym_enum] = ACTIONS(133),
    [anon_sym_prop] = ACTIONS(133),
    [anon_sym_impl] = ACTIONS(133),
    [anon_sym_return] = ACTIONS(133),
    [anon_sym_yield] = ACTIONS(133),
    [anon_sym_cascade] = ACTIONS(133),
    [anon_sym_break] = ACTIONS(133),
    [anon_sym_loop] = ACTIONS(133),
    [anon_sym_void] = ACTIONS(133),
    [anon_sym_int] = ACTIONS(133),
    [anon_sym_char] = ACTIONS(133),
    [anon_sym_bool] = ACTIONS(133),
    [anon_sym_float] = ACTIONS(133),
    [anon_sym_range] = ACTIONS(133),
    [anon_sym_list] = ACTIONS(133),
    [anon_sym_string] = ACTIONS(133),
    [anon_sym_line] = ACTIONS(133),
    [anon_sym_word] = ACTIONS(133),
    [anon_sym_Program] = ACTIONS(133),
    [anon_sym_Embedded] = ACTIONS(133),
    [anon_sym_Self] = ACTIONS(133),
    [anon_sym_Type] = ACTIONS(133),
    [anon_sym_Field] = ACTIONS(133),
    [anon_sym_Variable] = ACTIONS(133),
    [anon_sym_into] = ACTIONS(133),
    [anon_sym_fun] = ACTIONS(133),
    [anon_sym_may] = ACTIONS(133),
    [anon_sym_itr] = ACTIONS(133),
    [anon_sym_err] = ACTIONS(133),
    [anon_sym_ark] = ACTIONS(133),
    [anon_sym_ptr] = ACTIONS(133),
    [anon_sym_mut] = ACTIONS(133),
    [anon_sym_ref] = ACTIONS(133),
    [anon_sym_true] = ACTIONS(133),
    [anon_sym_false] = ACTIONS(133),
    [anon_sym_LT_DASH] = ACTIONS(129),
    [anon_sym_DASH_GT] = ACTIONS(129),
    [anon_sym_QMARK_QMARK] = ACTIONS(129),
    [anon_sym____] = ACTIONS(133),
    [anon_sym_BANG_EQ] = ACTIONS(129),
    [anon_sym_LT] = ACTIONS(133),
    [anon_sym_GT] = ACTIONS(133),
    [anon_sym_LT_EQ] = ACTIONS(129),
    [anon_sym_GT_EQ] = ACTIONS(129),
    [anon_sym_PLUS] = ACTIONS(129),
    [anon_sym_DASH] = ACTIONS(133),
    [anon_sym_STAR] = ACTIONS(129),
    [anon_sym_SLASH] = ACTIONS(133),
    [anon_sym_CARET] = ACTIONS(129),
    [anon_sym_BANG] = ACTIONS(133),
    [anon_sym_TILDE] = ACTIONS(129),
    [anon_sym_AMP] = ACTIONS(129),
    [anon_sym_BSLASH] = ACTIONS(129),
    [anon_sym_QMARK] = ACTIONS(133),
    [anon_sym_AT] = ACTIONS(129),
    [anon_sym_DASH_DASH] = ACTIONS(129),
    [anon_sym_GT_GT] = ACTIONS(129),
    [anon_sym_COLON] = ACTIONS(133),
    [anon_sym_SEMI] = ACTIONS(129),
    [anon_sym_COMMA] = ACTIONS(129),
    [anon_sym_LBRACE] = ACTIONS(129),
    [anon_sym_RBRACE] = ACTIONS(129),
    [anon_sym_LBRACK] = ACTIONS(129),
    [anon_sym_RBRACK] = ACTIONS(129),
    [anon_sym_LPAREN] = ACTIONS(129),
    [anon_sym_RPAREN] = ACTIONS(129),
    [sym_string] = ACTIONS(129),
    [sym_char] = ACTIONS(129),
    [sym_number] = ACTIONS(133),
  },
  [7] = {
    [sym_comment] = STATE(7),
    [ts_builtin_sym_end] = ACTIONS(135),
    [sym_identifier] = ACTIONS(137),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(139),
    [anon_sym_EQ_EQ] = ACTIONS(139),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(135),
    [anon_sym_DOT] = ACTIONS(135),
    [anon_sym_EQ_GT] = ACTIONS(135),
    [anon_sym_PIPE] = ACTIONS(139),
    [anon_sym_PIPE_GT] = ACTIONS(135),
    [anon_sym_COLON_COLON] = ACTIONS(139),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(135),
    [anon_sym_fn] = ACTIONS(139),
    [anon_sym_DOLLAR] = ACTIONS(135),
    [anon_sym_LT_LT] = ACTIONS(135),
    [sym_type_identifier] = ACTIONS(139),
    [anon_sym__] = ACTIONS(139),
    [anon_sym_PERCENT] = ACTIONS(135),
    [anon_sym_POUND] = ACTIONS(135),
    [anon_sym_new] = ACTIONS(139),
    [anon_sym_old] = ACTIONS(139),
    [anon_sym_heap] = ACTIONS(139),
    [anon_sym_const] = ACTIONS(139),
    [anon_sym_if] = ACTIONS(139),
    [anon_sym_else] = ACTIONS(139),
    [anon_sym_while] = ACTIONS(139),
    [anon_sym_for] = ACTIONS(139),
    [anon_sym_in] = ACTIONS(139),
    [anon_sym_switch] = ACTIONS(139),
    [anon_sym_case] = ACTIONS(139),
    [anon_sym_fail] = ACTIONS(139),
    [anon_sym_sec] = ACTIONS(139),
    [anon_sym_pkg] = ACTIONS(139),
    [anon_sym_use] = ACTIONS(139),
    [anon_sym_package] = ACTIONS(139),
    [anon_sym_default] = ACTIONS(139),
    [anon_sym_struct] = ACTIONS(139),
    [anon_sym_type] = ACTIONS(139),
    [anon_sym_interface] = ACTIONS(139),
    [anon_sym_alias] = ACTIONS(139),
    [anon_sym_enum] = ACTIONS(139),
    [anon_sym_prop] = ACTIONS(139),
    [anon_sym_impl] = ACTIONS(139),
    [anon_sym_return] = ACTIONS(139),
    [anon_sym_yield] = ACTIONS(139),
    [anon_sym_cascade] = ACTIONS(139),
    [anon_sym_break] = ACTIONS(139),
    [anon_sym_loop] = ACTIONS(139),
    [anon_sym_void] = ACTIONS(139),
    [anon_sym_int] = ACTIONS(139),
    [anon_sym_char] = ACTIONS(139),
    [anon_sym_bool] = ACTIONS(139),
    [anon_sym_float] = ACTIONS(139),
    [anon_sym_range] = ACTIONS(139),
    [anon_sym_list] = ACTIONS(139),
    [anon_sym_string] = ACTIONS(139),
    [anon_sym_line] = ACTIONS(139),
    [anon_sym_word] = ACTIONS(139),
    [anon_sym_Program] = ACTIONS(139),
    [anon_sym_Embedded] = ACTIONS(139),
    [anon_sym_Self] = ACTIONS(139),
    [anon_sym_Type] = ACTIONS(139),
    [anon_sym_Field] = ACTIONS(139),
    [anon_sym_Variable] = ACTIONS(139),
    [anon_sym_into] = ACTIONS(139),
    [anon_sym_fun] = ACTIONS(139),
    [anon_sym_may] = ACTIONS(139),
    [anon_sym_itr] = ACTIONS(139),
    [anon_sym_err] = ACTIONS(139),
    [anon_sym_ark] = ACTIONS(139),
    [anon_sym_ptr] = ACTIONS(139),
    [anon_sym_mut] = ACTIONS(139),
    [anon_sym_ref] = ACTIONS(139),
    [anon_sym_true] = ACTIONS(139),
    [anon_sym_false] = ACTIONS(139),
    [anon_sym_LT_DASH] = ACTIONS(135),
    [anon_sym_DASH_GT] = ACTIONS(135),
    [anon_sym_QMARK_QMARK] = ACTIONS(135),
    [anon_sym____] = ACTIONS(139),
    [anon_sym_BANG_EQ] = ACTIONS(135),
    [anon_sym_LT] = ACTIONS(139),
    [anon_sym_GT] = ACTIONS(139),
    [anon_sym_LT_EQ] = ACTIONS(135),
    [anon_sym_GT_EQ] = ACTIONS(135),
    [anon_sym_PLUS] = ACTIONS(135),
    [anon_sym_DASH] = ACTIONS(139),
    [anon_sym_STAR] = ACTIONS(135),
    [anon_sym_SLASH] = ACTIONS(139),
    [anon_sym_CARET] = ACTIONS(135),
    [anon_sym_BANG] = ACTIONS(139),
    [anon_sym_TILDE] = ACTIONS(135),
    [anon_sym_AMP] = ACTIONS(135),
    [anon_sym_BSLASH] = ACTIONS(135),
    [anon_sym_QMARK] = ACTIONS(139),
    [anon_sym_AT] = ACTIONS(135),
    [anon_sym_DASH_DASH] = ACTIONS(135),
    [anon_sym_GT_GT] = ACTIONS(135),
    [anon_sym_COLON] = ACTIONS(139),
    [anon_sym_SEMI] = ACTIONS(135),
    [anon_sym_COMMA] = ACTIONS(135),
    [anon_sym_LBRACE] = ACTIONS(135),
    [anon_sym_RBRACE] = ACTIONS(135),
    [anon_sym_LBRACK] = ACTIONS(135),
    [anon_sym_RBRACK] = ACTIONS(135),
    [anon_sym_LPAREN] = ACTIONS(135),
    [anon_sym_RPAREN] = ACTIONS(135),
    [sym_string] = ACTIONS(135),
    [sym_char] = ACTIONS(135),
    [sym_number] = ACTIONS(139),
  },
  [8] = {
    [sym_comment] = STATE(8),
    [ts_builtin_sym_end] = ACTIONS(141),
    [sym_identifier] = ACTIONS(143),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(143),
    [anon_sym_EQ_EQ] = ACTIONS(143),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(141),
    [anon_sym_DOT] = ACTIONS(141),
    [anon_sym_EQ_GT] = ACTIONS(141),
    [anon_sym_PIPE] = ACTIONS(143),
    [anon_sym_PIPE_GT] = ACTIONS(141),
    [anon_sym_COLON_COLON] = ACTIONS(143),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(141),
    [anon_sym_fn] = ACTIONS(143),
    [anon_sym_DOLLAR] = ACTIONS(141),
    [anon_sym_LT_LT] = ACTIONS(141),
    [sym_type_identifier] = ACTIONS(143),
    [anon_sym__] = ACTIONS(143),
    [anon_sym_PERCENT] = ACTIONS(141),
    [anon_sym_POUND] = ACTIONS(141),
    [anon_sym_new] = ACTIONS(143),
    [anon_sym_old] = ACTIONS(143),
    [anon_sym_heap] = ACTIONS(143),
    [anon_sym_const] = ACTIONS(143),
    [anon_sym_if] = ACTIONS(143),
    [anon_sym_else] = ACTIONS(143),
    [anon_sym_while] = ACTIONS(143),
    [anon_sym_for] = ACTIONS(143),
    [anon_sym_in] = ACTIONS(143),
    [anon_sym_switch] = ACTIONS(143),
    [anon_sym_case] = ACTIONS(143),
    [anon_sym_fail] = ACTIONS(143),
    [anon_sym_sec] = ACTIONS(143),
    [anon_sym_pkg] = ACTIONS(143),
    [anon_sym_use] = ACTIONS(143),
    [anon_sym_package] = ACTIONS(143),
    [anon_sym_default] = ACTIONS(143),
    [anon_sym_struct] = ACTIONS(143),
    [anon_sym_type] = ACTIONS(143),
    [anon_sym_interface] = ACTIONS(143),
    [anon_sym_alias] = ACTIONS(143),
    [anon_sym_enum] = ACTIONS(143),
    [anon_sym_prop] = ACTIONS(143),
    [anon_sym_impl] = ACTIONS(143),
    [anon_sym_return] = ACTIONS(143),
    [anon_sym_yield] = ACTIONS(143),
    [anon_sym_cascade] = ACTIONS(143),
    [anon_sym_break] = ACTIONS(143),
    [anon_sym_loop] = ACTIONS(143),
    [anon_sym_void] = ACTIONS(143),
    [anon_sym_int] = ACTIONS(143),
    [anon_sym_char] = ACTIONS(143),
    [anon_sym_bool] = ACTIONS(143),
    [anon_sym_float] = ACTIONS(143),
    [anon_sym_range] = ACTIONS(143),
    [anon_sym_list] = ACTIONS(143),
    [anon_sym_string] = ACTIONS(143),
    [anon_sym_line] = ACTIONS(143),
    [anon_sym_word] = ACTIONS(143),
    [anon_sym_Program] = ACTIONS(143),
    [anon_sym_Embedded] = ACTIONS(143),
    [anon_sym_Self] = ACTIONS(143),
    [anon_sym_Type] = ACTIONS(143),
    [anon_sym_Field] = ACTIONS(143),
    [anon_sym_Variable] = ACTIONS(143),
    [anon_sym_into] = ACTIONS(143),
    [anon_sym_fun] = ACTIONS(143),
    [anon_sym_may] = ACTIONS(143),
    [anon_sym_itr] = ACTIONS(143),
    [anon_sym_err] = ACTIONS(143),
    [anon_sym_ark] = ACTIONS(143),
    [anon_sym_ptr] = ACTIONS(143),
    [anon_sym_mut] = ACTIONS(143),
    [anon_sym_ref] = ACTIONS(143),
    [anon_sym_true] = ACTIONS(143),
    [anon_sym_false] = ACTIONS(143),
    [anon_sym_LT_DASH] = ACTIONS(141),
    [anon_sym_DASH_GT] = ACTIONS(141),
    [anon_sym_QMARK_QMARK] = ACTIONS(141),
    [anon_sym____] = ACTIONS(143),
    [anon_sym_BANG_EQ] = ACTIONS(141),
    [anon_sym_LT] = ACTIONS(143),
    [anon_sym_GT] = ACTIONS(143),
    [anon_sym_LT_EQ] = ACTIONS(141),
    [anon_sym_GT_EQ] = ACTIONS(141),
    [anon_sym_PLUS] = ACTIONS(141),
    [anon_sym_DASH] = ACTIONS(143),
    [anon_sym_STAR] = ACTIONS(141),
    [anon_sym_SLASH] = ACTIONS(143),
    [anon_sym_CARET] = ACTIONS(141),
    [anon_sym_BANG] = ACTIONS(143),
    [anon_sym_TILDE] = ACTIONS(141),
    [anon_sym_AMP] = ACTIONS(141),
    [anon_sym_BSLASH] = ACTIONS(141),
    [anon_sym_QMARK] = ACTIONS(143),
    [anon_sym_AT] = ACTIONS(141),
    [anon_sym_DASH_DASH] = ACTIONS(141),
    [anon_sym_GT_GT] = ACTIONS(141),
    [anon_sym_COLON] = ACTIONS(143),
    [anon_sym_SEMI] = ACTIONS(141),
    [anon_sym_COMMA] = ACTIONS(141),
    [anon_sym_LBRACE] = ACTIONS(141),
    [anon_sym_RBRACE] = ACTIONS(141),
    [anon_sym_LBRACK] = ACTIONS(141),
    [anon_sym_RBRACK] = ACTIONS(141),
    [anon_sym_LPAREN] = ACTIONS(141),
    [anon_sym_RPAREN] = ACTIONS(141),
    [sym_string] = ACTIONS(141),
    [sym_char] = ACTIONS(141),
    [sym_number] = ACTIONS(143),
  },
  [9] = {
    [sym_comment] = STATE(9),
    [ts_builtin_sym_end] = ACTIONS(145),
    [sym_identifier] = ACTIONS(147),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(147),
    [anon_sym_EQ_EQ] = ACTIONS(147),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(145),
    [anon_sym_DOT] = ACTIONS(145),
    [anon_sym_EQ_GT] = ACTIONS(145),
    [anon_sym_PIPE] = ACTIONS(147),
    [anon_sym_PIPE_GT] = ACTIONS(145),
    [anon_sym_COLON_COLON] = ACTIONS(147),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(145),
    [anon_sym_fn] = ACTIONS(147),
    [anon_sym_DOLLAR] = ACTIONS(145),
    [anon_sym_LT_LT] = ACTIONS(145),
    [sym_type_identifier] = ACTIONS(147),
    [anon_sym__] = ACTIONS(147),
    [anon_sym_PERCENT] = ACTIONS(145),
    [anon_sym_POUND] = ACTIONS(145),
    [anon_sym_new] = ACTIONS(147),
    [anon_sym_old] = ACTIONS(147),
    [anon_sym_heap] = ACTIONS(147),
    [anon_sym_const] = ACTIONS(147),
    [anon_sym_if] = ACTIONS(147),
    [anon_sym_else] = ACTIONS(147),
    [anon_sym_while] = ACTIONS(147),
    [anon_sym_for] = ACTIONS(147),
    [anon_sym_in] = ACTIONS(147),
    [anon_sym_switch] = ACTIONS(147),
    [anon_sym_case] = ACTIONS(147),
    [anon_sym_fail] = ACTIONS(147),
    [anon_sym_sec] = ACTIONS(147),
    [anon_sym_pkg] = ACTIONS(147),
    [anon_sym_use] = ACTIONS(147),
    [anon_sym_package] = ACTIONS(147),
    [anon_sym_default] = ACTIONS(147),
    [anon_sym_struct] = ACTIONS(147),
    [anon_sym_type] = ACTIONS(147),
    [anon_sym_interface] = ACTIONS(147),
    [anon_sym_alias] = ACTIONS(147),
    [anon_sym_enum] = ACTIONS(147),
    [anon_sym_prop] = ACTIONS(147),
    [anon_sym_impl] = ACTIONS(147),
    [anon_sym_return] = ACTIONS(147),
    [anon_sym_yield] = ACTIONS(147),
    [anon_sym_cascade] = ACTIONS(147),
    [anon_sym_break] = ACTIONS(147),
    [anon_sym_loop] = ACTIONS(147),
    [anon_sym_void] = ACTIONS(147),
    [anon_sym_int] = ACTIONS(147),
    [anon_sym_char] = ACTIONS(147),
    [anon_sym_bool] = ACTIONS(147),
    [anon_sym_float] = ACTIONS(147),
    [anon_sym_range] = ACTIONS(147),
    [anon_sym_list] = ACTIONS(147),
    [anon_sym_string] = ACTIONS(147),
    [anon_sym_line] = ACTIONS(147),
    [anon_sym_word] = ACTIONS(147),
    [anon_sym_Program] = ACTIONS(147),
    [anon_sym_Embedded] = ACTIONS(147),
    [anon_sym_Self] = ACTIONS(147),
    [anon_sym_Type] = ACTIONS(147),
    [anon_sym_Field] = ACTIONS(147),
    [anon_sym_Variable] = ACTIONS(147),
    [anon_sym_into] = ACTIONS(147),
    [anon_sym_fun] = ACTIONS(147),
    [anon_sym_may] = ACTIONS(147),
    [anon_sym_itr] = ACTIONS(147),
    [anon_sym_err] = ACTIONS(147),
    [anon_sym_ark] = ACTIONS(147),
    [anon_sym_ptr] = ACTIONS(147),
    [anon_sym_mut] = ACTIONS(147),
    [anon_sym_ref] = ACTIONS(147),
    [anon_sym_true] = ACTIONS(147),
    [anon_sym_false] = ACTIONS(147),
    [anon_sym_LT_DASH] = ACTIONS(145),
    [anon_sym_DASH_GT] = ACTIONS(145),
    [anon_sym_QMARK_QMARK] = ACTIONS(145),
    [anon_sym____] = ACTIONS(147),
    [anon_sym_BANG_EQ] = ACTIONS(145),
    [anon_sym_LT] = ACTIONS(147),
    [anon_sym_GT] = ACTIONS(147),
    [anon_sym_LT_EQ] = ACTIONS(145),
    [anon_sym_GT_EQ] = ACTIONS(145),
    [anon_sym_PLUS] = ACTIONS(145),
    [anon_sym_DASH] = ACTIONS(147),
    [anon_sym_STAR] = ACTIONS(145),
    [anon_sym_SLASH] = ACTIONS(147),
    [anon_sym_CARET] = ACTIONS(145),
    [anon_sym_BANG] = ACTIONS(147),
    [anon_sym_TILDE] = ACTIONS(145),
    [anon_sym_AMP] = ACTIONS(145),
    [anon_sym_BSLASH] = ACTIONS(145),
    [anon_sym_QMARK] = ACTIONS(147),
    [anon_sym_AT] = ACTIONS(145),
    [anon_sym_DASH_DASH] = ACTIONS(145),
    [anon_sym_GT_GT] = ACTIONS(145),
    [anon_sym_COLON] = ACTIONS(147),
    [anon_sym_SEMI] = ACTIONS(145),
    [anon_sym_COMMA] = ACTIONS(145),
    [anon_sym_LBRACE] = ACTIONS(145),
    [anon_sym_RBRACE] = ACTIONS(145),
    [anon_sym_LBRACK] = ACTIONS(145),
    [anon_sym_RBRACK] = ACTIONS(145),
    [anon_sym_LPAREN] = ACTIONS(145),
    [anon_sym_RPAREN] = ACTIONS(145),
    [sym_string] = ACTIONS(145),
    [sym_char] = ACTIONS(145),
    [sym_number] = ACTIONS(147),
  },
  [10] = {
    [sym_comment] = STATE(10),
    [ts_builtin_sym_end] = ACTIONS(129),
    [sym_identifier] = ACTIONS(133),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(133),
    [anon_sym_EQ_EQ] = ACTIONS(133),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(129),
    [anon_sym_DOT] = ACTIONS(129),
    [anon_sym_EQ_GT] = ACTIONS(129),
    [anon_sym_PIPE] = ACTIONS(133),
    [anon_sym_PIPE_GT] = ACTIONS(129),
    [anon_sym_COLON_COLON] = ACTIONS(133),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(129),
    [anon_sym_fn] = ACTIONS(133),
    [anon_sym_DOLLAR] = ACTIONS(129),
    [anon_sym_LT_LT] = ACTIONS(129),
    [sym_type_identifier] = ACTIONS(149),
    [anon_sym__] = ACTIONS(133),
    [anon_sym_PERCENT] = ACTIONS(129),
    [anon_sym_POUND] = ACTIONS(129),
    [anon_sym_new] = ACTIONS(133),
    [anon_sym_old] = ACTIONS(133),
    [anon_sym_heap] = ACTIONS(133),
    [anon_sym_const] = ACTIONS(133),
    [anon_sym_if] = ACTIONS(133),
    [anon_sym_else] = ACTIONS(133),
    [anon_sym_while] = ACTIONS(133),
    [anon_sym_for] = ACTIONS(133),
    [anon_sym_in] = ACTIONS(133),
    [anon_sym_switch] = ACTIONS(133),
    [anon_sym_case] = ACTIONS(133),
    [anon_sym_fail] = ACTIONS(133),
    [anon_sym_sec] = ACTIONS(133),
    [anon_sym_pkg] = ACTIONS(133),
    [anon_sym_use] = ACTIONS(133),
    [anon_sym_package] = ACTIONS(133),
    [anon_sym_default] = ACTIONS(133),
    [anon_sym_struct] = ACTIONS(133),
    [anon_sym_type] = ACTIONS(133),
    [anon_sym_interface] = ACTIONS(133),
    [anon_sym_alias] = ACTIONS(133),
    [anon_sym_enum] = ACTIONS(133),
    [anon_sym_prop] = ACTIONS(133),
    [anon_sym_impl] = ACTIONS(133),
    [anon_sym_return] = ACTIONS(133),
    [anon_sym_yield] = ACTIONS(133),
    [anon_sym_cascade] = ACTIONS(133),
    [anon_sym_break] = ACTIONS(133),
    [anon_sym_loop] = ACTIONS(133),
    [anon_sym_void] = ACTIONS(133),
    [anon_sym_int] = ACTIONS(133),
    [anon_sym_char] = ACTIONS(133),
    [anon_sym_bool] = ACTIONS(133),
    [anon_sym_float] = ACTIONS(133),
    [anon_sym_range] = ACTIONS(133),
    [anon_sym_list] = ACTIONS(133),
    [anon_sym_string] = ACTIONS(133),
    [anon_sym_line] = ACTIONS(133),
    [anon_sym_word] = ACTIONS(133),
    [anon_sym_Program] = ACTIONS(133),
    [anon_sym_Embedded] = ACTIONS(133),
    [anon_sym_Self] = ACTIONS(133),
    [anon_sym_Type] = ACTIONS(133),
    [anon_sym_Field] = ACTIONS(133),
    [anon_sym_Variable] = ACTIONS(133),
    [anon_sym_into] = ACTIONS(133),
    [anon_sym_fun] = ACTIONS(133),
    [anon_sym_may] = ACTIONS(133),
    [anon_sym_itr] = ACTIONS(133),
    [anon_sym_err] = ACTIONS(133),
    [anon_sym_ark] = ACTIONS(133),
    [anon_sym_ptr] = ACTIONS(133),
    [anon_sym_mut] = ACTIONS(133),
    [anon_sym_ref] = ACTIONS(133),
    [anon_sym_true] = ACTIONS(133),
    [anon_sym_false] = ACTIONS(133),
    [anon_sym_LT_DASH] = ACTIONS(129),
    [anon_sym_DASH_GT] = ACTIONS(129),
    [anon_sym_QMARK_QMARK] = ACTIONS(129),
    [anon_sym____] = ACTIONS(133),
    [anon_sym_BANG_EQ] = ACTIONS(129),
    [anon_sym_LT] = ACTIONS(133),
    [anon_sym_GT] = ACTIONS(133),
    [anon_sym_LT_EQ] = ACTIONS(129),
    [anon_sym_GT_EQ] = ACTIONS(129),
    [anon_sym_PLUS] = ACTIONS(129),
    [anon_sym_DASH] = ACTIONS(133),
    [anon_sym_STAR] = ACTIONS(129),
    [anon_sym_SLASH] = ACTIONS(133),
    [anon_sym_CARET] = ACTIONS(129),
    [anon_sym_BANG] = ACTIONS(133),
    [anon_sym_TILDE] = ACTIONS(129),
    [anon_sym_AMP] = ACTIONS(129),
    [anon_sym_BSLASH] = ACTIONS(129),
    [anon_sym_QMARK] = ACTIONS(133),
    [anon_sym_AT] = ACTIONS(129),
    [anon_sym_DASH_DASH] = ACTIONS(129),
    [anon_sym_GT_GT] = ACTIONS(129),
    [anon_sym_COLON] = ACTIONS(133),
    [anon_sym_SEMI] = ACTIONS(129),
    [anon_sym_COMMA] = ACTIONS(129),
    [anon_sym_LBRACE] = ACTIONS(129),
    [anon_sym_RBRACE] = ACTIONS(129),
    [anon_sym_LBRACK] = ACTIONS(129),
    [anon_sym_RBRACK] = ACTIONS(129),
    [anon_sym_LPAREN] = ACTIONS(129),
    [anon_sym_RPAREN] = ACTIONS(129),
    [sym_string] = ACTIONS(129),
    [sym_char] = ACTIONS(129),
    [sym_number] = ACTIONS(133),
  },
  [11] = {
    [sym_comment] = STATE(11),
    [ts_builtin_sym_end] = ACTIONS(135),
    [sym_identifier] = ACTIONS(139),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(139),
    [anon_sym_EQ_EQ] = ACTIONS(139),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(135),
    [anon_sym_DOT] = ACTIONS(135),
    [anon_sym_EQ_GT] = ACTIONS(135),
    [anon_sym_PIPE] = ACTIONS(139),
    [anon_sym_PIPE_GT] = ACTIONS(135),
    [anon_sym_COLON_COLON] = ACTIONS(139),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(135),
    [anon_sym_fn] = ACTIONS(139),
    [anon_sym_DOLLAR] = ACTIONS(135),
    [anon_sym_LT_LT] = ACTIONS(135),
    [sym_type_identifier] = ACTIONS(139),
    [anon_sym__] = ACTIONS(139),
    [anon_sym_PERCENT] = ACTIONS(135),
    [anon_sym_POUND] = ACTIONS(135),
    [anon_sym_new] = ACTIONS(139),
    [anon_sym_old] = ACTIONS(139),
    [anon_sym_heap] = ACTIONS(139),
    [anon_sym_const] = ACTIONS(139),
    [anon_sym_if] = ACTIONS(139),
    [anon_sym_else] = ACTIONS(139),
    [anon_sym_while] = ACTIONS(139),
    [anon_sym_for] = ACTIONS(139),
    [anon_sym_in] = ACTIONS(139),
    [anon_sym_switch] = ACTIONS(139),
    [anon_sym_case] = ACTIONS(139),
    [anon_sym_fail] = ACTIONS(139),
    [anon_sym_sec] = ACTIONS(139),
    [anon_sym_pkg] = ACTIONS(139),
    [anon_sym_use] = ACTIONS(139),
    [anon_sym_package] = ACTIONS(139),
    [anon_sym_default] = ACTIONS(139),
    [anon_sym_struct] = ACTIONS(139),
    [anon_sym_type] = ACTIONS(139),
    [anon_sym_interface] = ACTIONS(139),
    [anon_sym_alias] = ACTIONS(139),
    [anon_sym_enum] = ACTIONS(139),
    [anon_sym_prop] = ACTIONS(139),
    [anon_sym_impl] = ACTIONS(139),
    [anon_sym_return] = ACTIONS(139),
    [anon_sym_yield] = ACTIONS(139),
    [anon_sym_cascade] = ACTIONS(139),
    [anon_sym_break] = ACTIONS(139),
    [anon_sym_loop] = ACTIONS(139),
    [anon_sym_void] = ACTIONS(139),
    [anon_sym_int] = ACTIONS(139),
    [anon_sym_char] = ACTIONS(139),
    [anon_sym_bool] = ACTIONS(139),
    [anon_sym_float] = ACTIONS(139),
    [anon_sym_range] = ACTIONS(139),
    [anon_sym_list] = ACTIONS(139),
    [anon_sym_string] = ACTIONS(139),
    [anon_sym_line] = ACTIONS(139),
    [anon_sym_word] = ACTIONS(139),
    [anon_sym_Program] = ACTIONS(139),
    [anon_sym_Embedded] = ACTIONS(139),
    [anon_sym_Self] = ACTIONS(139),
    [anon_sym_Type] = ACTIONS(139),
    [anon_sym_Field] = ACTIONS(139),
    [anon_sym_Variable] = ACTIONS(139),
    [anon_sym_into] = ACTIONS(139),
    [anon_sym_fun] = ACTIONS(139),
    [anon_sym_may] = ACTIONS(139),
    [anon_sym_itr] = ACTIONS(139),
    [anon_sym_err] = ACTIONS(139),
    [anon_sym_ark] = ACTIONS(139),
    [anon_sym_ptr] = ACTIONS(139),
    [anon_sym_mut] = ACTIONS(139),
    [anon_sym_ref] = ACTIONS(139),
    [anon_sym_true] = ACTIONS(139),
    [anon_sym_false] = ACTIONS(139),
    [anon_sym_LT_DASH] = ACTIONS(135),
    [anon_sym_DASH_GT] = ACTIONS(135),
    [anon_sym_QMARK_QMARK] = ACTIONS(135),
    [anon_sym____] = ACTIONS(139),
    [anon_sym_BANG_EQ] = ACTIONS(135),
    [anon_sym_LT] = ACTIONS(139),
    [anon_sym_GT] = ACTIONS(139),
    [anon_sym_LT_EQ] = ACTIONS(135),
    [anon_sym_GT_EQ] = ACTIONS(135),
    [anon_sym_PLUS] = ACTIONS(135),
    [anon_sym_DASH] = ACTIONS(139),
    [anon_sym_STAR] = ACTIONS(135),
    [anon_sym_SLASH] = ACTIONS(139),
    [anon_sym_CARET] = ACTIONS(135),
    [anon_sym_BANG] = ACTIONS(139),
    [anon_sym_TILDE] = ACTIONS(135),
    [anon_sym_AMP] = ACTIONS(135),
    [anon_sym_BSLASH] = ACTIONS(135),
    [anon_sym_QMARK] = ACTIONS(139),
    [anon_sym_AT] = ACTIONS(135),
    [anon_sym_DASH_DASH] = ACTIONS(135),
    [anon_sym_GT_GT] = ACTIONS(135),
    [anon_sym_COLON] = ACTIONS(139),
    [anon_sym_SEMI] = ACTIONS(135),
    [anon_sym_COMMA] = ACTIONS(135),
    [anon_sym_LBRACE] = ACTIONS(135),
    [anon_sym_RBRACE] = ACTIONS(135),
    [anon_sym_LBRACK] = ACTIONS(135),
    [anon_sym_RBRACK] = ACTIONS(135),
    [anon_sym_LPAREN] = ACTIONS(135),
    [anon_sym_RPAREN] = ACTIONS(135),
    [sym_string] = ACTIONS(135),
    [sym_char] = ACTIONS(135),
    [sym_number] = ACTIONS(139),
  },
  [12] = {
    [sym_comment] = STATE(12),
    [ts_builtin_sym_end] = ACTIONS(151),
    [sym_identifier] = ACTIONS(153),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(153),
    [anon_sym_EQ_EQ] = ACTIONS(153),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(151),
    [anon_sym_DOT] = ACTIONS(151),
    [anon_sym_EQ_GT] = ACTIONS(151),
    [anon_sym_PIPE] = ACTIONS(153),
    [anon_sym_PIPE_GT] = ACTIONS(151),
    [anon_sym_COLON_COLON] = ACTIONS(153),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(151),
    [anon_sym_fn] = ACTIONS(153),
    [anon_sym_DOLLAR] = ACTIONS(151),
    [anon_sym_LT_LT] = ACTIONS(151),
    [sym_type_identifier] = ACTIONS(153),
    [anon_sym__] = ACTIONS(153),
    [anon_sym_PERCENT] = ACTIONS(151),
    [anon_sym_POUND] = ACTIONS(151),
    [anon_sym_new] = ACTIONS(153),
    [anon_sym_old] = ACTIONS(153),
    [anon_sym_heap] = ACTIONS(153),
    [anon_sym_const] = ACTIONS(153),
    [anon_sym_if] = ACTIONS(153),
    [anon_sym_else] = ACTIONS(153),
    [anon_sym_while] = ACTIONS(153),
    [anon_sym_for] = ACTIONS(153),
    [anon_sym_in] = ACTIONS(153),
    [anon_sym_switch] = ACTIONS(153),
    [anon_sym_case] = ACTIONS(153),
    [anon_sym_fail] = ACTIONS(153),
    [anon_sym_sec] = ACTIONS(153),
    [anon_sym_pkg] = ACTIONS(153),
    [anon_sym_use] = ACTIONS(153),
    [anon_sym_package] = ACTIONS(153),
    [anon_sym_default] = ACTIONS(153),
    [anon_sym_struct] = ACTIONS(153),
    [anon_sym_type] = ACTIONS(153),
    [anon_sym_interface] = ACTIONS(153),
    [anon_sym_alias] = ACTIONS(153),
    [anon_sym_enum] = ACTIONS(153),
    [anon_sym_prop] = ACTIONS(153),
    [anon_sym_impl] = ACTIONS(153),
    [anon_sym_return] = ACTIONS(153),
    [anon_sym_yield] = ACTIONS(153),
    [anon_sym_cascade] = ACTIONS(153),
    [anon_sym_break] = ACTIONS(153),
    [anon_sym_loop] = ACTIONS(153),
    [anon_sym_void] = ACTIONS(153),
    [anon_sym_int] = ACTIONS(153),
    [anon_sym_char] = ACTIONS(153),
    [anon_sym_bool] = ACTIONS(153),
    [anon_sym_float] = ACTIONS(153),
    [anon_sym_range] = ACTIONS(153),
    [anon_sym_list] = ACTIONS(153),
    [anon_sym_string] = ACTIONS(153),
    [anon_sym_line] = ACTIONS(153),
    [anon_sym_word] = ACTIONS(153),
    [anon_sym_Program] = ACTIONS(153),
    [anon_sym_Embedded] = ACTIONS(153),
    [anon_sym_Self] = ACTIONS(153),
    [anon_sym_Type] = ACTIONS(153),
    [anon_sym_Field] = ACTIONS(153),
    [anon_sym_Variable] = ACTIONS(153),
    [anon_sym_into] = ACTIONS(153),
    [anon_sym_fun] = ACTIONS(153),
    [anon_sym_may] = ACTIONS(153),
    [anon_sym_itr] = ACTIONS(153),
    [anon_sym_err] = ACTIONS(153),
    [anon_sym_ark] = ACTIONS(153),
    [anon_sym_ptr] = ACTIONS(153),
    [anon_sym_mut] = ACTIONS(153),
    [anon_sym_ref] = ACTIONS(153),
    [anon_sym_true] = ACTIONS(153),
    [anon_sym_false] = ACTIONS(153),
    [anon_sym_LT_DASH] = ACTIONS(151),
    [anon_sym_DASH_GT] = ACTIONS(151),
    [anon_sym_QMARK_QMARK] = ACTIONS(151),
    [anon_sym____] = ACTIONS(153),
    [anon_sym_BANG_EQ] = ACTIONS(151),
    [anon_sym_LT] = ACTIONS(153),
    [anon_sym_GT] = ACTIONS(153),
    [anon_sym_LT_EQ] = ACTIONS(151),
    [anon_sym_GT_EQ] = ACTIONS(151),
    [anon_sym_PLUS] = ACTIONS(151),
    [anon_sym_DASH] = ACTIONS(153),
    [anon_sym_STAR] = ACTIONS(151),
    [anon_sym_SLASH] = ACTIONS(153),
    [anon_sym_CARET] = ACTIONS(151),
    [anon_sym_BANG] = ACTIONS(153),
    [anon_sym_TILDE] = ACTIONS(151),
    [anon_sym_AMP] = ACTIONS(151),
    [anon_sym_BSLASH] = ACTIONS(151),
    [anon_sym_QMARK] = ACTIONS(153),
    [anon_sym_AT] = ACTIONS(151),
    [anon_sym_DASH_DASH] = ACTIONS(151),
    [anon_sym_GT_GT] = ACTIONS(151),
    [anon_sym_COLON] = ACTIONS(153),
    [anon_sym_SEMI] = ACTIONS(151),
    [anon_sym_COMMA] = ACTIONS(151),
    [anon_sym_LBRACE] = ACTIONS(151),
    [anon_sym_RBRACE] = ACTIONS(151),
    [anon_sym_LBRACK] = ACTIONS(151),
    [anon_sym_RBRACK] = ACTIONS(151),
    [anon_sym_LPAREN] = ACTIONS(151),
    [anon_sym_RPAREN] = ACTIONS(151),
    [sym_string] = ACTIONS(151),
    [sym_char] = ACTIONS(151),
    [sym_number] = ACTIONS(153),
  },
  [13] = {
    [sym_comment] = STATE(13),
    [ts_builtin_sym_end] = ACTIONS(155),
    [sym_identifier] = ACTIONS(157),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(157),
    [anon_sym_EQ_EQ] = ACTIONS(157),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(155),
    [anon_sym_DOT] = ACTIONS(155),
    [anon_sym_EQ_GT] = ACTIONS(155),
    [anon_sym_PIPE] = ACTIONS(157),
    [anon_sym_PIPE_GT] = ACTIONS(155),
    [anon_sym_COLON_COLON] = ACTIONS(157),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(155),
    [anon_sym_fn] = ACTIONS(157),
    [anon_sym_DOLLAR] = ACTIONS(155),
    [anon_sym_LT_LT] = ACTIONS(155),
    [sym_type_identifier] = ACTIONS(157),
    [anon_sym__] = ACTIONS(157),
    [anon_sym_PERCENT] = ACTIONS(155),
    [anon_sym_POUND] = ACTIONS(155),
    [anon_sym_new] = ACTIONS(157),
    [anon_sym_old] = ACTIONS(157),
    [anon_sym_heap] = ACTIONS(157),
    [anon_sym_const] = ACTIONS(157),
    [anon_sym_if] = ACTIONS(157),
    [anon_sym_else] = ACTIONS(157),
    [anon_sym_while] = ACTIONS(157),
    [anon_sym_for] = ACTIONS(157),
    [anon_sym_in] = ACTIONS(157),
    [anon_sym_switch] = ACTIONS(157),
    [anon_sym_case] = ACTIONS(157),
    [anon_sym_fail] = ACTIONS(157),
    [anon_sym_sec] = ACTIONS(157),
    [anon_sym_pkg] = ACTIONS(157),
    [anon_sym_use] = ACTIONS(157),
    [anon_sym_package] = ACTIONS(157),
    [anon_sym_default] = ACTIONS(157),
    [anon_sym_struct] = ACTIONS(157),
    [anon_sym_type] = ACTIONS(157),
    [anon_sym_interface] = ACTIONS(157),
    [anon_sym_alias] = ACTIONS(157),
    [anon_sym_enum] = ACTIONS(157),
    [anon_sym_prop] = ACTIONS(157),
    [anon_sym_impl] = ACTIONS(157),
    [anon_sym_return] = ACTIONS(157),
    [anon_sym_yield] = ACTIONS(157),
    [anon_sym_cascade] = ACTIONS(157),
    [anon_sym_break] = ACTIONS(157),
    [anon_sym_loop] = ACTIONS(157),
    [anon_sym_void] = ACTIONS(157),
    [anon_sym_int] = ACTIONS(157),
    [anon_sym_char] = ACTIONS(157),
    [anon_sym_bool] = ACTIONS(157),
    [anon_sym_float] = ACTIONS(157),
    [anon_sym_range] = ACTIONS(157),
    [anon_sym_list] = ACTIONS(157),
    [anon_sym_string] = ACTIONS(157),
    [anon_sym_line] = ACTIONS(157),
    [anon_sym_word] = ACTIONS(157),
    [anon_sym_Program] = ACTIONS(157),
    [anon_sym_Embedded] = ACTIONS(157),
    [anon_sym_Self] = ACTIONS(157),
    [anon_sym_Type] = ACTIONS(157),
    [anon_sym_Field] = ACTIONS(157),
    [anon_sym_Variable] = ACTIONS(157),
    [anon_sym_into] = ACTIONS(157),
    [anon_sym_fun] = ACTIONS(157),
    [anon_sym_may] = ACTIONS(157),
    [anon_sym_itr] = ACTIONS(157),
    [anon_sym_err] = ACTIONS(157),
    [anon_sym_ark] = ACTIONS(157),
    [anon_sym_ptr] = ACTIONS(157),
    [anon_sym_mut] = ACTIONS(157),
    [anon_sym_ref] = ACTIONS(157),
    [anon_sym_true] = ACTIONS(157),
    [anon_sym_false] = ACTIONS(157),
    [anon_sym_LT_DASH] = ACTIONS(155),
    [anon_sym_DASH_GT] = ACTIONS(155),
    [anon_sym_QMARK_QMARK] = ACTIONS(155),
    [anon_sym____] = ACTIONS(157),
    [anon_sym_BANG_EQ] = ACTIONS(155),
    [anon_sym_LT] = ACTIONS(157),
    [anon_sym_GT] = ACTIONS(157),
    [anon_sym_LT_EQ] = ACTIONS(155),
    [anon_sym_GT_EQ] = ACTIONS(155),
    [anon_sym_PLUS] = ACTIONS(155),
    [anon_sym_DASH] = ACTIONS(157),
    [anon_sym_STAR] = ACTIONS(155),
    [anon_sym_SLASH] = ACTIONS(157),
    [anon_sym_CARET] = ACTIONS(155),
    [anon_sym_BANG] = ACTIONS(157),
    [anon_sym_TILDE] = ACTIONS(155),
    [anon_sym_AMP] = ACTIONS(155),
    [anon_sym_BSLASH] = ACTIONS(155),
    [anon_sym_QMARK] = ACTIONS(157),
    [anon_sym_AT] = ACTIONS(155),
    [anon_sym_DASH_DASH] = ACTIONS(155),
    [anon_sym_GT_GT] = ACTIONS(155),
    [anon_sym_COLON] = ACTIONS(157),
    [anon_sym_SEMI] = ACTIONS(155),
    [anon_sym_COMMA] = ACTIONS(155),
    [anon_sym_LBRACE] = ACTIONS(155),
    [anon_sym_RBRACE] = ACTIONS(155),
    [anon_sym_LBRACK] = ACTIONS(155),
    [anon_sym_RBRACK] = ACTIONS(155),
    [anon_sym_LPAREN] = ACTIONS(155),
    [anon_sym_RPAREN] = ACTIONS(155),
    [sym_string] = ACTIONS(155),
    [sym_char] = ACTIONS(155),
    [sym_number] = ACTIONS(157),
  },
  [14] = {
    [sym_comment] = STATE(14),
    [ts_builtin_sym_end] = ACTIONS(159),
    [sym_identifier] = ACTIONS(161),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(161),
    [anon_sym_EQ_EQ] = ACTIONS(161),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(159),
    [anon_sym_DOT] = ACTIONS(159),
    [anon_sym_EQ_GT] = ACTIONS(159),
    [anon_sym_PIPE] = ACTIONS(161),
    [anon_sym_PIPE_GT] = ACTIONS(159),
    [anon_sym_COLON_COLON] = ACTIONS(161),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(159),
    [anon_sym_fn] = ACTIONS(161),
    [anon_sym_DOLLAR] = ACTIONS(159),
    [anon_sym_LT_LT] = ACTIONS(159),
    [sym_type_identifier] = ACTIONS(161),
    [anon_sym__] = ACTIONS(161),
    [anon_sym_PERCENT] = ACTIONS(159),
    [anon_sym_POUND] = ACTIONS(159),
    [anon_sym_new] = ACTIONS(161),
    [anon_sym_old] = ACTIONS(161),
    [anon_sym_heap] = ACTIONS(161),
    [anon_sym_const] = ACTIONS(161),
    [anon_sym_if] = ACTIONS(161),
    [anon_sym_else] = ACTIONS(161),
    [anon_sym_while] = ACTIONS(161),
    [anon_sym_for] = ACTIONS(161),
    [anon_sym_in] = ACTIONS(161),
    [anon_sym_switch] = ACTIONS(161),
    [anon_sym_case] = ACTIONS(161),
    [anon_sym_fail] = ACTIONS(161),
    [anon_sym_sec] = ACTIONS(161),
    [anon_sym_pkg] = ACTIONS(161),
    [anon_sym_use] = ACTIONS(161),
    [anon_sym_package] = ACTIONS(161),
    [anon_sym_default] = ACTIONS(161),
    [anon_sym_struct] = ACTIONS(161),
    [anon_sym_type] = ACTIONS(161),
    [anon_sym_interface] = ACTIONS(161),
    [anon_sym_alias] = ACTIONS(161),
    [anon_sym_enum] = ACTIONS(161),
    [anon_sym_prop] = ACTIONS(161),
    [anon_sym_impl] = ACTIONS(161),
    [anon_sym_return] = ACTIONS(161),
    [anon_sym_yield] = ACTIONS(161),
    [anon_sym_cascade] = ACTIONS(161),
    [anon_sym_break] = ACTIONS(161),
    [anon_sym_loop] = ACTIONS(161),
    [anon_sym_void] = ACTIONS(161),
    [anon_sym_int] = ACTIONS(161),
    [anon_sym_char] = ACTIONS(161),
    [anon_sym_bool] = ACTIONS(161),
    [anon_sym_float] = ACTIONS(161),
    [anon_sym_range] = ACTIONS(161),
    [anon_sym_list] = ACTIONS(161),
    [anon_sym_string] = ACTIONS(161),
    [anon_sym_line] = ACTIONS(161),
    [anon_sym_word] = ACTIONS(161),
    [anon_sym_Program] = ACTIONS(161),
    [anon_sym_Embedded] = ACTIONS(161),
    [anon_sym_Self] = ACTIONS(161),
    [anon_sym_Type] = ACTIONS(161),
    [anon_sym_Field] = ACTIONS(161),
    [anon_sym_Variable] = ACTIONS(161),
    [anon_sym_into] = ACTIONS(161),
    [anon_sym_fun] = ACTIONS(161),
    [anon_sym_may] = ACTIONS(161),
    [anon_sym_itr] = ACTIONS(161),
    [anon_sym_err] = ACTIONS(161),
    [anon_sym_ark] = ACTIONS(161),
    [anon_sym_ptr] = ACTIONS(161),
    [anon_sym_mut] = ACTIONS(161),
    [anon_sym_ref] = ACTIONS(161),
    [anon_sym_true] = ACTIONS(161),
    [anon_sym_false] = ACTIONS(161),
    [anon_sym_LT_DASH] = ACTIONS(159),
    [anon_sym_DASH_GT] = ACTIONS(159),
    [anon_sym_QMARK_QMARK] = ACTIONS(159),
    [anon_sym____] = ACTIONS(161),
    [anon_sym_BANG_EQ] = ACTIONS(159),
    [anon_sym_LT] = ACTIONS(161),
    [anon_sym_GT] = ACTIONS(161),
    [anon_sym_LT_EQ] = ACTIONS(159),
    [anon_sym_GT_EQ] = ACTIONS(159),
    [anon_sym_PLUS] = ACTIONS(159),
    [anon_sym_DASH] = ACTIONS(161),
    [anon_sym_STAR] = ACTIONS(159),
    [anon_sym_SLASH] = ACTIONS(161),
    [anon_sym_CARET] = ACTIONS(159),
    [anon_sym_BANG] = ACTIONS(161),
    [anon_sym_TILDE] = ACTIONS(159),
    [anon_sym_AMP] = ACTIONS(159),
    [anon_sym_BSLASH] = ACTIONS(159),
    [anon_sym_QMARK] = ACTIONS(161),
    [anon_sym_AT] = ACTIONS(159),
    [anon_sym_DASH_DASH] = ACTIONS(159),
    [anon_sym_GT_GT] = ACTIONS(159),
    [anon_sym_COLON] = ACTIONS(161),
    [anon_sym_SEMI] = ACTIONS(159),
    [anon_sym_COMMA] = ACTIONS(159),
    [anon_sym_LBRACE] = ACTIONS(159),
    [anon_sym_RBRACE] = ACTIONS(159),
    [anon_sym_LBRACK] = ACTIONS(159),
    [anon_sym_RBRACK] = ACTIONS(159),
    [anon_sym_LPAREN] = ACTIONS(159),
    [anon_sym_RPAREN] = ACTIONS(159),
    [sym_string] = ACTIONS(159),
    [sym_char] = ACTIONS(159),
    [sym_number] = ACTIONS(161),
  },
  [15] = {
    [sym_comment] = STATE(15),
    [ts_builtin_sym_end] = ACTIONS(163),
    [sym_identifier] = ACTIONS(165),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(165),
    [anon_sym_EQ_EQ] = ACTIONS(165),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(163),
    [anon_sym_DOT] = ACTIONS(163),
    [anon_sym_EQ_GT] = ACTIONS(163),
    [anon_sym_PIPE] = ACTIONS(165),
    [anon_sym_PIPE_GT] = ACTIONS(163),
    [anon_sym_COLON_COLON] = ACTIONS(165),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(163),
    [anon_sym_fn] = ACTIONS(165),
    [anon_sym_DOLLAR] = ACTIONS(163),
    [anon_sym_LT_LT] = ACTIONS(163),
    [sym_type_identifier] = ACTIONS(165),
    [anon_sym__] = ACTIONS(165),
    [anon_sym_PERCENT] = ACTIONS(163),
    [anon_sym_POUND] = ACTIONS(163),
    [anon_sym_new] = ACTIONS(165),
    [anon_sym_old] = ACTIONS(165),
    [anon_sym_heap] = ACTIONS(165),
    [anon_sym_const] = ACTIONS(165),
    [anon_sym_if] = ACTIONS(165),
    [anon_sym_else] = ACTIONS(165),
    [anon_sym_while] = ACTIONS(165),
    [anon_sym_for] = ACTIONS(165),
    [anon_sym_in] = ACTIONS(165),
    [anon_sym_switch] = ACTIONS(165),
    [anon_sym_case] = ACTIONS(165),
    [anon_sym_fail] = ACTIONS(165),
    [anon_sym_sec] = ACTIONS(165),
    [anon_sym_pkg] = ACTIONS(165),
    [anon_sym_use] = ACTIONS(165),
    [anon_sym_package] = ACTIONS(165),
    [anon_sym_default] = ACTIONS(165),
    [anon_sym_struct] = ACTIONS(165),
    [anon_sym_type] = ACTIONS(165),
    [anon_sym_interface] = ACTIONS(165),
    [anon_sym_alias] = ACTIONS(165),
    [anon_sym_enum] = ACTIONS(165),
    [anon_sym_prop] = ACTIONS(165),
    [anon_sym_impl] = ACTIONS(165),
    [anon_sym_return] = ACTIONS(165),
    [anon_sym_yield] = ACTIONS(165),
    [anon_sym_cascade] = ACTIONS(165),
    [anon_sym_break] = ACTIONS(165),
    [anon_sym_loop] = ACTIONS(165),
    [anon_sym_void] = ACTIONS(165),
    [anon_sym_int] = ACTIONS(165),
    [anon_sym_char] = ACTIONS(165),
    [anon_sym_bool] = ACTIONS(165),
    [anon_sym_float] = ACTIONS(165),
    [anon_sym_range] = ACTIONS(165),
    [anon_sym_list] = ACTIONS(165),
    [anon_sym_string] = ACTIONS(165),
    [anon_sym_line] = ACTIONS(165),
    [anon_sym_word] = ACTIONS(165),
    [anon_sym_Program] = ACTIONS(165),
    [anon_sym_Embedded] = ACTIONS(165),
    [anon_sym_Self] = ACTIONS(165),
    [anon_sym_Type] = ACTIONS(165),
    [anon_sym_Field] = ACTIONS(165),
    [anon_sym_Variable] = ACTIONS(165),
    [anon_sym_into] = ACTIONS(165),
    [anon_sym_fun] = ACTIONS(165),
    [anon_sym_may] = ACTIONS(165),
    [anon_sym_itr] = ACTIONS(165),
    [anon_sym_err] = ACTIONS(165),
    [anon_sym_ark] = ACTIONS(165),
    [anon_sym_ptr] = ACTIONS(165),
    [anon_sym_mut] = ACTIONS(165),
    [anon_sym_ref] = ACTIONS(165),
    [anon_sym_true] = ACTIONS(165),
    [anon_sym_false] = ACTIONS(165),
    [anon_sym_LT_DASH] = ACTIONS(163),
    [anon_sym_DASH_GT] = ACTIONS(163),
    [anon_sym_QMARK_QMARK] = ACTIONS(163),
    [anon_sym____] = ACTIONS(165),
    [anon_sym_BANG_EQ] = ACTIONS(163),
    [anon_sym_LT] = ACTIONS(165),
    [anon_sym_GT] = ACTIONS(165),
    [anon_sym_LT_EQ] = ACTIONS(163),
    [anon_sym_GT_EQ] = ACTIONS(163),
    [anon_sym_PLUS] = ACTIONS(163),
    [anon_sym_DASH] = ACTIONS(165),
    [anon_sym_STAR] = ACTIONS(163),
    [anon_sym_SLASH] = ACTIONS(165),
    [anon_sym_CARET] = ACTIONS(163),
    [anon_sym_BANG] = ACTIONS(165),
    [anon_sym_TILDE] = ACTIONS(163),
    [anon_sym_AMP] = ACTIONS(163),
    [anon_sym_BSLASH] = ACTIONS(163),
    [anon_sym_QMARK] = ACTIONS(165),
    [anon_sym_AT] = ACTIONS(163),
    [anon_sym_DASH_DASH] = ACTIONS(163),
    [anon_sym_GT_GT] = ACTIONS(163),
    [anon_sym_COLON] = ACTIONS(165),
    [anon_sym_SEMI] = ACTIONS(163),
    [anon_sym_COMMA] = ACTIONS(163),
    [anon_sym_LBRACE] = ACTIONS(163),
    [anon_sym_RBRACE] = ACTIONS(163),
    [anon_sym_LBRACK] = ACTIONS(163),
    [anon_sym_RBRACK] = ACTIONS(163),
    [anon_sym_LPAREN] = ACTIONS(163),
    [anon_sym_RPAREN] = ACTIONS(163),
    [sym_string] = ACTIONS(163),
    [sym_char] = ACTIONS(163),
    [sym_number] = ACTIONS(165),
  },
  [16] = {
    [sym_comment] = STATE(16),
    [ts_builtin_sym_end] = ACTIONS(129),
    [sym_identifier] = ACTIONS(133),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(133),
    [anon_sym_EQ_EQ] = ACTIONS(133),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(129),
    [anon_sym_DOT] = ACTIONS(129),
    [anon_sym_EQ_GT] = ACTIONS(129),
    [anon_sym_PIPE] = ACTIONS(133),
    [anon_sym_PIPE_GT] = ACTIONS(129),
    [anon_sym_COLON_COLON] = ACTIONS(133),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(129),
    [anon_sym_fn] = ACTIONS(133),
    [anon_sym_DOLLAR] = ACTIONS(129),
    [anon_sym_LT_LT] = ACTIONS(129),
    [sym_type_identifier] = ACTIONS(133),
    [anon_sym__] = ACTIONS(133),
    [anon_sym_PERCENT] = ACTIONS(129),
    [anon_sym_POUND] = ACTIONS(129),
    [anon_sym_new] = ACTIONS(133),
    [anon_sym_old] = ACTIONS(133),
    [anon_sym_heap] = ACTIONS(133),
    [anon_sym_const] = ACTIONS(133),
    [anon_sym_if] = ACTIONS(133),
    [anon_sym_else] = ACTIONS(133),
    [anon_sym_while] = ACTIONS(133),
    [anon_sym_for] = ACTIONS(133),
    [anon_sym_in] = ACTIONS(133),
    [anon_sym_switch] = ACTIONS(133),
    [anon_sym_case] = ACTIONS(133),
    [anon_sym_fail] = ACTIONS(133),
    [anon_sym_sec] = ACTIONS(133),
    [anon_sym_pkg] = ACTIONS(133),
    [anon_sym_use] = ACTIONS(133),
    [anon_sym_package] = ACTIONS(133),
    [anon_sym_default] = ACTIONS(133),
    [anon_sym_struct] = ACTIONS(133),
    [anon_sym_type] = ACTIONS(133),
    [anon_sym_interface] = ACTIONS(133),
    [anon_sym_alias] = ACTIONS(133),
    [anon_sym_enum] = ACTIONS(133),
    [anon_sym_prop] = ACTIONS(133),
    [anon_sym_impl] = ACTIONS(133),
    [anon_sym_return] = ACTIONS(133),
    [anon_sym_yield] = ACTIONS(133),
    [anon_sym_cascade] = ACTIONS(133),
    [anon_sym_break] = ACTIONS(133),
    [anon_sym_loop] = ACTIONS(133),
    [anon_sym_void] = ACTIONS(133),
    [anon_sym_int] = ACTIONS(133),
    [anon_sym_char] = ACTIONS(133),
    [anon_sym_bool] = ACTIONS(133),
    [anon_sym_float] = ACTIONS(133),
    [anon_sym_range] = ACTIONS(133),
    [anon_sym_list] = ACTIONS(133),
    [anon_sym_string] = ACTIONS(133),
    [anon_sym_line] = ACTIONS(133),
    [anon_sym_word] = ACTIONS(133),
    [anon_sym_Program] = ACTIONS(133),
    [anon_sym_Embedded] = ACTIONS(133),
    [anon_sym_Self] = ACTIONS(133),
    [anon_sym_Type] = ACTIONS(133),
    [anon_sym_Field] = ACTIONS(133),
    [anon_sym_Variable] = ACTIONS(133),
    [anon_sym_into] = ACTIONS(133),
    [anon_sym_fun] = ACTIONS(133),
    [anon_sym_may] = ACTIONS(133),
    [anon_sym_itr] = ACTIONS(133),
    [anon_sym_err] = ACTIONS(133),
    [anon_sym_ark] = ACTIONS(133),
    [anon_sym_ptr] = ACTIONS(133),
    [anon_sym_mut] = ACTIONS(133),
    [anon_sym_ref] = ACTIONS(133),
    [anon_sym_true] = ACTIONS(133),
    [anon_sym_false] = ACTIONS(133),
    [anon_sym_LT_DASH] = ACTIONS(129),
    [anon_sym_DASH_GT] = ACTIONS(129),
    [anon_sym_QMARK_QMARK] = ACTIONS(129),
    [anon_sym____] = ACTIONS(133),
    [anon_sym_BANG_EQ] = ACTIONS(129),
    [anon_sym_LT] = ACTIONS(133),
    [anon_sym_GT] = ACTIONS(133),
    [anon_sym_LT_EQ] = ACTIONS(129),
    [anon_sym_GT_EQ] = ACTIONS(129),
    [anon_sym_PLUS] = ACTIONS(129),
    [anon_sym_DASH] = ACTIONS(133),
    [anon_sym_STAR] = ACTIONS(129),
    [anon_sym_SLASH] = ACTIONS(133),
    [anon_sym_CARET] = ACTIONS(129),
    [anon_sym_BANG] = ACTIONS(133),
    [anon_sym_TILDE] = ACTIONS(129),
    [anon_sym_AMP] = ACTIONS(129),
    [anon_sym_BSLASH] = ACTIONS(129),
    [anon_sym_QMARK] = ACTIONS(133),
    [anon_sym_AT] = ACTIONS(129),
    [anon_sym_DASH_DASH] = ACTIONS(129),
    [anon_sym_GT_GT] = ACTIONS(129),
    [anon_sym_COLON] = ACTIONS(133),
    [anon_sym_SEMI] = ACTIONS(129),
    [anon_sym_COMMA] = ACTIONS(129),
    [anon_sym_LBRACE] = ACTIONS(129),
    [anon_sym_RBRACE] = ACTIONS(129),
    [anon_sym_LBRACK] = ACTIONS(129),
    [anon_sym_RBRACK] = ACTIONS(129),
    [anon_sym_LPAREN] = ACTIONS(129),
    [anon_sym_RPAREN] = ACTIONS(129),
    [sym_string] = ACTIONS(129),
    [sym_char] = ACTIONS(129),
    [sym_number] = ACTIONS(133),
  },
  [17] = {
    [sym_comment] = STATE(17),
    [ts_builtin_sym_end] = ACTIONS(167),
    [sym_identifier] = ACTIONS(169),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(169),
    [anon_sym_EQ_EQ] = ACTIONS(169),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(167),
    [anon_sym_DOT] = ACTIONS(167),
    [anon_sym_EQ_GT] = ACTIONS(167),
    [anon_sym_PIPE] = ACTIONS(169),
    [anon_sym_PIPE_GT] = ACTIONS(167),
    [anon_sym_COLON_COLON] = ACTIONS(169),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(167),
    [anon_sym_fn] = ACTIONS(169),
    [anon_sym_DOLLAR] = ACTIONS(167),
    [anon_sym_LT_LT] = ACTIONS(167),
    [sym_type_identifier] = ACTIONS(169),
    [anon_sym__] = ACTIONS(169),
    [anon_sym_PERCENT] = ACTIONS(167),
    [anon_sym_POUND] = ACTIONS(167),
    [anon_sym_new] = ACTIONS(169),
    [anon_sym_old] = ACTIONS(169),
    [anon_sym_heap] = ACTIONS(169),
    [anon_sym_const] = ACTIONS(169),
    [anon_sym_if] = ACTIONS(169),
    [anon_sym_else] = ACTIONS(169),
    [anon_sym_while] = ACTIONS(169),
    [anon_sym_for] = ACTIONS(169),
    [anon_sym_in] = ACTIONS(169),
    [anon_sym_switch] = ACTIONS(169),
    [anon_sym_case] = ACTIONS(169),
    [anon_sym_fail] = ACTIONS(169),
    [anon_sym_sec] = ACTIONS(169),
    [anon_sym_pkg] = ACTIONS(169),
    [anon_sym_use] = ACTIONS(169),
    [anon_sym_package] = ACTIONS(169),
    [anon_sym_default] = ACTIONS(169),
    [anon_sym_struct] = ACTIONS(169),
    [anon_sym_type] = ACTIONS(169),
    [anon_sym_interface] = ACTIONS(169),
    [anon_sym_alias] = ACTIONS(169),
    [anon_sym_enum] = ACTIONS(169),
    [anon_sym_prop] = ACTIONS(169),
    [anon_sym_impl] = ACTIONS(169),
    [anon_sym_return] = ACTIONS(169),
    [anon_sym_yield] = ACTIONS(169),
    [anon_sym_cascade] = ACTIONS(169),
    [anon_sym_break] = ACTIONS(169),
    [anon_sym_loop] = ACTIONS(169),
    [anon_sym_void] = ACTIONS(169),
    [anon_sym_int] = ACTIONS(169),
    [anon_sym_char] = ACTIONS(169),
    [anon_sym_bool] = ACTIONS(169),
    [anon_sym_float] = ACTIONS(169),
    [anon_sym_range] = ACTIONS(169),
    [anon_sym_list] = ACTIONS(169),
    [anon_sym_string] = ACTIONS(169),
    [anon_sym_line] = ACTIONS(169),
    [anon_sym_word] = ACTIONS(169),
    [anon_sym_Program] = ACTIONS(169),
    [anon_sym_Embedded] = ACTIONS(169),
    [anon_sym_Self] = ACTIONS(169),
    [anon_sym_Type] = ACTIONS(169),
    [anon_sym_Field] = ACTIONS(169),
    [anon_sym_Variable] = ACTIONS(169),
    [anon_sym_into] = ACTIONS(169),
    [anon_sym_fun] = ACTIONS(169),
    [anon_sym_may] = ACTIONS(169),
    [anon_sym_itr] = ACTIONS(169),
    [anon_sym_err] = ACTIONS(169),
    [anon_sym_ark] = ACTIONS(169),
    [anon_sym_ptr] = ACTIONS(169),
    [anon_sym_mut] = ACTIONS(169),
    [anon_sym_ref] = ACTIONS(169),
    [anon_sym_true] = ACTIONS(169),
    [anon_sym_false] = ACTIONS(169),
    [anon_sym_LT_DASH] = ACTIONS(167),
    [anon_sym_DASH_GT] = ACTIONS(167),
    [anon_sym_QMARK_QMARK] = ACTIONS(167),
    [anon_sym____] = ACTIONS(169),
    [anon_sym_BANG_EQ] = ACTIONS(167),
    [anon_sym_LT] = ACTIONS(169),
    [anon_sym_GT] = ACTIONS(169),
    [anon_sym_LT_EQ] = ACTIONS(167),
    [anon_sym_GT_EQ] = ACTIONS(167),
    [anon_sym_PLUS] = ACTIONS(167),
    [anon_sym_DASH] = ACTIONS(169),
    [anon_sym_STAR] = ACTIONS(167),
    [anon_sym_SLASH] = ACTIONS(169),
    [anon_sym_CARET] = ACTIONS(167),
    [anon_sym_BANG] = ACTIONS(169),
    [anon_sym_TILDE] = ACTIONS(167),
    [anon_sym_AMP] = ACTIONS(167),
    [anon_sym_BSLASH] = ACTIONS(167),
    [anon_sym_QMARK] = ACTIONS(169),
    [anon_sym_AT] = ACTIONS(167),
    [anon_sym_DASH_DASH] = ACTIONS(167),
    [anon_sym_GT_GT] = ACTIONS(167),
    [anon_sym_COLON] = ACTIONS(169),
    [anon_sym_SEMI] = ACTIONS(167),
    [anon_sym_COMMA] = ACTIONS(167),
    [anon_sym_LBRACE] = ACTIONS(167),
    [anon_sym_RBRACE] = ACTIONS(167),
    [anon_sym_LBRACK] = ACTIONS(167),
    [anon_sym_RBRACK] = ACTIONS(167),
    [anon_sym_LPAREN] = ACTIONS(167),
    [anon_sym_RPAREN] = ACTIONS(167),
    [sym_string] = ACTIONS(167),
    [sym_char] = ACTIONS(167),
    [sym_number] = ACTIONS(169),
  },
  [18] = {
    [sym_comment] = STATE(18),
    [ts_builtin_sym_end] = ACTIONS(119),
    [sym_identifier] = ACTIONS(121),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(121),
    [anon_sym_EQ_EQ] = ACTIONS(121),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(119),
    [anon_sym_DOT] = ACTIONS(119),
    [anon_sym_EQ_GT] = ACTIONS(119),
    [anon_sym_PIPE] = ACTIONS(121),
    [anon_sym_PIPE_GT] = ACTIONS(119),
    [anon_sym_COLON_COLON] = ACTIONS(121),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(119),
    [anon_sym_fn] = ACTIONS(121),
    [anon_sym_DOLLAR] = ACTIONS(119),
    [anon_sym_LT_LT] = ACTIONS(119),
    [sym_type_identifier] = ACTIONS(121),
    [anon_sym__] = ACTIONS(121),
    [anon_sym_PERCENT] = ACTIONS(119),
    [anon_sym_POUND] = ACTIONS(119),
    [anon_sym_new] = ACTIONS(121),
    [anon_sym_old] = ACTIONS(121),
    [anon_sym_heap] = ACTIONS(121),
    [anon_sym_const] = ACTIONS(121),
    [anon_sym_if] = ACTIONS(121),
    [anon_sym_else] = ACTIONS(121),
    [anon_sym_while] = ACTIONS(121),
    [anon_sym_for] = ACTIONS(121),
    [anon_sym_in] = ACTIONS(121),
    [anon_sym_switch] = ACTIONS(121),
    [anon_sym_case] = ACTIONS(121),
    [anon_sym_fail] = ACTIONS(121),
    [anon_sym_sec] = ACTIONS(121),
    [anon_sym_pkg] = ACTIONS(121),
    [anon_sym_use] = ACTIONS(121),
    [anon_sym_package] = ACTIONS(121),
    [anon_sym_default] = ACTIONS(121),
    [anon_sym_struct] = ACTIONS(121),
    [anon_sym_type] = ACTIONS(121),
    [anon_sym_interface] = ACTIONS(121),
    [anon_sym_alias] = ACTIONS(121),
    [anon_sym_enum] = ACTIONS(121),
    [anon_sym_prop] = ACTIONS(121),
    [anon_sym_impl] = ACTIONS(121),
    [anon_sym_return] = ACTIONS(121),
    [anon_sym_yield] = ACTIONS(121),
    [anon_sym_cascade] = ACTIONS(121),
    [anon_sym_break] = ACTIONS(121),
    [anon_sym_loop] = ACTIONS(121),
    [anon_sym_void] = ACTIONS(121),
    [anon_sym_int] = ACTIONS(121),
    [anon_sym_char] = ACTIONS(121),
    [anon_sym_bool] = ACTIONS(121),
    [anon_sym_float] = ACTIONS(121),
    [anon_sym_range] = ACTIONS(121),
    [anon_sym_list] = ACTIONS(121),
    [anon_sym_string] = ACTIONS(121),
    [anon_sym_line] = ACTIONS(121),
    [anon_sym_word] = ACTIONS(121),
    [anon_sym_Program] = ACTIONS(121),
    [anon_sym_Embedded] = ACTIONS(121),
    [anon_sym_Self] = ACTIONS(121),
    [anon_sym_Type] = ACTIONS(121),
    [anon_sym_Field] = ACTIONS(121),
    [anon_sym_Variable] = ACTIONS(121),
    [anon_sym_into] = ACTIONS(121),
    [anon_sym_fun] = ACTIONS(121),
    [anon_sym_may] = ACTIONS(121),
    [anon_sym_itr] = ACTIONS(121),
    [anon_sym_err] = ACTIONS(121),
    [anon_sym_ark] = ACTIONS(121),
    [anon_sym_ptr] = ACTIONS(121),
    [anon_sym_mut] = ACTIONS(121),
    [anon_sym_ref] = ACTIONS(121),
    [anon_sym_true] = ACTIONS(121),
    [anon_sym_false] = ACTIONS(121),
    [anon_sym_LT_DASH] = ACTIONS(119),
    [anon_sym_DASH_GT] = ACTIONS(119),
    [anon_sym_QMARK_QMARK] = ACTIONS(119),
    [anon_sym____] = ACTIONS(121),
    [anon_sym_BANG_EQ] = ACTIONS(119),
    [anon_sym_LT] = ACTIONS(121),
    [anon_sym_GT] = ACTIONS(121),
    [anon_sym_LT_EQ] = ACTIONS(119),
    [anon_sym_GT_EQ] = ACTIONS(119),
    [anon_sym_PLUS] = ACTIONS(119),
    [anon_sym_DASH] = ACTIONS(121),
    [anon_sym_STAR] = ACTIONS(119),
    [anon_sym_SLASH] = ACTIONS(121),
    [anon_sym_CARET] = ACTIONS(119),
    [anon_sym_BANG] = ACTIONS(121),
    [anon_sym_TILDE] = ACTIONS(119),
    [anon_sym_AMP] = ACTIONS(119),
    [anon_sym_BSLASH] = ACTIONS(119),
    [anon_sym_QMARK] = ACTIONS(121),
    [anon_sym_AT] = ACTIONS(119),
    [anon_sym_DASH_DASH] = ACTIONS(119),
    [anon_sym_GT_GT] = ACTIONS(119),
    [anon_sym_COLON] = ACTIONS(121),
    [anon_sym_SEMI] = ACTIONS(119),
    [anon_sym_COMMA] = ACTIONS(119),
    [anon_sym_LBRACE] = ACTIONS(119),
    [anon_sym_RBRACE] = ACTIONS(119),
    [anon_sym_LBRACK] = ACTIONS(119),
    [anon_sym_RBRACK] = ACTIONS(119),
    [anon_sym_LPAREN] = ACTIONS(119),
    [anon_sym_RPAREN] = ACTIONS(119),
    [sym_string] = ACTIONS(119),
    [sym_char] = ACTIONS(119),
    [sym_number] = ACTIONS(121),
  },
  [19] = {
    [sym_comment] = STATE(19),
    [ts_builtin_sym_end] = ACTIONS(171),
    [sym_identifier] = ACTIONS(173),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(173),
    [anon_sym_EQ_EQ] = ACTIONS(173),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(171),
    [anon_sym_DOT] = ACTIONS(171),
    [anon_sym_EQ_GT] = ACTIONS(171),
    [anon_sym_PIPE] = ACTIONS(173),
    [anon_sym_PIPE_GT] = ACTIONS(171),
    [anon_sym_COLON_COLON] = ACTIONS(173),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(171),
    [anon_sym_fn] = ACTIONS(173),
    [anon_sym_DOLLAR] = ACTIONS(171),
    [anon_sym_LT_LT] = ACTIONS(171),
    [sym_type_identifier] = ACTIONS(173),
    [anon_sym__] = ACTIONS(173),
    [anon_sym_PERCENT] = ACTIONS(171),
    [anon_sym_POUND] = ACTIONS(171),
    [anon_sym_new] = ACTIONS(173),
    [anon_sym_old] = ACTIONS(173),
    [anon_sym_heap] = ACTIONS(173),
    [anon_sym_const] = ACTIONS(173),
    [anon_sym_if] = ACTIONS(173),
    [anon_sym_else] = ACTIONS(173),
    [anon_sym_while] = ACTIONS(173),
    [anon_sym_for] = ACTIONS(173),
    [anon_sym_in] = ACTIONS(173),
    [anon_sym_switch] = ACTIONS(173),
    [anon_sym_case] = ACTIONS(173),
    [anon_sym_fail] = ACTIONS(173),
    [anon_sym_sec] = ACTIONS(173),
    [anon_sym_pkg] = ACTIONS(173),
    [anon_sym_use] = ACTIONS(173),
    [anon_sym_package] = ACTIONS(173),
    [anon_sym_default] = ACTIONS(173),
    [anon_sym_struct] = ACTIONS(173),
    [anon_sym_type] = ACTIONS(173),
    [anon_sym_interface] = ACTIONS(173),
    [anon_sym_alias] = ACTIONS(173),
    [anon_sym_enum] = ACTIONS(173),
    [anon_sym_prop] = ACTIONS(173),
    [anon_sym_impl] = ACTIONS(173),
    [anon_sym_return] = ACTIONS(173),
    [anon_sym_yield] = ACTIONS(173),
    [anon_sym_cascade] = ACTIONS(173),
    [anon_sym_break] = ACTIONS(173),
    [anon_sym_loop] = ACTIONS(173),
    [anon_sym_void] = ACTIONS(173),
    [anon_sym_int] = ACTIONS(173),
    [anon_sym_char] = ACTIONS(173),
    [anon_sym_bool] = ACTIONS(173),
    [anon_sym_float] = ACTIONS(173),
    [anon_sym_range] = ACTIONS(173),
    [anon_sym_list] = ACTIONS(173),
    [anon_sym_string] = ACTIONS(173),
    [anon_sym_line] = ACTIONS(173),
    [anon_sym_word] = ACTIONS(173),
    [anon_sym_Program] = ACTIONS(173),
    [anon_sym_Embedded] = ACTIONS(173),
    [anon_sym_Self] = ACTIONS(173),
    [anon_sym_Type] = ACTIONS(173),
    [anon_sym_Field] = ACTIONS(173),
    [anon_sym_Variable] = ACTIONS(173),
    [anon_sym_into] = ACTIONS(173),
    [anon_sym_fun] = ACTIONS(173),
    [anon_sym_may] = ACTIONS(173),
    [anon_sym_itr] = ACTIONS(173),
    [anon_sym_err] = ACTIONS(173),
    [anon_sym_ark] = ACTIONS(173),
    [anon_sym_ptr] = ACTIONS(173),
    [anon_sym_mut] = ACTIONS(173),
    [anon_sym_ref] = ACTIONS(173),
    [anon_sym_true] = ACTIONS(173),
    [anon_sym_false] = ACTIONS(173),
    [anon_sym_LT_DASH] = ACTIONS(171),
    [anon_sym_DASH_GT] = ACTIONS(171),
    [anon_sym_QMARK_QMARK] = ACTIONS(171),
    [anon_sym____] = ACTIONS(173),
    [anon_sym_BANG_EQ] = ACTIONS(171),
    [anon_sym_LT] = ACTIONS(173),
    [anon_sym_GT] = ACTIONS(173),
    [anon_sym_LT_EQ] = ACTIONS(171),
    [anon_sym_GT_EQ] = ACTIONS(171),
    [anon_sym_PLUS] = ACTIONS(171),
    [anon_sym_DASH] = ACTIONS(173),
    [anon_sym_STAR] = ACTIONS(171),
    [anon_sym_SLASH] = ACTIONS(173),
    [anon_sym_CARET] = ACTIONS(171),
    [anon_sym_BANG] = ACTIONS(173),
    [anon_sym_TILDE] = ACTIONS(171),
    [anon_sym_AMP] = ACTIONS(171),
    [anon_sym_BSLASH] = ACTIONS(171),
    [anon_sym_QMARK] = ACTIONS(173),
    [anon_sym_AT] = ACTIONS(171),
    [anon_sym_DASH_DASH] = ACTIONS(171),
    [anon_sym_GT_GT] = ACTIONS(171),
    [anon_sym_COLON] = ACTIONS(173),
    [anon_sym_SEMI] = ACTIONS(171),
    [anon_sym_COMMA] = ACTIONS(171),
    [anon_sym_LBRACE] = ACTIONS(171),
    [anon_sym_RBRACE] = ACTIONS(171),
    [anon_sym_LBRACK] = ACTIONS(171),
    [anon_sym_RBRACK] = ACTIONS(171),
    [anon_sym_LPAREN] = ACTIONS(171),
    [anon_sym_RPAREN] = ACTIONS(171),
    [sym_string] = ACTIONS(171),
    [sym_char] = ACTIONS(171),
    [sym_number] = ACTIONS(173),
  },
  [20] = {
    [sym_comment] = STATE(20),
    [ts_builtin_sym_end] = ACTIONS(129),
    [sym_identifier] = ACTIONS(133),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(133),
    [anon_sym_EQ_EQ] = ACTIONS(133),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(129),
    [anon_sym_DOT] = ACTIONS(129),
    [anon_sym_EQ_GT] = ACTIONS(129),
    [anon_sym_PIPE] = ACTIONS(133),
    [anon_sym_PIPE_GT] = ACTIONS(129),
    [anon_sym_COLON_COLON] = ACTIONS(133),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(129),
    [anon_sym_fn] = ACTIONS(133),
    [anon_sym_DOLLAR] = ACTIONS(129),
    [anon_sym_LT_LT] = ACTIONS(129),
    [sym_type_identifier] = ACTIONS(133),
    [anon_sym__] = ACTIONS(133),
    [anon_sym_PERCENT] = ACTIONS(129),
    [anon_sym_POUND] = ACTIONS(129),
    [anon_sym_new] = ACTIONS(133),
    [anon_sym_old] = ACTIONS(133),
    [anon_sym_heap] = ACTIONS(133),
    [anon_sym_const] = ACTIONS(133),
    [anon_sym_if] = ACTIONS(133),
    [anon_sym_else] = ACTIONS(133),
    [anon_sym_while] = ACTIONS(133),
    [anon_sym_for] = ACTIONS(133),
    [anon_sym_in] = ACTIONS(133),
    [anon_sym_switch] = ACTIONS(133),
    [anon_sym_case] = ACTIONS(133),
    [anon_sym_fail] = ACTIONS(133),
    [anon_sym_sec] = ACTIONS(133),
    [anon_sym_pkg] = ACTIONS(133),
    [anon_sym_use] = ACTIONS(133),
    [anon_sym_package] = ACTIONS(133),
    [anon_sym_default] = ACTIONS(133),
    [anon_sym_struct] = ACTIONS(133),
    [anon_sym_type] = ACTIONS(133),
    [anon_sym_interface] = ACTIONS(133),
    [anon_sym_alias] = ACTIONS(133),
    [anon_sym_enum] = ACTIONS(133),
    [anon_sym_prop] = ACTIONS(133),
    [anon_sym_impl] = ACTIONS(133),
    [anon_sym_return] = ACTIONS(133),
    [anon_sym_yield] = ACTIONS(133),
    [anon_sym_cascade] = ACTIONS(133),
    [anon_sym_break] = ACTIONS(133),
    [anon_sym_loop] = ACTIONS(133),
    [anon_sym_void] = ACTIONS(133),
    [anon_sym_int] = ACTIONS(133),
    [anon_sym_char] = ACTIONS(133),
    [anon_sym_bool] = ACTIONS(133),
    [anon_sym_float] = ACTIONS(133),
    [anon_sym_range] = ACTIONS(133),
    [anon_sym_list] = ACTIONS(133),
    [anon_sym_string] = ACTIONS(133),
    [anon_sym_line] = ACTIONS(133),
    [anon_sym_word] = ACTIONS(133),
    [anon_sym_Program] = ACTIONS(133),
    [anon_sym_Embedded] = ACTIONS(133),
    [anon_sym_Self] = ACTIONS(133),
    [anon_sym_Type] = ACTIONS(133),
    [anon_sym_Field] = ACTIONS(133),
    [anon_sym_Variable] = ACTIONS(133),
    [anon_sym_into] = ACTIONS(133),
    [anon_sym_fun] = ACTIONS(133),
    [anon_sym_may] = ACTIONS(133),
    [anon_sym_itr] = ACTIONS(133),
    [anon_sym_err] = ACTIONS(133),
    [anon_sym_ark] = ACTIONS(133),
    [anon_sym_ptr] = ACTIONS(133),
    [anon_sym_mut] = ACTIONS(133),
    [anon_sym_ref] = ACTIONS(133),
    [anon_sym_true] = ACTIONS(133),
    [anon_sym_false] = ACTIONS(133),
    [anon_sym_LT_DASH] = ACTIONS(129),
    [anon_sym_DASH_GT] = ACTIONS(129),
    [anon_sym_QMARK_QMARK] = ACTIONS(129),
    [anon_sym____] = ACTIONS(133),
    [anon_sym_BANG_EQ] = ACTIONS(129),
    [anon_sym_LT] = ACTIONS(133),
    [anon_sym_GT] = ACTIONS(133),
    [anon_sym_LT_EQ] = ACTIONS(129),
    [anon_sym_GT_EQ] = ACTIONS(129),
    [anon_sym_PLUS] = ACTIONS(129),
    [anon_sym_DASH] = ACTIONS(133),
    [anon_sym_STAR] = ACTIONS(129),
    [anon_sym_SLASH] = ACTIONS(133),
    [anon_sym_CARET] = ACTIONS(129),
    [anon_sym_BANG] = ACTIONS(133),
    [anon_sym_TILDE] = ACTIONS(129),
    [anon_sym_AMP] = ACTIONS(129),
    [anon_sym_BSLASH] = ACTIONS(129),
    [anon_sym_QMARK] = ACTIONS(133),
    [anon_sym_AT] = ACTIONS(129),
    [anon_sym_DASH_DASH] = ACTIONS(129),
    [anon_sym_GT_GT] = ACTIONS(129),
    [anon_sym_COLON] = ACTIONS(133),
    [anon_sym_SEMI] = ACTIONS(129),
    [anon_sym_COMMA] = ACTIONS(129),
    [anon_sym_LBRACE] = ACTIONS(129),
    [anon_sym_RBRACE] = ACTIONS(129),
    [anon_sym_LBRACK] = ACTIONS(129),
    [anon_sym_RBRACK] = ACTIONS(129),
    [anon_sym_LPAREN] = ACTIONS(129),
    [anon_sym_RPAREN] = ACTIONS(129),
    [sym_string] = ACTIONS(129),
    [sym_char] = ACTIONS(129),
    [sym_number] = ACTIONS(133),
  },
  [21] = {
    [sym_comment] = STATE(21),
    [ts_builtin_sym_end] = ACTIONS(175),
    [sym_identifier] = ACTIONS(177),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(177),
    [anon_sym_EQ_EQ] = ACTIONS(177),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(175),
    [anon_sym_DOT] = ACTIONS(175),
    [anon_sym_EQ_GT] = ACTIONS(175),
    [anon_sym_PIPE] = ACTIONS(177),
    [anon_sym_PIPE_GT] = ACTIONS(175),
    [anon_sym_COLON_COLON] = ACTIONS(177),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(175),
    [anon_sym_fn] = ACTIONS(177),
    [anon_sym_DOLLAR] = ACTIONS(175),
    [anon_sym_LT_LT] = ACTIONS(175),
    [sym_type_identifier] = ACTIONS(177),
    [anon_sym__] = ACTIONS(177),
    [anon_sym_PERCENT] = ACTIONS(175),
    [anon_sym_POUND] = ACTIONS(175),
    [anon_sym_new] = ACTIONS(177),
    [anon_sym_old] = ACTIONS(177),
    [anon_sym_heap] = ACTIONS(177),
    [anon_sym_const] = ACTIONS(177),
    [anon_sym_if] = ACTIONS(177),
    [anon_sym_else] = ACTIONS(177),
    [anon_sym_while] = ACTIONS(177),
    [anon_sym_for] = ACTIONS(177),
    [anon_sym_in] = ACTIONS(177),
    [anon_sym_switch] = ACTIONS(177),
    [anon_sym_case] = ACTIONS(177),
    [anon_sym_fail] = ACTIONS(177),
    [anon_sym_sec] = ACTIONS(177),
    [anon_sym_pkg] = ACTIONS(177),
    [anon_sym_use] = ACTIONS(177),
    [anon_sym_package] = ACTIONS(177),
    [anon_sym_default] = ACTIONS(177),
    [anon_sym_struct] = ACTIONS(177),
    [anon_sym_type] = ACTIONS(177),
    [anon_sym_interface] = ACTIONS(177),
    [anon_sym_alias] = ACTIONS(177),
    [anon_sym_enum] = ACTIONS(177),
    [anon_sym_prop] = ACTIONS(177),
    [anon_sym_impl] = ACTIONS(177),
    [anon_sym_return] = ACTIONS(177),
    [anon_sym_yield] = ACTIONS(177),
    [anon_sym_cascade] = ACTIONS(177),
    [anon_sym_break] = ACTIONS(177),
    [anon_sym_loop] = ACTIONS(177),
    [anon_sym_void] = ACTIONS(177),
    [anon_sym_int] = ACTIONS(177),
    [anon_sym_char] = ACTIONS(177),
    [anon_sym_bool] = ACTIONS(177),
    [anon_sym_float] = ACTIONS(177),
    [anon_sym_range] = ACTIONS(177),
    [anon_sym_list] = ACTIONS(177),
    [anon_sym_string] = ACTIONS(177),
    [anon_sym_line] = ACTIONS(177),
    [anon_sym_word] = ACTIONS(177),
    [anon_sym_Program] = ACTIONS(177),
    [anon_sym_Embedded] = ACTIONS(177),
    [anon_sym_Self] = ACTIONS(177),
    [anon_sym_Type] = ACTIONS(177),
    [anon_sym_Field] = ACTIONS(177),
    [anon_sym_Variable] = ACTIONS(177),
    [anon_sym_into] = ACTIONS(177),
    [anon_sym_fun] = ACTIONS(177),
    [anon_sym_may] = ACTIONS(177),
    [anon_sym_itr] = ACTIONS(177),
    [anon_sym_err] = ACTIONS(177),
    [anon_sym_ark] = ACTIONS(177),
    [anon_sym_ptr] = ACTIONS(177),
    [anon_sym_mut] = ACTIONS(177),
    [anon_sym_ref] = ACTIONS(177),
    [anon_sym_true] = ACTIONS(177),
    [anon_sym_false] = ACTIONS(177),
    [anon_sym_LT_DASH] = ACTIONS(175),
    [anon_sym_DASH_GT] = ACTIONS(175),
    [anon_sym_QMARK_QMARK] = ACTIONS(175),
    [anon_sym____] = ACTIONS(177),
    [anon_sym_BANG_EQ] = ACTIONS(175),
    [anon_sym_LT] = ACTIONS(177),
    [anon_sym_GT] = ACTIONS(177),
    [anon_sym_LT_EQ] = ACTIONS(175),
    [anon_sym_GT_EQ] = ACTIONS(175),
    [anon_sym_PLUS] = ACTIONS(175),
    [anon_sym_DASH] = ACTIONS(177),
    [anon_sym_STAR] = ACTIONS(175),
    [anon_sym_SLASH] = ACTIONS(177),
    [anon_sym_CARET] = ACTIONS(175),
    [anon_sym_BANG] = ACTIONS(177),
    [anon_sym_TILDE] = ACTIONS(175),
    [anon_sym_AMP] = ACTIONS(175),
    [anon_sym_BSLASH] = ACTIONS(175),
    [anon_sym_QMARK] = ACTIONS(177),
    [anon_sym_AT] = ACTIONS(175),
    [anon_sym_DASH_DASH] = ACTIONS(175),
    [anon_sym_GT_GT] = ACTIONS(175),
    [anon_sym_COLON] = ACTIONS(177),
    [anon_sym_SEMI] = ACTIONS(175),
    [anon_sym_COMMA] = ACTIONS(175),
    [anon_sym_LBRACE] = ACTIONS(175),
    [anon_sym_RBRACE] = ACTIONS(175),
    [anon_sym_LBRACK] = ACTIONS(175),
    [anon_sym_RBRACK] = ACTIONS(175),
    [anon_sym_LPAREN] = ACTIONS(175),
    [anon_sym_RPAREN] = ACTIONS(175),
    [sym_string] = ACTIONS(175),
    [sym_char] = ACTIONS(175),
    [sym_number] = ACTIONS(177),
  },
  [22] = {
    [sym_comment] = STATE(22),
    [ts_builtin_sym_end] = ACTIONS(179),
    [sym_identifier] = ACTIONS(181),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(181),
    [anon_sym_EQ_EQ] = ACTIONS(181),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(179),
    [anon_sym_DOT] = ACTIONS(179),
    [anon_sym_EQ_GT] = ACTIONS(179),
    [anon_sym_PIPE] = ACTIONS(181),
    [anon_sym_PIPE_GT] = ACTIONS(179),
    [anon_sym_COLON_COLON] = ACTIONS(181),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(179),
    [anon_sym_fn] = ACTIONS(181),
    [anon_sym_DOLLAR] = ACTIONS(179),
    [anon_sym_LT_LT] = ACTIONS(179),
    [sym_type_identifier] = ACTIONS(181),
    [anon_sym__] = ACTIONS(181),
    [anon_sym_PERCENT] = ACTIONS(179),
    [anon_sym_POUND] = ACTIONS(179),
    [anon_sym_new] = ACTIONS(181),
    [anon_sym_old] = ACTIONS(181),
    [anon_sym_heap] = ACTIONS(181),
    [anon_sym_const] = ACTIONS(181),
    [anon_sym_if] = ACTIONS(181),
    [anon_sym_else] = ACTIONS(181),
    [anon_sym_while] = ACTIONS(181),
    [anon_sym_for] = ACTIONS(181),
    [anon_sym_in] = ACTIONS(181),
    [anon_sym_switch] = ACTIONS(181),
    [anon_sym_case] = ACTIONS(181),
    [anon_sym_fail] = ACTIONS(181),
    [anon_sym_sec] = ACTIONS(181),
    [anon_sym_pkg] = ACTIONS(181),
    [anon_sym_use] = ACTIONS(181),
    [anon_sym_package] = ACTIONS(181),
    [anon_sym_default] = ACTIONS(181),
    [anon_sym_struct] = ACTIONS(181),
    [anon_sym_type] = ACTIONS(181),
    [anon_sym_interface] = ACTIONS(181),
    [anon_sym_alias] = ACTIONS(181),
    [anon_sym_enum] = ACTIONS(181),
    [anon_sym_prop] = ACTIONS(181),
    [anon_sym_impl] = ACTIONS(181),
    [anon_sym_return] = ACTIONS(181),
    [anon_sym_yield] = ACTIONS(181),
    [anon_sym_cascade] = ACTIONS(181),
    [anon_sym_break] = ACTIONS(181),
    [anon_sym_loop] = ACTIONS(181),
    [anon_sym_void] = ACTIONS(181),
    [anon_sym_int] = ACTIONS(181),
    [anon_sym_char] = ACTIONS(181),
    [anon_sym_bool] = ACTIONS(181),
    [anon_sym_float] = ACTIONS(181),
    [anon_sym_range] = ACTIONS(181),
    [anon_sym_list] = ACTIONS(181),
    [anon_sym_string] = ACTIONS(181),
    [anon_sym_line] = ACTIONS(181),
    [anon_sym_word] = ACTIONS(181),
    [anon_sym_Program] = ACTIONS(181),
    [anon_sym_Embedded] = ACTIONS(181),
    [anon_sym_Self] = ACTIONS(181),
    [anon_sym_Type] = ACTIONS(181),
    [anon_sym_Field] = ACTIONS(181),
    [anon_sym_Variable] = ACTIONS(181),
    [anon_sym_into] = ACTIONS(181),
    [anon_sym_fun] = ACTIONS(181),
    [anon_sym_may] = ACTIONS(181),
    [anon_sym_itr] = ACTIONS(181),
    [anon_sym_err] = ACTIONS(181),
    [anon_sym_ark] = ACTIONS(181),
    [anon_sym_ptr] = ACTIONS(181),
    [anon_sym_mut] = ACTIONS(181),
    [anon_sym_ref] = ACTIONS(181),
    [anon_sym_true] = ACTIONS(181),
    [anon_sym_false] = ACTIONS(181),
    [anon_sym_LT_DASH] = ACTIONS(179),
    [anon_sym_DASH_GT] = ACTIONS(179),
    [anon_sym_QMARK_QMARK] = ACTIONS(179),
    [anon_sym____] = ACTIONS(181),
    [anon_sym_BANG_EQ] = ACTIONS(179),
    [anon_sym_LT] = ACTIONS(181),
    [anon_sym_GT] = ACTIONS(181),
    [anon_sym_LT_EQ] = ACTIONS(179),
    [anon_sym_GT_EQ] = ACTIONS(179),
    [anon_sym_PLUS] = ACTIONS(179),
    [anon_sym_DASH] = ACTIONS(181),
    [anon_sym_STAR] = ACTIONS(179),
    [anon_sym_SLASH] = ACTIONS(181),
    [anon_sym_CARET] = ACTIONS(179),
    [anon_sym_BANG] = ACTIONS(181),
    [anon_sym_TILDE] = ACTIONS(179),
    [anon_sym_AMP] = ACTIONS(179),
    [anon_sym_BSLASH] = ACTIONS(179),
    [anon_sym_QMARK] = ACTIONS(181),
    [anon_sym_AT] = ACTIONS(179),
    [anon_sym_DASH_DASH] = ACTIONS(179),
    [anon_sym_GT_GT] = ACTIONS(179),
    [anon_sym_COLON] = ACTIONS(181),
    [anon_sym_SEMI] = ACTIONS(179),
    [anon_sym_COMMA] = ACTIONS(179),
    [anon_sym_LBRACE] = ACTIONS(179),
    [anon_sym_RBRACE] = ACTIONS(179),
    [anon_sym_LBRACK] = ACTIONS(179),
    [anon_sym_RBRACK] = ACTIONS(179),
    [anon_sym_LPAREN] = ACTIONS(179),
    [anon_sym_RPAREN] = ACTIONS(179),
    [sym_string] = ACTIONS(179),
    [sym_char] = ACTIONS(179),
    [sym_number] = ACTIONS(181),
  },
  [23] = {
    [sym_comment] = STATE(23),
    [ts_builtin_sym_end] = ACTIONS(183),
    [sym_identifier] = ACTIONS(185),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(185),
    [anon_sym_EQ_EQ] = ACTIONS(185),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(183),
    [anon_sym_DOT] = ACTIONS(183),
    [anon_sym_EQ_GT] = ACTIONS(183),
    [anon_sym_PIPE] = ACTIONS(185),
    [anon_sym_PIPE_GT] = ACTIONS(183),
    [anon_sym_COLON_COLON] = ACTIONS(185),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(183),
    [anon_sym_fn] = ACTIONS(185),
    [anon_sym_DOLLAR] = ACTIONS(183),
    [anon_sym_LT_LT] = ACTIONS(183),
    [sym_type_identifier] = ACTIONS(185),
    [anon_sym__] = ACTIONS(185),
    [anon_sym_PERCENT] = ACTIONS(183),
    [anon_sym_POUND] = ACTIONS(183),
    [anon_sym_new] = ACTIONS(185),
    [anon_sym_old] = ACTIONS(185),
    [anon_sym_heap] = ACTIONS(185),
    [anon_sym_const] = ACTIONS(185),
    [anon_sym_if] = ACTIONS(185),
    [anon_sym_else] = ACTIONS(185),
    [anon_sym_while] = ACTIONS(185),
    [anon_sym_for] = ACTIONS(185),
    [anon_sym_in] = ACTIONS(185),
    [anon_sym_switch] = ACTIONS(185),
    [anon_sym_case] = ACTIONS(185),
    [anon_sym_fail] = ACTIONS(185),
    [anon_sym_sec] = ACTIONS(185),
    [anon_sym_pkg] = ACTIONS(185),
    [anon_sym_use] = ACTIONS(185),
    [anon_sym_package] = ACTIONS(185),
    [anon_sym_default] = ACTIONS(185),
    [anon_sym_struct] = ACTIONS(185),
    [anon_sym_type] = ACTIONS(185),
    [anon_sym_interface] = ACTIONS(185),
    [anon_sym_alias] = ACTIONS(185),
    [anon_sym_enum] = ACTIONS(185),
    [anon_sym_prop] = ACTIONS(185),
    [anon_sym_impl] = ACTIONS(185),
    [anon_sym_return] = ACTIONS(185),
    [anon_sym_yield] = ACTIONS(185),
    [anon_sym_cascade] = ACTIONS(185),
    [anon_sym_break] = ACTIONS(185),
    [anon_sym_loop] = ACTIONS(185),
    [anon_sym_void] = ACTIONS(185),
    [anon_sym_int] = ACTIONS(185),
    [anon_sym_char] = ACTIONS(185),
    [anon_sym_bool] = ACTIONS(185),
    [anon_sym_float] = ACTIONS(185),
    [anon_sym_range] = ACTIONS(185),
    [anon_sym_list] = ACTIONS(185),
    [anon_sym_string] = ACTIONS(185),
    [anon_sym_line] = ACTIONS(185),
    [anon_sym_word] = ACTIONS(185),
    [anon_sym_Program] = ACTIONS(185),
    [anon_sym_Embedded] = ACTIONS(185),
    [anon_sym_Self] = ACTIONS(185),
    [anon_sym_Type] = ACTIONS(185),
    [anon_sym_Field] = ACTIONS(185),
    [anon_sym_Variable] = ACTIONS(185),
    [anon_sym_into] = ACTIONS(185),
    [anon_sym_fun] = ACTIONS(185),
    [anon_sym_may] = ACTIONS(185),
    [anon_sym_itr] = ACTIONS(185),
    [anon_sym_err] = ACTIONS(185),
    [anon_sym_ark] = ACTIONS(185),
    [anon_sym_ptr] = ACTIONS(185),
    [anon_sym_mut] = ACTIONS(185),
    [anon_sym_ref] = ACTIONS(185),
    [anon_sym_true] = ACTIONS(185),
    [anon_sym_false] = ACTIONS(185),
    [anon_sym_LT_DASH] = ACTIONS(183),
    [anon_sym_DASH_GT] = ACTIONS(183),
    [anon_sym_QMARK_QMARK] = ACTIONS(183),
    [anon_sym____] = ACTIONS(185),
    [anon_sym_BANG_EQ] = ACTIONS(183),
    [anon_sym_LT] = ACTIONS(185),
    [anon_sym_GT] = ACTIONS(185),
    [anon_sym_LT_EQ] = ACTIONS(183),
    [anon_sym_GT_EQ] = ACTIONS(183),
    [anon_sym_PLUS] = ACTIONS(183),
    [anon_sym_DASH] = ACTIONS(185),
    [anon_sym_STAR] = ACTIONS(183),
    [anon_sym_SLASH] = ACTIONS(185),
    [anon_sym_CARET] = ACTIONS(183),
    [anon_sym_BANG] = ACTIONS(185),
    [anon_sym_TILDE] = ACTIONS(183),
    [anon_sym_AMP] = ACTIONS(183),
    [anon_sym_BSLASH] = ACTIONS(183),
    [anon_sym_QMARK] = ACTIONS(185),
    [anon_sym_AT] = ACTIONS(183),
    [anon_sym_DASH_DASH] = ACTIONS(183),
    [anon_sym_GT_GT] = ACTIONS(183),
    [anon_sym_COLON] = ACTIONS(185),
    [anon_sym_SEMI] = ACTIONS(183),
    [anon_sym_COMMA] = ACTIONS(183),
    [anon_sym_LBRACE] = ACTIONS(183),
    [anon_sym_RBRACE] = ACTIONS(183),
    [anon_sym_LBRACK] = ACTIONS(183),
    [anon_sym_RBRACK] = ACTIONS(183),
    [anon_sym_LPAREN] = ACTIONS(183),
    [anon_sym_RPAREN] = ACTIONS(183),
    [sym_string] = ACTIONS(183),
    [sym_char] = ACTIONS(183),
    [sym_number] = ACTIONS(185),
  },
  [24] = {
    [sym_comment] = STATE(24),
    [ts_builtin_sym_end] = ACTIONS(187),
    [sym_identifier] = ACTIONS(189),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(189),
    [anon_sym_EQ_EQ] = ACTIONS(189),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(187),
    [anon_sym_DOT] = ACTIONS(187),
    [anon_sym_EQ_GT] = ACTIONS(187),
    [anon_sym_PIPE] = ACTIONS(189),
    [anon_sym_PIPE_GT] = ACTIONS(187),
    [anon_sym_COLON_COLON] = ACTIONS(189),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(187),
    [anon_sym_fn] = ACTIONS(189),
    [anon_sym_DOLLAR] = ACTIONS(187),
    [anon_sym_LT_LT] = ACTIONS(187),
    [sym_type_identifier] = ACTIONS(189),
    [anon_sym__] = ACTIONS(189),
    [anon_sym_PERCENT] = ACTIONS(187),
    [anon_sym_POUND] = ACTIONS(187),
    [anon_sym_new] = ACTIONS(189),
    [anon_sym_old] = ACTIONS(189),
    [anon_sym_heap] = ACTIONS(189),
    [anon_sym_const] = ACTIONS(189),
    [anon_sym_if] = ACTIONS(189),
    [anon_sym_else] = ACTIONS(189),
    [anon_sym_while] = ACTIONS(189),
    [anon_sym_for] = ACTIONS(189),
    [anon_sym_in] = ACTIONS(189),
    [anon_sym_switch] = ACTIONS(189),
    [anon_sym_case] = ACTIONS(189),
    [anon_sym_fail] = ACTIONS(189),
    [anon_sym_sec] = ACTIONS(189),
    [anon_sym_pkg] = ACTIONS(189),
    [anon_sym_use] = ACTIONS(189),
    [anon_sym_package] = ACTIONS(189),
    [anon_sym_default] = ACTIONS(189),
    [anon_sym_struct] = ACTIONS(189),
    [anon_sym_type] = ACTIONS(189),
    [anon_sym_interface] = ACTIONS(189),
    [anon_sym_alias] = ACTIONS(189),
    [anon_sym_enum] = ACTIONS(189),
    [anon_sym_prop] = ACTIONS(189),
    [anon_sym_impl] = ACTIONS(189),
    [anon_sym_return] = ACTIONS(189),
    [anon_sym_yield] = ACTIONS(189),
    [anon_sym_cascade] = ACTIONS(189),
    [anon_sym_break] = ACTIONS(189),
    [anon_sym_loop] = ACTIONS(189),
    [anon_sym_void] = ACTIONS(189),
    [anon_sym_int] = ACTIONS(189),
    [anon_sym_char] = ACTIONS(189),
    [anon_sym_bool] = ACTIONS(189),
    [anon_sym_float] = ACTIONS(189),
    [anon_sym_range] = ACTIONS(189),
    [anon_sym_list] = ACTIONS(189),
    [anon_sym_string] = ACTIONS(189),
    [anon_sym_line] = ACTIONS(189),
    [anon_sym_word] = ACTIONS(189),
    [anon_sym_Program] = ACTIONS(189),
    [anon_sym_Embedded] = ACTIONS(189),
    [anon_sym_Self] = ACTIONS(189),
    [anon_sym_Type] = ACTIONS(189),
    [anon_sym_Field] = ACTIONS(189),
    [anon_sym_Variable] = ACTIONS(189),
    [anon_sym_into] = ACTIONS(189),
    [anon_sym_fun] = ACTIONS(189),
    [anon_sym_may] = ACTIONS(189),
    [anon_sym_itr] = ACTIONS(189),
    [anon_sym_err] = ACTIONS(189),
    [anon_sym_ark] = ACTIONS(189),
    [anon_sym_ptr] = ACTIONS(189),
    [anon_sym_mut] = ACTIONS(189),
    [anon_sym_ref] = ACTIONS(189),
    [anon_sym_true] = ACTIONS(189),
    [anon_sym_false] = ACTIONS(189),
    [anon_sym_LT_DASH] = ACTIONS(187),
    [anon_sym_DASH_GT] = ACTIONS(187),
    [anon_sym_QMARK_QMARK] = ACTIONS(187),
    [anon_sym____] = ACTIONS(189),
    [anon_sym_BANG_EQ] = ACTIONS(187),
    [anon_sym_LT] = ACTIONS(189),
    [anon_sym_GT] = ACTIONS(189),
    [anon_sym_LT_EQ] = ACTIONS(187),
    [anon_sym_GT_EQ] = ACTIONS(187),
    [anon_sym_PLUS] = ACTIONS(187),
    [anon_sym_DASH] = ACTIONS(189),
    [anon_sym_STAR] = ACTIONS(187),
    [anon_sym_SLASH] = ACTIONS(189),
    [anon_sym_CARET] = ACTIONS(187),
    [anon_sym_BANG] = ACTIONS(189),
    [anon_sym_TILDE] = ACTIONS(187),
    [anon_sym_AMP] = ACTIONS(187),
    [anon_sym_BSLASH] = ACTIONS(187),
    [anon_sym_QMARK] = ACTIONS(189),
    [anon_sym_AT] = ACTIONS(187),
    [anon_sym_DASH_DASH] = ACTIONS(187),
    [anon_sym_GT_GT] = ACTIONS(187),
    [anon_sym_COLON] = ACTIONS(189),
    [anon_sym_SEMI] = ACTIONS(187),
    [anon_sym_COMMA] = ACTIONS(187),
    [anon_sym_LBRACE] = ACTIONS(187),
    [anon_sym_RBRACE] = ACTIONS(187),
    [anon_sym_LBRACK] = ACTIONS(187),
    [anon_sym_RBRACK] = ACTIONS(187),
    [anon_sym_LPAREN] = ACTIONS(187),
    [anon_sym_RPAREN] = ACTIONS(187),
    [sym_string] = ACTIONS(187),
    [sym_char] = ACTIONS(187),
    [sym_number] = ACTIONS(189),
  },
  [25] = {
    [sym_comment] = STATE(25),
    [ts_builtin_sym_end] = ACTIONS(191),
    [sym_identifier] = ACTIONS(193),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(193),
    [anon_sym_EQ_EQ] = ACTIONS(193),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(191),
    [anon_sym_DOT] = ACTIONS(191),
    [anon_sym_EQ_GT] = ACTIONS(191),
    [anon_sym_PIPE] = ACTIONS(193),
    [anon_sym_PIPE_GT] = ACTIONS(191),
    [anon_sym_COLON_COLON] = ACTIONS(193),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(191),
    [anon_sym_fn] = ACTIONS(193),
    [anon_sym_DOLLAR] = ACTIONS(191),
    [anon_sym_LT_LT] = ACTIONS(191),
    [sym_type_identifier] = ACTIONS(193),
    [anon_sym__] = ACTIONS(193),
    [anon_sym_PERCENT] = ACTIONS(191),
    [anon_sym_POUND] = ACTIONS(191),
    [anon_sym_new] = ACTIONS(193),
    [anon_sym_old] = ACTIONS(193),
    [anon_sym_heap] = ACTIONS(193),
    [anon_sym_const] = ACTIONS(193),
    [anon_sym_if] = ACTIONS(193),
    [anon_sym_else] = ACTIONS(193),
    [anon_sym_while] = ACTIONS(193),
    [anon_sym_for] = ACTIONS(193),
    [anon_sym_in] = ACTIONS(193),
    [anon_sym_switch] = ACTIONS(193),
    [anon_sym_case] = ACTIONS(193),
    [anon_sym_fail] = ACTIONS(193),
    [anon_sym_sec] = ACTIONS(193),
    [anon_sym_pkg] = ACTIONS(193),
    [anon_sym_use] = ACTIONS(193),
    [anon_sym_package] = ACTIONS(193),
    [anon_sym_default] = ACTIONS(193),
    [anon_sym_struct] = ACTIONS(193),
    [anon_sym_type] = ACTIONS(193),
    [anon_sym_interface] = ACTIONS(193),
    [anon_sym_alias] = ACTIONS(193),
    [anon_sym_enum] = ACTIONS(193),
    [anon_sym_prop] = ACTIONS(193),
    [anon_sym_impl] = ACTIONS(193),
    [anon_sym_return] = ACTIONS(193),
    [anon_sym_yield] = ACTIONS(193),
    [anon_sym_cascade] = ACTIONS(193),
    [anon_sym_break] = ACTIONS(193),
    [anon_sym_loop] = ACTIONS(193),
    [anon_sym_void] = ACTIONS(193),
    [anon_sym_int] = ACTIONS(193),
    [anon_sym_char] = ACTIONS(193),
    [anon_sym_bool] = ACTIONS(193),
    [anon_sym_float] = ACTIONS(193),
    [anon_sym_range] = ACTIONS(193),
    [anon_sym_list] = ACTIONS(193),
    [anon_sym_string] = ACTIONS(193),
    [anon_sym_line] = ACTIONS(193),
    [anon_sym_word] = ACTIONS(193),
    [anon_sym_Program] = ACTIONS(193),
    [anon_sym_Embedded] = ACTIONS(193),
    [anon_sym_Self] = ACTIONS(193),
    [anon_sym_Type] = ACTIONS(193),
    [anon_sym_Field] = ACTIONS(193),
    [anon_sym_Variable] = ACTIONS(193),
    [anon_sym_into] = ACTIONS(193),
    [anon_sym_fun] = ACTIONS(193),
    [anon_sym_may] = ACTIONS(193),
    [anon_sym_itr] = ACTIONS(193),
    [anon_sym_err] = ACTIONS(193),
    [anon_sym_ark] = ACTIONS(193),
    [anon_sym_ptr] = ACTIONS(193),
    [anon_sym_mut] = ACTIONS(193),
    [anon_sym_ref] = ACTIONS(193),
    [anon_sym_true] = ACTIONS(193),
    [anon_sym_false] = ACTIONS(193),
    [anon_sym_LT_DASH] = ACTIONS(191),
    [anon_sym_DASH_GT] = ACTIONS(191),
    [anon_sym_QMARK_QMARK] = ACTIONS(191),
    [anon_sym____] = ACTIONS(193),
    [anon_sym_BANG_EQ] = ACTIONS(191),
    [anon_sym_LT] = ACTIONS(193),
    [anon_sym_GT] = ACTIONS(193),
    [anon_sym_LT_EQ] = ACTIONS(191),
    [anon_sym_GT_EQ] = ACTIONS(191),
    [anon_sym_PLUS] = ACTIONS(191),
    [anon_sym_DASH] = ACTIONS(193),
    [anon_sym_STAR] = ACTIONS(191),
    [anon_sym_SLASH] = ACTIONS(193),
    [anon_sym_CARET] = ACTIONS(191),
    [anon_sym_BANG] = ACTIONS(193),
    [anon_sym_TILDE] = ACTIONS(191),
    [anon_sym_AMP] = ACTIONS(191),
    [anon_sym_BSLASH] = ACTIONS(191),
    [anon_sym_QMARK] = ACTIONS(193),
    [anon_sym_AT] = ACTIONS(191),
    [anon_sym_DASH_DASH] = ACTIONS(191),
    [anon_sym_GT_GT] = ACTIONS(191),
    [anon_sym_COLON] = ACTIONS(193),
    [anon_sym_SEMI] = ACTIONS(191),
    [anon_sym_COMMA] = ACTIONS(191),
    [anon_sym_LBRACE] = ACTIONS(191),
    [anon_sym_RBRACE] = ACTIONS(191),
    [anon_sym_LBRACK] = ACTIONS(191),
    [anon_sym_RBRACK] = ACTIONS(191),
    [anon_sym_LPAREN] = ACTIONS(191),
    [anon_sym_RPAREN] = ACTIONS(191),
    [sym_string] = ACTIONS(191),
    [sym_char] = ACTIONS(191),
    [sym_number] = ACTIONS(193),
  },
  [26] = {
    [sym_comment] = STATE(26),
    [ts_builtin_sym_end] = ACTIONS(195),
    [sym_identifier] = ACTIONS(197),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(197),
    [anon_sym_EQ_EQ] = ACTIONS(197),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(195),
    [anon_sym_DOT] = ACTIONS(195),
    [anon_sym_EQ_GT] = ACTIONS(195),
    [anon_sym_PIPE] = ACTIONS(197),
    [anon_sym_PIPE_GT] = ACTIONS(195),
    [anon_sym_COLON_COLON] = ACTIONS(197),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(195),
    [anon_sym_fn] = ACTIONS(197),
    [anon_sym_DOLLAR] = ACTIONS(195),
    [anon_sym_LT_LT] = ACTIONS(195),
    [sym_type_identifier] = ACTIONS(197),
    [anon_sym__] = ACTIONS(197),
    [anon_sym_PERCENT] = ACTIONS(195),
    [anon_sym_POUND] = ACTIONS(195),
    [anon_sym_new] = ACTIONS(197),
    [anon_sym_old] = ACTIONS(197),
    [anon_sym_heap] = ACTIONS(197),
    [anon_sym_const] = ACTIONS(197),
    [anon_sym_if] = ACTIONS(197),
    [anon_sym_else] = ACTIONS(197),
    [anon_sym_while] = ACTIONS(197),
    [anon_sym_for] = ACTIONS(197),
    [anon_sym_in] = ACTIONS(197),
    [anon_sym_switch] = ACTIONS(197),
    [anon_sym_case] = ACTIONS(197),
    [anon_sym_fail] = ACTIONS(197),
    [anon_sym_sec] = ACTIONS(197),
    [anon_sym_pkg] = ACTIONS(197),
    [anon_sym_use] = ACTIONS(197),
    [anon_sym_package] = ACTIONS(197),
    [anon_sym_default] = ACTIONS(197),
    [anon_sym_struct] = ACTIONS(197),
    [anon_sym_type] = ACTIONS(197),
    [anon_sym_interface] = ACTIONS(197),
    [anon_sym_alias] = ACTIONS(197),
    [anon_sym_enum] = ACTIONS(197),
    [anon_sym_prop] = ACTIONS(197),
    [anon_sym_impl] = ACTIONS(197),
    [anon_sym_return] = ACTIONS(197),
    [anon_sym_yield] = ACTIONS(197),
    [anon_sym_cascade] = ACTIONS(197),
    [anon_sym_break] = ACTIONS(197),
    [anon_sym_loop] = ACTIONS(197),
    [anon_sym_void] = ACTIONS(197),
    [anon_sym_int] = ACTIONS(197),
    [anon_sym_char] = ACTIONS(197),
    [anon_sym_bool] = ACTIONS(197),
    [anon_sym_float] = ACTIONS(197),
    [anon_sym_range] = ACTIONS(197),
    [anon_sym_list] = ACTIONS(197),
    [anon_sym_string] = ACTIONS(197),
    [anon_sym_line] = ACTIONS(197),
    [anon_sym_word] = ACTIONS(197),
    [anon_sym_Program] = ACTIONS(197),
    [anon_sym_Embedded] = ACTIONS(197),
    [anon_sym_Self] = ACTIONS(197),
    [anon_sym_Type] = ACTIONS(197),
    [anon_sym_Field] = ACTIONS(197),
    [anon_sym_Variable] = ACTIONS(197),
    [anon_sym_into] = ACTIONS(197),
    [anon_sym_fun] = ACTIONS(197),
    [anon_sym_may] = ACTIONS(197),
    [anon_sym_itr] = ACTIONS(197),
    [anon_sym_err] = ACTIONS(197),
    [anon_sym_ark] = ACTIONS(197),
    [anon_sym_ptr] = ACTIONS(197),
    [anon_sym_mut] = ACTIONS(197),
    [anon_sym_ref] = ACTIONS(197),
    [anon_sym_true] = ACTIONS(197),
    [anon_sym_false] = ACTIONS(197),
    [anon_sym_LT_DASH] = ACTIONS(195),
    [anon_sym_DASH_GT] = ACTIONS(195),
    [anon_sym_QMARK_QMARK] = ACTIONS(195),
    [anon_sym____] = ACTIONS(197),
    [anon_sym_BANG_EQ] = ACTIONS(195),
    [anon_sym_LT] = ACTIONS(197),
    [anon_sym_GT] = ACTIONS(197),
    [anon_sym_LT_EQ] = ACTIONS(195),
    [anon_sym_GT_EQ] = ACTIONS(195),
    [anon_sym_PLUS] = ACTIONS(195),
    [anon_sym_DASH] = ACTIONS(197),
    [anon_sym_STAR] = ACTIONS(195),
    [anon_sym_SLASH] = ACTIONS(197),
    [anon_sym_CARET] = ACTIONS(195),
    [anon_sym_BANG] = ACTIONS(197),
    [anon_sym_TILDE] = ACTIONS(195),
    [anon_sym_AMP] = ACTIONS(195),
    [anon_sym_BSLASH] = ACTIONS(195),
    [anon_sym_QMARK] = ACTIONS(197),
    [anon_sym_AT] = ACTIONS(195),
    [anon_sym_DASH_DASH] = ACTIONS(195),
    [anon_sym_GT_GT] = ACTIONS(195),
    [anon_sym_COLON] = ACTIONS(197),
    [anon_sym_SEMI] = ACTIONS(195),
    [anon_sym_COMMA] = ACTIONS(195),
    [anon_sym_LBRACE] = ACTIONS(195),
    [anon_sym_RBRACE] = ACTIONS(195),
    [anon_sym_LBRACK] = ACTIONS(195),
    [anon_sym_RBRACK] = ACTIONS(195),
    [anon_sym_LPAREN] = ACTIONS(195),
    [anon_sym_RPAREN] = ACTIONS(195),
    [sym_string] = ACTIONS(195),
    [sym_char] = ACTIONS(195),
    [sym_number] = ACTIONS(197),
  },
  [27] = {
    [sym_comment] = STATE(27),
    [ts_builtin_sym_end] = ACTIONS(199),
    [sym_identifier] = ACTIONS(201),
    [aux_sym_comment_token1] = ACTIONS(3),
    [anon_sym_EQ] = ACTIONS(201),
    [anon_sym_EQ_EQ] = ACTIONS(201),
    [anon_sym_EQ_EQ_EQ] = ACTIONS(199),
    [anon_sym_DOT] = ACTIONS(199),
    [anon_sym_EQ_GT] = ACTIONS(199),
    [anon_sym_PIPE] = ACTIONS(201),
    [anon_sym_PIPE_GT] = ACTIONS(199),
    [anon_sym_COLON_COLON] = ACTIONS(201),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(199),
    [anon_sym_fn] = ACTIONS(201),
    [anon_sym_DOLLAR] = ACTIONS(199),
    [anon_sym_LT_LT] = ACTIONS(199),
    [sym_type_identifier] = ACTIONS(201),
    [anon_sym__] = ACTIONS(201),
    [anon_sym_PERCENT] = ACTIONS(199),
    [anon_sym_POUND] = ACTIONS(199),
    [anon_sym_new] = ACTIONS(201),
    [anon_sym_old] = ACTIONS(201),
    [anon_sym_heap] = ACTIONS(201),
    [anon_sym_const] = ACTIONS(201),
    [anon_sym_if] = ACTIONS(201),
    [anon_sym_else] = ACTIONS(201),
    [anon_sym_while] = ACTIONS(201),
    [anon_sym_for] = ACTIONS(201),
    [anon_sym_in] = ACTIONS(201),
    [anon_sym_switch] = ACTIONS(201),
    [anon_sym_case] = ACTIONS(201),
    [anon_sym_fail] = ACTIONS(201),
    [anon_sym_sec] = ACTIONS(201),
    [anon_sym_pkg] = ACTIONS(201),
    [anon_sym_use] = ACTIONS(201),
    [anon_sym_package] = ACTIONS(201),
    [anon_sym_default] = ACTIONS(201),
    [anon_sym_struct] = ACTIONS(201),
    [anon_sym_type] = ACTIONS(201),
    [anon_sym_interface] = ACTIONS(201),
    [anon_sym_alias] = ACTIONS(201),
    [anon_sym_enum] = ACTIONS(201),
    [anon_sym_prop] = ACTIONS(201),
    [anon_sym_impl] = ACTIONS(201),
    [anon_sym_return] = ACTIONS(201),
    [anon_sym_yield] = ACTIONS(201),
    [anon_sym_cascade] = ACTIONS(201),
    [anon_sym_break] = ACTIONS(201),
    [anon_sym_loop] = ACTIONS(201),
    [anon_sym_void] = ACTIONS(201),
    [anon_sym_int] = ACTIONS(201),
    [anon_sym_char] = ACTIONS(201),
    [anon_sym_bool] = ACTIONS(201),
    [anon_sym_float] = ACTIONS(201),
    [anon_sym_range] = ACTIONS(201),
    [anon_sym_list] = ACTIONS(201),
    [anon_sym_string] = ACTIONS(201),
    [anon_sym_line] = ACTIONS(201),
    [anon_sym_word] = ACTIONS(201),
    [anon_sym_Program] = ACTIONS(201),
    [anon_sym_Embedded] = ACTIONS(201),
    [anon_sym_Self] = ACTIONS(201),
    [anon_sym_Type] = ACTIONS(201),
    [anon_sym_Field] = ACTIONS(201),
    [anon_sym_Variable] = ACTIONS(201),
    [anon_sym_into] = ACTIONS(201),
    [anon_sym_fun] = ACTIONS(201),
    [anon_sym_may] = ACTIONS(201),
    [anon_sym_itr] = ACTIONS(201),
    [anon_sym_err] = ACTIONS(201),
    [anon_sym_ark] = ACTIONS(201),
    [anon_sym_ptr] = ACTIONS(201),
    [anon_sym_mut] = ACTIONS(201),
    [anon_sym_ref] = ACTIONS(201),
    [anon_sym_true] = ACTIONS(201),
    [anon_sym_false] = ACTIONS(201),
    [anon_sym_LT_DASH] = ACTIONS(199),
    [anon_sym_DASH_GT] = ACTIONS(199),
    [anon_sym_QMARK_QMARK] = ACTIONS(199),
    [anon_sym____] = ACTIONS(201),
    [anon_sym_BANG_EQ] = ACTIONS(199),
    [anon_sym_LT] = ACTIONS(201),
    [anon_sym_GT] = ACTIONS(201),
    [anon_sym_LT_EQ] = ACTIONS(199),
    [anon_sym_GT_EQ] = ACTIONS(199),
    [anon_sym_PLUS] = ACTIONS(199),
    [anon_sym_DASH] = ACTIONS(201),
    [anon_sym_STAR] = ACTIONS(199),
    [anon_sym_SLASH] = ACTIONS(201),
    [anon_sym_CARET] = ACTIONS(199),
    [anon_sym_BANG] = ACTIONS(201),
    [anon_sym_TILDE] = ACTIONS(199),
    [anon_sym_AMP] = ACTIONS(199),
    [anon_sym_BSLASH] = ACTIONS(199),
    [anon_sym_QMARK] = ACTIONS(201),
    [anon_sym_AT] = ACTIONS(199),
    [anon_sym_DASH_DASH] = ACTIONS(199),
    [anon_sym_GT_GT] = ACTIONS(199),
    [anon_sym_COLON] = ACTIONS(201),
    [anon_sym_SEMI] = ACTIONS(199),
    [anon_sym_COMMA] = ACTIONS(199),
    [anon_sym_LBRACE] = ACTIONS(199),
    [anon_sym_RBRACE] = ACTIONS(199),
    [anon_sym_LBRACK] = ACTIONS(199),
    [anon_sym_RBRACK] = ACTIONS(199),
    [anon_sym_LPAREN] = ACTIONS(199),
    [anon_sym_RPAREN] = ACTIONS(199),
    [sym_string] = ACTIONS(199),
    [sym_char] = ACTIONS(199),
    [sym_number] = ACTIONS(201),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 5,
    ACTIONS(203), 1,
      aux_sym_comment_token1,
    ACTIONS(207), 1,
      anon_sym_EQ_EQ_EQ,
    STATE(28), 1,
      sym_comment,
    STATE(29), 1,
      aux_sym__doc_content,
    ACTIONS(205), 3,
      aux_sym__doc_content_token1,
      anon_sym_EQ,
      anon_sym_EQ_EQ,
  [18] = 5,
    ACTIONS(203), 1,
      aux_sym_comment_token1,
    ACTIONS(209), 1,
      anon_sym_EQ_EQ_EQ,
    STATE(29), 1,
      sym_comment,
    STATE(30), 1,
      aux_sym__doc_content,
    ACTIONS(205), 3,
      aux_sym__doc_content_token1,
      anon_sym_EQ,
      anon_sym_EQ_EQ,
  [36] = 4,
    ACTIONS(203), 1,
      aux_sym_comment_token1,
    ACTIONS(214), 1,
      anon_sym_EQ_EQ_EQ,
    STATE(30), 2,
      sym_comment,
      aux_sym__doc_content,
    ACTIONS(211), 3,
      aux_sym__doc_content_token1,
      anon_sym_EQ,
      anon_sym_EQ_EQ,
  [52] = 3,
    ACTIONS(203), 1,
      aux_sym_comment_token1,
    STATE(31), 1,
      sym_comment,
    ACTIONS(216), 4,
      aux_sym__doc_content_token1,
      anon_sym_EQ,
      anon_sym_EQ_EQ,
      anon_sym_EQ_EQ_EQ,
  [65] = 3,
    ACTIONS(3), 1,
      aux_sym_comment_token1,
    ACTIONS(218), 1,
      ts_builtin_sym_end,
    STATE(32), 1,
      sym_comment,
  [75] = 3,
    ACTIONS(3), 1,
      aux_sym_comment_token1,
    ACTIONS(220), 1,
      sym_identifier,
    STATE(33), 1,
      sym_comment,
  [85] = 3,
    ACTIONS(3), 1,
      aux_sym_comment_token1,
    ACTIONS(222), 1,
      sym_type_identifier,
    STATE(34), 1,
      sym_comment,
  [95] = 1,
    ACTIONS(224), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(28)] = 0,
  [SMALL_STATE(29)] = 18,
  [SMALL_STATE(30)] = 36,
  [SMALL_STATE(31)] = 52,
  [SMALL_STATE(32)] = 65,
  [SMALL_STATE(33)] = 75,
  [SMALL_STATE(34)] = 85,
  [SMALL_STATE(35)] = 95,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [19] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [41] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [49] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [51] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(5),
  [54] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(20),
  [57] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(28),
  [60] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(33),
  [63] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(6),
  [66] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(6),
  [69] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(20),
  [72] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(7),
  [75] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(8),
  [78] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(34),
  [81] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(10),
  [84] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(11),
  [87] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(12),
  [90] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(13),
  [93] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(14),
  [96] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(15),
  [99] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(16),
  [102] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(17),
  [105] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(18),
  [108] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(18),
  [111] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pipe_usage, 2, .production_id = 2),
  [113] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pipe_usage, 2, .production_id = 2),
  [115] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [119] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__item, 1),
  [121] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__item, 1),
  [123] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [125] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [127] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operator, 1),
  [131] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [133] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operator, 1),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_keyword, 1),
  [137] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_keyword, 1),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_usage, 1),
  [143] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_usage, 1),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_procedure_definition, 3, .production_id = 6),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_procedure_definition, 3, .production_id = 6),
  [149] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_terminator, 1),
  [153] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_terminator, 1),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_keyword, 1),
  [157] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_keyword, 1),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_modifier, 1),
  [161] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_modifier, 1),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean, 1),
  [165] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_boolean, 1),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_punctuation, 1),
  [169] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_punctuation, 1),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_documentation, 3),
  [173] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_documentation, 3),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 1),
  [177] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 1),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_usage, 2, .production_id = 5),
  [181] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_func_usage, 2, .production_id = 5),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_procedure_definition, 2, .production_id = 5),
  [185] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_procedure_definition, 2, .production_id = 5),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_documentation, 2),
  [189] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_documentation, 2),
  [191] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_usage, 2, .production_id = 4),
  [193] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_usage, 2, .production_id = 4),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_field, 2, .production_id = 1),
  [197] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_field, 2, .production_id = 1),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_procedure_definition, 2, .production_id = 3),
  [201] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_procedure_definition, 2, .production_id = 3),
  [203] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [205] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [207] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [209] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [211] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__doc_content, 2), SHIFT_REPEAT(31),
  [214] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__doc_content, 2),
  [216] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym__doc_content, 1),
  [218] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [222] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment, 1),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_cease(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .keyword_lex_fn = ts_lex_keywords,
    .keyword_capture_token = sym_identifier,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
