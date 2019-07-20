#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int n, a,b,flag = 1;

		scanf("%d",&n);
		int arr[n];
		for(int i= 0; i < n; i++)
			scanf("%d",&arr[i]);

		a = arr[0];
		b = arr[1];

		if(n == 2)
			flag = 0;

		for(int i = 0; i < n && flag; i++){
			if(arr[i] < a){
				b = a;
				a = arr[i];
			}else if(arr[i] < b)
				b = arr[i];
		}
		printf("%d\n",a+b);
	}
}