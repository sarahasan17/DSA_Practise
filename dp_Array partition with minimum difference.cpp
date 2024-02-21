int minSubsetSumDifference(vector<int>& arr, int n)
{
	int totalsum=0;
	for(int i=0;i<n;i++){
		totalsum+=arr[i];
	}
	int k=totalsum;
	vector<vector<bool>> dp(n,vector<bool>(k+1,0));
	for(int i=0;i<n;i++){
		dp[i][0]=true;
	}
	if(k>=arr[0]){
		dp[0][arr[0]]=true;
	}
	for(int i=1;i<n;i++){
		for(int tar=1;tar<=k;tar++){
			bool notake=dp[i-1][tar];
			bool take=false;
			if(arr[i]<=tar){
				take=dp[i-1][tar-arr[i]];
			}
			dp[i][tar]=take | notake;
		}
	}
	int mini=100000000;
	for(int d=0;d<=totalsum/2;d++){
		if(dp[n-1][d]==true){
			mini=min(mini,abs(totalsum-d)-d);
		}
	
	}
	return mini;
}
