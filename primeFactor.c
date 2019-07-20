#include<stdio.h>
#include<math.h>


int isPrime(long long number){

	if( number == 1)
		return 0;

	for(int i = 2; i<=sqrt(number); i++){

			if(number%i == 0)
				return 0;
	}
	return 1;
}

long long largestPrime(long long number){
	long long max = 0;

	for(int i = 2; i<=sqrt(number); i++){

		if(number%i == 0){

			if(isPrime(number/i))
				max = max > (number/i) ? max : (number/i);
			else if(isPrime(i))
				max = max > i ? max : i;
		}
	}
	return max;
}

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		long long n;
		scanf("%lli",&n);

		if(isPrime(n))
			printf("%lli\n",n);
		else
			printf("%lli\n", largestPrime(n));
	}
}