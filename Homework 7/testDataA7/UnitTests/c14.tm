* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/c14.tm
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
* TOFF:  -13
 40:    LDC  3,3(6)	load array size x
 41:     ST  3,-2(1)	save array size x
 42:    LDC  3,4(6)	load array size y
 43:     ST  3,-6(1)	save array size y
* ASSIGNMENT EXPRESSION
 44:    LDC  3,1(6)	Load Integer constant 
 45:     ST  3,-11(1)	Store variable z
* ASSIGNMENT EXPRESSION
 46:    LDC  3,2(6)	Load Integer constant 
 47:     ST  3,-12(1)	Store variable zz
* ASSIGNMENT EXPRESSION
 48:     LD  3,-12(1)	2 Load variable zz
 49:     ST  3,-13(1)	Push index 
 50:    LDC  3,73(6)	Load Integer constant 
 51:     LD  4,-13(1)	Pop index 
 52:    LDA  5,-3(1)	Load address of base of array x
 53:    SUB  5,5,4	Compute offset of value 
 54:     ST  3,0(5)	Store variable x
* ASSIGNMENT EXPRESSION
 55:     LD  3,-11(1)	2 Load variable z
 56:     ST  3,-13(1)	Push index 
 57:    LDC  3,211(6)	Load Integer constant 
 58:     LD  4,-13(1)	Pop index 
 59:    LDA  5,-7(1)	Load address of base of array y
 60:    SUB  5,5,4	Compute offset of value 
 61:     ST  3,0(5)	Store variable y
* CALL EXPRESSION
* CALL output
 62:     ST  1,-13(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -15
* OP EXPRESSION
* OP EXPRESSION
 63:     LD  3,-12(1)	2 Load variable zz
 64:    LDA  5,-3(1)	2 Load address of base of array x
 65:    SUB  5,5,3	Compute location from index 
 66:     LD  3,0(5)	Load array element 
 67:     ST  3,-15(1)	Push the left side 
* OP EXPRESSION
 68:     LD  3,-11(1)	2 Load variable z
 69:    LDA  5,-7(1)	2 Load address of base of array y
 70:    SUB  5,5,3	Compute location from index 
 71:     LD  3,0(5)	Load array element 
 72:     LD  4,-15(1)	Load Left into 1 
 73:    ADD  3,4,3	Op + +
 74:     ST  3,-15(1)	Push parameter 
* Param end output
 75:    LDA  1,-13(1)	1 Ghost frame becomes new active frame 
 76:    LDA  3,1(7)	Return address in ac 
 77:    JMP  7,-72(7)	CALL OUTPUT output
 78:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
 79:     ST  1,-13(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 80:    LDA  1,-13(1)	Ghost frame becomes new active frame 
 81:    LDA  3,1(7)	Return address in ac 
 82:    JMP  7,-49(7)	CALL OUTPUT outnl
 83:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
 84:    LDC  2,0(6)	Set return value to 0 
 85:     LD  3,-1(1)	Load return address 
 86:     LD  1,0(1)	Adjust fp 
 87:    JMP  7,0(3)	Return 
* END FUNCTION main
  0:    JMP  7,87(7)	Jump to init [backpatch] 
* INIT
 88:    LDA  1,0(0)	set first frame at end of globals 
 89:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
 90:    LDA  3,1(7)	Return address in ac 
 91:    JMP  7,-53(7)	Jump to main 
 92:   HALT  0,0,0	DONE! 
* END INIT
