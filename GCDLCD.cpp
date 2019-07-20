#include<iostream>
//using namespace std;

int GCD(int a, int b){
  if(b == 0)
    return a;
  return GCD(b, a%b);
}
int main(){
  int t;
  std::cin>>t;

  while(t--){
    long long n,m;
    std::cin>>n>>m;
    long long gcd = GCD(n,m);
    std::cout <<gcd<<" "<<(m*n)/gcd << '\n';
  }
}
