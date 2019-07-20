void makeFlase(bool **visited, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            visited[i][j] = false;
    }
}

bool pathExitst(char graph[][MAXN], bool **visited, int n, int m, int i, int j, string arr){

    if(arr.size() == 0){
        //cout << "found";
        return true;
    }

    if(i < 0 || i >= n)
        return false;

    if(j < 0 || j >= m)
        return false;

    if(visited[i][j])
        return false;

    if(arr[0] != graph[i][j])
        return false;

    visited[i][j] = true;

    if(pathExitst(graph,visited,n,m,i-1,j-1,arr.substr(1))){
        //cout << "path 1" << endl;
        return true;
    }


    if(pathExitst(graph,visited,n,m,i-1,j,arr.substr(1))){
        //cout << "path 2" << endl;
        return true;
    }


    if(pathExitst(graph,visited,n,m,i-1,j+1,arr.substr(1))){
        //cout << "path 3" << endl;
        return true;
    }


    if(pathExitst(graph,visited,n,m,i,j-1,arr.substr(1))){
        //cout << "path 4" << endl;
        return true;
    }

    if(pathExitst(graph,visited,n,m,i,j+1,arr.substr(1))){
        //cout << "path 5" << endl;
        return true;
    }

     if(pathExitst(graph,visited,n,m,i+1,j-1,arr.substr(1))){
         //cout << "path 6" << endl;
        return true;
     }

     if(pathExitst(graph,visited,n,m,i+1,j,arr.substr(1))){
         //cout << "path 7" << endl;
        return true;
     }

     if(pathExitst(graph,visited,n,m,i+1,j+1,arr.substr(1))){
         //cout << "path 8" << endl;
        return true;
     }

    visited[i][j] = false;

    return false;
}

bool found(char graph[][MAXN], int n, int m){

    string ans = "CODINGNINJA";

    bool **visited = new bool*[n];
    for(int i = 0; i < n; i++){
        visited[i] = new bool[m];
    }

    makeFlase(visited,n,m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(graph[i][j] == 'C'){
                //cout << graph[i][j] << endl;
                if(pathExitst(graph ,visited ,n ,m ,i, j, ans))
                    return true;
                else
                    makeFlase(visited,n,m);
            }

        }
    }
    return false;
}


int solve(char Graph[][MAXN],int N, int M)
{
    if(found(Graph,N,M))
        return true;
    return false;
}
