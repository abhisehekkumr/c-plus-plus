#include<stdio.h>

int main(){

	char str[20];

	for(int i=0;i<2;i++){
		scanf("%[^\n]s",str);
		printf("%s\n",str);
	}
}