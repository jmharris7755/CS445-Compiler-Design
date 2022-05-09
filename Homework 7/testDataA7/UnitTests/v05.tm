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
 42:     LD  3,-3(1)	2 Load variable 815 i
 43:     ST  3,-4(1)	Push the left side 677 
* TOFF: -5
* OP EXPRESSION
 44:     LD  3,-2(1)	Load address of base of array 543 s
 45:     LD  3,1(3)	Load array size 669 
* TOFF: -4
 46:     LD  4,-4(1)	Load Left into 1 <
 47:    TLT  3,4,3	Op < <
 48:    JNZ  3,1(7)	Jump to while part 
* DO
* COMPOUND
* TOFF:  -4
* IF
* OP EXPRESSION
* OP EXPRESSION
 50:     LD  3,-2(1)	2 Load address of base of array 583 s
 51:     ST  3,-4(1)	Push left side 
* TOFF: -5
 52:     LD  3,-3(1)	2 Load variable 815 i
* TOFF: -4
 53:     LD  4,-4(1)	1 Pop left into ac1 
 54:    SUB  3,4,3	1 Compute location from index 
 55:     LD  3,0(3)	1 Load array element 
 56:     ST  3,-4(1)	Push the left side 677 
* TOFF: -5
 57:    LDC  3,0(6)	Load Character constant 
* TOFF: -4
 58:     LD  4,-4(1)	Load Left into 1 =
 59:    TEQ  3,4,3	Op == =
* THEN
* BREAK
 61:    JMP  7,-13(7)	break 
 60:    JZR  3,1(7)	Jump around the THEN if false [backpatch] 
* END IF
* CALL EXPRESSION
* CALL outputc
 62:     ST  1,-4(1)	1 Store fp in ghost frame for outputc
* Param 1
* TOFF: -5
* TOFF: -6
* OP EXPRESSION
 63:     LD  3,-2(1)	2 Load address of base of array 583 s
 64:     ST  3,-6(1)	Push left side 
* TOFF: -7
 65:     LD  3,-3(1)	2 Load variable 815 i
* TOFF: -6
 66:     LD  4,-6(1)	1 Pop left into ac1 
 67:    SUB  3,4,3	1 Compute location from index 
 68:     LD  3,0(3)	1 Load array element 
 69:     ST  3,-6(1)	Push parameter 1001 
* Param end outputc
 70:    LDA  1,-4(1)	1 Ghost frame becomes new active frame 
 71:    LDA  3,1(7)	Return address in ac 
 72:    JMP  7,-45(7)	CALL OUTPUT outputc
 73:    LDA  3,0(2)	Save the result in ac 
* CALL end outputc
* TOFF: -4
* ASSIGNMENT EXPRESSION
 74:     LD  3,-3(1)	2 Load variable 815 i
 75:    LDA  3,1(3)	increment value of i
 76:     ST  3,-3(1)	Store variable i
* Compound Body
* TOFF:  -4
* END COMPOUND
 77:    JMP  7,-36(7)	go to the beginning of the loop 
 49:    JMP  7,28(7)	Jump past loop [backpatch] 
* END WHILE
* Compound Body
* TOFF:  -4
* END COMPOUND
* Add standard closing in case there is no return statement
 78:    LDC  2,0(6)	Set return value to 0 
 79:     LD  3,-1(1)	Load return address 
 80:     LD  1,0(1)	Adjust fp 
 81:    JMP  7,0(3)	Return 
* END FUNCTION outputs
* TOFF: -2
* FUNCTION main
 82:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -39
 83:    LDC  3,10(6)	load array size 124 a
 84:     ST  3,-2(1)	save array size a
  1:    LIT  "armadillo"
 85:    LDA  3,-1(0)	Load address of char array 
 86:    LDA  4,-3(1)	address of lhs 
 87:     LD  5,1(3)	size of rhs 
 88:     LD  6,1(4)	size of lhs 
 89:    SWP  5,6,6	pick smallest size 
 90:    MOV  4,3,5	array op = 
 91:    LDC  3,4(6)	load array size 124 b
 92:     ST  3,-13(1)	save array size b
 11:    LIT  "bat"
 93:    LDA  3,-11(0)	Load address of char array 
 94:    LDA  4,-14(1)	address of lhs 
 95:     LD  5,1(3)	size of rhs 
 96:     LD  6,1(4)	size of lhs 
 97:    SWP  5,6,6	pick smallest size 
 98:    MOV  4,3,5	array op = 
 99:    LDC  3,6(6)	load array size 124 h
100:     ST  3,-18(1)	save array size h
 15:    LIT  "horse"
