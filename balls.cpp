#include<bits/stdc++.h>
using namespace std;

bool check(long long n, long long k){
     long long sum = 0;
     long long curr = n;


     while(curr > 0){
          sum += min(curr,k);
          curr -= k;
          curr -= curr/10;
     }
     return 2*sum >= n;
}
long long get_k(long long n){

     long long k = n;
     long long lower = 1, higher = n;
     long long mid = 0;

     while(lower <= higher){
          mid = (lower + higher)/2;

          if(check(n,mid)){
               k = mid;
               higher = mid - 1;
          }else
               lower = mid + 1;
          std::cout << k << '\n';
     }
     return k;
}

int main(){
     long long n;
     cin >> n;
     cout << (get_k(n)) << endl;;
}
