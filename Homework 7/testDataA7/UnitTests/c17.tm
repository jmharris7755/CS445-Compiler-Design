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
* OP EXPRESSION
 54:    LDA  3,-9(0)	1 Load address of base of array 505 y
 55:     ST  3,-2(1)	Push left side 
 56:    LDC  3,7(6)	Load Integer constant 
 57:     LD  4,-2(1)	Pop left into ac1 
 58:    SUB  3,4,3	Compute location from index 
 59:     LD  3,0(3)	Load array element 
* OP EXPRESSION
 60:    LDA  3,-1(0)	1 Load address of base of array 505 x
 61:     ST  3,-2(1)	Push left side 
 62:    LDC  3,5(6)	Load Integer constant 
 63:     LD  4,-2(1)	Pop left into ac1 
 64:    SUB  3,4,3	Compute location from index 
 65:     LD  3,0(3)	Load array element 
 66:     LD  4,0(0)	Load LHS var 
 67:    ADD  3,4,3	Op +=
 68:     ST  3,0(1)	Store variable [
* CALL EXPRESSION
* CALL output
 69:     ST  1,-2(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -4
* OP EXPRESSION
 70:    LDC  3,5(6)	Load Integer constant 
 71:    LDA  5,-1(0)	1 Load address of base of array 535 x
 72:    SUB  5,5,3	Compute location from index 
 73:     LD  3,0(5)	Load array element 
 74:     ST  3,-4(1)	Push parameter 
* Param end output
 75:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
 76:    LDA  3,1(7)	Return address in ac 
 77:    JMP  7,-72(7)	CALL OUTPUT output
 78:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* ASSIGNMENT EXPRESSION
* OP EXPRESSION
 79:    LDC  3,5(6)	Load Integer constant 
 80:    LDA  5,-1(0)	1 Load address of base of array 535 x
 81:    SUB  5,5,3	Compute location from index 
 82:     LD  3,0(5)	Load array element 
* OP EXPRESSION
 83:    LDA  3,-9(0)	1 Load address of base of array 505 y
 84:     ST  3,-2(1)	Push left side 
 85:    LDC  3,7(6)	Load Integer constant 
 86:     LD  4,-2(1)	Pop left into ac1 
 87:    SUB  3,4,3	Compute location from index 
 88:     LD  3,0(3)	Load array element 
 89:     LD  4,0(0)	Load LHS var 
 90:    SUB  3,4,3	Op -=
 91:     ST  3,0(1)	Store variable [
* CALL EXPRESSION
* CALL output
 92:     ST  1,-2(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -4
* OP EXPRESSION
 93:    LDC  3,7(6)	Load Integer constant 
 94:    LDA  5,-9(0)	1 Load address of base of array 535 y
 95:    SUB  5,5,3	Compute location from index 
 96:     LD  3,0(5)	Load array element 
 97:     ST  3,-4(1)	Push parameter 
* Param end output
 98:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
 99:    LDA  3,1(7)	Return address in ac 
100:    JMP  7,-95(7)	CALL OUTPUT output
101:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
102:     ST  1,-2(1)	3 Store fp in ghost frame for outnl
* Param end outnl
103:    LDA  1,-2(1)	Ghost frame becomes new active frame 
104:    LDA  3,1(7)	Return address in ac 
105:    JMP  7,-72(7)	CALL OUTPUT outnl
106:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
107:    LDC  2,0(6)	Set return value to 0 
108:     LD  3,-1(1)	Load return address 
109:     LD  1,0(1)	Adjust fp 
110:    JMP  7,0(3)	Return 
* END FUNCTION main
  0:    JMP  7,110(7)	Jump to init [backpatch] 
* INIT
111:    LDA  1,-18(0)	set first frame at end of globals 
112:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
113:    LDC  3,7(6)	load size of array x
114:     ST  3,0(0)	save size of array x
115:    LDC  3,9(6)	load size of array y
116:     ST  3,-8(0)	save size of array y
* END INIT GLOBALS AND STATICS
117:    LDA  3,1(7)	Return address in ac 
118:    JMP  7,-80(7)	Jump to main 
119:   HALT  0,0,0	DONE! 
* END INIT
