#include<stdio.h>

int main(){
  int t;
  scanf("%d",&t);

  while(t!=0){
    int permuation[t+1],inverse[t+1];

    for(int i=1;i<=t;i++)
      scanf("%d",&permuation[i]);

    int flag = 0;

    for(int i=1;i<=t;i++){
      inverse[permuation[i]] = i;

      if(inverse[permuation[i]]!=permuation[permuation[i]])
        flag = 1;
    }

    if(flag)
      printf("not ambiguous\n");
    else
      printf("ambiguous\n");

    scanf("%d",&t);
  }
}
