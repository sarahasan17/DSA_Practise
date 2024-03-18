int values(int n, int w, vector<int> &profit, vector<int> &weight, int ind,vector<vector<int>> &dp){
    if(ind==0){
        if(weight[0]<=w){
            return ((int)(w/weight[0]))*profit[0];
        }
        return 0;
    }
    if(dp[ind][w]!=-1){
        return dp[ind][w];
    }
    int ntake=values(n,w,profit,weight,ind-1,dp);
    int take=0;
    if(weight[ind]<=w){
        take=values(n,w-weight[ind],profit,weight,ind,dp)+profit[ind];
    }
    return dp[ind][w]=max(take,ntake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n,vector<int>(w+1,-1));
    return values(n,w,profit,weight,n-1,dp);
}
