#include<stdio.h>

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    int number,new_number=0;
    scanf("%d",&number);

    while(number>0){
      new_number  = new_number*10 + number%10;
      number = number/10;
    }

    printf("%d\n",new_number);
  }
}
