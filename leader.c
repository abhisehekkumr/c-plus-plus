#include<stdio.h>
#include<stdlib.h>


int main(){

	int n;
	scanf("%d",&n);
	int player1[n],player2[n];
	int a=0,b=0;
	for(int i=0;i<n;i++)
		scanf("%d%d",&player1[i],&player2[i]);

	int index = 0,diff = 0;
	for(int i=0;i<n;i++){
	
		a =a + player1[i];
		b = b + player2[i];

		if(a>b && a-b>diff){
			index  = 1;
			diff =a-b;
		}else if(b>a && b-a>diff){
			index  = 2;
			diff = b-a;
		}

	}
	printf("%d %d",index,diff);

	return 0;
}