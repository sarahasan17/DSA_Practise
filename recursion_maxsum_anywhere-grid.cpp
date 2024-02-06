#include <iostream>
using namespace std;
int maxsum(int a[3][3],int i,int j,int n){
    if(j<0 || j>n-1){
        return -10000000;
    }
    if(i==0){
        return a[i][j];
    }
    else{
        int t=a[i][j]+maxsum(a,i-1,j,n);
        int ld=a[i][j]+maxsum(a,i-1,j-1,n);
        int rd=a[i][j]+maxsum(a,i-1,j+1,n);
        int m=max(ld,rd);
        return max(t,m);
    }
}
int main()
{
    int a[3][3]={{4,3,5},{2,6,7},{1,2,3}};
    cout<<maxsum(a,2,2,3);
}
