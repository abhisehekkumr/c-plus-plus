#include<iostream>
using namespace std;

int main(){

     int n;
     cin >> n;

     int row = 2*n-1;


     int count = 1;
     int spaces = row-2;
     int k  = n;
     bool flag = false;
     while(count <= row){
          int i;

          for( i = n; i >= k; i--)
               std::cout << i << ' ';

          for(int j = 1; j <= spaces; j++)
               std::cout << i+1 << ' ';

          if(k == 1){
               i = 1;
               flag = true;
          }
          for(int j = i + 1; j <= n; j++)
               std::cout << j << ' ';
          std::cout << '\n';


          if(flag){
               k++;
               spaces += 2;
          }
          else{
               k--;
               spaces -= 2;
          }
          count++;
     }
     return 0;
}
