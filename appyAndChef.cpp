#include<iostream>
using namespace std;

int main(){
  int t;
  cin>>t;

  while(t--){
    long long n,a,b,k;
    cin>>n>>a>>b>>k;

    long long count = 0;
    for(long long i=1; i<=n; i++){

      if(i%a == 0 && i%b != 0)
        count++;
      else if(i%a != 0  && i%b == 0)
        count++;
    }

    if(count >= k)
      std::cout << "Win" << '\n';
    else
      std::cout << "Lose" << '\n';
  }
}
