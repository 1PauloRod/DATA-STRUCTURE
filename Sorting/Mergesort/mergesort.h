#include <stdio.h>

int* mergesort(int* vector, int len);
int* left_partition(int* vector, int len);
int* right_partition(int* vector, int len);
int* merge(int* left, int left_len, int* right, int right_len);
void print_vector(int* vet, int len);