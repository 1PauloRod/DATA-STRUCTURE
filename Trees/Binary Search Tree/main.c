#include "bst.h"

int main(void){
    Node* t = NULL;
    t = insert(t, 40);
    t = insert(t, 25); 
    t = insert(t, 77); 
    t = insert(t, 15);
    t = insert(t, 8);
    t = insert(t, 33); 
    t = insert(t, 56);
    t = insert(t, 90);
    t = insert(t, 48);
    t = insert(t, 100);
    printf("*****PREORDER*****\n");
    preorder(t);
    printf("\n\n");
    printf("*****POSTORDER*****\n");
    postorder(t);
    printf("\n\n");
    printf("*****INORDER*****\n");
    inorder(t);
    printf("\n\n");
    printf("\n\n");
    printf("search value 56: %p\n", search(t, 56));
    printf("\n\n");
    printf("\n\n");
    printf("\n*****REMOVE VALUE 15*****\n");
    remove_value(&t, 15);
    preorder(t);
    printf("\n\n");
    printf("\n\n");
    int height_tree = height(t);
    printf("height: %d\n", height_tree);
    printf("\n\n");
       
    return 0;
}
