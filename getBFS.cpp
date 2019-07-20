#include<bits/stdc++.h>
using namespace std;

vector<int> getPath(int **edges, int n, int start, int end){
     bool *visited = new bool[n];
     for(int i = 0; i < n; i++)
          visited[i] = false;

     map<int,int> m;
     queue<int> q;
     vector<int> v;

    bool flag = false;

     if(start == end){
          //v.push_back(start);
          return v;
     }
     q.push(start);
     m[start] = start;
     visited[start] = true;

     while(!q.empty()){

          int sv = q.front();
          //std::cout << "start " << sv << '\n';
          q.pop();


          for(int i = 0; i < n; i++){
               if(edges[sv][i] && visited[i] == false){
                    m[i] = sv;
                    q.push(i);
                    visited[i] = true;

                    if(i == end){
                        flag = true;
                         break;
                    }
               }
          }
     }

     //map<int,int> :: iterator it;
     //std::cout << "/* message */" << '\n';
     //for(it = m.begin(); it != m.end(); it++)
     //     std::cout << it->first << " " << it->second << '\n';
     //std::cout << "/* message */" << '\n';
     if(flag){
          int i = end;
          v.push_back(end);

         while(i != start){
             v.push_back(m[i]);
             i = m[i];
         }
     }

     return v;
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


     vector<int> v = getPath(edges,n,start,end);
     for(int i = 0; i < v.size(); i++){
               std::cout << v[i] << ' ';
     }

     std::cout << '\n';
}
