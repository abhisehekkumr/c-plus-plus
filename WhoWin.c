#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int array,position,gautam,shubham,count= 0,count1=0;
		scanf("%d %d %d %d",&array,&position,&gautam,&shubham);

		for(int i=1;i<=array;i++){
			count1 += gautam;
			if(i==position)
				break;
		}

		int low = 1,high = array;

		while(low<high){

			count += shubham;
			
			int mid = (low + high)/2;

			if(mid==position)
				break;

			if(mid>position)
				low = mid+1;
			else
				high = mid -1;
		}

		if(count>count1)
			printf("1\n");
		else
			printf("2\n");
	}
}