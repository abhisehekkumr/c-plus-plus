#include<bits/stdc++.h>
using namespace std;

int main(){

      int t;
      cin >> t;

      while(t--){
          int n;
          cin >> n;

          int arr[n][n];

          for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++)
                cin >> arr[j][i];
          }


          for(int i = 0; i < n; i++){
            for(int j = n-1; j >= 0; j--)
                std::cout << arr[i][j] << " ";
          }

          std::cout  << '\n';
      }
}
