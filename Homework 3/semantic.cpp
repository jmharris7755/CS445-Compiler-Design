#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantic.h"
#include "symbolTable.h"
#include "parser.tab.h"
#include "syntaxTree.h"

extern int numErrors, numWarnings;
extern SymbolTable symTab;
bool errors;
bool newScope = false;
bool returnFlag = false;
bool inRange = false;
int bug = 0;
int loopDepth = 0;
char *inScope;

void analyze(TreeNode *syntaxTree){
    
    TreeNode *tTree, *tTree2;
    bool fWhile = false;

    while(syntaxTree != NULL){

        if(syntaxTree->nodekind == DeclK){

            if(symTab.insert(syntaxTree->attr.name, (TreeNode*) syntaxTree) == 0){
                TreeNode *functionName = (TreeNode*)symTab.lookup(syntaxTree->attr.name);
                printf("ERROR(%d): Symbol '%s' is already declared at line %d.\n", syntaxTree->linenum, syntaxTree->attr.name, functionName->linenum);
                numErrors++;
            }

            switch(syntaxTree->subkind.decl){

                case VarK:
                
                    //may need != NULL
                    if(syntaxTree->child[0]){

                        analyze(syntaxTree->child[0]);
                    }
                    break;

                case FuncK:

                    tTree = symTab.lookup(syntaxTree->attr.name);
                    if(!tTree){

                        symTab.insert(syntaxTree->attr.name, (TreeNode*) syntaxTree);
                    }

                    symTab.enter(syntaxTree->attr.name);
                    newScope = true;
                    inScope = strdup(syntaxTree->attr.name);
                    returnFlag = false;
                    syntaxTree->isUsed = true;
                    analyze(syntaxTree->child[0]);
                    analyze(syntaxTree->child[1]);
                    symTab.leave();

                    break;

                case ParamK:

                    tTree = symTab.lookup(syntaxTree->attr.name);

                    if(syntaxTree->isArray){

                        if(!tTree){

                            symTab.insert(syntaxTree->attr.name, (TreeNode*) syntaxTree);
                        }
                    }
                    else{

                        symTab.insert(syntaxtree->attr.name, (TreeNode*) syntaxTree);
                    }
                    break;

                    default:
                        printf("Unknown Deck Line %d\n", syntaxTree->linenum)';'

            }
        }

        else if(syntaxTree->nodekind == StmtK){

            switch(syntaxTree->subkind.stmt){

                case NullK:
                break;

                case IfK:
                    newScope = true;
                    symTab.enter(syntaxTree->attr.name);
                    for(int i = 0; i < 3; i++){

                        if(syntaxTree->child[0]){

                            analyze(syntaxTree->child[i]);
                        }
                    }

                    //symTab.applyToAll(wasUsed);
                    newScope = false;
                    symTab.leave();
                    break;

                case WhileK:

                    loopDepth++;
                    newScope = true;

                    symTab.enter(syntaxTree->attr.name);

                    for(int i=0; i < 2; i++){
                        if(syntaxTree->child[i]){
                            analyze(syntaxTree->child[i]);
                        }
                    }

                    //symTab.applyToAll();

                    newScope = false;
                    loopDepth--;
                    symTab.leave();
                    break;

                case ForK:

                    loopDepth++;
                    newScope = true;

                    symTab.enter(syntaxTree->attr.name);

                    for(int i=0; i < 2; i++){
                        if(syntaxTree->child[i]){
                            analyze(syntaxTree->child[i]);
                        }
                    }

                    //symTab.applyToAll();

                    newScope = false;
                    loopDepth--;
                    symTab.leave();
                    break;

                case CompoundK:
                    //confused by this one
                    break;

                case ReturnK:

                    returnFlag = true;
                    
                    for(int i=0; i < 2; i++){
                        if(syntaxTree->child[i]){
                            analyze(syntaxTree->child[i]);
                        }
                    }

                    tTree2 = symTab.lookup(inScope);

                    if(syntaxTree->child[0] && syntaxTree->child[0]->nodekind == ExpK &&syntaxTree->child[0]->subkind.exp == IdK){

                        tTree = symTab.lookup(syntaxTree->child[0]->attr.name);

                        if(tTree && tTree->isArray){

                            printf("ERROR(%d): Cannot return an array.\n", syntaxTree->linenum);
                        }
                    }

                    if(syntaxTree->child[0] && syntaxTree->child[0]->subkind.exp == AssignK && syntaxTree->child[0]->child[0] && syntaxTree->child[0]->child[1] && syntaxTree->child[0]->child[0]->isArray == true){

                        printf("ERROR(%d): Cannot return an array.\n", syntaxTree->linenum);
                    }
                    break;

                case BreakK:
                break;

                case RangeK:
                    inRange = true;

                    for(int i=0; i < 2; i++){
                        if(syntaxTree->child[i]){
                            analyze(syntaxTree->child[i]);
                        }
                    }
                    break;


            }

        }

        else if(syntaxTree->nodekind == ExpK){

            switch(syntaxTree->subkind.exp){

                case OpK:
                    for(int i = 0; i < 3; i++){
                        //was syntaxTree... != NULL
                        if(syntaxTree->child[i]){
                            analyze(syntaxTree->child[i]);
                        }
                    }

                    //was syntaxTree != NULL
                    if(syntaxTree->child[1]){

                        checkBinaryOps(syntaxTree);
                    }
                    else{
                        checkUnaryOps(syntaxTree);
                    }
                    break;

                case ConstantK:
                    break;

                case IdK:
                    tTree = symTab.lookup(syntaxTree->attr.name);

                    //was tTree == NULL
                    if(!tTree){

                        printf("ERROR(%d): Symbol '%s' is not declared.\n", syntaxTree->linenum, syntaxTree->attr.name);
                        numErrors++;
                        syntaxTree->expType = UndefinedType;
                        err = true;
                    }
                    //was tTree != NULL
                    else if(tTree && (tTree->subkind.decl == VarK) || (tTree->subkind.decl == ParamK)){

                        //
                    }

                    //was tTree != NULL
                    else if(tTree && tTree->subkind.decl == FuncK){

                        syntaxTree->expType = UndefinedType;
                        printf("ERROR(%d): Cannot use function '%s' as a variable.\n", syntaxTree->linenum, syntaxTree->attr.name);
                        numErrors++;
                    }

                    else if( tTree){
                    
                    }
                    break;

                case AssignK:

                    for(int i=0; i < 3; i++){

                        //was syntaxTree->... != NULL
                        if(syntaxTree->child[0]){
                            analyze(syntaxTree->child[i]);
                        }
                    }

                    //was syntaxTree->... != NULL
                    if(syntaxTree->child[1]){
                        
                        checkUnaryAsgns(syntaxTree);
                    }
                    else{
                        checkBinaryAsgns(syntaxTree);
                    }

                    if(syntaxTree->child[0]->subkind.exp == IdK){
                        
                        tTree = symTab.lookup(syntaxTree->child[0]->attr.name);
                    }

                    //if current child exp == OpK and child of child exp == IdK, get name of childs child
                    if(syntaxTree->child[0]->subkind.exp == OpK && syntaxTree->child[0]->subkind.exp == IdK){

                        tTree = symTab.lookup(syntaxTree->child[0]->child[0]->attr.name);
                    }
                    //was tTree != NULL
                    if(tTree){
                        syntaxTree->expType = syntaxTree->child[0]->expType;
                    }

                    case InitK:
                    break;

                    case CallK:

                    for(int i=0; i < 3; i++){

                        analyze(syntaxTree->child[i]);
                    }

                    tTree = symTab.lookup(syntaxTree->attr.name);

                    if(tTree->subkind.decl == VarK || tTree->subkind.decl == ParamK){

                        printf("ERROR(%d): '%s' is a simple variable and cannot be called.\n", syntaxTree->linenum, syntaxTree->attr.name);
                        numErrors++;
                    }
                    else{
                        printf("ERROR(%d): Symbol '%s' is not declared.\n", syntaxTree->linenum, syntaxTree->attr.name);
                        numErrors++;
                    }

                    default:
                    break;


            }
        }

    }
}

