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

          for(int i = 0; i < n - 1; i++){
               if(arr[i] == arr[i + 1] + 1)
                    swap(arr[i],arr[i+1]);
          }

          bool flag = true;

          for(int i = 0; i < n -1; i++){

               if(arr[i] > arr[i + 1]){
                    flag = false;
                    break;
               }
          }

          if(flag)
               std::cout << "Yes" << '\n';
          else
               std::cout << "No" << '\n';
     }
}
