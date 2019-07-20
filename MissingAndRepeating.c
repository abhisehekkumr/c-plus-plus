#include<stdio.h>
#include<stdlib.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int n;
		scanf("%d",&n);
		int a[n];

		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);

		// this loop will find the repeating number in the array. the idea is find the number at index i
		// and save it at position a[i] - 1, we are subtrating by -1 because the biggest element will be
		// n and our i can varry only 0 to n-1. what is algorithm will do is tha by geeting value of a[a[i]-1]
		// absolute value, thus if there is any repeating element it will be once set to -ve already
		// thus we can find our element but this loop is also doing one more thing that it will leave only one 
		// i untouched thus we missing element will be i+1, which is done by the next loop 
		for(int i=0;i<n;i++){
			if(a[abs(a[i])-1]>0)
				a[abs(a[i])-1] = -a[abs(a[i])-1];
			else 
				printf("%d ",abs(a[i]));
		}

		for(int i=0;i<n;i++){
			if(a[i]>0){
				printf(" %d\n",i+1);
			}
		}
	}
}