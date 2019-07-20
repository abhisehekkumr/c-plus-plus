#include<bits/stdc++.h>
using namespace std;

int main(){

        int n;
        cin >> n;

        while(n--){

                char c;
                int count = 0;
                cin >> c;
                while(c != '\n'){

                  count++;
                  std::cout << c << " ";
                  cin >> c;
                  if(count == 5)
                      break;
                }
                std::cout  << '\n';
                std::cout << "break" << '\n';
        }
}
