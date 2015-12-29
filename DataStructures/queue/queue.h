#include <stdint.h>

typedef uint32_t T;

typedef struct queueNode{
    struct queueNode* prev;
    struct queueNode* next;
    T data;
} QueueNode;

typedef struct{
    QueueNode* head;
    QueueNode* tail;
    uint32_t size;
} Queue;


void queue_init(Queue* queue);
void queue_destroy(Queue* queue);
void queue_enqueue(Queue* queue, T element);
T queue_dequeue(Queue* queue);
T queue_first(Queue* queue);
int queue_isempty(Queue* queue);
uint32_t queue_size(Queue* queue);
void queue_print(Queue* queue);

