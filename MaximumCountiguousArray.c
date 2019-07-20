#include<stdio.h>

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    int n,k;
    scanf("%d %d",&n,&k);

    int array[n],index=0,max=0;

    for(int i=0;i<n;i++)
      scanf("%d",&array[i]);

    for(int i=0;i<n;i++){

      if(max<array[i])
        max = array[i];
      ++index;

      if(index == k){
        printf("%d ",max);
        index = 0;
        max = array[i-k+2];
        i = i-k+1;
      }
    }

    printf("\n");
  }
}
