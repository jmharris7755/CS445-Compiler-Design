* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/s02e.tm
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
* FUNCTION sum
 39:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -4
* IF
 40:     LD  3,-2(1)	1 load variable 861 init
* THEN
* ASSIGNMENT EXPRESSION
 42:    LDC  3,0(6)	Load Integer constant 
 43:     ST  3,-1(0)	Store variable runningSum
 41:    JZR  3,3(7)	Jump around the THEN if false [backpatch] 
* ELSE
* ASSIGNMENT EXPRESSION
 45:     LD  3,-3(1)	4 Load variable 851 x
 46:     LD  4,-1(0)	Load LHS var 
 47:    ADD  3,4,3	Op +=
 48:     ST  3,-1(0)	Store variable runningSum
 44:    JMP  7,4(7)	Jump around the ELSE [backpatch] 
* END IF
* RETURN
 49:     LD  3,-1(0)	1 Load variable 797 runningSum
 50:    LDA  2,0(3)	Copy result to ret register 
 51:     LD  3,-1(1)	Load return address 
 52:     LD  1,0(1)	Adjust fp 
 53:    JMP  7,0(3)	Return 
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
 54:    LDC  2,0(6)	Set return value to 0 
 55:     LD  3,-1(1)	Load return address 
 56:     LD  1,0(1)	Adjust fp 
 57:    JMP  7,0(3)	Return 
* END FUNCTION sum
* TOFF: -2
* FUNCTION main
 58:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -2
* CALL EXPRESSION
* CALL sum
* TOFF: -2
 59:     ST  1,-2(1)	2 Store fp in ghost frame for sum
* TOFF: -3
* TOFF: -4
* 1071 Param 1
 60:    LDC  3,1(6)	Load Boolean constant 
 61:     ST  3,-4(1)	3 Push parameter 
* TOFF: -5
* 1071 Param 2
 62:    LDC  3,666(6)	Load integer constant 
 63:     ST  3,-5(1)	3 Push parameter 
* Param end sum
 64:    LDA  1,-2(1)	Ghost frame becomes new active frame 
 65:    LDA  3,1(7)	Return address in ac 
 66:    JMP  7,-28(7)	CALL OUTPUT sum
 67:    LDA  3,0(2)	Save the result in ac 
* CALL end sum
* TOFF: -2
* CALL EXPRESSION
* CALL sum
* TOFF: -2
 68:     ST  1,-2(1)	2 Store fp in ghost frame for sum
* TOFF: -3
* TOFF: -4
* 1071 Param 1
 69:    LDC  3,0(6)	Load Boolean constant 
 70:     ST  3,-4(1)	3 Push parameter 
* TOFF: -5
* 1071 Param 2
 71:    LDC  3,777(6)	Load integer constant 
 72:     ST  3,-5(1)	3 Push parameter 
* Param end sum
 73:    LDA  1,-2(1)	Ghost frame becomes new active frame 
 74:    LDA  3,1(7)	Return address in ac 
 75:    JMP  7,-37(7)	CALL OUTPUT sum
 76:    LDA  3,0(2)	Save the result in ac 
* CALL end sum
* TOFF: -2
* CALL EXPRESSION
* CALL output
 77:     ST  1,-2(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -3
* TOFF: -4
* CALL EXPRESSION
* CALL sum
* TOFF: -4
 78:     ST  1,-4(1)	2 Store fp in ghost frame for sum
* TOFF: -5
* TOFF: -6
* 1071 Param 1
 79:    LDC  3,0(6)	Load Boolean constant 
 80:     ST  3,-6(1)	3 Push parameter 
* TOFF: -7
* 1071 Param 2
 81:    LDC  3,0(6)	Load integer constant 
 82:     ST  3,-7(1)	3 Push parameter 
* Param end sum
 83:    LDA  1,-4(1)	Ghost frame becomes new active frame 
 84:    LDA  3,1(7)	Return address in ac 
 85:    JMP  7,-47(7)	CALL OUTPUT sum
 86:    LDA  3,0(2)	Save the result in ac 
* CALL end sum
* TOFF: -4
 87:     ST  3,-4(1)	Push parameter 1001 
* Param end output
 88:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
 89:    LDA  3,1(7)	Return address in ac 
 90:    JMP  7,-85(7)	CALL OUTPUT output
 91:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -2
* CALL EXPRESSION
* CALL sum
* TOFF: -2
 92:     ST  1,-2(1)	2 Store fp in ghost frame for sum
* TOFF: -3
* TOFF: -4
* 1071 Param 1
 93:    LDC  3,0(6)	Load Boolean constant 
 94:     ST  3,-4(1)	3 Push parameter 
* TOFF: -5
* 1071 Param 2
 95:    LDC  3,888(6)	Load integer constant 
 96:     ST  3,-5(1)	3 Push parameter 
* Param end sum
 97:    LDA  1,-2(1)	Ghost frame becomes new active frame 
 98:    LDA  3,1(7)	Return address in ac 
 99:    JMP  7,-61(7)	CALL OUTPUT sum
100:    LDA  3,0(2)	Save the result in ac 
* CALL end sum
* TOFF: -2
* CALL EXPRESSION
* CALL output
101:     ST  1,-2(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -3
* TOFF: -4
* CALL EXPRESSION
* CALL sum
* TOFF: -4
102:     ST  1,-4(1)	2 Store fp in ghost frame for sum
* TOFF: -5
* TOFF: -6
* 1071 Param 1
103:    LDC  3,0(6)	Load Boolean constant 
104:     ST  3,-6(1)	3 Push parameter 
* TOFF: -7
* 1071 Param 2
105:    LDC  3,0(6)	Load integer constant 
106:     ST  3,-7(1)	3 Push parameter 
* Param end sum
107:    LDA  1,-4(1)	Ghost frame becomes new active frame 
108:    LDA  3,1(7)	Return address in ac 
109:    JMP  7,-71(7)	CALL OUTPUT sum
110:    LDA  3,0(2)	Save the result in ac 
* CALL end sum
* TOFF: -4
111:     ST  3,-4(1)	Push parameter 1001 
* Param end output
112:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
113:    LDA  3,1(7)	Return address in ac 
114:    JMP  7,-109(7)	CALL OUTPUT output
115:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -2
* CALL EXPRESSION
* CALL outnl
116:     ST  1,-2(1)	3 Store fp in ghost frame for outnl
* Param end outnl
117:    LDA  1,-2(1)	Ghost frame becomes new active frame 
118:    LDA  3,1(7)	Return address in ac 
119:    JMP  7,-86(7)	CALL OUTPUT outnl
120:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -2
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
121:    LDC  2,0(6)	Set return value to 0 
122:     LD  3,-1(1)	Load return address 
123:     LD  1,0(1)	Adjust fp 
124:    JMP  7,0(3)	Return 
* END FUNCTION main
* TOFF: -2
  0:    JMP  7,124(7)	Jump to init [backpatch] 
* INIT
125:    LDA  1,-2(0)	set first frame at end of globals 
126:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
127:    LDA  3,1(7)	Return address in ac 
128:    JMP  7,-71(7)	Jump to main 
129:   HALT  0,0,0	DONE! 
* END INIT
