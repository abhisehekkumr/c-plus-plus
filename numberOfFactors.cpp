#include<iostream>
using namespace std;

int main(){

    int max = 1000001;
    int *primes = new int[max];
    for(int i = 2; i <= max; i++)
        primes[i] = 0;

    primes[0] = 0;
    primes[1] = 0;

    for(int i = 2; i <= max; i += 2)
        primes[i] = 1;

    for(int i = 3; i <= max; i += 2){

        if(primes[i] == 0){
            for(int j = i; j <= max; j += i)
                primes[j] += 1;
        }

    }

    int **result = new int*[11];
    for(int i = 0; i <= 10; i++)
        result[i] = new int[max];

    for(int i = 0; i <= 10; i++)
        result[i][0] = 0;

    for(int i = 0; i <= 10; i++){
        for(int j = 1; j <= max; j++){

            if(primes[j] == i)
                result[i][j] = result[i][j-1]+1;
            else
                result[i][j] = result[i][j-1];
        }
    }

    int t;
    cin >> t;
    while(t--){

        int a,b,n;
        cin >> a >> b >> n;

        cout << result[n][b] - result[n][a-1] << endl;

    }

	return 0;
}
