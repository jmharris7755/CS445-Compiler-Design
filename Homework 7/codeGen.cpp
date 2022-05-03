#include <string.h>
#include "codeGen.h"
#include "emitcode.h"
#include "parser.tab.h"


#define MAXCHILDREN 3

using namespace std;

extern int goffset;
extern int loffset;

FILE *code;

extern SymbolTable symbolTable;

int tempOffset;
bool stFlag = false;
bool isUnary = true;
int cpdSize = 0;
int tmpIdx;

void generateCode(TreeNode *t, char* infile){

    code = fopen(infile, "w");

    emitComment((char*)"C- compiler version C-S21");
    emitComment((char*)"Built: 4-22 - 5-22");
    emitComment((char*)"Author: Justin Harris");
    emitComment((char*)"File compiled: ", infile);

    //emitAbout(infile);
    emitIO(t);
    emitInput(t);
    emitInit(t);
    fclose(code);

}

//Emit info about compiler at beginning
void emitAbout(char* infile){

    emitComment((char*)"C- compiler version C-S21");
    emitComment((char*)"Built: 4-22 - 5-22");
    emitComment((char*)"Author: Justin Harris");
    emitComment((char*)"File compiled: ", infile);
    emitSkip(1);
}

void emitInput(TreeNode* t){
    for(int i = 0; i < 7; i++){
        t = t->sibling;
        emitStart(t);
    }
}

//recursive function for emitting, mimic syntax tree set up
void emitStart(TreeNode* t){
    if(t == NULL){
        return;
    }
    else{
        switch(t->nodekind){

            case DeclK:
            emitDecl(t);
            break;

            case StmtK:
            emitStmt(t);
            break;

            case ExpK:
            emitExp(t);
            break;
        }
    }
    emitStart(t->sibling);
}

//emit code for nodekind Decl
void emitDecl(TreeNode *t){

    switch(t->subkind.decl){

        //start with paramK
        case ParamK:

            //loop through children
            for(int i = 0; i < MAXCHILDREN; i++){
                emitStart(t->child[i]);
            }
        break;


        case VarK:

            if((!t->isGlobal && !t->isStatic)){

                //check for arrays
                if(t->isArray){

                    emitRM((char*)"LDC", 3, t->mSize - 1, 6, (char*)"load array size", (char*)t->attr.name);
                    emitRM((char*)"ST", 3, t->mOffset + 1, 1, (char*)"save array size", (char*)t->attr.name);

                }
                else{
                    
                    //check initiailzed variable
                    if(t->child[0] != NULL){
                        
                        emitRM((char*)"ST", 3, t->mOffset + 1, 1, (char*)"save array size", (char*)t->attr.name);
                    }
                }
            }
            break;

        case FuncK:

            TreeNode* cntSiblings;
            int pcount;

            cntSiblings = t->child[0];

            if(cntSiblings != NULL){

                for(pcount = 0; cntSiblings != NULL; pcount++){
                    cntSiblings = cntSiblings->sibling;
                }

                if(!(t->child[1]->nodekind == StmtK && t->child[1]->subkind.stmt == CompoundK)){

                    tempOffset -= pcount + 2;
                }
            }

            t->emitLoc = emitSkip(0) - 1;

            emitComment((char *)("FUNCTION"), (char *) t->attr.name);
            emitRM((char *)"ST", 3, -1, 1,(char *)"Store return address");

            for(int i = 0; i < MAXCHILDREN; i++){
                
                if(t->child[i] != NULL){
                    emitStart(t->child[i]);
                }
            }

            emitComment((char *)("Add standard closing in case there is no return statement"));
			emitRM((char *)"LDC", 2, 0, 6, (char *)"Set return value to 0");
			emitRM((char *)"LD", 3, -1, 1, (char *)("Load return address"));
			emitRM((char *)"LD", 1, 0, 1, (char *)("Adjust fp"));
			emitRM((char *)"JMP", 7, 0, 3,(char *)("Return"));
			emitComment((char *)("END FUNCTION"), (char *) t->attr.name);

            tempOffset = 0;
            break;

    }

}

