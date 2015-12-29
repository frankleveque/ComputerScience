#include <stdint.h>

#define DEFAULT_CAPACITY 10
typedef int32_t T;

typedef struct{
    uint32_t capacity;
    int32_t top;
    T* bottom;
} Stack;



void stack_init(Stack* stack);
void stack_destroy(Stack* stack);
void stack_realloc(Stack* stack);
void stack_push(Stack* stack, T num);
T stack_pop(Stack* stack);
T stack_peek(Stack* stack);
int stack_isempty(Stack* stack);
uint32_t stack_size(Stack* stack);
void stack_print(Stack* stack);

