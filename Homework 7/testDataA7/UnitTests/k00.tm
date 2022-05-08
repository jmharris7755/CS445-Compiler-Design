* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/k00.tm
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
* FOR
* COMPOUND
* TOFF:  -3
* CALL EXPRESSION
* CALL output
 40:     ST  1,-3(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -4
* TOFF: -5
 41:     LD  3,-2(1)	1 load variable 851 i
 42:     ST  3,-5(1)	Push parameter 1001 
* Param end output
 43:    LDA  1,-3(1)	1 Ghost frame becomes new active frame 
 44:    LDA  3,1(7)	Return address in ac 
 45:    JMP  7,-40(7)	CALL OUTPUT output
 46:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -3
* CALL EXPRESSION
* CALL outnl
 47:     ST  1,-3(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 48:    LDA  1,-3(1)	Ghost frame becomes new active frame 
 49:    LDA  3,1(7)	Return address in ac 
 50:    JMP  7,-17(7)	CALL OUTPUT outnl
 51:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -3
* Compound Body
* TOFF:  -2
* END COMPOUND
* END FOR
* RETURN
 52:    LDA  2,0(3)	Copy result to ret register 
 53:     LD  3,-1(1)	Load return address 
 54:     LD  1,0(1)	Adjust fp 
 55:    JMP  7,0(3)	Return 
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
 56:    LDC  2,0(6)	Set return value to 0 
 57:     LD  3,-1(1)	Load return address 
 58:     LD  1,0(1)	Adjust fp 
 59:    JMP  7,0(3)	Return 
* END FUNCTION main
* TOFF: -2
  0:    JMP  7,59(7)	Jump to init [backpatch] 
* INIT
 60:    LDA  1,0(0)	set first frame at end of globals 
 61:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
 62:    LDA  3,1(7)	Return address in ac 
 63:    JMP  7,-25(7)	Jump to main 
 64:   HALT  0,0,0	DONE! 
* END INIT
