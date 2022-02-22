 
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
int loopDepth = 1;

TreeNode *curFunc = NULL;

ExpType functionReturnType;
SymbolTable symbolTable;

int globOffset = 0;
int locOffset = 0;

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

    //check for main defined
    TreeNode *mainCheck = (TreeNode*)symbolTable.lookup("main");
    if(mainCheck == NULL){
        printError(15, 0, 0, NULL, NULL, NULL, 0);
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
            for(int i = 0; i < MAXCHILDREN; i++){
                analyze(t->child[i], nErrors, nWarnings);
            }
            //declared = NULL; //reset declared
  
            break;

        //next case, check VarK, starting by looping through children
        case VarK:
            for(int i = 0; i < MAXCHILDREN; i++){
                analyze(t->child[i], nErrors, nWarnings);
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
                    //printError(17, t->linenum, 0, t->attr.name, NULL, NULL, 0);
                }
            }

            check for initialization  -- doing nothing
            if(declared->expType != t->expType){
              printError(17, t->linenum, 0, t->attr.name, NULL, NULL, 0);
            }*/

           //check for duplicate declarations
           if(!symbolTable.insert(t->attr.name, t)){
               TreeNode* exists = (TreeNode*)symbolTable.lookup(t->attr.name);
               printError(0, t->linenum, exists->linenum, t->attr.name, NULL, NULL, 0);
           }

           break;

        case FuncK:
            //set t to current function variable
            curFunc = t;

            //Enter a scope for function arguments and compund section
            symbolTable.enter(t->attr.name);

            //might need this to avoid second enter() call with upcoming compound flags
            enterScope = false;
            functionReturnType = t->expType;

            //loop though function parameters and statements
            for(int i = 0; i < MAXCHILDREN; i++){
                if(t->child[i] != NULL){
                    analyze(t->child[i], nErrors, nWarnings);
                }
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
/*
    //variables to track child errors and array status
    bool c0err, c1err, c2err, c0isArr, c1isArr, c2isArr;
    c0err = c1err = c2err = false;
    c0isArr = c1isArr = c2isArr = false;

    //Keep track of if we are in a loop or not for error checking
    // before analyzing children nodes

    if(t->subkind.stmt == WhileK || t->subkind.stmt == ForK || t->subkind.stmt == IfK){
        
        if(!inLoop){
            loopDepth = symbolTable.depth();
            inLoop = true;
        }
    }

    if(t->subkind.stmt != CompoundK){
        //symbolTable.enter(t->attr.name);
        for(int i = 0; i < MAXCHILDREN; i++){
            analyze(t->child[i], nErrors, nWarnings);
            if(t->child[i] != NULL && t->child[i]->isArray == true){
                if(i = 0){
                    c0isArr = true;
                }
                if(i = 1){
                    c1isArr = true;
                }
                if(i = 2){
                    c2isArr = true;
                }
            }
        }
    }

    TreeNode* child0 = t->child[0];
    TreeNode* child1 = t->child[1];
    TreeNode* child2 = t->child[2];

    if(child0 != NULL && child0->child[0] != NULL) c0isArr = false;
    if(child1 != NULL && child1->child[0] != NULL) c1isArr = false;
    if(child2 != NULL && child2->child[0] != NULL) c2isArr = false;
    */

    switch(t->subkind.stmt){
        case IfK:
            inLoop = true;
            symbolTable.enter(t->attr.name);
            for(int i = 0; i < MAXCHILDREN; i++){
                if(t->child[0]){
                analyze(t->child[i], nErrors, nWarnings);
                }
            }
            inLoop = false;
            symbolTable.leave();
            break;

        case WhileK:
            inLoop = true;
            symbolTable.enter(t->attr.name);
            for(int i = 0; i < MAXCHILDREN; i++){
                if(t->child[i]){
                analyze(t->child[i], nErrors, nWarnings);
                }
            }
            if(loopDepth == symbolTable.depth()){
                inLoop = false;
                symbolTable.leave();
            }
            break;

        case ForK:
            inLoop = true;
            symbolTable.enter(t->attr.name);
            for(int i = 0; i < MAXCHILDREN; i++){
                if(t->child[i]){
                analyze(t->child[i], nErrors, nWarnings);
                }
            }
            if(loopDepth == symbolTable.depth()){
                inLoop = false;
                symbolTable.leave();
            }
            break;

        case ReturnK:
            analyze(t->child[0], nErrors, nWarnings);
            if(t->child[0] != NULL){
                if(curFunc == NULL){
                    break;
                }
                else{
                    if(t->isArray){
                        //cannot return array error
                        printError(9, t->linenum, 0, NULL, NULL, NULL, 0);
                    }
                }
            }
            break;

        case BreakK:
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
                symbolTable.leave();
            }

            break;
    }

}

