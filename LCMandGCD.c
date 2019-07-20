#include<stdio.h>

int gcd(int a, int b){

	if(b == 0)
		return a;
	return gcd(b,a%b);
}

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int a,b,largest,smaller;
		scanf("%d %d",&a,&b);

		if(a > b){
			largest = a;
			smaller = b;
		}else{
			largest = b;
			smaller = a;
		}

		printf("%d %d\n",(largest*smaller)/gcd(largest,smaller),gcd(largest,smaller));
	}
}