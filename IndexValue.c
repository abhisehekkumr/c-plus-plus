#include<stdio.h>

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    int n;
    scanf("%d",&n);

    int element=0,count=0;

    for(int i=1;i<=n;i++){
      scanf("%d",&element);

      if(element==i){
        printf("%d ",element);
        count++;
      }
    }
    if(count==0)
      printf("Not Found\n");
    printf("\n");
  }
}
