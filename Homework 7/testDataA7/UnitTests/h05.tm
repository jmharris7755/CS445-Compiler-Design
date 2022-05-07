* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/h05.tm
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
* TOFF:  -3
* CALL EXPRESSION
* CALL output
 40:     ST  1,-3(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -4
* TOFF: -5
* OP EXPRESSION
 41:     LD  3,-2(1)	2 Load address of base of array 583 x
 42:     ST  3,-5(1)	Push left side 
* TOFF: -6
 43:    LDC  3,3(6)	Load Integer constant 
* TOFF: -5
 44:     LD  4,-5(1)	1 Pop left into ac1 
 45:    SUB  3,4,3	1 Compute location from index 
 46:     LD  3,0(3)	1 Load array element 
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
* IF
* OP EXPRESSION
* OP EXPRESSION
 57:     LD  3,-2(1)	2 Load address of base of array 583 x
 58:     ST  3,-3(1)	Push left side 
* TOFF: -4
 59:    LDC  3,3(6)	Load Integer constant 
* TOFF: -3
 60:     LD  4,-3(1)	1 Pop left into ac1 
 61:    SUB  3,4,3	1 Compute location from index 
 62:     LD  3,0(3)	1 Load array element 
 63:     ST  3,-3(1)	Push the left side 
* TOFF: -4
 64:    LDC  3,0(6)	Load Integer constant 
* TOFF: -3
 65:     LD  4,-3(1)	Load Left into 1 >
 66:    TGT  3,4,3	Op > >
* THEN
* COMPOUND
* TOFF:  -3
* ASSIGNMENT EXPRESSION
 68:    LDC  3,3(6)	Load Integer constant 
 69:     ST  3,-3(1)	Push index 
