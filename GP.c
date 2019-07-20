#include<stdio.h>
#include<math.h>

double factorial(double b, double n){
	if(n == 0)
		return 1;
	return b*factorial(b,n-1);
}
int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		double a,b,n,result;
		scanf("%lf %lf",&a,&b);
		scanf("%lf",&n);
		
		if(n == 1)
			result = a;
		else{
			double d = b/a;
			result = a*factorial(d,n-1);
		}
		printf("%d\n",(int)result);
	}
}