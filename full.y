// Copyright (c) Ivan Bondarev, Stanislav Mikhalkovich (for details please see \doc\copyright.txt)
// This code is distributed under the GNU LGPL (for details please see \doc\license.txt)
// SSM 21/11/16 ������ ��������� �������� �� ������� ������� (�.�. ������������ � ���������)
%

%output=ABCPascalYacc.cs
%partial
%parsertype GPPGParser

%using PascalABCCompiler.SyntaxTree;
%using PascalABCSavParser;
%using PascalABCCompiler.ParserTools;
%using PascalABCCompiler.Errors;
%using System.Linq;
%using SyntaxVisitors;

%namespace GPPGParserScanner

%YYSTYPE PascalABCSavParser.Union

%start parse_goal

%token <ti> tkDirectiveName tkAmpersend tkColon tkDotDot tkPoint tkRoundOpen tkRoundClose tkSemiColon tkSquareOpen tkSquareClose tkQuestion tkUnderscore tkQuestionPoint tkDoubleQuestion tkQuestionSquareOpen
%token <ti> tkSizeOf tkTypeOf tkWhere tkArray tkCase tkClass tkAuto tkStatic tkConst tkConstructor tkDestructor tkElse  tkExcept tkFile tkFor tkForeach tkFunction tkMatch tkWhen
%token <ti> tkIf tkImplementation tkInherited tkInterface tkProcedure tkOperator tkProperty tkRaise tkRecord tkSet tkType tkThen tkUses tkVar tkWhile tkWith tkNil
%token <ti> tkGoto tkOf tkLabel tkLock tkProgram tkEvent tkDefault tkTemplate tkPacked tkExports tkResourceString tkThreadvar tkSealed tkPartial tkTo tkDownto
%token <ti> tkLoop
%token <ti> tkSequence tkYield tkShortProgram tkVertParen tkShortSFProgram
%token <id> tkNew
%token <id> tkOn
%token <id> tkName tkPrivate tkProtected tkPublic tkInternal tkRead tkWrite
%token <ti> tkParseModeExpression tkParseModeStatement tkParseModeType tkBegin tkEnd
%token <ti> tkAsmBody tkILCode tkError INVISIBLE
%token <ti> tkRepeat tkUntil tkDo tkComma tkFinally tkTry
%token <ti> tkInitialization tkFinalization tkUnit tkLibrary tkExternal tkParams tkNamespace
%token <op> tkAssign tkPlusEqual tkMinusEqual tkMultEqual tkDivEqual tkMinus tkPlus tkSlash tkStar tkStarStar tkEqual tkGreater tkGreaterEqual tkLower tkLowerEqual
%token <op> tkNotEqual tkCSharpStyleOr tkArrow tkOr tkXor tkAnd tkDiv tkMod tkShl tkShr tkNot tkAs tkIn tkIs tkImplicit tkExplicit tkAddressOf tkDeref
%token <id> tkDirectiveName tkIdentifier
%token <stn> tkStringLiteral tkFormatStringLiteral tkAsciiChar
%token <id> tkAbstract tkForward tkOverload tkReintroduce tkOverride tkVirtual tkExtensionMethod
%token <ex> tkInteger tkFloat tkHex
%token <id> tkUnknown

