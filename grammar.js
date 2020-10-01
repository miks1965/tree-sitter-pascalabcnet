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
            seq($._statement),
            $.end
        ),

        declarations: $ => choice(
            $.var_declarations,
        ),

        var_declarations: $ => seq(
            'var',
            repeat(seq(
                $.identifier,
                $.colon,
                $.type,
                $.semicolon)
            )
        ),

        type: $ => choice(
            'boolean',
            'integer',
            'real',
            'char'
        ),

        _statement: $ => choice(
            $.assignment,
            // $.if,
        ),

        assignment: $ => seq(
            $.identifier,
            choice(...assignment_operators),
            $._expression,
        ),

        _expression: $ => choice(
            $.identifier,
            $._number,
            $.char,
            $.true,
            $.false,
            $.unary_expression,
            $.binary_expression,
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

        true: $ => 'true',
        false: $ => 'false',
        begin: $ => 'begin',
        end: $ => 'end'
    }
});
