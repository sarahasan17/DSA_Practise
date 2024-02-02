//n unique paths
//all possible ways
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> dp(4,vector<int>(4,0));
    dp[0][0]=1;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==0 && j==0){
                dp[0][0]=1;
            }
            else{
                int l=0;
                int r=0;
                if(i>0){
                    l=dp[i-1][j];
                }
                if(j>0){
                    r=dp[i][j-1];
                }
                dp[i][j]=l+r;
            }
        }
    }
    cout<<dp[2][2];
}
