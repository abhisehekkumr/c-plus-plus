#include<stdio.h>
#include<string.h>

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    char str[10000];
    int c[26] = {0},abhi;
    scanf("%s",&str);
    int size,start=0,max=1,end=0;
    size = strlen(str);

    memset(c,-1,sizeof(c));
    for(int i=0;i<size;i++){

      if(c[str[i]-'a']==-1){
        c[str[i]-'a'] = i;
        end++;
      }else {
        if(c[str[i]-'a']<start){
          c[str[i]-'a'] = i;
          end++;
          //printf("%d %d\n",start,end);
        }else{
          start = c[str[i]-'a']+1;
          c[str[i]-'a'] = i;
          end++;
        }
      }

        max = (max>(end-start))?max:(end-start);
    }

    printf("%d\n",max);
  }
}
