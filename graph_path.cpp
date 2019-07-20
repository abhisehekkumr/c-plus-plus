#include<bits/stdc++.h>
using namespace std;


void dfs(int **edges, int n, int *path, bool *visited, int start, int end){

     path[0] = start;
     visited[start] = true;
     //std::cout << start << ' ';

     for(int i = 0; i < n; i++){
          if(i == start)
               continue;

          if(edges[start][i]){
               if(visited[i])
                    continue;
               dfs(edges,n,path + 1,visited,i,end);
          }
     }

     //path[0] = -1;
}

void getPath(int **edges, int n, int *path, int start, int end){

     bool *visited = new bool[n];
     for(int i = 0; i < n; i++)
          visited[i] = false;

     dfs(edges,n,path,visited,start,end);
}

int main(){
     int n,e;
     cin >> n >> e;

     int **edges = new int*[n];
     for(int i = 0; i < n; i++){
          edges[i] = new int[n];
          for(int j = 0; j < n; j++)
               edges[i][j] = 0;
     }

     for(int i = 0; i < e; i++){
          int f,s;
          cin >> f >> s;
          edges[f][s] = 1;
          edges[s][f] = 1;
     }

     int start,end;
     cin >> start >> end;

     if(start == end){
          std::cout << end << '\n';
          return 0;
     }

     int *arr = new int[n];
     for(int i = 0; i < n; i++)
          arr[i] = -1;
     getPath(edges,n,arr,start,end);

     int i = 0;
     for(i = 0; i < n; i++){
          if(arr[i] == end)
               break;
     }

     for(int j = i; j >= 0; j--)
          std::cout << arr[j] << ' ';
     std::cout << '\n';
}
