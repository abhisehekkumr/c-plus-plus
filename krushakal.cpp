#include<bits/stdc++.h>
using namespace std;

struct vertex{
     int source;
     int end;
     int weight;
};

bool compare(vertex v1, vertex v2){

     return v1.weight < v2.weight;
}


int getParent(int v, int parent[]){

    if(parent[v] == v)
        return v;
    return getParent(parent[v], parent);
}

int main(){

     int n,e;
     cin >> n >> e;

     vertex arr[e];

     for(int i = 0; i < e; i++)
          cin >> arr[i].source >> arr[i].end >> arr[i].weight;

     sort(arr, arr + e, compare);

     //std::cout << "output is" << '\n';

     int parent[n];
     for(int i = 0; i < n; i++)
          parent[i] = i;

     int count = 0,i = 0;
     vertex output[n];

     while(count < n -1){

         int sourceParent = getParent(arr[i].source, parent);
         int endParent = getParent(arr[i].end, parent);

         if(sourceParent != endParent){
             parent[sourceParent] = endParent;
             output[count] = arr[i];
             count++;
         }
         i++;
     }

     for(int i = 0; i < count; i++){

         if(output[i].source < output[i].end)
             std::cout << output[i].source << " " << output[i].end << " " << output[i].weight << '\n';
         else
             std::cout << output[i].end << " " << output[i].source << " " << output[i].weight << '\n';
     }

}
