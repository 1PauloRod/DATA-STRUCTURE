#include <stdio.h>
#include <stdlib.h>

struct hash{
    int len;
    int collision;
    int array[100];
}; typedef struct hash Hash;


Hash* createHash(int len);
int functionHash(int key, int i, int pos, int len);
int insertHash(Hash* hash, int value);
void printHash(Hash* hash, int len);
