* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/h04.tm
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
* TOFF: -4
* OP EXPRESSION
* OP EXPRESSION
 70:     LD  3,-2(1)	2 Load address of base of array 583 x
 71:     ST  3,-4(1)	Push left side 
* TOFF: -5
 72:    LDC  3,3(6)	Load Integer constant 
* TOFF: -4
 73:     LD  4,-4(1)	1 Pop left into ac1 
 74:    SUB  3,4,3	1 Compute location from index 
 75:     LD  3,0(3)	1 Load array element 
 76:     ST  3,-4(1)	Push the left side 
* TOFF: -5
 77:    LDC  3,1(6)	Load Integer constant 
* TOFF: -4
 78:     LD  4,-4(1)	Load Left into 1 -
 79:    SUB  3,4,3	Op - -
* TOFF: -3
 80:     LD  4,-3(1)	Pop index 
 81:     LD  5,-2(1)	Load address of base of array 387 x
 82:    SUB  5,5,4	Compute offset of value 
 83:     ST  3,0(5)	Store variable x
* CALL EXPRESSION
* CALL cat
 84:     ST  1,-3(1)	1 Store fp in ghost frame for cat
* Param 1
* TOFF: -4
* TOFF: -4
 85:     LD  3,-2(1)	load address of base of array 836 x
 86:     ST  3,-5(1)	Push parameter 
* Param end cat
 87:    LDA  1,-3(1)	1 Ghost frame becomes new active frame 
 88:    LDA  3,1(7)	Return address in ac 
 89:    JMP  7,-51(7)	CALL OUTPUT cat
 90:    LDA  3,0(2)	Save the result in ac 
* CALL end cat
* TOFF: -3
* Compound Body
* TOFF:  -3
* END COMPOUND
 67:    JZR  3,23(7)	Jump around the THEN if false [backpatch] 
* END IF
* RETURN
 91:     LD  3,-1(1)	Load return address 
 92:     LD  1,0(1)	Adjust fp 
 93:    JMP  7,0(3)	Return 
* Compound Body
* TOFF:  -3
* END COMPOUND
* Add standard closing in case there is no return statement
 94:    LDC  2,0(6)	Set return value to 0 
 95:     LD  3,-1(1)	Load return address 
 96:     LD  1,0(1)	Adjust fp 
 97:    JMP  7,0(3)	Return 
* END FUNCTION cat
* TOFF: -2
* FUNCTION main
 98:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -2
* ASSIGNMENT EXPRESSION
 99:    LDC  3,3(6)	Load Integer constant 
100:     ST  3,-2(1)	Push index 
* TOFF: -3
101:    LDC  3,12(6)	Load Integer constant 
* TOFF: -2
102:     LD  4,-2(1)	Pop index 
103:    LDA  5,-1(0)	Load address of base of array 383 x
104:    SUB  5,5,4	Compute offset of value 
105:     ST  3,0(5)	Store variable x
* CALL EXPRESSION
* CALL cat
106:     ST  1,-2(1)	1 Store fp in ghost frame for cat
* Param 1
107:     LD  3,-1(0)	1 variable x
* TOFF: -3
* TOFF: -3
108:     ST  3,-3(1)	Push parameter 
* Param end cat
109:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
110:    LDA  3,1(7)	Return address in ac 
111:    JMP  7,-73(7)	CALL OUTPUT cat
112:    LDA  3,0(2)	Save the result in ac 
* CALL end cat
* TOFF: -2
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
113:    LDC  2,0(6)	Set return value to 0 
114:     LD  3,-1(1)	Load return address 
115:     LD  1,0(1)	Adjust fp 
116:    JMP  7,0(3)	Return 
* END FUNCTION main
* TOFF: -2
  0:    JMP  7,116(7)	Jump to init [backpatch] 
* INIT
117:    LDA  1,-19(0)	set first frame at end of globals 
118:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
119:    LDC  3,18(6)	load size of array x
120:     ST  3,0(0)	save size of array x
* END INIT GLOBALS AND STATICS
121:    LDA  3,1(7)	Return address in ac 
122:    JMP  7,-25(7)	Jump to main 
123:   HALT  0,0,0	DONE! 
* END INIT
