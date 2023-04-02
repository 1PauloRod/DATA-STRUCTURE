#include <stdio.h>
#include <stdlib.h>
#include "../Linked List/linkedList.h"

struct stack{
    List* top;
}; typedef struct stack Stack;


Stack* create_stack();
void push(Stack* stack, int value);
int pop(Stack* stack);
int empty_stack(Stack* stack); 
void free_stack(Stack* stack);
void print_stack(Stack* stack);