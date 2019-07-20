#include<iostream>
using namespace std;

void rotate(int **input, int n){

     for(int i = 0; i < n; i++){
          for(int j = 0; j <= i; j++){
               int temp = input[i][j];
               input[i][j] = input[j][i];
               input[j][i] = temp;
          }
     }
     /*
     for(int i = 0; i < n/2; i++){
          for(int j = 0; j < n; j++){
               int temp = input[i][j];
               input[i][j] = input[n-1-i][j];
          }
     }*/
}

int main(){

     int n;
     cin >> n;

     int **arr = new int*[n];
     for(int i = 0; i < n; i++)
          arr[i] = new int[n];

     for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++)
               cin >> arr[i][j];
     }

     rotate(arr,n);

     std::cout << '\n';
     for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++)
               std::cout << arr[i][j] << ' ';
          std::cout << '\n';
     }
     std::cout << '\n';
     return 0;
}


/*
3

1 2 3
4 5 6
7 8 9

*/
