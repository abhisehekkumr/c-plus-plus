#include<stdio.h>

int main(){

	long int t;
	long int k;
	scanf("%li%li",&t,&k);
	int count = 0;

	while(t>0){
		t = t-1;
		long int number;
		scanf("%li",&number);

		if(number%k==0)
			count++;
	}

	printf("%d\n",count );
}

