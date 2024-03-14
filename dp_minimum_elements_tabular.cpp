#include <bits/stdc++.h> 

int minimumElements(vector<int> &a, int p)
{
    int n=a.size();
    vector<vector<int>> dp(n,vector<int>(p+1,0));
    for(int i=0;i<=p;i++){
        if(i%a[0]==0){
          dp[0][i]=i/a[0];
        }
        else{
          dp[0][i]=1e9;
        }
    }
    for(int i=1;i<n;i++){
        for(int tar=0;tar<=p;tar++){
            int ntake=dp[i-1][tar];
            int take=INT_MAX;
            if(a[i]<=tar){
                take=1+dp[i][tar-a[i]];
            }
            dp[i][tar]=min(take,ntake);
        }
    }
    if (dp[n-1][p]>=1e9){
        return -1;
    }
    return dp[n-1][p];
    
}
