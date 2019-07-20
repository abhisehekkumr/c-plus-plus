#include<stdio.h>
#include<math.h>


struct point{
		int x;
		int y;
};

int length(struct point first, struct point second){
	int result = (first.x - second.x)*(first.x - second.x) + (first.y - second.y)*(first.y - second.y);
	//printf("length %d \n",result);
	return result;
}

int distance(struct point first,struct point second, struct point third, struct point fourth){
	double one = sqrt((first.x - fourth.x)*(first.x - fourth.x) + (first.y - fourth.y)*(first.y - fourth.y));
	double second1 = sqrt((third.x - second.x)*(third.x - second.x) + (third.y - second.y)*(third.y - second.y));

	//printf("%lf %lf\n",one,second1);
	if(one == second1)
		return 1;
	return 0;
}

int main(){
	int t;
	scanf("%d",&t);

	while(t--){

		struct point first,second,third,fourth;
		scanf("%d %d %d %d %d %d %d %d",&fourth.x,&fourth.y,&third.x,&third.y,&second.x,&second.y,&first.x,&first.y);
		//printf("%d %d %d %d %d %d %d %d \n",fourth.x,fourth.y,third.x,third.y,second.x,second.y,first.x,first.y);
		int require_length = length(first,second);

		

		if(length(third,first) == require_length && length(fourth,second) == require_length &&
			length(third,fourth) == require_length && length(first,second) == require_length){
			if(length(second,third) == length(first,fourth))
				printf("1\n");
			else
				printf("0\n");
		}

		else if(length(second,fourth) == require_length && length(first,third) == require_length &&
			length(second,first) == require_length && length(fourth,third) == require_length){
			if(length(second,third) == length(first,fourth))
				printf("1\n");
			else
				printf("0\n");
		}

		else if(length(third,second) == require_length && length(fourth,first) == require_length &&
			length(third,fourth) == require_length && length(second,first) == require_length){
			if(length(first,third) == length(second,fourth))
				printf("1\n");
			else
				printf("0\n");

		}

		else if(length(first,second) == require_length && length(third,fourth) == require_length &&
			length(first,third) == require_length && length(second,fourth) == require_length){
			if(length(second,third) == length(first,fourth))
				printf("1\n");
			else
				printf("0\n");
		}

		else
			printf("0\n");
	}
}