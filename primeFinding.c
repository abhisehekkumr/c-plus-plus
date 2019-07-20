#include<stdio.h>

int *getPrimeArray(int number, int arr[]){
	
	for(int i = 0; i<= number; i++)
		arr[i] = 1;

	int p = 2;

	for(int p = 2; p*p <=number; p++){
		if(arr[p]){
			for(int i = p*p; i<=number; i += p)
				arr[i] = 0;
		}
	}

	return arr;
}
int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int number,*arr;
		scanf("%d",&number);
		int array[number+1];
		arr = getPrimeArray(number,array);

		for(int i = 2; i<=number; i++){
			if(arr[i])
				printf("%d ",i);
		}
		printf("\n");
	}
}