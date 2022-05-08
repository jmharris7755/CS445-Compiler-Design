* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/j00.tm
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
* RETURN
* OP EXPRESSION
 40:     LD  3,-2(1)	2 Load address of base of array 583 x
 41:     ST  3,-4(1)	Push left side 
* TOFF: -5
 42:     LD  3,-3(1)	1 load variable 861 i
* TOFF: -4
 43:     LD  4,-4(1)	1 Pop left into ac1 
 44:    SUB  3,4,3	1 Compute location from index 
 45:     LD  3,0(3)	1 Load array element 
 46:    LDA  2,0(3)	Copy result to ret register 
 47:     LD  3,-1(1)	Load return address 
 48:     LD  1,0(1)	Adjust fp 
 49:    JMP  7,0(3)	Return 
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
 50:    LDC  2,0(6)	Set return value to 0 
 51:     LD  3,-1(1)	Load return address 
 52:     LD  1,0(1)	Adjust fp 
 53:    JMP  7,0(3)	Return 
* END FUNCTION cat
* TOFF: -2
* FUNCTION dog
 54:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -4
* RETURN
* CALL EXPRESSION
* CALL cat
* TOFF: -4
 55:     ST  1,-4(1)	2 Store fp in ghost frame for cat
* TOFF: -5
* TOFF: -6
* 1071 Param 1
 56:    LDA  3,-2(1)	Load address of base of array 1123 x
 57:     ST  3,-6(1)	1101 Push parameter 
* TOFF: -7
* 1071 Param 2
 58:     LD  3,-3(1)	1 load variable 861 i
 59:     ST  3,-7(1)	1115 Push parameter 
* Param end cat
 60:    LDA  1,-4(1)	Ghost frame becomes new active frame 
 61:    LDA  3,1(7)	Return address in ac 
 62:    JMP  7,-24(7)	CALL OUTPUT cat
 63:    LDA  3,0(2)	Save the result in ac 
* CALL end cat
* TOFF: -4
 64:    LDA  2,0(3)	Copy result to ret register 
 65:     LD  3,-1(1)	Load return address 
 66:     LD  1,0(1)	Adjust fp 
 67:    JMP  7,0(3)	Return 
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
 68:    LDC  2,0(6)	Set return value to 0 
 69:     LD  3,-1(1)	Load return address 
 70:     LD  1,0(1)	Adjust fp 
 71:    JMP  7,0(3)	Return 
* END FUNCTION dog
* TOFF: -2
* FUNCTION fox
 72:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -4
* RETURN
* CALL EXPRESSION
* CALL dog
* TOFF: -4
 73:     ST  1,-4(1)	2 Store fp in ghost frame for dog
* TOFF: -5
* TOFF: -6
* 1071 Param 1
 74:    LDA  3,-2(1)	Load address of base of array 1123 x
 75:     ST  3,-6(1)	1101 Push parameter 
* TOFF: -7
* 1071 Param 2
 76:     LD  3,-3(1)	1 load variable 861 i
 77:     ST  3,-7(1)	1115 Push parameter 
* Param end dog
 78:    LDA  1,-4(1)	Ghost frame becomes new active frame 
 79:    LDA  3,1(7)	Return address in ac 
 80:    JMP  7,-27(7)	CALL OUTPUT dog
 81:    LDA  3,0(2)	Save the result in ac 
* CALL end dog
* TOFF: -4
 82:    LDA  2,0(3)	Copy result to ret register 
 83:     LD  3,-1(1)	Load return address 
 84:     LD  1,0(1)	Adjust fp 
 85:    JMP  7,0(3)	Return 
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
 86:    LDC  2,0(6)	Set return value to 0 
 87:     LD  3,-1(1)	Load return address 
 88:     LD  1,0(1)	Adjust fp 
 89:    JMP  7,0(3)	Return 
* END FUNCTION fox
* TOFF: -2
* FUNCTION main
 90:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -14
 91:    LDC  3,10(6)	load array size h
 92:     ST  3,-3(1)	save array size h
* ASSIGNMENT EXPRESSION
 93:    LDC  3,1(6)	Load Integer constant 
 94:     ST  3,-2(1)	Store variable i
