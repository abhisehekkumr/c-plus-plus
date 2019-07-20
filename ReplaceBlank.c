#include<stdio.h>

int main(){
	int c;

	while((c=getchar())!='\n'){
		if(c!=' ')
			putchar(c);
	}
}