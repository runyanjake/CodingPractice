#Makefile for github.com/runyanjake/CodingPractice/C++/...
FLAGS			= -std=gnu++14
CUSTOMFILENAME	= -o a.out
MAINSRC			= main.cpp
MODULES			= HelloWorld #put .cpps here that have matching .h files (NOTE: .h files with no .cpp (like generic classes) get compiled when used)
CPPSOURCE		= ${MODULES:=.cpp} ${MAINSRC}
OBJS			= ${CPPSOURCE:.cpp=.o}

all : ${OBJS}
	g++ ${OBJS} ${FLAGS} ${CUSTOMFILENAME}

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