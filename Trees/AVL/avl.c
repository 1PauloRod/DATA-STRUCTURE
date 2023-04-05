#include "avl.h"

Node* insertAVL(Node* t, int value){
    
    if (t == NULL){
        t = (Node*)malloc(sizeof(Node));
        if (t == NULL) return NULL;
        t->value = value;
        t->height = 0;
        t->left = t->right = NULL;
    }else{
        if (value < t->value){
            t->left = insertAVL(t->left, value);
            if (height(t->left) - height(t->right) == 2 || height(t->left) - height(t->right) == -2){
                if (value < t->left->value)
                    return rotateRight(t);
                t->left = rotateLeft(t->left);
                return rotateRight(t); 
            }
            t->height = 1 + greater(height(t->left), height(t->right));
        }else{
            if (value > t->value){
                t->right = insertAVL(t->right, value);
                if (height(t->left) - height(t->right) == 2 || height(t->left) - height(t->right) == -2){
                    if (value > t->right->value)
                        return rotateLeft(t);
                    t->right = rotateRight(t->right);
                    return rotateLeft(t);
                }
                t->height = 1 + greater(height(t->left), height(t->right));
            }else{
                printf("the value %d already exists!\n", value);
            }
        }
    }
    return t;
}


Node* rotateLeft(Node* t){
    Node* aux;
    aux = t->right;
    t->right = aux->left;
    aux->left = t;
    t->height = 1 + greater(height(t->left), height(t->right));
    aux->height = greater(height(aux->right), t->height) + 1;
    return aux;
}

Node* rotateRight(Node* t){
    Node* aux;
    aux = t->left;
    t->left = aux->right;
    aux->right = t;
    t->height = 1 + greater(height(t->left), height(t->right));
    aux->height = greater(height(aux->left), t->height) + 1;
    return aux;
}

Node* searchAVL(Node** t, int value){
    if (t == NULL || (*t)->value == value){
        return (*t);
    }
    if (value > (*t)->value){
        return searchAVL(&(*t)->right, value);
    }
    return searchAVL(&(*t)->left, value);
}

void preorder(Node* t){
    if (t != NULL){
        printf("address: %p - value: %d - left: %p - right: %p\n", t, t->value, t->left, t->right);
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
             printf("address: %p - value: %d - left: %p - right: %p\n", t, t->value, t->left, t->right);
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
         printf("address: %p - value: %d - left: %p - right: %p\n", t, t->value, t->left, t->right);
    }
}

int greater(int a, int b){
    if (a > b) return a;
    return b;
}

int height(Node* t){
    if (t == NULL)
        return -1;
    return t->height;
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

Node* removeAVL(Node** t, int value){
    if ((*t) == NULL)
        return (*t);
    else{
        if (value < (*t)->value){
            (*t)->left = removeAVL(&(*t)->left, value);
             if (height((*t)->left) - height((*t)->right) == 2 || height((*t)->left) - height((*t)->right) == -2){
                if (value < (*t)->left->value)
                    return rotateRight((*t));
                (*t)->left = rotateLeft((*t)->left);
                return rotateRight((*t));
            }
        (*t)->height = greater(height((*t)->left), height((*t)->right)) + 1;
        }
        else if (value > (*t)->value){
            (*t)->right = removeAVL(&(*t)->right, value);
            if (height((*t)->left) - height((*t)->right) == 2 || height((*t)->left) - height((*t)->right) == -2){
                if (value > (*t)->right->value)
                    return rotateLeft(*t);
                (*t)->right = rotateRight((*t)->right);
                return rotateLeft((*t));
            }
            (*t)->height = greater(height((*t)->left), height((*t)->right)) + 1;
        }
        else{
            Node* aux;
            if ((*t)->left == NULL){
                aux = (*t);
                (*t) = (*t)->right;
                free(aux);
            }else if ((*t)->right == NULL){
                aux = (*t);
                (*t) = (*t)->left;
                free(aux);
            }else{
                (*t)->value = lower_left(&(*t)->right);
            }
        }
    }
    return *t;
}