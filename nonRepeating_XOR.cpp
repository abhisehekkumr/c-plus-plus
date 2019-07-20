#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin >> t;

     while(t--){
          int n;
          cin >> n;
          int size = 2*n + 2;

          int arr[size];

          int xor_1 = 0;
          for(int i = 0; i < size; i++){
               cin >> arr[i];
               xor_1 = xor_1^arr[i];

          }

          int set_bit = xor_1 & ~(xor_1 - 1);

          int x = 0, y = 0;

          for(int i = 0; i < size; i++){

               if(arr[i] & set_bit)
                    x = x^arr[i];
               else
                    y = y^arr[i];
          }

          if(x < y)
               std::cout << x << " " << y << '\n';
          else
               std::cout << y <<" " << x << '\n';
     }
}
