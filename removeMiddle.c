#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int n;
		scanf("%d",&n);
		
		
		int arr[n], flag = 1;

		int k = 0;
		if(n%2 == 0)
			k =  n/2 -1;
		else
			k = n/2;

		//printf("k: %d\n",k);
		for(int i = 0; i < n; i++){
			scanf("%d",&arr[i]);
		}
		for(int i = n-1; i >= 0; i--)

			if(i != k)
				printf("%d ",arr[i]);
	}
}