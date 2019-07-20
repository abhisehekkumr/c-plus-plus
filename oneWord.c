#include<stdio.h>

int main(){
	int c;

	while((c=getchar())!='\n'){

		if(c==' ')
			printf("\n");
		else 
			putchar(c);
	}
}