#include<stdio.h>

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    char first[1000],second[1000];
    scanf("%s",&first);
    scanf("%s",&second);
    int i=0,k=0,index=0,flag=1,m=0;

    while(first[i]!='\0'){

        if(first[i]==second[k]){
          if(flag)
            index = i;
          flag = 0;
          k++;
        }else{
          k=0;
          flag = 1;
        }

        if(second[k]=='\0'){
          m=1;
          break;
        }

          i++;
    }

    if(m==0)
      printf("%d\n",-1);
    else
      printf("%d\n",index);
  }
}
