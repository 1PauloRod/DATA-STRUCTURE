#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0


struct list{
    int value;
    struct list* next;
}; typedef struct list List;



void insert_list(List** list, int value);
void insert_end_list(List** list, int value);
void insert_sorted(List** list, int value);
int search_list(List** list, int value);
void delete_list(List** list, int value);
void delete_first_list(List** list);
void delete_end_list(List** list); 
void free_list(List** list);
void print_list(List** list); 