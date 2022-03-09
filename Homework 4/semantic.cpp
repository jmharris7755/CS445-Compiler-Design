 //Current Progress: testing allbad.c-
 //Need to get "wasUsed" warning working
 //Change error 5 to be 2 cases instead of 1: lhs and rhs
 //Make sure to remove print statements
 //check parse tree printouts!!!
//semantic.cpp
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "semantic.h"

#define MAXCHILDREN 3

using namespace std;

//struct for sprintf to sort error based on line number
struct symErrors {
    int linenum;
    char* errorMsg;
};

vector<symErrors> errBuffer;

//store strings on each sprintf call
char sprintBuffer[256]; 

int nErrors; 
int nWarnings;

bool enterScope = true;
bool returnFlag = false;
bool inLoop = false;
bool inRange = false;
bool inFor = false;
int loopDepth = 1;
int rangePos = 0;

TreeNode *curFunc = NULL;

ExpType functionReturnType;
ExpType actualReturnType;
SymbolTable symbolTable;


SymbolTable returnSymbolTable() {
    return symbolTable;
}

bool compare(const symErrors& f, const symErrors& s){
    return f.linenum < s.linenum;
}

void printErrors(){
    for(int i = 0; i < errBuffer.size(); i++){
        printf("%s", errBuffer[i].errorMsg);
    }
}

void semanticAnalysis(TreeNode *t, int& errors, int& warnings){

    analyze(t, nErrors, nWarnings);

    symbolTable.applyToAll(wasUsedWarn);

    //check for main defined
    TreeNode *mainCheck = (TreeNode*)symbolTable.lookup("main");
    if(mainCheck == NULL){
        printError(16, 0, 0, NULL, NULL, NULL, 0);
    }
    else if(mainCheck != NULL){
        if(mainCheck->nodekind == DeclK && mainCheck->subkind.decl != FuncK){
            //if(mainCheck->subkind.decl == ParamK || mainCheck->child[0]!= NULL){ ?? double check
                printError(16, 0, 0, NULL, NULL, NULL, 0);
            //}
        }
        else if(mainCheck->child[0] != NULL && mainCheck->child[0]->subkind.decl == ParamK){
            printError(16, 0, 0, NULL, NULL, NULL, 0);
        }
    }

    printErrors();
    errors = nErrors;
    warnings = nWarnings;
}

void analyze(TreeNode *t, int& nErrors, int& nWarnings){

    //Break up into 3 cases to analyze each type of NodeKind
    if(t == NULL){
        return;
    }
    switch(t->nodekind){
        case DeclK:
            checkDecl(t, nErrors, nWarnings);
            break;

        case StmtK:
            checkStmt(t, nErrors, nWarnings);
            break;

        case ExpK:
            checkExp(t, nErrors, nWarnings);
            break;
    }

    //keep analyzing recursively
    if(t->sibling != NULL){
        analyze(t->sibling, nErrors, nWarnings);
    }
}

//function to check declaration nodes
void checkDecl(TreeNode *t, int& nErrors, int& nWarnings){
    //check depth to determin if global scope
    if(symbolTable.depth() == 1){
        t->isGlobal = true;
    }
    else{
        t->isGlobal = false;
    }

    
    //check for any re-declarations: "Symbol '%s' is already declared at line %d.\n"
    TreeNode *declared;
    if(t->subkind.decl != VarK && !symbolTable.insert(t->attr.name, t)){
        declared = (TreeNode*)symbolTable.lookup(t->attr.name);
        printError(0, t->linenum, declared->linenum, t->attr.name, NULL, NULL, 0);
    }

    switch(t->subkind.decl){
        
        //loop through params, analyze children
        case ParamK:
        //set declared status
            //t->isDeclared = true;
            for(int i = 0; i < MAXCHILDREN; i++){
                
                analyze(t->child[i], nErrors, nWarnings);
                if(t->child[0] != NULL){
                    t->child[0]->isInit = true;
                }
            }
            t->isInit = true;
            //declared = NULL; //reset declared
  
            break;

        //next case, check VarK, starting by looping through children
        case VarK:

            if(t->child[0] != NULL){
            for(int i = 0; i < MAXCHILDREN; i++){
                analyze(t->child[i], nErrors, nWarnings);
            } 
            }          

            //If VarK is not empty
            /*if(t->child[0] != NULL){
                //lookup ID declaration
                if(t->child[0]->nodekind == ExpK && (t->subkind.exp == IdK && t->child[0]->subkind.exp == CallK)){
                    declared = (TreeNode*)symbolTable.lookup(t->child[0]->attr.name);
                }
                else{
                    declared = t->child[0];
                    //not initialized?
                    //printf("Here %s\n", t->child[0]->attr.name);
                    printError(17, t->linenum, 0, t->attr.name, NULL, NULL, 0);
                }
            }*/

            //check for initialization  -- doing nothing
            //if(declared->expType != t->expType){
            //  printError(17, t->linenum, 0, t->attr.name, NULL, NULL, 0);
            //}

           //check for duplicate declarations
           TreeNode* exists;
           if(!symbolTable.insert(t->attr.name, t)){
               exists = (TreeNode*)symbolTable.lookup(t->attr.name);
               printError(0, t->linenum, exists->linenum, t->attr.name, NULL, NULL, 0);
           }

            //Fix for static declarations with siblings not being set correctly
            //Specifically in var.c- and everythingS22.c-
           if(t->sibling != NULL){
                //printf("VarK t has a sibling. %s\n", t->sibling->attr.name);
                //also need to check if they were declared on the same line
                if(t->isStatic && t->linenum == t->sibling->linenum){
                    t->sibling->isStatic = t->isStatic;
                //printf("VarK t isStatic: %d\n", t->isStatic);
                }
            }


           if(t->child[0] != NULL){
               t->isInit = true;
               //t->wasUsed = true;
               t->isDeclared = true;
               
           }
           else{
               t->isDeclared = true;
           }

           break;

        case FuncK:
            //set t to current function variable
            curFunc = t;

            //set returnFlag to false
            returnFlag = false;

            //Enter a scope for function arguments and compund section
            symbolTable.enter(t->attr.name);

            //might need this to avoid second enter() call with upcoming compound flags
            enterScope = false;
            functionReturnType = t->expType;
            

            //loop though function parameters and statements
            for(int i = 0; i < MAXCHILDREN; i++){
                analyze(t->child[i], nErrors, nWarnings);
            }

            symbolTable.applyToAll(wasUsedWarn);

            //if returnFlag is false, then there was no return statement, 
            //print warning
            if(returnFlag == false && t->expType != Void){
                //Warning 19: "WARNING(%d): Expecting to return %s but function '%s' has no return statement.\n"
                printError(19, t->linenum, 0, conExpType(functionReturnType), t->attr.name, NULL, 0);
            }
            // return type from function "return x" is not the expected type
            else if(returnFlag == true && functionReturnType != actualReturnType && actualReturnType != Void){
                //Error 31: "ERROR(%d): Function '%s' at line %d is expecting to return type %s but returns type %s.\n"
                printError(31, t->linenum, 0, t->attr.name, conExpType(functionReturnType), conExpType(actualReturnType), 0);
            }

            //leave current scope
            symbolTable.leave();

            //reset current function
            curFunc = NULL;

            break;
    }
}

