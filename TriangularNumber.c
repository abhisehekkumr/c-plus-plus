#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int number;
		scanf("%d",&number);
		int sum = 0;
		for(int i = 1; i<=number; i++){

			sum += i;

			if(sum == number){
				printf("1\n");
				break;
			}

			if(sum > number){
				printf("0\n");
				break;
			}
		}
	}
}