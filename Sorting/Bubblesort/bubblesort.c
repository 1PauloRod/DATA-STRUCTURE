#include "bubblesort.h"


void swap(int* a, int* b){
    int aux = *a; 
    *a = *b; 
    *b = aux; 
}

void bubblesort(int* vet, int len){
    for (int i = 0; i <len; i++){
        for(int j = i + 1; j <len; j++){
            if(vet[i] > vet[j]){
                swap(&vet[i], &vet[j]);
            }
        }
    }
}

void print_vector(int* vet, int len){
    for (int i = 0; i < len - 1; i++){
        printf("%d - ", vet[i]);
    }
    printf("%d\n", vet[len-1]);
}
