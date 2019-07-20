#include<stdio.h>

int main(){

	int tabs,blanks,c;

	while((c=getchar())!='\n'){

		if(c=='\t')
			printf("\\t");
		else if(c==' ')
			printf("\\b");
		else
			putchar(c);
	}
}