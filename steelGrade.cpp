#include<iostream>
using namespace std;

int main(){
  int t;
  cin>>t;

  while(t--){
    double hardness, carbon, tensile;
    cin>>hardness>>carbon>>tensile;

    if(hardness > 50 && carbon < 0.7 && tensile > 5600)
        std::cout << 10 << '\n';
    else if( hardness > 50 && carbon < 0.7)
        std::cout << 9 << '\n';
    else if(carbon < 0.7 && tensile > 5600)
        std::cout << 8 << '\n';
    else if(hardness > 50 && tensile > 5600)
        std::cout << 7 << '\n';
    else if(hardness > 50 || carbon < 0.7 || tensile > 5600)
        std::cout << 6 << '\n';
    else
        std::cout << 5 << '\n';
  }
}
