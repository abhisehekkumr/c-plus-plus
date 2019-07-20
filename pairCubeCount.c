#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){

		int number;
		scanf("%d",&number);
		int count = 0;
		for(int i = 1; i<number; i++){
			for(int j = 0; j<number; j++){
				//printf("%d %d\n",i,j );
				if((i*i*i + j*j*j) == number)
					count++;
			}
		}
		
		if (number == 1)
		    count = 1;
		printf("%d\n",count);
	}
}