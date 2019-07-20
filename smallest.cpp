#include<bits/stdc++.h>
using namespace std;

int main(){

      int t;
      cin >> t;

      while(t--){

            int s,d;
            cin >>s >> d;

            int arr[d];

            if(s == 0 && d > 0){
              std::cout << -1 << '\n';
            }

            else if(s == 0 && d == 1)
              std::cout << 0 << '\n';

            else if(s > 9*d)
                std::cout << -1 << '\n';


            else{

                s = s - 1;

                  for(int i = d-1; i >= 0; i--){

                        if(s >= 9){

                              arr[i] = 9;
                              s -= 9;
                        }
                        else{
                            arr[i] = s;
                            s = 0;
                        }
                  }

                  arr[0] = arr[0] + 1;

                 for(int i = 0; i < d; i++)
                      std::cout << arr[i];
                  std::cout  << '\n';
            }
      }
}
