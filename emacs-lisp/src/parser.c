#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 23
#define LARGE_STATE_COUNT 21
#define SYMBOL_COUNT 128
#define ALIAS_COUNT 0
#define TOKEN_COUNT 114
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 2
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 5

enum {
  sym_identifier = 1,
  sym_comment = 2,
  anon_sym_PIPE = 3,
  anon_sym_PIPE_GT = 4,
  anon_sym_COLON_COLON = 5,
  anon_sym_COLON_COLON_COLON = 6,
  anon_sym_DOLLAR = 7,
  anon_sym_LT_LT = 8,
  sym_type_identifier = 9,
  anon_sym__ = 10,
  anon_sym_PERCENT = 11,
  anon_sym_POUND = 12,
  anon_sym_new = 13,
  anon_sym_old = 14,
  anon_sym_heap = 15,
  anon_sym_const = 16,
  anon_sym_if = 17,
  anon_sym_else = 18,
  anon_sym_while = 19,
  anon_sym_for = 20,
  anon_sym_in = 21,
  anon_sym_switch = 22,
  anon_sym_case = 23,
  anon_sym_fail = 24,
  anon_sym_say = 25,
  anon_sym_sayif = 26,
  anon_sym_debug = 27,
  anon_sym_debugif = 28,
  anon_sym_print = 29,
  anon_sym_printif = 30,
  anon_sym_use = 31,
  anon_sym_package = 32,
  anon_sym_default = 33,
  anon_sym_set = 34,
  anon_sym_struct = 35,
  anon_sym_type = 36,
  anon_sym_interface = 37,
  anon_sym_alias = 38,
  anon_sym_enum = 39,
  anon_sym_prop = 40,
  anon_sym_impl = 41,
  anon_sym_return = 42,
  anon_sym_yield = 43,
  anon_sym_cascade = 44,
  anon_sym_break = 45,
  anon_sym_loop = 46,
  anon_sym_void = 47,
  anon_sym_int = 48,
  anon_sym_char = 49,
  anon_sym_bool = 50,
  anon_sym_float = 51,
  anon_sym_range = 52,
  anon_sym_list = 53,
  anon_sym_string = 54,
  anon_sym_line = 55,
  anon_sym_word = 56,
  anon_sym_Program = 57,
  anon_sym_Embedded = 58,
  anon_sym_Self = 59,
  anon_sym_Type = 60,
  anon_sym_Field = 61,
  anon_sym_Variable = 62,
  anon_sym_into = 63,
  anon_sym_fun = 64,
  anon_sym_may = 65,
  anon_sym_itr = 66,
  anon_sym_err = 67,
  anon_sym_ark = 68,
  anon_sym_ptr = 69,
  anon_sym_mut = 70,
  anon_sym_ref = 71,
  anon_sym_sec = 72,
  anon_sym_pkg = 73,
  anon_sym_true = 74,
  anon_sym_false = 75,
  anon_sym_EQ = 76,
  anon_sym_LT_DASH = 77,
  anon_sym_DASH_GT = 78,
  anon_sym_EQ_GT = 79,
  anon_sym_QMARK_QMARK = 80,
  anon_sym____ = 81,
  anon_sym_EQ_EQ = 82,
  anon_sym_BANG_EQ = 83,
  anon_sym_LT = 84,
  anon_sym_GT = 85,
  anon_sym_LT_EQ = 86,
  anon_sym_GT_EQ = 87,
  anon_sym_PLUS = 88,
  anon_sym_DASH = 89,
  anon_sym_STAR = 90,
  anon_sym_SLASH = 91,
  anon_sym_CARET = 92,
  anon_sym_BANG = 93,
  anon_sym_TILDE = 94,
  anon_sym_AMP = 95,
  anon_sym_BSLASH = 96,
  anon_sym_QMARK = 97,
  anon_sym_AT = 98,
  anon_sym_DASH_DASH = 99,
  anon_sym_GT_GT = 100,
  anon_sym_COLON = 101,
  anon_sym_SEMI = 102,
  anon_sym_COMMA = 103,
  anon_sym_DOT = 104,
  anon_sym_LBRACE = 105,
  anon_sym_RBRACE = 106,
  anon_sym_LBRACK = 107,
  anon_sym_RBRACK = 108,
  anon_sym_LPAREN = 109,
  anon_sym_RPAREN = 110,
  sym_string = 111,
  sym_char = 112,
  sym_number = 113,
  sym_source_file = 114,
  sym__item = 115,
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
  [sym_comment] = "comment",
  [anon_sym_PIPE] = "|",
  [anon_sym_PIPE_GT] = "|>",
  [anon_sym_COLON_COLON] = "::",
  [anon_sym_COLON_COLON_COLON] = ":::",
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
  [anon_sym_say] = "say",
  [anon_sym_sayif] = "sayif",
  [anon_sym_debug] = "debug",
  [anon_sym_debugif] = "debugif",
  [anon_sym_print] = "print",
  [anon_sym_printif] = "printif",
  [anon_sym_use] = "use",
  [anon_sym_package] = "package",
  [anon_sym_default] = "default",
  [anon_sym_set] = "set",
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
  [anon_sym_sec] = "sec",
  [anon_sym_pkg] = "pkg",
  [anon_sym_true] = "true",
  [anon_sym_false] = "false",
  [anon_sym_EQ] = "=",
  [anon_sym_LT_DASH] = "<-",
  [anon_sym_DASH_GT] = "->",
  [anon_sym_EQ_GT] = "=>",
  [anon_sym_QMARK_QMARK] = "\?\?",
  [anon_sym____] = "___",
  [anon_sym_EQ_EQ] = "==",
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
  [anon_sym_DOT] = ".",
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
  [sym__item] = "_item",
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
  [sym_comment] = sym_comment,
  [anon_sym_PIPE] = anon_sym_PIPE,
  [anon_sym_PIPE_GT] = anon_sym_PIPE_GT,
  [anon_sym_COLON_COLON] = anon_sym_COLON_COLON,
  [anon_sym_COLON_COLON_COLON] = anon_sym_COLON_COLON_COLON,
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
  [anon_sym_say] = anon_sym_say,
  [anon_sym_sayif] = anon_sym_sayif,
  [anon_sym_debug] = anon_sym_debug,
  [anon_sym_debugif] = anon_sym_debugif,
  [anon_sym_print] = anon_sym_print,
  [anon_sym_printif] = anon_sym_printif,
  [anon_sym_use] = anon_sym_use,
  [anon_sym_package] = anon_sym_package,
  [anon_sym_default] = anon_sym_default,
  [anon_sym_set] = anon_sym_set,
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
  [anon_sym_sec] = anon_sym_sec,
  [anon_sym_pkg] = anon_sym_pkg,
  [anon_sym_true] = anon_sym_true,
  [anon_sym_false] = anon_sym_false,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_LT_DASH] = anon_sym_LT_DASH,
  [anon_sym_DASH_GT] = anon_sym_DASH_GT,
  [anon_sym_EQ_GT] = anon_sym_EQ_GT,
  [anon_sym_QMARK_QMARK] = anon_sym_QMARK_QMARK,
  [anon_sym____] = anon_sym____,
  [anon_sym_EQ_EQ] = anon_sym_EQ_EQ,
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
  [anon_sym_DOT] = anon_sym_DOT,
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
  [sym__item] = sym__item,
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
  [sym_comment] = {
    .visible = true,
    .named = true,
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
  [anon_sym_say] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_sayif] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_debug] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_debugif] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_print] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_printif] = {
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
  [anon_sym_set] = {
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
  [anon_sym_sec] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_pkg] = {
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
  [anon_sym_EQ] = {
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
  [anon_sym_EQ_GT] = {
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
  [anon_sym_EQ_EQ] = {
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
  [anon_sym_DOT] = {
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
  [sym__item] = {
    .visible = false,
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
  field_prefix = 2,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_name] = "name",
  [field_prefix] = "prefix",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 1},
  [2] = {.index = 1, .length = 2},
  [3] = {.index = 3, .length = 1},
  [4] = {.index = 0, .length = 1},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_name, 1},
  [1] =
    {field_name, 1},
    {field_prefix, 0},
  [3] =
    {field_name, 0},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
  [2] = {
    [0] = sym_operator,
  },
  [3] = {
    [1] = sym_operator,
  },
  [4] = {
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
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(7);
      if (lookahead == '!') ADVANCE(34);
      if (lookahead == '"') ADVANCE(1);
      if (lookahead == '#') ADVANCE(17);
      if (lookahead == '$') ADVANCE(13);
      if (lookahead == '%') ADVANCE(16);
      if (lookahead == '&') ADVANCE(36);
      if (lookahead == '\'') ADVANCE(3);
      if (lookahead == '(') ADVANCE(50);
      if (lookahead == ')') ADVANCE(51);
      if (lookahead == '*') ADVANCE(31);
      if (lookahead == '+') ADVANCE(29);
      if (lookahead == ',') ADVANCE(44);
      if (lookahead == '-') ADVANCE(30);
      if (lookahead == '.') ADVANCE(45);
      if (lookahead == '/') ADVANCE(32);
      if (lookahead == ':') ADVANCE(42);
      if (lookahead == ';') ADVANCE(43);
      if (lookahead == '<') ADVANCE(25);
      if (lookahead == '=') ADVANCE(18);
      if (lookahead == '>') ADVANCE(26);
      if (lookahead == '?') ADVANCE(38);
      if (lookahead == '@') ADVANCE(39);
      if (lookahead == '[') ADVANCE(48);
      if (lookahead == '\\') ADVANCE(37);
      if (lookahead == ']') ADVANCE(49);
      if (lookahead == '^') ADVANCE(33);
      if (lookahead == '_') ADVANCE(56);
      if (lookahead == '`') ADVANCE(4);
      if (lookahead == '{') ADVANCE(46);
      if (lookahead == '|') ADVANCE(9);
      if (lookahead == '}') ADVANCE(47);
      if (lookahead == '~') ADVANCE(35);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(54);
      if (('A' <= lookahead && lookahead <= 'Z')) ADVANCE(15);
      if (('a' <= lookahead && lookahead <= 'z')) ADVANCE(57);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(52);
      if (lookahead != 0) ADVANCE(1);
      END_STATE();
    case 2:
      if (lookahead == '\'') ADVANCE(53);
      END_STATE();
    case 3:
      if (lookahead == '\\') ADVANCE(6);
      if (lookahead != 0) ADVANCE(2);
      END_STATE();
    case 4:
      if (lookahead == '`') ADVANCE(52);
      if (lookahead != 0) ADVANCE(4);
      END_STATE();
    case 5:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(55);
      END_STATE();
    case 6:
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(2);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_comment);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(8);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_PIPE);
      if (lookahead == '>') ADVANCE(10);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_PIPE_GT);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_COLON_COLON);
      if (lookahead == ':') ADVANCE(12);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_COLON_COLON_COLON);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_DOLLAR);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_LT_LT);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(sym_type_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(15);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_POUND);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_EQ);
      if (lookahead == '=') ADVANCE(23);
      if (lookahead == '>') ADVANCE(21);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_LT_DASH);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_DASH_GT);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_EQ_GT);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_QMARK_QMARK);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_EQ_EQ);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_BANG_EQ);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '-') ADVANCE(19);
      if (lookahead == '<') ADVANCE(14);
      if (lookahead == '=') ADVANCE(27);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(28);
      if (lookahead == '>') ADVANCE(41);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '-') ADVANCE(40);
      if (lookahead == '>') ADVANCE(20);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '/') ADVANCE(8);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_CARET);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_BANG);
      if (lookahead == '=') ADVANCE(24);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_TILDE);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_AMP);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_BSLASH);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_QMARK);
      if (lookahead == '?') ADVANCE(22);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(anon_sym_AT);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(anon_sym_DASH_DASH);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_GT_GT);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_COLON);
      if (lookahead == ':') ADVANCE(11);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_SEMI);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(anon_sym_DOT);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_LBRACE);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_RBRACE);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(anon_sym_LBRACK);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(anon_sym_RBRACK);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(anon_sym_LPAREN);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_RPAREN);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_string);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_char);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(5);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(54);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(57);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(55);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(56);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(57);
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
      if (lookahead == 'o') ADVANCE(48);
      if (lookahead == 'u') ADVANCE(49);
      END_STATE();
    case 14:
      if (lookahead == 'e') ADVANCE(50);
      END_STATE();
    case 15:
      if (lookahead == 'f') ADVANCE(51);
      if (lookahead == 'm') ADVANCE(52);
      if (lookahead == 'n') ADVANCE(53);
      if (lookahead == 't') ADVANCE(54);
      END_STATE();
    case 16:
      if (lookahead == 'i') ADVANCE(55);
      if (lookahead == 'o') ADVANCE(56);
      END_STATE();
    case 17:
      if (lookahead == 'a') ADVANCE(57);
      if (lookahead == 'u') ADVANCE(58);
      END_STATE();
    case 18:
      if (lookahead == 'e') ADVANCE(59);
      END_STATE();
    case 19:
      if (lookahead == 'l') ADVANCE(60);
      END_STATE();
    case 20:
      if (lookahead == 'a') ADVANCE(61);
      if (lookahead == 'k') ADVANCE(62);
      if (lookahead == 'r') ADVANCE(63);
      if (lookahead == 't') ADVANCE(64);
      END_STATE();
    case 21:
      if (lookahead == 'a') ADVANCE(65);
      if (lookahead == 'e') ADVANCE(66);
      END_STATE();
    case 22:
      if (lookahead == 'a') ADVANCE(67);
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
      if (lookahead == 'b') ADVANCE(92);
      if (lookahead == 'f') ADVANCE(93);
      END_STATE();
    case 43:
      if (lookahead == 's') ADVANCE(94);
      END_STATE();
    case 44:
      if (lookahead == 'u') ADVANCE(95);
      END_STATE();
    case 45:
      if (lookahead == 'r') ADVANCE(96);
      END_STATE();
    case 46:
      if (lookahead == 'i') ADVANCE(97);
      if (lookahead == 'l') ADVANCE(98);
      END_STATE();
    case 47:
      if (lookahead == 'o') ADVANCE(99);
      END_STATE();
    case 48:
      if (lookahead == 'r') ADVANCE(100);
      END_STATE();
    case 49:
      if (lookahead == 'n') ADVANCE(101);
      END_STATE();
    case 50:
      if (lookahead == 'a') ADVANCE(102);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 52:
      if (lookahead == 'p') ADVANCE(103);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_in);
      if (lookahead == 't') ADVANCE(104);
      END_STATE();
    case 54:
      if (lookahead == 'r') ADVANCE(105);
      END_STATE();
    case 55:
      if (lookahead == 'n') ADVANCE(106);
      if (lookahead == 's') ADVANCE(107);
      END_STATE();
    case 56:
      if (lookahead == 'o') ADVANCE(108);
      END_STATE();
    case 57:
      if (lookahead == 'y') ADVANCE(109);
      END_STATE();
    case 58:
      if (lookahead == 't') ADVANCE(110);
      END_STATE();
    case 59:
      if (lookahead == 'w') ADVANCE(111);
      END_STATE();
    case 60:
      if (lookahead == 'd') ADVANCE(112);
      END_STATE();
    case 61:
      if (lookahead == 'c') ADVANCE(113);
      END_STATE();
    case 62:
      if (lookahead == 'g') ADVANCE(114);
      END_STATE();
    case 63:
      if (lookahead == 'i') ADVANCE(115);
      if (lookahead == 'o') ADVANCE(116);
      END_STATE();
    case 64:
      if (lookahead == 'r') ADVANCE(117);
      END_STATE();
    case 65:
      if (lookahead == 'n') ADVANCE(118);
      END_STATE();
    case 66:
      if (lookahead == 'f') ADVANCE(119);
      if (lookahead == 't') ADVANCE(120);
      END_STATE();
    case 67:
      if (lookahead == 'y') ADVANCE(121);
      END_STATE();
    case 68:
      if (lookahead == 'c') ADVANCE(122);
      if (lookahead == 't') ADVANCE(123);
      END_STATE();
    case 69:
      if (lookahead == 'r') ADVANCE(124);
      END_STATE();
    case 70:
      if (lookahead == 'i') ADVANCE(125);
      END_STATE();
    case 71:
      if (lookahead == 'u') ADVANCE(126);
      END_STATE();
    case 72:
      if (lookahead == 'p') ADVANCE(127);
      END_STATE();
    case 73:
      if (lookahead == 'e') ADVANCE(128);
      END_STATE();
    case 74:
      if (lookahead == 'i') ADVANCE(129);
      END_STATE();
    case 75:
      if (lookahead == 'i') ADVANCE(130);
      END_STATE();
    case 76:
      if (lookahead == 'r') ADVANCE(131);
      END_STATE();
    case 77:
      if (lookahead == 'e') ADVANCE(132);
      END_STATE();
    case 78:
      if (lookahead == 'e') ADVANCE(133);
      END_STATE();
    case 79:
      if (lookahead == 'l') ADVANCE(134);
      END_STATE();
    case 80:
      if (lookahead == 'g') ADVANCE(135);
      END_STATE();
    case 81:
      if (lookahead == 'f') ADVANCE(136);
      END_STATE();
    case 82:
      if (lookahead == 'e') ADVANCE(137);
      END_STATE();
    case 83:
      if (lookahead == 'i') ADVANCE(138);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym____);
      END_STATE();
    case 85:
      if (lookahead == 'a') ADVANCE(139);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_ark);
      END_STATE();
    case 87:
      if (lookahead == 'l') ADVANCE(140);
      END_STATE();
    case 88:
      if (lookahead == 'a') ADVANCE(141);
      END_STATE();
    case 89:
      if (lookahead == 'c') ADVANCE(142);
      if (lookahead == 'e') ADVANCE(143);
      END_STATE();
    case 90:
      if (lookahead == 'r') ADVANCE(144);
      END_STATE();
    case 91:
      if (lookahead == 's') ADVANCE(145);
      END_STATE();
    case 92:
      if (lookahead == 'u') ADVANCE(146);
      END_STATE();
    case 93:
      if (lookahead == 'a') ADVANCE(147);
      END_STATE();
    case 94:
      if (lookahead == 'e') ADVANCE(148);
      END_STATE();
    case 95:
      if (lookahead == 'm') ADVANCE(149);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_err);
      END_STATE();
    case 97:
      if (lookahead == 'l') ADVANCE(150);
      END_STATE();
    case 98:
      if (lookahead == 's') ADVANCE(151);
      END_STATE();
    case 99:
      if (lookahead == 'a') ADVANCE(152);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_for);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_fun);
      END_STATE();
    case 102:
      if (lookahead == 'p') ADVANCE(153);
      END_STATE();
    case 103:
      if (lookahead == 'l') ADVANCE(154);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_int);
      if (lookahead == 'e') ADVANCE(155);
      if (lookahead == 'o') ADVANCE(156);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_itr);
      END_STATE();
    case 106:
      if (lookahead == 'e') ADVANCE(157);
      END_STATE();
    case 107:
      if (lookahead == 't') ADVANCE(158);
      END_STATE();
    case 108:
      if (lookahead == 'p') ADVANCE(159);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_may);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_mut);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_new);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_old);
      END_STATE();
    case 113:
      if (lookahead == 'k') ADVANCE(160);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_pkg);
      END_STATE();
    case 115:
      if (lookahead == 'n') ADVANCE(161);
      END_STATE();
    case 116:
      if (lookahead == 'p') ADVANCE(162);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_ptr);
      END_STATE();
    case 118:
      if (lookahead == 'g') ADVANCE(163);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_ref);
      END_STATE();
    case 120:
      if (lookahead == 'u') ADVANCE(164);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_say);
      if (lookahead == 'i') ADVANCE(165);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_sec);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(anon_sym_set);
      END_STATE();
    case 124:
      if (lookahead == 'i') ADVANCE(166);
      if (lookahead == 'u') ADVANCE(167);
      END_STATE();
    case 125:
      if (lookahead == 't') ADVANCE(168);
      END_STATE();
    case 126:
      if (lookahead == 'e') ADVANCE(169);
      END_STATE();
    case 127:
      if (lookahead == 'e') ADVANCE(170);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(anon_sym_use);
      END_STATE();
    case 129:
      if (lookahead == 'd') ADVANCE(171);
      END_STATE();
    case 130:
      if (lookahead == 'l') ADVANCE(172);
      END_STATE();
    case 131:
      if (lookahead == 'd') ADVANCE(173);
      END_STATE();
    case 132:
      if (lookahead == 'l') ADVANCE(174);
      END_STATE();
    case 133:
      if (lookahead == 'd') ADVANCE(175);
      END_STATE();
    case 134:
      if (lookahead == 'd') ADVANCE(176);
      END_STATE();
    case 135:
      if (lookahead == 'r') ADVANCE(177);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(anon_sym_Self);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(anon_sym_Type);
      END_STATE();
    case 138:
      if (lookahead == 'a') ADVANCE(178);
      END_STATE();
    case 139:
      if (lookahead == 's') ADVANCE(179);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(anon_sym_bool);
      END_STATE();
    case 141:
      if (lookahead == 'k') ADVANCE(180);
      END_STATE();
    case 142:
      if (lookahead == 'a') ADVANCE(181);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(anon_sym_case);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(anon_sym_char);
      END_STATE();
    case 145:
      if (lookahead == 't') ADVANCE(182);
      END_STATE();
    case 146:
      if (lookahead == 'g') ADVANCE(183);
      END_STATE();
    case 147:
      if (lookahead == 'u') ADVANCE(184);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(anon_sym_enum);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(anon_sym_fail);
      END_STATE();
    case 151:
      if (lookahead == 'e') ADVANCE(185);
      END_STATE();
    case 152:
      if (lookahead == 't') ADVANCE(186);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(anon_sym_heap);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(anon_sym_impl);
      END_STATE();
    case 155:
      if (lookahead == 'r') ADVANCE(187);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(anon_sym_into);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(anon_sym_line);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(anon_sym_list);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(anon_sym_loop);
      END_STATE();
    case 160:
      if (lookahead == 'a') ADVANCE(188);
      END_STATE();
    case 161:
      if (lookahead == 't') ADVANCE(189);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(anon_sym_prop);
      END_STATE();
    case 163:
      if (lookahead == 'e') ADVANCE(190);
      END_STATE();
    case 164:
      if (lookahead == 'r') ADVANCE(191);
      END_STATE();
    case 165:
      if (lookahead == 'f') ADVANCE(192);
      END_STATE();
    case 166:
      if (lookahead == 'n') ADVANCE(193);
      END_STATE();
    case 167:
      if (lookahead == 'c') ADVANCE(194);
      END_STATE();
    case 168:
      if (lookahead == 'c') ADVANCE(195);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(anon_sym_true);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(anon_sym_type);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(anon_sym_void);
      END_STATE();
    case 172:
      if (lookahead == 'e') ADVANCE(196);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(anon_sym_word);
      END_STATE();
    case 174:
      if (lookahead == 'd') ADVANCE(197);
      END_STATE();
    case 175:
      if (lookahead == 'd') ADVANCE(198);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(anon_sym_Field);
      END_STATE();
    case 177:
      if (lookahead == 'a') ADVANCE(199);
      END_STATE();
    case 178:
      if (lookahead == 'b') ADVANCE(200);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(anon_sym_alias);
      END_STATE();
    case 180:
      ACCEPT_TOKEN(anon_sym_break);
      END_STATE();
    case 181:
      if (lookahead == 'd') ADVANCE(201);
      END_STATE();
    case 182:
      ACCEPT_TOKEN(anon_sym_const);
      END_STATE();
    case 183:
      ACCEPT_TOKEN(anon_sym_debug);
      if (lookahead == 'i') ADVANCE(202);
      END_STATE();
    case 184:
      if (lookahead == 'l') ADVANCE(203);
      END_STATE();
    case 185:
      ACCEPT_TOKEN(anon_sym_false);
      END_STATE();
    case 186:
      ACCEPT_TOKEN(anon_sym_float);
      END_STATE();
    case 187:
      if (lookahead == 'f') ADVANCE(204);
      END_STATE();
    case 188:
      if (lookahead == 'g') ADVANCE(205);
      END_STATE();
    case 189:
      ACCEPT_TOKEN(anon_sym_print);
      if (lookahead == 'i') ADVANCE(206);
      END_STATE();
    case 190:
      ACCEPT_TOKEN(anon_sym_range);
      END_STATE();
    case 191:
      if (lookahead == 'n') ADVANCE(207);
      END_STATE();
    case 192:
      ACCEPT_TOKEN(anon_sym_sayif);
      END_STATE();
    case 193:
      if (lookahead == 'g') ADVANCE(208);
      END_STATE();
    case 194:
      if (lookahead == 't') ADVANCE(209);
      END_STATE();
    case 195:
      if (lookahead == 'h') ADVANCE(210);
      END_STATE();
    case 196:
      ACCEPT_TOKEN(anon_sym_while);
      END_STATE();
    case 197:
      ACCEPT_TOKEN(anon_sym_yield);
      END_STATE();
    case 198:
      if (lookahead == 'e') ADVANCE(211);
      END_STATE();
    case 199:
      if (lookahead == 'm') ADVANCE(212);
      END_STATE();
    case 200:
      if (lookahead == 'l') ADVANCE(213);
      END_STATE();
    case 201:
      if (lookahead == 'e') ADVANCE(214);
      END_STATE();
    case 202:
      if (lookahead == 'f') ADVANCE(215);
      END_STATE();
    case 203:
      if (lookahead == 't') ADVANCE(216);
      END_STATE();
    case 204:
      if (lookahead == 'a') ADVANCE(217);
      END_STATE();
    case 205:
      if (lookahead == 'e') ADVANCE(218);
      END_STATE();
    case 206:
      if (lookahead == 'f') ADVANCE(219);
      END_STATE();
    case 207:
      ACCEPT_TOKEN(anon_sym_return);
      END_STATE();
    case 208:
      ACCEPT_TOKEN(anon_sym_string);
      END_STATE();
    case 209:
      ACCEPT_TOKEN(anon_sym_struct);
      END_STATE();
    case 210:
      ACCEPT_TOKEN(anon_sym_switch);
      END_STATE();
    case 211:
      if (lookahead == 'd') ADVANCE(220);
      END_STATE();
    case 212:
      ACCEPT_TOKEN(anon_sym_Program);
      END_STATE();
    case 213:
      if (lookahead == 'e') ADVANCE(221);
      END_STATE();
    case 214:
      ACCEPT_TOKEN(anon_sym_cascade);
      END_STATE();
    case 215:
      ACCEPT_TOKEN(anon_sym_debugif);
      END_STATE();
    case 216:
      ACCEPT_TOKEN(anon_sym_default);
      END_STATE();
    case 217:
      if (lookahead == 'c') ADVANCE(222);
      END_STATE();
    case 218:
      ACCEPT_TOKEN(anon_sym_package);
      END_STATE();
    case 219:
      ACCEPT_TOKEN(anon_sym_printif);
      END_STATE();
    case 220:
      ACCEPT_TOKEN(anon_sym_Embedded);
      END_STATE();
    case 221:
      ACCEPT_TOKEN(anon_sym_Variable);
      END_STATE();
    case 222:
      if (lookahead == 'e') ADVANCE(223);
      END_STATE();
    case 223:
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
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [sym_comment] = ACTIONS(3),
    [anon_sym_PIPE] = ACTIONS(1),
    [anon_sym_PIPE_GT] = ACTIONS(1),
    [anon_sym_COLON_COLON] = ACTIONS(1),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(1),
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
    [anon_sym_say] = ACTIONS(1),
    [anon_sym_sayif] = ACTIONS(1),
    [anon_sym_debug] = ACTIONS(1),
    [anon_sym_debugif] = ACTIONS(1),
    [anon_sym_print] = ACTIONS(1),
    [anon_sym_printif] = ACTIONS(1),
    [anon_sym_use] = ACTIONS(1),
    [anon_sym_package] = ACTIONS(1),
    [anon_sym_default] = ACTIONS(1),
    [anon_sym_set] = ACTIONS(1),
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
    [anon_sym_sec] = ACTIONS(1),
    [anon_sym_pkg] = ACTIONS(1),
    [anon_sym_true] = ACTIONS(1),
    [anon_sym_false] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_LT_DASH] = ACTIONS(1),
    [anon_sym_DASH_GT] = ACTIONS(1),
    [anon_sym_EQ_GT] = ACTIONS(1),
    [anon_sym_QMARK_QMARK] = ACTIONS(1),
    [anon_sym____] = ACTIONS(1),
    [anon_sym_EQ_EQ] = ACTIONS(1),
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
    [anon_sym_DOT] = ACTIONS(1),
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
    [sym_source_file] = STATE(22),
    [sym__item] = STATE(2),
    [sym_procedure_definition] = STATE(2),
    [sym_func_usage] = STATE(2),
    [sym_pipe_usage] = STATE(2),
    [sym_type_usage] = STATE(2),
    [sym_keyword] = STATE(2),
    [sym_terminator] = STATE(2),
    [sym_type_keyword] = STATE(2),
    [sym_modifier] = STATE(2),
    [sym_boolean] = STATE(2),
    [sym_operator] = STATE(2),
    [sym_punctuation] = STATE(2),
    [aux_sym_source_file_repeat1] = STATE(2),
    [ts_builtin_sym_end] = ACTIONS(5),
    [sym_identifier] = ACTIONS(7),
    [sym_comment] = ACTIONS(3),
    [anon_sym_PIPE] = ACTIONS(9),
    [anon_sym_PIPE_GT] = ACTIONS(11),
    [anon_sym_COLON_COLON] = ACTIONS(13),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(15),
    [anon_sym_DOLLAR] = ACTIONS(15),
    [anon_sym_LT_LT] = ACTIONS(15),
    [sym_type_identifier] = ACTIONS(17),
    [anon_sym__] = ACTIONS(19),
    [anon_sym_PERCENT] = ACTIONS(21),
    [anon_sym_POUND] = ACTIONS(21),
    [anon_sym_new] = ACTIONS(23),
    [anon_sym_old] = ACTIONS(23),
    [anon_sym_heap] = ACTIONS(23),
    [anon_sym_const] = ACTIONS(23),
    [anon_sym_if] = ACTIONS(23),
    [anon_sym_else] = ACTIONS(23),
    [anon_sym_while] = ACTIONS(23),
    [anon_sym_for] = ACTIONS(23),
    [anon_sym_in] = ACTIONS(23),
    [anon_sym_switch] = ACTIONS(23),
    [anon_sym_case] = ACTIONS(23),
    [anon_sym_fail] = ACTIONS(23),
    [anon_sym_say] = ACTIONS(23),
    [anon_sym_sayif] = ACTIONS(23),
    [anon_sym_debug] = ACTIONS(23),
    [anon_sym_debugif] = ACTIONS(23),
    [anon_sym_print] = ACTIONS(23),
    [anon_sym_printif] = ACTIONS(23),
    [anon_sym_use] = ACTIONS(23),
    [anon_sym_package] = ACTIONS(23),
    [anon_sym_default] = ACTIONS(23),
    [anon_sym_set] = ACTIONS(23),
    [anon_sym_struct] = ACTIONS(23),
    [anon_sym_type] = ACTIONS(23),
    [anon_sym_interface] = ACTIONS(23),
    [anon_sym_alias] = ACTIONS(23),
    [anon_sym_enum] = ACTIONS(23),
    [anon_sym_prop] = ACTIONS(23),
    [anon_sym_impl] = ACTIONS(23),
    [anon_sym_return] = ACTIONS(25),
    [anon_sym_yield] = ACTIONS(25),
    [anon_sym_cascade] = ACTIONS(25),
    [anon_sym_break] = ACTIONS(25),
    [anon_sym_loop] = ACTIONS(25),
    [anon_sym_void] = ACTIONS(27),
    [anon_sym_int] = ACTIONS(27),
    [anon_sym_char] = ACTIONS(27),
    [anon_sym_bool] = ACTIONS(27),
    [anon_sym_float] = ACTIONS(27),
    [anon_sym_range] = ACTIONS(27),
    [anon_sym_list] = ACTIONS(27),
    [anon_sym_string] = ACTIONS(27),
    [anon_sym_line] = ACTIONS(27),
    [anon_sym_word] = ACTIONS(27),
    [anon_sym_Program] = ACTIONS(27),
    [anon_sym_Embedded] = ACTIONS(27),
    [anon_sym_Self] = ACTIONS(27),
    [anon_sym_Type] = ACTIONS(27),
    [anon_sym_Field] = ACTIONS(27),
    [anon_sym_Variable] = ACTIONS(27),
    [anon_sym_into] = ACTIONS(29),
    [anon_sym_fun] = ACTIONS(29),
    [anon_sym_may] = ACTIONS(29),
    [anon_sym_itr] = ACTIONS(29),
    [anon_sym_err] = ACTIONS(29),
    [anon_sym_ark] = ACTIONS(29),
    [anon_sym_ptr] = ACTIONS(29),
    [anon_sym_mut] = ACTIONS(29),
    [anon_sym_ref] = ACTIONS(29),
    [anon_sym_sec] = ACTIONS(29),
    [anon_sym_pkg] = ACTIONS(29),
    [anon_sym_true] = ACTIONS(31),
    [anon_sym_false] = ACTIONS(31),
    [anon_sym_EQ] = ACTIONS(13),
    [anon_sym_LT_DASH] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(15),
    [anon_sym_EQ_GT] = ACTIONS(15),
    [anon_sym_QMARK_QMARK] = ACTIONS(15),
    [anon_sym____] = ACTIONS(13),
    [anon_sym_EQ_EQ] = ACTIONS(15),
    [anon_sym_BANG_EQ] = ACTIONS(15),
    [anon_sym_LT] = ACTIONS(13),
    [anon_sym_GT] = ACTIONS(13),
    [anon_sym_LT_EQ] = ACTIONS(15),
    [anon_sym_GT_EQ] = ACTIONS(15),
    [anon_sym_PLUS] = ACTIONS(15),
    [anon_sym_DASH] = ACTIONS(13),
    [anon_sym_STAR] = ACTIONS(15),
    [anon_sym_SLASH] = ACTIONS(13),
    [anon_sym_CARET] = ACTIONS(15),
    [anon_sym_BANG] = ACTIONS(13),
    [anon_sym_TILDE] = ACTIONS(15),
    [anon_sym_AMP] = ACTIONS(15),
    [anon_sym_BSLASH] = ACTIONS(15),
    [anon_sym_QMARK] = ACTIONS(13),
    [anon_sym_AT] = ACTIONS(15),
    [anon_sym_DASH_DASH] = ACTIONS(15),
    [anon_sym_GT_GT] = ACTIONS(15),
    [anon_sym_COLON] = ACTIONS(33),
    [anon_sym_SEMI] = ACTIONS(35),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_DOT] = ACTIONS(35),
    [anon_sym_LBRACE] = ACTIONS(35),
    [anon_sym_RBRACE] = ACTIONS(35),
    [anon_sym_LBRACK] = ACTIONS(35),
    [anon_sym_RBRACK] = ACTIONS(35),
    [anon_sym_LPAREN] = ACTIONS(35),
    [anon_sym_RPAREN] = ACTIONS(35),
    [sym_string] = ACTIONS(37),
    [sym_char] = ACTIONS(37),
    [sym_number] = ACTIONS(39),
  },
  [2] = {
    [sym__item] = STATE(3),
    [sym_procedure_definition] = STATE(3),
    [sym_func_usage] = STATE(3),
    [sym_pipe_usage] = STATE(3),
    [sym_type_usage] = STATE(3),
    [sym_keyword] = STATE(3),
    [sym_terminator] = STATE(3),
    [sym_type_keyword] = STATE(3),
    [sym_modifier] = STATE(3),
    [sym_boolean] = STATE(3),
    [sym_operator] = STATE(3),
    [sym_punctuation] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(41),
    [sym_identifier] = ACTIONS(7),
    [sym_comment] = ACTIONS(3),
    [anon_sym_PIPE] = ACTIONS(9),
    [anon_sym_PIPE_GT] = ACTIONS(11),
    [anon_sym_COLON_COLON] = ACTIONS(13),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(15),
    [anon_sym_DOLLAR] = ACTIONS(15),
    [anon_sym_LT_LT] = ACTIONS(15),
    [sym_type_identifier] = ACTIONS(17),
    [anon_sym__] = ACTIONS(19),
    [anon_sym_PERCENT] = ACTIONS(21),
    [anon_sym_POUND] = ACTIONS(21),
    [anon_sym_new] = ACTIONS(23),
    [anon_sym_old] = ACTIONS(23),
    [anon_sym_heap] = ACTIONS(23),
    [anon_sym_const] = ACTIONS(23),
    [anon_sym_if] = ACTIONS(23),
    [anon_sym_else] = ACTIONS(23),
    [anon_sym_while] = ACTIONS(23),
    [anon_sym_for] = ACTIONS(23),
    [anon_sym_in] = ACTIONS(23),
    [anon_sym_switch] = ACTIONS(23),
    [anon_sym_case] = ACTIONS(23),
    [anon_sym_fail] = ACTIONS(23),
    [anon_sym_say] = ACTIONS(23),
    [anon_sym_sayif] = ACTIONS(23),
    [anon_sym_debug] = ACTIONS(23),
    [anon_sym_debugif] = ACTIONS(23),
    [anon_sym_print] = ACTIONS(23),
    [anon_sym_printif] = ACTIONS(23),
    [anon_sym_use] = ACTIONS(23),
    [anon_sym_package] = ACTIONS(23),
    [anon_sym_default] = ACTIONS(23),
    [anon_sym_set] = ACTIONS(23),
    [anon_sym_struct] = ACTIONS(23),
    [anon_sym_type] = ACTIONS(23),
    [anon_sym_interface] = ACTIONS(23),
    [anon_sym_alias] = ACTIONS(23),
    [anon_sym_enum] = ACTIONS(23),
    [anon_sym_prop] = ACTIONS(23),
    [anon_sym_impl] = ACTIONS(23),
    [anon_sym_return] = ACTIONS(25),
    [anon_sym_yield] = ACTIONS(25),
    [anon_sym_cascade] = ACTIONS(25),
    [anon_sym_break] = ACTIONS(25),
    [anon_sym_loop] = ACTIONS(25),
    [anon_sym_void] = ACTIONS(27),
    [anon_sym_int] = ACTIONS(27),
    [anon_sym_char] = ACTIONS(27),
    [anon_sym_bool] = ACTIONS(27),
    [anon_sym_float] = ACTIONS(27),
    [anon_sym_range] = ACTIONS(27),
    [anon_sym_list] = ACTIONS(27),
    [anon_sym_string] = ACTIONS(27),
    [anon_sym_line] = ACTIONS(27),
    [anon_sym_word] = ACTIONS(27),
    [anon_sym_Program] = ACTIONS(27),
    [anon_sym_Embedded] = ACTIONS(27),
    [anon_sym_Self] = ACTIONS(27),
    [anon_sym_Type] = ACTIONS(27),
    [anon_sym_Field] = ACTIONS(27),
    [anon_sym_Variable] = ACTIONS(27),
    [anon_sym_into] = ACTIONS(29),
    [anon_sym_fun] = ACTIONS(29),
    [anon_sym_may] = ACTIONS(29),
    [anon_sym_itr] = ACTIONS(29),
    [anon_sym_err] = ACTIONS(29),
    [anon_sym_ark] = ACTIONS(29),
    [anon_sym_ptr] = ACTIONS(29),
    [anon_sym_mut] = ACTIONS(29),
    [anon_sym_ref] = ACTIONS(29),
    [anon_sym_sec] = ACTIONS(29),
    [anon_sym_pkg] = ACTIONS(29),
    [anon_sym_true] = ACTIONS(31),
    [anon_sym_false] = ACTIONS(31),
    [anon_sym_EQ] = ACTIONS(13),
    [anon_sym_LT_DASH] = ACTIONS(15),
    [anon_sym_DASH_GT] = ACTIONS(15),
    [anon_sym_EQ_GT] = ACTIONS(15),
    [anon_sym_QMARK_QMARK] = ACTIONS(15),
    [anon_sym____] = ACTIONS(13),
    [anon_sym_EQ_EQ] = ACTIONS(15),
    [anon_sym_BANG_EQ] = ACTIONS(15),
    [anon_sym_LT] = ACTIONS(13),
    [anon_sym_GT] = ACTIONS(13),
    [anon_sym_LT_EQ] = ACTIONS(15),
    [anon_sym_GT_EQ] = ACTIONS(15),
    [anon_sym_PLUS] = ACTIONS(15),
    [anon_sym_DASH] = ACTIONS(13),
    [anon_sym_STAR] = ACTIONS(15),
    [anon_sym_SLASH] = ACTIONS(13),
    [anon_sym_CARET] = ACTIONS(15),
    [anon_sym_BANG] = ACTIONS(13),
    [anon_sym_TILDE] = ACTIONS(15),
    [anon_sym_AMP] = ACTIONS(15),
    [anon_sym_BSLASH] = ACTIONS(15),
    [anon_sym_QMARK] = ACTIONS(13),
    [anon_sym_AT] = ACTIONS(15),
    [anon_sym_DASH_DASH] = ACTIONS(15),
    [anon_sym_GT_GT] = ACTIONS(15),
    [anon_sym_COLON] = ACTIONS(33),
    [anon_sym_SEMI] = ACTIONS(35),
    [anon_sym_COMMA] = ACTIONS(35),
    [anon_sym_DOT] = ACTIONS(35),
    [anon_sym_LBRACE] = ACTIONS(35),
    [anon_sym_RBRACE] = ACTIONS(35),
    [anon_sym_LBRACK] = ACTIONS(35),
    [anon_sym_RBRACK] = ACTIONS(35),
    [anon_sym_LPAREN] = ACTIONS(35),
    [anon_sym_RPAREN] = ACTIONS(35),
    [sym_string] = ACTIONS(43),
    [sym_char] = ACTIONS(43),
    [sym_number] = ACTIONS(45),
  },
  [3] = {
    [sym__item] = STATE(3),
    [sym_procedure_definition] = STATE(3),
    [sym_func_usage] = STATE(3),
    [sym_pipe_usage] = STATE(3),
    [sym_type_usage] = STATE(3),
    [sym_keyword] = STATE(3),
    [sym_terminator] = STATE(3),
    [sym_type_keyword] = STATE(3),
    [sym_modifier] = STATE(3),
    [sym_boolean] = STATE(3),
    [sym_operator] = STATE(3),
    [sym_punctuation] = STATE(3),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(47),
    [sym_identifier] = ACTIONS(49),
    [sym_comment] = ACTIONS(3),
    [anon_sym_PIPE] = ACTIONS(52),
    [anon_sym_PIPE_GT] = ACTIONS(55),
    [anon_sym_COLON_COLON] = ACTIONS(58),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(61),
    [anon_sym_DOLLAR] = ACTIONS(61),
    [anon_sym_LT_LT] = ACTIONS(61),
    [sym_type_identifier] = ACTIONS(64),
    [anon_sym__] = ACTIONS(67),
    [anon_sym_PERCENT] = ACTIONS(70),
    [anon_sym_POUND] = ACTIONS(70),
    [anon_sym_new] = ACTIONS(73),
    [anon_sym_old] = ACTIONS(73),
    [anon_sym_heap] = ACTIONS(73),
    [anon_sym_const] = ACTIONS(73),
    [anon_sym_if] = ACTIONS(73),
    [anon_sym_else] = ACTIONS(73),
    [anon_sym_while] = ACTIONS(73),
    [anon_sym_for] = ACTIONS(73),
    [anon_sym_in] = ACTIONS(73),
    [anon_sym_switch] = ACTIONS(73),
    [anon_sym_case] = ACTIONS(73),
    [anon_sym_fail] = ACTIONS(73),
    [anon_sym_say] = ACTIONS(73),
    [anon_sym_sayif] = ACTIONS(73),
    [anon_sym_debug] = ACTIONS(73),
    [anon_sym_debugif] = ACTIONS(73),
    [anon_sym_print] = ACTIONS(73),
    [anon_sym_printif] = ACTIONS(73),
    [anon_sym_use] = ACTIONS(73),
    [anon_sym_package] = ACTIONS(73),
    [anon_sym_default] = ACTIONS(73),
    [anon_sym_set] = ACTIONS(73),
    [anon_sym_struct] = ACTIONS(73),
    [anon_sym_type] = ACTIONS(73),
    [anon_sym_interface] = ACTIONS(73),
    [anon_sym_alias] = ACTIONS(73),
    [anon_sym_enum] = ACTIONS(73),
    [anon_sym_prop] = ACTIONS(73),
    [anon_sym_impl] = ACTIONS(73),
    [anon_sym_return] = ACTIONS(76),
    [anon_sym_yield] = ACTIONS(76),
    [anon_sym_cascade] = ACTIONS(76),
    [anon_sym_break] = ACTIONS(76),
    [anon_sym_loop] = ACTIONS(76),
    [anon_sym_void] = ACTIONS(79),
    [anon_sym_int] = ACTIONS(79),
    [anon_sym_char] = ACTIONS(79),
    [anon_sym_bool] = ACTIONS(79),
    [anon_sym_float] = ACTIONS(79),
    [anon_sym_range] = ACTIONS(79),
    [anon_sym_list] = ACTIONS(79),
    [anon_sym_string] = ACTIONS(79),
    [anon_sym_line] = ACTIONS(79),
    [anon_sym_word] = ACTIONS(79),
    [anon_sym_Program] = ACTIONS(79),
    [anon_sym_Embedded] = ACTIONS(79),
    [anon_sym_Self] = ACTIONS(79),
    [anon_sym_Type] = ACTIONS(79),
    [anon_sym_Field] = ACTIONS(79),
    [anon_sym_Variable] = ACTIONS(79),
    [anon_sym_into] = ACTIONS(82),
    [anon_sym_fun] = ACTIONS(82),
    [anon_sym_may] = ACTIONS(82),
    [anon_sym_itr] = ACTIONS(82),
    [anon_sym_err] = ACTIONS(82),
    [anon_sym_ark] = ACTIONS(82),
    [anon_sym_ptr] = ACTIONS(82),
    [anon_sym_mut] = ACTIONS(82),
    [anon_sym_ref] = ACTIONS(82),
    [anon_sym_sec] = ACTIONS(82),
    [anon_sym_pkg] = ACTIONS(82),
    [anon_sym_true] = ACTIONS(85),
    [anon_sym_false] = ACTIONS(85),
    [anon_sym_EQ] = ACTIONS(58),
    [anon_sym_LT_DASH] = ACTIONS(61),
    [anon_sym_DASH_GT] = ACTIONS(61),
    [anon_sym_EQ_GT] = ACTIONS(61),
    [anon_sym_QMARK_QMARK] = ACTIONS(61),
    [anon_sym____] = ACTIONS(58),
    [anon_sym_EQ_EQ] = ACTIONS(61),
    [anon_sym_BANG_EQ] = ACTIONS(61),
    [anon_sym_LT] = ACTIONS(58),
    [anon_sym_GT] = ACTIONS(58),
    [anon_sym_LT_EQ] = ACTIONS(61),
    [anon_sym_GT_EQ] = ACTIONS(61),
    [anon_sym_PLUS] = ACTIONS(61),
    [anon_sym_DASH] = ACTIONS(58),
    [anon_sym_STAR] = ACTIONS(61),
    [anon_sym_SLASH] = ACTIONS(58),
    [anon_sym_CARET] = ACTIONS(61),
    [anon_sym_BANG] = ACTIONS(58),
    [anon_sym_TILDE] = ACTIONS(61),
    [anon_sym_AMP] = ACTIONS(61),
    [anon_sym_BSLASH] = ACTIONS(61),
    [anon_sym_QMARK] = ACTIONS(58),
    [anon_sym_AT] = ACTIONS(61),
    [anon_sym_DASH_DASH] = ACTIONS(61),
    [anon_sym_GT_GT] = ACTIONS(61),
    [anon_sym_COLON] = ACTIONS(88),
    [anon_sym_SEMI] = ACTIONS(91),
    [anon_sym_COMMA] = ACTIONS(91),
    [anon_sym_DOT] = ACTIONS(91),
    [anon_sym_LBRACE] = ACTIONS(91),
    [anon_sym_RBRACE] = ACTIONS(91),
    [anon_sym_LBRACK] = ACTIONS(91),
    [anon_sym_RBRACK] = ACTIONS(91),
    [anon_sym_LPAREN] = ACTIONS(91),
    [anon_sym_RPAREN] = ACTIONS(91),
    [sym_string] = ACTIONS(94),
    [sym_char] = ACTIONS(94),
    [sym_number] = ACTIONS(97),
  },
  [4] = {
    [ts_builtin_sym_end] = ACTIONS(100),
    [sym_identifier] = ACTIONS(102),
    [sym_comment] = ACTIONS(3),
    [anon_sym_PIPE] = ACTIONS(102),
    [anon_sym_PIPE_GT] = ACTIONS(100),
    [anon_sym_COLON_COLON] = ACTIONS(102),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(100),
    [anon_sym_DOLLAR] = ACTIONS(100),
    [anon_sym_LT_LT] = ACTIONS(100),
    [sym_type_identifier] = ACTIONS(102),
    [anon_sym__] = ACTIONS(102),
    [anon_sym_PERCENT] = ACTIONS(100),
    [anon_sym_POUND] = ACTIONS(100),
    [anon_sym_new] = ACTIONS(102),
    [anon_sym_old] = ACTIONS(102),
    [anon_sym_heap] = ACTIONS(102),
    [anon_sym_const] = ACTIONS(102),
    [anon_sym_if] = ACTIONS(102),
    [anon_sym_else] = ACTIONS(102),
    [anon_sym_while] = ACTIONS(102),
    [anon_sym_for] = ACTIONS(102),
    [anon_sym_in] = ACTIONS(102),
    [anon_sym_switch] = ACTIONS(102),
    [anon_sym_case] = ACTIONS(102),
    [anon_sym_fail] = ACTIONS(102),
    [anon_sym_say] = ACTIONS(102),
    [anon_sym_sayif] = ACTIONS(102),
    [anon_sym_debug] = ACTIONS(102),
    [anon_sym_debugif] = ACTIONS(102),
    [anon_sym_print] = ACTIONS(102),
    [anon_sym_printif] = ACTIONS(102),
    [anon_sym_use] = ACTIONS(102),
    [anon_sym_package] = ACTIONS(102),
    [anon_sym_default] = ACTIONS(102),
    [anon_sym_set] = ACTIONS(102),
    [anon_sym_struct] = ACTIONS(102),
    [anon_sym_type] = ACTIONS(102),
    [anon_sym_interface] = ACTIONS(102),
    [anon_sym_alias] = ACTIONS(102),
    [anon_sym_enum] = ACTIONS(102),
    [anon_sym_prop] = ACTIONS(102),
    [anon_sym_impl] = ACTIONS(102),
    [anon_sym_return] = ACTIONS(102),
    [anon_sym_yield] = ACTIONS(102),
    [anon_sym_cascade] = ACTIONS(102),
    [anon_sym_break] = ACTIONS(102),
    [anon_sym_loop] = ACTIONS(102),
    [anon_sym_void] = ACTIONS(102),
    [anon_sym_int] = ACTIONS(102),
    [anon_sym_char] = ACTIONS(102),
    [anon_sym_bool] = ACTIONS(102),
    [anon_sym_float] = ACTIONS(102),
    [anon_sym_range] = ACTIONS(102),
    [anon_sym_list] = ACTIONS(102),
    [anon_sym_string] = ACTIONS(102),
    [anon_sym_line] = ACTIONS(102),
    [anon_sym_word] = ACTIONS(102),
    [anon_sym_Program] = ACTIONS(102),
    [anon_sym_Embedded] = ACTIONS(102),
    [anon_sym_Self] = ACTIONS(102),
    [anon_sym_Type] = ACTIONS(102),
    [anon_sym_Field] = ACTIONS(102),
    [anon_sym_Variable] = ACTIONS(102),
    [anon_sym_into] = ACTIONS(102),
    [anon_sym_fun] = ACTIONS(102),
    [anon_sym_may] = ACTIONS(102),
    [anon_sym_itr] = ACTIONS(102),
    [anon_sym_err] = ACTIONS(102),
    [anon_sym_ark] = ACTIONS(102),
    [anon_sym_ptr] = ACTIONS(102),
    [anon_sym_mut] = ACTIONS(102),
    [anon_sym_ref] = ACTIONS(102),
    [anon_sym_sec] = ACTIONS(102),
    [anon_sym_pkg] = ACTIONS(102),
    [anon_sym_true] = ACTIONS(102),
    [anon_sym_false] = ACTIONS(102),
    [anon_sym_EQ] = ACTIONS(102),
    [anon_sym_LT_DASH] = ACTIONS(100),
    [anon_sym_DASH_GT] = ACTIONS(100),
    [anon_sym_EQ_GT] = ACTIONS(100),
    [anon_sym_QMARK_QMARK] = ACTIONS(100),
    [anon_sym____] = ACTIONS(102),
    [anon_sym_EQ_EQ] = ACTIONS(100),
    [anon_sym_BANG_EQ] = ACTIONS(100),
    [anon_sym_LT] = ACTIONS(102),
    [anon_sym_GT] = ACTIONS(102),
    [anon_sym_LT_EQ] = ACTIONS(100),
    [anon_sym_GT_EQ] = ACTIONS(100),
    [anon_sym_PLUS] = ACTIONS(100),
    [anon_sym_DASH] = ACTIONS(102),
    [anon_sym_STAR] = ACTIONS(100),
    [anon_sym_SLASH] = ACTIONS(102),
    [anon_sym_CARET] = ACTIONS(100),
    [anon_sym_BANG] = ACTIONS(102),
    [anon_sym_TILDE] = ACTIONS(100),
    [anon_sym_AMP] = ACTIONS(100),
    [anon_sym_BSLASH] = ACTIONS(100),
    [anon_sym_QMARK] = ACTIONS(102),
    [anon_sym_AT] = ACTIONS(100),
    [anon_sym_DASH_DASH] = ACTIONS(100),
    [anon_sym_GT_GT] = ACTIONS(100),
    [anon_sym_COLON] = ACTIONS(102),
    [anon_sym_SEMI] = ACTIONS(100),
    [anon_sym_COMMA] = ACTIONS(100),
    [anon_sym_DOT] = ACTIONS(100),
    [anon_sym_LBRACE] = ACTIONS(100),
    [anon_sym_RBRACE] = ACTIONS(100),
    [anon_sym_LBRACK] = ACTIONS(100),
    [anon_sym_RBRACK] = ACTIONS(100),
    [anon_sym_LPAREN] = ACTIONS(100),
    [anon_sym_RPAREN] = ACTIONS(100),
    [sym_string] = ACTIONS(100),
    [sym_char] = ACTIONS(100),
    [sym_number] = ACTIONS(102),
  },
  [5] = {
    [ts_builtin_sym_end] = ACTIONS(104),
    [sym_identifier] = ACTIONS(106),
    [sym_comment] = ACTIONS(3),
    [anon_sym_PIPE] = ACTIONS(106),
    [anon_sym_PIPE_GT] = ACTIONS(104),
    [anon_sym_COLON_COLON] = ACTIONS(106),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(104),
    [anon_sym_DOLLAR] = ACTIONS(104),
    [anon_sym_LT_LT] = ACTIONS(104),
    [sym_type_identifier] = ACTIONS(106),
    [anon_sym__] = ACTIONS(106),
    [anon_sym_PERCENT] = ACTIONS(104),
    [anon_sym_POUND] = ACTIONS(104),
    [anon_sym_new] = ACTIONS(106),
    [anon_sym_old] = ACTIONS(106),
    [anon_sym_heap] = ACTIONS(106),
    [anon_sym_const] = ACTIONS(106),
    [anon_sym_if] = ACTIONS(106),
    [anon_sym_else] = ACTIONS(106),
    [anon_sym_while] = ACTIONS(106),
    [anon_sym_for] = ACTIONS(106),
    [anon_sym_in] = ACTIONS(106),
    [anon_sym_switch] = ACTIONS(106),
    [anon_sym_case] = ACTIONS(106),
    [anon_sym_fail] = ACTIONS(106),
    [anon_sym_say] = ACTIONS(106),
    [anon_sym_sayif] = ACTIONS(106),
    [anon_sym_debug] = ACTIONS(106),
    [anon_sym_debugif] = ACTIONS(106),
    [anon_sym_print] = ACTIONS(106),
    [anon_sym_printif] = ACTIONS(106),
    [anon_sym_use] = ACTIONS(106),
    [anon_sym_package] = ACTIONS(106),
    [anon_sym_default] = ACTIONS(106),
    [anon_sym_set] = ACTIONS(106),
    [anon_sym_struct] = ACTIONS(106),
    [anon_sym_type] = ACTIONS(106),
    [anon_sym_interface] = ACTIONS(106),
    [anon_sym_alias] = ACTIONS(106),
    [anon_sym_enum] = ACTIONS(106),
    [anon_sym_prop] = ACTIONS(106),
    [anon_sym_impl] = ACTIONS(106),
    [anon_sym_return] = ACTIONS(106),
    [anon_sym_yield] = ACTIONS(106),
    [anon_sym_cascade] = ACTIONS(106),
    [anon_sym_break] = ACTIONS(106),
    [anon_sym_loop] = ACTIONS(106),
    [anon_sym_void] = ACTIONS(106),
    [anon_sym_int] = ACTIONS(106),
    [anon_sym_char] = ACTIONS(106),
    [anon_sym_bool] = ACTIONS(106),
    [anon_sym_float] = ACTIONS(106),
    [anon_sym_range] = ACTIONS(106),
    [anon_sym_list] = ACTIONS(106),
    [anon_sym_string] = ACTIONS(106),
    [anon_sym_line] = ACTIONS(106),
    [anon_sym_word] = ACTIONS(106),
    [anon_sym_Program] = ACTIONS(106),
    [anon_sym_Embedded] = ACTIONS(106),
    [anon_sym_Self] = ACTIONS(106),
    [anon_sym_Type] = ACTIONS(106),
    [anon_sym_Field] = ACTIONS(106),
    [anon_sym_Variable] = ACTIONS(106),
    [anon_sym_into] = ACTIONS(106),
    [anon_sym_fun] = ACTIONS(106),
    [anon_sym_may] = ACTIONS(106),
    [anon_sym_itr] = ACTIONS(106),
    [anon_sym_err] = ACTIONS(106),
    [anon_sym_ark] = ACTIONS(106),
    [anon_sym_ptr] = ACTIONS(106),
    [anon_sym_mut] = ACTIONS(106),
    [anon_sym_ref] = ACTIONS(106),
    [anon_sym_sec] = ACTIONS(106),
    [anon_sym_pkg] = ACTIONS(106),
    [anon_sym_true] = ACTIONS(106),
    [anon_sym_false] = ACTIONS(106),
    [anon_sym_EQ] = ACTIONS(106),
    [anon_sym_LT_DASH] = ACTIONS(104),
    [anon_sym_DASH_GT] = ACTIONS(104),
    [anon_sym_EQ_GT] = ACTIONS(104),
    [anon_sym_QMARK_QMARK] = ACTIONS(104),
    [anon_sym____] = ACTIONS(106),
    [anon_sym_EQ_EQ] = ACTIONS(104),
    [anon_sym_BANG_EQ] = ACTIONS(104),
    [anon_sym_LT] = ACTIONS(106),
    [anon_sym_GT] = ACTIONS(106),
    [anon_sym_LT_EQ] = ACTIONS(104),
    [anon_sym_GT_EQ] = ACTIONS(104),
    [anon_sym_PLUS] = ACTIONS(104),
    [anon_sym_DASH] = ACTIONS(106),
    [anon_sym_STAR] = ACTIONS(104),
    [anon_sym_SLASH] = ACTIONS(106),
    [anon_sym_CARET] = ACTIONS(104),
    [anon_sym_BANG] = ACTIONS(106),
    [anon_sym_TILDE] = ACTIONS(104),
    [anon_sym_AMP] = ACTIONS(104),
    [anon_sym_BSLASH] = ACTIONS(104),
    [anon_sym_QMARK] = ACTIONS(106),
    [anon_sym_AT] = ACTIONS(104),
    [anon_sym_DASH_DASH] = ACTIONS(104),
    [anon_sym_GT_GT] = ACTIONS(104),
    [anon_sym_COLON] = ACTIONS(106),
    [anon_sym_SEMI] = ACTIONS(104),
    [anon_sym_COMMA] = ACTIONS(104),
    [anon_sym_DOT] = ACTIONS(104),
    [anon_sym_LBRACE] = ACTIONS(104),
    [anon_sym_RBRACE] = ACTIONS(104),
    [anon_sym_LBRACK] = ACTIONS(104),
    [anon_sym_RBRACK] = ACTIONS(104),
    [anon_sym_LPAREN] = ACTIONS(104),
    [anon_sym_RPAREN] = ACTIONS(104),
    [sym_string] = ACTIONS(104),
    [sym_char] = ACTIONS(104),
    [sym_number] = ACTIONS(106),
  },
  [6] = {
    [ts_builtin_sym_end] = ACTIONS(108),
    [sym_identifier] = ACTIONS(110),
    [sym_comment] = ACTIONS(3),
    [anon_sym_PIPE] = ACTIONS(110),
    [anon_sym_PIPE_GT] = ACTIONS(108),
    [anon_sym_COLON_COLON] = ACTIONS(110),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(108),
    [anon_sym_DOLLAR] = ACTIONS(108),
    [anon_sym_LT_LT] = ACTIONS(108),
    [sym_type_identifier] = ACTIONS(112),
    [anon_sym__] = ACTIONS(110),
    [anon_sym_PERCENT] = ACTIONS(108),
    [anon_sym_POUND] = ACTIONS(108),
    [anon_sym_new] = ACTIONS(110),
    [anon_sym_old] = ACTIONS(110),
    [anon_sym_heap] = ACTIONS(110),
    [anon_sym_const] = ACTIONS(110),
    [anon_sym_if] = ACTIONS(110),
    [anon_sym_else] = ACTIONS(110),
    [anon_sym_while] = ACTIONS(110),
    [anon_sym_for] = ACTIONS(110),
    [anon_sym_in] = ACTIONS(110),
    [anon_sym_switch] = ACTIONS(110),
    [anon_sym_case] = ACTIONS(110),
    [anon_sym_fail] = ACTIONS(110),
    [anon_sym_say] = ACTIONS(110),
    [anon_sym_sayif] = ACTIONS(110),
    [anon_sym_debug] = ACTIONS(110),
    [anon_sym_debugif] = ACTIONS(110),
    [anon_sym_print] = ACTIONS(110),
    [anon_sym_printif] = ACTIONS(110),
    [anon_sym_use] = ACTIONS(110),
    [anon_sym_package] = ACTIONS(110),
    [anon_sym_default] = ACTIONS(110),
    [anon_sym_set] = ACTIONS(110),
    [anon_sym_struct] = ACTIONS(110),
    [anon_sym_type] = ACTIONS(110),
    [anon_sym_interface] = ACTIONS(110),
    [anon_sym_alias] = ACTIONS(110),
    [anon_sym_enum] = ACTIONS(110),
    [anon_sym_prop] = ACTIONS(110),
    [anon_sym_impl] = ACTIONS(110),
    [anon_sym_return] = ACTIONS(110),
    [anon_sym_yield] = ACTIONS(110),
    [anon_sym_cascade] = ACTIONS(110),
    [anon_sym_break] = ACTIONS(110),
    [anon_sym_loop] = ACTIONS(110),
    [anon_sym_void] = ACTIONS(110),
    [anon_sym_int] = ACTIONS(110),
    [anon_sym_char] = ACTIONS(110),
    [anon_sym_bool] = ACTIONS(110),
    [anon_sym_float] = ACTIONS(110),
    [anon_sym_range] = ACTIONS(110),
    [anon_sym_list] = ACTIONS(110),
    [anon_sym_string] = ACTIONS(110),
    [anon_sym_line] = ACTIONS(110),
    [anon_sym_word] = ACTIONS(110),
    [anon_sym_Program] = ACTIONS(110),
    [anon_sym_Embedded] = ACTIONS(110),
    [anon_sym_Self] = ACTIONS(110),
    [anon_sym_Type] = ACTIONS(110),
    [anon_sym_Field] = ACTIONS(110),
    [anon_sym_Variable] = ACTIONS(110),
    [anon_sym_into] = ACTIONS(110),
    [anon_sym_fun] = ACTIONS(110),
    [anon_sym_may] = ACTIONS(110),
    [anon_sym_itr] = ACTIONS(110),
    [anon_sym_err] = ACTIONS(110),
    [anon_sym_ark] = ACTIONS(110),
    [anon_sym_ptr] = ACTIONS(110),
    [anon_sym_mut] = ACTIONS(110),
    [anon_sym_ref] = ACTIONS(110),
    [anon_sym_sec] = ACTIONS(110),
    [anon_sym_pkg] = ACTIONS(110),
    [anon_sym_true] = ACTIONS(110),
    [anon_sym_false] = ACTIONS(110),
    [anon_sym_EQ] = ACTIONS(110),
    [anon_sym_LT_DASH] = ACTIONS(108),
    [anon_sym_DASH_GT] = ACTIONS(108),
    [anon_sym_EQ_GT] = ACTIONS(108),
    [anon_sym_QMARK_QMARK] = ACTIONS(108),
    [anon_sym____] = ACTIONS(110),
    [anon_sym_EQ_EQ] = ACTIONS(108),
    [anon_sym_BANG_EQ] = ACTIONS(108),
    [anon_sym_LT] = ACTIONS(110),
    [anon_sym_GT] = ACTIONS(110),
    [anon_sym_LT_EQ] = ACTIONS(108),
    [anon_sym_GT_EQ] = ACTIONS(108),
    [anon_sym_PLUS] = ACTIONS(108),
    [anon_sym_DASH] = ACTIONS(110),
    [anon_sym_STAR] = ACTIONS(108),
    [anon_sym_SLASH] = ACTIONS(110),
    [anon_sym_CARET] = ACTIONS(108),
    [anon_sym_BANG] = ACTIONS(110),
    [anon_sym_TILDE] = ACTIONS(108),
    [anon_sym_AMP] = ACTIONS(108),
    [anon_sym_BSLASH] = ACTIONS(108),
    [anon_sym_QMARK] = ACTIONS(110),
    [anon_sym_AT] = ACTIONS(108),
    [anon_sym_DASH_DASH] = ACTIONS(108),
    [anon_sym_GT_GT] = ACTIONS(108),
    [anon_sym_COLON] = ACTIONS(110),
    [anon_sym_SEMI] = ACTIONS(108),
    [anon_sym_COMMA] = ACTIONS(108),
    [anon_sym_DOT] = ACTIONS(108),
    [anon_sym_LBRACE] = ACTIONS(108),
    [anon_sym_RBRACE] = ACTIONS(108),
    [anon_sym_LBRACK] = ACTIONS(108),
    [anon_sym_RBRACK] = ACTIONS(108),
    [anon_sym_LPAREN] = ACTIONS(108),
    [anon_sym_RPAREN] = ACTIONS(108),
    [sym_string] = ACTIONS(108),
    [sym_char] = ACTIONS(108),
    [sym_number] = ACTIONS(110),
  },
  [7] = {
    [ts_builtin_sym_end] = ACTIONS(114),
    [sym_identifier] = ACTIONS(116),
    [sym_comment] = ACTIONS(3),
    [anon_sym_PIPE] = ACTIONS(116),
    [anon_sym_PIPE_GT] = ACTIONS(114),
    [anon_sym_COLON_COLON] = ACTIONS(116),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(114),
    [anon_sym_DOLLAR] = ACTIONS(114),
    [anon_sym_LT_LT] = ACTIONS(114),
    [sym_type_identifier] = ACTIONS(116),
    [anon_sym__] = ACTIONS(116),
    [anon_sym_PERCENT] = ACTIONS(114),
    [anon_sym_POUND] = ACTIONS(114),
    [anon_sym_new] = ACTIONS(116),
    [anon_sym_old] = ACTIONS(116),
    [anon_sym_heap] = ACTIONS(116),
    [anon_sym_const] = ACTIONS(116),
    [anon_sym_if] = ACTIONS(116),
    [anon_sym_else] = ACTIONS(116),
    [anon_sym_while] = ACTIONS(116),
    [anon_sym_for] = ACTIONS(116),
    [anon_sym_in] = ACTIONS(116),
    [anon_sym_switch] = ACTIONS(116),
    [anon_sym_case] = ACTIONS(116),
    [anon_sym_fail] = ACTIONS(116),
    [anon_sym_say] = ACTIONS(116),
    [anon_sym_sayif] = ACTIONS(116),
    [anon_sym_debug] = ACTIONS(116),
    [anon_sym_debugif] = ACTIONS(116),
    [anon_sym_print] = ACTIONS(116),
    [anon_sym_printif] = ACTIONS(116),
    [anon_sym_use] = ACTIONS(116),
    [anon_sym_package] = ACTIONS(116),
    [anon_sym_default] = ACTIONS(116),
    [anon_sym_set] = ACTIONS(116),
    [anon_sym_struct] = ACTIONS(116),
    [anon_sym_type] = ACTIONS(116),
    [anon_sym_interface] = ACTIONS(116),
    [anon_sym_alias] = ACTIONS(116),
    [anon_sym_enum] = ACTIONS(116),
    [anon_sym_prop] = ACTIONS(116),
    [anon_sym_impl] = ACTIONS(116),
    [anon_sym_return] = ACTIONS(116),
    [anon_sym_yield] = ACTIONS(116),
    [anon_sym_cascade] = ACTIONS(116),
    [anon_sym_break] = ACTIONS(116),
    [anon_sym_loop] = ACTIONS(116),
    [anon_sym_void] = ACTIONS(116),
    [anon_sym_int] = ACTIONS(116),
    [anon_sym_char] = ACTIONS(116),
    [anon_sym_bool] = ACTIONS(116),
    [anon_sym_float] = ACTIONS(116),
    [anon_sym_range] = ACTIONS(116),
    [anon_sym_list] = ACTIONS(116),
    [anon_sym_string] = ACTIONS(116),
    [anon_sym_line] = ACTIONS(116),
    [anon_sym_word] = ACTIONS(116),
    [anon_sym_Program] = ACTIONS(116),
    [anon_sym_Embedded] = ACTIONS(116),
    [anon_sym_Self] = ACTIONS(116),
    [anon_sym_Type] = ACTIONS(116),
    [anon_sym_Field] = ACTIONS(116),
    [anon_sym_Variable] = ACTIONS(116),
    [anon_sym_into] = ACTIONS(116),
    [anon_sym_fun] = ACTIONS(116),
    [anon_sym_may] = ACTIONS(116),
    [anon_sym_itr] = ACTIONS(116),
    [anon_sym_err] = ACTIONS(116),
    [anon_sym_ark] = ACTIONS(116),
    [anon_sym_ptr] = ACTIONS(116),
    [anon_sym_mut] = ACTIONS(116),
    [anon_sym_ref] = ACTIONS(116),
    [anon_sym_sec] = ACTIONS(116),
    [anon_sym_pkg] = ACTIONS(116),
    [anon_sym_true] = ACTIONS(116),
    [anon_sym_false] = ACTIONS(116),
    [anon_sym_EQ] = ACTIONS(116),
    [anon_sym_LT_DASH] = ACTIONS(114),
    [anon_sym_DASH_GT] = ACTIONS(114),
    [anon_sym_EQ_GT] = ACTIONS(114),
    [anon_sym_QMARK_QMARK] = ACTIONS(114),
    [anon_sym____] = ACTIONS(116),
    [anon_sym_EQ_EQ] = ACTIONS(114),
    [anon_sym_BANG_EQ] = ACTIONS(114),
    [anon_sym_LT] = ACTIONS(116),
    [anon_sym_GT] = ACTIONS(116),
    [anon_sym_LT_EQ] = ACTIONS(114),
    [anon_sym_GT_EQ] = ACTIONS(114),
    [anon_sym_PLUS] = ACTIONS(114),
    [anon_sym_DASH] = ACTIONS(116),
    [anon_sym_STAR] = ACTIONS(114),
    [anon_sym_SLASH] = ACTIONS(116),
    [anon_sym_CARET] = ACTIONS(114),
    [anon_sym_BANG] = ACTIONS(116),
    [anon_sym_TILDE] = ACTIONS(114),
    [anon_sym_AMP] = ACTIONS(114),
    [anon_sym_BSLASH] = ACTIONS(114),
    [anon_sym_QMARK] = ACTIONS(116),
    [anon_sym_AT] = ACTIONS(114),
    [anon_sym_DASH_DASH] = ACTIONS(114),
    [anon_sym_GT_GT] = ACTIONS(114),
    [anon_sym_COLON] = ACTIONS(116),
    [anon_sym_SEMI] = ACTIONS(114),
    [anon_sym_COMMA] = ACTIONS(114),
    [anon_sym_DOT] = ACTIONS(114),
    [anon_sym_LBRACE] = ACTIONS(114),
    [anon_sym_RBRACE] = ACTIONS(114),
    [anon_sym_LBRACK] = ACTIONS(114),
    [anon_sym_RBRACK] = ACTIONS(114),
    [anon_sym_LPAREN] = ACTIONS(114),
    [anon_sym_RPAREN] = ACTIONS(114),
    [sym_string] = ACTIONS(114),
    [sym_char] = ACTIONS(114),
    [sym_number] = ACTIONS(116),
  },
  [8] = {
    [ts_builtin_sym_end] = ACTIONS(118),
    [sym_identifier] = ACTIONS(120),
    [sym_comment] = ACTIONS(3),
    [anon_sym_PIPE] = ACTIONS(120),
    [anon_sym_PIPE_GT] = ACTIONS(118),
    [anon_sym_COLON_COLON] = ACTIONS(120),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(118),
    [anon_sym_DOLLAR] = ACTIONS(118),
    [anon_sym_LT_LT] = ACTIONS(118),
    [sym_type_identifier] = ACTIONS(120),
    [anon_sym__] = ACTIONS(120),
    [anon_sym_PERCENT] = ACTIONS(118),
    [anon_sym_POUND] = ACTIONS(118),
    [anon_sym_new] = ACTIONS(120),
    [anon_sym_old] = ACTIONS(120),
    [anon_sym_heap] = ACTIONS(120),
    [anon_sym_const] = ACTIONS(120),
    [anon_sym_if] = ACTIONS(120),
    [anon_sym_else] = ACTIONS(120),
    [anon_sym_while] = ACTIONS(120),
    [anon_sym_for] = ACTIONS(120),
    [anon_sym_in] = ACTIONS(120),
    [anon_sym_switch] = ACTIONS(120),
    [anon_sym_case] = ACTIONS(120),
    [anon_sym_fail] = ACTIONS(120),
    [anon_sym_say] = ACTIONS(120),
    [anon_sym_sayif] = ACTIONS(120),
    [anon_sym_debug] = ACTIONS(120),
    [anon_sym_debugif] = ACTIONS(120),
    [anon_sym_print] = ACTIONS(120),
    [anon_sym_printif] = ACTIONS(120),
    [anon_sym_use] = ACTIONS(120),
    [anon_sym_package] = ACTIONS(120),
    [anon_sym_default] = ACTIONS(120),
    [anon_sym_set] = ACTIONS(120),
    [anon_sym_struct] = ACTIONS(120),
    [anon_sym_type] = ACTIONS(120),
    [anon_sym_interface] = ACTIONS(120),
    [anon_sym_alias] = ACTIONS(120),
    [anon_sym_enum] = ACTIONS(120),
    [anon_sym_prop] = ACTIONS(120),
    [anon_sym_impl] = ACTIONS(120),
    [anon_sym_return] = ACTIONS(120),
    [anon_sym_yield] = ACTIONS(120),
    [anon_sym_cascade] = ACTIONS(120),
    [anon_sym_break] = ACTIONS(120),
    [anon_sym_loop] = ACTIONS(120),
    [anon_sym_void] = ACTIONS(120),
    [anon_sym_int] = ACTIONS(120),
    [anon_sym_char] = ACTIONS(120),
    [anon_sym_bool] = ACTIONS(120),
    [anon_sym_float] = ACTIONS(120),
    [anon_sym_range] = ACTIONS(120),
    [anon_sym_list] = ACTIONS(120),
    [anon_sym_string] = ACTIONS(120),
    [anon_sym_line] = ACTIONS(120),
    [anon_sym_word] = ACTIONS(120),
    [anon_sym_Program] = ACTIONS(120),
    [anon_sym_Embedded] = ACTIONS(120),
    [anon_sym_Self] = ACTIONS(120),
    [anon_sym_Type] = ACTIONS(120),
    [anon_sym_Field] = ACTIONS(120),
    [anon_sym_Variable] = ACTIONS(120),
    [anon_sym_into] = ACTIONS(120),
    [anon_sym_fun] = ACTIONS(120),
    [anon_sym_may] = ACTIONS(120),
    [anon_sym_itr] = ACTIONS(120),
    [anon_sym_err] = ACTIONS(120),
    [anon_sym_ark] = ACTIONS(120),
    [anon_sym_ptr] = ACTIONS(120),
    [anon_sym_mut] = ACTIONS(120),
    [anon_sym_ref] = ACTIONS(120),
    [anon_sym_sec] = ACTIONS(120),
    [anon_sym_pkg] = ACTIONS(120),
    [anon_sym_true] = ACTIONS(120),
    [anon_sym_false] = ACTIONS(120),
    [anon_sym_EQ] = ACTIONS(120),
    [anon_sym_LT_DASH] = ACTIONS(118),
    [anon_sym_DASH_GT] = ACTIONS(118),
    [anon_sym_EQ_GT] = ACTIONS(118),
    [anon_sym_QMARK_QMARK] = ACTIONS(118),
    [anon_sym____] = ACTIONS(120),
    [anon_sym_EQ_EQ] = ACTIONS(118),
    [anon_sym_BANG_EQ] = ACTIONS(118),
    [anon_sym_LT] = ACTIONS(120),
    [anon_sym_GT] = ACTIONS(120),
    [anon_sym_LT_EQ] = ACTIONS(118),
    [anon_sym_GT_EQ] = ACTIONS(118),
    [anon_sym_PLUS] = ACTIONS(118),
    [anon_sym_DASH] = ACTIONS(120),
    [anon_sym_STAR] = ACTIONS(118),
    [anon_sym_SLASH] = ACTIONS(120),
    [anon_sym_CARET] = ACTIONS(118),
    [anon_sym_BANG] = ACTIONS(120),
    [anon_sym_TILDE] = ACTIONS(118),
    [anon_sym_AMP] = ACTIONS(118),
    [anon_sym_BSLASH] = ACTIONS(118),
    [anon_sym_QMARK] = ACTIONS(120),
    [anon_sym_AT] = ACTIONS(118),
    [anon_sym_DASH_DASH] = ACTIONS(118),
    [anon_sym_GT_GT] = ACTIONS(118),
    [anon_sym_COLON] = ACTIONS(120),
    [anon_sym_SEMI] = ACTIONS(118),
    [anon_sym_COMMA] = ACTIONS(118),
    [anon_sym_DOT] = ACTIONS(118),
    [anon_sym_LBRACE] = ACTIONS(118),
    [anon_sym_RBRACE] = ACTIONS(118),
    [anon_sym_LBRACK] = ACTIONS(118),
    [anon_sym_RBRACK] = ACTIONS(118),
    [anon_sym_LPAREN] = ACTIONS(118),
    [anon_sym_RPAREN] = ACTIONS(118),
    [sym_string] = ACTIONS(118),
    [sym_char] = ACTIONS(118),
    [sym_number] = ACTIONS(120),
  },
  [9] = {
    [ts_builtin_sym_end] = ACTIONS(122),
    [sym_identifier] = ACTIONS(124),
    [sym_comment] = ACTIONS(3),
    [anon_sym_PIPE] = ACTIONS(124),
    [anon_sym_PIPE_GT] = ACTIONS(122),
    [anon_sym_COLON_COLON] = ACTIONS(124),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(122),
    [anon_sym_DOLLAR] = ACTIONS(122),
    [anon_sym_LT_LT] = ACTIONS(122),
    [sym_type_identifier] = ACTIONS(124),
    [anon_sym__] = ACTIONS(124),
    [anon_sym_PERCENT] = ACTIONS(122),
    [anon_sym_POUND] = ACTIONS(122),
    [anon_sym_new] = ACTIONS(124),
    [anon_sym_old] = ACTIONS(124),
    [anon_sym_heap] = ACTIONS(124),
    [anon_sym_const] = ACTIONS(124),
    [anon_sym_if] = ACTIONS(124),
    [anon_sym_else] = ACTIONS(124),
    [anon_sym_while] = ACTIONS(124),
    [anon_sym_for] = ACTIONS(124),
    [anon_sym_in] = ACTIONS(124),
    [anon_sym_switch] = ACTIONS(124),
    [anon_sym_case] = ACTIONS(124),
    [anon_sym_fail] = ACTIONS(124),
    [anon_sym_say] = ACTIONS(124),
    [anon_sym_sayif] = ACTIONS(124),
    [anon_sym_debug] = ACTIONS(124),
    [anon_sym_debugif] = ACTIONS(124),
    [anon_sym_print] = ACTIONS(124),
    [anon_sym_printif] = ACTIONS(124),
    [anon_sym_use] = ACTIONS(124),
    [anon_sym_package] = ACTIONS(124),
    [anon_sym_default] = ACTIONS(124),
    [anon_sym_set] = ACTIONS(124),
    [anon_sym_struct] = ACTIONS(124),
    [anon_sym_type] = ACTIONS(124),
    [anon_sym_interface] = ACTIONS(124),
    [anon_sym_alias] = ACTIONS(124),
    [anon_sym_enum] = ACTIONS(124),
    [anon_sym_prop] = ACTIONS(124),
    [anon_sym_impl] = ACTIONS(124),
    [anon_sym_return] = ACTIONS(124),
    [anon_sym_yield] = ACTIONS(124),
    [anon_sym_cascade] = ACTIONS(124),
    [anon_sym_break] = ACTIONS(124),
    [anon_sym_loop] = ACTIONS(124),
    [anon_sym_void] = ACTIONS(124),
    [anon_sym_int] = ACTIONS(124),
    [anon_sym_char] = ACTIONS(124),
    [anon_sym_bool] = ACTIONS(124),
    [anon_sym_float] = ACTIONS(124),
    [anon_sym_range] = ACTIONS(124),
    [anon_sym_list] = ACTIONS(124),
    [anon_sym_string] = ACTIONS(124),
    [anon_sym_line] = ACTIONS(124),
    [anon_sym_word] = ACTIONS(124),
    [anon_sym_Program] = ACTIONS(124),
    [anon_sym_Embedded] = ACTIONS(124),
    [anon_sym_Self] = ACTIONS(124),
    [anon_sym_Type] = ACTIONS(124),
    [anon_sym_Field] = ACTIONS(124),
    [anon_sym_Variable] = ACTIONS(124),
    [anon_sym_into] = ACTIONS(124),
    [anon_sym_fun] = ACTIONS(124),
    [anon_sym_may] = ACTIONS(124),
    [anon_sym_itr] = ACTIONS(124),
    [anon_sym_err] = ACTIONS(124),
    [anon_sym_ark] = ACTIONS(124),
    [anon_sym_ptr] = ACTIONS(124),
    [anon_sym_mut] = ACTIONS(124),
    [anon_sym_ref] = ACTIONS(124),
    [anon_sym_sec] = ACTIONS(124),
    [anon_sym_pkg] = ACTIONS(124),
    [anon_sym_true] = ACTIONS(124),
    [anon_sym_false] = ACTIONS(124),
    [anon_sym_EQ] = ACTIONS(124),
    [anon_sym_LT_DASH] = ACTIONS(122),
    [anon_sym_DASH_GT] = ACTIONS(122),
    [anon_sym_EQ_GT] = ACTIONS(122),
    [anon_sym_QMARK_QMARK] = ACTIONS(122),
    [anon_sym____] = ACTIONS(124),
    [anon_sym_EQ_EQ] = ACTIONS(122),
    [anon_sym_BANG_EQ] = ACTIONS(122),
    [anon_sym_LT] = ACTIONS(124),
    [anon_sym_GT] = ACTIONS(124),
    [anon_sym_LT_EQ] = ACTIONS(122),
    [anon_sym_GT_EQ] = ACTIONS(122),
    [anon_sym_PLUS] = ACTIONS(122),
    [anon_sym_DASH] = ACTIONS(124),
    [anon_sym_STAR] = ACTIONS(122),
    [anon_sym_SLASH] = ACTIONS(124),
    [anon_sym_CARET] = ACTIONS(122),
    [anon_sym_BANG] = ACTIONS(124),
    [anon_sym_TILDE] = ACTIONS(122),
    [anon_sym_AMP] = ACTIONS(122),
    [anon_sym_BSLASH] = ACTIONS(122),
    [anon_sym_QMARK] = ACTIONS(124),
    [anon_sym_AT] = ACTIONS(122),
    [anon_sym_DASH_DASH] = ACTIONS(122),
    [anon_sym_GT_GT] = ACTIONS(122),
    [anon_sym_COLON] = ACTIONS(124),
    [anon_sym_SEMI] = ACTIONS(122),
    [anon_sym_COMMA] = ACTIONS(122),
    [anon_sym_DOT] = ACTIONS(122),
    [anon_sym_LBRACE] = ACTIONS(122),
    [anon_sym_RBRACE] = ACTIONS(122),
    [anon_sym_LBRACK] = ACTIONS(122),
    [anon_sym_RBRACK] = ACTIONS(122),
    [anon_sym_LPAREN] = ACTIONS(122),
    [anon_sym_RPAREN] = ACTIONS(122),
    [sym_string] = ACTIONS(122),
    [sym_char] = ACTIONS(122),
    [sym_number] = ACTIONS(124),
  },
  [10] = {
    [ts_builtin_sym_end] = ACTIONS(108),
    [sym_identifier] = ACTIONS(126),
    [sym_comment] = ACTIONS(3),
    [anon_sym_PIPE] = ACTIONS(110),
    [anon_sym_PIPE_GT] = ACTIONS(108),
    [anon_sym_COLON_COLON] = ACTIONS(110),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(108),
    [anon_sym_DOLLAR] = ACTIONS(108),
    [anon_sym_LT_LT] = ACTIONS(108),
    [sym_type_identifier] = ACTIONS(110),
    [anon_sym__] = ACTIONS(110),
    [anon_sym_PERCENT] = ACTIONS(108),
    [anon_sym_POUND] = ACTIONS(108),
    [anon_sym_new] = ACTIONS(110),
    [anon_sym_old] = ACTIONS(110),
    [anon_sym_heap] = ACTIONS(110),
    [anon_sym_const] = ACTIONS(110),
    [anon_sym_if] = ACTIONS(110),
    [anon_sym_else] = ACTIONS(110),
    [anon_sym_while] = ACTIONS(110),
    [anon_sym_for] = ACTIONS(110),
    [anon_sym_in] = ACTIONS(110),
    [anon_sym_switch] = ACTIONS(110),
    [anon_sym_case] = ACTIONS(110),
    [anon_sym_fail] = ACTIONS(110),
    [anon_sym_say] = ACTIONS(110),
    [anon_sym_sayif] = ACTIONS(110),
    [anon_sym_debug] = ACTIONS(110),
    [anon_sym_debugif] = ACTIONS(110),
    [anon_sym_print] = ACTIONS(110),
    [anon_sym_printif] = ACTIONS(110),
    [anon_sym_use] = ACTIONS(110),
    [anon_sym_package] = ACTIONS(110),
    [anon_sym_default] = ACTIONS(110),
    [anon_sym_set] = ACTIONS(110),
    [anon_sym_struct] = ACTIONS(110),
    [anon_sym_type] = ACTIONS(110),
    [anon_sym_interface] = ACTIONS(110),
    [anon_sym_alias] = ACTIONS(110),
    [anon_sym_enum] = ACTIONS(110),
    [anon_sym_prop] = ACTIONS(110),
    [anon_sym_impl] = ACTIONS(110),
    [anon_sym_return] = ACTIONS(110),
    [anon_sym_yield] = ACTIONS(110),
    [anon_sym_cascade] = ACTIONS(110),
    [anon_sym_break] = ACTIONS(110),
    [anon_sym_loop] = ACTIONS(110),
    [anon_sym_void] = ACTIONS(110),
    [anon_sym_int] = ACTIONS(110),
    [anon_sym_char] = ACTIONS(110),
    [anon_sym_bool] = ACTIONS(110),
    [anon_sym_float] = ACTIONS(110),
    [anon_sym_range] = ACTIONS(110),
    [anon_sym_list] = ACTIONS(110),
    [anon_sym_string] = ACTIONS(110),
    [anon_sym_line] = ACTIONS(110),
    [anon_sym_word] = ACTIONS(110),
    [anon_sym_Program] = ACTIONS(110),
    [anon_sym_Embedded] = ACTIONS(110),
    [anon_sym_Self] = ACTIONS(110),
    [anon_sym_Type] = ACTIONS(110),
    [anon_sym_Field] = ACTIONS(110),
    [anon_sym_Variable] = ACTIONS(110),
    [anon_sym_into] = ACTIONS(110),
    [anon_sym_fun] = ACTIONS(110),
    [anon_sym_may] = ACTIONS(110),
    [anon_sym_itr] = ACTIONS(110),
    [anon_sym_err] = ACTIONS(110),
    [anon_sym_ark] = ACTIONS(110),
    [anon_sym_ptr] = ACTIONS(110),
    [anon_sym_mut] = ACTIONS(110),
    [anon_sym_ref] = ACTIONS(110),
    [anon_sym_sec] = ACTIONS(110),
    [anon_sym_pkg] = ACTIONS(110),
    [anon_sym_true] = ACTIONS(110),
    [anon_sym_false] = ACTIONS(110),
    [anon_sym_EQ] = ACTIONS(110),
    [anon_sym_LT_DASH] = ACTIONS(108),
    [anon_sym_DASH_GT] = ACTIONS(108),
    [anon_sym_EQ_GT] = ACTIONS(108),
    [anon_sym_QMARK_QMARK] = ACTIONS(108),
    [anon_sym____] = ACTIONS(110),
    [anon_sym_EQ_EQ] = ACTIONS(108),
    [anon_sym_BANG_EQ] = ACTIONS(108),
    [anon_sym_LT] = ACTIONS(110),
    [anon_sym_GT] = ACTIONS(110),
    [anon_sym_LT_EQ] = ACTIONS(108),
    [anon_sym_GT_EQ] = ACTIONS(108),
    [anon_sym_PLUS] = ACTIONS(108),
    [anon_sym_DASH] = ACTIONS(110),
    [anon_sym_STAR] = ACTIONS(108),
    [anon_sym_SLASH] = ACTIONS(110),
    [anon_sym_CARET] = ACTIONS(108),
    [anon_sym_BANG] = ACTIONS(110),
    [anon_sym_TILDE] = ACTIONS(108),
    [anon_sym_AMP] = ACTIONS(108),
    [anon_sym_BSLASH] = ACTIONS(108),
    [anon_sym_QMARK] = ACTIONS(110),
    [anon_sym_AT] = ACTIONS(108),
    [anon_sym_DASH_DASH] = ACTIONS(108),
    [anon_sym_GT_GT] = ACTIONS(108),
    [anon_sym_COLON] = ACTIONS(110),
    [anon_sym_SEMI] = ACTIONS(108),
    [anon_sym_COMMA] = ACTIONS(108),
    [anon_sym_DOT] = ACTIONS(108),
    [anon_sym_LBRACE] = ACTIONS(108),
    [anon_sym_RBRACE] = ACTIONS(108),
    [anon_sym_LBRACK] = ACTIONS(108),
    [anon_sym_RBRACK] = ACTIONS(108),
    [anon_sym_LPAREN] = ACTIONS(108),
    [anon_sym_RPAREN] = ACTIONS(108),
    [sym_string] = ACTIONS(108),
    [sym_char] = ACTIONS(108),
    [sym_number] = ACTIONS(110),
  },
  [11] = {
    [ts_builtin_sym_end] = ACTIONS(128),
    [sym_identifier] = ACTIONS(130),
    [sym_comment] = ACTIONS(3),
    [anon_sym_PIPE] = ACTIONS(130),
    [anon_sym_PIPE_GT] = ACTIONS(128),
    [anon_sym_COLON_COLON] = ACTIONS(130),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(128),
    [anon_sym_DOLLAR] = ACTIONS(128),
    [anon_sym_LT_LT] = ACTIONS(128),
    [sym_type_identifier] = ACTIONS(130),
    [anon_sym__] = ACTIONS(130),
    [anon_sym_PERCENT] = ACTIONS(128),
    [anon_sym_POUND] = ACTIONS(128),
    [anon_sym_new] = ACTIONS(130),
    [anon_sym_old] = ACTIONS(130),
    [anon_sym_heap] = ACTIONS(130),
    [anon_sym_const] = ACTIONS(130),
    [anon_sym_if] = ACTIONS(130),
    [anon_sym_else] = ACTIONS(130),
    [anon_sym_while] = ACTIONS(130),
    [anon_sym_for] = ACTIONS(130),
    [anon_sym_in] = ACTIONS(130),
    [anon_sym_switch] = ACTIONS(130),
    [anon_sym_case] = ACTIONS(130),
    [anon_sym_fail] = ACTIONS(130),
    [anon_sym_say] = ACTIONS(130),
    [anon_sym_sayif] = ACTIONS(130),
    [anon_sym_debug] = ACTIONS(130),
    [anon_sym_debugif] = ACTIONS(130),
    [anon_sym_print] = ACTIONS(130),
    [anon_sym_printif] = ACTIONS(130),
    [anon_sym_use] = ACTIONS(130),
    [anon_sym_package] = ACTIONS(130),
    [anon_sym_default] = ACTIONS(130),
    [anon_sym_set] = ACTIONS(130),
    [anon_sym_struct] = ACTIONS(130),
    [anon_sym_type] = ACTIONS(130),
    [anon_sym_interface] = ACTIONS(130),
    [anon_sym_alias] = ACTIONS(130),
    [anon_sym_enum] = ACTIONS(130),
    [anon_sym_prop] = ACTIONS(130),
    [anon_sym_impl] = ACTIONS(130),
    [anon_sym_return] = ACTIONS(130),
    [anon_sym_yield] = ACTIONS(130),
    [anon_sym_cascade] = ACTIONS(130),
    [anon_sym_break] = ACTIONS(130),
    [anon_sym_loop] = ACTIONS(130),
    [anon_sym_void] = ACTIONS(130),
    [anon_sym_int] = ACTIONS(130),
    [anon_sym_char] = ACTIONS(130),
    [anon_sym_bool] = ACTIONS(130),
    [anon_sym_float] = ACTIONS(130),
    [anon_sym_range] = ACTIONS(130),
    [anon_sym_list] = ACTIONS(130),
    [anon_sym_string] = ACTIONS(130),
    [anon_sym_line] = ACTIONS(130),
    [anon_sym_word] = ACTIONS(130),
    [anon_sym_Program] = ACTIONS(130),
    [anon_sym_Embedded] = ACTIONS(130),
    [anon_sym_Self] = ACTIONS(130),
    [anon_sym_Type] = ACTIONS(130),
    [anon_sym_Field] = ACTIONS(130),
    [anon_sym_Variable] = ACTIONS(130),
    [anon_sym_into] = ACTIONS(130),
    [anon_sym_fun] = ACTIONS(130),
    [anon_sym_may] = ACTIONS(130),
    [anon_sym_itr] = ACTIONS(130),
    [anon_sym_err] = ACTIONS(130),
    [anon_sym_ark] = ACTIONS(130),
    [anon_sym_ptr] = ACTIONS(130),
    [anon_sym_mut] = ACTIONS(130),
    [anon_sym_ref] = ACTIONS(130),
    [anon_sym_sec] = ACTIONS(130),
    [anon_sym_pkg] = ACTIONS(130),
    [anon_sym_true] = ACTIONS(130),
    [anon_sym_false] = ACTIONS(130),
    [anon_sym_EQ] = ACTIONS(130),
    [anon_sym_LT_DASH] = ACTIONS(128),
    [anon_sym_DASH_GT] = ACTIONS(128),
    [anon_sym_EQ_GT] = ACTIONS(128),
    [anon_sym_QMARK_QMARK] = ACTIONS(128),
    [anon_sym____] = ACTIONS(130),
    [anon_sym_EQ_EQ] = ACTIONS(128),
    [anon_sym_BANG_EQ] = ACTIONS(128),
    [anon_sym_LT] = ACTIONS(130),
    [anon_sym_GT] = ACTIONS(130),
    [anon_sym_LT_EQ] = ACTIONS(128),
    [anon_sym_GT_EQ] = ACTIONS(128),
    [anon_sym_PLUS] = ACTIONS(128),
    [anon_sym_DASH] = ACTIONS(130),
    [anon_sym_STAR] = ACTIONS(128),
    [anon_sym_SLASH] = ACTIONS(130),
    [anon_sym_CARET] = ACTIONS(128),
    [anon_sym_BANG] = ACTIONS(130),
    [anon_sym_TILDE] = ACTIONS(128),
    [anon_sym_AMP] = ACTIONS(128),
    [anon_sym_BSLASH] = ACTIONS(128),
    [anon_sym_QMARK] = ACTIONS(130),
    [anon_sym_AT] = ACTIONS(128),
    [anon_sym_DASH_DASH] = ACTIONS(128),
    [anon_sym_GT_GT] = ACTIONS(128),
    [anon_sym_COLON] = ACTIONS(130),
    [anon_sym_SEMI] = ACTIONS(128),
    [anon_sym_COMMA] = ACTIONS(128),
    [anon_sym_DOT] = ACTIONS(128),
    [anon_sym_LBRACE] = ACTIONS(128),
    [anon_sym_RBRACE] = ACTIONS(128),
    [anon_sym_LBRACK] = ACTIONS(128),
    [anon_sym_RBRACK] = ACTIONS(128),
    [anon_sym_LPAREN] = ACTIONS(128),
    [anon_sym_RPAREN] = ACTIONS(128),
    [sym_string] = ACTIONS(128),
    [sym_char] = ACTIONS(128),
    [sym_number] = ACTIONS(130),
  },
  [12] = {
    [ts_builtin_sym_end] = ACTIONS(108),
    [sym_identifier] = ACTIONS(110),
    [sym_comment] = ACTIONS(3),
    [anon_sym_PIPE] = ACTIONS(110),
    [anon_sym_PIPE_GT] = ACTIONS(108),
    [anon_sym_COLON_COLON] = ACTIONS(110),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(108),
    [anon_sym_DOLLAR] = ACTIONS(108),
    [anon_sym_LT_LT] = ACTIONS(108),
    [sym_type_identifier] = ACTIONS(110),
    [anon_sym__] = ACTIONS(110),
    [anon_sym_PERCENT] = ACTIONS(108),
    [anon_sym_POUND] = ACTIONS(108),
    [anon_sym_new] = ACTIONS(110),
    [anon_sym_old] = ACTIONS(110),
    [anon_sym_heap] = ACTIONS(110),
    [anon_sym_const] = ACTIONS(110),
    [anon_sym_if] = ACTIONS(110),
    [anon_sym_else] = ACTIONS(110),
    [anon_sym_while] = ACTIONS(110),
    [anon_sym_for] = ACTIONS(110),
    [anon_sym_in] = ACTIONS(110),
    [anon_sym_switch] = ACTIONS(110),
    [anon_sym_case] = ACTIONS(110),
    [anon_sym_fail] = ACTIONS(110),
    [anon_sym_say] = ACTIONS(110),
    [anon_sym_sayif] = ACTIONS(110),
    [anon_sym_debug] = ACTIONS(110),
    [anon_sym_debugif] = ACTIONS(110),
    [anon_sym_print] = ACTIONS(110),
    [anon_sym_printif] = ACTIONS(110),
    [anon_sym_use] = ACTIONS(110),
    [anon_sym_package] = ACTIONS(110),
    [anon_sym_default] = ACTIONS(110),
    [anon_sym_set] = ACTIONS(110),
    [anon_sym_struct] = ACTIONS(110),
    [anon_sym_type] = ACTIONS(110),
    [anon_sym_interface] = ACTIONS(110),
    [anon_sym_alias] = ACTIONS(110),
    [anon_sym_enum] = ACTIONS(110),
    [anon_sym_prop] = ACTIONS(110),
    [anon_sym_impl] = ACTIONS(110),
    [anon_sym_return] = ACTIONS(110),
    [anon_sym_yield] = ACTIONS(110),
    [anon_sym_cascade] = ACTIONS(110),
    [anon_sym_break] = ACTIONS(110),
    [anon_sym_loop] = ACTIONS(110),
    [anon_sym_void] = ACTIONS(110),
    [anon_sym_int] = ACTIONS(110),
    [anon_sym_char] = ACTIONS(110),
    [anon_sym_bool] = ACTIONS(110),
    [anon_sym_float] = ACTIONS(110),
    [anon_sym_range] = ACTIONS(110),
    [anon_sym_list] = ACTIONS(110),
    [anon_sym_string] = ACTIONS(110),
    [anon_sym_line] = ACTIONS(110),
    [anon_sym_word] = ACTIONS(110),
    [anon_sym_Program] = ACTIONS(110),
    [anon_sym_Embedded] = ACTIONS(110),
    [anon_sym_Self] = ACTIONS(110),
    [anon_sym_Type] = ACTIONS(110),
    [anon_sym_Field] = ACTIONS(110),
    [anon_sym_Variable] = ACTIONS(110),
    [anon_sym_into] = ACTIONS(110),
    [anon_sym_fun] = ACTIONS(110),
    [anon_sym_may] = ACTIONS(110),
    [anon_sym_itr] = ACTIONS(110),
    [anon_sym_err] = ACTIONS(110),
    [anon_sym_ark] = ACTIONS(110),
    [anon_sym_ptr] = ACTIONS(110),
    [anon_sym_mut] = ACTIONS(110),
    [anon_sym_ref] = ACTIONS(110),
    [anon_sym_sec] = ACTIONS(110),
    [anon_sym_pkg] = ACTIONS(110),
    [anon_sym_true] = ACTIONS(110),
    [anon_sym_false] = ACTIONS(110),
    [anon_sym_EQ] = ACTIONS(110),
    [anon_sym_LT_DASH] = ACTIONS(108),
    [anon_sym_DASH_GT] = ACTIONS(108),
    [anon_sym_EQ_GT] = ACTIONS(108),
    [anon_sym_QMARK_QMARK] = ACTIONS(108),
    [anon_sym____] = ACTIONS(110),
    [anon_sym_EQ_EQ] = ACTIONS(108),
    [anon_sym_BANG_EQ] = ACTIONS(108),
    [anon_sym_LT] = ACTIONS(110),
    [anon_sym_GT] = ACTIONS(110),
    [anon_sym_LT_EQ] = ACTIONS(108),
    [anon_sym_GT_EQ] = ACTIONS(108),
    [anon_sym_PLUS] = ACTIONS(108),
    [anon_sym_DASH] = ACTIONS(110),
    [anon_sym_STAR] = ACTIONS(108),
    [anon_sym_SLASH] = ACTIONS(110),
    [anon_sym_CARET] = ACTIONS(108),
    [anon_sym_BANG] = ACTIONS(110),
    [anon_sym_TILDE] = ACTIONS(108),
    [anon_sym_AMP] = ACTIONS(108),
    [anon_sym_BSLASH] = ACTIONS(108),
    [anon_sym_QMARK] = ACTIONS(110),
    [anon_sym_AT] = ACTIONS(108),
    [anon_sym_DASH_DASH] = ACTIONS(108),
    [anon_sym_GT_GT] = ACTIONS(108),
    [anon_sym_COLON] = ACTIONS(110),
    [anon_sym_SEMI] = ACTIONS(108),
    [anon_sym_COMMA] = ACTIONS(108),
    [anon_sym_DOT] = ACTIONS(108),
    [anon_sym_LBRACE] = ACTIONS(108),
    [anon_sym_RBRACE] = ACTIONS(108),
    [anon_sym_LBRACK] = ACTIONS(108),
    [anon_sym_RBRACK] = ACTIONS(108),
    [anon_sym_LPAREN] = ACTIONS(108),
    [anon_sym_RPAREN] = ACTIONS(108),
    [sym_string] = ACTIONS(108),
    [sym_char] = ACTIONS(108),
    [sym_number] = ACTIONS(110),
  },
  [13] = {
    [ts_builtin_sym_end] = ACTIONS(132),
    [sym_identifier] = ACTIONS(134),
    [sym_comment] = ACTIONS(3),
    [anon_sym_PIPE] = ACTIONS(134),
    [anon_sym_PIPE_GT] = ACTIONS(132),
    [anon_sym_COLON_COLON] = ACTIONS(134),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(132),
    [anon_sym_DOLLAR] = ACTIONS(132),
    [anon_sym_LT_LT] = ACTIONS(132),
    [sym_type_identifier] = ACTIONS(134),
    [anon_sym__] = ACTIONS(134),
    [anon_sym_PERCENT] = ACTIONS(132),
    [anon_sym_POUND] = ACTIONS(132),
    [anon_sym_new] = ACTIONS(134),
    [anon_sym_old] = ACTIONS(134),
    [anon_sym_heap] = ACTIONS(134),
    [anon_sym_const] = ACTIONS(134),
    [anon_sym_if] = ACTIONS(134),
    [anon_sym_else] = ACTIONS(134),
    [anon_sym_while] = ACTIONS(134),
    [anon_sym_for] = ACTIONS(134),
    [anon_sym_in] = ACTIONS(134),
    [anon_sym_switch] = ACTIONS(134),
    [anon_sym_case] = ACTIONS(134),
    [anon_sym_fail] = ACTIONS(134),
    [anon_sym_say] = ACTIONS(134),
    [anon_sym_sayif] = ACTIONS(134),
    [anon_sym_debug] = ACTIONS(134),
    [anon_sym_debugif] = ACTIONS(134),
    [anon_sym_print] = ACTIONS(134),
    [anon_sym_printif] = ACTIONS(134),
    [anon_sym_use] = ACTIONS(134),
    [anon_sym_package] = ACTIONS(134),
    [anon_sym_default] = ACTIONS(134),
    [anon_sym_set] = ACTIONS(134),
    [anon_sym_struct] = ACTIONS(134),
    [anon_sym_type] = ACTIONS(134),
    [anon_sym_interface] = ACTIONS(134),
    [anon_sym_alias] = ACTIONS(134),
    [anon_sym_enum] = ACTIONS(134),
    [anon_sym_prop] = ACTIONS(134),
    [anon_sym_impl] = ACTIONS(134),
    [anon_sym_return] = ACTIONS(134),
    [anon_sym_yield] = ACTIONS(134),
    [anon_sym_cascade] = ACTIONS(134),
    [anon_sym_break] = ACTIONS(134),
    [anon_sym_loop] = ACTIONS(134),
    [anon_sym_void] = ACTIONS(134),
    [anon_sym_int] = ACTIONS(134),
    [anon_sym_char] = ACTIONS(134),
    [anon_sym_bool] = ACTIONS(134),
    [anon_sym_float] = ACTIONS(134),
    [anon_sym_range] = ACTIONS(134),
    [anon_sym_list] = ACTIONS(134),
    [anon_sym_string] = ACTIONS(134),
    [anon_sym_line] = ACTIONS(134),
    [anon_sym_word] = ACTIONS(134),
    [anon_sym_Program] = ACTIONS(134),
    [anon_sym_Embedded] = ACTIONS(134),
    [anon_sym_Self] = ACTIONS(134),
    [anon_sym_Type] = ACTIONS(134),
    [anon_sym_Field] = ACTIONS(134),
    [anon_sym_Variable] = ACTIONS(134),
    [anon_sym_into] = ACTIONS(134),
    [anon_sym_fun] = ACTIONS(134),
    [anon_sym_may] = ACTIONS(134),
    [anon_sym_itr] = ACTIONS(134),
    [anon_sym_err] = ACTIONS(134),
    [anon_sym_ark] = ACTIONS(134),
    [anon_sym_ptr] = ACTIONS(134),
    [anon_sym_mut] = ACTIONS(134),
    [anon_sym_ref] = ACTIONS(134),
    [anon_sym_sec] = ACTIONS(134),
    [anon_sym_pkg] = ACTIONS(134),
    [anon_sym_true] = ACTIONS(134),
    [anon_sym_false] = ACTIONS(134),
    [anon_sym_EQ] = ACTIONS(134),
    [anon_sym_LT_DASH] = ACTIONS(132),
    [anon_sym_DASH_GT] = ACTIONS(132),
    [anon_sym_EQ_GT] = ACTIONS(132),
    [anon_sym_QMARK_QMARK] = ACTIONS(132),
    [anon_sym____] = ACTIONS(134),
    [anon_sym_EQ_EQ] = ACTIONS(132),
    [anon_sym_BANG_EQ] = ACTIONS(132),
    [anon_sym_LT] = ACTIONS(134),
    [anon_sym_GT] = ACTIONS(134),
    [anon_sym_LT_EQ] = ACTIONS(132),
    [anon_sym_GT_EQ] = ACTIONS(132),
    [anon_sym_PLUS] = ACTIONS(132),
    [anon_sym_DASH] = ACTIONS(134),
    [anon_sym_STAR] = ACTIONS(132),
    [anon_sym_SLASH] = ACTIONS(134),
    [anon_sym_CARET] = ACTIONS(132),
    [anon_sym_BANG] = ACTIONS(134),
    [anon_sym_TILDE] = ACTIONS(132),
    [anon_sym_AMP] = ACTIONS(132),
    [anon_sym_BSLASH] = ACTIONS(132),
    [anon_sym_QMARK] = ACTIONS(134),
    [anon_sym_AT] = ACTIONS(132),
    [anon_sym_DASH_DASH] = ACTIONS(132),
    [anon_sym_GT_GT] = ACTIONS(132),
    [anon_sym_COLON] = ACTIONS(134),
    [anon_sym_SEMI] = ACTIONS(132),
    [anon_sym_COMMA] = ACTIONS(132),
    [anon_sym_DOT] = ACTIONS(132),
    [anon_sym_LBRACE] = ACTIONS(132),
    [anon_sym_RBRACE] = ACTIONS(132),
    [anon_sym_LBRACK] = ACTIONS(132),
    [anon_sym_RBRACK] = ACTIONS(132),
    [anon_sym_LPAREN] = ACTIONS(132),
    [anon_sym_RPAREN] = ACTIONS(132),
    [sym_string] = ACTIONS(132),
    [sym_char] = ACTIONS(132),
    [sym_number] = ACTIONS(134),
  },
  [14] = {
    [ts_builtin_sym_end] = ACTIONS(136),
    [sym_identifier] = ACTIONS(138),
    [sym_comment] = ACTIONS(3),
    [anon_sym_PIPE] = ACTIONS(138),
    [anon_sym_PIPE_GT] = ACTIONS(136),
    [anon_sym_COLON_COLON] = ACTIONS(140),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(142),
    [anon_sym_DOLLAR] = ACTIONS(144),
    [anon_sym_LT_LT] = ACTIONS(144),
    [sym_type_identifier] = ACTIONS(138),
    [anon_sym__] = ACTIONS(138),
    [anon_sym_PERCENT] = ACTIONS(136),
    [anon_sym_POUND] = ACTIONS(136),
    [anon_sym_new] = ACTIONS(138),
    [anon_sym_old] = ACTIONS(138),
    [anon_sym_heap] = ACTIONS(138),
    [anon_sym_const] = ACTIONS(138),
    [anon_sym_if] = ACTIONS(138),
    [anon_sym_else] = ACTIONS(138),
    [anon_sym_while] = ACTIONS(138),
    [anon_sym_for] = ACTIONS(138),
    [anon_sym_in] = ACTIONS(138),
    [anon_sym_switch] = ACTIONS(138),
    [anon_sym_case] = ACTIONS(138),
    [anon_sym_fail] = ACTIONS(138),
    [anon_sym_say] = ACTIONS(138),
    [anon_sym_sayif] = ACTIONS(138),
    [anon_sym_debug] = ACTIONS(138),
    [anon_sym_debugif] = ACTIONS(138),
    [anon_sym_print] = ACTIONS(138),
    [anon_sym_printif] = ACTIONS(138),
    [anon_sym_use] = ACTIONS(138),
    [anon_sym_package] = ACTIONS(138),
    [anon_sym_default] = ACTIONS(138),
    [anon_sym_set] = ACTIONS(138),
    [anon_sym_struct] = ACTIONS(138),
    [anon_sym_type] = ACTIONS(138),
    [anon_sym_interface] = ACTIONS(138),
    [anon_sym_alias] = ACTIONS(138),
    [anon_sym_enum] = ACTIONS(138),
    [anon_sym_prop] = ACTIONS(138),
    [anon_sym_impl] = ACTIONS(138),
    [anon_sym_return] = ACTIONS(138),
    [anon_sym_yield] = ACTIONS(138),
    [anon_sym_cascade] = ACTIONS(138),
    [anon_sym_break] = ACTIONS(138),
    [anon_sym_loop] = ACTIONS(138),
    [anon_sym_void] = ACTIONS(138),
    [anon_sym_int] = ACTIONS(138),
    [anon_sym_char] = ACTIONS(138),
    [anon_sym_bool] = ACTIONS(138),
    [anon_sym_float] = ACTIONS(138),
    [anon_sym_range] = ACTIONS(138),
    [anon_sym_list] = ACTIONS(138),
    [anon_sym_string] = ACTIONS(138),
    [anon_sym_line] = ACTIONS(138),
    [anon_sym_word] = ACTIONS(138),
    [anon_sym_Program] = ACTIONS(138),
    [anon_sym_Embedded] = ACTIONS(138),
    [anon_sym_Self] = ACTIONS(138),
    [anon_sym_Type] = ACTIONS(138),
    [anon_sym_Field] = ACTIONS(138),
    [anon_sym_Variable] = ACTIONS(138),
    [anon_sym_into] = ACTIONS(138),
    [anon_sym_fun] = ACTIONS(138),
    [anon_sym_may] = ACTIONS(138),
    [anon_sym_itr] = ACTIONS(138),
    [anon_sym_err] = ACTIONS(138),
    [anon_sym_ark] = ACTIONS(138),
    [anon_sym_ptr] = ACTIONS(138),
    [anon_sym_mut] = ACTIONS(138),
    [anon_sym_ref] = ACTIONS(138),
    [anon_sym_sec] = ACTIONS(138),
    [anon_sym_pkg] = ACTIONS(138),
    [anon_sym_true] = ACTIONS(138),
    [anon_sym_false] = ACTIONS(138),
    [anon_sym_EQ] = ACTIONS(138),
    [anon_sym_LT_DASH] = ACTIONS(136),
    [anon_sym_DASH_GT] = ACTIONS(136),
    [anon_sym_EQ_GT] = ACTIONS(136),
    [anon_sym_QMARK_QMARK] = ACTIONS(136),
    [anon_sym____] = ACTIONS(138),
    [anon_sym_EQ_EQ] = ACTIONS(136),
    [anon_sym_BANG_EQ] = ACTIONS(136),
    [anon_sym_LT] = ACTIONS(138),
    [anon_sym_GT] = ACTIONS(138),
    [anon_sym_LT_EQ] = ACTIONS(136),
    [anon_sym_GT_EQ] = ACTIONS(136),
    [anon_sym_PLUS] = ACTIONS(136),
    [anon_sym_DASH] = ACTIONS(138),
    [anon_sym_STAR] = ACTIONS(136),
    [anon_sym_SLASH] = ACTIONS(138),
    [anon_sym_CARET] = ACTIONS(136),
    [anon_sym_BANG] = ACTIONS(138),
    [anon_sym_TILDE] = ACTIONS(136),
    [anon_sym_AMP] = ACTIONS(136),
    [anon_sym_BSLASH] = ACTIONS(136),
    [anon_sym_QMARK] = ACTIONS(138),
    [anon_sym_AT] = ACTIONS(136),
    [anon_sym_DASH_DASH] = ACTIONS(136),
    [anon_sym_GT_GT] = ACTIONS(136),
    [anon_sym_COLON] = ACTIONS(138),
    [anon_sym_SEMI] = ACTIONS(136),
    [anon_sym_COMMA] = ACTIONS(136),
    [anon_sym_DOT] = ACTIONS(136),
    [anon_sym_LBRACE] = ACTIONS(136),
    [anon_sym_RBRACE] = ACTIONS(136),
    [anon_sym_LBRACK] = ACTIONS(136),
    [anon_sym_RBRACK] = ACTIONS(136),
    [anon_sym_LPAREN] = ACTIONS(136),
    [anon_sym_RPAREN] = ACTIONS(136),
    [sym_string] = ACTIONS(136),
    [sym_char] = ACTIONS(136),
    [sym_number] = ACTIONS(138),
  },
  [15] = {
    [ts_builtin_sym_end] = ACTIONS(146),
    [sym_identifier] = ACTIONS(148),
    [sym_comment] = ACTIONS(3),
    [anon_sym_PIPE] = ACTIONS(148),
    [anon_sym_PIPE_GT] = ACTIONS(146),
    [anon_sym_COLON_COLON] = ACTIONS(148),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(146),
    [anon_sym_DOLLAR] = ACTIONS(146),
    [anon_sym_LT_LT] = ACTIONS(146),
    [sym_type_identifier] = ACTIONS(148),
    [anon_sym__] = ACTIONS(148),
    [anon_sym_PERCENT] = ACTIONS(146),
    [anon_sym_POUND] = ACTIONS(146),
    [anon_sym_new] = ACTIONS(148),
    [anon_sym_old] = ACTIONS(148),
    [anon_sym_heap] = ACTIONS(148),
    [anon_sym_const] = ACTIONS(148),
    [anon_sym_if] = ACTIONS(148),
    [anon_sym_else] = ACTIONS(148),
    [anon_sym_while] = ACTIONS(148),
    [anon_sym_for] = ACTIONS(148),
    [anon_sym_in] = ACTIONS(148),
    [anon_sym_switch] = ACTIONS(148),
    [anon_sym_case] = ACTIONS(148),
    [anon_sym_fail] = ACTIONS(148),
    [anon_sym_say] = ACTIONS(148),
    [anon_sym_sayif] = ACTIONS(148),
    [anon_sym_debug] = ACTIONS(148),
    [anon_sym_debugif] = ACTIONS(148),
    [anon_sym_print] = ACTIONS(148),
    [anon_sym_printif] = ACTIONS(148),
    [anon_sym_use] = ACTIONS(148),
    [anon_sym_package] = ACTIONS(148),
    [anon_sym_default] = ACTIONS(148),
    [anon_sym_set] = ACTIONS(148),
    [anon_sym_struct] = ACTIONS(148),
    [anon_sym_type] = ACTIONS(148),
    [anon_sym_interface] = ACTIONS(148),
    [anon_sym_alias] = ACTIONS(148),
    [anon_sym_enum] = ACTIONS(148),
    [anon_sym_prop] = ACTIONS(148),
    [anon_sym_impl] = ACTIONS(148),
    [anon_sym_return] = ACTIONS(148),
    [anon_sym_yield] = ACTIONS(148),
    [anon_sym_cascade] = ACTIONS(148),
    [anon_sym_break] = ACTIONS(148),
    [anon_sym_loop] = ACTIONS(148),
    [anon_sym_void] = ACTIONS(148),
    [anon_sym_int] = ACTIONS(148),
    [anon_sym_char] = ACTIONS(148),
    [anon_sym_bool] = ACTIONS(148),
    [anon_sym_float] = ACTIONS(148),
    [anon_sym_range] = ACTIONS(148),
    [anon_sym_list] = ACTIONS(148),
    [anon_sym_string] = ACTIONS(148),
    [anon_sym_line] = ACTIONS(148),
    [anon_sym_word] = ACTIONS(148),
    [anon_sym_Program] = ACTIONS(148),
    [anon_sym_Embedded] = ACTIONS(148),
    [anon_sym_Self] = ACTIONS(148),
    [anon_sym_Type] = ACTIONS(148),
    [anon_sym_Field] = ACTIONS(148),
    [anon_sym_Variable] = ACTIONS(148),
    [anon_sym_into] = ACTIONS(148),
    [anon_sym_fun] = ACTIONS(148),
    [anon_sym_may] = ACTIONS(148),
    [anon_sym_itr] = ACTIONS(148),
    [anon_sym_err] = ACTIONS(148),
    [anon_sym_ark] = ACTIONS(148),
    [anon_sym_ptr] = ACTIONS(148),
    [anon_sym_mut] = ACTIONS(148),
    [anon_sym_ref] = ACTIONS(148),
    [anon_sym_sec] = ACTIONS(148),
    [anon_sym_pkg] = ACTIONS(148),
    [anon_sym_true] = ACTIONS(148),
    [anon_sym_false] = ACTIONS(148),
    [anon_sym_EQ] = ACTIONS(148),
    [anon_sym_LT_DASH] = ACTIONS(146),
    [anon_sym_DASH_GT] = ACTIONS(146),
    [anon_sym_EQ_GT] = ACTIONS(146),
    [anon_sym_QMARK_QMARK] = ACTIONS(146),
    [anon_sym____] = ACTIONS(148),
    [anon_sym_EQ_EQ] = ACTIONS(146),
    [anon_sym_BANG_EQ] = ACTIONS(146),
    [anon_sym_LT] = ACTIONS(148),
    [anon_sym_GT] = ACTIONS(148),
    [anon_sym_LT_EQ] = ACTIONS(146),
    [anon_sym_GT_EQ] = ACTIONS(146),
    [anon_sym_PLUS] = ACTIONS(146),
    [anon_sym_DASH] = ACTIONS(148),
    [anon_sym_STAR] = ACTIONS(146),
    [anon_sym_SLASH] = ACTIONS(148),
    [anon_sym_CARET] = ACTIONS(146),
    [anon_sym_BANG] = ACTIONS(148),
    [anon_sym_TILDE] = ACTIONS(146),
    [anon_sym_AMP] = ACTIONS(146),
    [anon_sym_BSLASH] = ACTIONS(146),
    [anon_sym_QMARK] = ACTIONS(148),
    [anon_sym_AT] = ACTIONS(146),
    [anon_sym_DASH_DASH] = ACTIONS(146),
    [anon_sym_GT_GT] = ACTIONS(146),
    [anon_sym_COLON] = ACTIONS(148),
    [anon_sym_SEMI] = ACTIONS(146),
    [anon_sym_COMMA] = ACTIONS(146),
    [anon_sym_DOT] = ACTIONS(146),
    [anon_sym_LBRACE] = ACTIONS(146),
    [anon_sym_RBRACE] = ACTIONS(146),
    [anon_sym_LBRACK] = ACTIONS(146),
    [anon_sym_RBRACK] = ACTIONS(146),
    [anon_sym_LPAREN] = ACTIONS(146),
    [anon_sym_RPAREN] = ACTIONS(146),
    [sym_string] = ACTIONS(146),
    [sym_char] = ACTIONS(146),
    [sym_number] = ACTIONS(148),
  },
  [16] = {
    [ts_builtin_sym_end] = ACTIONS(108),
    [sym_identifier] = ACTIONS(110),
    [sym_comment] = ACTIONS(3),
    [anon_sym_PIPE] = ACTIONS(110),
    [anon_sym_PIPE_GT] = ACTIONS(108),
    [anon_sym_COLON_COLON] = ACTIONS(110),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(108),
    [anon_sym_DOLLAR] = ACTIONS(108),
    [anon_sym_LT_LT] = ACTIONS(108),
    [sym_type_identifier] = ACTIONS(110),
    [anon_sym__] = ACTIONS(110),
    [anon_sym_PERCENT] = ACTIONS(108),
    [anon_sym_POUND] = ACTIONS(108),
    [anon_sym_new] = ACTIONS(110),
    [anon_sym_old] = ACTIONS(110),
    [anon_sym_heap] = ACTIONS(110),
    [anon_sym_const] = ACTIONS(110),
    [anon_sym_if] = ACTIONS(110),
    [anon_sym_else] = ACTIONS(110),
    [anon_sym_while] = ACTIONS(110),
    [anon_sym_for] = ACTIONS(110),
    [anon_sym_in] = ACTIONS(110),
    [anon_sym_switch] = ACTIONS(110),
    [anon_sym_case] = ACTIONS(110),
    [anon_sym_fail] = ACTIONS(110),
    [anon_sym_say] = ACTIONS(110),
    [anon_sym_sayif] = ACTIONS(110),
    [anon_sym_debug] = ACTIONS(110),
    [anon_sym_debugif] = ACTIONS(110),
    [anon_sym_print] = ACTIONS(110),
    [anon_sym_printif] = ACTIONS(110),
    [anon_sym_use] = ACTIONS(110),
    [anon_sym_package] = ACTIONS(110),
    [anon_sym_default] = ACTIONS(110),
    [anon_sym_set] = ACTIONS(110),
    [anon_sym_struct] = ACTIONS(110),
    [anon_sym_type] = ACTIONS(110),
    [anon_sym_interface] = ACTIONS(110),
    [anon_sym_alias] = ACTIONS(110),
    [anon_sym_enum] = ACTIONS(110),
    [anon_sym_prop] = ACTIONS(110),
    [anon_sym_impl] = ACTIONS(110),
    [anon_sym_return] = ACTIONS(110),
    [anon_sym_yield] = ACTIONS(110),
    [anon_sym_cascade] = ACTIONS(110),
    [anon_sym_break] = ACTIONS(110),
    [anon_sym_loop] = ACTIONS(110),
    [anon_sym_void] = ACTIONS(110),
    [anon_sym_int] = ACTIONS(110),
    [anon_sym_char] = ACTIONS(110),
    [anon_sym_bool] = ACTIONS(110),
    [anon_sym_float] = ACTIONS(110),
    [anon_sym_range] = ACTIONS(110),
    [anon_sym_list] = ACTIONS(110),
    [anon_sym_string] = ACTIONS(110),
    [anon_sym_line] = ACTIONS(110),
    [anon_sym_word] = ACTIONS(110),
    [anon_sym_Program] = ACTIONS(110),
    [anon_sym_Embedded] = ACTIONS(110),
    [anon_sym_Self] = ACTIONS(110),
    [anon_sym_Type] = ACTIONS(110),
    [anon_sym_Field] = ACTIONS(110),
    [anon_sym_Variable] = ACTIONS(110),
    [anon_sym_into] = ACTIONS(110),
    [anon_sym_fun] = ACTIONS(110),
    [anon_sym_may] = ACTIONS(110),
    [anon_sym_itr] = ACTIONS(110),
    [anon_sym_err] = ACTIONS(110),
    [anon_sym_ark] = ACTIONS(110),
    [anon_sym_ptr] = ACTIONS(110),
    [anon_sym_mut] = ACTIONS(110),
    [anon_sym_ref] = ACTIONS(110),
    [anon_sym_sec] = ACTIONS(110),
    [anon_sym_pkg] = ACTIONS(110),
    [anon_sym_true] = ACTIONS(110),
    [anon_sym_false] = ACTIONS(110),
    [anon_sym_EQ] = ACTIONS(110),
    [anon_sym_LT_DASH] = ACTIONS(108),
    [anon_sym_DASH_GT] = ACTIONS(108),
    [anon_sym_EQ_GT] = ACTIONS(108),
    [anon_sym_QMARK_QMARK] = ACTIONS(108),
    [anon_sym____] = ACTIONS(110),
    [anon_sym_EQ_EQ] = ACTIONS(108),
    [anon_sym_BANG_EQ] = ACTIONS(108),
    [anon_sym_LT] = ACTIONS(110),
    [anon_sym_GT] = ACTIONS(110),
    [anon_sym_LT_EQ] = ACTIONS(108),
    [anon_sym_GT_EQ] = ACTIONS(108),
    [anon_sym_PLUS] = ACTIONS(108),
    [anon_sym_DASH] = ACTIONS(110),
    [anon_sym_STAR] = ACTIONS(108),
    [anon_sym_SLASH] = ACTIONS(110),
    [anon_sym_CARET] = ACTIONS(108),
    [anon_sym_BANG] = ACTIONS(110),
    [anon_sym_TILDE] = ACTIONS(108),
    [anon_sym_AMP] = ACTIONS(108),
    [anon_sym_BSLASH] = ACTIONS(108),
    [anon_sym_QMARK] = ACTIONS(110),
    [anon_sym_AT] = ACTIONS(108),
    [anon_sym_DASH_DASH] = ACTIONS(108),
    [anon_sym_GT_GT] = ACTIONS(108),
    [anon_sym_COLON] = ACTIONS(110),
    [anon_sym_SEMI] = ACTIONS(108),
    [anon_sym_COMMA] = ACTIONS(108),
    [anon_sym_DOT] = ACTIONS(108),
    [anon_sym_LBRACE] = ACTIONS(108),
    [anon_sym_RBRACE] = ACTIONS(108),
    [anon_sym_LBRACK] = ACTIONS(108),
    [anon_sym_RBRACK] = ACTIONS(108),
    [anon_sym_LPAREN] = ACTIONS(108),
    [anon_sym_RPAREN] = ACTIONS(108),
    [sym_string] = ACTIONS(108),
    [sym_char] = ACTIONS(108),
    [sym_number] = ACTIONS(110),
  },
  [17] = {
    [ts_builtin_sym_end] = ACTIONS(150),
    [sym_identifier] = ACTIONS(152),
    [sym_comment] = ACTIONS(3),
    [anon_sym_PIPE] = ACTIONS(152),
    [anon_sym_PIPE_GT] = ACTIONS(150),
    [anon_sym_COLON_COLON] = ACTIONS(154),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(156),
    [anon_sym_DOLLAR] = ACTIONS(150),
    [anon_sym_LT_LT] = ACTIONS(150),
    [sym_type_identifier] = ACTIONS(152),
    [anon_sym__] = ACTIONS(152),
    [anon_sym_PERCENT] = ACTIONS(150),
    [anon_sym_POUND] = ACTIONS(150),
    [anon_sym_new] = ACTIONS(152),
    [anon_sym_old] = ACTIONS(152),
    [anon_sym_heap] = ACTIONS(152),
    [anon_sym_const] = ACTIONS(152),
    [anon_sym_if] = ACTIONS(152),
    [anon_sym_else] = ACTIONS(152),
    [anon_sym_while] = ACTIONS(152),
    [anon_sym_for] = ACTIONS(152),
    [anon_sym_in] = ACTIONS(152),
    [anon_sym_switch] = ACTIONS(152),
    [anon_sym_case] = ACTIONS(152),
    [anon_sym_fail] = ACTIONS(152),
    [anon_sym_say] = ACTIONS(152),
    [anon_sym_sayif] = ACTIONS(152),
    [anon_sym_debug] = ACTIONS(152),
    [anon_sym_debugif] = ACTIONS(152),
    [anon_sym_print] = ACTIONS(152),
    [anon_sym_printif] = ACTIONS(152),
    [anon_sym_use] = ACTIONS(152),
    [anon_sym_package] = ACTIONS(152),
    [anon_sym_default] = ACTIONS(152),
    [anon_sym_set] = ACTIONS(152),
    [anon_sym_struct] = ACTIONS(152),
    [anon_sym_type] = ACTIONS(152),
    [anon_sym_interface] = ACTIONS(152),
    [anon_sym_alias] = ACTIONS(152),
    [anon_sym_enum] = ACTIONS(152),
    [anon_sym_prop] = ACTIONS(152),
    [anon_sym_impl] = ACTIONS(152),
    [anon_sym_return] = ACTIONS(152),
    [anon_sym_yield] = ACTIONS(152),
    [anon_sym_cascade] = ACTIONS(152),
    [anon_sym_break] = ACTIONS(152),
    [anon_sym_loop] = ACTIONS(152),
    [anon_sym_void] = ACTIONS(152),
    [anon_sym_int] = ACTIONS(152),
    [anon_sym_char] = ACTIONS(152),
    [anon_sym_bool] = ACTIONS(152),
    [anon_sym_float] = ACTIONS(152),
    [anon_sym_range] = ACTIONS(152),
    [anon_sym_list] = ACTIONS(152),
    [anon_sym_string] = ACTIONS(152),
    [anon_sym_line] = ACTIONS(152),
    [anon_sym_word] = ACTIONS(152),
    [anon_sym_Program] = ACTIONS(152),
    [anon_sym_Embedded] = ACTIONS(152),
    [anon_sym_Self] = ACTIONS(152),
    [anon_sym_Type] = ACTIONS(152),
    [anon_sym_Field] = ACTIONS(152),
    [anon_sym_Variable] = ACTIONS(152),
    [anon_sym_into] = ACTIONS(152),
    [anon_sym_fun] = ACTIONS(152),
    [anon_sym_may] = ACTIONS(152),
    [anon_sym_itr] = ACTIONS(152),
    [anon_sym_err] = ACTIONS(152),
    [anon_sym_ark] = ACTIONS(152),
    [anon_sym_ptr] = ACTIONS(152),
    [anon_sym_mut] = ACTIONS(152),
    [anon_sym_ref] = ACTIONS(152),
    [anon_sym_sec] = ACTIONS(152),
    [anon_sym_pkg] = ACTIONS(152),
    [anon_sym_true] = ACTIONS(152),
    [anon_sym_false] = ACTIONS(152),
    [anon_sym_EQ] = ACTIONS(152),
    [anon_sym_LT_DASH] = ACTIONS(150),
    [anon_sym_DASH_GT] = ACTIONS(150),
    [anon_sym_EQ_GT] = ACTIONS(150),
    [anon_sym_QMARK_QMARK] = ACTIONS(150),
    [anon_sym____] = ACTIONS(152),
    [anon_sym_EQ_EQ] = ACTIONS(150),
    [anon_sym_BANG_EQ] = ACTIONS(150),
    [anon_sym_LT] = ACTIONS(152),
    [anon_sym_GT] = ACTIONS(152),
    [anon_sym_LT_EQ] = ACTIONS(150),
    [anon_sym_GT_EQ] = ACTIONS(150),
    [anon_sym_PLUS] = ACTIONS(150),
    [anon_sym_DASH] = ACTIONS(152),
    [anon_sym_STAR] = ACTIONS(150),
    [anon_sym_SLASH] = ACTIONS(152),
    [anon_sym_CARET] = ACTIONS(150),
    [anon_sym_BANG] = ACTIONS(152),
    [anon_sym_TILDE] = ACTIONS(150),
    [anon_sym_AMP] = ACTIONS(150),
    [anon_sym_BSLASH] = ACTIONS(150),
    [anon_sym_QMARK] = ACTIONS(152),
    [anon_sym_AT] = ACTIONS(150),
    [anon_sym_DASH_DASH] = ACTIONS(150),
    [anon_sym_GT_GT] = ACTIONS(150),
    [anon_sym_COLON] = ACTIONS(152),
    [anon_sym_SEMI] = ACTIONS(150),
    [anon_sym_COMMA] = ACTIONS(150),
    [anon_sym_DOT] = ACTIONS(150),
    [anon_sym_LBRACE] = ACTIONS(150),
    [anon_sym_RBRACE] = ACTIONS(150),
    [anon_sym_LBRACK] = ACTIONS(150),
    [anon_sym_RBRACK] = ACTIONS(150),
    [anon_sym_LPAREN] = ACTIONS(150),
    [anon_sym_RPAREN] = ACTIONS(150),
    [sym_string] = ACTIONS(150),
    [sym_char] = ACTIONS(150),
    [sym_number] = ACTIONS(152),
  },
  [18] = {
    [ts_builtin_sym_end] = ACTIONS(158),
    [sym_identifier] = ACTIONS(160),
    [sym_comment] = ACTIONS(3),
    [anon_sym_PIPE] = ACTIONS(160),
    [anon_sym_PIPE_GT] = ACTIONS(158),
    [anon_sym_COLON_COLON] = ACTIONS(160),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(158),
    [anon_sym_DOLLAR] = ACTIONS(158),
    [anon_sym_LT_LT] = ACTIONS(158),
    [sym_type_identifier] = ACTIONS(160),
    [anon_sym__] = ACTIONS(160),
    [anon_sym_PERCENT] = ACTIONS(158),
    [anon_sym_POUND] = ACTIONS(158),
    [anon_sym_new] = ACTIONS(160),
    [anon_sym_old] = ACTIONS(160),
    [anon_sym_heap] = ACTIONS(160),
    [anon_sym_const] = ACTIONS(160),
    [anon_sym_if] = ACTIONS(160),
    [anon_sym_else] = ACTIONS(160),
    [anon_sym_while] = ACTIONS(160),
    [anon_sym_for] = ACTIONS(160),
    [anon_sym_in] = ACTIONS(160),
    [anon_sym_switch] = ACTIONS(160),
    [anon_sym_case] = ACTIONS(160),
    [anon_sym_fail] = ACTIONS(160),
    [anon_sym_say] = ACTIONS(160),
    [anon_sym_sayif] = ACTIONS(160),
    [anon_sym_debug] = ACTIONS(160),
    [anon_sym_debugif] = ACTIONS(160),
    [anon_sym_print] = ACTIONS(160),
    [anon_sym_printif] = ACTIONS(160),
    [anon_sym_use] = ACTIONS(160),
    [anon_sym_package] = ACTIONS(160),
    [anon_sym_default] = ACTIONS(160),
    [anon_sym_set] = ACTIONS(160),
    [anon_sym_struct] = ACTIONS(160),
    [anon_sym_type] = ACTIONS(160),
    [anon_sym_interface] = ACTIONS(160),
    [anon_sym_alias] = ACTIONS(160),
    [anon_sym_enum] = ACTIONS(160),
    [anon_sym_prop] = ACTIONS(160),
    [anon_sym_impl] = ACTIONS(160),
    [anon_sym_return] = ACTIONS(160),
    [anon_sym_yield] = ACTIONS(160),
    [anon_sym_cascade] = ACTIONS(160),
    [anon_sym_break] = ACTIONS(160),
    [anon_sym_loop] = ACTIONS(160),
    [anon_sym_void] = ACTIONS(160),
    [anon_sym_int] = ACTIONS(160),
    [anon_sym_char] = ACTIONS(160),
    [anon_sym_bool] = ACTIONS(160),
    [anon_sym_float] = ACTIONS(160),
    [anon_sym_range] = ACTIONS(160),
    [anon_sym_list] = ACTIONS(160),
    [anon_sym_string] = ACTIONS(160),
    [anon_sym_line] = ACTIONS(160),
    [anon_sym_word] = ACTIONS(160),
    [anon_sym_Program] = ACTIONS(160),
    [anon_sym_Embedded] = ACTIONS(160),
    [anon_sym_Self] = ACTIONS(160),
    [anon_sym_Type] = ACTIONS(160),
    [anon_sym_Field] = ACTIONS(160),
    [anon_sym_Variable] = ACTIONS(160),
    [anon_sym_into] = ACTIONS(160),
    [anon_sym_fun] = ACTIONS(160),
    [anon_sym_may] = ACTIONS(160),
    [anon_sym_itr] = ACTIONS(160),
    [anon_sym_err] = ACTIONS(160),
    [anon_sym_ark] = ACTIONS(160),
    [anon_sym_ptr] = ACTIONS(160),
    [anon_sym_mut] = ACTIONS(160),
    [anon_sym_ref] = ACTIONS(160),
    [anon_sym_sec] = ACTIONS(160),
    [anon_sym_pkg] = ACTIONS(160),
    [anon_sym_true] = ACTIONS(160),
    [anon_sym_false] = ACTIONS(160),
    [anon_sym_EQ] = ACTIONS(160),
    [anon_sym_LT_DASH] = ACTIONS(158),
    [anon_sym_DASH_GT] = ACTIONS(158),
    [anon_sym_EQ_GT] = ACTIONS(158),
    [anon_sym_QMARK_QMARK] = ACTIONS(158),
    [anon_sym____] = ACTIONS(160),
    [anon_sym_EQ_EQ] = ACTIONS(158),
    [anon_sym_BANG_EQ] = ACTIONS(158),
    [anon_sym_LT] = ACTIONS(160),
    [anon_sym_GT] = ACTIONS(160),
    [anon_sym_LT_EQ] = ACTIONS(158),
    [anon_sym_GT_EQ] = ACTIONS(158),
    [anon_sym_PLUS] = ACTIONS(158),
    [anon_sym_DASH] = ACTIONS(160),
    [anon_sym_STAR] = ACTIONS(158),
    [anon_sym_SLASH] = ACTIONS(160),
    [anon_sym_CARET] = ACTIONS(158),
    [anon_sym_BANG] = ACTIONS(160),
    [anon_sym_TILDE] = ACTIONS(158),
    [anon_sym_AMP] = ACTIONS(158),
    [anon_sym_BSLASH] = ACTIONS(158),
    [anon_sym_QMARK] = ACTIONS(160),
    [anon_sym_AT] = ACTIONS(158),
    [anon_sym_DASH_DASH] = ACTIONS(158),
    [anon_sym_GT_GT] = ACTIONS(158),
    [anon_sym_COLON] = ACTIONS(160),
    [anon_sym_SEMI] = ACTIONS(158),
    [anon_sym_COMMA] = ACTIONS(158),
    [anon_sym_DOT] = ACTIONS(158),
    [anon_sym_LBRACE] = ACTIONS(158),
    [anon_sym_RBRACE] = ACTIONS(158),
    [anon_sym_LBRACK] = ACTIONS(158),
    [anon_sym_RBRACK] = ACTIONS(158),
    [anon_sym_LPAREN] = ACTIONS(158),
    [anon_sym_RPAREN] = ACTIONS(158),
    [sym_string] = ACTIONS(158),
    [sym_char] = ACTIONS(158),
    [sym_number] = ACTIONS(160),
  },
  [19] = {
    [ts_builtin_sym_end] = ACTIONS(162),
    [sym_identifier] = ACTIONS(164),
    [sym_comment] = ACTIONS(3),
    [anon_sym_PIPE] = ACTIONS(164),
    [anon_sym_PIPE_GT] = ACTIONS(162),
    [anon_sym_COLON_COLON] = ACTIONS(164),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(162),
    [anon_sym_DOLLAR] = ACTIONS(162),
    [anon_sym_LT_LT] = ACTIONS(162),
    [sym_type_identifier] = ACTIONS(164),
    [anon_sym__] = ACTIONS(164),
    [anon_sym_PERCENT] = ACTIONS(162),
    [anon_sym_POUND] = ACTIONS(162),
    [anon_sym_new] = ACTIONS(164),
    [anon_sym_old] = ACTIONS(164),
    [anon_sym_heap] = ACTIONS(164),
    [anon_sym_const] = ACTIONS(164),
    [anon_sym_if] = ACTIONS(164),
    [anon_sym_else] = ACTIONS(164),
    [anon_sym_while] = ACTIONS(164),
    [anon_sym_for] = ACTIONS(164),
    [anon_sym_in] = ACTIONS(164),
    [anon_sym_switch] = ACTIONS(164),
    [anon_sym_case] = ACTIONS(164),
    [anon_sym_fail] = ACTIONS(164),
    [anon_sym_say] = ACTIONS(164),
    [anon_sym_sayif] = ACTIONS(164),
    [anon_sym_debug] = ACTIONS(164),
    [anon_sym_debugif] = ACTIONS(164),
    [anon_sym_print] = ACTIONS(164),
    [anon_sym_printif] = ACTIONS(164),
    [anon_sym_use] = ACTIONS(164),
    [anon_sym_package] = ACTIONS(164),
    [anon_sym_default] = ACTIONS(164),
    [anon_sym_set] = ACTIONS(164),
    [anon_sym_struct] = ACTIONS(164),
    [anon_sym_type] = ACTIONS(164),
    [anon_sym_interface] = ACTIONS(164),
    [anon_sym_alias] = ACTIONS(164),
    [anon_sym_enum] = ACTIONS(164),
    [anon_sym_prop] = ACTIONS(164),
    [anon_sym_impl] = ACTIONS(164),
    [anon_sym_return] = ACTIONS(164),
    [anon_sym_yield] = ACTIONS(164),
    [anon_sym_cascade] = ACTIONS(164),
    [anon_sym_break] = ACTIONS(164),
    [anon_sym_loop] = ACTIONS(164),
    [anon_sym_void] = ACTIONS(164),
    [anon_sym_int] = ACTIONS(164),
    [anon_sym_char] = ACTIONS(164),
    [anon_sym_bool] = ACTIONS(164),
    [anon_sym_float] = ACTIONS(164),
    [anon_sym_range] = ACTIONS(164),
    [anon_sym_list] = ACTIONS(164),
    [anon_sym_string] = ACTIONS(164),
    [anon_sym_line] = ACTIONS(164),
    [anon_sym_word] = ACTIONS(164),
    [anon_sym_Program] = ACTIONS(164),
    [anon_sym_Embedded] = ACTIONS(164),
    [anon_sym_Self] = ACTIONS(164),
    [anon_sym_Type] = ACTIONS(164),
    [anon_sym_Field] = ACTIONS(164),
    [anon_sym_Variable] = ACTIONS(164),
    [anon_sym_into] = ACTIONS(164),
    [anon_sym_fun] = ACTIONS(164),
    [anon_sym_may] = ACTIONS(164),
    [anon_sym_itr] = ACTIONS(164),
    [anon_sym_err] = ACTIONS(164),
    [anon_sym_ark] = ACTIONS(164),
    [anon_sym_ptr] = ACTIONS(164),
    [anon_sym_mut] = ACTIONS(164),
    [anon_sym_ref] = ACTIONS(164),
    [anon_sym_sec] = ACTIONS(164),
    [anon_sym_pkg] = ACTIONS(164),
    [anon_sym_true] = ACTIONS(164),
    [anon_sym_false] = ACTIONS(164),
    [anon_sym_EQ] = ACTIONS(164),
    [anon_sym_LT_DASH] = ACTIONS(162),
    [anon_sym_DASH_GT] = ACTIONS(162),
    [anon_sym_EQ_GT] = ACTIONS(162),
    [anon_sym_QMARK_QMARK] = ACTIONS(162),
    [anon_sym____] = ACTIONS(164),
    [anon_sym_EQ_EQ] = ACTIONS(162),
    [anon_sym_BANG_EQ] = ACTIONS(162),
    [anon_sym_LT] = ACTIONS(164),
    [anon_sym_GT] = ACTIONS(164),
    [anon_sym_LT_EQ] = ACTIONS(162),
    [anon_sym_GT_EQ] = ACTIONS(162),
    [anon_sym_PLUS] = ACTIONS(162),
    [anon_sym_DASH] = ACTIONS(164),
    [anon_sym_STAR] = ACTIONS(162),
    [anon_sym_SLASH] = ACTIONS(164),
    [anon_sym_CARET] = ACTIONS(162),
    [anon_sym_BANG] = ACTIONS(164),
    [anon_sym_TILDE] = ACTIONS(162),
    [anon_sym_AMP] = ACTIONS(162),
    [anon_sym_BSLASH] = ACTIONS(162),
    [anon_sym_QMARK] = ACTIONS(164),
    [anon_sym_AT] = ACTIONS(162),
    [anon_sym_DASH_DASH] = ACTIONS(162),
    [anon_sym_GT_GT] = ACTIONS(162),
    [anon_sym_COLON] = ACTIONS(164),
    [anon_sym_SEMI] = ACTIONS(162),
    [anon_sym_COMMA] = ACTIONS(162),
    [anon_sym_DOT] = ACTIONS(162),
    [anon_sym_LBRACE] = ACTIONS(162),
    [anon_sym_RBRACE] = ACTIONS(162),
    [anon_sym_LBRACK] = ACTIONS(162),
    [anon_sym_RBRACK] = ACTIONS(162),
    [anon_sym_LPAREN] = ACTIONS(162),
    [anon_sym_RPAREN] = ACTIONS(162),
    [sym_string] = ACTIONS(162),
    [sym_char] = ACTIONS(162),
    [sym_number] = ACTIONS(164),
  },
  [20] = {
    [ts_builtin_sym_end] = ACTIONS(166),
    [sym_identifier] = ACTIONS(168),
    [sym_comment] = ACTIONS(3),
    [anon_sym_PIPE] = ACTIONS(168),
    [anon_sym_PIPE_GT] = ACTIONS(166),
    [anon_sym_COLON_COLON] = ACTIONS(168),
    [anon_sym_COLON_COLON_COLON] = ACTIONS(166),
    [anon_sym_DOLLAR] = ACTIONS(166),
    [anon_sym_LT_LT] = ACTIONS(166),
    [sym_type_identifier] = ACTIONS(168),
    [anon_sym__] = ACTIONS(168),
    [anon_sym_PERCENT] = ACTIONS(166),
    [anon_sym_POUND] = ACTIONS(166),
    [anon_sym_new] = ACTIONS(168),
    [anon_sym_old] = ACTIONS(168),
    [anon_sym_heap] = ACTIONS(168),
    [anon_sym_const] = ACTIONS(168),
    [anon_sym_if] = ACTIONS(168),
    [anon_sym_else] = ACTIONS(168),
    [anon_sym_while] = ACTIONS(168),
    [anon_sym_for] = ACTIONS(168),
    [anon_sym_in] = ACTIONS(168),
    [anon_sym_switch] = ACTIONS(168),
    [anon_sym_case] = ACTIONS(168),
    [anon_sym_fail] = ACTIONS(168),
    [anon_sym_say] = ACTIONS(168),
    [anon_sym_sayif] = ACTIONS(168),
    [anon_sym_debug] = ACTIONS(168),
    [anon_sym_debugif] = ACTIONS(168),
    [anon_sym_print] = ACTIONS(168),
    [anon_sym_printif] = ACTIONS(168),
    [anon_sym_use] = ACTIONS(168),
    [anon_sym_package] = ACTIONS(168),
    [anon_sym_default] = ACTIONS(168),
    [anon_sym_set] = ACTIONS(168),
    [anon_sym_struct] = ACTIONS(168),
    [anon_sym_type] = ACTIONS(168),
    [anon_sym_interface] = ACTIONS(168),
    [anon_sym_alias] = ACTIONS(168),
    [anon_sym_enum] = ACTIONS(168),
    [anon_sym_prop] = ACTIONS(168),
    [anon_sym_impl] = ACTIONS(168),
    [anon_sym_return] = ACTIONS(168),
    [anon_sym_yield] = ACTIONS(168),
    [anon_sym_cascade] = ACTIONS(168),
    [anon_sym_break] = ACTIONS(168),
    [anon_sym_loop] = ACTIONS(168),
    [anon_sym_void] = ACTIONS(168),
    [anon_sym_int] = ACTIONS(168),
    [anon_sym_char] = ACTIONS(168),
    [anon_sym_bool] = ACTIONS(168),
    [anon_sym_float] = ACTIONS(168),
    [anon_sym_range] = ACTIONS(168),
    [anon_sym_list] = ACTIONS(168),
    [anon_sym_string] = ACTIONS(168),
    [anon_sym_line] = ACTIONS(168),
    [anon_sym_word] = ACTIONS(168),
    [anon_sym_Program] = ACTIONS(168),
    [anon_sym_Embedded] = ACTIONS(168),
    [anon_sym_Self] = ACTIONS(168),
    [anon_sym_Type] = ACTIONS(168),
    [anon_sym_Field] = ACTIONS(168),
    [anon_sym_Variable] = ACTIONS(168),
    [anon_sym_into] = ACTIONS(168),
    [anon_sym_fun] = ACTIONS(168),
    [anon_sym_may] = ACTIONS(168),
    [anon_sym_itr] = ACTIONS(168),
    [anon_sym_err] = ACTIONS(168),
    [anon_sym_ark] = ACTIONS(168),
    [anon_sym_ptr] = ACTIONS(168),
    [anon_sym_mut] = ACTIONS(168),
    [anon_sym_ref] = ACTIONS(168),
    [anon_sym_sec] = ACTIONS(168),
    [anon_sym_pkg] = ACTIONS(168),
    [anon_sym_true] = ACTIONS(168),
    [anon_sym_false] = ACTIONS(168),
    [anon_sym_EQ] = ACTIONS(168),
    [anon_sym_LT_DASH] = ACTIONS(166),
    [anon_sym_DASH_GT] = ACTIONS(166),
    [anon_sym_EQ_GT] = ACTIONS(166),
    [anon_sym_QMARK_QMARK] = ACTIONS(166),
    [anon_sym____] = ACTIONS(168),
    [anon_sym_EQ_EQ] = ACTIONS(166),
    [anon_sym_BANG_EQ] = ACTIONS(166),
    [anon_sym_LT] = ACTIONS(168),
    [anon_sym_GT] = ACTIONS(168),
    [anon_sym_LT_EQ] = ACTIONS(166),
    [anon_sym_GT_EQ] = ACTIONS(166),
    [anon_sym_PLUS] = ACTIONS(166),
    [anon_sym_DASH] = ACTIONS(168),
    [anon_sym_STAR] = ACTIONS(166),
    [anon_sym_SLASH] = ACTIONS(168),
    [anon_sym_CARET] = ACTIONS(166),
    [anon_sym_BANG] = ACTIONS(168),
    [anon_sym_TILDE] = ACTIONS(166),
    [anon_sym_AMP] = ACTIONS(166),
    [anon_sym_BSLASH] = ACTIONS(166),
    [anon_sym_QMARK] = ACTIONS(168),
    [anon_sym_AT] = ACTIONS(166),
    [anon_sym_DASH_DASH] = ACTIONS(166),
    [anon_sym_GT_GT] = ACTIONS(166),
    [anon_sym_COLON] = ACTIONS(168),
    [anon_sym_SEMI] = ACTIONS(166),
    [anon_sym_COMMA] = ACTIONS(166),
    [anon_sym_DOT] = ACTIONS(166),
    [anon_sym_LBRACE] = ACTIONS(166),
    [anon_sym_RBRACE] = ACTIONS(166),
    [anon_sym_LBRACK] = ACTIONS(166),
    [anon_sym_RBRACK] = ACTIONS(166),
    [anon_sym_LPAREN] = ACTIONS(166),
    [anon_sym_RPAREN] = ACTIONS(166),
    [sym_string] = ACTIONS(166),
    [sym_char] = ACTIONS(166),
    [sym_number] = ACTIONS(168),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(170), 1,
      sym_type_identifier,
  [7] = 2,
    ACTIONS(3), 1,
      sym_comment,
    ACTIONS(172), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(21)] = 0,
  [SMALL_STATE(22)] = 7,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT_EXTRA(),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [15] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [37] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [41] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [47] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [49] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(14),
  [52] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(10),
  [55] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(10),
  [58] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(16),
  [61] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(16),
  [64] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(5),
  [67] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(21),
  [70] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(6),
  [73] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(7),
  [76] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(8),
  [79] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(9),
  [82] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(4),
  [85] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(11),
  [88] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(12),
  [91] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(13),
  [94] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(3),
  [97] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(3),
  [100] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_modifier, 1),
  [102] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_modifier, 1),
  [104] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_usage, 1),
  [106] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_usage, 1),
  [108] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_operator, 1),
  [110] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_operator, 1),
  [112] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [114] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_keyword, 1),
  [116] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_keyword, 1),
  [118] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_terminator, 1),
  [120] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_terminator, 1),
  [122] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_keyword, 1),
  [124] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_keyword, 1),
  [126] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [128] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_boolean, 1),
  [130] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_boolean, 1),
  [132] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_punctuation, 1),
  [134] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_punctuation, 1),
  [136] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__item, 1),
  [138] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__item, 1),
  [140] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [146] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_procedure_definition, 3, .production_id = 4),
  [148] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_procedure_definition, 3, .production_id = 4),
  [150] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_pipe_usage, 2, .production_id = 1),
  [152] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_pipe_usage, 2, .production_id = 1),
  [154] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [156] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [158] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type_usage, 2, .production_id = 2),
  [160] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_type_usage, 2, .production_id = 2),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_procedure_definition, 2, .production_id = 3),
  [164] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_procedure_definition, 2, .production_id = 3),
  [166] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_func_usage, 2, .production_id = 3),
  [168] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_func_usage, 2, .production_id = 3),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [172] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
