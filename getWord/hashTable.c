#include "hashTable.h"

hTable* newHT(int size){
    hTable *newHT = NULL;

    if(newHT = (hTable*)malloc(sizeof(hTable)) == NULL)
    {
        fprintf(stderr, "Unable to allocate memory for Hash Table\n"); 
        exit(3); 
    }

    for(int i = 0; i < size; i++)
    {
        newHT->list[i] = NULL;
        newHT->count = 0; 
    }

    newHT->size = size; 

    return newHT; 

}
int hashKey(hTable *ht, char *key){
    int hashVal = 0;
    hashVal = ((crc64(key)) % (ht->size)); 
    return hashVal;
}
void insertHT(hTable *ht, char *key, void *value){
    double size = ht->size; 
    double count = ht->count;
    double threshold = (count / size); 
    int hashBuc = hashKey(ht, key); 

    Node *curr = NULL;
    Node *prev = NULL; 

    curr = ht->list[hashBuc]; 

    while((curr != NULL) && (strcmp(key, curr->key) != 0)){
        prev = curr;
        curr = curr->key; 
    }
    



}
void searchHT(hTable *ht, char *key){

}
void deleteHT(hTable *ht, void(*func)(Node *curr)){

}
void resizeHT(hTable *ht){

}
void destroyNode(Node *curr){

}