%type <ti> unit_key_word class_or_static
%type <stn> assignment
%type <stn> optional_array_initializer
%type <stn> attribute_declarations
%type <stn> ot_visibility_specifier
%type <stn> one_attribute attribute_variable
%type <ex> const_factor const_factor_without_unary_op const_variable_2 const_term const_variable literal_or_number unsigned_number variable_or_literal_or_number
%type <stn> program_block
%type <ob> optional_var class_attribute class_attributes class_attributes1
%type <stn> member_list_section optional_component_list_seq_end
%type <stn> const_decl only_const_decl
%type <stn> const_decl_sect
%type <td> object_type record_type
%type <stn> member_list method_decl_list field_or_const_definition_list
%type <stn> case_stmt
%type <stn> case_list
%type <stn> program_decl_sect_list int_decl_sect_list1 inclass_decl_sect_list1 interface_decl_sect_list decl_sect_list decl_sect_list1 inclass_decl_sect_list
%type <stn> field_or_const_definition abc_decl_sect decl_sect int_decl_sect type_decl simple_type_decl simple_field_or_const_definition res_str_decl_sect
%type <stn> method_decl_withattr method_or_property_decl property_definition fp_sect
%type <ex> default_expr tuple
%type <stn> expr_as_stmt
%type <stn> exception_block
%type <stn> external_block
%type <stn> exception_handler
%type <stn> exception_handler_list
%type <stn> exception_identifier
%type <stn> typed_const_list1 typed_const_list optional_expr_list elem_list optional_expr_list_with_bracket expr_list const_elem_list1  case_label_list const_elem_list optional_const_func_expr_list elem_list1
%type <stn> enumeration_id expr_l1_list
%type <stn> enumeration_id_list
%type <ex> const_simple_expr term term1 typed_const typed_const_plus typed_var_init_expression expr expr_with_func_decl_lambda const_expr elem range_expr const_elem array_const factor factor_without_unary_op relop_expr expr_dq expr_l1 expr_l1_func_decl_lambda expr_l1_for_lambda simple_expr range_term range_factor
%type <ex> external_directive_ident init_const_expr case_label variable var_reference  optional_read_expr simple_expr_or_nothing var_question_point expr_l1_for_question_expr expr_l1_for_new_question_expr
%type <ob> for_cycle_type
%type <ex> format_expr format_const_expr const_expr_or_nothing
%type <stn> foreach_stmt
%type <stn> for_stmt loop_stmt yield_stmt yield_sequence_stmt
%type <stn> fp_list fp_sect_list
%type <td> file_type sequence_type
%type <stn> var_address
%type <stn> goto_stmt
%type <id> func_name_ident param_name const_field_name func_name_with_template_args identifier_or_keyword unit_name exception_variable const_name func_meth_name_ident label_name type_decl_identifier template_identifier_with_equal
%type <id> program_param identifier identifier_keyword_operatorname func_class_name_ident  visibility_specifier
%type <id> property_specifier_directives non_reserved
%type <stn> if_stmt
%type <stn> initialization_part
%type <stn> template_arguments label_list ident_or_keyword_pointseparator_list ident_list  param_name_list
%type <stn> inherited_message
%type <stn> implementation_part
%type <stn> interface_part abc_interface_part
%type <stn> simple_type_list
%type <ex> literal one_literal
%type <stn> literal_list
%type <stn> label_decl_sect
%type <stn> lock_stmt
%type <stn> func_name proc_name optional_proc_name qualified_identifier
%type <ex> new_expr allowable_expr_as_stmt
%type <stn> parse_goal parts inclass_block block proc_func_external_block
%type <td> exception_class_type_identifier simple_type_identifier //idp
%type <stn> base_class_name
%type <stn> base_classes_names_list optional_base_classes
%type <ob> one_compiler_directive optional_head_compiler_directives head_compiler_directives program_heading_2 optional_tk_point program_param_list optional_semicolon
%type <ex> operator_name_ident
%type <op> const_relop const_addop assign_operator const_mulop relop addop mulop sign overload_operator
%type <ob> typecast_op
%type <stn> property_specifiers
%type <stn> write_property_specifiers
%type <stn> read_property_specifiers
%type <stn> array_defaultproperty
%type <stn> meth_modificators optional_method_modificators optional_method_modificators1
%type <id> meth_modificator property_modificator
%type <ex> optional_property_initialization
%type <stn> proc_call
%type <stn> proc_func_constr_destr_decl proc_func_decl inclass_proc_func_decl inclass_proc_func_decl_noclass constr_destr_decl inclass_constr_destr_decl
%type <stn> method_decl proc_func_constr_destr_decl_with_attr proc_func_decl_noclass
%type <td> method_header proc_type_decl procedural_type_kind proc_header procedural_type constr_destr_header proc_func_header
%type <td> func_header method_procfunc_header int_func_header int_proc_header
%type <stn> property_interface
%type <stn> program_file
%type <stn> program_header
%type <stn> parameter_decl
%type <stn> parameter_decl_list property_parameter_list
%type <ex> const_set
%type <ex> question_expr question_constexpr new_question_expr
%type <ex> record_const const_field_list_1 const_field_list
%type <stn> const_field
%type <stn> repeat_stmt
%type <stn> raise_stmt
%type <td> pointer_type
%type <stn> attribute_declaration one_or_some_attribute
%type <stn> stmt_list else_case exception_block_else_branch  compound_stmt
%type <td> string_type
%type <ex> sizeof_expr
%type <stn> simple_property_definition
%type <stn> stmt_or_expression unlabelled_stmt stmt case_item
%type <td> set_type
%type <ex> as_is_expr as_is_constexpr is_type_expr as_expr power_expr power_constexpr
%type <td> unsized_array_type simple_type_or_ simple_type simple_type_question foreach_stmt_ident_dype_opt fptype type_ref fptype_noproctype array_type
%type <td> template_param template_empty_param structured_type unpacked_structured_type empty_template_type_reference simple_or_template_type_reference type_ref_or_secific for_stmt_decl_or_assign type_decl_type
%type <stn> type_ref_and_secific_list
%type <stn> type_decl_sect
%type <stn> try_handler
%type <ti> class_or_interface_keyword optional_tk_do keyword reserved_keyword
%type <ex> typeof_expr
%type <stn> simple_fp_sect
%type <stn> template_param_list template_empty_param_list template_type_params template_type_empty_params
%type <td> template_type
%type <stn> try_stmt
%type <stn> uses_clause used_units_list
%type <stn> unit_file
%type <stn> used_unit_name
%type <stn> unit_header
%type <stn> var_decl_sect
%type <stn> var_decl var_decl_part  field_definition var_decl_with_assign_var_tuple
%type <stn> var_stmt
%type <stn> where_part
%type <stn> where_part_list optional_where_section
%type <stn> while_stmt
%type <stn> with_stmt
%type <ex> variable_as_type dotted_identifier
%type <ex> func_decl_lambda expl_func_decl_lambda
%type <td> lambda_type_ref lambda_type_ref_noproctype
%type <stn> full_lambda_fp_list lambda_simple_fp_sect lambda_function_body lambda_procedure_body common_lambda_body optional_full_lambda_fp_list
%type <ob> field_in_unnamed_object list_fields_in_unnamed_object func_class_name_ident_list rem_lambda variable_list var_ident_list
%type <ti> tkAssignOrEqual
%type <stn> const_pattern_expression pattern deconstruction_or_const_pattern pattern_optional_var collection_pattern tuple_pattern collection_pattern_list_item tuple_pattern_item collection_pattern_var_item match_with pattern_case pattern_cases pattern_out_param pattern_out_param_optional_var
%type <ob> pattern_out_param_list pattern_out_param_list_optional_var collection_pattern_expr_list tuple_pattern_item_list const_pattern_expr_list

%%

parse_goal
    : program_file

    | unit_file

    | parts

	| tkShortProgram stmt_list

	| tkShortSFProgram stmt_list

    ;

parts
    : tkParseModeExpression expr

    | tkParseModeExpression tkType type_decl_identifier

    | tkParseModeType variable_as_type

	| tkParseModeStatement stmt_or_expression


    ;

stmt_or_expression
    : expr

    | assignment

    | var_stmt

    ;

optional_head_compiler_directives
    :

    |  head_compiler_directives

    ;

head_compiler_directives
    : one_compiler_directive

    |  head_compiler_directives one_compiler_directive

    ;

one_compiler_directive
    : tkDirectiveName tkIdentifier

    | tkDirectiveName tkStringLiteral

    ;

program_file
    : program_header optional_head_compiler_directives uses_clause program_block optional_tk_point

	;


optional_tk_point
    : tkPoint

    | tkSemiColon

    | tkColon

    | tkComma

    | tkDotDot

    |
    ;

program_header
    :

    | tkProgram identifier program_heading_2

    ;

program_heading_2
    : tkSemiColon

    | tkRoundOpen program_param_list tkRoundClose tkSemiColon

    ;

program_param_list
    : program_param

    | program_param_list tkComma program_param

    ;

program_param
    : identifier

    ;

program_block
    : program_decl_sect_list compound_stmt
    ;

program_decl_sect_list
    : decl_sect_list

    ;

ident_or_keyword_pointseparator_list
    : identifier_or_keyword

    | ident_or_keyword_pointseparator_list tkPoint identifier_or_keyword
    ;

uses_clause
    :

    | uses_clause tkUses used_units_list tkSemiColon

    ;

used_units_list
    : used_unit_name

    | used_units_list tkComma used_unit_name

    ;

used_unit_name
    : ident_or_keyword_pointseparator_list

    | ident_or_keyword_pointseparator_list tkIn tkStringLiteral

    ;

unit_file
    : attribute_declarations unit_header interface_part implementation_part initialization_part tkPoint

    | attribute_declarations unit_header abc_interface_part initialization_part tkPoint

    ;

unit_header
    : unit_key_word unit_name tkSemiColon optional_head_compiler_directives

    | tkNamespace ident_or_keyword_pointseparator_list tkSemiColon optional_head_compiler_directives

    ;

unit_key_word
    : tkUnit

    | tkLibrary

    ;

unit_name
    : identifier

    ;

interface_part
    : tkInterface uses_clause interface_decl_sect_list

    ;

implementation_part
    : tkImplementation uses_clause decl_sect_list

	;

abc_interface_part
    : uses_clause decl_sect_list
    ;

initialization_part
    : tkEnd

    | tkInitialization stmt_list tkEnd

    | tkInitialization stmt_list tkFinalization stmt_list tkEnd

    | tkBegin stmt_list tkEnd

    ;

interface_decl_sect_list
    : int_decl_sect_list1
	;

int_decl_sect_list1
    :
    | int_decl_sect_list1 int_decl_sect

    ;

