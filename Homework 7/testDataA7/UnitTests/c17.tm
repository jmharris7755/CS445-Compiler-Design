* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/c17.tm
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
 40:    LDC  3,5(6)	Load Integer constant 
 41:     ST  3,-2(1)	Push index 
 42:    LDC  3,333(6)	Load Integer constant 
 43:     LD  4,-2(1)	Pop index 
 44:    LDA  5,-1(0)	Load address of base of array x
 45:    SUB  5,5,4	Compute offset of value 
 46:     ST  3,0(5)	Store variable x
* ASSIGNMENT EXPRESSION
 47:    LDC  3,7(6)	Load Integer constant 
 48:     ST  3,-2(1)	Push index 
 49:    LDC  3,444(6)	Load Integer constant 
 50:     LD  4,-2(1)	Pop index 
 51:    LDA  5,-9(0)	Load address of base of array y
 52:    SUB  5,5,4	Compute offset of value 
 53:     ST  3,0(5)	Store variable y
* ASSIGNMENT EXPRESSION
 54:    LDC  3,5(6)	Load Integer constant 
 55:     ST  3,-2(1)	Push index 
 56:    LDA  3,-9(0)	Load address of base of array y
 57:     ST  3,-3(1)	Push left side 
 58:    LDC  3,7(6)	Load Integer constant 
 59:     LD  4,-3(1)	Pop left into ac1 
 60:    SUB  3,4,3	Compute location from index 
 61:     LD  3,0(3)	Load array element 
 62:     LD  4,-2(1)	Pop index 
 63:    LDA  5,-1(0)	Load address of base of array x
 64:    SUB  5,5,4	Compute offset of value 
 65:     LD  4,0(5)	Load LHS variable 
 66:    ADD  3,4,3	Op +=
 67:     ST  3,0(5)	Store variable [
* CALL EXPRESSION
* CALL output
 68:     ST  1,-2(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -4
* OP EXPRESSION
 69:    LDA  3,-1(0)	1 Load address of base of array 507 x
 70:     ST  3,-4(1)	Push left side 
 71:    LDC  3,5(6)	Load Integer constant 
 72:     LD  4,-4(1)	Pop left into ac1 
 73:    SUB  3,4,3	Compute location from index 
 74:     LD  3,0(3)	Load array element 
 75:     ST  3,-4(1)	Push parameter 
* Param end output
 76:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
 77:    LDA  3,1(7)	Return address in ac 
 78:    JMP  7,-73(7)	CALL OUTPUT output
 79:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* ASSIGNMENT EXPRESSION
 80:    LDC  3,7(6)	Load Integer constant 
 81:     ST  3,-2(1)	Push index 
 82:    LDA  3,-1(0)	Load address of base of array x
 83:     ST  3,-3(1)	Push left side 
 84:    LDC  3,5(6)	Load Integer constant 
 85:     LD  4,-3(1)	Pop left into ac1 
 86:    SUB  3,4,3	Compute location from index 
 87:     LD  3,0(3)	Load array element 
 88:     LD  4,-2(1)	Pop index 
 89:    LDA  5,-9(0)	Load address of base of array y
 90:    SUB  5,5,4	Compute offset of value 
 91:     LD  4,0(5)	Load LHS variable 
 92:    SUB  3,4,3	Op -=
 93:     ST  3,0(5)	Store variable [
* CALL EXPRESSION
* CALL output
 94:     ST  1,-2(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -4
* OP EXPRESSION
 95:    LDA  3,-9(0)	1 Load address of base of array 507 y
 96:     ST  3,-4(1)	Push left side 
 97:    LDC  3,7(6)	Load Integer constant 
 98:     LD  4,-4(1)	Pop left into ac1 
 99:    SUB  3,4,3	Compute location from index 
100:     LD  3,0(3)	Load array element 
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
115:    LDA  1,-18(0)	set first frame at end of globals 
116:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
117:    LDC  3,7(6)	load size of array x
118:     ST  3,0(0)	save size of array x
119:    LDC  3,9(6)	load size of array y
120:     ST  3,-8(0)	save size of array y
* END INIT GLOBALS AND STATICS
121:    LDA  3,1(7)	Return address in ac 
122:    JMP  7,-84(7)	Jump to main 
123:   HALT  0,0,0	DONE! 
* END INIT
