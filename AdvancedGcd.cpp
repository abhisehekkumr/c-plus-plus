#include<iostream>
using namespace std;

int gcd(int a, int b){

     if(b == 0)
          return a;
     return gcd(b,a%b);
}

int main(){
     int t;
     cin >> t;

     while(t--){
          int a;
          string b;

          cin >> a >> b;
          int number = 0;

          int i = 0;
          while(b[i] != '\0'){
               number = (number*10 + (b[i] - '0'))%a;
               i++;
          }

          cout << gcd(a,number) << endl;
     }
}
