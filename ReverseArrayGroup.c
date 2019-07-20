#include<stdio.h>
void reverse(int array[], int i, int k, int n);

int main(){

    int t;
    scanf("%d",&t);

    while(t--){

        int n,k;
        scanf("%d",&n);
        int array[n];

        for(int i=0;i<n;i++)
          scanf("%d",&array[i]);

        scanf("%d",&k);

        int i=0,z;
        z = k;
        while(i<n){
            reverse(array,i,k,n);
            i = k;
            k = k + z;
        }

        for(int j=0;j<n;j++)
          printf("%d ",array[j]);

        printf("\n");
    }
}

void reverse(int array[],int i,int k,int n){

    if(n-i==1)
      {
        return;
      }
    if(n-k<0){
        int m = k-n;

        for(int a = i;a<k-m;a++){
          int temp;
          for(int j = i; j<k-m;j++){

              if(array[a]>array[j]){
                temp = array[j];
                array[j] = array[a];
                array[a] = temp;
              }
          }
        }

    }else{

        for(int a = i;a<k;a++){
          int temp;
          for(int j = i; j<k;j++){

              if(array[a]>array[j]){
                temp = array[j];
                array[j] = array[a];
                array[a] = temp;
              }
          }
        }

    }
}
