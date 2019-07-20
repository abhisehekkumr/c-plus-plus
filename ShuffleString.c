#include<stdio.h>
#include<string.h>
int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    char a[100];
    char b[100];
    scanf("%s",&a);
    scanf("%s",&b);

    int k=0,len,flag=0,count=0;
    len = strlen(a);

    if(a[0]==b[len-2] && a[1]==b[len-1])
      printf("1\n");
    else if(b[0]==a[len-2] && b[1]==a[len-1])
        printf("1\n");
    else
      printf("0\n");
  }
}
