int values(int n, int w, vector<int> &profit, vector<int> &weight, int ind){
    if(ind==0){
        if(weight[0]<=w){
            return ((int)(w/weight[0]))*profit[0];
        }
        return 0;
    }
    int ntake=values(n,w,profit,weight,ind-1);
    int take=0;
    if(weight[ind]<=w){
        take=values(n,w-weight[ind],profit,weight,ind)+profit[ind];
    }
    return max(take,ntake);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    return values(n,w,profit,weight,n-1);
}
