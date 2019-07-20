#include<stdio.h>
#include<string.h>

long long main(){
	long long t;
	scanf("%lli",&t);

	while(t--){
		char number[18];
		scanf("%s",&number);
		int len = strlen(number);
		long long base = 1,decimal = 0;
		for (int i = len-1; i >=0; i--){
			if(number[i] == '1')
				decimal = decimal + base;
			base = base*2;
		}
		printf("%lli\n",decimal);
	}
}