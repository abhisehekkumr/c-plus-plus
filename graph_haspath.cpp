#include<bits/stdc++.h>
using namespace std;

bool bfs(int **edges, int n, bool *visited, int start, int end){

     queue<int> q;
     q.push(start);
     visited[start] = true;

     while(!q.empty()){
          int v = q.front();
          q.pop();

          if(v == end)
               return true;

          for(int i = 0; i < n; i++){

               if(i == v)
                    continue;
               if(edges[v][i] == 1){

                    if(visited[i] == true)
                         continue;
                    q.push(i);
                    visited[i] = true;
               }
          }
     }
     return false;
}

bool hasPath(int **edges, int n, int start, int end){
     bool *visited = new bool[n];
     for(int i = 0; i < n; i++){
          visited[i] = false;
     }
     return bfs(edges,n,visited,start,end);
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
          int s,f;
          cin >> f >> s;
          edges[f][s] = 1;
          edges[s][f] = 1;
     }

     int start,end;
     cin >> start >> end;

     if(edges[start][end])
          std::cout << "true" << '\n';
     else{

          if(hasPath(edges,n,start,end))
               std::cout << "true" << '\n';
          else
               std::cout << "false" << '\n';

     }
}
