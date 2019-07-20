
void makeFalse(bool **dp, int n, int m){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            dp[i][j] = false;
    }

}

bool hasPath(char arr[][MAXN], bool **dp, int n, int m, int i, int j, int s, int e,char c, int count = 0){

    if(i == s && j == e && count >= 4)
        return true;

    if(i < 0 || i >= n || j < 0 || j >= m)
        return false;

    if(dp[i][j])
        return false;

    if(arr[i][j] != c)
        return false;

    if(dp[i][j])
        return false;

    dp[i][j] = true;

    if(hasPath(arr,dp,n,m,i-1,j,s,e,c,count+1))
        return true;

    if(hasPath(arr,dp,n,m,i+1,j,s,e,c,count+1))
        return true;

    if(hasPath(arr,dp,n,m,i,j-1,s,e,c,count+1))
        return true;

    if(hasPath(arr,dp,n,m,i,j+1,s,e,c,count+1))
        return true;

    dp[i][j] = false;
    
    return false;
}

int solve(char board[][MAXN],int n, int m)
{
	bool **dp = new bool*[n];

    for(int i = 0; i < n; i++){
        dp[i] = new bool[m];
        for(int j = 0; j < m; j++)
            dp[i][j] = false;
    }

    for(char c = 'A'; c <= 'Z'; c++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(hasPath(board,dp,n,m,i,j,i,j,c))
                    return 1;
                else
                    makeFalse(dp,n,m);

            }
        }
    }
    return 0;
}
