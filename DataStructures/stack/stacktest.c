#include "stack.h"
#include <stdio.h>

int main()
{
    Stack myStack;
    stack_init(&myStack);
    stack_push(&myStack, 0);
    stack_push(&myStack, 1);
    stack_push(&myStack, 2);
    stack_push(&myStack, 3);
    stack_push(&myStack, 4);
    stack_push(&myStack, 5);
    stack_push(&myStack, 6);
    stack_push(&myStack, 7);
    stack_push(&myStack, 8);
    stack_push(&myStack, 9);
    stack_push(&myStack, 10);
    stack_push(&myStack, 11);
    stack_push(&myStack, 12);
    stack_push(&myStack, 13);
    stack_push(&myStack, 14);
    stack_push(&myStack, 15);
    stack_push(&myStack, 16);
    stack_push(&myStack, 17);
    stack_print(&myStack);

    printf("%d popped\n", stack_pop(&myStack));
    printf("%d popped\n", stack_pop(&myStack));
    printf("%d popped\n", stack_pop(&myStack));
    printf("%d popped\n", stack_pop(&myStack));
    printf("%d popped\n", stack_pop(&myStack));
    printf("%d popped\n", stack_pop(&myStack));
    printf("%d popped\n", stack_pop(&myStack));
    printf("%d popped\n", stack_pop(&myStack));
    stack_print(&myStack);


    stack_destroy(&myStack);
    printf("Stack Destroyed\n");
    stack_print(&myStack);



return 0;
}
