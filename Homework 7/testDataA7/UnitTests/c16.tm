* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/c16.tm
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
* TOFF:  -4
* ASSIGNMENT EXPRESSION
 40:    LDC  3,1(6)	Load Integer constant 
 41:     ST  3,-2(1)	Store variable z
* ASSIGNMENT EXPRESSION
 42:    LDC  3,2(6)	Load Integer constant 
 43:     ST  3,-3(1)	Store variable zz
* ASSIGNMENT EXPRESSION
 44:     LD  3,-3(1)	2 Load variable zz
 45:     ST  3,-4(1)	Push index 
 46:    LDC  3,73(6)	Load Integer constant 
 47:     LD  4,-4(1)	Pop index 
 48:    LDA  5,-1(0)	Load address of base of array x
 49:    SUB  5,5,4	Compute offset of value 
 50:     ST  3,0(5)	Store variable x
* ASSIGNMENT EXPRESSION
 51:     LD  3,-2(1)	2 Load variable z
 52:     ST  3,-4(1)	Push index 
 53:    LDC  3,211(6)	Load Integer constant 
 54:     LD  4,-4(1)	Pop index 
 55:    LDA  5,-5(0)	Load address of base of array y
 56:    SUB  5,5,4	Compute offset of value 
 57:     ST  3,0(5)	Store variable y
* CALL EXPRESSION
* CALL output
 58:     ST  1,-4(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -6
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
 59:    LDC  3,33(6)	Load Integer constant 
 60:     ST  3,-7(1)	Push the left side 
 61:    LDC  3,31(6)	Load Integer constant 
 62:     LD  4,-7(1)	Load Left into 1 
 63:    SUB  3,4,3	Op - -
 64:    LDA  5,-1(0)	1 Load address of base of array x
 65:    SUB  5,5,3	Compute location from index 
 66:     LD  3,0(5)	Load array element 
 67:     ST  3,-6(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
 68:    LDC  3,9123(6)	Load Integer constant 
 69:     ST  3,-8(1)	Push the left side 
* OP EXPRESSION
 70:    LDC  3,9100(6)	Load Integer constant 
 71:     ST  3,-9(1)	Push the left side 
 72:    LDC  3,23(6)	Load Integer constant 
 73:     LD  4,-9(1)	Load Left into 1 
 74:    ADD  3,4,3	Op + +
 75:     LD  4,-8(1)	Load Left into 1 
 76:    DIV  3,4,3	Op / /
 77:    LDA  5,-5(0)	1 Load address of base of array y
 78:    SUB  5,5,3	Compute location from index 
 79:     LD  3,0(5)	Load array element 
 80:     LD  4,-6(1)	Load Left into 1 
 81:    ADD  3,4,3	Op + +
 82:     ST  3,-6(1)	Push parameter 
* Param end output
 83:    LDA  1,-4(1)	1 Ghost frame becomes new active frame 
 84:    LDA  3,1(7)	Return address in ac 
 85:    JMP  7,-80(7)	CALL OUTPUT output
 86:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
 87:     ST  1,-4(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 88:    LDA  1,-4(1)	Ghost frame becomes new active frame 
 89:    LDA  3,1(7)	Return address in ac 
 90:    JMP  7,-57(7)	CALL OUTPUT outnl
 91:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
 92:    LDC  2,0(6)	Set return value to 0 
 93:     LD  3,-1(1)	Load return address 
 94:     LD  1,0(1)	Adjust fp 
 95:    JMP  7,0(3)	Return 
* END FUNCTION main
  0:    JMP  7,95(7)	Jump to init [backpatch] 
* INIT
 96:    LDA  1,-9(0)	set first frame at end of globals 
 97:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
 98:    LDC  3,3(6)	load size of array x
 99:     ST  3,0(0)	save size of array x
100:    LDC  3,4(6)	load size of array y
101:     ST  3,-4(0)	save size of array y
* END INIT GLOBALS AND STATICS
102:    LDA  3,1(7)	Return address in ac 
103:    JMP  7,-65(7)	Jump to main 
104:   HALT  0,0,0	DONE! 
* END INIT
