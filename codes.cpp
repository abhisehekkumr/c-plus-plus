#include<iostream>
using namespace std;

int codes(string number, string output[]){

     if(number.length() == 0){
          output[0] = "";
          return 1;
     }

     string smallOutput1[1000];
     string smallOutput2[1000];

     int size1 = 0, size2 = 0;

     size1 = codes(number.substr(1), smallOutput1);
     int n = number[0] - '0';
     char c = n + 'a' - 1;
     for(int i = 0; i < size1; i++)
          output[i] = c + smallOutput1[i];

     if(number[1] != '\0'){

          int n = (number[0] - '0')*10 + (number[1] - '0');
          char c = n + 'a' - 1;

          if(n >= 10 && n <= 26){
               size2 = codes(number.substr(2), smallOutput2);

               for(int i = 0; i < size2; i++)
                    output[i + size1] = c + smallOutput2[i];
          }
     }
     return size1 + size2;
}


void getCodes(string number, string output){

     if(number.size() == 0){
          std::cout << output << '\n';
          return;
     }

     string second_output = output;
     int n = number[0] - '0';
     char c = n + 'a' - 1;
     output = output + c;
     getCodes(number.substr(1), output);

     if(number[1] != '\0'){
          int n = (number[0] - '0')*10 + (number[1] - '0');
          char c = n + 'a' - 1;
          if(n >= 10 && n <= 26){
               second_output = second_output + c;
               getCodes(number.substr(2), second_output);
          }
     }
}
int main(){
     string number;
     cin >> number;
/*
     string *output = new string[1000];
     int size = codes(number, output);

     for(int i = 0; i < size; i++)
          std::cout << output[i] << '\n';
*/

     getCodes(number,"");
}
