#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int n,k;
		scanf("%d",&n);

		int arr[n];

		for(int i = 0; i < n; i++)
			scanf("%d",&arr[i]);

		scanf("%d",&k);

		int i = 0, j = n-1, flag = 1;

		while(i < j){

			if(arr[j] > k){
				j--;
				continue;
			}

			if(j>=0 && (arr[i] + arr[j] == k)){
				printf("%d %d %d\n",arr[i],arr[j],k);
				flag = 0;
				i++;
				j--;
			}
			
			if(j>=0 && (arr[i] + arr[j] < k))
				i++;
			if(j>=0 && (arr[i] + arr[j] > k))
				j--;
		}

		if(flag)
			printf("-1\n");
	}
}