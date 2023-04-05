#include "binarySearch.h"

// iterative method
int binary_search(int len, int * v, int value){
    int low = 0;
    int high = len - 1;
    int mid;

    while (low <= high){
        mid = (low + high) / 2;
        if (value < v[mid]){
            high = mid - 1;
        }else if(value > v[mid]){
            low = mid + 1;
        }else{
            return mid;
        }
    }
    return -1;
}

//recursive method
int binary_search_recursive(int len, int * v, int low, int high, int value){
    
    if (low <= high){
        int mid = (low + high) / 2;
        
        if (value == v[mid]){
            return mid;
        }

        if (value < v[mid]){
            return binary_search_recursive(len, v, low, mid - 1, value);
        }else{
            return binary_search_recursive(len, v, mid + 1, high, value);
        }
    }
    return -1;
}
