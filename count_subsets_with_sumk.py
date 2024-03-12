int values(vector<int>& arr, int k, int ind){
	if(k==0){
		return 1;	
	}
	if(ind==0){
		return arr[ind]==k;
	}
	int ntake=values(arr,k,ind-1);
	int take=0;
	if(arr[ind]<=k){
		take=values(arr,k-arr[ind],ind-1);
	}
	return take+ntake;
}
int findWays(vector<int>& arr, int k)
{
	return values(arr,k,arr.size()-1);
}
