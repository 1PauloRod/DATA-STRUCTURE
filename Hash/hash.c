#include "hash.h"


Hash* createHash(int len){
    Hash* hash = (Hash*)malloc(sizeof(Hash));
    if (hash == NULL)
        return NULL;
    hash->len = len;
    hash->collision = 0;
    if (hash->array == NULL)
        return NULL;
    for (int i = 0; i < len; i++){
        hash->array[i] = -1;
    }
    return hash;
}

int functionHash(int key, int i, int pos, int len){
    return ((key % 11) + i) % len;
}

int insertHash(Hash* hash, int value){
    if (hash == NULL)
        return 0;
    int key, pos, newPos;
    key = value;
    pos = key % hash->len;
    for (int i = 0; i < hash->len; i++){
        newPos = functionHash(key, i, pos, hash->len);
        if(hash->array[newPos] == -1){
            hash->array[newPos] = key;
            hash->collision++;
            return 1;
        }
    }
    return 0;
}

void printHash(Hash* hash, int len){
    for (int i = 0; i < len; i++)
         printf("array[%d] - %d\n", i, hash->array[i]);
}
