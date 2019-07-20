#include<stdio.h>
#include<math.h>


int check(long long int a,long long int b){
  double base = log(a);
  double number = log(b);

  double result = number/base;

  if(floor(result)==ceil(result))
    return 1;
  return 0;
}

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    long long int a,b;
    scanf("%llu %llu",&a,&b);
    int flag = check(a,b);

    if(flag && a!=1)
      printf("1\n");
    else
      printf("0\n");
  }
}
