#include<iostream>
using namespace std;


void print(int p){
  std::cout << p << " ";
}
int main(){
  int i = 10;
  int &p = i;

  print(p++);
  std::cout << iz << '\n';

}