void erChkUOP(TreeNode *syntaxTree){

    //left child to check against
    TreeNode *leftChild, tTree;

    //check leftChild, if not null assign
    if(syntaxTree->child[0]){
        leftChild = syntaxTree->child[0];
    }

    //check for unary '-' (chsign)
    if(!strcmp(syntaxTree->attr.name, "-")){

        //check on IdK expType
        if(leftChild->subkind.exp == IdK){

            tTree = symTab.lookup(leftChild->attr.name);
            if(tTree && tTree->expType != Integer){

                printUError(syntaxTree, (char *) "int");
            }
        }

        //check on ConstantK expType
        else if(leftChild->subkind.exp == ConstantK){

            if(leftChild->child[0] && leftChild->child[0]->subkind.exp != ConstantK){
                printUError(syntaxTree, (char *) "int");
            }
            else if(leftChild->expType != Integer){
                printUError(syntaxTree, (char *) "int");
            }
        }
        notArrays(syntaxTree);
    }

    //check * unary operator (sizeof)
    else if(!strcmp(syntaxTree->attr.name, "*")){

        syntaxTree->expType = Integer;

        if(leftChild->isArray != true){

            if(leftChild->expType != UndefinedType){

                printf("ERROR(%d): The operation 'sizeof' only works with arrays.\n", tree->lineno);
                numErrors++;
            }
        }
    }

    //Check for "not" 
    else if(!strcmp(syntaxTree->attr.name, "not")){

        if(leftChild->subkind.exp == ConstantK && syntaxTree->exp != leftChild->expType){

            if(leftChild->child[0] && leftChild->child[0]->subkind.exp != ConstantK){
                printUError(syntaxTree, (char*) "bool");
            }
            else if(leftChild->expType != Boolean){
                printUError(syntaxTree, (char*) "bool");
            }
        }

        //check exp IdK
        if(leftChild->subkind.exp == IdK){

            tTree = symTab.lookup(leftChild->attr.name);
            if(tTree && tTree->expType != Boolean){
                printUError(syntaxTree, (char*) "bool");
            }
        }

        if(leftChild->child[0]){

            if(leftChild->child[0]->expType != Boolean && leftChild->child[0]->subkind.exp != OpK && syntaxTree->expType != leftChild->expType){

                printUError(syntaxTree, (char*) "bool");
            }
        }
        notArrays(syntaxTree);
    }

    else if(!strcmp(syntaxTree->attr.name, "?")){

        if(leftChild->subkind.exp == IdK)
      {
         tTree = symTab.lookup(leftChild->attr.name);
         if(tTree != NULL && tTree->expType != Integer)
         {
            printUError(syntaxTree, (char *) "int");
         }
      }
      else if(leftChild->subkind.exp != IdK)
      {
         if(left->expType != Integer)
         {
            printUError(syntaxTree, (char *) "int");
         }
      }
      notArrays(syntaxTree);
    }
    else{
        notArrays(syntaxTree);
    }
}

