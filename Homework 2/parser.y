%{
//Justin Harris 
//CS445
//Last Updated: 1-29-22
//parser.y
//This file contains Bison Code

#include <stdio.h>
#include <string.h>
#include "syntaxTree.h"
#include "scanType.h" //TokenData type 



double vars[26];

extern int yylex();
extern FILE *yyin;
extern int line;    //ERR line number from scanner
extern int numErrors;  // ERR err count
static TreeNode *ast;

#define YYERROR_VERBOSE
void yyerror(const char *msg)
{
    printf("ERROR(%d): %s\n", line, msg);
    numErrors++;
}

%}

//This is included in the tab.h file
//so scanType.h must be included before the tab.h file

%union {
    ExpType type;               //For passing types (i.e pass a type in a decl like int or bool)
    TokenData *tokenData;       //For terminals. Token data comes from yylex() in the $ vars
    TreeNode *tree;             //For nonterminals. Add these nodes as you build the tree. 
}

%token <tokenData> ID NUMCONST CHARCONST STRINGCONST BOOLCONST SPEC KEYWORD
%token <tokenData> INC DEC NEQ LEQ GEQ ASGN ADDASGN MINUSASGN MULTASGN DIVASGN
%token <tokenData> PLUS MINUS DIVIDE MULT EQUALS PERCENT
%token <tokenData> COLON SEMICOLON COMMA QMARK 
%token <tokenData> IF THEN ELSE FOR BREAK RETURN BEGIN END WHILE TO DO BY NOT
%token <tokenData> STATIC BOOL CHAR INT 

%type <tree>    declList decl varDecl scopedVarDecl varDeclList varDeclInit varDeclId
%type <tree>    typeSpec funDecl parms parmList parmTypeList parmIdList parmId
%type <tree>    stmt expStmt compoundStmt localDecls stmtList selectStmt iterStmt
%type <tree>    iterRange breakStmt exp assignop simpleExp andExp unaryRelExp
%type <tree>    relExp relop sumExp sumop mulExp mulop unaryExp unaryop
%type <tree>    factor mutable immutable call args argList constant

%%

program             :       declList                                            { ast = $1}

declList            :       declList decl                                       { $$ = addaSibling($1, $2); }
                    |       decl                                                { $$ = $1; }
                    ;

decl                :       varDecl                                             { $$ = 1; }       
                    |       funDecl                                             { $$ = 1; }
                    ;

varDecl             :       typeSpec varDeclList SEMICOLON                      { $$ = $2; isaSiblingType($$, $1); }
                    ;

scopedVarDecl       :       STATIC typeSpec varDeclList SEMICOLON               { $$ = $3; $$->isStatic = true; isaSiblingType($$, $1);}
                    |       typeSpec varDeclList SEMICOLON                      { $$ = 2; isaSiblingType($$, $1); }
                    ;

varDeclList         :       varDeclList COMMA varDeclInit                       { $$ = addaSibling($1, $3);}
                    |       varDeclInit                                         { $$ = $1; }
                    ;

varDeclInit         :       varDeclId                                           { $$ = $1; }
                    |       varDeclId COLON simpleExp                           { $$ = 1; $$->child[0] = $3; }
                    ;
                
varDeclId           :       ID                                                  { $$ = newDeclNode(VarK, $1); $$->attr.name = $1->tokenStrInput; } 
                    |       ID LBRACKET NUMCONST RBRACKET                       { $$ = newDeclNode(VarK, $1); 
                                                                                  $$->attr.name = $1->tokenStrInput;
                                                                                  $$->isArray = true;
                                                                                  $$->thisTokenData = $1; $$->expType = UndefinedType; }
                    ;

typeSpec            :       BOOL                                                { $$ = Boolean; }
                    |       CHAR                                                { $$ = Char; }
                    |       INT                                                 { $$ = Integer; }
                    ;

funDecl             :       typeSpec ID LPAREN parms RPAREN compoundStmt        { $$ = newDeclNode(FuncK, $2);
                                                                                  $$->attr.name = strdup($2->tokenStrInput);
                                                                                  $$->expType = $1;
                                                                                  $$->thisTokenData = $2;
                                                                                  $$->child[0] = $4;
                                                                                  $$->child[1] = $6; }

                    |       ID LPAREN parms RPAREN compoundStmt                 { $$ = newDeclNode(FuncK, $1);
                                                                                  $$->attr.name = strdup($1->tokenStrInput);
                                                                                  //$$->expType = $1;
                                                                                  $$->thisTokenData = $1;
                                                                                  $$->child[0] = $3;
                                                                                  $$->child[1] = $5; }  
                    ;

parms               :       parmList                                            { $$ = $1 ; }
                    |       %empty                                              { $$ = NULL ; } //epsilon
                    ;

