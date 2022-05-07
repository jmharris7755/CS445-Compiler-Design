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
* TOFF: -11
 44:    LDC  3,1023(6)	Load Integer constant 
* TOFF: -10
 45:     LD  4,-10(1)	Pop index 
 46:    LDA  5,-3(1)	Load address of base of array 390 x
 47:    SUB  5,5,4	Compute offset of value 
 48:     ST  3,0(5)	Store variable x
* CALL EXPRESSION
* CALL output
 49:     ST  1,-10(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -11
* TOFF: -12
* ASSIGNMENT EXPRESSION
* OP EXPRESSION
 50:    LDA  3,-3(1)	2 Load address of base of array 587 x
 51:     ST  3,-12(1)	Push left side 
* TOFF: -13
 52:    LDC  3,3(6)	Load Integer constant 
* TOFF: -12
 53:     LD  4,-12(1)	1 Pop left into ac1 
 54:    SUB  3,4,3	1 Compute location from index 
 55:     LD  3,0(3)	1 Load array element 
 56:    LDA  3,1(3)	increment value of x
 57:     ST  3,0(5)	Store variable x
 58:     ST  3,-12(1)	Push parameter 
* Param end output
 59:    LDA  1,-10(1)	1 Ghost frame becomes new active frame 
 60:    LDA  3,1(7)	Return address in ac 
 61:    JMP  7,-56(7)	CALL OUTPUT output
 62:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -10
* CALL EXPRESSION
* CALL outnl
 63:     ST  1,-10(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 64:    LDA  1,-10(1)	Ghost frame becomes new active frame 
 65:    LDA  3,1(7)	Return address in ac 
 66:    JMP  7,-33(7)	CALL OUTPUT outnl
 67:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -10
* CALL EXPRESSION
* CALL output
 68:     ST  1,-10(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -11
* TOFF: -12
* OP EXPRESSION
 69:    LDA  3,-3(1)	2 Load address of base of array 587 x
 70:     ST  3,-12(1)	Push left side 
* TOFF: -13
 71:    LDC  3,3(6)	Load Integer constant 
* TOFF: -12
 72:     LD  4,-12(1)	1 Pop left into ac1 
 73:    SUB  3,4,3	1 Compute location from index 
 74:     LD  3,0(3)	1 Load array element 
 75:     ST  3,-12(1)	Push parameter 
* Param end output
 76:    LDA  1,-10(1)	1 Ghost frame becomes new active frame 
 77:    LDA  3,1(7)	Return address in ac 
 78:    JMP  7,-73(7)	CALL OUTPUT output
 79:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -10
* CALL EXPRESSION
* CALL outnl
 80:     ST  1,-10(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 81:    LDA  1,-10(1)	Ghost frame becomes new active frame 
 82:    LDA  3,1(7)	Return address in ac 
 83:    JMP  7,-50(7)	CALL OUTPUT outnl
 84:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -10
* CALL EXPRESSION
* CALL output
 85:     ST  1,-10(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -11
* TOFF: -12
* ASSIGNMENT EXPRESSION
* OP EXPRESSION
 86:    LDA  3,-3(1)	2 Load address of base of array 587 x
 87:     ST  3,-12(1)	Push left side 
* TOFF: -13
 88:    LDC  3,3(6)	Load Integer constant 
* TOFF: -12
 89:     LD  4,-12(1)	1 Pop left into ac1 
 90:    SUB  3,4,3	1 Compute location from index 
 91:     LD  3,0(3)	1 Load array element 
 92:    LDA  3,-1(3)	decrement value of x
 93:     ST  3,0(5)	Store variable x
 94:     ST  3,-12(1)	Push parameter 
* Param end output
 95:    LDA  1,-10(1)	1 Ghost frame becomes new active frame 
 96:    LDA  3,1(7)	Return address in ac 
 97:    JMP  7,-92(7)	CALL OUTPUT output
 98:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -10
* CALL EXPRESSION
* CALL outnl
 99:     ST  1,-10(1)	3 Store fp in ghost frame for outnl
* Param end outnl
100:    LDA  1,-10(1)	Ghost frame becomes new active frame 
101:    LDA  3,1(7)	Return address in ac 
102:    JMP  7,-69(7)	CALL OUTPUT outnl
103:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -10
* CALL EXPRESSION
* CALL output
104:     ST  1,-10(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -11
* TOFF: -12
* OP EXPRESSION
105:    LDA  3,-3(1)	2 Load address of base of array 587 x
106:     ST  3,-12(1)	Push left side 
* TOFF: -13
107:    LDC  3,3(6)	Load Integer constant 
* TOFF: -12
108:     LD  4,-12(1)	1 Pop left into ac1 
109:    SUB  3,4,3	1 Compute location from index 
110:     LD  3,0(3)	1 Load array element 
111:     ST  3,-12(1)	Push parameter 
* Param end output
112:    LDA  1,-10(1)	1 Ghost frame becomes new active frame 
113:    LDA  3,1(7)	Return address in ac 
114:    JMP  7,-109(7)	CALL OUTPUT output
115:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -10
* CALL EXPRESSION
* CALL outnl
116:     ST  1,-10(1)	3 Store fp in ghost frame for outnl
* Param end outnl
117:    LDA  1,-10(1)	Ghost frame becomes new active frame 
118:    LDA  3,1(7)	Return address in ac 
119:    JMP  7,-86(7)	CALL OUTPUT outnl
120:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -10
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
121:    LDC  2,0(6)	Set return value to 0 
122:     LD  3,-1(1)	Load return address 
123:     LD  1,0(1)	Adjust fp 
124:    JMP  7,0(3)	Return 
* END FUNCTION main
* TOFF: -2
  0:    JMP  7,124(7)	Jump to init [backpatch] 
* INIT
125:    LDA  1,0(0)	set first frame at end of globals 
126:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
127:    LDA  3,1(7)	Return address in ac 
128:    JMP  7,-90(7)	Jump to main 
129:   HALT  0,0,0	DONE! 
* END INIT
