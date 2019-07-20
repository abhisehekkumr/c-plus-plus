#include<stdio.h>

void swap(char *a, char *b){
  char temp = *a;
  *a = *b;
  *b = temp;
}

void permute(char *a,int i,int n){
  if (i == n){
    printf("%s ", a);
    //printf("\n");
  }
  else{
        int j;
        for(j=i;j<=n;j++){
          swap((a+i),(a+j));
          permute(a,i+1,n);
          swap((a+i),(a+j));
        }
  }
}

/*void permute(char *a, int l, int r)
{
   int i;
   if (l == r){
     printf("%s ", a);
     printf("\n");
   }
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
}*/

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    char str[6];
    scanf("%s",&str);

    int i=0,count=0;
    while(str[i++]!='\0')
      count++;
      //printf("%d",count);

    for(int i=0;i<count;i++){
      char v = str[i];
      int j = i;

      while(str[j-1]>v && j>=1){
        str[j] = str[j-1];
        j--;
      }

      str[j] = v;
    }
  //  printf("%s\n",str);
    permute(str,0,count-1);
  }
}
