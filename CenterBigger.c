// this is function but in cannot working over one test case where total elements are 98 the effient solution
// is given in the CenterBiggerEfficient.c i hope you will get that logic

#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);

    while(t--){
      int n;
      scanf("%d",&n);

      int array[n],j;

      for(int i=0;i<n;i++)
        scanf("%d",&array[i]);

     // int temp=0;
      for(int i=0;i<n;i++){
        j = i+1;

        if(i==n-1)
          break;

        if(array[i]>array[j]){
          int temp = array[i];
          array[i] = array[j];
          array[j] = temp;
        }

        if(array[j]<array[j+1]){
          int temp = array[j];
          array[j] = array[j+1];
          array[j+1] = temp;
        }

        i = j;
        j = i+1;
      }

      for(int i=0;i<n;i++)
        printf("%d ",array[i]);
      printf("\n");
    }
}
