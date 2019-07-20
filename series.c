#include<stdio.h>

int main(){
	int t;

	scanf("%d",&t);

	while(t--){
		int a,b,n;

		scanf("%d %d",&a,&b);
		int d = b - a;
		scanf("%d",&n);

		printf("%d\n",(a+(n-1)*d));
	}
}