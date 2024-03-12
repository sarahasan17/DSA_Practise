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
	vector<vector<int>> dp(arr.size(),vector<int> (k+1,-1));
	return values(arr,k,arr.size()-1,dp);
}
