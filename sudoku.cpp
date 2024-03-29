#include<bits/stdc++.h>
#define N 9
using namespace std;


bool findEmpty(int grid[N][N], int &row, int &col){

     for(int i = 0; i < N; i++){
          for(int j = 0; j < N; j++)
               if(grid[i][j] == 0){
                    row = i;
                    col = j;
                    return true;
               }
     }

     return false;
}

bool horizontal(int grid[N][N], int row, int col, int num){
     for(int i = 0; i < N; i++){
          if(grid[row][i] == num)
               return false;
     }

     return true;
}

bool vertical(int grid[N][N], int row, int col, int num){
     for(int i = 0; i < N; i++){
          if(grid[i][col] == num)
               return false;
     }

     return true;
}

bool matrix(int grid[N][N], int row, int col, int num){

     int row_vector = row - row%3;
     int col_vector = col - col%3;
     for(int i = 0; i < 3; i++){
          for(int j = 0; j  < 3; j++){
               if(grid[i + row_vector][j + col_vector] == num)
                    return false;
          }
     }

     return true;
}

bool isSafe(int grid[N][N], int row, int col, int num){

     if(horizontal(grid,row,col,num) && vertical(grid,row,col,num) && matrix(grid,row,col,num))
          return true;

     return false;
}

bool solveSudoku(int grid[N][N]){
     int row,col;

     if(!findEmpty(grid,row,col))
          return true;

     for(int i = 1; i <= 9; i++){

          if(isSafe(grid,row,col,i)){
               grid[row][col] = i;

               if(solveSudoku(grid))
                    return true;

               grid[row][col] = 0;
          }
     }

     return false;
}




int main(){
     int grid[N][N];

     for(int i = 0; i < N; i++){
          for(int j = 0; j < N; j++)
               cin >> grid[i][j];
     }

     std::cout  << '\n';
     if(solveSudoku(grid)){
          for(int i = 0; i < N; i++){
               for(int j = 0; j < N; j++)
                    std::cout << grid[i][j] << ' ';
               std::cout  << '\n';
          }
     }
     else
          std::cout << "false" << '\n';
}
