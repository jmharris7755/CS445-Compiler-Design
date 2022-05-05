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
* TOFF:  -4
* ASSIGNMENT EXPRESSION
 40:    LDC  3,0(6)	Load Integer constant 
 41:     ST  3,-3(1)	Store variable i
* WHILE
* OP EXPRESSION
 42:     LD  3,-3(1)	2 Load variable i
 43:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
 44:    LDA  3,-2(1)	4 Load address of base of array s
 45:    LDA  3,-2(1)	Load address of base of array s
 46:     LD  3,1(3)	Load array size 
 47:     LD  4,-4(1)	Load Left into 1 
 48:    TLT  3,4,3	Op < <
 49:    JNZ  3,1(7)	Jump to while part 
* DO
* COMPOUND
* TOFF:  -4
* IF
* OP EXPRESSION
* OP EXPRESSION
 51:    LDA  3,-2(1)	4 Load address of base of array s
 52:     ST  3,-5(1)	Push the left side 
 53:     LD  3,-3(1)	2 Load variable i
 54:     LD  4,-5(1)	Load Left into 1 
 55:     ST  3,-5(1)	Push the left side 
 56:    LDC  3,0(6)	Load Character constant 
 57:     LD  4,-5(1)	Load Left into 1 
 58:    TEQ  3,4,3	Op == =
* THEN
* BREAK
 60:    LDA  7,-62(7)	break 
 59:    JZR  3,1(7)	Jump around the THEN if false [backpatch] 
* END IF
* CALL EXPRESSION
* CALL outputc
 61:     ST  1,-5(1)	1 Store fp in ghost frame for outputc
* Param 1
* TOFF: -7
* OP EXPRESSION
 62:    LDA  3,-2(1)	4 Load address of base of array s
 63:     ST  3,-8(1)	Push the left side 
 64:     LD  3,-3(1)	2 Load variable i
 65:     LD  4,-8(1)	Load Left into 1 
 66:     ST  3,-8(1)	Push parameter 
* Param end outputc
 67:    LDA  1,-5(1)	1 Ghost frame becomes new active frame 
 68:    LDA  3,1(7)	Return address in ac 
 69:    JMP  7,-42(7)	CALL OUTPUT outputc
 70:    LDA  3,0(2)	Save the result in ac 
* CALL end outputc
* ASSIGNMENT EXPRESSION
 71:     LD  3,-3(1)	2 Load variable i
 72:    LDA  3,1(3)	increment value of i
 73:     ST  3,-3(1)	Store variable i
* Compound Body
* TOFF:  -5
* END COMPOUND
 74:    LDA  7,-33(7)	go to the beginning of the loop 
 50:    JMP  7,24(7)	Jump past loop [backpatch] 
* END WHILE
* Compound Body
* TOFF:  -5
* END COMPOUND
* Add standard closing in case there is no return statement
 75:    LDC  2,0(6)	Set return value to 0 
 76:     LD  3,-1(1)	Load return address 
 77:     LD  1,0(1)	Adjust fp 
 78:    JMP  7,0(3)	Return 
* END FUNCTION outputs
* FUNCTION main
 79:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -39
 80:    LDC  3,10(6)	load array size a
 81:     ST  3,-2(1)	save array size a
 82:    LDC  3,4(6)	load array size b
 83:     ST  3,-13(1)	save array size b
 84:    LDC  3,6(6)	load array size h
 85:     ST  3,-18(1)	save array size h
 86:    LDC  3,10(6)	load array size big
 87:     ST  3,-25(1)	save array size big
 88:    LDC  3,2(6)	load array size small
 89:     ST  3,-36(1)	save array size small
* ASSIGNMENT EXPRESSION
 90:    LDA  3,-3(1)	2 Load address of base of array a
* CALL EXPRESSION
* CALL outputs
 91:     ST  1,-41(1)	1 Store fp in ghost frame for outputs
* Param 1
* TOFF: -42
 92:     ST  3,-42(1)	Push parameter 
* Param end outputs
 93:    LDA  1,-41(1)	1 Ghost frame becomes new active frame 
 94:    LDA  3,1(7)	Return address in ac 
 95:    JMP  7,-95(7)	CALL OUTPUT outputs
 96:    LDA  3,0(2)	Save the result in ac 
