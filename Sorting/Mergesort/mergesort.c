#include "mergesort.h"
#include <stdlib.h>

int* left_partition(int* vector, int len){
    int* left = (int*)malloc((len - len/2) * sizeof(int));
    if (left == NULL) exit(1);
    for (int i = 0; i < len/2; i++){
        left[i] = vector[i];
    }
    return left;
}

int* right_partition(int* vector, int len){
    int* right = (int*)malloc((len - len/2) * sizeof(int));
    if (right == NULL) exit(1);
    for (int i = len/2; i < len; i++){
        right[i - len/2] = vector[i];
    }

    return right;
}

int* merge(int* left, int left_len, int* right, int right_len){
    int* merged = (int*)malloc((left_len + right_len) * sizeof(int));
    if (merged == NULL) exit(1);

    int i = 0, j = 0, k = 0;

    while(i < left_len && j < right_len){
        if (left[i] <= right[j]){
            merged[k] = left[i];
            i++;
        }else{
            merged[k] = right[j];
            j++;
        }
        k++;
    } 

    while (i < left_len){
        merged[k] = left[i];
        i++;k++;
    }

    while (j < right_len){
        merged[k] = right[j];
        j++;k++;
    }

    return merged;
}

int* mergesort(int* vector, int len){
    if (len == 1){
        int* single_element = (int*)malloc(sizeof(int));
        *single_element = vector[0];
        return single_element;
    }
    int* left = left_partition(vector, len);
    int* right = right_partition(vector, len);

    int* left_ord = mergesort(left, len/2);
    int* right_ord = mergesort(right, len - len/2);

    int* sorted = merge(left_ord, len/2, right_ord, len - len/2);

    free(left);
    free(right);
    free(left_ord);
    free(right_ord);

    return sorted;
}

void print_vector(int* vet, int len){
    for (int i = 0; i < len - 1; i++){
        printf("%d - ", vet[i]);
    }
    printf("%d\n", vet[len-1]);
}