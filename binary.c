#include<stdio.h>
#define MAC "i am abhishek"
int main(){

	printf("%s",MAC);
	int array[10],low=0,end = 9;

	for(int i=0;i<10;i++)
		array[i] = i+1;

	int x;
	printf("\n enter value:");
	scanf("%d",&x);
	while(low<=end){
		int mid = (low+end)/2;

		if(x ==array[mid]){
			printf("found\n");
			break;
		}else if(x>array[mid])
			low = mid+1;
		else
			end = mid-1;
	}

}