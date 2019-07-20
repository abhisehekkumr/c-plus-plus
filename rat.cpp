#include<iostream>
using namespace std;


void goratgo(int maze[][20], int path[][20], int n, int row, int col){

     if(row == n - 1 && col == n - 1){
          for(int i = 0; i < n; i++){
               for(int j = 0; j < n; j++)
                    std::cout << path[i][j] << ' ';
               std::cout << '\n';
          }

          std::cout << '\n';
          return ;
     }

     // if rat is out of maze than we cannot go further
     if(row == n || col == n)
          return ;

     // preventing negative indexex while backtracking
     if(row < 0 || col < 0)
          return ;

     // checking for current position
     // if it is not blocked than we can have 4 possibilities
     // up, down, left and right


     if(maze[row][col] == 1){

          path[row][col] = 1;

          // going to right

          if(col + 1 < n && maze[row][col + 1] && path[row][col + 1] == 0){
               path[row][col + 1] = 1;
               goratgo(maze,path,n,row,col + 1);
               path[row][col + 1] = 0;
          }

          // goint to left
          if(col - 1 >= 0 && maze[row][col - 1] && path[row][col - 1] == 0){
               path[row][col - 1] = 1;
               goratgo(maze,path,n,row,col - 1);
               path[row][col - 1] = 0;
          }

          // goint to down
          if(row + 1 < n && maze[row + 1][col] && path[row + 1][col] == 0){
               path[row + 1][col] = 1;
               goratgo(maze,path,n,row + 1,col);
               path[row + 1][col] = 0;
          }

          // goint to up
          if(row - 1 >= 0 && maze[row - 1][col] && path[row - 1][col] == 0){
               path[row - 1][col] = 1;
               goratgo(maze,path,n,row - 1,col);
               path[row - 1][col] = 0;
          }

     }
}

void printPaths(int arr[][20], int n){

     int copy[n][20];

     for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++)
               copy[i][j] = 0;
     }

     goratgo(arr,copy,n,0,0);
}


int main(){
     int n;
     cin >> n;

     int arr[n][20];

     for(int i = 0; i < n; i++){
          for(int j = 0; j  < n; j++)
               cin >> arr[i][j];
     }

     printPaths(arr,n);
}
