#include<iostream>
using namespace std;

void print(int input, string output, string digits[]){

     if(input == 0){
          std::cout << output << '\n';
          return;
     }

     string number;
     int n;

     if(input < 10)
          n = input;
     else
          n = input%10;

     number = digits[n];

     for(int i = 0; i < number.size(); i++)
          print(input/10, number[i] + output, digits);
}

int main(){
     int number;
     cin >> number;

     string digit[10];

     digit[1] = ",.?!";
     digit[2] = "abc";
     digit[3] = "def";
     digit[4] = "ghi";
     digit[5] = "jkl";
     digit[6] = "mno";
     digit[7] = "pqrs";
     digit[8] = "tuv";
     digit[9] = "wxyz";

     bool flag = true;
     int n = number;

     while(n){
          if(n%10 == 0 || n%10 == 1){
               flag = false;
               break;
          }
          n = n/10;
     }

     if(flag)
          print(number,"",digit);
     else
          std::cout << "" << '\n';
}
