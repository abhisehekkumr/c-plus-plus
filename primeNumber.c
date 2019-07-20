#include<stdio.h>
#include<math.h>

int checkPrime(int number){
	if(number == 1)
		return -1;
	int len = sqrt(number)+1;

	for(int i = 2; i <=len; i++){
		if(number%i == 0)
			return -1;
	}
	return 1; 
}

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int number;
		scanf("%d",&number);

		if(checkPrime(number) == 1)
			printf("Yes\n");
		else
			printf("No\n");
	} 
}