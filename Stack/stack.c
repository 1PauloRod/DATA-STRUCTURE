#include "stack.h"


Stack* create_stack(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) exit(1);
    stack->top = NULL;
    return stack;
}

void push(Stack* stack, int value){
    List* new = (List*)malloc(sizeof(List));
    if (new == NULL) exit(1);
    new->value = value;
    new->next = stack->top;
    stack->top = new;
    return ;
}

int stack_empty(Stack* stack){
    return (stack->top == NULL);
}


int pop(Stack* stack){
    if (stack_empty(stack)) exit(1);
    List* aux = stack->top;
    int return_value = aux->value;
    stack->top = aux->next;
    return return_value;
}

void free_stack(Stack* stack){
    List* aux;
    List* s = stack->top;
    while(s != NULL){
        aux = s->next;
        free(s);
        s = aux;
    }
    free(stack);
}

void print_stack(Stack* stack){
    List* aux;
    for (aux = stack->top; aux != NULL; aux = aux->next)
        printf("%d - ", aux->value);
    printf("\n");
}

