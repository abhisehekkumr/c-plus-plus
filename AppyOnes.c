#include<stdio.h>


int shifArr(int arr[], int n){
	int temp = arr[n];

	for(int i = n; i > 0; i--)
		arr[i] = arr[i-1];
	arr[0] = temp;

	for(int i = 0; i <= n; i++)
		printf("%d \n",arr[i]);
	printf("\n");
}

int longestSequence(int arr[], int n, int k){
	int count = 0;
	int max = 0;

	for(int i = 0; i < n; i++){
		if(arr[i] == 0){
			max = max > count ? max : count;
			count = 0;
		}else 
			count++;
	}

	if(max >= k)
		return k;
	return max;
}

int main(){
	int n,q,k;
	scanf("%d %d %d",&n,&q,&k);

	int arr[n];

	for(int i = 0; i < n; i++)
		scanf("%d",&arr[i]);

	char exp[q+10];
	scanf("%s",&exp);

	int i = 0;

	while(exp[i]!= '\0'){
		if(exp[i] == '?')
			printf("%d\n",longestSequence(arr,n,k));
		else if(exp[i] == '!')
			shifArr(arr,n-1);
		i++;
	}
}