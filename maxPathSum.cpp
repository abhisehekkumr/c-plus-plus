#include<iostream>
using namespace std;

long maxSumPath(int *arr1, int *arr2, int n, int m){

     long max = 0, sum1 = 0, sum2 = 0;
     int i = 0, j = 0;

     while(i < n && j < m){

          if(arr1[i] == arr2[j]){

               max = max + (sum1 > sum2 ? sum1 : sum2) + arr1[i];
               i++;
               j++;
               sum1 = 0;
               sum2 = 0;
          }else if(arr1[i] < arr2[j]){
               sum1 += arr1[i];
               i++;
          }else{
               sum2 += arr2[j];
               j++;
          }
     }


     //max += sum1 > sum2 ? sum1 : sum2;
     //sum1 = 0;
     //sum2 = 0;

     while(i < n){
          sum1 += arr1[i];
          i++;
     }

     while(j < m){
          sum2 += arr2[j];
          j++;
     }

     return max + (sum1 > sum2 ? sum1 : sum2);

}

int main(){
     int n = 6;
     int arr1[] = {1, 5, 10, 15, 20, 25};

     int m = 5;
     int arr2[] = {2, 4, 5, 9, 15};
     cout << maxSumPath(arr1, arr2, n, m) << endl;
}
