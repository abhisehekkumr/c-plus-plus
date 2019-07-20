#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin >> t;

     while(t--){
          int n;
          cin >> n;

          int arr[n];

          for(int i = 0; i < n; i++)
               cin >> arr[i];

          bool flag  = true;
          for(int i = 0; i < n; i++){
               int index = arr[i]%n;
               arr[index] += n;

               if(arr[index]/n == 2){
                    std::cout << index << ' ';
                    flag = false;
               }
          }

          if(flag)
               std::cout << -1;
          std::cout  << '\n';
     }
}
