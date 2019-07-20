#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


struct Pair {
  int arrive;
  int exit;
};


bool compare(Pair obj1, Pair obj2){

      if(obj1.arrive < obj2.arrive)
          return true;
      else if(obj1.arrive  > obj2.arrive)
          return false;
      else if(obj1.exit > obj2.exit)
          return true;
      return false;
}

int main(){

  int n;
  cin >> n;
  Pair arr[n];

  for(int i = 0; i <n; i++)
    cin >> arr[i].arrive;

  for(int i = 0; i <n; i++)
    cin >> arr[i].exit;

  sort(arr, arr + n, compare);

  int count = 1;
  int min = arr[0].exit;

  for(int i = 1; i < n; i++){

        // person already left
        if(arr[i].arrive > arr[i-1].exit)
            min = arr[i].exit;

        // both persons arrived at same time
        else if(arr[i].arrive == arr[i-1].arrive){
            count++;
            min = min > arr[i].exit ? min : arr[i].exit;
        }

        // old person is alreadysitting
        else if(arr[i].arrive < arr[i-1].exit)
          count++;
  }

  cout << count << endl;
  return 0;
}
