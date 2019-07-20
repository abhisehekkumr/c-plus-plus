#include<stdio.h>


int reverseNum(int number, int reverse){

	if(number == 0)
		return reverse;
	return reverseNum(number/10,reverse*10+number%10);
}

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int number;
		scanf("%d",&number);

		printf("%d\n",reverseNum(number,0));
	}
}