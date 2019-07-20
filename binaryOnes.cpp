#include<iostream>
#include<string>
using namespace std;

int main(){
     int t;
     cin >> t;

     while(t--){
          int n;
          cin >> n;

          char arr[n];

          for(int i = 0; i < n; i++)
               cin >> arr[i];

          int sum = 0;

          for(int i = 0; i < n; i++){

               if(arr[i] == '1'){
                    int count = 0;

                    for(int j = i + 1; j < n; j++){
                         if(arr[j] == '1')
                              count++;
                    }

                    sum += count;
               }
          }

          std::cout << sum << '\n';
     }
}
