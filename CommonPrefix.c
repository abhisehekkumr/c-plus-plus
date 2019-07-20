#include<stdio.h>
#include<stdio.h>

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
    char str[1000];
    char prefix[100];
    int i=0,k=0,end=0,flag=1,not_prifix = 1,count = 0;

    scanf("%s",&str);
    //scanf("%s",&prefix);
    while(str[i]!=' ')
      prefix[i] = str[i++];
    prefix[i] = '\0';
    end  = i++ -1;
    for(int j=0;j<=end;j++)
      printf("%c",prefix[j]);
      printf("\n");
    while(str[i]!='\0'){
      // checking the prefix and incresing window size
      if(str[i]==prefix[k] && k<=end){
        k++;
        flag = 1;
        count++;
      }
      // if prefix is smaller than given string then set end to the size of the prefix
      else if(str[i]!=' ' && prefix[k]=='\0'){
        if(flag){
          end = k-1;
          k=0;
          count = 0;
          flag = 0;
        }
      }
      // if mismath occurs
      else if(str[i] != ' ' && prefix[k] != '\0'){
        if(flag){
          end = k;
          k=0;
          count = 0;
          flag = 0;
        }
      }
      // prefix is longer then string strig then shrink the prefix
      else if(str[i] == ' ' && prefix[k]!='\0'){
        end = count;
        k = 0;
        flag = 0;
        count = 0;
      }
      // prefix and string is having same length
      else if(str[i] == ' ' && prefix[k] == '\0'){
        end = k-1;
        k=0;
        flag = 0;
        count = 0;
      }

      i++;
    }

    for(int j=0;j<=end;j++)
      printf("%c",prefix[j]);
    printf("\n");
  }
}