//Function to check statement nodes
void checkStmt(TreeNode *t, int& nErrors, int& nWarnings){

    switch(t->subkind.stmt){
        case IfK:
            inLoop = true;
            symbolTable.enter(t->attr.name);
            enterScope = false;
            for(int i = 0; i < MAXCHILDREN; i++){
                if(t->child[0]){
                    //printf("IfK chid0 %s %s %d\n", t->child[0]->attr.name, conExpType(t->child[0]->expType), t->linenum);
                    analyze(t->child[i], nErrors, nWarnings);
                }
            }

            //boolean test condition check
            if(t->child[0]->expType != Boolean && t->child[0]->subkind.exp != OpK){
                char ifStmt[] = "if";
                //Error 27: "ERROR(%d): Expecting Boolean test condition in %s statement but got type %s.\n"
                printError(27, t->linenum, 0, ifStmt, conExpType(t->child[0]->expType), NULL, 0 );
            }
            inLoop = false;
            //symbolTable.applyToAll(wasUsedWarn);
            symbolTable.leave();
            enterScope = true;
            break;

        case WhileK:
            inLoop = true;
            symbolTable.enter(t->attr.name);
            enterScope = false;
            for(int i = 0; i < MAXCHILDREN; i++){
                if(t->child[i]){
                analyze(t->child[i], nErrors, nWarnings);
                }
            }
            //if(loopDepth == symbolTable.depth()){
                inLoop = false;
                symbolTable.applyToAll(wasUsedWarn);
                symbolTable.leave();
                enterScope = true;
            //}
            break;

        case ForK:
            //Might need to add isInit check in For case also
            inLoop = true;
            inFor = true;
            symbolTable.enter(t->attr.name);
            enterScope = false;
            
            for(int i = 0; i < MAXCHILDREN; i++){
                if(t->child[i]){
                analyze(t->child[i], nErrors, nWarnings);
                
                //maybe need these
                t->child[0]->isInit = true;
                t->child[1]->isInit = true;
                }
            }

            //if(loopDepth == symbolTable.depth()){
                inFor = false;
                inLoop = false;
                symbolTable.applyToAll(wasUsedWarn);
                symbolTable.leave();
                enterScope = true;
            //}
            break;

        case ReturnK:
            analyze(t->child[0], nErrors, nWarnings);
            if(t->child[0] != NULL){
                //symbolTable look up of c0 attr.name
                //set is child0 to is used 

                //set returnFlag to track functions that have a return statement
                returnFlag = true;

                //store return type to compare aginst in FuncK
                actualReturnType = t->expType;

                if(curFunc == NULL){
                    break;
                }
                //check if t is an array
                else if(t->child[0]->isArray){
                    //cannot return array error
                    printError(10, t->linenum, 0, NULL, NULL, NULL, 0);
                }
            }
            break;

        case BreakK:
            break;

        case RangeK:
            rangePos = 0;
            inRange = true;
            //printf("RangeK check: %s %s\n", t->attr.name, t->child[0]->attr.name);
            for(int i = 0; i < MAXCHILDREN; i++){
                if(t->child[i]){
                    rangePos++;
                    analyze(t->child[i], nErrors, nWarnings);
                    //printf("RangeK check: %s %d %d\n", t->child[i]->attr.name, t->linenum, t->child[i]->isArray);
                }
            }


            inRange = false;

            break;

        case CompoundK:
            //Enter a new scope, unless the flags are the beginning of a func decl
            bool keepCurScope = enterScope;
            if(keepCurScope){
                symbolTable.enter("compound");
            }
            else{
                enterScope = true;
            }

            for(int i = 0; i < MAXCHILDREN; i++){
                analyze(t->child[i], nErrors, nWarnings);
            }
            //Check if single compound and leave scope if true
            if(keepCurScope){
                symbolTable.applyToAll(wasUsedWarn);
                symbolTable.leave();
            }

            break;

    }

}

