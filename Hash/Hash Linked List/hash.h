#include <stdio.h>
#include <stdlib.h>
#include "../../Linked List/linkedList.h"

struct hash{
    int collision;
    int len;
    List* array[100];
};typedef struct hash Hash;

Hash* createHash(int len);
void insertHash(Hash* hash, int value);
void printHash(List* list);
