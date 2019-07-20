#include<stdio.h>

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    int n;
    scanf("%d",&n);
    int array[n];
    scanf("%d",&array[0]);
    int element = array[0];
    for(int i=1;i<n;i++){
      scanf("%d",&array[i]);
      element  = element ^ array[i];
    }

    printf("%d\n",element);
  }
}
