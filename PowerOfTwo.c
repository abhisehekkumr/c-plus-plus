#include<stdio.h>
#include<math.h>

int power(long int number){
  if(ceil(log2(number))==floor(log2(number)))
    return 1;
  return 0;

}
int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    long int number;
    scanf("%lu",&number);

    long sum = 0;
    int flag = power(number);

    if(flag && number!=0)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
