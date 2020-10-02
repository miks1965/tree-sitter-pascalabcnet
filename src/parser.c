#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 12
#define STATE_COUNT 123
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 84
#define ALIAS_COUNT 0
#define TOKEN_COUNT 55
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 10

enum {
  anon_sym_Program = 1,
  anon_sym_ = 2,
  anon_sym_const = 3,
  anon_sym_EQ = 4,
  anon_sym_procedure = 5,
  anon_sym_boolean = 6,
  anon_sym_integer = 7,
  anon_sym_real = 8,
  anon_sym_char = 9,
  anon_sym_STAR_EQ = 10,
  anon_sym_SLASH_EQ = 11,
  anon_sym_PERCENT_EQ = 12,
  anon_sym_PLUS_EQ = 13,
  anon_sym_DASH_EQ = 14,
  anon_sym_COLON_EQ = 15,
  anon_sym_if = 16,
  anon_sym_then = 17,
  anon_sym_else = 18,
  anon_sym_while = 19,
  anon_sym_do = 20,
  anon_sym_for = 21,
  anon_sym_to = 22,
  anon_sym_step = 23,
  anon_sym_PLUS = 24,
  anon_sym_DASH = 25,
  anon_sym_BANG = 26,
  anon_sym_CARET = 27,
  anon_sym_STAR = 28,
  anon_sym_AMP = 29,
  anon_sym_LT_DASH = 30,
  anon_sym_SLASH = 31,
  anon_sym_PERCENT = 32,
  anon_sym_LT_GT = 33,
  anon_sym_LT = 34,
  anon_sym_LT_EQ = 35,
  anon_sym_GT = 36,
  anon_sym_GT_EQ = 37,
  anon_sym_and = 38,
  anon_sym_or = 39,
  sym_identifier = 40,
  sym_integer = 41,
  sym_real = 42,
  sym_char = 43,
  sym_semicolon = 44,
  sym_colon = 45,
  sym_dot = 46,
  sym_comma = 47,
  sym_left_paren = 48,
  sym_right_paren = 49,
  sym_true = 50,
  sym_false = 51,
  sym_begin = 52,
  sym_end = 53,
  sym_var = 54,
  sym_module = 55,
  sym_mainblock = 56,
  sym_declarations = 57,
  sym_declarations_sequence = 58,
  sym_var_declarations = 59,
  sym_var_declaration = 60,
  sym_const_declarations = 61,
  sym_const_declaration = 62,
  sym_const_expression = 63,
  sym_procedure_declatarions = 64,
  sym_formal_params = 65,
  sym_return = 66,
  sym_formal_params_list = 67,
  sym_formal_params_sequence = 68,
  sym_type = 69,
  sym_statement_sequence = 70,
  sym__statement = 71,
  sym_assignment = 72,
  sym_if_statement = 73,
  sym_while_statement = 74,
  sym_for_statement = 75,
  sym_block_statement = 76,
  sym_procedure_call_statement = 77,
  sym_identifier_list = 78,
  sym_fact_params = 79,
  sym__expression = 80,
  sym_unary_expression = 81,
  sym_binary_expression = 82,
  sym__number = 83,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_Program] = "Program",
  [anon_sym_] = "",
  [anon_sym_const] = "const",
  [anon_sym_EQ] = "=",
  [anon_sym_procedure] = "procedure",
  [anon_sym_boolean] = "boolean",
  [anon_sym_integer] = "integer",
  [anon_sym_real] = "real",
  [anon_sym_char] = "char",
  [anon_sym_STAR_EQ] = "*=",
  [anon_sym_SLASH_EQ] = "/=",
  [anon_sym_PERCENT_EQ] = "%=",
  [anon_sym_PLUS_EQ] = "+=",
  [anon_sym_DASH_EQ] = "-=",
  [anon_sym_COLON_EQ] = ":=",
  [anon_sym_if] = "if",
  [anon_sym_then] = "then",
  [anon_sym_else] = "else",
  [anon_sym_while] = "while",
  [anon_sym_do] = "do",
  [anon_sym_for] = "for",
  [anon_sym_to] = "to",
  [anon_sym_step] = "step",
  [anon_sym_PLUS] = "+",
  [anon_sym_DASH] = "-",
  [anon_sym_BANG] = "!",
  [anon_sym_CARET] = "^",
  [anon_sym_STAR] = "*",
  [anon_sym_AMP] = "&",
  [anon_sym_LT_DASH] = "<-",
  [anon_sym_SLASH] = "/",
  [anon_sym_PERCENT] = "%",
  [anon_sym_LT_GT] = "<>",
  [anon_sym_LT] = "<",
  [anon_sym_LT_EQ] = "<=",
  [anon_sym_GT] = ">",
  [anon_sym_GT_EQ] = ">=",
  [anon_sym_and] = "and",
  [anon_sym_or] = "or",
  [sym_identifier] = "identifier",
  [sym_integer] = "integer",
  [sym_real] = "real",
  [sym_char] = "char",
  [sym_semicolon] = "semicolon",
  [sym_colon] = "colon",
  [sym_dot] = "dot",
  [sym_comma] = "comma",
  [sym_left_paren] = "left_paren",
  [sym_right_paren] = "right_paren",
  [sym_true] = "true",
  [sym_false] = "false",
  [sym_begin] = "begin",
  [sym_end] = "end",
  [sym_var] = "var",
  [sym_module] = "module",
  [sym_mainblock] = "mainblock",
  [sym_declarations] = "declarations",
  [sym_declarations_sequence] = "declarations_sequence",
  [sym_var_declarations] = "var_declarations",
  [sym_var_declaration] = "var_declaration",
  [sym_const_declarations] = "const_declarations",
  [sym_const_declaration] = "const_declaration",
  [sym_const_expression] = "const_expression",
  [sym_procedure_declatarions] = "procedure_declatarions",
  [sym_formal_params] = "formal_params",
  [sym_return] = "return",
  [sym_formal_params_list] = "formal_params_list",
  [sym_formal_params_sequence] = "formal_params_sequence",
  [sym_type] = "type",
  [sym_statement_sequence] = "statement_sequence",
  [sym__statement] = "_statement",
  [sym_assignment] = "assignment",
  [sym_if_statement] = "if_statement",
  [sym_while_statement] = "while_statement",
  [sym_for_statement] = "for_statement",
  [sym_block_statement] = "block_statement",
  [sym_procedure_call_statement] = "procedure_call_statement",
  [sym_identifier_list] = "identifier_list",
  [sym_fact_params] = "fact_params",
  [sym__expression] = "_expression",
  [sym_unary_expression] = "unary_expression",
  [sym_binary_expression] = "binary_expression",
  [sym__number] = "_number",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_Program] = anon_sym_Program,
  [anon_sym_] = anon_sym_,
  [anon_sym_const] = anon_sym_const,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_procedure] = anon_sym_procedure,
  [anon_sym_boolean] = anon_sym_boolean,
  [anon_sym_integer] = anon_sym_integer,
  [anon_sym_real] = anon_sym_real,
  [anon_sym_char] = anon_sym_char,
  [anon_sym_STAR_EQ] = anon_sym_STAR_EQ,
  [anon_sym_SLASH_EQ] = anon_sym_SLASH_EQ,
  [anon_sym_PERCENT_EQ] = anon_sym_PERCENT_EQ,
  [anon_sym_PLUS_EQ] = anon_sym_PLUS_EQ,
  [anon_sym_DASH_EQ] = anon_sym_DASH_EQ,
  [anon_sym_COLON_EQ] = anon_sym_COLON_EQ,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_then] = anon_sym_then,
  [anon_sym_else] = anon_sym_else,
  [anon_sym_while] = anon_sym_while,
  [anon_sym_do] = anon_sym_do,
  [anon_sym_for] = anon_sym_for,
  [anon_sym_to] = anon_sym_to,
  [anon_sym_step] = anon_sym_step,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_DASH] = anon_sym_DASH,
  [anon_sym_BANG] = anon_sym_BANG,
  [anon_sym_CARET] = anon_sym_CARET,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_AMP] = anon_sym_AMP,
  [anon_sym_LT_DASH] = anon_sym_LT_DASH,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [anon_sym_PERCENT] = anon_sym_PERCENT,
  [anon_sym_LT_GT] = anon_sym_LT_GT,
  [anon_sym_LT] = anon_sym_LT,
  [anon_sym_LT_EQ] = anon_sym_LT_EQ,
  [anon_sym_GT] = anon_sym_GT,
  [anon_sym_GT_EQ] = anon_sym_GT_EQ,
  [anon_sym_and] = anon_sym_and,
  [anon_sym_or] = anon_sym_or,
  [sym_identifier] = sym_identifier,
  [sym_integer] = sym_integer,
  [sym_real] = sym_real,
  [sym_char] = sym_char,
  [sym_semicolon] = sym_semicolon,
  [sym_colon] = sym_colon,
  [sym_dot] = sym_dot,
  [sym_comma] = sym_comma,
  [sym_left_paren] = sym_left_paren,
  [sym_right_paren] = sym_right_paren,
  [sym_true] = sym_true,
  [sym_false] = sym_false,
  [sym_begin] = sym_begin,
  [sym_end] = sym_end,
  [sym_var] = sym_var,
  [sym_module] = sym_module,
  [sym_mainblock] = sym_mainblock,
  [sym_declarations] = sym_declarations,
  [sym_declarations_sequence] = sym_declarations_sequence,
  [sym_var_declarations] = sym_var_declarations,
  [sym_var_declaration] = sym_var_declaration,
  [sym_const_declarations] = sym_const_declarations,
  [sym_const_declaration] = sym_const_declaration,
  [sym_const_expression] = sym_const_expression,
  [sym_procedure_declatarions] = sym_procedure_declatarions,
  [sym_formal_params] = sym_formal_params,
  [sym_return] = sym_return,
  [sym_formal_params_list] = sym_formal_params_list,
  [sym_formal_params_sequence] = sym_formal_params_sequence,
  [sym_type] = sym_type,
  [sym_statement_sequence] = sym_statement_sequence,
  [sym__statement] = sym__statement,
  [sym_assignment] = sym_assignment,
  [sym_if_statement] = sym_if_statement,
  [sym_while_statement] = sym_while_statement,
  [sym_for_statement] = sym_for_statement,
  [sym_block_statement] = sym_block_statement,
  [sym_procedure_call_statement] = sym_procedure_call_statement,
  [sym_identifier_list] = sym_identifier_list,
  [sym_fact_params] = sym_fact_params,
  [sym__expression] = sym__expression,
  [sym_unary_expression] = sym_unary_expression,
  [sym_binary_expression] = sym_binary_expression,
  [sym__number] = sym__number,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_Program] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_const] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_procedure] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_boolean] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_integer] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_real] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_char] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PLUS_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DASH_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_if] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_then] = {
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
  [anon_sym_do] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_for] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_to] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_step] = {
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
  [anon_sym_BANG] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_CARET] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_AMP] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_DASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_PERCENT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_LT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_and] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_or] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [sym_integer] = {
    .visible = true,
    .named = true,
  },
  [sym_real] = {
    .visible = true,
    .named = true,
  },
  [sym_char] = {
    .visible = true,
    .named = true,
  },
  [sym_semicolon] = {
    .visible = true,
    .named = true,
  },
  [sym_colon] = {
    .visible = true,
    .named = true,
  },
  [sym_dot] = {
    .visible = true,
    .named = true,
  },
  [sym_comma] = {
    .visible = true,
    .named = true,
  },
  [sym_left_paren] = {
    .visible = true,
    .named = true,
  },
  [sym_right_paren] = {
    .visible = true,
    .named = true,
  },
  [sym_true] = {
    .visible = true,
    .named = true,
  },
  [sym_false] = {
    .visible = true,
    .named = true,
  },
  [sym_begin] = {
    .visible = true,
    .named = true,
  },
  [sym_end] = {
    .visible = true,
    .named = true,
  },
  [sym_var] = {
    .visible = true,
    .named = true,
  },
  [sym_module] = {
    .visible = true,
    .named = true,
  },
  [sym_mainblock] = {
    .visible = true,
    .named = true,
  },
  [sym_declarations] = {
    .visible = true,
    .named = true,
  },
  [sym_declarations_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym_var_declarations] = {
    .visible = true,
    .named = true,
  },
  [sym_var_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_const_declarations] = {
    .visible = true,
    .named = true,
  },
  [sym_const_declaration] = {
    .visible = true,
    .named = true,
  },
  [sym_const_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_procedure_declatarions] = {
    .visible = true,
    .named = true,
  },
  [sym_formal_params] = {
    .visible = true,
    .named = true,
  },
  [sym_return] = {
    .visible = true,
    .named = true,
  },
  [sym_formal_params_list] = {
    .visible = true,
    .named = true,
  },
  [sym_formal_params_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym_type] = {
    .visible = true,
    .named = true,
  },
  [sym_statement_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
    .named = true,
  },
  [sym_assignment] = {
    .visible = true,
    .named = true,
  },
  [sym_if_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_while_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_for_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_block_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_procedure_call_statement] = {
    .visible = true,
    .named = true,
  },
  [sym_identifier_list] = {
    .visible = true,
    .named = true,
  },
  [sym_fact_params] = {
    .visible = true,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_unary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym_binary_expression] = {
    .visible = true,
    .named = true,
  },
  [sym__number] = {
    .visible = false,
    .named = true,
  },
};

