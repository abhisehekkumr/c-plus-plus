#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;

	cin>>t;

	while(t--){

				long long number,first,second,k;
				cin>>number >> first >> second >> k;

				long long gc = __gcd(first,second);

				long long count = number/first + number/second - 2*( number/(first*second/gc ));

				if(count >= k)
					std::cout << "Win" << '\n';
				else
					std::cout << "Lose" << '\n';
	}
}
