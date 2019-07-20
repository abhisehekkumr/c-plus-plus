#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int number,k;
		scanf("%d %d",&number,&k);

		int array[number],count=0;

		for(int i=0;i<number;i++){
			scanf("%d",&array[i]);

			if(array[i]==k)
				count++;
		}

		if(count)
			printf("%d\n",count);
		else
			printf("-1\n");
	}
}