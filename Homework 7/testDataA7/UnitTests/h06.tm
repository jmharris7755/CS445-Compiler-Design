* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/h06.tm
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
* IF
* OP EXPRESSION
 40:     LD  3,-3(1)	1 load variable 861 y
 41:     ST  3,-4(1)	Push the left side 
* TOFF: -5
 42:    LDC  3,0(6)	Load Integer constant 
* TOFF: -4
 43:     LD  4,-4(1)	Load Left into 1 >=
 44:    TGE  3,4,3	Op >= >=
* THEN
* COMPOUND
* TOFF:  -4
* ASSIGNMENT EXPRESSION
 46:     LD  3,-3(1)	1 load variable 373 y
 47:     ST  3,-4(1)	Push index 373 
* TOFF: -5
 48:     LD  3,-3(1)	1 load variable 861 y
* TOFF: -4
 49:     LD  4,-4(1)	Pop index 
 50:    LDA  5,-2(1)	Load address of base of array 390 x
 51:    SUB  5,5,4	Compute offset of value 
 52:     ST  3,0(5)	Store variable x
* CALL EXPRESSION
* CALL cat
* TOFF: -4
 53:     ST  1,-4(1)	2 Store fp in ghost frame for cat
* TOFF: -5
* TOFF: -6
* 1071 Param 1
 54:    LDA  3,-2(1)	Load address of base of array 1037 x
 55:     ST  3,-6(1)	1101 Push parameter 
* TOFF: -7
* 1071 Param 2
* OP EXPRESSION
 56:     LD  3,-3(1)	1 load variable 861 y
 57:     ST  3,-7(1)	Push the left side 
* TOFF: -8
 58:    LDC  3,1(6)	Load Integer constant 
* TOFF: -7
 59:     LD  4,-7(1)	Load Left into 1 -
 60:    SUB  3,4,3	Op - -
 61:     ST  3,-7(1)	1111 Push parameter 
* Param end cat
 62:    LDA  1,-4(1)	Ghost frame becomes new active frame 
 63:    LDA  3,1(7)	Return address in ac 
 64:    JMP  7,-26(7)	CALL OUTPUT cat
 65:    LDA  3,0(2)	Save the result in ac 
* CALL end cat
* TOFF: -4
* Compound Body
* TOFF:  -4
* END COMPOUND
 45:    JZR  3,20(7)	Jump around the THEN if false [backpatch] 
* END IF
* RETURN
 66:     LD  3,-1(1)	Load return address 
 67:     LD  1,0(1)	Adjust fp 
 68:    JMP  7,0(3)	Return 
* Compound Body
* TOFF:  -4
* END COMPOUND
* Add standard closing in case there is no return statement
 69:    LDC  2,0(6)	Set return value to 0 
 70:     LD  3,-1(1)	Load return address 
 71:     LD  1,0(1)	Adjust fp 
 72:    JMP  7,0(3)	Return 
* END FUNCTION cat
* TOFF: -2
* FUNCTION main
 73:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -22
 74:    LDC  3,18(6)	load array size x
 75:     ST  3,-2(1)	save array size x
* ASSIGNMENT EXPRESSION
 76:    LDC  3,12(6)	Load Integer constant 
 77:     ST  3,-21(1)	Store variable y
* CALL EXPRESSION
* CALL cat
* TOFF: -22
 78:     ST  1,-22(1)	2 Store fp in ghost frame for cat
* TOFF: -23
* TOFF: -24
* 1071 Param 1
 79:    LDA  3,-3(1)	Load address of base of array 1037 x
 80:     ST  3,-24(1)	1101 Push parameter 
* TOFF: -25
* 1071 Param 2
 81:     LD  3,-21(1)	2 Load variable 815 y
 82:     ST  3,-25(1)	1111 Push parameter 
* Param end cat
 83:    LDA  1,-22(1)	Ghost frame becomes new active frame 
 84:    LDA  3,1(7)	Return address in ac 
 85:    JMP  7,-47(7)	CALL OUTPUT cat
 86:    LDA  3,0(2)	Save the result in ac 
* CALL end cat
* TOFF: -22
* WHILE
* OP EXPRESSION
 87:     LD  3,-21(1)	2 Load variable 815 y
 88:     ST  3,-22(1)	Push the left side 
* TOFF: -23
 89:    LDC  3,0(6)	Load Integer constant 
* TOFF: -22
 90:     LD  4,-22(1)	Load Left into 1 >=
 91:    TGE  3,4,3	Op >= >=
 92:    JNZ  3,1(7)	Jump to while part 
* DO
* COMPOUND
* TOFF:  -22
* CALL EXPRESSION
* CALL output
 94:     ST  1,-22(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -23
* TOFF: -24
 95:     LD  3,-21(1)	2 Load variable 815 y
 96:     ST  3,-24(1)	Push parameter 
* Param end output
 97:    LDA  1,-22(1)	1 Ghost frame becomes new active frame 
 98:    LDA  3,1(7)	Return address in ac 
 99:    JMP  7,-94(7)	CALL OUTPUT output
100:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -22
* CALL EXPRESSION
* CALL outnl
101:     ST  1,-22(1)	3 Store fp in ghost frame for outnl
* Param end outnl
102:    LDA  1,-22(1)	Ghost frame becomes new active frame 
103:    LDA  3,1(7)	Return address in ac 
104:    JMP  7,-71(7)	CALL OUTPUT outnl
105:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -22
* ASSIGNMENT EXPRESSION
* OP EXPRESSION
106:     LD  3,-21(1)	2 Load variable 815 y
107:     ST  3,-22(1)	Push the left side 
* TOFF: -23
108:    LDC  3,1(6)	Load Integer constant 
* TOFF: -22
109:     LD  4,-22(1)	Load Left into 1 -
110:    SUB  3,4,3	Op - -
111:     ST  3,-21(1)	Store variable y
* Compound Body
* TOFF:  -22
* END COMPOUND
112:    JMP  7,-26(7)	go to the beginning of the loop 
 93:    JMP  7,19(7)	Jump past loop [backpatch] 
* END WHILE
* Compound Body
* TOFF:  -22
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
117:    LDA  1,0(0)	set first frame at end of globals 
118:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
119:    LDA  3,1(7)	Return address in ac 
120:    JMP  7,-48(7)	Jump to main 
121:   HALT  0,0,0	DONE! 
* END INIT
