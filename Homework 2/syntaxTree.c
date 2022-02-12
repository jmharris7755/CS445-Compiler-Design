#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "scanType.h"
#include "syntaxTree.h"
#include "parser.tab.h"

int blankSpaces = 0;

TreeNode *newDeclNode(DeclKind kind, TokenData *tokenData){
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if(t == NULL){
        printf("Out of memory error at line %d\n", tokenData->linenum);
    }

    else{
        for(i = 0; i<MAXCHILDREN; i++){
            t->child[i] = NULL;
            t->sibling = NULL;
            t->nodekind = DeclK;
            t->subkind.decl = kind;
            t->attr.name = strdup(tokenData->tokenStrInput);
            t->linenum = tokenData->linenum;
            t->expType = Void;
        }
    }
    return t;
}

TreeNode *newStmtNode(StmtKind kind, TokenData *tokenData){
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if(t == NULL){
        printf("Out of memory error at line %d\n", tokenData->linenum);
    }

    else{
        for(i = 0; i<MAXCHILDREN; i++){
            t->child[i] = NULL;
            t->sibling = NULL;
            t->nodekind = StmtK;
            t->subkind.stmt = kind;
            t->attr.name = strdup(tokenData->tokenStrInput);
            t->linenum = tokenData->linenum;
            t->expType = Void;
        }
    }
    return t;
}

TreeNode *newExpNode(ExpKind kind, TokenData *tokenData){
    TreeNode *t = (TreeNode *)malloc(sizeof(TreeNode));
    int i;
    if(t == NULL){
        printf("Out of memory error at line %d\n", tokenData->linenum);
    }

    else{
        for(i = 0; i<MAXCHILDREN; i++){
            t->child[i] = NULL;
            t->sibling = NULL;
            t->nodekind = ExpK;
            t->subkind.exp = kind;
            t->linenum = tokenData->linenum;
            t->expType = Void;
        }
    }
    return t;
}

//convert node to sibling and all sibling nodes to same type
void convertSiblingType(TreeNode *t, ExpType currentExp){
    TreeNode *curNode = t;

    while(curNode != NULL){
        curNode->expType = currentExp;
        curNode = curNode->sibling;
    }
}

TreeNode *addaSibling(TreeNode *t, TreeNode *s){
    if(t==NULL){
        return s;
    }
    if(s==NULL){
        return t;
    }
    if(s!=NULL && t!=NULL){
        TreeNode *newT = (TreeNode *)malloc(sizeof(TreeNode));
        newT = t;
    

        while(newT !=NULL && newT->sibling !=NULL){
            newT = newT->sibling;
        }
        newT->sibling = s;
    }
    return t;
}

//function to print whitespaces
void printSpaces(int whiteSpaces){
  int i = 0;
  for(i=0; i < whiteSpaces; i++){
      printf(". ");
  }  
}

