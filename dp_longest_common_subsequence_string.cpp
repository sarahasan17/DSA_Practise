#include <iostream>
using namespace std;
#include <vector>

string lcs(string a,string b){
    int n=a.size();
    int m=b.size();
    
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int i=n;
    int j=m;
    string c="";
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            c=c+a[i-1];
            i=i-1;
            j=j-1;
        }
        else{
            if(dp[i][j-1]>dp[i-1][j]){
                j=j-1;
            }
            else{
                i=i-1;
            }
        }
    }
    return c;
}


int main(){
    string a="abcde";
    string b="bdgek";
    string c=lcs(a,b);
    cout<<c;
}
