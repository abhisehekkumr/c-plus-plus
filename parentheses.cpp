#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin >> t;

     while(t--){
          string str;
          cin >> str;

          stack<int> s;
          int n = str.length();
          int result = 0;
          s.push(-1);

          for(int i = 0; i < n; i++){
               if(str[i] == '(')
                    s.push(i);
               else{
                    s.pop();
                    if(!s.empty())
                         result = max(result, i - s.top());
                    else
                         s.push(i);
               }
          }

          std::cout << result << '\n';
     }
}
