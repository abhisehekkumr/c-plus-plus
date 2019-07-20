#include<stdio.h>


long long factorial(long long a, long long b){
	if(b == 0)
		return 1;
	return a*factorial(a,b-1);
}

long long main(){
	long long t;
	scanf("%lli",&t);

	while(t--){
		long long a,b,k;
		scanf("%lli %lli %lli",&a,&b,&k);

		long long result = factorial(a,b);

		while(result != 0){

			if(k == 1){
				printf("%lli\n",result%10);
				break;
			}
			result = result/10;
			k--;
		}

	}
}