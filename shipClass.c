#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);
	char m = getchar();
	while(t>0){
		//printf("t: %d\n",t);
		char c;
		scanf("%c%*c",&c);

		if(c == 'B' || c == 'b')
			printf("BattleShip\n");
		else if(c == 'C' || c == 'c')
			printf("Cruiser\n");
		else if(c == 'D' || c == 'd')
			printf("Destroyer\n");
		else if(c == 'F' || c == 'f')
			printf("Frigate\n");
		t = t-1;
	}
}