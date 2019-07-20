#include<iostream>
using namespace std;

int main(){
     string str = "abhiabhishekabhhishekkk";
     string s = "";
     int flag = 0;
     int i = 0;
     while(str[i] != '\0'){
          int bit = str[i] - 'a';

          if(((1 << bit) & flag) == 0){
               s = s + str[i];
               flag = flag | (1 << bit);
          }
          i++;
     }


     std::cout << s << '\n';
}
