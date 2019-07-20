#include<stdio.h>

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    int a,b;
    scanf("%d %d",&a,&b);
    int small = (a>b)?a:b;

    printf("%d %d\n",small,(a+b));
  }
}
