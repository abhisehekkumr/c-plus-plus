#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int n;
		scanf("%d",&n);

		int i,count = 0;
		long long a = 0, b = 1, c = 0;

		for(i = 1; i< 3*n;i++){
			//printf("%lli\n",c);

			c = (a + b)%1000000007;
			//printf("%d\n",arr[i];

			if(c%2 == 0)
				count++;
			a = b;
			b = c;
		}
		printf("%lli\n",c);
	}
}