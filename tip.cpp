#include<iostream>
#include<climits>
using namespace std;

inline int max(int a, int b){
     return a > b ? a : b;
}

int maxTip(int a[], int b[], int x, int y, int n){
     if(n <= 0)
          return 0;

     if(x <= 0)
          return (maxTip(a,b,x,y-1,n-1) + b[n-1]);

     if(y <= 0)
          return (maxTip(a,b,x-1,y,n-1) + a[n-1]);

     int ans1 = maxTip(a,b,x-1,y,n-1) + a[n-1];
     int ans2 = maxTip(a,b,x,y-1,n-1) + b[n-1];
     //std::cout << ans1 << " " << ans2 << '\n';
     return max(ans1, ans2);
}



int dp(int a[], int b[], int x, int y, int n){
     int **arr = new int*[x+1];
     for(int i = 0; i <= x; i++){
          arr[i] = new int[y+1];
     }

     arr[0][0] = 0;
     for(int i = 1; i <= x; i++){
          arr[i][0] = (i <= n) ? arr[i-1][0] + a[i-1] : arr[i-1][0];
     }

     for(int i = 1; i <= y; i++){
          arr[0][i] = (i <= n) ? arr[0][i-1] + b[i-1] : arr[0][i-1];
     }

     for(int i = 1; i <= x; i++){
          for(int j = 1; j <= y; j++){
               if(i + j <= n)
                    arr[i][j] = max(arr[i-1][j] + a[i+j-1], arr[i][j-1] + b[i+j-1]);
          }
     }

     int tip = INT_MIN;
     for(int i = 0; i <= x; i++){
          for(int j = 0; j <= y; j++){
               if(i + j <= n)
                    tip = max(tip, arr[i][j]);
          }
     }
     return tip;
}

int main(){
     int t;
     cin >> t;

     while(t--){
          int n,x,y;
          cin >> n >> x >> y;

          int a[n],b[n];
          for(int i  = 0; i < n; i++)
               cin >> a[i];

          for(int i = 0; i < n; i++)
               cin  >> b[i];

          std::cout << dp(a,b,x,y,n) << '\n';
          //std::cout << maxTip(a,b,x,y,n) << '\n';
     }
}
