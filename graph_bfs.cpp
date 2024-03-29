#include<bits/stdc++.h>
using namespace std;

void print(int **edges, int n, int sv){

     bool *visited = new bool[n];
     for(int i = 0; i < n; i++)
          visited[i] = false;

     queue<int> q;
     q.push(sv);

     while(!q.empty()){

          int v = q.front();
          q.pop();

          std::cout << v << ' ';
          visited[v] = true;

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
     std::cout  << '\n';
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

     /*

     for(int i = 0; i < n; i++){
          for(int j = 0; j < n; j++)
               std::cout << edges[i][j] << ' ';
          std::cout  << '\n';
     }

     */

     print(edges,n,0);


     for(int i = 0; i < n; i++)
          delete[] edges[i];
     delete[] edges;
}