void checkExp(TreeNode *t, int& nErrors, int& nWarnings){
    //set up multiple bool flags for checking different array error conditions and initialize all to false
    bool leftStr, rightStr, isBinary, leftArr, rightArr, leftIndx, rightIndx, leftInit, leftDecl, rightInit, rightDecl, throwError;
    leftStr = rightStr = isBinary = leftArr = rightArr = leftIndx = rightIndx = leftInit = leftDecl = rightInit = rightDecl = throwError = false;

    ExpType leftSide, rightSide, returnType, leftExpected, rightExpected;
    leftSide = rightSide = returnType = leftExpected = rightExpected = UndefinedType;

    bool rightErr, leftErr, unaryErrors;
    rightErr = leftErr = unaryErrors = false;

    TreeNode* valFound = NULL;
    TreeNode* leftNode = NULL;
    TreeNode* rightNode = NULL;

    switch(t->subkind.exp) {
        case AssignK:
        case OpK:

            //Check for <- operator first (assignment statement)
            if(!strcmp(t->attr.name, "<-")){
                //make sure child0 is not null
                if(t->child[0] != NULL){
                    
                    //check for "[" (arrays) on the left and set child of [ init to true
                    if(t->child[0]->child[0]!=NULL && !strcmp(t->child[0]->attr.name, "[")){
                        t->child[0]->child[0]->isInit = true;

                        //printf("OpK strcmp child1 of child0 %s %s %d\n", t->attr.name, t->child[0]->child[1]->attr.name, t->child[0]->child[1]->isInit);

                        //check for ID inside of []
                        if(t->child[0]->child[1] != NULL){
                            t->child[0]->child[1]->isInit = true;
                            //check for operation inside of []
                            if(t->child[0]->child[1]->child[0] != NULL && t->child[0]->child[1]->child[1] != NULL){
                            if(t->child[0]->child[1]->subkind.exp == OpK){
                                t->child[0]->child[1]->child[0]->isInit = true;
                                t->child[0]->child[1]->child[1]->isInit = true;
                            //printf("OpK strcmp child1 of child0 %s %s %s %d\n", t->attr.name, t->child[0]->child[1]->attr.name, t->child[0]->child[1]->attr.name, t->linenum);
                            }
                            }
                        }
                        else if(t->child[0]->child[1]->child[0] != NULL){
                            t->child[0]->child[1]->child[0]->isInit = true;
                        }

                    }
                    //nested assignments and ID set to CallK checks
                    else if(t->child[1] !=NULL && t->child[1]->expType == Void){
                        //check if double assignment: x<-y<-z
                        if(!strcmp(t->child[1]->attr.name, "<-")){
                            t->child[0]->isInit = true;
                        }
                        //if ID is assigned to CallK output initialized is true
                        if(t->child[1]->subkind.exp == CallK){
                            t->child[0]->isInit = true;
                        }

                        //check for array on right side -- left child is init if the left child of [ is init
                        else if(!strcmp(t->child[1]->attr.name, "[")){
                            //make sure Id isn't initializing itself
                            char* lhs = strdup(t->child[0]->attr.name);
                            char* rhs = strdup(t->child[1]->child[0]->attr.name);
                            if(/*t->child[1]->child[0]->isInit &&*/ strcmp(lhs, rhs)){
                                t->child[0]->isInit = true;
                            }

                        }
                        else if(t->child[0]!=NULL && t->child[1]!=NULL){
                            //printf("OpK else init check: %s %s %s %d\n", t->child[0]->attr.name, t->attr.name, t->child[1]->attr.name, t->linenum);
                            if(t->child[0]->subkind.exp == IdK && !t->child[0]->isInit){
                                //printf("OpK else init check: %s %s %s %d\n", t->child[0]->attr.name, t->attr.name, t->child[1]->attr.name, t->linenum);
                                if(t->child[1]->subkind.exp == IdK){
                                    //make sure same variable isn't initializing itself
                                    char* lhs = strdup(t->child[0]->attr.name);
                                    char* rhs = strdup(t->child[1]->attr.name);
                                    if(strcmp(lhs, rhs)){
                                        t->child[0]->isInit = true;
                                    }
                                }
                                //recursive check for multiple assignK's on rhs += -= /= *=
                                //if child0 is and ID, not init and on lhs of nested assignments
                                //it should be inititalized
                                else if(t->child[1]->subkind.exp == AssignK){
                                    checkNestAssK(t->child[1]);
                                    t->child[0]->isInit = true;
                                    //printf("OpK else init check2: %s %s %s %d\n", t->child[0]->attr.name, t->attr.name, t->child[1]->attr.name, t->linenum);
                                }
                            }
                        }

                        else{
                            //printf("OpK else init check: %s %s %s %d\n", t->child[0]->attr.name, t->attr.name, t->child[1]->attr.name, t->linenum); 
                        }
                    }
                   
                    else {
                        t->child[0]->isInit = true;
                    }
                }

            }

            //variables that appear on either side of an operator except for <- should be considered used
            if(strcmp(t->attr.name, "<-")){
                if(t->child[0] != NULL){
                    t->child[0]->wasUsed = true;
                    
                }
                if(t->child[1] != NULL){
                    t->child[1]->wasUsed = true;
                }
            }

            for(int i= 0; i < MAXCHILDREN; i++){
                analyze(t->child[i], nErrors, nWarnings);
            }
            //set up left hand side
            if(t->child[0] != NULL){
                leftNode = t->child[0];
                leftSide = leftNode->expType;
                leftArr = leftNode->isArray;

                if(leftNode->child[0] != NULL){
                    leftArr = false; //indexed array is not an array after indexed
                    leftIndx = true; //indexing nonarrays
                }
                if(leftNode->nodekind == ExpK){
                    if(leftNode->subkind.exp == CallK){
                        leftArr = false;
                    }
                    if(leftNode->subkind.exp == ConstantK){
                        leftStr = true;
                    }
                }
            }

            //setup right hand side
            if(t->child[1] != NULL){
                rightNode = t->child[1];
                rightSide = rightNode->expType;
                rightArr = rightNode->isArray;
                

                if(rightNode->child[0] != NULL){
                    rightArr = false; //indexed array is not an array after indexed
                    rightIndx = true; //indexing nonarrays
                }
                if(rightNode->nodekind == ExpK){
                    if(rightNode->subkind.exp == CallK){
                        rightArr = false;
                    }
                    if(rightNode->subkind.exp == ConstantK){
                        rightStr = true;
                    }
                }
                isBinary = true;
            }

            //Get expected type based on OpK
            getExpTypes(t->attr.name, isBinary, unaryErrors, leftExpected, rightExpected, returnType);

            //if Void = undeclared ID :: not for Void function types
            if(leftSide == Void && !(leftNode->nodekind == ExpK && leftNode->subkind.exp == CallK)){
                leftErr = true;
            }
            if(rightSide == Void && !(rightNode->nodekind == ExpK && rightNode->subkind.exp == CallK)){
                rightErr = true;
            }

            //start checking for Unary errors
            if(!isBinary && !leftErr){
                //Error: Unary '%s' requires an operand of %s but was given %s
                if(leftSide != leftExpected && leftExpected != UndefinedType){

                    //check for Unary '-' to convert to chsign
                    if(!strcmp(t->attr.name, "-")){
                        char uMinus[] = "chsign";
                        printError(9, t->linenum, 0, uMinus, conExpType(leftExpected), conExpType(leftSide), 0);
                    }

                    else{
                        printError(9, t->linenum, 0, t->attr.name, conExpType(leftExpected), conExpType(leftSide), 0);
                    }
                }
                //check for Unary 'not' -- not working from getExpTypes? 
                //this does catch it though
                else if(!strcmp(t->attr.name, "not") && leftSide != leftExpected){
                    //leftExpected = Boolean;
                    printError(9, t->linenum, 0, t->attr.name, conExpType(leftExpected), conExpType(leftSide), 0);
                }
                //Check for Unary size of Error
                else if(!strcmp(t->attr.name, "*") && (!leftArr && leftSide != UndefinedType)){
                    char uSizeof[] = "sizeof";
                    printError(8, t->linenum, 0, uSizeof, NULL, NULL, 0);
                } 

                //Error: Does not work with Array and Only works with Array
                if(leftArr){
                    if(strcmp(t->attr.name, "*") != 0){
                        //check for chsign
                        if(!strcmp(t->attr.name, "-")){
                            char uMinus[] = "chsign";
                            printError(7, t->linenum, 0, uMinus, NULL, NULL, 0);
                        }
                        else{
                            printError(7, t->linenum, 0, t->attr.name, NULL, NULL, 0);
                        }
                    }
                }
            }
                else{
                    if(!unaryErrors){

                        //[ on arrays is being caughter here and printing out
                        if(!strcmp(t->attr.name, "[")){
                            //put logic into a function
                            arrayErrors(t);
                        }
                
                        //'and' and 'or' are currently erroring here*** - fixed
                        //Error: expected matching types on both sides
                        else if(leftSide != rightSide && !leftErr && !rightErr){
                            //check for CharInt and differentiate
                            //replace CharInt with char if leftside is int and right is charint
                            if(!strcmp(conExpType(leftSide), "int") && !strcmp(conExpType(rightSide), "CharInt")){
                                char diffCharInt[] = "char";
                                 printError(2, t->linenum, 0, t->attr.name, conExpType(leftSide), diffCharInt, 0);
                            }
                            else if(!strcmp(conExpType(leftSide), "char") && !strcmp(conExpType(rightSide), "CharInt")){
                                ; //do nothing, correct matching
                            }
                            else{
                                //print normally
                                 printError(2, t->linenum, 0, t->attr.name, conExpType(leftSide), conExpType(rightSide), 0);
                            }
                        }
                    }

                    //alt error for not expected types | left side or right side
                    if(!(leftExpected == UndefinedType || rightExpected == UndefinedType)){
                        
                        if(leftExpected == CharInt || rightExpected == CharInt){
                            //not sure what to do, but am getting multiple printouts with CharInt
                            ;
                        }
                        else{
                            //left error
                            if(leftSide != leftExpected && !leftErr){
                                printError(3, t->linenum, 0, t->attr.name, conExpType(leftExpected), conExpType(leftSide), 0);
                            }
                            //right error -- types.c- main++, ++ operator going to here
                            if(rightSide != rightExpected && !rightErr && rightSide != UndefinedType && rightSide != Void){
                                printError(4, t->linenum, 0, t->attr.name, conExpType(rightExpected), conExpType(rightSide), 0);
                            }
                        }
                    }

                    //check Array errors
                    if(leftArr || rightArr){
                        //Error: does not work with Arrays
                        if(strcmp(t->attr.name, "<-") && leftExpected != UndefinedType){
                            if(!strcmp(t->attr.name, "<") || !strcmp(t->attr.name, ">") || !strcmp(t->attr.name, "=") || !strcmp(t->attr.name, ">=") || !strcmp(t->attr.name, "<=") || !strcmp(t->attr.name, "><")){
                                //do nothing, these operators can be used with arrays -- I lied, error check
                                 if(leftArr && !rightArr){
                                printError(5, t->linenum, 0, t->attr.name, NULL, NULL, 0);
                                }
                                else if(!leftArr && rightArr){
                                printError(6, t->linenum, 0, t->attr.name, NULL, NULL, 0);
                                }
                            }

                            else{
                            printError(7, t->linenum, 0, t->attr.name, NULL, NULL, 0);
                            }
                        }
                        
                        else{
                            //Error: requires both sides to be an array
                            // [ for arrays is also being caught here and printing out
                            //now prints out blank line
                            if(!strcmp(t->attr.name, "[")){
                                ;
                            }
                            //%s -- don't print types, split into a left !right and !left right is an array
                            //error requires both operands be arrays or not but lhs is type %s an array and rhs is type %s an array.
                            else if((leftArr && !rightArr) || (!leftArr && rightArr)){
                                if(leftArr && !rightArr){
                                printError(5, t->linenum, 0, t->attr.name, NULL, NULL, 0);
                                }
                                else if(!leftArr && rightArr){
                                    printError(6, t->linenum, 0, t->attr.name, NULL, NULL, 0);
                                }
                            }
                        }
                    }
                }

            //stop cascading errors
            if(returnType != UndefinedType){
                t->expType = returnType;
            }
            else{
                t->expType = leftSide;
            }
            break;

        case ConstantK:
            for(int i = 0; i < MAXCHILDREN; i++){
                analyze(t->child[i], nErrors, nWarnings);
            }
            break;

        case IdK:
            valFound = (TreeNode*)symbolTable.lookup(t->attr.name);
            //if unable to find, Error: "Symbol undeclared"
            if(valFound == NULL){
                //check for ID inside of Range, considered declared if it shows up
                if(inRange){
                    t->isDeclared = true;
                }
                else{
                printError(1, t->linenum, 0, t->attr.name, NULL, NULL, 0); 
                    t->declErr = true;    
                }           
            }
            //check if ID is in a range
            else if(inRange){

                //check if ID is in a for loop
                if(inFor){
                    //set expType of t to declared expType
                    t->expType = valFound->expType;

                    //check for int at position 1 of for loop
                    if(t->expType != Integer && rangePos == 1)
                    {
                        char intExpect[] = "int";
                        //Error 26: "ERROR(%d): Expecting type %s in position %d in range of for statement but got type %s.\n"
                        printError(26, t->linenum, 0, intExpect, conExpType(t->expType), NULL, rangePos);
                    }

                    //not allowed to use arrays in range of for
                    if(valFound->isArray){
                        //Error 24: "ERROR(%d): Cannot use array in position %d in range of for statement.\n"
                        printError(24, t->linenum, 0, NULL, NULL, NULL, rangePos);
                    }

                    //don't check for this here
                    //check for type matching at positions as well
                    /*if(t->expType != valFound->expType){
                        //Error 26: "ERROR(%d): Expecting type %s in position %d in range of for statement but got type %s.\n"
                        printError(26, t->linenum, 0, conExpType(valFound->expType), conExpType(t->expType), NULL, rangePos);
                    }*/
                }
                //printf("IdK / RangeK check: %s %d %d\n", valFound->attr.name, t->linenum, valFound->isArray);
                t->isInit = true;
            }

            else{

                //check if initialized -- error if not -- make sure not param, warning hasn't been reported
                //isn't vark isn't <-, isn't global, isn't Void, 
                 if(valFound->isDeclared == true){
                     //printf("valFound Name, Declared, Static: %s, %d, %d %d\n", valFound->attr.name, valFound->isDeclared, valFound->isStatic, t->linenum);
                 if(!valFound->isInit && !valFound->warningReported && !valFound->isStatic && !valFound->isGlobal){
                     if(!t->isInit){
                        valFound->warningReported = true;
                        //printf("Idk check uninit warn %s %d\n", valFound->attr.name, valFound->isStatic);
                        printError(18, t->linenum, 0, t->attr.name, NULL, NULL, 0);
                     }
                     else{
                         valFound->isInit = true;
                     }
                 }
                 }

                //Error: cannot use function as variable
                if(valFound->subkind.decl == FuncK){
                    printError(12, t->linenum, 0, t->attr.name, NULL, NULL, 0);
                    break;
                }
                else{
                    t->expType = valFound->expType;
                    t->isArray = valFound->isArray;
                    t->isGlobal = valFound->isGlobal;
                    t->isStatic = valFound->isStatic;

                    //not used if in Range and rule out FuncK
                    //funcK should be considered used only in CallK
                    if(!inRange && valFound->subkind.decl != FuncK){
                    valFound->wasUsed = true;
                    }
                }

                //Array index errors
                if(t->child[0] != NULL){
                    analyze(t->child[0], nErrors, nWarnings);
                    if(t->child[0]->expType == Void && !(t->child[0]->nodekind == ExpK && t->child[0]->subkind.exp == CallK)){
                        //unidentified error
                        break;
                    }
                    if(!t->isArray){
                        //do nothing
                        break;
                    }
                    else{
                        //Error: array should be index by type int...
                        if(t->child[0]->expType != Integer){
                            printError(14, t->linenum, 0, t->attr.name, conExpType(t->child[0]->expType), NULL, 0);
                        }
                        //Error: array index is the unindexed array...
                        if(t->child[0]->isArray && t->child[0]->child[0] == NULL){
                            printError(13, t->linenum, 0, t->child[0]->attr.name, NULL, NULL, 0);
                        }
                    }
                }
            }
            break;

        case CallK:
            int paramCount = 1;
            TreeNode* funcFound;
            //check for undeclared call
            if(t->subkind.exp == CallK){
                funcFound = (TreeNode*)symbolTable.lookup(t->attr.name);
                if(funcFound == NULL){
                    printError(1, t->linenum, 0, t->attr.name, NULL, NULL, 0);  
                        t->declErr = true; 
                }
                else{
                    //if(funcFound->child[0] != NULL)
                    //{printf("CallK lookup Check: %s\n", conExpType(funcFound->child[0]->expType));}
                    
                }
            }

             for(int i = 0; i < MAXCHILDREN; i++){
                analyze(t->child[i], nErrors, nWarnings);
                }

            if(funcFound != NULL){
                t->expType = funcFound->expType;
                t->isArray = funcFound->isArray;
                t->isGlobal = funcFound->isGlobal;
                t->isStatic = funcFound->isStatic;
                funcFound->wasUsed = true;

                //Error: is a simple variable and cannot be used as a call
                if(funcFound->subkind.decl != FuncK){
                    printError(11, t->linenum, 0, t->attr.name, NULL, NULL, 0);
                }
                //check parameters
                else{

                    //printf("CallK funcFound check1: %s\n", funcFound->attr.name);

                    //function found has parameters and current call has parameters
                    if(funcFound->child[0] != NULL && t->child[0] != NULL){
                       
                       //recursive comparison of parameters because checking each child
                       //won't work since param list are converted to siblings instead of add'l children
                       parameterErrors(funcFound, t, funcFound->child[0], t->child[0], paramCount);
                    }
                    //too many parameters
                    //function found has expects no params, but current call has them
                    else if(funcFound->child[0] == NULL && t->child[0] != NULL){
                        //printf("CallK funcFound check2: %s\n", funcFound->attr.name);
                        printError(38, t->linenum, funcFound->linenum, t->attr.name, NULL, NULL, 0);
                    }
                    //too few parameters
                    //function found is expecting paramters but current call has none
                    else if(funcFound->child[0] != NULL && t->child[0] == NULL){
                        printError(37, t->linenum, funcFound->linenum, t->attr.name, NULL, NULL, 0);
                    }
                }
            }
      
            break;        
    }

}

