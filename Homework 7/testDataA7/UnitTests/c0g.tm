* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/c0g.tm
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
 40:    LDC  3,3(6)	Load Integer constant 
 41:     ST  3,-2(1)	Push index 
 42:    LDC  3,1023(6)	Load Integer constant 
 43:     LD  4,-2(1)	Pop index 
 44:    LDA  5,-1(0)	Load address of base of array x
 45:    SUB  5,5,4	Compute offset of value 
 46:     ST  3,0(5)	Store variable x
* CALL EXPRESSION
* CALL output
 47:     ST  1,-2(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -4
* ASSIGNMENT EXPRESSION
* OP EXPRESSION
 48:    LDC  3,3(6)	Load Integer constant 
 49:    LDA  5,-1(0)	1 Load address of base of array x
 50:    SUB  5,5,3	Compute location from index 
 51:     LD  3,0(5)	Load array element 
 52:    LDA  3,1(3)	increment value of x
 53:     ST  3,0(5)	Store variable x
 54:     ST  3,-4(1)	Push parameter 
* Param end output
 55:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
 56:    LDA  3,1(7)	Return address in ac 
 57:    JMP  7,-52(7)	CALL OUTPUT output
 58:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
 59:     ST  1,-2(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 60:    LDA  1,-2(1)	Ghost frame becomes new active frame 
 61:    LDA  3,1(7)	Return address in ac 
 62:    JMP  7,-29(7)	CALL OUTPUT outnl
 63:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* CALL EXPRESSION
* CALL output
 64:     ST  1,-2(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -4
* OP EXPRESSION
 65:    LDC  3,3(6)	Load Integer constant 
 66:    LDA  5,-1(0)	1 Load address of base of array x
 67:    SUB  5,5,3	Compute location from index 
 68:     LD  3,0(5)	Load array element 
 69:     ST  3,-4(1)	Push parameter 
* Param end output
 70:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
 71:    LDA  3,1(7)	Return address in ac 
 72:    JMP  7,-67(7)	CALL OUTPUT output
 73:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
 74:     ST  1,-2(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 75:    LDA  1,-2(1)	Ghost frame becomes new active frame 
 76:    LDA  3,1(7)	Return address in ac 
 77:    JMP  7,-44(7)	CALL OUTPUT outnl
 78:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* CALL EXPRESSION
* CALL output
 79:     ST  1,-2(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -4
* ASSIGNMENT EXPRESSION
* OP EXPRESSION
 80:    LDC  3,3(6)	Load Integer constant 
 81:    LDA  5,-1(0)	1 Load address of base of array x
 82:    SUB  5,5,3	Compute location from index 
 83:     LD  3,0(5)	Load array element 
 84:    LDA  3,-1(3)	decrement value of x
 85:     ST  3,0(5)	Store variable x
 86:     ST  3,-4(1)	Push parameter 
* Param end output
 87:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
 88:    LDA  3,1(7)	Return address in ac 
 89:    JMP  7,-84(7)	CALL OUTPUT output
 90:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
 91:     ST  1,-2(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 92:    LDA  1,-2(1)	Ghost frame becomes new active frame 
 93:    LDA  3,1(7)	Return address in ac 
 94:    JMP  7,-61(7)	CALL OUTPUT outnl
 95:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* CALL EXPRESSION
* CALL output
 96:     ST  1,-2(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -4
* OP EXPRESSION
 97:    LDC  3,3(6)	Load Integer constant 
 98:    LDA  5,-1(0)	1 Load address of base of array x
 99:    SUB  5,5,3	Compute location from index 
100:     LD  3,0(5)	Load array element 
101:     ST  3,-4(1)	Push parameter 
* Param end output
102:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
103:    LDA  3,1(7)	Return address in ac 
104:    JMP  7,-99(7)	CALL OUTPUT output
105:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
106:     ST  1,-2(1)	3 Store fp in ghost frame for outnl
* Param end outnl
107:    LDA  1,-2(1)	Ghost frame becomes new active frame 
108:    LDA  3,1(7)	Return address in ac 
109:    JMP  7,-76(7)	CALL OUTPUT outnl
110:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
111:    LDC  2,0(6)	Set return value to 0 
112:     LD  3,-1(1)	Load return address 
113:     LD  1,0(1)	Adjust fp 
114:    JMP  7,0(3)	Return 
* END FUNCTION main
  0:    JMP  7,114(7)	Jump to init [backpatch] 
* INIT
115:    LDA  1,-8(0)	set first frame at end of globals 
116:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
117:    LDC  3,7(6)	load size of array x
118:     ST  3,0(0)	save size of array x
* END INIT GLOBALS AND STATICS
119:    LDA  3,1(7)	Return address in ac 
120:    JMP  7,-82(7)	Jump to main 
121:   HALT  0,0,0	DONE! 
* END INIT
