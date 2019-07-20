#include<iostream>
using namespace std;


int countWaysToMakeChange(int denominations[], int numDenominations, int value){

     if(value == 0)
          return 1;

    if(numDenominations == 0)
          return 0;

     if(value < 0)
          return 0;

     int ans1 = countWaysToMakeChange(denominations,numDenominations,value - denominations[0]);
     int ans2 = countWaysToMakeChange(denominations+1,numDenominations-1,value);
     return ans1 + ans2;
}

int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];

     int value;
     cin >> value;
     std::cout << countWaysToMakeChange(arr,n,value) << '\n';
}
