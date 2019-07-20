#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;

  while(t--){

        int number;
        cin >> number;

        int reverse = 0, num = 0;

        while(number != 0){
          int mode = number%10;

          if(mode == 0)
            reverse = reverse*10 + 5;
          else
            reverse = reverse*10 + mode;
          number = number/10;
        }

        while(reverse != 0){
          num = num*10 + reverse%10;
          reverse = reverse/10;
        }

        std::cout << num << '\n';
  }
}
