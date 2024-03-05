#include <iostream>
using namespace std;
//recursion->take all possible steps
int frog_jump1(int n,int a[],int dp[]){
    if(n==0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int left=frog_jump1(n-1,a,dp)+abs(a[n]-a[n-1]);
    int right=100000;
    if(n>1){
        right=frog_jump1(n-2,a,dp)+abs(a[n]-a[n-2]);
    }
    return dp[n]=min(left,right);
}
int frog_jump(int n,int a[],int dp[]){
    return frog_jump1(n-1,a,dp);
}
int main(){
    int dp[]={-1,-1,-1};
    int a[]={10,20,30,10};
    int n=frog_jump(5,a,dp);
    cout<<"The minimum no. of distance covered by the from during jump:"<<n<<endl;
}
