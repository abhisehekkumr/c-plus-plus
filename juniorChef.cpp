#include<bits/stdc++.h>
using namespace std;

int main(){

      int t;
      cin>>t;

      while(t--){

            long long n;
            cin>>n;

            long long max = 0,element;

            for(long long i = 0; i < n; i++){

                    cin>>element;
                    max = max > element ? max : element;
            }

            std::cout << max << '\n';
      }
}
