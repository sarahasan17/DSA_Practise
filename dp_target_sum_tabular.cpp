#include <bits/stdc++.h> 
int values(int n,int tar,vector<int>& arr,int ind,vector<vector<int>>& dp){
    if(ind==0){
        if(tar==0 && arr[0]==0){
            return 2;
        }
        else if(tar==0 || tar==arr[0]){
            return 1;
        }
        return 0;
    }
    if(dp[ind][tar]!=-1){
        return dp[ind][tar];
    }
    int ntake=values(n,tar,arr,ind-1,dp);
    int take=0;
    if(arr[ind]<=tar){
        take=values(n,tar-arr[ind],arr,ind-1,dp);
    }
    return dp[ind][tar]=take+ntake;
}
int target1(int target, vector<int>& arr) {
    int n=arr.size();
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    if(arr[0]==0){
        dp[0][0]=2;
    }
    else{
        dp[0][0]=1;
    }
    if(arr[0]!=0 && arr[0]<=target){
        dp[0][arr[0]]=1;
    }
    for(int i=1;i<n;i++){
        for(int tar=0;tar<=target;tar++){
            int ntake=dp[i-1][tar];
            int take=0;
            if(arr[i]<=tar){
               take=dp[i-1][tar-arr[i]];
            }
            dp[i][tar]=take+ntake;
        }
    }
    return dp[n-1][target];
    
}
int targetSum(int n, int target, vector<int>& arr) {
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum-target<0 || (sum-target)%2!=0){
        return 0;
    }
    return target1((sum-target)/2,arr);
}

