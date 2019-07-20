#include<bits/stdc++.h>
using namespace std;

int lpsc(string s){
     int count = 0;
     int n = s.length();
     for(int i = 0; i < n; i++){

          // odd length
          int left = i;
          int right = i;
          while(left >= 0 && right < n && s[left] == s[right]){
               count++;
               left--;
               right++;
          }

          // even length
          left = i;
          right = i + 1;
          while(left >= 0 && right < n && s[left] == s[right]){
               count++;
               left--;
               right++;
          }
     }
     return count;
}

int main(){
     string s = "gqowffwncf";
     std::cout << lpsc(s) << '\n';
     return 0;
}
