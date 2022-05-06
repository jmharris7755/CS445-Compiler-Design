* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/c09.tm
* 
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
* TOFF:  -2
* ASSIGNMENT EXPRESSION
 40:    LDC  3,753(6)	Load Integer constant 
 41:     ST  3,0(0)	Store variable x
* ASSIGNMENT EXPRESSION
 42:    LDC  3,444(6)	Load Integer constant 
 43:     ST  3,-1(0)	Store variable y
* ASSIGNMENT EXPRESSION
 44:     LD  3,-1(0)	1 Load variable y
 45:     LD  4,0(0)	Load LHS var 
 46:    ADD  3,4,3	Op +=
 47:     ST  3,0(0)	Store variable x
* CALL EXPRESSION
* CALL output
 48:     ST  1,-2(1)	1 Store fp in ghost frame for output
* Param 1
 49:     LD  3,0(0)	1 variable x
* TOFF: -3
* TOFF: -4
 50:     LD  3,0(0)	1 Load variable x
 51:     ST  3,-4(1)	Push parameter 
* Param end output
 52:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
 53:    LDA  3,1(7)	Return address in ac 
 54:    JMP  7,-49(7)	CALL OUTPUT output
 55:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -2
* ASSIGNMENT EXPRESSION
 56:     LD  3,0(0)	1 Load variable x
 57:     LD  4,-1(0)	Load LHS var 
 58:    SUB  3,4,3	Op -=
 59:     ST  3,-1(0)	Store variable y
* CALL EXPRESSION
* CALL output
 60:     ST  1,-2(1)	1 Store fp in ghost frame for output
* Param 1
 61:     LD  3,-1(0)	1 variable y
* TOFF: -3
* TOFF: -4
 62:     LD  3,-1(0)	1 Load variable y
 63:     ST  3,-4(1)	Push parameter 
* Param end output
 64:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
 65:    LDA  3,1(7)	Return address in ac 
 66:    JMP  7,-61(7)	CALL OUTPUT output
 67:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -2
* CALL EXPRESSION
* CALL outnl
 68:     ST  1,-2(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 69:    LDA  1,-2(1)	Ghost frame becomes new active frame 
 70:    LDA  3,1(7)	Return address in ac 
 71:    JMP  7,-38(7)	CALL OUTPUT outnl
 72:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -2
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
 73:    LDC  2,0(6)	Set return value to 0 
 74:     LD  3,-1(1)	Load return address 
 75:     LD  1,0(1)	Adjust fp 
 76:    JMP  7,0(3)	Return 
* END FUNCTION main
* TOFF: -2
  0:    JMP  7,76(7)	Jump to init [backpatch] 
* INIT
 77:    LDA  1,-2(0)	set first frame at end of globals 
 78:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
 79:    LDA  3,1(7)	Return address in ac 
 80:    JMP  7,-42(7)	Jump to main 
 81:   HALT  0,0,0	DONE! 
* END INIT
