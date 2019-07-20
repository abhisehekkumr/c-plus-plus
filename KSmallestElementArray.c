#include<stdio.h>

int main(){
  int t;
  scanf("%d",&t);

  while(t--){

      int n,k;
      scanf("%d",&n);
      int array[n];

      for(int i=0;i<n;i++)
        scanf("%d",&array[i]);

      scanf("%d",&k);

      for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){

              int temp = 0;
              if(array[i]<array[j]){
                  temp = array[i];
                  array[i] = array[j];
                  array[j] = temp;
              }
          }
      }

      int smallest = n-k;
      printf("%d\n",array[smallest]);
  }
}
