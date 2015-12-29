#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void stack_init(Stack* stack)
{
    stack->top = -1;
    stack->capacity = DEFAULT_CAPACITY;
    stack->bottom = malloc(sizeof(T) * stack->capacity);
}

void stack_destroy(Stack* stack)
{
    stack->capacity = 0;
    stack->top = -1;
    free(stack->bottom);
    stack->bottom = NULL;
}

void stack_realloc(Stack* stack)
{
    if(stack->top == stack->capacity - 1){
        stack->capacity *= 2;
        stack->bottom = realloc(stack->bottom, sizeof(T) * stack->capacity);
    }
}

void stack_push(Stack* stack, T num)
{
    stack->top++;
    stack->bottom[stack->top] = num;
    stack_realloc(stack);
}

T stack_pop(Stack* stack)
{
    assert(stack->top > 0);

    T val = stack->bottom[stack->top];
    --(stack->top);
    return val;
}

T stack_peek(Stack* stack)
{
    return stack->bottom[stack->top];
}

int stack_isempty(Stack* stack)
{
    return (stack->top) == 0;
}

uint32_t stack_size(Stack* stack)
{
    return stack->top;
}

void stack_print(Stack* stack)
{
    if(stack->bottom){
        printf("Stack Contents: ");
        for(int32_t i=stack->top; i>=0; --i)
            printf("%d ", stack->bottom[i]);
        printf("\n");   
    } else{
        printf("Can't print uninitialized stack.\n");
    }
}

