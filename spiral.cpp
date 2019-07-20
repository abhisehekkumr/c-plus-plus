#include<iostream>
using namespace std;

void printSpiral(int arr[4][5], int n, int m){
     int rs = 0, re = n-1, cs = 0, ce = m-1;
     int count = 0;

     while(count < n*m){

          // horizontal upper row
          for(int i = rs; i <= ce; i++){
               count++;
               std::cout << arr[rs][i] << ' ';
               //std::cout << "first " << rs  << " " <<  i << '\n';

               //if(count == 10)
               //     break;
          }

          rs = rs + 1;
          // vertical last row
          for(int i = rs; i <= re; i++){
               count++;
               std::cout << arr[i][ce] << ' ';
               //std::cout << "second " << ce  << " " <<  i << '\n' ;
               //if(count == 10)
               //     break;
          }

          ce = ce-1;

          // horizontal bottom row

          for(int i = ce; i >= cs; i--){
               count++;
               std::cout << arr[re][i] << ' ';
               //std::cout << "third " << '\n';
               //if(count == 10)
               //     break;
          }

          re = re - 1;
          // vertical left row
          for(int i = re; i >= rs; i--){
               count++;
               std::cout << arr[i][cs] << ' ';
               //std::cout << "fourth" << '\n';
               //if(count == 10)
               //     break;
          }

          cs = cs + 1;
     }
     std::cout  << '\n';
     //std::cout << count << '\n';
}

int main(){
     int n,m;
     n = m = 4;
     int arr[4][5] = {
               {1,2,3,4,5},
               {5,6,7,8,6},
               {9,10,11,12,7},
               {13,14,15,16,9}
          };

     printSpiral(arr,n,m);
     return 0;
}
/*
4 4 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
*/