void emitStmt(TreeNode* t){

    int thenLoc, elseLoc, whileLoc, whileSkp, breakLoc, tmpBLoc, ldaLoc;

    switch(t->subkind.stmt){

        case IfK:

            emitComment((char*)("IF"));
            stFlag = false;

            emitStart(t->child[0]);
            emitComment((char*)("THEN"));

            elseLoc = 0;
            thenLoc = emitSkip(1);

            emitStart(t->child[1]);

            if(t->child[2] != NULL){

                elseLoc = emitSkip(1);
            }

            backPatchAJumpToHere((char*)"JZR", 3, thenLoc, (char *)("Jump around the THEN if false [backpatch]"));

            if(t->child[2] != NULL){

                emitComment((char*)"ELSE");
                emitStart(t->child[2]);
                backPatchAJumpToHere((char*)"JZR", 3, thenLoc, (char *)("Jump around the ELSE [backpatch]"));

            }

            emitComment((char*)"END IF");

            break;


        case WhileK:

            whileLoc = emitSkip(0);
            stFlag = false;
            emitComment((char*)("WHILE"));
            emitStart(t->child[0]);
            emitRM((char *)"JNZ", 3, 1, 7, (char *)("Jump to while part"));
            whileSkp = emitSkip(1);
            tmpBLoc = breakLoc;
            breakLoc = emitSkip(0);

            emitComment((char*)("DO"));
            emitStart(t->child[1]);
            emitRM((char*)"LDA", 7, whileLoc - emitSkip(0) - 1, 7, (char*)("go to the beginning of the loop"));
            ldaLoc = emitSkip(0);
            backPatchAJumpToHere(whileSkp, (char *)("Jump past loop [backpatch]"));
            breakLoc = tmpBLoc;
            emitNewLoc(ldaLoc);
            emitComment((char*)("END WHILE"));

            break;

        
        case ForK:

            emitComment((char*)("FOR"));
            for(int i = 0; i < MAXCHILDREN; i++){
                
                if(t->child[i] != NULL){
                    emitStart(t->child[i]);
                }
            }
            emitComment((char*)("END FOR"));


        
        case ReturnK:

            emitComment((char*)("RETURN"));
            stFlag = false;
            emitStart(t->child[0]);

            if(t->child[0] != NULL){
                emitRM((char *)"LDA", 2, 0, 3, (char *)("Copy result to ret register"));
            }
            emitRM((char *)"LD", 3, -1, 1, (char *)("Load return address"));
			emitRM((char *)"LD", 1, 0, 1, (char *)("Adjust fp"));
			emitRM((char *)"LDA", 7, 0, 3, (char *)("Return"));

            break;

        case BreakK:

            emitComment((char*)("BREAK"));
            emitRM((char *)"LDA", 7, breakLoc -emitSkip(0) - 2, 7, (char *)("break"));
            break;


        case CompoundK:

            cpdSize = t->mSize;
            emitComment((char*)("COMPOUND"));
            for(int i = 0; i < MAXCHILDREN; i++){
                if(t->child[i] != NULL){
                    emitStart(t->child[i]);
                }
            }
            
            emitComment((char*)("END COMPOUND"));
            break;

    }
}

