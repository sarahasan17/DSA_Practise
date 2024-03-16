#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector <vector<int>> dp(n,vector<int> (maxWeight+1,0));
	vector<int> prev(maxWeight+1,0);
	for(int i=weight[0];i<=maxWeight;i++){
		prev[i]=value[0];
	}
	for(int i=1;i<n;i++){
		for(int w=maxWeight;w>=0;w--){
			int ntake=0+prev[w];
	        int take=INT_MIN;
	    if(weight[i]<=w){
		   take=value[i]+prev[w-weight[i]];
	     }
		 prev[w]=max(take,ntake);
	}
	}
	return prev[maxWeight];
}
