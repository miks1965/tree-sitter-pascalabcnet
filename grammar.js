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
        parse_goal: $ => choice( //
            $.program_file,
            $.unit_file,
            // $.parts,
            seq($.tkShortProgram, $.stmt_list),
            seq($.tkShortSFProgram, $.stmt_list)
        ),

        // parts: $ => choice(
        //     seq($.tkParseModeExpression, $.expr),
        //     seq($.tkParseModeExpression, $.tkType, $.type_decl_identifier),
        //     seq($.tkParseModeType, $.variable_as_type),
        //     seq($.tkParseModeStatement, $.stmt_or_expression)
        // ),

        stmt_or_expression: $ => choice(
            $.expr,
            $.assignment,
            $.var_stmt
        ),

        head_compiler_directives: $ => seq( //
            optional($.head_compiler_directives),
            $.one_compiler_directive
        ),

        one_compiler_directive: $ => choice(
            seq($.tkDirectiveName, $.tkIdentifier),
            seq($.tkDirectiveName, $.tkStringLiteral)
        ),

        program_file: $ => seq( //
            optional($.program_header),
            optional($.head_compiler_directives),
            optional($.uses_clause),
            $.program_block,
            optional($.optional_tk_point)
        ),

        optional_tk_point: $ => choice(
            $.tkPoint,
            $.tkSemiColon,
            $.tkColon,
            $.tkComma,
            $.tkDotDot
        ),

        program_header: $ => seq( //
            $.tkPoint,
            $.identifier,
            choice(
                $.tkSemiColon,
                seq($.tkRoundOpen,
                    $.program_param_list,
                    $.tkRoundClose,
                    $.tkSemiColon
                ))
        ),

        program_param_list: $ => prec.right(seq(
            optional(seq(
                $.program_param_list,
                $.tkComma
            )),
            $.identifier
        )),

        program_block: $ => seq( //
            optional($.decl_sect_list),
            $.compound_stmt
        ),

        ident_or_keyword_pointseparator_list: $ => prec.right(seq(
            optional(seq(
                $.ident_or_keyword_pointseparator_list,
                $.tkPoint)),
            $.identifier_or_keyword
        )),

        uses_clause: $ => seq( //
            optional($.uses_clause),
            $.tkUses,
            $.used_units_list,
            $.tkSemiColon
        ),

        used_units_list: $ => prec.right(seq(
            optional(seq(
                $.used_units_list,
                $.tkComma)),
            $.used_unit_name
        )),

        used_unit_name: $ => prec.right(seq(
            $.ident_or_keyword_pointseparator_list,
            optional(seq(
                $.tkIn,
                $.tkStringLiteral
            ))
        )),

        unit_file: $ => seq( //
            repeat($.attribute_declaration),
            $.unit_header,
            choice(
                seq(
                    $.interface_part,
                    $.implementation_part
                ),
                optional($.abc_interface_part)
            ),
            $.initialization_part,
            $.tkPoint
        ),

        unit_header: $ => seq( //
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
            optional($.head_compiler_directives)
        ),

        unit_key_word: $ => choice(
            $.tkUnit,
            $.tkLibrary
        ),

        unit_name: $ => $.identifier,

        interface_part: $ => choice(
            seq(
                $.tkInterface,
                optional($.uses_clause),
                optional($.interface_decl_sect_list)
            )
        ),

        implementation_part: $ => seq( //
            $.tkImplementation,
            optional($.uses_clause),
            optional($.decl_sect_list)
        ),

        abc_interface_part: $ => choice( // посмотреть потом
            seq(
                $.uses_clause,
                optional($.decl_sect_list),
            ),
            seq(
                optional($.uses_clause),
                $.decl_sect_list,
            )
        ),

        initialization_part: $ => choice( //
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

        interface_decl_sect_list: $ => repeat1(choice(
            $.const_decl_sect,
            $.res_str_decl_sect,
            $.type_decl_sect,
            $.var_decl_sect,
            $.int_proc_func_header,
        )),

        decl_sect_list: $ => repeat1(choice(
            $.label_decl_sect,
            $.const_decl_sect,
            $.res_str_decl_sect,
            $.type_decl_sect,
            $.var_decl_sect,
            $.proc_func_constr_destr_decl_with_attr
        )),

        inclass_decl_sect_list: $ => repeat1(choice(
            $.label_decl_sect,
            $.const_decl_sect,
            $.res_str_decl_sect,
            $.type_decl_sect,
            $.var_decl_sect
        )),

        proc_func_constr_destr_decl_with_attr: $ => seq(
            repeat($.attribute_declaration),
            choice(
                $.proc_func_decl,
                $.constr_destr_decl
            )
        ),

        int_proc_func_header: $ => seq(
            repeat($.attribute_declaration),
            choice(
                $.proc_header,
                $.func_header),
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

        label_list: $ => prec.right(seq(
            optional(seq(
                $.label_list,
                $.tkComma
            )),
            $.label_name
        )),

        label_name: $ => choice(
            $.tkInteger,
            $.tkIdentifier
        ),

        const_decl_sect: $ => prec.right(choice(
            choice(
                $.tkConst,
                $.const_decl_sect),
            $.const_decl,
            $.tkSemiColon
        )),

        res_str_decl_sect: $ => prec.right(choice(
            choice(
                $.tkResourceString,
                $.res_str_decl_sect),
            $.const_decl,
            $.tkSemiColon
        )),

        type_decl_sect: $ => prec.right(choice(
            choice(
                $.tkType,
                $.type_decl_sect),
            $.type_decl
        )),

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

        var_decl_sect: $ => prec.right(seq(
            choice(
                $.tkVar,
                $.tkEvent,
                $.var_decl_sect
            ),
            $.var_decl_with_assign_var_tuple
        )),

        const_decl: $ => seq(
            $.identifier,
            choice(
                seq(
                    $.tkEqual,
                    choice(
                        $.const_expr,
                        $.array_const
                    ),
                ),
                seq(
                    $.tkColon,
                    $.type_ref,
                    $.tkEqual,
                    $.typed_const
                )
            )
        ),

        expr_l1_list: $ => prec.right(seq(
            optional(seq(
                $.expr_l1_list,
                $.tkComma
            )),
            $.expr_l1
        )),

        const_expr: $ => prec.right(choice(
            seq(
                $.const_simple_expr,
                optional(seq(
                    $.const_relop,
                    $.const_simple_expr
                ))
            ),
            $.question_constexpr
        )),

        question_constexpr: $ => prec.right(seq(
            $.const_expr,
            $.tkQuestion,
            $.const_expr,
            $.tkColon,
            $.const_expr
        )),

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

        power_constexpr: $ => prec.right(choice(
            seq(
                $.const_factor_without_unary_op,
                $.tkStarStar,
                choice(
                    $.const_factor,
                    $.power_constexpr
                )
            ),
            seq(
                $.sign,
                $.power_constexpr
            )
        )),

        const_term: $ => prec.right(choice(
            $.const_factor,
            seq(
                $.const_term,
                $.typecast_op,
                $.simple_or_template_type_reference
            ),
            $.power_constexpr,
            seq(
                $.const_term,
                $.const_mulop,
                choice(
                    $.const_factor,
                    $.power_constexpr)
            )
        )),

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

        const_factor: $ => prec.right(choice(
            $.const_variable,
            $.const_set,
            $.tkNil,
            seq($.tkAddressOf, $.const_factor),
            seq($.tkRoundOpen, $.const_expr, $.tkRoundClose),
            seq($.tkNot, $.const_factor),
            seq($.sign, $.const_factor),
            $.new_expr
        )),

        const_set: $ => prec.left(choice(
            seq(
                $.tkSquareOpen,
                optional($.elem_list),
                $.tkSquareClose
            ),
            seq(
                $.tkVertParen,
                optional($.elem_list),
                $.tkVertParen
            )
        )),

        sign: $ => choice(
            $.tkPlus,
            $.tkMinus
        ),

        const_variable: $ => prec.right(choice(
            $.identifier,
            $.literal,
            $.unsigned_number,
            seq($.tkInherited, $.identifier),
            $.sizeof_expr,
            $.typeof_expr,
            seq($.const_variable, $.tkAmpersend, $.template_type_params),
            seq($.const_variable, $.tkSquareOpen, $.format_const_expr, $.tkSquareClose),
            seq($.const_variable,
                choice(
                    seq($.tkPoint, $.identifier_or_keyword),
                    $.tkDeref,
                    seq($.tkRoundOpen, optional($.expr_list), $.tkRoundClose),
                    seq($.tkSquareOpen, optional($.const_elem_list), $.tkSquareClose)
                ),
            )
        )),

        const_elem_list: $ => prec.rigt(seq(
            optional(seq(
                $.const_elem_list,
                $.tkComma
            )),
            $.const_elem
        )),

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
            optional($.typed_const_list),
            $.tkRoundClose
        ),

        typed_const_list: $ => prec.right(seq(
            optional(seq(
                $.typed_const_list,
                $.tkComma)),
            $.typed_const_plus
        )),

        record_const: $ => seq(
            $.tkRoundOpen,
            $.const_field_list,
            $.tkRoundClose
        ),

        const_field_list: $ => seq(
            optional(seq(
                $.const_field_list_1,
                $.tkSemiColon
            )),
            $.const_field,
            optional($.tkSemiColon)
        ),

        const_field_list: $ => seq(
            choice(
                $.const_fiend,
                seq($.const_field_list,
                    $.tkSemiColon,
                    $.const_field)
            ),
            optional($.tkSemiColon)
        ),

        const_field: $ => seq(
            $.identifier,
            $.tkColon,
            $.typed_const
        ),

        type_decl: $ => seq(
            repeat($.attribute_declaration),
            $.simple_type_decl
        ),

        attribute_declaration: $ => seq(
            $.tkSquareOpen,
            $.attribute_list,
            $.tkSquareClose
        ),

        attribute_list: $ => seq(
            optional(seq(
                $.attribute_list,
                $.tkComma
            )),
            $.one_attribute
        ),

        one_attribute: $ => seq(
            optional(seq(
                $.identifier,
                $.tkColon
            )),
            seq(
                choice(
                    $.simple_type_identifier,
                    $.template_type),
                optional($.optional_expr_list_with_bracket),
            ),
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

        type_ref: $ => prec.right(choice(
            $.simple_type,
            $.simple_type_question,
            $.string_type,
            $.pointer_type,
            $.structured_type,
            $.proc_type_decl,
            $.template_type,
        )),

        template_type: $ => seq(
            $.simple_type_identifier,
            $.template_type_params
        ),

        template_type_params: $ => seq(
            $.tkLower,
            $.template_param_list,
            $.tkGreater
        ),

        template_param_list: $ => choice(
            $.template_param,
            seq(
                $.template_param_list,
                $.tkComma,
                $.template_param
            )
        ),

        template_param: $ => prec.right(choice(
            $.simple_type,
            seq($.simple_type, $.tkQuestion),
            $.structured_type,
            $.proc_type_decl,
            $.template_type,
        )),

        simple_type: $ => prec.right(choice(
            $.range_expr,
            seq($.range_expr, $.tkDotDot, $.range_expr),
            seq($.tkRoundOpen, $.enumeration_id_list, $.tkRoundClose)
        )),

        range_expr: $ => prec.right(seq(
            optional(seq(
                $.range_expr,
                $.const_addop
            )),
            $.range_term
        )),

        range_term: $ => prec.right(seq(
            optional(seq(
                $.range_term,
                $.const_mulop
            )),
            $.range_factor
        )),

        range_factor: $ => prec.right(choice(
            $.simple_type_identifier,
            $.unsigned_number,
            seq($.sign, $.range_factor),
            $.literal,
            seq(
                $.range_factor,
                $.tkRoundOpen,
                optional($.const_elem_list),
                $.tkRoundClose
            )
        )),

        simple_type_identifier: $ => prec.right(choice(
            $.identifier,
            seq(
                $.simple_type_identifier,
                $.tkPoint,
                $.identifier_or_keyword
            )
        )),

        enumeration_id_list: $ => prec.right(seq(
            choice(
                $.enumeration_id,
                $.enumeration_id_list
            ),
            $.tkComma,
            $.enumeration_id
        )),

        enumeration_id: $ => seq(
            $.type_ref,
            optional(seq(
                $.tkEqual,
                $.expr
            ))
        ),

        pointer_type: $ => seq(
            $.tkDeref,
            $.type_ref
        ),

        structured_type: $ => seq(
            optional($.tkPacked),
            choice(
                $.array_type,
                $.record_type,
                seq(
                    $.tkSet,
                    $.tkOf,
                    $.type_ref
                ),
                seq(
                    $.tkFile,
                    optional(seq(
                        $.tkOf,
                        $.type_ref
                    ))
                ),
                seq(
                    $.tkSequence,
                    $.tkOf,
                    $.type_ref
                ),
            ),
        ),

        array_type: $ => choice(
            seq(
                $.tkArray,
                $.tkSquareOpen,
                optional($.simple_type_list),
                $.tkSquareClose,
                $.tkOf,
                $.type_ref
            ),
            seq(
                $.tkArray,
                $.tkOf,
                $.type_ref
            ),
        ),

        simple_type_list: $ => choice(
            optional(seq(
                $.simple_type_list,
                $.tkComma
            )),
            $.simple_type
        ),

        string_type: $ => seq(
            $.tkIdentifier,
            $.tkSquareOpen,
            $.const_expr,
            $.tkSquareClose
        ),

        proc_type_decl: $ => prec.right(choice(
            seq(
                $.tkProcedure,
                $.fp_list,
            ),
            seq(
                $.tkFunction,
                $.fp_list,
                $.tkColon,
                $.type_ref,
            ),
            seq(
                $.simple_type_identifier,
                $.tkArrow,
                $.template_param,
            ),
            seq(
                $.template_type,
                $.tkArrow,
                $.template_param,
            ),
            seq(
                $.tkRoundOpen,
                $.tkRoundClose,
                $.tkArrow,
                $.template_param,
            ),
            seq(
                $.tkRoundOpen,
                $.enumeration_id_list,
                $.tkRoundClose,
                $.tkArrow,
                $.template_param,
            ),
            seq(
                $.simple_type_identifier,
                $.tkArrow,
                $.tkRoundOpen,
                $.tkRoundClose,
            ),
            seq(
                $.template_type,
                $.tkArrow,
                $.tkRoundOpen,
                $.tkRoundClose,
            ),
            seq(
                $.tkRoundOpen,
                $.tkRoundClose,
                $.tkArrow,
                $.tkRoundOpen,
                $.tkRoundClose,
            ),
            seq(
                $.tkRoundOpen,
                $.enumeration_id_list,
                $.tkRoundClose,
                $.tkArrow,
                $.tkRoundOpen,
                $.tkRoundClose,
            ),
        )),

        object_type: $ => seq(
            repeat($.class_attribute),
            $.class_or_interface_keyword,
            optional($.optional_base_classes),
            repeat($.where_part),
            optional($.optional_component_list_seq_end),
        ),

        record_type: $ => seq(
            $.tkRecord,
            optional($.optional_base_classes),
            repeat($.where_part),
            $.member_list_section,
            $.tkEnd,
        ),

        class_attribute: $ => choice(
            $.tkSealed,
            $.tkPartial,
            $.tkAbstract,
            $.tkAuto,
            $.tkStatic,
        ),

        class_or_interface_keyword: $ => choice(
            $.tkClass,
            $.tkInterface,
            seq($.tkTemplate,
                optional(choice(
                    $.tkClass,
                    $.tkRecord,
                    $.tkInterface,
                )))
        ),

        optional_component_list_seq_end: $ => seq(
            $.member_list_section,
            $.tkEnd,
        ),

        optional_base_classes: $ => seq(
            $.tkRoundOpen,
            $.base_classes_names_list,
            $.tkRoundClose,
        ),

        base_classes_names_list: $ => prec.right(choice(
            $.base_class_name,
            seq(
                $.base_classes_names_list,
                $.tkComma,
                $.base_class_name,
            ),
        )),

        base_class_name: $ => choice(
            $.simple_type_identifier,
            $.template_type,
        ),

        template_arguments: $ => seq(
            $.tkLower,
            $.ident_list,
            $.tkGreater,
        ),

        where_part: $ => seq(
            $.tkWhere,
            $.ident_list,
            $.tkColon,
            $.type_ref_and_secific_list,
            $.tkSemiColon,
        ),

        type_ref_and_secific_list: $ => prec.right(seq(
            optional(seq(
                $.type_ref_and_secific_list,
                $.tkComma)),
            $.type_ref_or_secific,
        )),

        type_ref_or_secific: $ => choice(
            $.type_ref,
            $.tkClass,
            $.tkRecord,
            $.tkConstructor,
        ),

        member_list_section: $ => prec.right(seq(
            optional(seq(
                $.member_list_section,
                $.ot_visibility_specifier,
            )),
            $.member_list,
        )),

        ot_visibility_specifier: $ => choice(
            $.tkInternal,
            $.tkPublic,
            $.tkProtected,
            $.tkPrivate,
        ),

        member_list: $ => choice(
            seq(
                $.field_or_const_definition_list,
                optional($.tkSemiColon),
            ),
            $.method_decl_list,
            seq(
                $.field_or_const_definition_list,
                $.tkSemiColon,
                $.method_decl_list,
            ),
        ),

        ident_list: $ => seq(
            optional(seq(
                $.ident_list,
                $.tkComma,
            )),
            $.identifier,
        ),

        field_or_const_definition_list: $ => prec.right(seq(
            optional(seq(
                $.field_or_const_definition_list,
                $.tkSemiColon,
            )),
            $.field_or_const_definition,
        )),

        field_or_const_definition: $ => seq(
            repeat($.attribute_declaration),
            choice(
                seq(
                    $.tkConst,
                    $.const_decl,
                ),
                $.field_definition,
                seq(
                    $.class_or_static,
                    $.field_definition,
                ),
            ),
        ),

        method_decl_list: $ => seq(
            optional($.method_decl_list),
            choice(
                $.method_decl_withattr,
                $.property_definition,
            )
        ),

        class_or_static: $ => choice(
            $.tkStatic,
            $.tkClass,
        ),

        field_definition: $ => choice(
            $.var_decl_part,
            seq(
                $.tkEvent,
                $.ident_list,
                $.tkColon,
                $.type_ref,
            ),
        ),

        method_decl_withattr: $ => seq(
            repeat($.attribute_declaration),
            choice(
                $.method_header,
                choice(
                    $.inclass_proc_func_decl,
                    $.inclass_constr_destr_decl,
                ),
            ),
        ),

        method_header: $ => choice(
            seq(
                $.class_or_static,
                $.proc_func_header,
            ),
            $.proc_func_header,
            $.constr_destr_header,
        ),

        proc_func_header: $ => choice(
            $.proc_header,
            $.func_header,
        ),

        constr_destr_header: $ => seq(
            choice(
                $.tkConstructor,
                seq(
                    $.class_or_static,
                    $.tkConstructor,
                ),
                $.tkDestructor
            ),
            optional($.proc_name),
            $.fp_list,
            optional($.optional_method_modificators), // тут остановилась
        ),

        qualified_identifier: $ => choice(
            $.identifier,
            $.visibility_specifier,
            seq(
                $.qualified_identifier,
                $.tkPoint,
                choice(
                    $.identifier,
                    $.visibility_specifier,
                )
            ),
        ),

        property_definition: $ => seq(
            repeat($.attribute_declaration),
            $.simple_property_definition,
        ),

        simple_property_definition: $ => choice(
            seq(
                $.tkProperty,
                $.qualified_identifier,
                $.property_interface,
                $.property_specifiers,
                $.tkSemiColon,
                optional(seq(
                    $.property_modificator,
                    $.tkSemiColon,
                )),
                optional($.array_defaultproperty),
            ),
            seq(
                $.class_or_static,
                $.tkProperty,
                $.qualified_identifier,
                $.property_interface,
                $.property_specifiers,
                $.tkSemiColon,
                optional(seq(
                    $.property_modificator,
                    $.tkSemiColon)),
                optional($.optional_property_initialization),
            ),
            seq(
                optional($.class_or_static),
                $.tkAuto,
                $.tkProperty,
                $.qualified_identifier,
                $.property_interface,
                optional($.optional_property_initialization),
                $.tkSemiColon,
            )
        ),

        optional_property_initialization: $ => seq(
            $.tkAssign,
            $.expr,
        ),

        array_defaultproperty: $ => seq(
            $.tkDefault,
            $.tkSemiColon,
        ),

        property_interface: $ => seq(
            optional($.property_parameter_list),
            $.tkColon,
            $.type_ref,
        ),

        property_parameter_list: $ => seq(
            $.tkSquareOpen,
            $.parameter_decl_list,
            $.tkSquareClose,
        ),

        parameter_decl_list: $ => seq(
            optional(seq(
                $.parameter_decl_list,
                $.tkSemiColon,
            )),
            $.parameter_decl,
        ),

        parameter_decl: $ => seq(
            $.ident_list,
            $.tkColon,
            $.type_ref,
        ),

        optional_read_expr: $ => $.expr_with_func_decl_lambda,

        property_specifiers: $ => choice(
            seq(
                $.tkRead,
                optional($.optional_read_expr),
                optional($.write_property_specifiers),
            ),
            seq(
                $.tkWrite,
                optional($.unlabelled_stmt),
                $.read_property_specifiers,
            ),
        ),

        write_property_specifiers: $ => seq(
            $.tkWrite,
            optional($.unlabelled_stmt),
        ),

        read_property_specifiers: $ => seq(
            $.tkRead,
            optional($.optional_read_expr),
        ),

        var_decl: $ => seq(
            $.var_decl_part,
            $.tkSemiColon,
        ),

        tkAssignOrEqual: $ => choice(
            $.tkAssign,
            $.tkEqual,
        ),

        var_decl_part: $ => prec.right(seq(
            $.ident_list,
            choice(
                seq(
                    $.tkColon,
                    $.type_ref,
                ),
                seq(
                    $.tkAssign,
                    $.expr_with_func_decl_lambda,
                ),
                seq(
                    $.tkColon,
                    $.type_ref,
                    $.tkAssignOrEqual,
                    $.typed_var_init_expression,
                )),
        )),

        typed_var_init_expression: $ => choice(
            $.typed_const_plus,
            $.expl_func_decl_lambda,
            seq(
                $.identifier,
                $.tkArrow,
                $.lambda_function_body,
            ),
            seq(
                $.tkRoundOpen,
                $.tkRoundClose,
                optional($.lambda_type_ref),
                $.tkArrow,
                $.lambda_function_body,
            ),
            seq(
                $.tkRoundOpen,
                optional($.typed_const_list),
                $.tkRoundClose,
                $.tkArrow,
                $.lambda_function_body,
            ),
        ),

        typed_const_plus: $ => choice(
            $.typed_const,
            $.default_expr,
        ),

        constr_destr_decl: $ => choice(
            seq(
                $.constr_destr_header,
                $.block,
            ),
            seq(
                optional($.class_or_static),
                $.tkConstructor,
                optional($.proc_name),
                $.fp_list,
                $.tkAssign,
                optional($.unlabelled_stmt),
                $.tkSemiColon,
            ),
        ),

        inclass_constr_destr_decl: $ => choice(
            seq(
                $.constr_destr_header,
                $.inclass_block,
            ),
            seq(
                optional($.class_or_static),
                $.tkConstructor,
                optional($.proc_name),
                $.fp_list,
                $.tkAssign,
                optional($.unlabelled_stmt),
                $.tkSemiColon,
            ),
        ),

        proc_func_decl: $ => seq(
            optional($.class_or_static),
            $.proc_func_decl_noclass,
        ),

        proc_func_decl_noclass: $ => choice(
            seq(
                $.proc_func_header,
                $.proc_func_external_block,
            ),
            seq(
                $.tkFunction,
                $.func_name,
                $.fp_list,
                $.tkColon,
                $.type_ref,
                optional($.optional_method_modificators1),
                $.tkAssign,
                choice(
                    $.expr_l1,
                    $.func_decl_lambda
                ),
                $.tkSemiColon
            ),
            seq(
                $.tkFunction,
                $.func_name,
                $.fp_list,
                optional($.optional_method_modificators1),
                $.tkAssign,
                choice(
                    $.func_decl_lambda,
                    $.expr_l1,
                ),
                $.tkSemiColon,
            ),
            seq(
                $.tkProcedure,
                $.proc_name,
                $.fp_list,
                optional($.optional_method_modificators1),
                $.tkAssign,
                optional($.unlabelled_stmt),
                $.tkSemiColon,
            ),
            seq(
                $.proc_func_header,
                $.tkForward,
                $.tkSemiColon,
            ),
        ),

        inclass_proc_func_decl: $ => seq(
            optional($.class_or_static),
            $.inclass_proc_func_decl_noclass,
        ),

        inclass_proc_func_decl_noclass: $ => choice(
            seq(
                $.proc_func_header,
                $.inclass_block,
            ),
            seq(
                $.tkFunction,
                $.func_name,
                $.fp_list,
                optional(seq(
                    $.tkColon,
                    $.type_ref
                )),
                optional($.optional_method_modificators1),
                $.tkAssign,
                $.expr_l1_func_decl_lambda,
                $.tkSemiColon,
            ),
            seq(
                $.tkProcedure,
                $.proc_name,
                $.fp_list,
                optional($.optional_method_modificators1),
                $.tkAssign,
                optional($.unlabelled_stmt),
                $.tkSemiColon,
            ),
        ),

        proc_func_external_block: $ => choice(
            $.block,
            $.external_block,
        ),

        proc_name: $ => $.func_name,

        func_name: $ => choice(
            $.func_meth_name_ident,
            seq(
                $.func_class_name_ident_list,
                $.tkPoint,
                $.func_meth_name_ident,
            ),
        ),

        func_class_name_ident: $ => $.func_name_with_template_args,

        func_class_name_ident_list: $ => seq(
            optional(seq(
                $.func_class_name_ident_list,
                $.tkPoint)),
            $.func_class_name_ident,
        ),

        func_meth_name_ident: $ => choice(
            $.func_name_with_template_args,
            seq(
                $.operator_name_ident,
                optional($.template_arguments)
            )
        ),

        func_name_with_template_args: $ => seq(
            $.identifier,
            optional($.template_arguments)
        ),

        proc_header: $ => seq(
            $.tkProcedure,
            $.proc_name,
            $.fp_list,
            optional($.optional_method_modificators),
            repeat($.where_part),
        ),

        func_header: $ => seq(
            $.tkFunction,
            $.func_name,
            $.fp_list,
            optional(seq(
                $.tkColon,
                $.type_ref)
            ),
            optional($.optional_method_modificators),
            repeat($.where_part),
        ),

        external_block: $ => seq(
            $.tkExternal,
            optional(seq(
                $.external_directive_ident,
                optional(seq(
                    $.tkName,
                    $.external_directive_ident)
                ))),
            $.tkSemiColon,
        ),

        external_directive_ident: $ => choice(
            $.identifier,
            $.literal,
        ),

        block: $ => seq(
            optional($.decl_sect_list),
            $.compound_stmt,
            $.tkSemiColon,
        ),

        inclass_block: $ => choice(
            seq(
                optional($.inclass_decl_sect_list),
                $.compound_stmt,
                $.tkSemiColon,
            ),
            $.external_block,
        ),

        fp_list: $ => seq(
            $.tkRoundOpen,
            optional($.fp_sect_list),
            $.tkRoundClose,
        ),

        fp_sect_list: $ => seq(
            optional(seq(
                $.fp_sect_list,
                $.tkSemiColon)),
            $.fp_sect,
        ),

        fp_sect: $ => seq(
            repeat($.attribute_declaration),
            $.simple_fp_sect,
        ),

        simple_fp_sect: $ => seq(
            optional(seq(
                $.tkVar,
                $.tkConst,
                $.tkParams,
            )),
            $.param_name_list,
            $.tkColon,
            $.type_ref,
            optional(seq(
                $.tkAssign,
                $.expr
            ))
        ),

        param_name_list: $ => seq(
            optional(seq(
                $.param_name_list,
                $.tkComma)),
            $.identifier
        ),


        fptype_noproctype: $ => choice(
            $.simple_type,
            $.string_type,
            $.pointer_type,
            $.structured_type,
            $.template_type,
        ),

        stmt: $ => prec.right(choice(
            $.unlabelled_stmt,
            seq(
                $.label_name,
                $.tkColon,
                optional($.stmt),
            ),
        )),

        unlabelled_stmt: $ => choice(
            $.assignment,
            $.proc_call,
            $.goto_stmt,
            $.compound_stmt,
            $.if_stmt,
            $.case_stmt,
            $.repeat_stmt,
            $.while_stmt,
            $.for_stmt,
            $.with_stmt,
            $.inherited_message,
            $.try_stmt,
            $.raise_stmt,
            $.foreach_stmt,
            $.var_stmt,
            $.expr_as_stmt,
            $.lock_stmt,
            $.yield_stmt,
            $.yield_sequence_stmt,
            $.loop_stmt,
            $.match_with,
        ),

        loop_stmt: $ => prec.left(seq(
            $.tkLoop,
            $.expr_l1,
            $.tkDo,
            optional($.unlabelled_stmt),
        )),

        yield_stmt: $ => seq(
            $.tkYield,
            $.expr_l1_func_decl_lambda,
        ),

        yield_sequence_stmt: $ => seq(
            $.tkYield,
            $.tkSequence,
            $.expr_l1_func_decl_lambda,
        ),

        var_stmt: $ => prec.right(choice(
            seq(
                $.tkVar,
                $.var_decl_part,
            ),
            seq(
                choice(
                    seq($.tkRoundOpen,
                        $.tkVar,
                        $.identifier,
                        $.tkComma,
                        $.var_ident_list),
                    seq($.tkVar,
                        $.tkRoundOpen,
                        $.identifier,
                        $.tkComma,
                        $.ident_list),
                    $.tkRoundClose,
                    $.tkAssign,
                    $.expr,
                ),
            )
        )),

        assignment: $ => choice(
            seq(
                $.var_reference,
                $.assign_operator,
                $.expr_with_func_decl_lambda,
            ),
            seq(
                $.tkRoundOpen,
                $.variable,
                $.tkComma,
                $.variable_list,
                $.tkRoundClose,
                $.assign_operator,
                $.expr,
            ),
            seq(
                $.variable,
                $.tkQuestionSquareOpen,
                $.format_expr,
                $.tkSquareClose,
                $.assign_operator,
                $.expr,
            ),
        ),

        variable_list: $ => seq(
            optional(seq(
                $.variable_list,
                $.tkComma,
            )),
            $.variable,
        ),

        var_ident_list: $ => seq(
            optional(seq(
                $.var_ident_list,
                $.tkComma)),
            $.tkVar,
            $.identifier,
        ),

        proc_call: $ => prec.right($.var_reference),

        goto_stmt: $ => seq(
            $.tkGoto,
            $.label_name,
        ),

        compound_stmt: $ => seq(
            $.tkBegin,
            $.stmt_list,
            $.tkEnd,
        ),

        stmt_list: $ => prec.right(seq(
            optional(seq(
                $.stmt_list,
                $.tkSemiColon)),
            $.stmt
        )),

        if_stmt: $ => prec.right(seq(
            $.tkIf,
            $.expr_l1,
            $.tkThen,
            optional(seq(
                optional($.unlabelled_stmt),
                $.tkElse)),
            optional($.unlabelled_stmt),
        )),

        match_with: $ => seq(
            $.tkMatch,
            $.expr_l1,
            $.tkWith,
            $.pattern_cases,
            optional($.tkSemiColon),
            optional($.else_case),
            $.tkEnd,
        ),

        pattern_cases: $ => prec.right(choice(
            seq(
                optional(seq(
                    $.pattern_cases,
                    $.tkSemiColon)),
                $.pattern_case),
            seq(
                seq(
                    $.pattern_cases,
                    $.tkSemiColon),
                optional($.pattern_case))
        )),

        pattern_case: $ => choice(
            seq(
                $.pattern_optional_var,
                $.tkWhen,
                $.expr_l1,
                $.tkColon,
                optional($.unlabelled_stmt),
            ),
            seq(
                $.deconstruction_or_const_pattern,
                $.tkColon,
                optional($.unlabelled_stmt),
            ),
            seq(
                $.collection_pattern,
                $.tkColon,
                optional($.unlabelled_stmt),
            ),
            seq(
                $.tuple_pattern,
                $.tkWhen,
                $.expr_l1,
                $.tkColon,
                optional($.unlabelled_stmt),
            ),
            seq(
                $.tuple_pattern,
                $.tkColon,
                optional($.unlabelled_stmt),
            ),
        ),

        case_stmt: $ => choice(
            seq(
                $.tkCase,
                $.expr_l1,
                $.tkOf,
                $.case_list,
                optional($.else_case),
                $.tkEnd,
            ),
            seq(
                $.tkCase,
                $.expr_l1,
                $.tkOf,
                $.case_list,
                $.tkSemiColon,
                optional($.else_case),
                $.tkEnd,
            ),
            seq(
                $.tkCase,
                $.expr_l1,
                $.tkOf,
                optional($.else_case),
                $.tkEnd,
            ),
        ),

        case_list: $ => seq(
            optional(seq(
                $.case_list,
                $.tkSemiColon,
            )),
            $.case_item,
        ),

        case_item: $ => seq(
            $.case_label_list,
            $.tkColon,
            optional($.unlabelled_stmt),
        ),

        case_label_list: $ => choice(
            optional(seq(
                $.case_label_list,
                $.tkComma
            )),
            $.case_label,
        ),

        case_label_list: $ => choice(
            seq(
                optional(seq(
                    $.case_label_list,
                    $.tkComma
                )),
                $.case_label
            ),
            seq(
                seq(
                    $.case_label_list,
                    $.tkComma
                ),
                optional($.case_label)
            )
        ),

        case_label: $ => $.const_elem,

        else_case: $ => seq(
            $.tkElse,
            $.stmt_list,
        ),

        repeat_stmt: $ => seq(
            $.tkRepeat,
            $.stmt_list,
            $.tkUntil,
            $.expr,
        ),

        while_stmt: $ => prec.right(seq(
            $.tkWhile,
            $.expr_l1,
            optional($.optional_tk_do),
            optional($.unlabelled_stmt),
        )),

        optional_tk_do: $ => $.tkDo,

        lock_stmt: $ => prec.left(seq(
            $.tkLock,
            $.expr_l1,
            $.tkDo,
            optional($.unlabelled_stmt),
        )),

        foreach_stmt: $ => prec.right(choice(
            seq(
                $.tkForeach,
                $.identifier,
                optional($.foreach_stmt_ident_dype_opt),
                $.tkIn,
                $.expr_l1,
                $.tkDo,
                optional($.unlabelled_stmt),
            ),
            seq(
                $.tkForeach,
                $.tkVar,
                $.identifier,
                optional(seq($.tkColon,
                    $.type_ref)),
                $.tkIn,
                $.expr_l1,
                $.tkDo,
                optional($.unlabelled_stmt),
            ),
        )),

        foreach_stmt_ident_dype_opt: $ => seq(
            $.tkColon,
            $.type_ref,
        ),

        for_stmt: $ => prec.right(seq(
            $.tkFor,
            optional($.optional_var),
            $.identifier,
            $.for_stmt_decl_or_assign,
            $.expr_l1,
            $.for_cycle_type,
            $.expr_l1,
            optional($.optional_tk_do),
            optional($.unlabelled_stmt),
        )),

        optional_var: $ => $.tkVar,

        // for_stmt_decl_or_assign: $ => choice(
        //     optional(seq(
        //         $.tkColon,
        //         $.simple_type_identifier
        //     )),
        //     $.tkAssign
        // ),

        for_stmt_decl_or_assign: $ => choice(
            seq(
                seq(
                    $.tkColon,
                    $.simple_type_identifier
                ),
                optional($.tkAssign)
            ),
            seq(
                optional(seq(
                    $.tkColon,
                    $.simple_type_identifier
                )),
                $.tkAssign
            )
        ),

        for_cycle_type: $ => choice(
            $.tkTo,
            $.tkDownto,
        ),

        with_stmt: $ => prec.left(seq(
            $.tkWith,
            $.expr_list,
            $.tkDo,
            optional($.unlabelled_stmt),
        )),

        inherited_message: $ => prec.left($.tkInherited),

        try_stmt: $ => seq(
            $.tkTry,
            $.stmt_list,
            $.try_handler,
        ),

        try_handler: $ => choice(
            seq(
                $.tkFinally,
                $.stmt_list,
                $.tkEnd,
            ),
            seq(
                $.tkExcept,
                $.exception_block,
                $.tkEnd,
            ),
        ),

        exception_block: $ => prec(6, choice(
            seq(
                $.exception_handler_list,
                optional($.tkSemiColon),
                optional($.exception_block_else_branch),
            ),
            $.stmt_list,
        )),

        exception_handler_list: $ => prec.left(choice(
            seq(optional(seq(
                $.exception_handler_list,
                $.tkSemiColon,
            )),
                $.exception_handler),
            seq(
                seq(
                    $.exception_handler_list,
                    $.tkSemiColon,
                ),
                optional($.exception_handler)
            )
        )),

        exception_block_else_branch: $ => seq(
            $.tkElse,
            $.stmt_list,
        ),

        exception_handler: $ => seq(
            $.tkOn,
            $.exception_identifier,
            $.tkDo,
            optional($.unlabelled_stmt),
        ),

        exception_identifier: $ => choice(
            seq(optional(seq(
                $.exception_variable,
                $.tkColon
            )),
                $.exception_class_type_identifier),
            seq(seq(
                $.exception_variable,
                $.tkColon
            ),
                optional($.exception_class_type_identifier)
            )
        ),

        exception_class_type_identifier: $ => $.simple_type_identifier,

        exception_variable: $ => $.identifier,

        raise_stmt: $ => prec.left(seq(
            $.tkRaise,
            optional($.expr),
        )),

        expr_list: $ => seq(
            optional(seq(
                $.expr_list,
                $.tkComma,
            )),
            $.expr_with_func_decl_lambda,
        ),

        expr_as_stmt: $ => $.allowable_expr_as_stmt,

        allowable_expr_as_stmt: $ => $.new_expr,

        expr_with_func_decl_lambda: $ => choice(
            $.expr,
            $.func_decl_lambda,
        ),

        expr: $ => choice(
            $.expr_l1,
            $.format_expr,
        ),

        expr_l1: $ => prec(2, choice(
            $.expr_dq,
            $.question_expr,
            $.new_question_expr,
        )),

        expr_l1_for_question_expr: $ => choice(
            $.expr_dq,
            $.question_expr,
        ),
        expr_l1_for_new_question_expr: $ => prec(6, choice(
            $.expr_dq,
            $.new_question_expr,
        )),
        expr_l1_func_decl_lambda: $ => choice(
            $.expr_l1,
            $.func_decl_lambda,
        ),
        expr_l1_for_lambda: $ => choice(
            $.expr_dq,
            $.question_expr,
            $.func_decl_lambda,
        ),

        expr_dq: $ => choice(
            $.relop_expr,
            seq(
                $.expr_dq,
                $.tkDoubleQuestion,
                $.relop_expr,
            ),
        ),

        sizeof_expr: $ => seq(
            $.tkSizeOf,
            $.tkRoundOpen,
            $.simple_or_template_type_reference,
            $.tkRoundClose,
        ),

        typeof_expr: $ => choice(
            seq(
                $.tkTypeOf,
                $.tkRoundOpen,
                choice(
                    $.simple_or_template_type_reference,
                    $.empty_template_type_reference),
                $.tkRoundClose,
            ),
        ),

        question_expr: $ => prec.left(seq(
            $.expr_l1_for_question_expr,
            $.tkQuestion,
            $.expr_l1_for_question_expr,
            $.tkColon,
            $.expr_l1_for_question_expr,
        )),

        new_question_expr: $ => seq(
            $.tkIf,
            $.expr_l1_for_new_question_expr,
            $.tkThen,
            $.expr_l1_for_new_question_expr,
            $.tkElse,
            $.expr_l1_for_new_question_expr,
        ),

        empty_template_type_reference: $ => seq(
            $.simple_type_identifier,
            optional($.tkAmpersend),
            choice(
                $.tkNotEqual,
                seq(
                    $.tkLower,
                    repeat(tkComma),
                    $.tkGreater
                )
            ),
        ),

        simple_or_template_type_reference: $ => prec.right(seq(
            $.simple_type_identifier,
            optional(seq(
                optional($.tkAmpersend),
                $.template_type_params
            )),
        )),

        optional_array_initializer: $ => seq(
            $.tkRoundOpen,
            optional($.typed_const_list),
            $.tkRoundClose,
        ),

        new_expr: $ => prec.right(choice(
            seq(
                $.tkNew,
                $.simple_or_template_type_reference,
                optional($.optional_expr_list_with_bracket),
            ),
            seq(
                $.tkNew,
                $.simple_or_template_type_reference,
                $.tkSquareOpen,
                optional($.optional_expr_list),
                $.tkSquareClose,
                optional($.optional_array_initializer),
            ),
            seq(
                $.tkNew,
                $.tkClass,
                $.tkRoundOpen,
                $.list_fields_in_unnamed_object,
                $.tkRoundClose,
            ),
        )),

        field_in_unnamed_object: $ => choice(
            seq(
                $.identifier,
                $.tkAssign,
                $.relop_expr,
            ),
            $.relop_expr,
        ),

        // здесь я перестала переписывать рекурсивные определения
        list_fields_in_unnamed_object: $ => choice(
            $.field_in_unnamed_object,
            seq(
                $.list_fields_in_unnamed_object,
                $.tkComma,
                $.field_in_unnamed_object,
            ),
        ),

        optional_expr_list_with_bracket: $ => seq(
            $.tkRoundOpen,
            optional($.optional_expr_list),
            $.tkRoundClose,
        ),

        relop_expr: $ => prec(6, choice(
            $.simple_expr,
            seq(
                $.relop_expr,
                $.relop,
                $.simple_expr,
            ),
            seq(
                $.relop_expr,
                $.relop,
                $.new_question_expr,
            ),
            seq(
                $.is_type_expr,
                $.tkRoundOpen,
                $.pattern_out_param_list,
                $.tkRoundClose,
            ),
        )),

        pattern: $ => seq(
            $.simple_or_template_type_reference,
            $.tkRoundOpen,
            $.pattern_out_param_list,
            $.tkRoundClose,
        ),

        pattern_optional_var: $ => seq(
            $.simple_or_template_type_reference,
            $.tkRoundOpen,
            $.pattern_out_param_list_optional_var,
            $.tkRoundClose,
        ),

        deconstruction_or_const_pattern: $ => choice(
            seq(
                $.simple_or_template_type_reference,
                $.tkRoundOpen,
                $.pattern_out_param_list_optional_var,
                $.tkRoundClose,
            ),
            $.const_pattern_expr_list,
        ),

        const_pattern_expr_list: $ => choice(
            $.const_pattern_expression,
            seq(
                $.const_pattern_expr_list,
                $.tkComma,
                $.const_pattern_expression,
            ),
        ),

        const_pattern_expression: $ => choice(
            $.literal,
            $.unsigned_number,
            $.simple_or_template_type_reference,
            $.tkNil,
            $.sizeof_expr,
            $.typeof_expr,
        ),

        collection_pattern: $ => seq(
            $.tkSquareOpen,
            $.collection_pattern_expr_list,
            $.tkSquareClose,
        ),

        collection_pattern_expr_list: $ => choice(
            $.collection_pattern_list_item,
            seq(
                $.collection_pattern_expr_list,
                $.tkComma,
                $.collection_pattern_list_item,
            ),
        ),

        collection_pattern_list_item: $ => choice(
            $.literal,
            $.unsigned_number,
            $.collection_pattern_var_item,
            $.tkUnderscore,
            $.pattern_optional_var,
            $.collection_pattern,
            $.tuple_pattern,
            $.tkDotDot,
        ),

        collection_pattern_var_item: $ => seq(
            $.tkVar,
            $.identifier,
        ),

        tuple_pattern: $ => seq(
            $.tkRoundOpen,
            $.tuple_pattern_item_list,
            $.tkRoundClose,
        ),

        tuple_pattern_item: $ => choice(
            $.tkUnderscore,
            $.literal,
            $.unsigned_number,
            seq(
                $.sign,
                $.literal,
            ),
            seq(
                $.sign,
                $.unsigned_number
            ),
            seq(
                $.tkVar,
                $.identifier,
            ),
            $.pattern_optional_var,
            $.collection_pattern,
            $.tuple_pattern,
        ),

        tuple_pattern_item_list: $ => choice(
            $.tuple_pattern_item,
            seq(
                $.tuple_pattern_item_list,
                $.tkComma,
                $.tuple_pattern_item,
            ),
        ),

        pattern_out_param_list_optional_var: $ => choice(
            $.pattern_out_param_optional_var,
            seq(
                $.pattern_out_param_list_optional_var,
                choice(
                    $.tkSemiColon,
                    $.tkComma
                ),
                $.pattern_out_param_optional_var,
            )
        ),

        pattern_out_param_list: $ => choice(
            $.pattern_out_param,
            seq(
                $.pattern_out_param_list,
                $.tkSemiColon,
                $.pattern_out_param,
            ),
            seq(
                $.pattern_out_param_list,
                $.tkComma,
                $.pattern_out_param,
            ),
        ),

        pattern_out_param: $ => choice(
            $.tkUnderscore,
            $.literal,
            $.unsigned_number,
            seq(
                $.tkVar,
                $.identifier,
                $.tkColon,
                $.type_ref,
            ),
            seq(
                $.tkVar,
                $.identifier,
            ),
            $.pattern,
            $.collection_pattern,
            $.tuple_pattern,
        ),

        pattern_out_param_optional_var: $ => choice(
            $.tkUnderscore,
            $.literal,
            $.unsigned_number,
            seq(
                $.sign,
                $.literal
            ),
            seq(
                $.sign,
                $.unsigned_number),
            seq(
                $.identifier,
                $.tkColon,
                $.type_ref,
            ),
            $.identifier,
            seq(
                $.tkVar,
                $.identifier,
                $.tkColon,
                $.type_ref,
            ),
            seq(
                $.tkVar,
                $.identifier,
            ),
            $.pattern_optional_var,
            $.collection_pattern,
            $.tuple_pattern,
        ),

        simple_expr_or_nothing: $ => prec.left($.simple_expr),

        const_expr_or_nothing: $ => $.const_expr,

        format_expr: $ => prec.left(choice(
            seq(
                $.simple_expr,
                $.tkColon,
                optional($.simple_expr_or_nothing),
            ),
            seq(
                $.tkColon,
                optional($.simple_expr_or_nothing),
            ),
            seq(
                $.simple_expr,
                $.tkColon,
                optional($.simple_expr_or_nothing),
                $.tkColon,
                $.simple_expr,
            ),
            seq(
                $.tkColon,
                optional($.simple_expr_or_nothing),
                $.tkColon,
                $.simple_expr,
            ),
        )),

        format_const_expr: $ => choice(
            seq(
                $.const_expr,
                $.tkColon,
                optional($.const_expr_or_nothing),
            ),
            seq(
                $.tkColon,
                optional($.const_expr_or_nothing),
            ),
            seq(
                $.const_expr,
                $.tkColon,
                optional($.const_expr_or_nothing),
                $.tkColon,
                $.const_expr,
            ),
            seq(
                $.tkColon,
                optional($.const_expr_or_nothing),
                $.tkColon,
                $.const_expr,
            ),
        ),

        relop: $ => choice(
            $.tkEqual,
            $.tkNotEqual,
            $.tkLower,
            $.tkGreater,
            $.tkLowerEqual,
            $.tkGreaterEqual,
            $.tkIn,
        ),

        simple_expr: $ => prec.left(choice(
            $.term1,
            seq(
                $.simple_expr,
                $.tkDotDot,
                $.term1,
            ),
        )),

        term1: $ => prec.right(choice(
            $.term,
            seq(
                $.term1,
                $.addop,
                $.term,
            ),
            seq(
                $.term1,
                $.addop,
                $.new_question_expr,
            ),
        )),

        addop: $ => choice(
            $.tkPlus,
            $.tkMinus,
            $.tkOr,
            $.tkXor,
            // $.tkCSharpStyleOr,
        ),

        typecast_op: $ => choice(
            $.tkAs,
            $.tkIs,
        ),

        as_is_expr: $ => choice(
            $.is_type_expr,
            $.as_expr,
        ),

        as_expr: $ => seq(
            $.term,
            $.tkAs,
            $.simple_or_template_type_reference,
        ),

        is_type_expr: $ => seq(
            $.term,
            $.tkIs,
            $.simple_or_template_type_reference,
        ),

        power_expr: $ => choice(
            seq(
                $.factor_without_unary_op,
                $.tkStarStar,
                $.factor,
            ),
            seq(
                $.factor_without_unary_op,
                $.tkStarStar,
                $.power_expr,
            ),
            seq(
                $.sign,
                $.power_expr,
            ),
        ),

        term: $ => prec(6, choice(
            $.factor,
            $.new_expr,
            $.power_expr,
            seq(
                $.term,
                $.mulop,
                $.factor,
            ),
            seq(
                $.term,
                $.mulop,
                $.power_expr,
            ),
            seq(
                $.term,
                $.mulop,
                $.new_question_expr,
            ),
            $.as_is_expr,
        )),

        mulop: $ => choice(
            $.tkStar,
            $.tkSlash,
            $.tkDiv,
            $.tkMod,
            $.tkShl,
            $.tkShr,
            $.tkAnd,
        ),

        default_expr: $ => seq(
            $.tkDefault,
            $.tkRoundOpen,
            $.simple_or_template_type_reference,
            $.tkRoundClose,
        ),

        tuple: $ => prec.right(seq(
            $.tkRoundOpen,
            $.expr_l1,
            $.tkComma,
            $.expr_l1_list,
            optional($.lambda_type_ref),
            $.optional_full_lambda_fp_list,
            $.tkRoundClose,
        )),

        factor_without_unary_op: $ => choice(
            $.literal,
            $.unsigned_number,
            $.var_reference,
        ),

        factor: $ => prec(6, choice(
            $.tkNil,
            $.literal,
            $.unsigned_number,
            $.default_expr,
            seq(
                $.tkSquareOpen,
                optional($.elem_list),
                $.tkSquareClose,
            ),
            seq(
                $.tkNot,
                $.factor,
            ),
            seq(
                $.sign,
                $.factor,
            ),
            seq(
                $.tkDeref,
                $.factor,
            ),
            $.var_reference,
            $.tuple,
        )),

        var_question_point: $ => prec.left(5, choice(
            seq(
                $.variable,
                $.tkQuestionPoint,
                $.variable,
            ),
            seq(
                $.variable,
                $.tkQuestionPoint,
                $.var_question_point,
            ),
        )),

        var_reference: $ => prec.right(6, choice(
            seq(
                $.var_address,
                $.variable,
            ),
            $.variable,
            $.var_question_point,
        )),

        var_address: $ => choice(
            $.tkAddressOf,
            seq(
                $.var_address,
                $.tkAddressOf,
            ),
        ),

        dotted_identifier: $ => choice(
            $.identifier,
            seq(
                $.dotted_identifier,
                $.tkPoint,
                $.identifier_or_keyword,
            ),
        ),

        variable_as_type: $ => choice(
            $.dotted_identifier,
            seq(
                $.dotted_identifier,
                $.template_type_params,
            ),
        ),

        variable: $ => prec.right(choice(
            $.identifier,
            $.operator_name_ident,
            seq(
                $.tkInherited,
                $.identifier,
            ),
            seq(
                $.tkRoundOpen,
                $.expr,
                $.tkRoundClose,
            ),
            $.sizeof_expr,
            $.typeof_expr,
            seq(
                choice(
                    $.literal,
                    $.unsigned_number),
                $.tkPoint,
                $.identifier_or_keyword,
            ),
            seq(
                $.variable,
                choice(
                    $.literal,
                    $.unsigned_number),
                $.tkSquareOpen,
                $.expr_list,
                $.tkSquareClose,
            ),
            seq(
                $.variable,
                $.tkQuestionSquareOpen,
                $.format_expr,
                $.tkSquareClose,
            ),
            seq(
                $.tkVertParen,
                optional($.elem_list),
                $.tkVertParen,
            ),
            seq(
                $.variable,
                $.tkRoundOpen,
                optional($.optional_expr_list),
                $.tkRoundClose,
            ),
            seq(
                $.variable,
                $.tkPoint,
                $.identifier_keyword_operatorname,
            ),
            seq(
                $.tuple,
                $.tkPoint,
                $.identifier_keyword_operatorname,
            ),
            seq(
                $.variable,
                $.tkDeref,
            ),
            seq(
                $.variable,
                $.tkAmpersend,
                $.template_type_params,
            ),
        )),

        optional_expr_list: $ => $.expr_list,

        elem_list: $ => choice(
            $.elem,
            seq(
                $.elem_list,
                $.tkComma,
                $.elem,
            ),
        ),

        elem: $ => choice(
            $.expr,
            seq(
                $.expr,
                $.tkDotDot,
                $.expr,
            ),
        ),

        one_literal: $ => choice(
            $.tkStringLiteral,
            $.tkAsciiChar,
        ),

        literal: $ => choice(
            repeat1($.one_literal),
            $.tkFormatStringLiteral,
        ),

        operator_name_ident: $ => seq(
            $.tkOperator,
            $.overload_operator,
        ),

        optional_method_modificators: $ => choice(
            $.tkSemiColon,
            seq(
                $.tkSemiColon,
                $.meth_modificators,
                $.tkSemiColon,
            ),
        ),

        optional_method_modificators1: $ => seq(
            $.tkSemiColon,
            $.meth_modificators,
        ),

        meth_modificators: $ => choice(
            $.meth_modificator,
            seq(
                $.meth_modificators,
                $.tkSemiColon,
                $.meth_modificator,
            ),
        ),

        identifier: $ => prec(6, choice(
            $.tkIdentifier,
            $.property_specifier_directives,
            $.non_reserved,
        )),

        identifier_or_keyword: $ => choice(
            $.identifier,
            $.keyword,
            $.reserved_keyword,
        ),

        identifier_keyword_operatorname: $ => choice(
            $.identifier,
            $.keyword,
            $.operator_name_ident,
        ),

        meth_modificator: $ => choice(
            $.tkAbstract,
            $.tkOverload,
            $.tkReintroduce,
            $.tkOverride,
            $.tkExtensionMethod,
            $.tkVirtual,
        ),

        property_modificator: $ => choice(
            $.tkVirtual,
            $.tkOverride,
            $.tkAbstract,
            $.tkReintroduce,
        ),

        property_specifier_directives: $ => prec.left(6, choice(
            $.tkRead,
            $.tkWrite,
        )),

        non_reserved: $ => prec.left(choice(
            $.tkName,
            $.tkNew,
        )),

        visibility_specifier: $ => choice(
            $.tkInternal,
            $.tkPublic,
            $.tkProtected,
            $.tkPrivate,
        ),

        keyword: $ => choice(
            $.visibility_specifier,
            $.tkSealed,
            $.tkTemplate,
            $.tkOr,
            $.tkTypeOf,
            $.tkSizeOf,
            $.tkDefault,
            $.tkWhere,
            $.tkXor,
            $.tkAnd,
            $.tkDiv,
            $.tkMod,
            $.tkShl,
            $.tkShr,
            $.tkNot,
            $.tkAs,
            $.tkIn,
            $.tkIs,
            $.tkArray,
            $.tkSequence,
            $.tkBegin,
            $.tkCase,
            $.tkClass,
            $.tkConst,
            $.tkConstructor,
            $.tkDestructor,
            $.tkDownto,
            $.tkDo,
            $.tkElse,
            $.tkEnd,
            $.tkExcept,
            $.tkFile,
            $.tkAuto,
            $.tkFinalization,
            $.tkFinally,
            $.tkFor,
            $.tkForeach,
            $.tkFunction,
            $.tkIf,
            $.tkImplementation,
            $.tkInherited,
            $.tkInitialization,
            $.tkInterface,
            $.tkProcedure,
            $.tkProperty,
            $.tkRaise,
            $.tkRecord,
            $.tkRepeat,
            $.tkSet,
            $.tkTry,
            $.tkType,
            $.tkStatic,
            $.tkThen,
            $.tkTo,
            $.tkUntil,
            $.tkUses,
            $.tkVar,
            $.tkWhile,
            $.tkWith,
            $.tkNil,
            $.tkGoto,
            $.tkOf,
            $.tkLabel,
            $.tkProgram,
            $.tkUnit,
            $.tkLibrary,
            $.tkNamespace,
            $.tkExternal,
            $.tkParams,
            $.tkEvent,
            $.tkYield,
            $.tkMatch,
            $.tkWhen,
            $.tkPartial,
            $.tkAbstract,
            $.tkLock,
            $.tkImplicit,
            $.tkExplicit,
            $.tkOn,
            $.tkVirtual,
            $.tkOverride,
            $.tkLoop,
            $.tkExtensionMethod,
            $.tkOverload,
            $.tkReintroduce,
            $.tkForward,
        ),

        reserved_keyword: $ => $.tkOperator,

        overload_operator: $ => choice(
            $.tkMinus,
            $.tkPlus,
            $.tkSlash,
            $.tkStar,
            $.tkEqual,
            $.tkGreater,
            $.tkGreaterEqual,
            $.tkLower,
            $.tkLowerEqual,
            $.tkNotEqual,
            $.tkOr,
            $.tkXor,
            $.tkAnd,
            $.tkDiv,
            $.tkMod,
            $.tkShl,
            $.tkShr,
            $.tkNot,
            $.tkIn,
            $.tkImplicit,
            $.tkExplicit,
            $.assign_operator,
            $.tkStarStar,
        ),

        assign_operator: $ => choice(
            $.tkAssign,
            $.tkPlusEqual,
            $.tkMinusEqual,
            $.tkMultEqual,
            $.tkDivEqual,
        ),

        func_decl_lambda: $ => choice(
            seq(
                $.identifier,
                $.tkArrow,
                $.lambda_function_body,
            ),
            seq(
                $.tkRoundOpen,
                $.tkRoundClose,
                optional($.lambda_type_ref_noproctype),
                $.tkArrow,
                $.lambda_function_body,
            ),
            seq(
                $.tkRoundOpen,
                $.identifier,
                $.tkColon,
                $.type_ref,
                $.tkRoundClose,
                optional($.lambda_type_ref_noproctype),
                $.tkArrow,
                $.lambda_function_body,
            ),
            seq(
                $.tkRoundOpen,
                $.identifier,
                $.tkSemiColon,
                $.full_lambda_fp_list,
                $.tkRoundClose,
                optional($.lambda_type_ref_noproctype),
                $.tkArrow,
                $.lambda_function_body,
            ),
            seq(
                $.tkRoundOpen,
                $.identifier,
                $.tkColon,
                $.type_ref,
                $.tkSemiColon,
                $.full_lambda_fp_list,
                $.tkRoundClose,
                optional($.lambda_type_ref_noproctype),
                $.tkArrow,
                $.lambda_function_body,
            ),
            seq(
                $.tkRoundOpen,
                $.expr_l1,
                $.tkComma,
                $.expr_l1_list,
                optional($.lambda_type_ref),
                $.optional_full_lambda_fp_list,
                $.tkRoundClose,
                $.rem_lambda,
            ),
            $.expl_func_decl_lambda,
        ),

        optional_full_lambda_fp_list: $ => seq(
            $.tkSemiColon,
            $.full_lambda_fp_list,
        ),

        rem_lambda: $ => seq(
            optional($.lambda_type_ref_noproctype),
            $.tkArrow,
            $.lambda_function_body,
        ),

        expl_func_decl_lambda: $ => choice(
            seq(
                $.tkFunction,
                optional($.lambda_type_ref_noproctype),
                $.tkArrow,
                $.lambda_function_body,
            ),
            seq(
                $.tkFunction,
                $.tkRoundOpen,
                $.tkRoundClose,
                optional($.lambda_type_ref_noproctype),
                $.tkArrow,
                $.lambda_function_body,
            ),
            seq(
                $.tkFunction,
                $.tkRoundOpen,
                $.full_lambda_fp_list,
                $.tkRoundClose,
                optional($.lambda_type_ref_noproctype),
                $.tkArrow,
                $.lambda_function_body,
            ),
            seq(
                $.tkProcedure,
                $.tkArrow,
                $.lambda_procedure_body,
            ),
            seq(
                $.tkProcedure,
                $.tkRoundOpen,
                $.tkRoundClose,
                $.tkArrow,
                $.lambda_procedure_body,
            ),
            seq(
                $.tkProcedure,
                $.tkRoundOpen,
                $.full_lambda_fp_list,
                $.tkRoundClose,
                $.tkArrow,
                $.lambda_procedure_body,
            ),
        ),

        full_lambda_fp_list: $ => choice(
            $.lambda_simple_fp_sect,
            seq(
                $.full_lambda_fp_list,
                $.tkSemiColon,
                $.lambda_simple_fp_sect,
            ),
        ),
        lambda_simple_fp_sect: $ => seq(
            $.ident_list,
            optional($.lambda_type_ref),
        ),

        lambda_type_ref: $ => seq(
            $.tkColon,
            $.type_ref,
        ),

        lambda_type_ref_noproctype: $ => seq(
            $.tkColon,
            $.fptype_noproctype,
        ),

        common_lambda_body: $ => choice(
            $.compound_stmt,
            $.if_stmt,
            $.while_stmt,
            $.repeat_stmt,
            $.for_stmt,
            $.foreach_stmt,
            $.loop_stmt,
            $.case_stmt,
            $.try_stmt,
            $.lock_stmt,
            $.raise_stmt,
            $.yield_stmt,
        ),

        lambda_function_body: $ => choice(
            $.expr_l1_for_lambda,
            $.common_lambda_body,
        ),

        lambda_procedure_body: $ => choice(
            $.proc_call,
            $.assignment,
            $.common_lambda_body,
        ),

        tkVertParen: $ => "|",
        tkAmpersend: $ => "&",
        tkComma: $ => ",",
        tkColon: $ => ":",
        tkDotDot: $ => "..",
        tkPoint: $ => ".",
        tkRoundOpen: $ => "(",
        tkRoundClose: $ => ")",
        tkSemiColon: $ => ";",
        tkSquareOpen: $ => "[",
        tkSquareClose: $ => "]",
        tkQuestion: $ => "?",
        tkUnderscore: $ => "_",
        tkQuestionPoint: $ => "?.",
        tkDoubleQuestion: $ => "??",
        tkQuestionSquareOpen: $ => "?[",
        tkAddressOf: $ => "@",
        tkAssign: $ => ":=",
        tkPlusEqual: $ => "+=",
        tkMinusEqual: $ => "-=",
        tkMultEqual: $ => "*=",
        tkDivEqual: $ => "/=",
        tkMinus: $ => "-",
        tkPlus: $ => "+",
        tkSlash: $ => "/",
        tkStar: $ => "*",
        tkStarStar: $ => "**",
        tkEqual: $ => "=",
        tkGreater: $ => ">",
        tkGreaterEqual: $ => ">=",
        tkLower: $ => "<",
        tkLowerEqual: $ => "<=",
        tkNotEqual: $ => "<>",
        tkDeref: $ => "^",
        tkArrow: $ => "->",
        tkBackSlashRoundOpen: $ => "\\[(]",
        tkArrow: $ => "→",
        tkShortProgram: $ => prec(5, /[#][#][ \t\r\n]+/),
        tkShortSFProgram: $ => prec(5, /[#][#][#][ \t\r\n]+/),
        tkDirectiveName: $ => seq("#", $.letterDigit),
        tkIdentifier: $ => $.ID,
        tkStringLiteral: $ => /\'([^\'\n]|\'\')*\'/,
        tkInteger: $ => prec.right(7, repeat1($.digit)),
        tkHex: $ => prec.right(6, repeat1($.hexDigit)),
        tkFloat: $ => seq($.tkInteger, ".", $.tkInteger),
        tkAsciiChar: $ => prec.right(seq("#", repeat1($.digit))),
        tkFormatStringLiteral: $ => /\$\'([^\'\n]|\'\')*\'/,

        letter: $ => /\p{L}/,
        digit: $ => /\p{Nd}/,
        hexDigit: $ => prec.right(repeat1(prec(6, choice($.digit, /[abcdefABCDEF]/)))),
        letterDigit: $ => prec.right(6, choice($.letter, $.digit)),
        ID: $ => prec.right(7, seq($.letter, repeat($.letterDigit))),

        tkOr: $ => "or",
        tkXor: $ => "xor",
        tkAnd: $ => "and",
        tkDiv: $ => "div",
        tkMod: $ => "mod",
        tkShl: $ => "shl",
        tkShr: $ => "shr",
        tkNot: $ => "not",
        tkAs: $ => "as",
        tkIn: $ => "in",
        tkIs: $ => "is",
        tkImplicit: $ => "implicit",
        tkExplicit: $ => "explicit",
        tkSizeOf: $ => "sizeof",
        tkTypeOf: $ => "typeof",
        tkWhere: $ => "where",
        tkArray: $ => "array",
        tkBegin: $ => "begin",
        tkCase: $ => "case",
        tkClass: $ => "class",
        tkConst: $ => "const",
        tkConstructor: $ => "constructor",
        tkDefault: $ => "default",
        tkDestructor: $ => "destructor",
        tkDownto: $ => "downto",
        tkDo: $ => "do",
        tkElse: $ => "else",
        tkEnd: $ => "end",
        tkEvent: $ => "event",
        tkExcept: $ => "except",
        tkExports: $ => "exports",
        tkFile: $ => "file",
        tkFinalization: $ => "finalization",
        tkFinally: $ => "finally",
        tkFor: $ => "for",
        tkForeach: $ => "foreach",
        tkFunction: $ => "function",
        tkGoto: $ => "goto",
        tkIf: $ => "if",
        tkImplementation: $ => "implementation",
        tkInherited: $ => "inherited",
        tkInitialization: $ => "initialization",
        tkInterface: $ => "interface",
        tkLabel: $ => "label",
        tkLock: $ => "lock",
        tkLoop: $ => "loop",
        tkNil: $ => "nil",
        tkProcedure: $ => "procedure",
        tkOf: $ => "of",
        tkOperator: $ => "operator",
        tkProperty: $ => "property",
        tkRaise: $ => "raise",
        tkRecord: $ => "record",
        tkRepeat: $ => "repeat",
        tkSet: $ => "set",
        tkTry: $ => "try",
        tkType: $ => "type",
        tkThen: $ => "then",
        tkTo: $ => "to",
        tkUntil: $ => "until",
        tkUses: $ => "uses",
        tkVar: $ => "var",
        tkWhile: $ => "while",
        tkWith: $ => "with",
        tkProgram: $ => "program",
        tkTemplate: $ => "template",
        tkPacked: $ => "packed",
        tkResourceString: $ => "resourcestring",
        tkThreadvar: $ => "threadvar",
        tkSealed: $ => "sealed",
        tkPartial: $ => "partial",
        tkParams: $ => "params",
        tkUnit: $ => "unit",
        tkLibrary: $ => "library",
        tkExternal: $ => "external",
        tkName: $ => "name",
        tkPrivate: $ => "private",
        tkProtected: $ => "protected",
        tkPublic: $ => "public",
        tkInternal: $ => "internal",
        tkRead: $ => "read",
        tkWrite: $ => "write",
        tkOn: $ => "on",
        tkForward: $ => "forward",
        tkAbstract: $ => "abstract",
        tkOverload: $ => "overload",
        tkReintroduce: $ => "reintroduce",
        tkOverride: $ => "override",
        tkVirtual: $ => "virtual",
        tkExtensionMethod: $ => "extensionmethod",
        tkNew: $ => "new",
        tkAuto: $ => "auto",
        tkSequence: $ => "sequence",
        tkYield: $ => "yield",
        tkMatch: $ => "match",
        tkWhen: $ => "when",
        tkNamespace: $ => "namespace",
        tkStatic: $ => "static",
    }
});