//Determine expected variables associated with each OpK operator
void getExpTypes(const char* strng, bool isBinary, bool &unaryErrors, ExpType &left, ExpType &right, ExpType &rightT){
    //c++ string array to hold unary operators
    std::string unaryOps[6] = {"not", "*", "?", "-", "--", "++"};

    //c++ string array to hold binary operators
    std::string binaryOps[18] = {"+", "-", "*", "/", "%", "+=", "-=", "*=", "/=", ">", "<", ">=", "<=", "==", "!=", "=", "and", "or"};
    std::string op(strng);
    unaryErrors = false;

    if(!isBinary){
        for(int i = 0; i < 6; i++){
            if(op == unaryOps[i]){
                if(i == 0){
                    left = right = rightT = Boolean;
                }
                if(i == 1){
                    left = right = UndefinedType;
                    rightT = Integer;
                }
                if(i >= 2){
                    left = right = rightT = Integer;
                }
            }
        }
    }
    else{
        for(int i = 0; i < 18; i++){
            if(op == binaryOps[i]){
                if(i >= 0 && i <= 8){
                    left = right = rightT = Integer;
                    unaryErrors = true;
                }
                //Doesn't work with arrays error
                if(i >= 9 && i <= 12){
                    left = right = CharInt; 
                    rightT = Boolean;
                }
                if(i >= 13 && i <=14){
                    left = right = UndefinedType;
                    rightT = Boolean;
                }
                if(i == 15){
                    left = right = rightT = UndefinedType;
                }
                if(i >= 16){
                    left = right = rightT = Boolean;
                    unaryErrors = true;
                }

            }
        }
    }

}

