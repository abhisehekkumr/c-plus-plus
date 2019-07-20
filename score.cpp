#include<bits/stdc++.h>
using namespace std;

int main() {

    long long n;
    cin >> n;

    long long result = 0;

    for(long long i = 1; i<=n ;i++){
        result += ((long long )(pow(i,n)))%100000;
    }

    if(result < 10)
        cout << "0000" << result << endl;
    else if(result < 100)
        cout << "0000" << result << endl;
    else if(result < 1000)
        cout << "00" << result << endl;
    else if(result < 10000)
        cout << "0" << result << endl;
    else
        cout << result%100000 << endl;

}
