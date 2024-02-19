#include <bits/stdc++.h> 
int maxival(int i,int j1,int j2,vector<vector<int>> &grid,int r,int c,vector<vector<vector<int>>> &dp){
    if(j1<0 || j2<0 || j1>=c || j2>=c){
        return -10000000;
    }
    if(i==r-1){
        if(j1==j2){
            return grid[i][j1];
        }
        else{
            return grid[i][j1]+grid[i][j2];
        }
    }
    if(dp[i][j1][j2]!=-1){
        return dp[i][j1][j2];
    }
    int maxi=-1000000;
    for(int k=-1;k<=1;k++){
        for(int l=-1;l<=1;l++){
            int val=0;
            if(j1==j2){
                val=grid[i][j1];
            }
            else{
                val=grid[i][j1]+grid[i][j2];
            }
            val=val+maxival(i+1,j1+k,j2+l,grid,r,c,dp);
            maxi=max(maxi,val);
        }
    }
    return dp[i][j1][j2]=maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
    return maxival(0,0,c-1,grid,r,c,dp);
}