//convert expression types for print outs
char* conExpType(ExpType type){
    switch(type){
       
        case Void:
            return strdup("void");
        case Integer:
            return strdup("int");
        case Boolean:
            return strdup("bool");
        case Char:
            return strdup("char");
        case CharInt:
            return strdup("CharInt");
        case Equal:
            return strdup("Equal");
        case UndefinedType:
            return strdup("undefined type");
        default:
            return strdup("expType not found\n");
    }
}

//print errors using sprintf and buffer based on error code (switch case)
void printError(int errCode, int linenum, int reasonNum, char* s1, char* s2, char* s3, int i){

    if(errCode > 16 && errCode < 22){
        nWarnings++;
    }
    else{
        nErrors++;
    }

    //print error depending on error code 0 - 38
    switch(errCode){

        //Declaration Errors
        case 0: 
            sprintf(sprintBuffer, "ERROR(%d): Symbol '%s' is already declared at line %d.\n", linenum, s1, reasonNum);
            break;

        case 1:
            sprintf(sprintBuffer, "ERROR(%d): Symbol '%s' is not declared.\n", linenum, s1);
            break;

        //Expression Errors
        case 2: 
            sprintf(sprintBuffer, "ERROR(%d): '%s' requires operands of the same type but lhs is type %s and rhs is type %s.\n", linenum, s1, s2, s3);
            break;

        case 3:
            sprintf(sprintBuffer, "ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n", linenum, s1, s2, s3);
            break;

        case 4:
            sprintf(sprintBuffer, "ERROR(%d): '%s' requires operands of type %s but rhs is of type %s.\n", linenum, s1, s2, s3);
            break;

                //This needs to be split into 2 cases, right hand side and left hand side
        case 5: 
            sprintf(sprintBuffer, "ERROR(%d): '%s' requires both operands be arrays or not but lhs is an array and rhs is not an array.\n", linenum, s1);
            break;

        case 6:
            sprintf(sprintBuffer, "ERROR(%d): '%s' requires both operands be arrays or not but lhs is not an array and rhs is an array.\n", linenum, s1);
            break;

        case 7: 
            sprintf(sprintBuffer, "ERROR(%d): The operation '%s' does not work with arrays.\n", linenum, s1);
            break;

        case 8: 
            sprintf(sprintBuffer, "ERROR(%d): The operation '%s' only works with arrays.\n", linenum, s1);
            break;

        case 9:
            sprintf(sprintBuffer, "ERROR(%d): Unary '%s' requires an operand of type %s but was given type %s.\n", linenum, s1, s2, s3);
            break;


        //Return Errors
        case 10: 
            sprintf(sprintBuffer, "ERROR(%d): Cannot return an array.\n", linenum);
            break;

        //Function Errors
        case 11: 
            sprintf(sprintBuffer, "ERROR(%d): '%s' is a simple variable and cannot be called.\n", linenum, s1);
            break;

        case 12:
            sprintf(sprintBuffer, "ERROR(%d): Cannot use function '%s' as a variable.\n", linenum, s1);
            break;

        //Array Index Errors
        case 13:
            sprintf(sprintBuffer, "ERROR(%d): Array index is the unindexed array '%s'.\n", linenum, s1);
            break;

        case 14: 
            sprintf(sprintBuffer, "ERROR(%d): Array '%s' should be indexed by type int but got type %s.\n", linenum, s1, s2);
            break;

        case 15: 
            sprintf(sprintBuffer, "ERROR(%d): Cannot index nonarray '%s'.\n", linenum, s1);
            break;

        // 'Main' Error
        case 16: 
            sprintf(sprintBuffer, "ERROR(LINKER): A function named 'main' with no parameters must be defined.\n");
            break;

        //Warnings -- initialized but not used, uninitialized
        case 17: 
            sprintf(sprintBuffer, "WARNING(%d): The variable '%s' seems not to be used.\n", linenum, s1);
            break;

        case 18:
            sprintf(sprintBuffer, "WARNING(%d): Variable '%s' may be uninitialized when used here.\n", linenum, s1);
            break;

        //Additonal Errors added for Assignment 4
        case 19: 
            sprintf(sprintBuffer, "WARNING(%d): Expecting to return type %s but function '%s' has no return statement.\n", linenum, s1, s2);
            break;

        case 20:
            sprintf(sprintBuffer, "WARNING(%d): The function '%s' seems not to be used.\n", linenum, s1);
            break;

        case 21:
            sprintf(sprintBuffer, "WARNING(%d): The parameter '%s' seems not to be used.\n", linenum, s1);
            break;

        // Additional errors added for Assignment 4

        case 22: 
            sprintf(sprintBuffer, "ERROR(%d): Cannot have a break statement outside of loop.\n", linenum);
            break;

        case 23:
            sprintf(sprintBuffer, "ERROR(%d): Cannot use array as test condition in %s statement.\n", linenum, s1);
            break;

        case 24:
            sprintf(sprintBuffer, "ERROR(%d): Cannot use array in position %d in range of for statement.\n", linenum, i);
            break;

        case 25:
            sprintf(sprintBuffer, "ERROR(%d): Expecting type %s in parameter %d of call to '%s' declared on line %d but got type %s.\n", linenum, s2, i, s1, reasonNum, s3);
            break;

        case 26:
            sprintf(sprintBuffer, "ERROR(%d): Expecting type %s in position %d in range of for statement but got type %s.\n", linenum, s1, i, s2);
            break;

        case 27:
            sprintf(sprintBuffer, "ERROR(%d): Expecting Boolean test condition in %s statement but got type %s.\n", linenum, s1, s2);
            break;

        case 28:
            sprintf(sprintBuffer, "ERROR(%d): Expecting array in parameter %d of call to '%s' declared on line %d.\n", linenum, i, s1, reasonNum);
            break;

        case 29:
            sprintf(sprintBuffer, "ERROR(%d): Function '%s' at line %d is expecting no return value, but return has a value.\n", linenum, s1, linenum);
            break;

        case 30:
            sprintf(sprintBuffer, "ERROR(%d): Function '%s' at line %d is expecting to return %s but return has no value.\n", linenum, s1, linenum, s2);
            break;

        case 31:
            sprintf(sprintBuffer, "ERROR(%d): Function '%s' at line %d is expecting to return type %s but returns type %s.\n", linenum, s1, linenum, s2, s3);
            break;

        case 32:
            sprintf(sprintBuffer, "ERROR(%d): Initializer for variable '%s' is not a constant expression.\n", linenum, s1);
            break;

        case 33:
            sprintf(sprintBuffer, "ERROR(%d): Initializer for variable '%s' of %s is of %s\n", linenum, s1, s2, s3);
            break;

        case 34:
            sprintf(sprintBuffer, "ERROR(%d): Initializer for variable '%s' requires both operands be arrays or not but variable is not an array and rhs is an array.\n", linenum, s1);
            break;

        case 35:
            sprintf(sprintBuffer, "ERROR(%d): Initializer for variable '%s' requires both operands be arrays or not but variable is an array and rhs is not an array.\n", linenum, s1);
            break;
        
        case 36:
            sprintf(sprintBuffer, "ERROR(%d): Not expecting array in parameter %d of call to '%s' declared on line %d.\n", linenum, i, s1, reasonNum);
            break;

        case 37:
            sprintf(sprintBuffer, "ERROR(%d): Too few parameters passed for function '%s' declared on line %d.\n", linenum, s1, reasonNum);
            break;

        case 38:
            sprintf(sprintBuffer, "ERROR(%d): Too many parameters passed for function '%s' declared on line %d.\n", linenum, s1, reasonNum);
    }

    //put the error message into the error vector!!!!
    symErrors e;
    e.linenum = linenum;
    e.errorMsg = strdup(sprintBuffer);
    errBuffer.push_back(e);
}

