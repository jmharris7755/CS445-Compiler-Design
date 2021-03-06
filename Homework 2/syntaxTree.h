//Justin Harris 
//CS445
//Last Updated: 2-11-22
//syntaxTree.h
//File containing types and function defs for building AST

#ifndef _SYNTAXTREE_H_
#define _SYNTAXTREE_H_

#include "scanType.h"
#include <stdbool.h>


#define MAXCHILDREN 3

//Kinds of operators
//these are the token numbers for the operators same as in flex
typedef int OpKind;

//Kinds of statements
typedef enum {DeclK, StmtK, ExpK} NodeKind;

//Subkinds of Declarations
typedef enum {VarK, FuncK, ParamK} DeclKind;

// Subkinds of Statements
typedef enum {NullK, IfK, WhileK, ForK, CompoundK, ReturnK, BreakK, RangeK} StmtKind;

//Subkinds of Expressions
typedef enum {OpK, ConstantK, IdK, AssignK, InitK, CallK} ExpKind;

//ExpType is used for type checking (Void means no type or value,
//UndefinedType means undefined)
typedef enum {Void, Integer, Boolean, Char, CharInt, Equal, UndefinedType} ExpType;

//What kind of scoping is used? (decided during typing)
typedef enum {None, Local, Global, Parameter, LocalStatic} VarKind;

typedef struct treeNode
{
    // connectivity in the tree
    struct treeNode *child[MAXCHILDREN]; // children of the node
    struct treeNode *sibling; // siblings for the node

    // what kind of node
    int linenum; // linenum relevant to this node
    NodeKind nodekind; // type of this node
    TokenData *thisTokenData;

    union // subtype of type
    {
        DeclKind decl; // used when DeclK
        StmtKind stmt; // used when StmtK
        ExpKind exp; // used when ExpK
    } subkind;

    // extra properties about the node depending on type of the node
    union // relevant data to type -> attr
    {
        OpKind op; // type of token (same as in bison)
        int value; // used when an integer constant or boolean
        unsigned char cvalue; // used when a character
        char *string; // used when a string constant
        char *name; // used when IdK
    } attr;

    ExpType expType; // used when ExpK for type checking
    bool isArray; // is this an array
    bool isStatic; // is staticly allocated?
    // even more semantic stuff will go here in later assignments.
} TreeNode;

TreeNode *newDeclNode(DeclKind kind, TokenData *tokenData);

TreeNode *newStmtNode(StmtKind kind, TokenData *tokenData);

TreeNode *newExpNode(ExpKind kind, TokenData *tokenData);

TreeNode *addaSibling(TreeNode *, TreeNode *);

void printTree(TreeNode *, int);

void convertSiblingType(TreeNode *, ExpType);

void printSpaces(int);

void printExp(ExpType t);

#endif