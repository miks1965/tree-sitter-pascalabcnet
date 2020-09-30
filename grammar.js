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
        source_file: $ => repeat(choice(
            $._statement,
            $._expression,
        )),
        // source_file: $ => module,

        // word: $ => $.identifier,

        // module: $ => seq(
        //     'Program',
        //     $.identifier,
        //     $.semicolon,
        //     $.mainblock,
        //     $.dot
        // ),

        // mainblock: $ => seq(
        //     $.declarations,
        //     $.begin,
        //     seq($._statement),
        //     $.end
        // ),

        // _top_level_declaration: $ => choice(

        // ),

        // declarations: $ => choice(

        // ),

        // _definition: $ => choice(

        // ),

        _type: $ => choice(
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
        dot: $ => '.',

        true: $ => 'true',
        false: $ => 'false',
        begin: $ => 'begin',
        end: $ => 'end'
    }
});
