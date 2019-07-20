#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);
	
	while(t--){
			
			int n,sum_low=0,sum_high=0;
			scanf("%d",&n);
			
			int array[n],i=0,k;
			k=n-1;
			for(int i=0;i<n;i++)
				scanf("%d",&array[i]);
				
			sum_low = array[0];
			sum_high = array[k];
			
			if(n==1)
			    printf("%d\n",1);
			else {
			    
			    while(n--){
			        
			        if(i+1==k-1)
			            break;
			         else if(sum_low<sum_high)
			            sum_low += array[++i];
			          else
			            sum_high += array[--k];
			    }
			}
			
			if(sum_low==sum_high)
			    printf("-1\n");
			else
			    printf("%d\n",i);   
		    
	}
}