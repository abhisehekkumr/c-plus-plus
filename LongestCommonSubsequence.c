#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int size,count=1,index=0;
		scanf("%d",&size);
		int array[size];

		for(int i=0;i<size;i++)
			scanf("%d",&array[i]);

		for(int i=1;i<size;i++){

			if(array[index]<array[i]){
				count++;
				index = i;
			}
		}

		printf("%d\n",count);
	}
}