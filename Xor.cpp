#include<bits/stdc++.h>
using namespace std;

long long getXor(long long l, long long r){
  long long res[] = {l,1,l+1,0};
  long long result[] = {r,1,r+1,0};
  return res[(l-1)%4]^result[r%4];
}

int main(){
      ios_base::sync_with_stdio(false);
      //cin.tie(NULL);
      int t;

      cin>>t;

      while(t--){

            long long l,r,result;
            cin>>l>>r;
            result = getXor(l-1,r);

            if(result%2 == 0)
                cout << "Even" << '\n';
            else
                cout << "Odd" << '\n';
      }
}
