#Makefile for github.com/runyanjake/CodingPractice/C++/...
FLAGS			= -std=gnu++14
DEBUGFLAGS			= -std=gnu++14 -g
CUSTOMFILENAME	= -o a.out
MAINSRC			= main.cpp
MODULES			= Graphs HelloWorld Hashmap JStack JQueue #put .cpps here that have matching .h files (NOTE: .h files with no .cpp (like generic classes) get compiled when used)
CPPSOURCE		= ${MODULES:=.cpp} ${MAINSRC}
OBJS			= ${CPPSOURCE:.cpp=.o}

all : ${OBJS}
	g++ ${OBJS} ${DEBUGFLAGS} ${CUSTOMFILENAME}

test :
	make clean
	make
	make run

debug :
	make clean
	make
	gdb a.out

%.o : %.cpp
	g++ -std=gnu++14 -c $<

run :
	./a.out

clean :
	- @rm a.out *.gch *.o
	clear

full :
	make
	make run
	make clean

hashmap :
	g++ -std=gnu++14 Hashmap_main.cpp