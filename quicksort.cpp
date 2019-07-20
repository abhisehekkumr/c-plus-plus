#include<iostream>
using namespace std;

void swap(int *a, int *b){
     int temp = *a;
     *a = *b;
     *b = temp;
}

int partiton(int arr[], int start, int end){
     int x = arr[end];
     int count = 0;

     for(int i = start; i < end; i++){
          if(arr[i] == x)
               count++;
     }

     swap(&arr[end], &arr[start + count]);

     int i = start, j = end;

     for(int k = start; k <= end; k++){
          if(arr[i] < x)
               i++;
          else if(arr[i] > x)
               j--;
          else{
               swap(&arr[i], &arr[j]);
               i++;
               j--;
          }
     }
     return i + 1;
}

void quickSort(int arr[], int start, int end){
     if(start < end){
          int index = partiton(arr, start, end);
          quickSort(arr,start,index - 1);
          quickSort(arr, index + 1, end);
     }
}

int main(){
     int n;
     cin >> n;

     int arr[n];

     for(int i = 0; i < n; i++)
          cin >> arr[i];

     quickSort(arr,0,n-1);

     for(int i = 0; i < n; i++)
          std::cout << arr[i] << ' ';
     std::cout  << '\n';
}