//Check for array errors 13-15
void arrayErrors(TreeNode *t)
{
    //set up lhs and rhs sides
   TreeNode *leftNode = NULL;
   TreeNode *rightNode = NULL;

   leftNode = t->child[0];
   rightNode = t->child[1];

    //if lhs is an ID
   if(t->child[0]->subkind.exp == IdK)
   {
       //lookup LHS
      leftNode = (TreeNode*)symbolTable.lookup(t->child[0]->attr.name);
      
      //if exists, set exp types
      if(leftNode != NULL)
      {
         t->child[0]->expType = leftNode->expType;
         t->expType = leftNode->expType;
      }

      //lhs exists and not an array
      if(leftNode == NULL || !leftNode->isArray)
      {
          //Error: can't index nonarray
         printError(15, t->linenum, 0, t->child[0]->attr.name, NULL, NULL, 0);
      }
   }
   else
   {
      printError(15, t->linenum, 0, t->child[0]->attr.name, NULL, NULL, 0);
   }
   if(t->child[1] != NULL)
   {
       //check if array is being indexed by something other than an int
      if(t->child[1]->expType != Integer && t->child[1]->expType != UndefinedType)
      {
          //Error: array should be indexed by type int but got...
         printError(14, t->linenum, 0, t->child[0]->attr.name, conExpType(t->child[1]->expType), NULL, 0);
      }
   }
   if(t->child[1] != NULL && t->child[1]->subkind.exp == IdK)
   {
       //right node exists and is being indexed by an array
      if(rightNode != NULL && rightNode->isArray == true)
      {
          //Error: Array is unindexed array
         printError(13, t->linenum, 0, rightNode->attr.name, NULL, NULL, 0); //
      }
      if(rightNode != NULL)
      {
         t->child[1]->expType = rightNode->expType;
      }
   }

}

