#include <iostream>
#include <limits.h>
using namespace std;
int minpath(int a[3][3],int i,int j,int dp[3][3]){
    if(i==0 && j==0){
        return a[0][0];
    }
    if(i<0 || j<0){
        return INT_MAX;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    else{
        int left=INT_MAX;
        int right=INT_MAX;
        if(i>0){
            left=minpath(a,i-1,j,dp)+a[i][j];
        }
        if(j>0){
            right=minpath(a,i,j-1,dp)+a[i][j];
        }
        return dp[i][j]=min(left,right);
    }
}
int main()
{
    int dp[3][3]={{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
    int a[3][3]={{0,1,2},{3,4,5},{6,7,8}};
    cout<<minpath(a,2,2,dp);
    
}
