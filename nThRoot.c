#include<stdio.h>

int factorial(int i, int n){
	if(n == 0 || n == 1)
		return i;
	return i*factorial(i,n-1);
}

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int n,m;
		scanf("%d %d",&n,&m);

		int i = 2,flag = 1;

		if(m == 1){
			printf("1\n");
			flag = 0;
		}else{
			while(i<m){
			int fact = factorial(i,n);

			if(fact == m){
				printf("%d\n",i);
				flag = 0;
				break;
			}

			if(fact > m){
				flag = 1;
				break;
			}
			i++;
		}
		}



		if(flag)
			printf("-1\n");
	}
}