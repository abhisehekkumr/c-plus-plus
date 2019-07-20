#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int number,sum,palindrome = 0;
		sum = 0;

		scanf("%d",&number);

		while(number != 0){
			sum += number%10;
			number = number/10;
		}
		//printf("Sum: %d\n",sum);

		palindrome = sum;
		int reverse = 0;

		while(palindrome != 0){
			reverse = reverse*10 + palindrome%10;
			palindrome = palindrome/10;
		}
		//printf("reverse : %d \n",reverse );

		if(reverse == sum)
			printf("YES\n");
		else
			printf("NO\n");
	}
}