#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "crc64.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Node
{
    char *key;
    void *value;
    void *next;
}Node;

typedef struct hashTable
{
    int count;
    int size;
    Node **list; 
}hTable;

hTable newHT(int size);
int hashKey(hTable *ht, char *key);
void insertHT(hTable *ht, char *key, void *value); 
void searchHT(hTable *ht, char *key);
void deleteHT(hTable *ht, void(*func)(Node *curr));
void resizeHT(hTable *ht); 
void destroyNode(Node *curr); 

#endif
