#include<bits/stdc++.h>
using namespace std;





long long getSum(int a[], int b[], int n, int m){

          long long max_sum = 0, a_sum = 0, b_sum = 0;
          int i = 0, j = 0;
          int max_index = 0, index;
          while(i < n && j < m){

               if(a[i] == b[j]){
                    max_sum += max(a_sum, b_sum) + a[i];
                    a_sum = b_sum = 0;
                    i++;
                    j++;
               }

               while(i < n && a[i] < b[j]){
                    a_sum += a[i++];
               }

               while(j < m && b[j] < a[i]){
                    b_sum += b[j++];
               }
          }



          while(i < n){
               a_sum += a[i];
               i++;
          }

          while(j < m){
               b_sum += b[j];
               j++;
          }

          max_sum += max(a_sum , b_sum);
          return max_sum;
}

int main(){
     int t;
     cin >> t;

     while(t--){

          int n,m;
          cin >> n >> m;

          int a[n], b[m];

          for(int i = 0; i < n; i++)
               cin >> a[i];

          for(int j = 0; j < m; j++)
               cin >> b[j];


          std::cout << getSum(a,b,n,m) << '\n';
     }
}
