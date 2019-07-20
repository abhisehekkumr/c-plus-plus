#include<bits/stdc++.h>
using namespace std;

int main(){

      int t;
      cin >> t;

      while(t--){

            int m,n;
            cin >> n >> m;

            int arr[n][m];

            int val = 2;
            for(int i = 0; i < n; i++)
              arr[i][0] = val + i;
            for(int i = 0; i < m; i++)
              arr[0][i] = val + i;

            for(int i = 1; i < n; i++){
              for(int j = 1; j < m; j++){

                    arr[i][j] = arr[i-1][j] + arr[i][j-1];
              }
            }

            for(int i = 0; i < n; i++){
              for(int j = 0; j < m; j++)
                std::cout << arr[i][j] << " ";
              std::cout  << '\n';
            }
      }
}
