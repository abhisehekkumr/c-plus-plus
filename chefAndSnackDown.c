#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int n;
		scanf("%d",&n);

		if(n == 2010 || n == 2017 || n == 2016 || n == 2017 || n == 2019)
			printf("HOSTED\n");
		else 
			printf("NOT HOSTED\n");
	}
}