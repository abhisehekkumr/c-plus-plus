#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int number,reverse_number = 0;
		scanf("%d",&number);

		while(number != 0){
			reverse_number =reverse_number*10 + number%10;
			number = number/10;
		}
		printf("%d\n",reverse_number );
	}
}