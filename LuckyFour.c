#include<stdio.h>

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    int count=0;
    int number;
    scanf("%d",&number);

    if(number<0)
      number = number*-1;
      
    while(number>0){
      if(number%10==4)
        count++;
      number = number/10;
    }

    printf("%d\n",count);
  }
}
