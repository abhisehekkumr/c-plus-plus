#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int n;
		scanf("%d",&n);
		int zeroes = 0, multiplier = 5;

		while(n/multiplier){
			zeroes += n/multiplier;
			multiplier *= 5;
		}

		printf("%d\n",zeroes);
	}
}