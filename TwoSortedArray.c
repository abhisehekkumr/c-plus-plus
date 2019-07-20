#include<stdio.h>

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    int f,s,k;
    scanf("%d %d %d",&f,&s,&k);

    int first_array[f],second_array[s];
    for(int i=0;i<f;i++)
      scanf("%d",&first_array[i]);
    for(int i=0;i<s;i++)
      scanf("%d",&second_array[i]);

    int array[f+s],count=0,i=0,j=0;

    while(i<f && j<s){
      if(first_array[i]<=second_array[j])
        array[count++] = first_array[i++];
      else
        array[count++] = second_array[j++];
    }

    if(f>s){
      while(i<f)
        array[count++] = first_array[i++];

    }else{
      printf("s is %d \n",j);
        printf("f is %d \n",i);
      while(j<s)
        array[count++] = second_array[j++];
      }

    printf("%d\n",array[k-1]);
  }
}
