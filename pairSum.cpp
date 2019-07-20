#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin >> t;

     while(t--){
          int n,k;
          cin >> n;

          int arr[n];

          for(int i = 0; i < n; i++)
               cin >> arr[i];

          cin >> k;

          int i = 0, j = n-1, element = -1;

          while(true){

               if(i == j || (j == i - 1))
                    break;

               if(arr[i] + arr[j] == k){
                    std::cout << arr[i] << " " << arr[j] << " " << k << '\n';
                    i++;
                    j--;
                    element++;
               }

               if(arr[i] + arr[j]  > k)
                    j--;

               if(arr[i]  + arr[j] < k)
                    i++;

          }

          if(element == -1)
               std::cout << -1 << '\n';
     }
}