//Check for nested assignments -- warnings missed in everythingS22 on HW3
//no longer nested (recursive) causes other problems
void checkNestAssK(TreeNode *c1){

    if(c1->child[0] != NULL){
        c1->child[0]->isInit = true;
        //printf("nestAssk check: %s %s\n", c1->attr.name, c1->child[0]->attr.name);
    }
}

//Function to check for wasUsed warnings
//recommended by TA to write an additonal function lookupNode for
//the symbolTable to check for this flag. 
void wasUsedWarn(std::string symbol, void* t){

    TreeNode* checkUsed;

    checkUsed = symbolTable.lookupNode(symbol.c_str());       

    if(!checkUsed->wasUsed && !checkUsed->isGlobal && strcmp(checkUsed->attr.name, "main")){
        //if parameter, print parameter variant
        //Warning 21: "WARNING(%d): The parameter '%s' seems not to be used.\n"
        if(checkUsed->subkind.decl == ParamK){
            printError(21, checkUsed->linenum, 0, checkUsed->attr.name, NULL, NULL, 0);
        }

        //otherwise print variable variant
        //Warning 17: "WARNING(%d): The variable '%s' seems not to be used.\n"
        else{
            printError(17, checkUsed->linenum, 0, checkUsed->attr.name, NULL, NULL, 0);
        }
    }
    //if function as not called, it wasn't used
    else if(!checkUsed->wasUsed && checkUsed->isGlobal && checkUsed->subkind.decl == FuncK){
        
        //exclude "main"
        if(strcmp(checkUsed->attr.name, "main")){
            //Warning 20: "WARNING(%d): The function '%s' seems not to be used.\n"
            printError(20, checkUsed->linenum, 0, checkUsed->attr.name, NULL, NULL, 0);
        }
    }

    //check for globals that are not used
    else if(!checkUsed->wasUsed && checkUsed->isGlobal){
         printError(17, checkUsed->linenum, 0, checkUsed->attr.name, NULL, NULL, 0);
    }
}


