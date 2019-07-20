int solve(int n,int m,vector<int>u,vector<int>v)
{
	int count = 0;

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

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= n; j++){

            if(arr[i][j]){
                for(int k = 1; k <= n; k++){

                        if(k == i)
                            continue;

                        if(arr[j][k] && arr[i][k])
                            count += 1;
                }
            }
        }
    }

    return count/6;
}
