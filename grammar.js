module.exports = grammar({
    name: 'pascalabcnet',

    conflicts: $ => [
        [$.assignment, $.variable_or_literal_or_number],
        [$.format_expr],
        [$.relop_expr, $.simple_expr],
        [$.assignment, $.var_reference],
        [$.new_expr, $.non_reserved],
        [$.relop_expr, $.simple_expr],
        [$.relop_expr, $.as_is_expr],
        [$.var_reference, $.variable],
        [$.literal, $.literal_list],
        [$.class_or_interface_keyword],
        [$.int_decl_sect, $.type_decl_sect],
        [$.format_expr, $.simple_expr],
        [$.variable, $.func_decl_lambda],
        [$.const_factor_without_unary_op, $.const_factor, $.typed_const],
        [$.type_ref, $.proc_type_decl],
        [$.simple_type_question, $.type_ref],
        [$.template_param, $.proc_type_decl],
        [$.write_property_specifiers, $.property_specifier_directives],
        [$.read_property_specifiers, $.property_specifier_directives],
        [$.expr_l1_for_new_question_expr, $.expr_dq]
    ],

    rules: {
        parse_goal: $ => choice(
            $.program_file,
            $.unit_file,
            seq(
                $.tkShortProgram,
                optional($.uses_clause_one_or_empty),
                optional($.decl_sect_list_proc_func_only),
                optional($.stmt_list),
            ),
            seq(
                $.tkShortSFProgram,
                optional($.uses_clause_one_or_empty),
                optional($.decl_sect_list_proc_func_only),
                optional($.stmt_list),
            ),
        ),
        stmt_or_expression: $ => choice(
            $.expr,
            $.assignment,
            $.var_stmt,
        ),
        optional_head_compiler_directives: $ => $.head_compiler_directives,
        head_compiler_directives: $ => choice(
            $.one_compiler_directive,
            seq(
                $.head_compiler_directives,
                $.one_compiler_directive,
            ),
        ),
        one_compiler_directive: $ => choice(
            seq(
                $.tkDirectiveName,
                $.tkIdentifier,
            ),
            seq(
                $.tkDirectiveName,
                $.tkStringLiteral,
            ),
        ),
        program_file: $ => prec.right(seq(
            optional($.program_header),
            optional($.optional_head_compiler_directives),
            optional($.uses_clause),
            $.program_block,
            optional($.optional_tk_point),
        )),

        optional_tk_point: $ => choice(
            $.tkPoint,
            $.tkSemiColon,
            $.tkColon,
            $.tkComma,
            $.tkDotDot,
        ),
        program_header: $ => seq(
            $.tkProgram,
            $.identifier,
            $.program_heading_2,
        ),
        program_heading_2: $ => choice(
            $.tkSemiColon,
            seq(
                $.tkRoundOpen,
                $.program_param_list,
                $.tkRoundClose,
                $.tkSemiColon,
            ),
        ),
        program_param_list: $ => choice(
            $.program_param,
            seq(
                $.program_param_list,
                $.tkComma,
                $.program_param,
            ),
        ),
        program_param: $ => $.identifier,
        program_block: $ => seq(
            optional($.decl_sect_list1),
            $.compound_stmt,
        ),

        ident_or_keyword_pointseparator_list: $ => choice(
            $.identifier_or_keyword,
            seq(
                $.ident_or_keyword_pointseparator_list,
                $.tkPoint,
                $.identifier_or_keyword,
            ),
        ),
        uses_clause_one: $ => seq(
            $.tkUses,
            $.used_units_list,
            $.tkSemiColon,
        ),

        uses_clause_one_or_empty: $ => $.uses_clause_one,
        uses_clause: $ => seq(
            optional($.uses_clause),
            $.uses_clause_one,
        ),
        used_units_list: $ => choice(
            $.used_unit_name,
            seq(
                $.used_units_list,
                $.tkComma,
                $.used_unit_name,
            ),
        ),
        used_unit_name: $ => choice(
            $.ident_or_keyword_pointseparator_list,
            seq(
                $.ident_or_keyword_pointseparator_list,
                $.tkIn,
                $.tkStringLiteral,
            ),
        ),
        unit_file: $ => choice(
            seq(
                optional($.attribute_declarations),
                $.unit_header,
                $.interface_part,
                $.implementation_part,
                $.initialization_part,
                $.tkPoint,
            ),
            seq(
                optional($.attribute_declarations),
                $.unit_header,
                seq(
                    optional($.uses_clause),
                    optional($.decl_sect_list1),
                ),
                $.initialization_part,
                $.tkPoint,
            ),
        ),
        unit_header: $ => choice(
            seq(
                $.unit_key_word,
                $.unit_name,
                $.tkSemiColon,
                optional($.optional_head_compiler_directives),
            ),
            seq(
                $.tkNamespace,
                $.ident_or_keyword_pointseparator_list,
                $.tkSemiColon,
                optional($.optional_head_compiler_directives),
            ),
        ),
        unit_key_word: $ => choice(
            $.tkUnit,
            $.tkLibrary,
        ),
        unit_name: $ => $.identifier,
        interface_part: $ => seq(
            $.tkInterface,
            optional($.uses_clause),
            optional($.int_decl_sect_list1),
        ),

        implementation_part: $ => seq(
            $.tkImplementation,
            optional($.uses_clause),
            optional($.decl_sect_list1),
        ),

        initialization_part: $ => choice(
            $.tkEnd,
            seq(
                $.tkInitialization,
                optional($.stmt_list),
                $.tkEnd,
            ),
            seq(
                $.tkInitialization,
                optional($.stmt_list),
                $.tkFinalization,
                optional($.stmt_list),
                $.tkEnd,
            ),
            seq(
                $.tkBegin,
                optional($.stmt_list),
                $.tkEnd,
            ),
        ),
        int_decl_sect_list1: $ => seq(
            optional($.int_decl_sect_list1),
            $.int_decl_sect,
        ),
        decl_sect_list_proc_func_only: $ => seq(
            optional($.decl_sect_list_proc_func_only),
            $.proc_func_decl_noclass,
        ),
        decl_sect_list1: $ => seq(
            optional($.decl_sect_list1),
            $.decl_sect,
        ),
        inclass_decl_sect_list1: $ => seq(
            optional($.inclass_decl_sect_list1),
            $.abc_decl_sect,
        ),
        int_decl_sect: $ => choice(
            $.const_decl_sect,
            $.res_str_decl_sect,
            $.type_decl_sect,
            $.var_decl_sect,
            $.int_proc_header,
            $.int_func_header,
        ),
        decl_sect: $ => prec.right(choice(
            $.label_decl_sect,
            $.const_decl_sect,
            $.res_str_decl_sect,
            $.type_decl_sect,
            $.var_decl_sect,
            $.proc_func_constr_destr_decl_with_attr,
        )),
        proc_func_constr_destr_decl: $ => choice(
            $.proc_func_decl,
            $.constr_destr_decl,
        ),
        proc_func_constr_destr_decl_with_attr: $ => seq(
            optional($.attribute_declarations),
            $.proc_func_constr_destr_decl,
        ),

        abc_decl_sect: $ => choice(
            $.label_decl_sect,
            $.const_decl_sect,
            $.res_str_decl_sect,
            $.type_decl_sect,
            $.var_decl_sect,
        ),
        int_proc_header: $ => choice(
            seq(
                optional($.attribute_declarations),
                $.proc_header,
            ),
            seq(
                optional($.attribute_declarations),
                $.proc_header,
                $.tkForward,
                $.tkSemiColon,
            ),
        ),
        int_func_header: $ => choice(
            seq(
                optional($.attribute_declarations),
                $.func_header,
            ),
            seq(
                optional($.attribute_declarations),
                $.func_header,
                $.tkForward,
                $.tkSemiColon,
            ),
        ),
        label_decl_sect: $ => seq(
            $.tkLabel,
            $.label_list,
            $.tkSemiColon,
        ),

        label_list: $ => choice(
            $.label_name,
            seq(
                $.label_list,
                $.tkComma,
                $.label_name,
            ),
        ),
        label_name: $ => choice(
            $.tkInteger,
            $.identifier,
        ),
        const_decl_sect: $ => choice(
            seq(
                $.tkConst,
                $.const_decl,
            ),
            seq(
                $.const_decl_sect,
                $.const_decl,
            ),
        ),
        res_str_decl_sect: $ => choice(
            seq(
                $.tkResourceString,
                $.const_decl,
            ),
            seq(
                $.res_str_decl_sect,
                $.const_decl,
            ),
        ),
        type_decl_sect: $ => choice(
            seq(
                $.tkType,
                $.type_decl,
            ),
            seq(
                $.type_decl_sect,
                $.type_decl,
            ),
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
                $.tkSemiColon,
            ),
        ),
        var_decl_sect: $ => choice(
            seq(
                $.tkVar,
                $.var_decl_with_assign_var_tuple,
            ),
            seq(
                $.tkEvent,
                $.var_decl_with_assign_var_tuple,
            ),
            seq(
                $.var_decl_sect,
                $.var_decl_with_assign_var_tuple,
            ),
        ),
        const_decl: $ => seq(
            $.only_const_decl,
            $.tkSemiColon,
        ),

        only_const_decl: $ => choice(
            seq(
                $.const_name,
                $.tkEqual,
                $.init_const_expr,
            ),
            seq(
                $.const_name,
                $.tkColon,
                $.type_ref,
                $.tkEqual,
                $.typed_const,
            ),
        ),
        init_const_expr: $ => choice(
            $.const_expr,
            $.array_const,
        ),
        const_name: $ => $.identifier,
        const_relop_expr: $ => choice(
            $.const_simple_expr,
            seq(
                $.const_relop_expr,
                $.const_relop,
                $.const_simple_expr,
            ),
        ),
        const_expr: $ => choice(
            $.const_relop_expr,
            $.question_constexpr,
            seq(
                $.const_expr,
                $.tkDoubleQuestion,
                $.const_relop_expr,
            ),
        ),
        question_constexpr: $ => prec.right(seq(
            $.const_expr,
            $.tkQuestion,
            $.const_expr,
            $.tkColon,
            $.const_expr,
        )),

        const_relop: $ => choice(
            $.tkEqual,
            $.tkNotEqual,
            $.tkLower,
            $.tkGreater,
            $.tkLowerEqual,
            $.tkGreaterEqual,
            $.tkIn,
        ),
        const_simple_expr: $ => choice(
            $.const_term,
            seq(
                $.const_simple_expr,
                $.const_addop,
                $.const_term,
            ),
        ),
        const_addop: $ => choice(
            $.tkPlus,
            $.tkMinus,
            $.tkOr,
            $.tkXor,
        ),
        as_is_constexpr: $ => seq(
            $.const_term,
            $.typecast_op,
            $.simple_or_template_type_reference,
        ),

        power_constexpr: $ => choice(
            seq(
                $.const_factor_without_unary_op,
                $.tkStarStar,
                $.const_factor,
            ),
            seq(
                $.const_factor_without_unary_op,
                $.tkStarStar,
                $.power_constexpr,
            ),
            seq(
                $.sign,
                $.power_constexpr,
            ),
        ),
        const_term: $ => choice(
            $.const_factor,
            $.as_is_constexpr,
            $.power_constexpr,
            seq(
                $.const_term,
                $.const_mulop,
                $.const_factor,
            ),
            seq(
                $.const_term,
                $.const_mulop,
                $.power_constexpr,
            ),
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
                $.tkRoundClose,
            ),
        ),
        const_factor: $ => choice(
            $.const_variable,
            $.const_set,
            $.tkNil,
            seq(
                $.tkAddressOf,
                $.const_factor,
            ),
            seq(
                $.tkRoundOpen,
                $.const_expr,
                $.tkRoundClose,
            ),
            seq(
                $.tkNot,
                $.const_factor,
            ),
            seq(
                $.sign,
                $.const_factor,
            ),
            $.new_expr,
            $.default_expr,
        ),
        const_set: $ => prec.right(choice(
            seq(
                $.tkSquareOpen,
                optional($.elem_list),
                $.tkSquareClose,
            ),
            seq(
                $.tkVertParen,
                optional($.elem_list),
                $.tkVertParen,
            ),
        )),
        sign: $ => choice(
            $.tkPlus,
            $.tkMinus,
        ),
        const_variable: $ => choice(
            $.identifier,
            $.literal,
            $.unsigned_number,
            seq(
                $.tkInherited,
                $.identifier,
            ),
            $.sizeof_expr,
            $.typeof_expr,
            seq(
                $.const_variable,
                $.const_variable_2,
            ),
            seq(
                $.const_variable,
                $.tkAmpersend,
                $.template_type_params,
            ),
            seq(
                $.const_variable,
                $.tkSquareOpen,
                $.format_const_expr,
                $.tkSquareClose,
            ),
        ),
        const_variable_2: $ => choice(
            seq(
                $.tkPoint,
                $.identifier_or_keyword,
            ),
            $.tkDeref,
            seq(
                $.tkRoundOpen,
                optional($.optional_const_func_expr_list),
                $.tkRoundClose,
            ),
            seq(
                $.tkSquareOpen,
                optional($.const_elem_list),
                $.tkSquareClose,
            ),
        ),
        optional_const_func_expr_list: $ => $.expr_list,
        const_elem_list: $ => $.const_elem_list1,
        const_elem_list1: $ => choice(
            $.const_elem,
            seq(
                $.const_elem_list1,
                $.tkComma,
                $.const_elem,
            ),
        ),
        const_elem: $ => choice(
            $.const_expr,
            seq(
                $.const_expr,
                $.tkDotDot,
                $.const_expr,
            ),
        ),
        unsigned_number: $ => choice(
            $.tkInteger,
            $.tkHex,
            $.tkFloat,
        ),
        typed_const: $ => choice(
            $.const_expr,
            $.array_const,
            $.record_const,
        ),
        array_const: $ => seq(
            $.tkRoundOpen,
            optional($.typed_const_list),
            $.tkRoundClose,
        ),

        typed_const_list: $ => $.typed_const_list1,
        typed_const_list1: $ => choice(
            $.typed_const_plus,
            seq(
                $.typed_const_list1,
                $.tkComma,
                $.typed_const_plus,
            ),
        ),
        record_const: $ => seq(
            $.tkRoundOpen,
            $.const_field_list,
            $.tkRoundClose,
        ),

        const_field_list: $ => choice(
            $.const_field_list_1,
            seq(
                $.const_field_list_1,
                $.tkSemiColon,
            ),
        ),
        const_field_list_1: $ => choice(
            $.const_field,
            seq(
                $.const_field_list_1,
                $.tkSemiColon,
                $.const_field,
            ),
        ),
        const_field: $ => seq(
            $.const_field_name,
            $.tkColon,
            $.typed_const,
        ),

        const_field_name: $ => $.identifier,
        type_decl: $ => seq(
            optional($.attribute_declarations),
            $.simple_type_decl,
        ),

        attribute_declarations: $ => choice(
            $.attribute_declaration,
            seq(
                optional($.attribute_declarations),
                $.attribute_declaration,
            ),
        ),
        attribute_declaration: $ => seq(
            $.tkSquareOpen,
            $.one_or_some_attribute,
            $.tkSquareClose,
        ),

        one_or_some_attribute: $ => choice(
            $.one_attribute,
            seq(
                $.one_or_some_attribute,
                $.tkComma,
                $.one_attribute,
            ),
        ),
        one_attribute: $ => choice(
            $.attribute_variable,
            seq(
                $.identifier,
                $.tkColon,
                $.attribute_variable,
            ),
        ),
        simple_type_decl: $ => choice(
            seq(
                $.type_decl_identifier,
                $.tkEqual,
                $.type_decl_type,
                $.tkSemiColon,
            ),
            seq(
                $.template_identifier_with_equal,
                $.type_decl_type,
                $.tkSemiColon,
            ),
        ),
        type_decl_identifier: $ => choice(
            $.identifier,
            seq(
                $.identifier,
                $.template_arguments,
            ),
        ),
        template_identifier_with_equal: $ => seq(
            $.identifier,
            $.tkLower,
            $.ident_list,
            $.tkGreaterEqual,
        ),

        type_decl_type: $ => choice(
            $.type_ref,
            $.object_type,
        ),
        simple_type_question: $ => choice(
            seq(
                $.simple_type,
                $.tkQuestion,
            ),
            seq(
                $.template_type,
                $.tkQuestion,
            ),
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
            $.template_type_params,
        ),

        template_type_params: $ => seq(
            $.tkLower,
            $.template_param_list,
            $.tkGreater,
        ),

        template_type_empty_params: $ => choice(
            $.tkNotEqual,
            seq(
                $.tkLower,
                optional($.template_empty_param_list),
                $.tkGreater,
            ),
        ),
        template_param_list: $ => choice(
            $.template_param,
            seq(
                $.template_param_list,
                $.tkComma,
                $.template_param,
            ),
        ),
        template_empty_param_list: $ => /,+/,
        template_param: $ => prec.right(choice(
            $.simple_type,
            seq(
                $.simple_type,
                $.tkQuestion,
            ),
            $.structured_type,
            $.procedural_type,
            $.template_type,
        )),
        simple_type: $ => prec.right(choice(
            $.range_expr,
            seq(
                $.range_expr,
                $.tkDotDot,
                $.range_expr,
            ),
            seq(
                $.tkRoundOpen,
                $.enumeration_id_list,
                $.tkRoundClose,
            ),
        )),
        range_expr: $ => prec.right(choice(
            $.range_term,
            seq(
                $.range_expr,
                $.const_addop,
                $.range_term,
            ),
        )),
        range_term: $ => prec.right(choice(
            $.range_factor,
            seq(
                $.range_term,
                $.const_mulop,
                $.range_factor,
            ),
        )),
        range_factor: $ => prec.right(choice(
            $.simple_type_identifier,
            $.unsigned_number,
            seq(
                $.sign,
                $.range_factor,
            ),
            $.literal,
            seq(
                $.range_factor,
                $.tkRoundOpen,
                optional($.const_elem_list),
                $.tkRoundClose,
            ),
        )),
        simple_type_identifier: $ => choice(
            $.identifier,
            seq(
                $.simple_type_identifier,
                $.tkPoint,
                $.identifier_or_keyword,
            ),
        ),
        enumeration_id_list: $ => choice(
            seq(
                $.enumeration_id,
                $.tkComma,
                $.enumeration_id,
            ),
            seq(
                $.enumeration_id_list,
                $.tkComma,
                $.enumeration_id,
            ),
        ),
        enumeration_id: $ => choice(
            $.type_ref,
            seq(
                $.type_ref,
                $.tkEqual,
                $.expr,
            ),
        ),
        pointer_type: $ => seq(
            $.tkDeref,
            $.fptype,
        ),

        structured_type: $ => choice(
            $.unpacked_structured_type,
            seq(
                $.tkPacked,
                $.unpacked_structured_type,
            ),
        ),
        unpacked_structured_type: $ => choice(
            $.array_type,
            $.record_type,
            $.set_type,
            $.file_type,
            $.sequence_type,
        ),
        sequence_type: $ => seq(
            $.tkSequence,
            $.tkOf,
            $.type_ref,
        ),

        array_type: $ => choice(
            seq(
                $.tkArray,
                $.tkSquareOpen,
                optional($.simple_type_list),
                $.tkSquareClose,
                $.tkOf,
                $.type_ref,
            ),
            $.unsized_array_type,
        ),
        unsized_array_type: $ => seq(
            $.tkArray,
            $.tkOf,
            $.type_ref,
        ),

        simple_type_list: $ => seq(
            optional(seq(
                $.simple_type_list,
                $.tkComma
            )),
            $.simple_type
        ),

        set_type: $ => seq(
            $.tkSet,
            $.tkOf,
            $.type_ref,
        ),

        file_type: $ => prec.right(choice(
            seq(
                $.tkFile,
                $.tkOf,
                $.type_ref,
            ),
            $.tkFile,
        )),
        string_type: $ => seq(
            $.tkIdentifier,
            $.tkSquareOpen,
            $.const_expr,
            $.tkSquareClose,
        ),

        procedural_type: $ => $.procedural_type_kind,
        procedural_type_kind: $ => $.proc_type_decl,
        proc_type_decl: $ => prec.right(choice(
            seq(
                $.tkProcedure,
                optional($.fp_list),
            ),
            seq(
                $.tkFunction,
                optional($.fp_list),
                $.tkColon,
                $.fptype,
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
            optional($.class_attributes),
            $.class_or_interface_keyword,
            optional($.optional_base_classes),
            optional($.optional_where_section),
            optional($.optional_component_list_seq_end),
        ),

        record_type: $ => seq(
            $.tkRecord,
            optional($.optional_base_classes),
            optional($.optional_where_section),
            optional($.member_list_section),
            $.tkEnd,
        ),

        class_attribute: $ => choice(
            $.tkSealed,
            $.tkPartial,
            $.tkAbstract,
            $.tkAuto,
            $.tkStatic,
        ),
        class_attributes: $ => $.class_attributes1,
        class_attributes1: $ => choice(
            $.class_attribute,
            seq(
                $.class_attributes1,
                $.class_attribute,
            ),
        ),
        class_or_interface_keyword: $ => choice(
            $.tkClass,
            $.tkInterface,
            $.tkTemplate,
            seq(
                $.tkTemplate,
                $.tkClass,
            ),
            seq(
                $.tkTemplate,
                $.tkRecord,
            ),
            seq(
                $.tkTemplate,
                $.tkInterface,
            ),
        ),
        optional_component_list_seq_end: $ => seq(
            optional($.member_list_section),
            $.tkEnd,
        ),
        optional_base_classes: $ => seq(
            $.tkRoundOpen,
            $.base_classes_names_list,
            $.tkRoundClose,
        ),
        base_classes_names_list: $ => choice(
            $.base_class_name,
            seq(
                $.base_classes_names_list,
                $.tkComma,
                $.base_class_name,
            ),
        ),
        base_class_name: $ => choice(
            $.simple_type_identifier,
            $.template_type,
        ),
        template_arguments: $ => seq(
            $.tkLower,
            $.ident_list,
            $.tkGreater,
        ),

        optional_where_section: $ => $.where_part_list,
        where_part_list: $ => choice(
            $.where_part,
            seq(
                $.where_part_list,
                $.where_part,
            ),
        ),
        where_part: $ => seq(
            $.tkWhere,
            $.ident_list,
            $.tkColon,
            $.type_ref_and_secific_list,
            $.tkSemiColon,
        ),

        type_ref_and_secific_list: $ => choice(
            $.type_ref_or_secific,
            seq(
                $.type_ref_and_secific_list,
                $.tkComma,
                $.type_ref_or_secific,
            ),
        ),
        type_ref_or_secific: $ => choice(
            $.type_ref,
            $.tkClass,
            $.tkRecord,
            $.tkConstructor,
        ),

        member_list_section: $ => seq(
            optional(seq(
                $.member_list_section,
                $.ot_visibility_specifier,
            )),
            $.member_list
        ),

        ot_visibility_specifier: $ => choice(
            $.tkInternal,
            $.tkPublic,
            $.tkProtected,
            $.tkPrivate,
        ),
        member_list: $ => choice(
            seq(
                $.field_or_const_definition_list,
                optional($.optional_semicolon),
            ),
            $.method_decl_list,
            seq(
                $.field_or_const_definition_list,
                $.tkSemiColon,
                $.method_decl_list,
            ),
        ),
        ident_list: $ => choice(
            $.identifier,
            seq(
                $.ident_list,
                $.tkComma,
                $.identifier,
            ),
        ),
        optional_semicolon: $ => $.tkSemiColon,
        field_or_const_definition_list: $ => choice(
            $.field_or_const_definition,
            seq(
                $.field_or_const_definition_list,
                $.tkSemiColon,
                $.field_or_const_definition,
            ),
        ),
        field_or_const_definition: $ => seq(
            optional($.attribute_declarations),
            $.simple_field_or_const_definition,
        ),

        method_decl_list: $ => choice(
            $.method_or_property_decl,
            seq(
                $.method_decl_list,
                $.method_or_property_decl,
            ),
        ),
        method_or_property_decl: $ => choice(
            $.method_decl_withattr,
            $.property_definition,
        ),
        simple_field_or_const_definition: $ => choice(
            seq(
                $.tkConst,
                $.only_const_decl,
            ),
            $.field_definition,
            seq(
                $.class_or_static,
                $.field_definition,
            ),
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
        method_decl_withattr: $ => choice(
            seq(
                optional($.attribute_declarations),
                $.method_header,
            ),
            seq(
                optional($.attribute_declarations),
                $.method_decl,
            ),
        ),
        method_decl: $ => choice(
            $.inclass_proc_func_decl,
            $.inclass_constr_destr_decl,
        ),
        method_header: $ => choice(
            seq(
                $.class_or_static,
                $.method_procfunc_header,
            ),
            $.method_procfunc_header,
            $.constr_destr_header,
        ),
        method_procfunc_header: $ => $.proc_func_header,
        proc_func_header: $ => choice(
            $.proc_header,
            $.func_header,
        ),
        constr_destr_header: $ => choice(
            seq(
                $.tkConstructor,
                optional($.optional_proc_name),
                optional($.fp_list),
                $.optional_method_modificators,
            ),
            seq(
                $.class_or_static,
                $.tkConstructor,
                optional($.optional_proc_name),
                optional($.fp_list),
                $.optional_method_modificators,
            ),
            seq(
                $.tkDestructor,
                optional($.optional_proc_name),
                optional($.fp_list),
                $.optional_method_modificators,
            ),
        ),
        optional_proc_name: $ => $.proc_name,
        property_definition: $ => seq(
            optional($.attribute_declarations),
            $.simple_property_definition,
        ),

        simple_property_definition: $ => choice(
            seq(
                $.tkProperty,
                $.func_name,
                $.property_interface,
                optional($.property_specifiers),
                $.tkSemiColon,
                optional($.array_defaultproperty),
            ),
            seq(
                $.tkProperty,
                $.func_name,
                $.property_interface,
                optional($.property_specifiers),
                $.tkSemiColon,
                $.property_modificator,
                $.tkSemiColon,
                optional($.array_defaultproperty),
            ),
            seq(
                $.class_or_static,
                $.tkProperty,
                $.func_name,
                $.property_interface,
                optional($.property_specifiers),
                $.tkSemiColon,
                optional($.array_defaultproperty),
            ),
            seq(
                $.class_or_static,
                $.tkProperty,
                $.func_name,
                $.property_interface,
                optional($.property_specifiers),
                $.tkSemiColon,
                $.property_modificator,
                $.tkSemiColon,
                optional($.array_defaultproperty),
            ),
            seq(
                $.tkAuto,
                $.tkProperty,
                $.func_name,
                $.property_interface,
                optional($.optional_property_initialization),
                $.tkSemiColon,
            ),
            seq(
                $.class_or_static,
                $.tkAuto,
                $.tkProperty,
                $.func_name,
                $.property_interface,
                optional($.optional_property_initialization),
                $.tkSemiColon,
            ),
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
            $.fptype,
        ),

        property_parameter_list: $ => seq(
            $.tkSquareOpen,
            $.parameter_decl_list,
            $.tkSquareClose,
        ),
        parameter_decl_list: $ => choice(
            $.parameter_decl,
            seq(
                $.parameter_decl_list,
                $.tkSemiColon,
                $.parameter_decl,
            ),
        ),
        parameter_decl: $ => seq(
            $.ident_list,
            $.tkColon,
            $.fptype,
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
                optional($.read_property_specifiers),
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
        var_decl_part: $ => choice(
            seq(
                $.ident_list,
                $.tkColon,
                $.type_ref,
            ),
            seq(
                $.ident_list,
                $.tkAssign,
                $.expr_with_func_decl_lambda,
            ),
            seq(
                $.ident_list,
                $.tkColon,
                $.type_ref,
                $.tkAssignOrEqual,
                $.typed_var_init_expression,
            ),
        ),
        typed_var_init_expression: $ => choice(
            $.typed_const_plus,
            seq(
                $.const_simple_expr,
                $.tkDotDot,
                $.const_term,
            ),
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
        typed_const_plus: $ => $.typed_const,
        constr_destr_decl: $ => choice(
            seq(
                $.constr_destr_header,
                $.block,
            ),
            seq(
                $.tkConstructor,
                optional($.optional_proc_name),
                optional($.fp_list),
                $.tkAssign,
                optional($.unlabelled_stmt),
                $.tkSemiColon,
            ),
            seq(
                $.class_or_static,
                $.tkConstructor,
                optional($.optional_proc_name),
                optional($.fp_list),
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
                $.tkConstructor,
                optional($.optional_proc_name),
                optional($.fp_list),
                $.tkAssign,
                optional($.unlabelled_stmt),
                $.tkSemiColon,
            ),
            seq(
                $.class_or_static,
                $.tkConstructor,
                optional($.optional_proc_name),
                optional($.fp_list),
                $.tkAssign,
                optional($.unlabelled_stmt),
                $.tkSemiColon,
            ),
        ),
        proc_func_decl: $ => choice(
            $.proc_func_decl_noclass,
            seq(
                $.class_or_static,
                $.proc_func_decl_noclass,
            ),
        ),
        proc_func_decl_noclass: $ => choice(
            seq(
                $.proc_func_header,
                $.proc_func_external_block,
            ),
            seq(
                $.tkFunction,
                $.func_name,
                optional($.fp_list),
                $.tkColon,
                $.fptype,
                optional($.optional_method_modificators1),
                $.tkAssign,
                $.expr_l1,
                $.tkSemiColon,
            ),
            seq(
                $.tkFunction,
                $.func_name,
                optional($.fp_list),
                optional($.optional_method_modificators1),
                $.tkAssign,
                $.expr_l1,
                $.tkSemiColon,
            ),
            seq(
                $.tkFunction,
                $.func_name,
                optional($.fp_list),
                $.tkColon,
                $.fptype,
                optional($.optional_method_modificators1),
                $.tkAssign,
                $.func_decl_lambda,
                $.tkSemiColon,
            ),
            seq(
                $.tkFunction,
                $.func_name,
                optional($.fp_list),
                optional($.optional_method_modificators1),
                $.tkAssign,
                $.func_decl_lambda,
                $.tkSemiColon,
            ),
            seq(
                $.tkProcedure,
                $.proc_name,
                optional($.fp_list),
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
        inclass_proc_func_decl: $ => choice(
            $.inclass_proc_func_decl_noclass,
            seq(
                $.class_or_static,
                $.inclass_proc_func_decl_noclass,
            ),
        ),
        inclass_proc_func_decl_noclass: $ => choice(
            seq(
                $.proc_func_header,
                $.inclass_block,
            ),
            seq(
                $.tkFunction,
                $.func_name,
                optional($.fp_list),
                $.tkColon,
                $.fptype,
                optional($.optional_method_modificators1),
                $.tkAssign,
                $.expr_l1_func_decl_lambda,
                $.tkSemiColon,
            ),
            seq(
                $.tkFunction,
                $.func_name,
                optional($.fp_list),
                optional($.optional_method_modificators1),
                $.tkAssign,
                $.expr_l1_func_decl_lambda,
                $.tkSemiColon,
            ),
            seq(
                $.tkProcedure,
                $.proc_name,
                optional($.fp_list),
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
        func_class_name_ident_list: $ => choice(
            $.func_class_name_ident,
            seq(
                $.func_class_name_ident_list,
                $.tkPoint,
                $.func_class_name_ident,
            ),
        ),
        func_meth_name_ident: $ => choice(
            $.func_name_with_template_args,
            $.operator_name_ident,
            seq(
                $.operator_name_ident,
                $.template_arguments,
            ),
        ),
        func_name_with_template_args: $ => choice(
            $.func_name_ident,
            seq(
                $.func_name_ident,
                $.template_arguments,
            ),
        ),
        func_name_ident: $ => $.identifier,
        proc_header: $ => seq(
            $.tkProcedure,
            $.proc_name,
            optional($.fp_list),
            $.optional_method_modificators,
            optional($.optional_where_section),
        ),

        func_header: $ => choice(
            seq(
                $.tkFunction,
                $.func_name,
                optional($.fp_list),
                $.optional_method_modificators,
                optional($.optional_where_section),
            ),
            seq(
                $.tkFunction,
                $.func_name,
                optional($.fp_list),
                $.tkColon,
                $.fptype,
                $.optional_method_modificators,
                optional($.optional_where_section),
            ),
        ),
        external_block: $ => choice(
            seq(
                $.tkExternal,
                $.external_directive_ident,
                $.tkName,
                $.external_directive_ident,
                $.tkSemiColon,
            ),
            seq(
                $.tkExternal,
                $.external_directive_ident,
                $.tkSemiColon,
            ),
            seq(
                $.tkExternal,
                $.tkSemiColon,
            ),
        ),
        external_directive_ident: $ => choice(
            $.identifier,
            $.literal,
        ),
        block: $ => seq(
            optional($.decl_sect_list1),
            $.compound_stmt,
            $.tkSemiColon,
        ),

        inclass_block: $ => choice(
            seq(
                optional($.inclass_decl_sect_list1),
                $.compound_stmt,
                $.tkSemiColon,
            ),
            $.external_block,
        ),
        fp_list: $ => choice(
            seq(
                $.tkRoundOpen,
                $.tkRoundClose,
            ),
            seq(
                $.tkRoundOpen,
                $.fp_sect_list,
                $.tkRoundClose,
            ),
        ),
        fp_sect_list: $ => choice(
            $.fp_sect,
            seq(
                $.fp_sect_list,
                $.tkSemiColon,
                $.fp_sect,
            ),
        ),
        fp_sect: $ => seq(
            optional($.attribute_declarations),
            $.simple_fp_sect,
        ),

        simple_fp_sect: $ => choice(
            seq(
                $.param_name_list,
                $.tkColon,
                $.fptype,
            ),
            seq(
                $.tkVar,
                $.param_name_list,
                $.tkColon,
                $.fptype,
            ),
            seq(
                $.tkConst,
                $.param_name_list,
                $.tkColon,
                $.fptype,
            ),
            seq(
                $.tkParams,
                $.param_name_list,
                $.tkColon,
                $.fptype,
            ),
            seq(
                $.param_name_list,
                $.tkColon,
                $.fptype,
                $.tkAssign,
                $.expr,
            ),
            seq(
                $.tkVar,
                $.param_name_list,
                $.tkColon,
                $.fptype,
                $.tkAssign,
                $.expr,
            ),
            seq(
                $.tkConst,
                $.param_name_list,
                $.tkColon,
                $.fptype,
                $.tkAssign,
                $.expr,
            ),
        ),
        param_name_list: $ => choice(
            $.param_name,
            seq(
                $.param_name_list,
                $.tkComma,
                $.param_name,
            ),
        ),
        param_name: $ => $.identifier,
        fptype: $ => $.type_ref,
        fptype_noproctype: $ => choice(
            $.simple_type,
            $.string_type,
            $.pointer_type,
            $.structured_type,
            $.template_type,
        ),
        stmt: $ => choice(
            $.unlabelled_stmt,
            seq(
                $.label_name,
                $.tkColon,
                optional($.stmt),
            ),
        ),
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

        var_stmt: $ => choice(
            seq(
                $.tkVar,
                $.var_decl_part,
            ),
            seq(
                $.tkRoundOpen,
                $.tkVar,
                $.identifier,
                $.tkComma,
                $.var_ident_list,
                $.tkRoundClose,
                $.tkAssign,
                $.expr,
            ),
            seq(
                $.tkVar,
                $.tkRoundOpen,
                $.identifier,
                $.tkComma,
                $.ident_list,
                $.tkRoundClose,
                $.tkAssign,
                $.expr,
            ),
        ),
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
        variable_list: $ => choice(
            $.variable,
            seq(
                $.variable_list,
                $.tkComma,
                $.variable,
            ),
        ),
        var_ident_list: $ => choice(
            seq(
                $.tkVar,
                $.identifier,
            ),
            seq(
                $.var_ident_list,
                $.tkComma,
                $.tkVar,
                $.identifier,
            ),
        ),
        proc_call: $ => $.var_reference,
        goto_stmt: $ => seq(
            $.tkGoto,
            $.label_name,
        ),

        compound_stmt: $ => seq(
            $.tkBegin,
            optional($.stmt_list),
            $.tkEnd,
        ),

        stmt_list: $ => seq(
            optional(seq(
                $.stmt_list,
                $.tkSemiColon,
            )),
            $.stmt,
        ),

        if_stmt: $ => prec.right(choice(
            seq(
                $.tkIf,
                $.expr_l1,
                $.tkThen,
                optional($.unlabelled_stmt),
            ),
            seq(
                $.tkIf,
                $.expr_l1,
                $.tkThen,
                optional($.unlabelled_stmt),
                $.tkElse,
                optional($.unlabelled_stmt),
            ),
        )),
        match_with: $ => choice(
            seq(
                $.tkMatch,
                $.expr_l1,
                $.tkWith,
                $.pattern_cases,
                optional($.else_case),
                $.tkEnd,
            ),
            seq(
                $.tkMatch,
                $.expr_l1,
                $.tkWith,
                $.pattern_cases,
                $.tkSemiColon,
                optional($.else_case),
                $.tkEnd,
            ),
        ),
        pattern_cases: $ => choice(
            $.pattern_case,
            seq(
                $.pattern_cases,
                $.tkSemiColon,
                $.pattern_case,
            ),
        ),
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
        case_list: $ => choice(
            $.case_item,
            seq(
                $.case_list,
                $.tkSemiColon,
                $.case_item,
            ),
        ),
        case_item: $ => seq(
            $.case_label_list,
            $.tkColon,
            optional($.unlabelled_stmt),
        ),

        case_label_list: $ => choice(
            $.case_label,
            seq(
                $.case_label_list,
                $.tkComma,
                $.case_label,
            ),
        ),
        case_label: $ => $.const_elem,
        else_case: $ => seq(
            $.tkElse,
            optional($.stmt_list),
        ),
        repeat_stmt: $ => seq(
            $.tkRepeat,
            optional($.stmt_list),
            $.tkUntil,
            $.expr,
        ),

        while_stmt: $ => prec.left(seq(
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

        foreach_stmt: $ => prec.left(choice(
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
                $.tkColon,
                $.type_ref,
                $.tkIn,
                $.expr_l1,
                $.tkDo,
                optional($.unlabelled_stmt),
            ),
            seq(
                $.tkForeach,
                $.tkVar,
                $.identifier,
                $.tkIn,
                $.expr_l1,
                $.tkDo,
                optional($.unlabelled_stmt),
            ),
            seq(
                $.tkForeach,
                $.tkVar,
                $.tkRoundOpen,
                $.ident_list,
                $.tkRoundClose,
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
        for_stmt_decl_or_assign: $ => choice(
            $.tkAssign,
            seq(
                $.tkColon,
                $.simple_type_identifier,
                $.tkAssign,
            ),
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
            optional($.stmt_list),
            $.try_handler,
        ),

        try_handler: $ => choice(
            seq(
                $.tkFinally,
                optional($.stmt_list),
                $.tkEnd,
            ),
            seq(
                $.tkExcept,
                optional($.exception_block),
                $.tkEnd,
            ),
        ),
        exception_block: $ => choice(
            seq(
                $.exception_handler_list,
                optional($.exception_block_else_branch),
            ),
            seq(
                $.exception_handler_list,
                $.tkSemiColon,
                optional($.exception_block_else_branch),
            ),
            $.stmt_list,
        ),
        exception_handler_list: $ => choice(
            $.exception_handler,
            seq(
                $.exception_handler_list,
                $.tkSemiColon,
                $.exception_handler,
            ),
        ),
        exception_block_else_branch: $ => seq(
            $.tkElse,
            optional($.stmt_list),
        ),
        exception_handler: $ => seq(
            $.tkOn,
            $.exception_identifier,
            $.tkDo,
            optional($.unlabelled_stmt),
        ),

        exception_identifier: $ => choice(
            $.exception_class_type_identifier,
            seq(
                $.exception_variable,
                $.tkColon,
                $.exception_class_type_identifier,
            ),
        ),
        exception_class_type_identifier: $ => $.simple_type_identifier,
        exception_variable: $ => $.identifier,
        raise_stmt: $ => prec.right(choice(
            $.tkRaise,
            seq(
                $.tkRaise,
                $.expr,
            ),
        )),
        expr_list: $ => choice(
            $.expr_with_func_decl_lambda,
            seq(
                $.expr_list,
                $.tkComma,
                $.expr_with_func_decl_lambda,
            ),
        ),
        expr_as_stmt: $ => $.allowable_expr_as_stmt,
        allowable_expr_as_stmt: $ => $.new_expr,
        expr_with_func_decl_lambda: $ => prec.right(choice(
            $.expr,
            $.func_decl_lambda,
            $.tkInherited,
        )),
        expr: $ => choice(
            $.expr_l1,
            $.format_expr,
        ),
        expr_l1: $ => choice(
            $.expr_dq,
            $.question_expr,
            $.new_question_expr,
        ),
        expr_l1_for_question_expr: $ => choice(
            $.expr_dq,
            $.question_expr,
        ),
        expr_l1_for_new_question_expr: $ => choice(
            $.expr_dq,
            $.new_question_expr,
        ),
        expr_l1_func_decl_lambda: $ => choice(
            $.expr_l1,
            $.func_decl_lambda,
        ),
        expr_l1_for_lambda: $ => choice(
            $.expr_dq,
            $.question_expr,
            $.func_decl_lambda,
        ),
        expr_dq: $ => prec.right(choice(
            $.relop_expr,
            seq(
                $.expr_dq,
                $.tkDoubleQuestion,
                $.relop_expr,
            ),
        )),
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
                $.simple_or_template_type_reference,
                $.tkRoundClose,
            ),
            seq(
                $.tkTypeOf,
                $.tkRoundOpen,
                $.empty_template_type_reference,
                $.tkRoundClose,
            ),
        ),
        question_expr: $ => prec.right(seq(
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

        empty_template_type_reference: $ => choice(
            seq(
                $.simple_type_identifier,
                $.template_type_empty_params,
            ),
            seq(
                $.simple_type_identifier,
                $.tkAmpersend,
                $.template_type_empty_params,
            ),
        ),
        simple_or_template_type_reference: $ => prec.right(choice(
            $.simple_type_identifier,
            seq(
                $.simple_type_identifier,
                $.template_type_params,
            ),
            seq(
                $.simple_type_identifier,
                $.tkAmpersend,
                $.template_type_params,
            ),
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
        relop_expr: $ => choice(
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
        ),
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
            $.literal_or_number,
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
            $.literal_or_number,
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
            $.literal_or_number,
            seq(
                $.sign,
                $.literal_or_number,
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
                $.tkSemiColon,
                $.pattern_out_param_optional_var,
            ),
            seq(
                $.pattern_out_param_list_optional_var,
                $.tkComma,
                $.pattern_out_param_optional_var,
            ),
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
            $.literal_or_number,
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
            $.literal_or_number,
            seq(
                $.sign,
                $.literal_or_number,
            ),
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
        format_expr: $ => choice(
            seq(
                $.simple_expr,
                $.tkColon,
                optional($.simple_expr),
            ),
            seq(
                $.tkColon,
                optional($.simple_expr),
            ),
            seq(
                $.simple_expr,
                $.tkColon,
                optional($.simple_expr),
                $.tkColon,
                $.simple_expr,
            ),
            seq(
                $.tkColon,
                optional($.simple_expr),
                $.tkColon,
                $.simple_expr,
            ),
        ),
        format_const_expr: $ => choice(
            seq(
                $.const_expr,
                $.tkColon,
                optional($.const_expr),
            ),
            seq(
                $.tkColon,
                optional($.const_expr),
            ),
            seq(
                $.const_expr,
                $.tkColon,
                optional($.const_expr),
                $.tkColon,
                $.const_expr,
            ),
            seq(
                $.tkColon,
                optional($.const_expr),
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
        simple_expr: $ => prec.right(choice(
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
        ),
        typecast_op: $ => choice(
            $.tkAs,
            $.tkIs,
        ),
        as_is_expr: $ => choice(
            $.is_type_expr,
            $.as_expr,
        ),
        as_expr: $ => choice(
            seq(
                $.term,
                $.tkAs,
                $.simple_or_template_type_reference,
            ),
            seq(
                $.term,
                $.tkAs,
                $.array_type,
            ),
        ),
        is_type_expr: $ => choice(
            seq(
                $.term,
                $.tkIs,
                $.simple_or_template_type_reference,
            ),
            seq(
                $.term,
                $.tkIs,
                $.array_type,
            ),
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
        term: $ => choice(
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
        ),
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
            $.expr_l1_or_unpacked,
            $.tkComma,
            $.expr_l1_or_unpacked_list,
            optional($.lambda_type_ref),
            optional($.optional_full_lambda_fp_list),
            $.tkRoundClose,
        )),

        factor_without_unary_op: $ => choice(
            $.literal_or_number,
            $.var_reference,
        ),
        factor: $ => choice(
            $.tkNil,
            $.literal_or_number,
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
        ),
        literal_or_number: $ => choice(
            $.literal,
            $.unsigned_number,
        ),
        var_question_point: $ => prec.right(choice(
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
        var_reference: $ => choice(
            seq(
                $.var_address,
                $.variable,
            ),
            $.variable,
            $.var_question_point,
        ),
        var_address: $ => choice(
            $.tkAddressOf,
            seq(
                $.var_address,
                $.tkAddressOf,
            ),
        ),
        attribute_variable: $ => choice(
            seq(
                $.simple_type_identifier,
                optional($.optional_expr_list_with_bracket),
            ),
            seq(
                $.template_type,
                optional($.optional_expr_list_with_bracket),
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
        variable_or_literal_or_number: $ => choice(
            $.variable,
            $.literal_or_number,
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
                $.literal_or_number,
                $.tkPoint,
                $.identifier_or_keyword,
            ),
            seq(
                $.variable_or_literal_or_number,
                $.tkSquareOpen,
                $.expr_list,
                $.tkSquareClose,
            ),
            seq(
                $.variable_or_literal_or_number,
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
        elem_list: $ => $.elem_list1,
        elem_list1: $ => choice(
            $.elem,
            seq(
                $.elem_list1,
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
            $.literal_list,
            $.tkFormatStringLiteral,
        ),
        literal_list: $ => choice(
            $.one_literal,
            seq(
                $.literal_list,
                $.one_literal,
            ),
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
        identifier: $ => choice(
            $.tkIdentifier,
            $.property_specifier_directives,
            $.non_reserved,
        ),
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
        property_specifier_directives: $ => choice(
            $.tkRead,
            $.tkWrite,
        ),
        non_reserved: $ => choice(
            $.tkName,
            $.tkNew,
        ),
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
        lambda_unpacked_params: $ => seq(
            $.tkBackSlashRoundOpen,
            $.lambda_list_of_unpacked_params_or_id,
            $.tkComma,
            $.lambda_unpacked_params_or_id,
            $.tkRoundClose,
        ),

        lambda_unpacked_params_or_id: $ => choice(
            $.lambda_unpacked_params,
            $.identifier,
        ),
        lambda_list_of_unpacked_params_or_id: $ => choice(
            $.lambda_unpacked_params_or_id,
            seq(
                $.lambda_list_of_unpacked_params_or_id,
                $.tkComma,
                $.lambda_unpacked_params_or_id,
            ),
        ),
        expr_l1_or_unpacked: $ => choice(
            $.expr_l1,
            $.lambda_unpacked_params,
        ),
        expr_l1_or_unpacked_list: $ => choice(
            $.expr_l1_or_unpacked,
            seq(
                $.expr_l1_or_unpacked_list,
                $.tkComma,
                $.expr_l1_or_unpacked,
            ),
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
                $.fptype,
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
                $.fptype,
                $.tkSemiColon,
                $.full_lambda_fp_list,
                $.tkRoundClose,
                optional($.lambda_type_ref_noproctype),
                $.tkArrow,
                $.lambda_function_body,
            ),
            seq(
                $.tkRoundOpen,
                $.expr_l1_or_unpacked,
                $.tkComma,
                $.expr_l1_or_unpacked_list,
                optional($.lambda_type_ref),
                optional($.optional_full_lambda_fp_list),
                $.tkRoundClose,
                $.rem_lambda,
            ),
            seq(
                $.lambda_unpacked_params,
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
            $.fptype,
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
        tkDirectiveName: $ => /\#(\p{L}|\p{Nd})+/,
        tkIdentifier: $ => /\p{L}(\p{L}|\p{Nd})*/,
        tkStringLiteral: $ => /\'([^\'\n]|\'\')*\'/,
        tkInteger: $ => /(\p{Nd})+/,
        tkHex: $ => /(\p{Nd}|[abcdefABCDEF])+/,
        tkFloat: $ => /(\p{Nd})+\.(\p{Nd})+/,
        tkAsciiChar: $ => /#(\p{Nd})+/,
        tkFormatStringLiteral: $ => /\$\'([^\'\n]|\'\')*\'/,

        letter: $ => /\p{L}/,
        digit: $ => /\p{Nd}/,
        letterDigit: $ => /(\p{L}|\p{Nd})/,
        hexDigit: $ => /(\p{Nd}|[abcdefABCDEF])+/,

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