void emitExp(TreeNode *t){

    TreeNode *leftSide;
    TreeNode *rightSide;

    if(t->child[0] != NULL){

        leftSide = t->child[0];
    }
    if(t->child[1] != NULL){

        rightSide = t->child[1];
    }

    switch(t->subkind.exp){

        //Look up assignment op
        TreeNode* askOp;

        case AssignK:

            emitComment((char*)("ASSIGNMENT EXPRESSION"));

            askOp = (TreeNode*)symbolTable.lookup(t->attr.name);

            //check for standard assignment -- like syntaxTree
            if(strcmp(askOp->attr.name, "<-")){

                //check for arrays
                if(!strcmp(askOp->attr.name, "[")){

                    emitStart(leftSide->child[1]);
                    emitRM((char *)"ST", 3, tempOffset, 1, (char *)("Push index"));
                    tempOffset--;

                    emitStart(rightSide);
                    tempOffset++;
                    emitRM((char *)"LD", 4, tempOffset, 1,(char *)("Pop index")); 

                    if(leftSide->child[0]->memT == Global){
                        emitRM((char *)"LDA", 5, leftSide->child[0]->mOffset, 0, (char *)("Load address of base of array"), (char *)leftSide->child[0]->attr.name);
                    }
                    else{
                        emitRM((char *)"LDA", 5, leftSide->child[0]->mOffset, 1, (char *)("Load address of base of array"), (char *)leftSide->child[0]->attr.name);
                    }
                    emitRO((char *)"SUB", 5, 5, 4, (char *)("Compute offset of value"));
					emitRM((char *)"ST", 3, 0, 5, (char *)("Store variable"), (char *)leftSide->child[0]->attr.name);
                }
                //not an array
                else{
                    emitStart(rightSide);
                    stFlag = true;
                    emitStart(leftSide);
                    isUnary = true;
                }
            }

            //check for ++ --
            else if(rightSide == NULL){

                stFlag = false;
                isUnary = true;

                emitStart(leftSide);

                if(!strcmp(t->attr.name, "++"))
				{
					emitRM((char *)"LDA", 3, 1, 3, (char *)("increment value of"), (char *)leftSide->attr.name);
				}
				else if(!strcmp(t->attr.name, "--"))
				{
					emitRM((char *)"LDA", 3, -1, 3, (char *)("decrement value of"), (char *)leftSide->attr.name);
				}
	
				emitRM((char *)"ST", 3, leftSide->mOffset, 1,(char *)("Store variable"), (char *)leftSide->attr.name);
            }

            else{

                stFlag = false;

                emitStart(rightSide);
                isUnary = false;
                emitStart(leftSide);

                //check for each other assignment operator
                if(!strcmp(t->attr.name, "+="))
				{
					emitRO((char *)"ADD", 3, 4, 3, (char *)("op"), (char *)t->attr.name);
				}
				else if(!strcmp(t->attr.name, "-="))
				{
					emitRO((char *)"SUB", 3, 4, 3, (char *)("op"), (char *)t->attr.name);
				}
				else if(!strcmp(t->attr.name, "*="))
				{
					emitRO((char *)"MUL", 3, 4, 3, (char *)("op"), (char *)t->attr.name);
				}
				else if(!strcmp(t->attr.name, "/="))
				{
					emitRO((char *)"DIV", 3, 4, 3, (char *)("op"), (char *)t->attr.name);
				}
				
                //check mem types
				if(leftSide->memT == Global)
				{
					emitRM((char *)"ST", 3, leftSide->mOffset, 0, (char *)("Store variable"), (char *)leftSide->attr.name);
				}
				else
				{
					emitRM((char *)"ST", 3, leftSide->mOffset, 1, (char *)("Store variable"), (char *)leftSide->attr.name);
				}
                //reset unary flag
				isUnary = true;
            }

            break;

        case OpK:

            emitComment((char*)("OP EXPRESSION"));

            //Check Unary ops
            if(rightSide == NULL){

                emitStart(t->child[0]);

                if(!strcmp(t->attr.name, "-")){

                    emitRO((char *)"NEG", 3, 3, 3, (char *)("Op unary -"), (char *)t->attr.name);
                }

                else if(!strcmp(t->attr.name, "*")){

                    if(t->memT == Global){

                        emitRM((char *)"LDA", 3, leftSide->mOffset, 0, (char *)("Load address of base of array"), (char *)leftSide->attr.name);
                    }
                    else if(t->memT == Parameter){
                        emitRM((char *)"LD", 3, leftSide->mOffset, 1, (char *)("Load address of base of array"), (char *)leftSide->attr.name);
                    }
                    else{
                        emitRM((char *)"LDA", 3, leftSide->mOffset, 1, (char *)("Load address of base of array"), (char *)leftSide->attr.name);
                    }
                    emitRM((char *)"LD", 3, 1, 3, (char *)("Load array size"));
                }

                else if(!strcmp(t->attr.name, "?")){

                    emitRO((char *)"RND", 3, 3, 3, (char *)("Op unary"), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, "NOT")){

                    emitRM((char *)"LDC", 4, 1, 6, (char *)("Load 1"));
					emitRO((char *)"XOR", 3, 3, 4, (char *)("Op XOR to get logical not"));
                }
            }
            //binary checks
            else{

                emitStart(t->child[0]);

                //save temp index from where we are
                tmpIdx = tempOffset;  

                //move past index in use
                tmpIdx--; 

                emitRM((char*)"ST", 3, tmpIdx, 1, (char*)("Save the left side"));
                emitStart(t->child[1]);

                emitRM((char*)"LD", 4, tmpIdx, 1, (char*)("Load Left into 1"));
                tmpIdx++;

                if(!strcmp(t->attr.name, "AND")){
                    emitRO((char *)"AND", 3, 4, 3, (char *)("Op AND"), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, "OR")){
                    emitRO((char *)"OR", 3, 4, 3, (char *)("Op OR"), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, ">")){
                    emitRO((char *)"TGT", 3, 4, 3, (char *)("Op >"), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, "<")){
                    emitRO((char *)"TLT", 3, 4, 3, (char *)("Op <"), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, ">=")){
                    emitRO((char *)"TGE", 3, 4, 3, (char *)("Op >="), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, "<=")){
                    emitRO((char *)"TLE", 3, 4, 3, (char *)("Op <="), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, "==")){
                    emitRO((char *)"TEQ", 3, 4, 3, (char *)("Op =="), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, "!=")){
                    emitRO((char *)"TNE", 3, 4, 3, (char *)("Op !="), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, "+")){
                    emitRO((char *)"ADD", 3, 4, 3, (char *)("Op +"), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, "-")){
                    emitRO((char *)"SUB", 3, 4, 3, (char *)("Op -"), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, "/")){
                    emitRO((char *)"DIV", 3, 4, 3, (char *)("Op /"), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, "%")){
                    emitRO((char *)"MOD", 3, 4, 3, (char *)("Op %"), (char *)t->attr.name);
                }

            }
            break;

        case ConstantK:

            if(t->expType == Integer){
                emitRM((char *)"LDC", 3, t->attr.value, 6,(char *)"Load integer constant");
            }
            else if(t->expType == Boolean){
                emitRM((char *)"LDC", 3, t->attr.value, 6,(char *)"Load boolean constant");
            }
            else if(t->expType == Char){
                emitRM((char *)"LDC", 3, t->attr.cvalue, 6,(char *)"Load character constant");
            }
            /*else if(t->expType == CharInt){
                char strName = t->attr.string;
                emitRM((char *)"LDC", 3, strName, 6,(char *)"Load string constant");
            }*/

            break;

        case IdK:

            //store
            if(stFlag){

                if(t->memT == Global || t->memT == LocalStatic){
                    if(!t->isArray){
                        emitRM((char *)"ST", 3, t->mOffset, 0,(char *)("Store variable"), t->attr.name);
                        stFlag = false;
                    }
                }
                else if(t->memT == Local){
                    if(!t->isArray){
                        emitRM((char *)"ST", 3, t->mOffset, 1, (char *)("Store variable"), t->attr.name);
                        stFlag = false;
                    }
                }

            }
            //load
            else{

                if(t->memT == Global){

                    if(isUnary){
                        
                        if(t->isArray){
                            emitRM((char *)" LD", 3, t->mOffset, 0, (char *)("1 Load address of base of array"), t->attr.name);
                            tempOffset--;
                        }
                        else{
                            emitRM((char *)"LD", 3, t->mOffset, 0, (char *)("1 Load variable"), t->attr.name);
                        }
                    }
                    else{
                        emitRM((char *)"LD", 4, t->mOffset, 0, (char *)("1 load lhs variable"), t->attr.name);
                    }
                }

                else if(t->memT == Local){

                    if(isUnary){
                        
                        if(t->isArray){
                            emitRM((char *)" LD", 3, t->mOffset, 1, (char *)("2 Load address of base of array"), t->attr.name);
                            tempOffset--;
                        }
                        else{
                            emitRM((char *)"LD", 3, t->mOffset, 1, (char *)("2 Load variable"), t->attr.name);
                        }
                    }
                    else{
                        emitRM((char *)"LD", 4, t->mOffset, 1, (char *)("2 load lhs variable"), t->attr.name);
                    }
                }

                else if(t->memT == LocalStatic){

                    if(isUnary){
                        
                        if(t->isArray){
                            emitRM((char *)" LD", 3, t->mOffset, 0, (char *)("3 Load address of base of array"), t->attr.name);
                            tempOffset--;
                        }
                        else{
                            emitRM((char *)"LD", 3, t->mOffset, 0, (char *)("3 Load variable"), t->attr.name);
                        }
                    }
                    else{
                        emitRM((char *)"LD", 4, t->mOffset, 0, (char *)("3 load lhs variable"), t->attr.name);
                    }
                }

                else if(t->memT == Parameter){

                    if(isUnary){
                        
                        if(t->isArray){
                            emitRM((char *)" LD", 3, t->mOffset, 1, (char *)("4 Load address of base of array"), t->attr.name);
                            tempOffset--;
                        }
                        else{
                            emitRM((char *)"LD", 3, t->mOffset, 1, (char *)("4 Load variable"), t->attr.name);
                        }
                    }
                    else{
                        emitRM((char *)"LD", 4, t->mOffset, 1, (char *)("4 load lhs variable"), t->attr.name);
                    }
                }
            }

            break;

            case CallK:
            
                int tmpIdx;

                emitComment((char*)("CALL EXPRESSION"));

                //track param count and if call has params(children)
                int pCount = 0;
                bool hasChild = false;

                //lookup original fn decl from symbol table
                TreeNode* curFunc = (TreeNode*)symbolTable.lookup(t->attr.name);

                //print call name
                emitComment((char*)"CALL", t->attr.name);
                tmpIdx = tempOffset;

                if(t->child[0] != NULL){

                    hasChild = true;
                    TreeNode* getParams = t->child[0];

                    while(getParams){

                        getParams = t->sibling;
                        pCount++;
                    }

                    //check single parameter
                    if(pCount == 1){

                        emitRM((char *)"ST", 1, tempOffset, 1, (char *)("1 Store fp in ghost frame for"), (char *)t->attr.name);

                        tempOffset -= 2;

                        emitComment((char*)"Param 1");

                        emitStart(t->child[0]);

                        //if not array, adjust temp offset
                        if(!t->child[0]->isArray){

                            tempOffset -= pCount;
                        }
                        emitRM((char *)"ST", 3, tempOffset, 1,(char *)"Push parameter");
                        emitComment((char *)("Param end"), t->attr.name);
                        emitRM((char *)"LDA", 1, tmpIdx, 1,(char *)"Ghost frame becomes new active frame");
                    }

                    //more than 1 parameter
                    else{
                        //set base number of parms
                        int parmIterator = 1;

                        emitRM((char *)"ST", 1, tempOffset, 1, (char *)("2 Store fp in ghost frame for"), (char *)t->attr.name);

                        TreeNode* curChild = t->child[0];
                        tempOffset--;

                        //loop through all children (parameters)
                        while(curChild != NULL){

                            tempOffset--;

                            //check for arrays
                            if(curChild->isArray){
                                
                                emitComment((char *)("Param"), parmIterator);

                                //check mem types
                                if(curChild->memT == Global){

                                    //check first parameter
                                    //if(pCount == 1){

                                        emitRM((char *)"LDA", 3, curChild->mOffset, 0, (char *)("Load address of base of array"), (char *)curChild->attr.name);
                                    //}
                                    /*else{

                                        emitRM((char *)"LDA", 3, curChild->mOffset, 0, (char *)("Load address of base of array"), (char *)curChild->attr.name);
                                    }*/
                                }
                                else{

                                    //check first parameter
                                    //if(pCount == 1){

                                        emitRM((char *)"LDA", 3, curChild->mOffset, 1, (char *)("Load address of base of array"), (char *)curChild->attr.name);
                                    //}
                                    /*else{

                                        emitRM((char *)"LDA", 3, curChild->mOffset, 1, (char *)("Load address of base of array"), (char *)curChild->attr.name);
                                    }*/                                    
                                }
                                emitRM((char *)"ST", 3, tempOffset, 1,(char *)("Push parameter"));
                            }
                            
                            //not an array
                            else{
                                
                                if(curChild->expType == Integer){
                                    emitRM((char *)"LDC", 3, curChild->attr.value, 6, (char *)"Load integer constant");
                                }
                                else if(curChild->expType == Boolean){
                                    emitRM((char *)"LDC", 3, curChild->attr.value, 6, (char *)"Load boolean constant");
                                }
                                else if(curChild->expType == Char){
                                    emitRM((char *)"LDC", 3, curChild->attr.value, 6, (char *)"Load character constant");
                                }
                                emitRM((char *)"ST", 3, tempOffset, 1,(char *)"Push parameter");
                            }

                            //increment parmiterator
                            parmIterator++;
                            curChild = curChild->sibling;
                        }
                        emitComment((char *)("Param end"), t->attr.name);
					    emitRM((char *)"LDA", 1, tmpIdx, 1,(char *)"Ghost frame becomes new active frame");

                    }
                }
                //no parameters
                else{
                    emitRM((char *)"ST", 1, tempOffset, 1, (char *)("3 Store fp in ghost frame for"), (char *)t->attr.name);
                    emitComment((char *)("Param end"), t->attr.name);
                    emitRM((char *)"LDA", 1, tmpIdx, 1,(char *)"Ghost frame becomes new active frame");
                }

                curFunc = (TreeNode*)symbolTable.lookup(t->attr.name);
                emitRM((char *)"LDA", 3, 1, 7,(char *)"Return address in ac");
                int backpatch = emitSkip(0);
                emitRM((char *)"JMP",7, curFunc->linenum - backpatch - 1, 7, (char *)("CALL"), t->attr.name);
                
                emitRM((char *)"LDA", 3, 0, 2,(char *)"Save the result in ac");
                emitComment((char *)("CALL end"), t->attr.name);

                tempOffset = tmpIdx;

                break;
    }
}

