#include<bits/stdc++.h>
using namespace std;
int main()
{

	int n;
    cin >> n;

    int  **arr = new int *[n];

  	for(int i = 0; i < n; i++)
      	arr[i] = new int[n];




  	for(int i = 0; i < n; i++){

      	for(int j = 0; j < n; j++){

          		cin >> arr[i][j];
          		//cout << arr[i][j] << " hey "<< endl;
        }
    }


  	int  sum = 0;

  	for(int i = 0; i < n; i++){

      	for(int j = 0; j < n; j++){

          	if(j == 0)
          		sum += arr[i][j];
          	else if(i == 0)
          		sum += arr[i][j];
          	else if(i == n-1)
              sum += arr[i][j];
          	else if(j == n-1)
              sum += arr[i][j];
        }
    }


  	for(int i = 0; i < n; i++){

      	sum += arr[i][i];
      	sum += arr[i][n-1-i];
    }

  	int result = sum - arr[0][0] -arr[0][n-1] - arr[n-1][0] -arr[n-1][n-1] - arr[int(n/2)][int(n/2)];
  	cout << result << endl;

  return 0;
}
