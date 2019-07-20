#include<stdio.h>
#define MODE 1000000007

long long power(long long n, long long base){
	long long result = 1;

	n = n%MODE;

	while(base > 0){

		if(base & 1)
			result = result*n%MODE;

		base = base>>1;
		n = n*n%MODE;
	}
	return result;
}


long long modeInverse(long long fact){
	return power(fact,MODE-2);
}
int main(){
	int t;
	scanf("%d",&t);
	long long fact[1000+10];
	fact[0] = 1;
	
	for(int i = 1; i<=1009; i++)
		fact[i] = fact[i-1]*i%MODE;


	while(t--){
		long long r,n;
		scanf("%lli %lli",&n,&r);

		if( n > r){
			long long n_factorial = fact[n];
			long long r_factorial = modeInverse(fact[r])%MODE;
			long long r_n_factorial = modeInverse(fact[n-r])%MODE;

			long long result = (n_factorial * r_factorial *r_n_factorial)%MODE;
			printf("%lli\n",result%MODE);
		}

		else
			printf("0\n");
	}
}