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
        int left=0;
        int right=0;
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
    int dp[3][3];
    int a[3][3]={{0,1,2},{3,4,5},{6,7,8}};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==0&&j==0){
                dp[i][j]=a[i][j];
                continue;
            }
            int min1=INT_MAX;
            int min2=INT_MAX;
            if(i>0){
               min1=dp[i-1][j]+a[i][j];
            }
            if(j>0){
               min2=dp[i][j-1]+a[i][j];
            }
            dp[i][j]=min(min1,min2);
        }
    }
    cout<<dp[2][2];
}
