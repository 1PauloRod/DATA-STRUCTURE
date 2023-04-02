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

int main(void){
    List* l = NULL;
    printf("[1] Insert List;\n");
    insert_list(&l, 1);
    insert_list(&l, 2);
    insert_list(&l, 3);
    insert_list(&l, 4);
    insert_list(&l, 5);
    print_list(&l);
    free_list(&l);
    printf("\n\n");
    
    printf("[2] Insert End List;\n");
    insert_end_list(&l, 1);
    insert_end_list(&l, 2);
    insert_end_list(&l, 3);
    insert_end_list(&l, 4);
    insert_end_list(&l, 5);
    print_list(&l);
    free_list(&l);
    printf("\n\n");

    printf("[3] Insert Sorted List;\n"); 
    insert_sorted(&l, 3);
    insert_sorted(&l, 1);
    insert_sorted(&l, 5);
    insert_sorted(&l, 2);
    insert_sorted(&l, 4);
    print_list(&l);
    printf("\n\n");

    printf("[4] Search value;\n");
    int v;
    printf("Choose value: ");
    scanf("%d", &v);
    int search = search_list(&l, v);
    if (search == TRUE)
        printf("Found value!!\n");
    else
        printf("Value not Found.\n");
    printf("\n");

    printf("[5] Delete value;\n");
    printf("Choose value: ");
    scanf("%d", &v);
    delete_list(&l, v);
    print_list(&l);
    printf("\n\n");

    printf("[6] Delete first value; \n");
    delete_first_list(&l);
    print_list(&l);
    printf("\n\n");

    printf("[7] Delete end value; \n");
    delete_end_list(&l);
    print_list(&l);
    printf("\n\n");

    return 0;
}