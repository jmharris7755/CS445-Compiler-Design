* C- compiler version C-S21
* Built: 4-22 - 5-22
* Author: Justin Harris
* File compiled:  ./testDataA7/UnitTests/v02.tm
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
* TOFF:  -14
 40:    LDC  3,5(6)	load array size 124 a
 41:     ST  3,-2(1)	save array size a
  1:    LIT  "acid"
 42:    LDA  3,-1(0)	Load address of char array 
 43:    LDA  4,-3(1)	address of lhs 
 44:     LD  5,1(3)	size of rhs 
 45:     LD  6,1(4)	size of lhs 
 46:    SWP  5,6,6	pick smallest size 
 47:    MOV  4,3,5	array op = 
 48:    LDC  3,5(6)	load array size 124 b
 49:     ST  3,-8(1)	save array size b
  6:    LIT  "army"
 50:    LDA  3,-6(0)	Load address of char array 
 51:    LDA  4,-9(1)	address of lhs 
 52:     LD  5,1(3)	size of rhs 
 53:     LD  6,1(4)	size of lhs 
 54:    SWP  5,6,6	pick smallest size 
 55:    MOV  4,3,5	array op = 
* CALL EXPRESSION
* CALL outputb
 56:     ST  1,-14(1)	1 Store fp in ghost frame for outputb
* Param 1
* TOFF: -15
* TOFF: -16
* OP EXPRESSION
 57:     ST  3,-16(1)	Push the left side 677 
* TOFF: -17
* TOFF: -16
 58:     LD  4,-16(1)	Load Left into 1 =
 59:    TEQ  3,4,3	Op == =
 60:     ST  3,-16(1)	Push parameter 1001 
* Param end outputb
 61:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
 62:    LDA  3,1(7)	Return address in ac 
 63:    JMP  7,-47(7)	CALL OUTPUT outputb
 64:    LDA  3,0(2)	Save the result in ac 
* CALL end outputb
* TOFF: -14
* CALL EXPRESSION
* CALL outputb
 65:     ST  1,-14(1)	1 Store fp in ghost frame for outputb
* Param 1
* TOFF: -15
* TOFF: -16
* OP EXPRESSION
 66:     ST  3,-16(1)	Push the left side 677 
* TOFF: -17
* TOFF: -16
 67:     LD  4,-16(1)	Load Left into 1 =
 68:    TEQ  3,4,3	Op == =
 69:     ST  3,-16(1)	Push parameter 1001 
* Param end outputb
 70:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
 71:    LDA  3,1(7)	Return address in ac 
 72:    JMP  7,-56(7)	CALL OUTPUT outputb
 73:    LDA  3,0(2)	Save the result in ac 
