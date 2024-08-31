#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"


int main(void){
    int vector[10] = {7, 3, 8, 1, 9, 2, 5, 4, 10, 6};
    printf("Before merge sort: \n");
    print_vector(vector, 10);
    printf("\n");
    int* ms = mergesort(vector, 10);
    printf("After merge sort: \n");
    print_vector(ms, 10);
    free(ms);
    return 0;
}