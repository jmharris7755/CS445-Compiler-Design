* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/v06.tm
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
* FUNCTION outputs
 39:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -3
* FOR
* CALL EXPRESSION
* CALL outputc
 40:     ST  1,-3(1)	1 Store fp in ghost frame for outputc
* Param 1
* TOFF: -5
* OP EXPRESSION
 41:    LDA  3,-2(1)	4 Load address of base of array s
 42:    LDA  3,-2(1)	Load address of base of array 
 43:     ST  3,-6(1)	Push parameter 
* Param end outputc
 44:    LDA  1,-3(1)	1 Ghost frame becomes new active frame 
 45:    LDA  3,1(7)	Return address in ac 
 46:    JMP  7,-19(7)	CALL OUTPUT outputc
 47:    LDA  3,0(2)	Save the result in ac 
* CALL end outputc
* END FOR
* RETURN
 48:    LDA  2,0(3)	Copy result to ret register 
 49:     LD  3,-1(1)	Load return address 
 50:     LD  1,0(1)	Adjust fp 
 51:    LDA  7,0(3)	Return 
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
 52:    LDC  2,0(6)	Set return value to 0 
 53:     LD  3,-1(1)	Load return address 
 54:     LD  1,0(1)	Adjust fp 
 55:    JMP  7,0(3)	Return 
* END FUNCTION outputs
* FUNCTION main
 56:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -2
* CALL EXPRESSION
* CALL outputs
 57:     ST  1,-2(1)	1 Store fp in ghost frame for outputs
* Param 1
* TOFF: -3
 58:     ST  3,-3(1)	Push parameter 
* Param end outputs
 59:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
 60:    LDA  3,1(7)	Return address in ac 
 61:    JMP  7,-61(7)	CALL OUTPUT outputs
 62:    LDA  3,0(2)	Save the result in ac 
* CALL end outputs
* CALL EXPRESSION
* CALL outnl
 63:     ST  1,-2(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 64:    LDA  1,-2(1)	Ghost frame becomes new active frame 
 65:    LDA  3,1(7)	Return address in ac 
 66:    JMP  7,-33(7)	CALL OUTPUT outnl
 67:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* CALL EXPRESSION
* CALL outputs
 68:     ST  1,-2(1)	1 Store fp in ghost frame for outputs
* Param 1
* TOFF: -3
 69:     ST  3,-3(1)	Push parameter 
* Param end outputs
 70:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
 71:    LDA  3,1(7)	Return address in ac 
 72:    JMP  7,-72(7)	CALL OUTPUT outputs
 73:    LDA  3,0(2)	Save the result in ac 
* CALL end outputs
* CALL EXPRESSION
* CALL output
 74:     ST  1,-2(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -4
 75:    LDC  3,42(6)	Load Integer constant 
 76:     ST  3,-4(1)	Push parameter 
* Param end output
 77:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
 78:    LDA  3,1(7)	Return address in ac 
 79:    JMP  7,-74(7)	CALL OUTPUT output
 80:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
 81:     ST  1,-2(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 82:    LDA  1,-2(1)	Ghost frame becomes new active frame 
 83:    LDA  3,1(7)	Return address in ac 
 84:    JMP  7,-51(7)	CALL OUTPUT outnl
 85:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
 86:    LDC  2,0(6)	Set return value to 0 
 87:     LD  3,-1(1)	Load return address 
 88:     LD  1,0(1)	Adjust fp 
 89:    JMP  7,0(3)	Return 
* END FUNCTION main
  0:    JMP  7,89(7)	Jump to init [backpatch] 
* INIT
 90:    LDA  1,-36(0)	set first frame at end of globals 
 91:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
 92:    LDA  3,1(7)	Return address in ac 
 93:    JMP  7,-38(7)	Jump to main 
 94:   HALT  0,0,0	DONE! 
* END INIT
