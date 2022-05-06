* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/g07.tm
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
 40:     LD  3,-2(1)	2 Load address of base of array 583 z
 41:     ST  3,-4(1)	Push left side 
* TOFF: -5
 42:     LD  3,-3(1)	1 load variable x
* TOFF: -4
 43:     LD  4,-4(1)	1 Pop left into ac1 
 44:    SUB  3,4,3	1 Compute location from index 
 45:     LD  3,0(3)	1 Load array element 
 46:    LDA  2,0(3)	Copy result to ret register 
 47:     LD  3,-1(1)	Load return address 
 48:     LD  1,0(1)	Adjust fp 
 49:    JMP  7,0(3)	Return 
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
 50:    LDC  2,0(6)	Set return value to 0 
 51:     LD  3,-1(1)	Load return address 
 52:     LD  1,0(1)	Adjust fp 
 53:    JMP  7,0(3)	Return 
* END FUNCTION cat
* TOFF: -2
* FUNCTION main
 54:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -13
 55:    LDC  3,10(6)	load array size z
 56:     ST  3,-2(1)	save array size z
* ASSIGNMENT EXPRESSION
 57:    LDC  3,3(6)	Load Integer constant 
 58:     ST  3,-13(1)	Push index 
* TOFF: -14
 59:    LDC  3,445(6)	Load Integer constant 
* TOFF: -13
 60:     LD  4,-13(1)	Pop index 
 61:    LDA  5,-3(1)	Load address of base of array z
 62:    SUB  5,5,4	Compute offset of value 
 63:     ST  3,0(5)	Store variable z
* CALL EXPRESSION
* CALL output
 64:     ST  1,-13(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -14
* TOFF: -15
* CALL EXPRESSION
* CALL cat
* TOFF: -15
 65:     ST  1,-15(1)	2 Store fp in ghost frame for cat
* TOFF: -16
* TOFF: -17
* Param 1
 66:    LDA  3,-3(1)	Load address of base of array z
 67:     ST  3,-17(1)	Push parameter 
* TOFF: -18
* Param 2
 68:    LDC  3,3(6)	Load integer constant 
 69:     ST  3,-18(1)	3 Push parameter 
* Param end cat
 70:    LDA  1,-15(1)	Ghost frame becomes new active frame 
 71:    LDA  3,1(7)	Return address in ac 
 72:    JMP  7,-34(7)	CALL OUTPUT cat
 73:    LDA  3,0(2)	Save the result in ac 
* CALL end cat
* TOFF: -15
 74:     ST  3,-15(1)	Push parameter 
* Param end output
 75:    LDA  1,-13(1)	1 Ghost frame becomes new active frame 
 76:    LDA  3,1(7)	Return address in ac 
 77:    JMP  7,-72(7)	CALL OUTPUT output
 78:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -13
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
 79:    LDC  2,0(6)	Set return value to 0 
 80:     LD  3,-1(1)	Load return address 
 81:     LD  1,0(1)	Adjust fp 
 82:    JMP  7,0(3)	Return 
* END FUNCTION main
* TOFF: -2
  0:    JMP  7,82(7)	Jump to init [backpatch] 
* INIT
 83:    LDA  1,0(0)	set first frame at end of globals 
 84:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
 85:    LDA  3,1(7)	Return address in ac 
 86:    JMP  7,-33(7)	Jump to main 
 87:   HALT  0,0,0	DONE! 
* END INIT
