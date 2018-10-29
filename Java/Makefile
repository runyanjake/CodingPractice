MAINCLASSNAME	= main
SUBDIRS := $(wildcard */.)

all:
	make clean
	make compile
	make run
	
compile:
	javac $(MAINCLASSNAME).java

run:
	java $(MAINCLASSNAME)

clean: 
	-@ rm *.class
	-@ for dir in $(SUBDIRS) ; do \
        rm $$dir/*.class ; \
    done
	clear