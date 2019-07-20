#include<bits/stdc++.h>
using namespace std;

int main(){
     int n;
     cin >> n;

     int arr[n];

     for(int i = 0; i < n; i++)
          cin >> arr[i];

     sort(arr, arr + n, greater<int>());

     int a = 0, b = 0, c = 0;

     for(int i = 0; i < n - 3; i++){

          if(arr[i] < arr[i + 1] + arr[i+ 2] &&
             arr[i] < arr[i + 1] + arr[i+ 2] &&
             arr[i] < arr[i + 1] + arr[i+ 2]){

                  if(c < arr[i] || a > arr[i + 2]){
                  a = arr[i];
                  b = arr[i + 1];
                  c = arr[i + 2];
             }
             }
     }

     if(a && b && c)
          std::cout  << a << " " << b << " " << c << '\n';
     else
          std::cout << -1 << '\n';

}
