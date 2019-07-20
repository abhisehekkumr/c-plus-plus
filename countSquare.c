#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		double n;
		scanf("%lf",&n);

		long long count  = 0;
		for(double i = 1; i<n ; i++){

			if(i*i < n){
				count++;
				printf("%lli\n",count);
			}
		}
		printf("%lli\n",count);
	}
}