#include "hash.h"

int main(void){
    int LEN = 11; 
    Hash* hash = createHash(LEN); 
    insertHash(hash, 9);
    insertHash(hash, 10);
    insertHash(hash, 17);
    insertHash(hash, 3);
    insertHash(hash, 2);
    insertHash(hash, 13);
    insertHash(hash, 15);
    insertHash(hash, 25);
    insertHash(hash, 14);


    printf("Hash:\n\n");
    printHash(hash, LEN);
    printf("\n\n");
    printf("total collisions: %d\n", hash->collision);

    printf("%d\n", ((9%11)+0)%11);
    printf("%d\n", ((10%11)+1)%11);
    printf("%d\n", ((17%11))%11);
    printf("%d\n", ((3%11)+3)%11);
    printf("%d\n", ((2%11)+4)%11);
    printf("%d\n", ((13%11)+5)%11);
    printf("%d\n", ((15%11)+6)%11);
    printf("%d\n", ((25%11)+7)%11);
    printf("%d\n", ((14%11)+8)%11);
    
    return 0;
}          