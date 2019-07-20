#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int n;
		scanf("%d",&n);
		int arr[n+1];

		for(int i = 1; i< n+1; i++)
			scanf("%d",&arr[i]);

		int flag = 0;
		for( int i = 1; i < n + 1; i++) {

			for(int j = 1; j < n + 1; j++){
				if(i != j && arr[i] != arr[j] && arr[arr[i]] == arr[arr[j]]){
					flag = 1;
					break;
				}
			}
			if(flag)
				break;
		}

		if(flag)
			printf("Truly Happy\n");
		else
			printf("Poor Chef\n");
	}
}