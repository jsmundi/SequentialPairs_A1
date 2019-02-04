
# Makefile 
# Program 5
#
# Author: Jaiteg S Mundi
#
# Compile: make
# Run    : make run
# Clean  : make clean

CC=gcc
COMPILE=-g -c -std=c99 -Wall -pedantic
LINK= -g


wordpairs: main.o crc64.o hashTable.o getWord.o
	$(CC) $(LINK) -o wordpairs main.o crc64.o hashTable.o getWord.o

main.o:	main.c hashTable.h getWord.h
	$(CC) $(COMPILE) main.c

getWord.o: getWord.h getWord.c
	$(CC) $(COMPILE) getWord.c

crc64.o: crc64.c crc64.h 
	$(CC) $(COMPILE) crc64.c

hashTable.o: hashTable.c hashTable.h crc64.h
	$(CC) $(COMPILE) hashTable.c

clean:
	rm *.o wordpairs