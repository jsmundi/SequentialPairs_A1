# Makefile 
# Program 1
#
# Author: JT Mundi
#
# Compile: make
# Run    : make run
# Clean  : make clean

CC = gcc 
FLAGS =  -g -std=c99 -Wall -pedantic 
GET_PATH = .

PROJECT_NAME = 1A_360
FILES = main.c hashTable.h hashTable.c helper.h Makefile

wordpairs: main.o hashTable.o crc64.o getWord.o
		$(CC) $(FLAGS) -o wordpairs main.o hashTable.o crc64.o getWord.o

main.o: main.c $(GET_PATH)/include/getWord.c
		$(CC) -c $(FLAGS) main.c $(GET_PATH)/include/getWord.c

crc64.o: $(GET_PATH)/dict/crc64.c $(GET_PATH)/dict/crc64.h
		$(CC) -c $(FLAGS) $(GET_PATH)/dict/crc64.c

hashTable.o: hashTable.c hashTable.h
		$(CC) -c $(FLAGS) hashTable.c

getWord.o: $(GET_PATH)/include/getWord.c $(GET_PATH)/include/getWord.h
		$(CC) -c $(FLAGS) $(GET_PATH)/include/getWord.c

tar:
	tar -cvf ${PROJECT_NAME}.tgz ${FILES}

# Used to clean up the solution
# it will remove all .o file and the execution file
clean:
	rm *.o wordpairs
