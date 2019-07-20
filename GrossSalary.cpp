#include<iostream>
#include <iomanip>
using namespace std;

int main(){
  int t;
  cin>>t;

  while(t--){
    double salary,total;
    cin>>salary;

    if(salary < 1500)
      total = salary + 0.10*salary + 0.90*salary;
    else
      total = salary + 500 + 0.98*salary;
    std::cout << fixed << setprecision(2) << total << '\n';
  }
}
