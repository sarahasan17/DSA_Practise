#include <iostream>
using namespace std;
//tabular-bottom up approach
int main(){
    int dp[4];
    int a[]={10,20,30,10};
    dp[0]=0;
    for(int i=1;i<4;i++){
        int left=dp[i-1]+abs(a[i]-a[i-1]);
        int right=10000000;
        if(i>1){
            right=dp[i-2]+abs(a[i]-a[i-2]);
        }
        dp[i]=min(left,right);
    }
    cout<<"The minimum no. of distance covered by the from during jump:"<<dp[3]<<endl;
}
/**FOR CODING NINJA
#include <bits/stdc++.h> 

int frogJump(int n, vector<int> &heights)
{
    int dp[n];
    dp[0]=0;
    for(int i=1;i<n;i++){
        int l1=dp[i-1]+abs(heights[i]-heights[i-1]);
        int l2=1000000;
        if(i>1){
            l2=dp[i-2]+abs(heights[i]-heights[i-2]);
        }
        dp[i]=min(l1,l2);
    }
    return dp[n-1];
}**/
