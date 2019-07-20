#include<stdio.h>
#include<math.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		long long n;
		scanf("%lli",&n);

		printf("%d\n",(int)floor(sqrt(n)));
	}
}