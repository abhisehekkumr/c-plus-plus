#include<stdio.h>

int main(){

  int m;
  scanf("%d",&m);

  while(m--){
    long long int number;
    int i=0,flag=0;
    long long int sum;
    scanf("%llu",&number);
    flag = 0;
    sum = 0;
    while(sum<=number){
      sum = 1<<i;
      if(number==sum){
        flag = 1;
        break;
      }
      printf("%llu\n",sum);
      i++;
    }

    if(flag && number!=0)
      printf("Yes\n");
    else
      printf("No\n");
    sum = 0;
    flag = 0;
  }


}
