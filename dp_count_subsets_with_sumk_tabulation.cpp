int values(vector<int>& arr, int k, int ind,vector<vector<int>>& dp){
	if(k==0){
		return 1;	
	}
	if(ind==0){
		return arr[ind]==k;
	}
	if(dp[ind][k]!=-1){
		return dp[ind][k];
	}
	int ntake=values(arr,k,ind-1,dp);
	int take=0;
	if(arr[ind]<=k){
		take=values(arr,k-arr[ind],ind-1,dp);
	}
	return dp[ind][k]=take+ntake;
}
int findWays(vector<int>& arr, int k)
{
	vector<vector<int>> dp(arr.size(),vector<int> (k+1,0));
	int n=arr.size();
	for(int i=0;i<n;i++){
		dp[i][0]=1;
	}
	if(arr[0]<=k){
		dp[0][arr[0]]=1;
	}
	for(int i=1;i<n;i++){
		for(int tar=1;tar<=k;tar++){
			int ntake=dp[i-1][tar];
			int take=0;
			if(arr[i]<=tar){
				take=dp[i-1][tar-arr[i]];
			}
			dp[i][tar]=ntake+take;
		}
	}
	return dp[n-1][k];
}
