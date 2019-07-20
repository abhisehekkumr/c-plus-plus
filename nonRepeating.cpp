#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
     int t;
     cin >> t;

     while(t--){
          int n;
          cin >> n;

          int arr[2*n + 2];

          for(int i = 0; i < (2*n + 2); i++)
               cin >> arr[i];

          sort(arr,(arr + 2*n + 2));

          for(int i = 0; i < (2*n + 2 - 1); i++){

               if(arr[i] != arr[i + 1])
                    std::cout << arr[i] << ' ';
               else
                    i++;
          }

          if(arr[2*n + 1] != arr[2*n])
               std::cout << arr[2*n + 1] << ' ';
          std::cout  << '\n';
     }
}
