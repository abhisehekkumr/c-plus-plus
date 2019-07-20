#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

          long long n, positive = 0, negative = 0, element = 0;
          cin >> n;
          for(int i = 0; i < n; i++){
            cin >> element;

            if(element >= 0)
                positive++;
            else
                negative++;
          }

          //std::cout << "positve : " << positive << " " << "negative : " << negative << '\n';

          if(positive == 0 || negative == 0){
            long long result = positive > negative ? positive : negative;
            std::cout << result << " " << result << '\n';
          }
          else if(positive > negative)
              std::cout << positive << " " << negative << '\n';
          else if(negative > positive)
              std::cout << negative << " " << positive << '\n';
          else{

              long long result = positive > negative ? positive : negative;
              std::cout << result << " " << result << '\n';
          }
    }
}
