#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n,vector<bool>(k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    dp[0][arr[0]]=true;
    for(int i=1;i<n;i++){
        for(int target=1;target<=k;target++){
            bool nottake=dp[i-1][target];
            bool take=false;
            if (target >=arr[i]) {
              take = dp[i - 1][ target - arr[i]];
            }
            dp[i][target]=(take|nottake);
        }
    }
    return dp[n-1][k];
}
