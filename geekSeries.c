#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int n;
		scanf("%d",&n);

		long long x = 7;
		long long y = 15;
		long long d = 0;
		long long z = 0;
		int i = 2, flag = 1;

		if(n == 1){
			printf("7\n");
			flag = 0;
		}

		if(n == 2){
			printf("15\n");
			flag = 0;
		}

		for(i=1;i<=n-1;i++)
		{
			x=(x*2+i)%1000000007;
		}

		if(flag)
			printf("%llu\n",x);
	}
}