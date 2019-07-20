#include<stdio.h>

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    int n;
    scanf("%d",&n);
    long long int fact=1;

    for(int i=2;i<=n;i++)
      fact = fact*(long long int)i;
    printf("%llu\n",fact);
  }
}
