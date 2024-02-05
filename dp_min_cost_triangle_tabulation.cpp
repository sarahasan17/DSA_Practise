#include <iostream>
#include <limits.h>
using namespace std;
//here we start from top to bottom
int minpath(int a[4][4],int i,int j,int n,int dp[3][3]){
    if(i==n-1){
        return a[n-1][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int down=minpath(a,i+1,j,n,dp)+a[i][j];
    int diagonal=minpath(a,i+1,j+1,n,dp)+a[i][j];
    return dp[i][j]=min(down,diagonal);
}
int main()
{
    int dp[4][4];
    int a[4][4]={{1},{2,3},{3,6,7},{12,9,6,10}};
    for(int j=0;j<4;j++){
        dp[3][j]=a[3][j];
    }
    for(int i=2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int up=dp[i+1][j]+a[i][j];
            int diagonal=dp[i+1][j+1]+a[i][j];
            dp[i][j]=min(up,diagonal);
        }
    }
    cout<<dp[0][0];
}
