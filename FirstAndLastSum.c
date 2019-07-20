#include<stdio.h>

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    int number;
    scanf("%d",&number);

    int sum = 0,flag = 1;

    while(number>0){

      if (flag) {
        sum += number%10;
        flag = 0;
      }

      number = number/10;

      if(number/10==0){
        sum = sum+ number;
        break;
      }
    }

    printf("%d\n",sum);
  }
}
