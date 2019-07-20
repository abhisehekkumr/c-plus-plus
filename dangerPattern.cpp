#include<iostream>
using namespace std;

int main(){

     int n;
     cin >> n;

     int count = 1,start = 0;
     bool flag = true;
     int first = 0;

     if(n%2 == 1)
          first = n/2 + 1;
     else
          first = n/2;

     while(count <= n){

          if(flag){
               for(int i = start*n + 1; i < (start*n + 1 + n); i++)
                    std::cout << i << ' ';
               start += 2;

               if(first == count){

                    if(n%2 == 0)
                         start += 1;
                    else
                         start -= 1;
                    flag = false;
               }

          }else{

               start -= 2;
               for(int i = start*n + 1; i < (start*n + 1 + n); i++)
                    std::cout << i << ' ';
          }

          std::cout << '\n';
          count++;
     }
}
