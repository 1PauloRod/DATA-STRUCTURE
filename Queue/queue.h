#include "../Linked List/linkedList.h"
#include <stdio.h>
#include <stdlib.h>


struct queue{
    List* front;
    List* rear;
}; typedef struct queue Queue;


Queue* create_queue(void);
void queue_push(Queue* queue, int value);
int queue_pop(Queue* queue);
int queue_empty();
void queue_print(Queue* queue);
void clean_queue(Queue* queue);