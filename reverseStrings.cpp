#include<iostream>
#include<cstring>
using namespace std;

void reverseStrings(char str[]){

     int i = 0;
     while(str[i] != '\0'){
          int k = i;
          //std::cout << "/* message */" << '\n';
          while(str[k] != ' ' &&   str[k] != '\0'){
               //std::cout << i << " " << k << '\n';
               k++;
          }

          int distance = k - i;
          int m = k-1;
          for(int j = i; j < i + distance/2; j++){
               char c = str[j];
               str[j] = str[m];
               str[m] = c;
               m--;
          }

          if(str[k] == '\0'){
               //std::cout <<str << '\n';
               return;
          }

          i = k + 1;
     }

     //std::cout << str << '\n';
}

int main(){

     char arr[1000];
     cin.getline(arr , 1000);
     //std::cout << arr << '\n';
     reverseStrings(arr);
     std::cout << arr << '\n';
}
