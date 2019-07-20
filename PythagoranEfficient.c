// not working right now but logic brings complexity to n2

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
        int num;
        for(int j=i;j<n;j++){
          num = array[j];

          if(array[i]==num+array[j]){
            flag = 1;
            break;
          }

          if(array[i] == array[j]+array[j+1]){
            flag = 1;
            break;
          }

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
