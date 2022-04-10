//Justin Harris 
//CS445
//Last Updated: 4-09-22

#include "IOinit.h"
#include "symbolTable.h"
#include "syntaxTree.h"
#include "scanType.h"
#include "semantic.h"

#include <stdio.h>
#include <string.h>
#include <iostream>

extern SymbolTable symbolTable;

void setupIO(){

    //vars for IO nodes and dummy parameters
    TreeNode* newIONode; 
    TreeNode* dummyParam;

    //each node to set up
    /*
    void output(int)
    void outputb(bool)
    void outputc(char)
    int input()
    bool inputb()
    char inputc()
    void outnl()
    */

   //set up each section of new nodes as arrays
   std::string IONameArr[] = {"output", "outputb", "outputc", "input", "inputb", "inputc", "outnl"};

   ExpType IOexpType[] = {Void, Void, Void, Integer, Boolean, Char, Void};
   ExpType IOParamExpType[] = {Integer, Boolean, Char, Void, Void, Void, Void};
   int IOmemSizes[] = {-3, -3, -3, -2, -2, -2, -2};

   //set up nodes

   for(int i = 0; i < 7; i++){

       newIONode = newDeclNodeIO(FuncK);
       newIONode->attr.name = strdup(IONameArr[i].c_str());
       newIONode->linenum = -1;
       newIONode->expType = IOexpType[i];

       //avoid warnings
       newIONode->isDeclared = true;
       newIONode->isInit = true;
       newIONode->wasUsed = true;
       newIONode->isIO = true;
       newIONode->mSize = IOmemSizes[i];
       newIONode->mOffset = 0;

       //insert into symbolTable
       symbolTable.insert(newIONode->attr.name, (TreeNode*) newIONode);


       //set up parameters if not void
       if(IOParamExpType[i] != Void){
           dummyParam = newDeclNodeIO(ParamK);
           dummyParam->attr.name = strdup("dummy");
           dummyParam->linenum = -1;
           dummyParam->expType - IOParamExpType[i];
           newIONode->child[0] = dummyParam;
           dummyParam->mSize = 1;
           dummyParam->mOffset = -2;
       }
       else{
           newIONode->child[0] = NULL;
       }
   }
   

}

