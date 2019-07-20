#include<stdio.h>


int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int size,sum,result=0,flag = 0,first = 0,second = 0;
		scanf("%d %d",&size,&sum);

		int array[size];

		for(int i=0;i<size;i++)
			scanf("%d",&array[i]);

		for(int i=0;i<size;i++){
			result = result + array[i];

			while(result>sum && first < i-1){
				result = result - array[first];
				first = first + 1;
			}

			if(result==sum){
				flag = 1;
				second = i;
				break;
			}
		}

		if(flag)
			printf("%d %d\n",first+1,second+1);
		else{
			result = 0;
			flag = 0;
			first = size-1;
			for(int i = size -1;i>=0;i--){
				result = result + array[i];
				
				if(result>sum){
					result = result - array[first];
					first--;
				}

				if(sum==result){
					flag = 1;
					second = first;
					first = i;
					break;
				}
			}

			if(flag)
				printf("%d %d\n",first+1,second+1);
			else
				printf("-1\n");
		}
	}
}