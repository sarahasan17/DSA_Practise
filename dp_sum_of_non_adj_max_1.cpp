#include <iostream>
using namespace std;

int sum_of_no_adj1(int n,int a[],int dp[]){
    if(n==0){
        return a[n];
    }
    if(n<0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int pick=a[n]+sum_of_no_adj1(n-2,a,dp);
    int pick2=0+sum_of_no_adj1(n-1,a,dp);
    return dp[n]=max(pick,pick2);
}
int sum_of_no_adj(int n,int a[]){
    int dp[]={-1,-1,-1,-1};
    return sum_of_no_adj1(n-1,a,dp);
}
int main(){
    int a[]={2,4,2,2};
    cout<<"sum of non adjacent values:"<<sum_of_no_adj(4,a)<<endl;
}
