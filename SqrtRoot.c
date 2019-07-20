#include<stdio.h>
#include<math.h>

int main(){
  int t;
  scanf("%d",&t);

  while (t--) {
    double number,root;
    scanf("%lf",&number);
    root = sqrt(number);
    printf("%d\n",(int)root);
  }
}
