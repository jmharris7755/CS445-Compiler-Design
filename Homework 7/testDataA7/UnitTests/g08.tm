* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/g08.tm
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
* FUNCTION cat
 39:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -4
* RETURN
* OP EXPRESSION
 40:    LDC  3,77(6)	Load Integer constant 
 41:     ST  3,-4(1)	Push the left side 
* TOFF: -5
* OP EXPRESSION
* OP EXPRESSION
 42:     LD  3,-2(1)	2 Load address of base of array 583 z
 43:     ST  3,-5(1)	Push left side 
* TOFF: -6
 44:     LD  3,-3(1)	1 load variable x
* TOFF: -5
 45:     LD  4,-5(1)	1 Pop left into ac1 
 46:    SUB  3,4,3	1 Compute location from index 
 47:     LD  3,0(3)	1 Load array element 
 48:     ST  3,-5(1)	Push the left side 
* TOFF: -6
* OP EXPRESSION
 49:     LD  3,-2(1)	2 Load address of base of array 583 z
 50:     ST  3,-6(1)	Push left side 
* TOFF: -7
 51:     LD  3,-3(1)	1 load variable x
* TOFF: -6
 52:     LD  4,-6(1)	1 Pop left into ac1 
 53:    SUB  3,4,3	1 Compute location from index 
 54:     LD  3,0(3)	1 Load array element 
* TOFF: -5
 55:     LD  4,-5(1)	Load Left into 1 *
 56:    MUL  3,4,3	Op * *
* TOFF: -4
 57:     LD  4,-4(1)	Load Left into 1 +
 58:    ADD  3,4,3	Op + +
 59:    LDA  2,0(3)	Copy result to ret register 
 60:     LD  3,-1(1)	Load return address 
 61:     LD  1,0(1)	Adjust fp 
 62:    JMP  7,0(3)	Return 
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
 63:    LDC  2,0(6)	Set return value to 0 
 64:     LD  3,-1(1)	Load return address 
 65:     LD  1,0(1)	Adjust fp 
 66:    JMP  7,0(3)	Return 
* END FUNCTION cat
* TOFF: -2
* FUNCTION main
 67:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -13
 68:    LDC  3,10(6)	load array size z
 69:     ST  3,-2(1)	save array size z
* ASSIGNMENT EXPRESSION
 70:    LDC  3,3(6)	Load Integer constant 
 71:     ST  3,-13(1)	Push index 
* TOFF: -14
 72:    LDC  3,445(6)	Load Integer constant 
* TOFF: -13
 73:     LD  4,-13(1)	Pop index 
 74:    LDA  5,-3(1)	Load address of base of array z
 75:    SUB  5,5,4	Compute offset of value 
 76:     ST  3,0(5)	Store variable z
* CALL EXPRESSION
* CALL output
 77:     ST  1,-13(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -14
* TOFF: -15
* CALL EXPRESSION
* CALL cat
* TOFF: -15
 78:     ST  1,-15(1)	2 Store fp in ghost frame for cat
* TOFF: -16
* TOFF: -17
* Param 1
 79:    LDA  3,-3(1)	Load address of base of array z
 80:     ST  3,-17(1)	Push parameter 
* TOFF: -18
* Param 2
 81:    LDC  3,3(6)	Load integer constant 
 82:     ST  3,-18(1)	3 Push parameter 
* Param end cat
 83:    LDA  1,-15(1)	Ghost frame becomes new active frame 
 84:    LDA  3,1(7)	Return address in ac 
 85:    JMP  7,-47(7)	CALL OUTPUT cat
 86:    LDA  3,0(2)	Save the result in ac 
* CALL end cat
* TOFF: -15
 87:     ST  3,-15(1)	Push parameter 
* Param end output
 88:    LDA  1,-13(1)	1 Ghost frame becomes new active frame 
 89:    LDA  3,1(7)	Return address in ac 
 90:    JMP  7,-85(7)	CALL OUTPUT output
 91:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -13
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
 92:    LDC  2,0(6)	Set return value to 0 
 93:     LD  3,-1(1)	Load return address 
 94:     LD  1,0(1)	Adjust fp 
 95:    JMP  7,0(3)	Return 
* END FUNCTION main
* TOFF: -2
  0:    JMP  7,95(7)	Jump to init [backpatch] 
* INIT
 96:    LDA  1,0(0)	set first frame at end of globals 
 97:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
 98:    LDA  3,1(7)	Return address in ac 
 99:    JMP  7,-33(7)	Jump to main 
100:   HALT  0,0,0	DONE! 
* END INIT
