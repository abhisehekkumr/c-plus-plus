#include<iostream>
#include<algorithm>
#define mod 1000000007
using namespace std;

int main(){
	int max = 750001;


    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr,arr+n);

        int min = arr[0];
        int max = arr[n-1];

        int *primes = new int[max+10];
        for(int i = 0; i <= max; i++)
            primes[i] = 0;

        for(int i = 0; i < n; i++)
            primes[arr[i]] = 1;



        for(int i = 0; i < n; i++){
            //int number = primes[arr[i]];
            for(int j = 2*arr[i]; j <= max; j += arr[i]){

                if(j%arr[i] == 0 && primes[j] > 0)
                    primes[j] = (primes[j]%mod + primes[arr[i]]%mod)%mod;
            }
        }

        //for(int i = min; i <= max; i++)
          //  cout << i << " " << primes[i] << endl;

        long long sum = 0;
        for(int i = min; i <= max; i++){
            sum = (sum%mod + primes[i]%mod)%mod;
        }




        cout << sum << endl;
    }

	return 0;
}
