#include <stdio.h>
#include <stdlib.h>


struct node{
    int value;
    int height;
    struct node* left;
    struct node* right;
    struct node* father;
}; typedef struct node Node;

Node* insert(Node* t, int value);
void preorder(Node* t);
void inorder(Node* t);
void postorder(Node* t);
Node* search(Node* t, int value);
int lower_left(Node** t);
int bigger_right(Node** t);
void remove_value(Node** t, int value);
int greater(int a, int b);
int height(Node* t);