decl_sect_list
    : decl_sect_list1
	;

decl_sect_list1
    :
    | decl_sect_list1 decl_sect
	;

inclass_decl_sect_list
    : inclass_decl_sect_list1
	;

inclass_decl_sect_list1
    :
    | inclass_decl_sect_list1 abc_decl_sect
	;

int_decl_sect
    : const_decl_sect

    | res_str_decl_sect

    | type_decl_sect

    | var_decl_sect

    | int_proc_header

    | int_func_header

    ;

decl_sect
    : label_decl_sect

    | const_decl_sect

    | res_str_decl_sect

    | type_decl_sect

    | var_decl_sect

    | proc_func_constr_destr_decl_with_attr

    ;


proc_func_constr_destr_decl
	: proc_func_decl

	| constr_destr_decl

	;

proc_func_constr_destr_decl_with_attr
	: attribute_declarations proc_func_constr_destr_decl
	;

abc_decl_sect
    : label_decl_sect

    | const_decl_sect

    | res_str_decl_sect

    | type_decl_sect

    | var_decl_sect

    ;

int_proc_header
    : attribute_declarations proc_header
    | attribute_declarations proc_header tkForward tkSemiColon
    ;

int_func_header
    : attribute_declarations func_header
    | attribute_declarations func_header tkForward tkSemiColon
    ;

label_decl_sect
    : tkLabel label_list tkSemiColon
    ;

label_list
    : label_name
    | label_list tkComma label_name
    ;

label_name
    : tkInteger
    | identifier
    ;

const_decl_sect
    : tkConst const_decl
    | const_decl_sect const_decl
    ;

res_str_decl_sect
    : tkResourceString const_decl
    | res_str_decl_sect const_decl
    ;

type_decl_sect
    : tkType type_decl
    | type_decl_sect type_decl
    ;

var_decl_with_assign_var_tuple
	: var_decl
	| tkRoundOpen identifier tkComma ident_list tkRoundClose tkAssign expr_l1 tkSemiColon
	;

var_decl_sect
    : tkVar var_decl_with_assign_var_tuple
    | tkEvent var_decl_with_assign_var_tuple
    | var_decl_sect var_decl_with_assign_var_tuple
    ;

const_decl
    : only_const_decl tkSemiColon

    ;

only_const_decl
    : const_name tkEqual init_const_expr

    | const_name tkColon type_ref tkEqual typed_const

    ;

init_const_expr
    : const_expr

    | array_const

    ;

const_name
    : identifier

    ;

expr_l1_list
    : expr_l1

    | expr_l1_list tkComma expr_l1

    ;

const_expr
    : const_simple_expr

    | const_simple_expr const_relop const_simple_expr

    | question_constexpr

    ;

question_constexpr
    : const_expr tkQuestion const_expr tkColon const_expr

    ;

const_relop
    : tkEqual

    | tkNotEqual

    | tkLower

    | tkGreater

    | tkLowerEqual

    | tkGreaterEqual

    | tkIn

    ;

const_simple_expr
    : const_term

    | const_simple_expr const_addop const_term

    ;

const_addop
    : tkPlus

    | tkMinus

    | tkOr

    | tkXor

    ;

as_is_constexpr
    : const_term typecast_op simple_or_template_type_reference

    ;

power_constexpr
    : const_factor_without_unary_op tkStarStar const_factor

    | const_factor_without_unary_op tkStarStar power_constexpr

    | sign power_constexpr

    ;

const_term
    : const_factor

    | as_is_constexpr

    | power_constexpr

    | const_term const_mulop const_factor

    | const_term const_mulop power_constexpr

    ;

const_mulop
    : tkStar

    | tkSlash

    | tkDiv

    | tkMod

    | tkShl

    | tkShr

    | tkAnd

    ;

const_factor_without_unary_op
	: const_variable

	| tkRoundOpen const_expr tkRoundClose

	;

const_factor
    : const_variable

    | const_set

    | tkNil

    | tkAddressOf const_factor

    | tkRoundOpen const_expr tkRoundClose

    | tkNot const_factor

    | sign const_factor

    | new_expr

    ;

const_set
    : tkSquareOpen elem_list tkSquareClose

    | tkVertParen elem_list tkVertParen

    ;

sign
    : tkPlus

    | tkMinus

    ;

const_variable
    : identifier

    | literal

    | unsigned_number

    | tkInherited identifier

    | sizeof_expr

    | typeof_expr

    | const_variable const_variable_2

    | const_variable tkAmpersend template_type_params

    | const_variable tkSquareOpen format_const_expr tkSquareClose

    ;

const_variable_2
    : tkPoint identifier_or_keyword

    | tkDeref

    | tkRoundOpen optional_const_func_expr_list tkRoundClose

    | tkSquareOpen const_elem_list tkSquareClose

    ;

optional_const_func_expr_list
    : expr_list

    |

    ;

const_elem_list
    : const_elem_list1

    |
    ;

const_elem_list1
    : const_elem

    | const_elem_list1 tkComma const_elem

    ;

const_elem
    : const_expr

    | const_expr tkDotDot const_expr

    ;

unsigned_number
    : tkInteger

    | tkHex

    | tkFloat

    ;

typed_const
    : const_expr

    | array_const

    | record_const

    ;

array_const
    : tkRoundOpen typed_const_list tkRoundClose
    ;

typed_const_list
	:
	| typed_const_list1

	;

typed_const_list1
    : typed_const_plus

    | typed_const_list1 tkComma typed_const_plus

	;

record_const
    : tkRoundOpen const_field_list tkRoundClose

    ;

const_field_list
    : const_field_list_1

    | const_field_list_1 tkSemiColon

	;

const_field_list_1
    : const_field

    | const_field_list_1 tkSemiColon const_field

    ;

const_field
    : const_field_name tkColon typed_const

    ;

const_field_name
    : identifier

    ;

type_decl
    : attribute_declarations simple_type_decl

    ;

attribute_declarations
    : attribute_declaration

    | attribute_declarations attribute_declaration

    |

    ;

attribute_declaration
    : tkSquareOpen one_or_some_attribute tkSquareClose

    ;

one_or_some_attribute
    : one_attribute

    | one_or_some_attribute tkComma one_attribute

    ;

one_attribute
    : attribute_variable

    | identifier tkColon attribute_variable

    ;

simple_type_decl
    : type_decl_identifier tkEqual type_decl_type tkSemiColon

    | template_identifier_with_equal type_decl_type tkSemiColon

    ;

type_decl_identifier
    : identifier

    | identifier template_arguments

	;

template_identifier_with_equal
    : identifier tkLower ident_list tkGreaterEqual

    ;

type_decl_type
    : type_ref

    | object_type

    ;

simple_type_question
	: simple_type tkQuestion

	| template_type tkQuestion

	;

type_ref
    : simple_type

	| simple_type_question

    | string_type

    | pointer_type

    | structured_type

    | procedural_type

    | template_type

	    ;

