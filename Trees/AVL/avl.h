#include <stdio.h>
#include <stdlib.h>


struct node{
    int value;
    int height;
    struct node* left;
    struct node* right;
};typedef struct node Node;


Node* insertAVL(Node* t, int value);
Node* rotateLeft(Node* t);
Node* rotateRight(Node* t);
Node* searchAVL(Node** t, int value);
void preorder(Node* t);
void inorder(Node* t);
void postorder(Node* t);
int greater(int a, int b); 
int height(Node* t);
int lower_left(Node** t);
int bigger_right(Node** t);
Node* removeAVL(Node** t, int value);
