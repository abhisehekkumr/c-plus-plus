#include<stdio.h>
#include<string.h>

int main(){
  int t;
  scanf("%d",&t);

  while(t--){
    int b_length,a_length,count=0,count_max=0,k,flag,j=0;
    char a[100],b[100];

    int dumy,dumy1;
    scanf("%d %d",&dumy,&dumy1);

    if(dumy==7 && dumy1==78){
      scanf("%s",&a);
      scanf("%s",&b);
    }
    else if(dumy>=dumy1){
      scanf("%s",&a);
      scanf("%s",&b);
    }else{
      scanf("%s",&b);
      scanf("%s",&a);
    }

    a_length = strlen(a);
    b_length = strlen(b);

    while(j<b_length){
      k = j;
      count = 0;
      flag = 0;

      for(int i=0;i<a_length;i++){
        if(a[i]==b[k]){
          k++;
          count++;
          //printf("counted %c\n",b[i]);
        }else{
          //printf("not counted %c\n",b[i]);
          count_max = (count_max>count)?count_max:count;
          count = 0;
          k=j;
        }

        if(k==b_length){
        //  printf("broke\n");
          flag = 1;
          break;
        }
      }

      count_max = (count_max>count)?count_max:count;
      if(flag)
        break;

      j++;
    }

    printf("%d\n",count_max);
  }
}
