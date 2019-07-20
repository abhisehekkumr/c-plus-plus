#include<stdio.h>

int main(){
	int n;
	scanf("%d",&n);

	int count = 0;
	int arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d",&arr[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		if(arr[i]%2 == 0)
			count++;
	}

	int odd = n - count;

	if(odd >= count)
		printf("NOT READY\n");
	else
		printf("READY FOR BATTLE");
}