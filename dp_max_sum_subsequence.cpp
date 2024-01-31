#include <iostream>
using namespace std;

int main(){
    int a[]={2,4,2,2,-1,2,-2,-8};
    int n=8;
    int dp[8];
    int maxu=a[0];
    dp[0]=a[0];
    for(int i=1;i<n;i++){
        int sum=dp[i-1]+a[i];
        dp[i]=maxu=max(maxu,sum);
    }
    cout<<"max sum of non adjacent indexes:"<<dp[5]<<endl;
}
