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

          int new1[n];
          sort(arr,arr+n);

          int j = 0, k = n -1;
          for(int i = n-1; i >= 0; i--){
               if(arr[i]%2)
                    new1[j++] = arr[i];
               else
                    new1[k--] = arr[i];
          }

          for(int i = 0; i < n; i++)
               std::cout << new1[i] << ' ';
          std::cout << '\n';
     }
}
