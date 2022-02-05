%{
//Justin Harris 
//CS445
//Last Updated: 1-29-22
//parser.y
//This file contains Bison Code

#include "scanType.h" //TokenData type 
#include <stdio.h>

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
    TokenData *tokenData;
}

%token <tokenData> ID NUMCONST CHARCONST STRINGCONST BOOLCONST SPEC KEYWORD INC DEC NEQ LEQ GEQ ASGN ADDASGN

%%
tokenList       : tokenList token
                | token
                ;

token           : ID            {printf("Line %d Token: %s Value: %s\n", $1->linenum, $1->tokenID, $1->tokenStrInput);}
                | NUMCONST      {printf("Line %d Token: %s Value: %d  Input: %s\n", $1->linenum, $1->tokenID, $1->nvalue, $1->tokenStrInput);}
                | CHARCONST     {printf("Line %d Token: %s Value: \'%c\'  Input: %s\n", $1->linenum, $1->tokenID, $1->cvalue, $1->tokenStrInput);}
                | STRINGCONST   {printf("Line %d Token: %s Value: \"%s\"  Len: %d  Input: %s\n", $1->linenum, $1->tokenID, $1->svalue, $1->strLength, $1->tokenStrInput);}
                | BOOLCONST     {printf("Line %d Token: %s Value: %d  Input: %s\n", $1->linenum, $1->tokenID, $1->nvalue, $1->tokenStrInput);}
                | KEYWORD       {printf("Line %d Token: %s\n", $1->linenum, $1->tokenID);}
                | INC           {printf("Line %d Token: %s\n", $1->linenum, $1->tokenID);}
                | DEC           {printf("Line %d Token: %s\n", $1->linenum, $1->tokenID);}
                | NEQ           {printf("Line %d Token: %s\n", $1->linenum, $1->tokenID);}
                | LEQ           {printf("Line %d Token: %s\n", $1->linenum, $1->tokenID);}
                | GEQ           {printf("Line %d Token: %s\n", $1->linenum, $1->tokenID);}
                | ASGN          {printf("Line %d Token: %s\n", $1->linenum, $1->tokenID);}
                | ADDASGN       {printf("Line %d Token: %s\n", $1->linenum, $1->tokenID);}
                | SPEC          {printf("Line %d Token: %s\n", $1->linenum, $1->tokenID);}
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