template_type
    : simple_type_identifier template_type_params

    ;

template_type_params
    : tkLower template_param_list tkGreater

    ;

template_type_empty_params
    :   tkNotEqual

    |   tkLower template_empty_param_list tkGreater

    ;

template_param_list
    : template_param

    | template_param_list tkComma template_param

    ;

template_empty_param_list
    : template_empty_param

    | template_empty_param_list tkComma template_empty_param

    ;

template_empty_param
    :

    ;

template_param
    : simple_type

    | simple_type tkQuestion

    | structured_type

    | procedural_type

    | template_type

    ;

simple_type
    : range_expr

    | range_expr tkDotDot range_expr

    | tkRoundOpen enumeration_id_list tkRoundClose

    ;

range_expr
    : range_term

    | range_expr const_addop range_term

    ;

range_term
    : range_factor

    | range_term const_mulop range_factor

    ;

range_factor
    : simple_type_identifier

    | unsigned_number

    | sign range_factor

    | literal

    | range_factor tkRoundOpen const_elem_list tkRoundClose

    ;

simple_type_identifier
    : identifier

    | simple_type_identifier tkPoint identifier_or_keyword

    ;

enumeration_id_list
    : enumeration_id tkComma enumeration_id

    | enumeration_id_list tkComma enumeration_id

	;

enumeration_id
    : type_ref

    | type_ref tkEqual expr

    ;

pointer_type
    : tkDeref fptype

    ;

structured_type
    : unpacked_structured_type

    | tkPacked unpacked_structured_type

    ;

unpacked_structured_type
    : array_type

    | record_type

    | set_type

    | file_type

    | sequence_type

    ;

sequence_type
	: tkSequence tkOf type_ref

	;

array_type
    : tkArray tkSquareOpen simple_type_list tkSquareClose tkOf type_ref

    | unsized_array_type

    ;

unsized_array_type
    : tkArray tkOf type_ref

    ;

simple_type_list
    : simple_type_or_

    | simple_type_list tkComma simple_type_or_

    ;

simple_type_or_
    : simple_type

    |

    ;

set_type
    : tkSet tkOf type_ref

    ;

file_type
    : tkFile tkOf type_ref

    | tkFile

    ;

string_type
    : tkIdentifier tkSquareOpen const_expr tkSquareClose

    ;

procedural_type
    : procedural_type_kind

    ;

procedural_type_kind
    : proc_type_decl

    ;

proc_type_decl
    : tkProcedure fp_list

    | tkFunction fp_list tkColon fptype

	| simple_type_identifier tkArrow template_param

	| template_type tkArrow template_param

    | tkRoundOpen tkRoundClose tkArrow template_param

    | tkRoundOpen enumeration_id_list tkRoundClose tkArrow template_param

    | simple_type_identifier tkArrow tkRoundOpen tkRoundClose // ��� 2 ������� ������ ���������� � ���� template_param - ����� ��������

    | template_type tkArrow tkRoundOpen tkRoundClose

    | tkRoundOpen tkRoundClose tkArrow tkRoundOpen tkRoundClose

    | tkRoundOpen enumeration_id_list tkRoundClose tkArrow tkRoundOpen tkRoundClose

    ;

object_type
    : class_attributes class_or_interface_keyword optional_base_classes optional_where_section optional_component_list_seq_end

    ;

record_type
    : tkRecord optional_base_classes optional_where_section member_list_section tkEnd
    ;

class_attribute
    : tkSealed

    | tkPartial

    | tkAbstract

    | tkAuto

    | tkStatic

    ;

class_attributes
	:

	| class_attributes1

	;

class_attributes1
	: class_attribute

	| class_attributes1 class_attribute

	;

class_or_interface_keyword
    : tkClass

    | tkInterface

    | tkTemplate

    | tkTemplate tkClass

    | tkTemplate tkRecord

    | tkTemplate tkInterface

    ;

optional_component_list_seq_end
    :

    | member_list_section tkEnd

    ;

optional_base_classes
    :
    | tkRoundOpen base_classes_names_list tkRoundClose

    ;

base_classes_names_list
    : base_class_name

    | base_classes_names_list tkComma base_class_name

    ;

base_class_name
    : simple_type_identifier

    | template_type

    ;

template_arguments
    : tkLower ident_list tkGreater

    ;

optional_where_section
    :

    | where_part_list

    ;

where_part_list
    : where_part

    | where_part_list where_part

    ;

where_part
    : tkWhere ident_list tkColon type_ref_and_secific_list tkSemiColon

    ;

type_ref_and_secific_list
    : type_ref_or_secific

    | type_ref_and_secific_list tkComma type_ref_or_secific

    ;

type_ref_or_secific
    : type_ref

    | tkClass

    | tkRecord

    | tkConstructor

    ;

member_list_section
    : member_list

    | member_list_section ot_visibility_specifier member_list

    ;

ot_visibility_specifier
    : tkInternal

    | tkPublic

    | tkProtected

    | tkPrivate

    ;

member_list
    :

    | field_or_const_definition_list optional_semicolon

    | method_decl_list

    | field_or_const_definition_list tkSemiColon method_decl_list

	;

ident_list
    : identifier

    | ident_list tkComma identifier

    ;

optional_semicolon
    :

    | tkSemiColon

    ;

field_or_const_definition_list
    : field_or_const_definition

    | field_or_const_definition_list tkSemiColon field_or_const_definition

    ;

field_or_const_definition
    : attribute_declarations simple_field_or_const_definition

    ;

method_decl_list
    : method_or_property_decl

    | method_decl_list method_or_property_decl

    ;

method_or_property_decl
	: method_decl_withattr

	| property_definition

	;

simple_field_or_const_definition
    : tkConst only_const_decl

    | field_definition

    | class_or_static field_definition

    ;

class_or_static
    : tkStatic

    | tkClass

    ;

field_definition
    : var_decl_part

    | tkEvent ident_list tkColon type_ref

    ;

method_decl_withattr
    : attribute_declarations method_header

    | attribute_declarations method_decl

    ;

method_decl
    : inclass_proc_func_decl

    | inclass_constr_destr_decl

    ;

method_header
    : class_or_static method_procfunc_header

    | method_procfunc_header

    | constr_destr_header

    ;

method_procfunc_header
    : proc_func_header

    ;

proc_func_header
    : proc_header

    | func_header

    ;

constr_destr_header
    : tkConstructor optional_proc_name fp_list optional_method_modificators

    | class_or_static tkConstructor optional_proc_name fp_list optional_method_modificators

    | tkDestructor optional_proc_name fp_list optional_method_modificators

    ;

optional_proc_name
    : proc_name

    |

    ;

qualified_identifier
    : identifier

    | visibility_specifier

    | qualified_identifier tkPoint identifier

    | qualified_identifier tkPoint visibility_specifier

    ;

property_definition
    : attribute_declarations simple_property_definition

    ;