101:    LDA  3,-15(0)	Load address of char array 
102:    LDA  4,-19(1)	address of lhs 
103:     LD  5,1(3)	size of rhs 
104:     LD  6,1(4)	size of lhs 
105:    SWP  5,6,6	pick smallest size 
106:    MOV  4,3,5	array op = 
107:    LDC  3,10(6)	load array size 124 big
108:     ST  3,-25(1)	save array size big
109:    LDC  3,2(6)	load array size 124 small
110:     ST  3,-36(1)	save array size small
* ASSIGNMENT EXPRESSION
111:    LDA  3,-3(1)	Load address of char array a
112:    LDA  4,-37(1)	address of lhs 
113:     LD  5,1(3)	size of rhs 
114:     LD  6,1(4)	size of lhs 
115:    SWP  5,6,6	pick smallest size 
116:    MOV  4,3,5	array op = 
* CALL EXPRESSION
* CALL outputs
117:     ST  1,-39(1)	1 Store fp in ghost frame for outputs
* Param 1
* TOFF: -41
* TOFF: -41
118:    LDA  3,-37(1)	2 Load address of base of array 783 small
* TOFF: -41
119:     ST  3,-41(1)	Push parameter 1001 
* Param end outputs
120:    LDA  1,-39(1)	1 Ghost frame becomes new active frame 
121:    LDA  3,1(7)	Return address in ac 
122:    JMP  7,-84(7)	CALL OUTPUT outputs
123:    LDA  3,0(2)	Save the result in ac 
* CALL end outputs
* TOFF: -39
* CALL EXPRESSION
* CALL outnl
124:     ST  1,-39(1)	3 Store fp in ghost frame for outnl
* Param end outnl
125:    LDA  1,-39(1)	Ghost frame becomes new active frame 
126:    LDA  3,1(7)	Return address in ac 
127:    JMP  7,-94(7)	CALL OUTPUT outnl
128:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -39
* ASSIGNMENT EXPRESSION
129:    LDA  3,-3(1)	Load address of char array a
130:    LDA  4,-26(1)	address of lhs 
131:     LD  5,1(3)	size of rhs 
132:     LD  6,1(4)	size of lhs 
133:    SWP  5,6,6	pick smallest size 
134:    MOV  4,3,5	array op = 
* CALL EXPRESSION
* CALL outputs
135:     ST  1,-39(1)	1 Store fp in ghost frame for outputs
* Param 1
* TOFF: -41
* TOFF: -41
136:    LDA  3,-26(1)	2 Load address of base of array 783 big
* TOFF: -41
137:     ST  3,-41(1)	Push parameter 1001 
* Param end outputs
138:    LDA  1,-39(1)	1 Ghost frame becomes new active frame 
139:    LDA  3,1(7)	Return address in ac 
140:    JMP  7,-102(7)	CALL OUTPUT outputs
141:    LDA  3,0(2)	Save the result in ac 
* CALL end outputs
* TOFF: -39
* CALL EXPRESSION
* CALL outnl
142:     ST  1,-39(1)	3 Store fp in ghost frame for outnl
* Param end outnl
143:    LDA  1,-39(1)	Ghost frame becomes new active frame 
144:    LDA  3,1(7)	Return address in ac 
145:    JMP  7,-112(7)	CALL OUTPUT outnl
146:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -39
* CALL EXPRESSION
* CALL outnl
147:     ST  1,-39(1)	3 Store fp in ghost frame for outnl
* Param end outnl
148:    LDA  1,-39(1)	Ghost frame becomes new active frame 
149:    LDA  3,1(7)	Return address in ac 
150:    JMP  7,-117(7)	CALL OUTPUT outnl
151:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -39
* ASSIGNMENT EXPRESSION
152:    LDA  3,-14(1)	Load address of char array b
153:    LDA  4,-37(1)	address of lhs 
154:     LD  5,1(3)	size of rhs 
155:     LD  6,1(4)	size of lhs 
156:    SWP  5,6,6	pick smallest size 
157:    MOV  4,3,5	array op = 
* CALL EXPRESSION
* CALL outputs
158:     ST  1,-39(1)	1 Store fp in ghost frame for outputs
* Param 1
* TOFF: -41
* TOFF: -41
159:    LDA  3,-37(1)	2 Load address of base of array 783 small
* TOFF: -41
160:     ST  3,-41(1)	Push parameter 1001 
* Param end outputs
161:    LDA  1,-39(1)	1 Ghost frame becomes new active frame 
162:    LDA  3,1(7)	Return address in ac 
163:    JMP  7,-125(7)	CALL OUTPUT outputs
164:    LDA  3,0(2)	Save the result in ac 
* CALL end outputs
* TOFF: -39
* CALL EXPRESSION
* CALL outnl
165:     ST  1,-39(1)	3 Store fp in ghost frame for outnl
* Param end outnl
166:    LDA  1,-39(1)	Ghost frame becomes new active frame 
167:    LDA  3,1(7)	Return address in ac 
168:    JMP  7,-135(7)	CALL OUTPUT outnl
169:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -39
* ASSIGNMENT EXPRESSION
170:    LDA  3,-14(1)	Load address of char array b
171:    LDA  4,-26(1)	address of lhs 
172:     LD  5,1(3)	size of rhs 
173:     LD  6,1(4)	size of lhs 
174:    SWP  5,6,6	pick smallest size 
175:    MOV  4,3,5	array op = 
* CALL EXPRESSION
* CALL outputs
176:     ST  1,-39(1)	1 Store fp in ghost frame for outputs
* Param 1
* TOFF: -41
* TOFF: -41
177:    LDA  3,-26(1)	2 Load address of base of array 783 big
* TOFF: -41
178:     ST  3,-41(1)	Push parameter 1001 
* Param end outputs
179:    LDA  1,-39(1)	1 Ghost frame becomes new active frame 
180:    LDA  3,1(7)	Return address in ac 
181:    JMP  7,-143(7)	CALL OUTPUT outputs
182:    LDA  3,0(2)	Save the result in ac 
* CALL end outputs
* TOFF: -39
* CALL EXPRESSION
* CALL outnl
183:     ST  1,-39(1)	3 Store fp in ghost frame for outnl
* Param end outnl
184:    LDA  1,-39(1)	Ghost frame becomes new active frame 
185:    LDA  3,1(7)	Return address in ac 
186:    JMP  7,-153(7)	CALL OUTPUT outnl
187:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -39
* CALL EXPRESSION
* CALL outnl
188:     ST  1,-39(1)	3 Store fp in ghost frame for outnl
* Param end outnl
189:    LDA  1,-39(1)	Ghost frame becomes new active frame 
190:    LDA  3,1(7)	Return address in ac 
191:    JMP  7,-158(7)	CALL OUTPUT outnl
192:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -39
* ASSIGNMENT EXPRESSION
193:    LDA  3,-19(1)	Load address of char array h
194:    LDA  4,-37(1)	address of lhs 
195:     LD  5,1(3)	size of rhs 
196:     LD  6,1(4)	size of lhs 
197:    SWP  5,6,6	pick smallest size 
198:    MOV  4,3,5	array op = 
* CALL EXPRESSION
* CALL outputs
199:     ST  1,-39(1)	1 Store fp in ghost frame for outputs
* Param 1
* TOFF: -41
* TOFF: -41
200:    LDA  3,-37(1)	2 Load address of base of array 783 small
* TOFF: -41
201:     ST  3,-41(1)	Push parameter 1001 
* Param end outputs
202:    LDA  1,-39(1)	1 Ghost frame becomes new active frame 
203:    LDA  3,1(7)	Return address in ac 
204:    JMP  7,-166(7)	CALL OUTPUT outputs
205:    LDA  3,0(2)	Save the result in ac 
* CALL end outputs
* TOFF: -39
* CALL EXPRESSION
* CALL outnl
206:     ST  1,-39(1)	3 Store fp in ghost frame for outnl
* Param end outnl
207:    LDA  1,-39(1)	Ghost frame becomes new active frame 
208:    LDA  3,1(7)	Return address in ac 
209:    JMP  7,-176(7)	CALL OUTPUT outnl
210:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -39
* ASSIGNMENT EXPRESSION
211:    LDA  3,-19(1)	Load address of char array h
212:    LDA  4,-26(1)	address of lhs 
213:     LD  5,1(3)	size of rhs 
214:     LD  6,1(4)	size of lhs 
215:    SWP  5,6,6	pick smallest size 
216:    MOV  4,3,5	array op = 
* CALL EXPRESSION
* CALL outputs
217:     ST  1,-39(1)	1 Store fp in ghost frame for outputs
* Param 1
* TOFF: -41
* TOFF: -41
218:    LDA  3,-26(1)	2 Load address of base of array 783 big
* TOFF: -41
219:     ST  3,-41(1)	Push parameter 1001 
* Param end outputs
220:    LDA  1,-39(1)	1 Ghost frame becomes new active frame 
221:    LDA  3,1(7)	Return address in ac 
222:    JMP  7,-184(7)	CALL OUTPUT outputs
223:    LDA  3,0(2)	Save the result in ac 
* CALL end outputs
* TOFF: -39
* CALL EXPRESSION
* CALL outnl
224:     ST  1,-39(1)	3 Store fp in ghost frame for outnl
* Param end outnl
225:    LDA  1,-39(1)	Ghost frame becomes new active frame 
226:    LDA  3,1(7)	Return address in ac 
227:    JMP  7,-194(7)	CALL OUTPUT outnl
228:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -39
* CALL EXPRESSION
* CALL outnl
229:     ST  1,-39(1)	3 Store fp in ghost frame for outnl
* Param end outnl
230:    LDA  1,-39(1)	Ghost frame becomes new active frame 
231:    LDA  3,1(7)	Return address in ac 
232:    JMP  7,-199(7)	CALL OUTPUT outnl
233:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -39
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
234:    LDC  2,0(6)	Set return value to 0 
235:     LD  3,-1(1)	Load return address 
236:     LD  1,0(1)	Adjust fp 
237:    JMP  7,0(3)	Return 
* END FUNCTION main
* TOFF: -2
  0:    JMP  7,237(7)	Jump to init [backpatch] 
* INIT
238:    LDA  1,-20(0)	set first frame at end of globals 
239:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
240:    LDA  3,1(7)	Return address in ac 
241:    JMP  7,-160(7)	Jump to main 
242:   HALT  0,0,0	DONE! 
* END INIT
