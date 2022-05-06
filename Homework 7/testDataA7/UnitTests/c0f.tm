* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/c0f.tm
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
* TOFF:  -10
 40:    LDC  3,7(6)	load array size x
 41:     ST  3,-2(1)	save array size x
* ASSIGNMENT EXPRESSION
 42:    LDC  3,3(6)	Load Integer constant 
 43:     ST  3,-10(1)	Push index 
 44:    LDC  3,1023(6)	Load Integer constant 
 45:     LD  4,-10(1)	Pop index 
 46:    LDA  5,-3(1)	Load address of base of array x
 47:    SUB  5,5,4	Compute offset of value 
 48:     ST  3,0(5)	Store variable x
* CALL EXPRESSION
* CALL output
 49:     ST  1,-10(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -12
* ASSIGNMENT EXPRESSION
* OP EXPRESSION
 50:    LDC  3,3(6)	Load Integer constant 
 51:    LDA  5,-3(1)	3 Load address of base of array 543 x
 52:    SUB  5,5,3	Compute location from index 
 53:     LD  3,0(5)	Load array element 
 54:    LDA  3,1(3)	increment value of x
 55:     ST  3,0(5)	Store variable x
 56:     ST  3,-12(1)	Push parameter 
* Param end output
 57:    LDA  1,-10(1)	1 Ghost frame becomes new active frame 
 58:    LDA  3,1(7)	Return address in ac 
 59:    JMP  7,-54(7)	CALL OUTPUT output
 60:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
 61:     ST  1,-10(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 62:    LDA  1,-10(1)	Ghost frame becomes new active frame 
 63:    LDA  3,1(7)	Return address in ac 
 64:    JMP  7,-31(7)	CALL OUTPUT outnl
 65:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* CALL EXPRESSION
* CALL output
 66:     ST  1,-10(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -12
* OP EXPRESSION
 67:    LDC  3,3(6)	Load Integer constant 
 68:    LDA  5,-3(1)	3 Load address of base of array 543 x
 69:    SUB  5,5,3	Compute location from index 
 70:     LD  3,0(5)	Load array element 
 71:     ST  3,-12(1)	Push parameter 
* Param end output
 72:    LDA  1,-10(1)	1 Ghost frame becomes new active frame 
 73:    LDA  3,1(7)	Return address in ac 
 74:    JMP  7,-69(7)	CALL OUTPUT output
 75:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
 76:     ST  1,-10(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 77:    LDA  1,-10(1)	Ghost frame becomes new active frame 
 78:    LDA  3,1(7)	Return address in ac 
 79:    JMP  7,-46(7)	CALL OUTPUT outnl
 80:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* CALL EXPRESSION
* CALL output
 81:     ST  1,-10(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -12
* ASSIGNMENT EXPRESSION
* OP EXPRESSION
 82:    LDC  3,3(6)	Load Integer constant 
 83:    LDA  5,-3(1)	3 Load address of base of array 543 x
 84:    SUB  5,5,3	Compute location from index 
 85:     LD  3,0(5)	Load array element 
 86:    LDA  3,-1(3)	decrement value of x
 87:     ST  3,0(5)	Store variable x
 88:     ST  3,-12(1)	Push parameter 
* Param end output
 89:    LDA  1,-10(1)	1 Ghost frame becomes new active frame 
 90:    LDA  3,1(7)	Return address in ac 
 91:    JMP  7,-86(7)	CALL OUTPUT output
 92:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
 93:     ST  1,-10(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 94:    LDA  1,-10(1)	Ghost frame becomes new active frame 
 95:    LDA  3,1(7)	Return address in ac 
 96:    JMP  7,-63(7)	CALL OUTPUT outnl
 97:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* CALL EXPRESSION
* CALL output
 98:     ST  1,-10(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -12
* OP EXPRESSION
 99:    LDC  3,3(6)	Load Integer constant 
100:    LDA  5,-3(1)	3 Load address of base of array 543 x
101:    SUB  5,5,3	Compute location from index 
102:     LD  3,0(5)	Load array element 
103:     ST  3,-12(1)	Push parameter 
* Param end output
104:    LDA  1,-10(1)	1 Ghost frame becomes new active frame 
105:    LDA  3,1(7)	Return address in ac 
106:    JMP  7,-101(7)	CALL OUTPUT output
107:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
108:     ST  1,-10(1)	3 Store fp in ghost frame for outnl
* Param end outnl
109:    LDA  1,-10(1)	Ghost frame becomes new active frame 
110:    LDA  3,1(7)	Return address in ac 
111:    JMP  7,-78(7)	CALL OUTPUT outnl
112:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
113:    LDC  2,0(6)	Set return value to 0 
114:     LD  3,-1(1)	Load return address 
115:     LD  1,0(1)	Adjust fp 
116:    JMP  7,0(3)	Return 
* END FUNCTION main
  0:    JMP  7,116(7)	Jump to init [backpatch] 
* INIT
117:    LDA  1,0(0)	set first frame at end of globals 
118:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
119:    LDA  3,1(7)	Return address in ac 
120:    JMP  7,-82(7)	Jump to main 
121:   HALT  0,0,0	DONE! 
* END INIT
