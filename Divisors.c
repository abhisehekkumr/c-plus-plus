#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int n;
		scanf("%d",&n);

		int large =0;
		if(n > 10000)
			large = n/2;
		else
			large = n;
		int arr[n+1];

		for(int i = 0; i<=n ; i++)
			arr[i] = 1;

		int count = 0;
		for(int p = 2; p*p <= n; p++){

			if(arr[p]){
				for(int i = p*p; i<= n; i += p)
					arr[i] = 0;
			}
		}

		for(int i = 2; i<=n; i++){
			if(arr[i] && i*i <=n){
				//printf("%d\n",i );
				count++;
			}
			if(i*i > n)
				break;
		}
		printf("%d\n",count);
	}
}