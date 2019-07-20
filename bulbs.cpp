#include<bits/stdc++.h>
using namespace std;

int main(){
     long long n,x,y;
     cin >> n >> x >> y;
     string arr;
     cin >> arr;


     int flag = true;

     for(int i = 0; i < n; i++){

         if(arr[i] == '0'){
             flag = false;
             break;
         }
     }

     if(flag){
         cout << 0 << endl;
         return 0;
     }

     for(int i = 0; i < n; i++){

         if(arr[i] == '1'){
             flag = false;
             break;
         }
     }

     if(flag){
         cout << y << endl;
         return 0;
     }

     long long groups = 0;

     if(arr[0] == '0')
          groups = 1;

     for(int i = 0; i < n; i++){
          //std::cout << arr[i] << '\n';

          if(arr[i] == '1' && arr[i + 1] == '0'){
               groups++;
               //std::cout << groups << '\n';
          }
     }
     //std::cout << groups << '\n';
     std::cout << (groups - 1 )*min(x,y) + y << '\n';
}
