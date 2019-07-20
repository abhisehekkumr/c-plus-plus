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

      for(int i=0;i<n;i++){
          int v = array[i];
          int j = i;

          while(array[j-1]>v && j>=1){
              array[j] = array[j-1];
              j--;
          }
          array[j] = v;
      }

    if(n==1)
      printf("%d\n",array[0]);
    else if(n==2)
      printf("%d\n",array[0]*array[1]);
    else
      printf("%d\n",array[n-1]*array[n-2]);
  }
}
