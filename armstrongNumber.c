#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int number,num = 0,n,k;
		scanf("%d",&n);

		number = n;

		while(n != 0){
			k = n%10;
			num = num + k*k*k;
			n = n/10;
		}

		if(num == number)
			printf("YES\n");
		else
			printf("NO\n");
	}
}