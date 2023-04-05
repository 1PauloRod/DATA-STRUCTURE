#include "heap.h"

int main(){
    int vet1[] = { 33, 39, 28, 66, 70, 60, 78, 95, 0, 0 };
    int vet2[] = { 33, 39, 28, 66, 70, 60, 78, 95, 0, 0 };
    int vet3[] = { 33, 39, 28, 66, 70, 60, 78, 95, 0, 0 };
    int len1, len2, len3;
    int new_value = 100;
    len1 = len2 = len3 = 8;
    
    printf("create heap1 by constructor1\n"); 
    construct1(vet1, len1);
    for (int i = 0; i < len1; i++)
        printf("%d\t", vet1[i]);
    printf("\n");
    
    printf("create heap2 by constructor2\n"); 
    construct2(vet2, len2);
    for (int i = 0; i < len2; i++)
        printf("%d\t", vet2[i]);
    printf("\n");
    
    printf("remove element of heap1 \n");
    remove_(vet1, len1);
    len1--;
    for (int i = 0; i < len1; i++)
        printf("%d\t", vet1[i]);
    printf("\n");
    
    printf("insert element with value %d in heap1\n", new_value);
    insert(vet1, new_value, len1);
    len1++;
    for (int i = 0; i < len1; i++)
        printf("%d\t", vet1[i]);
    printf("\n");
    
    printf("heapsort vet3\n");
    heapsort(vet3, len3);
    for (int i = 0; i < len3; i++)
        printf("%d\t", vet3[i]);
    printf("\n");

    return 0;
}