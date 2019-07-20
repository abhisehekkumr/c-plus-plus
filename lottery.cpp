#include<bits/stdc++.h>
using namespace std;


bool check(int digits[], int size, int sum){
     int s = 0;

     for(int i = 0; i < size; i++)
          s += digits[i];

     if(s == sum)
          return true;

     return false;
}


void print(int arr[], int size){

     for(int i = 0; i < size; i++)
          std::cout << arr[i];
     std::cout << '\n';
}

void incrementDigit(int arr[], int size){

     int carry = 0;
     int i = size - 1;
     int result = arr[i] + 1 + carry;
     arr[i] = result%10;
     carry = result/10;
     i--;
     while(i >= 0){
          int result = arr[i] + carry;
          arr[i] = result%10;
          carry = result/10;
          i--;
     }

     //print(arr,size);
}


int main(){
     int s,d;
     cin >> s >> d;

     int digit[d] = {0};
     digit[0] = 1;

     while(true){

          if(check(digit,d,s)){
               print(digit,d);
               break;
          }

          incrementDigit(digit,d);
     }
}
