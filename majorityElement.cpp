#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin >> t;

     while(t--){
          int n;
          cin >> n;

          int arr;
          int count[1000000];
          memset(count, 0, 1000000);

          int majority = n/2;
          int element = -1;
          for(int i = 0; i < n; i++){
               cin >> arr;

               count[arr]++;

               if(count[arr] > majority)
                    element = arr;
          }

          std::cout << element << '\n';
     }
}
