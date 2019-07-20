#include<iostream>
using namespace std;


void merge(int arr[], int lower, int mid, int upper){

     int i, j, k;
    int n1 = mid - lower + 1;
    int n2 =  upper - mid;

     int a[n1], b[n2];

     for (i = 0; i < n1; i++)
         a[i] = arr[lower + i];
     for (j = 0; j < n2; j++)
         b[j] = arr[mid + 1+ j];

     i = 0;
     k = lower;
     j = 0;

     while(i < n1 && j < n2){
          if(a[i] < b[j]){
               arr[k] = a[i];
               i++;
          }
          else{
               arr[k] = b[j];
               j++;
          }
          k++;
     }

     while(i < n1){
          arr[k] = a[i];
          i++;
          k++;
     }

     while(j < n2){
          arr[k] = b[j];
          j++;
          k++;
     }
}

void mergeSort(int arr[], int lower, int upper){

     if(lower < upper){
          int mid = (lower + upper)/2;
          mergeSort(arr, lower, mid);
          mergeSort(arr, mid + 1, upper);
          merge(arr,lower,mid, upper);
     }
}
int main(){

     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     mergeSort(arr,0,n-1);

     for(int i = 0; i < n; i++)
          std::cout << arr[i] << ' ';
     std::cout  << '\n';
}