void emitGlobAndStats(TreeNode* t){

    if(t != NULL){

        if(t->subkind.decl == VarK){

            if(t->memT == Global){

                if(t->isArray){

                    emitRM((char *)"LDC", 3, t->mSize - 1, 6,(char *)"load size of array", (char *) t->attr.name);
				    emitRM((char *)"ST", 3, t->mOffset + 1, 0,(char *)"save size of array", (char *) t->attr.name);
                }
            }
        }
    }
    
}

void emitIO(TreeNode *t){

    emitSkip(1);
	emitComment((char *)("** ** ** ** ** ** ** ** ** ** ** **"));
	emitComment((char *)("FUNCTION input"));
	TreeNode *curIO = (TreeNode*)symbolTable.lookup((char *)("input"));
	emitRM((char *)"ST", 3, -1, 1,(char *)"Store return address");
	curIO->linenum = emitSkip(0)-1;
	curIO->attr.name = (char *) "input";
	emitRO((char *)"IN", 2, 2, 2,(char *)("Grab int input"));
	emitRM((char *)"LD", 3, -1, 1, (char *)("Load return address"));
	emitRM((char *)"LD", 1, 0, 1, (char *)("Adjust fp"));
	emitRM((char *)"JMP", 7, 0, 3,(char *)("Return"));
	emitComment((char *)("END FUNCTION input"));
	emitComment((char *)(""));
	emitComment((char *)("** ** ** ** ** ** ** ** ** ** ** **"));

	emitComment((char *)("FUNCTION output"));
	curIO = (TreeNode*)symbolTable.lookup((char *)("output"));
	emitRM((char *)"ST", 3, -1, 1,(char *)"Store return address");
	curIO->linenum = emitSkip(0)-1;
	curIO->attr.name = (char *) "output";
	emitRO((char *)"IN", 2, 2, 2,(char *)("Grab int input"));
	emitRM((char *)"LD", 3, -1, 1, (char *)("Load return address"));
	emitRM((char *)"LD", 1, 0, 1, (char *)("Adjust fp"));
	emitRM((char *)"JMP", 7, 0, 3,(char *)("Return"));
	emitComment((char *)("END FUNCTION output"));
	emitComment((char *)(""));
	emitComment((char *)("** ** ** ** ** ** ** ** ** ** ** **"));

    emitComment((char *)("FUNCTION output"));
	curIO = (TreeNode*)symbolTable.lookup((char *)("output"));
	emitRM((char *)"ST", 3, -1, 1,(char *)"Store return address");
	curIO->linenum = emitSkip(0)-1;
	curIO->attr.name = (char *) "output";
	emitRM((char *)"LD", 3, -2, 1,(char *)("Load parameter"));
    emitRO((char *)"OUT",3,3,3,(char *)("Output integer"));
	emitRM((char *)"LD", 3, -1, 1, (char *)("Load return address"));
	emitRM((char *)"LD", 1, 0, 1, (char *)("Adjust fp"));
	emitRM((char *)"JMP", 7, 0, 3,(char *)("Return"));
	emitComment((char *)("END FUNCTION output"));
	emitComment((char *)(""));
	emitComment((char *)("** ** ** ** ** ** ** ** ** ** ** **"));

    emitComment((char *)("FUNCTION inputb"));
	curIO = (TreeNode*)symbolTable.lookup((char *)("inputb"));
	emitRM((char *)"ST", 3, -1, 1, (char *)"Store return address");
	curIO->linenum = emitSkip(0)-1;
	curIO->attr.name = (char *) "inputb";
	emitRO((char *)"INB", 2, 2, 2, (char *)("Grab bool input"));
	emitRM((char *)"LD", 3, -1, 1, (char *)("Load return address"));
	emitRM((char *)"LD", 1, 0, 1, (char *)("Adjust fp"));
	emitRM((char *)"JMP", 7, 0, 3, (char *)("Return"));
	emitComment((char *)("END FUNCTION inputb"));
	emitComment((char *)(""));
	emitComment((char *)("** ** ** ** ** ** ** ** ** ** ** **"));

	emitComment((char *)("FUNCTION outputb"));
	curIO = (TreeNode*)symbolTable.lookup((char *)("outputb"));
	emitRM((char *)"ST", 3, -1, 1,(char *)"Store return address");
	curIO->linenum = emitSkip(0)-1;
	curIO->attr.name = (char *) "outputb";
	emitRM((char *)"LD", 3, -2, 1,(char *)("Load parameter"));
	emitRO((char *)"OUTB", 3, 3, 3, (char *)("Output bool"));
	emitRM((char *)"LD",3,-1,1,(char *)("Load return address"));
	emitRM((char *)"LD",1,0,1,(char *)("Adjust fp"));
	emitRM((char *)"JMP",7,0,3,(char *)("Return"));
	emitComment((char *)("END FUNCTION outputb"));
	emitComment((char *)(""));
	emitComment((char *)("** ** ** ** ** ** ** ** ** ** ** **"));

	emitComment((char *)("FUNCTION inputc"));
	curIO = (TreeNode*)symbolTable.lookup((char *)("inputc"));
	emitRM((char *)"ST", 3, -1, 1,(char *)"Store return address");
	curIO->linenum = emitSkip(0)-1;
	curIO->attr.name = (char *) "inputc";
	emitRO((char *)"INC", 2, 2, 2, (char *)("Grab char input"));
	emitRM((char *)"LD", 3, -1, 1, (char *)("Load return address"));
	emitRM((char *)"LD", 1, 0, 1, (char *)("Adjust fp"));
	emitRM((char *)"JMP", 7, 0, 3, (char *)("Return"));
	emitComment((char *)("END FUNCTION inputc"));
	emitComment((char *)(""));
	emitComment((char *)("** ** ** ** ** ** ** ** ** ** ** **"));

	emitComment((char *)("FUNCTION outputc"));
	curIO = (TreeNode*)symbolTable.lookup((char *)("outputc"));
	emitRM((char *)"ST", 3, -1, 1, (char *)"Store return address");
	curIO->linenum = emitSkip(0)-1;
	curIO->attr.name = (char *) "outputc";
	emitRM((char *)"LD", 3, -2, 1, (char *)("Load parameter"));
	emitRO((char *)"OUTC", 3, 3, 3, (char *)("Output char"));
	emitRM((char *)"LD", 3, -1, 1, (char *)("Load return address"));
	emitRM((char *)"LD", 1, 0, 1, (char *)("Adjust fp"));
	emitRM((char *)"JMP", 7, 0, 3, (char *)("Return"));
	emitComment((char *)("END FUNCTION outputc"));
	emitComment((char *)(""));
	emitComment((char *)("** ** ** ** ** ** ** ** ** ** ** **"));

	emitComment((char *)("FUNCTION outnl"));
	curIO = (TreeNode*)symbolTable.lookup((char *)("outnl"));
	emitRM((char *)"ST", 3, -1, 1, (char *)"Store return address");
	curIO->linenum = emitSkip(0)-1;
	curIO->attr.name = (char *) "outnl";
	emitRO((char *)"OUTNL", 3, 3, 3, (char *)("Output a newline"));
	emitRM((char *)"LD", 3, -1, 1, (char *)("Load return address"));
	emitRM((char *)"LD", 1, 0, 1, (char *)("Adjust fp"));
	emitRM((char *)"JMP", 7, 0, 3, (char *)("Return"));
	emitComment((char *)("END FUNCTION outnl"));
	emitComment((char *)(""));
	emitComment((char *)("** ** ** ** ** ** ** ** ** ** ** **"));
}

void emitInit(TreeNode *t){

    TreeNode* mainFunc;
	
	int bp = emitSkip(0)-1;
	emitNewLoc(0);
	mainFunc = (TreeNode*)symbolTable.lookup("main"); 
	emitRM((char *)"JMP", 7, bp, 7, (char *)("Jump to init [backpatch]"));
	emitComment((char *)("INIT"));
	emitSkip(bp);
	emitRM((char *)"LDA", 1, 0+goffset, 0, (char *)("set first frame at end of globals"));
	emitRM((char *)"ST", 1, 0, 1, (char *)("store old fp (point to self)"));
	emitComment((char *)("INIT GLOBALS AND STATICS"));
	emitGlobAndStats(t);
	emitComment((char *)("END INIT GLOBALS AND STATICS"));
	emitRM((char *)"LDA", 3, 1, 7, (char *)("Return address in ac"));
	bp = emitSkip(0);
	emitRM((char *)"JMP", 7, mainFunc->linenum - bp - 1, 7, (char *)("Jump to main"));
	emitRO((char *)"HALT", 0, 0, 0, (char *)("DONE!"));
	emitComment((char *)("END INIT"));
}
