#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin >> t;
     while(t--){
          int n;
          cin >> n;

          int arr[n];
          for(int i = 0; i < n; i++)
               cin >> arr[i];

          int i = 0, j = n-1;
          int k = 0;
          while(i < j){

               if(arr[i]%2 == 1)
                    i++;

               if(arr[j]%2 == 0)
                    j--;

               if(i > j)
                    break;

               if(arr[i]%2 == 0 && arr[j]%2 == 1){
                    swap(arr[i],arr[j]);
                    //std::cout << "/* message */" << '\n';
                    i++;
                    j--;
               }

               //std::cout << i << " " << j << '\n';
          }

          //std::cout << i << " " << j << '\n';

          for(int k = 0; k < n; k++){
               if(arr[k]%2 == 0){
                    i = k;
                    break;
               }
          }

          sort(arr,arr+i);
          sort(arr+i,arr+n);
     /*
          for(int i = 0; i < n; i++)
               std::cout << arr[i] << ' ';
          std::cout  << '\n';
     */
          j = i-1;
          for(int k = 0; k < i/2; k++){
               swap(arr[k],arr[j]);
               j--;
          }

          for(int i = 0; i < n; i++)
               std::cout << arr[i] << ' ';
          std::cout  << '\n';
     }
}
