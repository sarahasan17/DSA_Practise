#include <iostream>
using namespace std;
#include <vector>
int sum_of_no_adj1(int n,vector<int> a,int dp[]){
    if(n==0){
        return a[n];
    }
    if(n<0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int pick=a[n]+sum_of_no_adj1(n-2,a,dp);
    int pick2=0+sum_of_no_adj1(n-1,a,dp);
    return dp[n]=max(pick,pick2);
}
int sum_of_no_adj(int n,vector<int> a){
    int dp[]={-1,-1,-1,-1};
    return sum_of_no_adj1(n-1,a,dp);
}
int device_round(vector<int> a,int n){
    vector<int> temp;
    vector<int> temp1;
    for(int i=0;i<n;i++){
       if(i!=0){
           temp.push_back(a[i]);
       } 
       if(i!=n-1){
           temp1.push_back(a[i]);
        }
    }
    return max(sum_of_no_adj(4,temp),sum_of_no_adj(4,temp1));
}
int main(){
    vector<int> a;
    a.push_back(2);
    a.push_back(3);
    a.push_back(2);
    a.push_back(2);
    a.push_back(5);
    cout<<device_round(a,5)<<endl;

}
