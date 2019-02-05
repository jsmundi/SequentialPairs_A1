/*
 * helper.h
 * SequentialPairs_A1
 * Author: JT Mundi
 * Date created: 01/25/2019
 * Date last modified: 02/05/2019
 */

#ifndef HELPER_H
#define HELPER_H

typedef struct Data
{
    char *key;
    void *value;
} Data;

int position = 0;
Data *data = NULL;

/* Declaratiosn of helper functiosn for main */
int _compare(const void *a, const void *b);
void insert(hTable *ht, char *wPair);
void printData(hTable *ht, int count);
void _makeData(char *key, void *value);
void sortData(hTable *ht);

#endif