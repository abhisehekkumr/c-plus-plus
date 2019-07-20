void DFS(int **edges, int n, int start, bool visited[]){
    visited[start] = true;
    for(int i = 1; i <= n; i++){

        if(edges[start][i]){

            if(visited[i])
                continue;
            DFS(edges,n,i,visited);
        }
    }
}

int totalComponents(int **edges, int n){

    bool *visited = new bool[n+1];
    for(int i = 0; i <= n; i++)
        visited[i] = false;
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            count += 1;
            DFS(edges,n,i,visited);
        }
    }
    return count;
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
	int **arr = new int*[n+1];
    for(int i = 0; i <= n; i++){
        arr[i] = new int[n+1];
        for(int j = 0; j <= n; j++)
            arr[i][j] = 0;
    }

    for(int i = 0; i < m; i++){
        arr[u[i]][v[i]] = 1;
        arr[v[i]][u[i]] = 1;
    }

    return totalComponents(arr,n);
}
