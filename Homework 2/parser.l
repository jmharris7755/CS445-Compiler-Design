%{
//Justin Harris 
//CS445
//Last Updated: 1-29-22

//parser.l
//This file contans Flex code

//order of includes is mandatory
#include "scanType.h" //TokenData Type
#include "parser.tab.h" // token definitions from Bison
#include <ctype.h>
#include <string.h>

int line=1;
int numErrors;  //ERR err count

//helper function to convert lowercase keywords to uppercase
void lowToUpper(char *str)
{
    while(*str = toupper(*str))
    ++str;
}

//helper function to remove '\' from STRINGCONST
void cleanString(char *str, char backSlash)
{
    //character pointers to loop through input string
    char *start, *end;
    char temp;

    //get string length
    int strLen;
    strLen = strlen(str);

    //remove beginning and ending quotes in place
    memmove(str, str+1, strLen-2);
    str[strLen-2] = 0;


    //set all pointers equivalent and loop through until end of string
    for (start = end = str; *str != '\0'; start++)
    {
        //set end pointer equal to start pointer
        *end = *start;



        //if end pointer is not a backslash, increment and reset temp var. 
        if(*end != backSlash) {

            end++;
            temp = ' ';

        }
        else{
            //if temp is a backslash, increment end pointer, clear temp var.
            if(temp == '\\'){
                end++;
                temp = ' ';

            }
            //otherwise save backslash since it's the first backslash in a series .. ie '\\'
            else{
                temp = *end;
            }
        }

        //increment input string
        str++;
    }
    //set terminating character for end of string
    *end = '\0';
}


static int setValue(int linenum, int tokenClass, char *svalue)
{
    //create pas-back data space
    yylval.tokenData = new TokenData;

    //fill it up
    yylval.tokenData->linenum = linenum;

    //assign tokenClass
    yylval.tokenData->tokenclass = tokenClass;

    //duplicate the string
    yylval.tokenData->tokenStrInput = strdup(svalue);

    if (tokenClass == NUMCONST){
        yylval.tokenData->nvalue = atoi(svalue);
        yylval.tokenData->tokenID = strdup("NUMCONST");
        
    }
    else if (tokenClass == ID) {
        yylval.tokenData->svalue = strdup(svalue);
        yylval.tokenData->tokenID = strdup("ID");
    }
    else if (tokenClass == CHARCONST){

        int charLen = 0;

        //get length of char string
        charLen = strlen(svalue);

        //check if beginning and end are ' 
        if(charLen == 3){
            yylval.tokenData->cvalue = svalue[1];
        }

        else if(charLen > 3){
            if(svalue[1] == '\\' && svalue[2] != 'n' && svalue[2] != '0'){
                yylval.tokenData->cvalue = svalue[2];
            }
            //if nullChar or newLine
            else if(svalue[1] == '\\' && (svalue[2] == 'n' || svalue[2] == '0')){
                if(svalue[2] == 'n')
                {
                    yylval.tokenData->cvalue = '\n';
                }
                else{
                    yylval.tokenData->cvalue = '\0';
                }
                
            }
            //length longer than 3 and not nullChar or newLine - print error
            else{
                printf("WARNING(%d): character is %d characters long and not a single character: \'%s\'.  The first char will be used.\n", line, (charLen-2), svalue);
                yylval.tokenData->cvalue = svalue[1];
            }
        }

        //yylval.tokenData->cvalue = svalue[0];
        yylval.tokenData->tokenID = strdup("CHARCONST");

    }
    else if (tokenClass == STRINGCONST){
        //initialization for string length variable
        int strLen = 0;

        //check for newLine STRINGCONST
        if(svalue[1] == '\\' && svalue[2] == 'n'){
            
            strLen = strlen(svalue) - 3;
            yylval.tokenData->svalue = strdup("\n");
            yylval.tokenData->tokenID = strdup("STRINGCONST");
            yylval.tokenData->strLength = strLen;

        }
        else{

            //remove escape character \ from string
            cleanString(svalue, '\\');

            //get string length - 2 for double quotes at beginning and end.
            strLen = strlen(svalue);
            yylval.tokenData->svalue = strdup(svalue);
            yylval.tokenData->tokenID = strdup("STRINGCONST");
            yylval.tokenData->strLength = strLen;
        }
    }
    else if (tokenClass == BOOLCONST) {
        if(strcmp(svalue, "true") == 0){
			yylval.tokenData->nvalue = 1;
            yylval.tokenData->tokenID = strdup("BOOLCONST");
		}
		else {
			    yylval.tokenData->nvalue = 0;
                yylval.tokenData->tokenID = strdup("BOOLCONST");
		}

    }
    else if (tokenClass == KEYWORD){

        //lowToUpper(svalue);
        yylval.tokenData->tokenID = strdup(svalue);

    }
    else if(tokenClass == INC){
        yylval.tokenData->tokenID = strdup("INC");
    }
    else if(tokenClass == DEC){
        yylval.tokenData->tokenID = strdup("DEC");
    }
    else if(tokenClass == NEQ){
        yylval.tokenData->tokenID = strdup("NEQ");
    }
    else if(tokenClass == LEQ){
        yylval.tokenData->tokenID = strdup("LEQ");
    }
    else if(tokenClass == GEQ){
        yylval.tokenData->tokenID = strdup("GEQ");
    }
    else if(tokenClass == ASGN){
        yylval.tokenData->tokenID = strdup("ASGN");
    }
    else if(tokenClass == ADDASGN){
        yylval.tokenData->tokenID = strdup("ADDASGN");
    }
    else if (tokenClass == SPEC) {

        yylval.tokenData->tokenID = strdup(svalue);
    }

    //return the tokenClass
    return tokenClass;
}

%}

