#include <iostream>
#include <vector>
using namespace std;
//memoization:previous value is stored
int fibonacci(int a,vector<int> dp){
    if(a<=1){
        return a;
    }
    else if(dp[a]!=-1){
        return dp[a];
    }
    return dp[a]=fibonacci(a-1,dp)+fibonacci(a-2,dp);
}
int main()
{
    cout<<"Fibonacci:"<<endl;
    int b=3;
    vector<int> dp(b+1,-1);
    cout<<fibonacci(b,dp);
    
}
