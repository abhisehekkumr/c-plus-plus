#include<iostream>
using namespace std;

bool check(char input[]){

     if(input[0] == '\0')
        return true;

        std::cout << "/* message */" << '\n';
    if(input[0] == 'a'){
         std::cout << input[0] << '\n';
        check(input + 1);
   }

    else if(input[0] == 'b' && input[1] == 'b'){
         std::cout << input[0] << '\n';
        check(input + 2);
   }

    else
        return false;
}

bool checkAB(char input[]) {

   if(input[0] == 'a')
       return checkAB(input + 1);
    return false;
}

int main(){

     char arr[100];
     cin >> arr;
     std::cout << arr << '\n';
     std::cout << checkAB(arr) << '\n';
}
