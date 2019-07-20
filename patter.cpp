#include<iostream>
using namespace std;

int main(){
     int n;
     cin >> n;

     int count = 1;
     int number = 1, length = 1;
     while(count <= n){

          for(int i = count; i <n; i++)
               std::cout << ' ';

          int m = 0;

          for(int i = 0; i < length; i++){

               if(i + count <= number){
                    std::cout << i + count;
                    m = i + count;
               }
               else{
                    std::cout << m-1;
                    m--;
               }
          }
          count++;
          length += 2;
          number += 2;
          std::cout << '\n';
     }
     return 0;
}
