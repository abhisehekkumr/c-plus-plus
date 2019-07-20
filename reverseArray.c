#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int n;
		scanf("%d",&n);

		int arr[n];

		for(int i = 0 ; i<n ; i++)
			scanf("%d",&arr[i]);
		for(int i = n-1; i >= 0; i--)
			printf("%d ", arr[i]);
		printf("\n");
	}
}