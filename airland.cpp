#include<bits/stdc++.h>
using namespace std;

int main(){

      int t;
      cin>>t;

      while(t--){

            int n;
            cin>>n;

            int attacks[n], defences[n];

            for(int i = 0; i < n; i++)
              cin>>attacks[i];

            for(int i = 0; i < n; i++)
              cin>>defences[i];

            int max = 0;

            for(int i = 1; i<n-1; i++){

                  if(attacks[i-1] + attacks[i + 1]  < defences[i])
                      max = max > defences[i] ? max : defences[i];
            }

            if(attacks[1] + attacks[n-1]  < defences[0])
              max = max > defences[0] ? max : defences[0];

            if(attacks[n-2] + attacks[0] < defences[n-1])
              max = max > defences[n-1] ? max : defences[n-1];

            if(max)
                std::cout << max << '\n';
            else
                std::cout << -1 << '\n';
      }
}
