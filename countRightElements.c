// although it will work but efficient solution exist with AVL tree

#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int n;
		scanf("%d",&n);
		int arr[n];

		for(int i = 0; i< n; i++)
			scanf("%d",&arr[i]);

		for(int i = 0; i<n; i++){
			int count = 0;

			for(int j = i; j<n; j++){

				if(arr[i] > arr[j])
					count++;
			}

			printf("%d ",count);
		}

		printf("\n");
	}
}