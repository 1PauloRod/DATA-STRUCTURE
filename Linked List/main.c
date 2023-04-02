#include "linkedList.h"


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