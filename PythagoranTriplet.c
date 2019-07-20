#include<stdio.h>

int main(){
    int t;
    scanf("%d",&t);

    while(t--){

        int n;
        scanf("%d",&n);
        int number,array[n];

        for(int i=0;i<n;i++){
          scanf("%d",&number);
          array[i] = number*number;
        }

        for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
            if(array[i]>array[j]){
              int temp = array[i];
              array[i] = array[j];
              array[j]  = temp;
            }
          }
        }

      int flag = 0;

      for(int i=0;i<n;i++){
        flag = 0;

        for(int j=i+1;j<n;j++){

            flag = 0;
            for(int k=j+1;k<n;k++){

                if(array[i] == array[j]+array[k]){
                  flag = 1;
                  break;
                }
            }

            if(flag)
              break;
        }

        if(flag)
          break;
      }

      if(flag)
        printf("Yes\n");
      else
        printf("No\n");
    }
}
