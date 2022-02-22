#ifndef SEMANTIC 
#define SEMANTIC

#include "syntaxTree.h"
#include "symbolTable.h"
#include "scanType.h"

SymbolTable returnSymbolTable();
void semanticAnalysis(TreeNode *t, int& errors, int& warnings);
void analyze(TreeNode *t, int& nErrors, int& nWarnings);
void checkDecl(TreeNode *t, int& nErrors, int& nWarnings);
void checkStmt(TreeNode *t, int& nErrors, int& nWarnings);
void checkExp(TreeNode *t, int& nErrors, int& nWarnings);
void getExpTypes(const char* string, bool isBinary, bool &unaryErrors, ExpType &left, ExpType &right, ExpType &rightT);
char* conExpType(ExpType type);
void printError(int errCode, int linenum, int explaineno, char* s1, char* s2, char* s3, double d);
void checkArrays(TreeNode *tree);

#endif