%option noyywrap

LETTER	[a-zA-Z]
DIGIT	[0-9]

%%

"##".*                          ;
[ \t]+                          ;
\n                              { line++; }
"true"                          { return setValue(line, BOOLCONST, yytext); }
"false"                         { return setValue(line, BOOLCONST, yytext); }

"int"                           { return setValue(line, KEYWORD, yytext); }
"begin"                         { return setValue(line, KEYWORD, yytext); }
"if"                            { return setValue(line, KEYWORD, yytext); }
"then"                          { return setValue(line, KEYWORD, yytext); }
"return"                        { return setValue(line, KEYWORD, yytext); }
"else"                          { return setValue(line, KEYWORD, yytext); }
"end"                           { return setValue(line, KEYWORD, yytext); }
"bool"                          { return setValue(line, KEYWORD, yytext); }
"char"                          { return setValue(line, KEYWORD, yytext); }
"static"                        { return setValue(line, KEYWORD, yytext); }
"and"                           { return setValue(line, KEYWORD, yytext); }
"or"                            { return setValue(line, KEYWORD, yytext); }
"not"                           { return setValue(line, KEYWORD, yytext); }
"for"                           { return setValue(line, KEYWORD, yytext); }
"to"                            { return setValue(line, KEYWORD, yytext); }
"by"                            { return setValue(line, KEYWORD, yytext); }
"break"                         { return setValue(line, KEYWORD, yytext); }
"while"                         { return setValue(line, KEYWORD, yytext); }

{DIGIT}+                        { return setValue(line, NUMCONST, yytext); }
{LETTER}+({LETTER}|{DIGIT})*    { return setValue(line, ID, yytext); }

\'([^\\n']|\\.)*\'              { return setValue(line, CHARCONST, yytext); }
\"([^\\\n"]|\\.)*\"             { return setValue(line, STRINGCONST, yytext); }

"++"                            { return setValue(line, INC, yytext); }
"--"                            { return setValue(line, DEC, yytext); }
"+="                            { return setValue(line, ADDASGN, yytext); }
"-="                            { return setValue(line, MINUSASGN, yytext); }
"*="                            { return setValue(line, MULTASGN, yytext); }
"/*"                            { return setValue(line, DIVASGN, yytext); }
"!="                            { return setValue(line, NEQ, yytext); }
"<="                            { return setValue(line, LEQ, yytext); }
">="                            { return setValue(line, GEQ, yytext); }
"<-"                            { return setValue(line, ASGN, yytext); }


";"                             { return setValue(line, SEMICOLON, yytext); }
"="                             { return setValue(line, EQUALS, yytext); }
","                             { return setValue(line, COMMA, yytext); }
"("                             { return setValue(line, LPAREN, yytext); }
")"                             { return setValue(line, RPAREN, yytext); }         
"["                             { return setValue(line, LBRACKET, yytext); }
"]"                             { return setValue(line, RBRACKET, yytext); }
"*"                             { return setValue(line, MULT, yytext); }
"+"                             { return setValue(line, PLUS, yytext); }
"-"                             { return setValue(line, MINUS, yytext); }             
":"                             { return setValue(line, COLON, yytext); }
"%"                             { return setValue(line, PERCENT, yytext); }
"<"                             { return setValue(line, LESSTHAN, yytext); }
">"                             { return setValue(line, GREATERTHAN, yytext); }
"/"                             { return setValue(line, DIVIDE, yytext); }
"?"                             { return setValue(line, QMARK, yytext); }        

.                               { printf("ERROR(%d): Invalid or misplaced input character: \'%c\'. Character Ignored.\n", line, yytext[0]); numErrors++;}
%%