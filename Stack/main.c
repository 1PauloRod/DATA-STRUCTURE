#include "stack.h"

int main(void){
    Stack* stack = NULL;
    printf("Create a stack\n");
    stack = create_stack();
    printf("Push values on stack: ");
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    print_stack(stack);
    printf("Pop value on stack: ");
    pop(stack);
    print_stack(stack);
    free_stack(stack);
    return 0;
}