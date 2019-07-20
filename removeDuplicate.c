#include<stdio.h>
#include<string.h>

char* removeDup(char * str, int n)
{
    int len = strlen(str);
    int k = 0,i=0;

    for ( i=1; i< len; i++)
    {

        if (str[i-1] != str[i])
            str[k++] = str[i-1];
        else
            while (str[i-1] == str[i])
                i++;
    }
    str[k++] = str[i-1];
    str[k] =  '\0';
    if (k != n)
        removeDup(str, k);
    else
      return str;
}

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    char str[50];

    scanf("%s",&str);

    printf("%s",removeDup(str,strlen(str)));
    printf("\n");
  }
}
