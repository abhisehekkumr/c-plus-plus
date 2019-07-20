#include<iostream>
using namespace std;

int main(){
     int t;
     cin >> t;

     while(t--){
          int n;
          cin >> n;

          bool flag = false;
          int arr[n];

          for(int i = 0; i < n; i++)
               cin >> arr[i];

          int left = arr[0], right = 0;

          for(int i = n-1; i > 1; i--)
               right += arr[i];

          for(int i = 1; i < n -1; i++){
               //std::cout << left << " " << right << '\n';
               if(left == right){
                    //std::cout << "YES" << '\n';
                    flag = true;
                    break;
               }else{
                    left += arr[i];
                    right -= arr[i + 1];
               }

          }

          if(flag || n == 1)
          std::cout << "YES" << '\n';
          else
          std::cout << "NO" << '\n';
     }
}