parmList            :       parmList SEMICOLON parmTypeList                     { $$ = addaSibling($1, $3);}  //declaring multiple arguments in a function decl
                    |       parmTypeList                                        { $$ = $ 1; }
                    ;

parmTypeList        :       typeSpec parmIdList                                 { $$ = 2; isaSiblingType($$, $1); }
                    ;

parmIdList          :       parmIdList COMMA parmId                             { $$ = addaSibling($1, $3); }
                    |       parmId                                              { $$ = 1; }
                    ;

parmId              :       ID                                                  { $$ = newDeclNode(ParamK, $1);
                                                                                  $$->attr.name = strdup($1->tokenStrInput); }

                    |       ID LBRACKET RBRACKET                                { $$ = newDeclNode(ParamK, $1); 
                                                                                  $$->attr.name = strdup($1->tokenStrInput); 
                                                                                  isArray = true;}
                    ;

stmt                :       expStmt                                             { $$ = 1; }                                    
                    |       compoundStmt                                        { $$ = 1; }
                    |       selectStmt                                          { $$ = 1; }
                    |       iterStmt                                            { $$ = 1; }
                    |       returnStmt                                          { $$ = 1; }
                    |       breakStmt                                           { $$ = 1; }
                    ;

expStmt             :       exp SEMICOLON                                       { $$ = 1; }
                    |       SEMICOLON                                           { $$ = NULL; }
                    ;

compoundStmt        :       BEGIN localDecls stmtList END                       { $$ newStmtNode(CompoundK, $1);
                                                                                  $$->child[0] = $2;
                                                                                  $$->child[1] = $3;}
                    ;

localDecls          :       localDecls scopedVarDecl
                    |       %empty                                              { $$ = NULL; }
                    ;

stmtList            :       stmtList stmt
                    |       %empty                                              { $$ = NULL; }
                    ;

selectStmt          :       IF simpleExp THEN stmt 
                    |       IF simpleExp THEN stmt ELSE stmt
                    ;

iterStmt            :       WHILE simpleExp DO stmt
                    |       FOR ID ASGN iterRange DO stmt
                    ;

iterRange           :       simpleExp TO simpleExp
                    |       simpleExp TO simpleExp BY simpleExp
                    ;

returnStmt          :       RETURN SEMICOLON 
                    |       RETURN exp SEMICOLON
                    ;

breakStmt           :       BREAK
                    ;

exp                 :       mutable assignop exp 
                    |       mutable INC
                    |       mutable DEC
                    |       simpleExp
                    ;

assignop            :       ASGN
                    |       ADDASGN
                    |       MINUSASGN
                    |       MULTASGN
                    |       DIVASGN
                    ;

simpleExp           :       simpleExp OR andExp
                    |       andExp
                    ;

andExp              :       andExp AND unaryRelExp
                    |       relExp
                    ;

unaryRelExp         :       NOT unaryRelExp
                    |       relExp
                    ;

relExp              :       sumExp relop sumExp
                    |       sumExp
                    ;

relop               :       LESSTHAN
                    |       LEQ
                    |       GREATERTHAN
                    |       GEQ
                    |       EQUALS
                    |       NEQ
                    ;

sumExp              :       sumExp sumop mulExp
                    |       mulExp
                    ;

sumop               :       PLUS
                    |       MINUS
                    ;

mulExp              :       mulExp mulop unaryExp
                    |       unaryExp
                    ;

mulop               :       MULT
                    |       DIVIDE
                    |       PERCENT
                    ;

unaryExp            :       unaryop unaryExp
                    |       unaryExp
                    ;

unaryop             :       MINUS
                    |       MULT
                    |       QMARK
                    ;

factor              :       mutable
                    |       immutable
                    ;

mutable             :       ID
                    |       ID LBRACKET exp RBRACKET
                    ;

immutable           :       LPAREN exp RPAREN
                    |       call
                    |       constant
                    ;

call                :       ID LPAREN args RPAREN
                    ;

args                :       argList 
                    |       %empty
                    ;

argList             :       argList COMMA exp 
                    |       exp
                    ;

constant            :       NUMCONST
                    |       CHARCONST
                    |       STRINGCONST
                    |       BOOLCONST
                    ;

%%

extern int yydebug;
int main(int argc, char *argv[])
{
    if(argc >1){
        if((yyin = fopen(argv[1], "r"))) {
            // file open successful
        }
        else {
            //failed to open
            printf("ERROR: failed to open \'%s\'\n", argv[1]);
            exit(1);
        }
    }

    //init variables a through z
    for (int i=0; i<26; i++) vars[i] = 0.0;

    //do the parsing
    numErrors = 0;
    yyparse();

    //printf("Number of errors: %d\n", numErrors);

    return 0;
}