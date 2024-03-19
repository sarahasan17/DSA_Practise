int cutRod(vector<int> &price, int n)
{
	int leng=price.size();
	vector<vector<int>> dp(leng,vector<int>(n+1,0));
	for(int i=0;i<=n;i++){
		dp[0][i]=i*price[0];
	}
	for(int ind=1;ind<leng;ind++){
		for(int k=0;k<=n;k++){
			int ntake=dp[ind-1][k];
			int take=INT_MIN;
			int sub=ind+1;
			if(ind+1<=k){
				take=dp[ind][k-sub]+price[ind];
			}
			dp[ind][k]=max(take,ntake);
		}
	}
	return dp[leng-1][n];

}
