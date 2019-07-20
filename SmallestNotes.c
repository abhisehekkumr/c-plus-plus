#include<stdio.h>

int main(){
  int t;
  scanf("%d",&t);

  int notes[6] = {100,50,10,5,2,1};

  while(t--){
    int number = 0;

    int n;
    scanf("%d",&n);

    for(int i=0;i<6;i++){
      if(n/notes[i]!=0){
        number = number + n/notes[i];
        n = n%notes[i];
      }
    }

    printf("%d\n",number);
  }
}
