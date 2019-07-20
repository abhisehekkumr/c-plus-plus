#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin >> t;

     while(t--){

          int n,p;
          cin >> n >> p;

          int i = n;

          while(p){

               i++;
               if(i == 12)
                    i = 0;
               p--;
          }

          std::cout << i << '\n';
     }
}
