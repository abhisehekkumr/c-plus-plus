#include<stdio.h>

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    int num,n;
    scanf("%d",&num);
    n = num;
    int number = 0;

    while(n>0){
      number = number*10 + n%10;
      n = n/10;
    }

    if(num == number)
      printf("wins\n");
    else
      printf("losses\n");
  }
}
