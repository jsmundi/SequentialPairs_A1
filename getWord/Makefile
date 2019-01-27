
# Makefile 
# Program 5
#
# Author: Jaiteg S Mundi
#
# Compile: make
# Run    : make run
# Clean  : make clean

CPP = gcc
FLAGS = -Wall -g -std=c99 -pedantic 

EXEC = main
OBJS = main.o getWord.o 

PROJECT_NAME = Assignment_1
FILES = main.c Makefile

default:${EXEC}

clean:
	rm -f ${EXEC}
	rm -f *.o

run: ${EXEC}
	./${EXEC}

${EXEC}:${OBJS}
	${CPP} ${FLAGS} -o ${EXEC} ${OBJS}

tar:
	tar -cvf ${PROJECT_NAME}.tgz ${FILES}


.c.o:
	${CPP} ${FLAGS} -c $<

main.o: main.c getWord.h
getWord.o: getWord.c getWord.h
