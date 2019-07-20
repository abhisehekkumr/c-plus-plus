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

      for(int i=0;i<n;i++){
        int v = array[i];
        int j=i;

        while(array[j-1]>v && j>=1){
          array[j] = array[j-1];
          j--;
        }
        array[j] = v;
      }

    int m;
    scanf("%d",&m);

    int min = 99999;
    int diff,first=0,second=0;

    if(m==1){
        min  = 0;
    }else{

            if(n-m==0)
              min = array[n-1] - array[0];
            else{

              for(int i=0;i<=n-m;i++){
                diff = array[i+m-1] - array[i];
                if(min>diff){
                  min  = diff;
                  first = i;
                  second = i+m-1;
                }
              }
            }
    }

    printf("%d\n",min);
  }
}
