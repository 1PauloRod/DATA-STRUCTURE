#include "queue.h"

Queue* create_queue(void){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) exit(1);
    queue->front = queue->rear = NULL;
    return queue;
}

int queue_empty(Queue* queue){ 
    return (queue->front == NULL);
}

void queue_push(Queue* queue, int value){
    List* element = (List*)malloc(sizeof(List));
    if (element == NULL) exit(1);
    element->value = value;
    element->next = NULL;
    if (queue_empty(queue)) 
        queue->front = queue->rear = element; 
    else 
        queue->rear->next = element;
    queue->rear = element;
    return ;
}

int queue_pop(Queue* queue){
    int return_value;
    List* element;
    if (queue_empty(queue)) exit(1);
    element = queue->front;
    return_value = element->value;
    queue->front = element->next;
    if (queue->front == NULL){
        queue->rear = NULL;
    }
    free(element);
    return return_value;
}

void queue_print(Queue* queue){
    List* t = NULL;
    for (t = queue->front; t != NULL; t = t->next)
        printf("%d  - ", t->value);
    printf("\n"); 

}

void clean_queue(Queue* queue){
    List* q = queue->front;
    List* aux;
    while(q != NULL){
        aux = q->next;
        free(q);
        q = aux;
    }
    free(queue);
}