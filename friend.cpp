#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin >> t;

     while (t--) {

          int n, count = 0;
          cin >> n;
          string s;
          char x;
          cin >> s >> x;
          //std::cout << s << " " << x << '\n';
          unsigned int size = pow(2,n);
          //int arr[size];

          for(int i = 0; i < size; i++){
               string str = "";
               for(int j = 0; j < n; j++){

                    if(i & ( 1 << j))
                         str += s[j];
               }

               //std::cout << str << '\n';
               for(int j = 0; j < str.size(); j++){
                         //std::cout << str[j] << '\n';
                    if(str[j] == x){
                         count++;
                         std::cout << str << '\n';
                         break;
                    }
               }
          }

          std::cout << count << '\n';
     }


}
