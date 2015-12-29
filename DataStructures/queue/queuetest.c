#include "queue.h"
#include <stdio.h>
#include <assert.h>

int main()
{
    Queue myQueue;
    queue_init(&myQueue);
    assert(queue_isempty(&myQueue));
    queue_enqueue(&myQueue, 9);
    assert(!queue_isempty(&myQueue));
    printf("%d is top\n", queue_first(&myQueue));
    queue_enqueue(&myQueue, 1);
    queue_enqueue(&myQueue, 2);
    queue_enqueue(&myQueue, 3);
    queue_enqueue(&myQueue, 4);
    queue_enqueue(&myQueue, 5);
    queue_enqueue(&myQueue, 6);
    queue_enqueue(&myQueue, 7);
    queue_print(&myQueue);
    printf("%d dequeued\n", queue_dequeue(&myQueue));
    printf("%d dequeued\n", queue_dequeue(&myQueue));
    printf("%d dequeued\n", queue_dequeue(&myQueue));
    printf("%d dequeued\n", queue_dequeue(&myQueue));
    queue_print(&myQueue);
    
    queue_destroy(&myQueue);
    queue_print(&myQueue);
}
