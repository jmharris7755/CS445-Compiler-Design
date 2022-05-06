* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/g05.tm
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
* OP EXPRESSION
 40:     LD  3,-2(1)	1 load variable z
 41:     ST  3,-4(1)	Push the left side 
* TOFF: -5
 42:     LD  3,-3(1)	1 load variable x
* TOFF: -4
 43:     LD  4,-4(1)	Load Left into 1 *
 44:    MUL  3,4,3	Op * *
 45:     ST  3,-4(1)	Push the left side 
* TOFF: -5
 46:     LD  3,-3(1)	1 load variable x
* TOFF: -4
 47:     LD  4,-4(1)	Load Left into 1 -
 48:    SUB  3,4,3	Op - -
 49:    LDA  2,0(3)	Copy result to ret register 
 50:     LD  3,-1(1)	Load return address 
 51:     LD  1,0(1)	Adjust fp 
 52:    JMP  7,0(3)	Return 
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
 53:    LDC  2,0(6)	Set return value to 0 
 54:     LD  3,-1(1)	Load return address 
 55:     LD  1,0(1)	Adjust fp 
 56:    JMP  7,0(3)	Return 
* END FUNCTION cat
* TOFF: -2
* FUNCTION main
 57:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -13
 58:    LDC  3,10(6)	load array size z
 59:     ST  3,-2(1)	save array size z
* ASSIGNMENT EXPRESSION
 60:    LDC  3,3(6)	Load Integer constant 
 61:     ST  3,-13(1)	Push index 
* TOFF: -14
 62:    LDC  3,445(6)	Load Integer constant 
* TOFF: -13
 63:     LD  4,-13(1)	Pop index 
 64:    LDA  5,-3(1)	Load address of base of array z
 65:    SUB  5,5,4	Compute offset of value 
 66:     ST  3,0(5)	Store variable z
* CALL EXPRESSION
* CALL output
 67:     ST  1,-13(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -14
* TOFF: -15
* CALL EXPRESSION
* CALL cat
* TOFF: -15
 68:     ST  1,-15(1)	2 Store fp in ghost frame for cat
* TOFF: -16
* TOFF: -17
* Param 1
* OP EXPRESSION
 69:    LDA  3,-3(1)	2 Load address of base of array 587 z
 70:     ST  3,-17(1)	Push left side 
* TOFF: -18
 71:    LDC  3,3(6)	Load Integer constant 
* TOFF: -17
 72:     LD  4,-17(1)	1 Pop left into ac1 
 73:    SUB  3,4,3	1 Compute location from index 
 74:     LD  3,0(3)	1 Load array element 
 75:     ST  3,-17(1)	Push parameter 
* TOFF: -18
* Param 2
 76:    LDC  3,911(6)	Load integer constant 
 77:     ST  3,-18(1)	3 Push parameter 
* Param end cat
 78:    LDA  1,-15(1)	Ghost frame becomes new active frame 
 79:    LDA  3,1(7)	Return address in ac 
 80:    JMP  7,-42(7)	CALL OUTPUT cat
 81:    LDA  3,0(2)	Save the result in ac 
* CALL end cat
* TOFF: -15
 82:     ST  3,-15(1)	Push parameter 
* Param end output
 83:    LDA  1,-13(1)	1 Ghost frame becomes new active frame 
 84:    LDA  3,1(7)	Return address in ac 
 85:    JMP  7,-80(7)	CALL OUTPUT output
 86:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -13
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
 87:    LDC  2,0(6)	Set return value to 0 
 88:     LD  3,-1(1)	Load return address 
 89:     LD  1,0(1)	Adjust fp 
 90:    JMP  7,0(3)	Return 
* END FUNCTION main
* TOFF: -2
  0:    JMP  7,90(7)	Jump to init [backpatch] 
* INIT
 91:    LDA  1,0(0)	set first frame at end of globals 
 92:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
 93:    LDA  3,1(7)	Return address in ac 
 94:    JMP  7,-38(7)	Jump to main 
 95:   HALT  0,0,0	DONE! 
* END INIT
