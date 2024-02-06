#include <iostream>
using namespace std;
int maxsum(int a[3][3],int i,int j,int n,int dp[3][3]){
    if(j<0 || j>n-1){
        return -10000000;
    }
    if(i==0){
        return a[i][j];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    else{
        int t=a[i][j]+maxsum(a,i-1,j,n,dp);
        int ld=a[i][j]+maxsum(a,i-1,j-1,n,dp);
        int rd=a[i][j]+maxsum(a,i-1,j+1,n,dp);
        int m=max(ld,rd);
        return dp[i][j]=max(t,m);
    }
}
int main()
{
    int a[3][3]={{4,3,5},{2,6,7},{1,2,3}};
    int dp[3][3]={{-1,-1,-1},{-1,-1,-1},{-1,-1,-1}};
    cout<<maxsum(a,2,2,3,dp);
}
