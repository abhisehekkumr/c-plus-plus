#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin >> t;
     while(t--){
          int n, k;
          cin >> n >> k;
          int arr[n];
          for(int i = 0; i < n; i++)
               cin >> arr[i];

          int count[101];
          for(int i = 0; i <= 100; i++)
               count[i] = 0;

          for(int i = 0; i <= n - k; i++){

               for(int j = i; j < i+k; j++){

                    if(j < n){
                         count[arr[j]]++;
                    }
               }

               int c = 0;
               for(int j = 0; j <= 100; j++){
                    if(count[j])
                         c++;
                    count[j]= 0;
               }

               std::cout << c << ' ';
          }
          std::cout << '\n';
     }
}
