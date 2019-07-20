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
                  cin >> arr[i][j];
            }

            int no_of_diagonals = 2*(n-1) + 1;

            std::cout << arr[0][0] << " ";

            int i_th_diagonal = 2;
            int i = 0;
            int j = i + 1;
            int cc = 0;
            for(int k = 1; k <= no_of_diagonals; k++){

                      if(k <= n -1){
                         i = 0;
                         j = k;
                      }else{

                              i = cc;
                              j = n - 1;
                      }

                    for(int m = 1; m <= i_th_diagonal; m++){

                            std::cout << arr[i][j] << " ";
                            i++;
                            j--;
                    }

                    if(k >= n - 1){
                      i_th_diagonal--;
                      cc++;
                    }
                    else
                      i_th_diagonal++;
            }

            std::cout  << '\n';
      }
}
