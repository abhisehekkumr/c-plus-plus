#include<bits/stdc++.h>
using namespace std;

int solve(string A){

     int sum0 = 0, sum1 = 0, count = 0;
     int *arr0 = new int[A.size()];
     int *arr1 = new int[A.size()];



     for(int i = 0; i < A.size(); i++){

          if(A[i] =='0')
               sum0 += 1;
          else
               sum1 += 1;

          arr0[i] = sum0;
          arr1[i] = sum1;
     }

     for(int i = 0; i < A.size(); i++)
          std::cout << arr0[i] << ' ';
     std::cout << '\n';

     for(int i = 0; i < A.size(); i++)
          std::cout << arr1[i] << ' ';
     std::cout << '\n';

     for(int i = 1; i < A.size() - 1; i++){
          if(arr0[i] == arr1[i])
               count++;
     }

     return count + 1;
}

int main(){
     string A;
     cin >> A;
     std::cout << solve(A) << '\n';
     return 0;
}
