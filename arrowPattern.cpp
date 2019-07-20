#include<iostream>
using namespace std;

int main(){

     int n;
     cin >> n;

     int space  = 0;

     for(int i = 1; i <= (n + 1)/2; i++){

          for(int j = 1; j <= space; j++)
               std::cout << ' ';

          for(int j = 1; j <= i; j++)
               std::cout << "*" << " ";
          std::cout << '\n';
          space++;
     }

     space = n/2-1;

     for(int i = n/2; i >= 1; i--){

          for(int j = 1; j <= space; j++)
               std::cout << ' ';

          for(int j = 1; j <= i; j++)
               std::cout << "*" << " ";

          std::cout << '\n';
          space -= 1;
     }
     return 0;
}
