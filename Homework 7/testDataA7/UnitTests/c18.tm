* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/c18.tm
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
* TOFF:  -20
 40:    LDC  3,7(6)	load array size x
 41:     ST  3,-2(1)	save array size x
 42:    LDC  3,9(6)	load array size y
 43:     ST  3,-10(1)	save array size y
* ASSIGNMENT EXPRESSION
 44:    LDC  3,5(6)	Load Integer constant 
 45:     ST  3,-20(1)	Push index 
 46:    LDC  3,333(6)	Load Integer constant 
 47:     LD  4,-20(1)	Pop index 
 48:    LDA  5,-3(1)	Load address of base of array x
 49:    SUB  5,5,4	Compute offset of value 
 50:     ST  3,0(5)	Store variable x
* ASSIGNMENT EXPRESSION
 51:    LDC  3,7(6)	Load Integer constant 
 52:     ST  3,-20(1)	Push index 
 53:    LDC  3,444(6)	Load Integer constant 
 54:     LD  4,-20(1)	Pop index 
 55:    LDA  5,-11(1)	Load address of base of array y
 56:    SUB  5,5,4	Compute offset of value 
 57:     ST  3,0(5)	Store variable y
* ASSIGNMENT EXPRESSION
* OP EXPRESSION
 58:    LDA  3,-11(1)	2 Load address of base of array y
 59:     ST  3,-20(1)	Push left side 
 60:    LDC  3,7(6)	Load Integer constant 
 61:     LD  4,-20(1)	Pop left into ac1 
 62:    SUB  3,4,3	Compute location from index 
 63:     LD  3,0(3)	Load array element 
* OP EXPRESSION
 64:    LDA  3,-3(1)	2 Load address of base of array x
 65:     ST  3,-20(1)	Push left side 
 66:    LDC  3,5(6)	Load Integer constant 
 67:     LD  4,-20(1)	Pop left into ac1 
 68:    SUB  3,4,3	Compute location from index 
 69:     LD  3,0(3)	Load array element 
 70:     LD  4,0(0)	Load LHS var 
 71:    ADD  3,4,3	Op +=
 72:     ST  3,0(1)	Store variable [
* CALL EXPRESSION
* CALL output
 73:     ST  1,-20(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -22
* OP EXPRESSION
 74:    LDC  3,5(6)	Load Integer constant 
 75:    LDA  5,-3(1)	2 Load address of base of array x
 76:    SUB  5,5,3	Compute location from index 
 77:     LD  3,0(5)	Load array element 
 78:     ST  3,-22(1)	Push parameter 
* Param end output
 79:    LDA  1,-20(1)	1 Ghost frame becomes new active frame 
 80:    LDA  3,1(7)	Return address in ac 
 81:    JMP  7,-76(7)	CALL OUTPUT output
 82:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* ASSIGNMENT EXPRESSION
* OP EXPRESSION
 83:    LDC  3,5(6)	Load Integer constant 
 84:    LDA  5,-3(1)	2 Load address of base of array x
 85:    SUB  5,5,3	Compute location from index 
 86:     LD  3,0(5)	Load array element 
* OP EXPRESSION
 87:    LDA  3,-11(1)	2 Load address of base of array y
 88:     ST  3,-20(1)	Push left side 
 89:    LDC  3,7(6)	Load Integer constant 
 90:     LD  4,-20(1)	Pop left into ac1 
 91:    SUB  3,4,3	Compute location from index 
 92:     LD  3,0(3)	Load array element 
 93:     LD  4,0(0)	Load LHS var 
 94:    SUB  3,4,3	Op -=
 95:     ST  3,0(1)	Store variable [
* CALL EXPRESSION
* CALL output
 96:     ST  1,-20(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -22
* OP EXPRESSION
 97:    LDC  3,7(6)	Load Integer constant 
 98:    LDA  5,-11(1)	2 Load address of base of array y
 99:    SUB  5,5,3	Compute location from index 
100:     LD  3,0(5)	Load array element 
101:     ST  3,-22(1)	Push parameter 
* Param end output
102:    LDA  1,-20(1)	1 Ghost frame becomes new active frame 
103:    LDA  3,1(7)	Return address in ac 
104:    JMP  7,-99(7)	CALL OUTPUT output
105:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
106:     ST  1,-20(1)	3 Store fp in ghost frame for outnl
* Param end outnl
107:    LDA  1,-20(1)	Ghost frame becomes new active frame 
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
115:    LDA  1,0(0)	set first frame at end of globals 
116:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
117:    LDA  3,1(7)	Return address in ac 
118:    JMP  7,-80(7)	Jump to main 
119:   HALT  0,0,0	DONE! 
* END INIT