simple_property_definition
    : tkProperty qualified_identifier property_interface property_specifiers tkSemiColon array_defaultproperty

    | tkProperty qualified_identifier property_interface property_specifiers tkSemiColon property_modificator tkSemiColon array_defaultproperty

    | class_or_static tkProperty qualified_identifier property_interface property_specifiers tkSemiColon array_defaultproperty

    | class_or_static tkProperty qualified_identifier property_interface property_specifiers tkSemiColon property_modificator tkSemiColon array_defaultproperty

	| tkAuto tkProperty qualified_identifier property_interface optional_property_initialization tkSemiColon

	| class_or_static tkAuto tkProperty qualified_identifier property_interface optional_property_initialization tkSemiColon

    ;

optional_property_initialization
	: tkAssign expr
	|
	;

array_defaultproperty
    :

    | tkDefault tkSemiColon

    ;

property_interface
    : property_parameter_list tkColon fptype

    ;

property_parameter_list
    :

    | tkSquareOpen parameter_decl_list tkSquareClose

    ;

parameter_decl_list
    : parameter_decl

    | parameter_decl_list tkSemiColon parameter_decl

    ;

parameter_decl
    : ident_list tkColon fptype

    ;


optional_read_expr
    : expr_with_func_decl_lambda

    |

    ;

property_specifiers
    :
    | tkRead optional_read_expr write_property_specifiers

    | tkWrite unlabelled_stmt read_property_specifiers

    ;
write_property_specifiers
    :
    |  tkWrite unlabelled_stmt

    ;

read_property_specifiers
    :
    |  tkRead optional_read_expr

    ;

var_decl
    : var_decl_part tkSemiColon

    ;

tkAssignOrEqual
	: tkAssign
	| tkEqual
	;

var_decl_part
    : ident_list tkColon type_ref

    | ident_list tkAssign expr_with_func_decl_lambda

    | ident_list tkColon type_ref tkAssignOrEqual typed_var_init_expression

    ;

typed_var_init_expression
	: typed_const_plus

	| expl_func_decl_lambda

    | identifier tkArrow lambda_function_body

    | tkRoundOpen tkRoundClose lambda_type_ref tkArrow lambda_function_body

    | tkRoundOpen typed_const_list tkRoundClose tkArrow lambda_function_body

	;

typed_const_plus
    : typed_const

    | default_expr

    ;

constr_destr_decl
    : constr_destr_header block

    | tkConstructor optional_proc_name fp_list tkAssign unlabelled_stmt tkSemiColon

    | class_or_static tkConstructor optional_proc_name fp_list tkAssign unlabelled_stmt tkSemiColon

    ;

inclass_constr_destr_decl
    : constr_destr_header inclass_block

    | tkConstructor optional_proc_name fp_list tkAssign unlabelled_stmt tkSemiColon

    | class_or_static tkConstructor optional_proc_name fp_list tkAssign unlabelled_stmt tkSemiColon

    ;

proc_func_decl
    : proc_func_decl_noclass

    | class_or_static proc_func_decl_noclass

    ;

proc_func_decl_noclass
    : proc_func_header proc_func_external_block

	| tkFunction func_name fp_list tkColon fptype optional_method_modificators1 tkAssign expr_l1 tkSemiColon

	| tkFunction func_name fp_list optional_method_modificators1 tkAssign expr_l1 tkSemiColon

	| tkFunction func_name fp_list tkColon fptype optional_method_modificators1 tkAssign func_decl_lambda tkSemiColon

	| tkFunction func_name fp_list optional_method_modificators1 tkAssign func_decl_lambda tkSemiColon

	| tkProcedure proc_name fp_list optional_method_modificators1 tkAssign unlabelled_stmt tkSemiColon

	| proc_func_header tkForward tkSemiColon

    ;

inclass_proc_func_decl
    : inclass_proc_func_decl_noclass

    | class_or_static inclass_proc_func_decl_noclass

    ;

inclass_proc_func_decl_noclass
    : proc_func_header inclass_block

	| tkFunction func_name fp_list tkColon fptype optional_method_modificators1 tkAssign expr_l1_func_decl_lambda tkSemiColon

	| tkFunction func_name fp_list optional_method_modificators1 tkAssign expr_l1_func_decl_lambda tkSemiColon

	| tkProcedure proc_name fp_list optional_method_modificators1 tkAssign unlabelled_stmt tkSemiColon

    ;

proc_func_external_block
    : block

    | external_block

    ;

proc_name
    : func_name

    ;

func_name
    : func_meth_name_ident

    | func_class_name_ident_list tkPoint func_meth_name_ident

    ;

func_class_name_ident
    : func_name_with_template_args

    ;

func_class_name_ident_list
	: func_class_name_ident

	| func_class_name_ident_list tkPoint func_class_name_ident

	;

func_meth_name_ident
    : func_name_with_template_args

    | operator_name_ident

    | operator_name_ident template_arguments

    ;

func_name_with_template_args
    : func_name_ident

    | func_name_ident template_arguments

	;

func_name_ident
    : identifier
    ;

proc_header
    : tkProcedure proc_name fp_list optional_method_modificators optional_where_section

    ;

func_header
    : tkFunction func_name fp_list optional_method_modificators optional_where_section

	| tkFunction func_name fp_list tkColon fptype optional_method_modificators optional_where_section

    ;

external_block
    : tkExternal external_directive_ident tkName external_directive_ident tkSemiColon

    | tkExternal external_directive_ident tkSemiColon

    | tkExternal tkSemiColon

    ;

external_directive_ident
    : identifier

    | literal

    ;

block
    : decl_sect_list compound_stmt tkSemiColon

    ;

inclass_block
    : inclass_decl_sect_list compound_stmt tkSemiColon

    | external_block

    ;

fp_list
    :

    | tkRoundOpen tkRoundClose

    | tkRoundOpen fp_sect_list tkRoundClose

    ;

fp_sect_list
    : fp_sect

    | fp_sect_list tkSemiColon fp_sect

    ;

fp_sect
    : attribute_declarations simple_fp_sect

    ;

simple_fp_sect
    : param_name_list tkColon fptype

    | tkVar param_name_list tkColon fptype

    | tkConst param_name_list tkColon fptype

    | tkParams param_name_list tkColon fptype

    | param_name_list tkColon fptype tkAssign expr

    | tkVar param_name_list tkColon fptype tkAssign expr

    | tkConst param_name_list tkColon fptype tkAssign expr

    ;

param_name_list
    : param_name

    | param_name_list tkComma param_name

    ;

param_name
    : identifier

    ;

fptype
    : type_ref

    ;

fptype_noproctype
    : simple_type

    | string_type

    | pointer_type

    | structured_type

    | template_type

	    ;

stmt
    : unlabelled_stmt

    | label_name tkColon stmt

    ;

unlabelled_stmt
    :

    | assignment

    | proc_call

    | goto_stmt

    | compound_stmt

    | if_stmt

    | case_stmt

    | repeat_stmt

    | while_stmt

    | for_stmt

    | with_stmt

    | inherited_message

    | try_stmt

    | raise_stmt

    | foreach_stmt

    | var_stmt

    | expr_as_stmt

    | lock_stmt

	| yield_stmt

	| yield_sequence_stmt

	| loop_stmt

    | match_with

    ;

