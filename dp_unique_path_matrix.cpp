//n unique paths
//all possible ways
#include <iostream>
#include <vector>
using namespace std;
int unique_paths(vector<vector<int>> a,int i,int j,vector<vector<int>> dp){
    if(i==0||j==0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int l=unique_paths(a,i-1,j,dp);
    int r=unique_paths(a,i,j-1,dp);
    return dp[i][j]=l+r;
}

int main()
{
    vector<vector<int>>a(4,vector<int>(4,1));
    vector<vector<int>>dp(4,vector<int>(4,-1));
    cout<<unique_paths(a,2,2,dp);
}
