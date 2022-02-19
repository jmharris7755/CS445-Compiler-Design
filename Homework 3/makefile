#Justin Harris 
#CS445
#Last Updated: 2-11-22
#makefile executed to build my c-
BIN = parser
CC = g++

FLES = syntaxTree.c symbolTable.cpp semantic.cpp
SRCS = $(BIN).y  $(BIN).l
HDRS = scanType.h syntaxTree.h symbolTable.h semantic.h
OBJS = lex.yy.o $(BIN).tab.o 

$(BIN) : $(OBJS)
	$(CC) $(OBJS) $(FLES) -o c-

lex.yy.c : $(BIN).l $(BIN).tab.h $(HDRS)
	flex $(BIN).l 

$(BIN).tab.h $(BIN).tab.c : $(BIN).y 
	bison -v -t -d $(BIN).y 

clean :
	rm -f *~$(OBJS) $(BIN) lex.yy.c $(BIN).tab.h $(BIN).tab.c $(BIN).output

tar:
	tar -cvf $(BIN).tar $(HDRS) $(SRCS) $(FLES) makefile