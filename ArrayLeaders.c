#include<stdio.h>

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    int n;
    scanf("%d",&n);

    int array[n],int max=0,arr[n],k=0;
    for(int i=0;i<n;i++)
      scanf("%d",&array[i]);

    arr[k++] = array[n-1];
    max = array[n-1];
    for(int i=n-2;i>=0;i--){

        if(array[i]>max){
          max = array[i];
          arr[k++] = array[i];
        }

    }

    for(int i=0;i<=k;i++)
      printf("%d ",arr[i]);
  }
}
