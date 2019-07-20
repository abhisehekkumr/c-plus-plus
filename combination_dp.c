#include<stdio.h>

int main(){
	int t;
	scanf("%d",&t);

	while(t--){
		int n,r;
		scanf("%d %d",&n,&r);

		long long arr[n+1][n+1];

		if( r > n || r == 0)
			printf("0\n");
		else if(r == n)
			printf("1\n");
		else{


			for(int i = 1; i<=n ; i++){

				for(int j = 1; j<=i; j++){
					
					if(i==j) 
					 	arr[i][j]=1;
            		else if(j==1) 
            			arr[i][j]=i;
					else{
						arr[i][j]=(arr[i-1][j-1]+arr[i-1][j])%(1000000000+7);
					}
				}
			}
			printf("%lli\n",arr[n][r]);
		}
	}
}