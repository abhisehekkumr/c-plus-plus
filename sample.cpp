#include<iostream>
using namespace std;
int main(){
  cout<<"Hello  Abhishek ,  welcome to c++ programming language\n";
  cout<<"size of character is "<<sizeof(char)<<endl;
  cout<<"size of integer is "<<sizeof(int)<<endl;
  cout<<"size of short is "<<sizeof(short)<<endl;
  cout<<"size of long is "<<sizeof(long long int)<<endl;
  cout<<"size of float is "<<sizeof(float)<<endl;
  cout<<"size of double is "<<sizeof(long double)<<endl;
  cout<<"This is integer pointe "<<sizeof(int *)<<endl;

  double a;
  cout<<"variable result "<<a<<endl;


  char ch = 'a';
  char *pointer = &ch;
  char *default_1;
  cout<<"pointer value *pointer "<<*pointer<<endl;
  cout<<"pointer value pointer "<<pointer<<endl;
  cout<<"actual variable value "<<&ch<<endl;
  cout<<"default valure of pointer "<<default_1<<endl;


  // declaring the typedef for integer and naming it with number
  typedef int number;
  number num = 3;
  cout<<"result of typedef number is "<<num<<endl;
}
