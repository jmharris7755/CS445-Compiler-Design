* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/t02.tm
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
* FUNCTION factorial
 39:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -3
* IF
* OP EXPRESSION
 40:     ST  3,-3(1)	Push the left side 
 41:    LDC  3,2(6)	Load Integer constant 
 42:     LD  4,-3(1)	Load Left into 1 
 43:    TLT  3,4,3	Op < <
* THEN
* COMPOUND
* TOFF:  -3
* ASSIGNMENT EXPRESSION
 45:     ST  3,-3(1)	Push index 
 46:    LDC  3,1(6)	Load Integer constant 
 47:     LD  4,-3(1)	Pop index 
 48:    LDA  5,-1(0)	Load address of base of array k
 49:    SUB  5,5,4	Compute offset of value 
 50:     ST  3,0(5)	Store variable k
* Compound Body
* TOFF:  -3
* END COMPOUND
 44:    JZR  3,7(7)	Jump around the THEN if false [backpatch] 
* ELSE
* COMPOUND
* TOFF:  -3
* ASSIGNMENT EXPRESSION
 52:     ST  3,-3(1)	Push index 
* OP EXPRESSION
 53:     ST  3,-4(1)	Push the left side 
* CALL EXPRESSION
* CALL factorial
 54:     ST  1,-5(1)	1 Store fp in ghost frame for factorial
* Param 1
* TOFF: -7
* OP EXPRESSION
 55:     ST  3,-7(1)	Push the left side 
 56:    LDC  3,1(6)	Load Integer constant 
 57:     LD  4,-7(1)	Load Left into 1 
 58:    SUB  3,4,3	Op - -
 59:     ST  3,-7(1)	Push parameter 
* Param end factorial
 60:    LDA  1,-5(1)	1 Ghost frame becomes new active frame 
 61:    LDA  3,1(7)	Return address in ac 
 62:    JMP  7,-24(7)	CALL OUTPUT factorial
 63:    LDA  3,0(2)	Save the result in ac 
* CALL end factorial
 64:     LD  4,-4(1)	Load Left into 1 
 65:    MUL  3,4,3	Op % *
 66:     LD  4,-3(1)	Pop index 
 67:    LDA  5,-1(0)	Load address of base of array k
 68:    SUB  5,5,4	Compute offset of value 
 69:     ST  3,0(5)	Store variable k
* Compound Body
* TOFF:  -3
* END COMPOUND
 44:    JZR  3,25(7)	Jump around the ELSE [backpatch] 
* END IF
* RETURN
* OP EXPRESSION
 70:    LDA  3,-1(0)	1 Load address of base of array 505 k
 71:     ST  3,-3(1)	Push left side 
 72:     LD  4,-3(1)	Pop left into ac1 
 73:    SUB  3,4,3	Compute location from index 
 74:     LD  3,0(3)	Load array element 
 75:    LDA  2,0(3)	Copy result to ret register 
 76:     LD  3,-1(1)	Load return address 
 77:     LD  1,0(1)	Adjust fp 
 78:    JMP  7,0(3)	Return 
* Compound Body
* TOFF:  -3
* END COMPOUND
* Add standard closing in case there is no return statement
 79:    LDC  2,0(6)	Set return value to 0 
 80:     LD  3,-1(1)	Load return address 
 81:     LD  1,0(1)	Adjust fp 
 82:    JMP  7,0(3)	Return 
* END FUNCTION factorial
* FUNCTION main
 83:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -3
* ASSIGNMENT EXPRESSION
 84:    LDC  3,10(6)	Load Integer constant 
 85:     ST  3,-2(1)	Store variable n
* ASSIGNMENT EXPRESSION
* CALL EXPRESSION
* CALL factorial
 86:     ST  1,-4(1)	1 Store fp in ghost frame for factorial
* Param 1
* TOFF: -6
 87:     LD  3,-2(1)	2 Load variable n
 88:     ST  3,-6(1)	Push parameter 
* Param end factorial
 89:    LDA  1,-4(1)	1 Ghost frame becomes new active frame 
 90:    LDA  3,1(7)	Return address in ac 
 91:    JMP  7,-53(7)	CALL OUTPUT factorial
 92:    LDA  3,0(2)	Save the result in ac 
* CALL end factorial
 93:     ST  3,-2(1)	Store variable n
* CALL EXPRESSION
* CALL output
 94:     ST  1,-5(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -7
 95:     LD  3,-2(1)	2 Load variable n
 96:     ST  3,-7(1)	Push parameter 
* Param end output
 97:    LDA  1,-5(1)	1 Ghost frame becomes new active frame 
 98:    LDA  3,1(7)	Return address in ac 
 99:    JMP  7,-94(7)	CALL OUTPUT output
100:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
101:     ST  1,-5(1)	3 Store fp in ghost frame for outnl
* Param end outnl
102:    LDA  1,-5(1)	Ghost frame becomes new active frame 
103:    LDA  3,1(7)	Return address in ac 
104:    JMP  7,-71(7)	CALL OUTPUT outnl
105:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
106:    LDC  2,0(6)	Set return value to 0 
107:     LD  3,-1(1)	Load return address 
108:     LD  1,0(1)	Adjust fp 
109:    JMP  7,0(3)	Return 
* END FUNCTION main
  0:    JMP  7,109(7)	Jump to init [backpatch] 
* INIT
110:    LDA  1,-21(0)	set first frame at end of globals 
111:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
112:    LDC  3,20(6)	load size of array k
113:     ST  3,0(0)	save size of array k
* END INIT GLOBALS AND STATICS
114:    LDA  3,1(7)	Return address in ac 
115:    JMP  7,-33(7)	Jump to main 
116:   HALT  0,0,0	DONE! 
* END INIT
