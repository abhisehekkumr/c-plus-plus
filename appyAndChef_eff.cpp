#include<iostream>
using namespace std;


int main(){

			int t;
			cin>>t;

			while(t--){

						long long n,a,b,k;

						long long i,j,m;
						cin>>n>>a>>b>>k;
						for(i = n; i>0; i--){

									if(i%a == 0)
											break;
						}


						for( j = n; j>0; j--){

									if(j%b == 0)
											break;
						}

						for(m = n; m >0; m--){

									if(m%(a*b) == 0)
											break;
						}

						double first = (double(i) - double(a))/double(a) + 1;
						double second = (double(j) - double(b))/double(b) + 1;
						double common = (double(m) - double(a*b))/double(a*b) + 1;
						long long count = (long long)(first + second - common);

						if(count >= k)
								std::cout << "Win" << '\n';
						else
								std::cout << "Lose" << '\n';
			}
}
