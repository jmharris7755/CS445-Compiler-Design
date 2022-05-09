* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/t01.tm
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
* TOFF:  -4
* IF
* OP EXPRESSION
 40:     LD  3,-2(1)	1 load variable 861 n
 41:     ST  3,-4(1)	Push the left side 677 
* TOFF: -5
 42:    LDC  3,2(6)	Load Integer constant 
* TOFF: -4
 43:     LD  4,-4(1)	Load Left into 1 <
 44:    TLT  3,4,3	Op < <
* THEN
* COMPOUND
* TOFF:  -4
* ASSIGNMENT EXPRESSION
 46:     LD  3,-2(1)	1 load variable 861 n
 47:     ST  3,-4(1)	Push index 373 
* TOFF: -5
 48:    LDC  3,1(6)	Load Integer constant 
* TOFF: -4
 49:     LD  4,-4(1)	Pop index 
 50:     LD  5,-3(1)	Load address of base of array 500 k
 51:    SUB  5,5,4	Compute offset of value 
 52:     ST  3,0(5)	Store variable k
* Compound Body
* TOFF:  -4
* END COMPOUND
 45:    JZR  3,8(7)	Jump around the THEN if false [backpatch] 
* ELSE
* COMPOUND
* TOFF:  -4
* ASSIGNMENT EXPRESSION
 54:     LD  3,-2(1)	1 load variable 861 n
 55:     ST  3,-4(1)	Push index 373 
* TOFF: -5
* OP EXPRESSION
 56:     LD  3,-2(1)	1 load variable 861 n
 57:     ST  3,-5(1)	Push the left side 677 
* TOFF: -6
* CALL EXPRESSION
* CALL factorial
* TOFF: -6
 58:     ST  1,-6(1)	2 Store fp in ghost frame for factorial
* TOFF: -7
* TOFF: -8
* 1071 Param 1
* OP EXPRESSION
 59:     LD  3,-2(1)	1 load variable 861 n
 60:     ST  3,-8(1)	Push the left side 677 
* TOFF: -9
 61:    LDC  3,1(6)	Load Integer constant 
* TOFF: -8
 62:     LD  4,-8(1)	Load Left into 1 -
 63:    SUB  3,4,3	Op - -
 64:     ST  3,-8(1)	1115 Push parameter 
* TOFF: -9
* 1071 Param 2
 65:     LD  3,-3(1)	Load address of base of array 1119 k
 66:     ST  3,-9(1)	1101 Push parameter 
* Param end factorial
 67:    LDA  1,-6(1)	Ghost frame becomes new active frame 
 68:    LDA  3,1(7)	Return address in ac 
 69:    JMP  7,-31(7)	CALL OUTPUT factorial
 70:    LDA  3,0(2)	Save the result in ac 
* CALL end factorial
* TOFF: -6
* TOFF: -5
 71:     LD  4,-5(1)	Load Left into 1 *
 72:    MUL  3,4,3	Op * *
* TOFF: -4
 73:     LD  4,-4(1)	Pop index 
 74:     LD  5,-3(1)	Load address of base of array 493 k
 75:    SUB  5,5,4	Compute offset of value 
 76:     ST  3,0(5)	Store variable k
* Compound Body
* TOFF:  -4
* END COMPOUND
 53:    JMP  7,23(7)	Jump around the ELSE [backpatch] 
* END IF
* RETURN
* OP EXPRESSION
 77:     LD  3,-3(1)	2 Load address of base of array 583 k
 78:     ST  3,-4(1)	Push left side 
* TOFF: -5
 79:     LD  3,-2(1)	1 load variable 861 n
* TOFF: -4
 80:     LD  4,-4(1)	1 Pop left into ac1 
 81:    SUB  3,4,3	1 Compute location from index 
 82:     LD  3,0(3)	1 Load array element 
 83:    LDA  2,0(3)	Copy result to ret register 
 84:     LD  3,-1(1)	Load return address 
 85:     LD  1,0(1)	Adjust fp 
 86:    JMP  7,0(3)	Return 
* Compound Body
* TOFF:  -4
* END COMPOUND
* Add standard closing in case there is no return statement
 87:    LDC  2,0(6)	Set return value to 0 
 88:     LD  3,-1(1)	Load return address 
 89:     LD  1,0(1)	Adjust fp 
 90:    JMP  7,0(3)	Return 
* END FUNCTION factorial
* TOFF: -2
* FUNCTION main
 91:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -24
 92:    LDC  3,20(6)	load array size 124 k
 93:     ST  3,-3(1)	save array size k
* ASSIGNMENT EXPRESSION
 94:    LDC  3,10(6)	Load Integer constant 
 95:     ST  3,-2(1)	Store variable n
* ASSIGNMENT EXPRESSION
* CALL EXPRESSION
* CALL factorial
* TOFF: -24
 96:     ST  1,-24(1)	2 Store fp in ghost frame for factorial
* TOFF: -25
* TOFF: -26
* 1071 Param 1
 97:     LD  3,-2(1)	2 Load variable 815 n
 98:     ST  3,-26(1)	1115 Push parameter 
* TOFF: -27
* 1071 Param 2
 99:    LDA  3,-4(1)	Load address of base of array 1123 k
100:     ST  3,-27(1)	1101 Push parameter 
* Param end factorial
101:    LDA  1,-24(1)	Ghost frame becomes new active frame 
102:    LDA  3,1(7)	Return address in ac 
103:    JMP  7,-65(7)	CALL OUTPUT factorial
104:    LDA  3,0(2)	Save the result in ac 
* CALL end factorial
* TOFF: -24
105:     ST  3,-2(1)	Store variable n
* CALL EXPRESSION
* CALL output
106:     ST  1,-24(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -25
* TOFF: -26
107:     LD  3,-2(1)	2 Load variable 815 n
108:     ST  3,-26(1)	Push parameter 1001 
* Param end output
109:    LDA  1,-24(1)	1 Ghost frame becomes new active frame 
110:    LDA  3,1(7)	Return address in ac 
111:    JMP  7,-106(7)	CALL OUTPUT output
112:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -24
* CALL EXPRESSION
* CALL outnl
113:     ST  1,-24(1)	3 Store fp in ghost frame for outnl
* Param end outnl
114:    LDA  1,-24(1)	Ghost frame becomes new active frame 
115:    LDA  3,1(7)	Return address in ac 
116:    JMP  7,-83(7)	CALL OUTPUT outnl
117:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -24
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
118:    LDC  2,0(6)	Set return value to 0 
119:     LD  3,-1(1)	Load return address 
120:     LD  1,0(1)	Adjust fp 
121:    JMP  7,0(3)	Return 
* END FUNCTION main
* TOFF: -2
  0:    JMP  7,121(7)	Jump to init [backpatch] 
* INIT
122:    LDA  1,0(0)	set first frame at end of globals 
123:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
124:    LDA  3,1(7)	Return address in ac 
125:    JMP  7,-35(7)	Jump to main 
126:   HALT  0,0,0	DONE! 
* END INIT
