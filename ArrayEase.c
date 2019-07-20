#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);
	
	while(t--){
		
		int n;
		scanf("%d",&n);
		
		int array[n];
		for(int i=0;i<n;i++)
			scanf("%d",&array[i]);
			
		int zero_count = 0,j=1;
		for(int i=0;i<n;i++){
			
			if(array[i]==0)
				zero_count++;
			else if(array[i]==array[j]){
				array[i] = 2*array[i];
				array[j] = 0;
				//zero_count++;
			}
		
				j++;
		}
		
		for(int i=0;i<n;i++){
			
			if(array[i]!=0)
				printf("%d ",array[i]);
		}
		
		for(int i=0;i<zero_count;i++)
		printf("%d ",0);
		
		printf("\n");
			
	}
}