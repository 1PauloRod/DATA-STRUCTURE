#include "hash.h"


Hash* createHash(int len){
    Hash* hash = (Hash*)malloc(sizeof(Hash));
    if (hash == NULL)
        return NULL;
    hash->len = len;
    if (hash->array == NULL)
        return NULL;
    hash->collision = 0;
    for (int i = 0; i < len; i++)
        hash->array[i] = NULL;
    return hash;
}

void insertHash(Hash* hash, int value){
    if (hash == NULL)
        exit(1);
    int key, pos;
    key = value;
    pos = key % hash->len;
    if (hash->array[pos] == NULL){
        insert_list(&hash->array[pos], value);
    }else{
        insert_list(&hash->array[pos], value);
        hash->collision++;
    }
}

void printHash(List* list){
    List* t;
    for (t = list; t != NULL; t = t->next)
        printf("%d->", t->value);
    printf("(null)\n");
}
