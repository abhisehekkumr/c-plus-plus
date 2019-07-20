#include<iostream>
using namespace std;


void func(int i, int &j, int p){
  i++;
  j++;
  p++;
}
int main(){

      int i = 10;
      int j = 6;
      int &p = i;
      func(i,j,p);
      std::cout << i << " " << j << " " << p;
}
