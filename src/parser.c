#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 12
#define STATE_COUNT 21
#define LARGE_STATE_COUNT 11
#define SYMBOL_COUNT 46
#define ALIAS_COUNT 0
#define TOKEN_COUNT 38
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 0
#define MAX_ALIAS_SEQUENCE_LENGTH 3

enum {
  anon_sym_boolean = 1,
  anon_sym_integer = 2,
  anon_sym_real = 3,
  anon_sym_char = 4,
  anon_sym_STAR_EQ = 5,
  anon_sym_SLASH_EQ = 6,
  anon_sym_PERCENT_EQ = 7,
  anon_sym_PLUS_EQ = 8,
  anon_sym_DASH_EQ = 9,
  anon_sym_COLON_EQ = 10,
  anon_sym_PLUS = 11,
  anon_sym_DASH = 12,
  anon_sym_BANG = 13,
  anon_sym_CARET = 14,
  anon_sym_STAR = 15,
  anon_sym_AMP = 16,
  anon_sym_LT_DASH = 17,
  anon_sym_SLASH = 18,
  anon_sym_PERCENT = 19,
  anon_sym_EQ = 20,
  anon_sym_LT_GT = 21,
  anon_sym_LT = 22,
  anon_sym_LT_EQ = 23,
  anon_sym_GT = 24,
  anon_sym_GT_EQ = 25,
  anon_sym_and = 26,
  anon_sym_or = 27,
  sym_identifier = 28,
  sym_integer = 29,
  sym_real = 30,
  sym_char = 31,
  sym_semicolon = 32,
  sym_dot = 33,
  sym_true = 34,
  sym_false = 35,
  sym_begin = 36,
  sym_end = 37,
  sym_source_file = 38,
  sym__statement = 39,
  sym_assignment = 40,
  sym__expression = 41,
  sym_unary_expression = 42,
  sym_binary_expression = 43,
  sym__number = 44,
  aux_sym_source_file_repeat1 = 45,
};

static const char *ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
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
  [sym_dot] = "dot",
  [sym_true] = "true",
  [sym_false] = "false",
  [sym_begin] = "begin",
  [sym_end] = "end",
  [sym_source_file] = "source_file",
  [sym__statement] = "_statement",
  [sym_assignment] = "assignment",
  [sym__expression] = "_expression",
  [sym_unary_expression] = "unary_expression",
  [sym_binary_expression] = "binary_expression",
  [sym__number] = "_number",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
};

static TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
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
  [sym_dot] = sym_dot,
  [sym_true] = sym_true,
  [sym_false] = sym_false,
  [sym_begin] = sym_begin,
  [sym_end] = sym_end,
  [sym_source_file] = sym_source_file,
  [sym__statement] = sym__statement,
  [sym_assignment] = sym_assignment,
  [sym__expression] = sym__expression,
  [sym_unary_expression] = sym_unary_expression,
  [sym_binary_expression] = sym_binary_expression,
  [sym__number] = sym__number,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
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
  [sym_source_file] = {
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
  [aux_sym_source_file_repeat1] = {
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
      if (eof) ADVANCE(6);
      if (lookahead == '!') ADVANCE(21);
      if (lookahead == '%') ADVANCE(30);
      if (lookahead == '&') ADVANCE(25);
      if (lookahead == '*') ADVANCE(24);
      if (lookahead == '+') ADVANCE(18);
      if (lookahead == '-') ADVANCE(20);
      if (lookahead == '.') ADVANCE(82);
      if (lookahead == '/') ADVANCE(28);
      if (lookahead == ':') ADVANCE(1);
      if (lookahead == ';') ADVANCE(81);
      if (lookahead == '<') ADVANCE(33);
      if (lookahead == '=') ADVANCE(31);
      if (lookahead == '>') ADVANCE(35);
      if (lookahead == '^') ADVANCE(22);
      if (lookahead == 'a') ADVANCE(59);
      if (lookahead == 'b') ADVANCE(45);
      if (lookahead == 'c') ADVANCE(54);
      if (lookahead == 'e') ADVANCE(63);
      if (lookahead == 'f') ADVANCE(39);
      if (lookahead == 'i') ADVANCE(60);
      if (lookahead == 'o') ADVANCE(65);
      if (lookahead == 'r') ADVANCE(51);
      if (lookahead == 't') ADVANCE(66);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(73);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('d' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 1:
      if (lookahead == '=') ADVANCE(16);
      END_STATE();
    case 2:
      if (lookahead == 'd') ADVANCE(74);
      END_STATE();
    case 3:
      if (eof) ADVANCE(6);
      if (lookahead == '\n') SKIP(3)
      if (lookahead == '!') ADVANCE(21);
      if (lookahead == '&') ADVANCE(25);
      if (lookahead == '*') ADVANCE(23);
      if (lookahead == '+') ADVANCE(17);
      if (lookahead == '-') ADVANCE(19);
      if (lookahead == '<') ADVANCE(79);
      if (lookahead == '^') ADVANCE(22);
      if (lookahead == 'f') ADVANCE(39);
      if (lookahead == 't') ADVANCE(66);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(78);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(73);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(75);
      END_STATE();
    case 4:
      if (eof) ADVANCE(6);
      if (lookahead == '\n') SKIP(4)
      if (lookahead == '!') ADVANCE(21);
      if (lookahead == '%') ADVANCE(30);
      if (lookahead == '&') ADVANCE(25);
      if (lookahead == '*') ADVANCE(24);
      if (lookahead == '+') ADVANCE(18);
      if (lookahead == '-') ADVANCE(20);
      if (lookahead == '/') ADVANCE(28);
      if (lookahead == ':') ADVANCE(80);
      if (lookahead == '<') ADVANCE(33);
      if (lookahead == '=') ADVANCE(31);
      if (lookahead == '>') ADVANCE(35);
      if (lookahead == '^') ADVANCE(22);
      if (lookahead == 'a') ADVANCE(59);
      if (lookahead == 'f') ADVANCE(39);
      if (lookahead == 'o') ADVANCE(65);
      if (lookahead == 't') ADVANCE(66);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(76);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(73);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(75);
      END_STATE();
    case 5:
      if (eof) ADVANCE(6);
      if (lookahead == '\n') SKIP(5)
      if (lookahead == '!') ADVANCE(21);
      if (lookahead == '%') ADVANCE(29);
      if (lookahead == '&') ADVANCE(25);
      if (lookahead == '*') ADVANCE(23);
      if (lookahead == '+') ADVANCE(17);
      if (lookahead == '-') ADVANCE(19);
      if (lookahead == '/') ADVANCE(27);
      if (lookahead == '<') ADVANCE(33);
      if (lookahead == '=') ADVANCE(31);
      if (lookahead == '>') ADVANCE(35);
      if (lookahead == '^') ADVANCE(22);
      if (lookahead == 'a') ADVANCE(59);
      if (lookahead == 'f') ADVANCE(39);
      if (lookahead == 'o') ADVANCE(65);
      if (lookahead == 't') ADVANCE(66);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(77);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(73);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      if (lookahead != 0 &&
          lookahead != '\'') ADVANCE(75);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(anon_sym_boolean);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(anon_sym_integer);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 9:
      ACCEPT_TOKEN(anon_sym_real);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 10:
      ACCEPT_TOKEN(anon_sym_char);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 11:
      ACCEPT_TOKEN(anon_sym_STAR_EQ);
      END_STATE();
    case 12:
      ACCEPT_TOKEN(anon_sym_SLASH_EQ);
      END_STATE();
    case 13:
      ACCEPT_TOKEN(anon_sym_PERCENT_EQ);
      END_STATE();
    case 14:
      ACCEPT_TOKEN(anon_sym_PLUS_EQ);
      END_STATE();
    case 15:
      ACCEPT_TOKEN(anon_sym_DASH_EQ);
      END_STATE();
    case 16:
      ACCEPT_TOKEN(anon_sym_COLON_EQ);
      END_STATE();
    case 17:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 18:
      ACCEPT_TOKEN(anon_sym_PLUS);
      if (lookahead == '=') ADVANCE(14);
      END_STATE();
    case 19:
      ACCEPT_TOKEN(anon_sym_DASH);
      END_STATE();
    case 20:
      ACCEPT_TOKEN(anon_sym_DASH);
      if (lookahead == '=') ADVANCE(15);
      END_STATE();
    case 21:
      ACCEPT_TOKEN(anon_sym_BANG);
      END_STATE();
    case 22:
      ACCEPT_TOKEN(anon_sym_CARET);
      END_STATE();
    case 23:
      ACCEPT_TOKEN(anon_sym_STAR);
      END_STATE();
    case 24:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '=') ADVANCE(11);
      END_STATE();
    case 25:
      ACCEPT_TOKEN(anon_sym_AMP);
      END_STATE();
    case 26:
      ACCEPT_TOKEN(anon_sym_LT_DASH);
      END_STATE();
    case 27:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 28:
      ACCEPT_TOKEN(anon_sym_SLASH);
      if (lookahead == '=') ADVANCE(12);
      END_STATE();
    case 29:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      END_STATE();
    case 30:
      ACCEPT_TOKEN(anon_sym_PERCENT);
      if (lookahead == '=') ADVANCE(13);
      END_STATE();
    case 31:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 32:
      ACCEPT_TOKEN(anon_sym_LT_GT);
      END_STATE();
    case 33:
      ACCEPT_TOKEN(anon_sym_LT);
      if (lookahead == '-') ADVANCE(26);
      if (lookahead == '=') ADVANCE(34);
      if (lookahead == '>') ADVANCE(32);
      END_STATE();
    case 34:
      ACCEPT_TOKEN(anon_sym_LT_EQ);
      END_STATE();
    case 35:
      ACCEPT_TOKEN(anon_sym_GT);
      if (lookahead == '=') ADVANCE(36);
      END_STATE();
    case 36:
      ACCEPT_TOKEN(anon_sym_GT_EQ);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(anon_sym_and);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(anon_sym_or);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(56);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(67);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(57);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(62);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(37);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(86);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(52);
      if (lookahead == 'o') ADVANCE(64);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(83);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(84);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(53);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(42);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(68);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(41);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(55);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(50);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'h') ADVANCE(40);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(61);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(69);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(9);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(49);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(43);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(70);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(85);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(7);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'n') ADVANCE(44);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'o') ADVANCE(58);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(38);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(71);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(10);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(8);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 's') ADVANCE(47);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 't') ADVANCE(48);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'u') ADVANCE(46);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_identifier);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_integer);
      if (lookahead == ',') ADVANCE(2);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(73);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_real);
      if (lookahead == 'd') ADVANCE(74);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_char);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_char);
      if (lookahead == '!') ADVANCE(21);
      if (lookahead == '%') ADVANCE(30);
      if (lookahead == '&') ADVANCE(25);
      if (lookahead == '*') ADVANCE(24);
      if (lookahead == '+') ADVANCE(18);
      if (lookahead == '-') ADVANCE(20);
      if (lookahead == '/') ADVANCE(28);
      if (lookahead == ':') ADVANCE(80);
      if (lookahead == '<') ADVANCE(33);
      if (lookahead == '=') ADVANCE(31);
      if (lookahead == '>') ADVANCE(35);
      if (lookahead == '^') ADVANCE(22);
      if (lookahead == 'a') ADVANCE(59);
      if (lookahead == 'f') ADVANCE(39);
      if (lookahead == 'o') ADVANCE(65);
      if (lookahead == 't') ADVANCE(66);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(76);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(73);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'') ADVANCE(75);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_char);
      if (lookahead == '!') ADVANCE(21);
      if (lookahead == '%') ADVANCE(29);
      if (lookahead == '&') ADVANCE(25);
      if (lookahead == '*') ADVANCE(23);
      if (lookahead == '+') ADVANCE(17);
      if (lookahead == '-') ADVANCE(19);
      if (lookahead == '/') ADVANCE(27);
      if (lookahead == '<') ADVANCE(33);
      if (lookahead == '=') ADVANCE(31);
      if (lookahead == '>') ADVANCE(35);
      if (lookahead == '^') ADVANCE(22);
      if (lookahead == 'a') ADVANCE(59);
      if (lookahead == 'f') ADVANCE(39);
      if (lookahead == 'o') ADVANCE(65);
      if (lookahead == 't') ADVANCE(66);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(77);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(73);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'') ADVANCE(75);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_char);
      if (lookahead == '!') ADVANCE(21);
      if (lookahead == '&') ADVANCE(25);
      if (lookahead == '*') ADVANCE(23);
      if (lookahead == '+') ADVANCE(17);
      if (lookahead == '-') ADVANCE(19);
      if (lookahead == '<') ADVANCE(79);
      if (lookahead == '^') ADVANCE(22);
      if (lookahead == 'f') ADVANCE(39);
      if (lookahead == 't') ADVANCE(66);
      if (lookahead == '\t' ||
          lookahead == '\r' ||
          lookahead == ' ') ADVANCE(78);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(73);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      if (lookahead != 0 &&
          lookahead != '\n' &&
          lookahead != '\'') ADVANCE(75);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_char);
      if (lookahead == '-') ADVANCE(26);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_char);
      if (lookahead == '=') ADVANCE(16);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_semicolon);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_dot);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(sym_true);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(sym_false);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(sym_begin);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(sym_end);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(72);
      END_STATE();
    default:
      return false;
  }
}

static TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 3},
  [2] = {.lex_state = 4},
  [3] = {.lex_state = 5},
  [4] = {.lex_state = 5},
  [5] = {.lex_state = 5},
  [6] = {.lex_state = 5},
  [7] = {.lex_state = 5},
  [8] = {.lex_state = 5},
  [9] = {.lex_state = 5},
  [10] = {.lex_state = 5},
  [11] = {.lex_state = 3},
  [12] = {.lex_state = 3},
  [13] = {.lex_state = 3},
  [14] = {.lex_state = 3},
  [15] = {.lex_state = 3},
  [16] = {.lex_state = 3},
  [17] = {.lex_state = 3},
  [18] = {.lex_state = 3},
  [19] = {.lex_state = 3},
  [20] = {.lex_state = 0},
};

static uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_boolean] = ACTIONS(1),
    [anon_sym_integer] = ACTIONS(1),
    [anon_sym_real] = ACTIONS(1),
    [anon_sym_char] = ACTIONS(1),
    [anon_sym_STAR_EQ] = ACTIONS(1),
    [anon_sym_SLASH_EQ] = ACTIONS(1),
    [anon_sym_PERCENT_EQ] = ACTIONS(1),
    [anon_sym_PLUS_EQ] = ACTIONS(1),
    [anon_sym_DASH_EQ] = ACTIONS(1),
    [anon_sym_COLON_EQ] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_DASH] = ACTIONS(1),
    [anon_sym_BANG] = ACTIONS(1),
    [anon_sym_CARET] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_AMP] = ACTIONS(1),
    [anon_sym_LT_DASH] = ACTIONS(1),
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
    [sym_identifier] = ACTIONS(1),
    [sym_integer] = ACTIONS(1),
    [sym_real] = ACTIONS(1),
    [sym_semicolon] = ACTIONS(1),
    [sym_dot] = ACTIONS(1),
    [sym_true] = ACTIONS(1),
    [sym_false] = ACTIONS(1),
    [sym_begin] = ACTIONS(1),
    [sym_end] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(20),
    [sym__statement] = STATE(11),
    [sym_assignment] = STATE(11),
    [sym__expression] = STATE(4),
    [sym_unary_expression] = STATE(4),
    [sym_binary_expression] = STATE(4),
    [sym__number] = STATE(4),
    [aux_sym_source_file_repeat1] = STATE(11),
    [ts_builtin_sym_end] = ACTIONS(3),
    [anon_sym_PLUS] = ACTIONS(5),
    [anon_sym_DASH] = ACTIONS(5),
    [anon_sym_BANG] = ACTIONS(5),
    [anon_sym_CARET] = ACTIONS(5),
    [anon_sym_STAR] = ACTIONS(5),
    [anon_sym_AMP] = ACTIONS(5),
    [anon_sym_LT_DASH] = ACTIONS(5),
    [sym_identifier] = ACTIONS(7),
    [sym_integer] = ACTIONS(9),
    [sym_real] = ACTIONS(9),
    [sym_char] = ACTIONS(9),
    [sym_true] = ACTIONS(9),
    [sym_false] = ACTIONS(9),
  },
  [2] = {
    [ts_builtin_sym_end] = ACTIONS(11),
    [anon_sym_STAR_EQ] = ACTIONS(13),
    [anon_sym_SLASH_EQ] = ACTIONS(13),
    [anon_sym_PERCENT_EQ] = ACTIONS(13),
    [anon_sym_PLUS_EQ] = ACTIONS(13),
    [anon_sym_DASH_EQ] = ACTIONS(13),
    [anon_sym_COLON_EQ] = ACTIONS(13),
    [anon_sym_PLUS] = ACTIONS(15),
    [anon_sym_DASH] = ACTIONS(15),
    [anon_sym_BANG] = ACTIONS(15),
    [anon_sym_CARET] = ACTIONS(15),
    [anon_sym_STAR] = ACTIONS(15),
    [anon_sym_AMP] = ACTIONS(15),
    [anon_sym_LT_DASH] = ACTIONS(15),
    [anon_sym_SLASH] = ACTIONS(15),
    [anon_sym_PERCENT] = ACTIONS(15),
    [anon_sym_EQ] = ACTIONS(15),
    [anon_sym_LT_GT] = ACTIONS(15),
    [anon_sym_LT] = ACTIONS(15),
    [anon_sym_LT_EQ] = ACTIONS(15),
    [anon_sym_GT] = ACTIONS(15),
    [anon_sym_GT_EQ] = ACTIONS(15),
    [anon_sym_and] = ACTIONS(15),
    [anon_sym_or] = ACTIONS(15),
    [sym_identifier] = ACTIONS(15),
    [sym_integer] = ACTIONS(15),
    [sym_real] = ACTIONS(15),
    [sym_char] = ACTIONS(15),
    [sym_true] = ACTIONS(15),
    [sym_false] = ACTIONS(15),
  },
  [3] = {
    [ts_builtin_sym_end] = ACTIONS(17),
    [anon_sym_PLUS] = ACTIONS(19),
    [anon_sym_DASH] = ACTIONS(19),
    [anon_sym_BANG] = ACTIONS(21),
    [anon_sym_CARET] = ACTIONS(21),
    [anon_sym_STAR] = ACTIONS(23),
    [anon_sym_AMP] = ACTIONS(21),
    [anon_sym_LT_DASH] = ACTIONS(21),
    [anon_sym_SLASH] = ACTIONS(23),
    [anon_sym_PERCENT] = ACTIONS(23),
    [anon_sym_EQ] = ACTIONS(25),
    [anon_sym_LT_GT] = ACTIONS(25),
    [anon_sym_LT] = ACTIONS(25),
    [anon_sym_LT_EQ] = ACTIONS(25),
    [anon_sym_GT] = ACTIONS(25),
    [anon_sym_GT_EQ] = ACTIONS(25),
    [anon_sym_and] = ACTIONS(27),
    [anon_sym_or] = ACTIONS(29),
    [sym_identifier] = ACTIONS(21),
    [sym_integer] = ACTIONS(21),
    [sym_real] = ACTIONS(21),
    [sym_char] = ACTIONS(21),
    [sym_true] = ACTIONS(21),
    [sym_false] = ACTIONS(21),
  },
  [4] = {
    [ts_builtin_sym_end] = ACTIONS(31),
    [anon_sym_PLUS] = ACTIONS(19),
    [anon_sym_DASH] = ACTIONS(19),
    [anon_sym_BANG] = ACTIONS(33),
    [anon_sym_CARET] = ACTIONS(33),
    [anon_sym_STAR] = ACTIONS(23),
    [anon_sym_AMP] = ACTIONS(33),
    [anon_sym_LT_DASH] = ACTIONS(33),
    [anon_sym_SLASH] = ACTIONS(23),
    [anon_sym_PERCENT] = ACTIONS(23),
    [anon_sym_EQ] = ACTIONS(25),
    [anon_sym_LT_GT] = ACTIONS(25),
    [anon_sym_LT] = ACTIONS(25),
    [anon_sym_LT_EQ] = ACTIONS(25),
    [anon_sym_GT] = ACTIONS(25),
    [anon_sym_GT_EQ] = ACTIONS(25),
    [anon_sym_and] = ACTIONS(27),
    [anon_sym_or] = ACTIONS(29),
    [sym_identifier] = ACTIONS(33),
    [sym_integer] = ACTIONS(33),
    [sym_real] = ACTIONS(33),
    [sym_char] = ACTIONS(33),
    [sym_true] = ACTIONS(33),
    [sym_false] = ACTIONS(33),
  },
  [5] = {
    [ts_builtin_sym_end] = ACTIONS(35),
    [anon_sym_PLUS] = ACTIONS(37),
    [anon_sym_DASH] = ACTIONS(37),
    [anon_sym_BANG] = ACTIONS(37),
    [anon_sym_CARET] = ACTIONS(37),
    [anon_sym_STAR] = ACTIONS(37),
    [anon_sym_AMP] = ACTIONS(37),
    [anon_sym_LT_DASH] = ACTIONS(37),
    [anon_sym_SLASH] = ACTIONS(37),
    [anon_sym_PERCENT] = ACTIONS(37),
    [anon_sym_EQ] = ACTIONS(37),
    [anon_sym_LT_GT] = ACTIONS(37),
    [anon_sym_LT] = ACTIONS(37),
    [anon_sym_LT_EQ] = ACTIONS(37),
    [anon_sym_GT] = ACTIONS(37),
    [anon_sym_GT_EQ] = ACTIONS(37),
    [anon_sym_and] = ACTIONS(37),
    [anon_sym_or] = ACTIONS(37),
    [sym_identifier] = ACTIONS(37),
    [sym_integer] = ACTIONS(37),
    [sym_real] = ACTIONS(37),
    [sym_char] = ACTIONS(37),
    [sym_true] = ACTIONS(37),
    [sym_false] = ACTIONS(37),
  },
  [6] = {
    [ts_builtin_sym_end] = ACTIONS(39),
    [anon_sym_PLUS] = ACTIONS(41),
    [anon_sym_DASH] = ACTIONS(41),
    [anon_sym_BANG] = ACTIONS(41),
    [anon_sym_CARET] = ACTIONS(41),
    [anon_sym_STAR] = ACTIONS(23),
    [anon_sym_AMP] = ACTIONS(41),
    [anon_sym_LT_DASH] = ACTIONS(41),
    [anon_sym_SLASH] = ACTIONS(23),
    [anon_sym_PERCENT] = ACTIONS(23),
    [anon_sym_EQ] = ACTIONS(41),
    [anon_sym_LT_GT] = ACTIONS(41),
    [anon_sym_LT] = ACTIONS(41),
    [anon_sym_LT_EQ] = ACTIONS(41),
    [anon_sym_GT] = ACTIONS(41),
    [anon_sym_GT_EQ] = ACTIONS(41),
    [anon_sym_and] = ACTIONS(41),
    [anon_sym_or] = ACTIONS(41),
    [sym_identifier] = ACTIONS(41),
    [sym_integer] = ACTIONS(41),
    [sym_real] = ACTIONS(41),
    [sym_char] = ACTIONS(41),
    [sym_true] = ACTIONS(41),
    [sym_false] = ACTIONS(41),
  },
  [7] = {
    [ts_builtin_sym_end] = ACTIONS(39),
    [anon_sym_PLUS] = ACTIONS(41),
    [anon_sym_DASH] = ACTIONS(41),
    [anon_sym_BANG] = ACTIONS(41),
    [anon_sym_CARET] = ACTIONS(41),
    [anon_sym_STAR] = ACTIONS(41),
    [anon_sym_AMP] = ACTIONS(41),
    [anon_sym_LT_DASH] = ACTIONS(41),
    [anon_sym_SLASH] = ACTIONS(41),
    [anon_sym_PERCENT] = ACTIONS(41),
    [anon_sym_EQ] = ACTIONS(41),
    [anon_sym_LT_GT] = ACTIONS(41),
    [anon_sym_LT] = ACTIONS(41),
    [anon_sym_LT_EQ] = ACTIONS(41),
    [anon_sym_GT] = ACTIONS(41),
    [anon_sym_GT_EQ] = ACTIONS(41),
    [anon_sym_and] = ACTIONS(41),
    [anon_sym_or] = ACTIONS(41),
    [sym_identifier] = ACTIONS(41),
    [sym_integer] = ACTIONS(41),
    [sym_real] = ACTIONS(41),
    [sym_char] = ACTIONS(41),
    [sym_true] = ACTIONS(41),
    [sym_false] = ACTIONS(41),
  },
  [8] = {
    [ts_builtin_sym_end] = ACTIONS(39),
    [anon_sym_PLUS] = ACTIONS(19),
    [anon_sym_DASH] = ACTIONS(19),
    [anon_sym_BANG] = ACTIONS(41),
    [anon_sym_CARET] = ACTIONS(41),
    [anon_sym_STAR] = ACTIONS(23),
    [anon_sym_AMP] = ACTIONS(41),
    [anon_sym_LT_DASH] = ACTIONS(41),
    [anon_sym_SLASH] = ACTIONS(23),
    [anon_sym_PERCENT] = ACTIONS(23),
    [anon_sym_EQ] = ACTIONS(41),
    [anon_sym_LT_GT] = ACTIONS(41),
    [anon_sym_LT] = ACTIONS(41),
    [anon_sym_LT_EQ] = ACTIONS(41),
    [anon_sym_GT] = ACTIONS(41),
    [anon_sym_GT_EQ] = ACTIONS(41),
    [anon_sym_and] = ACTIONS(41),
    [anon_sym_or] = ACTIONS(41),
    [sym_identifier] = ACTIONS(41),
    [sym_integer] = ACTIONS(41),
    [sym_real] = ACTIONS(41),
    [sym_char] = ACTIONS(41),
    [sym_true] = ACTIONS(41),
    [sym_false] = ACTIONS(41),
  },
  [9] = {
    [ts_builtin_sym_end] = ACTIONS(39),
    [anon_sym_PLUS] = ACTIONS(19),
    [anon_sym_DASH] = ACTIONS(19),
    [anon_sym_BANG] = ACTIONS(41),
    [anon_sym_CARET] = ACTIONS(41),
    [anon_sym_STAR] = ACTIONS(23),
    [anon_sym_AMP] = ACTIONS(41),
    [anon_sym_LT_DASH] = ACTIONS(41),
    [anon_sym_SLASH] = ACTIONS(23),
    [anon_sym_PERCENT] = ACTIONS(23),
    [anon_sym_EQ] = ACTIONS(25),
    [anon_sym_LT_GT] = ACTIONS(25),
    [anon_sym_LT] = ACTIONS(25),
    [anon_sym_LT_EQ] = ACTIONS(25),
    [anon_sym_GT] = ACTIONS(25),
    [anon_sym_GT_EQ] = ACTIONS(25),
    [anon_sym_and] = ACTIONS(41),
    [anon_sym_or] = ACTIONS(41),
    [sym_identifier] = ACTIONS(41),
    [sym_integer] = ACTIONS(41),
    [sym_real] = ACTIONS(41),
    [sym_char] = ACTIONS(41),
    [sym_true] = ACTIONS(41),
    [sym_false] = ACTIONS(41),
  },
  [10] = {
    [ts_builtin_sym_end] = ACTIONS(39),
    [anon_sym_PLUS] = ACTIONS(19),
    [anon_sym_DASH] = ACTIONS(19),
    [anon_sym_BANG] = ACTIONS(41),
    [anon_sym_CARET] = ACTIONS(41),
    [anon_sym_STAR] = ACTIONS(23),
    [anon_sym_AMP] = ACTIONS(41),
    [anon_sym_LT_DASH] = ACTIONS(41),
    [anon_sym_SLASH] = ACTIONS(23),
    [anon_sym_PERCENT] = ACTIONS(23),
    [anon_sym_EQ] = ACTIONS(25),
    [anon_sym_LT_GT] = ACTIONS(25),
    [anon_sym_LT] = ACTIONS(25),
    [anon_sym_LT_EQ] = ACTIONS(25),
    [anon_sym_GT] = ACTIONS(25),
    [anon_sym_GT_EQ] = ACTIONS(25),
    [anon_sym_and] = ACTIONS(27),
    [anon_sym_or] = ACTIONS(41),
    [sym_identifier] = ACTIONS(41),
    [sym_integer] = ACTIONS(41),
    [sym_real] = ACTIONS(41),
    [sym_char] = ACTIONS(41),
    [sym_true] = ACTIONS(41),
    [sym_false] = ACTIONS(41),
  },
};

