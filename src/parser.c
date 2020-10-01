#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 12
#define STATE_COUNT 36
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 53
#define ALIAS_COUNT 0
#define TOKEN_COUNT 41
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 5

enum {
  anon_sym_Program = 1,
  anon_sym_var = 2,
  anon_sym_boolean = 3,
  anon_sym_integer = 4,
  anon_sym_real = 5,
  anon_sym_char = 6,
  anon_sym_STAR_EQ = 7,
  anon_sym_SLASH_EQ = 8,
  anon_sym_PERCENT_EQ = 9,
  anon_sym_PLUS_EQ = 10,
  anon_sym_DASH_EQ = 11,
  anon_sym_COLON_EQ = 12,
  anon_sym_PLUS = 13,
  anon_sym_DASH = 14,
  anon_sym_BANG = 15,
  anon_sym_CARET = 16,
  anon_sym_STAR = 17,
  anon_sym_AMP = 18,
  anon_sym_LT_DASH = 19,
  anon_sym_SLASH = 20,
  anon_sym_PERCENT = 21,
  anon_sym_EQ = 22,
  anon_sym_LT_GT = 23,
  anon_sym_LT = 24,
  anon_sym_LT_EQ = 25,
  anon_sym_GT = 26,
  anon_sym_GT_EQ = 27,
  anon_sym_and = 28,
  anon_sym_or = 29,
  sym_identifier = 30,
  sym_integer = 31,
  sym_real = 32,
  sym_char = 33,
  sym_semicolon = 34,
  sym_colon = 35,
  sym_dot = 36,
  sym_true = 37,
  sym_false = 38,
  sym_begin = 39,
  sym_end = 40,
  sym_module = 41,
  sym_mainblock = 42,
  sym_declarations = 43,
  sym_var_declarations = 44,
  sym_type = 45,
  sym__statement = 46,
  sym_assignment = 47,
  sym__expression = 48,
  sym_unary_expression = 49,
  sym_binary_expression = 50,
  sym__number = 51,
  aux_sym_var_declarations_repeat1 = 52,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_Program] = "Program",
  [anon_sym_var] = "var",
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
  [sym_assignment] = "assignment",
  [sym__expression] = "_expression",
  [sym_unary_expression] = "unary_expression",
  [sym_binary_expression] = "binary_expression",
  [sym__number] = "_number",
  [aux_sym_var_declarations_repeat1] = "var_declarations_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_Program] = anon_sym_Program,
  [anon_sym_var] = anon_sym_var,
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
  [sym_assignment] = sym_assignment,
  [sym__expression] = sym__expression,
  [sym_unary_expression] = sym_unary_expression,
  [sym_binary_expression] = sym_binary_expression,
  [sym__number] = sym__number,
  [aux_sym_var_declarations_repeat1] = aux_sym_var_declarations_repeat1,
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
  [sym_assignment] = {
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
      if (eof) ADVANCE(52);
      if (lookahead == '!') ADVANCE(67);
      if (lookahead == '%') ADVANCE(73);
      if (lookahead == '&') ADVANCE(70);
      if (lookahead == '*') ADVANCE(69);
      if (lookahead == '+') ADVANCE(65);
      if (lookahead == '-') ADVANCE(66);
      if (lookahead == '.') ADVANCE(102);
      if (lookahead == '/') ADVANCE(72);
      if (lookahead == ':') ADVANCE(101);
      if (lookahead == ';') ADVANCE(99);
      if (lookahead == '<') ADVANCE(76);
      if (lookahead == '=') ADVANCE(74);
      if (lookahead == '>') ADVANCE(78);
      if (lookahead == 'P') ADVANCE(42);
      if (lookahead == '^') ADVANCE(68);
      if (lookahead == 'a') ADVANCE(35);
      if (lookahead == 'b') ADVANCE(19);
      if (lookahead == 'c') ADVANCE(29);
      if (lookahead == 'e') ADVANCE(39);
      if (lookahead == 'f') ADVANCE(10);
      if (lookahead == 'i') ADVANCE(36);
      if (lookahead == 'o') ADVANCE(43);
      if (lookahead == 'r') ADVANCE(25);
      if (lookahead == 't') ADVANCE(44);
      if (lookahead == 'v') ADVANCE(13);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      END_STATE();
    case 1:
      if (lookahead == '\n') SKIP(1)
      if (lookahead == '!') ADVANCE(67);
      if (lookahead == '&') ADVANCE(70);
      if (lookahead == '*') ADVANCE(69);
      if (lookahead == '+') ADVANCE(65);
      if (lookahead == '-') ADVANCE(66);
      if (lookahead == '<') ADVANCE(98);
      if (lookahead == '^') ADVANCE(68);
      if (lookahead == 'f') ADVANCE(82);
      if (lookahead == 't') ADVANCE(90);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(97);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(96);
      END_STATE();
    case 2:
      if (lookahead == '%') ADVANCE(5);
      if (lookahead == '*') ADVANCE(6);
      if (lookahead == '+') ADVANCE(7);
      if (lookahead == '-') ADVANCE(8);
      if (lookahead == '/') ADVANCE(9);
      if (lookahead == ':') ADVANCE(4);
      if (lookahead == 'b') ADVANCE(85);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(2)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 3:
      if (lookahead == ':') ADVANCE(100);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(3)
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 4:
      if (lookahead == '=') ADVANCE(64);
      END_STATE();
    case 5:
      if (lookahead == '=') ADVANCE(61);
      END_STATE();
    case 6:
      if (lookahead == '=') ADVANCE(59);
      END_STATE();
    case 7:
      if (lookahead == '=') ADVANCE(62);
      END_STATE();
    case 8:
      if (lookahead == '=') ADVANCE(63);
      END_STATE();
    case 9:
      if (lookahead == '=') ADVANCE(60);
      END_STATE();
    case 10:
      if (lookahead == 'a') ADVANCE(31);
      END_STATE();
    case 11:
      if (lookahead == 'a') ADVANCE(34);
      END_STATE();
    case 12:
      if (lookahead == 'a') ADVANCE(32);
      END_STATE();
    case 13:
      if (lookahead == 'a') ADVANCE(45);
      END_STATE();
    case 14:
      if (lookahead == 'a') ADVANCE(38);
      END_STATE();
    case 15:
      if (lookahead == 'a') ADVANCE(46);
      END_STATE();
    case 16:
      if (lookahead == 'd') ADVANCE(80);
      END_STATE();
    case 17:
      if (lookahead == 'd') ADVANCE(109);
      END_STATE();
    case 18:
      if (lookahead == 'd') ADVANCE(95);
      END_STATE();
    case 19:
      if (lookahead == 'e') ADVANCE(26);
      if (lookahead == 'o') ADVANCE(41);
      END_STATE();
    case 20:
      if (lookahead == 'e') ADVANCE(103);
      END_STATE();
    case 21:
      if (lookahead == 'e') ADVANCE(105);
      END_STATE();
    case 22:
      if (lookahead == 'e') ADVANCE(28);
      END_STATE();
    case 23:
      if (lookahead == 'e') ADVANCE(14);
      END_STATE();
    case 24:
      if (lookahead == 'e') ADVANCE(47);
      END_STATE();
    case 25:
      if (lookahead == 'e') ADVANCE(12);
      END_STATE();
    case 26:
      if (lookahead == 'g') ADVANCE(30);
      END_STATE();
    case 27:
      if (lookahead == 'g') ADVANCE(48);
      END_STATE();
    case 28:
      if (lookahead == 'g') ADVANCE(24);
      END_STATE();
    case 29:
      if (lookahead == 'h') ADVANCE(15);
      END_STATE();
    case 30:
      if (lookahead == 'i') ADVANCE(37);
      END_STATE();
    case 31:
      if (lookahead == 'l') ADVANCE(49);
      END_STATE();
    case 32:
      if (lookahead == 'l') ADVANCE(57);
      END_STATE();
    case 33:
      if (lookahead == 'l') ADVANCE(23);
      END_STATE();
    case 34:
      if (lookahead == 'm') ADVANCE(53);
      END_STATE();
    case 35:
      if (lookahead == 'n') ADVANCE(16);
      END_STATE();
    case 36:
      if (lookahead == 'n') ADVANCE(50);
      END_STATE();
    case 37:
      if (lookahead == 'n') ADVANCE(107);
      END_STATE();
    case 38:
      if (lookahead == 'n') ADVANCE(55);
      END_STATE();
    case 39:
      if (lookahead == 'n') ADVANCE(17);
      END_STATE();
    case 40:
      if (lookahead == 'o') ADVANCE(27);
      END_STATE();
    case 41:
      if (lookahead == 'o') ADVANCE(33);
      END_STATE();
    case 42:
      if (lookahead == 'r') ADVANCE(40);
      END_STATE();
    case 43:
      if (lookahead == 'r') ADVANCE(81);
      END_STATE();
    case 44:
      if (lookahead == 'r') ADVANCE(51);
      END_STATE();
    case 45:
      if (lookahead == 'r') ADVANCE(54);
      END_STATE();
    case 46:
      if (lookahead == 'r') ADVANCE(58);
      END_STATE();
    case 47:
      if (lookahead == 'r') ADVANCE(56);
      END_STATE();
    case 48:
      if (lookahead == 'r') ADVANCE(11);
      END_STATE();
    case 49:
      if (lookahead == 's') ADVANCE(21);
      END_STATE();
    case 50:
      if (lookahead == 't') ADVANCE(22);
      END_STATE();
    case 51:
      if (lookahead == 'u') ADVANCE(20);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_Program);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_var);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_boolean);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_integer);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_real);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_char);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_STAR_EQ);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_SLASH_EQ);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(anon_sym_PERCENT_EQ);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(anon_sym_PLUS_EQ);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_DASH_EQ);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_COLON_EQ);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(anon_sym_CARET);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(anon_sym_AMP);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(anon_sym_LT_DASH);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(anon_sym_LT_GT);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '=') ADVANCE(77);
      if (lookahead == '>') ADVANCE(75);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(79);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(anon_sym_and);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(anon_sym_or);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(88);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(104);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(106);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(86);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(87);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(89);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(91);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(108);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(92);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(84);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(83);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_identifier);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == ',') ADVANCE(18);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_real);
      if (lookahead == 'd') ADVANCE(95);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_char);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_char);
      if (lookahead == '!') ADVANCE(67);
      if (lookahead == '&') ADVANCE(70);
      if (lookahead == '*') ADVANCE(69);
      if (lookahead == '+') ADVANCE(65);
      if (lookahead == '-') ADVANCE(66);
      if (lookahead == '<') ADVANCE(98);
      if (lookahead == '^') ADVANCE(68);
      if (lookahead == 'f') ADVANCE(82);
      if (lookahead == 't') ADVANCE(90);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(97);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(94);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'') ADVANCE(96);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_char);
      if (lookahead == '-') ADVANCE(71);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_semicolon);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_colon);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_colon);
      if (lookahead == '=') ADVANCE(64);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_dot);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_true);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_true);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_false);
      END_STATE();
    case 106:
      ACCEPT_TOKEN(sym_false);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 107:
      ACCEPT_TOKEN(sym_begin);
      END_STATE();
    case 108:
      ACCEPT_TOKEN(sym_begin);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(93);
      END_STATE();
    case 109:
      ACCEPT_TOKEN(sym_end);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 1},
  [3] = {.lex_state = 1},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 1},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 0},
  [10] = {.lex_state = 0},
  [11] = {.lex_state = 0},
  [12] = {.lex_state = 0},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 2},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 2},
  [20] = {.lex_state = 2},
  [21] = {.lex_state = 3},
  [22] = {.lex_state = 2},
  [23] = {.lex_state = 2},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 0},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 3},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 0},
  [30] = {.lex_state = 0},
  [31] = {.lex_state = 3},
  [32] = {.lex_state = 0},
  [33] = {.lex_state = 0},
  [34] = {.lex_state = 0},
  [35] = {.lex_state = 0},
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
    [anon_sym_COLON_EQ] = ACTIONS(1),
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
    [sym_true] = ACTIONS(1),
    [sym_false] = ACTIONS(1),
    [sym_begin] = ACTIONS(1),
    [sym_end] = ACTIONS(1),
  },
  [1] = {
    [sym_module] = STATE(35),
    [anon_sym_Program] = ACTIONS(3),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 3,
    STATE(12), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(7), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(5), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [24] = 3,
    STATE(10), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(9), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(5), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [48] = 3,
    STATE(14), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(11), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(5), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [72] = 3,
    STATE(15), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(13), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(5), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [96] = 3,
    STATE(13), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(15), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(5), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [120] = 3,
    STATE(9), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(17), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(5), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [144] = 3,
    STATE(11), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(19), 6,
      sym_identifier,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(5), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [168] = 3,
    ACTIONS(25), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(23), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(21), 9,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_and,
      anon_sym_or,
      sym_end,
  [189] = 6,
    ACTIONS(33), 1,
      anon_sym_and,
    ACTIONS(21), 2,
      anon_sym_or,
      sym_end,
    ACTIONS(27), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(31), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(23), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(29), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [216] = 4,
    ACTIONS(25), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(27), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(23), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(21), 7,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
      anon_sym_and,
      anon_sym_or,
      sym_end,
  [239] = 2,
    ACTIONS(25), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(21), 12,
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
      sym_end,
  [258] = 7,
    ACTIONS(33), 1,
      anon_sym_and,
    ACTIONS(35), 1,
      anon_sym_or,
    ACTIONS(37), 1,
      sym_end,
    ACTIONS(27), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(31), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(23), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(29), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [287] = 5,
    ACTIONS(27), 2,
      anon_sym_PLUS,
      anon_sym_DASH,
    ACTIONS(31), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(21), 3,
      anon_sym_and,
      anon_sym_or,
      sym_end,
    ACTIONS(23), 3,
      anon_sym_STAR,
      anon_sym_SLASH,
      anon_sym_PERCENT,
    ACTIONS(29), 4,
      anon_sym_EQ,
      anon_sym_LT_GT,
      anon_sym_LT_EQ,
      anon_sym_GT_EQ,
  [312] = 2,
    ACTIONS(41), 2,
      anon_sym_LT,
      anon_sym_GT,
    ACTIONS(39), 12,
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
      sym_end,
  [331] = 1,
    ACTIONS(43), 6,
      anon_sym_STAR_EQ,
      anon_sym_SLASH_EQ,
      anon_sym_PERCENT_EQ,
      anon_sym_PLUS_EQ,
      anon_sym_DASH_EQ,
      anon_sym_COLON_EQ,
  [340] = 2,
    STATE(26), 1,
      sym_type,
    ACTIONS(45), 4,
      anon_sym_boolean,
      anon_sym_integer,
      anon_sym_real,
      anon_sym_char,
  [350] = 4,
    ACTIONS(47), 1,
      anon_sym_var,
    STATE(24), 1,
      sym_var_declarations,
    STATE(32), 1,
      sym_declarations,
    STATE(33), 1,
      sym_mainblock,
  [363] = 3,
    ACTIONS(49), 1,
      sym_identifier,
    ACTIONS(51), 1,
      sym_begin,
    STATE(20), 1,
      aux_sym_var_declarations_repeat1,
  [373] = 3,
    ACTIONS(53), 1,
      sym_identifier,
    ACTIONS(56), 1,
      sym_begin,
    STATE(20), 1,
      aux_sym_var_declarations_repeat1,
  [383] = 2,
    ACTIONS(58), 1,
      sym_identifier,
    STATE(29), 2,
      sym__statement,
      sym_assignment,
  [391] = 3,
    ACTIONS(49), 1,
      sym_identifier,
    ACTIONS(60), 1,
      sym_begin,
    STATE(19), 1,
      aux_sym_var_declarations_repeat1,
  [401] = 1,
    ACTIONS(62), 2,
      sym_identifier,
      sym_begin,
  [406] = 1,
    ACTIONS(64), 1,
      sym_begin,
  [410] = 1,
    ACTIONS(66), 1,
      sym_dot,
  [414] = 1,
    ACTIONS(68), 1,
      sym_semicolon,
  [418] = 1,
    ACTIONS(70), 1,
      sym_identifier,
  [422] = 1,
    ACTIONS(72), 1,
      sym_semicolon,
  [426] = 1,
    ACTIONS(74), 1,
      sym_end,
  [430] = 1,
    ACTIONS(76), 1,
      ts_builtin_sym_end,
  [434] = 1,
    ACTIONS(78), 1,
      sym_colon,
  [438] = 1,
    ACTIONS(80), 1,
      sym_begin,
  [442] = 1,
    ACTIONS(82), 1,
      sym_dot,
  [446] = 1,
    ACTIONS(84), 1,
      sym_semicolon,
  [450] = 1,
    ACTIONS(86), 1,
      ts_builtin_sym_end,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 24,
  [SMALL_STATE(4)] = 48,
  [SMALL_STATE(5)] = 72,
  [SMALL_STATE(6)] = 96,
  [SMALL_STATE(7)] = 120,
  [SMALL_STATE(8)] = 144,
  [SMALL_STATE(9)] = 168,
  [SMALL_STATE(10)] = 189,
  [SMALL_STATE(11)] = 216,
  [SMALL_STATE(12)] = 239,
  [SMALL_STATE(13)] = 258,
  [SMALL_STATE(14)] = 287,
  [SMALL_STATE(15)] = 312,
  [SMALL_STATE(16)] = 331,
  [SMALL_STATE(17)] = 340,
  [SMALL_STATE(18)] = 350,
  [SMALL_STATE(19)] = 363,
  [SMALL_STATE(20)] = 373,
  [SMALL_STATE(21)] = 383,
  [SMALL_STATE(22)] = 391,
  [SMALL_STATE(23)] = 401,
  [SMALL_STATE(24)] = 406,
  [SMALL_STATE(25)] = 410,
  [SMALL_STATE(26)] = 414,
  [SMALL_STATE(27)] = 418,
  [SMALL_STATE(28)] = 422,
  [SMALL_STATE(29)] = 426,
  [SMALL_STATE(30)] = 430,
  [SMALL_STATE(31)] = 434,
  [SMALL_STATE(32)] = 438,
  [SMALL_STATE(33)] = 442,
  [SMALL_STATE(34)] = 446,
  [SMALL_STATE(35)] = 450,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(27),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3),
  [23] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [25] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3),
  [27] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [29] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [31] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [33] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [35] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment, 3),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_expression, 2),
  [41] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unary_expression, 2),
  [43] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [45] = {.entry = {.count = 1, .reusable = true}}, SHIFT(28),
  [47] = {.entry = {.count = 1, .reusable = true}}, SHIFT(22),
  [49] = {.entry = {.count = 1, .reusable = false}}, SHIFT(31),
  [51] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_declarations, 2),
  [53] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_var_declarations_repeat1, 2), SHIFT_REPEAT(31),
  [56] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_var_declarations_repeat1, 2),
  [58] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [60] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_var_declarations, 1),
  [62] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_var_declarations_repeat1, 4),
  [64] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_declarations, 1),
  [66] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_mainblock, 4),
  [68] = {.entry = {.count = 1, .reusable = true}}, SHIFT(23),
  [70] = {.entry = {.count = 1, .reusable = true}}, SHIFT(34),
  [72] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_type, 1),
  [74] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [76] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_module, 5),
  [78] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [80] = {.entry = {.count = 1, .reusable = true}}, SHIFT(21),
  [82] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [84] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [86] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
