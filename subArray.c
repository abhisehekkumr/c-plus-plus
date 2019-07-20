#include<stdio.h>

int main(){
	
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int array[n];
		for(int i=0;i<n;i++){
			scanf("%d",&array[i]);
		}
		
		int high=0,next=0;
		high = array[0];
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				next = next + array[j];
				
				if(next>high)
					high = next;
			}
			next = 0;
		}
		printf("%d\n",high);
	}
}