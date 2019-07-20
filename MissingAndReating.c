// this is good approach but we cannot and wont be able to determine which one is different of which one
// is missing thus we have to used extra last loop

#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int n;
		scanf("%d",&n);

		int array[n],xor=0,x = 0,y = 0;

		for(int i=0;i<n;i++)
			scanf("%d",&array[i]);

		xor = array[0];

		for(int i=1;i<n;i++)
			xor = xor^array[i];

		for(int i=1;i<=n;i++)
			xor = xor^i;

		int bit = xor & ~(xor-1);

		for(int i=0;i<n;i++){
			if(array[i] & bit)
				x = x^array[i];
			else
				y = y^array[i];
		}

		for(int i=1;i<=n;i++){
			if(i & bit)
				x = x^i;
			else
				y = y^i;
		}

		int flag = 0;
		for(int i=0;i<n;i++){
			if(array[i] == y){
				flag = 1;
				break;
			}
		}

		if(flag)
			printf("%d %d\n",y,x);
		else
			printf("%d %d\n",x,y);
	}
}