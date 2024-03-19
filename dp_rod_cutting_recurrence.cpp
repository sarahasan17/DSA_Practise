int values(int ind,int n,vector<int> &price){
	if(ind==0){
		return n*price[0];
	}
	int ntake=values(ind-1,n,price);
	int take=0;
	if(ind+1<=n){
		take=values(ind,n-ind-1,price)+price[ind];
	}
	return max(take,ntake);
}
int cutRod(vector<int> &price, int n)
{
	int leng=price.size();
	return values(leng-1,n,price);
}
