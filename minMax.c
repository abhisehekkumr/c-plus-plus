#include<stdio.h>
#include<limits.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int n;
		scanf("%d",&n);

		int arr[n],min,max,element;

		min = INT_MAX;
		max = INT_MIN;
		for(int i = 0; i<n ;i++){
			scanf("%d",&element);

			min = min < element ? min : element;
			max = max > element ? max : element;
		}

		printf("%d %d\n",min,max);
	}
}