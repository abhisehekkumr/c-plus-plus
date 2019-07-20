#include<iostream>
using namespace std;


void merge(long long arr[], int lower, int mid, int upper){

     int n1 = mid - lower + 1;
     int n2 = upper - mid;

     long long arr1[n1], arr2[n1];

     for(int i = 0; i < n1; i++)
          arr1[i] = arr[lower + i];

     for(int i = 0; i < n2; i++)
          arr2[i] = arr[mid + 1 + i];

     int i = 0, j = 0, k = lower;

     while(i < n1 && j < n2){

          if(arr1[i] > arr2[j]){
               arr[k] = arr1[i];
               i++;
          }else{
               arr[k] = arr2[j];
               j++;
          }

          k++;
     }

     while(i < n1){
          arr[k] = arr1[i];
          i++;
          k++;
     }

     while(j < n2){
          arr[k] = arr2[j];
          j++;
          k++;
     }
}


void mergeSort(long long arr[], int lower, int upper){

     if(lower < upper){
          int mid = (lower + upper)/2;
          mergeSort(arr,lower,mid);
          mergeSort(arr,mid + 1, upper);
          merge(arr,lower,mid,upper);
     }
}

long long power(long long n, long long x){
     long long res = 1;
     while(n){

          if(n & 1)
               res = res*x;
          x = x*x;
          n = n >> 1;
     }
     return res;
}
int main(){
     int n;
     cin >> n;

     long long  arr[n];

     for(int i = 0; i < n; i++)
          cin >> arr[i];

     mergeSort(arr,0,n-1);

     long long sum = 0;

     for(int i = 0; i < n; i++)
          sum += arr[i] * power(i,2);
     std::cout << sum << '\n';
}
