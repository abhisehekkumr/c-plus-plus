#include <stdio.h>
#include<math.h>

int main() {
	int t;
	scanf("%d",&t);
	
	while(t--){
	    double n;
	    scanf("%lf",&n);
	    double result = sqrt(n);	    
	    if(result == floor(sqrt(n)))
	        printf("%d\n",(int)(result -1));
	   else
	        printf("%d\n",(int)(result));
	}
	return 0;
}