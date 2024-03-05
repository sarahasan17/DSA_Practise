#include <iostream>
#include<vector>
using namespace std;
int frog_k(int n,int a[],vector<int> dp,int k){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int minu=100000;
    for(int i=1;i<=k;i++){
        if(n-i>=0){
            int val=frog_k(n-k,a,dp,k)+abs(a[n]-a[n-i]);
            minu=min(val,minu);
        }
    }
    return dp[n]=minu;
}
int main()
{
    int a[]={10,20,30,10};
    vector<int> dp(4,-1);
    cout<<"The minimum no. of distance covered by the from during jump:"<<frog_k(3,a,dp,2)<<endl;
}
