#include "linkedList.h"


void insert_list(List** list, int value){
    List* new = (List*)malloc(sizeof(List));
    if (new == NULL) exit(1);
    new->value = value;
    new->next = *list;
    *list = new;
    return ;
}

void insert_end_list(List** list, int value){
   List* aux;
   List* new = (List*)malloc(sizeof(List));
   if (new == NULL) exit(1);
   new->value = value;
   new->next = NULL;

   if (*list == NULL){
    *list = new;
   }else{
    aux = *list;
    while(aux->next != NULL){
        aux = aux->next;
        }
        aux->next = new;
    }
    return ;
}

void insert_sorted(List** list, int value){
    List* aux = *list;
    List* prev = NULL;
    List* new;

    while((aux != NULL) && (aux->value < value)){
        prev = aux;
        aux = aux->next;     
    }
    new = (List*)malloc(sizeof(List));
    if (new == NULL) exit(1);
    new->value = value;
    if (prev == NULL){
        new->next = *list;
        *list = new;
    }else{
        new->next = prev->next;
        prev->next = new;
    }
    return ;
}

int search_list(List** list, int value){
    List* aux = NULL;
    for (aux = *list; aux != NULL; aux = aux->next){
        if (aux->value == value){
            return TRUE;
        }
    }
    return FALSE;
}

void delete_list(List** list, int value){
    List* prev;
    List* aux = *list;

    while ((aux != NULL) && (aux->value != value)){
        prev = aux;
        aux = aux->next;
    }
    if (prev == NULL){
        *list = aux->next;
    }else{
        prev->next = aux->next;
    }
    free(aux);
    return ;
}

void delete_first_list(List** list){
    List* aux = (List*)malloc(sizeof(List));
    if (aux == NULL) exit(1);
    aux = (*list)->next;
    *list = aux;
    return ;
}


void delete_end_list(List** list){
    List* aux = *list;
    List* prev = NULL;
    while(aux->next != NULL){
        prev = aux;
        aux = aux->next;
    }
    prev->next = NULL;    
    return ;
}

void free_list(List** list){
    free(*list);
    *list = NULL;
}

void print_list(List** list){
    List* aux;
    for (aux = *list; aux != NULL; aux = aux->next){
        printf(" - %d", aux->value);
    }
    return ;
}

