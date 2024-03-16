#include <bits/stdc++.h> 
int values(vector<int> weight, vector<int> value, int n, int maxWeight,int ind,vector<vector<int>> dp){
	if(ind==0){
		if(weight[ind]<=maxWeight){
			return value[ind];
		}
		else{
			return 0;
		}
	}
	if (dp[ind][maxWeight]!=-1){
		return dp[ind][maxWeight];
	}
	int ntake=0+values(weight,value,n,maxWeight,ind-1,dp);
	int take=INT_MIN;
	if(weight[ind]<=maxWeight){
		take=value[ind]+values(weight,value,n,maxWeight-weight[ind],ind-1,dp);
	}
	return dp[ind][maxWeight]=max(take,ntake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector <vector<int>> dp(n,vector<int> (maxWeight+1,0));
	return values(weight,value,n,maxWeight,n-1,dp);
}
