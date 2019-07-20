#include<bits/stdc++.h>
using namespace std;

int main(){

      int t;
      cin >> t;

      while(t--){

            int n, k;
            cin >> n >> k;

            int arr[n];

            for(int i = 0; i < n; i++)
                cin >> arr[i];


            int position = 0, i = 0;

            for(i = 0; i < n; i++){

                  int sum = 0;
                  int count = 1;

                  for(int j = i; j  < n; j++){

                        sum += floor(arr[j]/count);
                        count++;

                        if(sum > k)
                            break;
                  }

                  if(sum  <= k){
                    position = i + 1;
                    break;
                  }
            }

            if(i < n)
                std::cout << position << '\n';
            else
                std::cout << n + 1 << '\n';
      }
}
