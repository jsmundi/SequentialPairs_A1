/*
 * hashTable.h
 * SequentialPairs_A1
 * Author: JT Mundi
 * Date created: 01/25/2019
 * Date last modified: 02/04/2019
 */

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
    Node **items; 
}hTable;

hTable *createHT(int size);
int hashKey(hTable *ht, char *key);
void insertHT(hTable *ht, char *key, void *value); 
void *searchHT(hTable *ht, char *key);
void destroyHT(hTable *ht, void (*f)(Node *current));
void resizeHT(hTable *ht); 
void destroyNode(Node *curr); 
void updateHT(hTable *ht, void (*f)(char *k, void *v));

#endif
