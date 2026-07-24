module.exports = grammar({
  name: 'cease',

  extras: $ => [
    /\s/,
    $.comment,
  ],

  // Ensures that keywords like 'new' don't accidentally match prefixes of identifiers like 'newVar'
  word: $ => $.identifier,

  rules: {
    source_file: $ => repeat($._item),

    comment: $ => token(seq('//', /.*/)),

    _item: $ => choice(
      $.procedure_definition,
      $.type_usage,
	  $.type_identifier,
      $.keyword,
	  $.func_usage,
      $.pipe_usage,
      $.type_keyword,
      $.modifier,
      $.operator,
      $.string,
      $.char,
      $.number,
      $.terminator,
      $.boolean,
      $.punctuation,
      $.identifier
    ),

    // Catches functions and pipes: someFunc :: ...
    procedure_definition: $ => prec(4, seq(
	  optional(alias(choice('|', '|>'), $.operator)),
	  field('name', $.identifier),
	  alias(choice('::', ':::'), $.operator)
	)),

	func_usage: $ => prec(3, seq(
	  field('name', $.identifier),
	  alias(choice('$', '<<'), $.operator),
	)),

	pipe_usage: $ => prec(3, seq(
	  choice('|', '|>'),
	  field('name', $.identifier),
	)),

	type_identifier: $ => /[A-Z]\w*/,

    type_usage: $ => prec(4, choice(
      $.type_identifier,
      seq(
        field('prefix', alias(choice('_', '%', '#'), $.operator)),
        field('name', $.type_identifier)
      )
    )),

    payload: $ => prec(2, seq(
      field('name', $.identifier),
      choice('|', '|>')
    )),

    keyword: $ => choice(
      'new', 'old', 'heap', 'const',
      'if', 'else', 'while', 'for', 'in', 'switch', 'case',
      'fail', 'say', 'sayif', 'debug', 'debugif', 'print', 'printif',
      'use', 'package', 'default', 'set',
	  'struct', 'type', 'interface', 'alias', 'enum', 'prop', 'impl'
    ),

	terminator: $ => choice(
	  'return', 'yield', 'cascade', 'break', 'loop',
	),

	type_keyword: $ => choice(
      'void', 'int', 'char', 'bool', 'float', 'range', 'list', 'string', 'line', 'word',
      'Program', 'Embedded', 'Self', 'Type', 'Field', 'Variable'
    ),

    modifier: $ => choice(
      'into', 'fun', 'may', 'itr', 'err', 'ark', 'ptr', 'mut', 'ref', 'sec', 'pkg'
    ),

    boolean: $ => choice('true', 'false'),

    operator: $ => prec(2, choice(
      '=', '<-', '|', '|>', '$', '->', '=>', '??', '___',
      '==', '!=', '<', '>', '<=', '>=', '+', '-', '*', '/', '%', '^',
      '!', '~', '&', '\\', '?', '#', '@', '--', '<<', '>>', ':', '::', ':::'
	)),

    punctuation: $ => choice(
      ';', ':', ',', '.', '{', '}', '[', ']', '(', ')'
    ),

    string: $ => token(choice(
      seq('"', /[^"]*/, '"'),
      seq('`', /[^`]*/, '`') // Interpolated string shorthand
    )),

    char: $ => token(seq("'", /[^\\]|\\./, "'")),

    number: $ => token(/\d+(\.\d+)?/),

    identifier: $ => /[a-zA-Z0-9][a-zA-Z0-9_]*|_[a-z0-9_]*/
  }
});