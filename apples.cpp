#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
  int t;
  cin>>t;

  while(t--){

    int apple, orange, gold;
    cin>>apple>>orange>>gold;
    int diff = abs(apple - orange);

    if(diff == 0)
      std::cout << 0 << '\n';
    else if(gold >= diff)
      std::cout << 0 << '\n';
    else
      std::cout << diff - gold << '\n';
  }
}
