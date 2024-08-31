#include <stdio.h>
#include "quicksort.h"


int main(void){
    int vector[10] = {7, 3, 8, 1, 9, 2, 5, 4, 10, 6};
    int n = 10;
    printf("Before quick sort: \n");
    print_vector(vector, 10);
    printf("\n");
    quicksort(vector, 0, n - 1);
    printf("After quick sort: \n");
    print_vector(vector, 10);
   
    return 0;
}