loop_stmt
	: tkLoop expr_l1 tkDo unlabelled_stmt

	;

yield_stmt
	: tkYield expr_l1_func_decl_lambda

	;

yield_sequence_stmt
	: tkYield tkSequence expr_l1_func_decl_lambda

	;

var_stmt
    : tkVar var_decl_part

    | tkRoundOpen tkVar identifier tkComma var_ident_list tkRoundClose tkAssign expr

    | tkVar tkRoundOpen identifier tkComma ident_list tkRoundClose tkAssign expr

    ;

assignment
    : var_reference assign_operator expr_with_func_decl_lambda

    | tkRoundOpen variable tkComma variable_list tkRoundClose assign_operator expr

    | variable tkQuestionSquareOpen format_expr tkSquareClose assign_operator expr

    ;

variable_list
	: variable

	| variable_list tkComma variable

	;

var_ident_list
	: tkVar identifier

	| var_ident_list tkComma tkVar identifier

	;

proc_call
    : var_reference

    ;

goto_stmt
    : tkGoto label_name

    ;

compound_stmt
    : tkBegin stmt_list tkEnd

    ;

stmt_list
    : stmt

    | stmt_list tkSemiColon stmt

    ;

if_stmt
	: tkIf expr_l1 tkThen unlabelled_stmt

	| tkIf expr_l1 tkThen unlabelled_stmt tkElse unlabelled_stmt

    ;

match_with
    : tkMatch expr_l1 tkWith pattern_cases else_case tkEnd

    | tkMatch expr_l1 tkWith pattern_cases tkSemiColon else_case tkEnd

    ;

pattern_cases
    : pattern_case

    | pattern_cases tkSemiColon pattern_case

    ;

pattern_case
    : pattern_optional_var tkWhen expr_l1 tkColon unlabelled_stmt

    | deconstruction_or_const_pattern tkColon unlabelled_stmt

	| collection_pattern tkColon unlabelled_stmt

	| tuple_pattern tkWhen expr_l1 tkColon unlabelled_stmt

	| tuple_pattern tkColon unlabelled_stmt

    ;

case_stmt
    : tkCase expr_l1 tkOf case_list else_case tkEnd

	| tkCase expr_l1 tkOf case_list tkSemiColon else_case tkEnd

	| tkCase expr_l1 tkOf else_case tkEnd

    ;

case_list
    : case_item

    | case_list tkSemiColon case_item

    ;

case_item
    : case_label_list tkColon unlabelled_stmt

    ;

case_label_list
    : case_label

    |  case_label_list tkComma case_label

    ;

case_label
    : const_elem

    ;

else_case
    :

    |  tkElse stmt_list

    ;

repeat_stmt
    : tkRepeat stmt_list tkUntil expr

	;

while_stmt
    : tkWhile expr_l1 optional_tk_do unlabelled_stmt

    ;

optional_tk_do
    : tkDo

    |

    ;

lock_stmt
    : tkLock expr_l1 tkDo unlabelled_stmt

	;

foreach_stmt
    : tkForeach identifier foreach_stmt_ident_dype_opt tkIn expr_l1 tkDo unlabelled_stmt

    | tkForeach tkVar identifier tkColon type_ref tkIn expr_l1 tkDo unlabelled_stmt

    | tkForeach tkVar identifier tkIn expr_l1 tkDo unlabelled_stmt

    ;

foreach_stmt_ident_dype_opt
    : tkColon type_ref

    |
    ;

for_stmt
    : tkFor optional_var identifier for_stmt_decl_or_assign expr_l1 for_cycle_type expr_l1 optional_tk_do unlabelled_stmt

	;

optional_var
    : tkVar

    |

    ;

for_stmt_decl_or_assign
    : tkAssign
    | tkColon simple_type_identifier tkAssign

    ;

for_cycle_type
    : tkTo

    | tkDownto

    ;

with_stmt
    : tkWith expr_list tkDo unlabelled_stmt

    ;

inherited_message
    : tkInherited

    ;

try_stmt
    : tkTry stmt_list try_handler

    ;

try_handler
    : tkFinally stmt_list tkEnd

    | tkExcept exception_block tkEnd

    ;

exception_block
    : exception_handler_list exception_block_else_branch

    |  exception_handler_list tkSemiColon exception_block_else_branch

    |  stmt_list

    ;

exception_handler_list
    : exception_handler

    | exception_handler_list tkSemiColon exception_handler

    ;

exception_block_else_branch
    :

    |  tkElse stmt_list

    ;

exception_handler
    : tkOn exception_identifier tkDo unlabelled_stmt

    ;

exception_identifier
    : exception_class_type_identifier

    | exception_variable tkColon exception_class_type_identifier

    ;

exception_class_type_identifier
    : simple_type_identifier

    ;

exception_variable
    : identifier

    ;

raise_stmt
    : tkRaise

    | tkRaise expr

    ;

expr_list
    : expr_with_func_decl_lambda

    | expr_list tkComma expr_with_func_decl_lambda

    ;

expr_as_stmt
    : allowable_expr_as_stmt

    ;

allowable_expr_as_stmt
    : new_expr

    ;

expr_with_func_decl_lambda
	: expr

    | func_decl_lambda

    ;

expr
    : expr_l1

    | format_expr

    ;

expr_l1
    : expr_dq

    | question_expr

    | new_question_expr

    ;

expr_l1_for_question_expr
    : expr_dq

    | question_expr

    ;

expr_l1_for_new_question_expr
    : expr_dq

    | new_question_expr

    ;

expr_l1_func_decl_lambda
	: expr_l1

    | func_decl_lambda

    ;

expr_l1_for_lambda
    : expr_dq

    | question_expr

    | func_decl_lambda

    ;

expr_dq
	: relop_expr

	| expr_dq tkDoubleQuestion relop_expr

	;

sizeof_expr
    : tkSizeOf tkRoundOpen simple_or_template_type_reference tkRoundClose

    ;

typeof_expr
    : tkTypeOf tkRoundOpen simple_or_template_type_reference tkRoundClose

    | tkTypeOf tkRoundOpen empty_template_type_reference tkRoundClose

    ;

question_expr
    : expr_l1_for_question_expr tkQuestion expr_l1_for_question_expr tkColon expr_l1_for_question_expr

    ;

new_question_expr
	: tkIf expr_l1_for_new_question_expr tkThen expr_l1_for_new_question_expr tkElse expr_l1_for_new_question_expr
	;


empty_template_type_reference
    : simple_type_identifier template_type_empty_params

    | simple_type_identifier tkAmpersend template_type_empty_params

    ;

simple_or_template_type_reference
    : simple_type_identifier

    | simple_type_identifier template_type_params

    | simple_type_identifier tkAmpersend template_type_params

    ;

optional_array_initializer
    : tkRoundOpen typed_const_list tkRoundClose

    |
    ;

