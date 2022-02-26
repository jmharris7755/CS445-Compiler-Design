%{
//Justin Harris 
//CS445
//Last Updated: 2-11-22
//parser.y
//This file contains Bison Code
#include "scanType.h" //TokenData type 
#include "syntaxTree.h"
#include "semantic.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <getopt.h>


extern int yylex();
extern FILE *yyin;
extern int line;    //ERR line number from scanner
extern int numErrors;  // ERR err count
int numWarnings; //warning count
static TreeNode *ast;
bool TYPES = false;

extern SymbolTable symbolTable;

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
%token <tokenData> IF THEN ELSE FOR BREAK RETURN START STOP WHILE TO DO BY NOT
%token <tokenData> STATIC BOOL CHAR INT 
%token <tokenData> LBRACKET RBRACKET LPAREN RPAREN OR AND LESSTHAN GREATERTHAN

%type <type>    typeSpec

%type <tree>    declList decl varDecl scopedVarDecl varDeclList varDeclInit varDeclId
%type <tree>    funDecl parms parmList parmTypeList parmIdList parmId
%type <tree>    stmt expStmt compoundStmt localDecls stmtList returnStmt endStmt
%type <tree>    iterRange breakStmt exp assignop simpleExp andExp unaryRelExp
%type <tree>    relExp relop sumExp sumop mulExp mulop unaryExp unaryop
%type <tree>    factor mutable immutable call args argList constant matchedif unmatchedif

%%

program             :       declList                                            { ast = $1 ;}
                    ;

declList            :       declList decl                                       { $$ = addaSibling($1, $2); }
                    |       decl                                                { $$ = $1; }
                    ;

decl                :       varDecl                                             { $$ = $1; }       
                    |       funDecl                                             { $$ = $1; }
                    ;

varDecl             :       typeSpec varDeclList SEMICOLON                      { $$ = $2; 
                                                                                  convertSiblingType($$, $1); }
                    ;

scopedVarDecl       :       STATIC typeSpec varDeclList SEMICOLON               { $$ = $3; $$->isStatic = true; 
                                                                                  convertSiblingType($$, $2);}

                    |       typeSpec varDeclList SEMICOLON                      { $$ = $2; 
                                                                                  convertSiblingType($$, $1); }
                    ;

varDeclList         :       varDeclList COMMA varDeclInit                       { $$ = addaSibling($1, $3);}
                    |       varDeclInit                                         { $$ = $1; }
                    ;

varDeclInit         :       varDeclId                                           { $$ = $1; }
                    |       varDeclId COLON simpleExp                           { $$ = $1; $$->child[0] = $3; }
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
                                                                                  //$$->thisTokenData = $2;
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
                    |       parmTypeList                                        { $$ = $1 ; }
                    ;

parmTypeList        :       typeSpec parmIdList                                 { $$ = $2; convertSiblingType($$, $1); }
                    ;

parmIdList          :       parmIdList COMMA parmId                             { $$ = addaSibling($1, $3); }
                    |       parmId                                              { $$ = $1; }
                    ;

parmId                                                                                                :       ID                                                  { $$ = newDeclNode(ParamK, $1);
$$->attr.name = strdup($1->tokenStrInput); }

                    |       ID LBRACKET RBRACKET                                { $$ = newDeclNode(ParamK, $1); 
                                                                                  $$->attr.name = strdup($1->tokenStrInput); 
                                                                                  $$->isArray = true;}
                    ;

stmt                :       matchedif                                           { $$ = $1; }                                    
                    |       unmatchedif                                         { $$ = $1; }
                    ;

expStmt             :       exp SEMICOLON                                       { $$ = $1; }
                    |       SEMICOLON                                           { $$ = NULL; }
                    ;

compoundStmt        :       START localDecls stmtList STOP                      { $$ = newStmtNode(CompoundK, $1);
                                                                                  $$->child[0] = $2;
                                                                                  $$->child[1] = $3; }
                    ;

localDecls          :       localDecls scopedVarDecl                            { $$ = addaSibling($1, $2); }
                    |       %empty                                              { $$ = NULL; }
                    ;

stmtList            :       stmtList stmt                                       { $$ = addaSibling($1, $2); }
                    |       %empty                                              { $$ = NULL; }
                    ;

//trying to fix dangling else?
matchedif           :       endStmt                                             { $$ = $1; }
                    |       IF simpleExp THEN matchedif ELSE matchedif          { $$ = newStmtNode(IfK, $1);
                                                                                  $$->child[0] = $2;
                                                                                  $$->child[1] = $4;
                                                                                  $$->child[2] = $6;}

                    |       WHILE simpleExp DO matchedif                        { $$ = newStmtNode(WhileK, $1);
                                                                                  $$->attr.name = $1->tokenStrInput;
                                                                                  $$->child[0] = $2;
                                                                                  $$->child[1] = $4;}

                    |       FOR ID ASGN iterRange DO matchedif                  { $$ = newStmtNode(ForK, $1);
                                                                                  $$->child[0] = newDeclNode(VarK, $2);
                                                                                  $$->child[0]->expType = Integer;
                                                                                  $$->attr.name = $3->tokenStrInput;
                                                                                  $$->child[1] = $4;
                                                                                  $$->child[2] = $6;}
                    ;

unmatchedif         :       IF simpleExp THEN matchedif ELSE unmatchedif        { $$ = newStmtNode(IfK, $1);
                                                                                  $$->child[0] = $2;
                                                                                  $$->child[1] = $4;
                                                                                  $$->child[2] = $6;}

                    |       WHILE simpleExp DO unmatchedif                      { $$ = newStmtNode(WhileK, $1);
                                                                                  $$->attr.name = $1->tokenStrInput;
                                                                                  $$->child[0] = $2;
                                                                                  $$->child[1] = $4;}

                    |       FOR ID ASGN iterRange DO unmatchedif                { $$ = newStmtNode(ForK, $1);
                                                                                  $$->child[0] = newDeclNode(VarK, $2);
                                                                                  $$->child[0]->expType = Integer;
                                                                                  $$->attr.name = $3->tokenStrInput;
                                                                                  $$->child[1] = $4;
                                                                                  $$->child[2] = $6;}

                    |       IF simpleExp THEN stmt                              { $$ = newStmtNode(IfK, $1);
                                                                                  $$->child[0] = $2;
                                                                                  $$->child[1] = $4;}
                    ;

endStmt             :       expStmt                                             { $$ = $1; }
                    |       compoundStmt                                        { $$ = $1; }
                    |       returnStmt                                          { $$ = $1; }
                    |       breakStmt                                           { $$ = $1; }
                    ;

iterRange           :       simpleExp TO simpleExp                              { $$ = newStmtNode(RangeK, $2);
                                                                                  $$->child[0] = $1;
                                                                                  $$->child[1] = $3;}

                    |       simpleExp TO simpleExp BY simpleExp                 { $$ = newStmtNode(RangeK, $2);
                                                                                  $$->child[0] = $1;
                                                                                  $$->child[1] = $3;
                                                                                  $$->child[2] = $5;}
                    ;

returnStmt          :       RETURN SEMICOLON                                    { $$ = newStmtNode(ReturnK, $1);
                                                                                  $$->attr.name = $1->tokenStrInput;}

                    |       RETURN exp SEMICOLON                                { $$ = newStmtNode(ReturnK, $1); 
                                                                                  $$->attr.name = $1->tokenStrInput; 
                                                                                  $$->expType = $2->expType;
                                                                                  $$->child[0] = $2;}
                    ;

breakStmt           :       BREAK SEMICOLON                                     { $$ = newStmtNode(BreakK, $1);
                                                                                  $$->attr.name = $1->tokenStrInput; }
                    ;

exp                 :       mutable assignop exp                                { $$ = $2;
                                                                                  $$->child[0] = $1;
                                                                                  $$->child[1] = $3;}

                    |       mutable INC                                         { $$ = newExpNode(AssignK, $2);
                                                                                  $$->attr.name = $2->tokenStrInput;
                                                                                  $$->expType = Integer;
                                                                                  $$->child[0] = $1; }

                    |       mutable DEC                                         { $$ = newExpNode(AssignK, $2);
                                                                                  $$->attr.name = $2->tokenStrInput;
                                                                                  $$->expType = Integer;
                                                                                  $$->child[0] = $1; }

                    |       simpleExp                                           { $$ = $1; }
                    ;

assignop            :       ASGN                                                { $$ = newExpNode(AssignK, $1); $$->attr.name = $1->tokenStrInput;}
                    |       ADDASGN                                             { $$ = newExpNode(AssignK, $1); $$->attr.name = $1->tokenStrInput;}
                    |       MINUSASGN                                           { $$ = newExpNode(AssignK, $1); $$->attr.name = $1->tokenStrInput;}
                    |       MULTASGN                                            { $$ = newExpNode(AssignK, $1); $$->attr.name = $1->tokenStrInput;}
                    |       DIVASGN                                             { $$ = newExpNode(AssignK, $1); $$->attr.name = $1->tokenStrInput;}
                    ;

simpleExp           :       simpleExp OR andExp                                 { $$ = newExpNode(OpK, $2);
                                                                                  $$->attr.name = $2->tokenStrInput;
                                                                                  $$->expType = Boolean;
                                                                                  $$->child[0] = $1;
                                                                                  $$->child[1] = $3;}

                    |       andExp                                              { $$ = $1; }
                    ;

andExp              :       andExp AND unaryRelExp                              { $$ = newExpNode(OpK, $2);
                                                                                  $$->attr.name = $2->tokenStrInput;
                                                                                  $$->expType = Boolean;
                                                                                  $$->child[0] = $1;
                                                                                  $$->child[1] = $3;}

                    |       unaryRelExp                                         { $$ = $1; }
                    ;

unaryRelExp         :       NOT unaryRelExp                                     { $$ = newExpNode(OpK, $1);
                                                                                  $$->attr.name = $1->tokenStrInput;
                                                                                  $$->expType = Boolean;
                                                                                  $$->child[0] = $2;}

                    |       relExp                                              { $$ = $1; }
                    ;

relExp              :       sumExp relop sumExp                                 { $$  = $2;
                                                                                  $$->child[0] = $1;
                                                                                  $$->child[1] = $3; }

                    |       sumExp                                              { $$ = $1 ;}
                    ;

relop               :       LESSTHAN                                            { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenStrInput;
                                                                                  $$->expType = Boolean;}

                    |       LEQ                                                 { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenStrInput;
                                                                                  $$->expType = Boolean;}

                    |       GREATERTHAN                                         { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenStrInput;
                                                                                  $$->expType = Boolean;}

                    |       GEQ                                                 { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenStrInput;
                                                                                  $$->expType = Boolean;}

                    |       EQUALS                                              { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenStrInput;
                                                                                  $$->expType = Boolean;}

                    |       NEQ                                                 { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenStrInput;
                                                                                  $$->expType = Boolean;}
                    ;

sumExp              :       sumExp sumop mulExp                                 { $$  = $2;
                                                                                  $$->child[0] = $1;
                                                                                  $$->child[1] = $3; }

                    |       mulExp                                              { $$ = $1; }
                    ;

sumop               :       PLUS                                                { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenStrInput;
                                                                                  $$->expType = Integer;}

                    |       MINUS                                               { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenStrInput;
                                                                                  $$->expType = Integer;}
                    ;

mulExp              :       mulExp mulop unaryExp                               { $$  = $2;
                                                                                  $$->child[0] = $1;
                                                                                  $$->child[1] = $3; }

                    |       unaryExp                                            { $$ = $1; }
                    ;

mulop               :       MULT                                                { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenStrInput;
                                                                                  $$->expType = Integer;}

                    |       DIVIDE                                              { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenStrInput;
                                                                                  $$->expType = Integer;}

                    |       PERCENT                                             { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenStrInput;
                                                                                  $$->expType = Integer;}
                    ;

unaryExp            :       unaryop unaryExp                                    { $$  = $1;
                                                                                  $$->child[0] = $2; }

                    |       factor                                            { $$ = $1; }
                    ;

unaryop             :       MINUS                                               { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenStrInput;
                                                                                  $$->expType = Integer;}

                    |       MULT                                                { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenStrInput;
                                                                                  $$->expType = Integer;}

                    |       QMARK                                               { $$ = newExpNode(OpK, $1) ;
                                                                                  $$->attr.name = $1->tokenStrInput;
                                                                                  $$->expType = Integer;}
                    ;

factor              :       mutable                                             { $$ = $1; }
                    |       immutable                                           { $$ = $1; }
                    ;

mutable             :       ID                                                  { $$ = newExpNode(IdK, $1);
                                                                                  $$->attr.name = strdup($1->tokenStrInput); }

                    |       ID LBRACKET exp RBRACKET                            { $$ = newExpNode(OpK, $2); 
                                                                                  $$->attr.name = $2->tokenStrInput;
                                                                                  $$->child[0] = newExpNode(IdK, $1);
                                                                                  $$->child[0]->attr.name = $1->tokenStrInput;
                                                                                  $$->child[0]->isArray = true;
                                                                                  $$->child[1] = $3; }
                    ;

immutable           :       LPAREN exp RPAREN                                   { $$ = $2; }
                    |       call                                                { $$ = $1; }
                    |       constant                                            { $$ = $1; }
                    ;

call                :       ID LPAREN args RPAREN                               { $$ = newExpNode(CallK, $1);
                                                                                  $$->attr.name = strdup($1->tokenStrInput);
                                                                                  $$->child[0] = $3;}
                    ;

args                :       argList                                             { $$ = $1; }
                    |       %empty                                              { $$ = NULL; }
                    ;

argList             :       argList COMMA exp                                   {$$ = addaSibling($1, $3); }
                    |       exp                                                 { $$ = $1; }
                    ;

constant            :       NUMCONST                                            { $$ = newExpNode(ConstantK, $1);
                                                                                  $$->attr.value = $1->nvalue;
                                                                                  $$->expType = Integer; }

                    |       CHARCONST                                           { $$ = newExpNode(ConstantK, $1);
                                                                                  $$->attr.name = $1->tokenStrInput;
                                                                                  $$->thisTokenData = $1;
                                                                                  $$->expType = Char; }

                    |       STRINGCONST                                         { $$ = newExpNode(ConstantK, $1);
                                                                                  $$->attr.string = strdup($1->svalue);
                                                                                  $$->isArray = true;
                                                                                  $$->expType = CharInt; }

                    |       BOOLCONST                                           { $$ = newExpNode(ConstantK, $1);
                                                                                  $$->attr.value = $1->nvalue;
                                                                                  $$->attr.name = $1->tokenStrInput;
                                                                                  $$->expType = Boolean; }
                    ;

%%

extern int yydebug;
int main(int argc, char *argv[])
{

    int selOption = 0;
    bool printAST = 0;
    numErrors = 0;
    numWarnings = 0;

    while((selOption = getopt(argc, argv, "dDpPh")) != -1){

        switch(selOption){

            case'c':
                //do nothing
                break;

            case 'd':
                yydebug = 1;
                break;
            
            case 'p':
                printAST = true;
                TYPES = false;
                break;

            case 'D':
                symbolTable.debug(1);
                break;

            case 'P':
                //print AST with type information
                printAST = true;
                TYPES = true;
                break;

            case 'h':
                printf("usage: -c [options] [sourcefile]\n");
                printf("options:\n");
                printf("-d     - turn on parser debugging\n");
                printf("-D     - turn on symbol table debugging\n");
                printf("-h     - print this usage message\n");
                printf("-p     - print the abstract syntax tree\n");
                printf("-P     - print the abstract syntax tree plus type information\n");
                break;

            default:
                exit(1);
        }
    }


    if(argc >1){
        if((yyin = fopen(argv[argc-1], "r"))) {
            // file open successful
        }
        else {
            //failed to open
            printf("ERROR(ARGLIST): source file \'%s\' could not be opened.\n", argv[1]);
            numErrors++;
            printf("Number of warnings: %d\n", numWarnings);
            printf("Number of errors: %d\n", numErrors);
            exit(1);
        }
    }

    yyparse();

    if(printAST && !TYPES){
        printTree(ast, 0, TYPES);
    }
    else if(printAST && TYPES){
        semanticAnalysis(ast, numErrors, numWarnings);
        //COMMENTED OUT THIS IF STATEMENT FOR TESTING ----- CHANGE BACK***********************
        if(numErrors < 1)
        {
            printTree(ast, 0, TYPES);
        }
    }

    printf("Number of warnings: %d\n", numWarnings);
    printf("Number of errors: %d\n", numErrors);

    return 0;
}