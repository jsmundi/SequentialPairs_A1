/*
 * hashTable.c
 * SequentialPairs_A1
 * Author: JT Mundi
 * Date created: 01/25/2019
 * Date last modified: 02/04/2019
 */

#include "hashTable.h"

/*
 * hTable *newHT(int size)
 * 
 * Create and initialize a new hash table of specified size.
 * Allocate memory for table and return an error 3 if unsuccessfull. 
 * Initialize all the values with Null and set count to zero.
 * A Null value marks the bucket to be empty in the items array. 
 * 
 * Return pointer to the newly created hash table.
 */
hTable *createHT(int size)
{
    hTable *newHT = NULL;

    //Allocate memory for the hash table
    if ((newHT = (hTable *)malloc(sizeof(hTable))) == NULL)
    {
        fprintf(stderr, "Unable to allocate memory for Hash Table\n");
        exit(3);
    }
    if ((newHT->items = (Node **)malloc(sizeof(Node *) * size)) == NULL)
    {
        fprintf(stderr, "Unable to allocate memory for Hash Table\n");
        exit(3);
    }

    //Initalize the hash table of size
    for (int i = 0; i < size; i++)
    {
        newHT->items[i] = NULL;
        newHT->count = 0;
    }

    //Set Size of table
    newHT->size = size;

    return newHT;
}

int hashKey(hTable *ht, char *key)
{
    int hashVal = 0;
    hashVal = ((crc64(key)) % (ht->size));
    return hashVal;
}

/* 
 * void insertHT(hTable *ht, char *key, void *value)
 *
 * Insert a key value pair into the hash table.
 * Iterate through the table to find an empty bucket,
 * insert the key and vlaue in empty bucket and update
 * the collison count of the Node. Resize if the threshold
 * of collisons increase by factor of 0.7 greater than
 * count/size to keep the performace of table intact. 
 * 
 */

void insertHT(hTable *ht, char *key, void *value)
{
    long double size = ht->size;
    long double count = ht->count;
    long double threshold = (count / size);
    int hashBuc = hashKey(ht, key);

    //Initalize new node and pointers
    Node *newNode = NULL;
    Node *curr = NULL;
    Node *prev = NULL;

    //Allocate memory for new node
    if ((newNode = (Node *)malloc(sizeof(Node))) == NULL)
    {
        fprintf(stderr, "Unable to allocate memory for Hash Table\n");
        exit(3);
    }

    //Set curr to first bucket
    curr = ht->items[hashBuc];

    //Iterate node until key match is found or empty bucket.
    while ((curr != NULL) && (strcmp(key, curr->key) != 0))
    {
        prev = curr;
        curr = curr->next;
    }

    //Intialize the node with key value pair for insertion
    newNode->key = key;
    newNode->next = NULL;
    newNode->value = value;

    //Insert at top
    if (curr == ht->items[hashBuc])
    {
        newNode->next = curr;
        ht->items[hashBuc] = newNode;
    }

    //Insert at bottom
    else
    {
        prev->next = newNode;
    }

    //Test for load factor and resize
    if (threshold > 0.7f)
    {
        resizeHT(ht);
    }
}

/*
 * void searchHT(hTable *ht, char *key)
 * 
 * Traverse to the correct list based on the hash value and check if key is
 * in the list. If found return a pointer to bucket. Else return NULL.
 * 
 */
void *searchHT(hTable *ht, char *key)
{
   int hashBuc = hashKey(ht, key);
    Node *current;                                    // to hold where we are in LL
    current = ht->items[hashBuc];
    while (current != NULL && current->key != NULL) {
        if (strcmp(key, current->key) != 0) {           // not the same
            current = current->next;                    // transverse LL
        }
        else if (strcmp(key, current->key) == 0) {      // they match
            return current->value;
        }
    }
    return NULL;   
}

/*
 * void destroyHT(hTable *ht, void(*f)(Node *current))
 * 
 * Iterate the hashtable and delete a key and destroy 
 * the node. Rearrange the next pointers.
 * 
 */ 
void destroyHT(hTable *ht, void (*f)(Node *current))
{
    Node *current = NULL;
    Node *temp = NULL;

    for (int i = 0; i < ht->size; i++)
    { //loop through hashtable
        current = ht->items[i];
        while (current != NULL)
        { // loop through LL
            if (current->next != NULL)
            {
                temp = current->next; // save the next pointer
                current->next = NULL; // disconnect current->next
                f(current);           // free function
                current = temp;       // set current to next pointer
            }
            else
            {
                f(current);
                current = NULL;
            }
        }
    }
}


/*
 * void destroyNode(Node *curr)
 *
 * Empty the node and delete key 
 * and value pairs. 
 * 
 */ 
void destroyNode(Node *curr)
{
    if ((curr->value == NULL) || (curr->key == NULL))
    {
        free(curr);
    }
    else
    {
        free(curr->value);
        free(curr->key);
        free(curr);
    }
}

void updateHT(hTable *ht, void (*f)(char *k, void *v))
{
    int size = ht->size;
    Node *curr = NULL;

    for (int i = 0; i < size; i++)
    {
        curr = ht->items[i];
        if (curr != NULL)
        {
            while (curr != NULL)
            {
                f(curr->key, (int *)curr->value);
                curr = curr->next;
            }
        }
    }
}

/* void resizeHT(hTable *oldHT)
 *
 * Iterate the hash table copy data to temporaty table
 * resize the table by factor of three copy data 
 * to the old table after resizing and delete the temporary table.
 * 
 */ 
void resizeHT(hTable *oldHT)
{
    int newSize = oldHT->size * 3;
    Node *curr = NULL;

    hTable *tempHT = createHT(newSize);

    for (int i = 0; i < oldHT->size; i++)
    {
        curr = oldHT->items[i];
        if (curr != NULL)
        {
            while (curr != NULL)
            {
                tempHT->count = oldHT->count;
                insertHT(tempHT, curr->key, curr->value);
                curr->key = NULL;
                curr->value = NULL;
                curr = curr->next;
            }
        }
    }

    Node **temp = oldHT->items;
    oldHT->items = tempHT->items;
    oldHT->size = tempHT->size;
    tempHT->items = temp;
    tempHT->size = (tempHT->size / 3);

    destroyHT(tempHT, destroyNode);
    free(tempHT->items);
    free(tempHT);
}
