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

    int flag=1;

    for(int i=0;i<n-1;i++){

      if(flag==1){
        if(array[i]>array[i+1]){
          int temp = array[i];
          array[i] = array[i+1];
          array[i+1] = temp;
        }

        flag = 0;
      }else {
        if(array[i]<array[i+1]){
          int temp = array[i];
          array[i] = array[i+1];
          array[i+1] = temp;
        }

        flag = 1;
      }
    }

    for(int i=0;i<n;i++)
      printf("%d ",array[i]);
    printf("\n");
  }
}