static TSSymbol ts_alias_sequences[1][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(78);
      if (lookahead == '!') ADVANCE(108);
      if (lookahead == '%') ADVANCE(114);
      if (lookahead == '&') ADVANCE(111);
      if (lookahead == '(') ADVANCE(157);
      if (lookahead == ')') ADVANCE(158);
      if (lookahead == '*') ADVANCE(110);
      if (lookahead == '+') ADVANCE(106);
      if (lookahead == ',') ADVANCE(156);
      if (lookahead == '-') ADVANCE(107);
      if (lookahead == '.') ADVANCE(155);
      if (lookahead == '/') ADVANCE(113);
      if (lookahead == ':') ADVANCE(154);
      if (lookahead == ';') ADVANCE(152);
      if (lookahead == '<') ADVANCE(116);
      if (lookahead == '=') ADVANCE(83);
      if (lookahead == '>') ADVANCE(118);
      if (lookahead == 'P') ADVANCE(66);
      if (lookahead == '^') ADVANCE(109);
      if (lookahead == 'a') ADVANCE(51);
      if (lookahead == 'b') ADVANCE(23);
      if (lookahead == 'c') ADVANCE(42);
      if (lookahead == 'd') ADVANCE(56);
      if (lookahead == 'e') ADVANCE(45);
      if (lookahead == 'f') ADVANCE(11);
      if (lookahead == 'i') ADVANCE(36);
      if (lookahead == 'o') ADVANCE(61);
      if (lookahead == 'p') ADVANCE(68);
      if (lookahead == 'r') ADVANCE(30);
      if (lookahead == 's') ADVANCE(74);
      if (lookahead == 't') ADVANCE(41);
      if (lookahead == 'v') ADVANCE(14);
      if (lookahead == 'w') ADVANCE(40);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(147);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(1)
      if (lookahead == '!') ADVANCE(108);
      if (lookahead == '&') ADVANCE(111);
      if (lookahead == '(') ADVANCE(157);
      if (lookahead == '*') ADVANCE(110);
      if (lookahead == '+') ADVANCE(106);
      if (lookahead == '-') ADVANCE(107);
      if (lookahead == '<') ADVANCE(151);
      if (lookahead == '^') ADVANCE(109);
      if (lookahead == 'f') ADVANCE(122);
      if (lookahead == 't') ADVANCE(139);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(147);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(149);
      END_STATE();
    case 2:
      if (lookahead == '%') ADVANCE(6);
      if (lookahead == '(') ADVANCE(157);
      if (lookahead == '*') ADVANCE(7);
      if (lookahead == '+') ADVANCE(8);
      if (lookahead == '-') ADVANCE(9);
      if (lookahead == '/') ADVANCE(10);
      if (lookahead == ':') ADVANCE(5);
      if (lookahead == 'b') ADVANCE(126);
      if (lookahead == 'f') ADVANCE(137);
      if (lookahead == 'i') ADVANCE(128);
      if (lookahead == 'w') ADVANCE(130);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 3:
      if (lookahead == ',') ADVANCE(156);
      if (lookahead == ':') ADVANCE(153);
      if (lookahead == 'v') ADVANCE(123);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 4:
      if (lookahead == '.') ADVANCE(155);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 5:
      if (lookahead == '=') ADVANCE(94);
      END_STATE();
    case 6:
      if (lookahead == '=') ADVANCE(91);
      END_STATE();
    case 7:
      if (lookahead == '=') ADVANCE(89);
      END_STATE();
    case 8:
      if (lookahead == '=') ADVANCE(92);
      END_STATE();
    case 9:
      if (lookahead == '=') ADVANCE(93);
      END_STATE();
    case 10:
      if (lookahead == '=') ADVANCE(90);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(49);
      if (lookahead == 'o') ADVANCE(62);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(50);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(46);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(63);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(64);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(54);
      END_STATE();
    case 17:
      if (lookahead == 'c') ADVANCE(138);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(17)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 18:
      if (lookahead == 'c') ADVANCE(34);
      END_STATE();
    case 19:
      if (lookahead == 'd') ADVANCE(120);
      END_STATE();
    case 20:
      if (lookahead == 'd') ADVANCE(165);
      END_STATE();
    case 21:
      if (lookahead == 'd') ADVANCE(148);
      END_STATE();
    case 22:
      if (lookahead == 'd') ADVANCE(77);
      END_STATE();
    case 23:
      if (lookahead == 'e') ADVANCE(37);
      if (lookahead == 'o') ADVANCE(59);
      END_STATE();
    case 24:
      if (lookahead == 'e') ADVANCE(60);
      END_STATE();
    case 25:
      if (lookahead == 'e') ADVANCE(98);
      END_STATE();
    case 26:
      if (lookahead == 'e') ADVANCE(159);
      END_STATE();
    case 27:
      if (lookahead == 'e') ADVANCE(161);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(99);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(84);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(13);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(52);
      END_STATE();
    case 32:
      if (lookahead == 'e') ADVANCE(39);
      END_STATE();
    case 33:
      if (lookahead == 'e') ADVANCE(16);
      END_STATE();
    case 34:
      if (lookahead == 'e') ADVANCE(22);
      END_STATE();
    case 35:
      if (lookahead == 'e') ADVANCE(65);
      END_STATE();
    case 36:
      if (lookahead == 'f') ADVANCE(95);
      if (lookahead == 'n') ADVANCE(75);
      END_STATE();
    case 37:
      if (lookahead == 'g') ADVANCE(43);
      END_STATE();
    case 38:
      if (lookahead == 'g') ADVANCE(67);
      END_STATE();
    case 39:
      if (lookahead == 'g') ADVANCE(35);
      END_STATE();
    case 40:
      if (lookahead == 'h') ADVANCE(44);
      END_STATE();
    case 41:
      if (lookahead == 'h') ADVANCE(31);
      if (lookahead == 'o') ADVANCE(104);
      if (lookahead == 'r') ADVANCE(76);
      END_STATE();
    case 42:
      if (lookahead == 'h') ADVANCE(15);
      if (lookahead == 'o') ADVANCE(55);
      END_STATE();
    case 43:
      if (lookahead == 'i') ADVANCE(53);
      END_STATE();
    case 44:
      if (lookahead == 'i') ADVANCE(47);
      END_STATE();
    case 45:
      if (lookahead == 'l') ADVANCE(71);
      if (lookahead == 'n') ADVANCE(20);
      END_STATE();
    case 46:
      if (lookahead == 'l') ADVANCE(87);
      END_STATE();
    case 47:
      if (lookahead == 'l') ADVANCE(28);
      END_STATE();
    case 48:
      if (lookahead == 'l') ADVANCE(33);
      END_STATE();
    case 49:
      if (lookahead == 'l') ADVANCE(72);
      END_STATE();
    case 50:
      if (lookahead == 'm') ADVANCE(79);
      END_STATE();
    case 51:
      if (lookahead == 'n') ADVANCE(19);
      END_STATE();
    case 52:
      if (lookahead == 'n') ADVANCE(97);
      END_STATE();
    case 53:
      if (lookahead == 'n') ADVANCE(163);
      END_STATE();
    case 54:
      if (lookahead == 'n') ADVANCE(85);
      END_STATE();
    case 55:
      if (lookahead == 'n') ADVANCE(70);
      END_STATE();
    case 56:
      if (lookahead == 'o') ADVANCE(101);
      END_STATE();
    case 57:
      if (lookahead == 'o') ADVANCE(18);
      END_STATE();
    case 58:
      if (lookahead == 'o') ADVANCE(38);
      END_STATE();
    case 59:
      if (lookahead == 'o') ADVANCE(48);
      END_STATE();
    case 60:
      if (lookahead == 'p') ADVANCE(105);
      END_STATE();
    case 61:
      if (lookahead == 'r') ADVANCE(121);
      END_STATE();
    case 62:
      if (lookahead == 'r') ADVANCE(102);
      END_STATE();
    case 63:
      if (lookahead == 'r') ADVANCE(166);
      END_STATE();
    case 64:
      if (lookahead == 'r') ADVANCE(88);
      END_STATE();
    case 65:
      if (lookahead == 'r') ADVANCE(86);
      END_STATE();
    case 66:
      if (lookahead == 'r') ADVANCE(58);
      END_STATE();
    case 67:
      if (lookahead == 'r') ADVANCE(12);
      END_STATE();
    case 68:
      if (lookahead == 'r') ADVANCE(57);
      END_STATE();
    case 69:
      if (lookahead == 'r') ADVANCE(29);
      END_STATE();
    case 70:
      if (lookahead == 's') ADVANCE(73);
      END_STATE();
    case 71:
      if (lookahead == 's') ADVANCE(25);
      END_STATE();
    case 72:
      if (lookahead == 's') ADVANCE(27);
      END_STATE();
    case 73:
      if (lookahead == 't') ADVANCE(81);
      END_STATE();
    case 74:
      if (lookahead == 't') ADVANCE(24);
      END_STATE();
    case 75:
      if (lookahead == 't') ADVANCE(32);
      END_STATE();
    case 76:
      if (lookahead == 'u') ADVANCE(26);
      END_STATE();
    case 77:
      if (lookahead == 'u') ADVANCE(69);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_Program);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_const);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_const);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_procedure);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_boolean);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_integer);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_real);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_char);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_STAR_EQ);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_SLASH_EQ);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_PERCENT_EQ);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_PLUS_EQ);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_DASH_EQ);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_COLON_EQ);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_if);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_then);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_while);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_while);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_do);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_for);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_for);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_to);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_step);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_CARET);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_AMP);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_LT_DASH);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_LT_GT);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(117);
      if (lookahead == '>') ADVANCE(115);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(119);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_and);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_or);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(133);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(141);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(160);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(162);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(129);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(100);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(96);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(131);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h') ADVANCE(132);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(135);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(134);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(143);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(127);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(164);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(142);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(140);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(136);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(145);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(103);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(167);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(144);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(125);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(82);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(124);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym_identifier);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == ',') ADVANCE(21);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(147);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym_real);
      if (lookahead == 'd') ADVANCE(148);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym_char);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym_char);
      if (lookahead == '!') ADVANCE(108);
      if (lookahead == '&') ADVANCE(111);
      if (lookahead == '(') ADVANCE(157);
      if (lookahead == '*') ADVANCE(110);
      if (lookahead == '+') ADVANCE(106);
      if (lookahead == '-') ADVANCE(107);
      if (lookahead == '<') ADVANCE(151);
      if (lookahead == '^') ADVANCE(109);
      if (lookahead == 'f') ADVANCE(122);
      if (lookahead == 't') ADVANCE(139);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(150);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(147);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'') ADVANCE(149);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym_char);
      if (lookahead == '-') ADVANCE(112);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym_semicolon);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym_colon);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym_colon);
      if (lookahead == '=') ADVANCE(94);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym_dot);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym_comma);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym_left_paren);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym_right_paren);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym_true);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym_true);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(sym_false);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym_false);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(sym_begin);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(sym_begin);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(sym_end);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(sym_var);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(sym_var);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(146);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 1},
  [14] = {.lex_state = 1},
  [15] = {.lex_state = 1},
  [16] = {.lex_state = 1},
  [17] = {.lex_state = 1},
  [18] = {.lex_state = 1},
  [19] = {.lex_state = 1},
  [20] = {.lex_state = 1},
  [21] = {.lex_state = 1},
  [22] = {.lex_state = 1},
  [23] = {.lex_state = 1},
  [24] = {.lex_state = 1},
  [25] = {.lex_state = 1},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 2},
  [36] = {.lex_state = 2},
  [37] = {.lex_state = 2},
  [38] = {.lex_state = 2},
  [39] = {.lex_state = 2},
  [40] = {.lex_state = 2},
  [41] = {.lex_state = 2},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 2},
  [44] = {.lex_state = 80},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 0},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 3},
  [52] = {.lex_state = 17},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 17},
  [57] = {.lex_state = 3},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 80},
  [64] = {.lex_state = 80},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 80},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 0},
  [71] = {.lex_state = 80},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 80},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 4},
  [76] = {.lex_state = 3},
  [77] = {.lex_state = 3},
  [78] = {.lex_state = 80},
  [79] = {.lex_state = 4},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 4},
  [82] = {.lex_state = 4},
  [83] = {.lex_state = 0},
  [84] = {.lex_state = 4},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 4},
  [88] = {.lex_state = 3},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 4},
  [95] = {.lex_state = 4},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 4},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 2},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 3},
  [107] = {.lex_state = 4},
  [108] = {.lex_state = 4},
  [109] = {.lex_state = 4},
  [110] = {.lex_state = 4},
  [111] = {.lex_state = 4},
  [112] = {.lex_state = 4},
  [113] = {.lex_state = 0},
  [114] = {.lex_state = 4},
  [115] = {.lex_state = 4},
  [116] = {.lex_state = 0},
  [117] = {.lex_state = 0},
  [118] = {.lex_state = 0},
  [119] = {.lex_state = 0},
  [120] = {.lex_state = 0},
  [121] = {.lex_state = 0},
  [122] = {.lex_state = 3},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_Program] = ACTIONS(1),
    [anon_sym_const] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_procedure] = ACTIONS(1),
    [anon_sym_boolean] = ACTIONS(1),
    [anon_sym_integer] = ACTIONS(1),
    [anon_sym_real] = ACTIONS(1),
    [anon_sym_char] = ACTIONS(1),
    [anon_sym_COLON_EQ] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_then] = ACTIONS(1),
    [anon_sym_else] = ACTIONS(1),
    [anon_sym_while] = ACTIONS(1),
    [anon_sym_do] = ACTIONS(1),
    [anon_sym_for] = ACTIONS(1),
    [anon_sym_to] = ACTIONS(1),
    [anon_sym_step] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_CARET] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_AMP] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [anon_sym_PERCENT] = ACTIONS(1),
    [anon_sym_LT_GT] = ACTIONS(1),
    [anon_sym_LT] = ACTIONS(1),
    [anon_sym_LT_EQ] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [anon_sym_GT_EQ] = ACTIONS(1),
    [anon_sym_and] = ACTIONS(1),
    [anon_sym_or] = ACTIONS(1),
    [sym_integer] = ACTIONS(1),
    [sym_real] = ACTIONS(1),
    [sym_semicolon] = ACTIONS(1),
    [sym_colon] = ACTIONS(1),
    [sym_dot] = ACTIONS(1),
    [sym_comma] = ACTIONS(1),
    [sym_left_paren] = ACTIONS(1),
    [sym_right_paren] = ACTIONS(1),
    [sym_true] = ACTIONS(1),
    [sym_false] = ACTIONS(1),
    [sym_begin] = ACTIONS(1),
    [sym_end] = ACTIONS(1),
    [sym_var] = ACTIONS(1),
  },
  [1] = {
    [sym_module] = STATE(120),
    [anon_sym_Program] = ACTIONS(3),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(7), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(5), 20,
      anon_sym_EQ,
      anon_sym_then,
      anon_sym_else,
      anon_sym_do,
      anon_sym_to,
      anon_sym_step,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_and,
      anon_sym_or,
      sym_semicolon,
      sym_comma,
      sym_right_paren,
      sym_end,
  [27] = 4,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(13), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(9), 15,
      anon_sym_EQ,
      anon_sym_then,
      anon_sym_else,
      anon_sym_do,
      anon_sym_to,
      anon_sym_step,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_and,
      anon_sym_or,
      sym_semicolon,
      sym_comma,
      sym_right_paren,
      sym_end,
  [58] = 3,
    ACTIONS(15), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(13), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(9), 17,
      anon_sym_EQ,
      anon_sym_then,
      anon_sym_else,
      anon_sym_do,
      anon_sym_to,
      anon_sym_step,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_and,
      anon_sym_or,
      sym_semicolon,
      sym_comma,
      sym_right_paren,
      sym_end,
  [87] = 2,
    ACTIONS(15), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 20,
      anon_sym_EQ,
      anon_sym_then,
      anon_sym_else,
      anon_sym_do,
      anon_sym_to,
      anon_sym_step,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_and,
      anon_sym_or,
      sym_semicolon,
      sym_comma,
      sym_right_paren,
      sym_end,
  [114] = 5,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(19), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(13), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(17), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(9), 11,
      anon_sym_then,
      anon_sym_else,
      anon_sym_do,
      anon_sym_to,
      anon_sym_step,
      anon_sym_and,
      anon_sym_or,
      sym_semicolon,
      sym_comma,
      sym_right_paren,
      sym_end,
  [147] = 2,
    ACTIONS(23), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(21), 20,
      anon_sym_EQ,
      anon_sym_then,
      anon_sym_else,
      anon_sym_do,
      anon_sym_to,
      anon_sym_step,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_and,
      anon_sym_or,
      sym_semicolon,
      sym_comma,
      sym_right_paren,
      sym_end,
  [174] = 6,
    ACTIONS(25), 1,
      anon_sym_and,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(19), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(13), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(17), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(9), 10,
      anon_sym_then,
      anon_sym_else,
      anon_sym_do,
      anon_sym_to,
      anon_sym_step,
      anon_sym_or,
      sym_semicolon,
      sym_comma,
      sym_right_paren,
      sym_end,
  [209] = 5,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(96), 1,
      sym_fact_params,
    STATE(27), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(29), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(27), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [239] = 5,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(104), 1,
      sym_const_expression,
    STATE(29), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(33), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(27), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [269] = 5,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(117), 1,
      sym_const_expression,
    STATE(29), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(33), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(27), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [299] = 5,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(105), 1,
      sym_fact_params,
    STATE(27), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(29), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(27), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [329] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(5), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(35), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(27), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [356] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(8), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(37), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(27), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [383] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(33), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(39), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(27), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [410] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(3), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(41), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(27), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [437] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(32), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(43), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(27), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [464] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(7), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(45), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(27), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [491] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(4), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(47), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(27), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [518] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(34), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(49), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(27), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [545] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(28), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(51), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(27), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [572] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(30), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(53), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(27), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [599] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(26), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(55), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(27), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [626] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(6), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(57), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(27), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [653] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(31), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(59), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(27), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [680] = 7,
    ACTIONS(25), 1,
      anon_sym_and,
    ACTIONS(63), 1,
      anon_sym_or,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(19), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(13), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(61), 3,
      anon_sym_else,
      sym_semicolon,
      sym_end,
    ACTIONS(17), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [711] = 8,
    ACTIONS(25), 1,
      anon_sym_and,
    ACTIONS(63), 1,
      anon_sym_or,
    ACTIONS(65), 1,
      sym_comma,
    ACTIONS(67), 1,
      sym_right_paren,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(19), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(13), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(17), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [743] = 7,
    ACTIONS(25), 1,
      anon_sym_and,
    ACTIONS(63), 1,
      anon_sym_or,
    ACTIONS(69), 1,
      anon_sym_do,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(19), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(13), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(17), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [772] = 7,
    ACTIONS(25), 1,
      anon_sym_and,
    ACTIONS(63), 1,
      anon_sym_or,
    ACTIONS(71), 1,
      sym_semicolon,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(19), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(13), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(17), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [801] = 7,
    ACTIONS(25), 1,
      anon_sym_and,
    ACTIONS(63), 1,
      anon_sym_or,
    ACTIONS(73), 1,
      anon_sym_do,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(19), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(13), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(17), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [830] = 7,
    ACTIONS(25), 1,
      anon_sym_and,
    ACTIONS(63), 1,
      anon_sym_or,
    ACTIONS(75), 1,
      anon_sym_to,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(19), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(13), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(17), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [859] = 7,
    ACTIONS(25), 1,
      anon_sym_and,
    ACTIONS(63), 1,
      anon_sym_or,
    ACTIONS(77), 1,
      anon_sym_step,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(19), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(13), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(17), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [888] = 7,
    ACTIONS(25), 1,
      anon_sym_and,
    ACTIONS(63), 1,
      anon_sym_or,
    ACTIONS(79), 1,
      sym_right_paren,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(19), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(13), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(17), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [917] = 7,
    ACTIONS(25), 1,
      anon_sym_and,
    ACTIONS(63), 1,
      anon_sym_or,
    ACTIONS(81), 1,
      anon_sym_then,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(19), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(13), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(17), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [946] = 7,
    ACTIONS(83), 1,
      anon_sym_if,
    ACTIONS(85), 1,
      anon_sym_while,
    ACTIONS(87), 1,
      anon_sym_for,
    ACTIONS(89), 1,
      sym_identifier,
    ACTIONS(91), 1,
      sym_begin,
    STATE(72), 1,
      sym_statement_sequence,
    STATE(86), 7,
      sym__statement,
      sym_assignment,
      sym_if_statement,
      sym_while_statement,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [974] = 7,
    ACTIONS(83), 1,
      anon_sym_if,
    ACTIONS(85), 1,
      anon_sym_while,
    ACTIONS(87), 1,
      anon_sym_for,
    ACTIONS(89), 1,
      sym_identifier,
    ACTIONS(91), 1,
      sym_begin,
    STATE(80), 1,
      sym_statement_sequence,
    STATE(86), 7,
      sym__statement,
      sym_assignment,
      sym_if_statement,
      sym_while_statement,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [1002] = 6,
    ACTIONS(83), 1,
      anon_sym_if,
    ACTIONS(85), 1,
      anon_sym_while,
    ACTIONS(87), 1,
      anon_sym_for,
    ACTIONS(89), 1,
      sym_identifier,
    ACTIONS(91), 1,
      sym_begin,
    STATE(70), 7,
      sym__statement,
      sym_assignment,
      sym_if_statement,
      sym_while_statement,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [1027] = 6,
    ACTIONS(83), 1,
      anon_sym_if,
    ACTIONS(85), 1,
      anon_sym_while,
    ACTIONS(87), 1,
      anon_sym_for,
    ACTIONS(89), 1,
      sym_identifier,
    ACTIONS(91), 1,
      sym_begin,
    STATE(113), 7,
      sym__statement,
      sym_assignment,
      sym_if_statement,
      sym_while_statement,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [1052] = 6,
    ACTIONS(83), 1,
      anon_sym_if,
    ACTIONS(85), 1,
      anon_sym_while,
    ACTIONS(87), 1,
      anon_sym_for,
    ACTIONS(89), 1,
      sym_identifier,
    ACTIONS(91), 1,
      sym_begin,
    STATE(85), 7,
      sym__statement,
      sym_assignment,
      sym_if_statement,
      sym_while_statement,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [1077] = 6,
    ACTIONS(83), 1,
      anon_sym_if,
    ACTIONS(85), 1,
      anon_sym_while,
    ACTIONS(87), 1,
      anon_sym_for,
    ACTIONS(89), 1,
      sym_identifier,
    ACTIONS(91), 1,
      sym_begin,
    STATE(67), 7,
      sym__statement,
      sym_assignment,
      sym_if_statement,
      sym_while_statement,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [1102] = 6,
    ACTIONS(83), 1,
      anon_sym_if,
    ACTIONS(85), 1,
      anon_sym_while,
    ACTIONS(87), 1,
      anon_sym_for,
    ACTIONS(89), 1,
      sym_identifier,
    ACTIONS(91), 1,
      sym_begin,
    STATE(65), 7,
      sym__statement,
      sym_assignment,
      sym_if_statement,
      sym_while_statement,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [1127] = 6,
    ACTIONS(93), 1,
      anon_sym_const,
    ACTIONS(95), 1,
      anon_sym_procedure,
    ACTIONS(97), 1,
      sym_begin,
    ACTIONS(99), 1,
      sym_var,
    STATE(59), 1,
      sym_declarations_sequence,
    STATE(60), 3,
      sym_var_declarations,
      sym_const_declarations,
      sym_procedure_declatarions,
  [1148] = 2,
    ACTIONS(103), 1,
      sym_left_paren,
    ACTIONS(101), 6,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT_EQ,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_COLON_EQ,
  [1160] = 5,
    ACTIONS(105), 1,
      anon_sym_,
    ACTIONS(107), 1,
      sym_right_paren,
    ACTIONS(109), 1,
      sym_var,
    STATE(89), 1,
      sym_formal_params_sequence,
    STATE(90), 1,
      sym_formal_params_list,
  [1176] = 2,
    STATE(118), 1,
      sym_type,
    ACTIONS(111), 4,
      anon_sym_boolean,
      anon_sym_integer,
      anon_sym_real,
      anon_sym_char,
  [1186] = 2,
    STATE(116), 1,
      sym_type,
    ACTIONS(111), 4,
      anon_sym_boolean,
      anon_sym_integer,
      anon_sym_real,
      anon_sym_char,
  [1196] = 2,
    STATE(97), 1,
      sym_type,
    ACTIONS(111), 4,
      anon_sym_boolean,
      anon_sym_integer,
      anon_sym_real,
      anon_sym_char,
  [1206] = 2,
    STATE(91), 1,
      sym_type,
    ACTIONS(111), 4,
      anon_sym_boolean,
      anon_sym_integer,
      anon_sym_real,
      anon_sym_char,
  [1216] = 1,
    ACTIONS(113), 4,
      anon_sym_const,
      anon_sym_procedure,
      sym_begin,
      sym_var,
  [1223] = 1,
    ACTIONS(115), 4,
      anon_sym_const,
      anon_sym_procedure,
      sym_begin,
      sym_var,
  [1230] = 4,
    ACTIONS(117), 1,
      sym_identifier,
    ACTIONS(119), 1,
      sym_var,
    STATE(75), 1,
      sym_var_declarations,
    STATE(94), 1,
      sym_var_declaration,
  [1243] = 4,
    ACTIONS(121), 1,
      anon_sym_const,
    ACTIONS(123), 1,
      sym_identifier,
    STATE(79), 1,
      sym_const_declarations,
    STATE(107), 1,
      sym_const_declaration,
  [1256] = 1,
    ACTIONS(125), 4,
      anon_sym_const,
      anon_sym_procedure,
      sym_begin,
      sym_var,
  [1263] = 1,
    ACTIONS(127), 4,
      anon_sym_const,
      anon_sym_procedure,
      sym_begin,
      sym_var,
  [1270] = 1,
    ACTIONS(129), 4,
      anon_sym_const,
      anon_sym_procedure,
      sym_begin,
      sym_var,
  [1277] = 4,
    ACTIONS(121), 1,
      anon_sym_const,
    ACTIONS(131), 1,
      sym_identifier,
    STATE(61), 1,
      sym_const_declaration,
    STATE(84), 1,
      sym_const_declarations,
  [1290] = 4,
    ACTIONS(119), 1,
      sym_var,
    ACTIONS(133), 1,
      sym_identifier,
    STATE(49), 1,
      sym_var_declaration,
    STATE(87), 1,
      sym_var_declarations,
  [1303] = 1,
    ACTIONS(135), 4,
      anon_sym_const,
      anon_sym_procedure,
      sym_begin,
      sym_var,
  [1310] = 1,
    ACTIONS(137), 4,
      anon_sym_const,
      anon_sym_procedure,
      sym_begin,
      sym_var,
  [1317] = 1,
    ACTIONS(139), 4,
      anon_sym_const,
      anon_sym_procedure,
      sym_begin,
      sym_var,
  [1324] = 1,
    ACTIONS(141), 4,
      anon_sym_const,
      anon_sym_procedure,
      sym_begin,
      sym_var,
  [1331] = 1,
    ACTIONS(143), 4,
      anon_sym_const,
      anon_sym_procedure,
      sym_begin,
      sym_var,
  [1338] = 3,
    ACTIONS(145), 1,
      anon_sym_,
    STATE(42), 1,
      sym_declarations,
    STATE(103), 1,
      sym_mainblock,
  [1348] = 3,
    ACTIONS(105), 1,
      anon_sym_,
    ACTIONS(109), 1,
      sym_var,
    STATE(92), 1,
      sym_formal_params_sequence,
  [1358] = 1,
    ACTIONS(147), 3,
      anon_sym_else,
      sym_semicolon,
      sym_end,
  [1364] = 3,
    ACTIONS(149), 1,
      anon_sym_,
    ACTIONS(151), 1,
      sym_comma,
    STATE(100), 1,
      sym_return,
  [1374] = 1,
    ACTIONS(153), 3,
      anon_sym_else,
      sym_semicolon,
      sym_end,
  [1380] = 1,
    ACTIONS(155), 3,
      anon_sym_else,
      sym_semicolon,
      sym_end,
  [1386] = 1,
    ACTIONS(157), 3,
      anon_sym_else,
      sym_semicolon,
      sym_end,
  [1392] = 1,
    ACTIONS(159), 3,
      anon_sym_else,
      sym_semicolon,
      sym_end,
  [1398] = 3,
    ACTIONS(145), 1,
      anon_sym_,
    STATE(42), 1,
      sym_declarations,
    STATE(108), 1,
      sym_mainblock,
  [1408] = 2,
    ACTIONS(161), 1,
      sym_semicolon,
    ACTIONS(163), 1,
      sym_end,
  [1415] = 2,
    ACTIONS(165), 1,
      anon_sym_,
    ACTIONS(167), 1,
      sym_comma,
  [1422] = 1,
    ACTIONS(169), 2,
      sym_semicolon,
      sym_right_paren,
  [1427] = 2,
    ACTIONS(171), 1,
      sym_identifier,
    STATE(110), 1,
      sym_var_declaration,
  [1434] = 1,
    ACTIONS(173), 2,
      sym_colon,
      sym_comma,
  [1439] = 2,
    ACTIONS(175), 1,
      sym_colon,
    ACTIONS(177), 1,
      sym_comma,
  [1446] = 2,
    ACTIONS(179), 1,
      anon_sym_,
    ACTIONS(181), 1,
      sym_comma,
  [1453] = 2,
    ACTIONS(183), 1,
      sym_identifier,
    STATE(109), 1,
      sym_const_declaration,
  [1460] = 2,
    ACTIONS(161), 1,
      sym_semicolon,
    ACTIONS(185), 1,
      sym_end,
  [1467] = 1,
    ACTIONS(187), 2,
      sym_identifier,
      sym_dot,
  [1472] = 2,
    ACTIONS(189), 1,
      sym_identifier,
    STATE(77), 1,
      sym_identifier_list,
  [1479] = 2,
    ACTIONS(191), 1,
      sym_left_paren,
    STATE(66), 1,
      sym_formal_params,
  [1486] = 2,
    ACTIONS(193), 1,
      sym_identifier,
    STATE(62), 1,
      sym_const_declaration,
  [1493] = 1,
    ACTIONS(195), 2,
      sym_semicolon,
      sym_end,
  [1498] = 1,
    ACTIONS(197), 2,
      sym_semicolon,
      sym_end,
  [1503] = 2,
    ACTIONS(199), 1,
      sym_identifier,
    STATE(54), 1,
      sym_var_declaration,
  [1510] = 1,
    ACTIONS(201), 2,
      sym_colon,
      sym_comma,
  [1515] = 1,
    ACTIONS(203), 2,
      sym_semicolon,
      sym_right_paren,
  [1520] = 2,
    ACTIONS(205), 1,
      sym_semicolon,
    ACTIONS(207), 1,
      sym_right_paren,
  [1527] = 1,
    ACTIONS(209), 2,
      sym_semicolon,
      sym_right_paren,
  [1532] = 1,
    ACTIONS(211), 2,
      sym_semicolon,
      sym_right_paren,
  [1537] = 1,
    ACTIONS(213), 1,
      anon_sym_EQ,
  [1541] = 1,
    ACTIONS(113), 1,
      sym_identifier,
  [1545] = 1,
    ACTIONS(215), 1,
      sym_identifier,
  [1549] = 1,
    ACTIONS(217), 1,
      sym_right_paren,
  [1553] = 1,
    ACTIONS(219), 1,
      sym_semicolon,
  [1557] = 1,
    ACTIONS(221), 1,
      sym_identifier,
  [1561] = 1,
    ACTIONS(223), 1,
      sym_semicolon,
  [1565] = 1,
    ACTIONS(225), 1,
      sym_semicolon,
  [1569] = 1,
    ACTIONS(227), 1,
      ts_builtin_sym_end,
  [1573] = 1,
    ACTIONS(229), 1,
      anon_sym_COLON_EQ,
  [1577] = 1,
    ACTIONS(231), 1,
      sym_dot,
  [1581] = 1,
    ACTIONS(233), 1,
      sym_semicolon,
  [1585] = 1,
    ACTIONS(235), 1,
      sym_right_paren,
  [1589] = 1,
    ACTIONS(237), 1,
      sym_colon,
  [1593] = 1,
    ACTIONS(141), 1,
      sym_identifier,
  [1597] = 1,
    ACTIONS(239), 1,
      sym_identifier,
  [1601] = 1,
    ACTIONS(143), 1,
      sym_identifier,
  [1605] = 1,
    ACTIONS(127), 1,
      sym_identifier,
  [1609] = 1,
    ACTIONS(115), 1,
      sym_identifier,
  [1613] = 1,
    ACTIONS(135), 1,
      sym_identifier,
  [1617] = 1,
    ACTIONS(241), 1,
      anon_sym_else,
  [1621] = 1,
    ACTIONS(243), 1,
      sym_identifier,
  [1625] = 1,
    ACTIONS(245), 1,
      sym_identifier,
  [1629] = 1,
    ACTIONS(247), 1,
      sym_semicolon,
  [1633] = 1,
    ACTIONS(249), 1,
      sym_semicolon,
  [1637] = 1,
    ACTIONS(251), 1,
      sym_semicolon,
  [1641] = 1,
    ACTIONS(253), 1,
      sym_semicolon,
  [1645] = 1,
    ACTIONS(255), 1,
      ts_builtin_sym_end,
  [1649] = 1,
    ACTIONS(257), 1,
      anon_sym_EQ,
  [1653] = 1,
    ACTIONS(259), 1,
      sym_colon,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 27,
  [SMALL_STATE(4)] = 58,
  [SMALL_STATE(5)] = 87,
  [SMALL_STATE(6)] = 114,
  [SMALL_STATE(7)] = 147,
  [SMALL_STATE(8)] = 174,
  [SMALL_STATE(9)] = 209,
  [SMALL_STATE(10)] = 239,
  [SMALL_STATE(11)] = 269,
  [SMALL_STATE(12)] = 299,
  [SMALL_STATE(13)] = 329,
  [SMALL_STATE(14)] = 356,
  [SMALL_STATE(15)] = 383,
  [SMALL_STATE(16)] = 410,
  [SMALL_STATE(17)] = 437,
  [SMALL_STATE(18)] = 464,
  [SMALL_STATE(19)] = 491,
  [SMALL_STATE(20)] = 518,
  [SMALL_STATE(21)] = 545,
  [SMALL_STATE(22)] = 572,
  [SMALL_STATE(23)] = 599,
  [SMALL_STATE(24)] = 626,
  [SMALL_STATE(25)] = 653,
  [SMALL_STATE(26)] = 680,
  [SMALL_STATE(27)] = 711,
  [SMALL_STATE(28)] = 743,
  [SMALL_STATE(29)] = 772,
  [SMALL_STATE(30)] = 801,
  [SMALL_STATE(31)] = 830,
  [SMALL_STATE(32)] = 859,
  [SMALL_STATE(33)] = 888,
  [SMALL_STATE(34)] = 917,
  [SMALL_STATE(35)] = 946,
  [SMALL_STATE(36)] = 974,
  [SMALL_STATE(37)] = 1002,
  [SMALL_STATE(38)] = 1027,
  [SMALL_STATE(39)] = 1052,
  [SMALL_STATE(40)] = 1077,
  [SMALL_STATE(41)] = 1102,
  [SMALL_STATE(42)] = 1127,
  [SMALL_STATE(43)] = 1148,
  [SMALL_STATE(44)] = 1160,
  [SMALL_STATE(45)] = 1176,
  [SMALL_STATE(46)] = 1186,
  [SMALL_STATE(47)] = 1196,
  [SMALL_STATE(48)] = 1206,
  [SMALL_STATE(49)] = 1216,
  [SMALL_STATE(50)] = 1223,
  [SMALL_STATE(51)] = 1230,
  [SMALL_STATE(52)] = 1243,
  [SMALL_STATE(53)] = 1256,
  [SMALL_STATE(54)] = 1263,
  [SMALL_STATE(55)] = 1270,
  [SMALL_STATE(56)] = 1277,
  [SMALL_STATE(57)] = 1290,
  [SMALL_STATE(58)] = 1303,
  [SMALL_STATE(59)] = 1310,
  [SMALL_STATE(60)] = 1317,
  [SMALL_STATE(61)] = 1324,
  [SMALL_STATE(62)] = 1331,
  [SMALL_STATE(63)] = 1338,
  [SMALL_STATE(64)] = 1348,
  [SMALL_STATE(65)] = 1358,
  [SMALL_STATE(66)] = 1364,
  [SMALL_STATE(67)] = 1374,
  [SMALL_STATE(68)] = 1380,
  [SMALL_STATE(69)] = 1386,
  [SMALL_STATE(70)] = 1392,
  [SMALL_STATE(71)] = 1398,
  [SMALL_STATE(72)] = 1408,
  [SMALL_STATE(73)] = 1415,
  [SMALL_STATE(74)] = 1422,
  [SMALL_STATE(75)] = 1427,
  [SMALL_STATE(76)] = 1434,
  [SMALL_STATE(77)] = 1439,
  [SMALL_STATE(78)] = 1446,
  [SMALL_STATE(79)] = 1453,
  [SMALL_STATE(80)] = 1460,
  [SMALL_STATE(81)] = 1467,
  [SMALL_STATE(82)] = 1472,
  [SMALL_STATE(83)] = 1479,
  [SMALL_STATE(84)] = 1486,
  [SMALL_STATE(85)] = 1493,
  [SMALL_STATE(86)] = 1498,
  [SMALL_STATE(87)] = 1503,
  [SMALL_STATE(88)] = 1510,
  [SMALL_STATE(89)] = 1515,
  [SMALL_STATE(90)] = 1520,
  [SMALL_STATE(91)] = 1527,
  [SMALL_STATE(92)] = 1532,
  [SMALL_STATE(93)] = 1537,
  [SMALL_STATE(94)] = 1541,
  [SMALL_STATE(95)] = 1545,
  [SMALL_STATE(96)] = 1549,
  [SMALL_STATE(97)] = 1553,
  [SMALL_STATE(98)] = 1557,
  [SMALL_STATE(99)] = 1561,
  [SMALL_STATE(100)] = 1565,
  [SMALL_STATE(101)] = 1569,
  [SMALL_STATE(102)] = 1573,
  [SMALL_STATE(103)] = 1577,
  [SMALL_STATE(104)] = 1581,
  [SMALL_STATE(105)] = 1585,
  [SMALL_STATE(106)] = 1589,
  [SMALL_STATE(107)] = 1593,
  [SMALL_STATE(108)] = 1597,
  [SMALL_STATE(109)] = 1601,
  [SMALL_STATE(110)] = 1605,
  [SMALL_STATE(111)] = 1609,
  [SMALL_STATE(112)] = 1613,
  [SMALL_STATE(113)] = 1617,
  [SMALL_STATE(114)] = 1621,
  [SMALL_STATE(115)] = 1625,
  [SMALL_STATE(116)] = 1629,
  [SMALL_STATE(117)] = 1633,
  [SMALL_STATE(118)] = 1637,
  [SMALL_STATE(119)] = 1641,
  [SMALL_STATE(120)] = 1645,
  [SMALL_STATE(121)] = 1649,
  [SMALL_STATE(122)] = 1653,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(115),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 3),
  [7] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression, 3),
  [9] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [15] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_expression, 2),
  [23] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unary_expression, 2),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(27),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [49] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [55] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [57] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [59] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment, 3),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fact_params, 1),
  [69] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [71] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_expression, 1),
  [73] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [75] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [77] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [83] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(21),
  [87] = {.entry = {.count = 1, .reusable = false}}, SHIFT(114),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [91] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(12),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [107] = {.entry = {.count = 1, .reusable = false}}, SHIFT(73),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(82),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_declarations, 2),
  [115] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_declaration, 4),
  [117] = {.entry = {.count = 1, .reusable = false}}, SHIFT(122),
  [119] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [121] = {.entry = {.count = 1, .reusable = false}}, SHIFT(52),
  [123] = {.entry = {.count = 1, .reusable = false}}, SHIFT(121),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declarations, 1),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_declarations, 3),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_procedure_declatarions, 8),
  [131] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [133] = {.entry = {.count = 1, .reusable = false}}, SHIFT(106),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_var_declaration, 4),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declarations, 2),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declarations_sequence, 1),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_declarations, 2),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_declarations, 3),
  [145] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_for_statement, 10),
  [149] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [151] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [153] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_statement, 6),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_procedure_call_statement, 4),
  [157] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_statement, 3),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_statement, 4),
  [161] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [163] = {.entry = {.count = 1, .reusable = true}}, SHIFT(81),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formal_params, 2),
  [167] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_formal_params, 2),
  [169] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [171] = {.entry = {.count = 1, .reusable = true}}, SHIFT(122),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier_list, 1),
  [175] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [177] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formal_params, 3),
  [181] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_formal_params, 3),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(121),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [187] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_mainblock, 4),
  [189] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [191] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [193] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement_sequence, 3),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement_sequence, 1),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier_list, 3),
  [203] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formal_params_list, 1),
  [205] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formal_params_sequence, 4),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formal_params_list, 3),
  [213] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [217] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fact_params, 3),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [227] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 5),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [231] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [237] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [241] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(102),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(119),
  [247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return, 2),
  [249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(111),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(112),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [255] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_pascalabcnet(void) {
  static TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .alias_map = ts_non_terminal_alias_map,
    .state_count = STATE_COUNT,
    .symbol_metadata = ts_symbol_metadata,
    .parse_table = (const unsigned short *)ts_parse_table,
    .small_parse_table = (const uint16_t *)ts_small_parse_table,
    .small_parse_table_map = (const uint32_t *)ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .lex_modes = ts_lex_modes,
    .symbol_names = ts_symbol_names,
    .public_symbol_map = ts_symbol_map,
    .alias_sequences = (const TSSymbol *)ts_alias_sequences,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .lex_fn = ts_lex,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