void erChkUASGN(TreeNode *tree){

    //set left and temp treeNodes
    TreeNode *leftChild, tTree;
    
    //check leftChild, if not null assign
    if(syntaxTree->child[0]){
        leftChild = syntaxTree->child[0];
    }

    //check chsign
     if(!strcmp(syntaxTree->attr.name, "-"))
   {
      notArrays(syntaxTree);
      if(leftChild->expType != Integer && leftChild->expType != UndefinedType)
      {
         printUError(syntaxTree, (char *) "int");
      }
   }
   else if(!strcmp(syntaxTree->attr.name, "*"))
   {
      if(leftChild->isArray != true)
      {
         erChkUOP(syntaxTree);
      }
   }

   else if(!strcmp(syntaxTree->attr.name, "not"))
   {
      //printf("left->expType: %s right->expType %s LINE %i\n", convertExpTypeEnum(left->expType), convertExpTypeEnum(right->expType), tree->lineno);
      notArrays(tree);
      if(leftChild->expType != Boolean && leftChild->expType != UndefinedType /*&& left->expType != right->expType*/)
      {
         //printf("HERE\n");
         printUError(syntaxTree, (char *) "bool");
      }
      /*if(left->expType == Boolean && right->expType != Boolean)
      {
         unaryError(tree, (char *) "bool");
      }*/
   }
   else if(!strcmp(syntaxTree->attr.name, "?"))
   {
      notArrays(tree);
      if(left->expType != Integer && leftChild->expType != UndefinedType)
      {
         printUError(syntaxTree, (char *) "int");
      }
   }
 
   else if(!strcmp(syntaxTree->attr.name, "++") || !strcmp(syntaxTree->attr.name, "--"))
   {
      notArrays(tree);
      if(leftChild->expType != Integer && leftChild->expType != UndefinedType)
      {
         printUError(syntaxTree, (char *) "int");
      }
   }
}

