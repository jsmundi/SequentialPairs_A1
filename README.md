# SequentialPairs_A1

## Overview 
A  C program targeted at the Linux platform which reads words from one or more files, and prints out a list of the most frequently occuring sequential pairs of wrods an the number of times they occcurred, in decreasing order of occurence. 

## Program Interface
```bash
wordpairs <-count> fileName1 <fileName2> <fileName3> ...
```
Where: count is the integer number of word pairs to print out and fileNameN are
pathnames from which to read words. If no count argument is specified, ALL words
pairs are printed to stdout. (tokens enclosed in angular brackets are optional).

## Specifications
- All error output is printed to stderr. If unrecoverable errors occur, the program exits with a non-zero exit code, otherwise it exits with a zero exit code.
- All normal (expected) output (the list of word pairs and number of occurrences) are to be printed to stdout.
- A hash table is used to store and count occurrences of sequences of words. The hash table keeps track of how full it is and grow itself to a larger size as needed. Separate chaining is used to implement hash table buckets.
- The Hash table has a threshold of 0.7 after that the table is resized by factor of 3. 
- Hashing fucntion crc64.h is used for hashing strings.
- The standard library procedure “qsort()” is usedfor sorting with a compare function.
- The program outputs word pairs and their occurrence counts, output one word pair per line using the format %10d %s\n", where the decimal number is the number of occurrences and the string is the word pair (with one space between the words).
- The program manages the heap to prevent any memory leaks. (Checked with Valgrind)

## Running the Program

- Open the seqWordPairs Directory
- Run in terminal to compilte:

```bash
make
```
- To Run the executable file run in terminal in the same directory:

```bash
./wordpairs <-count> <filename1> <filename2>
```

- To clean the output files
```bash
make clean
```

-To create Tar of the program

```bash
make tar
```

## Output

Output for mobydick.txt and gettysubrg

```
./wordpairs -3 gettysburg
3 the people
3 to the
3 it is
```

```
./wordpairs -3 mobydick.txt
1906 of the
1193 in the
745 to the
```
### Author
JT Mundi