static uint16_t ts_small_parse_table[] = {
  [0] = 6,
    ACTIONS(7), 1,
      sym_identifier,
    ACTIONS(43), 1,
      ts_builtin_sym_end,
    STATE(12), 3,
      sym__statement,
      sym_assignment,
      aux_sym_source_file_repeat1,
    STATE(4), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(9), 5,
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
  [34] = 6,
    ACTIONS(45), 1,
      ts_builtin_sym_end,
    ACTIONS(50), 1,
      sym_identifier,
    STATE(12), 3,
      sym__statement,
      sym_assignment,
      aux_sym_source_file_repeat1,
    STATE(4), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(53), 5,
      sym_integer,
      sym_real,
      sym_char,
      sym_true,
      sym_false,
    ACTIONS(47), 7,
      anon_sym_PLUS,
      anon_sym_DASH,
      anon_sym_BANG,
      anon_sym_CARET,
      anon_sym_STAR,
      anon_sym_AMP,
      anon_sym_LT_DASH,
  [68] = 3,
    STATE(3), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(56), 6,
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
  [92] = 3,
    STATE(6), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(58), 6,
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
  [116] = 3,
    STATE(7), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(60), 6,
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
  [140] = 3,
    STATE(8), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(62), 6,
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
  [164] = 3,
    STATE(9), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(64), 6,
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
  [188] = 3,
    STATE(10), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(66), 6,
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
  [212] = 3,
    STATE(5), 4,
      sym__expression,
      sym_unary_expression,
      sym_binary_expression,
      sym__number,
    ACTIONS(68), 6,
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
  [236] = 1,
    ACTIONS(70), 1,
      ts_builtin_sym_end,
};

static uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(11)] = 0,
  [SMALL_STATE(12)] = 34,
  [SMALL_STATE(13)] = 68,
  [SMALL_STATE(14)] = 92,
  [SMALL_STATE(15)] = 116,
  [SMALL_STATE(16)] = 140,
  [SMALL_STATE(17)] = 164,
  [SMALL_STATE(18)] = 188,
  [SMALL_STATE(19)] = 212,
  [SMALL_STATE(20)] = 236,
};

static TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(19),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__expression, 1),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(13),
  [15] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__expression, 1),
  [17] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_assignment, 3),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(14),
  [21] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_assignment, 3),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(15),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(16),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(17),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(18),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 1),
  [33] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 1),
  [35] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_unary_expression, 2),
  [37] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_unary_expression, 2),
  [39] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_binary_expression, 3),
  [41] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_binary_expression, 3),
  [43] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1),
  [45] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2),
  [47] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(19),
  [50] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(2),
  [53] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2), SHIFT_REPEAT(4),
  [56] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [58] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [62] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [64] = {.entry = {.count = 1, .reusable = false}}, SHIFT(9),
  [66] = {.entry = {.count = 1, .reusable = false}}, SHIFT(10),
  [68] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [70] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
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
