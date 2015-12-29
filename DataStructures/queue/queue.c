#include "queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void queue_init(Queue* queue)
{
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
}

void queue_destroy(Queue* queue)
{
    QueueNode* front = queue->head;

    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;
    while(front){
        QueueNode* old = front;
        front = front->next;

        old->prev = NULL;
        old->next = NULL;
        free(old);
        old = NULL;
    }
}

void queue_enqueue(Queue* queue, T element)
{

    QueueNode* new_node = malloc(sizeof(QueueNode));
    new_node->data = element;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(!queue->head){
        queue->head = new_node;
        queue->tail = queue->head;

    } else{
        new_node->prev = queue->tail;
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
    queue->size++;
}

T queue_dequeue(Queue* queue)
{
    assert(queue->head);
    T data = queue->head->data;
    QueueNode* old = queue->head;
    queue->head = queue->head->next;
    free(old);
    queue->size--;
    return data;
}

T queue_first(Queue* queue)
{
    return queue->head->data; 
}

int queue_isempty(Queue* queue)
{
    return queue->size == 0;
}

uint32_t queue_size(Queue* queue)
{
    return queue->size;
}

void queue_print(Queue* queue)
{
    if(queue->size){
        QueueNode* current = queue->head;
        printf("Queue Contents: ");
        while(current){
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    } else{
        printf("Queue is empty.\n");
    }
}

