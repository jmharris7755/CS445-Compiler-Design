#makefile executed to build my c-
BIN = parser
CC = g++

SRCS = $(BIN).y  $(BIN).l
HDRS = scanType.h syntaxTree.h
OBJS = lex.yy.o $(BIN).tab.o 

$(BIN) : $(OBJS)
	$(CC) $(OBJS) -o c-

lex.yy.c : $(BIN).l $(BIN).tab.h $(HDRS)
	flex $(BIN).l 

$(BIN).tab.h $(BIN).tab.c : $(BIN).y 
	bison -v -t -d $(BIN).y 

clean :
	rm -f *~$(OBJS) $(BIN) lex.yy.c $(BIN).tab.h $(BIN).tab.c $(BIN).output

tar:
	tar -cvf $(BIN).tar $(HDRS) $(SRCS) makefile