#include<stdio.h>

int main(){

	int t;
	scanf("%d",&t);
	
	while(t--){
		
		int n;
		scanf("%d",&n);
		int a,b,max_sum=0,sum2=0;
		
		scanf("%d",&a);
		sum2 += a;
		
		while(--n){
			
			scanf("%d",&b);
			
			if(a<b)
				sum2 += b;
			else
				max_sum = (max_sum>sum2)?max_sum:sum2;
			a=b;
		}
		
		printf("%d\n",max_sum);
	}
}