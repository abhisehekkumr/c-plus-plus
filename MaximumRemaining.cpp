#include<bits/stdc++.h>
using namespace std;


int main(){
          int n;
          cin >> n;

          int arr[n], max = 0;

          for(int i = 0; i < n; i++){
               cin >> arr[i];
          }

          sort(arr,arr + n);

          for(int i = 0; i < n; i++)
               max = max > arr[i]%arr[n-1] ? max : arr[i]%arr[n-1];

        std::cout << max << std::endl;
}
