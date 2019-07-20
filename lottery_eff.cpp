#include<bits/stdc++.h>
using namespace std;


int diffence(int arr[], int size, int sum){
     int s = 0;

     for(int i = 0; i < size; i++)
          s += arr[i];
     //std::cout << s << " " << sum << '\n';
     return sum - s;
}

void print(int arr[], int size){

     for(int i = 0; i < size; i++)
          std::cout << arr[i];
     std::cout << '\n';
}

void append(int arr[], int size, int location, int number){

     if(location == 1 && arr[location] == 0){
          arr[location] = number;
          return;
     }
     for(int  i = location; i < size; i++)
          arr[i - 1] = arr[i];

     arr[size - 1] = number;
}

void lottery(int arr[], int size, int sum){
     int displacement = 1;
     int location = size-1;

     while(sum - displacement){

          int diff = sum - displacement;

          if(diff > 9)
               arr[location] = 9;
          else
               append(arr,size,location,diff);

          location--;

          if(diff > 9)
               displacement += 9;
          else
               displacement += diff;

          //print(arr,size);
     }

     print(arr,size);
}

int main(){
     int sum,digit;

     cin >> sum >> digit;

     int digits[digit] = {0};
     digits[0] = 1;
     lottery(digits,digit,sum);
}
