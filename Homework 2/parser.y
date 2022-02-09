%{
//Justin Harris 
//CS445
//Last Updated: 1-29-22
//parser.y
//This file contains Bison Code

#include "scanType.h" //TokenData type 
#include <stdio.h>
#include "syntaxTree.h"

double vars[26];

extern int yylex();
extern FILE *yyin;
extern int line;    //ERR line number from scanner
extern int numErrors;  // ERR err count

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

program             :       declList                                         //Add rules and operations over here
                    ;

declList            :       declList decl
                    |       decl
                    ;

decl                :       varDecl
                    |       funDecl
                    ;

varDecl             :       typeSpec varDeclList SEMICOLON
                    ;

scopedVarDecl       :       STATIC typSpec varDeclList SEMICOLON
                    |       typeSpec varDeclList SEMICOLON
                    ;

varDeclList         :       varDeclList COMMA varDeclInit
                    |       varDeclInit
                    ;

varDeclInit         :       varDeclId
                    |       varDeclId COLON simpleExp
                    ;
                
varDeclId           :       ID 
                    |       ID LBRACKET NUMCONST RBRACKET
                    ;

typeSpec            :       BOOL
                    |       CHAR
                    |       INT
                    ;

funDecl             :       typeSpec ID LPAREN parms RPAREN compoundStmt
                    |       ID LPAREN parms RPAREN compoundStmt
                    ;

parms               :       parmList
                    |       %empty
                    ;

parmList            :       parmList SEMICOLON parmTypeList
                    |       parmTypeList
                    ;

parmTypeList        :       typeSpec parmIdList
                    ;

parmIdList          :       parmIdList COMMA parmId
                    |       parmId
                    ;

parmId              :       ID
                    |       ID LBRACKET RBRACKET
                    ;

stmt                :       expStmt
                    |       compoundStmt
                    |       selectStmt
                    |       iterStmt
                    |       returnStmt
                    |       breakStmt
                    ;

expStmt             :       exp SEMICOLON
                    |       SEMICOLON
                    ;

compoundStmt        :       BEGIN localDecls stmtList END
                    ;

localDecls          :       localDecls scopedVarDecl
                    |       %empty
                    ;

stmtList            :       stmtList stmt
                    |       %empty
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

unaryRelExp         :       NOT unaryRelExp
                    |       unaryRelExp
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