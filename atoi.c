#include<stdio.h>
#include<string.h>

long int numberConvert(char str[]){
  int len = strlen(str);
  long int number = 0;
  int minus = 1,i=0;

  if(str[0]=='-'){
    minus = -1;
    i = 1;
  }

  while(i<len){
    if(str[i]>='0' && str[i]<='9')
      number = number*10 + (str[i]-'0');
    else
      return -1;
    i++;
  }
  return number*(long int)minus;
}
int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    char str[10];
    scanf("%s",&str);
    printf("%ld\n",numberConvert(str));
  }
}
