#include<iostream>
using namespace std;

int main(){

      int n, k;
      cin >> n >> k;

      int arr[n];
      int index = 0, sum = 0;
      for(int i = 0; i < n; i++){
          cin >> arr[i];
      }

      bool flag = false;
      int i = 0;
      for(i = 0; i < n; i++){

            sum += arr[i];

            if(sum > k){

              while(sum > k && index  <= i){
                  sum -= arr[index];
                  index++;
              }

            }

            if(sum == k){
              flag = true;
              break;
            }
      }

      if(flag){
        std::cout << "true" << '\n';
        for(int j = index; j <= i; j++)
              std::cout << arr[j] << " ";
        std::cout << '\n';
      }else
        std::cout << "false" << '\n';
}
