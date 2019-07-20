#include<stdio.h>

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    int n;
    scanf("%d",&n);

    int array[n];
    for(int i=0;i<n;i++)
      scanf("%d",&array[i]);

    int first=0,second=0,element,flag = 1;
    scanf("%d",&element);

    for(int i=0;i<n;i++){

      if(element == array[i]){

        if(flag){
          first = i;
          flag  = 0;
        }else
          second = i;
      }
    }

    if(first!=0 && second==0){
        second = first;
        printf("%d %d",first,second);
    }else if(second==0 && first==0)
        printf("-1\n");
    else
        printf("%d %d\n",first,second);
  }
}
