#include<stdio.h>
#include<stdlib.h>

struct Stack {
  int top;
  unsigned int capacity;
  int *array;
};

struct Stack *createStack(int capacity){
  struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
  if(!stack)
    return NULL;

  stack->top = -1;
  stack->capacity = capacity;
  stack->array = (int *)malloc(stack->capacity*sizeof(int));
  return stack;
}

int isFull(struct Stack *stack){
  return stack->top == stack->capacity-1;
}

int isEmpty(struct Stack *stack){
  return stack->top == -1;
}

void push(struct Stack *stack,int element){
  if(isFull(stack))
    return;
  stack->array[++stack->top] = element;
}

int pop(struct Stack *stack){
  if(isEmpty(stack))
    return -1;
  return stack->array[stack->top--];
}


int main(){
  struct Stack *stack = createStack(10);

  for(int i=0;i<10;i++)
    push(stack,i);

  for(int i=0;i<10;i++)
    printf("%d ",pop(stack));

  printf("%d ",pop(stack));
}
