#include<stdio.h>

int main(){

      int t;
      scanf("%d",&t);

      while(t--){

            int n;
            scanf("%d",&n);
            int days[n];

            for(int i=0;i<n;i++)
              scanf("%d",&days[i]);

            int small = days[0],index=0;

            for(int i=1;i<n;i++){
                if(days[i]<small){
                  small = days[i];
                  index = i;
                  break;
                }
            }

            int flag = 1,count=0;
            for(int i=0;i<n;i++){

                if(flag && days[i]<days[i+1] && i!=n-1){
                  printf("(%d ",i);
                  flag = 0;
                  count++;
                }
                else if(flag==0 && days[i]>days[i+1]){
                    printf("%d) ",i);
                    flag = 1;
                }else if(flag==0 && i==n-1 && days[i]>days[i-1])
                  printf("%d)",i);
                else if(flag==0 && i==n-1 && days[i]<days[i+1])
                  printf("No Profit\n");
                else if(count==0 && flag==1 && i == n-1)
                    printf("No Profit");

            }

            printf("\n");
      }
}
