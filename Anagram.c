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

    int  a_length = strlen(a);
    int  b_length = strlen(b);

    int a_array[26]={0},b_array[26]={0},flag=0;

    for(int i=0;i<a_length;i++){
      a_array[a[i]-'a']++;
      //printf("%c",a[i]);
    }

      for(int i=0;i<b_length;i++)
        b_array[b[i]-'a']++;

        for(int i=0;i<26;i++){
          //printf("%d %d\n",a_array[i],b_array[i]);
          if(a_array[i]!=b_array[i]){
            flag = 1;
            //break;
          }
        }

        if(flag)
          printf("NO\n");
        else
          printf("YES\n");
  }
}
