* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/h08.tm
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
* FUNCTION fib
 39:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -4
* CALL EXPRESSION
* CALL output
 40:     ST  1,-4(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -5
* TOFF: -6
 41:     LD  3,-2(1)	1 load variable 861 x
 42:     ST  3,-6(1)	Push parameter 
* Param end output
 43:    LDA  1,-4(1)	1 Ghost frame becomes new active frame 
 44:    LDA  3,1(7)	Return address in ac 
 45:    JMP  7,-40(7)	CALL OUTPUT output
 46:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -4
* CALL EXPRESSION
* CALL outnl
 47:     ST  1,-4(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 48:    LDA  1,-4(1)	Ghost frame becomes new active frame 
 49:    LDA  3,1(7)	Return address in ac 
 50:    JMP  7,-17(7)	CALL OUTPUT outnl
 51:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -4
* IF
* OP EXPRESSION
 52:     LD  3,-2(1)	1 load variable 861 x
 53:     ST  3,-4(1)	Push the left side 677 
* TOFF: -5
 54:    LDC  3,2(6)	Load Integer constant 
* TOFF: -4
 55:     LD  4,-4(1)	Load Left into 1 <
 56:    TLT  3,4,3	Op < <
* THEN
* COMPOUND
* TOFF:  -4
* ASSIGNMENT EXPRESSION
 58:    LDC  3,0(6)	Load Integer constant 
 59:     ST  3,-4(1)	Push index 373 
* TOFF: -5
* ASSIGNMENT EXPRESSION
 60:    LDC  3,1(6)	Load Integer constant 
 61:     ST  3,-5(1)	Push index 373 
* TOFF: -6
 62:    LDC  3,1(6)	Load Integer constant 
* TOFF: -5
 63:     LD  4,-5(1)	Pop index 
 64:    LDA  5,-3(1)	Load address of base of array 390 f
 65:    SUB  5,5,4	Compute offset of value 
 66:     ST  3,0(5)	Store variable f
* TOFF: -4
 67:     LD  4,-4(1)	Pop index 
 68:     LD  5,-3(1)	Load address of base of array 387 f
 69:    SUB  5,5,4	Compute offset of value 
 70:     ST  3,0(5)	Store variable f
* RETURN
* OP EXPRESSION
 71:     LD  3,-3(1)	2 Load address of base of array 583 f
 72:     ST  3,-4(1)	Push left side 
* TOFF: -5
 73:     LD  3,-2(1)	1 load variable 861 x
* TOFF: -4
 74:     LD  4,-4(1)	1 Pop left into ac1 
 75:    SUB  3,4,3	1 Compute location from index 
 76:     LD  3,0(3)	1 Load array element 
 77:    LDA  2,0(3)	Copy result to ret register 
 78:     LD  3,-1(1)	Load return address 
 79:     LD  1,0(1)	Adjust fp 
 80:    JMP  7,0(3)	Return 
* Compound Body
* TOFF:  -4
* END COMPOUND
 57:    JZR  3,23(7)	Jump around the THEN if false [backpatch] 
* END IF
* CALL EXPRESSION
* CALL fib
* TOFF: -4
 81:     ST  1,-4(1)	2 Store fp in ghost frame for fib
* TOFF: -5
* TOFF: -6
* 1071 Param 1
* OP EXPRESSION
 82:     LD  3,-2(1)	1 load variable 861 x
 83:     ST  3,-6(1)	Push the left side 677 
* TOFF: -7
 84:    LDC  3,1(6)	Load Integer constant 
* TOFF: -6
 85:     LD  4,-6(1)	Load Left into 1 -
 86:    SUB  3,4,3	Op - -
 87:     ST  3,-6(1)	1115 Push parameter 
* TOFF: -7
* 1071 Param 2
 88:    LDA  3,-3(1)	Load address of base of array 1037 f
 89:     ST  3,-7(1)	1101 Push parameter 
* Param end fib
 90:    LDA  1,-4(1)	Ghost frame becomes new active frame 
 91:    LDA  3,1(7)	Return address in ac 
 92:    JMP  7,-54(7)	CALL OUTPUT fib
 93:    LDA  3,0(2)	Save the result in ac 
* CALL end fib
* TOFF: -4
* ASSIGNMENT EXPRESSION
 94:     LD  3,-2(1)	1 load variable 861 x
 95:     ST  3,-4(1)	Push index 373 
* TOFF: -5
* OP EXPRESSION
* OP EXPRESSION
 96:     LD  3,-3(1)	2 Load address of base of array 583 f
 97:     ST  3,-5(1)	Push left side 
* TOFF: -6
* OP EXPRESSION
 98:     LD  3,-2(1)	1 load variable 861 x
 99:     ST  3,-6(1)	Push the left side 677 
* TOFF: -7
100:    LDC  3,1(6)	Load Integer constant 
* TOFF: -6
101:     LD  4,-6(1)	Load Left into 1 -
102:    SUB  3,4,3	Op - -
* TOFF: -5
103:     LD  4,-5(1)	1 Pop left into ac1 
104:    SUB  3,4,3	1 Compute location from index 
105:     LD  3,0(3)	1 Load array element 
106:     ST  3,-5(1)	Push the left side 677 
* TOFF: -6
* OP EXPRESSION
107:     LD  3,-3(1)	2 Load address of base of array 583 f
108:     ST  3,-6(1)	Push left side 
* TOFF: -7
* OP EXPRESSION
109:     LD  3,-2(1)	1 load variable 861 x
110:     ST  3,-7(1)	Push the left side 677 
* TOFF: -8
111:    LDC  3,2(6)	Load Integer constant 
* TOFF: -7
112:     LD  4,-7(1)	Load Left into 1 -
113:    SUB  3,4,3	Op - -
* TOFF: -6
114:     LD  4,-6(1)	1 Pop left into ac1 
115:    SUB  3,4,3	1 Compute location from index 
116:     LD  3,0(3)	1 Load array element 
* TOFF: -5
117:     LD  4,-5(1)	Load Left into 1 +
118:    ADD  3,4,3	Op + +
* TOFF: -4
119:     LD  4,-4(1)	Pop index 
120:     LD  5,-3(1)	Load address of base of array 387 f
121:    SUB  5,5,4	Compute offset of value 
122:     ST  3,0(5)	Store variable f
* RETURN
* OP EXPRESSION
123:     LD  3,-3(1)	2 Load address of base of array 583 f
124:     ST  3,-4(1)	Push left side 
* TOFF: -5
125:     LD  3,-2(1)	1 load variable 861 x
* TOFF: -4
126:     LD  4,-4(1)	1 Pop left into ac1 
127:    SUB  3,4,3	1 Compute location from index 
128:     LD  3,0(3)	1 Load array element 
129:    LDA  2,0(3)	Copy result to ret register 
130:     LD  3,-1(1)	Load return address 
131:     LD  1,0(1)	Adjust fp 
132:    JMP  7,0(3)	Return 
* Compound Body
* TOFF:  -4
* END COMPOUND
* Add standard closing in case there is no return statement
133:    LDC  2,0(6)	Set return value to 0 
134:     LD  3,-1(1)	Load return address 
135:     LD  1,0(1)	Adjust fp 
136:    JMP  7,0(3)	Return 
* END FUNCTION fib
* TOFF: -2
* FUNCTION main
137:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -10
138:    LDC  3,7(6)	load array size f
139:     ST  3,-2(1)	save array size f
* ASSIGNMENT EXPRESSION
140:    LDC  3,0(6)	Load Integer constant 
141:     ST  3,-10(1)	Push index 373 
* TOFF: -11
142:    LDC  3,0(6)	Load Integer constant 
* TOFF: -10
143:     LD  4,-10(1)	Pop index 
144:    LDA  5,-3(1)	Load address of base of array 390 f
145:    SUB  5,5,4	Compute offset of value 
146:     ST  3,0(5)	Store variable f
* ASSIGNMENT EXPRESSION
147:    LDC  3,1(6)	Load Integer constant 
148:     ST  3,-10(1)	Push index 373 
* TOFF: -11
149:    LDC  3,0(6)	Load Integer constant 
* TOFF: -10
150:     LD  4,-10(1)	Pop index 
151:    LDA  5,-3(1)	Load address of base of array 390 f
152:    SUB  5,5,4	Compute offset of value 
153:     ST  3,0(5)	Store variable f
* ASSIGNMENT EXPRESSION
154:    LDC  3,2(6)	Load Integer constant 
155:     ST  3,-10(1)	Push index 373 
* TOFF: -11
156:    LDC  3,0(6)	Load Integer constant 
* TOFF: -10
157:     LD  4,-10(1)	Pop index 
158:    LDA  5,-3(1)	Load address of base of array 390 f
159:    SUB  5,5,4	Compute offset of value 
160:     ST  3,0(5)	Store variable f
* ASSIGNMENT EXPRESSION
161:    LDC  3,3(6)	Load Integer constant 
162:     ST  3,-10(1)	Push index 373 
* TOFF: -11
163:    LDC  3,0(6)	Load Integer constant 
* TOFF: -10
164:     LD  4,-10(1)	Pop index 
165:    LDA  5,-3(1)	Load address of base of array 390 f
166:    SUB  5,5,4	Compute offset of value 
167:     ST  3,0(5)	Store variable f
* ASSIGNMENT EXPRESSION
168:    LDC  3,4(6)	Load Integer constant 
169:     ST  3,-10(1)	Push index 373 
* TOFF: -11
170:    LDC  3,0(6)	Load Integer constant 
* TOFF: -10
171:     LD  4,-10(1)	Pop index 
172:    LDA  5,-3(1)	Load address of base of array 390 f
173:    SUB  5,5,4	Compute offset of value 
174:     ST  3,0(5)	Store variable f
* ASSIGNMENT EXPRESSION
175:    LDC  3,5(6)	Load Integer constant 
176:     ST  3,-10(1)	Push index 373 
* TOFF: -11
177:    LDC  3,0(6)	Load Integer constant 
* TOFF: -10
178:     LD  4,-10(1)	Pop index 
179:    LDA  5,-3(1)	Load address of base of array 390 f
180:    SUB  5,5,4	Compute offset of value 
181:     ST  3,0(5)	Store variable f
* ASSIGNMENT EXPRESSION
182:    LDC  3,6(6)	Load Integer constant 
183:     ST  3,-10(1)	Push index 373 
* TOFF: -11
184:    LDC  3,0(6)	Load Integer constant 
* TOFF: -10
185:     LD  4,-10(1)	Pop index 
186:    LDA  5,-3(1)	Load address of base of array 390 f
187:    SUB  5,5,4	Compute offset of value 
188:     ST  3,0(5)	Store variable f
* CALL EXPRESSION
* CALL fib
* TOFF: -10
189:     ST  1,-10(1)	2 Store fp in ghost frame for fib
* TOFF: -11
* TOFF: -12
* 1071 Param 1
190:    LDC  3,5(6)	Load integer constant 
191:     ST  3,-12(1)	3 Push parameter 
* TOFF: -13
* 1071 Param 2
192:    LDA  3,-3(1)	Load address of base of array 1037 f
193:     ST  3,-13(1)	1101 Push parameter 
* Param end fib
194:    LDA  1,-10(1)	Ghost frame becomes new active frame 
195:    LDA  3,1(7)	Return address in ac 
196:    JMP  7,-158(7)	CALL OUTPUT fib
197:    LDA  3,0(2)	Save the result in ac 
* CALL end fib
* TOFF: -10
* CALL EXPRESSION
* CALL output
198:     ST  1,-10(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -11
* TOFF: -12
* OP EXPRESSION
199:    LDA  3,-3(1)	2 Load address of base of array 587 f
200:     ST  3,-12(1)	Push left side 
* TOFF: -13
201:    LDC  3,0(6)	Load Integer constant 
* TOFF: -12
202:     LD  4,-12(1)	1 Pop left into ac1 
203:    SUB  3,4,3	1 Compute location from index 
204:     LD  3,0(3)	1 Load array element 
205:     ST  3,-12(1)	Push parameter 
* Param end output
206:    LDA  1,-10(1)	1 Ghost frame becomes new active frame 
207:    LDA  3,1(7)	Return address in ac 
208:    JMP  7,-203(7)	CALL OUTPUT output
209:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -10
* CALL EXPRESSION
* CALL output
210:     ST  1,-10(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -11
* TOFF: -12
* OP EXPRESSION
211:    LDA  3,-3(1)	2 Load address of base of array 587 f
212:     ST  3,-12(1)	Push left side 
* TOFF: -13
213:    LDC  3,1(6)	Load Integer constant 
* TOFF: -12
214:     LD  4,-12(1)	1 Pop left into ac1 
215:    SUB  3,4,3	1 Compute location from index 
216:     LD  3,0(3)	1 Load array element 
217:     ST  3,-12(1)	Push parameter 
* Param end output
218:    LDA  1,-10(1)	1 Ghost frame becomes new active frame 
219:    LDA  3,1(7)	Return address in ac 
220:    JMP  7,-215(7)	CALL OUTPUT output
221:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -10
* CALL EXPRESSION
* CALL output
222:     ST  1,-10(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -11
* TOFF: -12
* OP EXPRESSION
223:    LDA  3,-3(1)	2 Load address of base of array 587 f
224:     ST  3,-12(1)	Push left side 
* TOFF: -13
225:    LDC  3,2(6)	Load Integer constant 
* TOFF: -12
226:     LD  4,-12(1)	1 Pop left into ac1 
227:    SUB  3,4,3	1 Compute location from index 
228:     LD  3,0(3)	1 Load array element 
229:     ST  3,-12(1)	Push parameter 
* Param end output
230:    LDA  1,-10(1)	1 Ghost frame becomes new active frame 
231:    LDA  3,1(7)	Return address in ac 
232:    JMP  7,-227(7)	CALL OUTPUT output
233:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -10
* CALL EXPRESSION
* CALL output
234:     ST  1,-10(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -11
* TOFF: -12
* OP EXPRESSION
235:    LDA  3,-3(1)	2 Load address of base of array 587 f
236:     ST  3,-12(1)	Push left side 
* TOFF: -13
237:    LDC  3,3(6)	Load Integer constant 
* TOFF: -12
238:     LD  4,-12(1)	1 Pop left into ac1 
239:    SUB  3,4,3	1 Compute location from index 
240:     LD  3,0(3)	1 Load array element 
241:     ST  3,-12(1)	Push parameter 
* Param end output
242:    LDA  1,-10(1)	1 Ghost frame becomes new active frame 
243:    LDA  3,1(7)	Return address in ac 
244:    JMP  7,-239(7)	CALL OUTPUT output
245:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -10
* CALL EXPRESSION
* CALL output
246:     ST  1,-10(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -11
* TOFF: -12
* OP EXPRESSION
247:    LDA  3,-3(1)	2 Load address of base of array 587 f
248:     ST  3,-12(1)	Push left side 
* TOFF: -13
249:    LDC  3,4(6)	Load Integer constant 
* TOFF: -12
250:     LD  4,-12(1)	1 Pop left into ac1 
251:    SUB  3,4,3	1 Compute location from index 
252:     LD  3,0(3)	1 Load array element 
253:     ST  3,-12(1)	Push parameter 
* Param end output
254:    LDA  1,-10(1)	1 Ghost frame becomes new active frame 
255:    LDA  3,1(7)	Return address in ac 
256:    JMP  7,-251(7)	CALL OUTPUT output
257:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -10
* CALL EXPRESSION
* CALL output
258:     ST  1,-10(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -11
* TOFF: -12
* OP EXPRESSION
259:    LDA  3,-3(1)	2 Load address of base of array 587 f
260:     ST  3,-12(1)	Push left side 
* TOFF: -13
261:    LDC  3,5(6)	Load Integer constant 
* TOFF: -12
262:     LD  4,-12(1)	1 Pop left into ac1 
263:    SUB  3,4,3	1 Compute location from index 
264:     LD  3,0(3)	1 Load array element 
265:     ST  3,-12(1)	Push parameter 
* Param end output
266:    LDA  1,-10(1)	1 Ghost frame becomes new active frame 
267:    LDA  3,1(7)	Return address in ac 
268:    JMP  7,-263(7)	CALL OUTPUT output
269:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -10
* CALL EXPRESSION
* CALL output
270:     ST  1,-10(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -11
* TOFF: -12
* OP EXPRESSION
271:    LDA  3,-3(1)	2 Load address of base of array 587 f
272:     ST  3,-12(1)	Push left side 
* TOFF: -13
273:    LDC  3,6(6)	Load Integer constant 
* TOFF: -12
274:     LD  4,-12(1)	1 Pop left into ac1 
275:    SUB  3,4,3	1 Compute location from index 
276:     LD  3,0(3)	1 Load array element 
277:     ST  3,-12(1)	Push parameter 
* Param end output
278:    LDA  1,-10(1)	1 Ghost frame becomes new active frame 
279:    LDA  3,1(7)	Return address in ac 
280:    JMP  7,-275(7)	CALL OUTPUT output
281:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* TOFF: -10
* CALL EXPRESSION
* CALL outnl
282:     ST  1,-10(1)	3 Store fp in ghost frame for outnl
* Param end outnl
283:    LDA  1,-10(1)	Ghost frame becomes new active frame 
284:    LDA  3,1(7)	Return address in ac 
285:    JMP  7,-252(7)	CALL OUTPUT outnl
286:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -10
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
287:    LDC  2,0(6)	Set return value to 0 
288:     LD  3,-1(1)	Load return address 
289:     LD  1,0(1)	Adjust fp 
290:    JMP  7,0(3)	Return 
* END FUNCTION main
* TOFF: -2
  0:    JMP  7,290(7)	Jump to init [backpatch] 
* INIT
291:    LDA  1,0(0)	set first frame at end of globals 
292:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
293:    LDA  3,1(7)	Return address in ac 
294:    JMP  7,-158(7)	Jump to main 
295:   HALT  0,0,0	DONE! 
* END INIT
