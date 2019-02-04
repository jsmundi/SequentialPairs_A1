/*
 * main.c
 * SequentialPairs_A1
 * Author: JT Mundi
 * Date created: 01/25/2019
 * Date last modified: 02/04/2019
 */

#include "getWord.h"
#include "hashTable.h"
#include <math.h>

/* Data struct to hold the key, value and 
 * position 
 */ 
#define HT_SIZE 100

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


/* Insert the word pairs into the hashtable and update count*/
void insert(hTable *ht, char *wPair)
{
    int *wpCount = (int *)searchHT(ht, wPair);
    if (wpCount == NULL)
    {
        if ((wpCount = (int *)malloc(sizeof(int))) == NULL)
        {
            fprintf(stderr, "Error allocating memory for word pair.\n");
            exit(2);
        }
        (*wpCount) = 1;
        ht->count++;
        insertHT(ht, wPair, wpCount);
    }
    else
    {
        (*wpCount)++;
        free(wPair);
    }
}

/* Compare function for qSort */
int _compare(const void *a, const void *b)
{
    int _a = *((int *)((Data *)a)->value);
    int _b = *((int *)((Data *)b)->value);

    if (_a > _b)
    {
        return -1;
    }
    if (_a == _b)
    {
        return 0;
    }
    return 1;
}

/* Populate data array with key and value and update position */
void _makeData(char *key, void *value)
{
    data[position].key = key;
    data[position].value = value;
    position++;
}

/* Sort the data in hash table using qsort and update hahtable into array */
void sortData(hTable *ht)
{
    if ((data = calloc(ht->count, sizeof(Data))) == NULL)
    {
        fprintf(stderr, "Error allocating memory for word pair.\n");
        exit(2);
    }
    updateHT(ht, _makeData);
    qsort(data, ht->count, sizeof(Data), _compare);
}

/* Prints out keys and count */
void printData(hTable *ht, int count)
{
    if (count == 0 || count > (ht->count))
    {
        count = ht->count;
    }
    for (int i = 0; i < count; i++)
    {
        printf("%10d %s\n", *((int *)data[i].value), data[i].key);
    }
}

int main(int argc, char const *argv[])
{

    FILE *fp= NULL;
    char *temp= NULL;
    char *w1= NULL;
    char *w2= NULL;
    char *wPair= NULL;
    int wLen = 0;
    int countFlag = 1;
    int count = 0;

    //Initialize table
    hTable *ht = createHT(HT_SIZE);

    if (argv[1] == NULL)
    {
        fprintf(stderr, "No files provided\n");
        exit(1);
    }

    if (argv[1][0] == '-')
    {
        sscanf(argv[1], "-%d", &count);
        countFlag++;
    }

    //Iterate the argc for files
    while (countFlag < argc)
    {

        if ((fp = fopen(argv[countFlag], "r")) == NULL)
        {
            fprintf(stderr, "Unable to open file\n");
            exit(1);
        }

        //Store word into temp from getWord.c
        temp = getNextWord(fp);

        while (temp != NULL)
        {
            wLen = strlen(temp);
            w1 = temp;
            temp = getNextWord(fp);
            w2 = temp;
            if (w2 == NULL)
            {
                free(w1);
                break;
            }
            wLen = wLen + strlen(temp) + 2;
            if ((wPair = (char *)malloc(wLen)) == NULL)
            {
                fprintf(stderr, "Error allocating memory for word pair.\n");
                exit(2);
            }
            strcpy(wPair, w1);
            free(w1);
            strcat(wPair, " ");
            strcat(wPair, w2);
            insert(ht, wPair);
        }
        fclose(fp);
        free(temp);
        free(w2);
        countFlag++;
    }

    //Sort the data in desc order
    sortData(ht);
    //Print the data
    printData(ht, count);

    //Free allocated memory 
    free(data);
    destroyHT(ht, destroyNode);
    free(ht->items);
    free(ht);

    return 0;
}
