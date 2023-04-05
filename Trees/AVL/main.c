#include "avl.h"


int main(void){
    Node* t = NULL;
    t = insertAVL(t, 30);
    t = insertAVL(t, 50);
    t = insertAVL(t, 70);
    t = insertAVL(t, 60);
    t = insertAVL(t, 80);
    t = insertAVL(t, 40);
    t = insertAVL(t, 20);
    t = insertAVL(t, 10);
    t = insertAVL(t, 5);
    t = insertAVL(t, 35);
    t = insertAVL(t, 55);
    t = insertAVL(t, 1);
    preorder(t);
    printf("\n");
    Node* search = searchAVL(&t, 50);
    if(search != NULL)
        printf("valor: %d found! %p\n", search->value, search);
    else
        printf("value not found. =/\n");

    printf("\n\n");
    int heightAVL = height(t);
    printf("height: %d\n", heightAVL);
    printf("\n\n");

     printf("\n*****REMOVE VALUE 60*****\n");
    Node* remove = removeAVL(&t, 60);
    preorder(remove);

    return 0;
}