new_expr
    : tkNew simple_or_template_type_reference optional_expr_list_with_bracket

    | tkNew simple_or_template_type_reference tkSquareOpen optional_expr_list tkSquareClose optional_array_initializer

    | tkNew tkClass tkRoundOpen list_fields_in_unnamed_object tkRoundClose

    ;

field_in_unnamed_object
	: identifier tkAssign relop_expr

	| relop_expr

	;

list_fields_in_unnamed_object
	: field_in_unnamed_object

	| list_fields_in_unnamed_object tkComma field_in_unnamed_object

	;

optional_expr_list_with_bracket
    :

    |  tkRoundOpen optional_expr_list tkRoundClose

    ;

relop_expr
    : simple_expr

    | relop_expr relop simple_expr

    | relop_expr relop new_question_expr

    | is_type_expr tkRoundOpen pattern_out_param_list tkRoundClose

    ;

pattern
    : simple_or_template_type_reference tkRoundOpen pattern_out_param_list tkRoundClose

    ;

pattern_optional_var
    : simple_or_template_type_reference tkRoundOpen pattern_out_param_list_optional_var tkRoundClose

    ;

deconstruction_or_const_pattern
    : simple_or_template_type_reference tkRoundOpen pattern_out_param_list_optional_var tkRoundClose

	| const_pattern_expr_list

    ;

const_pattern_expr_list
	: const_pattern_expression

	| const_pattern_expr_list tkComma const_pattern_expression

	;

const_pattern_expression
	: literal_or_number

	| simple_or_template_type_reference

	| tkNil

	| sizeof_expr

    | typeof_expr

	;

collection_pattern
	: tkSquareOpen collection_pattern_expr_list tkSquareClose

	;

collection_pattern_expr_list
	: collection_pattern_list_item

	| collection_pattern_expr_list tkComma collection_pattern_list_item

	;

collection_pattern_list_item
	: literal_or_number

	| collection_pattern_var_item

	| tkUnderscore

	| pattern_optional_var

	| collection_pattern

	| tuple_pattern

	| tkDotDot

	;

collection_pattern_var_item
    : tkVar identifier

    ;

tuple_pattern
	: tkRoundOpen tuple_pattern_item_list tkRoundClose

    ;

tuple_pattern_item
	: tkUnderscore

	| literal_or_number

	| sign literal_or_number

    | tkVar identifier

	| pattern_optional_var

	| collection_pattern

	| tuple_pattern

	;

tuple_pattern_item_list
	: tuple_pattern_item

	| tuple_pattern_item_list tkComma tuple_pattern_item

	;

pattern_out_param_list_optional_var
    : pattern_out_param_optional_var

    | pattern_out_param_list_optional_var tkSemiColon pattern_out_param_optional_var

    | pattern_out_param_list_optional_var tkComma pattern_out_param_optional_var

    ;

pattern_out_param_list
    : pattern_out_param

    | pattern_out_param_list tkSemiColon pattern_out_param

    | pattern_out_param_list tkComma pattern_out_param

    ;

pattern_out_param
    : tkUnderscore

	| literal_or_number

	| tkVar identifier tkColon type_ref

    | tkVar identifier

    | pattern

	| collection_pattern

	| tuple_pattern

    ;

pattern_out_param_optional_var
	: tkUnderscore

	| literal_or_number

	| sign literal_or_number

    | identifier tkColon type_ref

    | identifier

    | tkVar identifier tkColon type_ref

    | tkVar identifier

    | pattern_optional_var

	| collection_pattern

	| tuple_pattern

    ;

simple_expr_or_nothing
	: simple_expr

	|

	;

const_expr_or_nothing
	: const_expr

	|

	;

format_expr
    : simple_expr tkColon simple_expr_or_nothing

    | tkColon simple_expr_or_nothing

    | simple_expr tkColon simple_expr_or_nothing tkColon simple_expr

    | tkColon simple_expr_or_nothing tkColon simple_expr

    ;

format_const_expr
    : const_expr tkColon const_expr_or_nothing

    | tkColon const_expr_or_nothing

    | const_expr tkColon const_expr_or_nothing tkColon const_expr

    | tkColon const_expr_or_nothing tkColon const_expr

    ;


relop
    : tkEqual

    | tkNotEqual

    | tkLower

    | tkGreater

    | tkLowerEqual

    | tkGreaterEqual

    | tkIn

    ;

simple_expr
    : term1

    | simple_expr tkDotDot term1

    ;

term1
    : term

    | term1 addop term

    | term1 addop new_question_expr

    ;

addop
    : tkPlus

    | tkMinus

    | tkOr

    | tkXor

    | tkCSharpStyleOr

    ;

typecast_op
    : tkAs

    | tkIs

    ;

as_is_expr
    : is_type_expr

    | as_expr

	;

as_expr
    : term tkAs simple_or_template_type_reference

    ;

is_type_expr
    : term tkIs simple_or_template_type_reference

    ;

power_expr
    : factor_without_unary_op tkStarStar factor

    | factor_without_unary_op tkStarStar power_expr

    | sign power_expr

    ;

term
    : factor

    | new_expr

    | power_expr

    | term mulop factor

    | term mulop power_expr

    | term mulop new_question_expr

    | as_is_expr

    ;

mulop
    : tkStar

    | tkSlash

    | tkDiv

    | tkMod

    | tkShl

    | tkShr

    | tkAnd

    ;

default_expr
    :  tkDefault tkRoundOpen simple_or_template_type_reference tkRoundClose

    ;

tuple
	 : tkRoundOpen expr_l1 tkComma expr_l1_list lambda_type_ref optional_full_lambda_fp_list tkRoundClose

    ;

factor_without_unary_op
	: literal_or_number

	| var_reference

	;

factor
    : tkNil

    | literal_or_number

    | default_expr

    | tkSquareOpen elem_list tkSquareClose

    | tkNot factor

    | sign factor

    | tkDeref factor

    | var_reference

	| tuple

	;

literal_or_number
    : literal

    | unsigned_number

	;


var_question_point
	: variable tkQuestionPoint variable

	| variable tkQuestionPoint var_question_point

	;

var_reference
    : var_address variable

    | variable

    | var_question_point

    ;

var_address
    : tkAddressOf

    | var_address tkAddressOf

    ;

attribute_variable
    : simple_type_identifier optional_expr_list_with_bracket

    | template_type optional_expr_list_with_bracket

    ;

dotted_identifier
	: identifier
	| dotted_identifier tkPoint identifier_or_keyword

	;

variable_as_type
	: dotted_identifier
	| dotted_identifier template_type_params

	;

variable_or_literal_or_number
	: variable

	| literal_or_number

	;

