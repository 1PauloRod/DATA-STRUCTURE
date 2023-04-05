#include "binarySearch.h"


int main(void){

    int vet[7] = {10, 40, 70, 90, 120, 200, 300};
    int len = sizeof(vet)/sizeof(vet[0]);
    int result = binary_search(len, vet, 70);
    //int result = binary_search_recursive(len, vet, 0, len - 1, 70);

    if (result == -1){
        printf("Not found");
    }else{
        printf("Element is found at index %d", result);
    }

    return 0;
}