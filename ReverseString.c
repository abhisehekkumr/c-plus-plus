#include<stdio.h>


void reverse(char str[],char reverse_string[],int first,int second,int size,int flag){
  if(flag){
    int window_size = second -first+1;
    int ending = size-first-1;
    int starting = ending-window_size;

    for(int i=starting+1;i<=ending;i++)
      reverse_string[i] = str[first++];
  }else{
    int window_size = second-first+1;
    int ending = size-first-1;
    int starting = 0;

    for(int i=starting;i<=ending;i++)
      reverse_string[i] = str[first++];
      int f=0;
    for(int i=0;i<size-1;i++){

        if(f==0 && i==ending+1){
          printf(".");
          f =1;
          i--;
        }else
          printf("%c",reverse_string[i]);
    }

  }

  // reverse_string[ending+1] = '.';
}

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    char str[2000];

    scanf("%s",&str);

    int i=0,first=0,easy=0;
    int count=0;
    while(str[i++]!='\0'){

      if(str[i]=='.')
        easy = 1;
      count++;
    }

  if(easy){
    char reverse_string[count];
    i=1;
    while(str[i]!='\0'){
      if(str[i]=='.'){
        reverse(str,reverse_string,first,i,count,1);
        first = i+1;
      }
      i++;
      if(str[i]=='\0'){
        reverse(str,reverse_string,first,i,count,0);
      }
    }
  }else{
    int j=0;
    while(str[j]!='\0')
      printf("%c",str[j++]);
  }
    printf("\n");
  }
}
