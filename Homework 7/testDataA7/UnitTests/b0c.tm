* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/b0c.tm
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
* TOFF:  -2
* CALL EXPRESSION
* CALL outputb
 40:     ST  1,-2(1)	1 Store fp in ghost frame for outputb
* Param 1
* TOFF: -4
* OP EXPRESSION
* OP EXPRESSION
 41:    LDC  3,1(6)	Load Integer constant 
 42:    RND  3,3,6	Op unary ?
 43:     ST  3,-4(1)	Push the left side 
 44:    LDC  3,0(6)	Load Integer constant 
 45:     LD  4,-4(1)	Load Left into 1 
 46:    TEQ  3,4,3	Op == =
 47:     ST  3,-4(1)	Push parameter 
* Param end outputb
 48:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
 49:    LDA  3,1(7)	Return address in ac 
 50:    JMP  7,-34(7)	CALL OUTPUT outputb
 51:    LDA  3,0(2)	Save the result in ac 
* CALL end outputb
* CALL EXPRESSION
* CALL outnl
 52:     ST  1,-2(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 53:    LDA  1,-2(1)	Ghost frame becomes new active frame 
 54:    LDA  3,1(7)	Return address in ac 
 55:    JMP  7,-22(7)	CALL OUTPUT outnl
 56:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* CALL EXPRESSION
* CALL outputb
 57:     ST  1,-2(1)	1 Store fp in ghost frame for outputb
* Param 1
* TOFF: -4
* OP EXPRESSION
* OP EXPRESSION
 58:    LDC  3,100000(6)	Load Integer constant 
 59:    RND  3,3,6	Op unary ?
 60:     ST  3,-4(1)	Push the left side 
 61:    LDC  3,0(6)	Load Integer constant 
 62:     LD  4,-4(1)	Load Left into 1 
 63:    TGT  3,4,3	Op > >
 64:     ST  3,-4(1)	Push parameter 
* Param end outputb
 65:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
 66:    LDA  3,1(7)	Return address in ac 
 67:    JMP  7,-51(7)	CALL OUTPUT outputb
 68:    LDA  3,0(2)	Save the result in ac 
* CALL end outputb
* CALL EXPRESSION
* CALL outputb
 69:     ST  1,-2(1)	1 Store fp in ghost frame for outputb
* Param 1
* TOFF: -4
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
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
 70:    LDC  3,3(6)	Load Integer constant 
 71:    RND  3,3,6	Op unary ?
 72:     ST  3,-4(1)	Push the left side 
 73:    LDC  3,0(6)	Load Integer constant 
 74:     LD  4,-4(1)	Load Left into 1 
 75:    TGT  3,4,3	Op > >
 76:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
 77:    LDC  3,3(6)	Load Integer constant 
 78:    RND  3,3,6	Op unary ?
 79:     ST  3,-4(1)	Push the left side 
 80:    LDC  3,0(6)	Load Integer constant 
 81:     LD  4,-4(1)	Load Left into 1 
 82:    TGT  3,4,3	Op > >
 83:     LD  4,-3(1)	Load Left into 1 
 84:    AND  3,4,3	Op AND and
 85:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
 86:    LDC  3,3(6)	Load Integer constant 
 87:    RND  3,3,6	Op unary ?
 88:     ST  3,-4(1)	Push the left side 
 89:    LDC  3,0(6)	Load Integer constant 
 90:     LD  4,-4(1)	Load Left into 1 
 91:    TGT  3,4,3	Op > >
 92:     LD  4,-3(1)	Load Left into 1 
 93:    AND  3,4,3	Op AND and
 94:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
 95:    LDC  3,3(6)	Load Integer constant 
 96:    RND  3,3,6	Op unary ?
 97:     ST  3,-4(1)	Push the left side 
 98:    LDC  3,0(6)	Load Integer constant 
 99:     LD  4,-4(1)	Load Left into 1 
100:    TGT  3,4,3	Op > >
101:     LD  4,-3(1)	Load Left into 1 
102:    AND  3,4,3	Op AND and
103:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
104:    LDC  3,3(6)	Load Integer constant 
105:    RND  3,3,6	Op unary ?
106:     ST  3,-4(1)	Push the left side 
107:    LDC  3,0(6)	Load Integer constant 
108:     LD  4,-4(1)	Load Left into 1 
109:    TGT  3,4,3	Op > >
110:     LD  4,-3(1)	Load Left into 1 
111:    AND  3,4,3	Op AND and
112:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
113:    LDC  3,3(6)	Load Integer constant 
114:    RND  3,3,6	Op unary ?
115:     ST  3,-4(1)	Push the left side 
116:    LDC  3,0(6)	Load Integer constant 
117:     LD  4,-4(1)	Load Left into 1 
118:    TGT  3,4,3	Op > >
119:     LD  4,-3(1)	Load Left into 1 
120:    AND  3,4,3	Op AND and
121:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
122:    LDC  3,3(6)	Load Integer constant 
123:    RND  3,3,6	Op unary ?
124:     ST  3,-4(1)	Push the left side 
125:    LDC  3,0(6)	Load Integer constant 
126:     LD  4,-4(1)	Load Left into 1 
127:    TGT  3,4,3	Op > >
128:     LD  4,-3(1)	Load Left into 1 
129:    AND  3,4,3	Op AND and
130:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
131:    LDC  3,3(6)	Load Integer constant 
132:    RND  3,3,6	Op unary ?
133:     ST  3,-4(1)	Push the left side 
134:    LDC  3,0(6)	Load Integer constant 
135:     LD  4,-4(1)	Load Left into 1 
136:    TGT  3,4,3	Op > >
137:     LD  4,-3(1)	Load Left into 1 
138:    AND  3,4,3	Op AND and
139:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
140:    LDC  3,3(6)	Load Integer constant 
141:    RND  3,3,6	Op unary ?
142:     ST  3,-4(1)	Push the left side 
143:    LDC  3,0(6)	Load Integer constant 
144:     LD  4,-4(1)	Load Left into 1 
145:    TGT  3,4,3	Op > >
146:     LD  4,-3(1)	Load Left into 1 
147:    AND  3,4,3	Op AND and
148:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
149:    LDC  3,3(6)	Load Integer constant 
150:    RND  3,3,6	Op unary ?
151:     ST  3,-4(1)	Push the left side 
152:    LDC  3,0(6)	Load Integer constant 
153:     LD  4,-4(1)	Load Left into 1 
154:    TGT  3,4,3	Op > >
155:     LD  4,-3(1)	Load Left into 1 
156:    AND  3,4,3	Op AND and
157:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
158:    LDC  3,3(6)	Load Integer constant 
159:    RND  3,3,6	Op unary ?
160:     ST  3,-4(1)	Push the left side 
161:    LDC  3,0(6)	Load Integer constant 
162:     LD  4,-4(1)	Load Left into 1 
163:    TGT  3,4,3	Op > >
164:     LD  4,-3(1)	Load Left into 1 
165:    AND  3,4,3	Op AND and
166:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
167:    LDC  3,3(6)	Load Integer constant 
168:    RND  3,3,6	Op unary ?
169:     ST  3,-4(1)	Push the left side 
170:    LDC  3,0(6)	Load Integer constant 
171:     LD  4,-4(1)	Load Left into 1 
172:    TGT  3,4,3	Op > >
173:     LD  4,-3(1)	Load Left into 1 
174:    AND  3,4,3	Op AND and
175:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
176:    LDC  3,3(6)	Load Integer constant 
177:    RND  3,3,6	Op unary ?
178:     ST  3,-4(1)	Push the left side 
179:    LDC  3,0(6)	Load Integer constant 
180:     LD  4,-4(1)	Load Left into 1 
181:    TGT  3,4,3	Op > >
182:     LD  4,-3(1)	Load Left into 1 
183:    AND  3,4,3	Op AND and
184:     ST  3,-4(1)	Push parameter 
* Param end outputb
185:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
186:    LDA  3,1(7)	Return address in ac 
187:    JMP  7,-171(7)	CALL OUTPUT outputb
188:    LDA  3,0(2)	Save the result in ac 
* CALL end outputb
* CALL EXPRESSION
* CALL outputb
189:     ST  1,-2(1)	1 Store fp in ghost frame for outputb
* Param 1
* TOFF: -4
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
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
* OP EXPRESSION
190:    LDC  3,3(6)	Load Integer constant 
191:    RND  3,3,6	Op unary ?
192:     ST  3,-4(1)	Push the left side 
193:    LDC  3,0(6)	Load Integer constant 
194:     LD  4,-4(1)	Load Left into 1 
195:    TGT  3,4,3	Op > >
196:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
197:    LDC  3,3(6)	Load Integer constant 
198:    RND  3,3,6	Op unary ?
199:     ST  3,-4(1)	Push the left side 
200:    LDC  3,0(6)	Load Integer constant 
201:     LD  4,-4(1)	Load Left into 1 
202:    TGT  3,4,3	Op > >
203:     LD  4,-3(1)	Load Left into 1 
204:     OR  3,4,3	Op OR or
205:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
206:    LDC  3,3(6)	Load Integer constant 
207:    RND  3,3,6	Op unary ?
208:     ST  3,-4(1)	Push the left side 
209:    LDC  3,0(6)	Load Integer constant 
210:     LD  4,-4(1)	Load Left into 1 
211:    TGT  3,4,3	Op > >
212:     LD  4,-3(1)	Load Left into 1 
213:     OR  3,4,3	Op OR or
214:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
215:    LDC  3,3(6)	Load Integer constant 
216:    RND  3,3,6	Op unary ?
217:     ST  3,-4(1)	Push the left side 
218:    LDC  3,0(6)	Load Integer constant 
219:     LD  4,-4(1)	Load Left into 1 
220:    TGT  3,4,3	Op > >
221:     LD  4,-3(1)	Load Left into 1 
222:     OR  3,4,3	Op OR or
223:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
224:    LDC  3,3(6)	Load Integer constant 
225:    RND  3,3,6	Op unary ?
226:     ST  3,-4(1)	Push the left side 
227:    LDC  3,0(6)	Load Integer constant 
228:     LD  4,-4(1)	Load Left into 1 
229:    TGT  3,4,3	Op > >
230:     LD  4,-3(1)	Load Left into 1 
231:     OR  3,4,3	Op OR or
232:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
233:    LDC  3,3(6)	Load Integer constant 
234:    RND  3,3,6	Op unary ?
235:     ST  3,-4(1)	Push the left side 
236:    LDC  3,0(6)	Load Integer constant 
237:     LD  4,-4(1)	Load Left into 1 
238:    TGT  3,4,3	Op > >
239:     LD  4,-3(1)	Load Left into 1 
240:     OR  3,4,3	Op OR or
241:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
242:    LDC  3,3(6)	Load Integer constant 
243:    RND  3,3,6	Op unary ?
244:     ST  3,-4(1)	Push the left side 
245:    LDC  3,0(6)	Load Integer constant 
246:     LD  4,-4(1)	Load Left into 1 
247:    TGT  3,4,3	Op > >
248:     LD  4,-3(1)	Load Left into 1 
249:     OR  3,4,3	Op OR or
250:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
251:    LDC  3,3(6)	Load Integer constant 
252:    RND  3,3,6	Op unary ?
253:     ST  3,-4(1)	Push the left side 
254:    LDC  3,0(6)	Load Integer constant 
255:     LD  4,-4(1)	Load Left into 1 
256:    TGT  3,4,3	Op > >
257:     LD  4,-3(1)	Load Left into 1 
258:     OR  3,4,3	Op OR or
259:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
260:    LDC  3,3(6)	Load Integer constant 
261:    RND  3,3,6	Op unary ?
262:     ST  3,-4(1)	Push the left side 
263:    LDC  3,0(6)	Load Integer constant 
264:     LD  4,-4(1)	Load Left into 1 
265:    TGT  3,4,3	Op > >
266:     LD  4,-3(1)	Load Left into 1 
267:     OR  3,4,3	Op OR or
268:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
269:    LDC  3,3(6)	Load Integer constant 
270:    RND  3,3,6	Op unary ?
271:     ST  3,-4(1)	Push the left side 
272:    LDC  3,0(6)	Load Integer constant 
273:     LD  4,-4(1)	Load Left into 1 
274:    TGT  3,4,3	Op > >
275:     LD  4,-3(1)	Load Left into 1 
276:     OR  3,4,3	Op OR or
277:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
278:    LDC  3,3(6)	Load Integer constant 
279:    RND  3,3,6	Op unary ?
280:     ST  3,-4(1)	Push the left side 
281:    LDC  3,0(6)	Load Integer constant 
282:     LD  4,-4(1)	Load Left into 1 
283:    TGT  3,4,3	Op > >
284:     LD  4,-3(1)	Load Left into 1 
285:     OR  3,4,3	Op OR or
286:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
287:    LDC  3,3(6)	Load Integer constant 
288:    RND  3,3,6	Op unary ?
289:     ST  3,-4(1)	Push the left side 
290:    LDC  3,0(6)	Load Integer constant 
291:     LD  4,-4(1)	Load Left into 1 
292:    TGT  3,4,3	Op > >
293:     LD  4,-3(1)	Load Left into 1 
294:     OR  3,4,3	Op OR or
295:     ST  3,-4(1)	Push the left side 
* OP EXPRESSION
* OP EXPRESSION
296:    LDC  3,3(6)	Load Integer constant 
297:    RND  3,3,6	Op unary ?
298:     ST  3,-4(1)	Push the left side 
299:    LDC  3,0(6)	Load Integer constant 
300:     LD  4,-4(1)	Load Left into 1 
301:    TGT  3,4,3	Op > >
302:     LD  4,-3(1)	Load Left into 1 
303:     OR  3,4,3	Op OR or
304:     ST  3,-4(1)	Push parameter 
* Param end outputb
305:    LDA  1,-2(1)	1 Ghost frame becomes new active frame 
306:    LDA  3,1(7)	Return address in ac 
307:    JMP  7,-291(7)	CALL OUTPUT outputb
308:    LDA  3,0(2)	Save the result in ac 
* CALL end outputb
* CALL EXPRESSION
* CALL outnl
309:     ST  1,-2(1)	3 Store fp in ghost frame for outnl
* Param end outnl
310:    LDA  1,-2(1)	Ghost frame becomes new active frame 
311:    LDA  3,1(7)	Return address in ac 
312:    JMP  7,-279(7)	CALL OUTPUT outnl
313:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
314:    LDC  2,0(6)	Set return value to 0 
315:     LD  3,-1(1)	Load return address 
316:     LD  1,0(1)	Adjust fp 
317:    JMP  7,0(3)	Return 
* END FUNCTION main
  0:    JMP  7,317(7)	Jump to init [backpatch] 
* INIT
318:    LDA  1,0(0)	set first frame at end of globals 
319:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
320:    LDA  3,1(7)	Return address in ac 
321:    JMP  7,-283(7)	Jump to main 
322:   HALT  0,0,0	DONE! 
* END INIT
