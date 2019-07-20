#include<stdio.h>
#include<math.h>

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    int number,flag=0;
    scanf("%d",&number);

    if(number<0)
      number = number*-1;
    int num = (int)sqrt((double)number);

    for(int i=2;i<=num;i++){
      if(number%i==0){
        flag=1;
        break;
      }
    }


      if(flag>=1)
        printf("No\n");
      else
        printf("Yes\n");

  }
}
