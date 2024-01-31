#include <iostream>
using namespace std;

int main(){
    int a[]={2,4,2,2,-1,2};
    int n=6;
    int dp[6];
    dp[0]=a[0];
    for(int i=1;i<n;i++){
        int pick=-1000000;
        if(i>=2){
            pick=dp[i-2]+a[i];
        }
        else{
            pick=a[i];
        }
        int pick1=dp[i-1];
        dp[i]=max(pick,pick1);
    }
    cout<<"max sum of non adjacent indexes:"<<dp[n-1]<<endl;
}
