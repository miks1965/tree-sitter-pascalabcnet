#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 12
#define STATE_COUNT 109
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 71
#define ALIAS_COUNT 0
#define TOKEN_COUNT 52
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 10

enum {
  anon_sym_Program = 1,
  anon_sym_var = 2,
  anon_sym_boolean = 3,
  anon_sym_integer = 4,
  anon_sym_real = 5,
  anon_sym_char = 6,
  anon_sym_if = 7,
  anon_sym_then = 8,
  anon_sym_else = 9,
  anon_sym_while = 10,
  anon_sym_do = 11,
  anon_sym_STAR_EQ = 12,
  anon_sym_SLASH_EQ = 13,
  anon_sym_PERCENT_EQ = 14,
  anon_sym_PLUS_EQ = 15,
  anon_sym_DASH_EQ = 16,
  anon_sym_COLON_EQ = 17,
  anon_sym_for = 18,
  anon_sym_to = 19,
  anon_sym_step = 20,
  anon_sym_PLUS = 21,
  anon_sym_DASH = 22,
  anon_sym_BANG = 23,
  anon_sym_CARET = 24,
  anon_sym_STAR = 25,
  anon_sym_AMP = 26,
  anon_sym_LT_DASH = 27,
  anon_sym_SLASH = 28,
  anon_sym_PERCENT = 29,
  anon_sym_EQ = 30,
  anon_sym_LT_GT = 31,
  anon_sym_LT = 32,
  anon_sym_LT_EQ = 33,
  anon_sym_GT = 34,
  anon_sym_GT_EQ = 35,
  anon_sym_and = 36,
  anon_sym_or = 37,
  sym_identifier = 38,
  sym_integer = 39,
  sym_real = 40,
  sym_char = 41,
  sym_semicolon = 42,
  sym_colon = 43,
  sym_dot = 44,
  sym_comma = 45,
  sym_left_paren = 46,
  sym_right_paren = 47,
  sym_true = 48,
  sym_false = 49,
  sym_begin = 50,
  sym_end = 51,
  sym_module = 52,
  sym_mainblock = 53,
  sym_declarations = 54,
  sym_var_declarations = 55,
  sym_type = 56,
  sym__statement = 57,
  sym_if_statement = 58,
  sym_while_statement = 59,
  sym_assignment = 60,
  sym_for_statement = 61,
  sym_block_statement = 62,
  sym_procedure_call_statement = 63,
  sym_fact_params = 64,
  sym__expression = 65,
  sym_unary_expression = 66,
  sym_binary_expression = 67,
  sym__number = 68,
  aux_sym_var_declarations_repeat1 = 69,
  aux_sym_block_statement_repeat1 = 70,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_Program] = "Program",
  [anon_sym_var] = "var",
  [anon_sym_boolean] = "boolean",
  [anon_sym_integer] = "integer",
  [anon_sym_real] = "real",
  [anon_sym_char] = "char",
  [anon_sym_if] = "if",
  [anon_sym_then] = "then",
  [anon_sym_else] = "else",
  [anon_sym_while] = "while",
  [anon_sym_do] = "do",
  [anon_sym_STAR_EQ] = "*=",
  [anon_sym_SLASH_EQ] = "/=",
  [anon_sym_PERCENT_EQ] = "%=",
  [anon_sym_PLUS_EQ] = "+=",
  [anon_sym_DASH_EQ] = "-=",
  [anon_sym_COLON_EQ] = ":=",
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
  [anon_sym_EQ] = "=",
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
  [sym_module] = "module",
  [sym_mainblock] = "mainblock",
  [sym_declarations] = "declarations",
  [sym_var_declarations] = "var_declarations",
  [sym_type] = "type",
  [sym__statement] = "_statement",
  [sym_if_statement] = "if_statement",
  [sym_while_statement] = "while_statement",
  [sym_assignment] = "assignment",
  [sym_for_statement] = "for_statement",
  [sym_block_statement] = "block_statement",
  [sym_procedure_call_statement] = "procedure_call_statement",
  [sym_fact_params] = "fact_params",
  [sym__expression] = "_expression",
  [sym_unary_expression] = "unary_expression",
  [sym_binary_expression] = "binary_expression",
  [sym__number] = "_number",
  [aux_sym_var_declarations_repeat1] = "var_declarations_repeat1",
  [aux_sym_block_statement_repeat1] = "block_statement_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_Program] = anon_sym_Program,
  [anon_sym_var] = anon_sym_var,
  [anon_sym_boolean] = anon_sym_boolean,
  [anon_sym_integer] = anon_sym_integer,
  [anon_sym_real] = anon_sym_real,
  [anon_sym_char] = anon_sym_char,
  [anon_sym_if] = anon_sym_if,
  [anon_sym_then] = anon_sym_then,
  [anon_sym_else] = anon_sym_else,
  [anon_sym_while] = anon_sym_while,
  [anon_sym_do] = anon_sym_do,
  [anon_sym_STAR_EQ] = anon_sym_STAR_EQ,
  [anon_sym_SLASH_EQ] = anon_sym_SLASH_EQ,
  [anon_sym_PERCENT_EQ] = anon_sym_PERCENT_EQ,
  [anon_sym_PLUS_EQ] = anon_sym_PLUS_EQ,
  [anon_sym_DASH_EQ] = anon_sym_DASH_EQ,
  [anon_sym_COLON_EQ] = anon_sym_COLON_EQ,
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
  [anon_sym_EQ] = anon_sym_EQ,
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
  [sym_module] = sym_module,
  [sym_mainblock] = sym_mainblock,
  [sym_declarations] = sym_declarations,
  [sym_var_declarations] = sym_var_declarations,
  [sym_type] = sym_type,
  [sym__statement] = sym__statement,
  [sym_if_statement] = sym_if_statement,
  [sym_while_statement] = sym_while_statement,
  [sym_assignment] = sym_assignment,
  [sym_for_statement] = sym_for_statement,
  [sym_block_statement] = sym_block_statement,
  [sym_procedure_call_statement] = sym_procedure_call_statement,
  [sym_fact_params] = sym_fact_params,
  [sym__expression] = sym__expression,
  [sym_unary_expression] = sym_unary_expression,
  [sym_binary_expression] = sym_binary_expression,
  [sym__number] = sym__number,
  [aux_sym_var_declarations_repeat1] = aux_sym_var_declarations_repeat1,
  [aux_sym_block_statement_repeat1] = aux_sym_block_statement_repeat1,
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
  [anon_sym_var] = {
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
  [anon_sym_EQ] = {
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
  [sym_var_declarations] = {
    .visible = true,
    .named = true,
  },
  [sym_type] = {
    .visible = true,
    .named = true,
  },
  [sym__statement] = {
    .visible = false,
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
  [sym_assignment] = {
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
  [aux_sym_var_declarations_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_block_statement_repeat1] = {
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
      if (eof) ADVANCE(68);
      if (lookahead == '!') ADVANCE(94);
      if (lookahead == '%') ADVANCE(100);
      if (lookahead == '&') ADVANCE(97);
      if (lookahead == '(') ADVANCE(145);
      if (lookahead == ')') ADVANCE(146);
      if (lookahead == '*') ADVANCE(96);
      if (lookahead == '+') ADVANCE(92);
      if (lookahead == ',') ADVANCE(144);
      if (lookahead == '-') ADVANCE(93);
      if (lookahead == '.') ADVANCE(143);
      if (lookahead == '/') ADVANCE(99);
      if (lookahead == ':') ADVANCE(142);
      if (lookahead == ';') ADVANCE(140);
      if (lookahead == '<') ADVANCE(103);
      if (lookahead == '=') ADVANCE(101);
      if (lookahead == '>') ADVANCE(105);
      if (lookahead == 'P') ADVANCE(60);
      if (lookahead == '^') ADVANCE(95);
      if (lookahead == 'a') ADVANCE(47);
      if (lookahead == 'b') ADVANCE(21);
      if (lookahead == 'c') ADVANCE(38);
      if (lookahead == 'd') ADVANCE(51);
      if (lookahead == 'e') ADVANCE(41);
      if (lookahead == 'f') ADVANCE(11);
      if (lookahead == 'i') ADVANCE(32);
      if (lookahead == 'o') ADVANCE(55);
      if (lookahead == 'r') ADVANCE(28);
      if (lookahead == 's') ADVANCE(64);
      if (lookahead == 't') ADVANCE(37);
      if (lookahead == 'v') ADVANCE(14);
      if (lookahead == 'w') ADVANCE(36);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(135);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(1)
      if (lookahead == '!') ADVANCE(94);
      if (lookahead == '&') ADVANCE(97);
      if (lookahead == '*') ADVANCE(96);
      if (lookahead == '+') ADVANCE(92);
      if (lookahead == '-') ADVANCE(93);
      if (lookahead == '<') ADVANCE(139);
      if (lookahead == '^') ADVANCE(95);
      if (lookahead == 'f') ADVANCE(111);
      if (lookahead == 't') ADVANCE(131);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(135);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(137);
      END_STATE();
    case 2:
      if (lookahead == '%') ADVANCE(100);
      if (lookahead == '*') ADVANCE(96);
      if (lookahead == '+') ADVANCE(92);
      if (lookahead == '-') ADVANCE(93);
      if (lookahead == '/') ADVANCE(99);
      if (lookahead == ':') ADVANCE(5);
      if (lookahead == '<') ADVANCE(103);
      if (lookahead == '=') ADVANCE(101);
      if (lookahead == '>') ADVANCE(105);
      if (lookahead == 'a') ADVANCE(125);
      if (lookahead == 'b') ADVANCE(114);
      if (lookahead == 'e') ADVANCE(127);
      if (lookahead == 'f') ADVANCE(128);
      if (lookahead == 'i') ADVANCE(118);
      if (lookahead == 'o') ADVANCE(129);
      if (lookahead == 'w') ADVANCE(120);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('c' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 3:
      if (lookahead == '%') ADVANCE(6);
      if (lookahead == '(') ADVANCE(145);
      if (lookahead == '*') ADVANCE(7);
      if (lookahead == '+') ADVANCE(8);
      if (lookahead == '-') ADVANCE(9);
      if (lookahead == '/') ADVANCE(10);
      if (lookahead == ':') ADVANCE(5);
      if (lookahead == 'b') ADVANCE(114);
      if (lookahead == 'e') ADVANCE(127);
      if (lookahead == 'f') ADVANCE(128);
      if (lookahead == 'i') ADVANCE(118);
      if (lookahead == 'w') ADVANCE(120);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 4:
      if (lookahead == ':') ADVANCE(141);
      if (lookahead == 'b') ADVANCE(114);
      if (lookahead == 'f') ADVANCE(128);
      if (lookahead == 'i') ADVANCE(118);
      if (lookahead == 'w') ADVANCE(120);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(4)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 5:
      if (lookahead == '=') ADVANCE(87);
      END_STATE();
    case 6:
      if (lookahead == '=') ADVANCE(84);
      END_STATE();
    case 7:
      if (lookahead == '=') ADVANCE(82);
      END_STATE();
    case 8:
      if (lookahead == '=') ADVANCE(85);
      END_STATE();
    case 9:
      if (lookahead == '=') ADVANCE(86);
      END_STATE();
    case 10:
      if (lookahead == '=') ADVANCE(83);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(45);
      if (lookahead == 'o') ADVANCE(56);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(46);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(42);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(57);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(50);
      END_STATE();
    case 16:
      if (lookahead == 'a') ADVANCE(58);
      END_STATE();
    case 17:
      if (lookahead == 'b') ADVANCE(114);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(17)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 18:
      if (lookahead == 'd') ADVANCE(107);
      END_STATE();
    case 19:
      if (lookahead == 'd') ADVANCE(153);
      END_STATE();
    case 20:
      if (lookahead == 'd') ADVANCE(136);
      END_STATE();
    case 21:
      if (lookahead == 'e') ADVANCE(33);
      if (lookahead == 'o') ADVANCE(53);
      END_STATE();
    case 22:
      if (lookahead == 'e') ADVANCE(54);
      END_STATE();
    case 23:
      if (lookahead == 'e') ADVANCE(78);
      END_STATE();
    case 24:
      if (lookahead == 'e') ADVANCE(147);
      END_STATE();
    case 25:
      if (lookahead == 'e') ADVANCE(149);
      END_STATE();
    case 26:
      if (lookahead == 'e') ADVANCE(79);
      END_STATE();
    case 27:
      if (lookahead == 'e') ADVANCE(48);
      END_STATE();
    case 28:
      if (lookahead == 'e') ADVANCE(13);
      END_STATE();
    case 29:
      if (lookahead == 'e') ADVANCE(35);
      END_STATE();
    case 30:
      if (lookahead == 'e') ADVANCE(15);
      END_STATE();
    case 31:
      if (lookahead == 'e') ADVANCE(59);
      END_STATE();
    case 32:
      if (lookahead == 'f') ADVANCE(75);
      if (lookahead == 'n') ADVANCE(65);
      END_STATE();
    case 33:
      if (lookahead == 'g') ADVANCE(39);
      END_STATE();
    case 34:
      if (lookahead == 'g') ADVANCE(61);
      END_STATE();
    case 35:
      if (lookahead == 'g') ADVANCE(31);
      END_STATE();
    case 36:
      if (lookahead == 'h') ADVANCE(40);
      END_STATE();
    case 37:
      if (lookahead == 'h') ADVANCE(27);
      if (lookahead == 'o') ADVANCE(90);
      if (lookahead == 'r') ADVANCE(66);
      END_STATE();
    case 38:
      if (lookahead == 'h') ADVANCE(16);
      END_STATE();
    case 39:
      if (lookahead == 'i') ADVANCE(49);
      END_STATE();
    case 40:
      if (lookahead == 'i') ADVANCE(43);
      END_STATE();
    case 41:
      if (lookahead == 'l') ADVANCE(62);
      if (lookahead == 'n') ADVANCE(19);
      END_STATE();
    case 42:
      if (lookahead == 'l') ADVANCE(73);
      END_STATE();
    case 43:
      if (lookahead == 'l') ADVANCE(26);
      END_STATE();
    case 44:
      if (lookahead == 'l') ADVANCE(30);
      END_STATE();
    case 45:
      if (lookahead == 'l') ADVANCE(63);
      END_STATE();
    case 46:
      if (lookahead == 'm') ADVANCE(69);
      END_STATE();
    case 47:
      if (lookahead == 'n') ADVANCE(18);
      END_STATE();
    case 48:
      if (lookahead == 'n') ADVANCE(77);
      END_STATE();
    case 49:
      if (lookahead == 'n') ADVANCE(151);
      END_STATE();
    case 50:
      if (lookahead == 'n') ADVANCE(71);
      END_STATE();
    case 51:
      if (lookahead == 'o') ADVANCE(81);
      END_STATE();
    case 52:
      if (lookahead == 'o') ADVANCE(34);
      END_STATE();
    case 53:
      if (lookahead == 'o') ADVANCE(44);
      END_STATE();
    case 54:
      if (lookahead == 'p') ADVANCE(91);
      END_STATE();
    case 55:
      if (lookahead == 'r') ADVANCE(109);
      END_STATE();
    case 56:
      if (lookahead == 'r') ADVANCE(88);
      END_STATE();
    case 57:
      if (lookahead == 'r') ADVANCE(70);
      END_STATE();
    case 58:
      if (lookahead == 'r') ADVANCE(74);
      END_STATE();
    case 59:
      if (lookahead == 'r') ADVANCE(72);
      END_STATE();
    case 60:
      if (lookahead == 'r') ADVANCE(52);
      END_STATE();
    case 61:
      if (lookahead == 'r') ADVANCE(12);
      END_STATE();
    case 62:
      if (lookahead == 's') ADVANCE(23);
      END_STATE();
    case 63:
      if (lookahead == 's') ADVANCE(25);
      END_STATE();
    case 64:
      if (lookahead == 't') ADVANCE(22);
      END_STATE();
    case 65:
      if (lookahead == 't') ADVANCE(29);
      END_STATE();
    case 66:
      if (lookahead == 'u') ADVANCE(24);
      END_STATE();
    case 67:
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(67)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_Program);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_var);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_boolean);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_integer);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_real);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_char);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_if);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_if);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_then);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_else);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_while);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_while);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_do);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(anon_sym_STAR_EQ);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_SLASH_EQ);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_PERCENT_EQ);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(anon_sym_PLUS_EQ);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_DASH_EQ);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(anon_sym_COLON_EQ);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(anon_sym_for);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(anon_sym_for);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(anon_sym_to);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(anon_sym_step);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(anon_sym_CARET);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(anon_sym_AMP);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(anon_sym_LT_DASH);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(anon_sym_LT_GT);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(104);
      if (lookahead == '>') ADVANCE(102);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(106);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(anon_sym_and);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(anon_sym_and);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(anon_sym_or);
      END_STATE();
    case 110:
      ACCEPT_TOKEN(anon_sym_or);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 111:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(123);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 112:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(108);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 113:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(154);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 114:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(119);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 115:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(80);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 116:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(148);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 117:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(150);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 118:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'f') ADVANCE(76);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 119:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(122);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 120:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h') ADVANCE(121);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 121:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(124);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 122:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(126);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 123:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(132);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 124:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(115);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 125:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(112);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 126:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(152);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 127:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(113);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 128:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(130);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 129:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(110);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 130:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(89);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 131:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(133);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 132:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(117);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 133:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(116);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 134:
      ACCEPT_TOKEN(sym_identifier);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 135:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == ',') ADVANCE(20);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(135);
      END_STATE();
    case 136:
      ACCEPT_TOKEN(sym_real);
      if (lookahead == 'd') ADVANCE(136);
      END_STATE();
    case 137:
      ACCEPT_TOKEN(sym_char);
      END_STATE();
    case 138:
      ACCEPT_TOKEN(sym_char);
      if (lookahead == '!') ADVANCE(94);
      if (lookahead == '&') ADVANCE(97);
      if (lookahead == '*') ADVANCE(96);
      if (lookahead == '+') ADVANCE(92);
      if (lookahead == '-') ADVANCE(93);
      if (lookahead == '<') ADVANCE(139);
      if (lookahead == '^') ADVANCE(95);
      if (lookahead == 'f') ADVANCE(111);
      if (lookahead == 't') ADVANCE(131);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(138);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(135);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'') ADVANCE(137);
      END_STATE();
    case 139:
      ACCEPT_TOKEN(sym_char);
      if (lookahead == '-') ADVANCE(98);
      END_STATE();
    case 140:
      ACCEPT_TOKEN(sym_semicolon);
      END_STATE();
    case 141:
      ACCEPT_TOKEN(sym_colon);
      END_STATE();
    case 142:
      ACCEPT_TOKEN(sym_colon);
      if (lookahead == '=') ADVANCE(87);
      END_STATE();
    case 143:
      ACCEPT_TOKEN(sym_dot);
      END_STATE();
    case 144:
      ACCEPT_TOKEN(sym_comma);
      END_STATE();
    case 145:
      ACCEPT_TOKEN(sym_left_paren);
      END_STATE();
    case 146:
      ACCEPT_TOKEN(sym_right_paren);
      END_STATE();
    case 147:
      ACCEPT_TOKEN(sym_true);
      END_STATE();
    case 148:
      ACCEPT_TOKEN(sym_true);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 149:
      ACCEPT_TOKEN(sym_false);
      END_STATE();
    case 150:
      ACCEPT_TOKEN(sym_false);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 151:
      ACCEPT_TOKEN(sym_begin);
      END_STATE();
    case 152:
      ACCEPT_TOKEN(sym_begin);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
      END_STATE();
    case 153:
      ACCEPT_TOKEN(sym_end);
      END_STATE();
    case 154:
      ACCEPT_TOKEN(sym_end);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(134);
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
  [8] = {.lex_state = 2},
  [9] = {.lex_state = 2},
  [10] = {.lex_state = 2},
  [11] = {.lex_state = 2},
  [12] = {.lex_state = 2},
  [13] = {.lex_state = 2},
  [14] = {.lex_state = 2},
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
  [26] = {.lex_state = 1},
  [27] = {.lex_state = 1},
  [28] = {.lex_state = 1},
  [29] = {.lex_state = 1},
  [30] = {.lex_state = 1},
  [31] = {.lex_state = 1},
  [32] = {.lex_state = 1},
  [33] = {.lex_state = 1},
  [34] = {.lex_state = 1},
  [35] = {.lex_state = 1},
  [36] = {.lex_state = 1},
  [37] = {.lex_state = 1},
  [38] = {.lex_state = 1},
  [39] = {.lex_state = 1},
  [40] = {.lex_state = 1},
  [41] = {.lex_state = 1},
  [42] = {.lex_state = 0},
  [43] = {.lex_state = 0},
  [44] = {.lex_state = 0},
  [45] = {.lex_state = 3},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 0},
  [48] = {.lex_state = 3},
  [49] = {.lex_state = 0},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 0},
  [52] = {.lex_state = 3},
  [53] = {.lex_state = 0},
  [54] = {.lex_state = 0},
  [55] = {.lex_state = 0},
  [56] = {.lex_state = 0},
  [57] = {.lex_state = 3},
  [58] = {.lex_state = 3},
  [59] = {.lex_state = 4},
  [60] = {.lex_state = 4},
  [61] = {.lex_state = 4},
  [62] = {.lex_state = 4},
  [63] = {.lex_state = 4},
  [64] = {.lex_state = 4},
  [65] = {.lex_state = 4},
  [66] = {.lex_state = 4},
  [67] = {.lex_state = 4},
  [68] = {.lex_state = 3},
  [69] = {.lex_state = 3},
  [70] = {.lex_state = 3},
  [71] = {.lex_state = 3},
  [72] = {.lex_state = 3},
  [73] = {.lex_state = 3},
  [74] = {.lex_state = 3},
  [75] = {.lex_state = 3},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 17},
  [79] = {.lex_state = 17},
  [80] = {.lex_state = 17},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 17},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 67},
  [90] = {.lex_state = 0},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 67},
  [94] = {.lex_state = 0},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 2},
  [98] = {.lex_state = 0},
  [99] = {.lex_state = 0},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 4},
  [102] = {.lex_state = 0},
  [103] = {.lex_state = 0},
  [104] = {.lex_state = 0},
  [105] = {.lex_state = 0},
  [106] = {.lex_state = 0},
  [107] = {.lex_state = 2},
  [108] = {.lex_state = 67},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_Program] = ACTIONS(1),
    [anon_sym_var] = ACTIONS(1),
    [anon_sym_boolean] = ACTIONS(1),
    [anon_sym_integer] = ACTIONS(1),
    [anon_sym_real] = ACTIONS(1),
    [anon_sym_char] = ACTIONS(1),
    [anon_sym_if] = ACTIONS(1),
    [anon_sym_then] = ACTIONS(1),
    [anon_sym_else] = ACTIONS(1),
    [anon_sym_while] = ACTIONS(1),
    [anon_sym_do] = ACTIONS(1),
    [anon_sym_COLON_EQ] = ACTIONS(1),
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
    [anon_sym_EQ] = ACTIONS(1),
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
  },
  [1] = {
    [sym_module] = STATE(106),
    [anon_sym_Program] = ACTIONS(3),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 2,
    ACTIONS(7), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(5), 19,
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
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_and,
      anon_sym_or,
      sym_comma,
      sym_right_paren,
      sym_end,
  [26] = 3,
    ACTIONS(7), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(5), 16,
      anon_sym_then,
      anon_sym_else,
      anon_sym_do,
      anon_sym_to,
      anon_sym_step,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_and,
      anon_sym_or,
      sym_comma,
      sym_right_paren,
      sym_end,
  [54] = 6,
    ACTIONS(17), 1,
      anon_sym_and,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(13), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(5), 9,
      anon_sym_then,
      anon_sym_else,
      anon_sym_do,
      anon_sym_to,
      anon_sym_step,
      anon_sym_or,
      sym_comma,
      sym_right_paren,
      sym_end,
  [88] = 2,
    ACTIONS(21), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(19), 19,
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
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_and,
      anon_sym_or,
      sym_comma,
      sym_right_paren,
      sym_end,
  [114] = 5,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(13), 4,
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
      anon_sym_and,
      anon_sym_or,
      sym_comma,
      sym_right_paren,
      sym_end,
  [146] = 4,
    ACTIONS(7), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(5), 14,
      anon_sym_then,
      anon_sym_else,
      anon_sym_do,
      anon_sym_to,
      anon_sym_step,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_and,
      anon_sym_or,
      sym_comma,
      sym_right_paren,
      sym_end,
  [176] = 4,
    ACTIONS(23), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(25), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(5), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(7), 10,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_and,
      anon_sym_or,
      sym_identifier,
      sym_begin,
      sym_end,
  [204] = 2,
    ACTIONS(19), 9,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(21), 10,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_and,
      anon_sym_or,
      sym_identifier,
      sym_begin,
      sym_end,
  [228] = 6,
    ACTIONS(31), 1,
      anon_sym_and,
    ACTIONS(23), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(29), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(25), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(27), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(7), 7,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      anon_sym_or,
      sym_identifier,
      sym_begin,
      sym_end,
  [260] = 5,
    ACTIONS(23), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(29), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(25), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(27), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(7), 8,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      anon_sym_and,
      anon_sym_or,
      sym_identifier,
      sym_begin,
      sym_end,
  [290] = 2,
    ACTIONS(5), 9,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(7), 10,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_and,
      anon_sym_or,
      sym_identifier,
      sym_begin,
      sym_end,
  [314] = 3,
    ACTIONS(25), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(5), 6,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(7), 10,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      anon_sym_LT,
      anon_sym_GT,
      anon_sym_and,
      anon_sym_or,
      sym_identifier,
      sym_begin,
      sym_end,
  [340] = 7,
    ACTIONS(31), 1,
      anon_sym_and,
    ACTIONS(35), 1,
      anon_sym_or,
    ACTIONS(23), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(29), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(25), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(27), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
    ACTIONS(33), 6,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      sym_identifier,
      sym_begin,
      sym_end,
  [374] = 4,
    STATE(92), 1,
      sym_fact_params,
    STATE(42), 4,
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
    ACTIONS(37), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [401] = 4,
    STATE(91), 1,
      sym_fact_params,
    STATE(42), 4,
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
    ACTIONS(37), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [428] = 4,
    STATE(102), 1,
      sym_fact_params,
    STATE(42), 4,
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
    ACTIONS(37), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [455] = 3,
    STATE(51), 4,
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
    ACTIONS(37), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [479] = 3,
    STATE(2), 4,
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
    ACTIONS(37), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [503] = 3,
    STATE(8), 4,
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
    ACTIONS(45), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [527] = 3,
    STATE(12), 4,
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
    ACTIONS(45), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [551] = 3,
    STATE(13), 4,
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
    ACTIONS(45), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [575] = 3,
    STATE(14), 4,
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
    ACTIONS(45), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [599] = 3,
    STATE(5), 4,
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
    ACTIONS(37), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [623] = 3,
    STATE(9), 4,
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
    ACTIONS(45), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [647] = 3,
    STATE(46), 4,
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
    ACTIONS(37), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [671] = 3,
    STATE(56), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(61), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(37), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [695] = 3,
    STATE(43), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(63), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(37), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [719] = 3,
    STATE(10), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(65), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(45), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [743] = 3,
    STATE(44), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(67), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(37), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [767] = 3,
    STATE(55), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(69), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(37), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [791] = 3,
    STATE(49), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(71), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(37), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [815] = 3,
    STATE(54), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(73), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(37), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [839] = 3,
    STATE(53), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(75), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(37), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [863] = 3,
    STATE(50), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(77), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(37), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [887] = 3,
    STATE(3), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(79), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(37), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [911] = 3,
    STATE(11), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(81), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(45), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [935] = 3,
    STATE(7), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(83), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(37), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [959] = 3,
    STATE(6), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(85), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(37), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [983] = 3,
    STATE(4), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(87), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(37), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [1007] = 3,
    STATE(47), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(89), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(37), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [1031] = 8,
    ACTIONS(17), 1,
      anon_sym_and,
    ACTIONS(91), 1,
      anon_sym_or,
    ACTIONS(93), 1,
      sym_comma,
    ACTIONS(95), 1,
      sym_right_paren,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(13), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [1063] = 7,
    ACTIONS(17), 1,
      anon_sym_and,
    ACTIONS(91), 1,
      anon_sym_or,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(97), 2,
      anon_sym_else,
      sym_end,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(13), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [1093] = 7,
    ACTIONS(17), 1,
      anon_sym_and,
    ACTIONS(91), 1,
      anon_sym_or,
    ACTIONS(99), 1,
      anon_sym_do,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(13), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [1122] = 7,
    ACTIONS(101), 1,
      anon_sym_if,
    ACTIONS(103), 1,
      anon_sym_while,
    ACTIONS(105), 1,
      anon_sym_for,
    ACTIONS(107), 1,
      sym_identifier,
    ACTIONS(109), 1,
      sym_begin,
    ACTIONS(111), 1,
      sym_end,
    STATE(58), 8,
      sym__statement,
      sym_if_statement,
      sym_while_statement,
      sym_assignment,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
      aux_sym_block_statement_repeat1,
  [1151] = 7,
    ACTIONS(17), 1,
      anon_sym_and,
    ACTIONS(91), 1,
      anon_sym_or,
    ACTIONS(113), 1,
      anon_sym_to,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(13), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [1180] = 7,
    ACTIONS(17), 1,
      anon_sym_and,
    ACTIONS(91), 1,
      anon_sym_or,
    ACTIONS(115), 1,
      anon_sym_step,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(13), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [1209] = 7,
    ACTIONS(101), 1,
      anon_sym_if,
    ACTIONS(103), 1,
      anon_sym_while,
    ACTIONS(105), 1,
      anon_sym_for,
    ACTIONS(107), 1,
      sym_identifier,
    ACTIONS(109), 1,
      sym_begin,
    ACTIONS(117), 1,
      sym_end,
    STATE(52), 8,
      sym__statement,
      sym_if_statement,
      sym_while_statement,
      sym_assignment,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
      aux_sym_block_statement_repeat1,
  [1238] = 7,
    ACTIONS(17), 1,
      anon_sym_and,
    ACTIONS(91), 1,
      anon_sym_or,
    ACTIONS(119), 1,
      anon_sym_then,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(13), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [1267] = 7,
    ACTIONS(17), 1,
      anon_sym_and,
    ACTIONS(91), 1,
      anon_sym_or,
    ACTIONS(121), 1,
      anon_sym_then,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(13), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [1296] = 7,
    ACTIONS(17), 1,
      anon_sym_and,
    ACTIONS(91), 1,
      anon_sym_or,
    ACTIONS(123), 1,
      anon_sym_do,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(13), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [1325] = 7,
    ACTIONS(125), 1,
      anon_sym_if,
    ACTIONS(128), 1,
      anon_sym_while,
    ACTIONS(131), 1,
      anon_sym_for,
    ACTIONS(134), 1,
      sym_identifier,
    ACTIONS(137), 1,
      sym_begin,
    ACTIONS(140), 1,
      sym_end,
    STATE(52), 8,
      sym__statement,
      sym_if_statement,
      sym_while_statement,
      sym_assignment,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
      aux_sym_block_statement_repeat1,
  [1354] = 7,
    ACTIONS(17), 1,
      anon_sym_and,
    ACTIONS(91), 1,
      anon_sym_or,
    ACTIONS(142), 1,
      anon_sym_do,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(13), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [1383] = 7,
    ACTIONS(17), 1,
      anon_sym_and,
    ACTIONS(91), 1,
      anon_sym_or,
    ACTIONS(144), 1,
      anon_sym_do,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(13), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [1412] = 7,
    ACTIONS(17), 1,
      anon_sym_and,
    ACTIONS(91), 1,
      anon_sym_or,
    ACTIONS(146), 1,
      anon_sym_to,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(13), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [1441] = 7,
    ACTIONS(17), 1,
      anon_sym_and,
    ACTIONS(91), 1,
      anon_sym_or,
    ACTIONS(148), 1,
      anon_sym_step,
    ACTIONS(11), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(15), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(9), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(13), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [1470] = 7,
    ACTIONS(101), 1,
      anon_sym_if,
    ACTIONS(103), 1,
      anon_sym_while,
    ACTIONS(105), 1,
      anon_sym_for,
    ACTIONS(107), 1,
      sym_identifier,
    ACTIONS(109), 1,
      sym_begin,
    ACTIONS(150), 1,
      sym_end,
    STATE(48), 8,
      sym__statement,
      sym_if_statement,
      sym_while_statement,
      sym_assignment,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
      aux_sym_block_statement_repeat1,
  [1499] = 7,
    ACTIONS(101), 1,
      anon_sym_if,
    ACTIONS(103), 1,
      anon_sym_while,
    ACTIONS(105), 1,
      anon_sym_for,
    ACTIONS(107), 1,
      sym_identifier,
    ACTIONS(109), 1,
      sym_begin,
    ACTIONS(152), 1,
      sym_end,
    STATE(52), 8,
      sym__statement,
      sym_if_statement,
      sym_while_statement,
      sym_assignment,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
      aux_sym_block_statement_repeat1,
  [1528] = 6,
    ACTIONS(101), 1,
      anon_sym_if,
    ACTIONS(103), 1,
      anon_sym_while,
    ACTIONS(105), 1,
      anon_sym_for,
    ACTIONS(107), 1,
      sym_identifier,
    ACTIONS(109), 1,
      sym_begin,
    STATE(75), 7,
      sym__statement,
      sym_if_statement,
      sym_while_statement,
      sym_assignment,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [1553] = 6,
    ACTIONS(154), 1,
      anon_sym_if,
    ACTIONS(156), 1,
      anon_sym_while,
    ACTIONS(158), 1,
      anon_sym_for,
    ACTIONS(160), 1,
      sym_identifier,
    ACTIONS(162), 1,
      sym_begin,
    STATE(81), 7,
      sym__statement,
      sym_if_statement,
      sym_while_statement,
      sym_assignment,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [1578] = 6,
    ACTIONS(101), 1,
      anon_sym_if,
    ACTIONS(103), 1,
      anon_sym_while,
    ACTIONS(105), 1,
      anon_sym_for,
    ACTIONS(107), 1,
      sym_identifier,
    ACTIONS(109), 1,
      sym_begin,
    STATE(72), 7,
      sym__statement,
      sym_if_statement,
      sym_while_statement,
      sym_assignment,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [1603] = 6,
    ACTIONS(154), 1,
      anon_sym_if,
    ACTIONS(156), 1,
      anon_sym_while,
    ACTIONS(158), 1,
      anon_sym_for,
    ACTIONS(160), 1,
      sym_identifier,
    ACTIONS(162), 1,
      sym_begin,
    STATE(99), 7,
      sym__statement,
      sym_if_statement,
      sym_while_statement,
      sym_assignment,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [1628] = 6,
    ACTIONS(101), 1,
      anon_sym_if,
    ACTIONS(103), 1,
      anon_sym_while,
    ACTIONS(105), 1,
      anon_sym_for,
    ACTIONS(107), 1,
      sym_identifier,
    ACTIONS(109), 1,
      sym_begin,
    STATE(71), 7,
      sym__statement,
      sym_if_statement,
      sym_while_statement,
      sym_assignment,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [1653] = 6,
    ACTIONS(154), 1,
      anon_sym_if,
    ACTIONS(156), 1,
      anon_sym_while,
    ACTIONS(158), 1,
      anon_sym_for,
    ACTIONS(160), 1,
      sym_identifier,
    ACTIONS(162), 1,
      sym_begin,
    STATE(86), 7,
      sym__statement,
      sym_if_statement,
      sym_while_statement,
      sym_assignment,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [1678] = 6,
    ACTIONS(154), 1,
      anon_sym_if,
    ACTIONS(156), 1,
      anon_sym_while,
    ACTIONS(158), 1,
      anon_sym_for,
    ACTIONS(160), 1,
      sym_identifier,
    ACTIONS(162), 1,
      sym_begin,
    STATE(103), 7,
      sym__statement,
      sym_if_statement,
      sym_while_statement,
      sym_assignment,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [1703] = 6,
    ACTIONS(154), 1,
      anon_sym_if,
    ACTIONS(156), 1,
      anon_sym_while,
    ACTIONS(158), 1,
      anon_sym_for,
    ACTIONS(160), 1,
      sym_identifier,
    ACTIONS(162), 1,
      sym_begin,
    STATE(96), 7,
      sym__statement,
      sym_if_statement,
      sym_while_statement,
      sym_assignment,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [1728] = 6,
    ACTIONS(154), 1,
      anon_sym_if,
    ACTIONS(156), 1,
      anon_sym_while,
    ACTIONS(158), 1,
      anon_sym_for,
    ACTIONS(160), 1,
      sym_identifier,
    ACTIONS(162), 1,
      sym_begin,
    STATE(85), 7,
      sym__statement,
      sym_if_statement,
      sym_while_statement,
      sym_assignment,
      sym_for_statement,
      sym_block_statement,
      sym_procedure_call_statement,
  [1753] = 2,
    ACTIONS(166), 1,
      sym_left_paren,
    ACTIONS(164), 6,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT_EQ,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_COLON_EQ,
  [1765] = 2,
    ACTIONS(170), 1,
      sym_left_paren,
    ACTIONS(168), 6,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT_EQ,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_COLON_EQ,
  [1777] = 1,
    ACTIONS(172), 6,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      sym_identifier,
      sym_begin,
      sym_end,
  [1786] = 1,
    ACTIONS(174), 6,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      sym_identifier,
      sym_begin,
      sym_end,
  [1795] = 1,
    ACTIONS(176), 6,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      sym_identifier,
      sym_begin,
      sym_end,
  [1804] = 1,
    ACTIONS(178), 6,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      sym_identifier,
      sym_begin,
      sym_end,
  [1813] = 1,
    ACTIONS(180), 6,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      sym_identifier,
      sym_begin,
      sym_end,
  [1822] = 1,
    ACTIONS(182), 6,
      anon_sym_if,
      anon_sym_while,
      anon_sym_for,
      sym_identifier,
      sym_begin,
      sym_end,
  [1831] = 2,
    STATE(90), 1,
      sym_type,
    ACTIONS(184), 4,
      anon_sym_boolean,
      anon_sym_integer,
      anon_sym_real,
      anon_sym_char,
  [1841] = 4,
    ACTIONS(186), 1,
      anon_sym_var,
    STATE(88), 1,
      sym_var_declarations,
    STATE(95), 1,
      sym_declarations,
    STATE(98), 1,
      sym_mainblock,
  [1854] = 3,
    ACTIONS(188), 1,
      sym_identifier,
    ACTIONS(190), 1,
      sym_begin,
    STATE(80), 1,
      aux_sym_var_declarations_repeat1,
  [1864] = 3,
    ACTIONS(192), 1,
      sym_identifier,
    ACTIONS(195), 1,
      sym_begin,
    STATE(79), 1,
      aux_sym_var_declarations_repeat1,
  [1874] = 3,
    ACTIONS(188), 1,
      sym_identifier,
    ACTIONS(197), 1,
      sym_begin,
    STATE(79), 1,
      aux_sym_var_declarations_repeat1,
  [1884] = 1,
    ACTIONS(199), 2,
      anon_sym_else,
      sym_end,
  [1889] = 1,
    ACTIONS(201), 2,
      anon_sym_else,
      sym_end,
  [1894] = 1,
    ACTIONS(203), 2,
      sym_identifier,
      sym_begin,
  [1899] = 1,
    ACTIONS(205), 2,
      anon_sym_else,
      sym_end,
  [1904] = 1,
    ACTIONS(207), 2,
      anon_sym_else,
      sym_end,
  [1909] = 1,
    ACTIONS(209), 2,
      anon_sym_else,
      sym_end,
  [1914] = 1,
    ACTIONS(211), 2,
      anon_sym_else,
      sym_end,
  [1919] = 1,
    ACTIONS(213), 1,
      sym_begin,
  [1923] = 1,
    ACTIONS(215), 1,
      sym_identifier,
  [1927] = 1,
    ACTIONS(217), 1,
      sym_semicolon,
  [1931] = 1,
    ACTIONS(219), 1,
      sym_right_paren,
  [1935] = 1,
    ACTIONS(221), 1,
      sym_right_paren,
  [1939] = 1,
    ACTIONS(223), 1,
      sym_identifier,
  [1943] = 1,
    ACTIONS(225), 1,
      sym_dot,
  [1947] = 1,
    ACTIONS(227), 1,
      sym_begin,
  [1951] = 1,
    ACTIONS(229), 1,
      anon_sym_else,
  [1955] = 1,
    ACTIONS(231), 1,
      anon_sym_COLON_EQ,
  [1959] = 1,
    ACTIONS(233), 1,
      sym_dot,
  [1963] = 1,
    ACTIONS(235), 1,
      anon_sym_else,
  [1967] = 1,
    ACTIONS(237), 1,
      sym_semicolon,
  [1971] = 1,
    ACTIONS(239), 1,
      sym_colon,
  [1975] = 1,
    ACTIONS(241), 1,
      sym_right_paren,
  [1979] = 1,
    ACTIONS(243), 1,
      sym_end,
  [1983] = 1,
    ACTIONS(245), 1,
      sym_semicolon,
  [1987] = 1,
    ACTIONS(247), 1,
      ts_builtin_sym_end,
  [1991] = 1,
    ACTIONS(249), 1,
      ts_builtin_sym_end,
  [1995] = 1,
    ACTIONS(251), 1,
      anon_sym_COLON_EQ,
  [1999] = 1,
    ACTIONS(253), 1,
      sym_identifier,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 26,
  [SMALL_STATE(4)] = 54,
  [SMALL_STATE(5)] = 88,
  [SMALL_STATE(6)] = 114,
  [SMALL_STATE(7)] = 146,
  [SMALL_STATE(8)] = 176,
  [SMALL_STATE(9)] = 204,
  [SMALL_STATE(10)] = 228,
  [SMALL_STATE(11)] = 260,
  [SMALL_STATE(12)] = 290,
  [SMALL_STATE(13)] = 314,
  [SMALL_STATE(14)] = 340,
  [SMALL_STATE(15)] = 374,
  [SMALL_STATE(16)] = 401,
  [SMALL_STATE(17)] = 428,
  [SMALL_STATE(18)] = 455,
  [SMALL_STATE(19)] = 479,
  [SMALL_STATE(20)] = 503,
  [SMALL_STATE(21)] = 527,
  [SMALL_STATE(22)] = 551,
  [SMALL_STATE(23)] = 575,
  [SMALL_STATE(24)] = 599,
  [SMALL_STATE(25)] = 623,
  [SMALL_STATE(26)] = 647,
  [SMALL_STATE(27)] = 671,
  [SMALL_STATE(28)] = 695,
  [SMALL_STATE(29)] = 719,
  [SMALL_STATE(30)] = 743,
  [SMALL_STATE(31)] = 767,
  [SMALL_STATE(32)] = 791,
  [SMALL_STATE(33)] = 815,
  [SMALL_STATE(34)] = 839,
  [SMALL_STATE(35)] = 863,
  [SMALL_STATE(36)] = 887,
  [SMALL_STATE(37)] = 911,
  [SMALL_STATE(38)] = 935,
  [SMALL_STATE(39)] = 959,
  [SMALL_STATE(40)] = 983,
  [SMALL_STATE(41)] = 1007,
  [SMALL_STATE(42)] = 1031,
  [SMALL_STATE(43)] = 1063,
  [SMALL_STATE(44)] = 1093,
  [SMALL_STATE(45)] = 1122,
  [SMALL_STATE(46)] = 1151,
  [SMALL_STATE(47)] = 1180,
  [SMALL_STATE(48)] = 1209,
  [SMALL_STATE(49)] = 1238,
  [SMALL_STATE(50)] = 1267,
  [SMALL_STATE(51)] = 1296,
  [SMALL_STATE(52)] = 1325,
  [SMALL_STATE(53)] = 1354,
  [SMALL_STATE(54)] = 1383,
  [SMALL_STATE(55)] = 1412,
  [SMALL_STATE(56)] = 1441,
  [SMALL_STATE(57)] = 1470,
  [SMALL_STATE(58)] = 1499,
  [SMALL_STATE(59)] = 1528,
  [SMALL_STATE(60)] = 1553,
  [SMALL_STATE(61)] = 1578,
  [SMALL_STATE(62)] = 1603,
  [SMALL_STATE(63)] = 1628,
  [SMALL_STATE(64)] = 1653,
  [SMALL_STATE(65)] = 1678,
  [SMALL_STATE(66)] = 1703,
  [SMALL_STATE(67)] = 1728,
  [SMALL_STATE(68)] = 1753,
  [SMALL_STATE(69)] = 1765,
  [SMALL_STATE(70)] = 1777,
  [SMALL_STATE(71)] = 1786,
  [SMALL_STATE(72)] = 1795,
  [SMALL_STATE(73)] = 1804,
  [SMALL_STATE(74)] = 1813,
  [SMALL_STATE(75)] = 1822,
  [SMALL_STATE(76)] = 1831,
  [SMALL_STATE(77)] = 1841,
  [SMALL_STATE(78)] = 1854,
  [SMALL_STATE(79)] = 1864,
  [SMALL_STATE(80)] = 1874,
  [SMALL_STATE(81)] = 1884,
  [SMALL_STATE(82)] = 1889,
  [SMALL_STATE(83)] = 1894,
  [SMALL_STATE(84)] = 1899,
  [SMALL_STATE(85)] = 1904,
  [SMALL_STATE(86)] = 1909,
  [SMALL_STATE(87)] = 1914,
  [SMALL_STATE(88)] = 1919,
  [SMALL_STATE(89)] = 1923,
  [SMALL_STATE(90)] = 1927,
  [SMALL_STATE(91)] = 1931,
  [SMALL_STATE(92)] = 1935,
  [SMALL_STATE(93)] = 1939,
  [SMALL_STATE(94)] = 1943,
  [SMALL_STATE(95)] = 1947,
  [SMALL_STATE(96)] = 1951,
  [SMALL_STATE(97)] = 1955,
  [SMALL_STATE(98)] = 1959,
  [SMALL_STATE(99)] = 1963,
  [SMALL_STATE(100)] = 1967,
  [SMALL_STATE(101)] = 1971,
  [SMALL_STATE(102)] = 1975,
  [SMALL_STATE(103)] = 1979,
  [SMALL_STATE(104)] = 1983,
  [SMALL_STATE(105)] = 1987,
  [SMALL_STATE(106)] = 1991,
  [SMALL_STATE(107)] = 1995,
  [SMALL_STATE(108)] = 1999,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [5] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3),
  [7] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [11] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(38),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_expression, 2),
  [21] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unary_expression, 2),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [25] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(20),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [33] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_assignment, 3),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(29),
  [37] = {.entry = {.count = 1, .reusable = false}}, SHIFT(24),
  [39] = {.entry = {.count = 1, .reusable = false}}, SHIFT(42),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(51),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(25),
  [47] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [49] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [53] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [55] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [57] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [59] = {.entry = {.count = 1, .reusable = false}}, SHIFT(46),
  [61] = {.entry = {.count = 1, .reusable = false}}, SHIFT(56),
  [63] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [65] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [67] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [69] = {.entry = {.count = 1, .reusable = false}}, SHIFT(55),
  [71] = {.entry = {.count = 1, .reusable = false}}, SHIFT(49),
  [73] = {.entry = {.count = 1, .reusable = false}}, SHIFT(54),
  [75] = {.entry = {.count = 1, .reusable = false}}, SHIFT(53),
  [77] = {.entry = {.count = 1, .reusable = false}}, SHIFT(50),
  [79] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [81] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [83] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [87] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [89] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [95] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fact_params, 1),
  [97] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment, 3),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [101] = {.entry = {.count = 1, .reusable = false}}, SHIFT(35),
  [103] = {.entry = {.count = 1, .reusable = false}}, SHIFT(33),
  [105] = {.entry = {.count = 1, .reusable = false}}, SHIFT(108),
  [107] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [109] = {.entry = {.count = 1, .reusable = false}}, SHIFT(45),
  [111] = {.entry = {.count = 1, .reusable = false}}, SHIFT(74),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [117] = {.entry = {.count = 1, .reusable = false}}, SHIFT(84),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [123] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [125] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_statement_repeat1, 2), SHIFT_REPEAT(35),
  [128] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_statement_repeat1, 2), SHIFT_REPEAT(33),
  [131] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_statement_repeat1, 2), SHIFT_REPEAT(108),
  [134] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_statement_repeat1, 2), SHIFT_REPEAT(68),
  [137] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_block_statement_repeat1, 2), SHIFT_REPEAT(45),
  [140] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_block_statement_repeat1, 2),
  [142] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [144] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [146] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [148] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [150] = {.entry = {.count = 1, .reusable = false}}, SHIFT(82),
  [152] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [154] = {.entry = {.count = 1, .reusable = false}}, SHIFT(32),
  [156] = {.entry = {.count = 1, .reusable = false}}, SHIFT(30),
  [158] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [160] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [162] = {.entry = {.count = 1, .reusable = false}}, SHIFT(57),
  [164] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [166] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [168] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [170] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [172] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_statement, 3),
  [174] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_for_statement, 10),
  [176] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_while_statement, 4),
  [178] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_procedure_call_statement, 4),
  [180] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_statement, 2),
  [182] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_if_statement, 6),
  [184] = {.entry = {.count = 1, .reusable = true}}, SHIFT(100),
  [186] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [188] = {.entry = {.count = 1, .reusable = false}}, SHIFT(101),
  [190] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_declarations, 1),
  [192] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_var_declarations_repeat1, 2), SHIFT_REPEAT(101),
  [195] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_var_declarations_repeat1, 2),
  [197] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_declarations, 2),
  [199] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_if_statement, 6),
  [201] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_statement, 2),
  [203] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_var_declarations_repeat1, 4),
  [205] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_statement, 3),
  [207] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_while_statement, 4),
  [209] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_for_statement, 10),
  [211] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_procedure_call_statement, 4),
  [213] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declarations, 1),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(97),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(83),
  [219] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_fact_params, 3),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(104),
  [225] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_mainblock, 4),
  [227] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [229] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [231] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [233] = {.entry = {.count = 1, .reusable = true}}, SHIFT(105),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [237] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [241] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [243] = {.entry = {.count = 1, .reusable = true}}, SHIFT(94),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [247] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 5),
  [249] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(26),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(107),
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
