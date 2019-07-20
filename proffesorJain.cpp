#include<bits/stdc++.h>
using namespace std;

int main(){
     int n,k,l;
     cin >> n >> k >> l;

     int arr[n];

     for(int i = 0; i < n; i++)
          cin >> arr[i];

     int min = 10000000;

     bool flag = true;

     for(int i = 1; i < n; i++){

          if(arr[i] != arr[i - 1]){
               flag = false;
               break;
          }
     }

     if(flag){
          min = 0;
          flag = false;
     }


     for(int i = 0; i < n; i++){
          int pivot = arr[i];
          int inc = 0;
          int dec = 0;
          //std::cout << min << '\n';
          if(min == 0)
               break;

          for(int j = 0; j < n; j++){

               if(arr[j] > pivot)
                    dec += arr[j] - pivot;
               else
                    inc += pivot - arr[j];

          }


          if(inc >= dec){

               int result = (dec)*k + (inc - dec)*l;
               min = min < result ? min : result;
               //std::cout << "dec : " << dec <<  " "  << "inc : " << inc << '\n';
          }
     }

     std::cout << min << '\n';
}
