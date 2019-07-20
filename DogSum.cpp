#include<iostream>
using namespace std;

int main(){
  int t;
  cin>>t;

  while(t--){
    long long d,n;
    cin>>d>>n;

    for(int i = 0; i < d; i++){
        n = (n*(n + 1))/2;
    }

    std::cout << n << '\n';
  }
}
