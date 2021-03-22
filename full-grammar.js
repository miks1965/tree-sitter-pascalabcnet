const PREC = {
    unary: 6,
    multiplicative: 5,
    additive: 4,
    comparative: 3,
    and: 2,
    or: 1,
}

multiplicative_operators = ['*', "/", "%"]
additive_operators = ['+', '-']
comparative_operators = ['=', '<>', '<', '<=', '>', '>=']
assignment_operators = multiplicative_operators.concat(additive_operators).map(operator => operator + '=').concat(':=')

module.exports = grammar({
    name: 'pascalabcnet',

    rules: {
        parse_goal: $ => choice(
            $.program_file,
            $.unit_file,
            $.parts,
            seq($.tkShortProgram, $.stmt_list),
            seq($.tkShortSPFProgram, $.stmt_list)
        ),

        parts: $ => choice(
            seq($.tkParseModeExpression, $.expr),
            seq($.tkParseModeExpression, $.tkType, $.type_decl_identifier),
            seq($.tkParseModeType, $.variable_as_type),
            seq($.tkParseModeStatement, $.stmt_or_expression)
        ),

        stmt_or_expression: $ => choice(
            $.expr,
            $.assignment,
            $.var_stmt
        ),

        head_compiler_directives: $ => seq(
            optional(seq(
                $.head_compiler_directives,
                $.one_compiler_directive
            )),
            $.one_compiler_directive
        ),

        one_compiler_directive: $ => choice(
            seq($.tkDirectiveName, $.tkIdentifier),
            seq($.tkDirectiveName, $.tkStringLiteral)
        ),

        program_file: $ => seq(
            optional($.program_header),
            optional($.head_compiler_directives),
            $.uses_clause,
            $.program_block,
            optional($.tk_point)
        ),

        optional_tk_point: $ => choice(
            $.tkPoint,
            $.tkSemiColon,
            $.tkColon,
            $.tkComma,
            $.tkDotDot
        ),

        // optional
        program_header: $ => seq(
            $.tkPoint,
            $.identifier,
            $.program_heading_2
        ),

        program_heading_2: $ => choice(
            $.tkSemiColon,
            seq($.tkRoundOpen,
                $.program_param_list,
                $.tkRoundClose,
                $.tkSemiColon
            )
        ),

        program_param_list: $ => seq(
            optional(seq(
                $.program_param_list,
                $.tkComma
            )),
            $.program_param
        ),

        program_param: $ => identifier,

        program_block: $ => seq(
            $.program_decl_sect_list,
            $.compound_stmt
        ),

        program_decl_sect_list: $ => decl_sect_list,

        ident_or_keyword_pointseparator_list: $ => seq(
            optional(seq(
                $.ident_or_keyword_pointseparator_list,
                $.tkPoint)),
            $.identifier_or_keyword
        ),

        uses_clause: $ => optional(seq( // разорвёт сто проц, надо смотреть ещё
            $.uses_clause,
            $.tkUses,
            $.used_units_list,
            $.tkSemiColon
        )),

        used_units_list: $ => seq(
            optional(seq(
                $.used_units_list,
                $.tkComma)),
            $.used_unit_name
        ),

        used_unit_name: $ => seq(
            $.ident_or_keyword_pointseparator_list,
            optional(seq(
                $.tkIn,
                $.tkStringLiteral
            ))
        ),

        unit_file: $ => seq(
            $.attribute_declarations,
            $.unit_header,
            choice(
                seq(
                    $.interface_part,
                    $.implementation_part
                ),
                $.abc_interface_part
            ),
            $.initialization_part,
            $.tkPoint
        ),

        unit_header: $ => seq(
            choice(
                seq(
                    $.unit_key_word,
                    $.unit_name
                ),
                seq(
                    $.tkNamespace,
                    $.ident_or_keyword_pointseparator_list
                )
            ),
            $.tkSemiColon,
            $.optional_head_compiler_directives
        ),

        unit_key_word: $ => choice(
            $.tkUnit,
            $.tkLibrary
        ),

        unit_name: $ => identifier,

        interface_part: $ => seq(
            $.tkInterface,
            $.uses_clause,
            $.interface_decl_sect_list
        ),

        implementation_part: $ => seq(
            $.tkImplementation,
            $.uses_clause,
            $.decl_sect_list
        ),

        abc_interface_part: $ => seq(
            $.uses_clause,
            $.decl_sect_list,
        ),

        initialization_part: $ => choice(
            $.tkEnd,
            seq(
                $.tkInitialization,
                $.stmt_list,
                optional(seq(
                    $.tkFinalization,
                    $.stmt_list
                )),
                $.tkEnd
            ),
            seq(
                $.tkBegin,
                $.stmt_list,
                $.tkEnd
            )
        ),

        interface_decl_sect_list: $ => int_decl_sect_list_1, // это чё ващё??

        int_decl_sect_list_1: $ => optional(seq(
            $.int_decl_sect_list_1,
            $.int_decl_sect
        )),

        decl_sect_list: $ => decl_sect_list1, // опять

        decl_sect_list1: $ => optional(seq(
            $.decl_sect_list_1,
            $.decl_sect
        )),

        inclass_decl_sect_list: $ => inclass_decl_sect_list1, // опять

        inclass_decl_sect_list1: $ => optional(seq(
            $.inclass_decl_sect_list_1,
            $.abc_decl_sect
        )),

        int_decl_sect: $ => choice(
            $.const_decl_sect,
            $.res_str_decl_sect,
            $.type_decl_sect,
            $.var_decl_sect,
            $.int_proc_header,
            $.int_func_header
        ),

        decl_sect: $ => choice(
            $.label_decl_sect,
            $.const_decl_sect,
            $.res_str_decl_sect,
            $.type_decl_sect,
            $.var_decl_sect,
            $.proc_func_constr_destr_decl_with_attr
        ),

        proc_func_constr_destr_decl: $ => choice(
            $.proc_func_decl,
            $.constr_destr_decl
        ),

        abc_decl_sect: $ => choice(
            $.label_decl_sect,
            $.const_decl_sect,
            $.res_str_decl_sect,
            $.type_decl_sect,
            $.var_decl_sect
        ),

        int_proc_header: $ => seq(
            $.attribute_declarations,
            $.proc_header,
            optional(seq(
                $.tkForward,
                $.tkSemiColon
            ))
        ),

        int_func_header: $ => seq(
            $.attribute_declarations,
            $.func_header,
            optional(seq(
                $.tkForward,
                $.tkSemiColon
            ))
        ),

        label_decl_sect: $ => seq(
            $.tkLabel,
            $.label_list,
            $.tkSemiColon
        ),

        label_list: $ => seq(
            optional(seq(
                $.label_list,
                $.tkComma
            )),
            $.label_name
        ),

        label_name: $ => choice(
            $.tkInteger,
            $.tkIdentifier
        ),

        const_decl_sect: $ => choice(
            choice(
                $.tkConst,
                $.const_decl_sect),
            $.const_decl
        ),

        res_srt_decl_sect: $ => choice(
            choice(
                $.tkResourseString,
                $.res_str_decl_sect),
            $.const_decl
        ),

        type_decl_sect: $ => choice(
            choice(
                $.tkType,
                $.type_decl_sect),
            $.const_decl
        ),

        var_decl_with_assign_var_tuple: $ => choice(
            $.var_decl,
            seq(
                $.tkRoundOpen,
                $.identifier,
                $.tkComma,
                $.ident_list,
                $.tkRoundClose,
                $.tkAssign,
                $.expr_l1,
                $.tkSemiColon
            )
        ),

        var_decl_sect: $ => seq(
            choice(
                $.tkVar,
                $.tkEvent,
                $.var_decl_sect
            ),
            $.var_decl_with_assign_var_tuple
        ),

        const_decl: $ => seq(
            $.only_const_decl,
            $.tkSemiColon
        ),

        only_const_decl: $ => seq(
            $.const_name,
            choice(
                seq(
                    $.tkEqual,
                    $.init_const_expr
                ),
                seq(
                    $.tkColon,
                    $.type_ref,
                    $.tkEqual,
                    $.typed_const
                )
            )
        ),

        init_const_expr: $ => choice(
            $.const_expr,
            $.array_const
        ),

        const_name: $ => identifier,

        expr_l1_list: $ => seq(
            optional(seq(
                $.expr_l1_list,
                $.tkComma
            )),
            $.expr_l1
        ),

        const_expr: $ => choice(
            seq(
                $.const_simple_expr,
                optional(seq(
                    $.const_relop,
                    $.const_simple_expr
                ))
            ),
            $.question_constexpr
        ),

        question_constexpr: $ => seq(
            $.const_expr,
            $.tkQuestion,
            $.const_expr,
            $.tkColon,
            $.const_expr
        ),

        const_relop: $ => choice(
            $.tkEqual,
            $.tkNotEqual,
            $.tkLower,
            $.tkGreater,
            $.tkLowerEqual,
            $.tkGreaterEqual,
            $.tkIn
        ),

        const_simple_expr: $ => seq(
            optional(seq(
                $.const_simple_expr,
                $.const_addop
            )),
            $.const_term
        ),

        const_addop: $ => choice(
            $.tkPlus,
            $.tkMinus,
            $.tkOr,
            $.tkXor
        ),

        as_is_constexpr: $ => seq(
            $.const_term,
            $.typecast_op,
            $.simple_or_template_type_reference
        ),

        power_constexpr: $ => choice(
            seq(
                $.const_factor_without_unary_op,
                $.tkStarStar,
                option(
                    $.const_factor,
                    $.power_constexpr
                )
            ),
            seq(
                $.sign,
                $.power_constexpr
            )
        ),

        const_term: $ => choice(
            $.const_factor,
            $.as_is_constexpr,
            $.power_constexpr,
            seq(
                $.const_term,
                $.const_mulopm,
                choice(
                    $.const_factor,
                    $.power_constexpr)
            )
        ),

        const_mulop: $ => choice(
            $.tkStar,
            $.tkSlash,
            $.tkDiv,
            $.tkMod,
            $.tkShl,
            $.tkShr,
            $.tkAnd,
        ),

        const_factor_without_unary_op: $ => choice(
            $.const_variable,
            seq(
                $.tkRoundOpen,
                $.const_expr,
                $.tkRoundClose
            )
        ),

        const_factor: $ => choice(
            $.const_variable,
            $.const_set,
            $.tkNil,
            seq($.tkAddressOf, $.const_factor),
            seq($.tkRoundOpen, $.const_expr, $.tkRoundClose),
            seq($.tkNot, $.const_factor),
            seq($.sign, $.const_factor),
            $.new_expr
        ),

        const_set: $ => choice(
            seq(
                $.tkSquareOpen,
                $.elem_list,
                $.tkSquareClose
            ),
            seq(
                $.tkVertParen,
                $.elem_list,
                $.tkVertParen
            )
        ),

        sign: $ => choice(
            $.tkPlus,
            $.tkMinus
        ),

        const_variable: $ => choice(
            $.identifier,
            $.literal,
            $.unsigned_number,
            seq($.tkInherited, $.identifier),
            $.sizeof_expr,
            $.typeof_expr,
            seq($.const_variable.$.const_variable_2),
            seq($.const_variable, $.tkAmpersend, $.template_type_params),
            seq($.const_variable, $.tkSquareOpen, $.format_const_expr, $.tkSquareClose)
        ),

        const_variable_2: $ => choice(
            seq($.tkPoint, $.identifier_or_keyword),
            $.tkDeref,
            seq($.tkRoundOpen, $.optional_const_func_expr_list, $.tkRoundClose),
            seq($.tkSquareOpen, $.const_elem_list, $.tkSquareClose)
        ),

        const_elem_list: $ => const_elem_list1,

        const_elem_list1: $ => seq(
            optional(seq(
                $.const_elem_list1,
                $.tkComma
            )),
            $.const_elem
        ),

        const_elem: $ => seq(
            optional(seq(
                $.const_expr,
                $.tkDotDot
            )),
            $.const_expr
        ),

        unsigned_number: $ => choice(
            $.tkInteger,
            $.tkHex,
            $.tkFloat
        ),

        typed_const: $ => choice(
            $.const_expr,
            $.array_const,
            $.record_const
        ),

        array_const: $ => seq(
            $.tkRoundOpen,
            $.typed_const_list,
            $.tkRoundClose
        ),

        typed_const_list: $ => typed_const_list1, // опять

        typed_const_list1: $ => seq(
            optional(seq(
                $.typed_const_list1,
                $.tkComma)),
            $.typed_const_plus
        ),

        record_const: $ => seq(
            $.tkRoundOpen,
            $.const_field_list,
            $.tkRoundClose
        ),

        const_field_list: $ => seq(
            $.const_field_list_1,
            optional($.tkSemiColon)
        ),

        const_field_list_1: $ => seq(
            optional(seq(
                $.const_field_list_1,
                $.tkSemiColon
            )),
            $.const_field
        ),

        const_field: $ => seq(
            $.const_field_name,
            $.tkColon,
            $.typed_const
        ),

        const_field_name: $ => identifier,

        type_decl: $ => seq(
            $.attribute_declarations,
            $.simple_type_decl
        ),

        attribute_declarations: $ => seq(
            optional($.attribute_declarations),
            $.attribute_declaration
        ),

        attribute_declaration: $ => seq(
            $.tkSquareOpen,
            $.one_or_some_attribute,
            $.tkSquareClose
        ),

        one_or_some_attribute: $ => seq(
            optional(seq(
                $.one_or_some_attribute,
                $.tkComma
            )),
            $.one_attribute
        ),

        one_attribute: $ => seq(
            optional(seq(
                $.identifier,
                $.tkColon
            )),
            $.attribute_variable
        ),

        simple_type_decl: $ => seq(
            choice(
                seq($.type_decl_identifier, $.tkEqual),
                $.template_identifier_with_equal
            ),
            $.type_decl_type,
            $.tkSemiColon
        ),

        type_decl_identifier: $ => seq(
            $.identifier,
            optional($.template_arguments)
        ),

        template_identifier_with_equal: $ => seq(
            $.identifier,
            $.tkLower,
            $.ident_list,
            $.tkGreaterEqual
        ),

        type_decl_type: $ => choice(
            $.type_ref,
            $.object_type
        ),

        simple_type_question: $ => seq(
            choice(
                $.simple_type,
                $.template_type
            ),
            $.tkQuestion
        ),

        type_ref: $ => choice(
            $.simple_type,
            $.simple_type_question,
            $.string_type,
            $.pointer_type,
            $.structured_type,
            $.procedural_type,
            $.template_type,
        ),

        template_type: $ => seq(
            $.simple_type_identifier,
            $.template_type_params
        ),

        template_type_params: $ => seq(
            $.tkLower,
            $.template_param_list,
            $.tkGreater
        ),

        template_type_empty_params: $ => choice(
            $.tkNotEqual,
            seq(
                $.tkLower,
                $.template_type_empty_param_list,
                $.tkGreater
            )
        ),

        template_param_list: $ => choice(
            $.template_param,
            seq(
                $.template_param_list,
                $.tkComma,
                $.template_param
            )
        ),

        template_empty_param_list: $ => choice(
            $.template_empty_param,
            seq(
                $.template_empty_param_list,
                $.tkComma,
                $.template_empty_param
            )
        ),

        template_empty_param, // эээ, наверное надо будет убрать сделав его как опшенал

        template_param: $ => choice(
            $.simple_type,
            seq($.simple_type, $.tkQuestion),
            $.structured_type,
            $.procedural_type,
            $.template_type,
        ),

        simple_type: $ => choice(
            $.range_expr,
            seq($.range_expr, $.tkDotDot, $.range_expr),
            seq($.tkRoundOpen, $.enumeration_id_list, $.tkRoundClose)
        ),

        range_expr: $ => seq(
            optional(seq(
                $.range_expr,
                $.const_addop
            )),
            $.range_term
        ),

        range_term: $ => seq(
            optional(seq(
                $.range_term,
                $.const_mulop
            )),
            $.range_factor
        ),

        range_factor: $ => choice(
            $.simple_type_identifier,
            $.unsigned_number,
            $.sign_range_factor,
            $.literal,
            seq(
                $.range_factor,
                $.tkRoundOpen,
                $.const_elem_list,
                $.tkRoundClose
            )
        ),

        simple_type_identifier: $ => choice(
            $.identifier,
            seq(
                $.simple_type_identifier,
                $.tkPoint,
                $.identifier_or_keyword // чёт подозрительно, надо посмотреть что он там собой представляет
            )
        ),

        enumeration_id_list: $ => seq(
            choice(
                $.enumeration_id,
                $.enumeration_id_list
            ),
            $.tkComma,
            $.enumeration_id
        ),

        enumeration_id: $ => seq(
            $.type_ref,
            optional(seq(
                $.tkEqual,
                $.expr
            ))
        ),

        pointer_type: $ => seq(
            $.tkDeref,
            $.fptype
        ),

        structured_type: $ => seq(
            optional($.tkPacked),
            $.unpacked_structured_type
        ),

        unpacked_structured_type: $ => choice(
            $.array_type,
            $.record_type,
            $.set_type,
            $.file_type,
            $.sequence_type
        ),

        sequence_type: $ => seq(
            $.tkSequence,
            $.tkOf,
            $.type_ref
        ),

        array_type: $ => choice(
            seq(
                $.tkArray,
                $.tkSquareOpen,
                $.simple_type_list,
                $.tkSquareClose,
                $.tkOf,
                $.type_ref
            ),
            $.unsized_array_type
        ),

        unsized_array_type: $ => seq(
            $.tkArray,
            $.tkOf,
            $.type_ref
        ),

        simple_type_list: $ => seq(
            optional(seq(
                $.simple_type_list,
                $.tkComma
            )),
            optional($.simple_type) // разорвёт по-любому
        ),

        set_type: $ => seq(
            $.tkSet,
            $.tkOf,
            $.type_ref
        ),

        file_type: $ => seq(
            $.tkFile,
            optional(seq(
                $.tkOf,
                $.type_ref
            ))
        ),

        string_type: $ => seq(
            $.tkIdentifier,
            $.tkSquareOpen,
            $.const_expr,
            $.tkSquareClose
        ),
    }
});