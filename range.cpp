#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin >> t;

     while(t--){

          int x,lower, upper;
          cin >> x;
          cin >> lower >> upper;

          long long count = 0;

          for(int i = lower + 1; i < upper; i++){
               int number = i;

               while(number != 0){
                    if(number%10 == x)
                         count++;
                    number = number/10;
               }
          }

          std::cout << count << '\n';
     }
}