void erChkBOP(TreeNode *syntaxTree){

    TreeNode *leftChild, rightChild, tTree;

    if(syntaxTree->child[0]){
        leftChild = syntaxTree->child[0];
    }
    if(syntaxTree->child[1]){
        rightChild = syntaxTree->child[1];
    }

    if(!strcmp(syntaxTree->attr.name, "or") || !strcmp(syntaxTree->attr.name, "and")){

        if(leftChild->subkin.exp = CallK){


            if(leftChild->expType != Boolean && leftChild->expType != UndefinedType && leftChild->expType != Void ){

                printf("ERROR(%d): '%s' requires operans of bool but lhs is of type %s.\n", syntaxTree->linenum, syntaxTree->attr.name, printExpType(leftChild->expType));

            }
            if(rightChild->expType != Boolean && rightChild->expType != UndefinedType && rightChild->expType != Void ){

                printf("ERROR(%d): '%s' requires operans of bool but rhs is of type %s.\n", syntaxTree->linenum, syntaxTree->attr.name, printExpType(rightChild->expType));

            }
        }
        else{ //IdK

            if(leftChild->expType != Boolean && leftChild->expType != UndefinedType && leftChild->expType != Void)
            {
                printf("ERROR(%d): '%s' requires operands of bool but lhs is of type %s.\n", syntaxTree->linenum, syntaxTree->attr.name, printExpType(leftChild->expType));
                numErrors++;
            }
            if(rightChild->expType != Boolean && rightChild->expType != UndefinedType && rightChild->expType != Void)
            {
                printf("ERROR(%d): '%s' requires operands of bool but rhs is of type %s.\n", syntaxTree->lineno, syntaxTree->attr.name, printExpType(rightChild->expType));
                numErrors++;
            }
            if(leftChild->isArray == true || rightChild->isArray == true)
            {
                printf("ERROR(%d): The operation '%s' does not work with arrays.\n", syntaxTree->linenum, syntaxTree->attr.name);
                numErrors++;
            }

        }
    }

    else if(!strcmp(syntaxTree->attr.name, "<") || !strcmp(syntaxTree->attr.name, ">") || !strcmp(syntaxTree->attr.name, "=") || !strcmp(syntaxTree->attr.name, ">=") || !strcmp(syntaxTree->attr.name, "<=") || !strcmp(syntaxTree->attr.name, "><")){
              //if(tree->isErr == false)
      //{
         if(leftChild->expType != rightChild->expType && (leftChild->expType != UndefinedType && rightChild->expType != UndefinedType) && (leftChild->expType != Void && rightChild->expType != Void))
         {
            printf("ERROR(%d): '%s' requires operands of the same type but lhs is %s and rhs is %s.\n", syntaxTree->linenum, syntaxTree->attr.name, printExpType(leftChild->expType), printExpType(rightChild->expType));
            numErrors++;
         }
         if(leftChild->isArray == true && rightChild->isArray != true)
         {
            printf("ERROR(%d): '%s' requires both operands be arrays or not but lhs is an array and rhs is not an array.\n", syntaxTree->linenum, syntaxTree->attr.name);
            numErrors++;
         }
         if(leftChild->isArray != true && rightChild->isArray == true)
         {
            printf("ERROR(%d): '%s' requires both operands be arrays or not but lhs is not an array and rhs is an array.\n", syntaxTree->linenum, syntaxTree->attr.name);
            numErrors++;
         }    
      //}
    }

   else if(!strcmp(syntaxTree->attr.name, "+") || !strcmp(syntaxTree->attr.name, "-") || !strcmp(syntaxTree->attr.name, "*") || !strcmp(syntaxTree->attr.name, "/") || !strcmp(syntaxTree->attr.name, "%")){
      if(syntaxTree->isArray == false)
      {
         //printf("HERE LINE %i\n", tree->lineno);
         if(leftChild->expType != Integer && leftChild->expType != UndefinedType && leftChild->expType != Void)
         {
            printf("ERROR(%d): '%s' requires operands of int but lhs is of type %s.\n", syntaxTree->linenum, syntaxTree->attr.name, printExpType(leftChild->expType));
            numErrors++;
         }
         if(rightChild->expType != Integer && rightChild->expType != UndefinedType && rightChild->expType != Void)
         {
            printf("ERROR(%d): '%s' requires operands of int but rhs is of type %s.\n", syntaxTree->linenum, syntaxTree->attr.name, printExpType(rightChild->expType));
            numErrors++;
         }
      }

      if(leftChild->subkind.exp == CallK && rightChild->subkind.exp == CallK)
      {
         if(leftChild->expType != Integer && leftChild->expType != UndefinedType)
         {
            printf("ERROR(%d): '%s' requires operands of int but lhs is of type %s.\n", syntaxTree->linenum, syntaxTree->attr.name, printExpType(leftChild->expType));
            numErrors++;
         }
         if(rightChild->expType != Integer && rightChild->expType != UndefinedType)
         {
            printf("ERROR(%d): '%s' requires operands of type int but rhs is of type %s.\n", syntaxTree->lineno, syntaxTree->attr.name, printExpType(rightChild->expType));
            numErrors++;
         }
      }
      notArrays(tree);

   }
   else if(!strcmp(syntaxTree->attr.name, "["))
   {
      syntaxTree->expType = leftChild->expType;
      //printf("squarebracket %s %d %s left %s %d %s\n", tree->attr.name, tree->lineno, convertExpTypeEnum(tree->expType), left->attr.name, left->lineno, convertExpTypeEnum(left->expType));
      checkArrays(syntaxTree);
   }
}

