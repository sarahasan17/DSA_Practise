#include <iostream>
#include <vector>
using namespace std;
//cherry picky 3d dP 
int cherrypickup(int a[3][3], int i,int j1,int j2,int n,vector<vector<vector<int>>> &dp){
    if(j1<0 || j1>n-1|| j2<0 || j2>n-1){
        return -100000;
    }
    if(i==n-1){
        if(j1==j2){
            return a[i][j1];
        }
        else{
            return a[i][j1]+a[i][j2];
        }
    }
    if(dp[i][j1][j2]!=-1){
        return dp[i][j1][j2];
    }
    int maxi=0;
    int val;
    for(int d=-1;d<=1;d++){
        for(int k=-1;k<=1;k++){
            if(j1==j2){
                val=a[i][j1]+cherrypickup(a,i+1,j1+k,j2+d,n,dp);
            }
            else{
                val=a[i][j1]+a[i][j2]+cherrypickup(a,i+1,j1+k,j2+d,n,dp);
            }
            if(val>maxi){
                maxi=val;
            }
        }
    }
    return dp[i][j1][j2]=maxi;
}
int main()
{
    int a[3][3]={{1,1,1},{1,1,1},{1,1,1}};
    vector<vector<vector<int>>> dp(3,vector<vector<int>>(3,vector<int>(3,-1)));
    cout<<cherrypickup(a,0,0,2,3,dp);
    
}
