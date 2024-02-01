//the last is not same as the current. find max
#include <iostream>
using namespace std;
#include <vector>
int ninja_jump(int n,int a[3][3],int last,vector<vector<int>> dp){
    if(n==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi=max(maxi,a[0][i]);
            }
        }
        return dp[0][last]=maxi;
    }
    if(dp[n][last]!=-1){
        return dp[n][last];
    }
    int maxi=0;
    for(int i=0;i<3;i++){
        if(i!=last){
            int val=a[n][i]+ninja_jump(n-1,a,i,dp);
            maxi=max(val,maxi);
        }
    }
    return dp[n][last]=maxi;
}
int main()
{
    vector <vector<int>> dp(3,vector<int>(4,-1));
    int a[3][3]={{5,3,3},{4,6,3},{10,8,2}};
    cout<<ninja_jump(2,a,3,dp);
    return 0;
}
