#ifndef CODEGEN_H
#define CODEGEN_H

#include "syntaxTree.h"
#include "symbolTable.h"


void generateCode(TreeNode *t, SymbolTable st, char* outfile, char* infile);
void emitAbout(char* infile);
void emitIO(TreeNode *t);
void emitInput(TreeNode *t);
void emitInit(TreeNode *t);
void emitStart(TreeNode* t);
void emitDecl(TreeNode *t);
void emitExp(TreeNode *t);
void emitStmt(TreeNode *t);
void emitGlobAndStats(TreeNode* t);

#endif