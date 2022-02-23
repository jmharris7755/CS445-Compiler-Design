//Justin Harris 
//CS445
//Last Updated: 2-11-22
//syntaxTree.c
//File containing function logic from syntaxTree.h
//builds the AST

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
      printf(".   ");
  }  
}

void printExp(ExpType t){

    switch(t){

        case Void:
            printf("void");
            break;

        case Integer:
            printf("int");
            break;
        
        case Boolean:
            printf("bool");
            break;

        case Char:
            printf("char");
            break;

        case CharInt:
            printf("CharInt");
            break;

        case Equal:
            printf("Equal");
            break;

        case UndefinedType:
            printf("undefined type");
            break;

        default:
            printf("exprType not found\n");
            break;
    }
}

void printTree(TreeNode *t, int siblingCounter, bool w_typing){
    int i;
    int thisSibling = siblingCounter;
    bool TYPES = w_typing;

    if(t==NULL){
        printf("Unable to print tree\n");
    }
    while(t != NULL){
            
        //Check in order declared in syntaxTree.h
        if(t->nodekind == DeclK){

            switch(t->subkind.decl){

                case VarK:
                    if(t->isArray == true){
                        printf("Var: %s of array of type ", t->attr.name);
                        printExp(t->expType);
                        printf(" [line: %d]\n", t->linenum);
                    }
                    else if(t->isStatic == true){
                        printf("Var: %s of static type ", t->attr.name);
                        printExp(t->expType);
                        printf(" [line: %d]\n", t->linenum);
                    }
                    else{
                        printf("Var: %s of type ", t->attr.name);
                        printExp(t->expType);
                        printf(" [line: %d]\n", t->linenum);
                    }
                    break;

                case FuncK:
                    printf("Func: %s returns type ", t->attr.name);
                    printExp(t->expType);
                        printf(" [line: %d]\n", t->linenum);
                    break;

                case ParamK:
                    if(t->isArray){
                        printf("Parm: %s of array of type ", t->attr.name);
                        printExp(t->expType);
                        printf(" [line: %d]\n", t->linenum);
                    }
                    else{
                        printf("Parm: %s of type ", t->attr.name);
                        printExp(t->expType);
                        printf(" [line: %d]\n", t->linenum);
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
                    printf("While [line: %d]\n", t->linenum);
                break;

                case ForK:
                    printf("For [line: %d]\n", t->linenum);
                break;

                case CompoundK:
                    printf("Compound [line: %d]\n", t->linenum);
                break;

                case ReturnK:
                    printf("Return [line: %d]\n", t->linenum);
                break;

                case BreakK:
                    printf("Break [line: %d]\n", t->linenum);
                break;

                case RangeK:
                    printf("Range [line: %d]\n", t->linenum);
                break;

                default:
                break;
            }
        }

        else if(t->nodekind == ExpK){

            switch(t->subkind.exp){
                
                case OpK:

                if(t->child[1] == NULL && !strcmp(t->attr.name, "-")){
                    
                    printf("Op: chsign");
                    if(t->expType == UndefinedType){
                        //if 'P' option
                        if(TYPES){
                            printf(" of undefined type");
                        }
                    }
                    else
                    {
                        //if 'P' option
                        if(TYPES){
                            printf(" of type ");
                            printExp(t->expType);
                        }
                    }
                    printf(" [line: %d]\n", t->linenum);
                    
                }

                else if(t->child[1] == NULL && !strcmp(t->attr.name, "*")){
                    printf("Op: sizeof");
                    if(t->expType == UndefinedType){
                        //if 'P' option
                        if(TYPES){
                            printf(" of undefined type");
                        }
                    }
                    else
                    {
                        //if 'P' option
                        if(TYPES){
                            printf(" of type ");
                            printExp(t->expType);
                        }
                    }
                    printf(" [line: %d]\n", t->linenum);
                }

                else{
                    printf("Op: %s", t->attr.name);
                    if(t->expType == UndefinedType){
                        //if 'P' option
                        if(TYPES){
                            printf(" of undefined type");
                        }
                    }
                    else
                    {
                        //if 'P' option
                        if(TYPES){
                            printf(" of type ");
                            printExp(t->expType);
                        }
                    }
                    printf(" [line: %d]\n", t->linenum);
                }
                break;

                case ConstantK:
                if(t->expType == Boolean){
                    printf("Const %s ", t->attr.name);

                    //if 'P' option
                    if(TYPES){
                        printf(" of type bool");
                    }

                    printf(" [line: %d]\n", t->linenum);
                }

                else if(t->expType == CharInt){
                    printf("Const \"");
                    printf("%s\"", t->attr.name);

                    //if 'P' option
                    if(TYPES){
                        printf(" of type char");
                    }

                    printf(" [line: %d]\n", t->linenum);
                }

                else if(t->expType == Char){
                    printf("Const \'%c\'", t->thisTokenData->cvalue);

                    //if 'P' option
                    if(TYPES){
                        printf(" of type char");
                    }

                    printf(" [line: %d]\n", t->linenum);
                }

                else{
                    printf("Const %d", t->attr.value);

                    //if 'P' option
                    if(TYPES){
                        printf(" of type int");
                    }

                    printf(" [line: %d]\n", t->linenum);
                }
                break;

                case IdK:
                    printf("Id: %s", t->attr.name);

                    //if 'P' option
                    if(TYPES){
                        printf(" of type ");
                        printExp(t->expType);
                    }

                    printf(" [line: %d]\n", t->linenum);
                break;

                case AssignK:
                    printf("Assign: %s", t->attr.name);
                    
                    //if 'P' option
                    if(TYPES){
                        printf(" of type ");
                        printExp(t->expType);
                    }

                    printf(" [line: %d]\n", t->linenum);
                break;

                case InitK:
                    //printf("Init: [line: %d]\n", t->linenum);
                break;

                case CallK:
                     printf("Call: %s", t->attr.name);
                    
                    //if 'P' option
                    if(TYPES){
                        printf(" of type ");
                        printExp(t->expType);
                    }

                    printf(" [line: %d]\n", t->linenum);
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
                printf("Child: %d  ", i);
                printTree(t->child[i], 0, TYPES);
                blankSpaces--;
            }
        }

        if(t->sibling != NULL){
            thisSibling++;
            printSpaces(blankSpaces);
            printf("Sibling: %d  ", thisSibling);
        }
        t = t->sibling;
    }

}