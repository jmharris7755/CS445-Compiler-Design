* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/g02.tm
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
* TOFF:  -3
* CALL EXPRESSION
* CALL output
 40:     ST  1,-3(1)	1 Store fp in ghost frame for output
* Param 1
 41:     LD  3,-2(1)	2 variable z
* TOFF: -4
* TOFF: -5
 42:     LD  3,-2(1)	1 load variable z
 43:     ST  3,-5(1)	Push parameter 
* Param end output
 44:    LDA  1,-3(1)	1 Ghost frame becomes new active frame 
 45:    LDA  3,1(7)	Return address in ac 
 46:    JMP  7,-41(7)	CALL OUTPUT output
 47:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -3
* ASSIGNMENT EXPRESSION
 48:    LDC  3,122(6)	Load Integer constant 
 49:     ST  3,-2(1)	Store variable z
* CALL EXPRESSION
* CALL output
 50:     ST  1,-3(1)	1 Store fp in ghost frame for output
* Param 1
 51:     LD  3,-2(1)	2 variable z
* TOFF: -4
* TOFF: -5
 52:     LD  3,-2(1)	4 Load variable z
 53:     ST  3,-5(1)	Push parameter 
* Param end output
 54:    LDA  1,-3(1)	1 Ghost frame becomes new active frame 
 55:    LDA  3,1(7)	Return address in ac 
 56:    JMP  7,-51(7)	CALL OUTPUT output
 57:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -3
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
 58:    LDC  2,0(6)	Set return value to 0 
 59:     LD  3,-1(1)	Load return address 
 60:     LD  1,0(1)	Adjust fp 
 61:    JMP  7,0(3)	Return 
* END FUNCTION cat
* TOFF: -2
* FUNCTION main
 62:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -3
* ASSIGNMENT EXPRESSION
 63:    LDC  3,637(6)	Load Integer constant 
 64:     ST  3,-2(1)	Store variable z
* CALL EXPRESSION
* CALL cat
 65:     ST  1,-3(1)	1 Store fp in ghost frame for cat
* Param 1
* TOFF: -4
* TOFF: -5
 66:     LD  3,-2(1)	2 Load variable z
 67:     ST  3,-5(1)	Push parameter 
* Param end cat
 68:    LDA  1,-3(1)	1 Ghost frame becomes new active frame 
 69:    LDA  3,1(7)	Return address in ac 
 70:    JMP  7,-32(7)	CALL OUTPUT cat
 71:    LDA  3,0(2)	Save the result in ac 
* CALL end cat
* TOFF: -3
* CALL EXPRESSION
* CALL output
 72:     ST  1,-3(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -4
* TOFF: -5
 73:     LD  3,-2(1)	2 Load variable z
 74:     ST  3,-5(1)	Push parameter 
* Param end output
 75:    LDA  1,-3(1)	1 Ghost frame becomes new active frame 
 76:    LDA  3,1(7)	Return address in ac 
 77:    JMP  7,-72(7)	CALL OUTPUT output
 78:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -3
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
 79:    LDC  2,0(6)	Set return value to 0 
 80:     LD  3,-1(1)	Load return address 
 81:     LD  1,0(1)	Adjust fp 
 82:    JMP  7,0(3)	Return 
* END FUNCTION main
* TOFF: -2
  0:    JMP  7,82(7)	Jump to init [backpatch] 
* INIT
 83:    LDA  1,-1(0)	set first frame at end of globals 
 84:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
 85:    LDA  3,1(7)	Return address in ac 
 86:    JMP  7,-25(7)	Jump to main 
 87:   HALT  0,0,0	DONE! 
* END INIT
