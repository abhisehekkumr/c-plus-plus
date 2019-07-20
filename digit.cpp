#include<bits/stdc++.h>
#include<string>
using namespace std;

int main(){

  int t;
  cin >> t;

  while(t--){

        string str,d;
        cin >> str >> d;

        string min = str;
        string extended = str + d;


        for(int i = 0; i < str.length(); i++){

              string copy = extended;

              for(int j = 0; j < copy.length(); j++){
                  string strimmed = copy.erase(j,1);
                  copy = extended;

                  if(min > strimmed)
                      min = strimmed;
              }

              extended = min + d;
        }

        std::cout << min << '\n';

  }
  return 0;
}
