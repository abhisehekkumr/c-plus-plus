#include<bits/stdc++.h>
using namespace std;

long long IndexSum(int last, int arr[]){
    long long sum = 0;

    for(int i = last - 1; i >= 0; i--){

            if(arr[last] > arr[i])
                sum += arr[i];
          //  cout << sum << endl;
    }

    //std::cout << '\n';

    return sum;
}

int main() {

	int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];

        long long sum = 0;

        for(int i = 0; i < n; i++){
            cin >> arr[i];
            sum += IndexSum(i, arr);
            //cout << sum << endl;
        }

        cout << sum << endl;
    }
}
