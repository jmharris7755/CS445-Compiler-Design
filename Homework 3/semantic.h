#ifndef SEMANTIC 
#define SEMANTIC

#include "syntaxTree.h"
#include "symbolTable.h"
#include "scanType.h"

SymbolTable returnSymbolTable();
bool compare(const err& f, const err& s)
void printErrors();
void semanticAnalysis(TreeNode *t, int& errors, int& warnings);
void analyze(TreeNode *t, int& numErrors, int&numWarnings)
void checkDecl(TreeNode *t, int& numErrors, int& numWarnings);
void checkStmt(TreeNode *t, int& numErrors, int& numWarnings);
void checkExp(TreeNode *t, int& numErrors, int& numWarnings);
void getExpTypes(const char* string, bool isBinary, bool &unaryErrors, ExpType &left, ExpType &right, ExpType &rightT);
char* conExpType(ExpType type);
void printError(int errCode, int linenum, int explaineno, char* s1, char* s2, char* s3, double d);

#endif