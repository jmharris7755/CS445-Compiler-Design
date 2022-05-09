* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/s02.tm
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
* TOFF:  -6
* IF
 40:     LD  3,-2(1)	1 load variable 861 init
* THEN
* ASSIGNMENT EXPRESSION
 42:    LDC  3,0(6)	Load Integer constant 
 43:     ST  3,-1(0)	Store variable runningSum
 41:    JZR  3,2(7)	Jump around the THEN if false [backpatch] 
* END IF
* ASSIGNMENT EXPRESSION
 44:     LD  3,-3(1)	4 Load variable 851 x
 45:     LD  4,-1(0)	Load LHS var 
 46:    ADD  3,4,3	Op +=
 47:     ST  3,-1(0)	Store variable runningSum
* RETURN
 48:     LD  3,-1(0)	1 Load variable 797 runningSum
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
* END FUNCTION sum
* TOFF: -2
* FUNCTION main
 57:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -2
* ASSIGNMENT EXPRESSION
 58:    LDC  3,7000(6)	Load Integer constant 
 59:     ST  3,0(0)	Store variable runningSum
* CALL EXPRESSION
* CALL output
 60:     ST  1,-2(1)	1 Store fp in ghost frame for output
* Param 1
 61:     LD  3,0(0)	1 variable runningSum
* TOFF: -3
* TOFF: -4
 62:     LD  3,0(0)	1 Load variable 797 runningSum
 63:     ST  3,-4(1)	Push parameter 1001 
* Param end output
 64:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
 65:    LDA  3,1(7)	Return address in ac 
 66:    JMP  7,-61(7)	CALL OUTPUT output
 67:    LDA  3,0(2)	Save the result in ac 
* CALL end output
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
 71:    LDC  3,666(6)	Load integer constant 
 72:     ST  3,-5(1)	3 Push parameter 
* Param end sum
 73:    LDA  1,-2(1)	Ghost frame becomes new active frame 
 74:    LDA  3,1(7)	Return address in ac 
 75:    JMP  7,-37(7)	CALL OUTPUT sum
 76:    LDA  3,0(2)	Save the result in ac 
* CALL end sum
* TOFF: -2
* CALL EXPRESSION
* CALL sum
* TOFF: -2
 77:     ST  1,-2(1)	2 Store fp in ghost frame for sum
* TOFF: -3
* TOFF: -4
* 1071 Param 1
 78:    LDC  3,0(6)	Load Boolean constant 
 79:     ST  3,-4(1)	3 Push parameter 
* TOFF: -5
* 1071 Param 2
 80:    LDC  3,3(6)	Load integer constant 
 81:     ST  3,-5(1)	3 Push parameter 
* Param end sum
 82:    LDA  1,-2(1)	Ghost frame becomes new active frame 
 83:    LDA  3,1(7)	Return address in ac 
 84:    JMP  7,-46(7)	CALL OUTPUT sum
 85:    LDA  3,0(2)	Save the result in ac 
* CALL end sum
* TOFF: -2
* CALL EXPRESSION
* CALL output
 86:     ST  1,-2(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -3
* TOFF: -4
* CALL EXPRESSION
* CALL sum
* TOFF: -4
 87:     ST  1,-4(1)	2 Store fp in ghost frame for sum
* TOFF: -5
* TOFF: -6
* 1071 Param 1
 88:    LDC  3,0(6)	Load Boolean constant 
 89:     ST  3,-6(1)	3 Push parameter 
* TOFF: -7
* 1071 Param 2
 90:    LDC  3,0(6)	Load integer constant 
 91:     ST  3,-7(1)	3 Push parameter 
* Param end sum
 92:    LDA  1,-4(1)	Ghost frame becomes new active frame 
 93:    LDA  3,1(7)	Return address in ac 
 94:    JMP  7,-56(7)	CALL OUTPUT sum
 95:    LDA  3,0(2)	Save the result in ac 
* CALL end sum
* TOFF: -4
 96:     ST  3,-4(1)	Push parameter 1001 
* Param end output
 97:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
 98:    LDA  3,1(7)	Return address in ac 
 99:    JMP  7,-94(7)	CALL OUTPUT output
100:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -2
* CALL EXPRESSION
* CALL output
101:     ST  1,-2(1)	1 Store fp in ghost frame for output
* Param 1
102:     LD  3,0(0)	1 variable runningSum
* TOFF: -3
* TOFF: -4
103:     LD  3,0(0)	1 Load variable 797 runningSum
104:     ST  3,-4(1)	Push parameter 1001 
* Param end output
105:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
106:    LDA  3,1(7)	Return address in ac 
107:    JMP  7,-102(7)	CALL OUTPUT output
108:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -2
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
109:    LDC  2,0(6)	Set return value to 0 
110:     LD  3,-1(1)	Load return address 
111:     LD  1,0(1)	Adjust fp 
112:    JMP  7,0(3)	Return 
* END FUNCTION main
* TOFF: -2
  0:    JMP  7,112(7)	Jump to init [backpatch] 
* INIT
113:    LDA  1,-2(0)	set first frame at end of globals 
114:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
115:    LDA  3,1(7)	Return address in ac 
116:    JMP  7,-60(7)	Jump to main 
117:   HALT  0,0,0	DONE! 
* END INIT
