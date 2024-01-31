#include <iostream>
using namespace std;

int main(){
    int a[]={2,4,2,2,-1,2};
    int n=6;
    int dp[6];
    int val=a[0];
    int val1=0;
    for(int i=1;i<n;i++){
        int pick=-1000000;
        if(i>=2){
            pick=val1+a[i];
        }
        else{
            pick=a[i];
        }
        int pick1=val;
        val1=val;
        val=max(pick,pick1);
    }
    cout<<"max sum of non adjacent indexes:"<<val<<endl;
}
