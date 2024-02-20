#include <bits/stdc++.h> 
bool f(int n,int target,vector<int> &arr){
    if(target==0){
        return true;
    }
    if(n==0) return (arr[0]==target);
    bool nottake=f(n-1,target,arr);
    bool take=false;
    if(target>=arr[n]){
        take=f(n-1,target-arr[n],arr);
    }
    return take || nottake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    return f(n-1,k,arr);
}
