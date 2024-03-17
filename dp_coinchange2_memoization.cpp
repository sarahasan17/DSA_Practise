#include <vector>
long values(int *a,int n,int tar,int ind, vector<vector<long>> &dp){
    if(ind==0){
        return tar%a[ind]==0;
    }
    if(dp[ind][tar]!=-1){
        return dp[ind][tar];
    }
    long ntake=values(a,n,tar,ind-1,dp);
    long take=0;
    if(a[ind]<=tar){
        take=values(a,n,tar-a[ind],ind,dp);
    }
    return dp[ind][tar]=take+ntake;
}
long countWaysToMakeChange(int *a, int n, int tar)
{
    vector<vector<long>> dp(n,vector<long>(tar+1,-1));
    return values(a,n,tar,n-1,dp);
}