//function to recursively check paramaters in function, for each sibling parameter. 
void parameterErrors(TreeNode *funcFound, TreeNode *t, TreeNode *ffParm, TreeNode *tParm, int paramCount){
    
    //Compare number of parameters  

    //if function found has no addl params, but current call does
    //too many arguments
    if(ffParm->sibling == NULL && tParm->sibling != NULL){
        //printf("parmErrors checking 4: %s %d\n", funcFound->attr.name, t->linenum);
        printError(38, t->linenum, funcFound->linenum, t->attr.name, NULL, NULL, 0);
    }
    //if function found requires addl params, but call is missing them
    //too few aruments
    else if(ffParm->sibling != NULL && tParm->sibling == NULL){
        //printf("parmErrors checking 5: %s %d\n", funcFound->attr.name, t->linenum);
        printError(37, t->linenum, funcFound->linenum, t->attr.name, NULL, NULL, 0);
    }

    //analyze(t->child[paramCount], nErrors, nWarnings);
    
    if(tParm->expType != UndefinedType){
        
        //Error 25: "ERROR(%d): Expecting %s in parameter %d of call to '%s' declared on line %d but got %s.\n"
        if(ffParm->expType != tParm->expType && !tParm->declErr){
            //printf("Parameter Errors made it here %s %s\n", conExpType(ffParm->expType), conExpType(tParm->expType));
            printError(25, t->linenum, funcFound->linenum, funcFound->attr.name, conExpType(ffParm->expType), conExpType(tParm->expType), paramCount);
            //printf("is the issue the printError?\n");

             //Error 36: "ERROR(%d): Not expecting array in parameter %d of call to '%s' declared on line %d.\n"
            if(!ffParm->isArray && tParm->isArray){
                printError(36, t->linenum, funcFound->linenum, funcFound->attr.name, NULL, NULL, paramCount);
            }
            //Error 28: "ERROR(%d): Expecting array in parameter %d of call to '%s' declared on line %d.\n" 
            else if(ffParm->isArray && !tParm->isArray){
                printError(28, t->linenum, funcFound->linenum, funcFound->attr.name, NULL, NULL, paramCount);
            }
        }
        //Error 36: "ERROR(%d): Not expecting array in parameter %d of call to '%s' declared on line %d.\n"
        else if(!ffParm->isArray && tParm->isArray){
            printError(36, t->linenum, funcFound->linenum, funcFound->attr.name, NULL, NULL, paramCount);
        }
        //Error 28: "ERROR(%d): Expecting array in parameter %d of call to '%s' declared on line %d.\n" 
        else if(ffParm->isArray && !tParm->isArray){
            printError(28, t->linenum, funcFound->linenum, funcFound->attr.name, NULL, NULL, paramCount);
        }
       
    }

    paramCount++;
    //if siblings are not null check for sibling -- doesn't show up when checking
    //for additonal children
    if(ffParm->sibling != NULL && tParm->sibling != NULL){
    parameterErrors(funcFound, t, ffParm->sibling, tParm->sibling, paramCount);
    }

}
