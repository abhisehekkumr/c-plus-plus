#include<stdio.h>

int main(){
    int t;
    scanf("%d",&t);

    while(t--){
      char str[100];

      scanf("%s",str);
      int i=0,count=0,index,flag=0;

      if(str[0]=='\0')
        index = -1;
      else{
           while(str[i]!='\0'){
        count++;

        if(str[i]=='1'){
          index = count -1;
          flag = 1;
        }
         i++;
      }
      }

      if(flag)
        printf("%d\n",index);
      else
        printf("-1\n");
    }
}
