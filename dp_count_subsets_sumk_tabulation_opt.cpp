int findWays(vector<int>& arr, int k)
{
	vector<int> prev(k+1,0);
	vector<int> cur(k+1);
	int n=arr.size();
	prev[0]=cur[0]=1;
	if(arr[0]<=k){
		prev[arr[0]]=1;
	}
	for(int i=1;i<n;i++){
		for(int tar=0;tar<=k;tar++){
			int ntake=prev[tar];
			int take=0;
			if(arr[i]<=tar){
				take=prev[tar-arr[i]];
			}
			cur[tar]=ntake+take;
		}
		prev=cur;
	}
	return prev[k];
}
