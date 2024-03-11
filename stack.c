// Implement a Stack data structure (FILO) using a dinamically allocated array
// Implements the following operations: 
// new, push, pop, is_empty, is_full, peek, destroy

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
  int *elements;
  int size;
  int capacity;
} Stack;

Stack *stack_new(int capacity) {
  Stack *stack = malloc(sizeof(Stack));
  stack->elements = malloc(capacity * sizeof(int *));
  stack->capacity = capacity;
  stack->size = 0;

  return stack;
}

bool is_stack_empty(Stack *stack) {
  return stack->size == 0;
}

bool is_stack_full(Stack *stack) {
  return stack->size == stack->capacity;
}

Stack *stack_push(Stack *stack, int element) {
  if(is_stack_full(stack)) return stack;
  
  stack->elements[stack->size] = element;
  stack->size++;

  return stack;
}

// Pass by pointer
bool stack_pop(Stack *stack, int *element) {
  if(is_stack_empty(stack)) return false;
  
  stack->size--;
  *element = stack->elements[stack->size];
  
  return true;
}

// Pass by pointer
bool stack_peek(Stack *stack, int *element) {
  if(is_stack_empty(stack)) return false;

  *element = stack->elements[stack->size - 1];

  return true;
}

void stack_print(char *name, Stack *stack) {
  printf("%s: {", name);
  for(int i = stack->size - 1; i >= 0; i--) {
    i != 0 ? printf("%d, ", stack->elements[i]) : printf("%d", stack->elements[i]);
  }
  printf("}\n");
}

int main() {
  Stack *stack = stack_new(5);
  
  printf("Stack is empty? %s\n", is_stack_empty(stack) ? "true" : "false");

  stack_push(stack, 1);
  stack_push(stack, 2);
  stack_push(stack, 3);
  stack_push(stack, 4);
  stack_push(stack, 5);
  stack_print("Stack after pushing", stack);

  int elem = 0;
  stack_pop(stack, &elem);
  printf("Popped: %d\n", elem);
  stack_pop(stack, &elem);
  printf("Popped: %d\n", elem);
  stack_print("Stack after popping", stack);

  stack_peek(stack, &elem);
  printf("Peek: %d\n", elem);
  stack_print("Stack after peeking", stack);
  return 0;
}