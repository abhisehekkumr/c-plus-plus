#include<bits/stdc++.h>
#include<algorithm>
#define ll long long
using namespace std;

int main(){
  int t;
  cin >> t;

  while(t--){

        ll n;
        cin >> n;

        ll a[n], b[n];

        for(ll i = 0; i < n; i++)
            cin >> a[i];

        for(ll i = 0; i < n; i++)
            cin >> b[i];


        sort(a,a + n);
        sort(b, b + n, greater<int>());

        ll sum = 0;
        for(ll i = 0; i < n; i++)
          sum += a[i]*b[i];

        cout << sum << endl;
  }
}
