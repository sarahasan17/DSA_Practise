#include <bits/stdc++.h> 

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector <vector<int>> dp(n,vector<int> (maxWeight+1,0));
	for(int i=weight[0];i<=maxWeight;i++){
		dp[0][i]=value[0];
	}
	for(int i=1;i<n;i++){
		for(int w=0;w<=maxWeight;w++){
			int ntake=0+dp[i-1][w];
	        int take=INT_MIN;
	    if(weight[i]<=w){
		   take=value[i]+dp[i-1][w-weight[i]];
	     }
		 dp[i][w]=max(take,ntake);
	}
	}
	return dp[n-1][maxWeight];
}