void checkExp(TreeNode *t, int& nErrors, int& nWarnings){
    //set up multiple bool flags for checking different array error conditions and initialize all to false
    bool leftStr, rightStr, isBinary, leftArr, rightArr, leftIndx, rightIndx, throwError;
    leftStr = rightStr = isBinary = leftArr = rightArr = leftIndx = rightIndx = throwError = false;

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
                    leftIndx = true; //redundancy for indexing nonarrays
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
                    rightIndx = true; //redundancy for indexing nonarrays
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

            //start checking left side and right side for array errors
            if(!isBinary && !leftErr){
                //Error: Unary '%s' requires an operand of %s but was given %s
                if(leftSide != leftExpected && leftExpected != UndefinedType){

                    //check for Unary '-' to convert to chsign
                    if(!strcmp(t->attr.name, "-")){
                        char uMinus[] = "chsign";
                        printError(8, t->linenum, 0, uMinus, conExpType(leftExpected), conExpType(leftSide), 0);
                    }
                    //check for sizeof unary
                    else if(!strcmp(t->attr.name, "*") && (!leftArr && leftSide != UndefinedType)){
                        char uSizeof[] = "sizeof";
                        printError(7, t->linenum, 0, uSizeof, NULL, NULL, 0);
                    }
                    else if(!strcmp(t->attr.name, "*") && leftArr){
                        ; //do noting * operating is being used correctly on array
                    }
                    else{
                        printError(8, t->linenum, 0, t->attr.name, conExpType(leftExpected), conExpType(leftSide), 0);
                    }
                }
                //check for Unary 'not' -- not working from getExpTypes? 
                //this does catch it though
                else if(!strcmp(t->attr.name, "not")){
                    leftExpected = Boolean;
                    printError(8, t->linenum, 0, t->attr.name, conExpType(leftExpected), conExpType(leftSide), 0);
                }

                //Error: Does not work with Array and Only works with Array
                if(leftArr){
                    if(strcmp(t->attr.name, "*") != 0){
                        printError(6, t->linenum, 0, t->attr.name, NULL, NULL, 0);
                    }
                    /*else if(strcmp(t->attr.name, "*") == 0){
                        char uSizeof[] = "sizeof";
                        printError(7, t->linenum, 0, uSizeof, NULL, NULL, 0);
                        ;
                    }*/
                }
            }
                else{
                    //Error: expected matching types on both sides
                    if(!unaryErrors){

                        //[ on arrays is being caughter here and printing out
                        if(!strcmp(t->attr.name, "[")){
                            //put logic into a function
                            arrayErrors(t);
                        }
                
                        //'and' and 'or' are currently erroring here*** - fixed
                        else if(leftSide != rightSide && !leftErr && !rightErr){
                            printError(2, t->linenum, 0, t->attr.name, conExpType(leftSide), conExpType(rightSide), 0);
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
                            //right error
                            if(rightSide != rightExpected && !rightErr){
                                printError(4, t->linenum, 0, t->attr.name, conExpType(rightExpected), conExpType(rightSide), 0);
                            }
                        }
                    }

                    //check Array errors
                    if(leftArr || rightArr){
                        //Error: does not work with Arrays
                        if(leftExpected != UndefinedType){
                            if(!strcmp(t->attr.name, "<") || !strcmp(t->attr.name, ">") || !strcmp(t->attr.name, "=") || !strcmp(t->attr.name, ">=") || !strcmp(t->attr.name, "<=") || !strcmp(t->attr.name, "><")){
                                ; //do nothing, these operators can be used with arrays
                            }
                            else{
                            printError(6, t->linenum, 0, t->attr.name, NULL, NULL, 0);
                            }
                        }
                        else{
                            //Error: requires both sides to be an array
                            // [ for arrays is also being caught here and printing out
                            //now prints out blank line
                            if(!strcmp(t->attr.name, "[")){
                                ;
                            }
                            //error requires both operands be arrays or not but lhs is type %s an array and rhs is type %s an array.
                            else if((leftArr && !rightArr) || (!leftArr && rightArr)){
                                printError(5, t->linenum, 0, t->attr.name, NULL, NULL, 0);
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
                printError(1, t->linenum, 0, t->attr.name, NULL, NULL, 0);                
            }
            else{
                t->expType = valFound->expType;
                t->isArray = valFound->isArray;
                t->isGlobal = valFound->isGlobal;
                t->isStatic = valFound->isStatic;

                //Error: cannot use function as variable
                if(valFound->subkind.decl == FuncK){
                    printError(11, t->linenum, 0, t->attr.name, NULL, NULL, 0);
                    break;
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
                            printError(13, t->linenum, 0, t->attr.name, conExpType(t->child[0]->expType), NULL, 0);
                        }
                        //Error: array index is the unindexed array...
                        if(t->child[0]->isArray && t->child[0]->child[0] == NULL){
                            printError(12, t->linenum, 0, t->child[0]->attr.name, NULL, NULL, 0);
                        }
                    }
                }
            }
            break;

        case CallK:
            for(int i = 0; i < MAXCHILDREN; i++){
                analyze(t->child[i], nErrors, nWarnings);
            }

            //check for undeclared
            valFound = (TreeNode*)symbolTable.lookup(t->attr.name);
            if(valFound == NULL){
                printError(1, t->linenum, 0, t->attr.name, NULL, NULL, 0);   
            }

            else{
                t->expType = valFound->expType;
                t->isArray = valFound->isArray;
                t->isGlobal = valFound->isGlobal;
                t->isStatic = valFound->isStatic;
            }

            //Error: is a simple variable and cannot be used as a call
            if(valFound->subkind.decl != FuncK){
                printError(10, t->linenum, 0, t->attr.name, NULL, NULL, 0);
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
    else{
        for(int i = 0; i < 18; i++){
            if(op == binaryOps[i]){
                if(i >= 0 && i <= 8){
                    left = right = rightT = Integer;
                    unaryErrors = true;
                }
                //Doesn't work with arrays error
                if(i >= 9 && i <= 12){
                    left = right = Char; 
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
void printError(int errCode, int linenum, int explaineno, char* s1, char* s2, char* s3, double d){

    if(errCode > 15){
        nWarnings++;
    }
    else{
        nErrors++;
    }

    //print error depending on error code 0 - 17
    switch(errCode){

        //Declaration Errors
        case 0: 
            sprintf(sprintBuffer, "ERROR(%d): Symbol '%s' is already declared at line %d.\n", linenum, s1, explaineno);
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

        case 5: 
            sprintf(sprintBuffer, "ERROR(%d): '%s' requires both operands be arrays or not but lhs is type %s an array and rhs is type %s an array.\n", linenum, s1, s2, s3);
            break;

        case 6: 
            sprintf(sprintBuffer, "ERROR(%d): The operation '%s' does not work with arrays.\n", linenum, s1);
            break;

        case 7: 
            sprintf(sprintBuffer, "ERROR(%d): The operation '%s' only works with arrays.\n", linenum, s1);
            break;

        case 8:
            sprintf(sprintBuffer, "ERROR(%d): Unary '%s' requires an operand of type %s but was given type %s.\n", linenum, s1, s2, s3);
            break;


        //Return Errors
        case 9: 
            sprintf(sprintBuffer, "ERROR(%d): Cannot return an array.\n", linenum);
            break;

        //Function Errors
        case 10: 
            sprintf(sprintBuffer, "ERROR(%d): '%s' is a simple variable and cannot be called.\n", linenum, s1);
            break;

        case 11:
            sprintf(sprintBuffer, "ERROR(%d): Cannot use function '%s' as a variable.\n", linenum, s1);
            break;

        //Array Index Errors
        case 12:
            sprintf(sprintBuffer, "ERROR(%d): Array index is the unindexed array '%s'.\n", linenum, s1);
            break;

        case 13: 
            sprintf(sprintBuffer, "ERROR(%d): Array '%s' should be indexed by type int but got type %s.\n", linenum, s1, s2);
            break;

        case 14: 
            sprintf(sprintBuffer, "ERROR(%d): Cannot index nonarray '%s'.\n", linenum, s1);
            break;

        // 'Main' Error
        case 15: 
            sprintf(sprintBuffer, "ERROR(LINKER): A function named 'main()' must be defined.\n");
            break;

        //Warnings -- initialized but not used, uninitialized
        case 16: 
            sprintf(sprintBuffer, "WARNING(%d): The variable '%s' seems not to be used.\n", linenum, s1);
            break;

        case 17:
            sprintf(sprintBuffer, "WARNING(%d): Variable '%s' may be uninitialized when used here.\n", linenum, s1);
            break;
    }

    //put the error message into the error vector!!!!
    symErrors e;
    e.linenum = linenum;
    e.errorMsg = strdup(sprintBuffer);
    errBuffer.push_back(e);
}

void arrayErrors(TreeNode *t)
{
   TreeNode *leftNode = NULL;
   TreeNode *rightNode = NULL;

   leftNode = t->child[0];
   rightNode = t->child[1];

   if(t->child[0]->subkind.exp == IdK)
   {
      leftNode = (TreeNode*)symbolTable.lookup(t->child[0]->attr.name);
      if(leftNode != NULL)
      {
         t->child[0]->expType = leftNode->expType;
         t->expType = leftNode->expType;
      }

      if(leftNode == NULL || !leftNode->isArray)
      {
         printError(14, t->linenum, 0, t->child[0]->attr.name, NULL, NULL, 0);
      }
   }
   else
   {
      printError(14, t->linenum, 0, t->child[0]->attr.name, NULL, NULL, 0);
   }
   if(t->child[1] != NULL)
   {
      if(t->child[1]->expType != Integer && t->child[1]->expType != UndefinedType)
      {
         printError(13, t->linenum, 0, t->child[0]->attr.name, conExpType(t->child[1]->expType), NULL, 0);
      }
   }
   if(t->child[1] != NULL && t->child[1]->subkind.exp == IdK)
   {
      if(rightNode != NULL && rightNode->isArray == true)
      {
         printError(12, t->linenum, 0, rightNode->attr.name, NULL, NULL, 0); //
      }
      if(rightNode != NULL)
      {
         t->child[1]->expType = rightNode->expType;
      }
   }

}
