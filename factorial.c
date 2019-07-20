#include<stdio.h>

int main(){

    long double fact;
	int t;
	scanf("%d\n",&t);

	while(t-->0){
		fact = 1;
		int l = 0;
		scanf("%d",&l);

		
		for(int i=1;i<=l;i++){

			fact = fact*i;
			printf("fact:%.0LF , i:%d\n",fact,i);
		}
		printf("%.0Lf\n",fact);
	}

	return 0;
}