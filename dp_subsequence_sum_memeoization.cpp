#include <bits/stdc++.h> 
bool f(int n,int target,vector<int> &arr,vector<vector<int>> dp){
    if(target==0){
        return true;
    }
    if(dp[n][target]!=-1){
        return dp[n][target];
    }
    if(n==0) return (arr[0]==target);
    bool nottake=f(n-1,target,arr,dp);
    bool take=false;
    if(target>=arr[n]){
        take=f(n-1,target-arr[n],arr,dp);
    }
    return dp[n][target]=(take | nottake);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
}