* WHILE
* OP EXPRESSION
 95:     LD  3,-2(1)	2 Load variable 815 i
 96:     ST  3,-14(1)	Push the left side 677 
* TOFF: -15
 97:    LDC  3,10(6)	Load Integer constant 
* TOFF: -14
 98:     LD  4,-14(1)	Load Left into 1 <
 99:    TLT  3,4,3	Op < <
100:    JNZ  3,1(7)	Jump to while part 
* DO
* ASSIGNMENT EXPRESSION
102:     LD  3,-2(1)	2 Load variable 815 i
103:     ST  3,-14(1)	Push index 373 
* TOFF: -15
* ASSIGNMENT EXPRESSION
104:     LD  3,-2(1)	2 Load variable 815 i
105:     ST  3,-15(1)	Push index 373 
* TOFF: -16
* ASSIGNMENT EXPRESSION
106:     LD  3,-2(1)	2 Load variable 815 i
107:     ST  3,-16(1)	Push index 373 
* TOFF: -17
* ASSIGNMENT EXPRESSION
108:     LD  3,-2(1)	2 Load variable 815 i
109:    LDA  3,1(3)	increment value of i
110:     ST  3,-2(1)	Store variable i
* TOFF: -16
111:     LD  4,-16(1)	Pop index 
112:     LD  5,-12(1)	Load address of base of array 401 s
113:    SUB  5,5,4	Compute offset of value 
114:     ST  3,0(5)	Store variable s
* TOFF: -15
115:     LD  4,-15(1)	Pop index 
116:    LDA  5,-1(0)	Load address of base of array 383 g
117:    SUB  5,5,4	Compute offset of value 
118:     ST  3,0(5)	Store variable g
* TOFF: -14
119:     LD  4,-14(1)	Pop index 
120:     LD  5,-4(1)	Load address of base of array 401 h
121:    SUB  5,5,4	Compute offset of value 
122:     ST  3,0(5)	Store variable h
123:    JMP  7,-29(7)	go to the beginning of the loop 
101:    JMP  7,22(7)	Jump past loop [backpatch] 
* END WHILE
* CALL EXPRESSION
* CALL output
124:     ST  1,-14(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -15
* TOFF: -16
* OP EXPRESSION
* TOFF: -17
125:    LDC  3,6(6)	Load Integer constant 
* TOFF: -16
126:    LDA  5,-1(0)	1 Load address of base of array 620 g
127:    SUB  5,5,3	2 Compute location from index 
128:     LD  3,0(5)	2 Load array element 
129:     ST  3,-16(1)	Push parameter 1001 
* Param end output
130:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
131:    LDA  3,1(7)	Return address in ac 
132:    JMP  7,-127(7)	CALL OUTPUT output
133:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -14
* CALL EXPRESSION
* CALL output
134:     ST  1,-14(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -15
* TOFF: -16
* OP EXPRESSION
* TOFF: -17
135:    LDC  3,6(6)	Load Integer constant 
* TOFF: -16
136:    LDA  5,-4(1)	3 Load address of base of array 626 h
137:    SUB  5,5,3	2 Compute location from index 
138:     LD  3,0(5)	2 Load array element 
139:     ST  3,-16(1)	Push parameter 1001 
* Param end output
140:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
141:    LDA  3,1(7)	Return address in ac 
142:    JMP  7,-137(7)	CALL OUTPUT output
143:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -14
* CALL EXPRESSION
* CALL output
144:     ST  1,-14(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -15
* TOFF: -16
* OP EXPRESSION
* TOFF: -17
145:    LDC  3,6(6)	Load Integer constant 
* TOFF: -16
146:    LDA  5,-12(1)	3 Load address of base of array 626 s
147:    SUB  5,5,3	2 Compute location from index 
148:     LD  3,0(5)	2 Load array element 
149:     ST  3,-16(1)	Push parameter 1001 
* Param end output
150:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
151:    LDA  3,1(7)	Return address in ac 
152:    JMP  7,-147(7)	CALL OUTPUT output
153:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -14
* CALL EXPRESSION
* CALL outnl
154:     ST  1,-14(1)	3 Store fp in ghost frame for outnl
* Param end outnl
155:    LDA  1,-14(1)	Ghost frame becomes new active frame 
156:    LDA  3,1(7)	Return address in ac 
157:    JMP  7,-124(7)	CALL OUTPUT outnl
158:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -14
* CALL EXPRESSION
* CALL output
159:     ST  1,-14(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -15
* TOFF: -16
* CALL EXPRESSION
* CALL cat
* TOFF: -16
160:     ST  1,-16(1)	2 Store fp in ghost frame for cat
* TOFF: -17
* TOFF: -18
* 1071 Param 1
161:    LDA  3,-1(0)	Load address of base of array 1025 g
162:     ST  3,-18(1)	1101 Push parameter 
* TOFF: -19
* 1071 Param 2
163:     ST  3,-19(1)	3 Push parameter 
* Param end cat
164:    LDA  1,-16(1)	Ghost frame becomes new active frame 
165:    LDA  3,1(7)	Return address in ac 
166:    JMP  7,-128(7)	CALL OUTPUT cat
167:    LDA  3,0(2)	Save the result in ac 
* CALL end cat
* TOFF: -16
168:     ST  3,-16(1)	Push parameter 1001 
* Param end output
169:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
170:    LDA  3,1(7)	Return address in ac 
171:    JMP  7,-166(7)	CALL OUTPUT output
172:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -14
* CALL EXPRESSION
* CALL output
173:     ST  1,-14(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -15
* TOFF: -16
* CALL EXPRESSION
* CALL cat
* TOFF: -16
174:     ST  1,-16(1)	2 Store fp in ghost frame for cat
* TOFF: -17
* TOFF: -18
* 1071 Param 1
175:    LDA  3,-4(1)	Load address of base of array 1123 h
176:     ST  3,-18(1)	1101 Push parameter 
* TOFF: -19
* 1071 Param 2
177:    LDC  3,6(6)	Load integer constant 
178:     ST  3,-19(1)	3 Push parameter 
* Param end cat
179:    LDA  1,-16(1)	Ghost frame becomes new active frame 
180:    LDA  3,1(7)	Return address in ac 
181:    JMP  7,-143(7)	CALL OUTPUT cat
182:    LDA  3,0(2)	Save the result in ac 
* CALL end cat
* TOFF: -16
183:     ST  3,-16(1)	Push parameter 1001 
* Param end output
184:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
185:    LDA  3,1(7)	Return address in ac 
186:    JMP  7,-181(7)	CALL OUTPUT output
187:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -14
* CALL EXPRESSION
* CALL output
188:     ST  1,-14(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -15
* TOFF: -16
* CALL EXPRESSION
* CALL cat
* TOFF: -16
189:     ST  1,-16(1)	2 Store fp in ghost frame for cat
* TOFF: -17
* TOFF: -18
* 1071 Param 1
190:    LDA  3,-12(1)	Load address of base of array 1123 s
191:     ST  3,-18(1)	1101 Push parameter 
* TOFF: -19
* 1071 Param 2
192:    LDC  3,6(6)	Load integer constant 
193:     ST  3,-19(1)	3 Push parameter 
* Param end cat
194:    LDA  1,-16(1)	Ghost frame becomes new active frame 
195:    LDA  3,1(7)	Return address in ac 
196:    JMP  7,-158(7)	CALL OUTPUT cat
197:    LDA  3,0(2)	Save the result in ac 
* CALL end cat
* TOFF: -16
198:     ST  3,-16(1)	Push parameter 1001 
* Param end output
199:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
200:    LDA  3,1(7)	Return address in ac 
201:    JMP  7,-196(7)	CALL OUTPUT output
202:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -14
* CALL EXPRESSION
* CALL outnl
203:     ST  1,-14(1)	3 Store fp in ghost frame for outnl
* Param end outnl
204:    LDA  1,-14(1)	Ghost frame becomes new active frame 
205:    LDA  3,1(7)	Return address in ac 
206:    JMP  7,-173(7)	CALL OUTPUT outnl
207:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -14
* CALL EXPRESSION
* CALL output
208:     ST  1,-14(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -15
* TOFF: -16
* CALL EXPRESSION
* CALL dog
* TOFF: -16
209:     ST  1,-16(1)	2 Store fp in ghost frame for dog
* TOFF: -17
* TOFF: -18
* 1071 Param 1
210:    LDA  3,-1(0)	Load address of base of array 1025 g
211:     ST  3,-18(1)	1101 Push parameter 
* TOFF: -19
* 1071 Param 2
212:     ST  3,-19(1)	3 Push parameter 
* Param end dog
213:    LDA  1,-16(1)	Ghost frame becomes new active frame 
214:    LDA  3,1(7)	Return address in ac 
215:    JMP  7,-162(7)	CALL OUTPUT dog
216:    LDA  3,0(2)	Save the result in ac 
* CALL end dog
* TOFF: -16
217:     ST  3,-16(1)	Push parameter 1001 
* Param end output
218:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
219:    LDA  3,1(7)	Return address in ac 
220:    JMP  7,-215(7)	CALL OUTPUT output
221:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -14
* CALL EXPRESSION
* CALL output
222:     ST  1,-14(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -15
* TOFF: -16
* CALL EXPRESSION
* CALL dog
* TOFF: -16
223:     ST  1,-16(1)	2 Store fp in ghost frame for dog
* TOFF: -17
* TOFF: -18
* 1071 Param 1
224:    LDA  3,-4(1)	Load address of base of array 1123 h
225:     ST  3,-18(1)	1101 Push parameter 
* TOFF: -19
* 1071 Param 2
226:    LDC  3,6(6)	Load integer constant 
227:     ST  3,-19(1)	3 Push parameter 
* Param end dog
228:    LDA  1,-16(1)	Ghost frame becomes new active frame 
229:    LDA  3,1(7)	Return address in ac 
230:    JMP  7,-177(7)	CALL OUTPUT dog
231:    LDA  3,0(2)	Save the result in ac 
* CALL end dog
* TOFF: -16
232:     ST  3,-16(1)	Push parameter 1001 
* Param end output
233:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
234:    LDA  3,1(7)	Return address in ac 
235:    JMP  7,-230(7)	CALL OUTPUT output
236:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -14
* CALL EXPRESSION
* CALL output
237:     ST  1,-14(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -15
* TOFF: -16
* CALL EXPRESSION
* CALL dog
* TOFF: -16
238:     ST  1,-16(1)	2 Store fp in ghost frame for dog
* TOFF: -17
* TOFF: -18
* 1071 Param 1
239:    LDA  3,-12(1)	Load address of base of array 1123 s
240:     ST  3,-18(1)	1101 Push parameter 
* TOFF: -19
* 1071 Param 2
241:    LDC  3,6(6)	Load integer constant 
242:     ST  3,-19(1)	3 Push parameter 
* Param end dog
243:    LDA  1,-16(1)	Ghost frame becomes new active frame 
244:    LDA  3,1(7)	Return address in ac 
245:    JMP  7,-192(7)	CALL OUTPUT dog
246:    LDA  3,0(2)	Save the result in ac 
* CALL end dog
* TOFF: -16
247:     ST  3,-16(1)	Push parameter 1001 
* Param end output
248:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
249:    LDA  3,1(7)	Return address in ac 
250:    JMP  7,-245(7)	CALL OUTPUT output
251:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -14
* CALL EXPRESSION
* CALL outnl
252:     ST  1,-14(1)	3 Store fp in ghost frame for outnl
* Param end outnl
253:    LDA  1,-14(1)	Ghost frame becomes new active frame 
254:    LDA  3,1(7)	Return address in ac 
255:    JMP  7,-222(7)	CALL OUTPUT outnl
256:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -14
* CALL EXPRESSION
* CALL output
257:     ST  1,-14(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -15
* TOFF: -16
* CALL EXPRESSION
* CALL fox
* TOFF: -16
258:     ST  1,-16(1)	2 Store fp in ghost frame for fox
* TOFF: -17
* TOFF: -18
* 1071 Param 1
259:    LDA  3,-1(0)	Load address of base of array 1025 g
260:     ST  3,-18(1)	1101 Push parameter 
* TOFF: -19
* 1071 Param 2
261:     ST  3,-19(1)	3 Push parameter 
* Param end fox
262:    LDA  1,-16(1)	Ghost frame becomes new active frame 
263:    LDA  3,1(7)	Return address in ac 
264:    JMP  7,-193(7)	CALL OUTPUT fox
265:    LDA  3,0(2)	Save the result in ac 
* CALL end fox
* TOFF: -16
266:     ST  3,-16(1)	Push parameter 1001 
* Param end output
267:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
268:    LDA  3,1(7)	Return address in ac 
269:    JMP  7,-264(7)	CALL OUTPUT output
270:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -14
* CALL EXPRESSION
* CALL output
271:     ST  1,-14(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -15
* TOFF: -16
* CALL EXPRESSION
* CALL fox
* TOFF: -16
272:     ST  1,-16(1)	2 Store fp in ghost frame for fox
* TOFF: -17
* TOFF: -18
* 1071 Param 1
273:    LDA  3,-4(1)	Load address of base of array 1123 h
274:     ST  3,-18(1)	1101 Push parameter 
* TOFF: -19
* 1071 Param 2
275:    LDC  3,6(6)	Load integer constant 
276:     ST  3,-19(1)	3 Push parameter 
* Param end fox
277:    LDA  1,-16(1)	Ghost frame becomes new active frame 
278:    LDA  3,1(7)	Return address in ac 
279:    JMP  7,-208(7)	CALL OUTPUT fox
280:    LDA  3,0(2)	Save the result in ac 
* CALL end fox
* TOFF: -16
281:     ST  3,-16(1)	Push parameter 1001 
* Param end output
282:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
283:    LDA  3,1(7)	Return address in ac 
284:    JMP  7,-279(7)	CALL OUTPUT output
285:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -14
* CALL EXPRESSION
* CALL output
286:     ST  1,-14(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -15
* TOFF: -16
* CALL EXPRESSION
* CALL fox
* TOFF: -16
287:     ST  1,-16(1)	2 Store fp in ghost frame for fox
* TOFF: -17
* TOFF: -18
* 1071 Param 1
288:    LDA  3,-12(1)	Load address of base of array 1123 s
289:     ST  3,-18(1)	1101 Push parameter 
* TOFF: -19
* 1071 Param 2
290:    LDC  3,6(6)	Load integer constant 
291:     ST  3,-19(1)	3 Push parameter 
* Param end fox
292:    LDA  1,-16(1)	Ghost frame becomes new active frame 
293:    LDA  3,1(7)	Return address in ac 
294:    JMP  7,-223(7)	CALL OUTPUT fox
295:    LDA  3,0(2)	Save the result in ac 
* CALL end fox
* TOFF: -16
296:     ST  3,-16(1)	Push parameter 1001 
* Param end output
297:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
298:    LDA  3,1(7)	Return address in ac 
299:    JMP  7,-294(7)	CALL OUTPUT output
300:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -14
* CALL EXPRESSION
* CALL outnl
301:     ST  1,-14(1)	3 Store fp in ghost frame for outnl
* Param end outnl
302:    LDA  1,-14(1)	Ghost frame becomes new active frame 
303:    LDA  3,1(7)	Return address in ac 
304:    JMP  7,-271(7)	CALL OUTPUT outnl
305:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -14
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
306:    LDC  2,0(6)	Set return value to 0 
307:     LD  3,-1(1)	Load return address 
308:     LD  1,0(1)	Adjust fp 
309:    JMP  7,0(3)	Return 
* END FUNCTION main
* TOFF: -2
  0:    JMP  7,309(7)	Jump to init [backpatch] 
* INIT
310:    LDA  1,-22(0)	set first frame at end of globals 
311:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
312:    LDC  3,10(6)	load size of array g
313:     ST  3,0(0)	save size of array g
* END INIT GLOBALS AND STATICS
314:    LDA  3,1(7)	Return address in ac 
315:    JMP  7,-226(7)	Jump to main 
316:   HALT  0,0,0	DONE! 
* END INIT
