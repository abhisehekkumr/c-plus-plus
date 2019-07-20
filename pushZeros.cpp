#include<bits/stdc++.h>
using namespace std;

void pushZeros(int arr[], int n){

     int *a = new int[n];

     int j = 0;

     for(int i = 0; i < n; i++){

          if(arr[i] == 0)
               continue;
          a[j] = arr[i];
          j++;
     }

     for(; j < n; j++)
          a[j] = 0;

     for(int i = 0; i < n; i++)
          arr[i] = a[i];
     delete [] a;
 }

 void optimized(int arr[], int n){

      int k = 0;

      for(int i = 0; i < n; i++){

           if(arr[i] == 0)
               continue;
          int temp = arr[i];
          arr[i] = arr[k];
          arr[k] = temp;
          k++;
      }
}

int main(){
     int n;
     cin >> n;

     int arr[n];

     for(int i = 0; i < n; i++)
          cin >> arr[i];

     optimized(arr,n);

     for(int i = 0; i < n; i++)
          std::cout << arr[i] << ' ';
     return 0;
}
