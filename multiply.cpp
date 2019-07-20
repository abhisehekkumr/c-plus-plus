#include<bits/stdc++.h>
using namespace std;


long long power(long long a, long long b, long long c){

      long long res = 1;
      a = a%c;

      while(b){

            if(b & 1)
                res = (res%c * a%c)%c;
            a = (a%c * a%c)%c;
            b = b >> 1;
      }

      return res;
}
int main(){

      int t;
      cin >> t;

      while(t--){

            long long a,b,c;
            cin >> a >> b >> c;
            std::cout << power(a,b,c) << '\n';
      }
}
