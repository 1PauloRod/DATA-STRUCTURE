#include "hash.h"

int main(void){
   
    Hash* hash = createHash(12);
    insertHash(hash, 4);
    insertHash(hash, 10);
    insertHash(hash, 24);
    insertHash(hash, 36);
    insertHash(hash, 25);
    insertHash(hash, 14);
    insertHash(hash, 23);
    insertHash(hash, 100);
    insertHash(hash, 2);
    insertHash(hash, 3);
    insertHash(hash, 12);
    insertHash(hash, 13);

    printf("Hash w/ Linked List: \n\n");
    for (int i = 0; i < 12; i++)
        printHash(hash->array[i]);
    printf("\n");
    printf("total collisions: %d\n", hash->collision);
    return 0;
}
