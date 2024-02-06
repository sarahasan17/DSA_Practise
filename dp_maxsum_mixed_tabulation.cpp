#include <iostream>
using namespace std;
int main()
{
    int a[3][3]={{4,3,5},{2,6,7},{1,2,3}};
    int dp[3][3];
    for(int j=0;j<3;j++){
        dp[0][j]=a[0][j];
    }
    int n=3;
    for(int i=1;i<3;i++){
        for(int j=0;j<3;j++){
            int ld=0;
            int rd=0;
            if(j>0){
                ld=a[i][j]+dp[i-1][j-1];
            }
            if(j<n-1){
                rd=a[i][j]+dp[i-1][j+1];
            }
            int t=a[i][j]+dp[i-1][j];
            int m=max(t,ld);
            dp[i][j]=max(m,rd);
        }
    }
    cout<<dp[2][2]<<endl;
}
