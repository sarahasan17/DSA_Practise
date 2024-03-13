int values(vector<int>& arr, int k, int ind,vector<vector<int>>& dp){
	if(ind==0){
		if(k==0 &&arr[0]==0){
			return 2;
		}
		else if(k==0 || k==arr[0]){
			return 1;
		}
		return 0;
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
int values2(vector<int>& arr, int k)
{
	vector<vector<int>> dp(arr.size(),vector<int> (k+1,-1));
	return values(arr,k,arr.size()-1,dp);
}
int countPartitions(int n,int d,vector<int> &arr){
	int tsum=0;
	for(int i=0;i<arr.size();i++){
		tsum+=arr[i];
	}
	if(tsum-d<0 || (tsum-d)%2!=0){
		return 0;
	}
	return values2(arr,(tsum-d)/2);
}



