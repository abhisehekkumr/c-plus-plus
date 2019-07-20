#include<iostream>
using namespace std;

int max(int a, int b){
     return a > b ? a : b;
}

int maxProfit(int weights[], int value[], int n, int max_weight){

     if(n == 0)
          return 0;

     if(max_weight < 0)
          return 0;

     int ans1 = maxProfit(weights+1,value+1,n-1,max_weight);
     int ans2 = 0;
     if(max_weight - weights[0] >= 0)
          ans2 = maxProfit(weights+1,value+1,n-1,max_weight - weights[0]) + value[0];
     return max(ans1,ans2);
}

int sackDP(int weights[], int value[], int n, int max_weight, int **dp){
     //std::cout << n << '\n';
     if(n == 0)
          return 0;

     if(max_weight < 0)
          return 0;

     if(dp[n][max_weight] > 0)
          return dp[n][max_weight];

     int ans1 = sackDP(weights+1,value+1,n-1,max_weight,dp);
     int ans2 = 0;
     if(max_weight - weights[0] >= 0)
          ans2 = sackDP(weights+1,value+1,n-1,max_weight-weights[0],dp) + value[0];
     dp[n][max_weight] = max(ans1,ans2);
     return dp[n][max_weight];
}

int KnapSackEfficient(int weights[], int value[], int n, int max_weight){

     int **dp = new int*[2];
     dp[0] = new int[max_weight+1];
     dp[1] = new int[max_weight+1];

     for(int i = 0; i < 2; i++){
          for(int j = 0; j <= max_weight; j++)
               dp[i][j] = 0;
     }

     int i = 0;
    while (i < n)
    {
        int j = 0;

        if (i%2!=0)
        {
            while (++j <= max_weight)
            {
                if (weights[i] <= j)
                    dp[1][j] = max(value[i] + dp[0][j-weights[i]],
                                    dp[0][j] );
                else
                    dp[1][j] = dp[0][j];
            }

        }

        else
        {
            while(++j <= max_weight)
            {
                if (weights[i] <= j)
                    dp[0][j] = max(value[i] + dp[1][j-weights[i]],
                                     dp[1][j]);
                else
                    dp[0][j] = dp[1][j];
            }
        }
        i++;
    }

    return (n%2 != 0)? dp[0][max_weight] : dp[1][max_weight];
}


int extreme(int weights[], int value[], int n, int max_weight){

     int dp[max_weight+1];
     for(int i = 0; i <= max_weight; i++)
          dp[i] = 0;
     for(int i = 0; i < n; i++){
          for(int j = max_weight; j >= weights[i]; j--)
               dp[j] = max(dp[j], value[i] + dp[j-weights[i]]);
     }
     return dp[max_weight];
}

int main(){
     int n;
     cin >> n;

     int weights[n];
     for(int i = 0; i < n; i++)
          cin >> weights[i];

     int value[n];
     for(int i = 0; i < n; i++)
          cin >> value[i];

     int max_weight;
     cin >> max_weight;

     //std::cout << maxProfit(weights,value,n,max_weight) << '\n';

     /*int **dp = new int*[n+1];
     for(int i = 0; i <= n; i++){
          dp[i] =  new int[max_weight+1];
          for(int j = 0; j <= max_weight; j++)
               dp[i][j] = 0;
     }
     std::cout << sackDP(weights,value,n,max_weight,dp) << '\n';
     */
     std::cout << extreme(weights,value,n,max_weight) << '\n';
}
