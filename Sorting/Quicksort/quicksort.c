#include "quicksort.h"

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){

    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++){
        if (arr[j] <= pivot){
            swap(&arr[j], &arr[i]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

void quicksort(int arr[], int low, int high){
    if (low < high){
        int pivot_index = partition(arr, low, high);
        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}

void print_vector(int* vet, int len){
    for (int i = 0; i < len - 1; i++){
        printf("%d - ", vet[i]);
    }
    printf("%d\n", vet[len-1]);
}