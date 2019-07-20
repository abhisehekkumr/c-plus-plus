#include<iostream>
using namespace std;

int power(int number){

     if(number == 0)
          return 1;
     return 3*power(number/10);
}

int subs(int input, string output[], string digit[]){

     if(input < 10){
          string number = digit[input];

          for(int i = 0; i < number.size(); i++)
               output[i] = number[i];
          return number.length();
     }

     int smallOutput = subs(input/10, output, digit);
     string number = digit[input%10];

     for(int i = 0; i < smallOutput; i++){
          string str = output[i];
          output[i] = str + number[0];
          int jump = smallOutput;

          for(int j = 1; j < number.size(); j++){
               output[i + jump] = str + number[j];
               jump += smallOutput;
          }
     }
     return number.size()*smallOutput;
}

int main(){
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

     int number;
     cin >> number;

     int n = number;
     bool flag = true;
     while(n){
          if(n%10 == 1 || n%10 == 0){
               flag = false;
               break;
          }
          n = n/10;
     }


     if(flag){
          string *output = new string[power(number)];

          int count = subs(number, output, digit);
          for(int i = 0; i < count; i++)
               std::cout << output[i] << '\n';
     }else
          std::cout << "" << '\n';
}
