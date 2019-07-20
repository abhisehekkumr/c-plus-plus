#include<stdio.h>

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    int n,first=0,second=0,number;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      scanf("%d",&number);

      if(number>first){
        second = first;
        first = number;
      }else if(number<first && number>second)
        second = number;

    }

    printf("%d\n",second);
  }
}
