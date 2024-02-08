#include <iostream>
#include <vector>
using namespace std;

int cherry(int a[3][3],int i,int j1,int j2,int n,vector<vector<vector<int>>> dp){
    if(j1<0 || j1>n-1 || j2<0 || j2>n-1){
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
                val=cherry(a,i+1,j1+d,j2+k,n,dp)+a[i][j1];
            }
            else{
                val=cherry(a,i+1,j1+d,j2+k,n,dp)+a[i][j1]+a[i][j2];
            }
            if(val>maxi){
                maxi=val;
            }
        }
        
    }
    return dp[i][j1][j2]=maxi;
}


int main(){
    vector<vector<vector<int>>> dp(3,vector<vector<int>>(3,vector<int>(3,0)));
    int n=3;
    int a[3][3]={{1,1,1},{1,1,1},{1,1,1}};
    for(int k=0;k<n;k++){
        for(int l=0;l<n;l++){
            if(k==l){
                dp[n-1][k][l]=a[n-1][k];
            }
            else{
                dp[n-1][k][l]=a[n-1][k]+a[n-1][l];
            }
        }
    }

    for(int i=n-2;i>=0;i--){
        for(int j1=0;j1<n;j1++){
            for(int j2=0;j2<n;j2++){
               int  maxi=0;
    int val=0;
    for(int d=-1;d<=1;d++){
        for(int k=-1;k<=1;k++){
            if(j1==j2 && (j1+d>=0 && j1+d<=n-1 && j2+k>=0 && j2+k<=n-1)){
                val=dp[i+1][j1+d][j2+k]+a[i][j1];
            }
            else if(j1+d>=0 && j1+d<=n-1 && j2+k>=0 && j2+k<=n-1){
                val=dp[i+1][j1+d][j2+k]+a[i][j1]+a[i][j2];
            }
            if(val>maxi){
                maxi=val;
            }
        }
        
    } 
    dp[i][j1][j2]=maxi;
            }
        }
    }
    cout<<dp[0][0][2];
}
