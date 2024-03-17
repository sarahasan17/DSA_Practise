#include <vector>

long countWaysToMakeChange(int *a, int n, int tar)
{
    vector<vector<long>> dp(n,vector<long>(tar+1,0));
    for(int i=0;i<=tar;i++){
        if(tar>=a[0] && tar%a[0]==0){
            dp[0][i]=1;
        }
        else{
            dp[0][i]=0;
        }
    }
    for(int ind=1;ind<n;ind++){
        for(int t=0;t<=tar;t++){
            int ntake=dp[ind-1][t];
            int take=0;
            if(a[ind]<=t){
               take=dp[ind][t-a[ind]];
            }
            dp[ind][t]=take+ntake;
        }
    }
    return dp[n-1][tar];
}
