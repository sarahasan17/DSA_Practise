#include <iostream>
using namespace std;
//tabular-bottom up approach
int main(){
    int dp[4];
    int a[]={10,20,30,10};
    int prev2i=0;
    int previ=0;
    for(int i=1;i<4;i++){
        int left=previ+abs(a[i]-a[i-1]);
        int right=10000000;
        if(i>1){
            right=prev2i+abs(a[i]-a[i-2]);
        }
        prev2i=previ;
        previ=min(left,right);
    }
    cout<<"The minimum no. of distance covered by the from during jump:"<<previ<<endl;
}
