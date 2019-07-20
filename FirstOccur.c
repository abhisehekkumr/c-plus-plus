#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int number,k;
		scanf("%d %d",&number,&k);
		int array[number];

		for(int i=0;i<number;i++)
			scanf("%d",&array[i]);

		int i=0;

		for(i=0;i<number;i++){
			if(array[i]==k)
				break;
		}
		if(i==number)
			printf("-1\n");
		else
			printf("%d\n",i+1);
	}
}