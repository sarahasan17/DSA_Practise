#include <vector>
int values(string s,string t,int ind1,int ind2,vector<vector<int>> dp){
	if(ind1<0 || ind2<0){
		return 0;
	}
	if(dp[ind1][ind2]!=-1){
		return dp[ind1][ind2];
	}
	if(s[ind1]==t[ind2]){
		return dp[ind1][ind2]=1+values(s,t,ind1-1,ind2-1,dp);
	}
	else{
		return dp[ind1][ind2]=max(values(s,t,ind1,ind2-1,dp),values(s,t,ind1-1,ind2,dp));
	}
}
int lcs(string s, string t)
{
	vector<vector<int>> dp(s.size(),vector<int>(t.size(),-1));
	return values(s,t,s.size()-1,t.size()-1,dp);
}
