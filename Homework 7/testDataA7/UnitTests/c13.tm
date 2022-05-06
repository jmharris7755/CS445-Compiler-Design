* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/c13.tm
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
* FUNCTION main
 39:     ST  3,-1(1)	Store return address 
* COMPOUND
* TOFF:  -304
 40:    LDC  3,300(6)	load array size x
 41:     ST  3,-2(1)	save array size x
* ASSIGNMENT EXPRESSION
 42:    LDC  3,5(6)	Load Integer constant 
 43:     ST  3,-303(1)	Store variable z
* ASSIGNMENT EXPRESSION
 44:     LD  3,-303(1)	2 Load variable z
 45:     ST  3,-304(1)	Push index 
 46:    LDC  3,73(6)	Load Integer constant 
 47:     LD  4,-304(1)	Pop index 
 48:    LDA  5,-3(1)	Load address of base of array x
 49:    SUB  5,5,4	Compute offset of value 
 50:     ST  3,0(5)	Store variable x
* CALL EXPRESSION
* CALL output
 51:     ST  1,-304(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -306
* OP EXPRESSION
 52:     LD  3,-303(1)	2 Load variable z
 53:    LDA  5,-3(1)	3 Load address of base of array 543 x
 54:    SUB  5,5,3	Compute location from index 
 55:     LD  3,0(5)	Load array element 
 56:     ST  3,-306(1)	Push parameter 
* Param end output
 57:    LDA  1,-304(1)	1 Ghost frame becomes new active frame 
 58:    LDA  3,1(7)	Return address in ac 
 59:    JMP  7,-54(7)	CALL OUTPUT output
 60:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
 61:     ST  1,-304(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 62:    LDA  1,-304(1)	Ghost frame becomes new active frame 
 63:    LDA  3,1(7)	Return address in ac 
 64:    JMP  7,-31(7)	CALL OUTPUT outnl
 65:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* ASSIGNMENT EXPRESSION
 66:    LDC  3,5(6)	Load Integer constant 
 67:     ST  3,-303(1)	Store variable z
* ASSIGNMENT EXPRESSION
 68:     LD  3,-303(1)	2 Load variable z
 69:     ST  3,-304(1)	Push index 
 70:    LDC  3,17(6)	Load Integer constant 
 71:     LD  4,-304(1)	Pop index 
 72:    LDA  5,-3(1)	Load address of base of array x
 73:    SUB  5,5,4	Compute offset of value 
 74:     ST  3,0(5)	Store variable x
* ASSIGNMENT EXPRESSION
 75:    LDC  3,17(6)	Load Integer constant 
 76:     ST  3,-303(1)	Store variable z
* ASSIGNMENT EXPRESSION
 77:     LD  3,-303(1)	2 Load variable z
 78:     ST  3,-304(1)	Push index 
 79:    LDC  3,5(6)	Load Integer constant 
 80:     LD  4,-304(1)	Pop index 
 81:    LDA  5,-3(1)	Load address of base of array x
 82:    SUB  5,5,4	Compute offset of value 
 83:     ST  3,0(5)	Store variable x
* CALL EXPRESSION
* CALL output
 84:     ST  1,-304(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -306
* OP EXPRESSION
 85:     LD  3,-303(1)	2 Load variable z
 86:    LDA  5,-3(1)	3 Load address of base of array 543 x
 87:    SUB  5,5,3	Compute location from index 
 88:     LD  3,0(5)	Load array element 
 89:     ST  3,-306(1)	Push parameter 
* Param end output
 90:    LDA  1,-304(1)	1 Ghost frame becomes new active frame 
 91:    LDA  3,1(7)	Return address in ac 
 92:    JMP  7,-87(7)	CALL OUTPUT output
 93:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
 94:     ST  1,-304(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 95:    LDA  1,-304(1)	Ghost frame becomes new active frame 
 96:    LDA  3,1(7)	Return address in ac 
 97:    JMP  7,-64(7)	CALL OUTPUT outnl
 98:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* CALL EXPRESSION
* CALL output
 99:     ST  1,-304(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -306
* OP EXPRESSION
* OP EXPRESSION
100:     LD  3,-303(1)	2 Load variable z
101:    LDA  5,-3(1)	3 Load address of base of array 543 x
102:    SUB  5,5,3	Compute location from index 
103:     LD  3,0(5)	Load array element 
104:    LDA  5,-3(1)	3 Load address of base of array 543 x
105:    SUB  5,5,3	Compute location from index 
106:     LD  3,0(5)	Load array element 
107:     ST  3,-306(1)	Push parameter 
* Param end output
108:    LDA  1,-304(1)	1 Ghost frame becomes new active frame 
109:    LDA  3,1(7)	Return address in ac 
110:    JMP  7,-105(7)	CALL OUTPUT output
111:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
112:     ST  1,-304(1)	3 Store fp in ghost frame for outnl
* Param end outnl
113:    LDA  1,-304(1)	Ghost frame becomes new active frame 
114:    LDA  3,1(7)	Return address in ac 
115:    JMP  7,-82(7)	CALL OUTPUT outnl
116:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* CALL EXPRESSION
* CALL output
117:     ST  1,-304(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -306
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
118:     LD  3,-303(1)	2 Load variable z
119:    LDA  5,-3(1)	3 Load address of base of array 543 x
120:    SUB  5,5,3	Compute location from index 
121:     LD  3,0(5)	Load array element 
122:    LDA  5,-3(1)	3 Load address of base of array 543 x
123:    SUB  5,5,3	Compute location from index 
124:     LD  3,0(5)	Load array element 
125:    LDA  5,-3(1)	3 Load address of base of array 543 x
126:    SUB  5,5,3	Compute location from index 
127:     LD  3,0(5)	Load array element 
128:     ST  3,-306(1)	Push parameter 
* Param end output
129:    LDA  1,-304(1)	1 Ghost frame becomes new active frame 
130:    LDA  3,1(7)	Return address in ac 
131:    JMP  7,-126(7)	CALL OUTPUT output
132:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
133:     ST  1,-304(1)	3 Store fp in ghost frame for outnl
* Param end outnl
134:    LDA  1,-304(1)	Ghost frame becomes new active frame 
135:    LDA  3,1(7)	Return address in ac 
136:    JMP  7,-103(7)	CALL OUTPUT outnl
137:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* CALL EXPRESSION
* CALL output
138:     ST  1,-304(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -306
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
139:     LD  3,-303(1)	2 Load variable z
140:    LDA  5,-3(1)	3 Load address of base of array 543 x
141:    SUB  5,5,3	Compute location from index 
142:     LD  3,0(5)	Load array element 
143:    LDA  5,-3(1)	3 Load address of base of array 543 x
144:    SUB  5,5,3	Compute location from index 
145:     LD  3,0(5)	Load array element 
146:    LDA  5,-3(1)	3 Load address of base of array 543 x
147:    SUB  5,5,3	Compute location from index 
148:     LD  3,0(5)	Load array element 
149:    LDA  5,-3(1)	3 Load address of base of array 543 x
150:    SUB  5,5,3	Compute location from index 
151:     LD  3,0(5)	Load array element 
152:     ST  3,-306(1)	Push parameter 
* Param end output
153:    LDA  1,-304(1)	1 Ghost frame becomes new active frame 
154:    LDA  3,1(7)	Return address in ac 
155:    JMP  7,-150(7)	CALL OUTPUT output
156:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
157:     ST  1,-304(1)	3 Store fp in ghost frame for outnl
* Param end outnl
158:    LDA  1,-304(1)	Ghost frame becomes new active frame 
159:    LDA  3,1(7)	Return address in ac 
160:    JMP  7,-127(7)	CALL OUTPUT outnl
161:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* CALL EXPRESSION
* CALL output
162:     ST  1,-304(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -306
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
163:     LD  3,-303(1)	2 Load variable z
164:    LDA  5,-3(1)	3 Load address of base of array 543 x
165:    SUB  5,5,3	Compute location from index 
166:     LD  3,0(5)	Load array element 
167:    LDA  5,-3(1)	3 Load address of base of array 543 x
168:    SUB  5,5,3	Compute location from index 
169:     LD  3,0(5)	Load array element 
170:    LDA  5,-3(1)	3 Load address of base of array 543 x
171:    SUB  5,5,3	Compute location from index 
172:     LD  3,0(5)	Load array element 
173:    LDA  5,-3(1)	3 Load address of base of array 543 x
174:    SUB  5,5,3	Compute location from index 
175:     LD  3,0(5)	Load array element 
176:    LDA  5,-3(1)	3 Load address of base of array 543 x
177:    SUB  5,5,3	Compute location from index 
178:     LD  3,0(5)	Load array element 
179:     ST  3,-306(1)	Push parameter 
* Param end output
180:    LDA  1,-304(1)	1 Ghost frame becomes new active frame 
181:    LDA  3,1(7)	Return address in ac 
182:    JMP  7,-177(7)	CALL OUTPUT output
183:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
184:     ST  1,-304(1)	3 Store fp in ghost frame for outnl
* Param end outnl
185:    LDA  1,-304(1)	Ghost frame becomes new active frame 
186:    LDA  3,1(7)	Return address in ac 
187:    JMP  7,-154(7)	CALL OUTPUT outnl
188:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* CALL EXPRESSION
* CALL output
189:     ST  1,-304(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -306
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
190:     LD  3,-303(1)	2 Load variable z
191:    LDA  5,-3(1)	3 Load address of base of array 543 x
192:    SUB  5,5,3	Compute location from index 
193:     LD  3,0(5)	Load array element 
194:    LDA  5,-3(1)	3 Load address of base of array 543 x
195:    SUB  5,5,3	Compute location from index 
196:     LD  3,0(5)	Load array element 
197:    LDA  5,-3(1)	3 Load address of base of array 543 x
198:    SUB  5,5,3	Compute location from index 
199:     LD  3,0(5)	Load array element 
200:    LDA  5,-3(1)	3 Load address of base of array 543 x
201:    SUB  5,5,3	Compute location from index 
202:     LD  3,0(5)	Load array element 
203:    LDA  5,-3(1)	3 Load address of base of array 543 x
204:    SUB  5,5,3	Compute location from index 
205:     LD  3,0(5)	Load array element 
206:    LDA  5,-3(1)	3 Load address of base of array 543 x
207:    SUB  5,5,3	Compute location from index 
208:     LD  3,0(5)	Load array element 
209:     ST  3,-306(1)	Push parameter 
* Param end output
210:    LDA  1,-304(1)	1 Ghost frame becomes new active frame 
211:    LDA  3,1(7)	Return address in ac 
212:    JMP  7,-207(7)	CALL OUTPUT output
213:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
214:     ST  1,-304(1)	3 Store fp in ghost frame for outnl
* Param end outnl
215:    LDA  1,-304(1)	Ghost frame becomes new active frame 
216:    LDA  3,1(7)	Return address in ac 
217:    JMP  7,-184(7)	CALL OUTPUT outnl
218:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* CALL EXPRESSION
* CALL output
219:     ST  1,-304(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -306
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
220:     LD  3,-303(1)	2 Load variable z
221:    LDA  5,-3(1)	3 Load address of base of array 543 x
222:    SUB  5,5,3	Compute location from index 
223:     LD  3,0(5)	Load array element 
224:    LDA  5,-3(1)	3 Load address of base of array 543 x
225:    SUB  5,5,3	Compute location from index 
226:     LD  3,0(5)	Load array element 
227:    LDA  5,-3(1)	3 Load address of base of array 543 x
228:    SUB  5,5,3	Compute location from index 
229:     LD  3,0(5)	Load array element 
230:    LDA  5,-3(1)	3 Load address of base of array 543 x
231:    SUB  5,5,3	Compute location from index 
232:     LD  3,0(5)	Load array element 
233:    LDA  5,-3(1)	3 Load address of base of array 543 x
234:    SUB  5,5,3	Compute location from index 
235:     LD  3,0(5)	Load array element 
236:    LDA  5,-3(1)	3 Load address of base of array 543 x
237:    SUB  5,5,3	Compute location from index 
238:     LD  3,0(5)	Load array element 
239:    LDA  5,-3(1)	3 Load address of base of array 543 x
240:    SUB  5,5,3	Compute location from index 
241:     LD  3,0(5)	Load array element 
242:     ST  3,-306(1)	Push parameter 
* Param end output
243:    LDA  1,-304(1)	1 Ghost frame becomes new active frame 
244:    LDA  3,1(7)	Return address in ac 
245:    JMP  7,-240(7)	CALL OUTPUT output
246:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
247:     ST  1,-304(1)	3 Store fp in ghost frame for outnl
* Param end outnl
248:    LDA  1,-304(1)	Ghost frame becomes new active frame 
249:    LDA  3,1(7)	Return address in ac 
250:    JMP  7,-217(7)	CALL OUTPUT outnl
251:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* CALL EXPRESSION
* CALL output
252:     ST  1,-304(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -306
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
253:     LD  3,-303(1)	2 Load variable z
254:    LDA  5,-3(1)	3 Load address of base of array 543 x
255:    SUB  5,5,3	Compute location from index 
256:     LD  3,0(5)	Load array element 
257:    LDA  5,-3(1)	3 Load address of base of array 543 x
258:    SUB  5,5,3	Compute location from index 
259:     LD  3,0(5)	Load array element 
260:    LDA  5,-3(1)	3 Load address of base of array 543 x
261:    SUB  5,5,3	Compute location from index 
262:     LD  3,0(5)	Load array element 
263:    LDA  5,-3(1)	3 Load address of base of array 543 x
264:    SUB  5,5,3	Compute location from index 
265:     LD  3,0(5)	Load array element 
266:    LDA  5,-3(1)	3 Load address of base of array 543 x
267:    SUB  5,5,3	Compute location from index 
268:     LD  3,0(5)	Load array element 
269:    LDA  5,-3(1)	3 Load address of base of array 543 x
270:    SUB  5,5,3	Compute location from index 
271:     LD  3,0(5)	Load array element 
272:    LDA  5,-3(1)	3 Load address of base of array 543 x
273:    SUB  5,5,3	Compute location from index 
274:     LD  3,0(5)	Load array element 
275:    LDA  5,-3(1)	3 Load address of base of array 543 x
276:    SUB  5,5,3	Compute location from index 
277:     LD  3,0(5)	Load array element 
278:     ST  3,-306(1)	Push parameter 
* Param end output
279:    LDA  1,-304(1)	1 Ghost frame becomes new active frame 
280:    LDA  3,1(7)	Return address in ac 
281:    JMP  7,-276(7)	CALL OUTPUT output
282:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
283:     ST  1,-304(1)	3 Store fp in ghost frame for outnl
* Param end outnl
284:    LDA  1,-304(1)	Ghost frame becomes new active frame 
285:    LDA  3,1(7)	Return address in ac 
286:    JMP  7,-253(7)	CALL OUTPUT outnl
287:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* CALL EXPRESSION
* CALL output
288:     ST  1,-304(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -306
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
289:     LD  3,-303(1)	2 Load variable z
290:    LDA  5,-3(1)	3 Load address of base of array 543 x
291:    SUB  5,5,3	Compute location from index 
292:     LD  3,0(5)	Load array element 
293:    LDA  5,-3(1)	3 Load address of base of array 543 x
294:    SUB  5,5,3	Compute location from index 
295:     LD  3,0(5)	Load array element 
296:    LDA  5,-3(1)	3 Load address of base of array 543 x
297:    SUB  5,5,3	Compute location from index 
298:     LD  3,0(5)	Load array element 
299:    LDA  5,-3(1)	3 Load address of base of array 543 x
300:    SUB  5,5,3	Compute location from index 
301:     LD  3,0(5)	Load array element 
302:    LDA  5,-3(1)	3 Load address of base of array 543 x
303:    SUB  5,5,3	Compute location from index 
304:     LD  3,0(5)	Load array element 
305:    LDA  5,-3(1)	3 Load address of base of array 543 x
306:    SUB  5,5,3	Compute location from index 
307:     LD  3,0(5)	Load array element 
308:    LDA  5,-3(1)	3 Load address of base of array 543 x
309:    SUB  5,5,3	Compute location from index 
310:     LD  3,0(5)	Load array element 
311:    LDA  5,-3(1)	3 Load address of base of array 543 x
312:    SUB  5,5,3	Compute location from index 
313:     LD  3,0(5)	Load array element 
314:    LDA  5,-3(1)	3 Load address of base of array 543 x
315:    SUB  5,5,3	Compute location from index 
316:     LD  3,0(5)	Load array element 
317:     ST  3,-306(1)	Push parameter 
* Param end output
318:    LDA  1,-304(1)	1 Ghost frame becomes new active frame 
319:    LDA  3,1(7)	Return address in ac 
320:    JMP  7,-315(7)	CALL OUTPUT output
321:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
322:     ST  1,-304(1)	3 Store fp in ghost frame for outnl
* Param end outnl
323:    LDA  1,-304(1)	Ghost frame becomes new active frame 
324:    LDA  3,1(7)	Return address in ac 
325:    JMP  7,-292(7)	CALL OUTPUT outnl
326:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* CALL EXPRESSION
* CALL output
327:     ST  1,-304(1)	1 Store fp in ghost frame for output
* Param 1
* TOFF: -306
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
328:     LD  3,-303(1)	2 Load variable z
329:    LDA  5,-3(1)	3 Load address of base of array 543 x
330:    SUB  5,5,3	Compute location from index 
331:     LD  3,0(5)	Load array element 
332:    LDA  5,-3(1)	3 Load address of base of array 543 x
333:    SUB  5,5,3	Compute location from index 
334:     LD  3,0(5)	Load array element 
335:    LDA  5,-3(1)	3 Load address of base of array 543 x
336:    SUB  5,5,3	Compute location from index 
337:     LD  3,0(5)	Load array element 
338:    LDA  5,-3(1)	3 Load address of base of array 543 x
339:    SUB  5,5,3	Compute location from index 
340:     LD  3,0(5)	Load array element 
341:    LDA  5,-3(1)	3 Load address of base of array 543 x
342:    SUB  5,5,3	Compute location from index 
343:     LD  3,0(5)	Load array element 
344:    LDA  5,-3(1)	3 Load address of base of array 543 x
345:    SUB  5,5,3	Compute location from index 
346:     LD  3,0(5)	Load array element 
347:    LDA  5,-3(1)	3 Load address of base of array 543 x
348:    SUB  5,5,3	Compute location from index 
349:     LD  3,0(5)	Load array element 
350:    LDA  5,-3(1)	3 Load address of base of array 543 x
351:    SUB  5,5,3	Compute location from index 
352:     LD  3,0(5)	Load array element 
353:    LDA  5,-3(1)	3 Load address of base of array 543 x
354:    SUB  5,5,3	Compute location from index 
355:     LD  3,0(5)	Load array element 
356:    LDA  5,-3(1)	3 Load address of base of array 543 x
357:    SUB  5,5,3	Compute location from index 
358:     LD  3,0(5)	Load array element 
359:     ST  3,-306(1)	Push parameter 
* Param end output
360:    LDA  1,-304(1)	1 Ghost frame becomes new active frame 
361:    LDA  3,1(7)	Return address in ac 
362:    JMP  7,-357(7)	CALL OUTPUT output
363:    LDA  3,0(2)	Save the result in ac 
* CALL end output
* CALL EXPRESSION
* CALL outnl
364:     ST  1,-304(1)	3 Store fp in ghost frame for outnl
* Param end outnl
365:    LDA  1,-304(1)	Ghost frame becomes new active frame 
366:    LDA  3,1(7)	Return address in ac 
367:    JMP  7,-334(7)	CALL OUTPUT outnl
368:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
369:    LDC  2,0(6)	Set return value to 0 
370:     LD  3,-1(1)	Load return address 
371:     LD  1,0(1)	Adjust fp 
372:    JMP  7,0(3)	Return 
* END FUNCTION main
  0:    JMP  7,372(7)	Jump to init [backpatch] 
* INIT
373:    LDA  1,0(0)	set first frame at end of globals 
374:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
375:    LDA  3,1(7)	Return address in ac 
376:    JMP  7,-338(7)	Jump to main 
377:   HALT  0,0,0	DONE! 
* END INIT
