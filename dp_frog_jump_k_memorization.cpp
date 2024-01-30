#include <bits/stdc++.h>
using namespace std;
//top-down approach_memoriation
int frog_jump(int n,int a[],int dp[],int k){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int minu=INT_MAX;
    for(int j=1;j<=k;j++){
        if(n-j>=0){
           int left=frog_jump(n-j,a,dp,k)+abs(a[n]-a[n-j]);
           minu=min(minu,left);
        }
    }
    return dp[n]=minu;
}
int frogjump(int n,int a[],int k){
    int dp[]={-1,-1,-1,-1};
    return frog_jump(n-1,a,dp,k);
}
int main(){
    int a[]={10,20,30,10};
    /*for(int i=1;i<4;i++){
        int left=previ+abs(a[i]-a[i-1]);
        int right=10000000;
        if(i>1){
            right=prev2i+abs(a[i]-a[i-2]);
        }
        prev2i=previ;
        previ=min(left,right);
    }*/
    cout<<"The minimum no. of distance covered by the from during jump:"<<frogjump(4,a,2)<<endl;
}
