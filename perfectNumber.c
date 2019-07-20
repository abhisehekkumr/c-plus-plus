#include<stdio.h>

void getPrimeArray(int arr[], int number){
	for(int i = 0; i<= number; i++)
		arr[i] = 1;

	for(int p = 2; p*p <= number; p++){
		if(arr[p]){
			for(int i = p*p; i<=number; i+= p)
				arr[i] = 0;
		}
	}
}

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int number;
		scanf("%d",&number);
		int sum = 1;
		
		int arr[number+1];
		getPrimeArray(arr,number);

		for(int i = 2; i<= number; i++){
			if(arr[i] && number%i == 0)
				sum += i;
		}

		if(sum == number)
			printf("%d\n",1);
		else
			printf("0\n");
	}
}