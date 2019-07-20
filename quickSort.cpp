#include<bits/stdc++.h>
using namespace std;

int partiton(int arr[], int start, int end){

     int x = arr[end];
     int i = start - 1;

     for(int j = start; j < end; j++){
          if(arr[j] <= x){
               i++;
               swap(arr[i], arr[j]);
          }
     }
     swap(arr[i + 1], arr[end]);
     return i + 1;
}
void quickSort(int arr[], int start, int end){

     if(start < end){
          int index = partiton(arr,start, end);
          quickSort(arr,start,index - 1);
          quickSort(arr,index + 1, end);
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
     std::cout << '\n';
}
