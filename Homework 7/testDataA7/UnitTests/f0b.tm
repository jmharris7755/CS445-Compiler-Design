* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/f0b.tm
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
* FUNCTION cat
 39:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -2
* CALL EXPRESSION
* CALL output
 40:     ST  1,-2(1)	1 Store fp in ghost frame for output
* Param 1
 41:     LD  3,0(0)	1 variable z
* TOFF: -3
* TOFF: -4
 42:     ST  3,-4(1)	Push parameter 
* Param end output
 43:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
 44:    LDA  3,1(7)	Return address in ac 
 45:    JMP  7,-40(7)	CALL OUTPUT output
 46:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -2
* ASSIGNMENT EXPRESSION
 47:    LDC  3,99(6)	Load Integer constant 
 48:     ST  3,0(0)	Store variable z
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
 49:    LDC  2,0(6)	Set return value to 0 
 50:     LD  3,-1(1)	Load return address 
 51:     LD  1,0(1)	Adjust fp 
 52:    JMP  7,0(3)	Return 
* END FUNCTION cat
* TOFF: -2
* FUNCTION main
 53:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -2
* ASSIGNMENT EXPRESSION
 54:    LDC  3,1001(6)	Load Integer constant 
 55:     ST  3,0(0)	Store variable z
* CALL EXPRESSION
* CALL cat
 56:     ST  1,-2(1)	3 Store fp in ghost frame for cat
* Param end cat
 57:    LDA  1,-2(1)	Ghost frame becomes new active frame 
 58:    LDA  3,1(7)	Return address in ac 
 59:    JMP  7,-21(7)	CALL OUTPUT cat
 60:    LDA  3,0(2)	Save the result in ac 
* CALL end cat
* TOFF: -2
* CALL EXPRESSION
* CALL output
 61:     ST  1,-2(1)	1 Store fp in ghost frame for output
* Param 1
 62:     LD  3,0(0)	1 variable z
* TOFF: -3
* TOFF: -4
 63:     LD  3,0(0)	1 Load variable z
 64:     ST  3,-4(1)	Push parameter 
* Param end output
 65:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
 66:    LDA  3,1(7)	Return address in ac 
 67:    JMP  7,-62(7)	CALL OUTPUT output
 68:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -2
* CALL EXPRESSION
* CALL outnl
 69:     ST  1,-2(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 70:    LDA  1,-2(1)	Ghost frame becomes new active frame 
 71:    LDA  3,1(7)	Return address in ac 
 72:    JMP  7,-39(7)	CALL OUTPUT outnl
 73:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -2
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
 74:    LDC  2,0(6)	Set return value to 0 
 75:     LD  3,-1(1)	Load return address 
 76:     LD  1,0(1)	Adjust fp 
 77:    JMP  7,0(3)	Return 
* END FUNCTION main
* TOFF: -2
  0:    JMP  7,77(7)	Jump to init [backpatch] 
* INIT
 78:    LDA  1,-1(0)	set first frame at end of globals 
 79:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
 80:    LDA  3,1(7)	Return address in ac 
 81:    JMP  7,-29(7)	Jump to main 
 82:   HALT  0,0,0	DONE! 
* END INIT