void erChkBASGN(TreeNode *syntaxTree)
{
   TreeNode *leftChild, *rightChild, *tTree;
   if(syntaxTree->child[0]){
      leftChild = tree->child[0];
   }

   if(syntaxTree->child[1]){
      rightChild = tree->child[1];
   }
   
   if(!strcmp(syntaxTree->attr.name, "+=") || !strcmp(syntaxTree->attr.name, "-=") || !strcmp(syntaxTree->attr.name, "*=") || !strcmp(syntaxTree->attr.name, "/="))
   {
      //printf("left->expType: %s LINE %i\n", convertExpTypeEnum(left->expType), tree->lineno);
      //printf("right->expType: %s LINE %i\n", convertExpTypeEnum(right->expType), tree->lineno);
      if(leftChild->expType != Integer && leftChild->expType != UndefinedType)
      {
         //printf("HERE LINE %i\n", tree->lineno);
         printf("ERROR(%d): '%s' requires operands of int but lhs is of type %s.\n", syntaxTree->linenum, syntaxTree->attr.name, printExpType(leftChild->expType));
         numErrors++;
      }
      if(rightChild->expType != Integer && rightChild->expType != UndefinedType)
      {
         printf("ERROR(%d): '%s' requires operands of int but rhs is of type %s.\n", syntaxTree->linenum, syntaxTree->attr.name, printExpType(rightChild->expType));
         numErrors++;
      }
   }
   else if(!strcmp(syntaxTree->attr.name, ":="))
   {
      if(syntaxTree->subkind.decl == ParamK)
      {
         if(leftChild->expType != rightChild->expType && (leftChild->expType != UndefinedType && rightChild->expType != UndefinedType))
         {
            printf("ERROR(%d): '%s' requires operands of the same type but lhs is %s and rhs is %s.\n", syntaxTree->linenum, syntaxTree->attr.name, printExpType(leftChild->expType), printExpType(rightChild->expType));
            numErrors++;
         }
      }
      if(leftChild->subkind.exp == IdK)
      {
         syntaxTree->expType = leftChild->expType;
         if(leftChild->expType != rightChild->expType && (leftChild->expType != UndefinedType && rightChild->expType != UndefinedType))
         {
            printf("ERROR(%d): '%s' requires operands of the same type but lhs is %s and rhs is %s.\n", syntaxTree->linenum, syntaxTree->attr.name, printExpType(leftChild->expType), printExpType(right->expType));
            numErrors++;
         }

         tTree = symTab.lookup(leftChild->attr.name);
         //if(tTree != NULL)
            //tTree->isInit = true;
         
         //leftChild->isInit = true;
         syntaxTree->expType = leftChild->expType;
      }
      if(leftChild->isArray == true && rightChild->isArray != true)
      {
         printf("ERROR(%d): '%s' requires both operands be arrays or not but lhs is an array and rhs is not an array.\n", syntaxTree->linenum, syntaxTree->attr.name);
         numErrors++;
      }
      if(leftChild->isArray != true && rightChild->isArray == true)
      {
         printf("ERROR(%d): '%s' requires both operands be arrays or not but lhs is not an array and rhs is an array.\n", syntaxTree->linenum, syntaxTree->attr.name);
         numErrors++;
      }
      if(leftChild->subkind.exp != IdK && (leftChild->expType != rightChild->expType) && (leftChild->expType != UndefinedType && rightChild->expType != UndefinedType))
      {
         printf("ERROR(%d): '%s' requires operands of the same type but lhs is type %s and rhs is type %s.\n", syntaxTree->linenum, syntaxTree->attr.name, printExpType(leftChild->expType), printExpType(rightChild->expType));
         numErrors++;
      }
   }
   else
   {
      printf("NOT IN BINARY ASGNS\n");
   }
}

const char* printExpType(ExpType exp){

    switch(exp){

        case 0:
            return("void");
            break;

        case 1:
            return("int");
            break;

        case 2:
            return("bool");
            break;

        case 3:
            return("char");
            break;

        case 4:
            return("char");
            break;

        case 5:
            return("equal");
            break;

        case 6:
            return("undefined type");
            break;

        default:
            break;
    }
}

void printUError(TreeNode *syntaxTree, char* expected){

    TreeNode *leftChild;
   if(syntaxTree->child[0]){
      leftChild = syntaxTree->child[0];
   }

   if(!strcmp(syntaxTree->attr.name, "-")){

      printf("ERROR(%d): Unary 'chsign' requires an operand of %s but was given type %s\n", syntaxTree->linenum, expected, printExpType(leftChild->expType));
      numErrors++;
   }
   else{

      printf("ERROR(%d): Unary %s requires an operand of %s but was given type %s\n", syntaxTree->linenum, syntaxTree->attr.name, expected, printExpType(leftChild->expType));
      numErrors++;

   }
}

