#include<stdio.h>

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    int n;
    scanf("%d",&n);

    if(n<10)
      printf("What an obedient servant you are!\n");
    else
      printf("-1\n");
  }
}
