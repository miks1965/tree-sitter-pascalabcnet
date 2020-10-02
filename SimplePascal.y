%{
// Ёти объ€влени€ добавл€ютс€ в класс GPPGParser, представл€ющий собой парсер, генерируемый системой gppg
    public syntax_tree_node root; //  орневой узел синтаксического дерева 
    public GPPGParser(AbstractScanner<ValueType, LexLocation> scanner) : base(scanner) { }
%}

%output=SimplePascalYacc.cs 

%parsertype GPPGParser

%union  
	{ 
		public bool bVal; 
		public string sVal; 
		public int iVal;
		public double rVal;
		public char cVal; 
		public named_type_reference ntr;
		public ident_list il;
		public var_def_statement vds;
		public variable_definitions vdss;
		public expression ex;
		public expression_list el;
		public ident id;
		public block bl;
		public statement st;
		public statement_list sl;
		public declarations decl;
		public Operators op;
		public simple_const_definition scd;
		public consts_definitions_list cdl;
		public declaration decsec;
		public procedure_definition pd;
	}

%using PascalABCCompiler.SyntaxTree
%using SimplePascalParser

%namespace GPPGParserScanner

%start module

%token <sVal> ID
%token <iVal> INTNUM 
%token <rVal> REALNUM
%token <cVal> CHARACTER
%token <bVal> TRUE FALSE
%token <op> PLUS MINUS MULT DIVIDE DIV MOD AND OR LT GT LE GE EQ NE
%token NOT 
%token ASSIGN SEMICOLUMN LPAREN RPAREN COMMA DOT COLON WRITE
%token TRUE FALSE ODD BOOLEAN INTEGER REAL CHAR
%token IF THEN ELSE BEGIN END WHILE DO PROGRAM CONST VAR FOR TO STEP
%token INVISIBLE
%token PROCEDURE

%type <id> ident
%type <ntr> type
%type <ex> expr ConstExpr
%type <st> Assignment IfStatement WhileStatement Statement BlockStatement ForStatement 
%type <st> EmptyStatement ProcCallStatement
%type <sl> StatementSequence
%type <decl> Declarations
%type <el> factparams
%type <il> IDList
%type <vds> VarDecl
%type <vdss> VarDeclarations VarDeclarationsSect
%type <scd> ConstDecl
%type <cdl> ConstDeclarations ConstDeclarationsSect
%type <pd> ProcedureDeclarationSect
%type <decsec> DeclarationsSect
%type <bl> mainblock
%type <bVal> maybevar

%left LT GT LE GE EQ NE
%left PLUS MINUS OR
%left MULT DIVIDE AND DIV MOD
%left NOT
%left UMINUS

%%

module  
	: PROGRAM ident SEMICOLUMN mainblock DOT 
    {
		// ѕодключение стандартного модул€ Oberon00System, написанного на PascalABC.NET
		// var ul = new uses_list("SimplePascalSystem");
		
		// ‘ормирование модул€ основной программы (используетс€ фабричный метод вместо конструктора)
		root = program_module.create($2, null, $4, @$);
    }
    ;
	
ident 
	: ID {
		$$ = new ident($1,@$); 
	}
	;
	
mainblock
	: Declarations BEGIN StatementSequence END
	{
		$$ = new block($1, $3, @$);
	}
	;

expr 	
	: ident {
		$$ = $1;
	}
	| INTNUM { 
		$$ = new int32_const($1,@$); 		
	}
	| REALNUM { 
		$$ = new double_const($1,@$); 		
	}
	| CHARACTER { 
		$$ = new char_const($1,@$); 		
	}
	| TRUE {
		$$ = new bool_const(true,@$);
	}
	| FALSE {
		$$ = new bool_const(false,@$);
	}
	| MINUS expr %prec UMINUS {
		$$ = new un_expr($2,Operators.Minus,@$);
	}
	| LPAREN expr RPAREN {$$ = $2;}
	| NOT expr {
		$$ = new un_expr($2,Operators.LogicalNOT,@$);
	}
	| expr PLUS expr {
		$$ = new bin_expr($1,$3,Operators.Plus,@$);
	}
	| expr MINUS expr {
		$$ = new bin_expr($1,$3,Operators.Minus,@$);
	}
	| expr MULT expr {
		$$ = new bin_expr($1,$3,Operators.Multiplication,@$);
	}
	| expr DIVIDE expr {
		$$ = new bin_expr($1,$3,Operators.Division,@$);
	}
	| expr DIV expr {
		$$ = new bin_expr($1,$3,Operators.IntegerDivision,@$);
	}
	| expr MOD expr {
		$$ = new bin_expr($1,$3,Operators.ModulusRemainder,@$);
	}	
	| expr AND expr {
		$$ = new bin_expr($1,$3,Operators.LogicalAND,@$);
	}
	| expr OR expr {
		$$ = new bin_expr($1,$3,Operators.LogicalOR,@$);
	}
	| expr EQ expr {
		$$ = new bin_expr($1,$3,Operators.Equal,@$);
	}
	| expr NE expr {
		$$ = new bin_expr($1,$3,Operators.NotEqual,@$);
	}
	| expr LT expr {
		$$ = new bin_expr($1,$3,Operators.Less,@$);
	}
	| expr LE expr {
		$$ = new bin_expr($1,$3,Operators.LessEqual,@$);
	}
	| expr GT expr {
		$$ = new bin_expr($1,$3,Operators.Greater,@$);
	}
	| expr GE expr {
		$$ = new bin_expr($1,$3,Operators.GreaterEqual,@$);
	}
	;

