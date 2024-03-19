int values(int ind,int n,vector<int> &price,vector<vector<int>> dp){
	if(ind==0){
		return n*price[0];
	}
	if(dp[ind][n]!=-1){
		return dp[ind][n];
	}
	int ntake=values(ind-1,n,price,dp);
	int take=0;
	if(ind+1<=n){
		take=values(ind,n-ind-1,price,dp)+price[ind];
	}
	return dp[ind][n]=max(take,ntake);
}
int cutRod(vector<int> &price, int n)
{
	int leng=price.size();
	vector<vector<int>> dp(leng,vector<int>(n+1,-1));
	return values(leng-1,n,price,dp);
}
