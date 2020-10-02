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
        module: $ => seq(
            'Program',
            $.identifier,
            $.semicolon,
            $.mainblock,
            $.dot
        ),

        mainblock: $ => seq(
            $.declarations,
            $.begin,
            $.statement_sequence,
            $.end
        ),

        declarations: $ => choice(
            '',
            seq($.declarations,
                $.declarations_sequence)
        ),

        declarations_sequence: $ => choice(
            $.var_declarations,
            $.const_declarations,
            $.procedure_declatarions,
        ),

        var_declarations: $ => seq(
            $.var,
            choice(
                $.var_declaration,
                seq($.var_declarations,
                    $.var_declaration)
            )
        ),

        var_declaration: $ => seq(
            $.identifier,
            $.colon,
            $.type,
            $.semicolon
        ),

        const_declarations: $ => seq(
            'const',
            choice(
                $.const_declaration,
                seq($.const_declarations,
                    $.const_declaration)
            )
        ),

        const_declaration: $ => seq(
            $.identifier,
            '=',
            $.const_expression,
            $.semicolon
        ),

        const_expression: $ => $._expression,

        procedure_declatarions: $ => seq(
            'procedure',
            $.identifier,
            $.formal_params,
            choice('', $.return),
            $.semicolon,
            $.mainblock,
            $.identifier,
            $.semicolon
        ),

        formal_params: $ => choice(
            seq($.left_paren,
                $.right_paren),
            seq($.left_paren,
                $.formal_params_list,
                $.right_paren)
        ),

        return: $ => seq($.comma, $.type),

        formal_params_list: $ => choice(
            $.formal_params_sequence,
            seq($.formal_params_list,
                $.semicolon,
                $.formal_params_sequence)
        ),

        formal_params_sequence: $ => seq(
            choice('', $.var),
            $.identifier_list,
            $.colon,
            $.type
        ),

        type: $ => choice(
            'boolean',
            'integer',
            'real',
            'char'
        ),

        statement_sequence: $ => choice(
            $._statement,
            seq($.statement_sequence,
                $.semicolon,
                $._statement),
        ),

        _statement: $ => choice(
            $.assignment,
            $.if_statement,
            $.while_statement,
            $.for_statement,
            $.block_statement,
            // $.empty_statement,
            $.procedure_call_statement,
        ),

        assignment: $ => seq(
            $.identifier,
            choice(...assignment_operators),
            $._expression,
        ),

        if_statement: $ => prec.right(seq(
            'if',
            $._expression,
            'then',
            $._statement,
            optional(seq(
                'else',
                $._statement)))
        ),

        while_statement: $ => seq(
            'while',
            $._expression,
            'do',
            $._statement
        ),

        for_statement: $ => seq(
            'for',
            $.identifier,
            ':=',
            $._expression,
            'to',
            $._expression,
            'step',
            $._expression,
            'do',
            $._statement
        ),

        empty_statement: $ => '',

        block_statement: $ => seq(
            $.begin,
            $.statement_sequence,
            $.end
        ),

        procedure_call_statement: $ => seq(
            $.identifier,
            $.left_paren,
            $.fact_params,
            $.right_paren
        ),

        identifier_list: $ => choice(
            $.identifier,
            seq($.identifier_list,
                $.comma,
                $.identifier
            )
        ),

        fact_params: $ => choice(
            $._expression,
            seq($._expression,
                $.comma,
                $.fact_params)
        ),

        _expression: $ => choice(
            $.identifier,
            $._number,
            $.char,
            $.true,
            $.false,
            seq($.left_paren, $._expression, $.right_paren),
            $.unary_expression,
            $.binary_expression,
            // $.const_expression
        ),

        unary_expression: $ => prec(PREC.unary, seq(
            choice('+', '-', '!', '^', '*', '&', '<-'),
            $._expression
        )),

        binary_expression: $ => {
            const table = [
                [PREC.multiplicative, choice(...multiplicative_operators)],
                [PREC.additive, choice(...additive_operators)],
                [PREC.comparative, choice(...comparative_operators)],
                [PREC.and, 'and'],
                [PREC.or, 'or'],
            ];

            return choice(...table.map(([precedence, operator]) =>
                prec.left(precedence, seq(
                    $._expression,
                    operator,
                    $._expression
                ))
            ));
        },

        // const_expression: $ => $._expression,

        _number: $ => choice(
            $.integer,
            $.real,
        ),

        identifier: $ => /[a-zA-Z_]+/,
        integer: $ => /\d+/,
        real: $ => /\d+,d+/,
        char: $ => /[^'\n]/,
        semicolon: $ => ';',
        colon: $ => ':',
        dot: $ => '.',
        comma: $ => ',',
        left_paren: $ => '(',
        right_paren: $ => ')',

        true: $ => 'true',
        false: $ => 'false',
        begin: $ => 'begin',
        end: $ => 'end',
        var: $ => 'var',
    }
});