* CALL end outputb
* TOFF: -14
* CALL EXPRESSION
* CALL outnl
 74:     ST  1,-14(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 75:    LDA  1,-14(1)	Ghost frame becomes new active frame 
 76:    LDA  3,1(7)	Return address in ac 
 77:    JMP  7,-44(7)	CALL OUTPUT outnl
 78:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -14
* CALL EXPRESSION
* CALL outputb
 79:     ST  1,-14(1)	1 Store fp in ghost frame for outputb
* Param 1
* TOFF: -15
* TOFF: -16
* OP EXPRESSION
 80:     ST  3,-16(1)	Push the left side 677 
* TOFF: -17
* TOFF: -16
 81:     LD  4,-16(1)	Load Left into 1 !=
 82:    TNE  3,4,3	Op != !=
 83:     ST  3,-16(1)	Push parameter 1001 
* Param end outputb
 84:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
 85:    LDA  3,1(7)	Return address in ac 
 86:    JMP  7,-70(7)	CALL OUTPUT outputb
 87:    LDA  3,0(2)	Save the result in ac 
* CALL end outputb
* TOFF: -14
* CALL EXPRESSION
* CALL outputb
 88:     ST  1,-14(1)	1 Store fp in ghost frame for outputb
* Param 1
* TOFF: -15
* TOFF: -16
* OP EXPRESSION
 89:     ST  3,-16(1)	Push the left side 677 
* TOFF: -17
* TOFF: -16
 90:     LD  4,-16(1)	Load Left into 1 !=
 91:    TNE  3,4,3	Op != !=
 92:     ST  3,-16(1)	Push parameter 1001 
* Param end outputb
 93:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
 94:    LDA  3,1(7)	Return address in ac 
 95:    JMP  7,-79(7)	CALL OUTPUT outputb
 96:    LDA  3,0(2)	Save the result in ac 
* CALL end outputb
* TOFF: -14
* CALL EXPRESSION
* CALL outnl
 97:     ST  1,-14(1)	3 Store fp in ghost frame for outnl
* Param end outnl
 98:    LDA  1,-14(1)	Ghost frame becomes new active frame 
 99:    LDA  3,1(7)	Return address in ac 
100:    JMP  7,-67(7)	CALL OUTPUT outnl
101:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -14
* CALL EXPRESSION
* CALL outputb
102:     ST  1,-14(1)	1 Store fp in ghost frame for outputb
* Param 1
* TOFF: -15
* TOFF: -16
* OP EXPRESSION
103:     ST  3,-16(1)	Push the left side 677 
* TOFF: -17
* TOFF: -16
104:     LD  4,-16(1)	Load Left into 1 >
105:    TGT  3,4,3	Op > >
106:     ST  3,-16(1)	Push parameter 1001 
* Param end outputb
107:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
108:    LDA  3,1(7)	Return address in ac 
109:    JMP  7,-93(7)	CALL OUTPUT outputb
110:    LDA  3,0(2)	Save the result in ac 
* CALL end outputb
* TOFF: -14
* CALL EXPRESSION
* CALL outputb
111:     ST  1,-14(1)	1 Store fp in ghost frame for outputb
* Param 1
* TOFF: -15
* TOFF: -16
* OP EXPRESSION
112:     ST  3,-16(1)	Push the left side 677 
* TOFF: -17
* TOFF: -16
113:     LD  4,-16(1)	Load Left into 1 >
114:    TGT  3,4,3	Op > >
115:     ST  3,-16(1)	Push parameter 1001 
* Param end outputb
116:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
117:    LDA  3,1(7)	Return address in ac 
118:    JMP  7,-102(7)	CALL OUTPUT outputb
119:    LDA  3,0(2)	Save the result in ac 
* CALL end outputb
* TOFF: -14
* CALL EXPRESSION
* CALL outnl
120:     ST  1,-14(1)	3 Store fp in ghost frame for outnl
* Param end outnl
121:    LDA  1,-14(1)	Ghost frame becomes new active frame 
122:    LDA  3,1(7)	Return address in ac 
123:    JMP  7,-90(7)	CALL OUTPUT outnl
124:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -14
* CALL EXPRESSION
* CALL outputb
125:     ST  1,-14(1)	1 Store fp in ghost frame for outputb
* Param 1
* TOFF: -15
* TOFF: -16
* OP EXPRESSION
126:     ST  3,-16(1)	Push the left side 677 
* TOFF: -17
* TOFF: -16
127:     LD  4,-16(1)	Load Left into 1 >=
128:    TGE  3,4,3	Op >= >=
129:     ST  3,-16(1)	Push parameter 1001 
* Param end outputb
130:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
131:    LDA  3,1(7)	Return address in ac 
132:    JMP  7,-116(7)	CALL OUTPUT outputb
133:    LDA  3,0(2)	Save the result in ac 
* CALL end outputb
* TOFF: -14
* CALL EXPRESSION
* CALL outputb
134:     ST  1,-14(1)	1 Store fp in ghost frame for outputb
* Param 1
* TOFF: -15
* TOFF: -16
* OP EXPRESSION
135:     ST  3,-16(1)	Push the left side 677 
* TOFF: -17
* TOFF: -16
136:     LD  4,-16(1)	Load Left into 1 >=
137:    TGE  3,4,3	Op >= >=
138:     ST  3,-16(1)	Push parameter 1001 
* Param end outputb
139:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
140:    LDA  3,1(7)	Return address in ac 
141:    JMP  7,-125(7)	CALL OUTPUT outputb
142:    LDA  3,0(2)	Save the result in ac 
* CALL end outputb
* TOFF: -14
* CALL EXPRESSION
* CALL outnl
143:     ST  1,-14(1)	3 Store fp in ghost frame for outnl
* Param end outnl
144:    LDA  1,-14(1)	Ghost frame becomes new active frame 
145:    LDA  3,1(7)	Return address in ac 
146:    JMP  7,-113(7)	CALL OUTPUT outnl
147:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -14
* CALL EXPRESSION
* CALL outputb
148:     ST  1,-14(1)	1 Store fp in ghost frame for outputb
* Param 1
* TOFF: -15
* TOFF: -16
* OP EXPRESSION
149:     ST  3,-16(1)	Push the left side 677 
* TOFF: -17
* TOFF: -16
150:     LD  4,-16(1)	Load Left into 1 <
151:    TLT  3,4,3	Op < <
152:     ST  3,-16(1)	Push parameter 1001 
* Param end outputb
153:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
154:    LDA  3,1(7)	Return address in ac 
155:    JMP  7,-139(7)	CALL OUTPUT outputb
156:    LDA  3,0(2)	Save the result in ac 
* CALL end outputb
* TOFF: -14
* CALL EXPRESSION
* CALL outputb
157:     ST  1,-14(1)	1 Store fp in ghost frame for outputb
* Param 1
* TOFF: -15
* TOFF: -16
* OP EXPRESSION
158:     ST  3,-16(1)	Push the left side 677 
* TOFF: -17
* TOFF: -16
159:     LD  4,-16(1)	Load Left into 1 <
160:    TLT  3,4,3	Op < <
161:     ST  3,-16(1)	Push parameter 1001 
* Param end outputb
162:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
163:    LDA  3,1(7)	Return address in ac 
164:    JMP  7,-148(7)	CALL OUTPUT outputb
165:    LDA  3,0(2)	Save the result in ac 
* CALL end outputb
* TOFF: -14
* CALL EXPRESSION
* CALL outnl
166:     ST  1,-14(1)	3 Store fp in ghost frame for outnl
* Param end outnl
167:    LDA  1,-14(1)	Ghost frame becomes new active frame 
168:    LDA  3,1(7)	Return address in ac 
169:    JMP  7,-136(7)	CALL OUTPUT outnl
170:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -14
* CALL EXPRESSION
* CALL outputb
171:     ST  1,-14(1)	1 Store fp in ghost frame for outputb
* Param 1
* TOFF: -15
* TOFF: -16
* OP EXPRESSION
172:     ST  3,-16(1)	Push the left side 677 
* TOFF: -17
* TOFF: -16
173:     LD  4,-16(1)	Load Left into 1 <=
174:    TLE  3,4,3	Op <= <=
175:     ST  3,-16(1)	Push parameter 1001 
* Param end outputb
176:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
177:    LDA  3,1(7)	Return address in ac 
178:    JMP  7,-162(7)	CALL OUTPUT outputb
179:    LDA  3,0(2)	Save the result in ac 
* CALL end outputb
* TOFF: -14
* CALL EXPRESSION
* CALL outputb
180:     ST  1,-14(1)	1 Store fp in ghost frame for outputb
* Param 1
* TOFF: -15
* TOFF: -16
* OP EXPRESSION
181:     ST  3,-16(1)	Push the left side 677 
* TOFF: -17
* TOFF: -16
182:     LD  4,-16(1)	Load Left into 1 <=
183:    TLE  3,4,3	Op <= <=
184:     ST  3,-16(1)	Push parameter 1001 
* Param end outputb
185:    LDA  1,-14(1)	1 Ghost frame becomes new active frame 
186:    LDA  3,1(7)	Return address in ac 
187:    JMP  7,-171(7)	CALL OUTPUT outputb
188:    LDA  3,0(2)	Save the result in ac 
* CALL end outputb
* TOFF: -14
* CALL EXPRESSION
* CALL outnl
189:     ST  1,-14(1)	3 Store fp in ghost frame for outnl
* Param end outnl
190:    LDA  1,-14(1)	Ghost frame becomes new active frame 
191:    LDA  3,1(7)	Return address in ac 
192:    JMP  7,-159(7)	CALL OUTPUT outnl
193:    LDA  3,0(2)	Save the result in ac 
* CALL end outnl
* TOFF: -14
* Compound Body
* TOFF:  -2
* END COMPOUND
* Add standard closing in case there is no return statement
194:    LDC  2,0(6)	Set return value to 0 
195:     LD  3,-1(1)	Load return address 
196:     LD  1,0(1)	Adjust fp 
197:    JMP  7,0(3)	Return 
* END FUNCTION main
* TOFF: -2
  0:    JMP  7,197(7)	Jump to init [backpatch] 
* INIT
198:    LDA  1,-10(0)	set first frame at end of globals 
199:     ST  1,0(1)	store old fp (point to self) 
* INIT GLOBALS AND STATICS
* END INIT GLOBALS AND STATICS
200:    LDA  3,1(7)	Return address in ac 
201:    JMP  7,-163(7)	Jump to main 
202:   HALT  0,0,0	DONE! 
* END INIT
