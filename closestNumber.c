#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int a,b,upper_true = 1, lower_true = 1,largest = 0;
		scanf("%d %d",&a,&b);

		int lower = a,upper = a;
		int largest_upper,largest_lower;
		if(a%b == 0){
			upper_true = 0;
			lower_true = 0;
			largest = a;
		}
		while(upper_true !=0 || lower_true != 0){
			upper++;
			lower--;

			if(upper%b == 0 && upper_true){
				largest_upper = upper;
				upper_true = 0;
			}

			if(lower%b == 0 && lower_true){
				largest_lower = lower;
				lower_true = 0;
			}

		}
		if(abs(a)%abs(b) == 0)
			largest = a;
		else if(abs(abs(largest_upper)-abs(a)) > abs(abs(largest_lower)-abs(a)))
			largest = largest_lower;
		else if(abs(abs(largest_lower)-abs(a)) > abs(abs(largest_upper)-abs(a)))
			largest = largest_upper;
		else if(abs(largest_upper) > abs(largest_lower))
			largest =  largest_upper;
		else
			largest = largest_lower;
			
		printf("%d\n",largest);
	}
}