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
                            analyze(tree->child[i]);
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

                        analyze(tree->child[i]);
                    }

                    tTree = symTab.lookup(tree->attr.name);

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