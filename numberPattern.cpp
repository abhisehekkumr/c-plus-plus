#include<iostream>
using namespace std;

int main(){

     int n;
     cin >> n;

     int count = 1;

     while(count <= n){

          for(int i = 1; i <= count; i++)
               std::cout << i;

          int skip = 2*n - 2*count;
          for(int i = 1; i <= skip; i++)
               std::cout << " ";

          for(int i = count; i > 0; i--)
               std::cout << i;
          std::cout << '\n';
          count++;
     }
     return 0;
}
