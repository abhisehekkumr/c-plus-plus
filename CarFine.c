#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);
	
	while(t--){
		
		int n,date;
		
		scanf("%d %d",&n,&date);
		int cars[n],penality[n],fine_odd=0,fine_even = 0;
		
		for(int i=0;i<n;i++){
			
			scanf("%d",&cars[i]);
		}
		
		for(int i=0;i<n;i++)
			scanf("%d",&penality[i]);
		}
		
		for(int i=0;i<n;i++){
			
				if(cars[i]%2==0)
				fine_even = fine_even + penality[i];
			else
				fine_odd = fine_odd + penality[i];
		}
		
		if(date%2==0)
			printf("%d\n",fine_odd);
		else
			printf("%d\n",fine_even);
			
		}
}

