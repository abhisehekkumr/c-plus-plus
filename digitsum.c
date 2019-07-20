#include<stdio.h>

int main(){
	int t;

	scanf("%d",&t);

	while(t--){
		int number,sum=0,flag=0;
		scanf("%d",&number);

		if(number<0){
			flag = 1;
			number = number*(-1);
		}

		while(number>0){
			sum += number%10;
			number = number/10;
		}

		if(flag)
			printf("%d\n",-1*sum);
		else
			printf("%d\n",sum);
	}

}