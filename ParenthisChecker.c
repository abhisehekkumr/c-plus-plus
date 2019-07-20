// this program is full fucntioning except one test case where (){} simultenously appears
// we have to determine different logic

#include<stdio.h>
#include<stdlib.h>

struct Stack {
  int top;
  unsigned int capacity;
  int *array;
};

struct Stack *createStack(int size){
  struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
  if(!stack)
    return NULL;
  stack->top = -1;
  stack->capacity = size;
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
  int t;
  scanf("%d",&t);

  while(t--){
    struct Stack *stack = createStack(100);
    char str[100];
    scanf("%s",&str);

    int i=0;
    while(str[i]!='\0'){
      if(str[i]==')' || str[i]==']' || str[i]== '}'){
        push(stack,(int) str[i]);
      //  printf("%c ",str[i]);
      }
      i++;
    }

    /*  i=0;
    while(str[i]!='\0'){
      int m =  pop(stack);
        printf("%c ",(char) m);
      i++;
    }*/
      i=0;
      int flag = 0;
    while(str[i]!='\0'){

      if((str[i]=='(' || str[i]=='[' || str[i] == '{')){
        char m = (char) pop(stack);
        char n = str[i];
      //  printf("m = %c ",m);
      //  printf("n = %c \n",n);

        if(n == '(' && m != ')'){
        //  printf("Yahoo 1\n");
          flag = 1;
          break;
        }
        else if(n == '[' && m != ']'){
        //  printf("Yahoo 2 \n");
          flag = 1;
          break;
        }
        else if(n == '{' && m != '}'){
        //  printf("Yahoo 3\n");
          flag = 1;
          break;
        }
      }
      i++;
    //  printf("%c ",pop(stack));
  }

    if(flag)
      printf("not balanced\n");
    else
      printf("balanced\n");
  }
}
