#include<stdio.h>

long long factorial(long long number){
	if(number == 1 || number == 0)
		return 1;
	return number*factorial(number-1);
}
int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		long long n,r;
		scanf("%lli %lli",&n,&r);

		long long factorial_n = factorial(n);
		long long factorial_r = factorial(n-r);
		printf("%lli\n",factorial_n/factorial_r);
	}
}