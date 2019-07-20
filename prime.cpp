#include<bits/stdc++.h>
using namespace std;

int sumToPrime(int n){
     bool arr[1000+1];
     for(int i = 0; i <= 1000; i++)
          arr[i] = true;

     for(int p = 2; p*p <= 1000; p++){
          if(arr[p]){
               for(int i = p*p; i <= 1000; i += p)
                    arr[i] = false;
          }
     }

     if(n < 1000 && arr[n] == true)
          return 1;

     int total = 0;
     for(int i = 2; i <= 1000; i++){
          if(arr[i])
               total += i;
     }

     if(n > total || n <= 0)
          return -1;
     int *prime = new int[1000 + 1];

     int sum = 0;
     for(int i = 0; i <= 1000; i++){

          if(arr[i]){
               sum += i;
               prime[i] = sum;
          }
          else
               prime[i] = 0;
     }

     int count = 0;
     for(int i = 0; i <= 1000; i++){
          int number = 0;
          if(arr[i]){
               number = n - prime[i];
               count++;
          }
     }
}

int main(){
     int n;
     cin >> n;
     std::cout << sumToPrime(n) << '\n';
     return 0;
}
