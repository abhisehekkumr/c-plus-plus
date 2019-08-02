#include<iostream>
#include<climits>
#define N 4
using namespace std;

int found(char matrix[N][N],bool **visited, int i, int j, int count){

     if(i < 0 || j < 0 || i >= N || j >= N)
          return INT_MAX;

     if(visited[i][j])
          return INT_MAX;

     if(matrix[i][j] == '0')
          return INT_MAX;

     if(matrix[i][j] == 'd')
          return count;

     visited[i][j] = true;

     int ans1 = found(matrix,visited,i-1,j,count+1);
     int ans2 = found(matrix,visited,i+1,j,count+1);
     int ans3 = found(matrix,visited,i,j-1,count+1);
     int ans4 = found(matrix,visited,i,j+1,count+1);

     visited[i][j] = false;
     return min(min(ans1,ans2), min(ans3, ans4));
}

void print(char matrix[N][N]){

     bool **visited = new bool*[N];
     for(int i = 0; i < N; i++){
          visited[i] = new bool[N];
          for(int j = 0; j < N; j++)
               visited[i][j] = false;
     }

     for(int i = 0; i < N; i++){
          for(int j = 0; j < N; j++){
               if(matrix[i][j] == 's'){
                    std::cout << found(matrix,visited,i,j,0) << '\n';
                    return;
               }
          }
     }
}

int main(){
      char matrix[N][N] =   {{'0', '*', '0', 's'},
                          {'*', '0', '*', '*'},
                          {'0', '*', '*', '*'},
                          {'d', '*', '*', '*'}};
     print(matrix);
}
