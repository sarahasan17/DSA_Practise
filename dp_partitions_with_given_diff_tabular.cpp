int findWays(vector<int>& arr, int k)
{
	vector<vector<int>> dp(arr.size(),vector<int> (k+1,0));
	int n=arr.size();
	if(arr[0]==0){
		dp[0][0]=2;
	}
	else{
		dp[0][0]=1;
	}
	if(arr[0]!=0 && arr[0]<=k){
		dp[0][arr[0]]=1;
	}
	for(int i=1;i<n;i++){
		for(int tar=0;tar<=k;tar++){
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


int countPartitions(int n,int d,vector<int> &arr){
	int tsum=0;
	for(int i=0;i<arr.size();i++){
		tsum+=arr[i];
	}
	if(tsum-d<0 || (tsum-d)%2!=0){
		return 0;
	}
	return findWays(arr,(tsum-d)/2);
}



