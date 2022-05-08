#include <string.h>
#include "codeGen.h"
#include "emitcode.h"



#define MAXCHILDREN 3

using namespace std;

extern int goffset;
extern int loffset;

FILE *code;

extern SymbolTable symbolTable;

int tempOffset = - 2;
bool stFlag = false;
bool isUnary = false;
int cpdSize = 0;
int tmpIdx;
bool opKarr;
int thenLoc = 0, elseLoc = 0, breakLoc = 0;
int nestThen = 0;
bool mpCall = false;
bool nestCall = false;
bool nestAsgn = false;
int doingFor = false;


void generateCode(TreeNode *t, char* infile){

    code = fopen(infile, "w");

    emitComment((char*)"C- compiler version C-S21");
    emitComment((char*)"Built: 4-22 - 5-22");
    emitComment((char*)"Author: Justin Harris");
    emitComment((char*)"File compiled: ", infile);
    emitComment((char*)"");

    //emitAbout(infile);
    //emitSkip(1);
    emitIO(t);
    //emitInput(t);
    //emitSkip(0);
    emitStart(t);
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
    /*for(int i = 0; i < 7; i++){
        
        if(t->sibling != NULL){
            emitStart(t);
        }
    }*/
    while(t->sibling != NULL){
        //t = t->sibling;
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
    if(t->sibling != NULL && !mpCall){
        emitStart(t->sibling);
    }
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

                        if(t->isArray){
                        emitRM((char*)"ST", 3, t->mOffset + 1, 1, (char*)"save array size", (char*)t->attr.name);
                        }
                        else{
                            emitStart(t->child[0]);
                            emitRM((char*)"ST", 3, t->mOffset, 1, (char*)"store variable 136", (char*)t->attr.name);
                        }
                    }
                }
            }
            break;

        case FuncK:

            t->codeLine = emitSkip(0);

            TreeNode* cntSiblings;
            int pcount;
            int tmpIdx = tempOffset;

            cntSiblings = t->child[0];

            if(cntSiblings != NULL){

                for(pcount = 0; cntSiblings != NULL; pcount++){
                    cntSiblings = cntSiblings->sibling;
                }

                if(!(t->child[1]->nodekind == StmtK && t->child[1]->subkind.stmt == CompoundK)){

                    tempOffset -= pcount + 2;
                    emitComment((char*)"TOFF:", tempOffset);
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

            //tempOffset = 0;
            tempOffset = tmpIdx;
            emitComment((char*)"TOFF:", tempOffset);
            break;

    }

}

