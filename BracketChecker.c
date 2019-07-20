#include<stdio.h>
#include<stdlib.h>

struct Stack {
  int top;
  unsigned int capacity;
  char *array;
};

struct Stack *createStack(int size){
  struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
  if(!stack)
    return NULL;
  stack->top = -1;
  stack->capacity = size;
  stack->array = (char *)malloc(stack->capacity*sizeof(char));
  return stack;
}

int isFull(struct Stack *stack){
  return stack->top == stack->capacity-1;
}

int isEmpty(struct Stack *stack){
  return stack->top == -1;
}

void push(struct Stack *stack,char element){
  if(isFull(stack))
    return;
  stack->array[++stack->top] = element;
}

char pop(struct Stack *stack){
  if(isEmpty(stack))
    return -1;
  return stack->array[stack->top--];
}

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    struct Stack *stack =createStack(100);
    char str[100];
    scanf("%s",&str);

    int i=0,flag=0;
    while(str[i]!='\0'){

      if(str[i] == '(' || str[i] == '{' || str[i] == '[')
        push(stack,str[i]);

      if(str[i] == ')' || str[i] == '}' || str[i] == ']'){

          if(isFull(stack)){
            flag = 1;
            break;
          }
          signed char bracket  = pop(stack);

          if((int) bracket==-1){
            flag = -1;
            break;
          }
            if(str[i] == ')' && bracket != '('){
              flag = 1;
              break;
            }
            else if(str[i] == '}' && bracket != '{'){
              flag = 1;
              break;
            }
            else if(str[i] == ']' && bracket != '['){
              flag = 1;
              break;
            }
      }
      i++;
    }

  //  printf("%d empty stack",isEmpty(stack));
    if(!isEmpty(stack))
      printf("not balanced\n");
    else{
      if(flag)
        printf("not balanced\n");
      else
        printf("balanced\n");
    }
  }
}
