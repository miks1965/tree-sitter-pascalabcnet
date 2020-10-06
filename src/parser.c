#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 12
#define STATE_COUNT 109
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 86
#define ALIAS_COUNT 0
#define TOKEN_COUNT 55
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 10

enum {
  anon_sym_Program = 1,
  anon_sym_const = 2,
  anon_sym_EQ = 3,
  anon_sym_procedure = 4,
  anon_sym_ = 5,
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
  sym_declarations_sequence = 57,
  sym_var_declarations = 58,
  sym_var_declaration = 59,
  sym_const_declarations = 60,
  sym_const_declaration = 61,
  sym_const_expression = 62,
  sym_procedure_declatarions = 63,
  sym_formal_params = 64,
  sym_return = 65,
  sym_formal_params_list = 66,
  sym_formal_params_sequence = 67,
  sym_type = 68,
  sym_statement_sequence = 69,
  sym__statement = 70,
  sym_assignment = 71,
  sym_if_statement = 72,
  sym_while_statement = 73,
  sym_for_statement = 74,
  sym_block_statement = 75,
  sym_procedure_call_statement = 76,
  sym_identifier_list = 77,
  sym_fact_params = 78,
  sym__expression = 79,
  sym_unary_expression = 80,
  sym_binary_expression = 81,
  sym__number = 82,
  aux_sym_mainblock_repeat1 = 83,
  aux_sym_var_declarations_repeat1 = 84,
  aux_sym_const_declarations_repeat1 = 85,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_Program] = "Program",
  [anon_sym_const] = "const",
  [anon_sym_EQ] = "=",
  [anon_sym_procedure] = "procedure",
  [anon_sym_] = "",
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
  [aux_sym_mainblock_repeat1] = "mainblock_repeat1",
  [aux_sym_var_declarations_repeat1] = "var_declarations_repeat1",
  [aux_sym_const_declarations_repeat1] = "const_declarations_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_Program] = anon_sym_Program,
  [anon_sym_const] = anon_sym_const,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_procedure] = anon_sym_procedure,
  [anon_sym_] = anon_sym_,
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
  [aux_sym_mainblock_repeat1] = aux_sym_mainblock_repeat1,
  [aux_sym_var_declarations_repeat1] = aux_sym_var_declarations_repeat1,
  [aux_sym_const_declarations_repeat1] = aux_sym_const_declarations_repeat1,
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
  [anon_sym_] = {
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
  [aux_sym_mainblock_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_var_declarations_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_const_declarations_repeat1] = {
    .visible = false,
    .named = false,
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
      if (lookahead == '!') ADVANCE(109);
      if (lookahead == '%') ADVANCE(115);
      if (lookahead == '&') ADVANCE(112);
      if (lookahead == '(') ADVANCE(168);
      if (lookahead == ')') ADVANCE(169);
      if (lookahead == '*') ADVANCE(111);
      if (lookahead == '+') ADVANCE(107);
      if (lookahead == ',') ADVANCE(167);
      if (lookahead == '-') ADVANCE(108);
      if (lookahead == '.') ADVANCE(166);
      if (lookahead == '/') ADVANCE(114);
      if (lookahead == ':') ADVANCE(165);
      if (lookahead == ';') ADVANCE(163);
      if (lookahead == '<') ADVANCE(117);
      if (lookahead == '=') ADVANCE(82);
      if (lookahead == '>') ADVANCE(119);
      if (lookahead == 'P') ADVANCE(66);
      if (lookahead == '^') ADVANCE(110);
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
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(158);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(1)
      if (lookahead == '!') ADVANCE(109);
      if (lookahead == '&') ADVANCE(112);
      if (lookahead == '(') ADVANCE(168);
      if (lookahead == '*') ADVANCE(111);
      if (lookahead == '+') ADVANCE(107);
      if (lookahead == '-') ADVANCE(108);
      if (lookahead == '<') ADVANCE(162);
      if (lookahead == '^') ADVANCE(110);
      if (lookahead == 'f') ADVANCE(123);
      if (lookahead == 't') ADVANCE(147);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(160);
      END_STATE();
    case 2:
      if (lookahead == '%') ADVANCE(6);
      if (lookahead == '(') ADVANCE(168);
      if (lookahead == '*') ADVANCE(7);
      if (lookahead == '+') ADVANCE(8);
      if (lookahead == '-') ADVANCE(9);
      if (lookahead == '/') ADVANCE(10);
      if (lookahead == ':') ADVANCE(5);
      if (lookahead == 'b') ADVANCE(130);
      if (lookahead == 'e') ADVANCE(141);
      if (lookahead == 'f') ADVANCE(145);
      if (lookahead == 'i') ADVANCE(134);
      if (lookahead == 'w') ADVANCE(136);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 3:
      if (lookahead == ',') ADVANCE(167);
      if (lookahead == ':') ADVANCE(164);
      if (lookahead == 'b') ADVANCE(130);
      if (lookahead == 'f') ADVANCE(145);
      if (lookahead == 'i') ADVANCE(134);
      if (lookahead == 'w') ADVANCE(136);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 4:
      if (lookahead == '.') ADVANCE(166);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 5:
      if (lookahead == '=') ADVANCE(95);
      END_STATE();
    case 6:
      if (lookahead == '=') ADVANCE(92);
      END_STATE();
    case 7:
      if (lookahead == '=') ADVANCE(90);
      END_STATE();
    case 8:
      if (lookahead == '=') ADVANCE(93);
      END_STATE();
    case 9:
      if (lookahead == '=') ADVANCE(94);
      END_STATE();
    case 10:
      if (lookahead == '=') ADVANCE(91);
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
      if (lookahead == 'b') ADVANCE(130);
      if (lookahead == 'c') ADVANCE(146);
      if (lookahead == 'p') ADVANCE(150);
      if (lookahead == 'v') ADVANCE(124);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(17)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 18:
      if (lookahead == 'c') ADVANCE(34);
      END_STATE();
    case 19:
      if (lookahead == 'd') ADVANCE(121);
      END_STATE();
    case 20:
      if (lookahead == 'd') ADVANCE(176);
      END_STATE();
    case 21:
      if (lookahead == 'd') ADVANCE(159);
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
      if (lookahead == 'e') ADVANCE(99);
      END_STATE();
    case 26:
      if (lookahead == 'e') ADVANCE(170);
      END_STATE();
    case 27:
      if (lookahead == 'e') ADVANCE(172);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(100);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(83);
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
      if (lookahead == 'f') ADVANCE(96);
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
      if (lookahead == 'o') ADVANCE(105);
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
      if (lookahead == 'l') ADVANCE(88);
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
      if (lookahead == 'n') ADVANCE(98);
      END_STATE();
    case 53:
      if (lookahead == 'n') ADVANCE(174);
      END_STATE();
    case 54:
      if (lookahead == 'n') ADVANCE(86);
      END_STATE();
    case 55:
      if (lookahead == 'n') ADVANCE(70);
      END_STATE();
    case 56:
      if (lookahead == 'o') ADVANCE(102);
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
      if (lookahead == 'p') ADVANCE(106);
      END_STATE();
    case 61:
      if (lookahead == 'r') ADVANCE(122);
      END_STATE();
    case 62:
      if (lookahead == 'r') ADVANCE(103);
      END_STATE();
    case 63:
      if (lookahead == 'r') ADVANCE(178);
      END_STATE();
    case 64:
      if (lookahead == 'r') ADVANCE(89);
      END_STATE();
    case 65:
      if (lookahead == 'r') ADVANCE(87);
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
      if (lookahead == 't') ADVANCE(80);
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
      ACCEPT_TOKEN(anon_sym_const);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_const);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_procedure);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_procedure);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_boolean);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_integer);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_real);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_char);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_STAR_EQ);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_SLASH_EQ);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_PERCENT_EQ);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_PLUS_EQ);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_DASH_EQ);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_COLON_EQ);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_if);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_then);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_while);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_while);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_do);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_for);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_for);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_to);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_step);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_CARET);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(anon_sym_AMP);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(anon_sym_LT_DASH);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(anon_sym_LT_GT);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(118);
      if (lookahead == '>') ADVANCE(116);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(120);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(anon_sym_and);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(anon_sym_or);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(139);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(149);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(133);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(177);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(156);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(171);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(173);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(135);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(101);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(84);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(127);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(97);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(138);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h') ADVANCE(137);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(140);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(142);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(153);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(131);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(126);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(175);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(125);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(148);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(143);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(155);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(104);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(179);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(144);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(132);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(154);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(129);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(81);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 155:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(128);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 156:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(151);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 157:
      ACCEPT_TOKEN(sym_identifier);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 158:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == ',') ADVANCE(21);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(158);
      END_STATE();
    case 159:
      ACCEPT_TOKEN(sym_real);
      if (lookahead == 'd') ADVANCE(159);
      END_STATE();
    case 160:
      ACCEPT_TOKEN(sym_char);
      END_STATE();
    case 161:
      ACCEPT_TOKEN(sym_char);
      if (lookahead == '!') ADVANCE(109);
      if (lookahead == '&') ADVANCE(112);
      if (lookahead == '(') ADVANCE(168);
      if (lookahead == '*') ADVANCE(111);
      if (lookahead == '+') ADVANCE(107);
      if (lookahead == '-') ADVANCE(108);
      if (lookahead == '<') ADVANCE(162);
      if (lookahead == '^') ADVANCE(110);
      if (lookahead == 'f') ADVANCE(123);
      if (lookahead == 't') ADVANCE(147);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(161);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(158);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'') ADVANCE(160);
      END_STATE();
    case 162:
      ACCEPT_TOKEN(sym_char);
      if (lookahead == '-') ADVANCE(113);
      END_STATE();
    case 163:
      ACCEPT_TOKEN(sym_semicolon);
      END_STATE();
    case 164:
      ACCEPT_TOKEN(sym_colon);
      END_STATE();
    case 165:
      ACCEPT_TOKEN(sym_colon);
      if (lookahead == '=') ADVANCE(95);
      END_STATE();
    case 166:
      ACCEPT_TOKEN(sym_dot);
      END_STATE();
    case 167:
      ACCEPT_TOKEN(sym_comma);
      END_STATE();
    case 168:
      ACCEPT_TOKEN(sym_left_paren);
      END_STATE();
    case 169:
      ACCEPT_TOKEN(sym_right_paren);
      END_STATE();
    case 170:
      ACCEPT_TOKEN(sym_true);
      END_STATE();
    case 171:
      ACCEPT_TOKEN(sym_true);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 172:
      ACCEPT_TOKEN(sym_false);
      END_STATE();
    case 173:
      ACCEPT_TOKEN(sym_false);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 174:
      ACCEPT_TOKEN(sym_begin);
      END_STATE();
    case 175:
      ACCEPT_TOKEN(sym_begin);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 176:
      ACCEPT_TOKEN(sym_end);
      END_STATE();
    case 177:
      ACCEPT_TOKEN(sym_end);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
      END_STATE();
    case 178:
      ACCEPT_TOKEN(sym_var);
      END_STATE();
    case 179:
      ACCEPT_TOKEN(sym_var);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(157);
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
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 2},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 2},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 0},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 2},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
  [36] = {.lex_state = 0},
  [37] = {.lex_state = 3},
  [38] = {.lex_state = 3},
  [39] = {.lex_state = 3},
  [40] = {.lex_state = 3},
  [41] = {.lex_state = 3},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 17},
  [47] = {.lex_state = 17},
  [48] = {.lex_state = 2},
  [49] = {.lex_state = 17},
  [50] = {.lex_state = 17},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 17},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 17},
  [55] = {.lex_state = 85},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 0},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 4},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 85},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 85},
  [64] = {.lex_state = 4},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 0},
  [70] = {.lex_state = 85},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 0},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 4},
  [75] = {.lex_state = 4},
  [76] = {.lex_state = 3},
  [77] = {.lex_state = 3},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 85},
  [80] = {.lex_state = 4},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 3},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 4},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 2},
  [91] = {.lex_state = 4},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 4},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 4},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 3},
  [100] = {.lex_state = 4},
  [101] = {.lex_state = 0},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 4},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 0},
  [108] = {.lex_state = 0},
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
    [sym_module] = STATE(107),
    [anon_sym_Program] = ACTIONS(3),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(7), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(11), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(5), 15,
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
  [31] = 2,
    ACTIONS(15), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(13), 20,
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
  [58] = 6,
    ACTIONS(21), 1,
      anon_sym_and,
    ACTIONS(7), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(19), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(17), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(5), 10,
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
  [93] = 2,
    ACTIONS(11), 2,
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
  [120] = 2,
    ACTIONS(25), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(23), 20,
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
  [147] = 3,
    ACTIONS(11), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(5), 17,
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
  [176] = 5,
    ACTIONS(7), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(19), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(17), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(5), 11,
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
  [209] = 5,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(102), 1,
      sym_fact_params,
    STATE(26), 4,
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
    STATE(108), 1,
      sym_const_expression,
    STATE(28), 4,
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
    STATE(98), 1,
      sym_fact_params,
    STATE(26), 4,
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
  [299] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(35), 4,
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
  [326] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(7), 4,
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
  [353] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(36), 4,
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
  [380] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(31), 4,
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
  [407] = 4,
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
  [434] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(6), 4,
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
  [461] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(2), 4,
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
  [488] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(5), 4,
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
  [515] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(8), 4,
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
  [542] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(34), 4,
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
  [569] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(25), 4,
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
  [596] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(30), 4,
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
  [623] = 4,
    ACTIONS(31), 1,
      sym_left_paren,
    STATE(4), 4,
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
  [650] = 7,
    ACTIONS(21), 1,
      anon_sym_and,
    ACTIONS(63), 1,
      anon_sym_or,
    ACTIONS(7), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(19), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
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
  [681] = 8,
    ACTIONS(21), 1,
      anon_sym_and,
    ACTIONS(63), 1,
      anon_sym_or,
    ACTIONS(65), 1,
      sym_comma,
    ACTIONS(67), 1,
      sym_right_paren,
    ACTIONS(7), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(19), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(17), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [713] = 8,
    ACTIONS(69), 1,
      anon_sym_if,
    ACTIONS(71), 1,
      anon_sym_while,
    ACTIONS(73), 1,
      anon_sym_for,
    ACTIONS(75), 1,
      sym_identifier,
    ACTIONS(77), 1,
      sym_begin,
    ACTIONS(79), 1,
      sym_end,
    STATE(81), 1,
      sym_statement_sequence,
    STATE(89), 7,
      sym__statement,
      sym_assignment,
      sym_if_statement,
      sym_while_statement,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [744] = 7,
    ACTIONS(21), 1,
      anon_sym_and,
    ACTIONS(63), 1,
      anon_sym_or,
    ACTIONS(81), 1,
      sym_semicolon,
    ACTIONS(7), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(19), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(17), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [773] = 8,
    ACTIONS(69), 1,
      anon_sym_if,
    ACTIONS(71), 1,
      anon_sym_while,
    ACTIONS(73), 1,
      anon_sym_for,
    ACTIONS(75), 1,
      sym_identifier,
    ACTIONS(77), 1,
      sym_begin,
    ACTIONS(83), 1,
      sym_end,
    STATE(71), 1,
      sym_statement_sequence,
    STATE(89), 7,
      sym__statement,
      sym_assignment,
      sym_if_statement,
      sym_while_statement,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [804] = 7,
    ACTIONS(21), 1,
      anon_sym_and,
    ACTIONS(63), 1,
      anon_sym_or,
    ACTIONS(85), 1,
      anon_sym_to,
    ACTIONS(7), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(19), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(17), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [833] = 7,
    ACTIONS(21), 1,
      anon_sym_and,
    ACTIONS(63), 1,
      anon_sym_or,
    ACTIONS(87), 1,
      anon_sym_then,
    ACTIONS(7), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(19), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(17), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [862] = 7,
    ACTIONS(21), 1,
      anon_sym_and,
    ACTIONS(63), 1,
      anon_sym_or,
    ACTIONS(89), 1,
      anon_sym_do,
    ACTIONS(7), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(19), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(17), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [891] = 8,
    ACTIONS(69), 1,
      anon_sym_if,
    ACTIONS(71), 1,
      anon_sym_while,
    ACTIONS(73), 1,
      anon_sym_for,
    ACTIONS(75), 1,
      sym_identifier,
    ACTIONS(77), 1,
      sym_begin,
    ACTIONS(91), 1,
      sym_end,
    STATE(78), 1,
      sym_statement_sequence,
    STATE(89), 7,
      sym__statement,
      sym_assignment,
      sym_if_statement,
      sym_while_statement,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [922] = 7,
    ACTIONS(21), 1,
      anon_sym_and,
    ACTIONS(63), 1,
      anon_sym_or,
    ACTIONS(93), 1,
      anon_sym_step,
    ACTIONS(7), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(19), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(17), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [951] = 7,
    ACTIONS(21), 1,
      anon_sym_and,
    ACTIONS(63), 1,
      anon_sym_or,
    ACTIONS(95), 1,
      sym_right_paren,
    ACTIONS(7), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(19), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(17), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [980] = 7,
    ACTIONS(21), 1,
      anon_sym_and,
    ACTIONS(63), 1,
      anon_sym_or,
    ACTIONS(97), 1,
      anon_sym_do,
    ACTIONS(7), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(19), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(17), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [1009] = 6,
    ACTIONS(69), 1,
      anon_sym_if,
    ACTIONS(71), 1,
      anon_sym_while,
    ACTIONS(73), 1,
      anon_sym_for,
    ACTIONS(75), 1,
      sym_identifier,
    ACTIONS(77), 1,
      sym_begin,
    STATE(62), 7,
      sym__statement,
      sym_assignment,
      sym_if_statement,
      sym_while_statement,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [1034] = 6,
    ACTIONS(69), 1,
      anon_sym_if,
    ACTIONS(71), 1,
      anon_sym_while,
    ACTIONS(73), 1,
      anon_sym_for,
    ACTIONS(75), 1,
      sym_identifier,
    ACTIONS(77), 1,
      sym_begin,
    STATE(60), 7,
      sym__statement,
      sym_assignment,
      sym_if_statement,
      sym_while_statement,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [1059] = 6,
    ACTIONS(69), 1,
      anon_sym_if,
    ACTIONS(71), 1,
      anon_sym_while,
    ACTIONS(73), 1,
      anon_sym_for,
    ACTIONS(75), 1,
      sym_identifier,
    ACTIONS(77), 1,
      sym_begin,
    STATE(66), 7,
      sym__statement,
      sym_assignment,
      sym_if_statement,
      sym_while_statement,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [1084] = 6,
    ACTIONS(69), 1,
      anon_sym_if,
    ACTIONS(71), 1,
      anon_sym_while,
    ACTIONS(73), 1,
      anon_sym_for,
    ACTIONS(75), 1,
      sym_identifier,
    ACTIONS(77), 1,
      sym_begin,
    STATE(67), 7,
      sym__statement,
      sym_assignment,
      sym_if_statement,
      sym_while_statement,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [1109] = 6,
    ACTIONS(69), 1,
      anon_sym_if,
    ACTIONS(71), 1,
      anon_sym_while,
    ACTIONS(73), 1,
      anon_sym_for,
    ACTIONS(75), 1,
      sym_identifier,
    ACTIONS(77), 1,
      sym_begin,
    STATE(72), 7,
      sym__statement,
      sym_assignment,
      sym_if_statement,
      sym_while_statement,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [1134] = 7,
    ACTIONS(99), 1,
      anon_sym_const,
    ACTIONS(101), 1,
      anon_sym_procedure,
    ACTIONS(103), 1,
      sym_begin,
    ACTIONS(105), 1,
      sym_var,
    STATE(95), 1,
      sym_mainblock,
    STATE(45), 2,
      sym_declarations_sequence,
      aux_sym_mainblock_repeat1,
    STATE(57), 3,
      sym_var_declarations,
      sym_const_declarations,
      sym_procedure_declatarions,
  [1159] = 7,
    ACTIONS(99), 1,
      anon_sym_const,
    ACTIONS(101), 1,
      anon_sym_procedure,
    ACTIONS(103), 1,
      sym_begin,
    ACTIONS(105), 1,
      sym_var,
    STATE(96), 1,
      sym_mainblock,
    STATE(45), 2,
      sym_declarations_sequence,
      aux_sym_mainblock_repeat1,
    STATE(57), 3,
      sym_var_declarations,
      sym_const_declarations,
      sym_procedure_declatarions,
  [1184] = 6,
    ACTIONS(107), 1,
      anon_sym_const,
    ACTIONS(110), 1,
      anon_sym_procedure,
    ACTIONS(113), 1,
      sym_begin,
    ACTIONS(115), 1,
      sym_var,
    STATE(44), 2,
      sym_declarations_sequence,
      aux_sym_mainblock_repeat1,
    STATE(57), 3,
      sym_var_declarations,
      sym_const_declarations,
      sym_procedure_declatarions,
  [1206] = 6,
    ACTIONS(99), 1,
      anon_sym_const,
    ACTIONS(101), 1,
      anon_sym_procedure,
    ACTIONS(105), 1,
      sym_var,
    ACTIONS(118), 1,
      sym_begin,
    STATE(44), 2,
      sym_declarations_sequence,
      aux_sym_mainblock_repeat1,
    STATE(57), 3,
      sym_var_declarations,
      sym_const_declarations,
      sym_procedure_declatarions,
  [1228] = 3,
    ACTIONS(122), 1,
      sym_identifier,
    STATE(50), 2,
      sym_const_declaration,
      aux_sym_const_declarations_repeat1,
    ACTIONS(120), 4,
      anon_sym_const,
      anon_sym_procedure,
      sym_begin,
      sym_var,
  [1242] = 3,
    ACTIONS(126), 1,
      sym_identifier,
    STATE(47), 2,
      sym_var_declaration,
      aux_sym_var_declarations_repeat1,
    ACTIONS(124), 4,
      anon_sym_const,
      anon_sym_procedure,
      sym_begin,
      sym_var,
  [1256] = 2,
    ACTIONS(131), 1,
      sym_left_paren,
    ACTIONS(129), 6,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT_EQ,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_COLON_EQ,
  [1268] = 3,
    ACTIONS(135), 1,
      sym_identifier,
    STATE(47), 2,
      sym_var_declaration,
      aux_sym_var_declarations_repeat1,
    ACTIONS(133), 4,
      anon_sym_const,
      anon_sym_procedure,
      sym_begin,
      sym_var,
  [1282] = 3,
    ACTIONS(139), 1,
      sym_identifier,
    STATE(50), 2,
      sym_const_declaration,
      aux_sym_const_declarations_repeat1,
    ACTIONS(137), 4,
      anon_sym_const,
      anon_sym_procedure,
      sym_begin,
      sym_var,
  [1296] = 2,
    STATE(85), 1,
      sym_type,
    ACTIONS(142), 4,
      anon_sym_boolean,
      anon_sym_integer,
      anon_sym_real,
      anon_sym_char,
  [1306] = 1,
    ACTIONS(144), 5,
      anon_sym_const,
      anon_sym_procedure,
      sym_identifier,
      sym_begin,
      sym_var,
  [1314] = 2,
    STATE(104), 1,
      sym_type,
    ACTIONS(142), 4,
      anon_sym_boolean,
      anon_sym_integer,
      anon_sym_real,
      anon_sym_char,
  [1324] = 1,
    ACTIONS(146), 5,
      anon_sym_const,
      anon_sym_procedure,
      sym_identifier,
      sym_begin,
      sym_var,
  [1332] = 5,
    ACTIONS(148), 1,
      anon_sym_,
    ACTIONS(150), 1,
      sym_right_paren,
    ACTIONS(152), 1,
      sym_var,
    STATE(82), 1,
      sym_formal_params_list,
    STATE(86), 1,
      sym_formal_params_sequence,
  [1348] = 2,
    STATE(105), 1,
      sym_type,
    ACTIONS(142), 4,
      anon_sym_boolean,
      anon_sym_integer,
      anon_sym_real,
      anon_sym_char,
  [1358] = 1,
    ACTIONS(154), 4,
      anon_sym_const,
      anon_sym_procedure,
      sym_begin,
      sym_var,
  [1365] = 1,
    ACTIONS(156), 4,
      anon_sym_const,
      anon_sym_procedure,
      sym_begin,
      sym_var,
  [1372] = 2,
    ACTIONS(158), 1,
      sym_identifier,
    STATE(49), 2,
      sym_var_declaration,
      aux_sym_var_declarations_repeat1,
  [1380] = 1,
    ACTIONS(160), 3,
      anon_sym_else,
      sym_semicolon,
      sym_end,
  [1386] = 3,
    ACTIONS(148), 1,
      anon_sym_,
    ACTIONS(152), 1,
      sym_var,
    STATE(87), 1,
      sym_formal_params_sequence,
  [1396] = 1,
    ACTIONS(162), 3,
      anon_sym_else,
      sym_semicolon,
      sym_end,
  [1402] = 3,
    ACTIONS(164), 1,
      anon_sym_,
    ACTIONS(166), 1,
      sym_comma,
    STATE(92), 1,
      sym_return,
  [1412] = 2,
    ACTIONS(168), 1,
      sym_identifier,
    STATE(46), 2,
      sym_const_declaration,
      aux_sym_const_declarations_repeat1,
  [1420] = 1,
    ACTIONS(170), 3,
      anon_sym_else,
      sym_semicolon,
      sym_end,
  [1426] = 1,
    ACTIONS(172), 3,
      anon_sym_else,
      sym_semicolon,
      sym_end,
  [1432] = 2,
    ACTIONS(174), 1,
      anon_sym_else,
    ACTIONS(176), 2,
      sym_semicolon,
      sym_end,
  [1440] = 1,
    ACTIONS(178), 3,
      anon_sym_else,
      sym_semicolon,
      sym_end,
  [1446] = 1,
    ACTIONS(180), 3,
      anon_sym_else,
      sym_semicolon,
      sym_end,
  [1452] = 2,
    ACTIONS(182), 1,
      anon_sym_,
    ACTIONS(184), 1,
      sym_comma,
  [1459] = 2,
    ACTIONS(186), 1,
      sym_semicolon,
    ACTIONS(188), 1,
      sym_end,
  [1466] = 1,
    ACTIONS(190), 2,
      sym_semicolon,
      sym_end,
  [1471] = 1,
    ACTIONS(192), 2,
      sym_semicolon,
      sym_right_paren,
  [1476] = 2,
    ACTIONS(194), 1,
      sym_identifier,
    STATE(77), 1,
      sym_identifier_list,
  [1483] = 1,
    ACTIONS(196), 2,
      sym_identifier,
      sym_dot,
  [1488] = 1,
    ACTIONS(198), 2,
      sym_colon,
      sym_comma,
  [1493] = 2,
    ACTIONS(200), 1,
      sym_colon,
    ACTIONS(202), 1,
      sym_comma,
  [1500] = 2,
    ACTIONS(186), 1,
      sym_semicolon,
    ACTIONS(204), 1,
      sym_end,
  [1507] = 2,
    ACTIONS(206), 1,
      anon_sym_,
    ACTIONS(208), 1,
      sym_comma,
  [1514] = 1,
    ACTIONS(210), 2,
      sym_identifier,
      sym_dot,
  [1519] = 2,
    ACTIONS(186), 1,
      sym_semicolon,
    ACTIONS(212), 1,
      sym_end,
  [1526] = 2,
    ACTIONS(214), 1,
      sym_semicolon,
    ACTIONS(216), 1,
      sym_right_paren,
  [1533] = 1,
    ACTIONS(218), 2,
      sym_colon,
      sym_comma,
  [1538] = 2,
    ACTIONS(220), 1,
      sym_left_paren,
    STATE(63), 1,
      sym_formal_params,
  [1545] = 1,
    ACTIONS(222), 2,
      sym_semicolon,
      sym_right_paren,
  [1550] = 1,
    ACTIONS(224), 2,
      sym_semicolon,
      sym_right_paren,
  [1555] = 1,
    ACTIONS(226), 2,
      sym_semicolon,
      sym_right_paren,
  [1560] = 1,
    ACTIONS(228), 2,
      sym_identifier,
      sym_dot,
  [1565] = 1,
    ACTIONS(230), 2,
      sym_semicolon,
      sym_end,
  [1570] = 1,
    ACTIONS(232), 1,
      anon_sym_COLON_EQ,
  [1574] = 1,
    ACTIONS(234), 1,
      sym_identifier,
  [1578] = 1,
    ACTIONS(236), 1,
      sym_semicolon,
  [1582] = 1,
    ACTIONS(238), 1,
      sym_identifier,
  [1586] = 1,
    ACTIONS(240), 1,
      ts_builtin_sym_end,
  [1590] = 1,
    ACTIONS(242), 1,
      sym_identifier,
  [1594] = 1,
    ACTIONS(244), 1,
      sym_dot,
  [1598] = 1,
    ACTIONS(246), 1,
      anon_sym_EQ,
  [1602] = 1,
    ACTIONS(248), 1,
      sym_right_paren,
  [1606] = 1,
    ACTIONS(250), 1,
      sym_colon,
  [1610] = 1,
    ACTIONS(252), 1,
      sym_identifier,
  [1614] = 1,
    ACTIONS(254), 1,
      sym_semicolon,
  [1618] = 1,
    ACTIONS(256), 1,
      sym_right_paren,
  [1622] = 1,
    ACTIONS(258), 1,
      sym_identifier,
  [1626] = 1,
    ACTIONS(260), 1,
      sym_semicolon,
  [1630] = 1,
    ACTIONS(262), 1,
      sym_semicolon,
  [1634] = 1,
    ACTIONS(264), 1,
      sym_semicolon,
  [1638] = 1,
    ACTIONS(266), 1,
      ts_builtin_sym_end,
  [1642] = 1,
    ACTIONS(268), 1,
      sym_semicolon,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 31,
  [SMALL_STATE(4)] = 58,
  [SMALL_STATE(5)] = 93,
  [SMALL_STATE(6)] = 120,
  [SMALL_STATE(7)] = 147,
  [SMALL_STATE(8)] = 176,
  [SMALL_STATE(9)] = 209,
  [SMALL_STATE(10)] = 239,
  [SMALL_STATE(11)] = 269,
  [SMALL_STATE(12)] = 299,
  [SMALL_STATE(13)] = 326,
  [SMALL_STATE(14)] = 353,
  [SMALL_STATE(15)] = 380,
  [SMALL_STATE(16)] = 407,
  [SMALL_STATE(17)] = 434,
  [SMALL_STATE(18)] = 461,
  [SMALL_STATE(19)] = 488,
  [SMALL_STATE(20)] = 515,
  [SMALL_STATE(21)] = 542,
  [SMALL_STATE(22)] = 569,
  [SMALL_STATE(23)] = 596,
  [SMALL_STATE(24)] = 623,
  [SMALL_STATE(25)] = 650,
  [SMALL_STATE(26)] = 681,
  [SMALL_STATE(27)] = 713,
  [SMALL_STATE(28)] = 744,
  [SMALL_STATE(29)] = 773,
  [SMALL_STATE(30)] = 804,
  [SMALL_STATE(31)] = 833,
  [SMALL_STATE(32)] = 862,
  [SMALL_STATE(33)] = 891,
  [SMALL_STATE(34)] = 922,
  [SMALL_STATE(35)] = 951,
  [SMALL_STATE(36)] = 980,
  [SMALL_STATE(37)] = 1009,
  [SMALL_STATE(38)] = 1034,
  [SMALL_STATE(39)] = 1059,
  [SMALL_STATE(40)] = 1084,
  [SMALL_STATE(41)] = 1109,
  [SMALL_STATE(42)] = 1134,
  [SMALL_STATE(43)] = 1159,
  [SMALL_STATE(44)] = 1184,
  [SMALL_STATE(45)] = 1206,
  [SMALL_STATE(46)] = 1228,
  [SMALL_STATE(47)] = 1242,
  [SMALL_STATE(48)] = 1256,
  [SMALL_STATE(49)] = 1268,
  [SMALL_STATE(50)] = 1282,
  [SMALL_STATE(51)] = 1296,
  [SMALL_STATE(52)] = 1306,
  [SMALL_STATE(53)] = 1314,
  [SMALL_STATE(54)] = 1324,
  [SMALL_STATE(55)] = 1332,
  [SMALL_STATE(56)] = 1348,
  [SMALL_STATE(57)] = 1358,
  [SMALL_STATE(58)] = 1365,
  [SMALL_STATE(59)] = 1372,
  [SMALL_STATE(60)] = 1380,
  [SMALL_STATE(61)] = 1386,
  [SMALL_STATE(62)] = 1396,
  [SMALL_STATE(63)] = 1402,
  [SMALL_STATE(64)] = 1412,
  [SMALL_STATE(65)] = 1420,
  [SMALL_STATE(66)] = 1426,
  [SMALL_STATE(67)] = 1432,
  [SMALL_STATE(68)] = 1440,
  [SMALL_STATE(69)] = 1446,
  [SMALL_STATE(70)] = 1452,
  [SMALL_STATE(71)] = 1459,
  [SMALL_STATE(72)] = 1466,
  [SMALL_STATE(73)] = 1471,
  [SMALL_STATE(74)] = 1476,
  [SMALL_STATE(75)] = 1483,
  [SMALL_STATE(76)] = 1488,
  [SMALL_STATE(77)] = 1493,
  [SMALL_STATE(78)] = 1500,
  [SMALL_STATE(79)] = 1507,
  [SMALL_STATE(80)] = 1514,
  [SMALL_STATE(81)] = 1519,
  [SMALL_STATE(82)] = 1526,
  [SMALL_STATE(83)] = 1533,
  [SMALL_STATE(84)] = 1538,
  [SMALL_STATE(85)] = 1545,
  [SMALL_STATE(86)] = 1550,
  [SMALL_STATE(87)] = 1555,
  [SMALL_STATE(88)] = 1560,
  [SMALL_STATE(89)] = 1565,
  [SMALL_STATE(90)] = 1570,
  [SMALL_STATE(91)] = 1574,
  [SMALL_STATE(92)] = 1578,
  [SMALL_STATE(93)] = 1582,
  [SMALL_STATE(94)] = 1586,
  [SMALL_STATE(95)] = 1590,
  [SMALL_STATE(96)] = 1594,
  [SMALL_STATE(97)] = 1598,
  [SMALL_STATE(98)] = 1602,
  [SMALL_STATE(99)] = 1606,
  [SMALL_STATE(100)] = 1610,
  [SMALL_STATE(101)] = 1614,
  [SMALL_STATE(102)] = 1618,
  [SMALL_STATE(103)] = 1622,
  [SMALL_STATE(104)] = 1626,
  [SMALL_STATE(105)] = 1630,
  [SMALL_STATE(106)] = 1634,
  [SMALL_STATE(107)] = 1638,
  [SMALL_STATE(108)] = 1642,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(13),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [11] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 3),
  [15] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression, 3),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [21] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [23] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_expression, 2),
  [25] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unary_expression, 2),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(26),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(28),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(36),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [49] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [55] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [57] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [59] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [61] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment, 3),
  [63] = {.entry = {.count = 1, .reusable = true}}, SHIFT(24),
  [65] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [67] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fact_params, 1),
  [69] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [71] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [73] = {.entry = {.count = 1, .reusable = false}}, SHIFT(100),
  [75] = {.entry = {.count = 1, .reusable = false}}, SHIFT(48),
  [77] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT(88),
  [81] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_const_expression, 1),
  [83] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [85] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [87] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [91] = {.entry = {.count = 1, .reusable = false}}, SHIFT(80),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(103),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [107] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_mainblock_repeat1, 2), SHIFT_REPEAT(64),
  [110] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_mainblock_repeat1, 2), SHIFT_REPEAT(103),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_mainblock_repeat1, 2),
  [115] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_mainblock_repeat1, 2), SHIFT_REPEAT(59),
  [118] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [120] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_const_declarations, 2),
  [122] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [124] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_var_declarations_repeat1, 2),
  [126] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_var_declarations_repeat1, 2), SHIFT_REPEAT(99),
  [129] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [131] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [133] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_declarations, 2),
  [135] = {.entry = {.count = 1, .reusable = false}}, SHIFT(99),
  [137] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_const_declarations_repeat1, 2),
  [139] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_const_declarations_repeat1, 2), SHIFT_REPEAT(97),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [144] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_declaration, 4),
  [146] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_const_declaration, 4),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(74),
  [150] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [152] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [154] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declarations_sequence, 1),
  [156] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_procedure_declatarions, 8),
  [158] = {.entry = {.count = 1, .reusable = true}}, SHIFT(99),
  [160] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_for_statement, 10),
  [162] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_statement, 4),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [166] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [170] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_statement, 2),
  [172] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_statement, 6),
  [174] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [176] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_statement, 4),
  [178] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_procedure_call_statement, 4),
  [180] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_statement, 3),
  [182] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formal_params, 3),
  [184] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_formal_params, 3),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [188] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [190] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement_sequence, 3),
  [192] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [194] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [196] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_mainblock, 4),
  [198] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier_list, 1),
  [200] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [202] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [204] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [206] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formal_params, 2),
  [208] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_formal_params, 2),
  [210] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_mainblock, 2),
  [212] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
  [214] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(70),
  [218] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_identifier_list, 3),
  [220] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [222] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formal_params_sequence, 4),
  [224] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formal_params_list, 1),
  [226] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_formal_params_list, 3),
  [228] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_mainblock, 3),
  [230] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_statement_sequence, 1),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [234] = {.entry = {.count = 1, .reusable = true}}, SHIFT(106),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [240] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 5),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(101),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [248] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fact_params, 3),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(90),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [256] = {.entry = {.count = 1, .reusable = true}}, SHIFT(68),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [260] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_return, 2),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [266] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
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
