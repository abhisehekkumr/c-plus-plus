#include<stdio.h>

int main(){
	int count,c;

	while((c=getchar())!='\t'){
		if(c=='\n')
			++count;
	}

	printf("Total lines are: %d",count);
}