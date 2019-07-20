#include<iostream>
using namespace std;

struct train {
     int arrival;
     int exit;
};



bool comapre(train t1, train t2){

     if(t1.arrival < t2.arrival)
          return true;

     else if(t1.arrival > t2.arrival)
          return false;

     if(t1.exit < t2.exit)
          return true;
     return false;
}

void merge(train *arr, int low, int mid, int high){

     int n1 = mid + 1 - low;
     int n2 = high - mid;

     train left[n1], right[n2];

     for(int i = 0; i < n1; i++)
          left[i] = arr[low + i];

     for(int i = 0; i < n2; i++)
          right[i] = arr[1 + mid + i];

     int i = 0;
     int j = 0;
     int k = low;

     while(i < n1 && j < n2){

          if(comapre(left[i], right[j])){
               arr[k] = left[i];
               i++;
               k++;
          }else{
               arr[k] = right[j];
               j++;
               k++;
          }
     }

     while(i < n1){
          arr[k] = left[i];
          i++;
          k++;
     }

     while(j < n2){
          arr[k] = right[j];
          j++;
          k++;
     }
}

void mergeSort(train *arr, int low, int high){

     if(low < high){
          int mid = (low + high)/2;
          mergeSort(arr,low,mid);
          mergeSort(arr,mid+1,high);
          merge(arr, low, mid, high);
     }
}

int main(){

     int n;
     cin >> n;

     train arr[n];

     for(int i = 0; i < n; i++)
          cin >> arr[i].arrival;

     for(int i = 0; i < n; i++)
          cin >> arr[i].exit;

     mergeSort(arr,0,n-1);

     int count = 1;
     for(int i = 1; i < n; i++){

          if(arr[i-1].exit >= arr[i].arrival)
               count++;
     }
     std::cout << count << '\n';
}
