#include<bits/stdc++.h>
using namespace std;

int main(){

      int t;
      cin >> t;

      while(t--){

          long long n;
          cin >> n;

          long long arr[n];

          for(long long i = 0; i < n; i++)
            cin >> arr[i];

          sort(arr, arr + n);

          long long max_sum = 0;
          long long sum = arr[0];
          for(long long i = 1; i < n; i++){

                sum += arr[i];
                max_sum += sum;
          }

          std::cout << max_sum << '\n';

          /*
          for(int i = 0; i < n; i++)
              std::cout << arr[i] << ' ';
          std::cout  << '\n';

          */
      }
}
