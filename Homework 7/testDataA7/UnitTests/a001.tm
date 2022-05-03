* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/a001.tm
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION input
  1:     ST  3,-1(1)	Store return address 
  2:     IN  2,2,2	Grab int input 
  3:     LD  3,-1(1)	Load return address 
  4:     LD  1,0(1)	Adjust fp 
  5:    JMP  7,0(3)	Return 
* END FUNCTION input
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION output
  6:     ST  3,-1(1)	Store return address 
  7:     IN  2,2,2	Grab int input 
  8:     LD  3,-1(1)	Load return address 
  9:     LD  1,0(1)	Adjust fp 
 10:    JMP  7,0(3)	Return 
* END FUNCTION output
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION output
 11:     ST  3,-1(1)	Store return address 
 12:     LD  3,-2(1)	Load parameter 
 13:    OUT  3,3,3	Output integer 
 14:     LD  3,-1(1)	Load return address 
 15:     LD  1,0(1)	Adjust fp 
 16:    JMP  7,0(3)	Return 
* END FUNCTION output
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION inputb
 17:     ST  3,-1(1)	Store return address 
 18:    INB  2,2,2	Grab bool input 
 19:     LD  3,-1(1)	Load return address 
 20:     LD  1,0(1)	Adjust fp 
 21:    JMP  7,0(3)	Return 
* END FUNCTION inputb
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION outputb
 22:     ST  3,-1(1)	Store return address 
 23:     LD  3,-2(1)	Load parameter 
 24:   OUTB  3,3,3	Output bool 
 25:     LD  3,-1(1)	Load return address 
 26:     LD  1,0(1)	Adjust fp 
 27:    JMP  7,0(3)	Return 
* END FUNCTION outputb
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION inputc
 28:     ST  3,-1(1)	Store return address 
 29:    INC  2,2,2	Grab char input 
 30:     LD  3,-1(1)	Load return address 
 31:     LD  1,0(1)	Adjust fp 
 32:    JMP  7,0(3)	Return 
* END FUNCTION inputc
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION outputc
 33:     ST  3,-1(1)	Store return address 
 34:     LD  3,-2(1)	Load parameter 
 35:   OUTC  3,3,3	Output char 
 36:     LD  3,-1(1)	Load return address 
 37:     LD  1,0(1)	Adjust fp 
 38:    JMP  7,0(3)	Return 
* END FUNCTION outputc
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION outnl
 39:     ST  3,-1(1)	Store return address 
 40:  OUTNL  3,3,3	Output a newline 
 41:     LD  3,-1(1)	Load return address 
 42:     LD  1,0(1)	Adjust fp 
 43:    JMP  7,0(3)	Return 
* END FUNCTION outnl
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION main
 44:     ST  3,-1(1)	Store return address 
* COMPOUND
 45:    LDC  3,666(6)	Load integer constant 
* END COMPOUND
* Add standard closing in case there is no return statement
 46:    LDC  2,0(6)	Set return value to 0 
 47:     LD  3,-1(1)	Load return address 
 48:     LD  1,0(1)	Adjust fp 
 49:    JMP  7,0(3)	Return 
* END FUNCTION main
  0:    JMP  7,49(7)	Jump to init [backpatch] 
* INIT
 50:    LDA  1,0(0)	set first frame at end of globals 
 51:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
 52:    LDA  3,1(7)	Return address in ac 
 53:    JMP  7,-52(7)	Jump to main 
 54:   HALT  0,0,0	DONE! 
* END INIT
