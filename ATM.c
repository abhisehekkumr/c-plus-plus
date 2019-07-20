#include<stdio.h>
#include<stdlib.h>

int main(){

	int withDraw = 0;
	float cash = 0;

	scanf("%d%f",&withDraw,&cash);

	if(withDraw%5==0 && withDraw+0.5<=cash)
		printf("%0.2f\n",(cash-((float)withDraw+0.5)));
	else 
		printf("%0.2f\n",cash );
}