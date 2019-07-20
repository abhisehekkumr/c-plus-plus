#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);
	
	while(t--){
		
		int n,zero=0,one=0,two=0,number;
		
		scanf("%d",&n);
		
		for(int i=0;i<n;i++){
			scanf("%d",&number);
			
			if(number==0)
				++zero;
			else if(number==1)
				++one;
			else if(number==2)
				++two;
		}
		
		for(int i=0;i<zero;i++)
			printf("%d ",0);
			
		for(int i=0;i<one;i++)
			printf("%d ",1);
			
		for(int i=0;i<two;i++)
			printf("%d ",2);
			
		printf("\n");
	}
}