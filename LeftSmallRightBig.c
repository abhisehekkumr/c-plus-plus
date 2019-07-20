

#include<stdio.h>

int main(){
    int t;
    scanf("%d",&t);

    while(t--){
        int n;
        scanf("%d",&n);

        int array[n];

        for(int i=0;i<n;i++)
          scanf("%d",&array[i]);

        int flag = 1,number=-1;

        for(int i=1;i<n-1;i++){

              for(int j=0;j<i;j++){

                    if(array[j]>array[i]){
                      flag = 0;
                      break;
                    }
              }


            if(flag==1){

              for(int k=i+1;k<n;k++){

                    if(array[k]<array[i]){
                      flag = 0;
                      break;
                    }
            }
            }

              if(flag){
                number = array[i];
                break;
              }else
                flag = 1;
        }

        printf("%d\n",number);
    }
}
