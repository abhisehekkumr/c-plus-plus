#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin >> t;

     while(t--){
          int n, s;
          cin >> n >> s;

          int arr[n];

          for(int i = 0; i < n; i++)
               cin >> arr[i];

          int sum = 0, first = 0, second = 0;
          bool flag = false;

          for(int i = 0; i < n; i++){

               sum += arr[i];
               
               while(sum > s){
                    sum -= arr[first];
                    first++;
               }

               if(sum == s){
                    first++;
                    second = i + 1;
                    flag = true;
                    break;
               }
          }

          if(flag)
               std::cout << first << " " << second << '\n';
          else
               std::cout << -1 << '\n';
     }
}
