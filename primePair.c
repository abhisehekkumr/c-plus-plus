#include<stdio.h>


int *getPrimeArray(int arr[], int number){

	for(int i = 0; i <= number; i++)
		arr[i] = 1;

	for(int p = 2; p*p <= number; p++){
		if(arr[p]){
			for(int i = 2*p; i<=number; i += p)
				arr[i] = 0;
		}
	}
	return arr;
}
int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int number;
		scanf("%d",&number);

		int arr[number+1];

		int *array = getPrimeArray(arr,number);

		for(int i = 2; i<= number; i++){
			for(int j=2; j<= number; j++){

				if(array[i] && array[j] && i*j <=number){
					printf("%d %d ",i,j);
				}
			}
		}
		printf("\n");
	}
}