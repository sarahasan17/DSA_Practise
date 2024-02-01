//time->O(n*4*3)
#include<iostream>
#include <vector>
using namespace std;

int main(){
    int a[3][3]={{5,3,3},{3,7,2},{10,2,1}};
    vector<vector<int>> dp(3,vector<int>(4,0));
    dp[0][0]=max(a[0][1],a[0][2]);
    dp[0][1]=max(a[0][0],a[0][2]);
    dp[0][2]=max(a[0][1],a[0][0]);
    dp[0][3]=max(dp[0][0],a[0][0]);
    for(int day=1;day<3;day++){
        for(int last=0;last<4;last++){
            dp[day][last]=0;
            for(int i=0;i<3;i++){
                if(i!=last){
                    int price=a[day][i]+dp[day-1][i];
                    dp[day][last]=max(price,dp[day][last]);
                }
            }
        }
    }
    cout<<dp[2][3];
}
