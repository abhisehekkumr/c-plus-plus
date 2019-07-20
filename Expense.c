#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		float item,price;
		scanf("%lf %lf",&item,&price);

		if(item > 1000){
			printf("%lf\n",item*price*0.90);
		}else 
			printf("%lf\n",item*price);
	}
}