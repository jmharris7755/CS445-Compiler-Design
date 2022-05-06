* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/c0h.tm
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
* FUNCTION dog
 39:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -3
* CALL EXPRESSION
* CALL output
 40:     ST  1,-3(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -4
* TOFF: -5
* ASSIGNMENT EXPRESSION
* OP EXPRESSION
* TOFF: -6
 41:    LDC  3,3(6)	Load Integer constant 
* TOFF: -5
 42:     LD  5,-2(1)	2 Load address of base of array 623 x
 43:    SUB  5,5,3	2 Compute location from index 
 44:     LD  3,0(5)	2 Load array element 
 45:    LDA  3,1(3)	increment value of x
 46:     ST  3,0(5)	Store variable x
 47:     ST  3,-5(1)	Push parameter 
* Param end output
 48:    LDA  1,-3(1)	1 Ghost frame becomes new active frame 
 49:    LDA  3,1(7)	Return address in ac 
 50:    JMP  7,-45(7)	CALL OUTPUT output
 51:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -3
* CALL EXPRESSION
* CALL outnl
 52:     ST  1,-3(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 53:    LDA  1,-3(1)	Ghost frame becomes new active frame 
 54:    LDA  3,1(7)	Return address in ac 
 55:    JMP  7,-22(7)	CALL OUTPUT outnl
 56:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -3
* CALL EXPRESSION
* CALL output
 57:     ST  1,-3(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -4
* TOFF: -5
* OP EXPRESSION
* TOFF: -6
 58:    LDC  3,3(6)	Load Integer constant 
* TOFF: -5
 59:     LD  5,-2(1)	2 Load address of base of array 623 x
 60:    SUB  5,5,3	2 Compute location from index 
 61:     LD  3,0(5)	2 Load array element 
 62:     ST  3,-5(1)	Push parameter 
* Param end output
 63:    LDA  1,-3(1)	1 Ghost frame becomes new active frame 
 64:    LDA  3,1(7)	Return address in ac 
 65:    JMP  7,-60(7)	CALL OUTPUT output
 66:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -3
* CALL EXPRESSION
* CALL outnl
 67:     ST  1,-3(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 68:    LDA  1,-3(1)	Ghost frame becomes new active frame 
 69:    LDA  3,1(7)	Return address in ac 
 70:    JMP  7,-37(7)	CALL OUTPUT outnl
 71:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -3
* CALL EXPRESSION
* CALL output
 72:     ST  1,-3(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -4
* TOFF: -5
* ASSIGNMENT EXPRESSION
* OP EXPRESSION
* TOFF: -6
 73:    LDC  3,3(6)	Load Integer constant 
* TOFF: -5
 74:     LD  5,-2(1)	2 Load address of base of array 623 x
 75:    SUB  5,5,3	2 Compute location from index 
 76:     LD  3,0(5)	2 Load array element 
 77:    LDA  3,-1(3)	decrement value of x
 78:     ST  3,0(5)	Store variable x
 79:     ST  3,-5(1)	Push parameter 
* Param end output
 80:    LDA  1,-3(1)	1 Ghost frame becomes new active frame 
 81:    LDA  3,1(7)	Return address in ac 
 82:    JMP  7,-77(7)	CALL OUTPUT output
 83:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -3
* CALL EXPRESSION
* CALL outnl
 84:     ST  1,-3(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 85:    LDA  1,-3(1)	Ghost frame becomes new active frame 
 86:    LDA  3,1(7)	Return address in ac 
 87:    JMP  7,-54(7)	CALL OUTPUT outnl
 88:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -3
* CALL EXPRESSION
* CALL output
 89:     ST  1,-3(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -4
* TOFF: -5
* OP EXPRESSION
* TOFF: -6
 90:    LDC  3,3(6)	Load Integer constant 
* TOFF: -5
 91:     LD  5,-2(1)	2 Load address of base of array 623 x
 92:    SUB  5,5,3	2 Compute location from index 
 93:     LD  3,0(5)	2 Load array element 
 94:     ST  3,-5(1)	Push parameter 
* Param end output
 95:    LDA  1,-3(1)	1 Ghost frame becomes new active frame 
 96:    LDA  3,1(7)	Return address in ac 
 97:    JMP  7,-92(7)	CALL OUTPUT output
 98:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -3
* CALL EXPRESSION
* CALL outnl
 99:     ST  1,-3(1)	3 Store fp in ghost frame for outnl
* Param end outnl
100:    LDA  1,-3(1)	Ghost frame becomes new active frame 
101:    LDA  3,1(7)	Return address in ac 
102:    JMP  7,-69(7)	CALL OUTPUT outnl
103:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -3
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
104:    LDC  2,0(6)	Set return value to 0 
105:     LD  3,-1(1)	Load return address 
106:     LD  1,0(1)	Adjust fp 
107:    JMP  7,0(3)	Return 
* END FUNCTION dog
* TOFF: -2
* FUNCTION main
108:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -10
109:    LDC  3,7(6)	load array size x
110:     ST  3,-2(1)	save array size x
* ASSIGNMENT EXPRESSION
111:    LDC  3,3(6)	Load Integer constant 
112:     ST  3,-10(1)	Push index 
* TOFF: -11
113:    LDC  3,1023(6)	Load Integer constant 
* TOFF: -10
114:     LD  4,-10(1)	Pop index 
115:    LDA  5,-3(1)	Load address of base of array x
116:    SUB  5,5,4	Compute offset of value 
117:     ST  3,0(5)	Store variable x
* CALL EXPRESSION
* CALL dog
118:     ST  1,-10(1)	1 Store fp in ghost frame for dog
* Param 1
* TOFF: -11
* TOFF: -11
119:    LDA  3,-3(1)	2 Load address of base of array 783 x
* TOFF: -12
120:     ST  3,-12(1)	Push parameter 
* Param end dog
121:    LDA  1,-10(1)	1 Ghost frame becomes new active frame 
122:    LDA  3,1(7)	Return address in ac 
123:    JMP  7,-85(7)	CALL OUTPUT dog
124:    LDA  3,0(2)	Save the result in ac 
* CALL end dog
* TOFF: -10
* CALL EXPRESSION
* CALL output
125:     ST  1,-10(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -11
* TOFF: -12
* OP EXPRESSION
* TOFF: -13
126:    LDC  3,3(6)	Load Integer constant 
* TOFF: -12
127:    LDA  5,-3(1)	3 Load address of base of array 626 x
128:    SUB  5,5,3	2 Compute location from index 
129:     LD  3,0(5)	2 Load array element 
130:     ST  3,-12(1)	Push parameter 
* Param end output
131:    LDA  1,-10(1)	1 Ghost frame becomes new active frame 
132:    LDA  3,1(7)	Return address in ac 
133:    JMP  7,-128(7)	CALL OUTPUT output
134:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -10
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
135:    LDC  2,0(6)	Set return value to 0 
136:     LD  3,-1(1)	Load return address 
137:     LD  1,0(1)	Adjust fp 
138:    JMP  7,0(3)	Return 
* END FUNCTION main
* TOFF: -2
  0:    JMP  7,138(7)	Jump to init [backpatch] 
* INIT
139:    LDA  1,0(0)	set first frame at end of globals 
140:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
141:    LDA  3,1(7)	Return address in ac 
142:    JMP  7,-35(7)	Jump to main 
143:   HALT  0,0,0	DONE! 
* END INIT
