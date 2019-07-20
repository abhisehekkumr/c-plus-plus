#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int n,d;
		scanf("%d %d",&n,&d);

		int arr[n];

		for(int i = 0; i<n; i++)
			scanf("%d",&arr[(n-d+i)%n]);
		for(int i = 0; i<n ;i++)
			printf("%d ",arr[i]);
		printf("\n");
	}
}