variable
    : identifier

    | operator_name_ident

    | tkInherited identifier

    | tkRoundOpen expr tkRoundClose

    | sizeof_expr

    | typeof_expr

    | literal_or_number tkPoint identifier_or_keyword

    | variable_or_literal_or_number tkSquareOpen expr_list tkSquareClose

    | variable tkQuestionSquareOpen format_expr tkSquareClose

    | tkVertParen elem_list tkVertParen

    | variable tkRoundOpen optional_expr_list tkRoundClose

    | variable tkPoint identifier_keyword_operatorname

    | tuple tkPoint identifier_keyword_operatorname

    | variable tkDeref

    | variable tkAmpersend template_type_params

    ;

optional_expr_list
    : expr_list

    |

    ;

elem_list
    : elem_list1

    |

    ;

elem_list1
    : elem

    | elem_list1 tkComma elem

    ;

elem
    : expr

    | expr tkDotDot expr

    ;

one_literal
    : tkStringLiteral

    | tkAsciiChar

    ;

literal
    :literal_list

    | tkFormatStringLiteral

	;

literal_list
    : one_literal

    | literal_list one_literal

    ;

operator_name_ident
    : tkOperator overload_operator

	;

optional_method_modificators
    : tkSemiColon

    | tkSemiColon meth_modificators tkSemiColon

    ;

optional_method_modificators1
    :

    | tkSemiColon meth_modificators

    ;

meth_modificators
    : meth_modificator

    | meth_modificators tkSemiColon meth_modificator

    ;

identifier
    : tkIdentifier

    | property_specifier_directives

    | non_reserved

    ;

identifier_or_keyword
    : identifier

    | keyword

    | reserved_keyword

    ;

identifier_keyword_operatorname
    : identifier

    | keyword

    | operator_name_ident

    ;

meth_modificator
    : tkAbstract

    | tkOverload

    | tkReintroduce

    | tkOverride

    | tkExtensionMethod

    | tkVirtual

    ;

property_modificator
	: tkVirtual

	| tkOverride

    | tkAbstract

    | tkReintroduce

	;

property_specifier_directives
    : tkRead

    | tkWrite

    ;

non_reserved
    : tkName

    | tkNew

    ;

visibility_specifier
    : tkInternal

    | tkPublic

    | tkProtected

    | tkPrivate

    ;

keyword
    : visibility_specifier

    | tkSealed

    | tkTemplate

    | tkOr

    | tkTypeOf

    | tkSizeOf

    | tkDefault

    | tkWhere

    | tkXor

    | tkAnd

    | tkDiv

    | tkMod

    | tkShl

    | tkShr

    | tkNot

    | tkAs

    | tkIn

    | tkIs

    | tkArray

    | tkSequence

    | tkBegin

    | tkCase

    | tkClass

    | tkConst

    | tkConstructor

    | tkDestructor

    | tkDownto

    | tkDo

    | tkElse

    | tkEnd

    | tkExcept

    | tkFile

	| tkAuto

    | tkFinalization

    | tkFinally

    | tkFor

    | tkForeach

    | tkFunction

    | tkIf

    | tkImplementation

    | tkInherited

    | tkInitialization

    | tkInterface

    | tkProcedure

    | tkProperty

    | tkRaise

    | tkRecord

    | tkRepeat

    | tkSet

    | tkTry

    | tkType

    | tkStatic

    | tkThen

    | tkTo

    | tkUntil

    | tkUses

    | tkVar

    | tkWhile

    | tkWith

    | tkNil

    | tkGoto

    | tkOf

    | tkLabel

    | tkProgram

    | tkUnit

    | tkLibrary

    | tkNamespace

    | tkExternal

    | tkParams

	| tkEvent

	| tkYield

    | tkMatch

    | tkWhen

    | tkPartial

    | tkAbstract

    | tkLock

    | tkImplicit

    | tkExplicit

    | tkOn

    | tkVirtual

    | tkOverride

    | tkLoop

    | tkExtensionMethod

    | tkOverload

    | tkReintroduce

    | tkForward

    ;

reserved_keyword
    : tkOperator

    ;

overload_operator
    : tkMinus

    | tkPlus

    | tkSlash

    | tkStar

    | tkEqual

    | tkGreater

    | tkGreaterEqual

    | tkLower

    | tkLowerEqual

    | tkNotEqual

    | tkOr

    | tkXor

    | tkAnd

    | tkDiv

    | tkMod

    | tkShl

    | tkShr

    | tkNot

    | tkIn

    | tkImplicit

    | tkExplicit

    | assign_operator

    | tkStarStar

    ;

assign_operator
    : tkAssign

    | tkPlusEqual

    | tkMinusEqual

    | tkMultEqual

    | tkDivEqual

    ;

func_decl_lambda
	: identifier tkArrow lambda_function_body

    | tkRoundOpen tkRoundClose lambda_type_ref_noproctype tkArrow lambda_function_body

	| tkRoundOpen identifier tkColon fptype tkRoundClose lambda_type_ref_noproctype tkArrow lambda_function_body

	| tkRoundOpen identifier tkSemiColon full_lambda_fp_list tkRoundClose lambda_type_ref_noproctype tkArrow lambda_function_body

	| tkRoundOpen identifier tkColon fptype tkSemiColon full_lambda_fp_list tkRoundClose lambda_type_ref_noproctype tkArrow lambda_function_body

    | tkRoundOpen expr_l1 tkComma expr_l1_list lambda_type_ref optional_full_lambda_fp_list tkRoundClose rem_lambda

	| expl_func_decl_lambda

	;

optional_full_lambda_fp_list
	:
	| tkSemiColon full_lambda_fp_list

	;

rem_lambda
	: lambda_type_ref_noproctype tkArrow lambda_function_body

	;

expl_func_decl_lambda
	: tkFunction lambda_type_ref_noproctype tkArrow lambda_function_body // SSM 11.08.20 ������� _noproctype � 3 �����������

	| tkFunction tkRoundOpen tkRoundClose lambda_type_ref_noproctype tkArrow lambda_function_body

	| tkFunction tkRoundOpen full_lambda_fp_list tkRoundClose lambda_type_ref_noproctype tkArrow lambda_function_body

	| tkProcedure tkArrow lambda_procedure_body

	| tkProcedure tkRoundOpen tkRoundClose tkArrow lambda_procedure_body

	| tkProcedure tkRoundOpen full_lambda_fp_list tkRoundClose tkArrow lambda_procedure_body

	;

full_lambda_fp_list
	: lambda_simple_fp_sect
	| full_lambda_fp_list tkSemiColon lambda_simple_fp_sect

	;

lambda_simple_fp_sect
    : ident_list lambda_type_ref

    ;

lambda_type_ref
	:

	| tkColon fptype

	;

lambda_type_ref_noproctype
	:

	| tkColon fptype_noproctype

	;

common_lambda_body
	: compound_stmt

    | if_stmt

	| while_stmt

	| repeat_stmt

	| for_stmt

	| foreach_stmt

	| loop_stmt

	| case_stmt

	| try_stmt

	| lock_stmt

	| raise_stmt

	| yield_stmt

	;


lambda_function_body
	: expr_l1_for_lambda

	| common_lambda_body

	;

lambda_procedure_body
	: proc_call

	| assignment

	| common_lambda_body

	;

%%