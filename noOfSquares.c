#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		long long n,m;
		scanf("%d %d",&m,&n);

		long long sum = 0, i = 0;

		while(n -i && m - i){
			sum += (n-i)*(m - i);
			i++;
		}
		printf("%lli\n",sum);
	}
}