Assignment 
	: ident ASSIGN expr {
		$$ = new assign($1, $3, Operators.Assignment,@$);
	}
	;

IfStatement 
	: IF expr THEN Statement {
		$$ = new if_node($2, $4, null, @$);
	}
	| IF expr THEN Statement ELSE Statement {
		$$ = new if_node($2, $4, $6, @$);
	}
	;

WhileStatement 
	: WHILE expr DO Statement {
		$$ = new while_node($2, $4, WhileCycleType.While, @$);
	}
	;

ForStatement
	: FOR ident ASSIGN expr TO expr STEP expr DO Statement
	{
		statement st0 = new assign($2, $4, Operators.Assignment);
		expression ex2 = new bin_expr($2, $8, Operators.Plus);
		statement s = new assign($2, ex2, Operators.Assignment);
		expression ex1 = new bin_expr($2, $6, Operators.Less);
		statement_list sl = new statement_list($10,@$);
		sl.Add(s);
		$$ = new while_node(ex1, sl, WhileCycleType.While, @$);
		statement_list sl1 = new statement_list(st0,@$);
		sl1.Add($$);
		$$ = sl1;
	}
	;

factparams
	: expr {
		$$ = new expression_list($1,@$);
	}
	| factparams COMMA expr {
		$1.Add($3,@$);
		$$ = $1;
	}
	;
	
ProcCallStatement
	: ident LPAREN factparams RPAREN {
		$$ = new method_call($1,$3,@$);
	}
	;
	
EmptyStatement
	: {
		$$ = new empty_statement();		
	}
	;
	
Statement 
	: Assignment
	| IfStatement
	| WhileStatement
	| ProcCallStatement
	| EmptyStatement
	| BlockStatement
	| ForStatement
	;

BlockStatement
	: BEGIN StatementSequence END {$$ = $2;}
	;

StatementSequence 
	: Statement {
		$$ = new statement_list($1,@$);
	}
	| StatementSequence SEMICOLUMN Statement {
		$1.Add($3,@$);
		$$ = $1;
	}
	;

type 	
	: BOOLEAN {
		$$ = new named_type_reference("boolean",@$);
	}
	| INTEGER {
		$$ = new named_type_reference("integer",@$);
	}
	| REAL {
		$$ = new named_type_reference("real",@$);
	}
	| CHAR {
		$$ = new named_type_reference("char",@$);
	}
	;

IDList 
	: ident {
		$$=new ident_list($1,@$);
	}
	| IDList COMMA ident {
		$1.Add($3,@$);
		$$ = $1;
	}
	;

VarDecl 
	: IDList COLON type SEMICOLUMN {
	  $$  = new var_def_statement($1,$3,null,definition_attribute.None,false,@$);
	}
	;

VarDeclarations 
	: VarDecl {
		$$ = new variable_definitions($1,@$);
	}
	| VarDeclarations VarDecl {
		$1.Add($2,@$);
		$$ = $1;
	}
	;

	
ConstDecl 
	: ident EQ ConstExpr SEMICOLUMN {
		$$ = new simple_const_definition($1,$3,@$);
	}
	;

ConstExpr 
	: expr 
	;
	
ConstDeclarations 
	: ConstDecl {
		$$ = new consts_definitions_list($1,@$);
	}
	| ConstDeclarations ConstDecl {
		$1.Add($2,@$); 
		$$ = $1;
	}
	;
	
ConstDeclarationsSect 
	: CONST ConstDeclarations {
		$$ = $2;
		$$.source_context = @$;
	}
	;

VarDeclarationsSect 
	: VAR VarDeclarations {
		$$ = $2;
		$$.source_context = @$;
	}
	;

DeclarationsSect
	: VarDeclarationsSect {
		$$ = $1;
	}
	| ConstDeclarationsSect	{
		$$ = $1;
	}	
	| ProcedureDeclarationSect {
		$$ = $1;
	}	
	;
	
Declarations 
	: {
	  $$ = new declarations();
	}
	| Declarations DeclarationsSect {
		if ($2 != null)
			$1.Add($2);
		$$ = $1;
		$$.source_context = @$;
	}
	;
	
ProcedureDeclarationSect
	: PROCEDURE ident maybeformalparams maybereturn SEMICOLUMN mainblock ident SEMICOLUMN {
	
	}
	;
	
maybeformalparams
	: {
		//$$ = null;
	}
	| LPAREN FPList RPAREN {
		//$$ = $2;
	}
	;
	
maybereturn
	: {
		
	}
	| COMMA type {
	
	}
	;
	
FPList
	: FPSect {
	
	}
	| FPList SEMICOLUMN FPSect {
	
	}
	;
	
FPSect
	: maybevar IDList COLON type {
	
	}
	;
	
maybevar
	: {
		$$ = false;
	}
	| VAR {
		$$ = true;
	}
	;
%%
