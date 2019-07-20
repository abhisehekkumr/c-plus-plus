#include<bits/stdc++.h>
using namespace std;
int main() {
    int n = 1000000+1;
	bool *primes = new bool[n+1];
    for(int i = 0; i <= n; i++)
        primes[i] = true;

    for(int i = 2; i*i*i <= n; i++){

        if(primes[i]){
            for(int j = i*i*i; j <= n; j += i*i*i)
                primes[j] = false;
        }

    }

    unordered_map<int,int> m;
    int count = 1;
    for(int i = 1; i <= n; i++){
        if(primes[i]){
            m[i] = count;
            count += 1;
        }
    }

    int t;
    cin >> t;
    int i = 1;
    while(t--){
        int k;
        cin >> k;

        if(primes[k]){
            cout << "Case " << i << ":" << " " << m[k] << endl;
        }else{
            cout << "Case " << i << ":" << " " << "Not Cube Free" << endl;
        }
        i++;
    }

}
