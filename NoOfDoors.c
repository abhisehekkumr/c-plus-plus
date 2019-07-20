#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		long long n;
		scanf("%lli",&n);

		long long arr[n+1];

		for(long long i = 0; i <= n; i++)
			arr[i] = 1;

		for(long long i = 1; i<=n; i++){

			for(long long j = i; j<=n; j += i){

				if(arr[j] == 1)
					arr[j] = 0;
				else if(arr[j] == 0)
					arr[j] = 1;
			}
		}

		int count = 0;

		for(long long i = 1; i <= n; i++){
			if(arr[i] == 0)
				count++;
		}
		printf("%d\n",count);
	}
}