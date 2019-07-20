#include<stdio.h>

int main(){

	int array[10],white,other,c;

	for(int i=0;i<10;i++)
		array[i] = 0;
	while((c=getchar())!='\n'){

		if(c>='0' && c<='9')
			++array[c-'0'];
		else if(c==' ' || c=='\t')
			++white;
		else
			++other;
	}

	printf("Digits are:");
	for(int i=0;i<10;i++)
		printf("%d ",array[i] );

	printf("White spaces:%d \n others: %d\n",white,other);
}