void printTree(TreeNode *t, int siblingCounter){
    int i;
    int thisSibling = siblingCounter;

    if(t==NULL){
        printf("Unable to print tree\n");
    }
    while(t != NULL){

            //convert exp type to proper print out and save for later
            char *convertExpType = NULL;

            if(t->expType == Void){
                //*convertExpType = "";
                strcpy(convertExpType, "void");
            }
            else if(t->expType == Integer){
                //convertExpType = "";
                strcpy(convertExpType, "int");
            }
            else if(t->expType == Boolean){
                //convertExpType = "";
                strcpy(convertExpType, "bool");
            }
            else if (t->expType == Char){
                //convertExpType = "";
                strcpy(convertExpType, "char");
            }
            else if(t->expType == CharInt){
                //convertExpType = "";
                strcpy(convertExpType, "CharInt");
            }
            else if(t->expType == Equal){
                //convertExpType = "";
                strcpy(convertExpType, "Equal");
            }
            else if(t->expType == UndefinedType){
                //convertExpType = "";
                strcpy(convertExpType, "undefined type");
            }
            else{
                //convertExpType = "";
                strcpy(convertExpType, "exprType not found\n");
            }
            
        //Check in order declared in syntaxTree.h
        if(t->nodekind == DeclK){

            switch(t->subkind.decl){

                case VarK:
                    if(t->isArray == true){
                        printf("Var: %s is array of type %s [line: %d]\n", t->thisTokenData->tokenStrInput, convertExpType, t->linenum);
                    }
                    else{
                        printf("Var: %s of type %s [line: %d]\n", t->attr.name, convertExpType, t->linenum);
                    }
                    break;

                case FuncK:
                    printf("Func: %s returns type %s, [line: %d]\n", t->attr.name, convertExpType, t->linenum);
                    break;

                case ParamK:
                    if(t->isArray){
                        printf("Parm: %s is array of type %s [line: %d]\n", t->attr.name, convertExpType, t->linenum);
                    }
                    else{
                        printf("Parm: %s of type %s [line: %d]\n", t->attr.name, convertExpType, t->linenum);
                    }
                    break;
                
                default:
                printf("Unknown Decl Kind Line:%d\n", t->linenum);
            }
        }

        else if(t->nodekind == StmtK){
            switch(t->subkind.stmt){
                
                case NullK:
                    printf("NULL [line: %d]\n", t->linenum);
                break;

                case IfK:
                    printf("If [line: %d]\n", t->linenum);
                break;

                case WhileK:
                    printf("NULL [line: %d]\n", t->linenum);
                break;

                case ForK:
                    printf("NULL [line: %d]\n", t->linenum);
                break;

                case CompoundK:
                    printf("NULL [line: %d]\n", t->linenum);
                break;

                case ReturnK:
                    printf("NULL [line: %d]\n", t->linenum);
                break;

                case BreakK:
                    printf("NULL [line: %d]\n", t->linenum);
                break;

                case RangeK:
                    printf("NULL [line: %d]\n", t->linenum);
                break;

                default:
                break;
            }
        }

        else if(t->nodekind == ExpK){

            switch(t->subkind.exp){
                
                case OpK:

                if(t->child[1] == NULL && !strcmp(t->attr.name, "-")){
                    
                    printf("Op: CHSIGN of type %s [line: %d]\n", convertExpType, t->linenum);
                    
                }

                else if(t->child[1] == NULL && !strcmp(t->attr.name, "*")){
                    printf("Op: sizeof of type %s [line: %d]\n", convertExpType, t->linenum);
                }

                else{
                    printf("Op: %s of type %s [line: %d]\n", t->attr.name, convertExpType, t->linenum);
                }
                break;

                case ConstantK:
                if(!strcmp(convertExpType, "bool")){
                    printf("Const %s [line: %d]\n", t->attr.name, t->linenum);
                }

                else if(!strcmp(convertExpType, "CharInt")){
                    printf("Const is array \"");
                    printf("%s [line: %d]\n", t->attr.name, t->linenum);
                }

                else if(!strcmp(convertExpType, "Char")){
                    printf("Const \'%c\' of type char [line: %d]\n", t->thisTokenData->cvalue, t->linenum);
                }

                else{
                    printf("Const %d  [line: %d]\n", t->attr.value, t->linenum);
                }
                break;

                case IdK:
                    printf("Id: %s [line: %d\n", t->attr.name, t->linenum);
                break;

                case AssignK:
                    printf("Assign %s [line: %d]\n", t->attr.name, t->linenum);

                case InitK:
                    printf("Init: [line: %d]\n", t->linenum);
                break;

                case CallK:
                    printf("Call: %s [line: %d]\n", t->attr.name, t->linenum);
                break;

                default:
                    printf("ERROR %i ", CallK);
                    printf("Unknown ExpNode subkind Line: %d\n", t->linenum);
                break;
            }
        }

        else{
            printf("Unknown node type: %d Line: %d\n", t->nodekind, t->linenum);
        }
        //Continue from here
        for(i=0; i< MAXCHILDREN; i++){
            if(t->child[i] != NULL){
                blankSpaces++;
                printSpaces(blankSpaces);
                printf("Child: %d ", i);
                printTree(t->child[i], 0);
                blankSpaces--;
            }
        }

        if(t->sibling != NULL){
            thisSibling++;
            printSpaces(blankSpaces);
            printf("Sibling: %d ", thisSibling);
        }
        t = t->sibling;
    }

}