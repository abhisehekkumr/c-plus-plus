#include<stdio.h>

int main(){
	
	int t;
	scanf("%d",&t);
	
	while(t--){
		
			int n,s;
			scanf("%d %d",&n,&s);
			
			int array[n];
			int first_index = 0, second_index = 0, sum = 0;
			
			for(int i=0;i<n;i++){
				scanf("%d",&array[i]);
			
				if(sum==s){
					second_index = i;
					break;
				}
				else if(sum>s){
					sum = sum - array[first_index];
					++first_index;
					
				}
				else
					sum = sum + array[i];
			}
			
			printf("%d %d\n",first_index+1,second_index+1);
	}
}