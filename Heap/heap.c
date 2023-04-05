#include "heap.h"
#define LEN 10

void up(int vet[], int i){
    int j, aux;
    j = (i - 1)/2;
    if (j >= 0){
        if (vet[i] > vet[j]){
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux; 
            up(vet, j);
        }
    }
}

void down(int vet[], int i, int len){
    int j, aux; 
    j = (2 * i) + 1;
    if (j <= len){
        if (j < len){
            if (vet[j + 1] > vet[j])
                j++;
        }
        if (vet[i] < vet[j]){
            aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            down(vet, j, len);            
        }
    }
}

void insert(int vet[], int new_, int len){
    if (len < LEN){
        vet[len] = new_;
        up(vet, len);
    }else{
        printf("error!\n");
    }
}

void remove_(int vet[], int len){
    if (len != 0){
        vet[0] = vet[len - 1];
        len--;
        down(vet, 0, len);
    }
}

void construct1(int vet[], int n){
    for (int i = (n / 2) - 1; i >= 0; i--){
        down(vet, i, n);
    }
}

void construct2(int vet[], int n){
    for(int i = 1; i < n; i++){
        up(vet, i);
    }
}

void heapsort(int vet[], int len){
    int n, aux;
    construct1(vet, len);
    printf("heapsort\n");
    n = len - 1;
    while(n >= 0){
        aux = vet[0];
        vet[0] = vet[n];
        vet[n] = aux;
        n--;
        down(vet, 0, n);
    }
}