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

          int max = 0;

          for(int i = 0; i < n; i++){
               for(int j = n-1; j > i; j--){

                    if(arr[i] <= arr[j]){
                         max = max > (j - i)  ? max : (j - i);
                         break;
                    }
               }
          }

          std::cout << max << '\n';
     }
}
