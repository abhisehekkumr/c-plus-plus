#include<stdio.h>

int make(int arr[]){
	int a = 0;
	int b = 1;
	arr[0] = 0;
	arr[1] = 1;
	for(int i = 2; i<=300 ; i++){
			arr[i] =(a+b)%100;
			a = b;
			b = arr[i];
	}
}
int main(){
	int t;
	scanf("%d",&t);
	int arr[3001];
	make(arr);
	while(t--){
		int n;
		scanf("%d",&n);
		printf("%d\n",arr[n%300]);
	}
}