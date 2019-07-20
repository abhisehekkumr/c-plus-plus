int n = 5;

int max1 = 0;

int hasPath(char arr[NMAX][NMAX], bool **dp, int n,int i ,int j){

    //cout << "hey" << endl;

    if(i < 0 || i >= n)
        return 0;

    if(j < 0 || j >= n)
        return 0;

    if(arr[i][j] == '0')
        return 0;

    if(dp[i][j])
        return 0;

    dp[i][j] = true;
    max1 += 1;

    int ans1 = hasPath(arr,dp,n,i-1,j);
    int ans2 = hasPath(arr,dp,n,i+1,j);
    int ans3 = hasPath(arr,dp,n,i,j-1);
    int ans4 = hasPath(arr,dp,n,i,j+1);

    int ans5 = ans1 > ans2 ? ans1 : ans2;
    int ans6 = ans3 > ans4 ? ans3 : ans4;
    return (ans5 > ans6 ? ans5 : ans6)+1;
}


int solve(int n,char arr[NMAX][NMAX])
{
	bool **dp = new bool*[n];
    for(int i = 0; i < n; i++){
        dp[i] = new bool[n];
        for(int j = 0; j < n; j++)
            dp[i][j] = false;
    }

    //cout << "hey" << endl;
    int count = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            if(arr[i][j] == '1'){
                int ans = hasPath(arr,dp,n,i,j);
                count = count > max1 ? count : max1;
                max1= 0;
                //cout << count << " this" << endl;
            }

        }
    }
    return count;
}
