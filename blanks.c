#include<stdio.h>

int main(){

	int blank, tabs, newLine=0,c;

	while((c=getchar())!='1'){

		if(c==' ')
			blank++;
		else if(c=='\n')
			newLine++;
		else if(c== '\t')
			tabs++;
	}

	printf("New lines: %u \n Tabs: %d \n blanks : %d\n",newLine,tabs,blank);
}