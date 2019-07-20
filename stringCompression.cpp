#include<bits/stdc++.h>
using namespace std;

string compress(string str){
     string ans = "";

     int i = 0;
     //bool flag = false;
     while(i < str.length()){

          char c = str[i];
          int count = 1;

          while(str[i + 1] == c){
               count++;
               i++;
               //flag = true;
               //std::cout << "/* message */" << '\n';
          }

          if(count > 1)
               ans = ans + c + to_string(count);
          else
               ans = ans + c;
          i++;
     }
     return ans;
}


// You need to update in the given string itself i.e. in input. No need to return or print.

void stringCompression(string str) {

    //string ans = "";

     int i = 0;
     //bool flag = false;
     while(str[i] != '\0'){

          char c = str[i];
          int count = 1;

          while(str[i + 1] == c){
               count++;
               i++;
               //flag = true;
               //std::cout << "/* message */" << '\n';
          }

          if(count > 1){

              std::cout << c << (char)(48 + count);
          }
          else{
               std::cout << c;
          }
          i++;
     }

    std::cout << '\n';
}

int main(){
     string str;
     cin >> str;
     stringCompression(str);
     //cout << "result" << (char)(48 + 6) << "hey" << endl;
     return 0;
}
