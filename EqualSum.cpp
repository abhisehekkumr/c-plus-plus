#include<iostream>
using namespace std;

int main(){
     int t;
     cin >> t;

     while(t--){
          int n;
          cin >> n;

          int arr[n], left[n], right[n];

          for(int i = 0;i < n; i++){
               cin >> arr[i];
          }

          left[0] = arr[0];

          for(int i = 1; i < n; i++)
               left[i] = left[i-1] + arr[i];

          right[n-1] = arr[n-1];
          for(int i = n-2; i >= 0; i--)
               right[i] = right[i + 1] + arr[i];

          /*
          for(int i = 0; i < n; i++)
               std::cout << left[i] << ' ';
          std::cout  << '\n';

          for(int i = 0; i < n; i++)
               std::cout << right[i] << ' ';
          std::cout  << '\n';
          */

          bool flag = true;
          for(int i = 0; i < n; i++){
               if(left[i] == right[i]){
                    std::cout << "YES" << '\n';
                    flag = false;
                    break;
               }
          }

          if(flag)
               std::cout << "NO" << '\n';
     }
}
