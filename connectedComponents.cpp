#include<bits/stdc++.h>
using namespace std;

void DFS(int **edges, int n, bool visited[], int start,vector<int> &v){
     v.push_back(start);
     visited[start] = true;

     for(int i = 0; i < n; i++){
          if(edges[start][i]){

               if(visited[i])
                    continue;
               DFS(edges,n,visited,i,v);
          }
     }
}

void getAllComponents(int **edges, int n){

     bool *arr = new bool[n];
     for(int i = 0; i < n; i++)
          arr[i] = false;

     vector<vector<int>> v;
     for(int i = 0; i < n; i++){

          if(!arr[i]){
               vector<int> k;
               DFS(edges,n,arr,i,k);
               v.push_back(k);
          }
     }

     for(int i = 0; i < v.size(); i++){
          vector<int> k = v[i];
          sort(k.begin(), k.end());
          for(int j = 0; j < k.size(); j++)
               std::cout << k[j] << ' ';
          std::cout << '\n';
     }

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


     getAllComponents(edges,n);

     for(int i = 0; i < n; i++)
          delete [] edges[i];
     delete [] edges;
     return 0;
}
