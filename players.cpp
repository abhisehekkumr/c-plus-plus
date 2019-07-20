#include<bits/stdc++.h>
using namespace std;

int main(){
     int n;
     cin >> n;

     int arr[n];

     for(int i = 0; i < n; i++)
          cin >> arr[i];

     int count = 0;

     for(int i = n-1; i >= 0; i--){

          if(i-1 >= 0 && arr[i-1] == i + 1 && arr[i] != i+ 1){
               swap(arr[i-1], arr[i]);
               count++;
               //std::cout << arr[i] << '\n';
          }

          else if(i - 2 >= 0 && arr[i - 2] == i + 1 && arr[i] != i+ 1){
               arr[i-2] = arr[i-1];
               arr[i-1] = arr[i];
               arr[i] = i + 1;
               count += 2;
               //std::cout << arr[i] << '\n';
          }

          if(arr[i] != i + 1){
               std::cout << "NO" << '\n';
               return 0;
          }
     }

     std::cout << "YES" << '\n';
     std::cout << count << '\n';
}
