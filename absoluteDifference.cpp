#include<iostream>
using namespace std;


void merge(int arr[], int lower, int mid, int higher){
     int n1 =  mid - lower + 1;
     int n2 = higher - mid;

     int arr1[n1], arr2[n2];

     for(int i = 0; i < n1; i++)
          arr1[i] = arr[lower + i];

     for(int i = 0; i < n2; i++)
          arr2[i] = arr[1 + mid + i];

     int i = 0, j = 0, k = lower;

     while(i < n1 && j < n2){
          if(arr1[i] < arr2[j]){
               arr[k] = arr1[i];
               i++;
          }
          else{
               arr[k] = arr2[j];
               j++;
          }
          k++;
     }

     while(i < n1){
          arr[k] = arr1[i];
          k++;
          i++;
     }

     while(j < n2){
          arr[k] = arr2[j];
          k++;
          j++;
     }
}

void mergeSort(int arr[], int lower, int higher){

     if(lower < higher){
          int mid = (lower + higher)/2;
          mergeSort(arr,lower,mid);
          mergeSort(arr,mid + 1, higher);
          merge(arr,lower,mid,higher);
     }
}

int minAbsoluteDiff(int arr[], int n) {


    mergeSort(arr,0,n-1);

    int min = 99999999;

    for(int i = 0; i < n - 1; i++){

        if((arr[i + 1] - arr[i]) < min)
            min = arr[i + 1] - arr[i];
    }

    return min;

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

     std::cout << "min difference : " << minAbsoluteDiff(arr,n) << endl;;
}
