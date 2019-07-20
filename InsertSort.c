#include<stdio.h>

int main(){

    int n;
    scanf("%d",&n);
    int array[n];
    for(int i=0;i<n;i++)
      scanf("%d",&array[i]);

    for(int i=0;i<n;i++){
        int v = array[i];
        int j = i;

        while(array[j-1]>v && j>=1){
            array[j] = array[j-1];
            j--;
        }
        array[j] = v;
    }


    for(int i=0;i<n;i++)
      printf("%d ",array[i]);
}
