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


          for(int i = count; i <= length; i++){
               if(i <= number){
                    std::cout << i;
               }
          }
          count++;
          length += 2;
          number += 2;
          std::cout << '\n';
     }
     return 0;
}
