#include <bits/stdc++.h>
using namespace std;
//bottom_up approach tabular
int main(){
    int a[]={10,20,30,10};
    int dp[4];
    int k=2;
    int n=4;
    dp[0]=0;
    for(int i=1;i<n;i++){
        int minu=INT_MAX;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int val=dp[i-j]+abs(a[i]-a[i-j]);
                minu=min(val,minu);
            }
        }
        dp[i]=minu;
    }
    cout<<"The minimum no. of distance covered by the from during jump:"<<dp[n-1]<<endl;
}

