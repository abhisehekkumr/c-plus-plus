#include<bits/stdc++.h>
using namespace std;

void printDFS(int **edges, int v, bool *visited, int sv){
     std::cout << sv << '\n';
     visited[sv] = true;
     for(int i = 0; i < v; i++){
          if(edges[sv][i] && visited[i] == false){
               printDFS(edges,v,visited,i);
          }
     }
}
bool safe = false;
void getPath(int **edges, int n, int start, int end, bool *visited, int *path, bool &safe){

     if(start == end){
          path[0] = start;
          visited[start] = true;
          safe = true;
          return;
     }

     path[0] = start;
     visited[start] = true;
     for(int i = 0; i < n; i++){
          if(edges[start][i] && visited[i] == false && safe == false){
               getPath(edges,n,i,end,visited,path+1,safe);
          }
     }

     if(!safe)
          path[0] = -1;
}


int main(){
     int v,e;
     cin >> v >> e;

     int **edges = new int*[v];
     for(int i = 0; i < v; i++){
          edges[i] = new int[v];
          for(int j = 0; j < v; j++)
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

     int *arr = new int[v];
     for(int i = 0; i < v; i++)
          arr[i] = -1;
     //bool safe = false;
     bool *visited = new bool[v];
     for(int i = 0; i < v; i++)
          visited[i] = false;

     getPath(edges,v,start,end,visited,arr,safe);
     int i = 0;
     for(i = 0; i < v; i++){
          if(arr[i] == -1)
               break;
     }

     if(i == v)
          return 0;

     for(int j = i-1; j >= 0; j--)
          std::cout << arr[j] << ' ';
     std::cout << '\n';
}
