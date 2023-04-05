#include "bst.h"


Node* insert(Node* t, int value){
    if (t == NULL){
        t = (Node*)malloc(sizeof(Node));
        if (t == NULL) return NULL;
        t->value = value; 
        t->left = NULL;
        t->right = NULL;
    }

    if (value < t->value){
        t->left = insert(t->left, value);
        t->left->father = t;
    }else if (value > t->value){
        t->right = insert(t->right, value);
        t->right->father = t;
    }
    return t;
}

void preorder(Node* t){
    if (t != NULL){
        printf("address: %p - value: %d - left: %p - right: %p - father: %p\n", t, t->value, t->left, t->right, t->father);
        if (t->left != NULL)
            preorder(t->left);
        if (t->right != NULL)
            preorder(t->right);
    }
}

void inorder(Node* t){
    if (t != NULL){
        if (t->left != NULL)
            inorder(t->left);
             printf("address: %p - value: %d - left: %p - right: %p - father: %p\n", t, t->value, t->left, t->right, t->father);
        if (t->right != NULL)
            inorder(t->right);
    }
}

void postorder(Node* t){
    if (t != NULL){
        if (t->left != NULL)
            postorder(t->left);
        if (t->right != NULL)
            postorder(t->right);
         printf("address: %p - value: %d - left: %p - right: %p - father: %p\n", t, t->value, t->left, t->right, t->father);
    }
}

Node* search(Node* t, int value){
    if (t == NULL || t->value == value){
        return t;
    }
    if (value > t->value){
        return search(t->right, value);
    }
    return search(t->left, value);
}

int lower_left(Node** t){
    Node* aux;
    int min;
    if ((*t)->left == NULL){
        min = (*t)->value;
        aux = (*t);
        (*t) = (*t)->right;
        free(aux);
        return min;
    }
    return lower_left(&(*t)->left);
}

int bigger_right(Node** t){
    Node* aux;
    int max;
    if ((*t)->right == NULL){
        max = (*t)->value;
        aux = (*t);
        (*t) = (*t)->left;
        free(aux);
        return (max);
    }
    return bigger_right(&(*t)->right);
}

void remove_value(Node** t, int value){
    Node* aux;
    if (value < (*t)->value){
        remove_value(&(*t)->left, value);
    }else if (value > (*t)->value){
        remove_value(&(*t)->right, value);
    }else{
        if ((*t)->left == NULL){
            aux = (*t);
            (*t) = (*t)->right;
            free(aux);
        }

        if ((*t)->right == NULL){
            aux = (*t);
            (*t) = (*t)->left;
            free(aux);
        }else{
            (*t)->value = lower_left(&(*t)->right);
        }
    }
}

int greater(int a, int b){
    if (a > b) return a;
    return b;
}

int height(Node* t){
    if (t == NULL || (t->left == NULL && t->right == NULL)){
        return 0;
    }
    t->height = 1 + greater(height(t->left), height(t->right));
    return 1 + greater(height(t->left), height(t->right));
}


