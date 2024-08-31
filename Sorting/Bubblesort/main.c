#include <stdio.h>
#include "bubblesort.h"


int main(void){
    int vector[10] = {7, 3, 8, 1, 9, 2, 5, 4, 10, 6};
    printf("Before Bubble Sort: \n");
    print_vector(vector, 10);
    printf("After Bubble Sort: \n");
    bubblesort(vector, 10);
    print_vector(vector, 10);
    printf("\n");
    int a = 10;
    int b = 4;
    swap(&a, &b);
    return 0;
}