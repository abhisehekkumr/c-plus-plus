#include<stdio.h>
#include<math.h>

int main(){
  int menu[12];
  for(int i=0;i<12;i++){

    double number = pow(2,12-1-i);
    menu[i] = (int) number;
  }

  int t;
  scanf("%d",&t);
  while(t--){
    int p;
    scanf("%d",&p);

    int price = 0,i=0;
    while(p>0){

        if(menu[i]<=p){
          price = price + p/menu[i];
          p = p%menu[i];
        }

        i++;
    }

    printf("%d\n",price);
  }
}