void emitStmt(TreeNode* t){

    int whileLoc = 0, tmpBloc = 0, whileSkp = 0, ldaLoc = 0, forCdrn = 0;
    int forOff = 0, forLoc = 0, forSkp = 0;

    switch(t->subkind.stmt){

        case IfK:

            //start if statement
            emitComment((char*)("IF"));
            stFlag = false;

            //analyze child0
            emitStart(t->child[0]);
            emitComment((char*)("THEN"));

            //set else location and then location
            elseLoc = 0;
            thenLoc = emitSkip(1);
            if(t->child[1]->subkind.stmt == IfK){
                nestThen = thenLoc--;
            }            

            //start analyzing child1
            emitStart(t->child[1]);

            //if there is an else statement updated location
            if(t->child[2] != NULL){

                elseLoc = emitSkip(1);
            }

            if(t->child[1]->subkind.stmt != IfK){
            //go back to then section
            //nestThen -= 2;
            backPatchAJumpToHere((char*)"JZR", 3, thenLoc, (char *)("Jump around the THEN if false [backpatch]"));
            }
            else{
                
                backPatchAJumpToHere((char*)"JZR", 3, nestThen, (char *)("Jump around the THEN if false [backpatch]"));
            }

            //if there is an else statement, analyze child2 jump the else
            if(t->child[2] != NULL){

                emitComment((char*)"ELSE");
                emitStart(t->child[2]);
                backPatchAJumpToHere((char*)"JMP", 7, elseLoc, (char *)("Jump around the ELSE [backpatch]"));
                

            }

            //done
            emitComment((char*)"END IF");

            break;


        case WhileK:

            whileLoc = emitSkip(0);
            stFlag = false;
            emitComment((char*)("WHILE"));
            
            emitStart(t->child[0]);
            tmpBloc = breakLoc;
            breakLoc = emitSkip(0);
            emitRM((char *)"JNZ", 3, 1, 7, (char *)("Jump to while part"));
            emitComment((char*)("DO"));
            whileSkp = emitSkip(1);
            
            emitStart(t->child[1]);
            emitRM((char*)"JMP", 7, whileLoc - emitSkip(0) - 1, 7, (char*)("go to the beginning of the loop"));
            ldaLoc = emitSkip(0);
            backPatchAJumpToHere(whileSkp, (char *)("Jump past loop [backpatch]"));
            breakLoc = tmpBloc;
            emitNewLoc(ldaLoc);
            emitComment((char*)("END WHILE"));

            break;

        
        case ForK:

            tempOffset -= 3;
            doingFor = true;
            emitComment((char*)("TOFF: "), tempOffset);

            emitComment((char*)("FOR"));

            forOff = tempOffset;

            //emit index var
            emitStart(t->child[0]);

            //emit RangeK section
            emitStart(t->child[1]);

            forLoc = emitSkip(0);

            //Check if the range has been exceeded.
            emitRM((char *)"LD", 4, forOff + 3, 1, (char *)"loop index");
            emitRM((char *)"LD", 5, forOff + 2, 1, (char *)"stop value");
            emitRM((char *)"LD", 3, forOff + 1, 1, (char *)"step value");
            emitRO((char *)"SLT", 3, 4, 5, (char *)"Op <");
            emitRM((char *)"JNZ", 3, 1, 7, (char *)"Jump to loop body");
            
            forSkp = emitSkip(1);

            //go through compound section for for loop
            emitStart(t->child[2]);

            emitRM((char *)"LD", 3, forOff + 3, 1, (char *)"Load index");
            emitRM((char *)"LD", 5, forOff + 1, 1, (char *)"Load step");

            emitRO((char *)"ADD", 3, 3, 5, (char *)"increment");

            emitRM((char *)"ST", 3, forOff + 3, 1, (char *)"store back to index");
            emitGotoAbs(forLoc, (char *)"go to beginning of loop");
            backPatchAJumpToHere(forSkp, (char *)"Jump past loop [backpatch]");

            emitComment((char*)("END FOR"));
            doingFor = false;
            
            break;

        case RangeK:

            //get first part of range
            emitStart(t->child[0]);
            emitRM((char *)"ST", 3, tempOffset + 3, 1, (char *)"save starting value in index variable");

            //get second part of range
            emitStart(t->child[1]);
            emitRM((char *)"ST", 3, tempOffset + 2, 1, (char *)"save stop value");

            //check if there is a 3rd child in the range
            //go through 3rd child if so
            if (t->child[2] != NULL)
            {
                emitStart(t->child[2]);
                emitRM((char *)"ST", 3, tempOffset + 1, 1, (char *)"save step value");
            }
            //else default increment and save current step.
            else
            {
                emitRM((char *)"LDC", 3, 1, 6, (char *)"default increment by 1");
                emitRM((char *)"ST", 3, tempOffset + 1, 1, (char *)"save step value");
            }

            break;


        
        case ReturnK:

            emitComment((char*)("RETURN"));
            stFlag = false;
            emitStart(t->child[0]);

            if(t->child[0] != NULL){
                emitRM((char *)"LDA", 2, 0, 3, (char *)("Copy result to ret register"));
            }
            emitRM((char *)"LD", 3, -1, 1, (char *)("Load return address"));
			emitRM((char *)"LD", 1, 0, 1, (char *)("Adjust fp"));
			emitRM((char *)"JMP", 7, 0, 3, (char *)("Return"));

            break;

        case BreakK:

            emitComment((char*)("BREAK"));
            emitRM((char *)"JMP", 7, breakLoc - emitSkip(0), 7, (char *)("break"));
            break;


        case CompoundK:

            cpdSize = tempOffset;
            emitComment((char*)("COMPOUND"));
            if(!doingFor){
                tempOffset = t->mSize;
            }
            emitComment((char*)"TOFF: ", tempOffset);
            for(int i = 0; i < MAXCHILDREN; i++){
                
                //maybe only t here instead of t->child[i]?
                if(t != NULL){
                    emitStart(t->child[i]);
                }
            }
            emitComment((char*)("Compound Body"));
            tempOffset = cpdSize;
            emitComment((char*)"TOFF: ", tempOffset);

            
            emitComment((char*)("END COMPOUND"));
            break;

    }
}

