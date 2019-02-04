
# Makefile 
# Program 1
#
# Author: JT Mundi
#
# Compile: make
# Run    : make run
# Clean  : make clean

CPP = gcc
FLAGS = -Wall -g -std=c99 -pedantic 

EXEC = main
OBJS = main.o hashTable.o getWord.o crc64.o

PROJECT_NAME = 360_1A
FILES = hashTable.c hashTable.h crc64.c crc64.h getWord.c getWord.h main.c Makefile

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

main.o: main.c hashTable.h
hashTable.o: hashTable.c getWord.h crc64.h
getWord.o: getWord.c getWord.h
crc64.o: crc64.c crc64.h