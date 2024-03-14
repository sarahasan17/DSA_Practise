#include <bits/stdc++.h> 
int mini(vector<int> &a,int p,int ind,vector<vector<int>>& dp){
    if(ind==0){
        if(p%a[0]==0) return p/a[0];
        return 1e9;
    }
    if(dp[ind][p]!=-1){
        return dp[ind][p];
    }
    int ntake=0+mini(a,p,ind-1,dp);
    int take=INT_MAX;
    if(a[ind]<=p){
        take=1+mini(a,p-a[ind],ind,dp);
    }
    return dp[ind][p]=min(take,ntake);
}
int minimumElements(vector<int> &a, int p)
{
    int n=a.size();
    vector<vector<int>> dp(n,vector<int>(p+1,-1));
    int ans=mini(a,p,n-1,dp);
    if (ans>=1e9){
      return -1;
    }
    return ans;
}
