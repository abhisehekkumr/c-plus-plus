#include<iostream>
using namespace std;

int power(int x, int n){
     int res = 1;

     while(n){

          if(n & 1)
               res = res*x;
          x = x*x;
          n = n >> 1;
     }
     return res;
}

int subset(int input[], int size, int output[][50], int k){

     if(size <= 0){
          if(k == 0){
               output[0][0] = 0;
               return 1;
          }
          else
               return 0;
     }

     int smallOutput1[1000][50];
     int smallOutput2[1000][50];

     int size1 = subset(input + 1, size - 1, smallOutput1, k - input[0]);
     int size2 = subset(input + 1, size - 1, smallOutput2, k);


     int k1 = 0;

     //if(size1 > 0){

          for(int i = 0; i < size1; i++, k1++){
               int l = smallOutput1[i][0];
               output[k1][0] = l + 1;
               output[k1][1] = input[0];

               for(int j = 1; j <= l; j++)
                    output[k1][j+1] = smallOutput1[i][j];
          }
     //}


     //if(size2 > 0){

          for(int i = 0; i < size2; i++, k1++){
               int l = smallOutput2[i][0];
               output[k1][0] = l ;
               output[k1][1] = input[0];

               for(int j = 1; j <= l; j++)
                    output[k1][j] = smallOutput2[i][j];
               }
          //}

     return size1 + size2;
}
int main(){
     int n;
     cin >> n;
     int k;
     int arr[n];

     for(int i = 0; i < n; i++)
          cin >> arr[i];
     cin >> k;
     int output[10000][50];
     int rows = subset(arr,n,output,k);

     for(int i = 0; i < rows; i++){
          for(int j = 1; j <= output[i][0]; j++)
               std::cout << output[i][j] << ' ';
          std::cout << '\n';
     }
}
