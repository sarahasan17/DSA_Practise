#include <vector>
int lcs(string s, string t)
{
	vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,0));
	int n1=s.size();
	int n2=t.size();
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++){
			if(s[i-1]==t[j-1]){
				dp[i][j]=1+dp[i-1][j-1];
			}
			else{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	}
	return dp[n1][n2];
}
