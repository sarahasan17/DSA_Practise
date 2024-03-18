int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n,vector<int>(w+1,0));
    for(int i=0;i<=w;i++){
        dp[0][i]=((int)(i/weight[0]))*profit[0];
    }
    for(int i=1;i<n;i++){
        for(int k=0;k<=w;k++){
            int ntake=dp[i-1][k];
            int take=0;
            if(weight[i]<=k){
                take=dp[i][k-weight[i]]+profit[i];
            }
            dp[i][k]=max(take,ntake);
        }
    }
    return dp[n-1][w];
}
