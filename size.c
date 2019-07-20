#include<stdio.h>
#include<stdlib.h>


int stlen(char array[]);
int main(){

	printf("int:%d\n",sizeof(int));
	printf("unsigned int:%d\n",sizeof(unsigned int));
	printf("short int:%d\n",sizeof(short int));
	printf("long:%d\n",sizeof(long));
	printf("float:%d\n",sizeof(float));
	printf("double:%d\n",sizeof(double));
	printf("long double:%d\n",sizeof(long double));
	printf("unsigned char:%d\n",sizeof(unsigned char));
	printf("char:%d\n",sizeof(char));

	printf("hello,""word\n");

	char array[10];
	//scanf("\n%s",array);
	int a = 0;
	scanf("%o",&a);
	printf("hexadecimal: %d\n",(int)a);
	//printf("%d\n",stlen(array) );
}

int stlen(char array[]){
	int count,i;
	count = i = 0;

	while(array[i++]!='\0')
		++count;
	return count;
}