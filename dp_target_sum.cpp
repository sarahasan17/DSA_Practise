#include <bits/stdc++.h> 
int values(int n,int tar,vector<int>& arr,int ind){
    if(ind==0){
        if(tar==0 && arr[0]==0){
            return 2;
        }
        else if(tar==0 || tar==arr[0]){
            return 1;
        }
        return 0;
    }
    int ntake=values(n,tar,arr,ind-1);
    int take=0;
    if(arr[ind]<=tar){
        take=values(n,tar-arr[ind],arr,ind-1);
    }
    return take+ntake;
}
int targetSum(int n, int target, vector<int>& arr) {
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    if(sum-target<0 || (sum-target)%2!=0){
        return 0;
    }
    return values(n,(sum-target)/2,arr,n-1);
}
