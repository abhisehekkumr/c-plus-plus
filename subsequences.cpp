#include<iostream>
using namespace std;

int power(int x, int n){
     int res = 1;

     while(n){
          if(n & 1)
               res = res * x;
          x = x * x;
          n = n >> 1;
     }
     return res;
}


int subs(string input, string output[]){

     if(input.empty()){
          output[0] = "";
          return 1;
     }

     string str = input.substr(1);
     int smallOutput = subs(str, output);

     for(int i = 0; i < smallOutput; i++){
          output[i + smallOutput] = input[0] + output[i];
     }

     return 2*smallOutput;
}

int main(){
     string input;
     cin >> input;

     string *output = new string[power(2,input.size())];
     int count = subs(input, output);
     for(int i = 0; i < count; i++)
          std::cout << output[i] << '\n';
}
