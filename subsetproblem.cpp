#include<iostream>
using namespace std;

bool helper(int arr[], int n, int sum){
     if(n == 0){
          return sum == 0;
     }

     return helper(arr+1,n-1,sum) || helper(arr+1,n-1,sum-arr[0]);
}

int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     std::cout << helper(arr,n,4) << '\n';
}