* CALL end outputs
* CALL EXPRESSION
* CALL outnl
 97:     ST  1,-41(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 98:    LDA  1,-41(1)	Ghost frame becomes new active frame 
 99:    LDA  3,1(7)	Return address in ac 
100:    JMP  7,-67(7)	CALL OUTPUT outnl
101:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* ASSIGNMENT EXPRESSION
* CALL EXPRESSION
* CALL outputs
102:     ST  1,-42(1)	1 Store fp in ghost frame for outputs
* Param 1
* TOFF: -43
103:     ST  3,-43(1)	Push parameter 
* Param end outputs
104:    LDA  1,-42(1)	1 Ghost frame becomes new active frame 
105:    LDA  3,1(7)	Return address in ac 
106:    JMP  7,-106(7)	CALL OUTPUT outputs
107:    LDA  3,0(2)	Save the result in ac 
* CALL end outputs
* CALL EXPRESSION
* CALL outnl
108:     ST  1,-42(1)	3 Store fp in ghost frame for outnl
* Param end outnl
109:    LDA  1,-42(1)	Ghost frame becomes new active frame 
110:    LDA  3,1(7)	Return address in ac 
111:    JMP  7,-78(7)	CALL OUTPUT outnl
112:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* CALL EXPRESSION
* CALL outnl
113:     ST  1,-42(1)	3 Store fp in ghost frame for outnl
* Param end outnl
114:    LDA  1,-42(1)	Ghost frame becomes new active frame 
115:    LDA  3,1(7)	Return address in ac 
116:    JMP  7,-83(7)	CALL OUTPUT outnl
117:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* ASSIGNMENT EXPRESSION
* CALL EXPRESSION
* CALL outputs
118:     ST  1,-43(1)	1 Store fp in ghost frame for outputs
* Param 1
* TOFF: -44
119:     ST  3,-44(1)	Push parameter 
* Param end outputs
120:    LDA  1,-43(1)	1 Ghost frame becomes new active frame 
121:    LDA  3,1(7)	Return address in ac 
122:    JMP  7,-122(7)	CALL OUTPUT outputs
123:    LDA  3,0(2)	Save the result in ac 
* CALL end outputs
* CALL EXPRESSION
* CALL outnl
124:     ST  1,-43(1)	3 Store fp in ghost frame for outnl
* Param end outnl
125:    LDA  1,-43(1)	Ghost frame becomes new active frame 
126:    LDA  3,1(7)	Return address in ac 
127:    JMP  7,-94(7)	CALL OUTPUT outnl
128:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* ASSIGNMENT EXPRESSION
* CALL EXPRESSION
* CALL outputs
129:     ST  1,-44(1)	1 Store fp in ghost frame for outputs
* Param 1
* TOFF: -45
130:     ST  3,-45(1)	Push parameter 
* Param end outputs
131:    LDA  1,-44(1)	1 Ghost frame becomes new active frame 
132:    LDA  3,1(7)	Return address in ac 
133:    JMP  7,-133(7)	CALL OUTPUT outputs
134:    LDA  3,0(2)	Save the result in ac 
* CALL end outputs
* CALL EXPRESSION
* CALL outnl
135:     ST  1,-44(1)	3 Store fp in ghost frame for outnl
* Param end outnl
136:    LDA  1,-44(1)	Ghost frame becomes new active frame 
137:    LDA  3,1(7)	Return address in ac 
138:    JMP  7,-105(7)	CALL OUTPUT outnl
139:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* CALL EXPRESSION
* CALL outnl
140:     ST  1,-44(1)	3 Store fp in ghost frame for outnl
* Param end outnl
141:    LDA  1,-44(1)	Ghost frame becomes new active frame 
142:    LDA  3,1(7)	Return address in ac 
143:    JMP  7,-110(7)	CALL OUTPUT outnl
144:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* ASSIGNMENT EXPRESSION
* CALL EXPRESSION
* CALL outputs
145:     ST  1,-45(1)	1 Store fp in ghost frame for outputs
* Param 1
* TOFF: -46
146:     ST  3,-46(1)	Push parameter 
* Param end outputs
147:    LDA  1,-45(1)	1 Ghost frame becomes new active frame 
148:    LDA  3,1(7)	Return address in ac 
149:    JMP  7,-149(7)	CALL OUTPUT outputs
150:    LDA  3,0(2)	Save the result in ac 
* CALL end outputs
* CALL EXPRESSION
* CALL outnl
151:     ST  1,-45(1)	3 Store fp in ghost frame for outnl
* Param end outnl
152:    LDA  1,-45(1)	Ghost frame becomes new active frame 
153:    LDA  3,1(7)	Return address in ac 
154:    JMP  7,-121(7)	CALL OUTPUT outnl
155:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* ASSIGNMENT EXPRESSION
* CALL EXPRESSION
* CALL outputs
156:     ST  1,-46(1)	1 Store fp in ghost frame for outputs
* Param 1
* TOFF: -47
157:     ST  3,-47(1)	Push parameter 
* Param end outputs
158:    LDA  1,-46(1)	1 Ghost frame becomes new active frame 
159:    LDA  3,1(7)	Return address in ac 
160:    JMP  7,-160(7)	CALL OUTPUT outputs
161:    LDA  3,0(2)	Save the result in ac 
* CALL end outputs
* CALL EXPRESSION
* CALL outnl
162:     ST  1,-46(1)	3 Store fp in ghost frame for outnl
* Param end outnl
163:    LDA  1,-46(1)	Ghost frame becomes new active frame 
164:    LDA  3,1(7)	Return address in ac 
165:    JMP  7,-132(7)	CALL OUTPUT outnl
166:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* CALL EXPRESSION
* CALL outnl
167:     ST  1,-46(1)	3 Store fp in ghost frame for outnl
* Param end outnl
168:    LDA  1,-46(1)	Ghost frame becomes new active frame 
169:    LDA  3,1(7)	Return address in ac 
170:    JMP  7,-137(7)	CALL OUTPUT outnl
171:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
172:    LDC  2,0(6)	Set return value to 0 
173:     LD  3,-1(1)	Load return address 
174:     LD  1,0(1)	Adjust fp 
175:    JMP  7,0(3)	Return 
* END FUNCTION main
  0:    JMP  7,175(7)	Jump to init [backpatch] 
* INIT
176:    LDA  1,-23(0)	set first frame at end of globals 
177:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
178:    LDA  3,1(7)	Return address in ac 
179:    JMP  7,-101(7)	Jump to main 
180:   HALT  0,0,0	DONE! 
* END INIT
