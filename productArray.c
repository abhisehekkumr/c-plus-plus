#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int n;
		scanf("%d",&n);

		int arr[n];

		for(int i=0;i<n;i++)
			scanf("%d",&arr[i]);
		//printf("Hello\n");

		int left[n],right[n];
		left[0] = right[n-1] = 1;

		for(int i=1; i<n; i++)
			left[i] = arr[i-1]*left[i-1];
		for(int i=n-2; i>=0; i--)
			right[i] = arr[i+1]*right[i+1];

		for(int i=0; i<n; i++)
			printf("%d ",left[i]*right[i]);
		printf("\n");
	}
}