void emitExp(TreeNode *t){

    //shorthands for checking child 0 and child1 in AssignK and OpK
    TreeNode *leftSide;
    TreeNode *rightSide;

    //setup leftSide and rightSide of AssignKs and OpKs
    if(t->child[0] != NULL){

        leftSide = t->child[0];
    }
    else{
        leftSide = NULL;
    }
    if(t->child[1] != NULL){

        rightSide = t->child[1];
    }
    else{
        rightSide = NULL;
    }

    switch(t->subkind.exp){

        //Look up assignment op
        //TreeNode* askOp;

        case AssignK:

            //int tmpIdx;

            emitComment((char*)("ASSIGNMENT EXPRESSION"));

            //tempOffset--;

            //askOp = (TreeNode*)symbolTable.lookup(t->attr.name);

            //check for standard assignment -- like syntaxTree
            if(!strcmp(t->attr.name, "<-")){

                //check for arrays
                if(!strcmp(t->child[0]->attr.name, "[")){

                    /*if(leftSide->child[1]->subkind.exp == IdK){
                        emitRM((char *)"LD", 3, leftSide->child[1]->mOffset, 1, (char *)("1 load variable 373"), leftSide->child[1]->attr.name);
                    }
                    else{*/
                    /*if(leftSide->child[1]->subkind.exp == IdK){
                        printf("Here: %s %d\n", leftSide->child[1]->attr.name, t->linenum);
                    }
                    if(leftSide->child[0]->subkind.exp != ConstantK){
                        printf("Here RS %s %d\n", leftSide->child[0]->attr.name, t->linenum);
                    }*/
                    emitStart(leftSide->child[1]);
                    //}
                    
                    emitRM((char *)"ST", 3, tempOffset, 1, (char *)("Push index 373"));
                    tempOffset--;
                    emitComment((char*)"TOFF:", tempOffset);

                    if(rightSide->subkind.exp == AssignK){
                        //printf("Here %s %d", rightSide->attr.name, t->linenum);
                        if(!strcmp(rightSide->attr.name, "<-")){
                            nestAsgn = true;
                        }
                    }
                    emitStart(rightSide);
                    
                    tempOffset++;
                    emitComment((char*)"TOFF:", tempOffset);
                    emitRM((char *)"LD", 4, tempOffset, 1,(char *)("Pop index")); 

                    if(leftSide->child[0]->memT == Global || leftSide->child[0]->memT == LocalStatic){
                        emitRM((char *)"LDA", 5, leftSide->child[0]->mOffset, 0, (char *)("Load address of base of array 383"), (char *)leftSide->child[0]->attr.name);
                    }
                    else{
                        if(t->child[1]->child[1] != NULL){
                            emitRM((char *)"LD", 5, leftSide->child[0]->mOffset, 1, (char *)("Load address of base of array 401"), (char *)leftSide->child[0]->attr.name);

                        }
                        else if(nestAsgn){
                            emitRM((char *)"LD", 5, leftSide->child[0]->mOffset, 1, (char *)("Load address of base of array 401"), (char *)leftSide->child[0]->attr.name);
                        }
                        
                        else{
                            emitRM((char *)"LDA", 5, leftSide->child[0]->mOffset, 1, (char *)("Load address of base of array 390"), (char *)leftSide->child[0]->attr.name);
                        }
                    }
                    emitRO((char *)"SUB", 5, 5, 4, (char *)("Compute offset of value"));
					emitRM((char *)"ST", 3, 0, 5, (char *)("Store variable"), (char *)leftSide->child[0]->attr.name);
                    nestAsgn = false;
                }
                //not an array
                else{
                    emitStart(rightSide);
                    stFlag = true;
                    isUnary = true;
                    emitStart(leftSide);
                    
                }
            }

            //check for ++ --
            else if(rightSide == NULL){

                stFlag = false;
                isUnary = true;

                emitStart(leftSide);

                if(!strcmp(leftSide->attr.name, "[")){

                    leftSide = leftSide->child[0];
                    opKarr = true;
                }

                if(!strcmp(t->attr.name, "++"))
				{
					emitRM((char *)"LDA", 3, 1, 3, (char *)("increment value of"), (char *)leftSide->attr.name);
				}
				else if(!strcmp(t->attr.name, "--"))
				{
					emitRM((char *)"LDA", 3, -1, 3, (char *)("decrement value of"), (char *)leftSide->attr.name);
				}
	
                if(opKarr){
                   emitRM((char *)"ST", 3, 0, 5,(char *)("Store variable"), (char *)leftSide->attr.name); 
                }
                else{
				    emitRM((char *)"ST", 3, leftSide->mOffset, 1,(char *)("Store variable"), (char *)leftSide->attr.name);
                }
                leftSide = t->child[0];
            }

            else{

                //check for array, need to do unique stuff
                //for an array version
                //load address of base of array will probably need global checks
                if(!strcmp(leftSide->attr.name, "[")){

                   emitStart(leftSide->child[1]);
                   emitRM((char *)"ST", 3, tempOffset, 1, (char *)("Push index 446"));

                   tempOffset--;
                   emitComment((char*)"TOFF:", tempOffset);

                    //array index to array index assignment
                   if(rightSide->child[1] != NULL){
                   emitRM((char *)"LDA", 3, rightSide->child[0]->mOffset, 0, (char *)("Load address of base of array 446"), (char *)rightSide->child[0]->attr.name);
                   emitRM((char *)"ST", 3, tempOffset, 1, (char *)"Push left side");
                   emitStart(rightSide->child[1]);
                   emitRM((char *)"LD", 4, tempOffset, 1, (char *)"Pop left into ac1");
                   emitStart(rightSide->child[0]);
                   emitRO((char *)"SUB", 3, 4, 3, (char *)"Compute location from index");
                   emitRM((char *)"LD", 3, 0, 3, (char *)"Load array element");

                   tempOffset++;
                   emitComment((char*)"TOFF:", tempOffset);

                   emitRM((char *)"LD", 4, tempOffset, 1, (char *)("Pop index"));
                   emitRM((char *)"LDA", 5, leftSide->child[0]->mOffset, 0, (char *)("Load address of base of array 458"), (char *)leftSide->child[0]->attr.name);
                   emitRO((char *)"SUB", 5, 5, 4, (char *)"Compute offset of value");
                   emitRM((char *)"LD", 4, 0, 5, (char *) "Load LHS variable 499");
                   }
                   else{
                       emitStart(rightSide);
                       tempOffset++;
                       emitComment((char*)"TOFF:", tempOffset);
                       emitRM((char *)"LD", 4, tempOffset, 1, (char *)"Pop index");
                       emitRM((char *)"LD", 5, leftSide->child[0]->mOffset, 1, (char *)("Load address of base of array 458"), (char *)leftSide->child[0]->attr.name);
                       emitRO((char *)"SUB", 5, 5, 4, (char *)"Compute offset of value");
                       emitRM((char *)"LD", 4, 0, 5, (char *) "Load LHS variable 508");
                   }

                   
                   
                    if(!strcmp(t->attr.name, "+=")){

                        emitRO((char *)"ADD", 3, 4, 3, (char *)("Op"), (char *)t->attr.name);
                    }
                    else if(!strcmp(t->attr.name, "-=")){
                        emitRO((char *)"SUB", 3, 4, 3, (char *)("Op"), (char *)t->attr.name);
                    }
                        else if(!strcmp(t->attr.name, "*=")){
                        emitRO((char *)"MUL", 3, 4, 3, (char *)("Op"), (char *)t->attr.name);
                    }
                        else if(!strcmp(t->attr.name, "/=")){
                        emitRO((char *)"DIV", 3, 4, 3, (char *)("Op"), (char *)t->attr.name);
                    }
                    //store
                    if(leftSide->child[0] != NULL){
                        emitRM((char *)"ST", 3, leftSide->mOffset, 5, (char *)("Store variable"),(char *)leftSide->child[0]->attr.name);
                    }
                    else{
                        emitRM((char *)"ST", 3, leftSide->mOffset, 5, (char *)("Store variable"),(char *)leftSide->attr.name);
                    }
                    
                }
                else{

                    stFlag = false;
                    emitStart(rightSide);
                    isUnary = false;
                    emitStart(leftSide);

                    //check for each other assignment operator
                    if(!strcmp(t->attr.name, "+=")){

                        emitRM((char *)"LD", 4, leftSide->mOffset, 0, (char *) "Load LHS var");
                        emitRO((char *)"ADD", 3, 4, 3, (char *)("Op"), (char *)t->attr.name);
                    }
                    else if(!strcmp(t->attr.name, "-=")){
                        emitRM((char *)"LD", 4, leftSide->mOffset, 0, (char *) "Load LHS var");
                        emitRO((char *)"SUB", 3, 4, 3, (char *)("Op"), (char *)t->attr.name);
                    }
                    else if(!strcmp(t->attr.name, "*=")){
                        emitRM((char *)"LD", 4, leftSide->mOffset, 0, (char *) "Load LHS var");
                        emitRO((char *)"MUL", 3, 4, 3, (char *)("Op"), (char *)t->attr.name);
                    }
                    else if(!strcmp(t->attr.name, "/=")){
                        emitRM((char *)"LD", 4, leftSide->mOffset, 0, (char *) "Load LHS var");
                        emitRO((char *)"DIV", 3, 4, 3, (char *)("Op"), (char *)t->attr.name);
                    }
                
				
                    //check mem types
                    if(leftSide->memT == Global || leftSide->memT == LocalStatic){

                        emitRM((char *)"ST", 3, leftSide->mOffset, 0, (char *)("Store variable"), (char *)leftSide->attr.name);
                    }
                    else{

                        emitRM((char *)"ST", 3, leftSide->mOffset, 1, (char *)("Store variable"), (char *)leftSide->attr.name);
                        
                    }
                    //reset unary flag
                    isUnary = true;
                }
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

                    if(t->child[0]->memT == Global || t->child[0]->memT == LocalStatic){

                        emitRM((char *)"LDA", 3, leftSide->mOffset, 0, (char *)("Load address of base of array 540"), (char *)leftSide->attr.name);
                    }
                    else if(t->child[0]->memT == Parameter){
                        emitRM((char *)"LD", 3, leftSide->mOffset, 1, (char *)("Load address of base of array 543"), (char *)leftSide->attr.name);
                    }
                    else{
                        emitRM((char *)"LDA", 3, leftSide->mOffset, 1, (char *)("Load address of base of array 546"), (char *)leftSide->attr.name);
                    }
                    emitRM((char *)"LD", 3, 1, 3, (char *)("Load array size"));
                }

                else if(!strcmp(t->attr.name, "?")){

                    emitRO((char *)"RND", 3, 3, 6, (char *)("Op unary"), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, "NOT") || !strcmp(t->attr.name, "not")){

                    emitRM((char *)"LDC", 4, 1, 6, (char *)("Load 1"));
					emitRO((char *)"XOR", 3, 3, 4, (char *)("Op XOR to get logical not"));
                }
            }
            //binary checks
            else{

                
                stFlag = false;

                //move past index in use
                //tmpIdx--; 

                //attempt to fix issues with arrays so far...but it
                //seems to be causing problems with c0f.c-
                if(!strcmp(t->attr.name, "[")){

                    //tmpIdx = tempOffset;
                    if(isUnary == false){
                        if(leftSide->isArray){

                            if(leftSide->memT == Global || leftSide->memT == LocalStatic){
                                emitRM((char *)"LDA", 3, leftSide->mOffset, 0, (char *)"1 Load address of base of array 578", (char*)leftSide->attr.name);
                            }
                            //might need to add this later
                            
                            else if(leftSide->memT == Parameter){
                                emitRM((char *)"LD", 3, leftSide->mOffset, 1, (char *)"2 Load address of base of array 583", (char*)leftSide->attr.name);
                            }
                            
                            else{
                                emitRM((char *)"LDA", 3, leftSide->mOffset, 1, (char *)"2 Load address of base of array 587", (char*)leftSide->attr.name);
                            }

                            emitRM((char *)"ST", 3, tempOffset, 1, (char *)"Push left side");
                            tempOffset--;
                            emitComment((char*)"TOFF:", tempOffset);
                            
                            
                            emitStart(t->child[1]);
                            

                            tempOffset++;
                            emitComment((char*)"TOFF:", tempOffset);

                            emitRM((char *)"LD", 4, tempOffset, 1, (char *)"1 Pop left into ac1");
                            emitRO((char *)"SUB", 3, 4, 3, (char *)"1 Compute location from index");
                            emitRM((char *)"LD", 3, 0, 3, (char *)"1 Load array element");

                        }
                    }
                    else{

                        if(leftSide->isArray){

                        tempOffset--;
                        emitComment((char*)"TOFF:", tempOffset);

                        emitStart(rightSide);

                        tempOffset++;
                        emitComment((char*)"TOFF:", tempOffset);

                        if(leftSide->memT == Global || leftSide->memT == LocalStatic){
                             emitRM((char *)"LDA", 5, leftSide->mOffset, 0, (char *)"1 Load address of base of array 620", (char*)leftSide->attr.name);
                        }
                        else if(leftSide->memT == Parameter){
                            emitRM((char *)"LD", 5, leftSide->mOffset, 1, (char *)"2 Load address of base of array 623", (char*)leftSide->attr.name);
                        }
                        else{
                            emitRM((char *)"LDA", 5, leftSide->mOffset, 1, (char *)"3 Load address of base of array 626", (char*)leftSide->attr.name);
                        }

                        emitRO((char *)"SUB", 5, 5, 3, (char *)"2 Compute location from index");
                        emitRM((char *)"LD", 3, 0, 5, (char *)"2 Load array element");

                        }


                    }
                }
                else{

                    emitStart(t->child[0]);

                    //save temp index from where we are
                    //tmpIdx = tempOffset;  

                    emitRM((char*)"ST", 3, tempOffset, 1, (char*)("Push the left side 677"));
                    tempOffset--;
                    emitComment((char*)"TOFF:", tempOffset);


                    emitStart(t->child[1]);

                    tempOffset++;
                    emitComment((char*)"TOFF:", tempOffset);
                    emitRM((char*)"LD", 4, tempOffset, 1, (char*)("Load Left into 1"), (char*)t->attr.name);
                }
                

                if(!strcmp(t->attr.name, "AND") || !strcmp(t->attr.name, "and")){
                    emitRO((char *)"AND", 3, 4, 3, (char *)("Op AND"), (char *)t->attr.name);
                }
                else if(!strcmp(t->attr.name, "OR") || !strcmp(t->attr.name, "or")){
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
                else if(!strcmp(t->attr.name, "=")){
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
                else if(!strcmp(t->attr.name, "*")){
                    emitRO((char *)"MUL", 3, 4, 3, (char *)("Op *"), (char *)t->attr.name);
                }
                //additional check for array here?
                //else if(!strcmp(t->attr.name, "[")){
                    
                //}

            }
            //tempOffset = tmpIdx;
            break;

        case ConstantK:

            if(t->expType == Integer){
                emitRM((char *)"LDC", 3, t->attr.value, 6,(char *)"Load Integer constant");
            }
            //printing out weird values when using t->attr.value in Boolean
            //trying to fix by manually setting
            else if(t->expType == Boolean){

                int boolVal;

                if(!strcmp(t->attr.name, "true")){
                    boolVal = 1;
                }
                else{
                    boolVal = 0;
                }
                emitRM((char *)"LDC", 3, boolVal, 6,(char *)"Load Boolean constant");
            }
            else if(t->expType == Char){
                emitRM((char *)"LDC", 3, t->attr.cvalue, 6,(char *)"Load Character constant");
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
                else if(t->memT == Parameter){
                    emitRM((char *)"ST", 3, t->mOffset, 1, (char *)("Store variable"), t->attr.name);
                    stFlag = false;
                }

            }
            //load
            else{

                if(t->memT == Global || t->memT == LocalStatic){

                    if(isUnary){
                        
                        if(t->isArray){
                            emitRM((char *)" LDA", 3, t->mOffset, 0, (char *)("1 Load address of base of array 671"), t->attr.name);
                            tempOffset--;
                            emitComment((char*)"TOFF:", tempOffset);
                        }
                        else{
                            emitRM((char *)"LD", 3, t->mOffset, 0, (char *)("1 Load variable 797"), t->attr.name);
                        }
                    }
                    else{
                        //emitRM((char *)"LD", 4, t->mOffset, 0, (char *)("1 load lhs variable"), t->attr.name);
                    }
                }

                else if(t->memT == Local){

                    if(isUnary){
                        
                        if(t->isArray){
                            emitRM((char *)" LDA", 3, t->mOffset, 1, (char *)("2 Load address of base of array 783"), t->attr.name);
                            //tempOffset--;
                            emitComment((char*)"TOFF:", tempOffset);
                        }
                        else{
                            emitRM((char *)"LD", 3, t->mOffset, 1, (char *)("2 Load variable 815"), t->attr.name);
                        }
                    }
                    else{
                        if(!t->isInit){
                            if(t->isArray){
                                //tempOffset--;
                                 //emitRM((char *)"LD", 3, t->mOffset, 1, (char *)("load address of base of array 836"), t->attr.name);
                            }
                            else{
                                
                            emitRM((char *)"LD", 3, t->mOffset, 1, (char *)("1 load variable 851"), t->attr.name);
                            }
                        }
                        else if(t->isInit && !t->isArray){
                            //emitRM((char *)"LD", 3, t->mOffset, 1, (char *)("1 load variable 862"), t->attr.name);
                        }
                        //emitRM((char *)"LD", 4, t->mOffset, 1, (char *)("2 load lhs variable"), t->attr.name);
                    }
                }

                else if(t->memT == LocalStatic){

                    if(isUnary){
                        
                        if(t->isArray){
                            emitRM((char *)" LDA", 3, t->mOffset, 0, (char *)("3 Load address of base of array 802"), t->attr.name);
                            tempOffset--;
                            emitComment((char*)"TOFF:", tempOffset);
                        }
                        else{
                            emitRM((char *)"LD", 3, t->mOffset, 0, (char *)("3 Load variable 833"), t->attr.name);
                        }
                    }
                    else{
                        //emitRM((char *)"LD", 4, t->mOffset, 0, (char *)("3 load lhs variable"), t->attr.name);
                    }
                }

                else if(t->memT == Parameter){

                    if(isUnary){
                        
                        if(t->isArray){
                            emitRM((char *)" LDA", 3, t->mOffset, 1, (char *)("4 Load address of base of array 820"), t->attr.name);
                            tempOffset--;
                            emitComment((char*)"TOFF:", tempOffset);
                        }
                        else{
                            emitRM((char *)"LD", 3, t->mOffset, 1, (char *)("4 Load variable 851"), t->attr.name);
                        }
                    }
                    else{
                        //printf("Here IdK: %s %d\n", t->attr.name, t->linenum);
                        if(!t->isInit){
                            if(t->isArray){
                                tempOffset--;
                                 emitRM((char *)"LD", 3, t->mOffset, 1, (char *)("load address of base of array 836"), t->attr.name);
                            }
                            else{
                                
                            emitRM((char *)"LD", 3, t->mOffset, 1, (char *)("1 load variable 861"), t->attr.name);
                            }
                        }
                        else if(t->isInit && !t->isArray){
                            emitRM((char *)"LD", 3, t->mOffset, 1, (char *)("1 load variable 861"), t->attr.name);
                        }
                        //emitRM((char *)"LD", 4, t->mOffset, 1, (char *)("4 load lhs variable"), t->attr.name);
                    }
                }
            }

            break;

            case CallK:{
            
                int tmpIdx = tempOffset;

                emitComment((char*)("CALL EXPRESSION"));

                //track param count and if call has params(children)
                int pCount = 0;
                bool hasChild = false;

                //lookup original fn decl from symbol table
                TreeNode* curFunc = (TreeNode*)symbolTable.lookup(t->attr.name);

                //print call name
                emitComment((char*)"CALL", t->attr.name);

                if(t->child[0] != NULL){

                    hasChild = true;
                    TreeNode* getParams = t->child[0];

                    for(int i = 0; i < MAXCHILDREN; i++){
                        if(getParams != NULL){

                            getParams = getParams->sibling;
                            pCount++;
                        }
                    }

                    //printf("pCount: %d\n", pCount);

                    //tempOffset -= pCount;

                    //check single parameter
                    if(pCount == 1){

                        //printf("%s\n", t->child[0]->attr.name);

                        if(t->child[0]->subkind.exp == IdK && !t->child[0]->isArray){
                            if(t->child[0]->isInit){
                            tempOffset--;
                            tmpIdx--;
                            emitComment((char*)"TOFF:", tempOffset);
                            }
                        }

                        //tempOffset -= pCount;


                        emitRM((char *)"ST", 1, tempOffset, 1, (char *)("1 Store fp in ghost frame for"), (char *)t->attr.name);

                        emitComment((char*)"Param 1");

                        if(t->child[0]->subkind.exp == IdK && !t->child[0]->isInit){

                            if(t->child[0]->memT == Global || t->child[0]->memT == LocalStatic){

                                if(t->child[0]->isArray){
                                    emitRM((char *)"LDA", 3, t->child[0]->mOffset, 0, (char *)("Load address of base of array 908"), t->child[0]->attr.name);
                                    tempOffset--;
                                }
                                else{
                                    emitRM((char *)"LD", 3, t->child[0]->mOffset, 0, (char *)("1 variable"), t->child[0]->attr.name);
                                }
                            
                            }
                            else if(t->child[0]->memT == Parameter){
                                
                                if(!t->child[0]->isArray){
                                //emitRM((char *)"LD", 3, t->child[0]->mOffset, 1, (char *)("2 variable"), t->child[0]->attr.name);
                                }
                            }
                            /*else{
                                //printf("call name %s, %d\n", t->attr.name, t->linenum);
                            }*/
                            else if(t->child[0]->memT == Local){
                                if(t->child[0]->isArray){
                                emitRM((char *)"LDA", 3, t->child[0]->mOffset, 1, (char *)("load address of base of array 916"), t->child[0]->attr.name);
                                tempOffset--;
                                }
                            }
                        }

                        tempOffset-= pCount;
                        emitComment((char*)"TOFF:", tempOffset);

                        //if not array, adjust temp offset
                        if(!t->child[0]->isArray){

                            tempOffset -= pCount;
                            stFlag = false;
                        }
                        /*else if(nestCall){
                            emitRM((char *)"LDA", 3, t->child[0]->mOffset, 1, (char *)("Load address of base of array 913"));
                            tempOffset-=pCount;
                            nestCall = false;
                        }*/
                        

                        emitComment((char*)"TOFF:", tempOffset);

                        if(t->child[0]->subkind.exp == CallK){
                            nestCall = true;
                        }
                        
                        emitStart(t->child[0]);
                        
                        

                        //printf("%d\n", isUnary);

                        emitRM((char *)"ST", 3, tempOffset, 1,(char *)"Push parameter 1001");
                        emitComment((char *)("Param end"), t->attr.name);
                        emitRM((char *)"LDA", 1, tmpIdx, 1,(char *)"1 Ghost frame becomes new active frame");
                        
                    }

                    //more than 1 parameter
                    else if(pCount > 1){
                        //set base number of parms
                        int parmIterator = 1;
                        TreeNode *curChild;
                        //tempOffset++;
                        emitComment((char*)"TOFF:", tempOffset);

                        emitRM((char *)"ST", 1, tempOffset, 1, (char *)("2 Store fp in ghost frame for"), (char *)t->attr.name);

                        if(t->child[0]->subkind.exp == IdK || t->child[0]->subkind.exp == OpK){

                            curChild = (TreeNode*)symbolTable.lookup(t->child[0]->attr.name);

                            //printf("Here: %s %d", curChild->attr.name, t->linenum);

                            //check for array
                            /*if(!strcmp(t->child[0]->attr.name, "[")){
                                printf("Open Bracket %s\n", t->child[0]->attr.name);
                            }*/

                            if(curChild == NULL){

                            curChild = t->child[0];
                            }

                        }
                        else{
                            curChild = t->child[0];
                        }
                        tempOffset--;
                        emitComment((char*)"TOFF:", tempOffset);

                        //check for arrays
                        if(t->child[0]->subkind.exp != ConstantK && !strcmp(t->child[0]->attr.name, "[")){
                            
                            if(t->child[0] != NULL){
                                
                                mpCall = true;
                                tempOffset--;
                                emitComment((char*)"TOFF:", tempOffset);
                                emitComment((char *)("1035 Param"), parmIterator);

                                /*if(t->child[0]->child[0]->isArray){
                                    
                                    if(t->child[0]->child[0]->memT == Global){
                                        emitRM((char *)"LDA", 3, t->child[0]->child[0]->mOffset, 0, (char *)("MP: Load address of base of array"));
                                    }
                                    else{
                                        emitRM((char *)"LDA", 3, t->child[0]->child[0]->mOffset, 1, (char *)("MP: Load address of base of array"));
                                    }
                                    emitRM((char *)"ST", 3, tempOffset, 1,(char *)("Push parameter"));
                                    emitRM((char *)"LD", 4, tempOffset, 1, (char *)"1 Pop left into ac1");
                                    emitRO((char *)"SUB", 3, 4, 3, (char *)"1 Compute location from index");
                                    emitRM((char *)"LD", 3, 0, 3, (char *)"1 Load array element");
                                }*/
                                emitStart(t->child[0]);
                                emitRM((char *)"ST", 3, tempOffset, 1,(char *)("Push parameter 1064"));
                                t->codeLine -= 1;

                                if(t->child[0]->sibling != NULL){
                                    curChild = t->child[0]->sibling;
                                }
                                parmIterator++;
                                mpCall = false;


                            }
                        }

                        //loop through all children (parameters)
                        while(curChild != NULL){

                            //printf("Here %d %d\n", parmIterator, t->linenum);

                            tempOffset--;
                            emitComment((char*)"TOFF:", tempOffset);
                            emitComment((char *)("1071 Param"), parmIterator);

                            //check for arrays
                            if(curChild->isArray){

                                //check mem types
                                if(curChild->memT == Global || curChild->memT == LocalStatic){

                                    //check first parameter
                                    //if(pCount == 1){

                                        emitRM((char *)"LDA", 3, curChild->mOffset, 0, (char *)("Load address of base of array 1025"), (char *)curChild->attr.name);
                                    //}
                                    /*else{

                                        emitRM((char *)"LDA", 3, curChild->mOffset, 0, (char *)("Load address of base of array"), (char *)curChild->attr.name);
                                    }*/
                                }
                                else{

                                    //check first parameter
                                    if(t->child[0]->subkind.exp == OpK){

                                        emitRM((char *)"LD", 3, curChild->mOffset, 1, (char *)("Load address of base of array 1119"), (char *)curChild->attr.name);
                                    }
                                    else{

                                        emitRM((char *)"LDA", 3, curChild->mOffset, 1, (char *)("Load address of base of array 1123"), (char *)curChild->attr.name);
                                    }                                   
                                }
                                emitRM((char *)"ST", 3, tempOffset, 1,(char *)("1101 Push parameter"));
                            }

                            else if(curChild->subkind.exp == OpK || curChild->subkind.exp == IdK){

                                /*emitStart(curChild->child[0]);
                                emitRM((char *)"ST", 3, tempOffset, 1,(char *)("Push left side"));
                                emitStart(curChild->child[1]);
                                */
                                mpCall = true;
                                emitStart(curChild);
                                
                                
                                emitRM((char *)"ST", 3, tempOffset, 1,(char *)("1115 Push parameter"));
                                mpCall = false;
                                
                            }
                            
                            //not an array
                            else{
                                
                                if(curChild->expType == Integer){
                                    emitRM((char *)"LDC", 3, curChild->attr.value, 6, (char *)"Load integer constant");
                                }
                                else if(curChild->expType == Boolean){
                                    
                                    int boolVal;

                                    if(!strcmp(t->attr.name, "true")){
                                        boolVal = 1;
                                    }
                                    else{
                                        boolVal = 0;
                                    }
                                    emitRM((char *)"LDC", 3, boolVal, 6,(char *)"Load Boolean constant");
                                }
                                else if(curChild->expType == Char){
                                    emitRM((char *)"LDC", 3, curChild->attr.value, 6, (char *)"Load character constant");
                                }
                                emitRM((char *)"ST", 3, tempOffset, 1,(char *)"3 Push parameter");
                            }

                            //increment parmiterator
                            parmIterator++;
                            if(curChild->sibling != NULL){
                                curChild = curChild->sibling;
                            }
                            else{
                                curChild = NULL;
                            }
                        }
                        emitComment((char *)("Param end"), t->attr.name);
					    emitRM((char *)"LDA", 1, tmpIdx, 1,(char *)"Ghost frame becomes new active frame");

                    }
                }
                //no parameters
                else if(pCount == 0){
                    emitRM((char *)"ST", 1, tmpIdx, 1, (char *)("3 Store fp in ghost frame for"), (char *)t->attr.name);
                    emitComment((char *)("Param end"), t->attr.name);
                    emitRM((char *)"LDA", 1, tempOffset, 1,(char *)"Ghost frame becomes new active frame");
                }

                curFunc = (TreeNode*)symbolTable.lookup(t->attr.name);
                emitRM((char *)"LDA", 3, 1, 7,(char *)"Return address in ac");
                int backpatch = emitSkip(0);
                emitRM((char *)"JMP",7, curFunc->codeLine - backpatch - 1, 7, (char *)("CALL OUTPUT"), t->attr.name);       
                emitRM((char *)"LDA", 3, 0, 2,(char *)"Save the result in ac");
                emitComment((char *)("CALL end"), t->attr.name);

                tempOffset = tmpIdx;
                emitComment((char*)"TOFF:", tempOffset);

                break;
            }
    }
}

void emitGlobAndStats(TreeNode* t){

    if(t != NULL){

        if(t->nodekind == DeclK && t->subkind.decl == VarK){

            if(t->memT == Global || t->isStatic){

                if(t->isArray){

                    emitRM((char *)"LDC", 3, t->mSize - 1, 6,(char *)"load size of array", (char *) t->attr.name);
				    emitRM((char *)"ST", 3, t->mOffset + 1, 0,(char *)"save size of array", (char *) t->attr.name);
                }
                else{

                    if(t->child[0] != NULL){
                    emitStart(t->child[0]);
                    emitRM((char *)"ST", 3, t->mOffset, 0,(char *)"Store variable",(char *)t->attr.name);
                    }
                }
            }
        }

        for(int i = 0; i < MAXCHILDREN; i++){
            emitGlobAndStats(t->child[i]);
        }
        if(t->sibling != NULL){
            emitGlobAndStats(t->sibling);
        }
    }
    
}

void emitIO(TreeNode *t){

    emitSkip(1);
	emitComment((char *)("** ** ** ** ** ** ** ** ** ** ** **"));
	emitComment((char *)("FUNCTION input"));
	TreeNode *curIO = (TreeNode*)symbolTable.lookup((char *)("input"));
	emitRM((char *)"ST", 3, -1, 1,(char *)"Store return address");
	curIO->codeLine = emitSkip(0)-1;
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
	curIO->codeLine = emitSkip(0)-1;
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
	curIO->codeLine = emitSkip(0)-1;
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
	curIO->codeLine = emitSkip(0)-1;
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
	curIO->codeLine = emitSkip(0)-1;
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
	curIO->codeLine = emitSkip(0)-1;
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
	curIO->codeLine = emitSkip(0)-1;
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
	emitRM((char *)"LDA", 1, 0 + goffset, 0, (char *)("set first frame at end of globals"));
	emitRM((char *)"ST", 1, 0, 1, (char *)("store old fp (point to self)"));
	emitComment((char *)("INIT GLOBALS AND STATICS"));
	emitGlobAndStats(t);
	emitComment((char *)("END INIT GLOBALS AND STATICS"));
	emitRM((char *)"LDA", 3, 1, 7, (char *)("Return address in ac"));
	bp = emitSkip(0);
	emitRM((char *)"JMP", 7, (mainFunc->codeLine-bp-1), 7, (char *)("Jump to main"));
	emitRO((char *)"HALT", 0, 0, 0, (char *)("DONE!"));
	emitComment((char *)("END INIT"));
}
