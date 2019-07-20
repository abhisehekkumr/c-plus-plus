#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int n;
		scanf("%d",&n);


		int arr[n];

		for(int i=0;i <n; i++)
			scanf("%d",&arr[i]);

		int i=0,j=-1,k=-1;

		for(int m=1; m<n; m++){

			if(arr[i] > arr[m] && j < 0){
				i = m;
				j = k = -1;
			}else if(arr[i] < arr[m] && j < 0){
				j = m;
				k = -1;
			}else if(j > 0 && arr[i] > arr[m]){
				i = m;
				j = k = -1;
			}
			else if(j > 0 && arr[j] < arr[m]){
				k = m;
				break;
			}
		}

		if(i < j && j < k)
			printf("1\n");
		else
			printf("0\n");
	}
}