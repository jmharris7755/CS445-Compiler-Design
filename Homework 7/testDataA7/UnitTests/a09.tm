* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/a09.tm
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
  7:     LD  3,-2(1)	Load parameter 
  8:    OUT  3,3,3	Output integer 
  9:     LD  3,-1(1)	Load return address 
 10:     LD  1,0(1)	Adjust fp 
 11:    JMP  7,0(3)	Return 
* END FUNCTION output
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION inputb
 12:     ST  3,-1(1)	Store return address 
 13:    INB  2,2,2	Grab bool input 
 14:     LD  3,-1(1)	Load return address 
 15:     LD  1,0(1)	Adjust fp 
 16:    JMP  7,0(3)	Return 
* END FUNCTION inputb
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION outputb
 17:     ST  3,-1(1)	Store return address 
 18:     LD  3,-2(1)	Load parameter 
 19:   OUTB  3,3,3	Output bool 
 20:     LD  3,-1(1)	Load return address 
 21:     LD  1,0(1)	Adjust fp 
 22:    JMP  7,0(3)	Return 
* END FUNCTION outputb
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION inputc
 23:     ST  3,-1(1)	Store return address 
 24:    INC  2,2,2	Grab char input 
 25:     LD  3,-1(1)	Load return address 
 26:     LD  1,0(1)	Adjust fp 
 27:    JMP  7,0(3)	Return 
* END FUNCTION inputc
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION outputc
 28:     ST  3,-1(1)	Store return address 
 29:     LD  3,-2(1)	Load parameter 
 30:   OUTC  3,3,3	Output char 
 31:     LD  3,-1(1)	Load return address 
 32:     LD  1,0(1)	Adjust fp 
 33:    JMP  7,0(3)	Return 
* END FUNCTION outputc
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION outnl
 34:     ST  3,-1(1)	Store return address 
 35:  OUTNL  3,3,3	Output a newline 
 36:     LD  3,-1(1)	Load return address 
 37:     LD  1,0(1)	Adjust fp 
 38:    JMP  7,0(3)	Return 
* END FUNCTION outnl
* 
* ** ** ** ** ** ** ** ** ** ** ** **
* FUNCTION main
 39:     ST  3,-1(1)	Store return address 
* COMPOUND
* ASSIGNMENT EXPRESSION
 40:    LDC  3,176(6)	Load Character constant 
 41:     LD  4,0(0)	1 load lhs variable x
 42:     ST  3,0(0)	Store variable x
* ASSIGNMENT EXPRESSION
 43:    LDC  3,192(6)	Load Character constant 
 44:     LD  4,-2(1)	2 load lhs variable y
 45:     ST  3,-2(1)	Store variable y
* CALL EXPRESSION
* CALL outputc
 46:     ST  1,0(1)	2 Store fp in ghost frame for outputc
 47:    LDC  3,-996481648(6)	Load character constant 
 48:     ST  3,-2(1)	Push parameter 
* Param end outputc
 49:    LDA  1,0(1)	Ghost frame becomes new active frame 
 50:    LDA  3,1(7)	Return address in ac 
 51:    JMP  7,-24(7)	CALL outputc
 52:    LDA  3,0(2)	Save the result in ac 
* CALL end outputc
* CALL EXPRESSION
* CALL outnl
 53:     ST  1,0(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 54:    LDA  1,0(1)	Ghost frame becomes new active frame 
 55:    LDA  3,1(7)	Return address in ac 
 56:    JMP  7,-23(7)	CALL outnl
 57:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* CALL EXPRESSION
* CALL outputc
 58:     ST  1,0(1)	2 Store fp in ghost frame for outputc
 59:    LDC  3,-996479456(6)	Load character constant 
 60:     ST  3,-2(1)	Push parameter 
* Param end outputc
 61:    LDA  1,0(1)	Ghost frame becomes new active frame 
 62:    LDA  3,1(7)	Return address in ac 
 63:    JMP  7,-36(7)	CALL outputc
 64:    LDA  3,0(2)	Save the result in ac 
* CALL end outputc
* CALL EXPRESSION
* CALL outnl
 65:     ST  1,0(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 66:    LDA  1,0(1)	Ghost frame becomes new active frame 
 67:    LDA  3,1(7)	Return address in ac 
 68:    JMP  7,-35(7)	CALL outnl
 69:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* Compound Body
* END COMPOUND
* Add standard closing in case there is no return statement
 70:    LDC  2,0(6)	Set return value to 0 
 71:     LD  3,-1(1)	Load return address 
 72:     LD  1,0(1)	Adjust fp 
 73:    JMP  7,0(3)	Return 
* END FUNCTION main
  0:    JMP  7,73(7)	Jump to init [backpatch] 
* INIT
 74:    LDA  1,-1(0)	set first frame at end of globals 
 75:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
 76:    LDA  3,1(7)	Return address in ac 
 77:    JMP  7,-77(7)	Jump to main 
 78:   HALT  0,0,0	DONE! 
* END INIT
