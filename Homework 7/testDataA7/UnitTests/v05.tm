* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/v05.tm
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
* FUNCTION outputs
 39:     ST  3,-1(1)	Store return address 
* COMPOUND
* ASSIGNMENT EXPRESSION
 40:    LDC  3,0(6)	Load Integer constant 
 41:     ST  3,-3(1)	Store variable i
* WHILE
* OP EXPRESSION
 42:     LD  3,-3(1)	2 Load variable i
 43:     ST  3,-3(1)	Save the left side 
* OP EXPRESSION
 44:     LD  3,-2(1)	4 Load address of base of array s
 45:     ST  3,-4(1)	Save the left side 
 46:     LD  4,-4(1)	Load Left into 1 
 47:     LD  4,-3(1)	Load Left into 1 
 48:    TLT  3,4,3	Op < <
 49:    JNZ  3,1(7)	Jump to while part 
* DO
* COMPOUND
* IF
* OP EXPRESSION
* OP EXPRESSION
 51:     LD  3,-2(1)	4 Load address of base of array s
 52:     ST  3,-5(1)	Save the left side 
 53:     LD  3,-3(1)	2 Load variable i
 54:     LD  4,-5(1)	Load Left into 1 
 55:     ST  3,-5(1)	Save the left side 
 56:    LDC  3,0(6)	Load Character constant 
 57:     LD  4,-5(1)	Load Left into 1 
* THEN
* BREAK
 59:    LDA  7,-61(7)	break 
 58:    JZR  3,1(7)	Jump around the THEN if false [backpatch] 
* END IF
* CALL EXPRESSION
* CALL outputc
 60:     ST  1,-4(1)	1 Store fp in ghost frame for outputc
* Param 1
* OP EXPRESSION
 61:     LD  3,-2(1)	4 Load address of base of array s
 62:     ST  3,-8(1)	Save the left side 
 63:     LD  3,-3(1)	2 Load variable i
 64:     LD  4,-8(1)	Load Left into 1 
 65:     ST  3,-7(1)	Push parameter 
* Param end outputc
 66:    LDA  1,-4(1)	1 Ghost frame becomes new active frame 
 67:    LDA  3,1(7)	Return address in ac 
 68:    JMP  7,-41(7)	CALL OUTPUT outputc
 69:    LDA  3,0(2)	Save the result in ac 
