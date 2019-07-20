#include<bits/stdc++.h>
#include<cmath>
using namespace std;

void getPrime(int arr[], int n){

     for(int p = 2; p*p <= n; p++){

          if(arr[p]){
               for(int i = p*p; i <= n; i+= p)
                    arr[i] = 0;
          }
     }
}

int getIndex(int number, int arr[]){

     int result = (int)sqrt(number);
     int index = number;
     for(int i = number; i >= 0; i--){

          if(arr[i] && arr[i] < number){
               index = i;
               break;
          }
     }
     return index;
}

long long power(int  a, int p){
     long long res = 1;

     while(p != 0){

          if( p & 1)
               res = res*a;
          a = a*a;
          p = p >> 1;
     }

     return res;
}

int main(){

     int t;
     cin >> t;


     while(t--){

               int n;
               cin >> n;
               bool flag = false;
               int num = -1;

               int nn = sqrt(n)  + 1;
               int arr[nn];
               memset(arr, 1, nn);
               getPrime(arr, nn);

               //int index = getIndex(n,arr);
               //cout << arr[23] << "tji ";
               for(int i = 2; i <= sqrt(n) + 10; i++){

                    long long result = 0;
                    for(int j = 2; j <= i; j++){

                              result = power(j,i);

                              if(result > n)
                                   break;
                              if(result <= n){
                                   std::cout << num << '\n';
                                   num = result;
                         }
                    }

                    if(result > n)
                         break;
               }
                    std::cout << num << '\n';
               }
}
