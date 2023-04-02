#include "queue.h"

int main(void){
    printf("Create queue\n");
    Queue* queue = create_queue();
    printf("Push values on queue: ");
    queue_push(queue, 1);
    queue_push(queue, 2);
    queue_push(queue, 3);
    queue_push(queue, 4);
    queue_push(queue, 5);
    queue_push(queue, 6);
    queue_print(queue); 
    printf("Pop value on queue: ");
    queue_pop(queue);
    queue_print(queue);
    clean_queue(queue);
    return 0;
}
