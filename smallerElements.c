#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int n;
		scanf("%d",&n);
		int arr[n],count = 0,x;
		for(int i = 0; i<n; i++)
			scanf("%d",&arr[i]);
		scanf("%d",&x);
		int i = 0;

		while(i < n && arr[i] <= x){
			count++;
			i++;
		}
		printf("%d\n",count);
	}
}